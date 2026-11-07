"""Byte-compare the configured EU2 Rev 1 player dispatcher and switch tables.

Uses the actual selected C translation unit and regional linker bindings.
Requires the original overlay and the repository's pinned compiler/maspsx tools.
This bounded check does not run full-project make check.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import struct
import sys

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
    parser.add_argument('--overlay', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--commands', type=Path, help='Optional JSON command arrays for host adapters')
    parser.add_argument('--rebuilt-overlay', type=Path, help='Optional complete output from a separate X00 build')
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    out = (root / args.out).resolve()
    assert out.is_relative_to(root) and not out.exists(), 'Use a fresh directory inside the worktree'
    config = (root / 'config/sces_013.31/x00.yaml').read_text()
    original = args.overlay.read_bytes()
    expected_sha1 = re.search(r'^sha1: ([0-9a-f]+)', config, re.M)[1]
    assert expected_sha1 == 'ce168475f667f2ca8842eabad2aec829e301c5c5'
    assert hashlib.sha1(original).hexdigest() == expected_sha1, 'Unsupported original overlay'
    for boundary in ['[0xEAC, .rodata, player_update]', '[0xF04, rodata]',
                     '[0x1A1EC, c, player_update]', '[0x1A9E0, asm]']:
        assert boundary in config, 'Changed dispatcher layout: ' + boundary
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

    preprocessed = run('cpp', commands['cpp'] + ['-E', '-P', '-undef', '-nostdinc', '-Iinclude',
        '-D_LANGUAGE_C', '-DUSE_INCLUDE_ASM', '-DREGION=REGION_EU', '-DVERSION=1',
        '-DLANGUAGE=LANGUAGE_NONE', 'src/overlays/x00/player_update.c'])
    (out / 'player.i').write_bytes(preprocessed)
    run('cc1', commands['cc1'] + ['-O2', '-G0', '-mips1', '-mcpu=3000', '-funsigned-char',
        '-gcoff', '-quiet', rel(out / 'player.i'), '-o', rel(out / 'player.s')])
    assembly = run('maspsx', commands['maspsx'] + ['--aspsx-version=2.56', '--expand-div',
        '--use-comm-section'], (out / 'player.s').read_bytes())
    (out / 'player.maspsx.s').write_bytes(assembly)
    run('assembler', commands['assembler'] + ['-EL', '-O2', '-G0', '-Iinclude', '-march=r3000',
        '-mtune=r3000', '-no-pad-sections', rel(out / 'player.maspsx.s'), '-o', rel(out / 'player.o')])
    values = bindings_from([root / 'symbols/sces_013.31' / name for name in
        ['x00_symbol_addrs.txt', 'x00_undefined_syms.txt', 'undefined_syms.txt']])
    undefined = undefined_symbols((out / 'player.o').read_bytes())
    assert undefined <= set(values), 'Missing regional bindings: ' + str(undefined - set(values))
    assert values['updatePlayer'] == 0x80102214
    script = '\n'.join(name + ' = ' + hex(values[name]) + ';' for name in sorted(undefined))
    script += '\nENTRY(updatePlayer)\nSECTIONS { .text 0x80102214 : SUBALIGN(4) { *(.text) } '
    script += '.rodata 0x800E8ED4 : SUBALIGN(4) { *(.rodata) } '
    script += '/DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.mdebug*) *(.comment) } }\n'
    (out / 'player.ld').write_text(script)
    run('linker', commands['linker'] + ['-EL', '-O2', '-nostdlib', '--no-check-sections', '-T',
        rel(out / 'player.ld'), rel(out / 'player.o'), '-o', rel(out / 'player.elf')])
    report = dict(region='EU2 Rev 1, configured language-0 X00 overlay', function='updatePlayer',
                  source_sha256=hashlib.sha256((root / 'src/overlays/x00/player_update.inc').read_bytes()).hexdigest(),
                  original_overlay_sha1=expected_sha1, full_project_make_check=False)
    for section, offset, length in [('text', 0x1A1EC, 2036), ('rodata', 0xEAC, 88)]:
        run('objcopy-' + section, commands['objcopy'] + ['--only-section=.' + section, '-O', 'binary',
            rel(out / 'player.elf'), rel(out / ('player.' + section))])
        data = (out / ('player.' + section)).read_bytes()
        assert len(data) == length and data == original[offset:offset + length], section + ' differs'
        report[section] = dict(bytes=length, byte_identical=True, sha256=hashlib.sha256(data).hexdigest())
    if args.rebuilt_overlay:
        rebuilt = args.rebuilt_overlay.read_bytes()
        assert rebuilt == original, 'Complete rebuilt overlay differs'
        report['whole_overlay'] = dict(bytes=len(rebuilt), byte_identical=True,
                                      sha1=hashlib.sha1(rebuilt).hexdigest())
    (out / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report, indent=2))


if __name__ == '__main__':
    main()
