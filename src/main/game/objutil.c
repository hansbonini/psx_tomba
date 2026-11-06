#include "common.h"
#include "game.h"
#include "game/objinit.h"

u32 D_8007D6A0_d[1] asm("D_8007D6A0") = {
    0x00000001,
};

// INCLUDE_ASM("nonmatchings/main/game/objutil", distanceToPlayer);
s16 distanceToPlayer(u8* self)
{
    s32 dx = abs((*(s16**)(self + 0x40))[1] - PLAYER.obj.h->p.whole);
    s32 dy = abs(*(s16*)(self + 0x16) - PLAYER.obj.y.p.whole);

    return (csqrt((dx * dx + dy * dy) << 12) << 4) >> 16;
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_800385EC);
void func_800385EC(GameObject *obj)
{
    initObjectAC(obj);
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_80038748);
s32 abs(s32);
void func_80038748(u8 *o)
{
    s32 dx, dy, d, n;

    D_8009B6A0->frame = 0;
    playSFX(0x26);
    D_800A5460 = 1;
    D_800A53C8 = *(s16 *)(*(u8 **)(o + 0x40) + 2);
    D_800A53CC = *(s16 *)(o + 0x16) + 4;
    dx = *(s16 *)(*(u8 **)(o + 0x40) + 2) - *(s16 *)((*(u8 **)&D_800A53D8) + 2);
    dx = abs(dx);
    dy = *(s16 *)(o + 0x16) - PLAYER.obj.y.p.whole;
    dy = abs(dy);
    d = csqrt((dx * dx + dy * dy) << 12) >> 12;
    D_800A544C = d;
    if (D_800A5434 == 0) D_800A544C = d - 0x10;
    if (D_800A544C < 0x28) D_800A544C = 0x28;
    d = angleToPlayer(o);
    n = D_8009BC9C;
    D_800A5412 = d;
    o[5] = 3;
    o[6] = 0;
    *(s32 *)(o + 0x90) = n;
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003887C);
extern s16 probeCollisionAtDepthB(GameObject *, s16, s16);
extern void func_800EA35C(s16, s16, s16, u8);
extern void func_800224FC(s32, s16, s16, s16);
extern s16 func_80045310(void *, s16, s16);

s32 func_8003887C(GameObject *obj)
{
    extern GameObject *D_8009B698;
    s16 n;
    s32 k;

    if (obj->active == 1 && probeCollisionAtDepthB(obj, obj->h->p.whole, obj->y.p.whole)) {
        obj->active = 2;
        obj->unkA5 = 0;
        obj->touchFlag = 0;
        if (PLAYER.obj.unk9E == 0) {
            if (!(SCRATCHPAD.hitFlags & 0x800)) {
                if (SCRATCHPAD.hitFlags & 2) obj->touchFlag = 1;
            }
        }
#if REGION != REGION_JP
        k = (SCRATCHPAD.hitFlags >> 5) & 0xf;
        if (!(SCRATCHPAD.hitFlags & 0x3000)) {
            switch (k) {
            case 1:
            case 2:
            case 3:
                func_800EA35C(obj->h->p.whole, obj->y.p.whole, obj->d->p.whole, obj->animFrame);
                break;
            }
        }
#endif
        func_800224FC(1, obj->x.p.whole, obj->y.p.whole, obj->z.p.whole);
        playSFX(5);
        obj->unkA8 = 0x4ff;
    }
    if (obj->touchFlag != 0 && PLAYER.obj.unk9E != 4 && PLAYER.obj.unk9E != 7) {
    n = 0;
    switch ((s8)D_8009B698->unk7) {
    case 0:
    case 2:
        if (func_80045310(&PLAYER.obj, PLAYER.obj.h->p.whole + 0x10, PLAYER.obj.y.p.whole + D_800A5408)) {
            obj->touchFlag = 0;
            n++;
        }
        break;
    case 1:
    case 3:
        if (func_80045310(&PLAYER.obj, PLAYER.obj.h->p.whole - 0x10, PLAYER.obj.y.p.whole + D_800A5408)) {
            obj->touchFlag = 0;
            n++;
        }
        break;
    }
    if (n == 0) {
        func_80038748(obj);
        return 1;
    }
    return 0;
    }
    obj->touchFlag = 0;
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_80038AC0);
extern GameObject *D_8009C650;
typedef struct {
    u8 b0, p1[5], b6, b7, b8, p9[0x22 - 9];
    u16 w22;
    u8 p24[4];
    u16 w28, w2a, w2c, w2e;
} S330_38AC0;
extern s16 fixedMulCos(s32, s16);
extern s16 fixedMulSin(s32, s16);
extern void advanceAnimFrame(GameObject *, s32);
extern s16 angleBetweenPoints(Vec2s, Vec2s);

