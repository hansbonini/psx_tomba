import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegSpr(TombaSegment):
    """Kind 0x3x: sprite data (table D_1F8002C8)."""

    EXTENSION = "spr"
