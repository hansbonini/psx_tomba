"""Bounded retail-byte checks for the player dispatcher/recovery/animation group.

Compile the actual complete engine_2.c unit, isolate only its compiler-generated
function blocks, assemble/link them with original bindings, and compare all text
and switch-table bytes. This does not perform a full-project make check.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys


BASE = '885c286d3fd068cca4fbfd11263fa99dac916705'
FUNCTIONS = {
    'updatePlayer': (0x80101574, 2020),
    'func_800F41C8': (0x800F41C8, 52),
    'func_800F41FC': (0x800F41FC, 52),
    'func_80100BCC': (0x80100BCC, 204),
}
PAL_HELPERS = {
    'func_800F41C8': 0x800F4E68,
    'func_800F41FC': 0x800F4E9C,
    'func_80100BCC': 0x8010186C,
}


def undefined_symbols(data):
    assert data[:6] == b'\x7fELF\x01\x01'
    offset = struct.unpack_from('<I', data, 32)[0]
    size, count = struct.unpack_from('<HH', data, 46)
    sections = [struct.unpack_from('<10I', data, offset + i * size) for i in range(count)]
    result = set()
    for section in sections:
        if section[1] != 2:
            continue
        strings = sections[section[6]]
        names = data[strings[4]:strings[4] + strings[5]]
        for at in range(section[4], section[4] + section[5], section[9]):
            name, value, length, info, other, index = struct.unpack_from('<IIIBBH', data, at)
            if name and index == 0:
                result.add(names[name:names.index(b'\0', name)].decode())
    return result


def bindings_from(paths):
    result = {}
    for path in paths:
        for name, value in re.findall(r'([A-Za-z_]\w*)\s*=\s*(0x[0-9a-fA-F]+)', path.read_text()):
            result.setdefault(name, int(value, 16))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--us-overlay', type=Path, required=True)
    parser.add_argument('--eu2-overlay', type=Path, help='Optional configured EU2 Rev 1 X000.BIN')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--commands', type=Path, help='Optional JSON command arrays for host adapters')
    parser.add_argument('--check-fallbacks', action='store_true', help='Compare inactive regional preprocessing against the recorded base')
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    out = (root / args.out).resolve()
    assert out.is_relative_to(root) and not out.exists(), 'Use a fresh directory inside the worktree'
    us = args.us_overlay.read_bytes()
    assert hashlib.sha1(us).hexdigest() == '2ba0d06824c940ab40c4c4031f3e3b8e9ead1b89', 'Unsupported US overlay'
    pal = args.eu2_overlay.read_bytes() if args.eu2_overlay else None
    if pal is not None:
        assert hashlib.sha1(pal).hexdigest() == 'ce168475f667f2ca8842eabad2aec829e301c5c5', 'Unsupported EU2 overlay'
    out.mkdir(parents=True)
    commands = dict(cpp=['mips-linux-gnu-cpp'], cc1=['tools/gcc-2.7.2-psx/cc1'],
                    maspsx=[sys.executable, 'tools/maspsx/maspsx.py'],
                    assembler=['mips-linux-gnu-as'], linker=['mips-linux-gnu-ld'],
                    objcopy=['mips-linux-gnu-objcopy'])
    if args.commands:
        overrides = json.loads(args.commands.read_text())
        assert set(overrides) <= set(commands)
        assert all(isinstance(v, list) and v and all(isinstance(x, str) for x in v) for v in overrides.values())
        commands.update(overrides)

    def rel(path):
        return path.relative_to(root).as_posix()

    def run(label, command, data=None):
        result = subprocess.run(command, cwd=root, input=data, capture_output=True)
        (out / (label + '.stderr')).write_bytes(result.stderr)
        if result.returncode:
            raise RuntimeError(label + ' failed: ' + result.stderr.decode(errors='replace'))
        return result.stdout

    def preprocess(source, region, version, label):
        return run(label, commands['cpp'] + ['-E', '-P', '-undef', '-nostdinc', '-Iinclude', '-Isrc/overlays/x00',
            '-D_LANGUAGE_C', '-DSKIP_ASM', '-DREGION=' + region, '-DVERSION=' + version, source])

    source = 'src/overlays/x00/engine_2.c'
    (out / 'unit.i').write_bytes(preprocess(source, 'REGION_US', '0', 'cpp-us'))
    run('cc1', commands['cc1'] + ['-O2', '-G0', '-mips1', '-mcpu=3000', '-funsigned-char',
        '-gcoff', '-quiet', rel(out / 'unit.i'), '-o', rel(out / 'unit.s')])
    assembly = run('maspsx', commands['maspsx'] + ['--aspsx-version=2.56', '--expand-div',
        '--use-comm-section'], (out / 'unit.s').read_bytes()).decode()
    files = '\n'.join(re.findall(r'^\.file[^\n]*', assembly, re.M))
    us_values = bindings_from(sorted((root / 'symbols/scus_942.36').glob('*.txt')))
    pal_values = bindings_from([root / 'symbols/sces_013.31' / name for name in
        ['main0_symbol_addrs.txt', 'main0_undefined_syms.txt', 'x00_symbol_addrs.txt']])
    # Additional PAL bindings documented by the matching Tombi-Decomp reference
    # playerSetAnimPairA/B and playerEventLandReset; verified below against retail.
    pal_values.update(D_80114570=0x80115220, D_80114578=0x80115228, D_800108A8=0x80010748)
    reports = []
    for name, (address, length) in FUNCTIONS.items():
        block = re.search(r'^\.ent\s+' + name + r'\s*$.*?^\.end\s+' + name + r'\s*$', assembly, re.M | re.S)
        assert block, 'Missing compiler-generated function: ' + name
        asm = files + '\n.text\n.set noreorder\n.globl ' + name + '\n' + block[0] + '\n'
        (out / 'function.s').write_text(asm)
        run(name + '-as', commands['assembler'] + ['-EL', '-O2', '-G0', '-Iinclude', '-march=r3000',
            '-mtune=r3000', '-no-pad-sections', rel(out / 'function.s'), '-o', rel(out / 'function.o')])
        undefined = undefined_symbols((out / 'function.o').read_bytes())
        regions = [('US', address, 0x800E7388, us, us_values)]
        if pal is not None and name in PAL_HELPERS:
            regions.append(('EU2-helper-cross-link', PAL_HELPERS[name], 0x800E8028, pal, pal_values))
        for region, start, base, original, values in regions:
            resolved = {symbol: values[symbol] for symbol in undefined if symbol in values}
            for symbol in undefined - set(resolved):
                match = re.fullmatch(r'(?:D_|func_)([0-9a-fA-F]{8})', symbol)
                assert region == 'US' and match, 'Missing verified binding: ' + symbol
                resolved[symbol] = int(match[1], 16)
            script = '\n'.join(symbol + ' = ' + hex(value) + ';' for symbol, value in sorted(resolved.items()))
            script += '\nSECTIONS { .text ' + hex(start) + ' : SUBALIGN(4) { *(.text) } '
            script += '.rodata 0x800E8234 : SUBALIGN(4) { *(.rodata) } '
            script += '/DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.mdebug*) *(.comment) } }\n'
            (out / 'function.ld').write_text(script)
            run(name + '-' + region + '-ld', commands['linker'] + ['-EL', '-O2', '-nostdlib', '--no-check-sections',
                '-T', rel(out / 'function.ld'), rel(out / 'function.o'), '-o', rel(out / 'function.elf')])
            for section in ['text', 'rodata']:
                run(name + '-' + region + '-' + section, commands['objcopy'] + ['--only-section=.' + section,
                    '-O', 'binary', rel(out / 'function.elf'), rel(out / ('function.' + section))])
            text = (out / 'function.text').read_bytes()
            rodata = (out / 'function.rodata').read_bytes()
            assert len(text) == length and text == original[start - base:start - base + length], name + ': text differs'
            assert len(rodata) == (88 if name == 'updatePlayer' else 0), name + ': unexpected rodata'
            assert not rodata or rodata == original[0xEAC:0xEAC + len(rodata)], name + ': switch tables differ'
            reports.append(dict(function=name, region=region, bytes=length, rodata_bytes=len(rodata),
                                byte_identical=True, text_sha256=hashlib.sha256(text).hexdigest()))
    unchanged = []
    if args.check_fallbacks:
        baseline = run('git-base', ['git', 'show', BASE + ':' + source])
        (out / 'baseline.c').write_bytes(baseline)
        for region, version in [('REGION_EU', '0'), ('REGION_EU', '1'), ('REGION_JP', '0')]:
            label = region + '-' + version
            before = preprocess(rel(out / 'baseline.c'), region, version, label + '-before')
            after = preprocess(source, region, version, label + '-after')
            normalize = lambda data: [line.strip() for line in data.splitlines() if line.strip()]
            assert normalize(before) == normalize(after), 'Inactive regional source changed: ' + label
            unchanged.append(label)
    result = dict(functions=reports, inactive_regions_unchanged=unchanged,
                  us_new_code_bytes=2328, us_switch_table_bytes=88, full_project_make_check=False)
    (out / 'result.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
