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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80034C14);

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
extern u8 D_800A545F;
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
        func_800384F0(self, D_8009C61A - 5);
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
        dy = arg2 + (D_800A53AE - *(u16*)(self + 0x16));
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
    player.x = D_800A53D8[1];
    player.y = D_800A53AE;
    return angleBetweenPoints(me, player);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036A8C);
extern void applyObjectSpeedXY(GameObject *);
extern s16 probeCollisionAtDepthB(GameObject *, s32, s32);
extern void func_800224FC(s32, s32, s32, s32);
extern void func_800EA35C(s32, s32, s32, s32);
extern void playSFX(s32);
extern void func_800EEDE0(GameObject *);
extern u16 D_1F800282;
extern u8 D_800A5435[];
extern s16 D_8007D60C[];

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
extern s16 D_8007D60C[];
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
    advanceAnimFrame(PLAYER, 0);
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

    switch (D_800A539D) {
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
extern u8 D_800A5434;
extern u8 D_800A545E;

void func_80036DF8(u8 *o)
{
    s16 flag;
    if (D_800A5436 == 4 || D_800A5436 == 7) {
        if (((s8 *)D_8009B698)[4] == 0) {
            D_800A545E = 1;
            D_8009B698[0] = 2;
            o[5] = 1;
            D_800A539D = 0x18;
            D_800A539E = 1;
            return;
        }
    } else {
        flag = 0;
        switch (D_800A539D) {
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
                D_800A539D = 3;
                D_800A539E = 1;
                break;
            case 1:
                D_800A5424 = 0;
                D_800A539D = 4;
                if (D_8009B698[8] != 0)
                    D_800A539E = 2;
                else
                    D_800A539E = 1;
                break;
            case 2:
                D_800A539D = 4;
                D_800A5424 = 0;
                D_800A539E = 3;
                break;
            }
            return;
        }
    }
    o[4] = 2;
    o[5] = 0;
    o[6] = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objlogic", func_80036F98);

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
extern u8 D_800A545F;
extern u8 D_8009C61A__383AC[];
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
            func_800384F0(o, D_8009C61A__383AC[0] - 5);
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
