#include "common.h"
#include "psyq/libgpu.h"

#define CMD_CLEAR_CACHE 0x01000000
#define CMD_COPY_CPU_TO_VRAM 0xA0000000

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetTPage);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetClut);
u_short GetClut(int x, int y)
{
    return getClut(x,y);
}

/**
 * @brief Display texture page information for debugging
 * 
 * Prints detailed texture page information to the debug output.
 * Shows texture format, position, and color mode based on the
 * current graphics type.
 * 
 * @param tpage Texture page identifier as returned by GetTPage() or LoadTPage()
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpTPage);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpClut);
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

/**
 * @brief Add multiple primitives to ordering table
 * 
 * Adds multiple primitives to the ordering table at once,
 * treating p0 through p1 as a range of primitives to add.
 * 
 * @param ot Pointer to ordering table
 * @param p0 Pointer to first primitive in range
 * @param p1 Pointer to last primitive in range
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", AddPrims);
void AddPrims(void *ot, void *p0, void *p1) {
    addPrims(ot, p0, p1);
}

/**
 * @brief Connect two primitives together
 * 
 * Links two primitives by setting the address of p0 to point to p1,
 * creating a chain of primitives for the GPU to process.
 * 
 * @param p0 Pointer to first primitive
 * @param p1 Pointer to second primitive to link to
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", CatPrim);
void CatPrim(void *p0, void *p1) {
    setaddr(p0, p1);
}

/**
 * @brief Terminate a primitive chain
 * 
 * Marks a primitive as the end of a primitive chain by setting
 * its address to NULL, stopping GPU command traversal.
 * 
 * @param p Pointer to primitive to terminate
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", TermPrim);
void TermPrim(void *p) {
    termPrim(p);
}

/**
 * @brief Set semi-transparency mode for a primitive
 * 
 * Enables or disables semi-transparency blending for a primitive.
 * When enabled, the primitive will be blended with the framebuffer
 * using the current blending equation.
 * 
 * @param p Pointer to primitive
 * @param abe Semi-transparency flag (0=disabled, 1=enabled)
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSemiTrans);
void SetSemiTrans(void *p, int abe) {
    setSemiTrans(p, abe);
}

/**
 * @brief Set texture gouraud shading mode for a primitive
 * 
 * Enables or disables texture gouraud shading, which applies
 * vertex colors to textured primitives for lighting effects.
 * 
 * @param p Pointer to primitive
 * @param tge Texture gouraud flag (0=disabled, 1=enabled)
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetShadeTex);
void SetShadeTex(void *p, int tge) {
    setShadeTex(p, tge);
}

/**
 * @brief Initialize a flat-shaded 3-vertex polygon primitive
 * 
 * Sets up a POLY_F3 primitive with proper packet length and
 * GPU command code for rendering a 3-vertex polygon with
 * flat (single) color shading.
 * 
 * @param p Pointer to POLY_F3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyF3);
void SetPolyF3(POLY_F3 *p) {
    setlen(p, 4);
    setcode(p, 0x20);
}

/**
 * @brief Initialize a flat-shaded textured 3-vertex polygon primitive
 * 
 * Sets up a POLY_FT3 primitive with proper packet length and
 * GPU command code for rendering a 3-vertex polygon with
 * flat color shading and texture mapping.
 * 
 * @param p Pointer to POLY_FT3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyFT3);
void SetPolyFT3(POLY_FT3 *p) {
    setlen(p, 7);
    setcode(p, 0x24);
}

/**
 * @brief Initialize a gouraud-shaded 3-vertex polygon primitive
 * 
 * Sets up a POLY_G3 primitive with proper packet length and
 * GPU command code for rendering a 3-vertex polygon with
 * gouraud (interpolated) color shading.
 * 
 * @param p Pointer to POLY_G3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyG3);
void SetPolyG3(POLY_G3 *p) {
    setlen(p, 6);
    setcode(p, 0x30);
}

/**
 * @brief Initialize a gouraud-shaded textured 3-vertex polygon primitive
 * 
 * Sets up a POLY_GT3 primitive with proper packet length and
 * GPU command code for rendering a 3-vertex polygon with
 * gouraud color shading and texture mapping.
 * 
 * @param p Pointer to POLY_GT3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyGT3);
void SetPolyGT3(POLY_GT3 *p) {
    setlen(p, 9);
    setcode(p, 0x34);
}

/**
 * @brief Initialize a flat-shaded 4-vertex polygon primitive
 * 
 * Sets up a POLY_F4 primitive (quad) with proper packet length and
 * GPU command code for rendering a 4-vertex polygon with
 * flat (single) color shading.
 * 
 * @param p Pointer to POLY_F4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyF4);
void SetPolyF4(POLY_F4 *p) {
    setlen(p, 5);
    setcode(p, 0x28);
}

/**
 * @brief Initialize a flat-shaded textured 4-vertex polygon primitive
 * 
 * Sets up a POLY_FT4 primitive (textured quad) with proper packet length and
 * GPU command code for rendering a 4-vertex polygon with
 * flat color shading and texture mapping.
 * 
 * @param p Pointer to POLY_FT4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyFT4);
void SetPolyFT4(POLY_FT4 *p) {
    setlen(p, 9);
    setcode(p, 0x2C);
}

/**
 * @brief Initialize a gouraud-shaded 4-vertex polygon primitive
 * 
 * Sets up a POLY_G4 primitive (gouraud quad) with proper packet length and
 * GPU command code for rendering a 4-vertex polygon with
 * gouraud (interpolated) color shading.
 * 
 * @param p Pointer to POLY_G4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyG4);
void SetPolyG4(POLY_G4 *p) {
    setlen(p, 8);
    setcode(p, 0x38);
}

/**
 * @brief Initialize a gouraud-shaded textured 4-vertex polygon primitive
 * 
 * Sets up a POLY_GT4 primitive (textured gouraud quad) with proper packet length and
 * GPU command code for rendering a 4-vertex polygon with
 * gouraud color shading and texture mapping.
 * 
 * @param p Pointer to POLY_GT4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPolyGT4);
void SetPolyGT4(POLY_GT4 *p) {
    setlen(p, 12);
    setcode(p, 0x3C);
}

/**
 * @brief Initialize an 8x8 pixel sprite primitive
 * 
 * Sets up a SPRT_8 primitive with proper packet length and
 * GPU command code for rendering an 8x8 pixel textured sprite.
 * 
 * @param p Pointer to SPRT_8 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt8);
void SetSprt8(SPRT_8 *p) {
    setlen(p, 3);
    setcode(p, 0x74);
}

/**
 * @brief Initialize a 16x16 pixel sprite primitive
 * 
 * Sets up a SPRT_16 primitive with proper packet length and
 * GPU command code for rendering a 16x16 pixel textured sprite.
 * 
 * @param p Pointer to SPRT_16 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt16);
void SetSprt16(SPRT_16 *p) {
    setlen(p, 3);
    setcode(p, 0x7C);
}

/**
 * @brief Initialize a variable-size sprite primitive
 * 
 * Sets up a SPRT primitive with proper packet length and
 * GPU command code for rendering a textured sprite with
 * arbitrary width and height.
 * 
 * @param p Pointer to SPRT primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetSprt);
void SetSprt(SPRT *p) {
    setlen(p, 4);
    setcode(p, 0x64);
}

/**
 * @brief Initialize a 1x1 pixel tile primitive
 * 
 * Sets up a TILE_1 primitive with proper packet length and
 * GPU command code for rendering a single pixel with solid color.
 * 
 * @param p Pointer to TILE_1 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile1);
void SetTile1(TILE_1 *p) {
    setlen(p, 2);
    setcode(p, 0x68);
}

/**
 * @brief Initialize an 8x8 pixel tile primitive
 * 
 * Sets up a TILE_8 primitive with proper packet length and
 * GPU command code for rendering an 8x8 pixel solid color rectangle.
 * 
 * @param p Pointer to TILE_8 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile8);
void SetTile8(TILE_8 *p) {
    setlen(p, 2);
    setcode(p, 0x70);
}

/**
 * @brief Initialize a 16x16 pixel tile primitive
 * 
 * Sets up a TILE_16 primitive with proper packet length and
 * GPU command code for rendering a 16x16 pixel solid color rectangle.
 * 
 * @param p Pointer to TILE_16 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile16);
void SetTile16(TILE_16 *p) {
    setlen(p, 2);
    setcode(p, 0x78);
}

/**
 * @brief Initialize a variable-size tile primitive
 * 
 * Sets up a TILE primitive with proper packet length and
 * GPU command code for rendering a solid color rectangle with
 * arbitrary width and height.
 * 
 * @param p Pointer to TILE primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTile);
void SetTile(TILE *p) {
    setlen(p, 3);
    setcode(p, 0x60);
}

/**
 * @brief Initialize a flat-shaded 2-point line primitive
 * 
 * Sets up a LINE_F2 primitive with proper packet length and
 * GPU command code for rendering a line between two points
 * with flat (single) color.
 * 
 * @param p Pointer to LINE_F2 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF2);
void SetLineF2(LINE_F2 *p) {
    setlen(p, 3);
    setcode(p, 0x40);
}

/**
 * @brief Initialize a gouraud-shaded 2-point line primitive
 * 
 * Sets up a LINE_G2 primitive with proper packet length and
 * GPU command code for rendering a line between two points
 * with gouraud (interpolated) color blending.
 * 
 * @param p Pointer to LINE_G2 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG2);
void SetLineG2(LINE_G2 *p) {
    setlen(p, 4);
    setcode(p, 0x50);
}

/**
 * @brief Initialize a flat-shaded 3-point polyline primitive
 * 
 * Sets up a LINE_F3 primitive with proper packet length and
 * GPU command code for rendering a polyline through three points
 * with flat (single) color. The pad field is set to disable
 * automatic line termination.
 * 
 * @param p Pointer to LINE_F3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF3);
void SetLineF3(LINE_F3 *p) {
    setlen(p, 5);
    setcode(p, 0x48);
    p->pad = 0x55555555;
}

/**
 * @brief Initialize a gouraud-shaded 3-point polyline primitive
 * 
 * Sets up a LINE_G3 primitive with proper packet length and
 * GPU command code for rendering a polyline through three points
 * with gouraud (interpolated) color blending. The pad field is set
 * to disable automatic line termination.
 * 
 * @param p Pointer to LINE_G3 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG3);
void SetLineG3(LINE_G3 *p) {
    setlen(p, 7);
    setcode(p, 0x58);
    p->pad = 0x55555555;
}

/**
 * @brief Initialize a flat-shaded 4-point polyline primitive
 * 
 * Sets up a LINE_F4 primitive with proper packet length and
 * GPU command code for rendering a polyline through four points
 * with flat (single) color. The pad field is set to disable
 * automatic line termination.
 * 
 * @param p Pointer to LINE_F4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineF4);
void SetLineF4(LINE_F4 *p) {
    setlen(p, 6);
    setcode(p, 0x4c);
    p->pad = 0x55555555;
}

/**
 * @brief Initialize a gouraud-shaded 4-point polyline primitive
 * 
 * Sets up a LINE_G4 primitive with proper packet length and
 * GPU command code for rendering a polyline through four points
 * with gouraud (interpolated) color blending. The pad field is set
 * to disable automatic line termination.
 * 
 * @param p Pointer to LINE_G4 primitive structure
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetLineG4);
void SetLineG4(LINE_G4 *p) {
    setlen(p, 9);
    setcode(p, 0x5c);
    p->pad = 0x55555555;
}

/**
 * @brief Initialize a texture page drawing command
 * 
 * Sets up a DR_TPAGE primitive that configures texture page settings
 * for subsequent rendering operations. This command is added to the
 * ordering table to change GPU texture parameters.
 * 
 * @param p Pointer to DR_TPAGE primitive structure
 * @param dfe Dither flag enable (0=disabled, 1=enabled)
 * @param dtd Draw to display area flag (0=disabled, 1=enabled)  
 * @param tpage Texture page ID containing format and position info
 */
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

