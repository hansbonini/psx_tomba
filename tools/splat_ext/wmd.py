import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegWmd(TombaSegment):
    """Kind 0x5x: 3D models (table D_1F800330)."""

    EXTENSION = "wmd"
