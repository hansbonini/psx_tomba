import struct
from pathlib import Path
from typing import List, Optional, Tuple

from splat.segtypes.segment import Segment
from splat.util import options

def split_wvd(data: bytes) -> List[Tuple[bytes, bytes]]:
    """Returns one (vab header, vab body) pair per bank in the file.

    func_80021340 reads two offsets from the start of the file. Each points to
    a table of offsets relative to the table itself, whose first entry is the
    size of the table. The first table locates the bodies sent to the SPU with
    SpuRead, the second the headers given to SsVabFakeHead. The entry after the
    last body marks the end of the last body.
    """
    body_top, head_top = struct.unpack_from("<II", data, 0)
    count = (struct.unpack_from("<I", data, head_top)[0] >> 2) - 1
    heads = [head_top + struct.unpack_from("<I", data, head_top + i * 4)[0] for i in range(count + 1)]
    bodies = [body_top + struct.unpack_from("<I", data, body_top + i * 4)[0] for i in range(count + 1)]
    banks = []
    for i in range(count):
        banks.append((data[heads[i] : heads[i + 1]], data[bodies[i] : bodies[i + 1]]))
    return banks


class PSXSegWvd(Segment):
    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / self.name

    def split(self, rom_bytes: bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        out_dir = self.out_path()
        out_dir.mkdir(parents=True, exist_ok=True)
        for i, (head, body) in enumerate(split_wvd(data)):
            (out_dir / f"{i}.vh").write_bytes(head)
            (out_dir / f"{i}.vb").write_bytes(body)
        self.log(f"Wrote {self.name} to {out_dir}")