/**
 * @brief Initialize a VRAM move command
 * 
 * Sets up a DR_MOVE primitive that copies a rectangular area from
 * one location in VRAM to another. The command includes cache
 * clear operations to ensure data integrity.
 * 
 * @param p Pointer to DR_MOVE primitive structure
 * @param rect Source rectangle in VRAM to copy from
 * @param x Destination X coordinate in VRAM
 * @param y Destination Y coordinate in VRAM
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMove);
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

/**
 * @brief Initialize a CPU-to-VRAM data transfer command
 * 
 * Sets up a DR_LOAD primitive that prepares for transferring pixel data
 * from CPU memory to VRAM. The command calculates the required packet
 * size based on pixel count and includes cache operations.
 * 
 * @param p Pointer to DR_LOAD primitive structure
 * @param rect Target rectangle in VRAM where data will be loaded
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawLoad);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MargePrim);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDrawEnv);
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

/**
 * @brief Display video display environment information for debugging
 * 
 * Prints detailed information about a display environment structure
 * to the debug output. Shows display area, screen area, interlace
 * mode, and RGB24 mode settings.
 * 
 * @param env Pointer to DISPENV structure to display
 */
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDispEnv);
void DumpDispEnv(DISPENV* env)
{
    GPU_printf("disp   (%3d,%3d)-(%d,%d)\n", env->disp.x, env->disp.y, env->disp.w, (s32) env->disp.h);
    GPU_printf("screen (%3d,%3d)-(%d,%d)\n", env->screen.x, env->screen.y, env->screen.w, (s32) env->screen.h);
    GPU_printf("isinter %d\n", (s16) env->isinter);
    GPU_printf("isrgb24 %d\n", (s16) env->isrgb24);
}