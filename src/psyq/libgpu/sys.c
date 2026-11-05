#include "common.h"
#include "psyq/libstamp.h"
#include "psyq/libgpu.h"


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

typedef struct QueueItem {
    int unk0;
    int unk4;
    int unk8;
    int unkC[2];
    int unk14;
    int unk18;
    char padding[0x14 + 0x1C + 0x14];
} QueueItem;

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
extern volatile QueueItem GPU_QITEM[];

const char D_80015BA8[] = "$Id: sys.c,v 1.129 1996/12/25 03:36:20 noda Exp $";

int printf();
int _status(void);
int _otc(OT_TYPE ot, s32 n);
s32 _clr(RECT* rect, u32 color);
s32 _dws(RECT* arg0, s32* arg1);
s32 _drs(RECT* arg0, s32* arg1);
void _ctl(u32 arg0);
s32 _getctl(s32 arg0);
s32 _cwb(s32* arg0, s32 arg1);
void _cwc(s32 arg0);
s32 _param(s32 arg0);
void _addque(int arg0, int arg1, int arg2);
s32 _addque2(void (*arg0)(s32*, s32), s32* arg1, s32 arg2, s32 arg3);
s32 _exeque(void);
s32 _reset(s32 mode);
s32 _sync(s32 arg0);

PsyqStamp libgpu_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_GPU, 19, 38, 52);
GPU _gpucb = {
    D_80015BA8, (void*)_addque, (void*)_addque2, (void*)_clr,
    (void*)_ctl, (void*)_cwb, (void*)_cwc, (void*)_drs,
    (void*)_dws, (void*)_exeque, (void*)_getctl, (void*)_otc,
    (void*)_param, (void*)_reset, (void*)_status, (void*)_sync,
};
GPU* gpu = &_gpucb;
int (*GPU_printf)() = printf;
DEBUG GEnv = {0};
s32 D_80090D1C[5] = {1024, 1024, 1024, 1024, 1024};
s32 D_80090D30[5] = {512, 1024, 1024, 512, 1024};
u_long move_image[5] = {0x04FFFFFF, 0x80000000, 0, 0, 0};
u_long D_80090D58[5] = {0x04FFFFFF, 0, 0, 0, 0};
volatile s32* GPU_DATA = (volatile s32*)0x1F801810;
volatile s32* GPU_STATUS = (volatile s32*)0x1F801814;
volatile s32* DMA2_MADR = (volatile s32*)0x1F8010A0;
volatile s32* DMA2_BCR = (volatile s32*)0x1F8010A4;
volatile s32* DMA2_CHCR = (volatile s32*)0x1F8010A8;
volatile s32* DMA6_MADR = (volatile s32*)0x1F8010E0;
volatile s32* DMA6_BCR = (volatile s32*)0x1F8010E4;
volatile s32* DMA6_CHCR = (volatile s32*)0x1F8010E8;
volatile s32* DPCR = (volatile s32*)0x1F8010F0;
volatile s32 _qlog = 0;
volatile s32 D_80090D94 = 0;
volatile s32 D_80090D98 = 0;
s32 D_80090D9C = 0;
volatile s32 _qin = 0;
volatile s32 _qout = 0;
s32 D_80090DA8 = 0;
s32 D_80090DAC = 0;
s32 D_80090DB0 = 0;
s32 D_80090DB4 = 0;
s32 D_80090DB8 = 0;

// INCLUDE_ASM("nonmatchings/psyq/libgpu", ResetGraph);
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
        printf("ResetGraph:jtb=%08x,env=%08x\n", &_gpucb, &GEnv);
    case 5:
        GPU_memset(&GEnv, 0, sizeof(DEBUG));
        ResetCallback();
        GPU_cw((s32) gpu & 0xFFFFFF);
        GEnv.version = _reset(mode);
        GEnv.D_80090C9D = 1;
        GEnv.w = D_80090D1C[GEnv.version];
        GEnv.h = D_80090D30[GEnv.version];
        GPU_memset(&GEnv.draw, -1, sizeof(DRAWENV));
        GPU_memset(&GEnv.disp, -1, sizeof(DISPENV));
        return GEnv.version;
    }
    if (GEnv.level >= 2U) {
        GPU_printf("ResetGraph(%d)...\n", mode);
    }
    return gpu->reset(1);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetGraphReverse);
