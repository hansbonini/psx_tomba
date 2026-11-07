"""Compile and byte-compare the PAL movement group against an original X000.

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

# name, source basename, byte count, configured EU1 address, EU2 Rev 1 address.
# The latter module is also byte-identical on the verified EU1 Rev 1 disc.
FUNCTIONS = [
    ('playerAccelerateUpCapped', 'motion_playerAccelerateUpCapped', 68, 0x8010E0A0, 0x8010E5E4),
    ('playerStartFall', 'motion_playerStartFall', 68, 0x8010E0E4, 0x8010E628),
    ('playerStepSuperJump', 'motion_playerStepSuperJump', 684, 0x8010E128, 0x8010E66C),
    ('playerGetSpeedTableIndex', 'motion_playerGetSpeedTableIndex', 100, 0x8010E3D4, 0x8010E918),
    ('playerDecelerateIfFlag', 'motion_playerDecelerateIfFlag', 380, 0x8010E438, 0x8010E97C),
    ('playerAirAccelerateX', 'motion_playerAirAccelerateX', 1532, 0x8010E5B4, 0x8010EAF8),
    ('ObjGravityStep', 'motion_ObjGravityStep', 352, 0x8010EBB0, 0x8010F0F4),
    ('playerSpinReleaseSpeedKind', 'motion_playerSpinReleaseSpeedKind', 212, 0x8010ED10, 0x8010F254),
    ('playerSetJumpRiseVelocity', 'motion_playerSetJumpRiseVelocity', 216, 0x8010EDE4, 0x8010F328),
    ('playerUpdateSpeedFromPad', 'motion_playerUpdateSpeedFromPad', 2672, 0x8010EEBC, 0x8010F400),
    ('playerSkidDecelerate', 'motion_playerSkidDecelerate', 1092, 0x8010F92C, 0x8010FE70),
    ('playerSlopeSlideAccelerate', 'motion_playerSlopeSlideAccelerate', 1196, 0x8010FD70, 0x801102B4),
    ('playerDecelerateSpeedB', 'motion_playerDecelerateSpeedB', 1356, 0x8011021C, 0x80110760),
    ('func_80110CAC', 'motion_func_80110CAC', 576, 0x80110768, 0x80110CAC),
    ('playerAccelerateDownhill', 'motion_playerAccelerateDownhill', 240, 0x801109A8, 0x80110EEC),
    ('playerAttackDecelerate', 'motion_playerAttackDecelerate', 400, 0x80110A98, 0x80110FDC),
    ('playerDecelerateSpeed', 'motion_playerDecelerateSpeed', 464, 0x80110C28, 0x8011116C),
    ('setVelXFromPadLR', 'motion_setVelXFromPadLR', 128, 0x80110DF8, 0x8011133C),
    ('adjustVelYFromPadDown', 'motion_adjustVelYFromPadDown', 160, 0x80110E78, 0x801113BC),
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
    expected_sha1 = ('ce168475f667f2ca8842eabad2aec829e301c5c5' if newer else
                     'f9b26ba38616320b2759a0f23a2cb7c56359da94')
    original = args.overlay.read_bytes()
    assert hashlib.sha1(original).hexdigest() == expected_sha1, 'Unsupported original overlay'
    config = (root / 'config' / args.profile / 'x00.yaml').read_text()
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
    for name in ['symbol_addrs.txt', 'x00_symbol_addrs.txt', 'undefined_syms.txt', 'x00_undefined_syms.txt']:
        for symbol, value in re.findall(r'(\w+)\s*=\s*(0x[\da-fA-F]+)',
                                       (root / 'symbols' / args.profile / name).read_text()):
            value = int(value, 16)
            assert symbol not in values or values[symbol] == value, 'Conflicting binding: ' + symbol
            values[symbol] = value
    report = dict(profile=args.profile, original_overlay_sha1=expected_sha1,
                  full_project_make_check=False, functions=[])
    for name, source, length, older_address, newer_address in FUNCTIONS:
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

        source_path = 'src/overlays/x00/' + source + '.c'
        assert f'[0x{address-base:X}, c, {source}]' in config
        data = run('cpp', commands['cpp'] + ['-E', '-P', '-undef', '-nostdinc', '-Iinclude',
            '-D_LANGUAGE_C', '-DUSE_INCLUDE_ASM', '-DREGION=REGION_EU',
            '-DVERSION=' + ('1' if newer else '0'), '-DLANGUAGE=LANGUAGE_NONE', source_path])
        (directory / 'f.i').write_bytes(data)
        flags = ['-fno-cse-skip-blocks'] if name == 'playerUpdateSpeedFromPad' else []
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
        rodata_address = base + 0x1C98
        if name == 'playerUpdateSpeedFromPad':
            script += f' .rodata 0x{rodata_address:08X} : SUBALIGN(4) {{ *(.rodata) }}'
        script += ' /DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.mdebug*) *(.comment) } }\n'
        (directory / 'f.ld').write_text(script)
        run('ld', commands['linker'] + ['-EL', '-O2', '-nostdlib', '--no-check-sections',
            '-T', rel(directory / 'f.ld'), rel(directory / 'f.o'), '-o', rel(directory / 'f.elf')])
        sections = [('text', address - base, length)]
        if name == 'playerUpdateSpeedFromPad':
            sections.append(('rodata', rodata_address - base, 96))
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
    report['additional_rodata_bytes'] = 96
    (out / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
