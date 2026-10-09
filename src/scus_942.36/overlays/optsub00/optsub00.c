#include "common.h"
#include "game.h"

typedef struct optsubSprite {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 u;
    /* 0x06 */ s16 v;
    /* 0x08 */ s16 w;
    /* 0x0A */ s16 h;
    /* 0x0C */ s16 clutX;
    /* 0x0E */ s16 clutY;
} optsubSprite;

typedef struct optsubRect {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 w;
    /* 0x06 */ s16 h;
} optsubRect;

typedef struct optsubRequest {
    /* 0x00 */ s16   unk0;
    /* 0x02 */ s16   unk2;
    /* 0x04 */ s16   unk4;
    /* 0x08 */ s32   unk8;
    /* 0x0C */ void* unkC;
    /* 0x10 */ void* unk10;
    /* 0x14 */ s32   unk14;
} optsubRequest;

extern u8    D_800E9348[];
extern u8    D_800E9648;
extern u8    D_800E9C64;
extern s32   D_800E9C90[];
extern s32   D_800E9CF4[];
extern s32   D_800E9D08[];
extern s32   D_800E9D8C[];
extern s32   D_800E9DB4;
extern s32   D_800E9DB8;
extern u8    D_800E9DBC;
extern u8    D_800E9DD4;
extern u8    D_800E9E14[];
extern u8    D_800E9E44[];
extern optsubRect D_800E9E74[];
extern optsubRect D_800E9EA4[];
extern optsubSprite D_800E9EB4[];
extern optsubSprite D_800E9EE4[];
extern optsubSprite* D_800EA2A4[];
extern optsubSprite D_800EA2BC[];
extern optsubSprite D_800EA2EC[];
extern s16   D_800EA36C;
extern s16   D_800EA370;
extern s16   D_800EA374;
extern s16   D_800EA378;
extern u16   D_800EA37C;
extern s16   D_800EA380;
extern void* SEQ_DATA;

s32 fixedMulSin2(s16 arg0, s16 arg1);
void drawOptsubSpriteList();
void func_800E7EFC(void);
void drawOptsubSprite(optsubSprite* arg0, s16 tpage, u8 arg2);
void func_800E8160();
void func_800E82F4(void);
void func_800E83EC(s32 arg0, s32 arg1);
void func_800E8570(s32 arg0);
void func_800E8680();
void func_800E8814(void);
void drawOptsubText(s16 arg0, s16 arg1, s32 arg2);
void func_800E8964(s16 arg0, s16 arg1, s32 arg2);
void func_800E89CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3);
void drawOptsubNumber(s16 arg0, s16 arg1, s32 arg2);
void func_800E8B6C();

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", drawOptsubSpriteList);

void func_800E75C4(void) {
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E75CC);

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7960);
s32 func_800E7960(void)
{
    switch (TASK_C->step.value) {
    case 0:
        TASK_C->step.value++;
        break;
    case 1:
        if (JOYPAD_STATE & 0x2000) {
            playSFXAndSetNote(10, 10);
            TASK_C->step.value = 0;
            TASK_C->state2 = 1;
        } else if (JOYPAD_STATE & 0x4000) {
            playSFX(8);
            D_8009E744++;
            if ((s16)D_8009E744 >= 6) {
                D_8009E744 = 0;
            }
            loadCollisionBounds();
        }
        updateSound();
        break;
    }
    func_800E7EFC();
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7A48);

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7D5C);
void func_800E7D5C(void)
{
    SEQ_DATA = &D_800E9C64;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7D74);
void func_800E7D74(void)
{
    drawOptsubSpriteList(&D_800E9DD4, 0, 0, 1);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7DA4);
void func_800E7DA4(void)
{
    D_800EA378 = 0x1000;
    D_800EA36C = 0;
    D_800EA370 = 0;
    D_800EA374 = 0;
    D_800EA37C = 0x40;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7DDC);
