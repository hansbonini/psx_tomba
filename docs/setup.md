# Tomba! PSX Decompilation Project Setup Guide

This guide will help you set up your development environment for the Tomba! (Ore no Tomba) PlayStation decompilation project.

## 📋 Prerequisites

### System Requirements

- **Operating System**: Windows 10/11, Linux (Ubuntu 20.04+), or macOS (10.15+)
- **RAM**: Minimum 8GB, recommended 16GB+
- **Storage**: At least 10GB free space
- **CPU**: x64 processor with SSE2 support

### Required Software

- **Git**: Version control system
- **Python**: 3.8 or higher
- **Go**: 1.21 or higher (for TombaTools)
- **Text Editor/IDE**: VS Code, Vim, or similar
- **Hex Editor**: HxD (Windows), Bless (Linux), or Hex Fiend (macOS)

## 🎮 Game Files Required

You need legal copies of the following Tomba! game files:

### Supported Versions

- **Tomba! (USA)** - SCUS-94236
- **Tombi! (Europe)** - SCES-01330 (En,Fr,De,It,Nl) Rev 1
- **Ore no Tomba! (Japan)** - SLPS-01443

### File Formats

- **ISO/BIN+CUE**: Disc image files
- **Extracted Files**: Already extracted game files

> **⚠️ Legal Notice**: You must own a legal copy of the game to participate in this project. We cannot and will not provide copyrighted game files.

## 🛠️ Installation Steps

### 1. Clone the Repository

```bash
git clone https://github.com/hansbonini/tomba-decompilation.git
cd tomba-decompilation
```

### 2. Set Up Python Environment

#### Option A: Using Virtual Environment (Recommended)

```bash
# Create virtual environment
python -m venv venv

# Activate virtual environment
# On Windows:
venv\Scripts\activate
# On Linux/macOS:
source venv/bin/activate

# Install dependencies
pip install -r requirements.txt
```

#### Option B: System-wide Installation

```bash
pip install -r requirements.txt
```

### 3. Install Splat Disassembler

Splat is the core tool used for disassembling the PlayStation executable:

```bash
# Clone splat repository
git clone https://github.com/ethteck/splat.git tools/splat
cd tools/splat

# Install splat dependencies
pip install -r requirements.txt

# Install splat
pip install .

# Return to project root
cd ../..
```

### 4. Install TombaTools

TombaTools handles game-specific file formats (WFM fonts and GAM archives):

#### Option A: Download Pre-built Binary (Windows)

1. Download `tombatools.exe` from the releases page
2. Place it in the `tools/tombatools/` directory
3. Add to your PATH or use full path

#### Option B: Build from Source

```bash
# Navigate to TombaTools directory
cd tools/tombatools

# Build the tool
go build -o tombatools.exe .

# Verify installation
./tombatools.exe --version

# Return to project root
cd ../..
```

### 5. Set Up Game Files

#### Extract Game ISO

If you have an ISO file, extract it first:

```bash
# Using 7-Zip (Windows)
7z x "Tomba! (USA).iso" -o"iso/us/"

# Using bchunk (Linux)
bchunk "Tomba! (USA).bin" "Tomba! (USA).cue" iso/us/track

# Using built-in tools (macOS)
hdiutil mount "Tomba! (USA).iso"
cp -r /Volumes/TOMBA/* iso/us/
hdiutil unmount /Volumes/TOMBA
```

#### Organize Game Files

Create the following directory structure:

```
iso/
├── us/          # USA version files
├── eu/          # European version files
└── jp/          # Japanese version files (if available)
```

Place the extracted game files in the appropriate directory based on your version.

## ⚙️ Configuration

### 1. Configure Splat

The project includes pre-configured Splat YAML files for each game version:

- `SCUS_94236.yaml` - USA version
- `SCES_01330.yaml` - European version

Edit the appropriate YAML file to match your setup:

```yaml
# Example configuration in SCUS_94236.yaml
options:
  platform: psx
  basename: SCUS_942.36
  target_path: iso/us/SCUS_942.36
  base_path: .
  asm_path: asm
  src_path: src
  build_path: build
  
# Update paths to match your file locations
segments:
  - name: main
    type: code
    start: 0x80010000
    vram: 0x80010000
    follows_vram: entry
    bss_size: 0x1234
```

### 2. Verify Installation

Run the verification script to ensure everything is set up correctly:

```bash
python tools/verify_setup.py
```

This script will check:
- Python version and dependencies
- Splat installation
- TombaTools functionality
- Game file presence

## 🚀 First Steps

### 1. Initial Disassembly

Start by disassembling the main executable:

```bash
# For USA version
python tools/splat/split.py SCUS_94236.yaml

# For European version
python tools/splat/split.py SCES_01330.yaml
```

