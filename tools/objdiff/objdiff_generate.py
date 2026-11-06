# Adapted from https://github.com/Vatuu/silent-hill-decomp/tree/master

from pathlib import Path
from argparse import ArgumentParser
from dataclasses import dataclass, asdict
import logging
import yaml
import json
import re

@dataclass
class UnitMetadata:
    progress_categories: list[str]
    complete: bool = False

@dataclass
class Unit:
    name: str
    base_path: str
    target_path: str
    metadata: UnitMetadata

@dataclass
class ProgressCategory:
    id: str
    name: str

@dataclass
class Config:
    build_base: bool
    build_target: bool
    custom_make: str
    custom_args: list[str]
    units: list[Unit]
    progress_categories: list[ProgressCategory]


def _create_config():
    parser = ArgumentParser()
    parser.add_argument("config", type = Path)
    args = parser.parse_args()

    if not args.config.exists() or args.config.is_dir() or args.config.suffix != ".yaml":
        raise ValueError(f"The given path {args.objects} is not pointing towards a valid config.")

    with open(args.config) as stream:
        try:
            return yaml.safe_load(stream)
        except yaml.YAMLError as exc:
            raise exc

EXCLUDED_NAMES = {"data", "rodata", "sdata", "bss"}

def _collect_objects(path: Path, config) -> list[Path]:
    ignored = config["ignored_files"]
    return [
        path for path in path.rglob("*.o")
        if not any(name in path.name for name in EXCLUDED_NAMES ) and not any(file in str(path) for file in ignored)
    ]

def _determine_categories(path: Path, config) -> tuple[UnitMetadata, str]:
    if path.name.endswith(".s.o"):
        modified_path = path.relative_to(config["expected_paths"]["asm"])
    else:
        modified_path = path.relative_to(config["expected_paths"]["src"])

    unit = _split_path(str(modified_path))[2]
    categories = []
    for category in config["categories"]:
        for prefix in category["paths"]:
            if unit.startswith(prefix):
                categories.append(category["id"])
    return (UnitMetadata(categories), str(modified_path))

def _split_path(path: str) -> tuple[str, str, str]:
    # <version>[/exe/<main>]/<unit>: the European MAINn.EXE build apart
    parts = path.split("/")
    if len(parts) > 3 and parts[1] == "exe":
        return parts[0], "/".join(parts[1:3]), "/".join(parts[3:])
    return parts[0], "", "/".join(parts[1:])

def _get_base_path(path: Path) -> Path:
    # <version>[/exe/<main>]/<unit> -> build/<version>[/exe/<main>]/src/<unit>
    version, exe, unit = _split_path(path.removesuffix(".s.o").removesuffix(".c.o"))
    name = "/".join(x for x in ("build", version, exe, "src", unit) if x)
    c_path = name + ".c.o"
    hasm_path = name + ".hasm.s.o"
    if Path(c_path).exists(): return c_path
    if Path(hasm_path).exists(): return hasm_path
    if Path(name + ".s.o").exists(): return name + ".s.o"
    return None

_AREA_START = {}


def _engine_copy(unit: str) -> bool:
    """A unit of the engine inside an Xnn other than X00: the engine is the
    same in all of them and counts once. Named ones are engine*; the unnamed
    pieces are named by their offset, below the start of the area module."""
    m = re.match(r"([^/]+)/overlays/(x\d\d)/(?:\.\./x00/)?(\w+)$", unit)
    if not m or m.group(2) == "x00":
        return False
    version, ov, name = m.groups()
    if name.startswith("engine"):
        return True
    if not re.fullmatch(r"[0-9A-F]+", name):
        return False
    if (version, ov) not in _AREA_START:
        cfg = Path("config") / version / (ov + ".yaml")
        s = re.search(r"- name: %s\n\s+type: code\n\s+start: (0x[0-9A-Fa-f]+)" % ov,
                      cfg.read_text().replace("\r\n", "\n")) if cfg.exists() else None
        _AREA_START[(version, ov)] = int(s.group(1), 16) if s else 0
    return int(name, 16) < _AREA_START[(version, ov)]


DATA_KINDS = ("data", "rodata", "sdata", "bss", "sbss")


def _data_blobs(asm_root: Path) -> list[Path]:
    """Data files with no code unit of the same name (blobs between units)."""
    blobs = []
    for p in asm_root.rglob("*.s.o"):
        rel = p.relative_to(asm_root)
        if "data" not in rel.parts or not any(p.name.endswith(".%s.s.o" % k) for k in DATA_KINDS):
            continue
        i = rel.parts.index("data")
        unit = Path(*rel.parts[:i], *rel.parts[i + 1:])
        stem = str(unit).rsplit(".", 3)[0]
        if not (asm_root / (stem + ".s.o")).exists():
            blobs.append(p)
    return blobs


def _source_complete(base_path) -> bool:
    """A unit whose C is linked whole: no INCLUDE_ASM / INCLUDE_RODATA left."""
    if base_path is None:
        return False
    if base_path.endswith(".s.o"):
        return True
    m = re.match(r"build/[^/]+/(?:exe/[^/]+/)?(src/.+\.c)\.o$", base_path)
    if not m or not Path(m.group(1)).exists():
        return False
    text = Path(m.group(1)).read_text(errors="replace")
    return not re.search(r"^\s*INCLUDE_(ASM|RODATA)\s*\(", text, re.M)


def main():
    logging.basicConfig(level = logging.INFO)
    config = _create_config()
    asm_root = Path(config["expected_paths"]["asm"])

    expected_objects = _collect_objects(asm_root, config) + _collect_objects(Path(config["expected_paths"]["src"]), config)

    logging.info(f"Accounting for {len(expected_objects)} objects.")
    units = []
    for file in expected_objects:
        processed_path = _determine_categories(file, config)
        name = processed_path[1].removesuffix(".s.o").removesuffix(".c.o")
        # the engine is the same in every Xnn: it counts once, in X00
        if _engine_copy(name):
            continue
        base = _get_base_path(processed_path[1])
        processed_path[0].complete = _source_complete(base)
        units.append(Unit(name, base, str(file), processed_path[0]))

    # data with no code unit: counted, with nothing to match against yet
    for file in _data_blobs(asm_root):
        rel = file.relative_to(asm_root)
        if any(f in str(rel) for f in config["ignored_files"]):
            continue
        version, exe, unit = _split_path(str(rel).replace("data/", "", 1))
        if _engine_copy("/".join(x for x in (version, exe, unit.rsplit(".", 3)[0]) if x)):
            continue
        categories = [c["id"] for c in config["categories"]
                      if any(unit.startswith(p) for p in c["paths"])] or ["main"]
        stem = "/".join(x for x in (version, exe, unit.rsplit(".", 3)[0]) if x)
        base = _get_base_path(stem + ".s.o")
        units.append(Unit(str(rel).removesuffix(".s.o"), base, str(file),
                          UnitMetadata(categories, _source_complete(base))))
    
    # only the categories this release has units in (no overlays where there
    # are none, no X07/X12/X15)
    used = {c for unit in units for c in unit.metadata.progress_categories}
    categories = []
    for category in config["categories"]:
        if category["id"] in used:
            categories.append(ProgressCategory(category["id"], category["name"]))
    
    with (Path(config["output"])).open("w") as json_file:
        json.dump(asdict(Config(True, False, "make", ["progress"], units, categories)), json_file, indent=2)

if __name__ == "__main__":
    main()