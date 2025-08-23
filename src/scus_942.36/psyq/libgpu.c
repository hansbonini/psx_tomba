/**
 * @file libgpu.c
 * @brief PlayStation PSYQ Graphics Processing Unit (GPU) Library
 * 
 * This library provides functions for managing the PlayStation's GPU, including:
 * - Graphics initialization and configuration
 * - Drawing environment setup
 * - Display environment setup  
 * - Primitive rendering and ordering tables
 * - VRAM memory management
 * - Graphics debugging utilities
 * - TMD (3D model) processing
 * 
 * The library is part of the official PSYQ SDK from Sony and provides
 * low-level access to the PlayStation's graphics hardware.
 * 
 * @note This is a reverse-engineered implementation based on the original
 *       PSYQ library for compatibility with the PSX Tomba! project.
 */

#include "common.h"

#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"

#define OT_TYPE u_long
#define CMD_CLEAR_CACHE 0x01000000
#define CMD_COPY_VRAM_TO_CPU 0xC0000000
#define CMD_COPY_CPU_TO_VRAM 0xA0000000
#define CMD_FILL_RECTANGLE_IN_VRAM(color) ((color & 0xFFFFFF) | 0x02000000)
#define CMD_MONOCHROME_RECTANGLE(color) ((color & 0xFFFFFF) | 0x60000000)
#define CLAMP(a, b, c) (a >= b ? (a > c ? c : a) : b)
#define CMPRECT(r1, r2)  (\
    ((volatile RECT*)r1)->x == r2.x && \
    ((volatile RECT*)r1)->y == r2.y && \
    ((volatile RECT*)r1)->w == r2.w && \
    ((volatile RECT*)r1)->h == r2.h\
)
#define LOAD_SVECTOR_XYZ(dest, base, index, offset) do { \
    (dest).vx = (*(SVECTOR *)((index * 8) + base)).vx; \
    (dest).vy = (*(SVECTOR *)((index * 8) + base)).vy; \
    (dest).vz = (*(SVECTOR *)((index * 8) + base)).vz; \
} while(0)
#define TERM_PRIM(ot, p) *ot = (u_long)p & 0xFFFFFF

typedef struct {
    /* 0x00 */ const char* ver; // D_80015BA8
    /* 0x04 */ void (*addque)();
    /* 0x08 */ int (*addque2)();
    /* 0x0C */ int (*clr)();
    /* 0x10 */ void (*ctl)(unsigned int);
    /* 0x14 */ int (*cwb)(u32* data, s32 n);
    /* 0x18 */ void (*cwc)();
    /* 0x1C */ int (*drs)();
    /* 0x20 */ int (*dws)();
    /* 0x24 */ int (*exeque)();
    /* 0x28 */ int (*getctl)(int);
    /* 0x2C */ void (*otc)(OT_TYPE* ot, s32 n);
    /* 0x30 */ int (*param)(int);
    /* 0x34 */ int (*reset)(int);
    /* 0x38 */ u_long (*status)(void);
    /* 0x3C */ int (*sync)(int mode);
} GPU;

typedef struct {
    // GPU version
    // https://psx-spx.consoledev.net/graphicsprocessingunitgpu/#gpu-versions
    u_char version;

    u_char D_80090C9D;
    u_char level;
    u_char reverse;
    short w;
    short h;
    u8 unk8[4];
    void (*drawSyncCb)();
    DRAWENV draw;
    DISPENV disp;
 } DEBUG;                               // size = 0x40

typedef struct {
    u_long tag;
    u_long code[2];
} DR_PRIO;

typedef struct {
    int vert;
    int nvert;
    int norm;
    int nnorm;
    int prim;
    int nprim;
    int scaling;
} TmdObj;

typedef struct {
    int id;
    int flags;
    int nobj;
    TmdObj obj[1];
} TMD;

typedef struct QueueItem {
    int unk0;
    int unk4;
    int unk8;
    int unkC[2];
    int unk14;
    int unk18;
    char padding[0x14 + 0x1C + 0x14];
} QueueItem;


extern s32 D_80090C54;
extern GPU* D_80090C94;
extern DEBUG GPU_INFO;
extern s32 D_80090D1C[];
extern s32 D_80090D30[];
extern u32 D_80090D4C[];
extern volatile s32 D_80090D58;
extern volatile s32* GPU_DATA;
extern volatile s32* GPU_STATUS;
extern volatile s32* DMA1_MADR;
extern volatile s32* DMA1_BCR;
extern volatile s32* DMA1_CHCR;
extern volatile s32* DMA2_CHCR;
extern volatile s32* DMA2_MADR;
extern volatile s32* DMA2_BCR;
extern volatile s32* DPCR;
extern volatile s32 D_80090D90;
extern volatile s32 D_80090D94;
extern volatile s32 D_80090D98;
extern volatile s32 GPU_QIN;
extern volatile s32 GPU_QOUT;
extern s32 D_80090DA8;
extern s32 D_80090DAC;
extern s32 D_80090DB0;
extern s32 D_80090DB4;
extern s32 D_80090DB8;
extern s32 D_8009B148;
extern s32 D_8009B14C;
extern s32 D_8009B150;
extern s32 D_8009B154;
extern s32 D_8009B158;
extern s32 D_8009B15C;
extern s32 D_8009B160;
extern s32 D_8009B164;
extern s32 D_8009B168;
extern s32 D_8009B16C;
extern s32 D_8009B170;
extern s32 D_8009B174;
extern s32 D_8009B178;
extern u8 GPU_CTLBUF[];
extern u32* D_8009B290;
extern s32 D_8009B294;
extern s32 D_8009B298;
extern s32 D_8009B29C;
extern s32 D_8009B2A0;
extern volatile QueueItem GPU_QITEM[];

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadTPage);
/**
 * @brief Load texture page data into VRAM
 * 
 * Loads pixel data into VRAM and returns a texture page identifier.
 * The width is automatically adjusted based on the texture mode (tp).
 * 
 * @param pix Pointer to pixel data to load
 * @param tp Texture mode: 0=4bit, 1=8bit, 2=16bit
 * @param abr Alpha blending rate (0-3)
 * @param x X coordinate in VRAM (must be multiple of 64 for tp=0, 32 for tp=1)
 * @param y Y coordinate in VRAM
 * @param w Width in pixels (actual VRAM width depends on tp)
 * @param h Height in pixels
 * @return Texture page identifier for use with primitives
 */
u_short LoadTPage(u_long* pix, int tp, int abr, int x, int y, int w, int h) {
    RECT rect;
    rect.x = x;
    rect.y = y;
    rect.h = h;
    switch (tp) {
    case 0:
        rect.w = w / 4;
        break;
    case 1:
        rect.w = w / 2;
        break;
    case 2:
        rect.w = w;
        break;
    }
    LoadImage(&rect, pix);
    return GetTPage(tp, abr, x, y);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut);
/**
 * @brief Load 256-color palette (CLUT) into VRAM
 * 
 * Loads a 256-color palette into VRAM at the specified coordinates.
 * The palette data takes up 256 pixels horizontally and 1 pixel vertically.
 * 
 * @param clut Pointer to palette data (256 16-bit color values)
 * @param x X coordinate in VRAM (typically 0-1023)
 * @param y Y coordinate in VRAM (typically in upper area 256-511)
 * @return CLUT identifier for use with textured primitives
 */
u_short LoadClut(u_long* clut, int x, int y) {
    RECT rect;
    rect.x = x;
    rect.y = y;
    rect.w = 256;
    rect.h = 1;
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut2);
/**
 * @brief Load 16-color palette (CLUT) into VRAM
 * 
 * Loads a 16-color palette into VRAM at the specified coordinates.
 * The palette data takes up 16 pixels horizontally and 1 pixel vertically.
 * 
 * @param clut Pointer to palette data (16 16-bit color values)
 * @param x X coordinate in VRAM (typically 0-1023)
 * @param y Y coordinate in VRAM (typically in upper area 256-511)
 * @return CLUT identifier for use with textured primitives
 */
u_short LoadClut2(u_long* clut, int x, int y) {
    RECT rect;
    rect.x = x;
    rect.y = y;
    rect.w = 16;
    rect.h = 1;
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDefDrawEnv);
/**
 * @brief Initialize drawing environment with default values
 * 
 * Sets up a drawing environment structure with sensible defaults.
 * The drawing environment controls clipping area, texture window,
 * background color, and other rendering parameters.
 * 
 * @param env Pointer to DRAWENV structure to initialize
 * @param x X coordinate of drawing area
 * @param y Y coordinate of drawing area  
 * @param w Width of drawing area
 * @param h Height of drawing area
 * @return Pointer to the initialized DRAWENV structure
 */
