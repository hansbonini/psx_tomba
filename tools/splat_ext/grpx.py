"""The grpx segment and the PNG output of the image data the game sends to VRAM.

No external dependency: the PNG is written with zlib from the standard library.
"""

import struct
import sys
import zlib
from pathlib import Path
from typing import List, Optional, Tuple

from splat.util import log, options

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


def _chunk(tag: bytes, payload: bytes) -> bytes:
    crc = zlib.crc32(tag + payload) & 0xFFFFFFFF
    return struct.pack(">I", len(payload)) + tag + payload + struct.pack(">I", crc)


def write_png(path: Path, w: int, h: int, rows: List[bytes], palette=None, bit_depth: int = 8) -> None:
    """rows holds RGBA bytes per row, or packed palette indices when palette is given."""
    path.parent.mkdir(parents=True, exist_ok=True)
    color_type = 3 if palette is not None else 6
    out = b"\x89PNG\r\n\x1a\n"
    out += _chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, bit_depth, color_type, 0, 0, 0))
    if palette is not None:
        out += _chunk(b"PLTE", b"".join(bytes(c[:3]) for c in palette))
        out += _chunk(b"tRNS", bytes(c[3] for c in palette))
    out += _chunk(b"IDAT", zlib.compress(b"".join(b"\0" + r for r in rows), 9))
    out += _chunk(b"IEND", b"")
    path.write_bytes(out)


def rgba_from_psx(value: int) -> Tuple[int, int, int, int]:
    """15-bit colour plus the STP bit.

    0x0000 is the transparent colour. The STP bit of any other colour is kept
    in the alpha channel (128) so the PNG can be converted back.
    """
    r = value & 0x1F
    g = (value >> 5) & 0x1F
    b = (value >> 10) & 0x1F
    if value == 0:
        alpha = 0
    elif value & 0x8000 and value != 0x8000:
        alpha = 128
    else:
        alpha = 255
    return ((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2), alpha)


def write_png16(path: Path, w: int, h: int, pixels: bytes) -> None:
    """Pixels as LoadImage receives them: w * h little-endian 16-bit words."""
    size = w * h * 2
    pixels = pixels[:size].ljust(size, b"\0")
    rows = []
    for y in range(h):
        row = bytearray()
        for value in struct.unpack_from(f"<{w}H", pixels, y * w * 2):
            row += bytes(rgba_from_psx(value))
        rows.append(bytes(row))
    write_png(path, w, h, rows)


def write_png_vram(path: Path, w16: int, h: int, pixels: bytes, bpp: int = 16) -> None:
    """A block of VRAM words read as 4 or 8-bit indices, 16-bit colour or
    24-bit colour (three bytes per pixel).

    LoadImage data carries no depth and no CLUT, so indexed pages are written
    with a grey ramp as palette.
    """
    if bpp == 16:
        write_png16(path, w16, h, pixels)
        return
    stride = w16 * 2
    size = stride * h
    pixels = pixels[:size].ljust(size, b"\0")
    rows = [pixels[y * stride : (y + 1) * stride] for y in range(h)]
    if bpp == 4:
        rows = [bytes(((b & 0x0F) << 4) | (b >> 4) for b in row) for row in rows]
        palette = [(i * 17, i * 17, i * 17, 255) for i in range(16)]
        write_png(path, w16 * 4, h, rows, palette, 4)
    elif bpp == 8:
        palette = [(i, i, i, 255) for i in range(256)]
        write_png(path, w16 * 2, h, rows, palette, 8)
    elif bpp == 24:
        w = stride // 3
        rgba = []
        for row in rows:
            line = bytearray()
            for i in range(w):
                line += row[i * 3 : i * 3 + 3] + b"\xff"
            rgba.append(bytes(line))
        write_png(path, w, h, rgba)
    else:
        raise ValueError(f"bpp must be 4, 8, 16 or 24, not {bpp}")


def is_tim(data: bytes) -> bool:
    if len(data) < 20 or data[:4] != b"\x10\x00\x00\x00":
        return False
    return data[4] in (0, 1, 2, 3, 8, 9) and data[5:8] == b"\0\0\0"


def write_tim_png(path: Path, data: bytes) -> None:
    """Converts a TIM to PNG.

    4 and 8 bit images become palette PNGs using the first CLUT row. When the
    CLUT block holds more than one palette it is also written whole as
    <name>.clut.png.
    """
    flags = struct.unpack_from("<I", data, 4)[0]
    mode = flags & 7
    pos = 8
    palette = None
    if flags & 8:
        clut_len, _, _, cw, ch = struct.unpack_from("<IHHHH", data, pos)
        clut = data[pos + 12 : pos + clut_len]
        count = 16 if mode == 0 else 256
        total = min(cw * ch, len(clut) // 2)
        colors = struct.unpack_from(f"<{total}H", clut, 0)
        palette = [rgba_from_psx(v) for v in colors[:count]]
        palette += [(0, 0, 0, 0)] * (count - len(palette))
        if ch > 1 or cw > count:
            write_png16(path.with_suffix(".clut.png"), cw, ch, clut)
        pos += clut_len
    _, _, _, w16, h = struct.unpack_from("<IHHHH", data, pos)
    img_len = struct.unpack_from("<I", data, pos)[0]
    pixels = data[pos + 12 : pos + img_len]
    stride = w16 * 2
    if mode == 0:
        rows = []
        for y in range(h):
            src = pixels[y * stride : (y + 1) * stride].ljust(stride, b"\0")
            rows.append(bytes(((b & 0x0F) << 4) | (b >> 4) for b in src))
        if palette is None:
            palette = [(i * 17, i * 17, i * 17, 255) for i in range(16)]
        write_png(path, w16 * 4, h, rows, palette, 4)
    elif mode == 1:
        rows = [pixels[y * stride : (y + 1) * stride].ljust(stride, b"\0") for y in range(h)]
        if palette is None:
            palette = [(i, i, i, 255) for i in range(256)]
        write_png(path, w16 * 2, h, rows, palette, 8)
    elif mode == 2:
        write_png16(path, w16, h, pixels)
    else:
        w = (w16 * 2) // 3
        rows = []
        for y in range(h):
            src = pixels[y * stride : y * stride + w * 3].ljust(w * 3, b"\0")
            row = bytearray()
            for i in range(w):
                row += src[i * 3 : i * 3 + 3] + b"\xff"
            rows.append(bytes(row))
        write_png(path, w, h, rows)


class PSXSegGrpx(TombaSegment):
    """Kind 0x1x: pixels func_80021340 sends to VRAM with LoadImage.

    The record gives the rectangle; the file is raw (load type 0) or a GAM
    container (load type 1). LoadImage data has no depth, so bpp says how to
    read the words: 4 or 8 as indices shown with a grey ramp, 16 or 24 as
    colours.
    """

    EXTENSION = "png"

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        if not isinstance(self.yaml, dict) or "rect" not in self.yaml:
            log.error(f"segment {self.name} needs rect: [x, y, w, h]")
        self.rect = [int(v) for v in self.yaml["rect"]]
        self.bpp = int(self.yaml.get("bpp", 16))

    def split(self, rom_bytes: bytes):
        path = self.out_path()
        write_png_vram(path, self.rect[2], self.rect[3], self.payload(rom_bytes), self.bpp)
        self.log(f"Wrote {self.name} to {path}")
