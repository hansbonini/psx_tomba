#include "common.h"
#include "psyq/libgpu.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadTPage);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut);
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
    setRECT(&rect, x, y, 256, 1);
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut2);
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
    setRECT(&rect, x, y, 16, 1);
    LoadImage(&rect, clut);
    return GetClut(x, y);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDefDrawEnv);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDefDispEnv);
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
