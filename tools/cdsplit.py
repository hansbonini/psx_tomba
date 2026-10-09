#!/usr/bin/env python3
"""Generates one splat config per CD file and splits them.

The segment type of each file is not guessed from its name: it is taken from
the load records the game itself walks (func_80021D70) and from what
func_80021340 does with a record of that type.

usage: python3 tools/cdsplit.py [--only AREA00/A000.GAM ...] [--no-split]
"""

import argparse
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools" / "splat_ext"))
import gam
import ldlist

ISO = ROOT / "iso" / "us"
EXE = ISO / "SCUS_942.36"
EXE_VRAM = 0x8000F800
CONFIG_DIR = ROOT / "build" / "cd" / "config"
ASSET_DIR = "assets/scus_942.36"

FILE_TABLE = 0x800791A0
# Pointer tables of record lists inside the executable (see cdfile.c).
EXE_LIST_TABLES = [
    (0x800782F4, 1),
    (0x800782F8, 20),
    (0x80078EB0, 52),
    (0x8007912C, 9),
]
# Pointers to record lists inside SYS/LDSYS.BIN, loaded at LDSYS_VRAM.
LDSYS_LIST_TABLE = (0x80079150, 20)

SPLIT_MODES = [
    "ldlist", "gam", "none", "grpx", "clut", "wvd", "str", "spr", "four", "wmd", "wpp",
    "whm", "apd", "clm", "unka", "seq", "wss", "wfm3", "ins",
]
MISSING = "missing in iso/us"


def enum_to_path(name: str) -> str:
    parts = name[len("FILE_") :].split("_")
    return f"{parts[0]}/{'_'.join(parts[1:-1])}.{parts[-1]}"


class Usage:
    def __init__(self, rec, source):
        self.rec = rec
        self.source = source
        self.subs = []

    def chunks(self):
        """Slices func_80021D70 registers for this file, or None."""
        rec = self.rec
        if rec.load_type not in (2, 3, 4) or rec.kind in (0xF0, 0xF8):
            return None
        if rec.kind_class not in ldlist.KIND_TYPES or rec.kind_class in (0x10, 0x20, 0x90):
            return None
        return [[r.kind, r.arg] for r in [rec] + self.subs]


def collect(exe: bytes, paths):
    usages = {}

    state = {"last": None}

    def add(rec, source):
        if rec.is_sub_record:
            if state["last"] is not None:
                state["last"].subs.append(rec)
            return
        state["last"] = None
        if rec.is_list_end or rec.file_id >= len(paths):
            return
        state["last"] = Usage(rec, source)
        usages.setdefault(rec.file_id, []).append(state["last"])

    def exe_off(addr):
        return addr - EXE_VRAM

    for table, count in EXE_LIST_TABLES:
        for i in range(count):
            ptr = struct.unpack_from("<I", exe, exe_off(table + i * 4))[0]
            for rec in ldlist.parse_record_list(exe, exe_off(ptr)):
                add(rec, f"exe:{ptr:08X}")

    ldsys = (ISO / "SYS" / "LDSYS.BIN").read_bytes()
    table, count = LDSYS_LIST_TABLE
    for i in range(count):
        ptr = struct.unpack_from("<I", exe, exe_off(table + i * 4))[0]
        off = ptr - ldlist.LDSYS_VRAM
        if 0 <= off < len(ldsys):
            for rec in ldlist.parse_record_list(ldsys, off):
                add(rec, f"LDSYS:{off:04X}")

    for path in sorted((ISO / "SYS").glob("LD*.BIN")):
        data = path.read_bytes()
        off = 4
        while off + ldlist.RECORD_SIZE <= len(data):
            add(ldlist.LoadRecord(data, off), f"{path.name}:{off:04X}")
            off += ldlist.RECORD_SIZE
    return usages


def kind_segment(kind: int) -> str:
    """Segment type of one kind of data: spr, clm, wfm3... or none."""
    named = ldlist.kind_type(kind)
    if not named:
        return "none"
    return named.split("_")[0].lower()


def describe(path: str, data: bytes, usages, bpp: int) -> dict:
    """Builds the top-level segment of a file.

    The type comes from the first load record that names the file; a file
    without a known kind is a none segment, written as it is. A record
    followed by sub-records makes a file with several kinds of data, one
    subsegment each. A compressed file is a gam segment and what it holds
    goes in its subsegments, always inside a folder named after the file;
    the .000 files, and a .GAM file that is not a GAM container, follow the
    same folder layout.
    """
    name = path.split("/")[1].replace(".", "_")
    seg = {"name": name, "type": "none", "vram": 0, "extra": {}, "subs": None, "end": None}
    if path.endswith(".STR"):
        seg["type"] = "str"
        return seg
    if path.startswith("SYS/LD"):
        seg["type"] = "ldlist"
        seg["vram"] = ldlist.LDSYS_VRAM if path == "SYS/LDSYS.BIN" else 0
        for u in usages:
            if u.source.startswith("exe:") and u.rec.addr:
                seg["vram"] = u.rec.addr
                break
        return seg

    compressed = gam.is_gam(data)
    payload = data
    if compressed:
        try:
            payload = gam.lz_decompress(data)
        except IndexError:
            payload = None

    leaf_type = "none"
    leaf_label = "NONE"
    leaf_extra = {}
    subs = None
    if usages:
        u = usages[0]
        rec = u.rec
        leaf_type = kind_segment(rec.kind) if rec.kind != 0xF8 else "ldlist"
        leaf_label = ldlist.kind_label(rec.kind) if leaf_type != "none" else "NONE"
        seg["vram"] = rec.addr
        if leaf_type == "grpx":
            leaf_extra = {"rect": [rec.x, rec.y, rec.w, rec.h]}
            seg["vram"] = 0
            if "CLUT" in name:
                seg["type"] = "clut"
                seg["extra"] = leaf_extra
                return seg
            leaf_extra["bpp"] = bpp
        elif leaf_type == "wvd":
            seg["type"] = "wvd"
            seg["vram"] = 0
            return seg
        elif leaf_type == "ins":
            seg["vram"] = ldlist.OVERLAY_VRAM
        chunks = u.chunks()
        if chunks and len(chunks) > 1 and payload is not None and sum(c[1] for c in chunks) == len(payload):
            subs = []
            offset = 0
            for i, (kind, size) in enumerate(chunks):
                subs.append((offset, kind_segment(kind), f"{i:02d}_{ldlist.kind_label(kind)}", {}))
                offset += size

    if compressed:
        seg["type"] = "gam"
        if payload is None:
            return seg
        seg["end"] = len(payload)
        seg["dir"] = name
        if subs is None:
            subs = [(0, leaf_type, f"00_{leaf_label}", leaf_extra)]
        seg["subs"] = subs
    elif subs is not None or path.endswith((".000", ".GAM")):
        if subs is None:
            subs = [(0, leaf_type, f"00_{leaf_label}", leaf_extra)]
        seg["type"] = "none"
        seg["dir"] = name
        seg["subs"] = subs
        seg["end"] = len(payload)
    else:
        seg["type"] = leaf_type
        seg["extra"] = leaf_extra
    return seg


