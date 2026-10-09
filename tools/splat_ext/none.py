"""The none segment and the base classes of the other segment types.

TombaSegment is one kind of data (spr, wmd, seq, wfm3...). TombaGroup is a
file that holds subsegments: none reads them straight from the file, gam
first runs the file through lz_decompress, so the offsets of its subsegments
are offsets into the decompressed data.
"""

import sys
from pathlib import Path
from typing import Optional

from splat.segtypes.common.group import CommonSegGroup
from splat.segtypes.segment import Segment
from splat.util import options

sys.path.insert(0, str(Path(__file__).parent))


def write_data(path: Path, data: bytes) -> Path:
    """Writes one piece of data, converting the formats that are known."""
    import grpx
    import wfm3

    if wfm3.is_wfm(data):
        wfm3.write_wfm(path.with_suffix(""), data)
        return path.with_suffix(".png")
    if grpx.is_tim(data):
        grpx.write_tim_png(path.with_suffix(".png"), data)
        return path.with_suffix(".png")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)
    return path


class TombaSegment(Segment):
    EXTENSION = "bin"

    def payload(self, rom_bytes: bytes) -> bytes:
        import gam

        data = rom_bytes[self.rom_start : self.rom_end]
        if gam.is_gam(data):
            data = gam.lz_decompress(data)
        return data

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.{self.EXTENSION}"

    def split(self, rom_bytes: bytes):
        path = write_data(self.out_path(), self.payload(rom_bytes))
        self.log(f"Wrote {self.name} to {path}")


class TombaGroup(CommonSegGroup):
    """A file made of subsegments.

    The subsegments are split against payload(), not against the file, and the
    list has to finish with an end marker ([size of the payload]) because the
    end of the last subsegment cannot be taken from the size of the file.
    """

    def payload(self, rom_bytes: bytes) -> bytes:
        return rom_bytes[self.rom_start : self.rom_end]

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.bin"

    def scan(self, rom_bytes: bytes):
        pass

    def split(self, rom_bytes: bytes):
        data = self.payload(rom_bytes)
        if not self.subsegments:
            path = write_data(self.out_path(), data)
            self.log(f"Wrote {self.name} to {path}")
            return
        for sub in self.subsegments:
            if sub.should_split():
                sub.split(data)


class PSXSegNone(TombaGroup):
    """Uncompressed data that has no kind of its own.

    Without subsegments nothing is known about it and it is written as it is:
    a file no load record names, or one of kind 0x2x. With subsegments it is a
    file that holds several kinds of data in a row, one per record of
    func_80021D70 (the record of the file and each sub-record after it).
    """
