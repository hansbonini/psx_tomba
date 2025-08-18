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

typedef struct {
    /* 0x00 */ u32 unk00;                       // aIdSysCV1831995
    /* 0x04 */ void (*addque)();                // _addque
    /* 0x08 */ int (*addque2)();                // _addque2
    /* 0x0C */ u32 clr;                         // _clr
    /* 0x10 */ void (*ctl)(int);                // _ctl
    /* 0x14 */ s32 (*cwb)(s32* arg0, s32 arg1); // _cwb
    /* 0x18 */ u32 cwc;                         // _cwc
    /* 0x1C */ u32 drs;                         // _drs
    /* 0x20 */ u32 dws;                         // _dws
    /* 0x24 */ u32 unk24;                       // _exeque
    /* 0x28 */ int (*getctl)(int);              // _getctl
    /* 0x2C */ void (*otc)(u32* ot, s32 n);     // _otc
    /* 0x30 */ u32 unk30;                       // _param
    /* 0x34 */ s32 (*reset)(int);               // _reset
    /* 0x38 */ u_long (*status)(void);          // _status
    /* 0x3C */ void (*sync)(int);               // _sync
} gpu;                                          // size = 0x40

typedef struct {
    u_long tag;
    u_long code[2];
} DR_PRIO;

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
extern gpu* D_80090C94;
extern s32 D_80090C9C;
extern s8 D_80090C9D;
extern u8 D_80090C9E;
extern s32 D_80090C9F;
extern s16 D_80090CA0;
extern s16 D_80090CA2;
extern void* D_80090CA8;
extern DISPENV TEMP_DISPENV; // size: 0x10
// extern u16 D_80090D0A;
// extern u16 D_80090D0C;
// extern u16 D_80090D0E;
// extern u16 D_80090D10;
// extern u16 D_80090D12;
// extern u16 D_80090D14;
// extern u16 D_80090D16;
// extern s32 D_80090D18;
extern s32 D_80090D1C;
extern s32 D_80090D30;
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

u16 LoadTPage(u_long* pix, s32 tp, s32 abr, s32 x, s32 y, s32 w, s32 h)
{
    RECT temp;
    s32 var_v0;

    temp.x = (s16) x;
    temp.h = (s16) h;
    temp.y = (s16) y;
    switch (tp) {
        case 0:
            var_v0 = w;
            if (w < 0) {
                var_v0 = w + 3;
            }
            temp.w = (s16) (var_v0 >> 2);
            break;
        case 1:
            temp.w = (s16) (w / 2);
            break;
        case 2:
            temp.w = (s16) w;
            break;
    }
    LoadImage((RECT* )&temp, pix);
    return GetTPage(tp, abr, x, y) & 0xFFFF;
}

u16 LoadClut(u_long* clut, s32 x, s32 y)
{
    RECT temp;

    temp.w = 0x100;
    temp.x = (s16) x;
    temp.y = (s16) y;
    temp.h = 1;
    LoadImage((RECT *)&temp, clut);
    return GetClut(x, y) & 0xFFFF;
}

u16 LoadClut2(u_long* clut, s32 x, s32 y)
{
    RECT temp;

    temp.w = 0x10;
    temp.x = (s16) x;
    temp.y = (s16) y;
    temp.h = 1;
    LoadImage((RECT* ) &temp, clut);
    return GetClut(x, y) & 0xFFFF;
}

DRAWENV* SetDefDrawEnv(DRAWENV* env, s32 x, s32 y, s32 w, s32 h)
{
    s32 temp_v0;
    u8 var_v0;

    temp_v0 = GetVideoMode();
    env->clip.x = (s16) x;
    env->clip.y = (s16) y;
    env->clip.w = (s16) w;
    env->tw.x = 0;
    env->tw.y = 0;
    env->tw.w = 0;
    env->tw.h = 0;
    env->r0 = 0;
    env->g0 = 0;
    env->b0 = 0;
    env->dtd = 1;
    env->clip.h = (s16) h;
    if (temp_v0 != 0) {
        var_v0 = h < 0x121;
    } else {
        var_v0 = h < 0x101;
    }
    env->dfe = var_v0;
    env->ofs[0] = (s16) x;
    env->ofs[1] = (s16) y;
    if (GetGraphType() != 1) {
        GetGraphType();
    }
    env->tpage = 0xA;
    env->isbg = 0;
    return env;
}

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

