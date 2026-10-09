"""WFM3 font + dialogue file, as the message routines of the game read it.

Layout (src/scus_942.36/main/game/message.c, func_80030A54, drawInfoMessageText):

    0x00  "WFM3"
    0x04  u32  unk4
    0x08  u32  offset of the dialogue table
    0x0C  u16  number of dialogues
    0x0E  u16  number of glyphs
    0x10  u16[0x40] id of the first dialogue of each group: func_80030800
          (group, index) shows dialogue table[group] + index
    0x90  u16[glyphs] offset of each glyph from the start of the file

    glyph:  u16 w (VRAM words, 4 pixels each), u16 h, u16 advance,
            u16 handakuten (the glyph is an accent mark), then w * h words
            sent to VRAM with SetDrawLoad (4 bits per pixel)

    dialogue table: u16[dialogues], offsets relative to the table; each
    dialogue is a stream of u16 tokens interpreted by func_8002FA24: the
    control codes listed in CONTROL_CODES below, each followed by its
    argument words, and glyph tokens (token & 0xFFF, flags in the top nibble).

Glyphs are recognised by hash against the reference fonts in fonts/font_08,
font_16 and font_24 (.yaml + .png), one per glyph height.
"""

import hashlib
import json
import re
import struct
import sys
from pathlib import Path
from typing import Dict, List, Optional

sys.path.insert(0, str(Path(__file__).parent))
import grpx
from none import TombaSegment

GLYPH_TABLE = 0x90
BOX_TABLE = 0x10
SHEET_COLUMNS = 16
FONTS_DIR = Path(__file__).parent / "fonts"

_reference: Optional[Dict[str, str]] = None


def is_wfm(data: bytes) -> bool:
    return data[:4] == b"WFM3"


def glyph_hash(w: int, h: int, pixels: bytes) -> str:
    """sha256 of u16 w (VRAM words), u16 h and the glyph words as stored."""
    return hashlib.sha256(struct.pack("<HH", w, h) + pixels).hexdigest()


def load_reference() -> Dict[str, str]:
    """hash -> character, from every fonts/font_*.yaml."""
    global _reference
    if _reference is None:
        _reference = {}
        pattern = re.compile(r"hash: ([0-9a-f]{64}), char: (\"(?:[^\"\\]|\\.)*\")")
        for path in sorted(FONTS_DIR.glob("font_*.yaml")):
            for digest, char in pattern.findall(path.read_text(encoding="utf-8")):
                _reference[digest] = json.loads(char)
    return _reference


def _quote(text: str) -> str:
    return json.dumps(text, ensure_ascii=False)


# Control codes, as dispatched by the jump table of func_8002FA24 (index =
# token + 14). Each entry: name, number of argument words, arguments signed.
#
#   FFFF end        closes the box (field 0xB4 = 0)
#   FFFE close      ends the text with field 0xB4 = 1
#   FFFD newline    cursor x = 8, cursor y += 13 (written as a line break)
#   FFFC wait       waits for the button (field 5 = 1)
#   FFFB clear      frees the glyphs on screen, cursor back to (8, 6)
#   FFFA box w h    sets the box size and recentres it
#   FFF9 delay n    waits n frames before the next token
#   FFF8 voice a b  tone a: playSFXWithNote(0xB, a) every 3 glyphs (field 0xC6);
#                   tail b: field 0xB6, where the balloon tail is drawn (see
#                   _tail_value; 8 becomes 0xFFFF); D_8009C377 = 1
#   FFF7 color n    field 0xC8 = n (0 is the normal text colour)
#   FFF6 move x y   adds (x, y) to the box position
#   FFF5 choice     field 0xB8 = 1 (the yes/no prompts use it)
#   FFF3 halt       stays on this token
#   FFF2 pose n     D_8009C377 = n: the area overlays switch on it to pick
#                   the talking animation (1 random gesture, 2-5 fixed
#                   animations, 0 back to normal behaviour)
#
# FFF4 and the codes below FFF2 are not in the table and fall through to the
# glyph path.
CONTROL_CODES = {
    0xFFFF: ("end", 0, False),
    0xFFFE: ("close", 0, False),
    0xFFFC: ("wait", 0, False),
    0xFFFB: ("clear", 0, False),
    0xFFFA: ("box", 2, False),
    0xFFF9: ("delay", 1, False),
    0xFFF8: ("voice", 2, False),
    0xFFF7: ("color", 1, False),
    0xFFF6: ("move", 2, True),
    0xFFF5: ("choice", 0, False),
    0xFFF3: ("halt", 0, False),
    0xFFF2: ("pose", 1, False),
}
NEWLINE = 0xFFFD
END = 0xFFFF
NORMAL_GLYPH_FLAGS = 8
CORNER_GLYPH_FLAGS = 0xC
KEY_ORDER = ["w", "h", "x", "y", "tone", "tail"]
# BALLOON_TAIL in include/game.h, without the prefix.
TAIL_NAMES = [
    "BOTTOM_CENTER",
    "BOTTOM_LEFT",
    "LEFT",
    "TOP_LEFT",
    "TOP_CENTER",
    "TOP_RIGHT",
    "RIGHT",
    "BOTTOM_RIGHT",
    "NONE",
]


