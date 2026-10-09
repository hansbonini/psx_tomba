import sys
from pathlib import Path

from splat.util import log

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaGroup


def lz_decompress(src: bytes) -> bytes:
    pos = 4
    size = src[pos] | (src[pos + 1] << 8) | (src[pos + 2] << 16) | (src[pos + 3] << 8)
    pos += 4
    bitmask = src[pos] | (src[pos + 1] << 8)
    pos += 2
    current_bit = 0
    out = bytearray()
    while True:
        if (bitmask >> current_bit) & 1:
            off = src[pos]
            length = src[pos + 1]
            pos += 2
            start = len(out) - off
            for i in range(length):
                idx = start + i
                out.append(out[idx] if 0 <= idx < len(out) else 0)
        else:
            out.append(src[pos])
            pos += 1
        current_bit += 1
        if current_bit > 15:
            bitmask = src[pos] | (src[pos + 1] << 8)
            pos += 2
            current_bit = 0
        if size <= len(out):
            break
    return bytes(out[:size])


def is_gam(data: bytes) -> bool:
    return data[:3] == b"GAM"


class PSXSegGam(TombaGroup):
    """A GAM container: "GAM", the size and data packed for lzDecompress.

    What is inside goes in subsegments (grpx, spr, wmd, seq, wfm3...), whose
    offsets are counted in the decompressed data:

        - name: A006_GAM
          type: gam
          start: 0x0
          dir: A006_GAM
          subsegments:
            - [0x0, wpp, 00_WPP_3]
            - [0x18C8, spr, 01_SPR_0]
            - [0x1CEF0]

    Without subsegments the decompressed data is written as it is.
    """

    def payload(self, rom_bytes: bytes) -> bytes:
        data = rom_bytes[self.rom_start : self.rom_end]
        if not is_gam(data):
            log.error(f"segment {self.name} is not a GAM container")
        return lz_decompress(data)
