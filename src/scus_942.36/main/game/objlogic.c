#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_8003473C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_8003481C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_800348FC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_800349DC);
extern s32 fixedMulCos(s32 a, s16 b);
extern s32 fixedMulSin(s32 a, s16 b);
extern s32 fixedMulSin2(s32 a, s16 b);

void func_800349DC(s16 *p, s32 a, s16 *o1, s16 *o2)
{
    s32 ang = (s16)a;
    s32 c = fixedMulCos(ang, p[0]);
    s32 s = fixedMulSin(ang, p[0]);
    s16 t = p[2];
    s16 b;
    if (ang < t) b = t + (t - a);
    else b = t - (a - t);
    *o1 = c + fixedMulCos2(b, p[1]);
    *o2 = s + fixedMulSin2(b, p[1]);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80034AB8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80034C14);
typedef struct { s16 x, y; } XY_34C14;
typedef struct {
    char p0[4];
    u8 b04, step, state, substep;
    char p8[0x14 - 8];
    Fix16 y;
    char p18[0x2e - 0x18];
    u16 animFrame;
    char p30[0x40 - 0x30];
    Fix16 *h;
    Fix16 *d;
    char p48[0x8c - 0x48];
    s32 d8c;
    char p90[0x9d - 0x90];
    u8 b9d, b9e;
    char p9f[0xa4 - 0x9f];
    u8 ba4, ba5;
    char pa6[0xac - 0xa6];
    u8 bac;
    char pad[0xe4 - 0xad];
    s32 de4;
} P38_34C14;
typedef struct {
    u8 b0;
    char p1[5];
    u8 b6, b7, b8;
    char p9[0x22 - 9];
    u16 w22;
    char p24[4];
    u16 w28, w2a, w2c, w2e;
} G330_34C14;
typedef struct {
    char p0[0xc];
    u8 b0c, b0d;
    s16 w0e;
    char p10[0x30 - 0x10];
    s16 w30, w32, w34, w36;
} G338_34C14;
typedef struct { s16 a, b, c; } D600_34C14;
extern P38_34C14 PLAYER_P38_34C14 asm("PLAYER");
extern u16 D_1F800282;
extern u8 D_8009BCA7_U8 asm("D_8009BCA7");
extern s32 D_8009C650;
extern void playSFX(s32);
extern s32 tickAnimation(GameObject *);
extern void applyObjectSpeedXY(GameObject *);
extern s16 probeCollisionAtDepthB(GameObject *, s32, s32);
extern void func_800224FC(s32, s32, s32, s32);
extern void func_800EA35C(s32, s32, s32, s32);

#define IDX(o, i) \
    i = o->subState * 6; \
    switch (o->animFrame) { \
    case 0: case 1: case 2: case 3: break; \
    case 4: case 5: i += 2; break; \
    case 6: case 7: i += 4; break; \
    }

#define TB(o) ((s16)(o->animFrame + o->animFrame * 2))

#define PADOK() ((*(volatile u16 *)&D_8009C9D8 & (*(u16 *)&D_1F8003C8)) && (*(P38_34C14 *)&PLAYER).b04 == 1 && (*(P38_34C14 *)&PLAYER).ba4 == 0)

