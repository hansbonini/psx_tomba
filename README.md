# Tomba! PSX Decompilation Project

<div align="center">
  <img src="https://github.com/user-attachments/assets/tomba-logo.png" alt="Tomba! Logo" width="400"/>
  
  [![Discord](https://img.shields.io/discord/your-discord-id?color=7289da&logo=discord&logoColor=white)](https://discord.gg/tomba-club)
  [![Progress](https://img.shields.io/badge/Progress-In%20Development-yellow)](https://github.com/hansbonini/tomba-decomp)
  [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  [![Platform](https://img.shields.io/badge/Platform-PlayStation-blue)](https://en.wikipedia.org/wiki/PlayStation_(console))
</div>

## 🎮 About the Project

This is a complete **decompilation** project of the **Tomba!** game (known as **Ore no Tomba** in Japan and **Tombi!** in Europe) for the original PlayStation. The goal is to create a fully functional and compilable version of the game's source code, enabling:

- 🔧 **Modifications and Improvements**: Ability to create patches, translations, and game enhancements
- 📖 **Educational Study**: Detailed analysis of 90s PSX game programming
- 🌍 **Preservation**: Ensuring this classic is preserved for future generations
- 🎯 **Accuracy**: Byte-perfect reproduction of the original executable

## 🌍 Supported Versions

| Region | Game Code | Status | SHA1 |
|--------|-----------|--------|------|
| 🇺🇸 **NTSC-U** | SCUS-94236 | ✅ Primary | `81cbc79f0230aeb4252e058039f47ac95a777f5a` |
| 🇪🇺 **PAL** | SCES-01330 | 🔄 In progress | - |
| 🇷🇺 **Russian** | - | 📋 Planned | - |

## 📁 Project Structure

```
PSX_TOMBA/
├── 📁 config/           # Splat configuration and symbols
├── 📁 iso/              # Extracted ISO data (US, EU, RU)
├── 📁 splat/            # Decompiled code by splat
├── 📁 tools/            # Custom tools
│   ├── 📁 splat/        # Splat disassembly tool
│   ├── 📁 tombatools/   # Tomba-specific utilities
│   └── 📁 mkpsxiso/     # PSX ISO reconstruction
├── 📄 *.bin/*.cue       # Original ISOs
└── 📄 *.xml             # ISO build scripts
```

## 🛠️ Tools Used

### Core Tools
- **[Splat](https://github.com/ethteck/splat)** - Primary PSX disassembler
- **[TombaTools](tools/tombatools/)** - Custom utilities for game files
- **[mkpsxiso](https://github.com/Lameguy64/mkpsxiso)** - PSX ISO creation
- **PSYQ SDK** - Original PlayStation toolchain

### TombaTools Features
- 🎨 **WFM Font Processing**: Extract and modify font glyphs with transparency support
- 📦 **GAM Archive Management**: Compress/decompress game data archives with integrity verification
- 🖼️ **PSX Graphics Support**: Native 4bpp format handling with palette management
- 📝 **Metadata Export**: JSON/YAML export for easy data editing and analysis
- 🔧 **Batch Operations**: Process multiple files with command-line automation
- 🎭 **Image Export**: PNG extraction with configurable transparency and sprite sheets

## 🚀 Getting Started

### Prerequisites

- **Python 3.8+** (for splat)
- **Go 1.21+** (for tombatools)
- **Make** (optional, for automation)
- **PSX Toolchain** (PSYQ recommended)

### Initial Setup

1. **Clone the repository**
```bash
git clone https://github.com/hansbonini/tomba-decomp.git
cd tomba-decomp
```

2. **Prepare the ISOs**
   - Place your Tomba! ISOs in the project root
   - Supported ISOs: `Tomba! (USA).bin/cue`, `Tombi! (Europe).bin/cue`

3. **Install dependencies**
```bash
# Install splat
cd tools/splat
pip install -r requirements.txt

# Compile tombatools
cd ../tombatools
make build
```

4. **Run initial extraction**
```bash
# Extract ISO data
python tools/splat/split.py config/scus_942.36.yaml

# Extract GAM archive files
./tools/tombatools/tombatools.exe gam extract iso/us/AREA00/A000.GAM ./extracted/

# Extract font files for analysis
./tools/tombatools/tombatools.exe wfm extract iso/us/SYSTEM/FONT.WFM ./fonts/
```

## 📊 Decompilation Progress

### SCUS-94236 (NTSC-U)
```
🟩🟩🟩🟨⬜⬜⬜⬜⬜⬜ 35% Complete

✅ Boot & System      (100%)
✅ Main Engine        (85%)
🔄 Game Logic         (45%)
🔄 Graphics Engine    (30%)
⬜ Audio System       (15%)
⬜ Menu System        (20%)
```

### Details by Area
- **AREA00-05**: 🟩 Main decompilation complete
- **AREA06-10**: 🟨 Actively in progress
- **AREA11-19**: ⬜ Awaiting analysis

## 🤝 How to Contribute

Contributions are very welcome! Here are some ways to help:

### 🐛 Report Bugs
- Use [Issues](https://github.com/hansbonini/tomba-decomp/issues) to report problems
- Include detailed logs and steps to reproduce

### 💻 Code Contributions
1. Fork the project
2. Create a branch for your feature (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Open a Pull Request

### 📝 Documentation
- Improve this README
- Document discovered functions
- Create tutorials and guides

### 🔍 Code Analysis
- Identify and name functions
- Document data structures
- Map execution flows

## 📚 Resources and Documentation

### Technical Documentation
- [📖 PSX Analysis Guide](docs/psx-analysis.md)
- [🔧 Environment Setup](docs/setup.md)
- [🎮 Game Structures](docs/game-structures.md)
- [📦 GAM File Format](docs/gam-format.md)
- [🎨 WFM Font Format](docs/wfm-format.md)
- [⚙️ TombaTools Examples](docs/tombatools-examples.md)
- [🛠️ TombaTools Commands](docs/tombatools-commands.md)
- [📋 TombaTools Setup](docs/tombatools-setup.md)
- [🎯 Game File Formats](docs/game-formats.md)

### External Resources
- [PSX Development Wiki](https://psx-spx.consoledev.net/)
- [PSYQ Documentation](http://psxdev.net/help.html)
- [Tomba! TCRF Page](https://tcrf.net/Tomba!)

## ⚖️ Legal Aspects

This project is intended **exclusively for educational and preservation purposes**.

- ✅ Only use ISOs you legally own
- ✅ Do not redistribute proprietary code
- ✅ Respect Whoopee Camp/Sony copyrights
- ⚠️ This project does not include proprietary assets or code

## 🏆 Credits and Acknowledgments

### Core Team
- **Hans Bonini** - Project lead and main development
- **PSX-Dev Community** - Technical support and tools

### Tools and Libraries
- [Splat](https://github.com/ethteck/splat) by ethteck
- [mkpsxiso](https://github.com/Lameguy64/mkpsxiso) by Lameguy64
- [PSX.Dev](https://psx.dev) community for documentation

### Special Thanks
- **zerovii** - Material and explanations about WFM format
- **vervalkon** - Material and explanations about quad polygon coordinates and GAM format
- **ethteck** - Creator of splat, the disassembler that makes this project possible
- **PCSX-Redux Team** - Advanced PlayStation emulator with debugging capabilities
- **DuckStation Team** - High-accuracy PlayStation emulator for testing and verification

## 📞 Contact and Community

- 💬 **Discord**: [Tomba.Club](https://discord.gg/tomba-club)
- 🌐 **Website**: [hansbonini.com.br](https://hansbonini.com.br)

---

<div align="center">
  <img src="https://github.com/user-attachments/assets/tomba-pixel-art.gif" alt="Tomba Running" width="64"/>
  
  **"Let's catch all the evil pigs!"** - Tomba
  
  Made with 💖 by the game preservation community
</div>