#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", computeRotatedQuad);
void computeRotatedQuad(s16* out, s32 arg1, s16 r1, s16 r2) {
    s32 angle = arg1 & 0xFF;
    s32 a;
    s16 half;
    s32 c;
    s32 s;

    a = (s16)(angle + 0x140) & 0xFF;
    half = r1 >> 1;
    out[0] = fixedMulCos((u8)a, half);
    out[1] = fixedMulSin((u8)a, half);
    a = (s16)(angle + 0xC0) & 0xFF;
    out[2] = fixedMulCos((u8)a, half);
    out[3] = fixedMulSin((u8)a, half);
    c = fixedMulCos(angle, r2);
    s = fixedMulSin(angle, r2);
    out[4] = out[0] + c;
    out[5] = out[1] + s;
    out[6] = out[2] + c;
    out[7] = out[3] + s;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8004FE24);
extern char *D_8009B6A0;
extern s32 fixedMulCos(s32, s16);
extern s32 fixedMulSin(s32, s16);

static __inline__ void box_4FE24(s16 *p, s32 a, s32 len)
{
    s16 b;
    s32 cy;

    b = (a + 0x140) & 0xff;
    p[0] = fixedMulCos(b, 8);
    p[1] = fixedMulSin(b, 8);
    b = (a + 0xc0) & 0xff;
    p[2] = fixedMulCos(b, 8);
    p[3] = fixedMulSin(b, 8);
    b = fixedMulCos(a, len);
    cy = fixedMulSin(a, len);
    p[4] = p[0] + b;
    p[6] = p[2] + b;
    p[5] = p[1] + cy;
    p[7] = p[3] + cy;
}

void func_8004FE24(char *o, s16 dx, s16 dy)
{
    char *p = D_8009B6A0;
    char *r;
    char *q1;
    char *q2;
    char *q3;
    char *q4;
    char *q5;
    char *q6;
    s16 a;

    switch (*(s8 *)((u8 *)p + 0xc)) {
    case 1:
        a = (*(u16 *)((u8 *)o + 0xaa) + 0x80) & 0xff;
        *(u16 *)((u8 *)p + 0x3c) = a;
        box_4FE24((s16 *)(p + 0x10), a, *(u16 *)((u8 *)p + 0x30));
        q1 = D_8009B6A0;
        *(s16 *)((u8 *)q1 + 0x34) = dx;
        *(s16 *)((u8 *)q1 + 0x36) = dy;
        *(s16 *)((u8 *)q1 + 0x10) += dx;
        *(s16 *)((u8 *)q1 + 0x14) += dx;
        *(s16 *)((u8 *)q1 + 0x18) += dx;
        *(s16 *)((u8 *)q1 + 0x1c) += dx;
        *(s16 *)((u8 *)q1 + 0x12) += dy;
        *(s16 *)((u8 *)q1 + 0x16) += dy;
        *(s16 *)((u8 *)q1 + 0x1a) += dy;
        *(s16 *)((u8 *)q1 + 0x1e) += dy;
        break;
    case 2:
        a = (*(u16 *)((u8 *)o + 0xaa) + 0x80) & 0xff;
        *(u16 *)((u8 *)p + 0x3e) = a;
        box_4FE24((s16 *)(p + 0x20), a, *(u16 *)((u8 *)p + 0x32));
        q2 = D_8009B6A0;
        a = *(u8 *)((u8 *)q2 + 0x3c);
        *(s16 *)((u8 *)q2 + 0x38) = dx;
        *(s16 *)((u8 *)q2 + 0x3a) = dy;
        *(s16 *)((u8 *)q2 + 0x20) += dx;
        *(s16 *)((u8 *)q2 + 0x24) += dx;
        *(s16 *)((u8 *)q2 + 0x28) += dx;
        *(s16 *)((u8 *)q2 + 0x2c) += dx;
        *(s16 *)((u8 *)q2 + 0x22) += dy;
        *(s16 *)((u8 *)q2 + 0x26) += dy;
        *(s16 *)((u8 *)q2 + 0x2a) += dy;
        *(s16 *)((u8 *)q2 + 0x2e) += dy;
        box_4FE24((s16 *)(q2 + 0x10), a, *(u16 *)((u8 *)q2 + 0x30));
        q3 = D_8009B6A0;
        *(s16 *)((u8 *)q3 + 0x10) += *(s16 *)((u8 *)q3 + 0x34);
        *(s16 *)((u8 *)q3 + 0x14) += *(s16 *)((u8 *)q3 + 0x34);
        *(s16 *)((u8 *)q3 + 0x18) += *(s16 *)((u8 *)q3 + 0x34);
        *(s16 *)((u8 *)q3 + 0x1c) += *(s16 *)((u8 *)q3 + 0x34);
        *(s16 *)((u8 *)q3 + 0x12) += *(s16 *)((u8 *)q3 + 0x36);
        *(s16 *)((u8 *)q3 + 0x16) += *(s16 *)((u8 *)q3 + 0x36);
        *(s16 *)((u8 *)q3 + 0x1a) += *(s16 *)((u8 *)q3 + 0x36);
        *(s16 *)((u8 *)q3 + 0x1e) += *(s16 *)((u8 *)q3 + 0x36);
        break;
    case 3:
        a = (*(u16 *)((u8 *)o + 0xaa) + 0x80) & 0xff;
        *(u16 *)((u8 *)p + 0x3c) = a;
        box_4FE24((s16 *)(p + 0x10), a, *(u16 *)((u8 *)p + 0x30));
        q4 = D_8009B6A0;
        a = *(u8 *)((u8 *)q4 + 0x3e);
        *(s16 *)((u8 *)q4 + 0x34) = dx;
        *(s16 *)((u8 *)q4 + 0x36) = dy;
        *(s16 *)((u8 *)q4 + 0x10) += dx;
        *(s16 *)((u8 *)q4 + 0x14) += dx;
        *(s16 *)((u8 *)q4 + 0x18) += dx;
        *(s16 *)((u8 *)q4 + 0x1c) += dx;
        *(s16 *)((u8 *)q4 + 0x12) += dy;
        *(s16 *)((u8 *)q4 + 0x16) += dy;
        *(s16 *)((u8 *)q4 + 0x1a) += dy;
        *(s16 *)((u8 *)q4 + 0x1e) += dy;
        box_4FE24((s16 *)(q4 + 0x20), a, *(u16 *)((u8 *)q4 + 0x32));
        q5 = D_8009B6A0;
        *(s16 *)((u8 *)q5 + 0x20) += *(s16 *)((u8 *)q5 + 0x38);
        *(s16 *)((u8 *)q5 + 0x24) += *(s16 *)((u8 *)q5 + 0x38);
        *(s16 *)((u8 *)q5 + 0x28) += *(s16 *)((u8 *)q5 + 0x38);
        *(s16 *)((u8 *)q5 + 0x2c) += *(s16 *)((u8 *)q5 + 0x38);
        *(s16 *)((u8 *)q5 + 0x22) += *(s16 *)((u8 *)q5 + 0x3a);
        *(s16 *)((u8 *)q5 + 0x26) += *(s16 *)((u8 *)q5 + 0x3a);
        *(s16 *)((u8 *)q5 + 0x2a) += *(s16 *)((u8 *)q5 + 0x3a);
        *(s16 *)((u8 *)q5 + 0x2e) += *(s16 *)((u8 *)q5 + 0x3a);
        break;
    default:
        a = (*(u16 *)((u8 *)o + 0xaa) + 0x80) & 0xff;
        r = D_8009B6A0;
        *(u16 *)((u8 *)r + 0x3c) = a;
        box_4FE24((s16 *)(r + 0x10), a, *(u16 *)((u8 *)r + 0x30));
        q6 = D_8009B6A0;
        *(s16 *)((u8 *)q6 + 0x10) = *(s16 *)((u8 *)q6 + 0x14) = *(s16 *)((u8 *)q6 + 0x18) = *(s16 *)((u8 *)q6 + 0x1c) = 0;
        *(s16 *)((u8 *)q6 + 0x12) = *(s16 *)((u8 *)q6 + 0x16) = *(s16 *)((u8 *)q6 + 0x1a) = *(s16 *)((u8 *)q6 + 0x1e) = 0;
        *(s16 *)((u8 *)q6 + 0x20) = *(s16 *)((u8 *)q6 + 0x24) = *(s16 *)((u8 *)q6 + 0x28) = *(s16 *)((u8 *)q6 + 0x2c) = 0;
        *(s16 *)((u8 *)q6 + 0x22) = *(s16 *)((u8 *)q6 + 0x26) = *(s16 *)((u8 *)q6 + 0x2a) = *(s16 *)((u8 *)q6 + 0x2e) = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", decreaseObjectTimer);
void decreaseObjectTimer(u8* self, u8 arg1)
{
    s16 v = *(s16*)(self + 0x98);

    if (v != 0) {
        v -= arg1;
        *(s16*)(self + 0x98) = v;
        if (v <= 0) {
            *(s16*)(self + 0x98) = 0;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800505E8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultA);
s32 resolveHitResultA(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 1:
    case 7:
        ret = 1;
        break;
    case 4:
    case 5:
    case 10:
        ret = 1;
        arg0[0x6A] = 1;
        arg0[0] = 2;
        *(s16*)(arg0 + 0xA8) = 0x4FF;
        break;
    case 0:
    case 3:
    case 9:
        ret = 2;
        break;
    case 13:
        arg1[0x68] = 0;
        ret = -1;
        break;
    case 6:
    case 11:
    case 12:
        ret = 2;
        arg0[0x6A] = 1;
        arg0[0] = 2;
        *(s16*)(arg0 + 0xA8) = 0x4FF;
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        break;
    }
    if (ret < 0) {
        ret = 0;
    } else {
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        if ((arg1[0x1C] & 0x7F) == 4) {
            playSFX(6);
        } else {
            playSFX(7);
        }
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultB);
s32 resolveHitResultB(u8* arg0, u8* arg1) {
    s32 ret;

    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 1:
    case 4:
        ret = 1;
        break;
    case 5:
        ret = 2;
        break;
    case 7:
    case 10:
        ret = 3;
        break;
    case 11:
        ret = 4;
        break;
    case 3:
    case 6:
    case 9:
    case 12:
        ret = 5;
        break;
    case 0:
        ret = 6;
        break;
    case 13:
        ret = 7;
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x68] = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        playSFX(6);
        break;
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultC);
s32 resolveHitResultC(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 1:
    case 4:
    case 5:
    case 7:
    case 10:
        ret = 1;
        break;
    case 13:
        if ((arg1[0x1C] & 0x7F) == 4) {
            arg1[0x68] = 0;
            return ret;
        }
    case 0:
    case 3:
    case 6:
    case 9:
    case 11:
    case 12:
        ret = 2;
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x68] = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        break;
    }
    func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
    if ((arg1[0x1C] & 0x7F) == 4) {
        playSFX(6);
    } else {
        playSFX(7);
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultD);
s32 resolveHitResultD(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 0:
        ret = 2;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 3:
    case 6:
    case 9:
    case 11:
    case 12:
    case 13:
        ret = 2;
    case 1:
    case 4:
    case 5:
    case 7:
    case 10:
        playSFX(7);
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x68] = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        playSFX(6);
        break;
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultE);
s32 resolveHitResultE(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 0:
        ret = 2;
        *(s16*)(arg1 + 0x98) = 0;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 1:
    case 4:
    case 5:
    case 7:
    case 10:
        playSFX(7);
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 3:
    case 6:
    case 9:
    case 11:
    case 12:
    case 13:
        ret = 2;
        playSFX(7);
        *(s16*)(arg1 + 0x98) = 0;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x68] = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        playSFX(6);
        break;
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultF);
s32 resolveHitResultF(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 1:
    case 4:
        playSFX(7);
        if ((*(s16*)(arg1 + 0x98)) != 0) {
            (*(s16*)(arg1 + 0x98)) -= 1;
        }
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        arg1[0x68] = 0;
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        playSFX(6);
        break;
    case 3:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        playSFX(7);
        (*(s16*)(arg1 + 0x98)) = 0;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 5:
        playSFX(7);
        (*(s16*)(arg1 + 0x98)) -= 2;
        if ((*(s16*)(arg1 + 0x98)) < 0) {
            (*(s16*)(arg1 + 0x98)) = 0;
        }
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 0:
        (*(s16*)(arg1 + 0x98)) = 0;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", resolveHitResultG);
s32 resolveHitResultG(u8* arg0, u8* arg1) {
    s32 ret;

    ret = 1;
    arg1[0x68] = 1;
    arg1[0x9E] = 0;
    switch (func_800505E8(arg0, arg1)) {
    case 9:
    case 12:
        playSFX(7);
    case 0:
        ret = 2;
        (*(s16*)(arg1 + 0x98)) = 0;
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 1:
    case 4:
    case 5:
        playSFX(6);
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 2:
    case 8:
        ret = 0;
        arg1[0x9E] = 1;
        arg1[0x9F] = 0;
        arg1[0x68] = 0;
        func_800224FC(1, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        playSFX(6);
        break;
    case 3:
    case 6:
    case 7:
    case 10:
    case 13:
        playSFX(7);
        if ((*(s16*)(arg1 + 0x98)) != 0) {
            (*(s16*)(arg1 + 0x98)) -= 1;
        }
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    case 11:
        playSFX(7);
        (*(s16*)(arg1 + 0x98)) -= 2;
        if ((*(s16*)(arg1 + 0x98)) < 0) {
            (*(s16*)(arg1 + 0x98)) = 0;
        }
        func_800224FC(0, *(s16*)(arg0 + 0x12), *(s16*)(arg0 + 0x16), *(s16*)(arg0 + 0x1A));
        break;
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", boxesOverlap);
s32 boxesOverlap(u8* arg0, u8* arg1) {
    u8* a = arg0;
    u8* b = arg1;
    s32 d;
    u16 dx;
    u16 w;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return 0;
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    w = *(u16*)(a + 0x6C) + *(u16*)(b + 0x6C);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x6E) + *(s16*)(b + 0x6E) < d) {
        return 0;
    }
    dx = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w = *(u16*)(a + 0x70) + *(u16*)(b + 0x70);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x72) + *(s16*)(b + 0x72) < d) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051090);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051284);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051488);
