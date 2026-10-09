import shutil
import subprocess
import sys
from pathlib import Path
from typing import List, Optional

from splat.segtypes.segment import Segment
from splat.util import log, options

SECTOR_FORM2 = 2336
SECTOR_RAW = 2352
SYNC = bytes([0x00] + [0xFF] * 10 + [0x00])
FFMPEG_CANDIDATES = ["ffmpeg", "ffmpeg.exe", "/mnt/c/ProgramData/chocolatey/bin/ffmpeg.exe"]


def find_ffmpeg() -> Optional[str]:
    for candidate in FFMPEG_CANDIDATES:
        found = shutil.which(candidate)
        if found:
            return found
    return None


def native_path(ffmpeg: str, path: Path) -> str:
    """A Windows ffmpeg run from WSL needs Windows paths."""
    if ffmpeg.lower().endswith(".exe") and shutil.which("wslpath"):
        return subprocess.run(["wslpath", "-w", str(path)], capture_output=True, text=True).stdout.strip()
    return str(path)


def raw_sectors(data: bytes) -> bytes:
    """Rebuilds 2352-byte sectors from the 2336 bytes the disc image keeps for
    each Mode 2 sector (subheader + data), so a demuxer can find them."""
    out = bytearray()
    for i in range(0, len(data), SECTOR_FORM2):
        lba = i // SECTOR_FORM2 + 150
        header = bytes([lba // (75 * 60), (lba // 75) % 60, lba % 75])
        bcd = bytes(((b // 10) << 4) | (b % 10) for b in header)
        out += SYNC + bcd + b"\x02" + data[i : i + SECTOR_FORM2]
    return bytes(out)


class PSXSegStr(Segment):
    """A movie: the stream the game plays through the libcd streaming and
    libpress MDEC routines (src/scus_942.36/main/video/movie.c), with XA audio
    interleaved. It is handed to ffmpeg, which demuxes and decodes it, and
    written as MP4."""

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}.mp4"

    def split(self, rom_bytes: bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        if len(data) % SECTOR_FORM2:
            log.error(f"segment {self.name} is not made of {SECTOR_FORM2}-byte sectors")
        ffmpeg = find_ffmpeg()
        if ffmpeg is None:
            log.error("ffmpeg was not found; it is needed to turn a movie into MP4")
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        raw = path.with_suffix(".raw")
        raw.write_bytes(raw_sectors(data))
        command: List[str] = [
            ffmpeg, "-y", "-loglevel", "error", "-f", "psxstr", "-i", native_path(ffmpeg, raw),
            "-c:v", "libx264", "-pix_fmt", "yuv420p", "-c:a", "aac", native_path(ffmpeg, path),
        ]
        result = subprocess.run(command, stdin=subprocess.DEVNULL, capture_output=True, text=True)
        raw.unlink()
        if result.returncode != 0:
            log.error(f"ffmpeg failed on {self.name}: {result.stderr.strip()[-300:]}")
        self.log(f"Wrote {self.name} to {path}")
