import re
import struct
from pathlib import Path
from typing import List, Optional

from splat.segtypes.segment import Segment
from splat.util import options

RECORD_SIZE = 0x14
LIST_END = 0xFFFF
SUB_RECORD = 0xFFFFFFFF

LDSYS_VRAM = 0x80097FA8
OVERLAY_VRAM = 0x800E7388

# Data kinds, keyed by the high nibble of record byte 3 as dispatched by
# func_80021D70. Each entry: name, what it is, and the table where the
# routine stores the pointer of the data. The low nibble of the byte is the
# slot in that table, so 0x32 is SPR_2. Kinds 0x8E/0x8F (CLM), 0xD0/0xD1
# (WFM3_TXT/WFM3_EVT) and 0xF0 (INS) are named in kind_type.
KIND_TYPES = {
    0x10: ("GRPX", "VRAM image", None),
    0x20: ("NONE", "nothing is stored", None),
    0x30: ("SPR", "sprite data", "D_1F8002C8"),
    0x40: ("FOUR", "unknown", "D_1F800310"),
    0x50: ("WMD", "3D models", "D_1F800330"),
    0x60: ("WPP", "Tomba sprite data", "D_1F800348"),
    0x70: ("WHM", "collision plane data", "D_1F800308"),
    0x80: ("APD", "asset placement data, collision map in slots 14 and 15", "D_1F800358"),
    0x90: ("WVD", "sound bank", "D_8009C658"),
    0xA0: ("UNKA", "unknown", "D_8009C758"),
    0xB0: ("SEQ", "sequenced music", "SEQ_DATA"),
    0xC0: ("WSS", "AREA15 files, start with \"WS\"", "D_1F8002B8"),
    0xD0: ("WFM3", "font and dialogues", "D_1F800398"),
}


def kind_type(kind: int) -> str:
    """GRPX, SPR_3, CLM_0, WFM3_TXT, INS... or "" when the kind has no name."""
    if kind == 0xF0:
        return "INS"
    if kind == 0xD0:
        return "WFM3_TXT"
    if kind == 0xD1:
        return "WFM3_EVT"
    if kind in (0x8E, 0x8F):
        return f"CLM_{kind - 0x8E}"
    entry = KIND_TYPES.get(kind & 0xF0)
    if entry is None:
        return ""
    name = entry[0]
    if name in ("GRPX", "NONE"):
        return name
    return f"{name}_{kind & 0xF}"


# Low nibble of the type word, as switched on by func_80021340.
TYPE_NAMES = {
    0: "STAGING",
    1: "LZ_TO_VRAM",
    2: "RAW",
    3: "LZ_TO_RAM",
    4: "RAW",
}


class LoadRecord:
    def __init__(self, data: bytes, offset: int):
        self.offset = offset
        (
            self.file_id,
            self.slot,
            self.kind,
            self.addr,
            self.arg,
            self.w,
            self.h,
            self.type,
        ) = struct.unpack_from("<HBBIIHHI", data, offset)

    @property
    def is_list_end(self) -> bool:
        return self.file_id == LIST_END

    @property
    def is_sub_record(self) -> bool:
        return self.type == SUB_RECORD

    @property
    def x(self) -> int:
        return self.arg & 0xFFFF

    @property
    def y(self) -> int:
        return self.arg >> 16

    @property
    def kind_class(self) -> int:
        return self.kind & 0xF0

    @property
    def kind_index(self) -> int:
        return self.kind & 0xF

    @property
    def load_type(self) -> int:
        return self.type & 0xF

    @property
    def alt_buffer(self) -> bool:
        return not self.is_sub_record and (self.type & 0x10) != 0

    def kind_name(self) -> str:
        if self.kind == 0xF8:
            return "LDSYS"
        return kind_type(self.kind) or f"0x{self.kind:02X}"

    def type_name(self) -> str:
        if self.is_sub_record:
            return "SUB"
        name = TYPE_NAMES.get(self.load_type, f"0x{self.type:X}")
        if self.alt_buffer:
            name += "|ALT_BUFFER"
        return name


def parse_record_list(data: bytes, offset: int) -> List[LoadRecord]:
    """Walk one list the way func_80021D70 does: until file_id == -1."""
    records = []
    while offset + RECORD_SIZE <= len(data):
        rec = LoadRecord(data, offset)
        records.append(rec)
        offset += RECORD_SIZE
        if rec.is_list_end:
            break
    return records


def load_file_names(base_path: Path) -> List[str]:
    """CdFile enum names, in table order, from include/cdfiles.h."""
    names: List[str] = []
    header = base_path / "include" / "cdfiles.h"
    if not header.exists():
        return names
    for m in re.finditer(r"^\s+(FILE_\w+) = (\d+),", header.read_text(), re.M):
        assert int(m.group(2)) == len(names)
        names.append(m.group(1))
    return names


def kind_label(kind: int) -> str:
    return kind_type(kind) or f"kind{kind:02X}"


class PSXSegLdlist(Segment):
    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.ldlist.txt"

    def split(self, rom_bytes: bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        names = load_file_names(options.opts.base_path)
        vram = self.vram_start if isinstance(self.vram_start, int) else 0
        lines = [f"header 0x{struct.unpack_from('<I', data, 0)[0]:X}"]
        offset = 4
        new_list = True
        while offset + RECORD_SIZE <= len(data):
            rec = LoadRecord(data, offset)
            if new_list:
                lines.append("")
                lines.append(f"list_{vram + offset:08X}:")
                new_list = False
            if rec.is_list_end:
                lines.append(f"    /* {offset:04X} */ end")
                new_list = True
            else:
                if rec.file_id < len(names):
                    name = names[rec.file_id]
                else:
                    name = f"0x{rec.file_id:04X}"
                if rec.is_sub_record:
                    name = "-"
                slot = "-" if rec.slot == 0xFF else f"0x{rec.slot:02X}"
                if rec.kind_class == 0x10:
                    arg = f"rect=({rec.x}, {rec.y}, {rec.w}, {rec.h})"
                else:
                    arg = f"size=0x{rec.arg:X} w=0x{rec.w:X} h=0x{rec.h:X}"
                lines.append(
                    f"    /* {offset:04X} */ {rec.type_name():<20} {rec.kind_name():<16} "
                    f"slot={slot:<4} addr=0x{rec.addr:08X} {arg:<34} {name}"
                )
            offset += RECORD_SIZE
        if offset < len(data):
            lines.append("")
            lines.append(f"trailing_{vram + offset:08X}:")
            lines.append("    " + data[offset:].hex())
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("\n".join(lines) + "\n")
        self.log(f"Wrote {self.name} to {path}")