s32 func_80051488(GameObject *o, GameObject *e)
{
    s16 dx, dy, sx, sy, ax, ay;
    if ((u16)(o->d->p.whole - e->d->p.whole + 45) > 90)
        return -1;
    sx = e->hitOffsetX + o->hitOffsetX;
    dx = o->h->p.whole - e->h->p.whole;
    if ((u16)(dx + sx) > e->hitWidth + o->hitWidth)
        return -1;
    dy = o->y.p.whole - e->y.p.whole;
    sy = e->hitOffsetY + o->hitOffsetY;
    if ((u16)(dy + sy) > o->hitHeight + e->hitHeight)
        return -1;
    ax = dx;
    if (dx < 0)
        dx = -dx;
    else
        sx = (e->hitWidth - e->hitOffsetX) + (o->hitWidth - o->hitOffsetX);
    ay = dy;
    if (dy < 0)
        dy = -dy;
    else
        sy = (e->hitHeight - e->hitOffsetY) + (o->hitHeight - o->hitOffsetY);
    if (sx - dx < sy - dy)
        return ax >= 0;
    if (ay <= 0)
        return 3;
    return 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051604);
typedef struct { char p0[2]; u16 s2; } H_51604;
typedef struct {
    char p00[0x16]; u16 s16;
    char p1[0x2e - 0x18]; u16 s2e;
    char p1b[0x40 - 0x30]; H_51604 *h40; H_51604 *h44;
    char p3[0x6c - 0x48]; u16 s6c; s16 s6e; u16 s70; s16 s72;
    char p6[0xac - 0x74]; u8 bac;
} TO_51604;

