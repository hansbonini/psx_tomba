"""Compile and byte-compare the PAL language menu display initialization.

Requires the original executable, the pinned maspsx submodule, original cc1,
and GNU MIPS binutils. No original bytes are embedded or substituted.
This is a bounded function check, not a full-project make check.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--version', choices=['sces_013.30', 'sces_013.31'], required=True)
    parser.add_argument('--exe', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--commands', type=Path, help='Optional JSON command arrays for host adapters')
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    out = (root / args.out).resolve()
    assert out.is_relative_to(root) and not out.exists(), 'Use a fresh directory inside this worktree'
    config = (root / 'config' / args.version / (args.version + '.yaml')).read_text()
    expected_sha1 = re.search(r'^sha1: ([0-9a-f]+)', config, re.M)[1]
    original = args.exe.resolve().read_bytes()
    assert hashlib.sha1(original).hexdigest() == expected_sha1, 'Unsupported original executable'
    assert '[0x14CC, c, main/language_menu_display]' in config
    assert '[0x1650, asm]' in config
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
        result = subprocess.run(command, input=data, cwd=root, capture_output=True)
        (out / (label + '.stderr')).write_bytes(result.stderr)
        if result.returncode:
            raise RuntimeError(label + ' failed: ' + result.stderr.decode(errors='replace'))
        return result.stdout

    preprocessed = run('cpp', commands['cpp'] + ['-E', '-P', '-undef', '-nostdinc', '-Iinclude',
        '-D_LANGUAGE_C', '-DSKIP_ASM', '-DREGION=REGION_EU',
        '-DVERSION=' + args.version[-1], '-DLANGUAGE=LANGUAGE_NONE', 'src/main/language_menu_display.c'])
    (out / 'display.i').write_bytes(preprocessed)
    run('cc1', commands['cc1'] + ['-O2', '-G0', '-mips1', '-mcpu=3000', '-funsigned-char',
        '-gcoff', '-quiet', rel(out / 'display.i'), '-o', rel(out / 'display.s')])
    assembly = run('maspsx', commands['maspsx'] + ['--aspsx-version=2.56', '--expand-div',
        '--use-comm-section'], (out / 'display.s').read_bytes())
    (out / 'display.maspsx.s').write_bytes(assembly)
    run('assembler', commands['assembler'] + ['-EL', '-O2', '-G0', '-Iinclude', '-march=r3000',
        '-mtune=r3000', '-no-pad-sections', rel(out / 'display.maspsx.s'), '-o', rel(out / 'display.o')])
    text = (root / 'symbols' / args.version / (args.version + '_symbol_addrs.txt')).read_text()
    bindings = {}
    for name in ['initLanguageMenuDisplay', 'languageMenuDrawEnv', 'SetDefDrawEnv', 'SetDefDispEnv', 'PutDrawEnv', 'PutDispEnv']:
        bindings[name] = int(re.search(r'^' + name + r' = (0x[0-9a-fA-F]+)', text, re.M)[1], 16)
    address = bindings.pop('initLanguageMenuDisplay')
    assert address == 0x80010CCC
    script = '\n'.join(name + ' = ' + hex(value) + ';' for name, value in bindings.items())
    script += '\nSECTIONS { .text ' + hex(address) + ' : SUBALIGN(4) { *(.text) } '
    script += '/DISCARD/ : { *(.MIPS.abiflags) *(.reginfo) *(.pdr) *(.mdebug*) *(.comment) } }\n'
    (out / 'display.ld').write_text(script)
    run('linker', commands['linker'] + ['-EL', '-O2', '-nostdlib', '--no-check-sections',
        '-T', rel(out / 'display.ld'), rel(out / 'display.o'), '-o', rel(out / 'display.elf')])
    run('objcopy', commands['objcopy'] + ['--only-section=.text', '-O', 'binary',
        rel(out / 'display.elf'), rel(out / 'display.text')])
    compiled = (out / 'display.text').read_bytes()
    expected = original[0x14CC:0x1650]
    assert len(compiled) == len(expected) == 388 and compiled == expected, 'Compiled text differs'
    report = dict(version=args.version, function='initLanguageMenuDisplay', bytes=388,
                  original_sha1=expected_sha1, text_sha256=hashlib.sha256(compiled).hexdigest(),
                  byte_identical=True, full_project_make_check=False)
    (out / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
