#include "common.h"

#include "psyq/libetc.h"
#include "psyq/libgpu.h"

extern s32 D_80090C9C;
extern s32 D_80090C9F;
extern volatile s32* GPU_DATA;
extern volatile s32* GPU_STATUS;
extern volatile s32* DMA1_MADR;
extern volatile s32* DMA1_BCR;
extern volatile s32* DMA1_CHCR;
extern s32 D_80090DB4;
extern s32 D_80090DB8;
extern u8 D_8009B18C[];
extern u32* D_8009B290;
extern s32 D_8009B294;
extern s32 D_8009B298;
extern s32 D_8009B29C;
extern s32 D_8009B2A0;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadTPage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", LoadClut2);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetTPage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", GetClut);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpTPage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", DumpClut);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", SetDrawTPage);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgpu", _clr);

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