s32 func_80051604(TO_51604 *a, TO_51604 *b)
{
    s16 w, k, sw, dx, dy, sh, dxs, dys, ex, ey;

    k = a->h44->s2 - b->h44->s2 + 0x2d;
    if ((u16)k >= 0x5b) return -1;
    if (b->s2e & 1) w = b->s6e - b->s6c; else w = b->s6c;
    k = a->bac == 1;
    sw = k + (w + a->s6c);
    dx = a->h40->s2 - b->h40->s2;
    if ((u16)(dx + sw) > b->s6e + a->s6e + k * 2) return -1;
    dy = a->s16 - b->s16;
    sh = b->s70 + a->s70;
    if ((u16)(dy + sh) > a->s72 + b->s72) return -1;
    dxs = dx;
    if (dx < 0) {
        dx = -dx;
    } else {
        if (b->s2e & 1) w = b->s6c; else w = b->s6e - b->s6c;
        sw = k + (w + (a->s6e - a->s6c));
    }
    ex = sw - dx;
    dys = dy;
    if (dy < 0) {
        dy = -dy;
    } else {
        sh = (a->s72 - a->s70) + (b->s72 - b->s70);
    }
    ey = sh - dy;
    if (dys < 6) {
        if (ex >= ey) return 2;
    } else if (ex >= ey) {
        goto three;
    }
    return dxs >= 0;
three:
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051804);
typedef struct { char p0[2]; u16 s2; } H_51804;
typedef struct {
    char p0[0x14]; u16 s14; u16 s16;
    char p1[0x40 - 0x18]; H_51804 *h40; H_51804 *h44;
    char p2[0x69 - 0x48]; u8 b69;
    char p2b[0x6c - 0x6a]; u16 s6c; s16 s6e; u16 s70; s16 s72;
    char p3[0x7e - 0x74]; s16 s7e;
    char p4[0x9c - 0x80]; u8 b9c;
    char p5[0xa6 - 0x9d]; u8 ba6;
    char p6[0xb0 - 0xa7]; u16 sb0;
} TO_51804;

s32 func_80051804(TO_51804 *a, TO_51804 *b)
{
    char pad;
    s16 dx;
    s16 wx;
    s16 px;
    s16 dy;
    s16 d;
    s32 hy;
    s16 cx;
    s32 di;

    if ((u16)(a->h44->s2 - b->h44->s2 + 0x2d) >= 0x5b) return 0;
    wx = b->s6c + a->s6c;
    px = wx;
    dx = a->h40->s2 - b->h40->s2;
    if ((u16)(dx + wx) > b->s6e + a->s6e) return 0;
    di = a->s16 - b->s16;
    d = di;
    hy = b->s70 + a->s70;
    dy = d;
    if ((u16)(d + hy) > a->s72 + b->s72) return 0;
    if (((u32)(hy - -di) & 0xffff) < 0xc) {
        if (a->b9c & 1) return 0;
        a->sb0 = 0;
        goto land;
    }
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = (b->s6e - b->s6c) + (a->s6e - a->s6c);
        cx = px;
    }
    if ((u16)(cx - dx) < 4) {
        a->h40->s2 = b->h40->s2 + px;
        if (px < 0) a->ba6 = 2; else a->ba6 = 3;
        return 2;
    }
    if (dy <= 0) {
        if (a->b9c & 1) return 0;
        a->sb0 = 0;
    land:
        {
            u16 t = b->s70;
            u16 w = b->s16;
            a->s14 = 0;
            a->b69 = 1;
            a->s7e = 0;
            a->s16 = w - (t + a->s70);
        }
        b->b69 = 3;
        if (a->b9c & 2) b->b69 = 1;
        return 1;
    }
    a->s16 = b->s16 + ((b->s72 - b->s70) + (a->s72 - a->s70));
    if (a->s7e < 0) a->s7e = 0;
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051A18);
s32 func_80051A18(GameObject *a, GameObject *b)
{
    s16 s, dx, ax, w, off, d0, sy;
    s32 dy, d; u16 t;
    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) > 0x5a) return 0;
    s = b->hitOffsetX + a->hitOffsetX;
    dx = a->h->p.whole - b->h->p.whole;
    off = s;
    ax = dx;
    if ((u16)(dx + s) > b->hitWidth + a->hitWidth) return 0;
    d = (u16)a->y.p.whole - (u16)b->y.p.whole;
    t = d + (b->hitOffsetY + a->hitOffsetY);
    dy = d;
    if ((u16)t > a->hitHeight + b->hitHeight) return 0;
    w = off;
    d0 = ax;
    if (dx < 0) {
        ax = -dx;
        off = -s;
    } else {
        off = (b->hitWidth - b->hitOffsetX) + (a->hitWidth - a->hitOffsetX);
        w = off;
    }
    if ((u16)(w - ax) < 4) {
        a->h->p.whole = b->h->p.whole + off;
        if (off < 0) a->unkA6 = 2; else a->unkA6 = 3;
        return 2;
    }
    sy = dy;
    if (sy <= 0) {
        if (a->unk9C & 1) {
            a->h->p.whole = b->h->p.whole + off;
            return 2;
        }
        a->y.p.whole = b->y.p.whole - (b->hitOffsetY + a->hitOffsetY);
        a->y.p.frac = 0;
        a->touchFlag = 1;
        b->touchFlag = 1;
        if (d0 >= 0) {
            a->unkBE = 8;
            a->unkB0 = 2;
        } else {
            a->unkBE = 9;
            a->unkB0 = -2;
        }
        return 1;
    }
    if ((b->hitHeight - b->hitOffsetY) + (a->hitHeight - a->hitOffsetY) - sy < 5) {
        a->y.p.whole = b->y.p.whole + ((b->hitHeight - b->hitOffsetY) + (a->hitHeight - a->hitOffsetY));
        if (a->velY < 0) {
            a->velY = 0;
            b->touchFlag = 1;
            if (b->type == 5) b->touchFlag = 4;
        }
        return 3;
    }
    a->h->p.whole = b->h->p.whole + off;
    if (off < 0) a->unkA6 = 2; else a->unkA6 = 3;
    return 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", pushOutOfBoxX);
s32 pushOutOfBoxX(u8* arg0, u8* arg1) {
    u8* a = arg0;
    u8* b = arg1;
    s16 push;
    s16 dx;
    u16 dy;
    u16 w;
    u16 w2;
    u16 bw;
    u16 aw;
    s16 bl;
    s16 al;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return 0;
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    bw = *(u16*)(b + 0x6C);
    aw = *(u16*)(a + 0x6C);
    w = bw + aw;
    bl = *(s16*)(b + 0x6E);
    al = *(s16*)(a + 0x6E);
    if ((u16)(dx + w) > bl + al) {
        return 0;
    }
    dy = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w2 = *(u16*)(b + 0x70) + *(u16*)(a + 0x70);
    if ((u16)(dy + w2) > *(s16*)(a + 0x72) + *(s16*)(b + 0x72)) {
        return 0;
    }
    if (dx < 0) {
        push = -w;
    } else {
        push = (bl - bw) + (al - aw);
    }
    (*(u16**)(a + 0x40))[1] = (*(u16**)(b + 0x40))[1] + push;
    if (push < 0) {
        a[0xA6] = 2;
    } else {
        a[0xA6] = 3;
    }
    return 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051DA4);
typedef struct { char p0[2]; u16 s2; } H_51DA4;
typedef struct {
    char p00[0x14]; s16 s14; u16 s16;
    char p1[0x40 - 0x18]; H_51DA4 *h40; H_51DA4 *h44;
    char p2[0x69 - 0x48]; char b69;
    char p3[0x6c - 0x6a]; u16 s6c; s16 s6e; u16 s70; s16 s72;
    char p4[0x7e - 0x74]; s16 s7e;
    char p5[0x9c - 0x80]; u8 b9c;
    char p6[0xb0 - 0x9d]; s16 sb0;
} TO_51DA4;

