import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegSeq(TombaSegment):
    """Kind 0xBx: sequenced music (table SEQ_DATA)."""

    EXTENSION = "seq"