DRAWENV* SetDefDrawEnv(DRAWENV* env, int x, int y, int w, int h)
{
    s32 videomode = GetVideoMode();
    env->clip.x = x;
    env->clip.y = y;
    env->clip.w = w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = h;
    if (videomode != 0) {
        env->dfe = h <= 288;
    } else {
        env->dfe = h <= 256;
    }
    env->ofs[0] = x;
    env->ofs[1] = y;
    if (GetGraphType() != 1) {
        GetGraphType();
    }
    env->tpage = 10;
    env->isbg = 0;
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDefDispEnv);
/**
 * @brief Initialize display environment with default values
 * 
 * Sets up a display environment structure with sensible defaults.
 * The display environment controls the area of VRAM that is shown
 * on screen and various display modes.
 * 
 * @param env Pointer to DISPENV structure to initialize
 * @param x X coordinate of display area in VRAM
 * @param y Y coordinate of display area in VRAM
 * @param w Width of display area
 * @param h Height of display area
 * @return Pointer to the initialized DISPENV structure
 */
DISPENV* SetDefDispEnv(DISPENV* env, int x, int y, int w, int h) {
    env->disp.x = x;
    env->disp.y = y;
    env->disp.w = w;
    env->disp.h = h;
    env->screen.x = 0;
    env->screen.y = 0;
    env->screen.w = 0;
    env->screen.h = 0;
    env->isrgb24 = 0;
    env->isinter = 0;
    env->pad1 = 0;
    env->pad0 = 0;
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetTPage);
u_short GetTPage(int tp, int abr, int x, int y)
{
    s32 result;
    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        result = ((tp & 3 ) << 9) | ((abr & 3) << 7) | ((y & 0x300) >> 3) | ((x & 0x3FF) >> 6);
    } else {
        result = (u16)getTPage(tp,abr,x,y);
    }
    return result;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetClut);
u_short GetClut(int x, int y)
{
    return getClut(x,y);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpTPage);
void DumpTPage(u_short tpage)
{
        u32 temp_v0;
        u32 temp_v0_2; 
        if ((GetGraphType() == 1) || (temp_v0 = tpage & 0xFFFF, (GetGraphType() == 2))) {
            temp_v0_2 = tpage & 0xFFFF;
            GPU_printf("tpage: (%d,%d,%d,%d)\n", (temp_v0_2 >> 9) & 3, (temp_v0_2 >> 7) & 3, (temp_v0_2 << 6) & 0x7C0, (temp_v0_2 * 8) & 0x300);
            return;
        }
        GPU_printf("tpage: (%d,%d,%d,%d)\n", ((tpage) >> 7) & 0x003, ((tpage) >> 5) & 0x003, ((tpage) << 6) & 0x7c0, (((tpage) << 4) & 0x100) + (((tpage) >> 2) & 0x200));
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpClut);
/**
 * @brief Display CLUT (palette) information for debugging
 * 
 * Prints the CLUT coordinates to the debug output. Used for debugging
 * texture and palette issues.
 * 
 * @param clut CLUT identifier as returned by GetClut() or LoadClut()
 */