s32 func_80051DA4(TO_51DA4 *a, TO_51DA4 *b)
{
    char pad;
    s32 t;
    if ((u16)(a->h44->s2 - b->h44->s2 + 0x2d) >= 0x5b) return 0;
    if ((u16)(a->h40->s2 - b->h40->s2 + (b->s6c + a->s6c)) > (b->s6e + a->s6e)) return 0;
    t = a->s16 - b->s16;
    if ((u16)(t + (b->s70 + a->s70)) > (a->s72 + b->s72)) return 0;
    if ((t << 16) <= 0) {
        if (a->b9c & 1) return 0;
        a->sb0 = 0;
        a->s16 = b->s16 - (b->s70 + a->s70);
        a->s14 = 0;
        a->b69 = 1;
        a->s7e = 0;
        b->b69 = 1;
        return 1;
    }
    a->s16 = b->s16 + ((b->s72 - b->s70) + (a->s72 - a->s70));
    if (a->s7e < 0) a->s7e = 0;
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051EE0);
typedef struct { s16 x, y; } Off_51EE0;

void func_80051EE0(GameObject *o, GameObject *e)
{
    extern Off_51EE0 D_8007EDD0[];
    s16 dx, dy, sx, px, cx, ax;
    s16 tx, ty;
    Off_51EE0 *t;
    s16 w;
    if ((u16)(o->d->p.whole - e->d->p.whole + 45) > 90)
        return;
    { s16 *u = &D_8007EDD0[e->unkC].x;
    px = sx = e->hitOffsetX + o->hitOffsetX + 8;
    tx = *u++;
    dx = o->h->p.whole - (e->h->p.whole + tx);
    ty = *u; }
    if ((u16)(dx + sx) > e->hitWidth + 16 + o->hitWidth)
        return;
    {
        u16 c = ((o->y.p.whole - (e->y.p.whole + ty)) - 8) + (e->hitOffsetY + o->hitOffsetY);
        dy = o->y.p.whole - (e->y.p.whole + ty);
        if (c > o->hitHeight + e->hitHeight - 16)
            return;
    }
    cx = px;
    ax = dx;
    if (dx < 0) {
        dx = -dx;
        px = -sx;
    } else {
        px = (e->hitWidth - e->hitOffsetX) + (s16)(o->hitWidth - o->hitOffsetX + 8);
        cx = px;
    }
    if ((u16)(cx - dx) < 4) {
        o->h->p.whole = px + (e->h->p.whole + tx);
        return;
    }
    if (dy < 5) {
        if (o->unk9C & 1) return;
        w = e->y.p.whole + ty + 8;
        o->y.p.whole = w - (e->hitOffsetY + o->hitOffsetY);
        o->y.p.frac = 0;
        o->touchFlag = 1;
        e->touchFlag = 1;
        if (ax >= 0) {
            o->unkBE = 8;
            o->unkB0 = 2;
        } else {
            o->unkBE = 9;
            o->unkB0 = -2;
        }
        return;
    }
    o->y.p.whole = (e->y.p.whole + ty) + ((e->hitHeight - e->hitOffsetY) + (o->hitHeight - o->hitOffsetY));
    if (o->velY < 0) o->velY = 0;
}