#define G PLAYER.obj
#define TB(n) D_8007D60A[(s16)(obj->animFrame + obj->animFrame * 2) + (n) - 1]
#define TK(n) D_8007D60A[k + (n) - 1]

void func_80038AC0(GameObject *obj)
{
    extern S330_38AC0 *D_8009B698;
    Vec2s t;
    Vec2s s;
    s16 va;
    s16 vb;
    s16 i;
    s16 k;
    s32 x;
    u16 u;

    D_8009B698->w2e = 0xffff;
    switch (obj->step) {
    case 0:
        obj->animFrame = G.animFrame;
        G.unk9D = 1;
        D_8009B698->b7 = obj->animFrame;
        u = TB(2);
        obj->active = 2;
        obj->drawType = DRAW_SPRITE;
        obj->unkAA = u;
        D_8009B6A0->mode = 0;
        D_8009B698->w22 = 0;
        D_8009C968.w2 = 0;
        D_8009B6A0->shadowLen = 1;
        D_8009B6A0->shadowLen2 = 0;
        D_8009B6A0->w34 = 0;
        D_8009B6A0->w36 = 0;
        obj->unkA8 = 0;
        if (G.unk9E == 4 || G.unk9E == 7) {
            obj->child = (s32)D_8009E454;
            *D_8009E454 = 2;
        }
        i = obj->subState * 6;
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3:
            break;
        case 4: case 5:
            i += 2;
            break;
        case 6: case 7:
            i += 4;
            break;
        }
        if (obj->animFrame & 1) va = 0xa0 - D_8007D5E4[i];
        else va = D_8007D5E4[i] - 0x20;
        vb = D_8007D5E4[i + 1];
        if (obj->animFrame >= 6) {
            x = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
            obj->velX = (obj->animFrame & 1) ? x - 4 : x + 4;
            obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        } else {
            obj->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
            obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        }
        obj->h->p.whole = obj->velX + fixedMulCos(((u16)obj->unkAA + 0x80) & 0xff, 0x10);
        obj->y.p.whole = obj->velY + fixedMulSin(((u16)obj->unkAA + 0x80) & 0xff, 0x10);
        obj->d->p.whole = G.d->p.whole;
        obj->unkA5 = 1;
        obj->hitboxX = 6;
        obj->hitboxY = 6;
        obj->hitboxW = 0xc;
        obj->hitboxH = 0xc;
        D_8009B6A0->frame = 0;
        switch (D_8009B698->b0) {
        case 2:
            obj->unkA8 = 0x1c00;
            playSFXWithNote(3, 2);
            obj->unk98 = 0;
            if (obj->type == 9) {
                obj->unkA8 = 0x1e00;
                obj->unk98 = 2;
            }
            break;
        case 1:
            obj->unkA8 = 0x2000;
            playSFXWithNote(3, 8);
            obj->unk98 = 0;
            if (obj->type == 9) {
                obj->unkA8 = 0x2200;
                obj->unk98 = 2;
            }
            break;
        }
        obj->velH = fixedMulCos(obj->unkAA, obj->unkA8);
        obj->velV = fixedMulSin(obj->unkAA, obj->unkA8);
        D_8009B698->w28 = 0xffff;
        D_8009B698->w2a = 0xffff;
        func_800348FC(obj);
        advanceAnimFrame(&G, 0);
        obj->unkAA += 0x80;
        if (obj->animFrame & 1) obj->unkAA -= 0x40;
        else obj->unkAA += 0x40;
        obj->step++;
        break;
    case 1:
        tickAnimation(&G);
        i = obj->subState * 6;
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3:
            break;
        case 4: case 5:
            i += 2;
            break;
        case 6: case 7:
            i += 4;
            break;
        }
        if (obj->animFrame & 1) va = 0xa0 - D_8007D5E4[i];
        else va = D_8007D5E4[i] - 0x20;
        vb = D_8007D5E4[i + 1];
        if (obj->animFrame >= 6) {
            x = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
            obj->velX = (obj->animFrame & 1) ? x - 4 : x + 4;
            obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        } else {
            obj->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
            obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        }
        obj->h->p.whole = obj->velX + fixedMulCos((u8)obj->unkAA, 0x10);
        obj->y.p.whole = obj->velY + fixedMulSin((u8)obj->unkAA, 0x10);
        k = obj->animFrame + obj->animFrame * 2;
        obj->unkAA += TK(1);
        if (obj->animFrame & 1) {
            if (obj->unkAA < TK(2) + 0x40) {
                func_8003473C(obj);
                advanceAnimFrame(&G, 0);
                obj->unkAA = TK(2);
                D_8009B6A0->mode = 1;
                G.rotZ = 0;
                obj->touchFlag = 0;
                obj->timer = 1;
                obj->step++;
            }
        } else {
            if (obj->unkAA > TK(2) + 0xc0) {
                func_8003473C(obj);
                advanceAnimFrame(&G, 0);
                obj->unkAA = TK(2);
                D_8009B6A0->mode = 1;
                G.rotZ = 0;
                obj->touchFlag = 0;
                obj->timer = 1;
                obj->step++;
            }
        }
        break;
    case 2:
        if (obj->timer != 0) {
            if (--obj->timer <= 0) {
                obj->timer = 0;
                obj->active = 1;
                obj->step++;
            }
        }
    case 3:
        D_8009B6A0->shadowLen += obj->unkA8 >> 8;
        if (D_8009B6A0->shadowLen > 0x60 - D_8009B698->b0 * 16) D_8009B6A0->shadowLen = 0x60 - (D_8009B698->b0 << 4);
        D_8009B6A0->shadowLen2 -= (obj->unkA8 >> 8) * 2;
        if (D_8009B6A0->shadowLen2 < 0) D_8009B6A0->shadowLen2 = 0;
        obj->unkA8 -= 0x280;
        obj->velH = fixedMulCos(obj->unkAA, obj->unkA8);
        obj->velV = fixedMulSin(obj->unkAA, obj->unkA8);
        applyObjectSpeedXY(obj);
        if (((s16 (*)(GameObject *))func_8003887C)(obj) == 0) {
            G.rotZ = 0;
            if (obj->unkA8 < 0x500) {
                obj->unkAA = TB(2);
                obj->velX = obj->h->p.whole + fixedMulCos(((u16)obj->unkAA + 0x80) & 0xff, 0x18);
                obj->velY = obj->y.p.whole + fixedMulSin(((u16)obj->unkAA + 0x80) & 0xff, 0x18);
                D_8009B6A0->shadowLen2 = 0;
                D_8009B6A0->mode = 2;
                D_8009B6A0->angle = 0;
                if (obj->visible) {
                    func_8002F05C(obj, (s16)(obj->x.p.whole + ((obj->animFrame & 1) ? -0x10 : 0x10)), obj->y.p.whole, obj->z.p.whole);
                }
                obj->step = 4;
            }
        }
        break;
    case 4:
        D_8009B6A0->shadowLen -= (obj->unkA8 >> 8) * 2;
        if (D_8009B6A0->shadowLen < 0) D_8009B6A0->shadowLen = 0;
        obj->h->p.whole = obj->velX + fixedMulCos(((u16)obj->unkAA + (u16)D_8009B6A0->angle) & 0xff, 0x18);
        obj->y.p.whole = obj->velY + fixedMulSin(((u16)obj->unkAA + (u16)D_8009B6A0->angle) & 0xff, 0x18);
        D_8009B6A0->angle += TB(1) >> 1;
        G.rotZ = 0;
        if (obj->animFrame & 1) {
            D_8009B6A0->frame = (D_8009B6A0->angle < -0x20) ? 2 : 1;
            if (D_8009B6A0->angle < -0x40) {
                obj->unkAA = (obj->unkAA + D_8009B6A0->angle) & 0xff;
                D_8009B6A0->mode = 3;
                func_8003481C(obj);
                advanceAnimFrame(&G, 0);
                D_8009B6A0->angle = (TB(2) - 0x40) & 0xff;
                obj->step++;
            }
        } else {
            D_8009B6A0->frame = (D_8009B6A0->angle > 0x20) ? 2 : 1;
            if (D_8009B6A0->angle > 0x40) {
                obj->unkAA = (obj->unkAA + D_8009B6A0->angle) & 0xff;
                D_8009B6A0->mode = 3;
                func_8003481C(obj);
                advanceAnimFrame(&G, 0);
                D_8009B6A0->angle = (TB(2) + 0x40) & 0xff;
                obj->step++;
            }
        }
        ((s16 (*)(GameObject *))func_8003887C)(obj);
        break;
    case 5:
        if (((s16 (*)(GameObject *))func_8003887C)(obj) == 0) {
            D_8009B6A0->frame = 0;
            obj->unkA8 = 0x2000;
            D_8009B6A0->shadowLen += 0x20;
            if (D_8009B6A0->shadowLen > 0x60 - D_8009B698->b0 * 16) D_8009B6A0->shadowLen = 0x60 - (D_8009B698->b0 << 4);
            D_8009B6A0->shadowLen2 -= obj->unkA8 >> 8;
            if (D_8009B6A0->shadowLen2 < 0) D_8009B6A0->shadowLen2 = 0;
            if (obj->animFrame & 1) obj->velX = PLAYER.obj.h->p.whole + 0x10;
            else obj->velX = PLAYER.obj.h->p.whole - 0x10;
            obj->velY = PLAYER.obj.y.p.whole - 0x10;
            t.x = obj->velX + fixedMulCos(D_8009B6A0->angle, 0xc);
            t.y = obj->velY + fixedMulSin(D_8009B6A0->angle, 0xc);
            s.x = obj->h->p.whole;
            s.y = obj->y.p.whole;
            obj->unkAA = angleBetweenPoints(s, t);
            obj->velH = fixedMulCos(obj->unkAA, obj->unkA8);
            obj->velV = fixedMulSin(obj->unkAA, obj->unkA8);
            applyObjectSpeedXY(obj);
            va = t.x - s.x + 0x10;
            vb = t.y - s.y + 0x10;
            if ((u16)va < 0x20 && (u16)vb < 0x20) {
                if (G.unk9E == 4 || G.unk9E == 7) *(u8 *)obj->child = D_8009B698->b6;
                obj->unkAA = TB(2) + 0x80;
                if (obj->animFrame & 1) {
                    obj->velX = PLAYER.obj.h->p.whole + 0x10;
                    obj->unkAA = (obj->unkAA + 0x40) & 0xff;
                } else {
                    obj->velX = PLAYER.obj.h->p.whole - 0x10;
                    obj->unkAA = (obj->unkAA - 0x40) & 0xff;
                }
                obj->velY = PLAYER.obj.y.p.whole - 0x10;
                obj->h->p.whole = obj->velX + fixedMulCos(obj->unkAA, 0xc);
                obj->y.p.whole = obj->velY + fixedMulSin(obj->unkAA, 0xc);
                D_8009B6A0->shadowLen2 = 0;
                D_8009B6A0->angle = 0;
                D_8009B6A0->mode = 0;
                G.unk9D = 0;
                obj->unkA5 = 0;
                if (!(PAD_PRESSED[0] & SPAD->buttonAttack) || G.state != 1 || G.modelLit || *(u8 *)&G.unkAC >= 2 || D_8009BCA7) {
#if REGION == REGION_JP
                    func_800EFBEC_slps01144(&G);
#endif
                    D_8009B698->b0 = 0;
                    setObjState(obj, 2, 0, 0);
                    D_8009BC9C = 0;
                } else {
#if REGION != REGION_JP
                    func_800EBA70(D_8009C61A[0], obj);
#endif
                    obj->unkAA += (obj->animFrame & 1) ? -0x40 : 0x40;
                    obj->step = 6;
                }
            }
        }
        break;
    case 6:
        obj->animFrame = G.animFrame;
        func_800348FC(obj);
        advanceAnimFrame(&G, 0);
        if ((SCRATCHPAD.unk1F8 & 0xf) == 0) {
#if REGION != REGION_JP
            func_80028A74(0, 0, 0xc0, 2);
#endif
            playSFX(3);
        }
        advanceAnimFrame(&G, (D_8009B698->w22 >> 2) & 3);
        k = obj->animFrame + obj->animFrame * 2;
        D_8009C968.w0 = 10;
        D_8009C968.w2 = 2;
        D_8009C968.w4 = TK(0);
        obj->unkAA += TK(1);
        if (obj->unkAA > 0xff) obj->unkAA -= 0x100;
        if (obj->unkAA < 0) obj->unkAA += 0x100;
