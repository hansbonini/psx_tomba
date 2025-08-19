#include "common.h"

#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"

#define OT_TYPE u_long
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
    /* 0x00 */ const char* ver;
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

extern char* D_80015AD8; // DumpTPage text
extern char* D_80015AF0; // DumpClut text
extern char* D_80015B00; // DumpDrawEnv text
extern char* D_80015B18; // DumpDrawEnv text
extern char* D_80015B28; // DumpDrawEnv text
extern char* D_80015B40; // DumpDrawEnv text
extern char* D_80015B4C; // DumpDrawEnv text
extern char* D_80015B58; // DumpDispEnv text
extern char* D_80015B74; // DumpDispEnv text
extern char* D_80015B90; // DumpDispEnv text
extern char* D_80015B9C; // DumpDispEnv text
extern char* D_80015BDC; // ResetGraph text
extern char* D_80015BFC; // ResetGraph text
extern char* D_80015C10; // SetGraphReverse text
extern char* D_80015C28; // SetGraphDebug text
extern char* D_80015C54; // SetGraphQueue text
extern char* D_80015C68; // DrawSyncCallback text
extern char* D_80015C84; // SetDispMask text
extern char* D_80015C98; // DrawSync text
extern char* D_80015CAC; // checkRECT text
extern char* D_80015CB8; // checkRECT text
extern char* D_80015CCC; // checkRECT text
extern char* D_80015CD0; // ClearImage text
extern char* D_80015CDC; // LoadImage text
extern char* D_80015CE8; // StoreImage text
extern char* D_80015CF4; // MoveImage text
extern char* D_80015D00; // ClearOTag text
extern char* D_80015D18; // ClearOTagR text 
extern char* D_80015D30; // DrawOTag text
extern char* D_80015D44; // PutDrawEnv text
extern char* D_80015D5C; // DrawOTagEnv text
extern char* D_80015D78; // PutDispEnv text
extern char* D_80015D90; // get_alarm text
extern char* D_80015DDC; // get_tim_addr text
extern char* D_80015DE8; // get_tim_addr text
extern char* D_80015DF4; // get_tim_addr text
extern char* D_80015E04; // get_tmd_addr text
extern char* D_80015E18; // get_tmd_addr text
extern char* D_80015E40; // get_tmd_addr text
extern char* D_80015E58; // get_tmd_addr text
extern char* D_80015E70; // get_tmd_addr text
extern char* D_80015E88; // unpack_packet text
extern char* D_80015E90; // unpack_packet text
extern char* D_80015E98; // unpack_packet text
extern char* D_80015EA0; // unpack_packet text
extern char* D_80015EA8; // unpack_packet text
extern char* D_80015EAC; // unpack_packet text
extern char* D_80015EB0; // unpack_packet text
extern char* D_80015EB8; // unpack_packet text
extern char* D_80015EC0; // unpack_packet text
extern char* D_80015EC8; // unpack_packet text
extern char* D_80015ED0; // unpack_packet text
extern char* D_80015ED8; // unpack_packet text
extern char* D_80015EE0; // unpack_packet text
extern char* D_80015EE4; // unpack_packet text
extern char* D_80015EE8; // unpack_packet text
extern char* D_80015EF0; // unpack_packet text
extern char* D_80015EF8; // unpack_packet text

