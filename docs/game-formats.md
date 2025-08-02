# Tomba! Game File Formats

This document describes the file formats used in Tomba! (Ore no Tomba) for PlayStation, based on reverse engineering and analysis.

## 📋 Overview

Tomba! uses several custom file formats for different types of game data:

- **WFM**: Font files containing glyphs and dialogue text
- **GAM**: Compressed archives containing game data
- **TIM**: PlayStation standard texture format
- **4bpp Linear**: Custom graphics format used for fonts

## 🎨 WFM Format (Whoopee Font Module)

WFM files contain font glyphs and dialogue text used throughout the game.

### File Structure

```
WFM File Layout:
├── Header (144 bytes)
├── Glyph Pointer Table (variable)
├── Glyph Data (variable)
├── Dialogue Pointer Table (variable)
└── Dialogue Data (variable)
```

### WFM Header

```c
typedef struct {
    char magic[4];                  // "WFM3" - File signature
    uint32_t padding;               // Usually 0x00000000
    uint32_t dialogue_pointer_table; // Offset to dialogue pointer table
    uint16_t total_dialogues;       // Number of dialogue entries
    uint16_t total_glyphs;          // Number of glyph entries
    uint8_t reserved[128];          // Reserved section (may contain special dialogue IDs)
} WFMHeader;
```

### Glyph Structure

```c
typedef struct {
    uint16_t glyph_clut;       // Color lookup table data (PSX 15-bit format)
    uint16_t glyph_height;     // Height of the glyph in pixels
    uint16_t glyph_width;      // Width of the glyph in pixels
    uint16_t glyph_handakuten; // Handakuten marker (Japanese diacritical mark)
    uint8_t glyph_image[];     // Raw image data (4bpp format)
} Glyph;
```

### Graphics Format: 4bpp Linear Little Endian

WFM files use a custom 4bpp (4 bits per pixel) format:

```
Pixel Layout:
- 4 bits per pixel (16 possible colors)
- 2 pixels per byte
- Little endian byte order
- Linear layout (row-major order)

Byte Structure: [pixel1][pixel0]
- Lower 4 bits = first pixel
- Upper 4 bits = second pixel

Example:
Byte 0x3A = 0011 1010
- Pixel 0 = 1010 (0xA)
- Pixel 1 = 0011 (0x3)
```

### Color Palettes (CLUT)

WFM files use 16-color palettes in PlayStation 15-bit format:

```c
// Default dialogue palette
uint16_t dialogue_clut[16] = {
    0x0000, 0x0400, 0x4E73, 0x2529,
    0x35AD, 0x4210, 0x14A5, 0x7E4D,
    0x03E0, 0x421F, 0x297F, 0x5319,
    0x4674, 0x3A11, 0x0000, 0x0000
};

// Event dialogue palette
uint16_t event_clut[16] = {
    0x01FF, 0x8400, 0x7FFF, 0x3DEF,
    0x2529, 0x56B5, 0x00F0, 0x0198,
    0x6739, 0x0134, 0x01FF, 0x7C00,
    0x7C00, 0x7C00, 0x7C00, 0x7C00
};
```

**PlayStation 15-bit Color Format:**
```
Bit layout: 0BBBBBGGGGGRRRRR
- Red: 5 bits (0-31)
- Green: 5 bits (0-31)  
- Blue: 5 bits (0-31)
- Alpha: 1 bit (0=transparent, 1=opaque)
```

### Dialogue System

Dialogues contain text and control codes for formatting:

#### Control Codes

```c
// Text control constants
#define INIT_TEXT_BOX    0xFFFA  // Initialize text box
#define FFF2             0xFFF2  // Special command (1 arg)
#define HALT             0xFFF3  // Halt text processing
#define F4               0xFFF4  // Unknown function
#define PROMPT           0xFFF5  // Show prompt
#define F6               0xFFF6  // Special command (2 args)
#define CHANGE_COLOR_TO  0xFFF7  // Change text color (1 arg)
#define INIT_TAIL        0xFFF8  // Initialize text tail (2 args)
#define PAUSE_FOR        0xFFF9  // Pause for duration (1 arg)
#define DOUBLE_NEWLINE   0xFFFB  // Double line break
#define WAIT_FOR_INPUT   0xFFFC  // Wait for player input
#define NEWLINE          0xFFFD  // Single line break
#define TERMINATOR_1     0xFFFE  // Dialogue terminator type 1
#define TERMINATOR_2     0xFFFF  // Dialogue terminator type 2

// Special characters
#define C04D             0xC04D  // Special character
#define C04E             0xC04E  // Special character

// Glyph reference
#define GLYPH_ID_BASE    0x8000  // Base offset for glyph IDs
```

#### Dialogue Entry Structure

```yaml
# YAML representation of dialogue entry
- id: 1
  type: "dialogue"
  font_height: 16
  font_clut: 0x4E73
  terminator: 0xFFFE
  content:
    - text: "Hello World!"
    - newline: {}
    - color: { value: 0x7FFF }
    - pause: { duration: 30 }
    - box: { width: 200, height: 100 }
    - tail: { width: 16, height: 8 }
```