u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y)
{
    s32 result;
    s32 var_v1;

    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        result = ((tp & 3 ) << 9) | ((abr & 3) << 7) | ((s32) (y & 0x300) >> 3) | ((s32) (x & 0x3FF) >> 6);
    } else {
        result = (u16)getTPage(tp,abr,x,y);
    }
    return result;
}

u16 GetClut(s32 x, s32 y)
{
    return getClut(x,y);
}

void DumpTPage(u16 tpage)
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

void DumpClut(u16 clut)
{
    GPU_printf(&D_80015AF0, (clut & 0x3F) * 0x10, (u32) (clut & 0xFFFF) >> 6);
}

void* NextPrim(void *p) {
    return nextPrim(p);
}

int IsEndPrim(void *p) {
    return isendprim(p);
}

void AddPrim(void *ot, void *p) {
    addPrim(ot, p);
}

void AddPrims(void *ot, void *p0, void *p1) {
    addPrims(ot, p0, p1);
}

void CatPrim(void *p0, void *p1) {
    setaddr(p0, p1);
}

void TermPrim(void *p) {
    termPrim(p);
}

void SetSemiTrans(void *p, int abe) {
    setSemiTrans(p, abe);
}

void SetShadeTex(void *p, int tge) {
    setShadeTex(p, tge);
}

void SetPolyF3(POLY_F3 *p) {
    setlen(p, 4);
    setcode(p, 0x20);
}

void SetPolyFT3(POLY_FT3 *p) {
    setlen(p, 7);
    setcode(p, 0x24);
}

void SetPolyG3(POLY_G3 *p) {
    setlen(p, 6);
    setcode(p, 0x30);
}

void SetPolyGT3(POLY_GT3 *p) {
    setlen(p, 9);
    setcode(p, 0x34);
}

void SetPolyF4(POLY_F4 *p) {
    setlen(p, 5);
    setcode(p, 0x28);
}

void SetPolyFT4(POLY_FT4 *p) {
    setlen(p, 9);
    setcode(p, 0x2C);
}

void SetPolyG4(POLY_G4 *p) {
    setlen(p, 8);
    setcode(p, 0x38);
}

void SetPolyGT4(POLY_GT4 *p) {
    setlen(p, 12);
    setcode(p, 0x3C);
}

void SetSprt8(SPRT_8 *p) {
    setlen(p, 3);
    setcode(p, 0x74);
}

void SetSprt16(SPRT_16 *p) {
    setlen(p, 3);
    setcode(p, 0x7C);
}

void SetSprt(SPRT *p) {
    setlen(p, 4);
    setcode(p, 0x64);
}

void SetTile1(TILE_1 *p) {
    setlen(p, 2);
    setcode(p, 0x68);
}

void SetTile8(TILE_8 *p) {
    setlen(p, 2);
    setcode(p, 0x70);
}

void SetTile16(TILE_16 *p) {
    setlen(p, 2);
    setcode(p, 0x78);
}

void SetTile(TILE *p) {
    setlen(p, 3);
    setcode(p, 0x60);
}

void SetLineF2(LINE_F2 *p) {
    setlen(p, 3);
    setcode(p, 0x40);
}

void SetLineG2(LINE_G2 *p) {
    setlen(p, 4);
    setcode(p, 0x50);
}

void SetLineF3(LINE_F3 *p) {
    setlen(p, 5);
    setcode(p, 0x48);
    p->pad = 0x55555555;
}

void SetLineG3(LINE_G3 *p) {
    setlen(p, 7);
    setcode(p, 0x58);
    p->pad = 0x55555555;
}