#if REGION != REGION_JP
        if (obj->animFrame & 1) obj->rotZ = (obj->unkAA + 0x80) & 0xff;
        else obj->rotZ = (u8)obj->unkAA;
#endif
        i = obj->subState * 6;
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3:
            break;
        case 4: case 5:
            i += 2;
            break;
        case 6: case 7:
            i += 4;
            break;
        }
        if (obj->animFrame & 1) va = 0x80 - D_8007D5E4[i];
        else va = D_8007D5E4[i];
        vb = D_8007D5E4[i + 1];
        obj->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
        obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        func_800349DC(&D_8009C968, obj->unkAA, &va, &vb);
        obj->h->p.whole = obj->velX + va;
        obj->y.p.whole = obj->velY + vb;
        if (!(PAD_PRESSED[0] & SPAD->buttonAttack) || G.state != 1 || G.modelLit || D_8009BCA7) {
            G.unk9D = 1;
            D_8009B698->b0 = 2;
            D_8009B698->w22 = 0;
            obj->step = 0;
        } else {
            D_8009B698->w22++;
        }
        if (D_8009B698->w22 >= 0x3d) {
            D_8009B698->w22 = 0;
            obj->step++;
        }
        break;
    case 7:
        obj->animFrame = G.animFrame;
        func_800348FC(obj);
        advanceAnimFrame(&G, 0);
        if ((SCRATCHPAD.unk1F8 & 0xf) == 0) {
#if REGION != REGION_JP
            func_80028A74(0, 0, 0xff, 2);
#endif
            playSFXWithNote(3, 6);
        }
        advanceAnimFrame(&G, (D_8009B698->w22 / 3) & 3);
        obj->animFrame = G.animFrame;
        k = obj->animFrame + obj->animFrame * 2;
        D_8009C968.w0 = 0x10;
        D_8009C968.w2 = 4;
        D_8009C968.w4 = TK(0);
        obj->unkAA += TK(1);
        if (obj->unkAA > 0xff) obj->unkAA -= 0x100;
        if (obj->unkAA < 0) obj->unkAA += 0x100;
