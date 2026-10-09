#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024CFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800251C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800253C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002564C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025810);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025A38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025E74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002601C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026228);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800263F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026E48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80027600);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800279E8);
void func_800279E8(u8* arg0, s32 arg1, s32 arg2)
{
    u8* r;

    arg0 += 4;
    r = func_80024EEC(arg2, arg0, arg0 + 4, arg1);
    func_80025C14(r + 0x14, r + 0x18, arg1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", subtractScaledVertices);
void subtractScaledVertices(u8* dst, u8* src, s32 scale)
{
    s32 n;

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x20;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x28;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x26) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x30) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x34;
            src += 0x40;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x30;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x40;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2A) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x54;
            src += 0x40;
        } while (--n != 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028638);
void func_80028638(s32 *src, char *dst)
{
    u16 sz[8];
    s16 i = 0;
    s32 v;
    u16 *p;
    sz[0] = 0x20; sz[1] = 0x28; sz[2] = 0x28; sz[3] = 0x34;
    sz[4] = 0x28; sz[5] = 0x30; sz[6] = 0x40; sz[7] = 0x54;
    do {
        v = *src++;
        if (v != 0) {
            p = (u16 *)(((i << 16) >> 15) + (s32)sz);
            *p = *p * v;
            memcpy(dst, src, *p);
            dst += *p & 0xfffc;
            src = (s32 *)((char *)src + (*p & 0xfffc));
        }
        i++;
    } while (i < 8);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", joypadInit);
void joypadInit(void)
{
    D_8009C97A = 1;
    D_8009C97C = 0;
    D_8009C97D = 0;
    D_8009C97E = 0;
    D_8009C97F = 0;
    D_8009C982 = 0;
    D_8009C983 = 0;
    func_8006A9EC(&D_8009EB58, &D_8009EB58 + 0x22);
    ((void (*)())PadInit)();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028794);
s16 func_80028794(u8* p, s16 mode)
{
    u8  v = *p;
    s32 a;
    s32 b;
    s32 r = 0;

    switch (mode) {
    case 0:
        a = 0x80;
        b = 0x20;
        break;
    case 1:
        a = 0x10;
        b = 0x40;
        break;
    }
    if (v == 0) {
        r = a;
    }
    if (v == 0xFF) {
        r = b;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800287F8);
s16 func_800287F8(u8 *p, s16 mode)
{
    u8 v = *p;
    s16 hi, lo, r;
    u16 t;
    u16 w;

    switch (mode) {
    case 0:
        hi = 0x80;
        lo = 0x20;
        break;
    case 1:
        hi = 0x10;
        lo = 0x40;
        break;
    }
    w = v;
    *p = 0;
    if ((u32)(w - 0x50) < 0x60) {
        return 0;
    }
    t = w - 0x30;
    if (t < 0xa0) {
        *p = 1;
        r = lo;
        if (t < 0x50) r = hi;
    } else {
        t = w - 0x10;
        if (t < 0xe0) {
            *p = 2;
            r = lo;
            if (t < 0x70) r = hi;
        } else {
            *p = 3;
            r = lo;
            if (v < 0x80) r = hi;
        }
    }
    return r;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800288C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028A74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028B34);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028CE4);
extern u8 D_8009C97C;
extern u8 D_8009C97D;
extern s32 func_80068E5C(s32, u8 *, s32);
extern s32 func_80068AA8(s32);
extern void func_80068DDC(s32, s8 *);

typedef struct { s8 b[6]; } PadAlign_28CE4;
extern PadAlign_28CE4 D_80010368;

void func_80028CE4(void)
{
    PadAlign_28CE4 align = D_80010368;
    D_8009C97C = 0;
    D_8009C97D = 0;
    func_80068E5C(0, &D_8009C97C, 2);
    if (func_80068AA8(0) == 6)
        func_80068DDC(0, &align.b[0]);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028D70);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028EF4);
typedef struct { char a; char pad[0x1f]; void *p[6]; char pad2[0x5c - 0x38]; char r[3][4]; } GT_28EF4;
extern s32 D_800B07B4;
extern char D_800B0772;
extern char D_800B0773;
extern s16 D_800B07BC;
extern s16 D_800B07BA;
extern s16 D_800B07C2;
extern s16 D_800B07C0;
extern s16 D_800B07C4;
extern s32 D_800B0788;
extern u8 D_8009BCD8;
extern u8 D_8009C3E7;

void func_80028EF4(void)
{
    s32 i;
    GT_28EF4 *g = &D_800B0770;
    g->a = 1;
    D_800B07B4 = -1;
    D_800B0772 = 0;
    D_800B0773 = 0;
    D_800B07BC = 600;
    D_800B07BA = 0;
    D_800B0788 = D_1F8002D8;
    D_800B07C2 = D_8009BCD8;
    D_800B07C0 = D_8009BCD8;
    D_800B07C4 = D_8009BCD8;
    if (D_8009C3E7 == 0)
        D_800B078C = D_800121A8;
    else
        D_800B078C = D_800121C8;
    g->p[0] = D_8001224C;
    g->p[1] = D_80012260;
    g->p[2] = D_800122B0;
    g->p[3] = D_800123F8;
    g->p[4] = D_80012650;
    g->p[5] = D_800127D0;
    i = 0;
    do {
        g->r[0][i] = 0;
        g->r[1][i] = 0;
        g->r[2][i] = 0;
        i++;
    } while (i < 3);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80029008);

void func_80029008(void)
{

    if (D_800B0770[0] != 0) {
        if (*(u_long*)&GAME.selectedArea == 6) {
            if (D_800B0778 != 0) {
                D_800B0778 -= 1;
            }
        } else {
            func_8002907C(D_800B0770);
        }
    }
}

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/render/ui", D_80010368);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002907C);
