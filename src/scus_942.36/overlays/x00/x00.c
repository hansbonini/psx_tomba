#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115AA8);
typedef struct { char p[2]; u16 s2; } P_15AA8;
typedef struct { char p[0x32]; s16 w32; P_15AA8 *p34; } S_15AA8;
extern u16 D_8009BCCA;
extern u8 D_8009C1A5;
void func_80115AA8(S_15AA8 *o)
{
    s16 t;
    if (D_8009BCCA == 1) {
        t = o->p34->s2 - 0x948;
        if ((u16)t >= 0x69) {
            if (t >= 0) o->w32 = -0x154;
        } else if (t != 0) {
            o->w32 += -(t * 190) / 104;
        }
    } else if (D_8009BCCA == 5) {
        if (D_8009C1A5 == 0xff) o->w32 = -0x54;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115B68);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115C70);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115D0C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80116064);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801160A0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80116814);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801168F4);
extern s16 D_1F80016E;
extern void tryStartItemInteraction(GameObject *, s32, s32);
extern void func_8002CEF8(GameObject *);
extern void func_8002CFF4(GameObject *);

void func_801168F4(GameObject *o)
{
    if (D_8009BCCA == 3) {
        switch (o->subState) {
        case 0:
            if (D_8009BCA2 != 0) o->subState++;
            func_8002CEF8(o);
            break;
        case 1:
            if (D_1F80016E < -0xdb && (*(s16 *)&D_1F80016A) >= 0x12b) tryStartItemInteraction(o, 2, 1);
            else if ((*(s16 *)&D_1F80016A) >= 0x157 && D_1F80016E >= -0x38) tryStartItemInteraction(o, 2, 0);
            func_8002CEF8(o);
            break;
        case 2:
            func_8002CFF4(o);
            break;
        }
    } else {
        func_80116064(o);
    }
}

INCLUDE_RODATA("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115214);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80116A28);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80116C78);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80116FFC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_8011700C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801172E8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117390);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801173FC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_8011767C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117788);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117790);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801178B8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117988);
void func_80117988(char *p)
{
    s16 v;
    u16 t;
    switch ((u8)p[5]) {
    case 0:
        p[5] = nextRandom() & 1;
        *(u16 *)(p + 0x20) = 0xa0;
        *(u16 *)(p + 0x80) = 0x80;
        p[0xe] = 0;
        *(u16 *)(p + 0x22) = 0;
        *(s16 *)(p + 0x7c) = -2;
        return;
    case 1:
        if (func_80022E44(p) == 0)
            return;
        t = *(u16 *)(p + 0x20) - 1;
        *(u16 *)(p + 0x20) = t;
        if ((s16)t == -1) {
            *(u16 *)(p + 0x20) = 0x140;
            p[5]++;
            return;
        }
        if (t & 1) {
            (*(u16 *)(p + 0xb4))--;
            (*(u16 *)(p + 0xbc))--;
            (*(u16 *)(p + 0xc4))++;
            (*(u16 *)(p + 0xcc))++;
        }
        break;
    case 2:
        if (func_80022E44(p) == 0)
            return;
        t = *(u16 *)(p + 0x20) - 1;
        *(u16 *)(p + 0x20) = t;
        if ((s16)t == -1) {
            *(u16 *)(p + 0x20) = 0x140;
            p[5]--;
            return;
        }
        if (t & 1) {
            (*(u16 *)(p + 0xb4))++;
            (*(u16 *)(p + 0xbc))++;
            (*(u16 *)(p + 0xc4))--;
            (*(u16 *)(p + 0xcc))--;
        }
        break;
    default:
        return;
    }
    **(s32 **)(p + 0x40) += *(s16 *)(p + 0x80) << 8;
    v = *(u16 *)(p + 0x80) + *(u16 *)(p + 0x7c);
    *(u16 *)(p + 0x80) = v;
    if ((u16)(v + 0x80) < 0x101)
        return;
    *(s16 *)(p + 0x7c) *= -1;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117B5C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117C4C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117C60);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117CEC);
extern u8 D_8009BCCE;
extern u8 D_8009C10E;
extern void func_80117B5C(GameObject *);
extern void pushDrawListCapped(GameObject *);