This will create:
- `asm/` - Assembly files
- `src/` - C source files (for identified functions)
- `build/` - Build output directory

### 2. Extract Game Assets

Extract fonts and archives using TombaTools:

```bash
# Extract all WFM font files
for file in iso/us/AREA*/A*.GAM; do
    tools/tombatools/tombatools.exe gam unpack "$file" "extracted/$(basename "$file" .GAM)/"
done

# Extract font files from archives
find extracted/ -name "*.WFM" -exec tools/tombatools/tombatools.exe wfm decode {} {}.yaml \;
```

### 3. Build Test

Attempt to build the disassembled code:

```bash
# Create build directory
mkdir -p build

# Run makefile
make
```

The initial build may fail - this is expected. The goal is to gradually replace assembly with C code.

## 📁 Project Structure

After setup, your project should look like this:

```
tomba-decompilation/
├── asm/                    # Generated assembly files
├── build/                  # Build output
├── config/                 # Splat configuration files
├── docs/                   # Documentation
├── extracted/              # Extracted game assets
├── iso/                    # Game ISO files
│   ├── us/                # USA version
│   ├── eu/                # European version
│   └── jp/                # Japanese version
├── src/                    # C source files
├── tools/                  # Development tools
│   ├── splat/             # Splat disassembler
│   └── tombatools/        # Game-specific tools
├── Makefile               # Build configuration
├── requirements.txt       # Python dependencies
└── README.md             # Project overview
```

## 🔧 Development Tools

### Recommended Extensions (VS Code)

Install these VS Code extensions for the best development experience:

```bash
# C/C++ support
code --install-extension ms-vscode.cpptools

# Assembly syntax highlighting
code --install-extension 13xforever.language-x86-64-assembly

# YAML support
code --install-extension redhat.vscode-yaml

# Hex editor
code --install-extension ms-vscode.hexeditor

# Git integration
code --install-extension eamodio.gitlens
```

### Debugging Tools

- **PCSX-Redux**: PlayStation emulator with debugging capabilities
- **DuckStation**: Fast PlayStation emulator for testing
- **NO$PSX**: Advanced PlayStation debugger
- **Ghidra**: Reverse engineering framework with PSX support

## 🔍 Analysis Workflow

### 1. Function Identification

1. Analyze assembly patterns to identify game functions
2. Create function stubs in C
3. Gradually implement function bodies

### 2. Data Structure Analysis

1. Examine memory dumps from emulators
2. Identify data patterns in hex editors
3. Create C structures to match data layouts
4. Validate structures against game behavior

### 3. Asset Extraction

1. Use TombaTools to extract WFM and GAM files
2. Analyze extracted data with hex editors
3. Document file formats
4. Create tools for asset modification

## 🎯 Performance Tips

### Build Performance

- Use parallel builds: `make -j$(nproc)`
- Enable ccache for faster rebuilds
- Use ramdisk for temporary files (Linux/macOS)

### Analysis Performance

- Use SSD storage for faster file operations
- Increase virtual memory if analyzing large files
- Close unnecessary applications during heavy analysis

## 🐛 Troubleshooting

### Common Issues

#### Python Import Errors

```bash
# Error: ModuleNotFoundError: No module named 'X'
pip install -r requirements.txt
```

#### Splat Configuration Errors

```bash
# Error: Invalid YAML configuration
python -m yaml.tool SCUS_94236.yaml
```

#### TombaTools Build Errors

```bash
# Ensure Go is properly installed
go version

# Clean and rebuild
go clean
go build -o tombatools.exe .
```

#### Missing Game Files

```bash
# Verify file paths in YAML configuration
ls -la iso/us/SCUS_942.36
```

### Getting Help

1. **Check Documentation**: Read all files in the `docs/` directory
2. **Search Issues**: Look through GitHub issues for similar problems
3. **Ask the Community**: Join our Discord server at Tomba.Club
4. **Create an Issue**: Report bugs or request features on GitHub

## 📚 Next Steps

After completing the setup:

1. **Read the Documentation**: Familiarize yourself with the game formats and tools
2. **Start Small**: Begin with simple functions or data structures
3. **Collaborate**: Share your findings with the community
4. **Document**: Update documentation as you learn more about the game

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for detailed contribution guidelines.

### Quick Start for Contributors

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/my-analysis`
3. Make your changes and commit: `git commit -am "Add analysis for X"`
4. Push to your fork: `git push origin feature/my-analysis`
5. Create a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Happy Decompiling!** 🎮✨

If you encounter any issues during setup, please check our [troubleshooting guide](troubleshooting.md) or reach out to the community for support.