#if REGION != REGION_JP
        if (obj->animFrame & 1) obj->rotZ = (obj->unkAA + 0x80) & 0xff;
        else obj->rotZ = (u8)obj->unkAA;
#endif
        i = obj->subState * 6;
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3:
            break;
        case 4: case 5:
            i += 2;
            break;
        case 6: case 7:
            i += 4;
            break;
        }
        if (obj->animFrame & 1) va = 0x80 - D_8007D5E4[i];
        else va = D_8007D5E4[i];
        vb = D_8007D5E4[i + 1];
        obj->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)va, vb);
        obj->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)va, vb);
        func_800349DC(&D_8009C968, obj->unkAA, &va, &vb);
        obj->h->p.whole = obj->velX + va;
        obj->y.p.whole = obj->velY + vb;
        if (!(PAD_PRESSED[0] & SPAD->buttonAttack) || G.state != 1 || G.modelLit || D_8009BCA7) {
            D_8009B698->b0 = 1;
            D_8009B698->w22 = 0;
            G.unk9D = 1;
            obj->step = 0;
        }
        D_8009B698->w22++;
        break;
    }
    if (*(u8 *)&G.unkAC >= 2) {
        D_8009C650 = D_800A547C;
        D_8009B698->b8 = 0;
        G.subState = 0xe;
        D_8009BC9C = 0;
        G.unkA5 = 0;
        G.step = 0;
        G.unk7 = 0;
        D_8009B698->w2c = 0xd;
        if (D_8009B698->w2e != 0xd) {
            func_800EEF64(obj);
            advanceAnimFrame(obj, 0);
            D_8009B698->w2e = D_8009B698->w2c;
        }
        D_8009B698->w2e = 0xffff;
        G.unk9D = 0;
        D_8009B6A0->mode = 0;
        D_8009B698->b0 = 0;
        setObjState(obj, 2, 0, 0);
    }
}
#undef G
#undef TB
#undef TK

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003A10C);
extern u8 *D_8009B698;

