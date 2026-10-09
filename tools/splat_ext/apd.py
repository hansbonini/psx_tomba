import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegApd(TombaSegment):
    """Kind 0x80-0x8D: asset placement data (table D_1F800358)."""

    EXTENSION = "apd"