def _dialogue_items(tokens, chars: List[str], used: Optional[set] = None) -> list:
    """Decodes a token stream the way func_8002FA24 walks it.

    Returns a list of (name, value): value is a dict for box, move and voice,
    a string for text, a number for the one-argument codes, a nested list of
    items for choice and None for the codes without arguments.

    Inside text, glyphs become their character and FFFD a line break. A
    character in braces, {char}, is a glyph with flags 0xC
    (CORNER_GLYPH_FLAGS): func_800316EC draws it in the corner of the box
    without moving the cursor, which is how the "next page" arrow is shown.
    Any other flags are written {char:flags} (the cursor does not advance for
    0xE). An unrecognised glyph is {gN}, or {gN:flags}.

    The game data always sets up a box as box, voice, move. The voice (tone
    and tail) and the move (x and y) that follow a box in that order are
    folded into the box item; elsewhere they are items of their own.

    Every dialogue is assumed to finish with FFFF, so a final end is not
    listed (nor the zero words that pad the file after it). A dialogue that
    finishes any other way keeps its last code, e.g. close.
    """
    tokens = list(tokens)
    while len(tokens) > 1 and tokens[-1] == 0 and tokens[-2] in (END, 0):
        tokens.pop()
    if tokens and tokens[-1] == END:
        tokens.pop()
    items = []

    def add_text(piece: str) -> None:
        if items and items[-1][0] == "text":
            items[-1] = ("text", items[-1][1] + piece)
        else:
            items.append(("text", piece))

    i = 0
    while i < len(tokens):
        token = tokens[i]
        i += 1
        if token == NEWLINE:
            add_text("\n")
        elif token in CONTROL_CODES:
            name, count, signed = CONTROL_CODES[token]
            args = []
            for value in tokens[i : i + count]:
                if signed and value & 0x8000:
                    value -= 0x10000
                args.append(value)
            i += count
            if name == "box":
                items.append(("box", {"w": args[0], "h": args[1]}))
            elif name == "voice":
                voice = {"tone": args[0], "tail": _tail_value(args[1])}
                last = items[-1] if items else None
                if last and last[0] == "box" and "x" not in last[1] and "tone" not in last[1]:
                    last[1].update(voice)
                else:
                    items.append(("voice", voice))
            elif name == "move":
                last = items[-1] if items else None
                if last and last[0] == "box" and "x" not in last[1]:
                    last[1]["x"] = args[0]
                    last[1]["y"] = args[1]
                else:
                    items.append(("move", {"x": args[0], "y": args[1]}))
            elif count == 1:
                items.append((name, args[0]))
            else:
                items.append((name, None))
        elif token & 0x8000:
            glyph = token & 0xFFF
            flags = token >> 12
            if used is not None:
                used.add(glyph)
            known = glyph < len(chars) and chars[glyph] != ""
            char = chars[glyph] if known else f"g{glyph}"
            if flags == CORNER_GLYPH_FLAGS and known:
                add_text(f"{{{char}}}")
            elif flags != NORMAL_GLYPH_FLAGS:
                add_text(f"{{{char}:{flags:X}}}")
            elif known:
                add_text(char)
            else:
                add_text(f"{{{char}}}")
        else:
            add_text(f"{{0x{token:04X}}}")
    return _nest_choices(items)