void SetLineF4(LINE_F4 *p) {
    setlen(p, 6);
    setcode(p, 0x4c);
    p->pad = 0x55555555;
}

void SetLineG4(LINE_G4 *p) {
    setlen(p, 9);
    setcode(p, 0x5c);
    p->pad = 0x55555555;
}

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

void SetDrawMove(DR_MOVE* p, RECT* rect, s32 x, s32 y)
{
    u32 var_a0;

    var_a0 = 5;
    if ((rect->w == 0) || (rect->h == 0)) {
        var_a0 = 0;
    }
    p->code[0] = 0x01000000;
    p->code[1] = 0x80000000;
    setlen(p, var_a0);
    p->code[2] = *(u32*)(&rect->x);
    p->code[3] = (y << 0x10) | (x & 0xFFFF);
    p->code[4] = *(u32*)(&rect->w);;
}

void SetDrawLoad(DR_LOAD* p, RECT* rect)
{
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = (s32) ((rect->w * rect->h) + 1) / 2;
    var_v1 = temp_v0 + 4;
    if (temp_v0 >= 0xDU) {
        var_v1 = 0;
    }
    setlen(p, var_v1);
    p->code[0] = 0xA0000000;
    p->code[1] = *(s32*)(&rect->x);
    p->code[2] = *(s32*)(&rect->w);
    p->code[var_v1-1] = 0x01000000;
}

s32 MargePrim(void* p0, void* p1)
{
    s32 temp_v1;
    s32 result;

    temp_v1 = *(u8 *)(p0 + 3) + *(u8 *)(p1 + 3) + 1;
    if (temp_v1 < 0x11) {
        *(u8*)(p0 + 3) = (u8) temp_v1;
        *(u32 *)(p1) = 0;
        result = 0;
    } else {
        result = -1;
    }
    return result;
}

void DumpDrawEnv(DRAWENV* env)
{
    u16 temp_v0;
    u16 temp_v0_2;

    GPU_printf(&D_80015B00, env->clip.x, env->clip.y, env->clip.w, (s32) env->clip.h);
    GPU_printf(&D_80015B18, env->ofs[0], env->ofs[1]);
    GPU_printf(&D_80015B28, env->tw.x, env->tw.y, env->tw.w, (s32) env->tw.h);
    GPU_printf(&D_80015B40, (s16) env->dtd);
    GPU_printf(&D_80015B4C, (s16) env->dfe);
    if ((GetGraphType() == 1) || (GetGraphType() == 2)) {
        temp_v0 = env->tpage;
        GPU_printf(&D_80015AD8, (temp_v0 >> 9) & 3, (temp_v0 >> 7) & 3, (temp_v0 << 6) & 0x7C0, (temp_v0 * 8) & 0x300);
        return;
    }
    temp_v0_2 = env->tpage;
    GPU_printf(&D_80015AD8, (temp_v0_2 >> 7) & 3, (temp_v0_2 >> 5) & 3, (temp_v0_2 << 6) & 0x7C0, ((temp_v0_2 * 0x10) & 0x100) + ((temp_v0_2 >> 2) & 0x200));
}

void DumpDispEnv(DISPENV* env)
{
    GPU_printf(&D_80015B58, env->disp.x, env->disp.y, env->disp.w, (s32) env->disp.h);
    GPU_printf(&D_80015B74, env->screen.x, env->screen.y, env->screen.w, (s32) env->screen.h);
    GPU_printf(&D_80015B90, (s16) env->isinter);
    GPU_printf(&D_80015B9C, (s16) env->isrgb24);
}