extern s32 D_80090C54;
extern GPU* D_80090C94;
extern DEBUG D_80090C9C;
// extern s8 D_80090C9D;
// extern u8 D_80090C9E;
// extern s32 D_80090C9F;
// extern s16 D_80090CA0;
// extern s16 D_80090CA2;
// extern void* D_80090C98;
extern DISPENV TEMP_DISPENV; // size: 0x10
// extern u16 D_80090D0A;
// extern u16 D_80090D0C;
// extern u16 D_80090D0E;
// extern u16 D_80090D10;
// extern u16 D_80090D12;
// extern u16 D_80090D14;
// extern u16 D_80090D16;
// extern s32 D_80090D18;
extern s32 D_80090D1C[];
extern s32 D_80090D30[];
extern u32 D_80090D4C[];
extern s32 D_80090D58;
extern volatile s32* GPU_DATA;
extern volatile s32* GPU_STATUS;
extern volatile s32* DMA1_MADR;
extern volatile s32* DMA1_BCR;
extern volatile s32* DMA1_CHCR;
extern volatile s32* DMA2_CHCR;
extern volatile s32* DMA2_MADR;
extern volatile s32* DMA2_BCR;
extern volatile s32* DPCR;
extern s8* D_80090DA0;
extern s8* D_80090DA4;
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
extern u8 D_8009B18C[];
extern u32* D_8009B290;
extern s32 D_8009B294;
extern s32 D_8009B298;
extern s32 D_8009B29C;
extern s32 D_8009B2A0;
extern s8 D_8009FD88;

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadTPage);
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
            GPU_printf(&D_80015AD8, (temp_v0_2 >> 9) & 3, (temp_v0_2 >> 7) & 3, (temp_v0_2 << 6) & 0x7C0, (temp_v0_2 * 8) & 0x300);
            return;
        }
        GPU_printf(&D_80015AD8, ((tpage) >> 7) & 0x003, ((tpage) >> 5) & 0x003, ((tpage) << 6) & 0x7c0, (((tpage) << 4) & 0x100) + (((tpage) >> 2) & 0x200));
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpClut);
void DumpClut(u_short clut)
{
    GPU_printf(&D_80015AF0, (clut & 0x3F) << 4, clut >> 6);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", NextPrim);
void* NextPrim(void *p) {
    return nextPrim(p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", IsEndPrim);
int IsEndPrim(void *p) {
    return isendprim(p);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", AddPrim);
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
    p->code[0] = 0x01000000;
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
    p->code[0] = 0xA0000000;
    p->code[1] = *(int*)&rect->x;
    p->code[2] = *(int*)&rect->w;
    p->code[len - 1] = 0x01000000;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MargePrim);
int MargePrim(void* p0, void* p1) {
    int newLen = getlen(p0) + getlen(p1) + 1;
    if (newLen > 16)
        return -1;
    setlen(p0, newLen);
    *(u_long*)p1 = 0;
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDrawEnv);
void DumpDrawEnv(DRAWENV* env)
{
    GPU_printf(&D_80015B00, env->clip.x, env->clip.y, env->clip.w, (s32) env->clip.h);
    GPU_printf(&D_80015B18, env->ofs[0], env->ofs[1]);
    GPU_printf(&D_80015B28, env->tw.x, env->tw.y, env->tw.w, (s32) env->tw.h);
    GPU_printf(&D_80015B40, (s16) env->dtd);
    GPU_printf(&D_80015B4C, (s16) env->dfe);
    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        GPU_printf(&D_80015AD8, (env->tpage >> 9) & 3, (env->tpage >> 7) & 3, (env->tpage << 6) & 0x7C0, (env->tpage * 8) & 0x300);
        return;
    }
    GPU_printf(&D_80015AD8, (env->tpage >> 7) & 3, (env->tpage >> 5) & 3, (env->tpage << 6) & 0x7C0, ((env->tpage * 0x10) & 0x100) + ((env->tpage >> 2) & 0x200));
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDispEnv);
void DumpDispEnv(DISPENV* env)
{
    GPU_printf(&D_80015B58, env->disp.x, env->disp.y, env->disp.w, (s32) env->disp.h);
    GPU_printf(&D_80015B74, env->screen.x, env->screen.y, env->screen.w, (s32) env->screen.h);
    GPU_printf(&D_80015B90, (s16) env->isinter);
    GPU_printf(&D_80015B9C, (s16) env->isrgb24);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ResetGraph);
int ResetGraph(int mode) {
    switch (mode & 7) {
    case 3:
    case 0:
        printf(&D_80015BDC, &D_80090C54, &D_80090C9C);
    case 5:
        GPU_memset(&D_80090C9C, 0, sizeof(DEBUG));
        ResetCallback();
        GPU_cw((s32) D_80090C94 & 0xFFFFFF);
        D_80090C9C.version = _reset(mode);
        D_80090C9C.D_80090C9D = 1;
        D_80090C9C.w = D_80090D1C[D_80090C9C.version];
        D_80090C9C.h = D_80090D30[D_80090C9C.version];
        GPU_memset(&D_80090C9C.draw, -1, sizeof(DRAWENV));
        GPU_memset(&D_80090C9C.disp, -1, sizeof(DISPENV));
        return D_80090C9C.version;
    }
    if (D_80090C9C.level >= 2U) {
        GPU_printf(&D_80015BFC, mode);
    }
    return D_80090C94->reset(1);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphReverse);
int SetGraphReverse(int mode) {
    u_char prev = D_80090C9C.reverse;
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015C10, mode);
    }
    D_80090C9C.reverse = mode;
    D_80090C94->ctl(D_80090C94->getctl(8) | (D_80090C9C.reverse ? 0x08000080 : 0x08000000));
    if (D_80090C9C.version == 2) {
        D_80090C94->ctl(D_80090C9C.reverse ? 0x20000501 : 0x20000504);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphDebug);
int SetGraphDebug(int level) {
    u_char prev = D_80090C9C.level;
    D_80090C9C.level = level;
    if (D_80090C9C.level) {
        GPU_printf(&D_80015C28, D_80090C9C.level,
                   D_80090C9C.version, D_80090C9C.reverse);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphQueue);
int SetGraphQueue(int mode) {
    u_char prev = D_80090C9C.D_80090C9D;
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015C54, mode);
    }
    if (mode != D_80090C9C.D_80090C9D) {
        D_80090C94->reset(1);
        D_80090C9C.D_80090C9D = mode;
        DMACallback(2, NULL);
    }
    return prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphType);
