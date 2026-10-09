import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegWss(TombaSegment):
    """Kind 0xCx: the AREA15 .WSS files, which start with "WS" (table D_1F8002B8)."""

    EXTENSION = "wss"
