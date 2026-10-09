import struct
import sys
from pathlib import Path
from typing import Optional

from splat.segtypes.segment import Segment
from splat.util import log, options

sys.path.insert(0, str(Path(__file__).parent))
import gam

ACT_COLORS = 256


def act_from_words(words: bytes) -> bytes:
    """Adobe Color Table: 256 R, G, B triplets.

    A table with fewer colours is padded to 256 and gets the optional 4-byte
    trailer (colour count, transparent index 0xFFFF = none), both big-endian.
    """
    out = bytearray()
    count = 0
    for (value,) in struct.iter_unpack("<H", words[: ACT_COLORS * 2]):
        r = value & 0x1F
        g = (value >> 5) & 0x1F
        b = (value >> 10) & 0x1F
        out += bytes(((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2)))
        count += 1
    out += bytes((ACT_COLORS - count) * 3)
    if count < ACT_COLORS:
        out += struct.pack(">HH", count, 0xFFFF)
    return bytes(out)


class PSXSegClut(Segment):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        if not isinstance(self.yaml, dict) or "rect" not in self.yaml:
            log.error(f"segment {self.name} needs rect: [x, y, w, h]")
        self.rect = [int(v) for v in self.yaml["rect"]]

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / self.name

    def split(self, rom_bytes: bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        if gam.is_gam(data):
            data = gam.lz_decompress(data)
        w, h = self.rect[2], self.rect[3]
        size = w * h * 2
        data = data[:size].ljust(size, bytes(1))
        out_dir = self.out_path()
        out_dir.mkdir(parents=True, exist_ok=True)
        digits = len(str(max(h - 1, 0)))
        for row in range(h):
            words = data[row * w * 2 : (row + 1) * w * 2]
            for part in range(0, w, ACT_COLORS):
                suffix = f"_{part // ACT_COLORS}" if w > ACT_COLORS else ""
                name = f"{row:0{max(digits, 2)}d}{suffix}.act"
                (out_dir / name).write_bytes(act_from_words(words[part * 2 : (part + ACT_COLORS) * 2]))
        self.log(f"Wrote {self.name} to {out_dir}")