def _inline(fields: dict) -> str:
    parts = []
    for key, value in fields.items():
        if isinstance(value, list):
            value = "[" + ", ".join(str(v) for v in value) + "]"
        parts.append(f"{key}: {value}")
    return "{ " + ", ".join(parts) + " }"


def write_config(path: str, size: int, seg: dict) -> Path:
    stem = path.replace("/", "_").replace(".", "_")
    directory = path.split("/")[0]
    fields = {"start": "0x0", "type": seg["type"], "name": seg["name"]}
    if seg["vram"]:
        fields["vram"] = f"0x{seg['vram']:08X}"
    if "dir" in seg:
        fields["dir"] = seg["dir"]
    fields.update(seg["extra"])
    lines = [
        f"name: {path}",
        "options:",
        f"  basename: {stem}",
        f"  target_path: ./iso/us/{path}",
        "  base_path: ../../../",
        "  platform: psx",
        "  compiler: PSYQ",
        f"  asset_path: ./{ASSET_DIR}/{directory}",
        "  extensions_path: ./tools/splat_ext",
        "  create_undefined_funcs_auto: False",
        "  create_undefined_syms_auto: False",
        "segments:",
    ]
    if seg["subs"] is None:
        lines.append("  - " + _inline(fields))
    else:
        first = True
        for key, value in fields.items():
            lines.append(f"  {'-' if first else ' '} {key}: {value}")
            first = False
        lines.append("    subsegments:")
        for start, sub_type, sub_name, extra in seg["subs"]:
            if extra:
                sub = {"start": f"0x{start:X}", "type": sub_type, "name": sub_name}
                sub.update(extra)
                lines.append("      - " + _inline(sub))
            else:
                lines.append(f"      - [0x{start:X}, {sub_type}, {sub_name}]")
        lines.append(f"      - [0x{seg['end']:X}]")
    lines.append(f"  - [0x{size:X}]")
    lines.append("")
    out = CONFIG_DIR / f"{stem}.yaml"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text("\n".join(lines))
    return out


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--only", nargs="*", default=None)
    parser.add_argument("--no-split", action="store_true")
    parser.add_argument("--vram-bpp", choices=["auto", "4", "8", "16", "24"], default="auto")
    args = parser.parse_args()

    names = ldlist.load_file_names(ROOT)
    paths = [enum_to_path(n) for n in names]
    exe = EXE.read_bytes()
    usages = collect(exe, paths)

    counts = {}
    sub_counts = {}
    failed = []
    for file_id, path in enumerate(paths):
        if args.only is not None and path not in args.only:
            continue
        source = ISO / path
        if not source.exists():
            failed.append((path, MISSING))
            continue
        data = source.read_bytes()
        bpp = 4 if args.vram_bpp == "auto" else int(args.vram_bpp)
        seg = describe(path, data, usages.get(file_id, []), bpp)
        config = write_config(path, len(data), seg)
        counts[seg["type"]] = counts.get(seg["type"], 0) + 1
        for sub in seg["subs"] or []:
            sub_counts[sub[1]] = sub_counts.get(sub[1], 0) + 1
        if args.no_split:
            continue
        result = subprocess.run(
            ["splat", "split", "--modes", *SPLIT_MODES, "--", str(config)],
            cwd=ROOT,
            stdin=subprocess.DEVNULL,
            capture_output=True,
            text=True,
        )
        if result.returncode != 0:
            lines = (result.stderr or result.stdout).strip().splitlines()
            failed.append((path, lines[-1] if lines else "splat failed"))

    for seg_type in sorted(counts):
        print(f"{seg_type:8} {counts[seg_type]}")
    if sub_counts:
        print("subsegments: " + ", ".join(f"{k} {sub_counts[k]}" for k in sorted(sub_counts)))
    missing = [path for path, reason in failed if reason == MISSING]
    if missing:
        print(f"{len(missing)} files missing in iso/us (first: {missing[0]})")
    for path, reason in failed:
        if reason != MISSING:
            print(f"FAILED {path}: {reason}")
    return 1 if len(failed) > len(missing) else 0


if __name__ == "__main__":
    sys.exit(main())
