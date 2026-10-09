import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegWhm(TombaSegment):
    """Kind 0x7x: collision plane data (table D_1F800308)."""

    EXTENSION = "whm"