void DumpClut(u_short clut)
{
    GPU_printf("clut: (%d,%d)\n", (clut & 0x3F) << 4, clut >> 6);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", NextPrim);
/**
 * @brief Get pointer to next primitive in a linked list
 * 
 * Returns a pointer to the next primitive in a chain of linked primitives.
 * Used for traversing primitive lists.
 * 
 * @param p Pointer to current primitive
 * @return Pointer to next primitive, or NULL if end of list
 */
void* NextPrim(void *p) {
    return nextPrim(p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", IsEndPrim);
/**
 * @brief Check if primitive is the end of a list
 * 
 * Determines if the given primitive is the last one in a linked list.
 * 
 * @param p Pointer to primitive to check
 * @return Non-zero if this is the end primitive, zero otherwise
 */
int IsEndPrim(void *p) {
    return isendprim(p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", AddPrim);
/**
 * @brief Add primitive to ordering table
 * 
 * Links a graphics primitive into the specified ordering table entry.
 * Primitives are rendered in order from OT entry 0 to highest entry.
 * 
 * @param ot Pointer to ordering table entry
 * @param p Pointer to primitive to add
 */
void AddPrim(void *ot, void *p) {
    addPrim(ot, p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", AddPrims);
void AddPrims(void *ot, void *p0, void *p1) {
    addPrims(ot, p0, p1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", CatPrim);
void CatPrim(void *p0, void *p1) {
    setaddr(p0, p1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", TermPrim);
void TermPrim(void *p) {
    termPrim(p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSemiTrans);
void SetSemiTrans(void *p, int abe) {
    setSemiTrans(p, abe);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetShadeTex);
void SetShadeTex(void *p, int tge) {
    setShadeTex(p, tge);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyF3);
void SetPolyF3(POLY_F3 *p) {
    setlen(p, 4);
    setcode(p, 0x20);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyFT3);
void SetPolyFT3(POLY_FT3 *p) {
    setlen(p, 7);
    setcode(p, 0x24);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyG3);
void SetPolyG3(POLY_G3 *p) {
    setlen(p, 6);
    setcode(p, 0x30);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyGT3);
void SetPolyGT3(POLY_GT3 *p) {
    setlen(p, 9);
    setcode(p, 0x34);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyF4);
void SetPolyF4(POLY_F4 *p) {
    setlen(p, 5);
    setcode(p, 0x28);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyFT4);
void SetPolyFT4(POLY_FT4 *p) {
    setlen(p, 9);
    setcode(p, 0x2C);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyG4);
void SetPolyG4(POLY_G4 *p) {
    setlen(p, 8);
    setcode(p, 0x38);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyGT4);
void SetPolyGT4(POLY_GT4 *p) {
    setlen(p, 12);
    setcode(p, 0x3C);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt8);
void SetSprt8(SPRT_8 *p) {
    setlen(p, 3);
    setcode(p, 0x74);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt16);
void SetSprt16(SPRT_16 *p) {
    setlen(p, 3);
    setcode(p, 0x7C);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt);
void SetSprt(SPRT *p) {
    setlen(p, 4);
    setcode(p, 0x64);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile1);
void SetTile1(TILE_1 *p) {
    setlen(p, 2);
    setcode(p, 0x68);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile8);
void SetTile8(TILE_8 *p) {
    setlen(p, 2);
    setcode(p, 0x70);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile16);
void SetTile16(TILE_16 *p) {
    setlen(p, 2);
    setcode(p, 0x78);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile);
void SetTile(TILE *p) {
    setlen(p, 3);
    setcode(p, 0x60);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF2);
void SetLineF2(LINE_F2 *p) {
    setlen(p, 3);
    setcode(p, 0x40);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG2);
void SetLineG2(LINE_G2 *p) {
    setlen(p, 4);
    setcode(p, 0x50);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF3);
void SetLineF3(LINE_F3 *p) {
    setlen(p, 5);
    setcode(p, 0x48);
    p->pad = 0x55555555;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG3);
void SetLineG3(LINE_G3 *p) {
    setlen(p, 7);
    setcode(p, 0x58);
    p->pad = 0x55555555;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF4);
void SetLineF4(LINE_F4 *p) {
    setlen(p, 6);
    setcode(p, 0x4c);
    p->pad = 0x55555555;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG4);
void SetLineG4(LINE_G4 *p) {
    setlen(p, 9);
    setcode(p, 0x5c);
    p->pad = 0x55555555;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawTPage);
void SetDrawTPage(DR_TPAGE* p, s32 dfe, s32 dtd, s32 tpage)
{
    s32 result;
    setlen(p, 1);
    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        result = ((0xe1000000) | ((dtd) ? 0x0800 : 0) | ((dfe) ? 0x1000 : 0) | ((tpage) & 0x27ff));
    } else {
        result = ((0xe1000000) | ((dtd) ? 0x0200 : 0) | ((dfe) ? 0x0400 : 0) | ((tpage) & 0x9ff));
    }
    p->code[0] = result;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMove);
void SetDrawMove(DR_MOVE* p, RECT* rect, int x, int y) {
    int len = 5;
    if (!rect->w || !rect->h) {
        len = 0;
    }
    setlen(p, len);
    p->code[0] = CMD_CLEAR_CACHE;
    p->code[1] = 0x80000000;
    p->code[2] = *(int*)&rect->x;
    p->code[3] = (y << 0x10) | (x & 0xFFFF);
    p->code[4] = *(int*)&rect->w;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawLoad);
void SetDrawLoad(DR_LOAD* p, RECT* rect) {
    int pixel_count = (rect->w * rect->h + 1) / 2;
    int len = pixel_count + 4;
    if (pixel_count < 0 || pixel_count > 12) {
        len = 0;
    }
    setlen(p, len);
    p->code[0] = CMD_COPY_CPU_TO_VRAM;
    p->code[1] = *(int*)&rect->x;
    p->code[2] = *(int*)&rect->w;
    p->code[len - 1] = CMD_CLEAR_CACHE;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MargePrim);
/**
 * @brief Merge two primitives into one
 * 
 * Combines two graphics primitives into a single primitive packet.
 * This can be used to optimize rendering by reducing the number
 * of separate GPU commands.
 * 
 * @param p0 Pointer to first primitive (becomes the merged primitive)
 * @param p1 Pointer to second primitive (will be cleared)
 * @return 0 on success, -1 if merged primitive would be too large
 */
int MargePrim(void* p0, void* p1) {
    int newLen = getlen(p0) + getlen(p1) + 1;
    if (newLen > 16)
        return -1;
    setlen(p0, newLen);
    *(u_long*)p1 = 0;
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDrawEnv);
/**
 * @brief Display drawing environment information for debugging
 * 
 * Prints detailed information about a drawing environment structure
 * to the debug output. Shows clipping area, offset, texture window,
 * dithering settings, and texture page information.
 * 
 * @param env Pointer to DRAWENV structure to display
 */
void DumpDrawEnv(DRAWENV* env)
{
    GPU_printf("clip (%3d,%3d)-(%d,%d)\n", env->clip.x, env->clip.y, env->clip.w, (s32) env->clip.h);
    GPU_printf("ofs  (%3d,%3d)\n", env->ofs[0], env->ofs[1]);
    GPU_printf("tw   (%d,%d)-(%d,%d)\n", env->tw.x, env->tw.y, env->tw.w, (s32) env->tw.h);
    GPU_printf("dtd   %d\n", (s16) env->dtd);
    GPU_printf("dfe   %d\n", (s16) env->dfe);
    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        GPU_printf("tpage: (%d,%d,%d,%d)\n", (env->tpage >> 9) & 3, (env->tpage >> 7) & 3, (env->tpage << 6) & 0x7C0, (env->tpage * 8) & 0x300);
        return;
    }
    GPU_printf("tpage: (%d,%d,%d,%d)\n", (env->tpage >> 7) & 3, (env->tpage >> 5) & 3, (env->tpage << 6) & 0x7C0, ((env->tpage * 0x10) & 0x100) + ((env->tpage >> 2) & 0x200));
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDispEnv);
void DumpDispEnv(DISPENV* env)
{
    GPU_printf("disp   (%3d,%3d)-(%d,%d)\n", env->disp.x, env->disp.y, env->disp.w, (s32) env->disp.h);
    GPU_printf("screen (%3d,%3d)-(%d,%d)\n", env->screen.x, env->screen.y, env->screen.w, (s32) env->screen.h);
    GPU_printf("isinter %d\n", (s16) env->isinter);
    GPU_printf("isrgb24 %d\n", (s16) env->isrgb24);
}

const char D_80015BA8[] = "$Id: sys.c,v 1.129 1996/12/25 03:36:20 noda Exp $";

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ResetGraph);
/**
 * @brief Initialize or reset the graphics system
 * 
 * Resets the GPU hardware and initializes the graphics library.
 * This function must be called before using any other graphics functions.
 * Different modes control the level of reset performed.
 * 
 * @param mode Reset mode:
 *             0 = Complete reset with debug output
 *             3 = Complete reset with debug output  
 *             5 = Complete reset without debug output
 *             Other = Partial reset
 * @return GPU version number (1 for GPU v1, 2 for GPU v2)
 */
int ResetGraph(int mode) {
    switch (mode & 7) {
    case 3:
    case 0:
        printf("ResetGraph:jtb=%08x,env=%08x\n", &D_80090C54, &GPU_INFO);
    case 5:
        GPU_memset(&GPU_INFO, 0, sizeof(DEBUG));
        ResetCallback();
        GPU_cw((s32) D_80090C94 & 0xFFFFFF);
        GPU_INFO.version = _reset(mode);
        GPU_INFO.D_80090C9D = 1;
        GPU_INFO.w = D_80090D1C[GPU_INFO.version];
        GPU_INFO.h = D_80090D30[GPU_INFO.version];
        GPU_memset(&GPU_INFO.draw, -1, sizeof(DRAWENV));
        GPU_memset(&GPU_INFO.disp, -1, sizeof(DISPENV));
        return GPU_INFO.version;
    }
    if (GPU_INFO.level >= 2U) {
        GPU_printf("ResetGraph(%d)...\n", mode);
    }
    return D_80090C94->reset(1);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphReverse);
int SetGraphReverse(int mode) {
    u_char prev = GPU_INFO.reverse;
    if (GPU_INFO.level >= 2) {
        GPU_printf("SetGraphReverse(%d)...\n", mode);
    }
    GPU_INFO.reverse = mode;
    D_80090C94->ctl(D_80090C94->getctl(8) | (GPU_INFO.reverse ? 0x08000080 : 0x08000000));
    if (GPU_INFO.version == 2) {
        D_80090C94->ctl(GPU_INFO.reverse ? 0x20000501 : 0x20000504);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphDebug);
/**
 * @brief Set graphics debugging level
 * 
 * Controls the amount of debugging information output by graphics functions.
 * Higher levels provide more detailed information about GPU operations.
 * 
 * @param level Debug level:
 *              0 = No debug output
 *              1 = Basic error checking
 *              2 = Detailed function tracing
 * @return Previous debug level
 */
int SetGraphDebug(int level) {
    u_char prev = GPU_INFO.level;
    GPU_INFO.level = level;
    if (GPU_INFO.level) {
        GPU_printf("SetGraphDebug:level:%d,type:%d reverse:%d\n", GPU_INFO.level,
                   GPU_INFO.version, GPU_INFO.reverse);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphQueue);
int SetGraphQueue(int mode) {
    u_char prev = GPU_INFO.D_80090C9D;
    if (GPU_INFO.level >= 2) {
        GPU_printf("SetGrapQue(%d)...\n", mode);
    }
    if (mode != GPU_INFO.D_80090C9D) {
        D_80090C94->reset(1);
        GPU_INFO.D_80090C9D = mode;
        DMACallback(2, NULL);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphType);
/**
 * @brief Get GPU hardware version
 * 
 * Returns the version of the GPU hardware detected during initialization.
 * Different GPU versions have slightly different capabilities and timing.
 * 
 * @return GPU version (1 for original GPU, 2 for revised GPU)
 */
u8 GetGraphType(void)
{
    return GPU_INFO.version;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphDebug);
/**
 * @brief Get current graphics debugging level
 * 
 * Returns the current debugging level set by SetGraphDebug().
 * 
 * @return Current debug level (0-2)
 */
s32 GetGraphDebug(void)
{
    return GPU_INFO.level;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSyncCallback);
/**
 * @brief Set callback function for draw synchronization
 * 
 * Registers a callback function that will be called when GPU drawing
 * operations complete. Used for frame synchronization and timing.
 * 
 * @param func Pointer to callback function, or NULL to disable
 * @return Pointer to previous callback function
 */
u_long DrawSyncCallback(void (*func)()) {
    void (*prev)();
    if (GPU_INFO.level >= 2) {
        GPU_printf("DrawSyncCallback(%08x)...\n", func);
    }
    prev = GPU_INFO.drawSyncCb;
    GPU_INFO.drawSyncCb = func;
    return (u_long)prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDispMask);
/**
 * @brief Enable or disable display output
 * 
 * Controls whether the GPU outputs video to the display. When disabled,
 * the screen will be black but rendering can still continue to VRAM.
 * 
 * @param mask Non-zero to enable display, zero to disable
 */
void SetDispMask(int mask) {
    if (GPU_INFO.level >= 2) {
        GPU_printf("SetDispMask(%d)...\n", mask);
    }
    if (mask == 0) {
        GPU_memset(&GPU_INFO.disp, -1, sizeof(DISPENV));
    }
    D_80090C94->ctl(mask ? 0x03000000 : 0x03000001);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSync);
/**
 * @brief Wait for GPU drawing operations to complete
 * 
 * Synchronizes CPU execution with GPU rendering. Different modes
 * provide different levels of synchronization.
 * 
 * @param mode Sync mode:
 *             0 = Wait for all operations to complete
 *             Other values = Implementation specific
 */
int DrawSync(int mode)
{
    if (GPU_INFO.level >= 2) {
        GPU_printf("DrawSync(%d)...\n", mode);
    }
    D_80090C94->sync(mode);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", checkRECT);
void checkRECT(const char* log, RECT* r) {
    switch (GPU_INFO.level) {
    case 1:
        if (
            r->w > GPU_INFO.w ||
            r->w + r->x > GPU_INFO.w ||
            r->y > GPU_INFO.h ||
            r->y + r->h > GPU_INFO.h ||
            r->w <= 0 ||
            r->x < 0 ||
            r->y < 0 ||
            r->h <= 0
        ) {
            GPU_printf("%s:bad RECT", log);
            GPU_printf("(%d,%d)-(%d,%d)\n", r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        GPU_printf("%s:", log);
        GPU_printf("(%d,%d)-(%d,%d)\n", r->x, r->y, r->w, r->h);
        break;
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage);
/**
 * @brief Clear rectangular area of VRAM with solid color
 * 
 * Fills the specified rectangular area in VRAM with a solid color.
 * This is commonly used to clear the background before rendering.
 * 
 * @param rect Pointer to RECT structure defining area to clear
 * @param r Red component (0-255)
 * @param g Green component (0-255)  
 * @param b Blue component (0-255)
 * @return Operation result from GPU queue
 */
int ClearImage(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT("ClearImage", rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, sizeof(RECT), (b << 0x10) | (g << 8) | r);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage2);
/**
 * @brief Clear rectangular area of VRAM with solid color (alternate mode)
 * 
 * Similar to ClearImage but with different GPU command flags.
 * The exact difference depends on GPU implementation details.
 * 
 * @param rect Pointer to RECT structure defining area to clear
 * @param r Red component (0-255)
 * @param g Green component (0-255)
 * @param b Blue component (0-255)
 * @return Operation result from GPU queue
 */
int ClearImage2(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT("ClearImage", rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, sizeof(RECT), 0x80000000 | (b << 0x10) | (g << 8) | r);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadImage);
/**
 * @brief Transfer image data from main memory to VRAM
 * 
 * Copies pixel data from main memory to the specified rectangular
 * area in VRAM. This is the primary method for loading textures
 * and other image data.
 * 
 * @param rect Pointer to RECT structure defining VRAM destination
 * @param p Pointer to source pixel data in main memory
 * @return Operation result from GPU queue
 */
int LoadImage(RECT* rect, u_long* p)
{
    checkRECT("LoadImage", rect);
    return D_80090C94->addque2(D_80090C94->dws, rect, sizeof(RECT), p);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", StoreImage);
/**
 * @brief Transfer image data from VRAM to main memory
 * 
 * Copies pixel data from the specified rectangular area in VRAM
 * to main memory. Used for reading back rendered images or
 * saving VRAM contents.
 * 
 * @param rect Pointer to RECT structure defining VRAM source area
 * @param p Pointer to destination buffer in main memory
 * @return Operation result from GPU queue
 */
int StoreImage(RECT* rect, u_long* p)
{
    checkRECT("StoreImage", rect);
    return D_80090C94->addque2(D_80090C94->drs, rect, sizeof(RECT), p);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MoveImage);
/**
 * @brief Copy rectangular area within VRAM
 * 
 * Copies pixel data from one rectangular area in VRAM to another.
 * Both source and destination are within VRAM. This is faster than
 * transferring through main memory.
 * 
 * @param rect Pointer to RECT structure defining source area
 * @param x X coordinate of destination
 * @param y Y coordinate of destination
 * @return 0 on success, -1 if rect has zero width/height
 */
int MoveImage(RECT* rect, s32 x, s32 y)
{
    checkRECT("MoveImage", rect);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80090D4C[0] = LOW(rect->x);
    D_80090D4C[1] = ((u16)y << 0x10) | ((u16)x);
    D_80090D4C[2] = LOW(rect->w);
    return D_80090C94->addque2(D_80090C94->cwc, D_80090D4C-2, sizeof(DISPENV), 0);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearOTag);
/**
 * @brief Initialize ordering table for primitive sorting
 * 
 * Initializes an ordering table by linking all entries and setting
 * up termination. Ordering tables are used to sort graphics primitives
 * by depth for proper rendering order.
 * 
 * @param ot Pointer to ordering table array
 * @param n Number of entries in the ordering table
 * @return Pointer to last entry in the ordering table
 */
OT_TYPE* ClearOTag(OT_TYPE* ot, int n) {
    if (GPU_INFO.level >= 2) {
        GPU_printf("ClearOTag(%08x,%d)...\n", ot, n);
    }
    while (--n) {
        setlen(ot, 0);
        setaddr(ot, ot + 1);
        ot++;
    }
    TERM_PRIM(ot, &D_80090D58);
    return ot;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearOTagR);
/**
 * @brief Initialize ordering table in reverse order
 * 
 * Similar to ClearOTag but initializes the ordering table in reverse
 * order. This can be useful for certain rendering techniques.
 * 
 * @param ot Pointer to ordering table array
 * @param n Number of entries in the ordering table
 * @return Pointer to first entry in the ordering table
 */
OT_TYPE* ClearOTagR(OT_TYPE* ot, int n)
{
    if (GPU_INFO.level >= 2) {
        GPU_printf("ClearOTagR(%08x,%d)...\n", ot, n);
    }
    D_80090C94->otc(ot, n);
    TERM_PRIM(ot, &D_80090D58);
    return ot;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawPrim);
/**
 * @brief Draw a single primitive immediately
 * 
 * Renders a single graphics primitive directly to the GPU without
 * using the ordering table system. Used for immediate rendering
 * or special effects.
 * 
 * @param p Pointer to primitive structure to render
 */
void DrawPrim(void* p) {
    int len = getlen(p);
    D_80090C94->sync(0);
    D_80090C94->cwb((u32*)&((P_TAG*)p)->r0, len);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTag);
/**
 * @brief Render all primitives in an ordering table
 * 
 * Processes and renders all graphics primitives stored in the ordering
 * table. This is the main function for rendering a complete frame.
 * Primitives are rendered in order from entry 0 to the highest entry.
 * 
 * @param p Pointer to the first entry of the ordering table
 */
void DrawOTag(u_long* p)
{
    if (GPU_INFO.level >= 2) {
        GPU_printf("DrawOTag(%08x)...\n", p);
    }
    D_80090C94->addque2(D_80090C94->cwc, p, 0, 0);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDrawEnv);
DRAWENV* PutDrawEnv(DRAWENV* env) {
    if (GPU_INFO.level >= 2) {
        GPU_printf("PutDrawEnv(%08x)...\n", env);
    }
    SetDrawEnv2(&env->dr_env, env);
    termPrim(&env->dr_env);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&GPU_INFO.draw) = *env;
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTagEnv);
void DrawOTagEnv(u_long* p, DRAWENV* env)
{
    if (GPU_INFO.level >= 2U) {
        GPU_printf("DrawOTagEnv(%08x,&08x)...\n", p, env);
    }
    SetDrawEnv2(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&GPU_INFO.draw) = *env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDrawEnv);
DRAWENV* GetDrawEnv(DRAWENV* env) {
    memcpy(env, &GPU_INFO.draw, sizeof(DRAWENV));
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDispEnv);
DISPENV* PutDispEnv(DISPENV* env)
{
    s32 h_start;
    s32 v_start;
    s32 h_end;
    s32 v_end;
    s32 mode;

    mode = 0x08000000;
    if (GPU_INFO.level >= 2) {
        GPU_printf("PutDispEnv(%08x)...\n", env);
    }
    D_80090C94->ctl(
        (
            GPU_INFO.version == 1 || GPU_INFO.version == 2 ? (
            (
                (env->disp.y & 0xFFF) << 0xC) |
                (get_dx(env) & 0xFFF) | 0x05000000
            ) : (
                ((env->disp.y & 0x3FF) << 0xA) |
                (env->disp.x & 0x3FF) | 0x05000000
            )
        )
    );
    
    if (!CMPRECT(&GPU_INFO.disp.screen, env->screen)){
        env->pad0 = GetVideoMode();
        h_start = (env->screen.x * 0xA) + 0x260;
        v_start = env->screen.y + ((env->pad0 & 0xFF) ? 0x13 : 0x10);
        h_end = h_start + (env->screen.w ? env->screen.w * 0xA : 0xA00);  
        v_end = v_start + (env->screen.h ? env->screen.h : 0xF0);
        h_start = CLAMP(h_start, 0x1F4, 0xCDA);
        h_end = CLAMP(h_end, h_start + 0x50, 0xCDA);
        v_start = CLAMP(v_start, 0x10, (env->pad0 ? 0x136 : 0x100));
        v_end = CLAMP(v_end, v_start + 2, (env->pad0 ? 0x138 : 0x102));
        D_80090C94->ctl((0x06000000 | (h_end & 0xFFF) << 0xC) | ((h_start & 0xFFF)));
        D_80090C94->ctl((0x07000000 | (v_end & 0x3FF) << 0xA) | ((v_start & 0x3FF)));
    }
    if ((LOWU(GPU_INFO.disp.isinter) != LOWU(env->isinter)) || !CMPRECT(&GPU_INFO.disp, env->disp)) {
        env->pad0 = GetVideoMode();
        if (env->pad0 == 1) {
            mode |= 0x8;
        }
        if (env->isrgb24 != 0) {
            mode |= 0x10;
        }
        if (env->isinter != 0) {
            mode |= 0x20;
        }
        if (GPU_INFO.reverse != 0) {
            mode |= 0x80;
        }
        if (env->disp.w >= 0x119) {
            if (env->disp.w < 0x161) {
                mode |= 1;
            } else if (env->disp.w < 0x191) {
                mode |= 0x40;
            } else if (env->disp.w < 0x231) {
                mode |= 2;
            } else {
                mode |= 3;
            }
        }
        if (env->disp.h <= (env->pad0 ? 0x120 : 0x100)) {
        } else {        
            mode |= 0x24;
        }
        D_80090C94->ctl(mode);
    }
    memcpy((u8*)&GPU_INFO.disp, (u8*)env, sizeof(DISPENV));
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDispEnv);
DISPENV* GetDispEnv(DISPENV* env)
{
    memcpy((u8* )env, (u8*)&GPU_INFO.disp, sizeof(DISPENV));
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetODE);
int GetODE(void)
{
    return D_80090C94->status() >> 0x1F;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTexWindow);
void SetTexWindow(DR_TWIN* p, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = get_tw(tw);
    p->code[1] = 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawArea);
void SetDrawArea(DR_AREA* p, RECT* r)
{
    setlen(p, 2);
    p->code[0] = get_cs(r->x, r->y);
    p->code[1] = get_ce((s16) (((u16) r->x + (u16) r->w) - 1), (s16) (((u16) r->y + (u16) r->h) - 1));
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawOffset);
void SetDrawOffset(DR_OFFSET* p, u_short* ofs) {
    setlen(p, 2);
    p->code[0] = get_ofs((s16)ofs[0], (s16)ofs[1]);
    p->code[1] = 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPriority);
void SetPriority(DR_PRIO* p, int pbc, int pbw) {
    int data;
    setlen(p, 2);
    data = 0xE6000000;
    if (pbc) {
        data = 0xE6000002;
    }
    p->code[0] = data | (pbw != 0);
    p->code[1] = 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMode);
void SetDrawMode(DR_MODE* p, s32 dfe, s32 dtd, s32 tpage, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = get_mode(dfe, dtd, tpage & 0xFFFF);
    p->code[1] = get_tw(tw);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv);
void SetDrawEnv(DR_ENV* dr_env, DRAWENV* env)
{
    DR_ENV* dr;
    RECT rect;
    s32 len=0;
    
    dr = dr_env;
    dr->code[0] = get_cs(env->clip.x, env->clip.y);
    dr->code[1] = get_ce(
                (s32)(((u32)(u16)(env->clip).w + (u32)(u16)(env->clip).x + -1) *
                      0x10000) >> 0x10,
                (s32)(((u32)(u16)(env->clip).y + (u32)(u16)(env->clip).h + -1) *
                      0x10000) >> 0x10
    );
    dr->code[2] = get_ofs(env->ofs[0], env->ofs[1]);
    dr->code[3] = get_mode(env->dfe, env->dtd, env->tpage);
    dr->code[4] = get_tw(&env->tw);
    dr->code[5]= 0xE6000000;
    len=7;
    if (env->isbg) {
        rect.x = env->clip.x;
        rect.y = env->clip.y;
        rect.w = env->clip.w;
        rect.h = env->clip.h;
        rect.w = CLAMP(rect.w, 0, GPU_INFO.w-1);
        rect.h = CLAMP(rect.h, 0, GPU_INFO.h-1);
        rect.x -= env->ofs[0];
        rect.y -= env->ofs[1];
        (&dr->tag)[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
        (&dr->tag)[len++] = LOW(rect.x);
        (&dr->tag)[len++] = LOW(rect.w);
        rect.x += env->ofs[0];
        rect.y += env->ofs[1];
    }
    setlen(dr, len-1);
    return;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv2);
int SetDrawEnv2(DR_ENV* dr_env, DRAWENV* env) {
    DR_ENV* dr;
    RECT rect;
    s32 len=0;
    
    dr = dr_env;
    dr->code[0] = get_cs(env->clip.x, env->clip.y);
    dr->code[1] = get_ce(
                (s32)(((u32)(u16)(env->clip).w + (u32)(u16)(env->clip).x + -1) *
                      0x10000) >> 0x10,
                (s32)(((u32)(u16)(env->clip).y + (u32)(u16)(env->clip).h + -1) *
                      0x10000) >> 0x10
    );
    dr->code[2] = get_ofs(env->ofs[0], env->ofs[1]);
    dr->code[3] = get_mode(env->dfe, env->dtd, env->tpage);
    dr->code[4] = get_tw(&env->tw);
    dr->code[5]= 0xE6000000;
    len=7;
    if (env->isbg) {
        rect.x = env->clip.x;
        rect.y = env->clip.y;
        rect.w = env->clip.w;
        rect.h = env->clip.h;
        rect.w = CLAMP(rect.w, 0, GPU_INFO.w-1);
        rect.h = CLAMP(rect.h, 0, GPU_INFO.h-1);
        if (rect.x & 0x3F || rect.w & 0x3F) {
            rect.x -= env->ofs[0];
            rect.y -= env->ofs[1];
            (&dr->tag)[len++] = 0x60000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            (&dr->tag)[len++] = LOW(rect.x);
            (&dr->tag)[len++] = LOW(rect.w);
            rect.x += env->ofs[0];
            rect.y += env->ofs[1];
        } else {
            (&dr->tag)[len++] = 0x02000000 | (env->b0 << 16) | (env->g0 << 8) | env->r0;
            (&dr->tag)[len++] = LOW(rect.x);
            (&dr->tag)[len++] = LOW(rect.w);
        }
    }
    setlen(dr, len-1);
    return;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_mode);
u_long get_mode(int dfe, int dtd, u_short tpage)
{
    if (GPU_INFO.version == 1 || GPU_INFO.version == 2) {
        return (dtd ? 0xE1000800 : 0xE1000000) | (dfe ? 0x1000 : 0) |
               (tpage & 0x27FF);
    }
    return (dtd ? 0xE1000200 : 0xE1000000) | (dfe ? 0x400 : 0) |
            (tpage & 0x9FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_cs);
u_long get_cs(short x, short y)
{
    x = CLAMP(x, 0, GPU_INFO.w - 1);
    y = CLAMP(y, 0, GPU_INFO.h - 1);
    if (GPU_INFO.version == 1 || GPU_INFO.version == 2) {
        return 0xE3000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ce);
u_long get_ce(short x, short y)
{
    x = CLAMP(x, 0, GPU_INFO.w - 1);
    y = CLAMP(y, 0, GPU_INFO.h - 1);
    
    if (GPU_INFO.version == 1 || GPU_INFO.version == 2) {
        return 0xE4000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ofs);
u_long get_ofs(short x, short y)
{
    if (GPU_INFO.version == 1 || GPU_INFO.version == 2) {
        return 0xe5000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xe5000000 | ((y & 0x7FF) << 11) | (x & 0x7FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tw);
u_long get_tw(RECT* rect) {
    u_long code[4];
    if (rect) {
        code[0] = (rect->x & 0xFF) >> 3;
        code[2] = (-rect->w & 0xFF) >> 3;
        code[1] = (rect->y & 0xFF) >> 3;
        code[3] = (-rect->h & 0xFF) >> 3;
        return 0xE2000000 | (code[1] << 15) | (code[0] << 10) | (code[3] << 5) |
               code[2];
    }
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_dx);
u_long get_dx(DISPENV* env)
{
    switch (GPU_INFO.version) {
    case 1:
        return GPU_INFO.reverse ? 0x400 - env->disp.x - env->disp.w : env->disp.x;
    case 2:
        return GPU_INFO.reverse ? 0x400 - env->disp.x - (env->disp.w / 2) : env->disp.x / 2;
    default:
        return env->disp.x;
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _status);
int _status(void)
{
    return *GPU_STATUS;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _otc);
int _otc(OT_TYPE ot, s32 n)
{
    *DPCR |= 0x08000000;
    *DMA2_CHCR = 0;
    *DMA2_MADR = ot - 4 + n * 4;
    *DMA2_BCR = n;
    *DMA2_CHCR = 0x11000002;
    set_alarm();
    if (*DMA2_CHCR & CMD_CLEAR_CACHE) {
       while(1)
        {
            if (get_alarm()) {
                return -1;
            }
            if (!(*DMA2_CHCR & CMD_CLEAR_CACHE)) {      
                break;
            }
        }
    }
    return n;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _clr);
s32 _clr(RECT* rect, u32 color)
{
    s32* ptr;
    rect->w = CLAMP(rect->w, 0, GPU_INFO.w - 1);
    rect->h = CLAMP(rect->h, 0, GPU_INFO.h - 1);
    if ((rect->x & 0x3F) || (rect->w & 0x3F)) {
        ptr = &D_8009B16C;
        D_8009B148 = ((s32) ptr & 0xFFFFFF) | 0x08000000;
        D_8009B14C = 0xE3000000;
        D_8009B150 = 0xE4FFFFFF;
        D_8009B154 = 0xE5000000;
        D_8009B158 = 0xE6000000;     
        D_8009B15C = 0xE1000000 | (*GPU_STATUS & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B160 = CMD_MONOCHROME_RECTANGLE(color);
        D_8009B164 = (s32) LOWU(rect->x);
        D_8009B168 = (s32) LOWU(rect->w);
        *ptr = 0x03FFFFFF;
        D_8009B170 = _param(3) | 0xE3000000; // set drawing area top left
        D_8009B174 = _param(4) | 0xE4000000; // set drawing area bottom right
        D_8009B178 = _param(5) | 0xE5000000; // set drawing offset
    } else {
        D_8009B148 = 0x05FFFFFF;
        D_8009B14C = 0xE6000000;       
        D_8009B150 = 0xE1000000 | ((*GPU_STATUS) & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B154 = CMD_FILL_RECTANGLE_IN_VRAM(color);
        D_8009B158 = (s32) LOWU(rect->x);
        D_8009B15C = (s32) LOWU(rect->w);
    }
    _cwc((s32) &D_8009B148);
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _dws);
s32 _dws(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s32 var_s4;
    img_ptr = arg1;
    set_alarm();
    var_s4 = 0;
    arg0->w = CLAMP(arg0->w, 0, GPU_INFO.w);
    arg0->h = CLAMP(arg0->h, 0, GPU_INFO.h);
    temp_a0 = ((arg0->w * arg0->h) + 1) / 2;
    if (temp_a0 <= 0) {
        return -1;
    }
    var_s0 = temp_a0 % 16;
    size = temp_a0 / 16;
    if (!(*GPU_STATUS & 0x04000000)) {
        while (1) {
            if (get_alarm()) {
                return -1;
            } else if (*GPU_STATUS & 0x04000000) {
                break;
            }
        }
    }
    *GPU_STATUS = 0x04000000;
    *GPU_DATA = CMD_CLEAR_CACHE;
    *GPU_DATA = var_s4 ? 0xB0000000 : CMD_COPY_CPU_TO_VRAM;
    *GPU_DATA = *(s32*)(&arg0->x);
    *GPU_DATA = *(s32*)(&arg0->w);
    for (var_s0 = var_s0 - 1; var_s0 != -1; var_s0--) {
        *GPU_DATA = *img_ptr++;
    }
    if (size != 0) {
        *GPU_STATUS = 0x04000002;
        *DMA1_MADR = img_ptr;
        *DMA1_BCR = (size << 0x10) | 0x10;
        *DMA1_CHCR = 0x01000201;
    }
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _drs);
s32 _drs(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s16 var_a0, var_a02;
    s32 var_s4;
    img_ptr = arg1;
    set_alarm();
    arg0->w = CLAMP(arg0->w, 0, GPU_INFO.w);
    arg0->h = CLAMP(arg0->h, 0, GPU_INFO.h); 
    temp_a0 = ((arg0->w * arg0->h) + 1) / 2;
    if (temp_a0 <= 0) {
        return -1;
    }
    var_s0 = temp_a0 % 16;
    size = temp_a0 / 16;
    while (!(*GPU_STATUS & 0x04000000)) {
        if (get_alarm()) {
            return -1;
        }
    }
    *GPU_STATUS = 0x04000000;
    *GPU_DATA = CMD_CLEAR_CACHE;
    *GPU_DATA = CMD_COPY_VRAM_TO_CPU;
    *GPU_DATA = *(s32*)&arg0->x;
    *GPU_DATA = *(s32*)&arg0->w;
    while (!(*GPU_STATUS & 0x08000000)) {
        if (get_alarm()) {
            return -1;
        }
    }
    while (--var_s0 != -1) {
        *img_ptr++ = *GPU_DATA;
    }
    if (size != 0) {
        *GPU_STATUS = 0x04000003;
        *DMA1_MADR = img_ptr;
        *DMA1_BCR = (size << 0x10) | 0x10;
        *DMA1_CHCR = 0x01000200;
    }
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _ctl);
void _ctl(u32 arg0)
{
    *GPU_STATUS = arg0;
    GPU_CTLBUF[(arg0 >> 0x18)] = arg0 & 0xFFFFFF;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _getctl);
s32 _getctl(s32 arg0)
{
    return *(&GPU_CTLBUF[arg0]);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _cwb);
s32 _cwb(s32* arg0, s32 arg1) {
    s32* var_a0;
    s32 i;

    *GPU_STATUS = 0x04000000;
    var_a0 = arg0;
    for (i = arg1 - 1; i != -1; i--) {
        *GPU_DATA = *var_a0++;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _cwc);
void _cwc(s32 arg0) {
    *GPU_STATUS = 0x04000002;
    *DMA1_MADR = arg0;
    *DMA1_BCR = 0;
    *DMA1_CHCR = 0x01000401;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _param);
s32 _param(s32 arg0)
{
    *GPU_STATUS = arg0 | 0x10000000;
    return *GPU_DATA & 0xFFFFFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _addque);
void _addque(int arg0, int arg1, int arg2) {
    _addque2(arg0, arg1, 0, arg2);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _addque2);
s32 _addque2(void (*arg0)(s32*, s32), s32* arg1, s32 arg2, s32 arg3)
{
    s32 i;
    set_alarm();
    while(((GPU_QIN + 1) & 0x3F) == GPU_QOUT) {
        if (get_alarm() != 0) {
            return -1;
        }
        _exeque();
    };
    D_80090DA8 = SetIntrMask(0);
    LOW(GPU_INFO.unk8[0]) = 1;
    
    if (
        (GPU_INFO.D_80090C9D == 0) ||
        (
            (GPU_QIN == GPU_QOUT) &&
            !(*DMA1_CHCR & CMD_CLEAR_CACHE) &&
            (GPU_INFO.drawSyncCb == NULL)
        )
    ) {
        do {
        } while ((*GPU_STATUS & 0x04000000)==0);
        arg0(arg1, arg3);
        *(&D_80090D90) = arg0;
        D_80090D94 = arg1;
        D_80090D98 = arg3;
        SetIntrMask(D_80090DA8);
        return 0;
    }
    
    DMACallback(2, _exeque);
    
    if (arg2) {
        for (i = 0; i < (arg2 / 4); i++) {
            GPU_QITEM[GPU_QIN].unkC[i] = arg1[i];
        }
        GPU_QITEM[GPU_QIN].unk4 = &GPU_QITEM[GPU_QIN].unkC[0];
    } else {
        GPU_QITEM[GPU_QIN].unk4 = arg1;
    }
    
    GPU_QITEM[GPU_QIN].unk8 = arg3;
    GPU_QITEM[GPU_QIN].unk0 = arg0;
    GPU_QIN = (GPU_QIN + 1) & 0x3F;
    SetIntrMask(D_80090DA8);
    _exeque();
    return (GPU_QIN - GPU_QOUT) & 0x3F;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _exeque);
s32 _exeque(void)
{
    s32 result=1;
    if (*DMA1_CHCR & CMD_CLEAR_CACHE) {
        return result;
    }
    D_80090DAC = SetIntrMask(0);
    if (GPU_QIN != GPU_QOUT) {
        while (!(*DMA1_CHCR & CMD_CLEAR_CACHE)) {
            if (((GPU_QOUT + 1 & 0x3F) == LOW(GPU_QIN)) && (*GPU_INFO.drawSyncCb == NULL)) {
                DMACallback(2, 0);
            }
            while (!(*GPU_STATUS & 0x04000000)) {
            }
            (
                (void (*)(s32, s32)) GPU_QITEM[GPU_QOUT].unk0
            )(
                GPU_QITEM[GPU_QOUT].unk4,
                GPU_QITEM[GPU_QOUT].unk8
            );
            *(&D_80090D90) = GPU_QITEM[GPU_QOUT].unk0;
            D_80090D94 = GPU_QITEM[GPU_QOUT].unk4;
            D_80090D98 = GPU_QITEM[GPU_QOUT].unk8;
            GPU_QOUT = GPU_QOUT + 1 & 0x3F;
            if (GPU_QIN == GPU_QOUT) break;
            result = DMA1_CHCR;
        }
    }
    SetIntrMask(D_80090DAC);
    if (
        (
            (GPU_QIN == GPU_QOUT) &&
            !(*DMA1_CHCR & CMD_CLEAR_CACHE)
        ) && 
        (LOW(GPU_INFO.unk8[0]) != 0) &&
        (GPU_INFO.drawSyncCb != 0)
    ) {
        *(volatile s32*)(&GPU_INFO.unk8[0]) = 0;
        GPU_INFO.drawSyncCb();
    }
    result = (GPU_QIN - GPU_QOUT) & 0x3F;
    return result;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _reset);
s32 _reset(s32 mode)
{
    u_long** queue = &GPU_QOUT;
    D_80090DB0 = SetIntrMask(0);
    LOW(GPU_QOUT) = NULL;
    GPU_QIN = GPU_QOUT;
    switch (mode & 7) {
    case 0:
    case 5:
        // complete reset, re-initialize draw and disp environments
        *DMA1_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0;
        GPU_memset((s8* )(GPU_CTLBUF), 0, 0x100);
        GPU_memset(&GPU_QITEM, 0, 0x1800);
        break;
    case 1:
    case 3:
        // cancels the current drawing and flushes the command buffer
        // preserves the current draw and disp environments
        *DMA1_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0x02000000;
        *GPU_STATUS = CMD_CLEAR_CACHE;
        break;
    }
    SetIntrMask(D_80090DB0);
    return !(mode & 7) ? _version(mode) : 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _sync);
s32 _sync(s32 arg0)
{
    s32 temp_s0;
    if (!arg0) {
        set_alarm();
        while (*(s32*)(&GPU_QIN) != *(s32*)(&GPU_QOUT)) {
            _exeque();
            if (get_alarm()) return -1;
        }
        
        while ((*DMA1_CHCR & CMD_CLEAR_CACHE) || !(*GPU_STATUS & 0x04000000)) {
            if (get_alarm()) return -1;
        }
        return 0;
    }    
    temp_s0 = (GPU_QIN - GPU_QOUT) & 0x3F;
    if (temp_s0) {
        _exeque();
    }    
    if ((*DMA1_CHCR & CMD_CLEAR_CACHE) || !(*GPU_STATUS & 0x04000000)) {
        if (!temp_s0) {
            return 1;
        } else {
            return temp_s0;
        }
    }   
    return temp_s0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", set_alarm);
void set_alarm(void)
{
    D_80090DB4 = VSync(-1) + 0xF0;
    D_80090DB8 = 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_alarm);
s32 get_alarm(void) {
    s32 intrMask;
    volatile int *p;
    int a1;
    if ((D_80090DB4 < VSync(-1)) || D_80090DB8++ > 0xF0000) {
        *GPU_STATUS;
        printf("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x,",
               GPU_QIN - GPU_QOUT & 0x3F, *GPU_STATUS, *DMA1_CHCR, *DMA1_MADR);
        p = &D_80090D90;
        a1 = *p;
        printf("func=(%08x)(%08x,%08x)\n", a1, D_80090D94, D_80090D98);
        intrMask = SetIntrMask(0);
        LOW(GPU_QOUT)=0;
        D_80090DB0 = intrMask;
        GPU_QIN = GPU_QOUT;
        *DMA1_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0x02000000;
        *GPU_STATUS = 0x01000000;
        SetIntrMask(D_80090DB0);
        return -1;
    }
    return 0;
}


//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _version);
int _version(int mode) {
    *GPU_STATUS = 0x10000007;
    if ((*GPU_DATA & 0xFFFFFF) != 2) { // check for GPUv2
        *GPU_DATA = 0xE1001000 | (*GPU_STATUS & 0x3FFF);
        *GPU_DATA;
        if (!(*GPU_STATUS & 0x1000)) {
            return 0;
        }
        if (!(mode & 8)) {
            return 1;
        }
        *GPU_STATUS = 0x20000504;
        return 2;
    } else if (!(mode & 8)) {
        return 3;
    } else {
        *GPU_STATUS = 0x09000001;
        return 4;
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GPU_memset);
void * GPU_memset(s8* ptr, int value, s32 num) {
    s32 i;
    for (i = num - 1; i != -1; i--) {
        *ptr++ = value;
    }
}


#if !(SKIP_ASM || M2CTX)
    BIOS_STUB(GPU_cw, 0xA0, 0x49);
#endif

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", OpenTIM);
int OpenTIM(u_long* addr)
{
    D_8009B290 = addr;
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTIM);
TIM_IMAGE* ReadTIM(TIM_IMAGE* timimg)
{
    s32 addr;
    addr = get_tim_addr(D_8009B290, timimg);
    if (addr == -1) {
        return 0;
    }
    D_8009B290 = &D_8009B290[addr];
    return timimg;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", OpenTMD);
int OpenTMD(u_long* tmd, int obj_no)
{
    D_8009B2A0 = get_tmd_addr(
        tmd,
        obj_no,
        &D_8009B29C,
        &D_8009B294,
        &D_8009B298
    );
    return D_8009B2A0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTMD);
TMD_PRIM* ReadTMD(TMD_PRIM* tmdprim)
{
    s32 packet;
    packet = unpack_packet((u8* ) D_8009B29C, tmdprim);
    if (packet < 0) return 0;
    
    D_8009B29C += packet;
    tmdprim->v_ofs = (SVECTOR*)(D_8009B294);
    tmdprim->n_ofs = (SVECTOR*)(D_8009B298);
    
    LOAD_SVECTOR_XYZ(tmdprim->n0, D_8009B298, tmdprim->norm0, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n1, D_8009B298, tmdprim->norm1, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n2, D_8009B298, tmdprim->norm2, 0);
    LOAD_SVECTOR_XYZ(tmdprim->n3, D_8009B298, tmdprim->norm3, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x0, D_8009B294, tmdprim->vert0, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x1, D_8009B294, tmdprim->vert1, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x2, D_8009B294, tmdprim->vert2, 0);
    LOAD_SVECTOR_XYZ(tmdprim->x3, D_8009B294, tmdprim->vert3, 0);
    return tmdprim;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tim_addr);
s32 get_tim_addr(u32* timaddr, TIM_IMAGE* img) {
    unsigned int clut_len;
    unsigned int img_len;
    if (*(int*)timaddr++ != 0x10) {
        return -1;
    }
    img->mode = *timaddr++;
    if (GetGraphDebug() == 2) {
        printf("id  =%08x\n", 0x10);
    }
    if (GetGraphDebug() == 2) {
        printf("mode=%08x\n", img->mode);
    }
    if (GetGraphDebug() == 2) {
        printf("timaddr=%08x\n", timaddr);
    }
    if (img->mode & 8) {
        clut_len = *timaddr >> 2;
        img->crect = (RECT*)(timaddr + 1);
        img->caddr = (u_long*)(timaddr + 3);
        timaddr = &timaddr[clut_len];
    } else {
        img->crect = NULL;
        img->caddr = NULL;
        clut_len = 0;
    }
    img_len = *timaddr >> 2;
    img->prect = (RECT*)(timaddr + 1);
    img->paddr = (u_long*)(timaddr + 3);
    return 2 + clut_len + img_len;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tmd_addr);
u_long get_tmd_addr(
    TMD* tmd, int objid, u_long** t_prim, u_long** v_ofs, u_long** n_ofs) {
    TmdObj* obj = tmd->obj;
    if (GetGraphDebug() == 2) {
        printf("analizing TMD...\n");
    }
    if (GetGraphDebug() == 2) {
        printf("\tid=%08X, flags=%d, nobj=%d, objid=%d\n", tmd->id, tmd->flags,
               tmd->nobj, objid);
    }
    if (GetGraphDebug() == 2) {
        printf("\tvert=%08X, nvert=%d\n", obj[objid].vert, obj[objid].nvert);
    }
    if (GetGraphDebug() == 2) {
        printf("\tnorm=%08X, nnorm=%d\n", obj[objid].norm, obj[objid].nnorm);
    }
    if (GetGraphDebug() == 2) {
        printf("\tprim=%08X, nprim=%d\n", obj[objid].prim, obj[objid].nprim);
    }
    *v_ofs = (u_long*)((unsigned char*)obj + obj[objid].vert);
    *n_ofs = (u_long*)((unsigned char*)obj + obj[objid].norm);
    *t_prim = (u_long*)((unsigned char*)obj + obj[objid].prim);
    return obj[objid].nprim;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", unpack_packet);
s32 unpack_packet(PACKET* arg0, TMD_PRIM* arg1) {
    s32 temp_v0;
    u32 temp_v1;
    memset(arg1, 0, sizeof(TMD_PRIM));
    temp_v0 = *(u32*)(&arg0[0]);
    temp_v1 = temp_v0 & 0xFDFFFFFF;
    arg1->id = (u32)temp_v0;
    switch (temp_v1) {
    case 0x20000304: // F3L
        if (GetGraphDebug() == 2) {
            printf("F3L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xC]);
        arg1->vert2 = *(u16*)(&arg0[0xE]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0x8]);
        arg1->norm2 = *(u16*)(&arg0[0x8]);
        return 0x10;
    case 0x30000406: // G3L
        if (GetGraphDebug() == 2) {
            printf("G3L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xE]);
        arg1->vert2 = *(u16*)(&arg0[0x12]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0xC]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        return 0x14;
    case 0x24000507: // FT3L
        if (GetGraphDebug() == 2) {
            printf("FT3L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x12]);
        arg1->vert1 = *(u16*)(&arg0[0x14]);
        arg1->vert2 = *(u16*)(&arg0[0x16]);
        arg1->norm0 = *(u16*)(&arg0[0x10]);
        arg1->norm1 = *(u16*)(&arg0[0x10]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        return 0x18;
    case 0x34000609: // GT3L
        if (GetGraphDebug() == 2) {
            printf("GT3L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x12]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x1A]);
        arg1->norm0 = *(u16*)(&arg0[0x10]);
        arg1->norm1 = *(u16*)(&arg0[0x14]);
        arg1->norm2 = *(u16*)(&arg0[0x18]);
        return 0x1C;
    case 0x21010304: // F3
        if (GetGraphDebug() == 2) {
            printf("F3 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0x8]);
        arg1->vert1 = *(u16*)(&arg0[0xA]);
        arg1->vert2 = *(u16*)(&arg0[0xC]);
        return 0x10;
    case 0x31010506: // G3
        if (GetGraphDebug() == 2) {
            printf("G3 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x8];
        arg1->g1 = arg0[0x9];
        arg1->b1 = arg0[0xA];
        arg1->r2 = arg0[0xC];
        arg1->g2 = arg0[0xD];
        arg1->b2 = arg0[0xE];
        arg1->vert0 = *(u16*)(&arg0[0x10]);
        arg1->vert1 = *(u16*)(&arg0[0x12]);
        arg1->vert2 = *(u16*)(&arg0[0x14]);
        return 0x18;
    case 0x25010607: //FT3
        if (GetGraphDebug() == 2) {
            printf("FT3 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->r0 = arg0[0x10];
        arg1->g0 = arg0[0x11];
        arg1->b0 = arg0[0x12];
        arg1->r1 = arg0[0x10];
        arg1->g1 = arg0[0x11];
        arg1->b1 = arg0[0x12];
        arg1->r2 = arg0[0x10];
        arg1->g2 = arg0[0x11];
        arg1->b2 = arg0[0x12];
        arg1->vert0 = *(u16*)(&arg0[0x14]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x18]);
        return 0x1C;
    case 0x35010809: // GT3
        if (GetGraphDebug() == 2) {
            printf("GT3 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->vert0 = *(u16*)(&arg0[0x1C]);
        arg1->vert1 = *(u16*)(&arg0[0x1E]);
        arg1->vert2 = *(u16*)(&arg0[0x20]);
        arg1->r0 = arg0[0x10];
        arg1->g0 = arg0[0x11];
        arg1->b0 = arg0[0x12];
        arg1->r1 = arg0[0x14];
        arg1->g1 = arg0[0x15];
        arg1->b1 = arg0[0x16];
        arg1->r2 = arg0[0x18];
        arg1->g2 = arg0[0x19];
        arg1->b2 = arg0[0x1A];
        return 0x24;
    case 0x28000405: // F4L
        if (GetGraphDebug() == 2) {
            printf("F4L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xC]);
        arg1->vert2 = *(u16*)(&arg0[0xE]);
        arg1->vert3 = *(u16*)(&arg0[0x10]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0x8]);
        arg1->norm2 = *(u16*)(&arg0[0x8]);
        arg1->norm3 = *(u16*)(&arg0[0x8]);
        return 0x14;
    case 0x38000508: //G4L
        if (GetGraphDebug() == 2) {
            printf("G4L ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0xA]);
        arg1->vert1 = *(u16*)(&arg0[0xE]);
        arg1->vert2 = *(u16*)(&arg0[0x12]);
        arg1->vert3 = *(u16*)(&arg0[0x16]);
        arg1->norm0 = *(u16*)(&arg0[0x8]);
        arg1->norm1 = *(u16*)(&arg0[0xC]);
        arg1->norm2 = *(u16*)(&arg0[0x10]);
        arg1->norm3 = *(u16*)(&arg0[0x14]);
        return 0x18;
    case 0x2C000709: // FT4L
        if (GetGraphDebug() == 2) {
            printf("FT4L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x16]);
        arg1->vert1 = *(u16*)(&arg0[0x18]);
        arg1->vert2 = *(u16*)(&arg0[0x1A]);
        arg1->vert3 = *(u16*)(&arg0[0x1C]);
        arg1->norm0 = *(u16*)(&arg0[0x14]);
        arg1->norm1 = *(u16*)(&arg0[0x14]);
        arg1->norm2 = *(u16*)(&arg0[0x14]);
        arg1->norm3 = *(u16*)(&arg0[0x14]);
        return 0x20;
    case 0x3C00080C: // GT4L
        if (GetGraphDebug() == 2) {
            printf("GT4L ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x16]);
        arg1->vert1 = *(u16*)(&arg0[0x1A]);
        arg1->vert2 = *(u16*)(&arg0[0x1E]);
        arg1->vert3 = *(u16*)(&arg0[0x22]);
        arg1->norm0 = *(u16*)(&arg0[0x14]);
        arg1->norm1 = *(u16*)(&arg0[0x18]);
        arg1->norm2 = *(u16*)(&arg0[0x1C]);
        arg1->norm3 = *(u16*)(&arg0[0x20]);
        return 0x24;
    case 0x29010305: // F4
        if (GetGraphDebug() == 2) {
            printf("F4 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x4];
        arg1->g1 = arg0[0x5];
        arg1->b1 = arg0[0x6];
        arg1->r2 = arg0[0x4];
        arg1->g2 = arg0[0x5];
        arg1->b2 = arg0[0x6];
        arg1->r3 = arg0[0x4];
        arg1->g3 = arg0[0x5];
        arg1->b3 = arg0[0x6];
        arg1->vert0 = *(u16*)(&arg0[0x8]);
        arg1->vert1 = *(u16*)(&arg0[0xA]);
        arg1->vert2 = *(u16*)(&arg0[0xC]);
        arg1->vert3 = *(u16*)(&arg0[0xE]);
        return 0x10;
    case 0x39010608: // G4
        if (GetGraphDebug() == 2) {
            printf("G4 ");
        }
        arg1->r0 = arg0[0x4];
        arg1->g0 = arg0[0x5];
        arg1->b0 = arg0[0x6];
        arg1->r1 = arg0[0x8];
        arg1->g1 = arg0[0x9];
        arg1->b1 = arg0[0xA];
        arg1->r2 = arg0[0xC];
        arg1->g2 = arg0[0xD];
        arg1->b2 = arg0[0xE];
        arg1->r3 = arg0[0x10];
        arg1->g3 = arg0[0x11];
        arg1->b3 = arg0[0x12];
        arg1->vert0 = *(u16*)(&arg0[0x14]);
        arg1->vert1 = *(u16*)(&arg0[0x16]);
        arg1->vert2 = *(u16*)(&arg0[0x18]);
        arg1->vert3 = *(u16*)(&arg0[0x1A]);
        return 0x1C;
    case 0x2D010709: // FT4
        if (GetGraphDebug() == 2) {
            printf("FT4 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->r0 = arg0[0x14];
        arg1->g0 = arg0[0x15];
        arg1->b0 = arg0[0x16];
        arg1->r1 = arg0[0x14];
        arg1->g1 = arg0[0x15];
        arg1->b1 = arg0[0x16];
        arg1->r2 = arg0[0x14];
        arg1->g2 = arg0[0x15];
        arg1->b2 = arg0[0x16];
        arg1->r3 = arg0[0x14];
        arg1->g3 = arg0[0x15];
        arg1->b3 = arg0[0x16];
        arg1->vert0 = *(u16*)(&arg0[0x18]);
        arg1->vert1 = *(u16*)(&arg0[0x1A]);
        arg1->vert2 = *(u16*)(&arg0[0x1C]);
        arg1->vert3 = *(u16*)(&arg0[0x1E]);
        return 0x20;
    case 0x3D010A0C: // GT4
        if (GetGraphDebug() == 2) {
            printf("GT4 ");
        }
        arg1->tpage = *(u16*)(&arg0[0xA]);
        arg1->clut = *(u16*)(&arg0[0x6]);
        arg1->u0 = arg0[0x4];
        arg1->v0 = arg0[0x5];
        arg1->u1 = arg0[0x8];
        arg1->v1 = arg0[0x9];
        arg1->u2 = arg0[0xC];
        arg1->v2 = arg0[0xD];
        arg1->u3 = arg0[0x10];
        arg1->v3 = arg0[0x11];
        arg1->vert0 = *(u16*)(&arg0[0x24]);
        arg1->vert1 = *(u16*)(&arg0[0x26]);
        arg1->vert2 = *(u16*)(&arg0[0x28]);
        arg1->vert3 = *(u16*)(&arg0[0x2A]);
        arg1->r0 = arg0[0x14];
        arg1->g0 = arg0[0x15];
        arg1->b0 = arg0[0x16];
        arg1->r1 = arg0[0x18];
        arg1->g1 = arg0[0x19];
        arg1->b1 = arg0[0x1A];
        arg1->r2 = arg0[0x1C];
        arg1->g2 = arg0[0x1D];
        arg1->b2 = arg0[0x1E];
        arg1->r3 = arg0[0x20];
        arg1->g3 = arg0[0x21];
        arg1->b3 = arg0[0x22];
        return 0x2C;
    default: // unsupported type
        printf("unsupported type (%08x)\n", arg1->id & 0xFDFFFFFF);
        return -1;
    }
}

/**
 * @brief PSYQ LIBGPU Library Summary
 * 
 * This library provides comprehensive access to the PlayStation's GPU hardware
 * through a high-level C interface. Key functionality includes:
 * 
 * INITIALIZATION & CONFIGURATION:
 * - ResetGraph(): Initialize GPU hardware and graphics system
 * - SetGraphDebug(): Control debug output and error checking
 * - SetGraphReverse(): Configure display orientation
 * 
 * DISPLAY & DRAWING ENVIRONMENTS:
 * - SetDefDrawEnv/SetDefDispEnv(): Initialize rendering parameters
 * - PutDrawEnv/PutDispEnv(): Apply environments to hardware
 * - GetDrawEnv/GetDispEnv(): Read current environment settings
 * 
 * VRAM MANAGEMENT:
 * - LoadImage/StoreImage(): Transfer data between RAM and VRAM
 * - ClearImage(): Fill VRAM areas with solid colors
 * - MoveImage(): Copy data within VRAM
 * 
 * TEXTURE & PALETTE MANAGEMENT:
 * - LoadTPage(): Load texture pages with automatic sizing
 * - LoadClut/LoadClut2(): Load color palettes
 * - GetTPage/GetClut(): Create texture/palette identifiers
 * 
 * PRIMITIVE RENDERING:
 * - AddPrim(): Add primitives to ordering tables
 * - DrawOTag(): Render complete ordering table
 * - DrawPrim(): Immediate primitive rendering
 * - ClearOTag/ClearOTagR(): Initialize ordering tables
 * 
 * SYNCHRONIZATION:
 * - DrawSync(): Wait for rendering completion
 * - DrawSyncCallback(): Register frame completion callbacks
 * - SetDispMask(): Control display output
 * 
 * TMD (3D MODEL) PROCESSING:
 * - Comprehensive TMD primitive unpacking for 3D models
 * - Support for flat/gouraud shading, textured/untextured
 * - Triangle and quad primitive types
 * 
 * The library abstracts the complex GPU command protocol and DMA operations
 * into easy-to-use functions while maintaining high performance through
 * hardware-accelerated operations.
 */