void func_800E7DDC(s32* arg0)
{
    s32 v;

    if (*arg0 == 0) {
        v = (s16)fixedMulSin2((u8)D_800EA37C, D_800EA378) >> 4;
        D_800EA370 = v;
        if (v < 0) {
            D_800EA370 = -v;
        }
        D_800EA37C += 2;
        if (D_800EA378 > 0) {
            D_800EA378 -= 0x20;
        }
    }
    drawOptsubSpriteList(D_800E9E14, 0, (s16)-D_800EA370, 0);
    drawOptsubSpriteList(D_800E9E44, 0, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7EB0);
void func_800E7EB0(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E8160();
    func_800E83EC(D_8009C9E4, D_8009E450);
    func_800E8814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7EFC);
void func_800E7EFC(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E82F4();
    func_800E8570((s16)D_8009E744);
    func_800E8814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E7F40);
void func_800E7F40(void)
{
    *(u8*)0x1F8001CF = 1;
    func_800E8680();
    func_800E8814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", drawOptsubSprite);
void drawOptsubSprite(optsubSprite* arg0, s16 tpage, u8 arg2)
{
    SPRT* sprt;
    SPRT* dst;
    DR_MODE* mode;

    sprt = (SPRT*)0x1F800000;
    setSprt(sprt);
    setRGB0(sprt, 0x80, 0x80, 0x80);
    setSemiTrans(sprt, 1);
    sprt->x0 = arg0->unk0;
    sprt->y0 = arg0->y;
    sprt->u0 = arg0->u;
    sprt->v0 = arg0->v;
    sprt->w = arg0->w;
    sprt->h = arg0->h;
    sprt->clut = GetClut(arg0->clutX, arg0->clutY);
    dst = (SPRT*)D_1F800164;
    *dst = *sprt;
    addPrim((u_long*)D_1F8001E0 + arg2 + 4, dst);
    D_1F800164 += sizeof(SPRT);
    mode = (DR_MODE*)D_1F800164;
    SetDrawMode(mode, 0, 0, tpage, NULL);
    addPrim((u_long*)D_1F8001E0 + arg2 + 4, mode);
    D_1F800164 += sizeof(DR_MODE);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8160);
void func_800E8160(s32 arg0)
{
    TILE* tile;
    TILE* dst;

    tile = (TILE*)0x1F800000;
    setTile(tile);
    setRGB0(tile, 0, 0xFF, 0);
    setSemiTrans(tile, 1);
    if (arg0 >= 4 && D_800EA380 == 0) {
        tile->x0 = D_800E9EA4[arg0 - 4].x;
        tile->y0 = D_800E9EA4[arg0 - 4].y;
        tile->w = D_800E9EA4[arg0 - 4].w;
        tile->h = D_800E9EA4[arg0 - 4].h;
    } else {
        tile->x0 = D_800E9E74[arg0].x;
        tile->y0 = D_800E9E74[arg0].y;
        tile->w = D_800E9E74[arg0].w;
        tile->h = D_800E9E74[arg0].h;
    }
    dst = (TILE*)D_1F800164;
    *dst = *tile;
    addPrim((u_long*)CURRENT_OT + 6, dst);
    D_1F800164 += sizeof(TILE);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E82F4);
void func_800E82F4(void)
{
    TILE* tile;
    TILE* dst;

    tile = (TILE*)0x1F800000;
    setTile(tile);
    setRGB0(tile, 0, 0xFF, 0);
    setSemiTrans(tile, 1);
    setXY0(tile, 0x60, 0x3C);
    setWH(tile, 0x38, 0x18);
    dst = (TILE*)D_1F800164;
    *dst = *tile;
    addPrim((u_long*)CURRENT_OT + 6, dst);
    D_1F800164 += sizeof(TILE);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E83EC);
void func_800E83EC(s32 arg0, s32 arg1)
{
    optsubSprite* p;
    s16 tpage;

    tpage = GetTPage(0, 0, 0x200, 0);
    p = D_800E9EB4;
    while (p->unk0 != -1) {
        drawOptsubSprite(p++, tpage, 0);
    }
    drawOptsubText(0x88, 0xE, 0);
    drawOptsubText(0x50, 0x2C, 1);
    drawOptsubText(0xB0, 0x2C, arg0 + 6);
    drawOptsubText(0x50, 0x44, 2);
    drawOptsubText(0xB0, 0x44, arg1 + 9);
    func_800E8964(0x60, 0xB0, 0x14);
    func_800E8964(0x60, 0xC0, 0x16);
    if (D_800EA380 != 0) {
        drawOptsubText(0x50, 0x5C, 3);
        drawOptsubText(0xB0, 0x5C, (u16)D_8009C97A + 0xB);
        drawOptsubText(0x50, 0x74, 4);
        drawOptsubText(0x50, 0x8C, 5);
    } else {
        drawOptsubText(0x50, 0x5C, 4);
        drawOptsubText(0x50, 0x74, 5);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8570);
void func_800E8570(s32 arg0)
{
    optsubSprite* p;
    s16 tpage;

    tpage = GetTPage(0, 0, 0x200, 0);
    p = D_800EA2A4[arg0];
    while (p->unk0 != -1) {
        drawOptsubSprite(p++, tpage, 0);
    }
    p = D_800E9EE4;
    while (p->unk0 != -1) {
        drawOptsubSprite(p++, tpage, 0);
    }
    func_800E8964(0x60, 0xB0, 0x14);
    func_800E8964(0x60, 0xC0, 0x16);
    func_800E8964(0x20, 0x48, 0x17);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8680);
void func_800E8680(s32 arg0)
{
    optsubSprite* p;
    s16 tpage;

    tpage = GetTPage(0, 0, 0x200, 0);
    p = D_800EA2BC;
    while (p->unk0 != -1) {
        drawOptsubSprite(p++, tpage, 0);
    }
    drawOptsubText(0x68, 0x10, 4);
    drawOptsubText(0xA0, 0x50, 0xD);
    drawOptsubText(0xA0, 0x70, 0xE);
    func_800E89CC(0x20, 0x60, 0x1D, (arg0 == 3) ? 3 : 0);
    func_800E89CC(0x60, 0x60, 0x1E, (arg0 == 4) ? 3 : 0);
    func_800E89CC(0x40, 0x40, 0x1F, (arg0 == 1) ? 3 : 0);
    func_800E89CC(0x40, 0x80, 0x20, (arg0 == 2) ? 3 : 0);
    drawOptsubNumber(0x100, 0x50, (s16)D_8009C864);
    drawOptsubNumber(0x100, 0x70, (s16)D_8009C866 - 8);
    func_800E8964(0x60, 0xB0, 0x16);
    func_800E8964(0x60, 0xC0, 0x15);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8814);
void func_800E8814(void)
{
    optsubSprite* p;
    s16 tpage;

    tpage = GetTPage(1, 0, 0x180, 0);
    p = D_800EA2EC;
    while (p->unk0 != -1) {
        drawOptsubSprite(p++, tpage, 4);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", printTitleScreenMessage);
void printTitleScreenMessage(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 6;
    req.unk8 = D_800E9C90[arg2];
    req.unkC = D_800E9348;
    req.unk10 = (void*)D_800E9CF4[arg2];
    func_800E8B6C(&req, 0, 1, 1);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", drawOptsubText);
void drawOptsubText(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 9;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    func_800E8B6C(&req, 0, 1, 0);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8964);
void func_800E8964(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 2;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    req.unk10 = &D_800E9DBC;
    func_800E8B6C(&req, 0, 1, 2);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E89CC);
void func_800E89CC(s16 arg0, s16 arg1, s32 arg2, s32 arg3)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 9;
    req.unk8 = D_800E9D08[arg2];
    req.unkC = &D_800E9648;
    func_800E8B6C(&req, 0, 1, arg3);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", drawOptsubNumber);
void drawOptsubNumber(s16 arg0, s16 arg1, s32 arg2)
{
    optsubRequest req;

    req.unk0 = arg0;
    req.unk2 = arg1;
    req.unk4 = 9;
    req.unkC = &D_800E9648;
    if (arg2 > 0) {
        req.unk8 = D_800E9DB4;
        func_800E8B6C(&req, 0, 1, 0);
    } else if (arg2 < 0) {
        arg2 = -arg2;
        req.unk8 = D_800E9DB8;
        func_800E8B6C(&req, 0, 1, 0);
    }
    req.unk0 += 8;
    if (arg2 >= 10) {
        req.unk8 = D_800E9D8C[arg2 / 10];
        req.unkC = &D_800E9648;
        func_800E8B6C(&req, 0, 1, 0);
        arg2 -= (arg2 / 10) * 10;
        req.unk0 += 8;
    }
    req.unk8 = D_800E9D8C[arg2];
    req.unkC = &D_800E9648;
    func_800E8B6C(&req, 0, 1, 0);
}

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8B6C);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E8E78);

INCLUDE_ASM("asm/scus_942.36/overlays/optsub00/nonmatchings/optsub00", func_800E90CC);
