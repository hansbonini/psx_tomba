import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from none import TombaSegment


class PSXSegUnka(TombaSegment):
    """Kind 0xAx: unknown (table D_8009C758)."""

    EXTENSION = "unka"