s32 ResetGraph(s32 mode)
{
    s32 temp_v0_2;
    s32 temp_v1;
    u8 temp_v0;

    temp_v1 = mode & 7;
    switch (temp_v1) {
        case 3:
        case 0:
            printf(&D_80015BDC, &D_80090C54, &D_80090C9C);
        case 5:
            GPU_memset((s8* ) &D_80090C9C, 0, sizeof(gpu)*2);
            ResetCallback();
            GPU_cw((s32) D_80090C94 & 0xFFFFFF);
            temp_v0 = _reset(mode);
            temp_v0_2 = (temp_v0 & 0xFF);
            *(u8*)(&D_80090C9C) = temp_v0;
            *(s8*)(&D_80090C9D) = 1;
            D_80090CA0 = *(u32*)(&D_80090D1C + temp_v0_2);
            D_80090CA2 = *(u32*)(&D_80090D30 + temp_v0_2);
            GPU_memset((s8* ) (&D_80090C9C + 0x4), -1, sizeof(DRAWENV));
            GPU_memset((s8* ) (&D_80090C9C + 0x1B), -1, sizeof(DISPENV));
            return *(u8*)(&D_80090C9C);
        default:
            if ((u8) D_80090C9E >= 2U) {
                GPU_printf(&D_80015BFC, mode);
            }
            return D_80090C94->reset(1);
    }
}

int SetGraphReverse(int mode) {
    s32 old = *(u8*)(&D_80090C9F);

    if (*(u8*)(&D_80090C9E) >= 2) {
        GPU_printf(&D_80015C10, mode);
    }

    *(u8*)(&D_80090C9F) = mode;
    D_80090C94->ctl(D_80090C94->getctl(8) | (*(u8*)(&D_80090C9F) ? 0x08000080 : 0x08000000));
    
    if ((u8)D_80090C9C == 2) {
        D_80090C94->ctl(*(u8*)(&D_80090C9F) ? 0x20000501 : 0x20000504);
    }
    return old;
}

s32 SetGraphDebug(s32 level) {
    u8 temp_s0;
    u8 temp_a1;

    temp_s0 = *(s32*)(&D_80090C9E);
    temp_a1 = level;
    temp_a1 &= 0xFF;
    *(s8*)(&D_80090C9E) = temp_a1;
    if (temp_a1) {
        GPU_printf(&D_80015C28, temp_a1, *(u8*)(&D_80090C9C), *(u8*)(&D_80090C9F));
    }
    return temp_s0;
}

int SetGraphQueue(int mode) {
    u8 old = *(s32*)(&D_80090C9D);

    if (*(u8*)(&D_80090C9E) >= 2) {
        GPU_printf(&D_80015C54, mode);
    }
    if (mode != *(u8*)(&D_80090C9D)) {
        D_80090C94->reset(1);
        *(u8*)(&D_80090C9D) = mode;
        DMACallback(2, 0);
    }

    return old;
}

u8 GetGraphType(void)
{
    return D_80090C9C;
}

s32 GetGraphDebug(void)
{
    return (s32) D_80090C9E;
}

u_long DrawSyncCallback(void (*func)())
{
    void (*temp_v0)();

    if ((u8) D_80090C9E >= 2U) {
        GPU_printf(&D_80015C68, func);
    }
    temp_v0 = D_80090CA8;
    D_80090CA8 = func;
    return (u32) temp_v0;
}

void SetDispMask(s32 mask)
{
    s32 var_a0;

    if (*(s8 *)(&D_80090C9E) >= 2U) {
        GPU_printf(&D_80015C84, mask);
    }
    if (!mask) {
        GPU_memset((u8*)(&D_80090C9E + 0x6A), -1, sizeof(DISPENV));
    }
    D_80090C94->ctl(mask ? 0x03000000:0x03000001);
}

s32 DrawSync(s32 mode)
{
    if ((u8) D_80090C9E >= 2U) {
        GPU_printf(&D_80015C98, mode);
    }
    D_80090C94->sync(mode);
}

