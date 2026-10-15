# Tomba! PSX Decompilation

<div align="center">
  <img src="https://github.com/hansbonini/psx_tomba/blob/main/docs/assets/logo.png?raw=true" alt="Tomba! Logo" width="400"/>

  [![Discord](https://img.shields.io/discord/404121852517285888?color=7289da&logo=discord&logoColor=white)](https://discord.gg/SjBn4g57Bj)
  [![Progress](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent)](https://decomp.dev/hansbonini/psx_tomba)
  [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  [![Platform](https://img.shields.io/badge/Platform-PlayStation-blue)](https://en.wikipedia.org/wiki/PlayStation_(console))
</div>

A decompilation of **Tomba!** for the original PlayStation, also released as **Ore! Tomba** in Japan
and **Tombi!** in Europe. The goal is C source code that compiles back into **byte-identical**
executables for every retail release. That source code supports:

- 🔧 **Modding**: patches, translations and enhancements built on real source code
- 📖 **Study**: how a late-90s PlayStation game was programmed
- 🌍 **Preservation**: keeping the game's code understandable for the future

## 🌍 Supported Versions

All four releases build from the **same sources** and are checked byte for byte.

| Region | Serial | `VERSION` | Executables | SHA1 of the main executable |
|--------|--------|-----------|-------------|-----------------------------|
| 🇺🇸 NTSC-U | SCUS-94236 | `scus_942.36` (default) | `SCUS_942.36` and the code overlays `SYSTEM/OPTSUB00.BIN`, `X00`–`X18` | `81cbc79f0230aeb4252e058039f47ac95a777f5a` |
| 🇯🇵 NTSC-J | SLPS-01144 | `slps_011.44` | `SLPS_011.44` | `07d577698ad31ec1a69b9d7b80a7c3f90b650888` |
| 🇪🇺 PAL (En/Fr/De/It/Nl) | SCES-01330 | `sces_013.30` | `SCES_013.30` and `EXE/MAIN0.EXE`–`MAIN8.EXE` | `1d98c6595a49bd8063c906221df1eaa854964cb1` |
| 🇪🇺 PAL (En/Es/Pt/Sv/Da) | SCES-01331 | `sces_013.31` | `SCES_013.31` and `EXE/MAIN0.EXE`–`MAIN8.EXE` | `f6c383514e5d8367d2eed06400315cf6dd57ef6b` |

On the European discs, `SCES_013.3x` is only the language menu. The game itself is `EXE/MAINn.EXE`,
with one executable per language. The checksums of every file are in `config/<VERSION>/checksum.sha`.

US is the reference release: functions are decompiled there first. The other releases reuse every
object that is the same in their executable. See [How the versions share code](#-how-the-versions-share-code).

## 📊 Progress

Live progress is tracked on **[decomp.dev](https://decomp.dev/hansbonini/psx_tomba)** from the objdiff
report that CI publishes on every push to `main`.

[![Overall](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent&label=Overall)](https://decomp.dev/hansbonini/psx_tomba)
[![Psy-Q SDK](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent&category=sdk)](https://decomp.dev/hansbonini/psx_tomba)
[![Functions](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_functions_percent&label=Functions)](https://decomp.dev/hansbonini/psx_tomba)

| Scope (US) | Matched code |
|------------|--------------|
| Overall, overlays included | 38.3% |
| Main game code (`main`) | 78.0% |
| Psy-Q SDK (`sdk`) | 88.0% |
| Shared overlay engine and X00 area (`x00`) | 77.0% |

*Local report from 2026-10-14. The badges are live; this table will drift.*

Matched code is weighted by bytes, so a 1200-byte state machine counts for more than a three-line
accessor. The other Xnn area modules have barely started, which is why the overall number is far
below the main executable's.

> **Note:** the game links PSY-Q libraries from **mixed SDK versions** (for example libpad 4.2
> alongside 4.3), so signature matching is done per object, not per SDK release.

## 🛠️ Toolchain

| Component | Version / Source | Role |
|-----------|------------------|------|
| [splat](https://github.com/ethteck/splat) | **0.35.2** (pinned) | Splitting and disassembly |
| [spimdisasm](https://github.com/Decompollaborate/spimdisasm) | **1.36.0** (pinned) | MIPS disassembly backend |
| `gcc 2.7.2-psx` | [`tools/gcc-2.7.2-psx/`](tools/gcc-2.7.2-psx/) | Original-era C compiler (`cc1`) |
| [maspsx](https://github.com/mkst/maspsx) | [`tools/maspsx/`](tools/maspsx/) | ASPSX 2.56 assembler emulation |
| `binutils-mips-linux-gnu` | distro package | Assembler and linker |
| [objdiff](https://github.com/encounter/objdiff) | [`tools/objdiff/`](tools/objdiff/) | Per-object diffing and progress reports |
| [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) | `make permuter-setup` | Search for near-matches |
| [m2c](https://github.com/matt-kempster/m2c) | [`tools/m2c/`](tools/m2c/) | First-pass assembly-to-C |
| [mkpsxiso](https://github.com/Lameguy64/mkpsxiso) | [`tools/mkpsxiso/`](tools/mkpsxiso/) | Disc extraction (`dumpsxiso`) and rebuild |
| [armips](https://github.com/Kingcom/armips) | `tools/armips/armips` (not bundled) | Standalone patches in [`patch/`](patch/) |

splat and spimdisasm are **pinned** on purpose. The build assembles the code they generate, and
their labels and rodata output change between releases, so an unpinned upgrade breaks the link in
ways that look nothing like a code error.

## 📁 Project Structure

```
PSX_TOMBA/
├── src/                 # C sources shared by every release
│   ├── main/            #   game code
│   ├── psyq/            #   PSY-Q SDK
│   └── overlays/        #   code overlays (US): shared engine + area modules
├── include/             # headers (game.h, common.h, psyq/)
├── config/<VERSION>/    # splat configs and checksums of each release
├── symbols/<VERSION>/   # symbol tables of each release
├── asm/<VERSION>/       # disassembly generated by splat (not in git)
│   ├── nonmatchings/    #   functions still in assembly, used by INCLUDE_ASM
│   └── matchings/       #   functions already in C, for reference
├── linker/<VERSION>/    # generated linker scripts (not in git)
├── build/<VERSION>/     # objects of each release (not in git)
├── build/out/iso/       # rebuilt executables
├── iso/<VERSION>/       # extracted disc of each release (not in git)
├── patch/               # standalone armips patches (debug menus)
├── i18n/                # translation data
├── docs/                # technical documentation
├── tools/               # toolchain and project scripts
└── *.xml                # mkpsxiso disc layouts
```

## 🚀 Getting Started

### Prerequisites

- **Linux** or **WSL**: the bundled `cc1` is a 32-bit Linux ELF binary
- **Python 3.8+** and **Make**
- `binutils-mips-linux-gnu` and `cpp-mips-linux-gnu`

### Setup

1. **Clone with submodules**

   ```bash
   git clone --recurse-submodules https://github.com/hansbonini/psx_tomba.git
   cd psx_tomba
   ```

2. **Install the toolchain**

   ```bash
   sudo apt-get install make binutils-mips-linux-gnu cpp-mips-linux-gnu
   python3 -m pip install splat64[mips]==0.35.2 spimdisasm==1.36.0
   ```

   Pin both. splat only asks for `spimdisasm>=1.36.0,<2.0.0`, so pip would otherwise pull a
   newer backend that produces different labels.

3. **Extract your disc**

   Use a disc you legally own. Extract it with `dumpsxiso` (from mkpsxiso) into `iso/<VERSION>`.
   Pass the `.bin` image, not the `.cue`:

   ```bash
   dumpsxiso -x iso/scus_942.36 -s SCUS_94236.xml "Tomba! (USA).bin"
   ```

   Check the main executable against the SHA1 in the table above. Every offset in the project
   assumes those exact builds.

4. **Build and check**

   ```bash
   make generate    # splat: disassembly and linker scripts
   make check       # build and compare with config/<VERSION>/checksum.sha
   ```

   Every target takes `VERSION`, and US is the default:

   ```bash
   make VERSION=slps_011.44 generate
   make VERSION=slps_011.44 check
   ```

   Every `OK` in the `make check` output means that file is byte-identical to the original.

### Make Targets

| Target | Purpose |
|--------|---------|
| `make generate` | Run splat for every executable of `VERSION` |
| `make build` / `make check` | Build; build and verify the checksums |
| `make report` | Re-split, build the objdiff baseline and write `build/<VERSION>/progress.json` |
| `make regenerate` | Remove the asm, linker scripts and build of `VERSION`, then run splat again |
| `make clean` / `make reset` | Remove the build of `VERSION`; also its asm and linker scripts |
| `make permuter-import FUNC=… SRC=…` / `make permuter-run FUNC=…` | Search for near-matches with decomp-permuter |
| `make patch_debug_sfx` etc. | Build the standalone debug patches in [`patch/`](patch/) |

> If you edit a header such as `game.h`, `make` does not rebuild the objects that include it.
> Remove `build/<VERSION>/src` before measuring.

## 🔀 How the Versions Share Code

There is one `src/` for all releases. Each release has its own splat config, symbol tables, asm and
build folder:

- **Only the asm differs per release.** `INCLUDE_ASM` paths are relative
  (`INCLUDE_ASM("nonmatchings/main/game/event", func)`). The assembler looks them up in the asm folder
  of the executable being built (`asm/<VERSION>`, or `asm/<VERSION>/exe/mainN` for a European
  MAIN).
- **The C keeps the US names.** Each executable of another release gets
  `symbols/<VERSION>/<name>_symbol_addrs.txt`, which places the US names at that executable's
  addresses. Names splat makes up there carry the serial as a suffix (`D_80012345_slps01144`), so
  they never clash with the US ones.
- **A function that differs in a release is kept in assembly there.** The `#if` uses one macro per
  serial, which the Makefile defines from `VERSION`:

  ```c
  #if defined(VERSION_SLPS_01144) || defined(VERSION_SCES_01330)
  INCLUDE_ASM("nonmatchings/main/render/camera", loadSpawnPosition);
  #else
  void loadSpawnPosition(void)
  {
      ...
  }
  #endif
  ```

  The macros are `VERSION_SCUS_94236`, `VERSION_SLPS_01144`, `VERSION_SCES_01330` and
  `VERSION_SCES_01331`.

These files are generated, not edited by hand. Two scripts produce them:

| Script | What it does |
|--------|--------------|
| [`tools/version_objects.py`](tools/version_objects.py) | Finds each US object in the other executables, function by function, and writes their splat subsegments with the US object names |
| [`tools/version_share.py`](tools/version_share.py) | Turns the objects that can share the US source into C, writes the symbol tables, and rewrites the `#if` blocks in `src/` |

After a change that affects other releases (a newly matched function, a renamed symbol), rebuild
the US first: `version_share.py` reads the relocations of the US objects. Then run it with no
arguments, because the `#if` blocks are only rewritten when every release is analysed. Finally run
`make VERSION=<serial> generate` and `make VERSION=<serial> check` for each release.

An object stays in assembly in another release in these cases:

- **It has `.data` of its own in C.** Its data is not split yet in that release.
- **It is split in two places in the executable.** This happens with some European objects.
- **Its changed functions cannot be told apart.** This happens with parts of the Japanese game code.
- **It is a libpad unit and one of its functions differs.** These units are assembled by GNU as,
  which cannot take `INCLUDE_ASM`.

## 🤖 Continuous Integration

[`.github/workflows/build.yaml`](.github/workflows/build.yaml) builds every release on each push to
`main`. It runs `make generate`, `make build` and `make report` once per `VERSION`, then uploads each
`build/<VERSION>/progress.json`. The runner image and the disassembly tools are pinned for the
reason given in the Toolchain section.

## 🤝 How to Contribute

The most useful contribution is **matching a function**.

1. Pick a function still under `INCLUDE_ASM` in [`src/`](src/).
2. Write C for it, using `asm/scus_942.36/nonmatchings/<object>/<function>.s` as reference.
3. Check it with `make check`, objdiff, or a scratch on [decomp.me](https://decomp.me).
   [`tools/decompile.py`](tools/decompile.py) extracts a function with its context and uploads it.
4. When it matches, replace the `INCLUDE_ASM` line with the C and leave the original line commented
   above it, as everywhere else in the repository.
5. Rebuild the other releases (see [How the versions share code](#-how-the-versions-share-code)). If
   the function differs in a release, `version_share.py` adds the `#if` for you.

Other help is just as welcome:

- 🔍 **Naming**: functions, data structures, execution flow
- 📝 **Documentation**: file formats and engine behaviour in [`docs/`](docs/)
- 🐛 **Bugs**: open an [issue](https://github.com/hansbonini/psx_tomba/issues) with the log and the
  steps to reproduce

Pull requests: fork, create a branch, commit, and open the PR against `main`.

## 🗺️ Game Areas

Area and section layout of the game data, for orientation in area-specific code:

| ID | Area | Sections |
|----|------|----------|
| AREA00 | Village of All Beginnings | 5 |
| AREA01 | Dwarf Forest | 5 |
| AREA02 | Dwarf Village | 6 |
| AREA03 | Phoenix Mountain | 6 |
| AREA04 | Haunted Mansion | 20 |
| AREA05 | Baccus Village | 4 |
| AREA06 | Motocross Segment | 3 |
| AREA07 | Dwarf Forest (Purified) | 5 |
| AREA08 | Baccus Lake | 4 |
| AREA09 | Mushroom Village | 7 |
| AREA10 | Deep Jungle | 9 |
| AREA11 | Village of Civilization | 3 |
| AREA12 | Haunted Mansion (Purified) | 20 |
| AREA13 | Pig Island | 2 |
| AREA14 | Evil Pigs | 8 |
| AREA15 | *Empty / Unused* | — |
| AREA16 | Village of Civilization — Clock Tower | 7 |
| AREA17 | Village of Civilization — Iron Tower | 11 |
| AREA18 | Village of Civilization — Y Crossing | 3 |
| AREA19 | Hidden Village | 3 |

## 📚 Documentation

In this repository:

- [Environment setup](docs/setup.md)
- [Game file formats](docs/game-formats.md)
- [CD file loading](docs/cd-file-loading.md)
- [File analysis](docs/file-analysis.md)

Elsewhere:

- [Tomba.Club](https://tomba.club), the community wiki
- [PSX-SPX](https://psx-spx.consoledev.net/), hardware reference
- [PSY-Q documentation](http://psxdev.net/help.html)
- [Tomba! on TCRF](https://tcrf.net/Tomba!)
- [decomp.me](https://decomp.me), collaborative function matching

## ⚖️ Legal

This project is for **education and preservation** only.

- No game assets or original code are distributed here.
- You need your own legally owned copy of the game to build anything.
- Tomba! is © Whoopee Camp / Sony Computer Entertainment.

## 🏆 Credits

- **Hans Bonini**: project lead and main development

Tools: [splat](https://github.com/ethteck/splat) (ethteck),
[spimdisasm](https://github.com/Decompollaborate/spimdisasm) (Decompollaborate),
[maspsx](https://github.com/mkst/maspsx) (mkst), [objdiff](https://github.com/encounter/objdiff)
(encounter), [mkpsxiso](https://github.com/Lameguy64/mkpsxiso) (Lameguy64), and the
[PSX.Dev](https://psx.dev) community.

Special thanks:

- **zerovii**: material and explanations about the WFM format
- **vervalkon**: material and explanations about quad polygon coordinates and the GAM format
- **[Xeeynamo](https://github.com/Xeeynamo)**: the Castlevania: SotN decompilation, used as reference
- **LAB313Ru**: PSX loader for Ghidra
- **PCSX-Redux** and **DuckStation** teams: emulators used for debugging and verification

## 📞 Community

- 💬 **Discord**: [Tomba.Club](https://discord.gg/SjBn4g57Bj)
- 🌐 **Website**: [hansbonini.com.br](https://hansbonini.com.br)

---

<div align="center">
  <strong>"Let's catch all the evil pigs!"</strong> — Tomba
</div>
