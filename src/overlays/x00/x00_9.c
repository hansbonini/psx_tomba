#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_9", func_801350F4);
extern char D_80077208[];
extern void *D_8013A4E8;
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);

void func_801350F4(GameObject *o)
{
    extern void *D_8013A4E4;
    switch (o->subState) {
    case 0:
        o->objectIndex = 0;
        o->movetab = D_80077208;
        o->subState++;
        o->velV = 0x80;
        o->unk88 = 0;
        o->anim = D_8013A4E4;
        readAnimFrameCount(o);
        break;
    case 1:
    case 4:
        if (o->subState == 4 && o->objectIndex == 0) {
            if (tickAnimation(o)) {
                o->anim = D_8013A4E4;
                readAnimFrameCount(o);
                o->objectIndex = 1;
            }
        } else {
            tickAnimation(o);
        }
        applyAnimVelocityX(o, o->animFrame);
        o->unk88 = (o->unk88 + 1) & 0xff;
        o->y.raw -= (D_8007DB88[o->unk88] * o->velV) >> 4;
        if (o->unk88 > 0x20) {
            o->timer = 0;
            o->cooldownTimer = 0;
            o->subState++;
        }
        break;
    case 2:
    case 5:
        tickAnimation(o);
        applyAnimVelocityX(o, o->animFrame);
        if (*(u16 *)0x1F8001F8 & 1) {
            o->unk88--;
        } else {
            o->unk88++;
        }
        o->unk88 = *(u8 *)&o->unk88;
        o->y.raw -= (D_8007DB88[o->unk88] * o->velV) >> 4;
        if (++o->timer >= 0x18) {
            o->subState++;
        }
        break;
    case 3:
    case 6:
        tickAnimation(o);
        applyAnimVelocityX(o, o->animFrame);
        o->unk88 = (o->unk88 + 1) & 0xff;
        o->y.raw -= (D_8007DB88[o->unk88] * o->velV) >> 4;
        if (o->unk88 >= 0x80) {
            *(s32 *)((char *)o + 0x88) = 0;
            *(s16 *)((char *)o + 0x20) = 0x10;
            *(s16 *)((char *)o + 0x16) = o->unk34;
            o->anim = D_8013A4E8;
            readAnimFrameCount(o);
            o->subState++;
        }
        break;
    case 7:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->subState++;
        }
        break;
    case 8:
        o->subState = 0;
        o->animFrame = 1 - o->animFrame;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_9", func_801353D4);
extern void freeObjectLayer2(u8 *);
extern void func_80134E50(u8 *);
extern u8 D_8009C114;
extern s32 D_1F8002D4;
extern u8 *D_8013A4A4;
extern u8 *D_8013A4E4;

void func_801353D4(u8 *o)
{
    u8 s;
    s32 t, w;
    u8 *u;
    s = o[4];
    switch (s) {
    case 0:
        if (D_8009C114 != 0xff)
            o[4] = 3;
        else {
            o[4] = s + 1;
            o[0] = 2;
            *(s16 *)(o + 0x6c) = 0x18;
            *(s16 *)(o + 0x6e) = 0x30;
            *(s16 *)(o + 0x70) = 0x18;
            *(s16 *)(o + 0x72) = 0x30;
            w = D_1F8002D4;
            o[0xd] = 0;
            *(s32 *)(o + 0x3c) = w;
            if (o[3] == 0) {
                *(s16 *)(o + 0x1e) = 8;
                *(u8 **)(o + 0x24) = D_8013A4A4;
            } else {
                t = *(s16 *)(o + 0x16);
                u = D_8013A4E4;
                *(s16 *)(o + 0x1e) = 0xb;
                *(s32 *)(o + 0x34) = t;
                *(u8 **)(o + 0x24) = u;
            }
            readAnimFrameCount(o);
        }
        break;
    case 1:
        func_80022E44(o);
        if (o[3] == 0) {
            tickAnimation(o);
            func_80134E50(o);
        } else
            func_801350F4(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_9", func_80135528);
extern u32 D_8009BCEC;
extern u8 D_8009C227;
extern u8 D_800A5403;
extern u8 D_800A5402;

void func_80135528(u8 *o)
{
    u8 *a, *b, *c;
    s32 n;
    u32 *fl = &D_8009BCEC;
    *fl |= 8;
    if (D_8009C114 == 0xff) {
        o[4] = 3;
        return;
    }
    if (D_8009C227 != 0)
        return;
    D_800A5403 = 0;
    D_800A5402 = 0;
    a = allocObjectLayer3();
    if (a != 0) {
        a[0] = 1;
        a[2] = 0x17;
        *(s32 *)(a + 0x10) = 0xa280000;
        *(s32 *)(a + 0x14) = 0xfec00000;
        *(s32 *)(a + 0x18) = 0x2a60000;
        *(s8 *)(a + 0xf) = -7;
        a[0xa] = 0;
        *(s16 *)(a + 0x2e) = 0;
        a[0x1d] = 5;
        a[4] = 0;
        a[5] = 0;
        a[6] = 0;
    }
    b = allocObjectLayer4();
    if (b != 0) {
        b[0] = 1;
        b[2] = 0x18;
        *(s32 *)(b + 0x10) = 0xa460000;
        *(s32 *)(b + 0x14) = 0xfef40000;
        *(s32 *)(b + 0x18) = 0x1340000;
        *(s8 *)(b + 0xf) = -7;
        b[0xa] = 0;
        *(s16 *)(b + 0x2e) = 0;
        b[0x1d] = 5;
        b[4] = 0;
        b[5] = 0;
        b[6] = 0;
    }
    c = allocObjectLayer4();
    if (c != 0) {
        volatile s32 *pp = &D_1F800334;
        s32 base;
        n = *(s32 *)(*pp + 4);
        base = *pp;
        c[0xa4] = 1;
        c[0] = 1;
        c[2] = 0x17;
        *(s32 *)(c + 0x10) = 0x9ea0000;
        *(s32 *)(c + 0x14) = 0xfedf0000;
        *(s32 *)(c + 0x18) = 0x2b50000;
        c[0xa] = 0x11;
        *(s8 *)(c + 0xf) = -7;
        c[3] = 0;
        c[0xc] = 0;
        *(s16 *)(c + 0x2e) = 0;
        c[0x1d] = 5;
        c[4] = 0;
        c[5] = 0;
        c[6] = 0;
        *(s32 *)(c + 0xa0) = base + n;
    }
    *(u8 **)(o + 0x1c) = a;
    *(u8 **)(o + 0x20) = b;
    *(u8 **)(o + 0x24) = c;
    o[4] = 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_9", func_80135708);
extern s16 *D_800A53D8;

s32 func_80135708(void)
{
    return D_800A53D8[1] > 0xd8;
}
