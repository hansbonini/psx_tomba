"""Compile and byte-compare the PAL X001 spring-vine group against an original X001.

Uses repository source and fixed regional linker bindings; does not infer or
mask relocations during verification. This is not full-project make check.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

# name, source basename, byte count, older/newer PAL addresses, extra sections.
# The latter module is also byte-identical on the verified EU1 Rev 1 disc.
FUNCTIONS = [
    ('spawnSpringVineLeafBurst', 'vine_spawnSpringVineLeafBurst', 132, 0x80118CA0, 0x801191E4, []),
    ('updateSpringVine', 'vine_updateSpringVine', 872, 0x80119C7C, 0x8011A1C0, []),
    ('stepSpringVine', 'vine_stepSpringVine', 180, 0x80119FE4, 0x8011A528, [('data', 2148777756, 2148779104, 20)]),
    ('springVineIdle', 'vine_springVineIdle', 336, 0x8011A098, 0x8011A5DC, []),
    ('springVineSwayStep', 'vine_springVineSwayStep', 304, 0x8011A1E8, 0x8011A72C, []),
    ('springVineGrabbed', 'vine_springVineGrabbed', 1696, 0x8011A318, 0x8011A85C, [('rodata', 2148620840, 2148622188, 24)]),
    ('springVineRopeStep1', 'vine_springVineRopeStep1', 616, 0x8011A9B8, 0x8011AEFC, [('rodata', 2148620864, 2148622212, 24)]),
    ('springVineStep2', 'vine_springVineStep2', 820, 0x8011AC20, 0x8011B164, []),
    ('springVineRopeStep2', 'vine_springVineRopeStep2', 396, 0x8011AF54, 0x8011B498, []),
    ('springVineStep3', 'vine_springVineStep3', 296, 0x8011B0E0, 0x8011B624, []),
    ('springVineRopeStep3', 'vine_springVineRopeStep3', 524, 0x8011B208, 0x8011B74C, [('data', 2148786296, 2148787644, 16)]),
    ('springVineStep4', 'vine_springVineStep4', 388, 0x8011B414, 0x8011B958, []),
    ('springVineRopeStep4', 'vine_springVineRopeStep4', 400, 0x8011B598, 0x8011BADC, []),
    ('springVinePlayerCollision', 'vine_springVinePlayerCollision', 48, 0x80124B00, 0x80125044, []),
    ('springVineObjectCollision', 'vine_springVineObjectCollision', 164, 0x801255A0, 0x80125AE4, []),
    ('springVineGrabProbe', 'vine_springVineGrabProbe', 144, 0x80126AA0, 0x80126FE4, []),
]


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


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--profile', choices=['sces_013.30', 'sces_013.31'], required=True)
    parser.add_argument('--overlay', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--commands', type=Path, help='Optional host command arrays')
    parser.add_argument('--rebuilt-overlay', type=Path)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    out = (root / args.out).resolve()
    assert out.is_relative_to(root) and not out.exists(), 'Use a fresh output directory inside the repository'
    newer = args.profile == 'sces_013.31'
    base = 0x800E8028 if newer else 0x800E7B28
    expected_sha1 = ('923f812dcfd7da18ee0f7017e5b45a5e38ee3015' if newer else
                     '8d7ffee2d37d154f6af255a6002e5a2c5e947e4f')
    original = args.overlay.read_bytes()
    assert hashlib.sha1(original).hexdigest() == expected_sha1, 'Unsupported original overlay'
    config = (root / 'config' / args.profile / 'x01.yaml').read_text()
    assert re.search(r'^sha1: (\w+)', config, re.M)[1] == expected_sha1
    out.mkdir(parents=True)
    commands = dict(cpp=['mips-linux-gnu-cpp'], cc1=['tools/gcc-2.7.2-psx/cc1'],
                    maspsx=[sys.executable, 'tools/maspsx/maspsx.py'],
                    assembler=['mips-linux-gnu-as'], linker=['mips-linux-gnu-ld'],
                    objcopy=['mips-linux-gnu-objcopy'])
    if args.commands:
        overrides = json.loads(args.commands.read_text())
        assert set(overrides) <= set(commands)
        assert all(isinstance(v, list) and v and all(isinstance(x, str) for x in v)
                   for v in overrides.values())
        commands.update(overrides)
    values = {}
    for name in ['symbol_addrs.txt', 'x01_symbol_addrs.txt', 'undefined_syms.txt', 'x01_undefined_syms.txt']:
        for symbol, value in re.findall(r'(\w+)\s*=\s*(0x[\da-fA-F]+)',
                                       (root / 'symbols' / args.profile / name).read_text()):
            value = int(value, 16)
            assert symbol not in values or values[symbol] == value, 'Conflicting binding: ' + symbol
            values[symbol] = value
    report = dict(profile=args.profile, original_overlay_sha1=expected_sha1,
                  full_project_make_check=False, functions=[])
    for name, source, length, older_address, newer_address, extra_sections in FUNCTIONS:
        directory = out / name
        directory.mkdir()
        address = newer_address if newer else older_address
        rel = lambda path: path.relative_to(root).as_posix()

        def run(label, command, data=None):
            result = subprocess.run(command, cwd=root, input=data, capture_output=True)
            (directory / (label + '.stderr')).write_bytes(result.stderr)
            if result.returncode:
                raise RuntimeError(label + ': ' + result.stderr.decode(errors='replace'))
            return result.stdout

        source_path = 'src/overlays/x01/' + source + '.c'
        assert f'[0x{address-base:X}, c, {source}]' in config
        data = run('cpp', commands['cpp'] + ['-E', '-P', '-undef', '-nostdinc', '-Iinclude',
            '-D_LANGUAGE_C', '-DUSE_INCLUDE_ASM', '-DREGION=REGION_EU',
            '-DVERSION=' + ('1' if newer else '0'), '-DLANGUAGE=LANGUAGE_NONE', source_path])
        (directory / 'f.i').write_bytes(data)
        flags = []
        run('cc1', commands['cc1'] + ['-O2', '-G0', '-mips1', '-mcpu=3000', '-funsigned-char',
            '-gcoff', '-quiet', *flags, rel(directory / 'f.i'), '-o', rel(directory / 'f.s')])
        data = run('maspsx', commands['maspsx'] + ['--aspsx-version=2.56', '--expand-div',
            '--use-comm-section'], (directory / 'f.s').read_bytes())
        (directory / 'f.maspsx.s').write_bytes(data)
        run('as', commands['assembler'] + ['-EL', '-O2', '-G0', '-Iinclude', '-march=r3000',
            '-mtune=r3000', '-no-pad-sections', rel(directory / 'f.maspsx.s'), '-o', rel(directory / 'f.o')])
        undefined = undefined_symbols((directory / 'f.o').read_bytes())
        assert undefined <= set(values), 'Missing bindings: ' + str(undefined - set(values))
        script = '\n'.join(f'{k} = 0x{values[k]:08X};' for k in sorted(undefined))
        script += f'\nSECTIONS {{ .text 0x{address:08X} : SUBALIGN(4) {{ *(.text) }}'
        for section, old, new, count in extra_sections:
            start = new if newer else old
            script += f' .{section} 0x{start:08X} : SUBALIGN(4) {{ *(.{section}) }}'
        script += ' /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.mdebug*) *(.comment) } }\n'
        (directory / 'f.ld').write_text(script)
        run('ld', commands['linker'] + ['-EL', '-O2', '-nostdlib', '--no-check-sections',
            '-T', rel(directory / 'f.ld'), rel(directory / 'f.o'), '-o', rel(directory / 'f.elf')])
        sections = [('text', address - base, length)]
        sections += [(section, (new if newer else old) - base, count)
                     for section, old, new, count in extra_sections]
        for section, offset, expected_length in sections:
            run('copy-' + section, commands['objcopy'] + ['--only-section=.' + section, '-O', 'binary',
                rel(directory / 'f.elf'), rel(directory / ('f.' + section))])
            actual = (directory / ('f.' + section)).read_bytes()
            assert len(actual) == expected_length and actual == original[offset:offset + expected_length], name + ': ' + section + ' differs'
        report['functions'].append(dict(name=name, code_bytes=length, byte_identical=True))
    if args.rebuilt_overlay:
        rebuilt = args.rebuilt_overlay.read_bytes()
        assert rebuilt == original, 'Rebuilt overlay differs'
        report['complete_overlay_bytes'] = len(rebuilt)
    report['additional_code_bytes'] = sum(item['code_bytes'] for item in report['functions'])
    report['additional_rodata_bytes'] = sum(s[3] for f in FUNCTIONS for s in f[5] if s[0]=='rodata')
    report['additional_data_bytes'] = sum(s[3] for f in FUNCTIONS for s in f[5] if s[0]=='data')
    (out / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