void func_8003A10C(GameObject *obj)
{
    GameObject *parent = *(GameObject **)((char *)obj + 0x90);
    s16 dx, dy;
    u16 b;
    ObjectAC *g;
    switch (obj->step) {
    case 0:
        D_8009B6A0->mode = 1;
        D_8009B6A0->shadowLen = 0;
        D_8009B6A0->shadowLen2 = 0;
        obj->step++;
        if (parent != 0) {
            obj->velX = parent->h->p.whole;
            if ((parent->category & 0x7f) == 2)
                obj->velY = parent->y.p.whole + 8;
            else
                obj->velY = parent->y.p.whole;
        }
        break;
    case 1:
        if (parent != 0) {
            dx = parent->h->p.whole - obj->velX;
            if ((parent->category & 0x7f) == 2) {
                b = obj->velY - 8;
                dy = parent->y.p.whole - b;
            } else
                dy = parent->y.p.whole - obj->velY;
            obj->h->p.whole += dx;
            obj->y.p.whole += dy;
            PLAYER.obj.localX += dx;
            PLAYER.obj.localY += dy;
            obj->velX = parent->h->p.whole;
            if ((parent->category & 0x7f) == 2)
                obj->velY = parent->y.p.whole + 8;
            else
                obj->velY = parent->y.p.whole;
        }
        obj->rotZ = D_800A5420;
        break;
    }
    if (PLAYER.obj.subState != 0x32) {
        g = D_8009B6A0;
        g->mode = 0;
        g->shadowLen2 = 0;
        g->angle = 0;
        D_800A5435 = 0;
        *D_8009B698 = 0;
        D_800A545E = 0;
        setObjState(obj, 2, 0, 0);
        D_8009BC9C = 0;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003A310);
void func_8003A310(u8 *o)
{
#if REGION != REGION_JP
    if ((u8)(o[6] - 6) < 2) return;
#endif
    switch (*(u16 *)(o + 0x2e)) {
    case 0: case 1: case 2: case 3:
        *(s32 *)(o + 0x8c) = 0; break;
    case 4: *(s32 *)(o + 0x8c) = 0x20; break;
    case 5: *(s32 *)(o + 0x8c) = 0xe0; break;
    case 6: *(s32 *)(o + 0x8c) = 0x40; break;
    case 7: *(s32 *)(o + 0x8c) = 0xc0; break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003A384);

void func_8003A384(GameObject *obj)
{
    switch (obj->subState) {
    case 0:
        func_80038AC0(obj);
#if REGION != REGION_JP
        if (obj->step == 6 || obj->step == 7)
            break;
#endif
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3: obj->rotZ = 0; break;
        case 4: obj->rotZ = 0x20; break;
        case 5: obj->rotZ = 0xe0; break;
        case 6: obj->rotZ = 0x40; break;
        case 7: obj->rotZ = 0xc0; break;
        }
        break;
    case 1:
        func_80038AC0(obj);
#if REGION != REGION_JP
        if (obj->step == 6 || obj->step == 7)
            break;
#endif
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3: obj->rotZ = 0; break;
        case 4: obj->rotZ = 0x20; break;
        case 5: obj->rotZ = 0xe0; break;
        case 6: obj->rotZ = 0x40; break;
        case 7: obj->rotZ = 0xc0; break;
        }
        break;
    case 2:
        func_80038AC0(obj);
#if REGION != REGION_JP
        if (obj->step == 6 || obj->step == 7)
            break;
#endif
        switch (obj->animFrame) {
        case 0: case 1: case 2: case 3: obj->rotZ = 0; break;
        case 4: obj->rotZ = 0x20; break;
        case 5: obj->rotZ = 0xe0; break;
        case 6: obj->rotZ = 0x40; break;
        case 7: obj->rotZ = 0xc0; break;
        }
        break;
    case 3:
    case 4:
        func_8003A10C(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003A4F8);
extern u8 *D_8009B698;
void func_8003A4F8(GameObject *obj)
{
    if (D_800A545F) obj->state = 2;
    switch (obj->state) {
    case 0:
#if REGION == REGION_EU && VERSION == 0
        initObjectAC(obj);
#else
        func_800385EC(obj);
#endif
        obj->state++;
        break;
    case 1:
        cullAndQueueDraw(obj);
        func_8003A384(obj);
        break;
    case 2:
        D_8009B6A0->mode = 0;
        *D_8009B698 = 0;
        if ((s8)--D_800A547B_U8 < 0) D_800A547B_U8 = 0;
        obj->state = 3;
        break;
    case 3:
        freeWeaponObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", func_8003A604);
void func_8003A604(int id)
{
    D_8007D6A0 = id;
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", unpackSpriteFrame);
void unpackSpriteFrame(s32 a, s32 b, u8 *dst, s32 d)
{
    u8 c;
    s32 *q;
    u8 *p;
    s32 n, a4;
    q = (s32 *)(a + 4);
    q = (s32 *)((s32)q + (b << 2));
    n = q[1] - *q;
    if (d != -1) {
        *(s32 *)dst = 0x10;
        *(s32 *)(dst + 4) = 0;
        *(s32 *)(dst + 8) = 1;
        *(s32 *)(dst + 0xc) = d;
        dst = dst + 0x10;
    }
    p = (u8 *)(a + *q);
    loop: {
        c = *p++;
        n = n - 1;
        if (n < 1)
            return;
        if (c & 1) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 2) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 4) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 8) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 16) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 32) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 64) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
        if (c & 128) {
            s32 x = *p++;
            s32 y = *p++;
            n = n - 2;
            dst = fillBytesUnrolled(x, dst, y);
        } else {
            *dst = *p++;
            n = n - 1;
            dst = dst + 1;
        }
    }
    goto loop;
}

