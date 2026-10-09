import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegFour(TombaSegment):
    """Kind 0x4x: unknown (table D_1F800310)."""

    EXTENSION = "four"