void func_80117CEC(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (D_8009BCCE == 3 || D_8009C10E == 0xff) {
            o->state = 3;
            break;
        }
        o->unkE = 1;
        o->unkB = 1;
        o->unkF = 100;
        o->unk30 = o->h->raw;
        o->unk34 = o->y.raw;
        o->subState++;
    case 1:
        switch (D_8009BCCE) {
        case 0:
            break;
        case 1:
            o->subState = 2;
            break;
        case 2:
            o->subState = 3;
            break;
        case 3:
            o->state = 3;
            break;
        }
        break;
    case 2:
        if (o->h->p.whole >= 0x4d9)
            o->h->raw -= 0x18000;
        func_80117B5C(o);
        o->visible = 1;
        pushDrawListCapped(o);
        switch (D_8009BCCE) {
        case 0:
            break;
        case 2:
            o->subState = 3;
            break;
        case 3:
            o->state = 3;
            break;
        }
        break;
    case 3:
        if (o->h->raw >= o->unk30) {
            o->h->raw = o->unk30;
            o->subState = 0;
            o->y.raw = o->unk34;
            break;
        }
        switch (D_8009BCCE) {
        case 0:
            break;
        case 1:
            o->subState = 2;
            break;
        case 3:
            o->state = 3;
            break;
        }
        o->h->raw += 0x18000;
        func_80117B5C(o);
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80117F10);
typedef struct { s16 lo, hi; } HL_17F10;
typedef struct { char p0[2]; s16 s2; } H_17F10;
typedef struct { u16 a, b; } E_17F10;
typedef struct {
    char p0[3]; u8 b3, state, step; char p1[6]; u8 b0c; char p2[7];
    union { s32 i; HL_17F10 s; } y; char p3[0x24 - 0x18]; s32 a24; char *a28; char p4[2]; u16 w2e;
    char p5[0x40 - 0x30]; H_17F10 *h; char p6[0x82 - 0x44]; s16 vel;
} O_17F10;
extern char D_80077214[];
extern E_17F10 D_801379A8[];
extern s32 D_8013A51C[];
extern void readAnimFrameCount(O_17F10 *);
extern void applyFrameVelocityX(O_17F10 *);
extern void freeObjectLayer3(O_17F10 *);
extern s16 probeCollisionAtDepthA(O_17F10 *, s32, s32);

void func_80117F10(O_17F10 *o)
{
    extern void tickAnimation(O_17F10 *);
    E_17F10 *t;
    switch (o->state) {
    case 0:
        o->state++;
        o->vel = -0x400;
        o->a28 = (o->b3 & 1) ? ((char *)&D_800771FC) : D_80077214;
        t = &D_801379A8[o->b3];
        o->w2e = t->a;
        o->b0c = t->b;
        o->a24 = D_8013A51C[o->b0c];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) == 0) {
            o->state = 3;
            break;
        }
        switch (o->step) {
        case 0:
            o->vel += 0x40;
            o->y.i += o->vel << 8;
            if (o->vel > 0) o->step++;
            break;
        case 1:
            o->vel += 0x40;
            o->y.i += o->vel << 8;
            if (probeCollisionAtDepthA(o, o->h->s2, o->y.s.hi))
                o->state = 3;
            break;
        }
        applyFrameVelocityX(o);
        tickAnimation(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801180DC);
extern char *allocObjectLayer3(void);

void func_801180DC(char *o, s16 b, s16 c, s32 d)
{
    s32 i = 0;
    s32 cc = c;
    s32 dd = d << 16;
    s32 x = b;
    char *n;
    u16 t;
    do {
        n = allocObjectLayer3();
        if (n != 0) {
            n[0] = 1;
            n[2] = 2;
            *(s32 *)(n + 0x10) = x << 16;
            *(s32 *)(n + 0x14) = (cc + (i % 2) * -8) * 0x10000;
            *(s32 *)(n + 0x18) = dd;
            t = *(u16 *)(o + 0x1e);
            n[0xd] = 0;
            n[10] = 0;
            n[3] = i;
            *(s8 *)&n[0xf] = -2;
            *(u16 *)(n + 0x1e) = t;
            *(s32 *)(n + 0x3c) = *(s32 *)(o + 0x3c);
        }
        i++;
        x -= 2;
    } while (i < 6);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801181C0);
extern u16 D_1F800250;
typedef struct { u32 w; } W_181C0;
extern u8 **D_1F800260;