void checkRECT(const char* log, RECT* r) {
    switch (*(u8*)(&D_80090C9E)) {
    case 1:
        if (r->w > D_80090CA0 || r->w + r->x > D_80090CA0 || r->y > D_80090CA2 ||
            r->y + r->h > D_80090CA2 || r->w <= 0 || r->x < 0 || r->y < 0 ||
            r->h <= 0) {
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

s32 ClearImage(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT(&D_80015CD0, rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, 8, ((b & 0xFF) << 0x10) | ((g & 0xFF) << 8) | (r & 0xFF));
}

s32 ClearImage2(RECT* rect, u8 r, u8 g, u8 b)
{
    checkRECT(&D_80015CD0, rect);
    return D_80090C94->addque2(D_80090C94->clr, rect, 8, (((b & 0xFF) << 0x10) | 0x80000000) | ((g & 0xFF) << 8) | (r & 0xFF));
}

int LoadImage(RECT* rect, u_long* p)
{
    checkRECT(&D_80015CDC, rect);
    return D_80090C94->addque2(D_80090C94->dws, rect, 8, p);
}

int StoreImage(RECT* rect, u_long* p)
{
    checkRECT(&D_80015CE8, rect);
    return D_80090C94->addque2(D_80090C94->drs, rect, 8, p);
}

s32 MoveImage(RECT* rect, s32 x, s32 y)
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

OT_TYPE* ClearOTag(OT_TYPE* ot, int n) {
    if (D_80090C9E >= 2) {
        GPU_printf(&D_80015D00, ot, n);
    }

    n--;
    while (n) {
        setlen(ot, 0);
        setaddr(ot, ot + 1);
        n--;
        ot++;
    }

    *ot = (s32) &D_80090D58 & 0xFFFFFF;
    return ot;
}

OT_TYPE* ClearOTagR(OT_TYPE* ot, int n)
{
    if (D_80090C9E >= 2) {
        GPU_printf(&D_80015D18, ot, n);
    }

    D_80090C94->otc(ot, n);
    *ot = (s32) &D_80090D58 & 0xFFFFFF;
    return ot;
}

void DrawPrim(void* p)
{
    u8 plen;
    
    plen = ((P_TAG*)(p))->len;
    D_80090C94->sync(0);
    D_80090C94->cwb(p + 4, (s32) plen);
}

void DrawOTag(u_long* p)
{
    if ((u8) D_80090C9E >= 2U) {
        GPU_printf(&D_80015D30, p);
    }
    D_80090C94->addque2(D_80090C94->cwc, p, 0, 0);
}

DRAWENV* PutDrawEnv(DRAWENV* env) {

    if ((u8)(LOW(D_80090C9E)) >= 2) {
        GPU_printf(&D_80015D44, env);
    }

    SetDrawEnv2(&env->dr_env, env);
    termPrim(&env->dr_env);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, 0x40, 0);
    *(DRAWENV*)(&D_80090C9E+0xE) = *env;

    return env;
}

void DrawOTagEnv(u_long* p, DRAWENV* env)
{
    if ((u8)(LOW(D_80090C9E)) >= 2U) {
        GPU_printf(&D_80015D5C, p, env);
    }
    
    SetDrawEnv2(&env->dr_env, env);
    setaddr(&env->dr_env, p);
    D_80090C94->addque2(D_80090C94->cwc, &env->dr_env, sizeof(DR_ENV), 0);
    *(DRAWENV*)(&D_80090C9E+0xE) = *env;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDispEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDispEnv);

s32 GetODE(void)
{
    return (s32) (D_80090C94->status() >> 0x1F);
}

void SetTexWindow(DR_TWIN* p, RECT* tw)
{
    setlen(p, 2);
    p->code[0] = get_tw(tw);
    p->code[1] = 0;
}

void SetDrawArea(DR_AREA* p, RECT* r)
{
    setlen(p, 2);
    p->code[0] = get_cs(r->x, r->y);
    p->code[1] = get_ce((s16) (((u16) r->x + (u16) r->w) - 1), (s16) (((u16) r->y + (u16) r->h) - 1));
}

void SetDrawOffset(DR_OFFSET* p, u_short* ofs) {
    setlen(p, 2);
    p->code[0] = get_ofs((s16)ofs[0], (s16)ofs[1]);
    p->code[1] = 0;
}

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_mode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_cs);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ce);