u8 GetGraphType(void)
{
    return D_80090C9C.version;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphDebug);
s32 GetGraphDebug(void)
{
    return D_80090C9C.level;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSyncCallback);
u_long DrawSyncCallback(void (*func)()) {
    void (*prev)();
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015C68, func);
    }
    prev = D_80090C9C.drawSyncCb;
    D_80090C9C.drawSyncCb = func;
    return (u_long)prev;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDispMask);
void SetDispMask(int mask) {
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015C84, mask);
    }
    if (mask == 0) {
        GPU_memset(&D_80090C9C.disp, -1, sizeof(DISPENV));
    }
    D_80090C94->ctl(mask ? 0x03000000 : 0x03000001);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSync);
int DrawSync(int mode)
{
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015C98, mode);
    }
    D_80090C94->sync(mode);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", checkRECT);
void checkRECT(const char* log, RECT* r) {
    switch (D_80090C9C.level) {
    case 1:
        if (
            r->w > D_80090C9C.w ||
            r->w + r->x > D_80090C9C.w ||
            r->y > D_80090C9C.h ||
            r->y + r->h > D_80090C9C.h ||
            r->w <= 0 ||
            r->x < 0 ||
            r->y < 0 ||
            r->h <= 0
        ) {
            GPU_printf(&D_80015CAC, log);
            GPU_printf(&D_80015CB8, r->x, r->y, r->w, r->h);
        }
        break;
    case 2:
        GPU_printf(&D_80015CCC, log);
        GPU_printf(&D_80015CB8, r->x, r->y, r->w, r->h);
        break;
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage);
int ClearImage(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT(&D_80015CD0, rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, sizeof(RECT), (b << 0x10) | (g << 8) | r);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage2);
int ClearImage2(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT(&D_80015CD0, rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, sizeof(RECT), 0x80000000 | (b << 0x10) | (g << 8) | r);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadImage);
int LoadImage(RECT* rect, u_long* p)
{
    checkRECT(&D_80015CDC, rect);
    return D_80090C94->addque2(D_80090C94->dws, rect, sizeof(RECT), p);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", StoreImage);
int StoreImage(RECT* rect, u_long* p)
{
    checkRECT(&D_80015CE8, rect);
    return D_80090C94->addque2(D_80090C94->drs, rect, sizeof(RECT), p);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MoveImage);
int MoveImage(RECT* rect, s32 x, s32 y)
{
    checkRECT(&D_80015CF4, rect);
    if (rect->w == 0 || rect->h == 0) {
        return -1;
    }
    D_80090D4C[0] = LOW(rect->x);
    D_80090D4C[1] = ((u16)y << 0x10) | ((u16)x);
    D_80090D4C[2] = LOW(rect->w);
    return D_80090C94->addque2(D_80090C94->cwc, D_80090D4C-2, sizeof(DISPENV), 0);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearOTag);
OT_TYPE* ClearOTag(OT_TYPE* ot, int n) {
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015D00, ot, n);
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
OT_TYPE* ClearOTagR(OT_TYPE* ot, int n)
{
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015D18, ot, n);
    }
    D_80090C94->otc(ot, n);
    TERM_PRIM(ot, &D_80090D58);
    return ot;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawPrim);