def _tail_value(raw: int):
    """Second argument of FFF8, the tail of the speech balloon.

    func_8004C258 switches on its top nibble (enum BALLOON_TAIL); 8 and above
    draw no tail. The value is written as the name of that position, or raw
    in hex when it is not one of them.
    """
    if raw & 0xFFF or (raw >> 12) >= len(TAIL_NAMES):
        return f"0x{raw:04X}"
    return TAIL_NAMES[raw >> 12]


def _nest_choices(items: list) -> list:
    """Puts the text that follows a choice code inside the choice item.

    FFF5 only raises a flag; the question it applies to is the text drawn
    right after it, up to the next code that is not text or color.
    """
    out = []
    i = 0
    while i < len(items):
        name, value = items[i]
        i += 1
        if name != "choice":
            out.append((name, value))
            continue
        inner = []
        while i < len(items) and items[i][0] in ("text", "color"):
            inner.append(items[i])
            i += 1
        out.append(("choice", inner if inner else None))
    return out


def _text_lines(name: str, value: str, indent: str) -> List[str]:
    """A text item. Text with line breaks is written as a YAML literal block
    so the breaks show as real lines; a double-quoted scalar would have them
    folded into spaces by the parser."""
    if "\n" not in value or value.strip("\n") == "":
        return [f"{indent}- {name}: {_quote(value)}"]
    body = value.split("\n")
    trailing = len(value) - len(value.rstrip("\n"))
    if trailing == 0:
        chomp = "-"
    elif trailing == 1:
        chomp = ""
        body.pop()
    else:
        chomp = "+"
        body.pop()
    first = body[0] if body else ""
    explicit = "2" if first == "" or first.startswith(" ") else ""
    lines = [f"{indent}- {name}: |{explicit}{chomp}"]
    for line in body:
        lines.append(f"{indent}    {line}" if line else "")
    return lines


def _content_lines(items: list, indent: str) -> List[str]:
    lines = []
    for name, value in items:
        if value is None:
            lines.append(f"{indent}- {name}")
        elif isinstance(value, list):
            lines.append(f"{indent}- {name}:")
            lines += _content_lines(value, indent + "    ")
        elif isinstance(value, dict):
            lines.append(f"{indent}- {name}:")
            for key, number in sorted(value.items(), key=lambda kv: KEY_ORDER.index(kv[0])):
                lines.append(f"{indent}    {key}: {number}")
        elif isinstance(value, str):
            lines += _text_lines(name, value, indent)
        else:
            lines.append(f"{indent}- {name}: {value}")
    return lines


def _special_dialogues(table) -> Optional[set]:
    """Dialogues that open a group, from the table at 0x10.

    func_80030800(group, index, ...) shows dialogue table[group] + index, so
    each entry is the id of the first dialogue of a group. The table is
    written as special: true on those dialogues. That only works when it is
    the usual ascending list starting at 0 and padded with zeros; otherwise
    None is returned and the caller writes the table as it is.
    """
    used = [v for i, v in enumerate(table) if v or i == 0]
    padded = used + [0] * (len(table) - len(used))
    if list(table) != padded or used != sorted(set(used)) or used[0] != 0:
        return None
    return set(used)