u32 get_ofs(s32 arg0, s16 arg1) {
    
    if (!(1U < (u8)D_80090C9C - 1U)) {
        return 0xe5000000 | ((arg1 & 0xfff) << 0xC) | arg0 & 0xfFF;
    }
    return 0xe5000000 | ((arg1 & 0x7ff) << 0xB) | (arg0 & 0x7ff);
}

u32 get_tw(RECT* arg0) {
    u32 pad[4];

    if (arg0 != 0) {
        pad[0] = (u8) arg0->x >> 3;
        pad[2] = (s32) (-arg0->w & 0xFF) >> 3;
        pad[1] = (u8) arg0->y >> 3;
        pad[3] = (s32) (-arg0->h & 0xFF) >> 3;
        return (pad[1] << 0xF) | 0xE2000000 | ((pad[0] << 0xA) ) | (pad[3] << 5) |  pad[2];
    }
    return 0;
}

u32 get_dx(DISPENV* env)
{
    switch ((u8)D_80090C9C) {
    case 1:
        return (u8)D_80090C9F ? 0x400 - env->disp.x - env->disp.w : env->disp.x;
    case 2:
        return (u8)D_80090C9F ? 0x400 - env->disp.x - (env->disp.w / 2) : env->disp.x / 2;
    default:
        return env->disp.x;
    }
}

s32 _status(void)
{
    return *GPU_STATUS;
}

s32 _otc(s32 arg0, s32 arg1)
{
    s32 temp;

    *DPCR |= 0x08000000;
    *DMA2_CHCR = 0;
    temp = arg0 - 4 + arg1 * 4;
    *DMA2_MADR = temp;
    *DMA2_BCR = arg1;
    *DMA2_CHCR = 0x11000002;
    set_alarm();
    if (*DMA2_CHCR & 0x01000000) {
       while(1)
        {
            if (get_alarm()) {
                return -1;
            }
            else {
                if (!(*DMA2_CHCR & 0x01000000)) {      
                    break;
                }
            }
        }
    }
    return arg1;
}

s32 _clr(RECT* rect, u32 color)
{
    s16 temp_w;
    s16 temp_h;
    s32* ptr;

    if (rect->w >= 0) {
        if ((D_80090CA0-1) >= rect->w) {
            temp_w = rect->w;
        } else {
            temp_w = D_80090CA0 - 1;
        }
    } else {
        temp_w = 0;
    }
    rect->w = temp_w;
    
    if (rect->h >= 0) {
        if ((D_80090CA2-1) >= rect->h) {
            temp_h = rect->h;
        } else {
            temp_h = D_80090CA2 - 1;
        }
    } else {
        temp_h = 0;
    }
    rect->h = temp_h;
    
    if ((rect->x & 0x3F) || (rect->w & 0x3F)) {
        ptr = &D_8009B16C;
        D_8009B148 = ((s32) ptr & 0xFFFFFF) | 0x08000000;
        D_8009B14C = 0xE3000000;
        D_8009B150 = 0xE4FFFFFF;
        D_8009B154 = 0xE5000000;
        D_8009B158 = 0xE6000000;
        
        D_8009B15C = 0xE1000000 | (*GPU_STATUS & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B160 = CMD_MONOCHROME_RECTANGLE(color);
        D_8009B164 = (s32) *(u32*)&rect->x;
        D_8009B168 = (s32) *(u32*)&rect->w;
        *ptr = 0x03FFFFFF;
        D_8009B170 = _param(3) | 0xE3000000; // set drawing area top left
        D_8009B174 = _param(4) | 0xE4000000; // set drawing area bottom right
        D_8009B178 = _param(5) | 0xE5000000; // set drawing offset
    } else {
        D_8009B148 = 0x05FFFFFF;
        D_8009B14C = 0xE6000000;
        
        D_8009B150 = 0xE1000000 | ((*GPU_STATUS) & 0x7FF) | (((color >> 0x1F) << 0xA));
        D_8009B154 = CMD_FILL_RECTANGLE_IN_VRAM(color);
        D_8009B158 = (s32) *(u32*)&rect->x;
        D_8009B15C = (s32) *(u32*)&rect->w;
    }
    _cwc((s32) &D_8009B148);
    return 0;
}

s32 _dws(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s32 var_s4;

    img_ptr = arg1;
    set_alarm();
    var_s4 = 0;

    arg0->w = CLAMP(arg0->w, 0, D_80090CA0);
    arg0->h = CLAMP(arg0->h, 0, D_80090CA2);
    
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

s32 _drs(RECT* arg0, s32* arg1) {
    s32 temp_a0;
    s32 size;
    s32 var_s0;
    s32* img_ptr;
    s16 var_a0, var_a02;
    s32 var_s4;

    img_ptr = arg1;
    set_alarm();

    arg0->w = CLAMP(arg0->w, 0, D_80090CA0);
    arg0->h = CLAMP(arg0->h, 0, D_80090CA2);
    
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

void _ctl(s32 arg0)
{
    *GPU_STATUS = arg0;
    D_8009B18C[(u32) arg0 >> 0x18] = (u8) arg0;
}

s32 _getctl(s32 arg0)
{
    return *(&D_8009B18C[arg0]);
}

s32 _cwb(s32* arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a2;
    s32* var_a0;
    u8 pad[8];

    var_a0 = arg0;
    var_a2 = arg1 - 1;
    *GPU_STATUS = 0x04000000;
    if (arg1 != 0) {
        do {
            temp_v1 = *var_a0;
            var_a0 += 1;
            var_a2 -= 1;
            *GPU_DATA = temp_v1;
        } while (var_a2 != -1);
    }
    return 0;
}

void _cwc(s32 arg0) {
    *GPU_STATUS = 0x04000002;
    *DMA1_MADR = arg0;
    *DMA1_BCR = 0;
    *DMA1_CHCR = 0x01000401;
}

s32 _param(s32 arg0)
{
    *GPU_STATUS = arg0 | 0x10000000;
    return *GPU_DATA & 0xFFFFFF;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _addque);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _addque2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _exeque);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _reset);

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

void set_alarm(void)
{
    D_80090DB4 = VSync(-1) + 0xF0;
    D_80090DB8 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_alarm);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _version);