static inline u8 boxesOverlapInline(u8* p0, u8* p1) {
    u8* a = p0;
    u8* b = p1;
    s32 d;
    u16 dx;
    u16 w;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return 0;
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    w = *(u16*)(a + 0x6C) + *(u16*)(b + 0x6C);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x6E) + *(s16*)(b + 0x6E) < d) {
        return 0;
    }
    dx = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w = *(u16*)(a + 0x70) + *(u16*)(b + 0x70);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x72) + *(s16*)(b + 0x72) < d) {
        return 0;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", onOverlapSetReaction4);
void onOverlapSetReaction4(u8* arg0, u8* arg1) {
    arg1[0x69] = 0;
    if (boxesOverlapInline(arg0, arg1) & 1) {
        if (arg1[2] != 0x26) {
            arg0[0xA0] = 4;
        }
        arg1[0x69] = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", onOverlapSetReaction3);
void onOverlapSetReaction3(u8* arg0, u8* arg1) {
    arg1[0x69] = 0;
    if (boxesOverlapInline(arg0, arg1) & 1) {
        arg0[0xA8] = 3;
        arg0[0xA0] = 1;
        arg1[0x69] = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800522B4);
void func_800522B4(void)
{
    func_80051090();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", tryAttachObjectOnResult3);
void tryAttachObjectOnResult3(u8* arg0, u8* arg1) {
    s16 ret;

    ret = func_80051488(arg0, arg1);
    if (ret == -1) {
        return;
    }
    if (ret == 3 && arg0[0xAC] == 1) {
        arg1[0] = 2;
        arg1[4] = 2;
        arg1[5] = 0;
        arg1[6] = 0;
        arg1[0x69] = 0;
        *(u8**)(arg0 + 0xE4) = arg1;
        arg0[0xAC] = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", onOverlapConsumeObject);
void onOverlapConsumeObject(u8* arg0, u8* arg1) {
    if (boxesOverlapInline(arg0, arg1) & 1) {
        arg0[0x6A] = 1;
        arg1[0] = 4;
        arg1[4] = 2;
        arg1[5] = 0;
        arg1[6] = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005242C);
extern u16 D_1F80019E;
s32 func_8005242C(GameObject *a, GameObject *b)
{
    s16 dy; s16 sx; s16 ad; s16 dx;
    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return -1;
    sx = *(u16 *)((u8 *)b + 0x6c) + *(u16 *)((u8 *)a + 0x6c);
    dx = *(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2);
    if ((u16)(dx + sx) > *(s16 *)((u8 *)b + 0x6e) + *(s16 *)((u8 *)a + 0x6e))
        return -1;
    {
        u16 c = (*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)b + 0x70) + *(u16 *)((u8 *)a + 0x70));
        dy = *(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16);
        if (c > *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72))
            return -1;
    }
    D_1F80019E = 0;
    ad = dx;
    if (dx < 0)
        dx = -dx;
    else
        sx = (*(u16 *)((u8 *)b + 0x6e) - *(u16 *)((u8 *)b + 0x6c)) + (*(u16 *)((u8 *)a + 0x6e) - *(u16 *)((u8 *)a + 0x6c));
    if ((u16)(sx - dx) < 4)
        return (s16)ad >= 0;
    if ((s16)dy <= 0)
        return 3;
    return 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", boxesOverlapSide);
s32 boxesOverlapSide(u8* arg0, u8* arg1) {
    u8* a = arg0;
    u8* b = arg1;
    s32 d;
    s16 dx;
    u16 dy;
    u16 w;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return -1;
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    w = *(u16*)(b + 0x6C) + *(u16*)(a + 0x6C);
    if ((u16)(dx + w) > *(s16*)(b + 0x6E) + *(s16*)(a + 0x6E)) {
        return -1;
    }
    dy = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w = *(u16*)(a + 0x70) + *(u16*)(b + 0x70);
    if ((u16)(dy + w) > *(s16*)(a + 0x72) + *(s16*)(b + 0x72)) {
        return -1;
    }
    *(s16*)0x1F80019E = 0;
    if (dx < 0) {
        return 0;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", boxesOverlapSigned);
s32 boxesOverlapSigned(u8* arg0, u8* arg1) {
    u8* a = arg0;
    u8* b = arg1;
    s32 d;
    u16 dx;
    u16 w;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return -1;
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    w = *(u16*)(b + 0x6C) + *(u16*)(a + 0x6C);
    if ((u16)(dx + w) > *(s16*)(b + 0x6E) + *(s16*)(a + 0x6E)) {
        return -1;
    }
    dx = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w = *(u16*)(a + 0x70) + *(u16*)(b + 0x70);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x72) + *(s16*)(b + 0x72) < d) {
        return -1;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", boxesOverlapFlipAware);
s32 boxesOverlapFlipAware(u8* arg0, u8* arg1) {
    u8* a = arg0;
    u8* b = arg1;
    s32 d;
    u16 dx;
    u16 w;
    u16 off;

    if ((u16)((*(u16**)(a + 0x44))[1] - (*(u16**)(b + 0x44))[1] + 0x2D) >= 0x5B) {
        return -1;
    }
    if (*(u16*)(b + 0x2E) & 1) {
        off = *(u16*)(b + 0x6E) - *(u16*)(b + 0x6C);
    } else {
        off = *(u16*)(b + 0x6C);
    }
    dx = (*(u16**)(a + 0x40))[1] - (*(u16**)(b + 0x40))[1];
    w = off + *(u16*)(a + 0x6C);
    if ((u16)(dx + w) > *(s16*)(b + 0x6E) + *(s16*)(a + 0x6E)) {
        return -1;
    }
    dx = *(u16*)(a + 0x16) - *(u16*)(b + 0x16);
    w = *(u16*)(b + 0x70) + *(u16*)(a + 0x70);
    d = (u16)(dx + w);
    if (*(s16*)(a + 0x72) + *(s16*)(b + 0x72) < d) {
        return -1;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800527C8);
typedef struct { u16 x, y; } P2_527C8;
extern P2_527C8 D_8007EDD0[];

void func_800527C8(GameObject *o, GameObject *q)
{
    P2_527C8 *t;
    s32 tx;
    u16 ty;
    s32 n;
    s32 s;
    u16 b0;

    if ((u16)(o->d->p.whole - q->d->p.whole + 0x2d) > 0x5a) return;
    { u16 *u = &D_8007EDD0[q->unkC].x;
    b0 = o->hitOffsetX;
    tx = *u++;
    ty = *u; }
    if ((u16)(o->h->p.whole - (q->h->p.whole + tx) + (q->hitOffsetX + b0)) > q->hitWidth + o->hitWidth) return;
    n = 1;
    if ((u16)(o->y.p.whole - (q->y.p.whole + ty) - 4 + (q->hitOffsetY + o->hitOffsetY)) > o->hitHeight + q->hitHeight - 4) return;
    q->unk68 = 1;
    q->unk9E = 0;
    switch (func_800505E8(o, q, b0)) {
    case 1: case 7:
        n = 1;
        break;
    case 4: case 5: case 10:
        n = 1;
        o->unk6A = 1;
        o->active = 2;
        o->unkA8 = 0x4ff;
        break;
    case 0: case 3: case 9:
        n = 2;
        break;
    case 13:
        q->unk68 = 0;
        n = -1;
        break;
    case 6: case 11: case 12:
        n = 2;
        o->unk6A = 1;
        o->active = 2;
        o->unkA8 = 0x4ff;
        break;
    case 2: case 8:
        n = 0;
        q->unk9E = 1;
        q->unk9F = 0;
        break;
    }
    if (n >= 0) {
        func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        s = 7;
        if ((q->category & 0x7f) == 4) s = 6;
        playSFX(s);
    }
    D_1F80019E = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800529A8);
extern u16 D_1F80019E;
extern s32 func_800505E8(GameObject *, GameObject *);
extern void func_800224FC(s32, s32, s32, s32);
extern void playSFX(s32);

static __inline__ s16 hit_529A8(GameObject *a, GameObject *b)
{
    s16 dx;
    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return -1;
    dx = *(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2);
    if ((u16)(dx + (*(u16 *)((u8 *)b + 0x6c) + *(u16 *)((u8 *)a + 0x6c))) > *(s16 *)((u8 *)b + 0x6e) + *(s16 *)((u8 *)a + 0x6e))
        return -1;
    if ((u16)((*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)a + 0x70) + *(u16 *)((u8 *)b + 0x70))) > *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72))
        return -1;
    D_1F80019E = 0;
    if (dx < 0)
        return 0;
    return 1;
}

static __inline__ s32 react_529A8(GameObject *a, GameObject *b)
{
    s32 r = 1;
    b->unk68 = 1;
    b->unk9E = 0;
    switch (func_800505E8(a, b)) {
    case 1: case 4: case 5: case 7: case 10:
        r = 1;
        break;
    case 13:
        if ((b->category & 0x7f) == 4) {
            b->unk68 = 0;
            return r;
        }
    case 0: case 3: case 6: case 9: case 11: case 12:
        r = 2;
        break;
    case 2: case 8:
        r = 0;
        b->unk68 = 0;
        b->unk9E = 1;
        b->unk9F = 0;
        break;
    }
    func_800224FC(1, a->x.p.whole, a->y.p.whole, a->z.p.whole);
    playSFX((b->category & 0x7f) == 4 ? 6 : 7);
    return r;
}

void func_800529A8(GameObject *a, GameObject *b)
{
    s16 h;

    h = hit_529A8(a, b);
    if (h < 0)
        return;
    if (react_529A8(a, b) && a->type != 10) {
        s16 t = a->unk98;
        b->animFrame = h & 1;
        b->unk68 = t;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052B88);
static __inline__ s16 hit_52B88(GameObject *a, GameObject *b)
{
    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return -1;
    if ((u16)((*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2)) + (*(u16 *)((u8 *)b + 0x6c) + *(u16 *)((u8 *)a + 0x6c))) > *(s16 *)((u8 *)b + 0x6e) + *(s16 *)((u8 *)a + 0x6e))
        return -1;
    if ((u16)((*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)a + 0x70) + *(u16 *)((u8 *)b + 0x70))) > *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72))
        return -1;
    return 1;
}

static __inline__ s32 spawn_52B88(GameObject *a, GameObject *b)
{
    GameObject *o = allocObjectLayer3();

    if (o) {
        o->active = 2;
        o->type = 0x5b;
        o->unk90 = (s32)a;
        o->unk94 = (s32)b;
        b->active = 5;
        b->h->p.whole = a->h->p.whole + (D_1F80019E & 3) * 4;
        b->y.p.whole = a->y.p.whole;
        b->d->p.whole = a->d->p.whole;
        return 1;
    }
    return 0;
}

void func_80052B88(GameObject *a, GameObject *b)
{
    u16 v, f;
    s16 t;

    if (hit_52B88(a, b) >= 0) {
        resolveHitResultD(a, b);
        t = a->type;
        if ((u8)t == 10)
            return;
        if ((u32)(t - 5) < 3 && spawn_52B88(a, b)) {
        } else {
            b->unk68 = 1;
            if (a->type == 1) {
                v = a->animFrame & 1;
            } else {
                f = a->animFrame;
                if (f < 6)
                    v = f & 1;
                else
                    v = 2;
            }
            b->animFrame = v;
        }
        D_1F80019E = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052D5C);
extern void func_8011EDBC(void);
extern void func_800E92D4(s32, s32, s32, s32);

static __inline__ s16 hit_52D5C(GameObject *a, GameObject *b)
{
    u16 off;

    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return -1;
    if (b->animFrame & 1) off = *(u16 *)((u8 *)b + 0x6e) - *(u16 *)((u8 *)b + 0x6c);
    else off = *(u16 *)((u8 *)b + 0x6c);
    if ((u16)((*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2)) + (off + *(u16 *)((u8 *)a + 0x6c))) > *(s16 *)((u8 *)b + 0x6e) + *(s16 *)((u8 *)a + 0x6e))
        return -1;
    if ((u16)((*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)b + 0x70) + *(u16 *)((u8 *)a + 0x70))) > *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72))
        return -1;
    return 1;
}

