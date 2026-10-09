import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegClm(TombaSegment):
    """Kind 0x8E and 0x8F: collision map (table D_1F800358)."""

    EXTENSION = "clm"