void DrawPrim(void* p) {
    int len = getlen(p);
    D_80090C94->sync(0);
    D_80090C94->cwb((u32*)&((P_TAG*)p)->r0, len);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTag);
void DrawOTag(u_long* p)
{
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015D30, p);
    }
    D_80090C94->addque2(D_80090C94->cwc, p, 0, 0);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDrawEnv);
DRAWENV* PutDrawEnv(DRAWENV* env) {
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015D44, env);
    }
    SetDrawEnv2(&env->dr_env, env);
    termPrim(&env->dr_env);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&D_80090C9C.draw) = *env;
    return env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTagEnv);
void DrawOTagEnv(u_long* p, DRAWENV* env)
{
    if (D_80090C9C.level >= 2U) {
        GPU_printf(&D_80015D5C, p, env);
    }
    SetDrawEnv2(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&D_80090C9C.draw) = *env;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDrawEnv);
DRAWENV* GetDrawEnv(DRAWENV* env) {
    memcpy(env, &D_80090C9C.draw, sizeof(DRAWENV));
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
    if (D_80090C9C.level >= 2) {
        GPU_printf(&D_80015D78, env);
    }
    D_80090C94->ctl(
        (
            D_80090C9C.version == 1 || D_80090C9C.version == 2 ? (
            (
                (env->disp.y & 0xFFF) << 0xC) |
                (get_dx(env) & 0xFFF) | 0x05000000
            ) : (
                ((env->disp.y & 0x3FF) << 0xA) |
                (env->disp.x & 0x3FF) | 0x05000000
            )
        )
    );
    
    if (!CMPRECT(&D_80090C9C.disp.screen, env->screen)){
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
    if ((LOWU(D_80090C9C.disp.isinter) != LOWU(env->isinter)) || !CMPRECT(&D_80090C9C.disp, env->disp)) {
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
        if (D_80090C9C.reverse != 0) {
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
    memcpy((u8*)&D_80090C9C.disp, (u8*)env, sizeof(DISPENV));
    return env;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDispEnv);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv2);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_mode);
u_long get_mode(int dfe, int dtd, u_short tpage)
{
    if (D_80090C9C.version == 1 || D_80090C9C.version == 2) {
        return (dtd ? 0xE1000800 : 0xE1000000) | (dfe ? 0x1000 : 0) |
               (tpage & 0x27FF);
    }
    return (dtd ? 0xE1000200 : 0xE1000000) | (dfe ? 0x400 : 0) |
            (tpage & 0x9FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_cs);
u_long get_cs(short x, short y)
{
    x = CLAMP(x, 0, D_80090C9C.w - 1);
    y = CLAMP(y, 0, D_80090C9C.h - 1);
    if (D_80090C9C.version == 1 || D_80090C9C.version == 2) {
        return 0xE3000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE3000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ce);
u_long get_ce(short x, short y)
{
    x = CLAMP(x, 0, D_80090C9C.w - 1);
    y = CLAMP(y, 0, D_80090C9C.h - 1);
    
    if (D_80090C9C.version == 1 || D_80090C9C.version == 2) {
        return 0xE4000000 | ((y & 0xFFF) << 12) | (x & 0xFFF);
    }
    return 0xE4000000 | ((y & 0x3FF) << 10) | (x & 0x3FF);
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ofs);
u_long get_ofs(short x, short y)
{
    if (D_80090C9C.version == 1 || D_80090C9C.version == 2) {
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
    switch (D_80090C9C.version) {
    case 1:
        return D_80090C9C.reverse ? 0x400 - env->disp.x - env->disp.w : env->disp.x;
    case 2:
        return D_80090C9C.reverse ? 0x400 - env->disp.x - (env->disp.w / 2) : env->disp.x / 2;
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
    if (*DMA2_CHCR & 0x01000000) {
       while(1)
        {
            if (get_alarm()) {
                return -1;
            }
            if (!(*DMA2_CHCR & 0x01000000)) {      
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
    rect->w = CLAMP(rect->w, 0, D_80090C9C.w - 1);
    rect->h = CLAMP(rect->h, 0, D_80090C9C.h - 1);
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
    arg0->w = CLAMP(arg0->w, 0, D_80090C9C.w);
    arg0->h = CLAMP(arg0->h, 0, D_80090C9C.h);
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
    *GPU_DATA = 0x01000000;
    *GPU_DATA = var_s4 ? 0xB0000000 : 0xA0000000;
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
    arg0->w = CLAMP(arg0->w, 0, D_80090C9C.w);
    arg0->h = CLAMP(arg0->h, 0, D_80090C9C.h); 
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
    *GPU_DATA = 0x01000000;
    *GPU_DATA = 0xC0000000;
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
    D_8009B18C[(arg0 >> 0x18)] = arg0 & 0xFFFFFF;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _getctl);
s32 _getctl(s32 arg0)
{
    return *(&D_8009B18C[arg0]);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _addque2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _exeque);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _reset);
s32 _reset(s32 mode)
{
    u_long** queue = &D_80090DA4;
    D_80090DB0 = SetIntrMask(0);
    LOW(D_80090DA4) = NULL;
    D_80090DA0 = D_80090DA4;
    switch (mode & 7) {
    case 0:
    case 5:
        // complete reset, re-initialize draw and disp environments
        *DMA1_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0;
        GPU_memset((s8* )(D_8009B18C), 0, 0x100);
        GPU_memset(&D_8009FD88, 0, 0x1800);
        break;
    case 1:
    case 3:
        // cancels the current drawing and flushes the command buffer
        // preserves the current draw and disp environments
        *DMA1_CHCR = 0x401;
        *DPCR |= 0x800;
        *GPU_STATUS = 0x02000000;
        *GPU_STATUS = 0x01000000;
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
        while (*(s32*)(&D_80090DA0) != *(s32*)(&D_80090DA4)) {
            _exeque();
            if (get_alarm()) return -1;
        }
        
        while ((*DMA1_CHCR & 0x01000000) || !(*GPU_STATUS & 0x04000000)) {
            if (get_alarm()) return -1;
        }
        return 0;
    }    
    temp_s0 = (D_80090DA0 - D_80090DA4) & 0x3F;
    if (temp_s0) {
        _exeque();
    }    
    if ((*DMA1_CHCR & 0x01000000) || !(*GPU_STATUS & 0x04000000)) {
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_alarm);

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
        printf(&D_80015DDC, 0x10);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015DE8, img->mode);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015DF4, timaddr);
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
        printf(&D_80015E04);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015E18, tmd->id, tmd->flags,
               tmd->nobj, objid);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015E40, obj[objid].vert, obj[objid].nvert);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015E58, obj[objid].norm, obj[objid].nnorm);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015E70, obj[objid].prim, obj[objid].nprim);
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
            printf(&D_80015E88);
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
            printf(&D_80015E90);
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
            printf(&D_80015E98);
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
            printf(&D_80015EA0);
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
            printf(&D_80015EA8);
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
            printf(&D_80015EAC);
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
            printf(&D_80015EB0);
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
            printf(&D_80015EB8);
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
            printf(&D_80015EC0);
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
            printf(&D_80015EC8);
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
            printf(&D_80015ED0);
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
            printf(&D_80015ED8);
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
            printf(&D_80015EE0);
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
            printf(&D_80015EE4);
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
            printf(&D_80015EE8);
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
            printf(&D_80015EF0);
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
        printf(&D_80015EF8, arg1->id & 0xFDFFFFFF);
        return -1;
    }
}
