# Tomba! PSX Decompilation

<div align="center">
  <img src="https://github.com/hansbonini/psx_tomba/blob/main/docs/assets/logo.png?raw=true" alt="Tomba! Logo" width="400"/>
  
  [![Discord](https://img.shields.io/discord/404121852517285888?color=7289da&logo=discord&logoColor=white)](https://discord.gg/SjBn4g57Bj)
  [![Progress](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent)](https://decomp.dev/hansbonini/psx_tomba)
  [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  [![Platform](https://img.shields.io/badge/Platform-PlayStation-blue)](https://en.wikipedia.org/wiki/PlayStation_(console))
</div>

## 🎮 About the Project

This is a **decompilation** project of the **Tomba!** game (known as **Ore! Tomba** in Japan and **Tombi!** in Europe) for the original PlayStation. The goal is to rebuild the game's source code in C so that it compiles back into a **byte-identical** executable, enabling:

- 🔧 **Modifications and Improvements**: patches, translations, and game enhancements
- 📖 **Educational Study**: detailed analysis of 90s PSX game programming
- 🌍 **Preservation**: ensuring this classic is preserved for future generations
- 🎯 **Accuracy**: byte-perfect reproduction of the original executable

## 🌍 Supported Versions

| Region | Game Code | Executable | SHA1 | Status |
|--------|-----------|------------|------|--------|
| 🇺🇸 **NTSC-U** | SCUS-94236 | `SCUS_942.36` | `81cbc79f0230aeb4252e058039f47ac95a777f5a` | ✅ Decompilation target |
| 🇪🇺 **PAL** | SCES-01330 | `SCES_013.30` | `aae1842ff8b05ac6ae812d122b360714368e0656` | 📋 Reference only |
| 🇯🇵 **NTSC-J** | SLPS-01144 | `SLPS_011.44` | `07d577698ad31ec1a69b9d7b80a7c3f90b650888` | 📋 Reference only |

**Only NTSC-U is wired into the decompilation build.** It is the single splat configuration in the
repository ([`config/scus_942.36/scus_942.36.yaml`](config/scus_942.36/scus_942.36.yaml)), and the
only target `make build` produces. The PAL and NTSC-J discs are present as reference material; they have no splat config yet, so they cannot be rebuilt from
source.

## 📊 Decompilation Progress

Live progress is tracked on **[decomp.dev](https://decomp.dev/hansbonini/psx_tomba)**, fed by the
objdiff report that CI publishes on every push to `main`.

[![Overall](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent&label=Overall)](https://decomp.dev/hansbonini/psx_tomba)
[![Psy-Q SDK](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_code_percent&category=sdk)](https://decomp.dev/hansbonini/psx_tomba)
[![Functions](https://decomp.dev/hansbonini/psx_tomba.svg?mode=shield&measure=matched_functions_percent&label=Functions)](https://decomp.dev/hansbonini/psx_tomba)

| Scope | Matched code | Matched functions |
|-------|--------------|-------------------|
| **Overall** | 72,064 / 395,516 bytes (18.22%) | 391 / 1,334 (29.31%) |
| Psy-Q SDK | 38,832 / 112,928 bytes (34.39%) | 243 / 595 (40.84%) |

*Snapshot as of commit `79654f7`. The badges above are live — the table will drift.*

Matched code is the meaningful number: it is byte-weighted, so a 1200-byte state machine counts for
more than a three-line accessor. Fuzzy match, which gives partial credit for near-misses, sits at
19.10%.

The Psy-Q SDK is further along than the game code because much of it is recovered from known PSY-Q
library signatures rather than decompiled by hand. Note that the *Overall* row includes the SDK, so
game code on its own is meaningfully lower than 18%.

To reproduce the report locally:

```bash
make report      # writes build/progress.json via objdiff
```

> **Note:** the project uses PSY-Q libraries from **mixed SDK versions** (for example libpad 4.2
> alongside 4.3), so signature matching has to be done per-object, not per-release.

## 🛠️ Toolchain

| Component | Version / Source | Role |
|-----------|------------------|------|
| [splat](https://github.com/ethteck/splat) | **0.35.2** (pinned) | Binary splitting and disassembly |
| [spimdisasm](https://github.com/Decompollaborate/spimdisasm) | **1.36.0** (pinned) | MIPS disassembly backend |
| `gcc 2.7.2-psx` | [`tools/gcc-2.7.2-psx/`](tools/gcc-2.7.2-psx/) | Original-era C compiler (cc1) |
| [maspsx](https://github.com/mkst/maspsx) | [`tools/maspsx/`](tools/maspsx/) | ASPSX 2.56 assembler emulation |
| `binutils-mips-linux-gnu` | distro package | Assembler and linker |
| [objdiff](https://github.com/encounter/objdiff) | [`tools/objdiff/`](tools/objdiff/) | Per-object diffing and progress reports |
| [mkpsxiso](https://github.com/Lameguy64/mkpsxiso) | [`tools/mkpsxiso/`](tools/mkpsxiso/) | ISO reconstruction |
| [armips](https://github.com/Kingcom/armips) | [`tools/armips/`](tools/armips/) | Standalone binary patches |
| [m2c](https://github.com/matt-kempster/m2c) | [`tools/m2c/`](tools/m2c/) | Assembly-to-C decompiler assistance |
| [TombaTools](tools/tombatools/) | in-tree | Game asset formats (WFM, GAM) |

Both splat and spimdisasm are **version-pinned in CI**. They generate the assembly that the build
consumes, and their label and rodata output changes between releases — an unpinned upgrade silently
breaks the build.

### TombaTools Features

- 🎨 **WFM Font Processing**
  - Extract glyphs as PNG files with transparency support
  - Decode dialogues to YAML with text and control codes
  - Encode YAML dialogues back to WFM
  - Automatic glyph-to-character mapping
- 📦 **GAM Archive Management**
  - Unpack compressed GAM files using the game's custom LZ algorithm
  - Repack data to GAM format with compression
  - Integrity verification and error checking

## 📁 Project Structure

```
PSX_TOMBA/
├── 📁 asm/            # Disassembly generated by splat
│   └── scus_942.36/
│       ├── matchings/      # Functions already reimplemented in C
│       ├── nonmatchings/   # Functions still pending
│       └── data/           # Data and rodata segments
├── 📁 src/            # C source (INCLUDE_ASM for pending functions)
│   └── scus_942.36/
│       ├── main/           # Game code
│       └── psyq/           # PSY-Q SDK reimplementation
├── 📁 include/        # Headers (game.h, common.h, psyq/)
├── 📁 config/         # Splat configuration and build checksums
├── 📁 linker/         # Generated linker scripts
├── 📁 symbols/        # Symbol address tables
├── 📁 iso/            # Extracted disc contents (not in git)
├── 📁 patch/          # Standalone armips patches (debug menus)
├── 📁 i18n/           # Translation data (british, portuguese_brazil)
├── 📁 docs/           # Technical documentation
├── 📁 tools/          # Toolchain and custom utilities
└── 📄 *.xml           # mkpsxiso build scripts, one per region
```

## 🚀 Getting Started

### Prerequisites

- **Linux** or WSL — the bundled `cc1` is a 32-bit Linux ELF binary
- **Python 3.8+**
- **Make**
- **binutils for MIPS**: `binutils-mips-linux-gnu`, `cpp-mips-linux-gnu`
- **Go 1.21+** (only to rebuild TombaTools)

### Setup

1. **Clone the repository with submodules**

```bash
git clone --recurse-submodules https://github.com/hansbonini/psx_tomba.git
cd psx_tomba
```

2. **Install the toolchain**

```bash
sudo apt-get install make binutils-mips-linux-gnu cpp-mips-linux-gnu
python3 -m pip install splat64[mips]==0.35.2 spimdisasm==1.36.0
```

Pin both versions. splat only requires `spimdisasm>=1.36.0,<2.0.0`, so without an explicit pin pip
will pull a newer backend that produces incompatible labels.

3. **Provide the executable**

Extract `SCUS_942.36` from a disc you legally own and place it at `iso/us/SCUS_942.36`. Verify it
matches the SHA1 in the table above before continuing — every offset in this project assumes that
exact build.

4. **Build**

```bash
make generate    # run splat: disassembly + linker scripts
make build       # compile and link
make check       # verify the output is byte-identical to the original
```

`make check` compares the linked executable against
[`config/scus_942.36/checksum.sha`](config/scus_942.36/checksum.sha). A clean pass means the rebuild
is byte-perfect.

### Other Make Targets

| Target | Purpose |
|--------|---------|
| `make report` | Generate `build/progress.json` via objdiff |
| `make expected` | Snapshot current objects as the diff baseline |
| `make regenerate` | Clean and re-run splat from scratch |
| `make clean` / `make reset` | Remove build artifacts |
| `make patch_debug_sfx` etc. | Build the standalone debug patches in [`patch/`](patch/) |

### Working with Game Assets

```bash
# Unpack a GAM archive
./tools/tombatools/tombatools gam unpack iso/us/AREA00/A000.GAM ./extracted/A000.UNGAM

# Decode a font / dialogue file
./tools/tombatools/tombatools wfm decode iso/us/SYSTEM/FONT.WFM ./fonts/
```

## 🤖 Continuous Integration

[`.github/workflows/build.yaml`](.github/workflows/build.yaml) runs `make generate`, `make build`
and `make report` on every push to `main`, and uploads the progress report as an artifact.

The runner image and every disassembly tool are pinned. This is deliberate: the build consumes
generated assembly, so a floating `ubuntu-latest` or an unpinned pip package changes the input and
breaks the link stage in ways that look nothing like a code error.

## 🗺️ Game Areas Reference

Area and section layout of the game data, for orientation when working on area-specific code:

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

## 🤝 How to Contribute

Contributions are very welcome. The most useful thing you can do right now is **match a function**.

### Matching a Function

1. Pick a function still listed as `INCLUDE_ASM` in [`src/scus_942.36/`](src/scus_942.36/)
2. Write C that reproduces it, using the assembly in `asm/scus_942.36/nonmatchings/` as reference
3. Verify with `make build` plus objdiff, or upload a scratch to [decomp.me](https://decomp.me)
4. When it matches, replace the `INCLUDE_ASM` line with your implementation (keep the original line
   commented above it — that is the convention used throughout this repository)

[`tools/decompile.py`](tools/decompile.py) automates extracting a function plus its context and
uploading it to decomp.me.

### Other Ways to Help

- 🔍 **Naming**: identify and name functions, document data structures, map execution flows
- 📝 **Documentation**: improve this README, document discovered formats
- 🐛 **Bugs**: report problems via [Issues](https://github.com/hansbonini/psx_tomba/issues) with
  logs and steps to reproduce

### Pull Requests

1. Fork the project
2. Create a branch (`git checkout -b feature/new-feature`)
3. Commit your changes
4. Push and open a Pull Request

## 📚 Resources and Documentation

### In This Repository

- [Environment Setup](docs/setup.md)
- [Game File Formats](docs/game-formats.md)
- [File Analysis](docs/file-analysis.md)
- [Function Analysis](docs/function-analysis.md)

### External Resources

- [Tomba.Club](https://tomba.club) — community wiki and resources
- [PSX Development Wiki](https://psx-spx.consoledev.net/)
- [PSYQ Documentation](http://psxdev.net/help.html)
- [Tomba! TCRF Page](https://tcrf.net/Tomba!)
- [decomp.me](https://decomp.me) — collaborative function matching

## ⚖️ Legal Aspects

This project is intended **exclusively for educational and preservation purposes**.

- ✅ Only use ISOs you legally own
- ✅ No proprietary assets or code are distributed here
- ✅ Respect Whoopee Camp / Sony copyrights
- ⚠️ You must supply your own copy of the game to build anything

## 🏆 Credits and Acknowledgments

### Core Team

- **Hans Bonini** — project lead and main development

### Tools and Libraries

- [splat](https://github.com/ethteck/splat) by ethteck
- [spimdisasm](https://github.com/Decompollaborate/spimdisasm) by Decompollaborate
- [maspsx](https://github.com/mkst/maspsx) by mkst
- [objdiff](https://github.com/encounter/objdiff) by encounter
- [mkpsxiso](https://github.com/Lameguy64/mkpsxiso) by Lameguy64
- [PSX.Dev](https://psx.dev) community for documentation

### Special Thanks

- **zerovii** — material and explanations about the WFM format
- **vervalkon** — material and explanations about quad polygon coordinates and the GAM format
- **[Xeeynamo](https://github.com/Xeeynamo)** — Castlevania decompilation project, used as reference
- **LAB313Ru** — PSX loader for the Ghidra reverse engineering framework
- **ethteck** — creator of splat, the disassembler that makes this project possible
- **PCSX-Redux Team** — advanced PlayStation emulator with debugging capabilities
- **DuckStation Team** — high-accuracy PlayStation emulator for testing and verification

## 📞 Contact and Community

- 💬 **Discord**: [Tomba.Club](https://discord.gg/SjBn4g57Bj)
- 🌐 **Website**: [hansbonini.com.br](https://hansbonini.com.br)

---

<div align="center">
  <strong>"Let's catch all the evil pigs!"</strong> — Tomba

  Made with 💖 by the game preservation community
</div>