def write_wfm(base: Path, data: bytes) -> None:
    """Writes <base>.png (glyph sheet) and <base>.yaml."""
    reference = load_reference()
    unk4, dialogue_table, dialogue_count, glyph_count = struct.unpack_from("<IIHH", data, 4)
    box_table = struct.unpack_from("<64H", data, BOX_TABLE)
    glyph_offsets = struct.unpack_from(f"<{glyph_count}H", data, GLYPH_TABLE)

    glyphs = []
    for offset in glyph_offsets:
        w, h, advance, handakuten = struct.unpack_from("<4H", data, offset)
        pixels = data[offset + 8 : offset + 8 + w * h * 2]
        digest = glyph_hash(w, h, pixels)
        glyphs.append((w, h, advance, handakuten, pixels, digest, reference.get(digest, "")))

    cell_w = max([g[0] * 4 for g in glyphs] or [4])
    cell_h = max([g[1] for g in glyphs] or [1])
    rows_count = (len(glyphs) + SHEET_COLUMNS - 1) // SHEET_COLUMNS or 1
    sheet_w = cell_w * SHEET_COLUMNS
    sheet_h = cell_h * rows_count
    sheet = [bytearray(sheet_w) for _ in range(sheet_h)]
    for index, (w, h, _, _, pixels, _, _) in enumerate(glyphs):
        left = (index % SHEET_COLUMNS) * cell_w
        top = (index // SHEET_COLUMNS) * cell_h
        for y in range(h):
            line = pixels[y * w * 2 : (y + 1) * w * 2]
            for i, byte in enumerate(line):
                sheet[top + y][left + i * 2] = byte & 0x0F
                sheet[top + y][left + i * 2 + 1] = byte >> 4
    packed = []
    for line in sheet:
        row = bytearray()
        for i in range(0, sheet_w, 2):
            row.append((line[i] << 4) | line[i + 1])
        packed.append(bytes(row))
    palette = [(i * 17, i * 17, i * 17, 255) for i in range(16)]
    png_path = base.with_suffix(".png")
    grpx.write_png(png_path, sheet_w, sheet_h, packed, palette, 4)

    chars = [g[6] for g in glyphs]
    dialogue_offsets = struct.unpack_from(f"<{dialogue_count}H", data, dialogue_table)
    starts = sorted(set(dialogue_offsets))
    lines: List[str] = [
        "magic: WFM3",
        f"unk4: 0x{unk4:X}",
        "sheet:",
        f"  file: {png_path.name}",
        f"  columns: {SHEET_COLUMNS}",
        f"  cell: [{cell_w}, {cell_h}]",
        "glyphs:",
    ]
    for index, (w, h, advance, handakuten, _, digest, char) in enumerate(glyphs):
        lines.append(
            f"  - {{ id: {index}, char: {_quote(char)}, w: {w * 4}, h: {h}, advance: {advance}, "
            f"handakuten: {handakuten}, hash: {digest} }}"
        )
    special = _special_dialogues(box_table)
    if special is None:
        lines.insert(2, f"group_table: [{', '.join(str(v) for v in box_table)}]")
    lines.append("dialogues:")
    for index, offset in enumerate(dialogue_offsets):
        later = [s for s in starts if s > offset]
        end = dialogue_table + later[0] if later else len(data)
        start = dialogue_table + offset
        count = (end - start) // 2
        tokens = struct.unpack_from(f"<{count}H", data, start)
        lines.append(f"  - id: {index}")
        if special is not None:
            lines.append(f"    special: {'true' if index in special else 'false'}")
        used = set()
        items = _dialogue_items(tokens, chars, used)
        heights = sorted({glyphs[g][1] for g in used if g < len(glyphs)})
        if len(heights) == 1:
            lines.append(f"    font: {heights[0]}")
        elif heights:
            lines.append(f"    font: [{', '.join(str(h) for h in heights)}]")
        lines.append("    content:")
        lines += _content_lines(items, "      ")
    base.with_suffix(".yaml").write_text("\n".join(lines) + "\n", encoding="utf-8")


class PSXSegWfm3(TombaSegment):
    """Kind 0xD0 and 0xD1: WFM3 font and dialogues, written as png + yaml."""

    EXTENSION = "wfm3"
