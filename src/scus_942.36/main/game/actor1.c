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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8004FE24);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051488);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051A18);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051DA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051EE0);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005242C);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800527C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800529A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052B88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052D5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800530F0);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005334C);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005368C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053808);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80054D60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005548C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055A44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055BA0);