int SetGraphReverse(int mode) {
    u_char prev = GEnv.reverse;
    if (GEnv.level >= 2) {
        GPU_printf("SetGraphReverse(%d)...\n", mode);
    }
    GEnv.reverse = mode;
    gpu->ctl(gpu->getctl(8) | (GEnv.reverse ? 0x08000080 : 0x08000000));
    if (GEnv.version == 2) {
        gpu->ctl(GEnv.reverse ? 0x20000501 : 0x20000504);
    }
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetGraphDebug);
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
    u_char prev = GEnv.level;
    GEnv.level = level;
    if (GEnv.level) {
        GPU_printf("SetGraphDebug:level:%d,type:%d reverse:%d\n", GEnv.level,
                   GEnv.version, GEnv.reverse);
    }
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetGraphQueue);
int SetGraphQueue(int mode) {
    u_char prev = GEnv.D_80090C9D;
    if (GEnv.level >= 2) {
        GPU_printf("SetGrapQue(%d)...\n", mode);
    }
    if (mode != GEnv.D_80090C9D) {
        gpu->reset(1);
        GEnv.D_80090C9D = mode;
        DMACallback(2, NULL);
    }
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", GetGraphType);
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
    return GEnv.version;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", GetGraphDebug);
/**
 * @brief Get current graphics debugging level
 * 
 * Returns the current debugging level set by SetGraphDebug().
 * 
 * @return Current debug level (0-2)
 */
s32 GetGraphDebug(void)
{
    return GEnv.level;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", DrawSyncCallback);
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
    if (GEnv.level >= 2) {
        GPU_printf("DrawSyncCallback(%08x)...\n", func);
    }
    prev = GEnv.drawSyncCb;
    GEnv.drawSyncCb = func;
    return (u_long)prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDispMask);
/**
 * @brief Enable or disable display output
 * 
 * Controls whether the GPU outputs video to the display. When disabled,
 * the screen will be black but rendering can still continue to VRAM.
 * 
 * @param mask Non-zero to enable display, zero to disable
 */
void SetDispMask(int mask) {
    if (GEnv.level >= 2) {
        GPU_printf("SetDispMask(%d)...\n", mask);
    }
    if (mask == 0) {
        GPU_memset(&GEnv.disp, -1, sizeof(DISPENV));
    }
    gpu->ctl(mask ? 0x03000000 : 0x03000001);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", DrawSync);
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
    if (GEnv.level >= 2) {
        GPU_printf("DrawSync(%d)...\n", mode);
    }
    gpu->sync(mode);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", checkRECT);
void checkRECT(const char* log, RECT* r) {
    switch (GEnv.level) {
    case 1:
        if (
            r->w > GEnv.w ||
            r->w + r->x > GEnv.w ||
            r->y > GEnv.h ||
            r->y + r->h > GEnv.h ||
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

// INCLUDE_ASM("nonmatchings/psyq/libgpu", ClearImage);
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
    return gpu->addque2(gpu->clr, rect, sizeof(RECT), (b << 0x10) | (g << 8) | r);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", ClearImage2);
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
    return gpu->addque2(gpu->clr, rect, sizeof(RECT), 0x80000000 | (b << 0x10) | (g << 8) | r);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", LoadImage);
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
    return gpu->addque2(gpu->dws, rect, sizeof(RECT), p);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", StoreImage);
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
    return gpu->addque2(gpu->drs, rect, sizeof(RECT), p);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", MoveImage);
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
    move_image[2] = LOW(rect->x);
    move_image[3] = ((u16)y << 0x10) | ((u16)x);
    move_image[4] = LOW(rect->w);
    return gpu->addque2(gpu->cwc, move_image, sizeof(DISPENV), 0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", ClearOTag);
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
    if (GEnv.level >= 2) {
        GPU_printf("ClearOTag(%08x,%d)...\n", ot, n);
    }
    while (--n) {
        setlen(ot, 0);
        setaddr(ot, ot + 1);
        ot++;
    }
    TERM_PRIM(ot, D_80090D58);
    return ot;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", ClearOTagR);
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
    if (GEnv.level >= 2) {
        GPU_printf("ClearOTagR(%08x,%d)...\n", ot, n);
    }
    gpu->otc(ot, n);
    TERM_PRIM(ot, D_80090D58);
    return ot;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", DrawPrim);
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
    gpu->sync(0);
    gpu->cwb((u32*)&((P_TAG*)p)->r0, len);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", DrawOTag);
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
    if (GEnv.level >= 2) {
        GPU_printf("DrawOTag(%08x)...\n", p);
    }
    gpu->addque2(gpu->cwc, p, 0, 0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", PutDrawEnv);
DRAWENV* PutDrawEnv(DRAWENV* env) {
    if (GEnv.level >= 2) {
        GPU_printf("PutDrawEnv(%08x)...\n", env);
    }
    SetDrawEnv2(&env->dr_env, env);
    termPrim(&env->dr_env);
    gpu->addque2(gpu->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&GEnv.draw) = *env;
    return env;
}

/**
 * @brief Render ordering table with specific drawing environment
 * 
 * Processes and renders all graphics primitives in the ordering table
 * with a specific drawing environment applied. The drawing environment
 * is linked to the ordering table and both are sent to the GPU.
 * 
 * @param p Pointer to the first entry of the ordering table
 * @param env Pointer to drawing environment to apply during rendering
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", DrawOTagEnv);
void DrawOTagEnv(u_long* p, DRAWENV* env)
{
    if (GEnv.level >= 2U) {
        GPU_printf("DrawOTagEnv(%08x,&08x)...\n", p, env);
    }
    SetDrawEnv2(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    gpu->addque2(gpu->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&GEnv.draw) = *env;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", GetDrawEnv);
DRAWENV* GetDrawEnv(DRAWENV* env) {
    memcpy(env, &GEnv.draw, sizeof(DRAWENV));
    return env;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", PutDispEnv);
DISPENV* PutDispEnv(DISPENV* env)
{
    s32 h_start;
    s32 v_start;
    s32 h_end;
    s32 v_end;
    s32 mode;

    mode = 134217728;
    if (GEnv.level >= 2) {
        GPU_printf("PutDispEnv(%08x)...\n", env);
    }
    gpu->ctl(
        (
            GEnv.version == 1 || GEnv.version == 2 ? (
            (
                (env->disp.y & 0xFFF) << 0xC) |
                (get_dx(env) & 0xFFF) | 0x05000000
            ) : (
                ((env->disp.y & 0x3FF) << 0xA) |
                (env->disp.x & 0x3FF) | 0x05000000
            )
        )
    );
    
    if (!CMPRECT(&GEnv.disp.screen, env->screen)){
        env->pad0 = GetVideoMode();
        h_start = (env->screen.x * 0xA) + 0x260;
        v_start = env->screen.y + ((env->pad0 & 0xFF) ? 0x13 : 0x10);
        h_end = h_start + (env->screen.w ? env->screen.w * 0xA : 0xA00);  
        v_end = v_start + (env->screen.h ? env->screen.h : 0xF0);
        h_start = CLAMP(h_start, 0x1F4, 0xCDA);
        h_end = CLAMP(h_end, h_start + 0x50, 0xCDA);
        v_start = CLAMP(v_start, 0x10, (env->pad0 ? 0x136 : 0x100));
        v_end = CLAMP(v_end, v_start + 2, (env->pad0 ? 0x138 : 0x102));
        gpu->ctl((0x06000000 | (h_end & 0xFFF) << 0xC) | ((h_start & 0xFFF)));
        gpu->ctl((0x07000000 | (v_end & 0x3FF) << 0xA) | ((v_start & 0x3FF)));
    }
    if ((LOWU(GEnv.disp.isinter) != LOWU(env->isinter)) || !CMPRECT(&GEnv.disp, env->disp)) {
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
        if (GEnv.reverse != 0) {
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
        gpu->ctl(mode);
    }
    memcpy((u8*)&GEnv.disp, (u8*)env, sizeof(DISPENV));
    return env;
}

/**
 * @brief Get current display environment settings
 * 
 * Retrieves the current display environment configuration from
 * the GPU system. Used to query current video display settings.
 * 
 * @param env Pointer to DISPENV structure to fill with current settings
 * @return Pointer to the filled environment structure
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", GetDispEnv);
DISPENV* GetDispEnv(DISPENV* env)
{
    memcpy((u8* )env, (u8*)&GEnv.disp, sizeof(DISPENV));
    return env;
}

/**
 * @brief Get Odd/Even display field status
 * 
 * Returns the current field being displayed in interlaced video modes.
 * Used for field-based rendering and synchronization.
 * 
 * @return 0 for even field, 1 for odd field
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", GetODE);
int GetODE(void)
{
    return gpu->status() >> 0x1F;
}

/**
 * @brief Set texture window drawing command
 * 
 * Sets up a DR_TWIN primitive that defines the texture window
 * for texture coordinate wrapping. The texture window controls
 * how texture coordinates wrap when they exceed texture boundaries.
 * 
 * @param p Pointer to DR_TWIN primitive structure
 * @param tw Pointer to RECT defining texture window area
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetTexWindow);
void SetTexWindow(DR_TWIN* p, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = get_tw(tw);
    p->code[1] = 0;
}

/**
 * @brief Set drawing area drawing command
 * 
 * Sets up a DR_AREA primitive that defines the drawing area bounds.
 * All rendering operations will be clipped to this rectangular area.
 * 
 * @param p Pointer to DR_AREA primitive structure
 * @param r Pointer to RECT defining the drawing area
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDrawArea);
void SetDrawArea(DR_AREA* p, RECT* r)
{
    setlen(p, 2);
    p->code[0] = get_cs(r->x, r->y);
    p->code[1] = get_ce((s16) (((u16) r->x + (u16) r->w) - 1), (s16) (((u16) r->y + (u16) r->h) - 1));
}

/**
 * @brief Set drawing offset drawing command
 * 
 * Sets up a DR_OFFSET primitive that defines the drawing offset.
 * All subsequent rendering operations will be offset by these values.
 * 
 * @param p Pointer to DR_OFFSET primitive structure
 * @param ofs Pointer to array of two offsets [x_offset, y_offset]
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDrawOffset);
void SetDrawOffset(DR_OFFSET* p, u_short* ofs) {
    setlen(p, 2);
    p->code[0] = get_ofs((s16)ofs[0], (s16)ofs[1]);
    p->code[1] = 0;
}

/**
 * @brief Set rendering priority drawing command
 * 
 * Sets up a DR_PRIO primitive that controls primitive rendering priority.
 * This affects the order in which primitives are processed and can
 * influence depth testing behavior.
 * 
 * @param p Pointer to DR_PRIO primitive structure
 * @param pbc Priority comparison flag
 * @param pbw Priority window flag
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetPriority);
void SetPriority(DR_PRIO* p, int pbc, int pbw) {
    int data;
    setlen(p, 2);
    data = 3858759680;
    if (pbc) {
        data = 3858759682;
    }
    p->code[0] = data | (pbw != 0);
    p->code[1] = 0;
}

/**
 * @brief Set drawing mode drawing command
 * 
 * Sets up a DR_MODE primitive that configures various drawing modes
 * including dithering, texture page settings, and texture window.
 * 
 * @param p Pointer to DR_MODE primitive structure
 * @param dfe Dither flag enable (0=disabled, 1=enabled)
 * @param dtd Draw to display area flag (0=disabled, 1=enabled)
 * @param tpage Texture page ID
 * @param tw Pointer to RECT defining texture window
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDrawMode);
void SetDrawMode(DR_MODE* p, s32 dfe, s32 dtd, s32 tpage, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = get_mode(dfe, dtd, tpage & 0xFFFF);
    p->code[1] = get_tw(tw);
}

/**
 * @brief Set drawing environment drawing command
 * 
 * Sets up a DR_ENV primitive that contains all drawing environment
 * settings from a DRAWENV structure. This includes clipping area,
 * drawing offset, texture window, and various GPU modes.
 * 
 * @param dr_env Pointer to DR_ENV primitive structure to initialize
 * @param env Pointer to DRAWENV structure containing settings
 */
// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDrawEnv);
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
        setRECT(&rect, env->clip.x, env->clip.y, env->clip.w, env->clip.h);
        rect.w = CLAMP(rect.w, 0, GEnv.w-1);
        rect.h = CLAMP(rect.h, 0, GEnv.h-1);
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

// INCLUDE_ASM("nonmatchings/psyq/libgpu", SetDrawEnv2);
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
        setRECT(&rect, env->clip.x, env->clip.y, env->clip.w, env->clip.h);
        rect.w = CLAMP(rect.w, 0, GEnv.w-1);
        rect.h = CLAMP(rect.h, 0, GEnv.h-1);
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

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_mode);
u_long get_mode(int dfe, int dtd, u_short tpage)
{
    if (GEnv.version == 1 || GEnv.version == 2) {
        return (dtd ? 0xE1000800 : 0xE1000000) | (dfe ? 0x1000 : 0) |
               (tpage & 0x27FF);
    }
    return (dtd ? 0xE1000200 : 0xE1000000) | (dfe ? 0x400 : 0) |
            (tpage & 0x9FF);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_cs);
u_long get_cs(short x, short y)
{
    x = CLAMP(x, 0, GEnv.w - 1);
    y = CLAMP(y, 0, GEnv.h - 1);
    if (GEnv.version == 1 || GEnv.version == 2) {
        return 0xE3000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_ce);
u_long get_ce(short x, short y)
{
    x = CLAMP(x, 0, GEnv.w - 1);
    y = CLAMP(y, 0, GEnv.h - 1);
    
    if (GEnv.version == 1 || GEnv.version == 2) {
        return 0xE4000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_ofs);
u_long get_ofs(short x, short y)
{
    if (GEnv.version == 1 || GEnv.version == 2) {
        return 0xe5000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xe5000000 | ((y & 0x7FF) << 11) | (x & 0x7FF);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_tw);
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

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_dx);
u_long get_dx(DISPENV* env)
{
    switch (GEnv.version) {
    case 1:
        return GEnv.reverse ? 0x400 - env->disp.x - env->disp.w : env->disp.x;
    case 2:
        return GEnv.reverse ? 0x400 - env->disp.x - (env->disp.w / 2) : env->disp.x / 2;
    default:
        return env->disp.x;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _status);
int _status(void)
{
    return *GPU_STATUS;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _otc);
int _otc(OT_TYPE ot, s32 n)
{
    *DPCR |= 0x08000000;
    *DMA6_CHCR = 0;
    *DMA6_MADR = ot - 4 + n * 4;
    *DMA6_BCR = n;
    *DMA6_CHCR = 285212674;
    set_alarm();
    if (*DMA6_CHCR & CMD_CLEAR_CACHE) {
       while(1)
        {
            if (get_alarm()) {
                return -1;
            }
            if (!(*DMA6_CHCR & CMD_CLEAR_CACHE)) {      
                break;
            }
        }
    }
    return n;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _clr);
s32 _clr(RECT* rect, u32 color)
{
    s32* ptr;
    rect->w = CLAMP(rect->w, 0, GEnv.w - 1);
    rect->h = CLAMP(rect->h, 0, GEnv.h - 1);
    if ((rect->x & 0x3F) || (rect->w & 0x3F)) {
        ptr = &D_8009B16C;
        D_8009B148 = ((s32) ptr & 0xFFFFFF) | 0x08000000;
        D_8009B14C = 3808428032;
        D_8009B150 = 3841982463;
        D_8009B154 = 3841982464;
        D_8009B158 = 0xE6000000;     
        D_8009B15C = 0xE1000000 | (*GPU_STATUS & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B160 = CMD_MONOCHROME_RECTANGLE(color);
        D_8009B164 = (s32) LOWU(rect->x);
        D_8009B168 = (s32) LOWU(rect->w);
        *ptr = 67108863;
        D_8009B170 = _param(3) | 0xE3000000; // set drawing area top left
        D_8009B174 = _param(4) | 0xE4000000; // set drawing area bottom right
        D_8009B178 = _param(5) | 0xE5000000; // set drawing offset
    } else {
        D_8009B148 = 100663295;
        D_8009B14C = 0xE6000000;       
        D_8009B150 = 0xE1000000 | ((*GPU_STATUS) & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B154 = CMD_FILL_RECTANGLE_IN_VRAM(color);
        D_8009B158 = (s32) LOWU(rect->x);
        D_8009B15C = (s32) LOWU(rect->w);
    }
    _cwc((s32) &D_8009B148);
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _dws);
s32 _dws(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s32 var_s4;
    img_ptr = arg1;
    set_alarm();
    var_s4 = 0;
    arg0->w = CLAMP(arg0->w, 0, GEnv.w);
    arg0->h = CLAMP(arg0->h, 0, GEnv.h);
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
    *GPU_STATUS = 67108864;
    *GPU_DATA = CMD_CLEAR_CACHE;
    *GPU_DATA = var_s4 ? 0xB0000000 : CMD_COPY_CPU_TO_VRAM;
    *GPU_DATA = *(s32*)(&arg0->x);
    *GPU_DATA = *(s32*)(&arg0->w);
    for (var_s0 = var_s0 - 1; var_s0 != -1; var_s0--) {
        *GPU_DATA = *img_ptr++;
    }
    if (size != 0) {
        *GPU_STATUS = 67108866;
        *DMA2_MADR = img_ptr;
        *DMA2_BCR = (size << 0x10) | 0x10;
        *DMA2_CHCR = 16777729;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _drs);
s32 _drs(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s16 var_a0, var_a02;
    s32 var_s4;
    img_ptr = arg1;
    set_alarm();
    arg0->w = CLAMP(arg0->w, 0, GEnv.w);
    arg0->h = CLAMP(arg0->h, 0, GEnv.h); 
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
    *GPU_STATUS = 67108864;
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
        *GPU_STATUS = 67108867;
        *DMA2_MADR = img_ptr;
        *DMA2_BCR = (size << 0x10) | 0x10;
        *DMA2_CHCR = 16777728;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _ctl);
void _ctl(u32 arg0)
{
    *GPU_STATUS = arg0;
    GPU_CTLBUF[(arg0 >> 0x18)] = arg0 & 0xFFFFFF;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _getctl);
s32 _getctl(s32 arg0)
{
    return *(&GPU_CTLBUF[arg0]);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _cwb);
s32 _cwb(s32* arg0, s32 arg1) {
    s32* var_a0;
    s32 i;

    *GPU_STATUS = 67108864;
    var_a0 = arg0;
    for (i = arg1 - 1; i != -1; i--) {
        *GPU_DATA = *var_a0++;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _cwc);
void _cwc(s32 arg0) {
    *GPU_STATUS = 67108866;
    *DMA2_MADR = arg0;
    *DMA2_BCR = 0;
    *DMA2_CHCR = 16778241;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _param);
s32 _param(s32 arg0)
{
    *GPU_STATUS = arg0 | 0x10000000;
    return *GPU_DATA & 0xFFFFFF;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _addque);
void _addque(int arg0, int arg1, int arg2) {
    _addque2(arg0, arg1, 0, arg2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _addque2);
s32 _addque2(void (*arg0)(s32*, s32), s32* arg1, s32 arg2, s32 arg3)
{
    s32 i;
    set_alarm();
    while(((_qin + 1) & 0x3F) == _qout) {
        if (get_alarm() != 0) {
            return -1;
        }
        _exeque();
    };
    D_80090DA8 = SetIntrMask(0);
    LOW(GEnv.unk8[0]) = 1;
    
    if (
        (GEnv.D_80090C9D == 0) ||
        (
            (_qin == _qout) &&
            !(*DMA2_CHCR & CMD_CLEAR_CACHE) &&
            (GEnv.drawSyncCb == NULL)
        )
    ) {
        do {
        } while ((*GPU_STATUS & 0x04000000)==0);
        arg0(arg1, arg3);
        *(&_qlog) = arg0;
        D_80090D94 = arg1;
        D_80090D98 = arg3;
        SetIntrMask(D_80090DA8);
        return 0;
    }
    
    DMACallback(2, _exeque);
    
    if (arg2) {
        for (i = 0; i < (arg2 / 4); i++) {
            GPU_QITEM[_qin].unkC[i] = arg1[i];
        }
        GPU_QITEM[_qin].unk4 = &GPU_QITEM[_qin].unkC[0];
    } else {
        GPU_QITEM[_qin].unk4 = arg1;
    }
    
    GPU_QITEM[_qin].unk8 = arg3;
    GPU_QITEM[_qin].unk0 = arg0;
    _qin = (_qin + 1) & 0x3F;
    SetIntrMask(D_80090DA8);
    _exeque();
    return (_qin - _qout) & 0x3F;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _exeque);
s32 _exeque(void)
{
    s32 result=1;
    if (*DMA2_CHCR & CMD_CLEAR_CACHE) {
        return result;
    }
    D_80090DAC = SetIntrMask(0);
    if (_qin != _qout) {
        while (!(*DMA2_CHCR & CMD_CLEAR_CACHE)) {
            if (((_qout + 1 & 0x3F) == LOW(_qin)) && (*GEnv.drawSyncCb == NULL)) {
                DMACallback(2, 0);
            }
            while (!(*GPU_STATUS & 0x04000000)) {
            }
            (
                (void (*)(s32, s32)) GPU_QITEM[_qout].unk0
            )(
                GPU_QITEM[_qout].unk4,
                GPU_QITEM[_qout].unk8
            );
            *(&_qlog) = GPU_QITEM[_qout].unk0;
            D_80090D94 = GPU_QITEM[_qout].unk4;
            D_80090D98 = GPU_QITEM[_qout].unk8;
            _qout = _qout + 1 & 0x3F;
            if (_qin == _qout) break;
            result = DMA2_CHCR;
        }
    }
    SetIntrMask(D_80090DAC);
    if (
        (
            (_qin == _qout) &&
            !(*DMA2_CHCR & CMD_CLEAR_CACHE)
        ) && 
        (LOW(GEnv.unk8[0]) != 0) &&
        (GEnv.drawSyncCb != 0)
    ) {
        *(volatile s32*)(&GEnv.unk8[0]) = 0;
        GEnv.drawSyncCb();
    }
    result = (_qin - _qout) & 0x3F;
    return result;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _reset);
s32 _reset(s32 mode)
{
    u_long** queue = &_qout;
    D_80090DB0 = SetIntrMask(0);
    LOW(_qout) = NULL;
    _qin = _qout;
    switch (mode & 7) {
    case 0:
    case 5:
        // complete reset, re-initialize draw and disp environments
        *DMA2_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0;
        GPU_memset((s8* )(GPU_CTLBUF), 0, 0x100);
        GPU_memset(&GPU_QITEM, 0, 0x1800);
        break;
    case 1:
    case 3:
        // cancels the current drawing and flushes the command buffer
        // preserves the current draw and disp environments
        *DMA2_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 33554432;
        *GPU_STATUS = CMD_CLEAR_CACHE;
        break;
    }
    SetIntrMask(D_80090DB0);
    return !(mode & 7) ? _version(mode) : 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", _sync);
s32 _sync(s32 arg0)
{
    s32 temp_s0;
    if (!arg0) {
        set_alarm();
        while (*(s32*)(&_qin) != *(s32*)(&_qout)) {
            _exeque();
            if (get_alarm()) return -1;
        }
        
        while ((*DMA2_CHCR & CMD_CLEAR_CACHE) || !(*GPU_STATUS & 0x04000000)) {
            if (get_alarm()) return -1;
        }
        return 0;
    }    
    temp_s0 = (_qin - _qout) & 0x3F;
    if (temp_s0) {
        _exeque();
    }    
    if ((*DMA2_CHCR & CMD_CLEAR_CACHE) || !(*GPU_STATUS & 0x04000000)) {
        if (!temp_s0) {
            return 1;
        } else {
            return temp_s0;
        }
    }   
    return temp_s0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", set_alarm);
void set_alarm(void)
{
    D_80090DB4 = VSync(-1) + 0xF0;
    D_80090DB8 = 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", get_alarm);
s32 get_alarm(void) {
    s32 intrMask;
    volatile int *p;
    int a1;
    if ((D_80090DB4 < VSync(-1)) || D_80090DB8++ > 0xF0000) {
        *GPU_STATUS;
        printf("GPU timeout:que=%d,stat=%08x,chcr=%08x,madr=%08x,",
               _qin - _qout & 0x3F, *GPU_STATUS, *DMA2_CHCR, *DMA2_MADR);
        p = &_qlog;
        a1 = *p;
        printf("func=(%08x)(%08x,%08x)\n", a1, D_80090D94, D_80090D98);
        intrMask = SetIntrMask(0);
        LOW(_qout)=0;
        D_80090DB0 = intrMask;
        _qin = _qout;
        *DMA2_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 33554432;
        *GPU_STATUS = 16777216;
        SetIntrMask(D_80090DB0);
        return -1;
    }
    return 0;
}


// INCLUDE_ASM("nonmatchings/psyq/libgpu", _version);
int _version(int mode) {
    *GPU_STATUS = 268435463;
    if ((*GPU_DATA & 0xFFFFFF) != 2) { // check for GPUv2
        *GPU_DATA = 0xE1001000 | (*GPU_STATUS & 0x3FFF);
        *GPU_DATA;
        if (!(*GPU_STATUS & 0x1000)) {
            return 0;
        }
        if (!(mode & 8)) {
            return 1;
        }
        *GPU_STATUS = 536872196;
        return 2;
    } else if (!(mode & 8)) {
        return 3;
    } else {
        *GPU_STATUS = 150994945;
        return 4;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libgpu", GPU_memset);
void * GPU_memset(s8* ptr, int value, s32 num) {
    s32 i;
    for (i = num - 1; i != -1; i--) {
        *ptr++ = value;
    }
}