void func_80052D5C(GameObject *a, GameObject *b)
{
    s32 t;

    if (GAME.selectedArea == 3 && b->subtype == 4) {
        func_8011EDBC();
        return;
    }
    if (hit_52D5C(a, b) != -1) {
        b->unk7A = a->animFrame & 1;
        t = resolveHitResultE(a, b);
        if (t != 0) {
            if (t == 1) {
                b->active = 3;
                b->state = 2;
                b->subState = 0;
                b->step = 0;
            } else {
                func_800E92D4(500, b->x.p.whole, b->y.p.whole, b->z.p.whole);
                b->active = 2;
                b->animFrame = 1 - (a->animFrame & 1);
                b->state = 2;
                b->subState = 2;
                b->step = 0;
            }
        }
        D_1F80019E = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052F20);
typedef struct FP_52F20 { u16 frac; s16 whole; } FP_52F20;
typedef struct O_52F20 { u8 b0; char p0[0x10-1]; FP_52F20 a; FP_52F20 y; FP_52F20 b; u8 b1c; char p1[0x40-0x1d];
  FP_52F20 *h; FP_52F20 *d; char p2[0x68-0x48]; u8 b68; char p3; u8 b6a; char p4;
  s16 box0, box1, box2, box3; char p5[42]; u8 b9e, b9f; char p6[0xa8-0xa0]; s16 wa8; } O_52F20;

static __inline__ s16 hit_52F20(O_52F20 *a, O_52F20 *b)
{
    s16 d;
    if ((u16)(a->d->whole - b->d->whole + 0x2d) >= 0x5b)
        return -1;
    d = a->h->whole - b->h->whole;
    if ((u16)(d + (b->box0 + a->box0)) > b->box1 + a->box1)
        return -1;
    if ((u16)((a->y.whole - b->y.whole) + (a->box2 + b->box2)) > a->box3 + b->box3)
        return -1;
    D_1F80019E = 0;
    if (d < 0)
        return 0;
    return 1;
}

void func_80052F20(O_52F20 *a, O_52F20 *b)
{
    s32 r;
    if (hit_52F20(a, b) < 0)
        return;
    r = 1;
    b->b68 = 1;
    b->b9e = 0;
    switch (func_800505E8(a, b)) {
    case 1: case 7:
        r = 1;
        break;
    case 4: case 5: case 10:
        r = 1;
        a->b6a = 1;
        a->b0 = 2;
        a->wa8 = 0x4ff;
        break;
    case 0: case 3: case 9:
        r = 2;
        break;
    case 13:
        b->b68 = 0;
        r = -1;
        break;
    case 6: case 11: case 12:
        r = 2;
        a->b6a = 1;
        a->b0 = 2;
        a->wa8 = 0x4ff;
        break;
    case 2: case 8:
        r = 0;
        b->b9e = 1;
        b->b9f = 0;
        break;
    }
    if (r < 0)
        return;
    func_800224FC(1, a->a.whole, a->y.whole, a->b.whole);
    playSFX((b->b1c & 0x7f) == 4 ? 6 : 7);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800530F0);
extern u16 D_1F80019E;
extern s32 func_800505E8(GameObject *, GameObject *);
extern void func_800224FC(s32, s32, s32, s32);
extern void playSFX(s32);

static __inline__ s16 hit_530F0(GameObject *a, GameObject *b)
{
    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return -1;
    if ((u16)((*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2)) + (*(u16 *)((u8 *)b + 0x6c) + *(u16 *)((u8 *)a + 0x6c))) > *(s16 *)((u8 *)b + 0x6e) + *(s16 *)((u8 *)a + 0x6e))
        return -1;
    if ((u16)((*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)a + 0x70) + *(u16 *)((u8 *)b + 0x70))) > *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72))
        return -1;
    return 1;
}

void func_800530F0(GameObject *a, GameObject *b)
{
    s32 r;

    if (hit_530F0(a, b) >= 0) {
        r = 1;
        b->unk68 = 1;
        b->unk9E = 0;
        switch (func_800505E8(a, b)) {
        case 1:
        case 7:
            r = 1;
            break;
        case 4:
        case 5:
        case 10:
            r = 1;
            a->unk6A = 1;
            a->active = 2;
            a->unkA8 = 0x4ff;
            break;
        case 0:
        case 3:
        case 9:
            r = 2;
            break;
        case 13:
            b->unk68 = 0;
            r = -1;
            break;
        case 6:
        case 11:
        case 12:
            r = 2;
            a->unk6A = 1;
            a->active = 2;
            a->unkA8 = 0x4ff;
            break;
        case 2:
        case 8:
            r = 0;
            b->unk9E = 1;
            b->unk9F = 0;
            break;
        }
        if (r >= 0) {
            func_800224FC(1, a->x.p.whole, a->y.p.whole, a->z.p.whole);
            playSFX((b->category & 0x7f) == 4 ? 6 : 7);
        }
        D_1F80019E = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaActorInit);
void dispatchAreaActorInit(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80124B38();
        break;
    case AREA01_DWARFFOREST:
        func_801233E0();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011EC1C();
        break;
    case AREA04_HAUNTEDMANSION:
        func_8011E254();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005334C);
static __inline__ s16 side_5334C(GameObject *a, GameObject *b)
{
    s16 dx;
    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) >= 0x5b) return -1;
    dx = a->h->p.whole - b->h->p.whole;
    if ((u16)(dx + (b->hitOffsetX + a->hitOffsetX)) > b->hitWidth + a->hitWidth) return -1;
    if ((u16)(a->y.p.whole - b->y.p.whole + (a->hitOffsetY + b->hitOffsetY)) > a->hitHeight + b->hitHeight) return -1;
    D_1F80019E = 0;
    if (dx < 0) return 0;
    return 1;
}
static __inline__ s32 touch_5334C(GameObject *o, GameObject *p)
{
    s32 r;
    r = 1;
    p->unk68 = 1;
    p->unk9E = 0;
    switch (func_800505E8(o, p)) {
    case 1: case 7:
        r = 1;
        break;
    case 4: case 5: case 10:
        r = 1;
        o->unk6A = 1;
        o->active = 2;
        o->unkA8 = 0x4ff;
        break;
    case 0: case 3: case 9:
        r = 2;
        break;
    case 13:
        p->unk68 = 0;
        r = -1;
        break;
    case 6: case 11: case 12:
        r = 2;
        o->unk6A = 1;
        o->active = 2;
        o->unkA8 = 0x4ff;
        break;
    case 2: case 8:
        r = 0;
        p->unk9E = 1;
        p->unk9F = 0;
        break;
    }
    if (r < 0) {
        r = 0;
    } else {
        s32 s;
        func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        s = 7;
        if ((p->category & 0x7f) == 4) s = 6;
        playSFX(s);
    }
    return r;
}

void func_8005334C(GameObject *o, GameObject *p)
{
    s16 s;
    GameObject *q, *q2;
    u8 v;
    s = side_5334C(o, p);
    if (s < 0) return;
    if (touch_5334C(o, p) == 0) return;
    switch (p->subtype) {
    case 0:
        q = (GameObject *)p->unk94;
        q2 = (GameObject *)q->unk94;
        break;
    case 1:
        q = (GameObject *)p->unk90;
        q2 = (GameObject *)p->unk94;
        break;
    }
    v = s | 2;
    p->unk68 = v;
    q->unk68 = v;
    q2->unk68 = v;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaActorUpdate);
