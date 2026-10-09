import struct
import sys
from pathlib import Path
from typing import List, Optional

from splat.util import options

sys.path.insert(0, str(Path(__file__).parent))
import gam
import grpx
from none import TombaSegment, write_data


def rle_frames(data: bytes) -> Optional[List[bytes]]:
    """Frames of a sprite set, still packed.

    Layout read by func_8003A614: u32 count, then count + 1 offsets from the
    start of the data; frame n goes from offset n to offset n + 1.
    """
    if len(data) < 8:
        return None
    count = struct.unpack_from("<I", data, 0)[0]
    table_end = 4 + 4 * (count + 1)
    if count == 0 or table_end > len(data):
        return None
    offsets = struct.unpack_from(f"<{count + 1}I", data, 4)
    if offsets[0] != table_end or list(offsets) != sorted(offsets) or offsets[-1] > len(data):
        return None
    return [data[offsets[i] : offsets[i + 1]] for i in range(count)]


def rle_decode(src: bytes) -> bytes:
    """func_8003A614: a control byte, then one item per bit from bit 0 up.

    A set bit is a run (count byte, value byte, as fillBytesUnrolled takes
    them), a clear bit a literal byte. Like the game, the length is only
    checked when a control byte is read.
    """
    out = bytearray()
    pos = 0
    remaining = len(src)
    while True:
        if pos >= len(src):
            break
        control = src[pos]
        pos += 1
        remaining -= 1
        if remaining <= 0:
            break
        for bit in range(8):
            if control & (1 << bit):
                if pos + 1 >= len(src):
                    return bytes(out)
                out += bytes([src[pos + 1]]) * src[pos]
                pos += 2
                remaining -= 2
            else:
                if pos >= len(src):
                    return bytes(out)
                out.append(src[pos])
                pos += 1
                remaining -= 1
    return bytes(out)


def tim_archive(data: bytes) -> Optional[List[bytes]]:
    """The set script.c reads through 0x1F800354: a table of offsets, each to
    a GAM container that holds a TIM. The last offset is the end of the data."""
    if len(data) < 8:
        return None
    first = struct.unpack_from("<I", data, 0)[0]
    if first % 4 or first < 8 or first > len(data):
        return None
    offsets = struct.unpack_from(f"<{first // 4}I", data, 0)
    if list(offsets) != sorted(offsets) or offsets[-1] > len(data):
        return None
    if not gam.is_gam(data[offsets[0] :]):
        return None
    return [data[offsets[i] : offsets[i + 1]] for i in range(len(offsets) - 1)]


class PSXSegWpp(TombaSegment):
    """Kind 0x6x: Tomba sprite data (table D_1F800348).

    Two layouts are known and both are written as one PNG per image, in a
    folder named after the segment: the RLE frames func_8003A614 unpacks into
    a TIM (u16 width in VRAM words, u16 height, 4-bit pixels), and the table
    of compressed TIMs. Anything else is written as it is.
    """

    EXTENSION = "wpp"

    def split(self, rom_bytes: bytes):
        data = self.payload(rom_bytes)
        out_dir = options.opts.asset_path / self.dir / self.name
        frames = rle_frames(data)
        if frames is not None:
            digits = max(3, len(str(len(frames) - 1)))
            for i, packed in enumerate(frames):
                image = rle_decode(packed)
                w16, h = struct.unpack_from("<HH", image.ljust(4, bytes(1)), 0)
                grpx.write_png_vram(out_dir / f"{i:0{digits}d}.png", w16, h, image[4:], 4)
            self.log(f"Wrote {self.name} to {out_dir}")
            return
        archive = tim_archive(data)
        if archive is not None:
            for i, packed in enumerate(archive):
                write_data(out_dir / f"{i:02d}.tim", gam.lz_decompress(packed))
            self.log(f"Wrote {self.name} to {out_dir}")
            return
        path = write_data(self.out_path(), data)
        self.log(f"Wrote {self.name} to {path}")
