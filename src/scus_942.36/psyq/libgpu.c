#include "common.h"

#include "psyq/libetc.h"
#include "psyq/libgpu.h"

#define CMD_FILL_RECTANGLE_IN_VRAM(color) ((color & 0xFFFFFF) | 0x02000000)
#define CMD_MONOCHROME_RECTANGLE(color) ((color & 0xFFFFFF) | 0x60000000)

extern char* D_80015AD8; // DumpTPage text
extern char* D_80015AF0; // DumpClut text
extern s32 D_80090C9C;
extern s32 D_80090C9F;
extern s16 D_80090CA0;
extern s16 D_80090CA2;
extern volatile s32* GPU_DATA;
extern volatile s32* GPU_STATUS;
extern volatile s32* DMA1_MADR;
extern volatile s32* DMA1_BCR;
extern volatile s32* DMA1_CHCR;
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
extern s32 D_80090DB4;
extern s32 D_80090DB8;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadTPage);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDefDrawEnv);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMove);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawLoad);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MargePrim);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpDispEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ResetGraph);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphReverse);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphDebug);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetGraphQueue);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphType);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetGraphDebug);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSyncCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDispMask);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", checkRECT);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearImage2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadImage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", StoreImage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", MoveImage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearOTag);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ClearOTagR);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawPrim);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTag);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DrawOTagEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", PutDispEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetDispEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetODE);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetTexWindow);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawArea);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawOffset);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetPriority);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawEnv2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_mode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_cs);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_ce);

u32 get_ofs(s32 arg0, u16 arg1) {
    
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _otc);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _dws);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _drs);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _sync);

void set_alarm(void)
{
    D_80090DB4 = VSync(-1) + 0xF0;
    D_80090DB8 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_alarm);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _version);

void * memset(s8* ptr, int value, s32 num) {
    s32 i;

    for (i = num - 1; i != -1; i--) {
        *ptr++ = value;
    }
}

BIOS_STUB(GPU_cw, 0xA0, 0x49);

int OpenTIM(u_long* addr)
{
    D_8009B290 = addr;
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTIM);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", ReadTMD);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tim_addr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", get_tmd_addr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", unpack_packet);