void * GPU_memset(s8* ptr, int value, s32 num) {
    s32 i;

    for (i = num - 1; i != -1; i--) {
        *ptr++ = value;
    }
}


#if !(SKIP_ASM || M2CTX)

    BIOS_STUB(GPU_cw, 0xA0, 0x49);

#endif

int OpenTIM(u_long* addr)
{
    D_8009B290 = addr;
    return 0;
}

TIM_IMAGE* ReadTIM(TIM_IMAGE* timimg)
{
    s32 temp_v0;

    temp_v0 = get_tim_addr(D_8009B290, timimg);
    if (temp_v0 == -1) {
        return 0;
    }
    D_8009B290 = &D_8009B290[temp_v0];
    return timimg;
}

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

TMD_PRIM* ReadTMD(TMD_PRIM* tmdprim)
{
    s32 packet;
    packet = unpack_packet((u8* ) D_8009B29C, tmdprim);
    if (packet < 0) return 0;
    
    D_8009B29C += packet;
    tmdprim->v_ofs = (SVECTOR*)(D_8009B294);
    tmdprim->n_ofs = (SVECTOR*)(D_8009B298);
    tmdprim->n0.vx = (*(SVECTOR *)((tmdprim->norm0 * 8) + D_8009B298)).vx;
    tmdprim->n0.vy = (*(SVECTOR *)((tmdprim->norm0 * 8) + D_8009B298)).vy;
    tmdprim->n0.vz = (*(SVECTOR *)((tmdprim->norm0 * 8) + D_8009B298)).vz;
    tmdprim->n1.vx = (*(SVECTOR *)((tmdprim->norm1 * 8) + D_8009B298)).vx;
    tmdprim->n1.vy = (*(SVECTOR *)((tmdprim->norm1 * 8) + D_8009B298)).vy;
    tmdprim->n1.vz = (*(SVECTOR *)((tmdprim->norm1 * 8) + D_8009B298)).vz;
    tmdprim->n2.vx = (*(SVECTOR *)((tmdprim->norm2 * 8) + D_8009B298)).vx;
    tmdprim->n2.vy = (*(SVECTOR *)((tmdprim->norm2 * 8) + D_8009B298)).vy;
    tmdprim->n2.vz = (*(SVECTOR *)((tmdprim->norm2 * 8) + D_8009B298)).vz;
    tmdprim->n3.vx = (*(SVECTOR *)((tmdprim->norm3 * 8) + D_8009B298)).vx;
    tmdprim->n3.vy = (*(SVECTOR *)((tmdprim->norm3 * 8) + D_8009B298)).vy;
    tmdprim->n3.vz = (*(SVECTOR *)((tmdprim->norm3 * 8) + D_8009B298)).vz;
    tmdprim->x0.vx = (*(SVECTOR *)((tmdprim->vert0 * 8) + D_8009B294)).vx;
    tmdprim->x0.vy = (*(SVECTOR *)((tmdprim->vert0 * 8) + D_8009B294)).vy;
    tmdprim->x0.vz = (*(SVECTOR *)((tmdprim->vert0 * 8) + D_8009B294)).vz;
    tmdprim->x1.vx = (*(SVECTOR *)((tmdprim->vert1 * 8) + D_8009B294)).vx;
    tmdprim->x1.vy = (*(SVECTOR *)((tmdprim->vert1 * 8) + D_8009B294)).vy;
    tmdprim->x1.vz = (*(SVECTOR *)((tmdprim->vert1 * 8) + D_8009B294)).vz;
    tmdprim->x2.vx = (*(SVECTOR *)((tmdprim->vert2 * 8) + D_8009B294)).vx;
    tmdprim->x2.vy = (*(SVECTOR *)((tmdprim->vert2 * 8) + D_8009B294)).vy;
    tmdprim->x2.vz = (*(SVECTOR *)((tmdprim->vert2 * 8) + D_8009B294)).vz;
    tmdprim->x3.vx = (*(SVECTOR *)((tmdprim->vert3 * 8) + D_8009B294)).vx;
    tmdprim->x3.vy = (*(SVECTOR *)((tmdprim->vert3 * 8) + D_8009B294)).vy;
    tmdprim->x3.vz = (*(SVECTOR *)((tmdprim->vert3 * 8) + D_8009B294)).vz;
    return tmdprim;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tim_addr);