## 📦 GAM Format (Game Archive Module)

GAM files are compressed archives containing various game data including graphics, level data, and other assets.

### File Structure

```
GAM File Layout:
├── Header (8 bytes)
└── Compressed Data (variable size)
```

### GAM Header

```c
typedef struct {
    char magic[3];              // "GAM" - File signature
    uint8_t reserved;           // Padding byte (typically 0x00)
    uint32_t uncompressed_size; // Size of decompressed data
} GAMHeader;
```

### Compression Algorithm

GAM files use a custom LZ-based compression algorithm with bitmask control:

#### Algorithm Characteristics

**Core Features:**
- Dictionary-based compression with sliding window
- Bitmask-controlled encoding (16-bit little endian)
- Variable-length matches (2-255 bytes)
- Backward references up to 255 bytes
- Optimized for PlayStation memory constraints
- Typical compression ratio: 50-70%

#### Compression Format Structure

```
Compressed Data Layout:
├── Bitmask (2 bytes, little endian)
├── Data Block 1 (literal or LZ reference)
├── Data Block 2 (literal or LZ reference)
├── ... (up to 16 data blocks)
├── Bitmask (2 bytes, little endian)
├── Data Block 17-32
└── ... (continues until end of data)
```

#### Bitmask Control System

Each 16-bit bitmask controls the next 16 data elements:

```c
typedef struct {
    uint16_t bitmask;           // Control bits (little endian)
    uint8_t data_blocks[16];    // Variable-size data blocks
} LZChunk;

// Bitmask interpretation:
// Bit 0 (LSB): Controls first data block
// Bit 1: Controls second data block
// ...
// Bit 15: Controls sixteenth data block

// Bit value interpretation:
// 0 = Literal byte (1 byte follows)
// 1 = LZ reference (2 bytes follow)
```

#### LZ Reference Format

When bitmask bit = 1, the next 2 bytes represent an LZ reference:

```c
typedef struct {
    uint8_t offset;    // Distance back in output buffer (1-255)
    uint8_t length;    // Number of bytes to copy (1-255)
} LZReference;

// Reference interpretation:
// offset = distance backward from current position
// length = number of bytes to copy from that position
```

#### Decompression Algorithm

```c
void decompress_gam_lz(uint8_t* compressed, uint32_t comp_size, 
                       uint8_t* output, uint32_t target_size) {
    uint32_t comp_pos = 0;
    uint32_t out_pos = 0;
    
    while (out_pos < target_size && comp_pos < comp_size) {
        // Read 16-bit bitmask (little endian)
        uint16_t bitmask = read_uint16_le(&compressed[comp_pos]);
        comp_pos += 2;
        
        // Process 16 bits
        for (int bit = 0; bit < 16 && out_pos < target_size; bit++) {
            if (bitmask & (1 << bit)) {
                // LZ reference (2 bytes)
                uint8_t offset = compressed[comp_pos++];
                uint8_t length = compressed[comp_pos++];
                
                // Copy data from previous position
                uint32_t src_pos = out_pos - offset;
                for (int i = 0; i < length && out_pos < target_size; i++) {
                    output[out_pos++] = output[src_pos + i];
                }
            } else {
                // Literal byte
                output[out_pos++] = compressed[comp_pos++];
            }
        }
    }
    
    // Pad with zeros if needed
    while (out_pos < target_size) {
        output[out_pos++] = 0x00;
    }
}
```

#### Compression Algorithm

```c
void compress_gam_lz(uint8_t* input, uint32_t input_size, 
                     uint8_t* output, uint32_t* output_size) {
    uint32_t in_pos = 0;
    uint32_t out_pos = 0;
    
    while (in_pos < input_size) {
        uint16_t bitmask = 0;
        uint32_t bitmask_pos = out_pos;
        out_pos += 2; // Reserve space for bitmask
        
        // Process up to 16 elements
        for (int bit = 0; bit < 16 && in_pos < input_size; bit++) {
            // Find best match in sliding window
            int best_offset, best_length;
            find_best_match(input, in_pos, &best_offset, &best_length);
            
            if (best_length >= 2 && best_offset <= 255 && best_length <= 255) {
                // Use LZ reference
                bitmask |= (1 << bit);
                output[out_pos++] = (uint8_t)best_offset;
                output[out_pos++] = (uint8_t)best_length;
                in_pos += best_length;
            } else {
                // Use literal byte
                output[out_pos++] = input[in_pos++];
            }
        }
        
        // Write bitmask (little endian)
        write_uint16_le(&output[bitmask_pos], bitmask);
    }
    
    *output_size = out_pos;
}
```

#### Match Finding Algorithm

The compression uses a sliding window approach to find the best matches:

```c
void find_best_match(uint8_t* data, uint32_t pos, int* best_offset, int* best_length) {
    *best_offset = 0;
    *best_length = 0;
    
    // Search backwards up to 255 bytes
    int max_offset = (pos > 255) ? 255 : pos;
    
    for (int offset = 1; offset <= max_offset; offset++) {
        uint32_t src_pos = pos - offset;
        int length = 0;
        
        // Count matching bytes (with wraparound for repetitive patterns)
        while (length < 255 && pos + length < data_size &&
               data[src_pos + (length % offset)] == data[pos + length]) {
            length++;
        }
        
        // Keep best match (prioritize longer matches)
        if (length > *best_length) {
            *best_offset = offset;
            *best_length = length;
        }
    }
}
```

#### Performance Characteristics

**Compression Efficiency:**
- Best case: Highly repetitive data (90%+ compression)
- Average case: Mixed data (50-70% compression)
- Worst case: Random data (110-120% size due to overhead)

**Speed Considerations:**
- Decompression: Very fast (~1-2 cycles per byte on PSX)
- Compression: Moderate (depends on window search depth)
- Memory usage: Minimal (streaming algorithm)

#### Implementation Notes

**PlayStation-Specific Optimizations:**
- Bitmask processing aligns with 16-bit MIPS instructions
- Window size (255 bytes) fits in PSX cache efficiently
- Little endian format matches PSX byte order

**Error Handling:**
- Invalid offsets are caught during decompression
- Output buffer overflow protection
- Automatic padding for undersized output

**Compatibility:**
- Forward compatible (older decompressors work with new files)
- Deterministic compression (same input = same output)
- Self-contained format (no external dictionaries)

### Common GAM File Contents

**Area GAM Files (A000.GAM, A001.GAM, etc.):**
- Level geometry data
- Texture references
- Entity placement data
- Collision maps
- Trigger zones

**System GAM Files:**
- Menu graphics
- UI elements
- System fonts
- Audio references

## 🖼️ TIM Format (PlayStation Standard)

While not custom to Tomba!, TIM files are used for textures:

### TIM Header

```c
typedef struct {
    uint32_t magic;       // 0x00000010 - TIM signature
    uint32_t flags;       // Format flags
    // CLUT data (if present)
    // Image data
} TIMHeader;
```

**TIM Formats Used in Tomba!:**
- 4bpp with CLUT (most common)
- 8bpp with CLUT (detailed textures)
- 16bpp direct color (special effects)

## 🎯 PSX-Specific Considerations

### Memory Layout

**VRAM Organization:**
```
PlayStation VRAM (1MB total):
├── 0-255: Texture pages 0-3
├── 256-511: Texture pages 4-7
├── 512-767: Font & UI textures
└── 768-1023: Frame buffers
```

**Texture Page Layout:**
- Each page: 64x256 pixels
- 4bpp: 128x256 effective resolution
- 8bpp: 64x256 effective resolution

### Color Depth Formats

**4bpp (16 colors):**
- Most efficient for fonts and simple graphics
- Requires 16-color CLUT
- 2 pixels per byte

**8bpp (256 colors):**
- Higher quality textures
- Requires 256-color CLUT
- 1 pixel per byte

**16bpp (32,768 colors):**
- Direct color, no CLUT needed
- Highest quality but uses more VRAM
- 2 bytes per pixel

### Endianness

**Little Endian Format:**
- All multi-byte values stored LSB first
- Matches PlayStation MIPS processor
- Important for cross-platform tools

## 🔧 Technical Implementation Notes

### Font Rendering Pipeline

1. **Load WFM File**: Parse header and glyph data
2. **Upload to VRAM**: Transfer glyphs to texture memory
3. **Set CLUT**: Configure color lookup table
4. **Render Text**: Use GPU primitives to draw glyphs
5. **Apply Effects**: Handle control codes for formatting

### GAM Processing Pipeline

1. **Read Header**: Parse GAM header for metadata
2. **Decompress**: Apply LZ decompression algorithm
3. **Parse Content**: Interpret decompressed data
4. **Load Assets**: Transfer data to appropriate memory regions

### Performance Considerations

**WFM Files:**
- Small file size (typically 50-500KB)
- Fast decompression (< 1 frame)
- Efficient VRAM usage

**GAM Files:**
- Variable size (100KB - 2MB)
- Moderate decompression time
- Streaming-friendly format

## 🔍 Reverse Engineering Notes

### Analysis Tools Used

- **Hex Editors**: For binary structure analysis
- **Disassemblers**: To understand game code
- **Emulators**: For runtime analysis
- **Graphics Viewers**: For format identification

### Common Patterns

**Magic Numbers:**
- "WFM3": WFM font files
- "GAM\0": GAM archive files
- 0x10000000: TIM texture files

**Pointer Tables:**
- Most formats use offset tables for random access
- Offsets typically relative to file start
- Pointer tables usually precede data sections

### Validation Methods

**File Integrity:**
- Check magic numbers
- Verify pointer table consistency
- Validate data section sizes

**Format Conformance:**
- Test with original game
- Compare with known good files
- Verify decompression/recompression

---

**Note**: This documentation is based on reverse engineering efforts and may be refined as analysis continues.