void func_801181C0(u8 *o)
{
    u8 **pp;
    u8 *e;

    if ((*(u16 *)&GAME) != 0)
        return;
    D_1F80019C = D_1F800250;
    pp = D_1F800260;
    while (D_1F80019C != 0) {
        e = *pp;
        D_1F80019C--;
        pp++;
        if ((((W_181C0 *)e)->w & 0xffff0000) == 0x1020000) {
            if ((*e & 1) == 0)
                return;
            if ((s16)e[4] != 1)
                return;
            if ((u16)(*(u16 *)(e + 0x6c) + (-*(u16 *)(e + 0x12) + *(u16 *)(o + 0x12) + 0x40)) > *(s16 *)(e + 0x6e) + 0x60)
                return;
            if ((u16)(*(u16 *)(e + 0x70) + (-*(u16 *)(e + 0x16) + *(u16 *)(o + 0x16) + 0x2c)) > *(s16 *)(e + 0x72) + 0x18)
                return;
            *e = 2;
            e[4] = 2;
            e[5] = 3;
            e[6] = 0;
            return;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801182E0);
extern s32 D_1F8002D4[];
extern void *D_8013A450[];

void func_801182E0(GameObject *o)
{
    s16 q;

    switch (o->state) {
    case 0:
        o->unkB4 = 1;
        o->unkB6 = 0x80;
        o->unkB8 = 0;
        o->unkBA = 0;
        o->tpage = (GetGraphType() == 1 || GetGraphType() == 2) ? 0x8a : 0x2a;
        o->clut = GetClut(0xe0, 0x1e0);
        o->unkD = 0x80;
        o->spriteBank = D_1F8002D4[0];
        o->anim = D_8013A450[o->subtype];
        readAnimFrameCount(o);
        o->timer = 0x38;
        o->cooldownTimer = 0;
        o->state++;
        break;
    case 1:
        if (func_80022E44(o) == 0) {
            o->state = 3;
            break;
        }
        if (--o->timer == 0) {
            o->timer++;
            if (*(u16 *)&o->unkB6 != 0) o->unkB6--;
            o->cooldownTimer += 2;
            q = o->cooldownTimer / 10;
            if (q > 0) {
                o->cooldownTimer %= 10;
                o->unkB8++;
                o->unkBA++;
            }
        }
        if (o->subtype == 1 && o->unkC == 1) func_801181C0(o);
        if (tickAnimation(o)) o->state++;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80118500);
extern char *allocObjectLayer3(void);

void func_80118500(s16 a, s16 b, s16 c, s16 d)
{
    s32 i;
    char *n;
    for (i = 0; i < 2; i++) {
        n = allocObjectLayer3();
        if (n != 0) {
            n[2] = 3;
            n[10] = 5;
            n[0] = 1;
            n[3] = i;
            *(s16 *)(n + 0x2c) = 0;
            *(s32 *)(n + 0x10) = b << 16;
            *(s32 *)(n + 0x14) = c << 16;
            *(s32 *)(n + 0x18) = d << 16;
            if (a == 0)
                n[12] = 1;
            else
                n[12] = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801185BC);
typedef struct P_185BC { char p[0x24]; s32 w24; char q[0x3c - 0x28]; s32 w3c; } P_185BC;
extern s32 D_8013A538;
extern s32 tickAnimation(char *);
extern void playSFX(s32);

void func_801185BC(char *o)
{
    u8 s = o[4];
    switch (s) {
    case 0:
        o[4] = s + 1;
        *(s16 *)(o + 0x1e) = 8;
        o[0xd] = 0;
        o[0xa] = 0;
        o[3] = 0;
        *(s8 *)&o[0xf] = -8;
        *(s16 *)(o + 0x2e) = 0;
        ((P_185BC *)o)->w3c = (*(s32 *)&D_1F8002D4);
        ((P_185BC *)o)->w24 = D_8013A538;
        readAnimFrameCount(o);
        playSFX(0x30);
        break;
    case 1:
        if (func_80022E44(o) == 0 || tickAnimation(o) != 0)
            o[4] = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801186AC);
typedef struct P_186AC { char p[0x24]; void *anim; char q[0x3c - 0x28]; s32 w3c; } P_186AC;
extern s16 D_801379C0[];
extern void *D_8013A53C[];

void func_801186AC(char *o)
{
    u8 s = o[4];

    switch (s) {
    case 0:
        o[4] = s + 1;
        *(s16 *)(o + 0x1e) = 9;
        *(s16 *)(o + 8) = GetClut(0xc0, D_801379C0[(u8)o[0xc]]);
        o[0xd] = 1;
        *(s8 *)&o[0xf] = -0x14;
        o[0xa] = 0;
        *(s16 *)(o + 0x2e) = 0;
        ((P_186AC *)o)->w3c = (*(s32 *)&D_1F8002D4);
        ((P_186AC *)o)->anim = D_8013A53C[(u8)o[3]];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) != 0)
            tickAnimation(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801187B8);
typedef struct P_187B8 { char p[0x24]; void *anim; char q[0x3c - 0x28]; s32 w3c; } P_187B8;
extern char D_8013AB58[];
extern void func_80023020(char *);

void func_801187B8(char *o)
{
    switch ((u8)o[4]) {
    case 0:
        o[4]++;
        *(s16 *)(o + 0x1e) = 10;
        *(s16 *)(o + 8) = GetClut(0xe0, 0x1e4);
        o[0xd] = 1;
        o[0xa] = 0;
        o[3] = 0;
        *(s8 *)&o[0xf] = -13;
        *(s16 *)(o + 0x2e) = 0;
        ((P_187B8 *)o)->anim = D_8013AB58;
        ((P_187B8 *)o)->w3c = (*(s32 *)&D_1F8002D4);
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) == 0)
            func_80023020(o);
        if (tickAnimation(o) != 0)
            o[4]++;
        break;
    case 2:
        o[4]++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_801188D4);
extern char *allocObjectLayer3();

void func_801188D4(s32 a, s32 x, s32 y, s32 z)
{
    char *p = allocObjectLayer3();
    if (p != 0) {
        p[0] = 1;
        p[2] = 8;
        *(s32 *)(p + 0x10) = x << 16;
        *(s32 *)(p + 0x14) = y << 16;
        *(s32 *)(p + 0x18) = z << 16;
    }
}

INCLUDE_RODATA("asm/scus_942.36/overlays/x00/nonmatchings/x00", func_80115274);