// INCLUDE_ASM("nonmatchings/main/game/objutil", fillBytesUnrolled);
u8* fillBytesUnrolled(s32 n, u8* dst, u8 val)
{
    switch (n) {
    case 255:  *dst++ = val;
    case 254:  *dst++ = val;
    case 253:  *dst++ = val;
    case 252:  *dst++ = val;
    case 251:  *dst++ = val;
    case 250:  *dst++ = val;
    case 249:  *dst++ = val;
    case 248:  *dst++ = val;
    case 247:  *dst++ = val;
    case 246:  *dst++ = val;
    case 245:  *dst++ = val;
    case 244:  *dst++ = val;
    case 243:  *dst++ = val;
    case 242:  *dst++ = val;
    case 241:  *dst++ = val;
    case 240:  *dst++ = val;
    case 239:  *dst++ = val;
    case 238:  *dst++ = val;
    case 237:  *dst++ = val;
    case 236:  *dst++ = val;
    case 235:  *dst++ = val;
    case 234:  *dst++ = val;
    case 233:  *dst++ = val;
    case 232:  *dst++ = val;
    case 231:  *dst++ = val;
    case 230:  *dst++ = val;
    case 229:  *dst++ = val;
    case 228:  *dst++ = val;
    case 227:  *dst++ = val;
    case 226:  *dst++ = val;
    case 225:  *dst++ = val;
    case 224:  *dst++ = val;
    case 223:  *dst++ = val;
    case 222:  *dst++ = val;
    case 221:  *dst++ = val;
    case 220:  *dst++ = val;
    case 219:  *dst++ = val;
    case 218:  *dst++ = val;
    case 217:  *dst++ = val;
    case 216:  *dst++ = val;
    case 215:  *dst++ = val;
    case 214:  *dst++ = val;
    case 213:  *dst++ = val;
    case 212:  *dst++ = val;
    case 211:  *dst++ = val;
    case 210:  *dst++ = val;
    case 209:  *dst++ = val;
    case 208:  *dst++ = val;
    case 207:  *dst++ = val;
    case 206:  *dst++ = val;
    case 205:  *dst++ = val;
    case 204:  *dst++ = val;
    case 203:  *dst++ = val;
    case 202:  *dst++ = val;
    case 201:  *dst++ = val;
    case 200:  *dst++ = val;
    case 199:  *dst++ = val;
    case 198:  *dst++ = val;
    case 197:  *dst++ = val;
    case 196:  *dst++ = val;
    case 195:  *dst++ = val;
    case 194:  *dst++ = val;
    case 193:  *dst++ = val;
    case 192:  *dst++ = val;
    case 191:  *dst++ = val;
    case 190:  *dst++ = val;
    case 189:  *dst++ = val;
    case 188:  *dst++ = val;
    case 187:  *dst++ = val;
    case 186:  *dst++ = val;
    case 185:  *dst++ = val;
    case 184:  *dst++ = val;
    case 183:  *dst++ = val;
    case 182:  *dst++ = val;
    case 181:  *dst++ = val;
    case 180:  *dst++ = val;
    case 179:  *dst++ = val;
    case 178:  *dst++ = val;
    case 177:  *dst++ = val;
    case 176:  *dst++ = val;
    case 175:  *dst++ = val;
    case 174:  *dst++ = val;
    case 173:  *dst++ = val;
    case 172:  *dst++ = val;
    case 171:  *dst++ = val;
    case 170:  *dst++ = val;
    case 169:  *dst++ = val;
    case 168:  *dst++ = val;
    case 167:  *dst++ = val;
    case 166:  *dst++ = val;
    case 165:  *dst++ = val;
    case 164:  *dst++ = val;
    case 163:  *dst++ = val;
    case 162:  *dst++ = val;
    case 161:  *dst++ = val;
    case 160:  *dst++ = val;
    case 159:  *dst++ = val;
    case 158:  *dst++ = val;
    case 157:  *dst++ = val;
    case 156:  *dst++ = val;
    case 155:  *dst++ = val;
    case 154:  *dst++ = val;
    case 153:  *dst++ = val;
    case 152:  *dst++ = val;
    case 151:  *dst++ = val;
    case 150:  *dst++ = val;
    case 149:  *dst++ = val;
    case 148:  *dst++ = val;
    case 147:  *dst++ = val;
    case 146:  *dst++ = val;
    case 145:  *dst++ = val;
    case 144:  *dst++ = val;
    case 143:  *dst++ = val;
    case 142:  *dst++ = val;
    case 141:  *dst++ = val;
    case 140:  *dst++ = val;
    case 139:  *dst++ = val;
    case 138:  *dst++ = val;
    case 137:  *dst++ = val;
    case 136:  *dst++ = val;
    case 135:  *dst++ = val;
    case 134:  *dst++ = val;
    case 133:  *dst++ = val;
    case 132:  *dst++ = val;
    case 131:  *dst++ = val;
    case 130:  *dst++ = val;
    case 129:  *dst++ = val;
    case 128:  *dst++ = val;
    case 127:  *dst++ = val;
    case 126:  *dst++ = val;
    case 125:  *dst++ = val;
    case 124:  *dst++ = val;
    case 123:  *dst++ = val;
    case 122:  *dst++ = val;
    case 121:  *dst++ = val;
    case 120:  *dst++ = val;
    case 119:  *dst++ = val;
    case 118:  *dst++ = val;
    case 117:  *dst++ = val;
    case 116:  *dst++ = val;
    case 115:  *dst++ = val;
    case 114:  *dst++ = val;
    case 113:  *dst++ = val;
    case 112:  *dst++ = val;
    case 111:  *dst++ = val;
    case 110:  *dst++ = val;
    case 109:  *dst++ = val;
    case 108:  *dst++ = val;
    case 107:  *dst++ = val;
    case 106:  *dst++ = val;
    case 105:  *dst++ = val;
    case 104:  *dst++ = val;
    case 103:  *dst++ = val;
    case 102:  *dst++ = val;
    case 101:  *dst++ = val;
    case 100:  *dst++ = val;
    case 99:  *dst++ = val;
    case 98:  *dst++ = val;
    case 97:  *dst++ = val;
    case 96:  *dst++ = val;
    case 95:  *dst++ = val;
    case 94:  *dst++ = val;
    case 93:  *dst++ = val;
    case 92:  *dst++ = val;
    case 91:  *dst++ = val;
    case 90:  *dst++ = val;
    case 89:  *dst++ = val;
    case 88:  *dst++ = val;
    case 87:  *dst++ = val;
    case 86:  *dst++ = val;
    case 85:  *dst++ = val;
    case 84:  *dst++ = val;
    case 83:  *dst++ = val;
    case 82:  *dst++ = val;
    case 81:  *dst++ = val;
    case 80:  *dst++ = val;
    case 79:  *dst++ = val;
    case 78:  *dst++ = val;
    case 77:  *dst++ = val;
    case 76:  *dst++ = val;
    case 75:  *dst++ = val;
    case 74:  *dst++ = val;
    case 73:  *dst++ = val;
    case 72:  *dst++ = val;
    case 71:  *dst++ = val;
    case 70:  *dst++ = val;
    case 69:  *dst++ = val;
    case 68:  *dst++ = val;
    case 67:  *dst++ = val;
    case 66:  *dst++ = val;
    case 65:  *dst++ = val;
    case 64:  *dst++ = val;
    case 63:  *dst++ = val;
    case 62:  *dst++ = val;
    case 61:  *dst++ = val;
    case 60:  *dst++ = val;
    case 59:  *dst++ = val;
    case 58:  *dst++ = val;
    case 57:  *dst++ = val;
    case 56:  *dst++ = val;
    case 55:  *dst++ = val;
    case 54:  *dst++ = val;
    case 53:  *dst++ = val;
    case 52:  *dst++ = val;
    case 51:  *dst++ = val;
    case 50:  *dst++ = val;
    case 49:  *dst++ = val;
    case 48:  *dst++ = val;
    case 47:  *dst++ = val;
    case 46:  *dst++ = val;
    case 45:  *dst++ = val;
    case 44:  *dst++ = val;
    case 43:  *dst++ = val;
    case 42:  *dst++ = val;
    case 41:  *dst++ = val;
    case 40:  *dst++ = val;
    case 39:  *dst++ = val;
    case 38:  *dst++ = val;
    case 37:  *dst++ = val;
    case 36:  *dst++ = val;
    case 35:  *dst++ = val;
    case 34:  *dst++ = val;
    case 33:  *dst++ = val;
    case 32:  *dst++ = val;
    case 31:  *dst++ = val;
    case 30:  *dst++ = val;
    case 29:  *dst++ = val;
    case 28:  *dst++ = val;
    case 27:  *dst++ = val;
    case 26:  *dst++ = val;
    case 25:  *dst++ = val;
    case 24:  *dst++ = val;
    case 23:  *dst++ = val;
    case 22:  *dst++ = val;
    case 21:  *dst++ = val;
    case 20:  *dst++ = val;
    case 19:  *dst++ = val;
    case 18:  *dst++ = val;
    case 17:  *dst++ = val;
    case 16:  *dst++ = val;
    case 15:  *dst++ = val;
    case 14:  *dst++ = val;
    case 13:  *dst++ = val;
    case 12:  *dst++ = val;
    case 11:  *dst++ = val;
    case 10:  *dst++ = val;
    case 9:  *dst++ = val;
    case 8:  *dst++ = val;
    case 7:  *dst++ = val;
    case 6:  *dst++ = val;
    case 5:  *dst++ = val;
    case 4:  *dst++ = val;
    case 3:  *dst++ = val;
    case 2:  *dst++ = val;
    case 1:  *dst++ = val;
    }
    return dst;
}