void dispatchAreaActorUpdate(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_801248A0();
        break;
    case AREA04_HAUNTEDMANSION:
        func_8011E3E4();
        break;
    case AREA10_DEEPJUNGLE:
        func_8011FC7C();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", tryAttachObjectOnOverlap);
void tryAttachObjectOnOverlap(u8* arg0, u8* arg1) {
    s16 ret;

    ret = func_80051090(arg0, arg1);
    if (ret != 0) {
        if (arg0[0xAC] == 1 && ret == 1) {
            arg1[0] = 2;
            arg1[4] = 2;
            arg1[5] = 1;
            arg1[6] = 0;
            arg1[0x69] = 0;
            *(u8**)(arg0 + 0xE4) = arg1;
            arg0[0xAC] = 2;
        }
        *(s16*)0x1F80019E = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005368C);
#define U(p, o) (*(u16 *)((p) + (o)))
#define S(p, o) (*(s16 *)((p) + (o)))

static __inline__ s16 HIT_5368C(u8 *a, u8 *b)
{
    if ((u16)(U(*(u8 **)(a + 0x44), 2) - U(*(u8 **)(b + 0x44), 2) + 0x2d) >= 0x5b)
        return 0;
    if ((u16)(U(*(u8 **)(a + 0x40), 2) - U(*(u8 **)(b + 0x40), 2) + (U(a, 0x6c) + U(b, 0x6c))) > S(a, 0x6e) + S(b, 0x6e))
        return 0;
    if ((u16)(U(a, 0x16) - U(b, 0x16) + (U(a, 0x70) + U(b, 0x70))) > S(a, 0x72) + S(b, 0x72))
        return 0;
    return 1;
}

void func_8005368C(u8 *a, u8 *b)
{
    s16 r;
    s32 h;
    if (b[0] & 2) {
        h = HIT_5368C(a, b);
        if (h) {
            b[0] = 2;
            b[4] = 2;
            b[5] = 7;
        }
    } else {
        r = func_80051284(a, b);
        if (r != 0 && r == 1 && a[0xac] == 1 && b[0] != 3) {
            b[0] = 6;
            b[4] = 2;
            b[5] = 0;
            *(u8 **)(a + 0xe4) = b;
            a[0xac] = 2;
            func_800224FC(2, S(a, 0x12), S(a, 0x16), S(a, 0x1a));
            D_1F80019E = 0;
        }
    }
}
#undef U
#undef S

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053808);
extern u8 D_8009C12F;
#define B(o, n) (((u8 *)(o))[n])

void func_80053808(GameObject *o, GameObject *e)
{
    s16 r;
    if (o->unk9E != 0 || B(o, 0xc8) != 0)
        return;
    if (e->unkC == 0x32) {
        if (D_8009C12F != 0xff)
            return;
        if ((u16)(o->h->p.whole - e->h->p.whole + (o->hitOffsetX + e->hitOffsetX)) > o->hitWidth + e->hitWidth)
            return;
        if ((u16)(o->y.p.whole - e->y.p.whole + (o->hitOffsetY + e->hitOffsetY)) > o->hitHeight + e->hitHeight)
            return;
        B(o, 0xa0) = 1;
        B(o, 0xa8) = 9;
        return;
    }
    r = func_80051284(o, e);
    if (r == 0)
        return;
    if (o->unkA6 & 2)
        o->unkA6 += 2;
    if (r != 1)
        return;
    if (e->active & 4) {
        if (B(o, 0xac) == r) {
            e->active = 2;
            e->state = 2;
            e->subState = 0;
            e->step = 0;
            e->touchFlag = 0;
            *(GameObject **)((char *)o + 0xe4) = e;
            B(o, 0xac) = 2;
            func_800224FC(2, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        }
        D_1F80019E = 0;
    } else {
        if (o->h->p.whole > e->h->p.whole) {
            o->unkBE = 8;
            o->unkB0 = 2;
        } else {
            o->unkBE = 9;
            o->unkB0 = -2;
        }
    }
}
#undef B

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaActorDraw1);
void dispatchAreaActorDraw1(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_801242E8();
    } else {
        func_8011F158();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaActorDraw2);
void dispatchAreaActorDraw2(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80124CC8();
    } else {
        func_8011F218();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaActorSpawn);
void dispatchAreaActorSpawn(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80123D24();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011EF08();
        break;
    case AREA04_HAUNTEDMANSION:
        func_8011E170();
        break;
    case AREA09_MUSHROOMVILLAGE:
        func_8011F650();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchAreaNpcInit);
void dispatchAreaNpcInit(void)
{
    if (GAME.selectedArea == AREA01_DWARFFOREST) {
        func_80123748();
    } else {
        func_8011D178();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", applyObjectPush);
void applyObjectPush(u8* arg0, u8* arg1)
{
    s32* q;

    arg1[0x69] = 0;
    if (func_80051284() == 1) {
        q = *(s32**)(arg0 + 0x40);
        *q = *q + (*(s16*)(arg1 + 0x80) << 8);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", callObjectInteraction);
void callObjectInteraction(void)
{
    func_80051284();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053BB4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", dispatchObjectContact);
void dispatchObjectContact(u8* arg0, u8* arg1) {
    switch (arg1[0xC]) {
    case 3:
        if (*(u16*)&GAME == 1 || (D_8009C62B & 0x40)) {
            func_80053BB4();
        }
        break;
    case 4:
        pushOutOfBoxX(arg0, arg1);
        break;
    default:
        func_80051284();
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053F08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80054618);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80054D60);
extern s16 D_1F80019E__54D60;
void func_80124200(GameObject *o, GameObject *e);
void func_80124280(GameObject *o, GameObject *e);
void func_8012437C(GameObject *o, GameObject *e);
void func_801245FC(GameObject *o, GameObject *e);
void func_80124054(GameObject *o, GameObject *e);
void func_80124318(GameObject *o, GameObject *e);
void func_801243AC(GameObject *o, GameObject *e);
void func_80123EE0(GameObject *o, GameObject *e);
void func_801243DC(GameObject *o, GameObject *e);
void func_801244E8(GameObject *o, GameObject *e);
void func_801246C4(GameObject *o, GameObject *e);
void func_80124240(GameObject *o, GameObject *e);
void func_80124260(GameObject *o, GameObject *e);
void func_80123390(GameObject *o, GameObject *e);
void func_8011F7C0(GameObject *o, GameObject *e);
void func_8011D23C(GameObject *o, GameObject *e);
void func_80125FFC(GameObject *o, GameObject *e);
void func_8011E964(GameObject *o, GameObject *e);
void func_8011E868(GameObject *o, GameObject *e);
void func_8011E78C(GameObject *o, GameObject *e);
void func_8011E660(GameObject *o, GameObject *e);
void func_8011E748(GameObject *o, GameObject *e);
void func_8011FFA8(GameObject *o, GameObject *e);
void func_8011DC04(GameObject *o, GameObject *e);
void func_8011D208(GameObject *o, GameObject *e);
void func_80120404(GameObject *o, GameObject *e);
void func_8011C6B4(GameObject *o, GameObject *e);
void func_8011BCE0(GameObject *o, GameObject *e);
void func_8011E67C(GameObject *o, GameObject *e);

static __inline__ s16 hit_54D60(GameObject *o, GameObject *e)
{
    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    if ((u16)(o->h->p.whole - e->h->p.whole + (o->hitOffsetX + e->hitOffsetX)) > o->hitWidth + e->hitWidth)
        return 0;
    if ((u16)(o->y.p.whole - e->y.p.whole + (o->hitOffsetY + e->hitOffsetY)) > o->hitHeight + e->hitHeight)
        return 0;
    return 1;
}

void func_80054D60(GameObject *o)
{
    GameObject **pp;
    GameObject *e;

    pp = D_1F800224;
    for (D_1F80019E__54D60 = D_1F80024C; D_1F80019E__54D60 != 0; ) {
        e = *pp++;
        D_1F80019E__54D60--;
        if (!(e->active & 1))
            continue;
        switch (e->type) {
        case 0: func_80051090(o, e); break;
        case 1: func_80124200(o, e); break;
        case 2: func_80124280(o, e); break;
        case 3: func_80051EE0(o, e); break;
        case 4:
            if (GAME.selectedArea == 0)
                func_801242E8(o, e);
            else
                func_8011F158(o, e);
            break;
        case 5: func_8012437C(o, e); break;
        case 6: func_801245FC(o, e); break;
        case 7:
            switch (GAME.selectedArea) {
            case 0: func_80123D24(o, e); break;
            case 3: func_8011EF08(o, e); break;
            case 4: func_8011E170(o, e); break;
            case 9: func_8011F650(o, e); break;
            }
            break;
        case 9: func_80124054(o, e); break;
        case 10: func_80124318(o, e); break;
        case 0xb: func_80051DA4(o, e); break;
        case 0xc: func_801243AC(o, e); break;
        case 0x14: func_80123EE0(o, e); break;
        case 0x15: func_801243DC(o, e); break;
        case 0xe: func_801244E8(o, e); break;
        case 0xf: func_801246C4(o, e); break;
        case 0x17: func_80124240(o, e); break;
        case 0x18: func_80124260(o, e); break;
        case 0x12: func_80123390(o, e); break;
        case 0x1a:
            e->touchFlag = 0;
            if (hit_54D60(o, e)) {
                if (e->type != 0x26)
                    *(u8 *)&o->unkA0 = 4;
                e->touchFlag = 1;
            }
            break;
        case 0x1c: func_8011F7C0(o, e); break;
        case 0x1d: func_8011D23C(o, e); break;
        case 0x23: func_80125FFC(o, e); break;
        case 0x28: func_8011E964(o, e); break;
        case 0x25: func_8011E868(o, e); break;
        case 0x26:
            e->touchFlag = 0;
            if (hit_54D60(o, e)) {
                if (e->type != 0x26)
                    *(u8 *)&o->unkA0 = 4;
                e->touchFlag = 1;
            }
            break;
        case 0x1f: func_8011E78C(o, e); break;
        case 0x38:
            e->touchFlag = 0;
            if (hit_54D60(o, e)) {
                *(u8 *)&o->unkA8 = 3;
                *(u8 *)&o->unkA0 = 1;
                e->touchFlag = 1;
            }
            break;
        case 0x24: func_8011E660(o, e); break;
        case 0x22: func_8011E748(o, e); break;
        case 0x33: func_8011FFA8(o, e); break;
        case 0x34: func_8011DC04(o, e); break;
        case 0x3b: func_8011D208(o, e); break;
        case 0x31: func_80120404(o, e); break;
        case 0x42: func_8011C6B4(o, e); break;
        case 0x43: func_8011BCE0(o, e); break;
        case 0x32:
        case 0x44:
            e->touchFlag = 0;
            if (func_80051284(o, e) == 1)
                o->h->raw += e->velH << 8;
            break;
        case 0x45:
            switch (e->unkC) {
            case 3:
                if (GAME.selectedArea == 1 || (D_8009C62B & 0x40))
                    func_80053BB4(o, e);
                break;
            case 4:
                pushOutOfBoxX(o, e);
                break;
            default:
                func_80051284(o, e);
                break;
            }
            break;
        case 0x1e: func_8011E67C(o, e); break;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005548C);
extern s16 D_1F80019E__5548C;
extern void func_8011BB50(GameObject *, u8 *);
extern void func_8011BC04(GameObject *, u8 *);
extern void func_8011BDA4(GameObject *, u8 *);
extern void func_8011BF60(GameObject *, u8 *);
extern void func_8011C0B0(GameObject *, u8 *);
extern void func_8011C1A8(GameObject *, u8 *);
extern void func_8011C270(GameObject *, u8 *);
extern void func_8011C384(GameObject *, u8 *);
extern void func_8011C47C(GameObject *, u8 *);
extern void func_8011CF54(GameObject *, u8 *);
extern void func_8011D6F8(GameObject *, u8 *);
extern void func_8011E858(GameObject *, u8 *);
extern void func_8011E984(GameObject *, u8 *);
extern void func_8011E978(GameObject *, u8 *);
extern void func_8011EC90(GameObject *, u8 *);
extern void func_8011EE24(GameObject *, u8 *);
extern void func_8011EFD4(GameObject *, u8 *);
extern void func_8011F070(GameObject *, u8 *);
extern void func_8011F490(GameObject *, u8 *);
extern void func_8011F710(GameObject *, u8 *);
extern void func_8011FA14(GameObject *, u8 *);
extern void func_8011FFAC(GameObject *, u8 *);
extern void func_80120278(GameObject *, u8 *);
extern void func_801204C4(GameObject *, u8 *);
extern void func_801235F8(GameObject *, u8 *);
extern void func_80123680(GameObject *, u8 *);
extern void func_8012370C(GameObject *, u8 *);
extern void func_80125274(GameObject *, u8 *);
extern void func_80125354(GameObject *, u8 *);
extern void func_8012543C(GameObject *, u8 *);
extern void func_801254DC(GameObject *, u8 *);
extern void func_80125584(GameObject *, u8 *);
extern void func_80125630(GameObject *, u8 *);
extern void func_801257A8(GameObject *, u8 *);
extern void func_8012589C(GameObject *, u8 *);
extern void func_801259DC(GameObject *, u8 *);
extern void func_80125BB4(GameObject *, u8 *);
extern void func_80125DA8(GameObject *, u8 *);
extern void func_80125EF4(GameObject *, u8 *);

void func_8005548C(GameObject *o)
{
    register u8 **r asm("$20");
    u8 *q;
    s16 v;

    if (D_8009BCA2 == 0) return;
    r = D_1F80021C;
    D_1F80019E__5548C = D_1F800246;
    while (D_1F80019E__5548C != 0) {
        q = *r;
        D_1F80019E__5548C = D_1F80019E__5548C - 1;
        r++;
        if (q[0] & 1) {
            switch (q[2]) {
            case 0:
                func_80125630(o, q);
                break;
            case 1:
                func_80125274(o, q);
                break;
            case 2:
                switch (GAME.selectedArea) {
                case 0: func_80124B38(o, q); break;
                case 1: func_801233E0(o, q); break;
                case 3: func_8011EC1C(o, q); break;
                case 4: func_8011E254(o, q); break;
                }
                break;
            case 4:
            case 0x1b:
                v = func_80051090(o, q);
                if (v != 0) {
                    if (*(u8 *)&o->unkAC == 1 && v == 1) {
                        q[0] = 2;
                        q[4] = 2;
                        q[5] = 1;
                        q[6] = 0;
                        q[0x69] = 0;
                        { GameObject *p = o; *(u8 **)((char *)p + 0xe4) = q; }
                        { GameObject *p = o; *(u8 *)&p->unkAC = 2; }
                    }
                    D_1F80019E__5548C = 0;
                }
                break;
            case 3:
            case 0x12:
                func_8012543C(o, q);
                break;
            case 6:
                func_80125584(o, q);
                break;
            case 7:
                switch (GAME.selectedArea) {
                case 0: func_801248A0(o, q); break;
                case 4: func_8011E3E4(o, q); break;
                case 10: func_8011FC7C(o, q); break;
                }
                break;
            case 8:
                func_801257A8(o, q);
                break;
            case 0x1f:
                if (GAME.selectedArea == 1) func_80123748(o, q);
                else func_8011D178(o, q);
                break;
            case 9:
                func_801259DC(o, q);
                break;
            case 10:
                func_8011FFAC(o, q);
                break;
            case 0xb:
                func_80125BB4(o, q);
                break;
            case 0xe:
                func_8005368C(o, q);
                break;
            case 0xf:
                func_80125DA8(o, q);
                break;
            case 0x11:
                func_80125EF4(o, q);
                break;
            case 0x15:
                func_801254DC(o, q);
                break;
            case 0x13:
                func_8012589C(o, q);
                break;
            case 0x1a:
                func_8011F710(o, q);
                break;
            case 0x1c:
                func_801204C4(o, q);
                break;
            case 0x17:
                func_80123680(o, q);
                break;
            case 0x16:
                func_801235F8(o, q);
                break;
            case 0x1d:
                func_8011F070(o, q);
                break;
            case 0x1e:
                func_8011E978(o, q);
                break;
            case 0x21:
                func_80120278(o, q);
                break;
            case 0x22:
                func_8012370C(o, q);
                break;
            case 0x28:
                func_8011F490(o, q);
                break;
            case 0x29:
                func_8011EC90(o, q);
                break;
            case 0x2b:
                func_80125354(o, q);
                break;
            case 0x24:
                func_8011EFD4(o, q);
                break;
            case 0x37:
                func_8011EE24(o, q);
                break;
            case 0x38:
                func_8011E984(o, q);
                break;
            case 0x39:
                func_8011E858(o, q);
                break;
            case 0x3a:
                func_8011FA14(o, q);
                break;
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x41:
            case 0x42:
                func_8011C47C(o, q);
                break;
            case 0x43:
                func_8011C384(o, q);
                break;
            case 0x46:
                func_8011BB50(o, q);
                break;
            case 0x47:
                func_8011BDA4(o, q);
                break;
            case 0x48:
                func_8011BF60(o, q);
                break;
            case 0x49:
                func_8011C0B0(o, q);
                break;
            case 0x4b:
                func_8011C1A8(o, q);
                break;
            case 0x18:
            case 0x23:
            case 0x32:
            case 0x4e:
            case 0x55:
            case 0x58:
            case 0x59:
            case 0x5a:
                func_80053808(o, q);
                break;
            case 0x4f:
                func_8011C270(o, q);
                break;
            case 0x50:
                func_8011BC04(o, q);
                break;
            case 0x53:
                func_8011D6F8(o, q);
                break;
            case 0x27:
                func_8011CF54(o, q);
                break;
            case 0x57:
                func_80051284(o, q);
                break;
            }
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055A44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055BA0);
