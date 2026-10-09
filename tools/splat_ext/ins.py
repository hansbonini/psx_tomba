import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegIns(TombaSegment):
    """Kind 0xF0: code overlay, loaded at 0x800E7388."""

    EXTENSION = "bin"