s32 get_tmd_addr(s32* arg0, s32 arg1, s32* arg2, s32* arg3, s32* arg4) {
    s32 temp_s2;
    s32* temp_v0;
    s32* temp_v1;

    temp_s2 = arg0 + 0x3;
    if (GetGraphDebug() == 2) {
        printf(&D_80015E04);
    }
    if (GetGraphDebug() == 2) {
        printf(&D_80015E18, *(s32*)(arg0), *(s32*)(arg0+0x1), *(s32*)(arg0+0x2), arg1);
    }
    if (GetGraphDebug() == 2) {
        temp_v0 = (arg1 * 0x1C) + temp_s2;
        printf(&D_80015E40, *(s32*)(temp_v0), *(s32*)(temp_v0+0x1));
    }
    if (GetGraphDebug() == 2) {
        temp_v0 = (arg1 * 0x1C) + temp_s2;
        printf(&D_80015E58, *(s32*)(temp_v0+0x2), *(s32*)(temp_v0+0x3));
    }
    if (GetGraphDebug() == 2) {
        temp_v0 = (arg1 * 0x1C) + temp_s2;
        printf(&D_80015E70, *(s32*)(temp_v0+0x4), *(s32*)(temp_v0+0x5));
    }
    temp_v1 = (((arg1 * 8) - arg1) * 4) + temp_s2;
    *arg3 = temp_s2 + *(s32*)(temp_v1);
    *arg4 = temp_s2 + *(s32*)(temp_v1+0x2);
    *arg2 = temp_s2 + *(s32*)(temp_v1+0x4);
    return *(s32*)(temp_v1+0x5);
}

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