void func_80034C14(GameObject *o)
{
    extern s16 angleBetweenPoints(XY_34C14, XY_34C14);
    extern void advanceAnimFrame(GameObject *, s32);
    extern D600_34C14 D_8009C968;
    extern G338_34C14 *D_8009B6A0;
    extern G330_34C14 *D_8009B698;
    extern s16 D_8007D608[];
    extern s16 D_8007D5E4[];
    XY_34C14 t, c;
    s16 dx, dy;
    s16 i;
    s16 v;
    s16 n;
    s32 k;
    s16 v2;

    D_8009B698->w2e = 0xffff;
    switch (o->step) {
    case 0:
        o->animFrame = (*(P38_34C14 *)&PLAYER).animFrame;
        (*(P38_34C14 *)&PLAYER).b9d = 1;
        D_8009B698->b7 = o->animFrame;
        v = D_8007D60C[TB(o)];
        o->unkA = 0;
        o->active = 2;
        o->unkAA = v;
        D_8009B6A0->b0c = 0;
        D_8009B698->w22 = 0;
        D_8009C968.b = 0;
        D_8009B6A0->w30 = 1;
        D_8009B6A0->w32 = 0;
        D_8009B6A0->w34 = 0;
        D_8009B6A0->w36 = 0;
        o->unkA8 = 0;
        if (PLAYER_P38_34C14.b9e == 4 || PLAYER_P38_34C14.b9e == 7) {
            o->unk94 = (s32)D_8009E454;
            *D_8009E454 = 2;
        }
        IDX(o, i);
        if (o->animFrame & 1) dx = 160 - D_8007D5E4[i];
        else dx = D_8007D5E4[i] - 32;
        dy = D_8007D5E6[i];
        if (o->animFrame >= 6) {
            k = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
            if (o->animFrame & 1) v2 = k - 4;
            else v2 = k + 4;
            o->velX = v2;
            o->velY = PLAYER_P38_34C14.y.p.whole + fixedMulSin((u8)dx, dy);
        } else {
            o->velX = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
            o->velY = PLAYER_P38_34C14.y.p.whole + fixedMulSin((u8)dx, dy);
        }
        o->h->p.whole = o->velX + ((s16 (*)(s32, s32))fixedMulCos)(((u16)o->unkAA + 0x80) & 0xff, 16);
        o->y.p.whole = o->velY + fixedMulSin(((u16)o->unkAA + 0x80) & 0xff, 16);
        o->d->p.whole = (*(P38_34C14 *)&PLAYER).d->p.whole;
        o->unkA5 = 1;
        o->hitOffsetX = 6;
        o->hitOffsetY = 6;
        o->hitWidth = 12;
        o->hitHeight = 12;
        D_8009B6A0->b0d = 0;
        switch (D_8009B698->b0) {
        case 2:
            o->unkA8 = 0x1400;
            playSFXWithNote(3, 2);
            o->unk98 = 1;
            break;
        case 1:
            o->unkA8 = 0x1900;
            playSFXWithNote(3, 8);
            o->unk98 = 2;
            break;
        }
        o->velH = ((s16 (*)(s32, s32))fixedMulCos)(o->unkAA, o->unkA8);
        o->velV = fixedMulSin(o->unkAA, o->unkA8);
        D_8009B698->w28 = 0xffff;
        D_8009B698->w2a = 0xffff;
        func_800348FC(o);
        advanceAnimFrame((GameObject *)&(*(P38_34C14 *)&PLAYER), 0);
        o->unkAA += 0x80;
        o->step++;
        break;
    case 1:
        tickAnimation((GameObject *)&(*(P38_34C14 *)&PLAYER));
        IDX(o, i);
        if (o->animFrame & 1) dx = 160 - D_8007D5E4[i];
        else dx = D_8007D5E4[i] - 32;
        dy = D_8007D5E6[i];
        if (o->animFrame >= 6) {
            k = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
            if (o->animFrame & 1) v2 = k - 4;
            else v2 = k + 4;
            o->velX = v2;
            o->velY = PLAYER_P38_34C14.y.p.whole + fixedMulSin((u8)dx, dy);
        } else {
            o->velX = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
            o->velY = PLAYER_P38_34C14.y.p.whole + fixedMulSin((u8)dx, dy);
        }
        o->h->p.whole = o->velX + ((s16 (*)(s32, s32))fixedMulCos)((u8)o->unkAA, 16);
        o->y.p.whole = o->velY + fixedMulSin((u8)o->unkAA, 16);
        {
            n = TB(o);
            o->unkAA += D_8007D60A[n];
            if (o->animFrame & 1) {
                if (o->unkAA < D_8007D60A[n + 1] + 0x40) {
                    func_8003473C(o);
                    o->unkAA = D_8007D60A[n + 1];
                    D_8009B6A0->b0c = 1;
                    (*(P38_34C14 *)&PLAYER).d8c = 0;
                    o->timer = 1;
                    o->step++;
                }
            } else {
                if (o->unkAA > D_8007D60A[n + 1] + 0xc0) {
                    func_8003473C(o);
                    o->unkAA = D_8007D60A[n + 1];
                    D_8009B6A0->b0c = 1;
                    (*(P38_34C14 *)&PLAYER).d8c = 0;
                    o->timer = 1;
                    o->step++;
                }
            }
        }
        break;
    case 2:
        if (o->timer != 0 && --o->timer <= 0) {
            o->timer = 0;
            o->active = 1;
            o->step++;
        }
    case 3:
        D_8009B6A0->w30 += (s16)o->unkA8 >> 8;
        if (D_8009B6A0->w30 > 0x60 - D_8009B698->b0 * 16)
            D_8009B6A0->w30 = 0x60 - (D_8009B698->b0 << 4);
        D_8009B6A0->w32 -= ((s16)o->unkA8 >> 8) * 2;
        if (D_8009B6A0->w32 < 0) D_8009B6A0->w32 = 0;
        {
            s16 s = o->unkA8 - 0x200;
            o->unkA8 = s;
            o->velH = ((s16 (*)(s32, s32))fixedMulCos)(o->unkAA, s);
        }
        o->velV = fixedMulSin(o->unkAA, o->unkA8);
        applyObjectSpeedXY(o);
        if (o->active == 1 && probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole) != 0) {
            u16 u;
            s32 m;
            func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            u = D_1F800282;
            m = u >> 5 & 0xf;
            if ((u & 0x3000) == 0 && m < 4 && m != 0)
                func_800EA35C(o->h->p.whole, o->y.p.whole, o->d->p.whole, (u8)o->animFrame);
            playSFX(5);
            o->unkA8 = 0x4ff;
        }
        (*(P38_34C14 *)&PLAYER).d8c = 0;
        if (o->unkA8 >= 0x500) break;
        {
            u16 w = D_8007D60C[TB(o)];
            o->unkAA = w;
            o->velX = o->h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((w + 0x80) & 0xff, 24);
        }
        o->velY = o->y.p.whole + fixedMulSin(((u16)o->unkAA + 0x80) & 0xff, 24);
        {
            G338_34C14 *q = D_8009B6A0;
            q->b0c = 2;
            q->w32 = 0;
            D_8009B6A0->w0e = 0;
        }
        if (o->visible) {
            s32 x = o->x.p.whole;
            func_8002F05C(o, (s16)((o->animFrame & 1) ? x - 16 : x + 16), o->y.p.whole, o->z.p.whole);
        }
        o->step++;
        break;
    case 4:
        D_8009B6A0->w30 -= ((s16)o->unkA8 >> 8) * 2;
        if (D_8009B6A0->w30 < 0) D_8009B6A0->w30 = 0;
        o->h->p.whole = o->velX + ((s16 (*)(s32, s32))fixedMulCos)(((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff, 24);
        o->y.p.whole = o->velY + fixedMulSin(((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff, 24);
        D_8009B6A0->w0e += D_8007D60A[TB(o)] >> 1;
        PLAYER_P38_34C14.d8c = 0;
        if (o->animFrame & 1) {
            {
                u8 b = 1;
                if (D_8009B6A0->w0e < -32) b = 2;
                D_8009B6A0->b0d = b;
            }
            if (D_8009B6A0->w0e >= -64) break;
            o->unkAA = ((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff;
            D_8009B6A0->b0c = 3;
            func_8003481C(o);
            advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, 0);
            D_8009B6A0->w0e = (D_8007D60A[TB(o) + 1] - 0x40) & 0xff;
            o->unkA5 = 0;
            o->active = 2;
            o->step++;
        } else {
            {
                u8 b = 1;
                if (D_8009B6A0->w0e > 32) b = 2;
                D_8009B6A0->b0d = b;
            }
            if (D_8009B6A0->w0e <= 64) break;
            o->unkAA = ((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff;
            D_8009B6A0->b0c = 3;
            func_8003481C(o);
            advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, 0);
            D_8009B6A0->w0e = (D_8007D60A[TB(o) + 1] + 0x40) & 0xff;
            o->unkA5 = 0;
            o->active = 2;
            o->step++;
        }
        break;
    case 5:
        D_8009B6A0->b0d = 0;
        o->unkA8 = 0x1400;
        D_8009B6A0->w30 += 20;
        if (D_8009B6A0->w30 > 0x60 - D_8009B698->b0 * 16)
            D_8009B6A0->w30 = 0x60 - (D_8009B698->b0 << 4);
        D_8009B6A0->w32 -= (s16)o->unkA8 >> 8;
        if (D_8009B6A0->w32 < 0) D_8009B6A0->w32 = 0;
        if (o->animFrame & 1) o->velX = PLAYER.obj.h->p.whole + 16;
        else o->velX = PLAYER.obj.h->p.whole - 16;
        o->velY = (*(P38_34C14 *)&PLAYER).y.p.whole - 16;
        t.x = o->velX + ((s16 (*)(s32, s32))fixedMulCos)(D_8009B6A0->w0e, 12);
        t.y = o->velY + fixedMulSin(D_8009B6A0->w0e, 12);
        c.x = o->h->p.whole;
        c.y = o->y.p.whole;
        o->unkAA = angleBetweenPoints(c, t);
        o->velH = ((s16 (*)(s32, s32))fixedMulCos)(o->unkAA, o->unkA8);
        o->velV = fixedMulSin(o->unkAA, o->unkA8);
        applyObjectSpeedXY(o);
        dx = t.x - c.x + 16;
        dy = t.y - c.y + 16;
        if ((u16)dx >= 32 || (u16)dy >= 32) break;
        o->unkAA = D_8007D60C[TB(o)] + 0x80;
        if (o->animFrame & 1) {
            {
                s16 pv = PLAYER.obj.h->p.whole;
                o->unkAA = (*(volatile u16 *)&o->unkAA + 0x40) & 0xff;
                o->velX = pv + 16;
            }
        } else {
            {
                s16 pv = PLAYER.obj.h->p.whole;
                o->unkAA = (*(volatile u16 *)&o->unkAA - 0x40) & 0xff;
                o->velX = pv - 16;
            }
        }
        o->velY = (*(P38_34C14 *)&PLAYER).y.p.whole - 16;
        o->h->p.whole = o->velX + ((s16 (*)(s32, s32))fixedMulCos)(o->unkAA, 12);
        o->y.p.whole = o->velY + fixedMulSin(o->unkAA, 12);
        D_8009B6A0->w32 = 0;
        D_8009B6A0->w0e = 0;
        D_8009B6A0->b0c = 0;
        (*(P38_34C14 *)&PLAYER).b9d = 0;
        o->unkA5 = 0;
        o->step++;
        break;
    case 6:
        if (o->animFrame & 1) o->velX = PLAYER.obj.h->p.whole + 16;
        else o->velX = PLAYER.obj.h->p.whole - 16;
        o->velY = PLAYER_P38_34C14.y.p.whole - 16;
        tickAnimation((GameObject *)&PLAYER_P38_34C14);
        D_8009B6A0->w0e += D_8007D60A[TB(o)];
        if (o->animFrame & 1) {
            if (D_8009B6A0->w0e < -64) {
                if (PLAYER_P38_34C14.b9e == 4 || PLAYER_P38_34C14.b9e == 7)
                    *(u8 *)o->unk94 = D_8009B698->b6;
                if (PADOK() && (*(P38_34C14 *)&PLAYER).bac < 2 && D_8009BCA7_U8 == 0) {
                    func_800EBA70((*(u8 *)&D_8009C61A), o);
                    (*(P38_34C14 *)&PLAYER).b9d = 0;
                    D_8009B6A0->w0e = 0;
                    o->unkAA -= 0x40;
                    o->step++;
                } else {
                    PLAYER_P38_34C14.b9d = 0;
                    D_8009B6A0->b0c = 0;
                    D_8009B698->b0 = 0;
                    o->state = 2;
                    o->subState = 0;
                    o->step = 0;
                }
            }
        } else if (D_8009B6A0->w0e > 64) {
            if (PLAYER_P38_34C14.b9e == 4 || PLAYER_P38_34C14.b9e == 7)
                *(u8 *)o->unk94 = D_8009B698->b6;
            if (!PADOK() || (*(P38_34C14 *)&PLAYER).bac >= 2 || D_8009BCA7_U8 != 0) {
                PLAYER_P38_34C14.b9d = 0;
                D_8009B6A0->b0c = 0;
                D_8009B698->b0 = 0;
                o->state = 2;
                o->subState = 0;
                o->step = 0;
            } else {
                func_800EBA70((*(u8 *)&D_8009C61A), o);
                (*(P38_34C14 *)&PLAYER).b9d = 0;
                D_8009B6A0->w0e = 0;
                o->unkAA += 0x40;
                o->step++;
            }
        }
        o->h->p.whole = o->velX + ((s16 (*)(s32, s32))fixedMulCos)(((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff, 12);
        o->y.p.whole = o->velY + fixedMulSin(((u16)o->unkAA + (u16)D_8009B6A0->w0e) & 0xff, 12);
        break;
    case 7:
        o->animFrame = PLAYER_P38_34C14.animFrame;
        func_800348FC(o);
        advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, 0);
        if ((D_1F8001F8 & 0xf) == 0) {
            func_80028A74(0, 0, 0xc0, 2);
            playSFX(3);
        }
        advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, D_8009B698->w22 >> 2 & 3);
        n = TB(o);
        D_8009C968.a = 10;
        D_8009C968.b = 2;
        D_8009C968.c = D_8007D608[n];
        o->unkAA += D_8007D60A[n];
        if (o->unkAA >= 0x100) o->unkAA -= 0x100;
        if (o->unkAA < 0) o->unkAA += 0x100;
        IDX(o, i);
        if (o->animFrame & 1) dx = 0x80 - D_8007D5E4[i];
        else dx = D_8007D5E4[i];
        dy = D_8007D5E6[i];
        o->velX = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
        o->velY = (*(P38_34C14 *)&PLAYER).y.p.whole + fixedMulSin((u8)dx, dy);
        func_800349DC(&D_8009C968, o->unkAA, &dx, &dy);
        o->h->p.whole = o->velX + dx;
        o->y.p.whole = o->velY + dy;
        if (!PADOK() || D_8009BCA7_U8 != 0) {
            (*(P38_34C14 *)&PLAYER).b9d = 1;
            D_8009B698->b0 = 2;
            D_8009B698->w22 = 0;
            o->step = 0;
        } else {
            D_8009B698->w22++;
        }
        if (D_8009B698->w22 < 61) break;
        D_8009B698->w22 = 0;
        o->step++;
        break;
    case 8:
        o->animFrame = PLAYER_P38_34C14.animFrame;
        func_800348FC(o);
        advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, 0);
        if ((D_1F8001F8 & 0xf) == 0) {
            func_80028A74(0, 0, 0xff, 2);
            playSFXWithNote(3, 6);
        }
        advanceAnimFrame((GameObject *)&PLAYER_P38_34C14, D_8009B698->w22 / 3 & 3);
        o->animFrame = PLAYER_P38_34C14.animFrame;
        n = TB(o);
        D_8009C968.a = 16;
        D_8009C968.b = 4;
        D_8009C968.c = D_8007D608[n];
        o->unkAA += D_8007D60A[n];
        if (o->unkAA >= 0x100) o->unkAA -= 0x100;
        if (o->unkAA < 0) o->unkAA += 0x100;
        IDX(o, i);
        if (o->animFrame & 1) dx = 0x80 - D_8007D5E4[i];
        else dx = D_8007D5E4[i];
        dy = D_8007D5E6[i];
        o->velX = PLAYER.obj.h->p.whole + ((s16 (*)(s32, s32))fixedMulCos)((u8)dx, dy);
        o->velY = (*(P38_34C14 *)&PLAYER).y.p.whole + fixedMulSin((u8)dx, dy);
        func_800349DC(&D_8009C968, o->unkAA, &dx, &dy);
        o->h->p.whole = o->velX + dx;
        o->y.p.whole = o->velY + dy;
        if (!PADOK() || D_8009BCA7_U8 != 0) {
            D_8009B698->b0 = 1;
            D_8009B698->w22 = 0;
            (*(P38_34C14 *)&PLAYER).b9d = 1;
            o->step = 0;
        }
        D_8009B698->w22++;
        break;
    }
    if ((*(P38_34C14 *)&PLAYER).bac >= 2) {
        char pad[16];
        D_8009C650 = (*(P38_34C14 *)&PLAYER).de4;
        D_8009B698->b8 = 0;
        (*(P38_34C14 *)&PLAYER).step = 14;
        (*(P38_34C14 *)&PLAYER).ba5 = 0;
        (*(P38_34C14 *)&PLAYER).state = 0;
        (*(P38_34C14 *)&PLAYER).substep = 0;
        D_8009B698->w2c = 13;
        if (D_8009B698->w2e != 13) {
            func_800EEF64(o);
            advanceAnimFrame(o, 0);
            D_8009B698->w2e = D_8009B698->w2c;
        }
        D_8009B698->w2e = 0xffff;
        (*(P38_34C14 *)&PLAYER).b9d = 0;
        D_8009B6A0->b0c = 0;
        D_8009B698->b0 = 0;
        o->state = 2;
        o->subState = 0;
        o->step = 0;
    }
}
#undef IDX
#undef TB
#undef PADOK

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036440);
void func_80036440(u8* self)
{
    switch (self[5]) {
    case 0:
        func_80034C14(self);
        break;
    case 1:
        func_80034C14(self);
        break;
    case 2:
        func_80034C14(self);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036494);
extern u8 *D_8009B6A0;
extern u8 *D_8009B698;
extern s8 D_800A547B;
extern void freeObjectLayer1(GameObject *);
void func_80036494(GameObject *o)
{
    if (D_800A545F != 0)
        o->state = 2;
    switch (o->state) {
    case 0:
        func_80034AB8(o);
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_80034C14(o);
            break;
        case 1:
            func_80034C14(o);
            break;
        case 2:
            func_80034C14(o);
            break;
        }
        break;
    case 2:
        D_8009B6A0[0xc] = 0;
        *D_8009B698 = 0;
        if (--D_800A547B < 0)
            D_800A547B = 0;
        o->state = 3;
        break;
    case 3:
        freeObjectLayer1(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_800365DC);
void func_800365DC(u8* self)
{
    if (self[6] == 0) {
        *(s16*)(self + 0x22) = 0;
        func_800384F0(self, D_8009C61A[0] - 5);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036618);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", isPlayerInRange);
s32 isPlayerInRange(u8* self, s16 arg1, s16 arg2)
{
    u16 dx;
    u16 dy;

    dx = arg1 + (*(u16*)((u8*)D_800A53D8 + 2) - *(u16*)(*(u8**)(self + 0x40) + 2));
    if ((s32)dx <= arg1 * 2) {
        dy = arg2 + (PLAYER.obj.y.p.whole - *(u16*)(self + 0x16));
        return (s32)dy <= arg2 * 2;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", angleToPlayer);

s32 angleBetweenPoints(Vec2s a, Vec2s b);

s16 angleToPlayer(u8* self) {
    Vec2s player;
    Vec2s me;

    me.x = (*(s16**)(self + 0x40))[1];
    me.y = *(s16*)(self + 0x16);
    player.x = PLAYER.obj.h->p.whole;
    player.y = PLAYER.obj.y.p.whole;
    return angleBetweenPoints(me, player);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036A8C);
extern void applyObjectSpeedXY(GameObject *);
extern s16 probeCollisionAtDepthB(GameObject *, s32, s32);
extern void func_800224FC(s32, s32, s32, s32);
extern void func_800EA35C(s32, s32, s32, s32);
extern void playSFX(s32);
extern u16 D_1F800282;
extern u8 D_800A5435[];

static __inline__ void f_36A8C(GameObject *q)
{
    q->unkAA = D_8007D60C[(s16)(q->animFrame + q->animFrame * 2)];
    D_800A5435[0] = 0;
    *D_8009B698 = 0;
    func_800EEDE0(q);
}

s32 func_80036A8C(GameObject *o)
{
    extern s32 D_800A5424[];
    s32 r;
    u8 *p;
    s16 t;
    u16 u;
    s32 m;
    r = 0;
    o->unk84 = 0x200;
    t = o->unkA8 - 0x200;
    o->unk88 = o->unk88 + 0x100 & 0xfff;
    o->unkA8 = t;
    o->velH = fixedMulCos((u8)o->unkAA, t);
    o->velV = fixedMulSin((u8)o->unkAA, o->unkA8);
    applyObjectSpeedXY(o);
    if (o->active == 1 && probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole) != 0) {
        func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        u = D_1F800282;
        m = u >> 5 & 0xf;
        if ((u & 0x3000) == 0 && m < 4 && m != 0)
            func_800EA35C(o->h->p.whole, o->y.p.whole, o->d->p.whole, (u8)o->animFrame);
        playSFX(5);
        o->unkA8 = 0x4ff;
    }
    D_800A5424[0] = 0;
    if (o->unkA8 < 0x500) {
        f_36A8C(o);
        r = 1;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036C14);
s32 func_80036C14(u8* self)
{
    s32 r = 0;
    s16 v = func_80036618(self);

    switch (v) {
    case 0:
    case 1:
        *(s16*)(self + 0x20) = 5;
        break;
    case 2:
        *(s16*)(self + 0x20) = 5;
        r = 1;
        break;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036C88);
typedef struct { char p0[6]; u8 step; char p1[0x20 - 7]; s16 timer; char p2[0x2e - 0x22]; u16 af; char p3[0x7a - 0x30]; s16 w7a; char p4[0xaa - 0x7c]; s16 waa; s16 wac; } O_36C88;
extern s32 D_800A5424;
extern void advanceAnimFrame(char *, s32);

void func_80036C88(O_36C88 *o)
{
    s32 f;
    s16 r;
    s16 s;
    s16 t;
    f = o->af;
    f = f * 3;
    func_8003473C();
    advanceAnimFrame(&PLAYER.obj, 0);
    o->wac = D_8007D60C[(s16)f];
    switch (o->af & 7) {
    case 0:
    case 2:
        o->waa = 0;
        break;
    case 1:
    case 3:
        o->waa = 0x7f;
        break;
    case 4:
        o->waa = 0x20;
        break;
    case 5:
        o->waa = 0x60;
        break;
    case 6:
    case 7:
        o->waa = 0x40;
        break;
    }
    r = 0;
    o->w7a = 2;
    D_800A5424 = 0;
    s = func_80036618(o);
    switch (s) {
    case 0:
    case 1:
        o->timer = 5;
        break;
    case 2:
        o->timer = 5;
        r = 1;
        break;
    }
    o->step = r ? 3 : 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036DB0);
s16 func_80036DB0(void)
{
    s16 r = 0;

    switch (PLAYER.obj.subState) {
    case 5:
    case 6:
    case 7:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 21:
    case 22:
    case 23:
    case 27:
    case 29:
    case 30:
    case 32:
    case 33:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 46:
    case 47:
    case 48:
    case 51:
    case 52:
    case 53:
    case 54:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 69:
        r++;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036DF8);

void func_80036DF8(u8 *o)
{
    s16 flag;
    if (PLAYER.obj.unk9E == 4 || PLAYER.obj.unk9E == 7) {
        if (((s8 *)D_8009B698)[4] == 0) {
            D_800A545E = 1;
            D_8009B698[0] = 2;
            o[5] = 1;
            PLAYER.obj.subState = 0x18;
            PLAYER.obj.step = 1;
            return;
        }
    } else {
        flag = 0;
        switch (PLAYER.obj.subState) {
        case 5: case 6: case 7: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf:
        case 0x10: case 0x11: case 0x12: case 0x15: case 0x16: case 0x17: case 0x1b:
        case 0x1d: case 0x1e: case 0x20: case 0x21: case 0x23: case 0x24: case 0x25:
        case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2e:
        case 0x2f: case 0x30: case 0x33: case 0x34: case 0x35: case 0x36: case 0x38:
        case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x45:
            flag++;
        }
        if (flag == 0) {
            o[5] = 0;
            D_800A545E = 1;
            D_8009B698[0] = 2;
            switch (D_800A5434) {
            case 0:
                PLAYER.obj.subState = 3;
                PLAYER.obj.step = 1;
                break;
            case 1:
                D_800A5424 = 0;
                PLAYER.obj.subState = 4;
                if (D_8009B698[8] != 0)
                    PLAYER.obj.step = 2;
                else
                    PLAYER.obj.step = 1;
                break;
            case 2:
                PLAYER.obj.subState = 4;
                D_800A5424 = 0;
                PLAYER.obj.step = 3;
                break;
            }
            return;
        }
    }
    o[4] = 2;
    o[5] = 0;
    o[6] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036F98);
typedef struct V2_36F98 { s16 x, y; } V2_36F98;
typedef struct {
    u8 b0; char p1[6]; u8 b7; char p8[0x22 - 8];
    u16 w22; char p24[4]; u16 w28, w2a; char p2c[2]; u16 w2e;
} P_36F98;
typedef struct { s16 w0, w2, w4; } D600_36F98;
extern P_36F98 *D_8009B698_P_36F98Ptr asm("D_8009B698");
extern u8 D_800A5436[];
extern D600_36F98 D_8009C968;
extern u16 D_8007D5E4[];
extern u16 D_8007D608[];
extern u8 D_800A5444;
extern u8 D_8009BCF8;
extern s32 tickAnimation(GameObject *);

static __inline__ s16 dir_36F98(GameObject *o)
{
    V2_36F98 b, a;
    a.x = o->h->p.whole;
    a.y = o->y.p.whole;
    b.x = PLAYER.obj.h->p.whole;
    b.y = PLAYER.obj.y.p.whole;
    return ((s16 (*)(V2_36F98, V2_36F98))angleBetweenPoints)(a, b);
}
#define DIR dir_36F98

static __inline__ s16 near_36F98(GameObject *o, s32 d, s32 w)
{
    if ((u16)(PLAYER.obj.h->p.whole - o->h->p.whole + d) > w) return 0;
    if ((u16)(PLAYER.obj.y.p.whole - o->y.p.whole + d) > w) return 0;
    return 1;
}

#define SPIN(o) \
    { if ((o)->animFrame & 1) (o)->unk88 = ((o)->unk88 + 0x300) & 0xfff; else (o)->unk88 = ((o)->unk88 - 0x300) & 0xfff; }

#define IDX(o, idx) \
    idx = (o)->subState * 6; \
    switch ((o)->animFrame) { \
    case 0: case 1: case 2: case 3: break; \
    case 4: case 5: idx += 2; break; \
    case 6: case 7: idx += 4; break; \
    }

void func_80036F98(GameObject *o)
{
    V2_36F98 vb, va;
    s16 a, r;
    s16 idx;
    s16 k;
    s16 s;
    s32 f;
    u16 w;
    u8 c;
    u16 cc;
    u8 *q;
    P_36F98 *p;

    switch (o->step) {
    case 0:
        p = D_8009B698_P_36F98Ptr;
        o->animFrame = PLAYER.obj.animFrame;
        D_800A5435[0] = 1;
        p->b7 = o->animFrame;
        k = D_8007D60A[(s16)(o->animFrame + o->animFrame * 2) + 1];
        o->active = 2;
        o->unkAA = k;
        *(u16 *)((char *)D_8009B698_P_36F98Ptr + 0x22) = 0;
        D_8009C968.w2 = 0;
        o->unkA8 = 0;
        o->unk74 = 0;
        o->objectIndex = 0;
        c = D_800A5436[0];
        o->objectIndex = c;
        switch (c) {
        case 4:
            q = D_8009E454;
            k = *q;
            o->unk74 = k;
            *q = 2;
            goto set94;
        case 7:
            p = (P_36F98 *)D_8009E454;
            o->unk74 = p->b0;
            p->b0 = 5;
        set94:
            o->unk94 = (s32)D_8009E454;
            break;
        }
        IDX(o, idx);
        if (o->animFrame & 1) a = 0xa0 - D_8007D5E4[idx]; else a = D_8007D5E4[idx] - 0x20;
        r = D_8007D5E4[idx + 1];
        o->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)a, r);
        o->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)a, r);
        o->h->p.whole = o->velX + fixedMulCos(((u16)o->unkAA + 0x80) & 0xff, 0x10);
        o->y.p.whole = o->velY + fixedMulSin(((u16)o->unkAA + 0x80) & 0xff, 0x10);
        o->d->p.whole = PLAYER.obj.d->p.whole;
        o->unkA5 = 1;
        p = D_8009B698_P_36F98Ptr;
        o->hitOffsetX = 6;
        o->hitOffsetY = 6;
        o->hitWidth = 0xc;
        o->hitHeight = 0xc;
        f = p->b0;
        switch (f) {
        case 2:
            o->unkA8 = 0x1600;
            playSFXWithNote(3, 2);
            o->unk98 = 1;
            if (D_8009C61A[0] - 5 == f) o->unk98 = 2;
            break;
        case 1:
            o->unkA8 = 0x1a00;
            playSFXWithNote(3, 8);
            o->unk98 = 2;
            break;
        }
        o->velH = fixedMulCos((u8)o->unkAA, o->unkA8);
        o->velV = fixedMulSin((u8)o->unkAA, o->unkA8);
        D_8009B698_P_36F98Ptr->w28 = 0xffff;
        D_8009B698_P_36F98Ptr->w2a = 0xffff;
        func_800348FC(o);
        advanceAnimFrame(&PLAYER.obj, 0);
        o->step++;
        o->unkAA += 0x80;
        D_8009B698_P_36F98Ptr->w2e = 0xffff;
        func_800EBA70(D_8009C61A[0], o);
        break;
    case 1:
        SPIN(o);
        o->unk84 = 0x100;
        o->unk8C = 0;
        tickAnimation(&PLAYER.obj);
        IDX(o, idx);
        if (o->animFrame & 1) a = 0xa0 - D_8007D5E4[idx]; else a = D_8007D5E4[idx] - 0x20;
        r = D_8007D5E4[idx + 1];
        o->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)a, r);
        o->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)a, r);
        o->h->p.whole = o->velX + fixedMulCos((u8)o->unkAA, 0x10);
        o->y.p.whole = o->velY + fixedMulSin((u8)o->unkAA, 0x10);
        k = o->animFrame + o->animFrame * 2;
        o->unkAA += D_8007D60A[k];
        if (o->animFrame & 1) {
            s32 x = (s16)o->unkAA, y = D_8007D60A[k + 1] + 0x40;
            if (x < y) func_80036C88(o);
        } else {
            s32 y = (s16)o->unkAA, x = D_8007D60A[k + 1] + 0xc0;
            if (x < y) func_80036C88(o);
        }
        break;
    case 2:
        if (o->unk7A > 0 && --o->unk7A <= 0) o->active = 1;
        SPIN(o);
        o->unk84 = (o->unk84 - 0x80) & 0xfff;
        {
            s32 w, cc, g;
            if (o->animFrame & 1) {
                cc = (u16)o->unkAC;
                w = ((u16)o->unkAA - 2) & 0xff;
                o->unkAA = w;
                w = w < cc;
            } else {
                cc = (u16)o->unkAC;
                w = ((u16)o->unkAA + 2) & 0xff;
                o->unkAA = w;
                w = cc < w;
            }
            if (w) o->unkAA = cc & 0xff;
        }
        if (--o->timer <= 0) {
            s16 g;
            o->timer = 5;
            g = 0;
            switch (func_80036618(o)) {
            case 0:
            case 1:
                o->timer = 5;
                break;
            case 2:
                o->timer = 5;
                g = 1;
                break;
            }
            o->step = g ? 3 : 2;
        }
        if (((s16 (*)(GameObject *))func_80036A8C)(o) == 0) break;
        if (o->animFrame & 1)
            o->unkAA = (o->unkAA - 0x40) & 0xff;
        else
            o->unkAA = (o->unkAA + 0x40) & 0xff;
        o->step = 4;
        o->timer = 0;
        D_8009B698_P_36F98Ptr->w2e = 0xff;
        break;
    case 3:
        if (o->unk7A > 0 && --o->unk7A <= 0) o->active = 1;
        SPIN(o);
        o->unk84 = (o->unk84 - 0x80) & 0xfff;
        {
            s32 w, cc, g;
            if (o->animFrame & 1) {
                cc = (u16)o->unkAC;
                w = ((u16)o->unkAA + 2) & 0xff;
                o->unkAA = w;
                w = cc < w;
            } else {
                cc = (u16)o->unkAC;
                w = ((u16)o->unkAA - 2) & 0xff;
                o->unkAA = w;
                w = w < cc;
            }
            if (w) o->unkAA = cc & 0xff;
        }
        if (--o->timer <= 0) {
            s16 g;
            o->timer = 5;
            g = 0;
            switch (func_80036618(o)) {
            case 0:
            case 1:
                o->timer = 5;
                break;
            case 2:
                o->timer = 5;
                g = 1;
                break;
            }
            o->step = g ? 3 : 2;
        }
        if (((s16 (*)(GameObject *))func_80036A8C)(o) == 0) break;
        if (o->animFrame & 1)
            o->unkAA = (o->unkAA + 0x40) & 0xff;
        else
            o->unkAA = (o->unkAA - 0x40) & 0xff;
        o->step = 4;
        o->timer = 0;
        D_8009B698_P_36F98Ptr->w2e = 0xff;
        break;
    case 4:
        SPIN(o);
        o->unk84 = (o->unk84 - 0x80) & 0xfff;
        if (--o->timer <= 0) {
            s = DIR(o);
            o->timer = 2;
            o->unkAC = (s - o->unkAA) & 0xff;
        }
        if ((u16)o->unkAC < 0x80)
            o->unkAA = (o->unkAA + 10) & 0xff;
        else
            o->unkAA = (o->unkAA - 10) & 0xff;
        o->unkA8 += 0x80;
        if (o->unkA8 > 0x1a00) o->unkA8 = 0x1a00;
        o->velH = fixedMulCos(o->unkAA, o->unkA8);
        o->velV = fixedMulSin(o->unkAA, o->unkA8);
        applyObjectSpeedXY(o);
        if (near_36F98(o, 0x20, 0x40)) {
            o->unkA8 = 0x1a00;
            o->step = 6;
        }
        break;
    case 6:
        o->unkAA = DIR(o);
        SPIN(o);
        o->unk84 = (o->unk84 - 0x80) & 0xfff;
        o->velH = fixedMulCos((u8)o->unkAA, o->unkA8);
        o->velV = fixedMulSin((u8)o->unkAA, o->unkA8);
        applyObjectSpeedXY(o);
        if (near_36F98(o, 0x10, 0x20)) {
            u32 m;
            o->unkA5 = 0;
            D_800A5435[0] = 0;
            o->unkAA = (o->unkAA - 0x40) & 0xff;
            o->step++;
            m = D_8009C61A[0] - 5;
            if (o->objectIndex == 7) {
                *(u8 *)o->unk94 = o->unk74;
                o->objectIndex = 0;
            }
            if (o->objectIndex == 4 && ((u8 *)o->unk94)[2] == 0x1d) {
                *(u8 *)o->unk94 = o->unk74;
                o->objectIndex = 0;
            }
            if ((D_8009C9D8[0] & (*(u16 *)&D_1F8003C8)) == 0 || D_800A539C != 1 || D_800A543C != 0 ||
                D_800A5444 >= 2 || D_800A545E != 0 || D_8009BCA7 != 0 || m >= 4 ||
                (u8)(D_8009BCF8 - 1) < 2 || D_800A545F != 0) {
                o->state = 2;
                o->subState = 0;
                o->step = 0;
            } else {
                func_80036DF8(o);
            }
        }
        break;
    case 7:
        SPIN(o);
        o->unk8C = 0;
        o->unk84 = 0x200;
        o->animFrame = PLAYER.obj.animFrame;
        func_800348FC(o);
        advanceAnimFrame(&PLAYER.obj, 0);
        if ((D_1F8001F8 & 0xf) == 0) {
            func_80028A74(0, 0, 0xc0, 2);
            playSFX(3);
        }
        advanceAnimFrame(&PLAYER.obj, (D_8009B698_P_36F98Ptr->w22 >> 2) & 3);
        k = o->animFrame + o->animFrame * 2;
        D_8009C968.w0 = 10;
        D_8009C968.w2 = 2;
        D_8009C968.w4 = D_8007D608[k];
        o->unkAA += D_8007D60A[k];
        if (o->unkAA > 0xff) o->unkAA -= 0x100;
        if (o->unkAA < 0) o->unkAA += 0x100;
        IDX(o, idx);
        if (o->animFrame & 1) a = 0x80 - D_8007D5E4[idx]; else a = D_8007D5E4[idx];
        r = D_8007D5E4[idx + 1];
        o->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)a, r);
        o->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)a, r);
        func_800349DC(&D_8009C968, o->unkAA, &a, &r);
        o->h->p.whole = o->velX + a;
        o->y.p.whole = o->velY + r;
        if ((D_8009C9D8[0] & (*(u16 *)&D_1F8003C8)) == 0 || D_800A539C != 1 || D_800A543C != 0 || D_8009BCA7 != 0) {
            D_800A545E = 0;
            D_8009B698_P_36F98Ptr->b0 = 2;
            D_8009B698_P_36F98Ptr->w22 = 0;
            o->step = 0;
        } else {
            D_8009B698_P_36F98Ptr->w22++;
        }
        if (D_8009B698_P_36F98Ptr->w22 > 0x3c) {
            D_8009B698_P_36F98Ptr->w22 = 0;
            o->step++;
        }
        break;
    case 8:
        SPIN(o);
        o->unk8C = 0;
        o->unk84 = 0x200;
        o->animFrame = PLAYER.obj.animFrame;
        func_800348FC(o);
        advanceAnimFrame(&PLAYER.obj, 0);
        if ((D_1F8001F8 & 0xf) == 0) {
            func_80028A74(0, 0, 0xff, 2);
            playSFXWithNote(3, 6);
        }
        advanceAnimFrame(&PLAYER.obj, (D_8009B698_P_36F98Ptr->w22 / 3) & 3);
        o->animFrame = PLAYER.obj.animFrame;
        k = o->animFrame + o->animFrame * 2;
        D_8009C968.w0 = 0x10;
        D_8009C968.w2 = 4;
        D_8009C968.w4 = D_8007D608[k];
        o->unkAA += D_8007D60A[k];
        if (o->unkAA > 0xff) o->unkAA -= 0x100;
        if (o->unkAA < 0) o->unkAA += 0x100;
        IDX(o, idx);
        if (o->animFrame & 1) a = 0x80 - D_8007D5E4[idx]; else a = D_8007D5E4[idx];
        r = D_8007D5E4[idx + 1];
        o->velX = PLAYER.obj.h->p.whole + fixedMulCos((u8)a, r);
        o->velY = PLAYER.obj.y.p.whole + fixedMulSin((u8)a, r);
        func_800349DC(&D_8009C968, o->unkAA, &a, &r);
        o->h->p.whole = o->velX + a;
        o->y.p.whole = o->velY + r;
        if ((D_8009C9D8[0] & (*(u16 *)&D_1F8003C8)) == 0 || D_800A539C != 1 || D_800A543C != 0 || D_8009BCA7 != 0) {
            D_800A545E = 0;
            D_8009B698_P_36F98Ptr->b0 = 1;
            D_8009B698_P_36F98Ptr->w22 = 0;
            o->step = 0;
        }
        D_8009B698_P_36F98Ptr->w22++;
        break;
    }
    { char pady[16]; { char padz[16]; } }
    if (o->cooldownTimer != 0 && --o->cooldownTimer <= 0) o->active = 1;
    if (o->unk6A != 0) {
        o->unk6A = 0;
        o->cooldownTimer = 5;
    }
}
#undef DIR
#undef SPIN
#undef IDX

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80038358);
void func_80038358(u8* self)
{
    switch (self[5]) {
    case 0:
        func_80036F98(self);
        break;
    case 1:
        func_80036F98(self);
        break;
    case 2:
        func_80036F98(self);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_800383AC);
extern s8 D_800A547B;
void freeObjectLayer1(GameObject *o);

void func_800383AC(GameObject *o)
{
    u8 st;
    if (D_800A545F != 0) {
        o->state = 2;
    }
    st = o->state;
    switch (st) {
    case 0:
        if (o->step == 0) {
            o->cooldownTimer = 0;
            func_800384F0(o, D_8009C61A[0] - 5);
        }
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_80036F98(o);
            break;
        case 1:
            func_80036F98(o);
            break;
        case 2:
            func_80036F98(o);
            break;
        }
        break;
    case 2:
        if (--D_800A547B < 0) {
            D_800A547B = 0;
        }
        o->state = 3;
        break;
    case 3:
        freeObjectLayer1(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_800384F0);
