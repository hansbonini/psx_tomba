#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED2F4);
extern void func_800ED15C(GameObject *);
extern void func_800ECF74(GameObject *);

void func_800ED2F4(GameObject *o)
{
    extern void freeObjectLayer4(GameObject *);
    switch (o->state) {
    case 0:
        switch (o->unkC) {
        case 1:
            o->unkA = 0x11;
            o->hitOffsetX = 0;
            o->hitWidth = 0;
            o->hitOffsetY = 0;
            o->hitHeight = 0;
            o->active = 2;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            break;
        case 2:
            if ((*(u16 *)&GAME) == 0) o->unkA0 = 0;
        case 0:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 8;
            o->hitHeight = 0x10;
            o->unkA = 0x11;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            break;
        }
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->unkC) {
        case 1:
            func_800ED15C(o);
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            if (o->visible != 0) {
                switch (o->subState) {
                case 0:
                    if (o->step == 0) o->step++;
                    if (o->touchFlag & 2) {
                        o->subState = 1;
                        o->step = 0;
                    }
                    break;
                case 1:
                    func_800ECF74(o);
                    break;
                }
            }
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED4EC);
extern void pushDrawListLayer4();
extern void freeObjectLayer4();
void func_800ED4EC(char *o)
{
    u8 s = *(u8 *)((u8 *)o + 4);
    switch (s) {
    case 0:
        *(u8 *)((u8 *)o + 0) = 2;
        *(u8 *)((u8 *)o + 0xa) = 0x10;
        (*(u8 *)((u8 *)o + 4))++;
        break;
    case 1:
        if ((*(u16 *)&GAME) == 4 || (*(u16 *)&GAME) == 0xc) {
            *(u8 *)((u8 *)o + 1) = 1;
            pushDrawListLayer4();
        } else {
            ((void (*)())func_80022E44)();
        }
        break;
    case 2:
        *(u8 *)((u8 *)o + 4) = s + 1;
        break;
    case 3:
        freeObjectLayer4();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED5BC);
extern void func_80121468(void);
extern void func_8011B91C(void);

void func_800ED5BC(void)
{
    if ((*(u16 *)&GAME) == 0) {
        func_80121468();
    } else if ((*(u16 *)&GAME) == 9) {
        func_8011B91C();
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED604);
extern void func_80022D3C(GameObject *, s32);
extern void freeObjectLayer4(void);

void func_800ED604(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        if (o->unkC == 0) {
            o->hitOffsetX = 4;
            o->hitWidth = 8;
            o->hitOffsetY = 0xaa;
            o->hitHeight = 0x154;
            o->subtype = 1;
        } else if (o->unkC == 1) {
            o->hitOffsetX = 6;
            o->hitWidth = 8;
            o->hitOffsetY = 0xaa;
            o->hitHeight = 0x154;
        } else if (o->unkC == 2) {
            o->hitOffsetX = 6;
            o->hitWidth = 8;
            o->hitOffsetY = 0x28;
            o->hitHeight = 0xb4;
        } else if (o->unkC == 3) {
            o->hitOffsetX = 6;
            o->hitWidth = 8;
            o->hitOffsetY = 0x64;
            o->hitHeight = 0xc8;
        }
        *(s32 *)((char *)o + 0xa0) = 0;
        break;
    case 1:
        func_80022D3C(o, 0x40);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED734);
extern u8 *D_8009B698;
void func_800ED734(u8 *o)
{
    D_8009B698[8] = 0;
    D_8009B698[9] = 0;
    *(s16 *)(D_8009B698 + 0xc) = 0;
    *(u16 *)(D_8009B698 + 0x28) = 0xffff;
    *(u16 *)(D_8009B698 + 0x2a) = 0xffff;
    *(s16 *)(o + 0x80) = 0;
    *(s16 *)(o + 0x82) = 0;
    *(s16 *)(o + 0xb0) = 0;
    *(s32 *)(o + 0x84) = 0;
    *(s32 *)(o + 0x88) = 0;
    *(s32 *)(o + 0x8c) = 0;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED788);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED7B4);
extern u8 D_80114638[];
void func_800ED7B4(GameObject *o)
{
    u32 c = (u8)(D_80114638[o->unkB0] - o->unk8C);
    s16 d;
    u16 u;
    s32 v;
    d = c;
    if (d == 0) return;
    u = c;
    if (u < 0x80) {
        if (d >= 4) v = o->unk8C + 4;
        else if (d >= 2) v = o->unk8C + 2;
        else v = o->unk8C + 1;
    } else {
        if (d < 0xfd) v = o->unk8C - 4;
        else if (d < 0xff) v = o->unk8C - 2;
        else v = o->unk8C - 1;
    }
    o->unk8C = v;
    o->unk8C = *(u8 *)&o->unk8C;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED840);
typedef struct S_ED840 { char pad[0x8c]; s32 v; char pad2[0xb0 - 0x90]; s16 idx; } S_ED840;
extern u8 D_80114638[];
extern u8 D_8011465C[];

void func_800ED840(S_ED840 *s, s16 f)
{
    u8 b;
    if (f) {
        b = D_8011465C[s->idx];
    } else {
        b = D_80114638[s->idx];
    }
    s->v = b;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED87C);
extern u8 D_8011465C[];
void func_800ED87C(u8 *o)
{
    s32 t = (u8)(D_8011465C[*(s16 *)(o + 0xb0)] - *(s32 *)(o + 0x8c));
    u8 d = t;
    if (t != 0) {
        if (d < 0x81) (*(s32 *)(o + 0x8c))--;
        else (*(s32 *)(o + 0x8c))++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED8C0);
typedef struct O_ED8C0 {
    char pad0[6];
    u8 state;
    char pad1[0x24 - 7];
    void *anim;
    char pad2[0x30 - 0x28];
    s32 d30;
    s32 d34;
    char pad3[0x88 - 0x38];
    s32 d88;
    s32 d8c;
    char pad4[0x9c - 0x90];
    char b9c;
    char pad5[0xaa - 0x9d];
    char baa;
} O_ED8C0;
extern char D_80010DB0[];
extern void playSFXWithVolume();
extern void advanceAnimFrame();

void func_800ED8C0(O_ED8C0 *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    o->b9c = 0;
    o->anim = D_80010DB0;
    advanceAnimFrame(o, 4);
    o->d30 = 0;
    o->d34 = 0;
    o->d88 = 0;
    o->d8c = 0;
    o->baa = 0;
    o->state = 5;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED928);
typedef struct { char pad[8]; u8 b8; char pad2[5]; u16 we; } P_ED928;
extern P_ED928 *D_8009B698_P_ED928Ptr asm("D_8009B698");
typedef struct { char pad[0xb6]; u16 wb6; } O_ED928;

void func_800ED928(O_ED928 *o)
{
    if ((u16)(o->wb6 += D_8009B698_P_ED928Ptr->we) < 0x800) {
        D_8009B698_P_ED928Ptr->b8 = 1;
    }
    if ((u32)(o->wb6 - 0x800) < 0x800) {
        D_8009B698_P_ED928Ptr->b8 = 0;
    }
    if ((u16)(o->wb6 + 0x7ff) < 0x800) {
        D_8009B698_P_ED928Ptr->b8 = 0;
    }
    if ((u16)(o->wb6 + 0xfff) < 0x800) {
        D_8009B698_P_ED928Ptr->b8 = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800ED9E0);
typedef struct S_ED9E0 { char pad0[0x40]; s32 *h; char pad1[0x7c-0x44]; s16 velH; } S_ED9E0;
extern void func_8010DE48(S_ED9E0 *);
extern void func_8010E444(S_ED9E0 *, s32 *);
extern void applyObjectAltSpeedVertical(S_ED9E0 *);
void func_800ED9E0(S_ED9E0 *o)
{
s32 *h; func_8010DE48(o); h = o->h; *h += o->velH << 8; func_8010E444(o, h); applyObjectAltSpeedVertical(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDA30);
void func_800EDA30(char *o)
{

    volatile u16 *pad = &D_8009C9D8;
    s32 a = 10;
    s16 d;
    s32 t;
    if ((*pad & 0xa0) == 0)
        *(s16 *)(o + 0x76) = 0;
    if ((*pad & 0x40) != 0)
        a = 8;
    if ((*pad & 0x80) != 0)
        *(s16 *)(o + 0x76) = 0xf0;
    if ((*pad & 0x20) != 0)
        *(s16 *)(o + 0x76) = 0x10;
    t = *(s32 *)(o + 0x88);
    d = (*(u16 *)(o + 0x76) - t) & 0xff;
    if (d != 0) {
        u8 e = d;
        if (e < 0x80)
            *(s32 *)(o + 0x88) = t + 1;
        else
            *(s32 *)(o + 0x88) = t - 1;
    }
    if ((*(u16 *)&GAME) == 3)
        *(s32 *)(o + 0x84) = *(s32 *)(o + 0x84) + 6;
    else
        *(s32 *)(o + 0x84) = *(s32 *)(o + 0x84) + 4;
    *(s32 *)(o + 0x8c) = (*(s32 *)(o + 0x88) + ((s16 (*)(s32, s32))fixedMulCos2)(*(u8 *)(o + 0x84), a)) & 0xff;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDB40);
extern void tickAnimation(GameObject *o);
extern void func_8011068C(GameObject *o);
extern void func_8011070C(GameObject *o);
extern s16 D_8009BCAC;
extern s16 D_8009BCAE;

void func_800EDB40(GameObject *o)
{
    tickAnimation(o);
    { s32 *p = &o->h->raw; *p += D_8009BCAC << 7; } o->y.raw += D_8009BCAE << 7;
    func_8011068C(o);
    o->h->raw += o->velX << 8;
    o->timer = o->timer - 1;
    if (o->timer <= 0) {
        o->timer = 0;
        func_8011070C(o);
        applyObjectAltSpeedVertical(o);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDBEC);
typedef struct O_EDBEC { char p0[3]; u8 sub; char p1[0x10]; s32 y; char p2[0xad-0x18]; u8 f; char p3[2]; s16 w; } O_EDBEC;
void func_800EDBEC(O_EDBEC *o)
{
    if (o->f == 0) {
        if (o->sub != 0) {
            if ((u16)(o->w + 5) > 10) o->y += 0x50000;
            else o->y += 0x30000;
        } else {
            if ((u16)(o->w + 5) > 10) o->y += 0xc0000;
            else o->y += 0x80000;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDC80);
typedef struct { char p[0x14]; s32 y; char q[0xad-0x18]; u8 f; } O_EDC80;
void func_800EDC80(O_EDC80 *o)
{
    if (o->f == 0) o->y += 0x7c000;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDCA8);
extern u8 D_8009C61A[];
extern s16 D_8007D5D0[];
extern u8 *allocObjectLayer1(void);
void func_800EDCA8(s8 *o, u8 p)
{
    u8 *q;
    s32 pad[1];
    if (o[0xe3] < D_8007D5D0[D_8009C61A[0]]) {
        o[0xe3]++;
        q = allocObjectLayer1();
        if (q != 0) {
            q[0] = 1;
            q[2] = D_8009C61A[0];
            q[5] = p;
            q[6] = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDD2C);
typedef struct TO_EDD2C {
    char p0[0x14];
    s32 y;
    char p1[0x40 - 0x18];
    s32 *h;
    char p2[0xb2 - 0x44];
    s16 w2;
    char p3[0xb6 - 0xb4];
    s16 w6;
} TO_EDD2C;
extern s16 D_8009BCAC;
extern s16 D_8009BCAE;
extern void setObjectSpeedPolar2(TO_EDD2C *o, s32 a, s32 b);
extern void applyObjectSpeedXY(TO_EDD2C *o);

static __inline__ void add_EDD2C(TO_EDD2C *p)
{
    *p->h += D_8009BCAC << 8;
    p->y += D_8009BCAE << 8;
}

void func_800EDD2C(TO_EDD2C *o)
{
    setObjectSpeedPolar2(o, o->w6, o->w2);
    add_EDD2C(o);
    applyObjectSpeedXY(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDD9C);
void func_800EDD9C(GameObject *o)
{
    s16 v = o->unkB0;
    if (v < 0) o->unkB6 = (s16)((v << 2) + 0x100) & 0xff;
    else if (v > 0) o->unkB6 = (s16)(v << 2) & 0xff;
    else o->unkB6 = 0;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDDDC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDE44);
typedef struct P_EDE44 { char p0[0x2c]; u16 a; u16 b; } P_EDE44;
extern P_EDE44 *D_8009B698_P_EDE44Ptr asm("D_8009B698");
void func_800EDE44(void *o, u16 x, s16 y)
{
    P_EDE44 *p = D_8009B698_P_EDE44Ptr;
    p->a = x;
    if (p->b != x) {
        p->a = x;
        func_800EEF64(o);
        advanceAnimFrame(o, y);
        D_8009B698_P_EDE44Ptr->b = D_8009B698_P_EDE44Ptr->a;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDEBC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDF24);
typedef struct S_EDF24 { char pad[0x24]; void *anim; char pad2[0x8c - 0x28]; s32 v; } S_EDF24;
extern char D_80010C48[];
extern void readAnimFrameCount(S_EDF24 *s);

void func_800EDF24(S_EDF24 *s)
{
    if ((*(u16 *)&GAME) == 3 && D_8009BCAC != 0) {
        s->anim = D_80011440;
        readAnimFrameCount(s);
    } else {
        s->anim = D_80010C48;
        advanceAnimFrame(s, 3);
    }
    s->v = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EDFA0);
void func_800EDFA0(GameObject *o)
{
    switch (*(u16 *)o->anim) {
    case 0x47:
        break;
    case 0xfa:
    case 0xfb:
    case 0xfc:
        if (o->animFrame & 1) {
            if (o->unk8C > 0)
                o->unk8C = -o->unk8C;
            o->unk8C -= 4;
            if (o->unk8C < -0x20)
                o->unk8C = -0x20;
        } else {
            if (o->unk8C < 0)
                o->unk8C = -o->unk8C;
            o->unk8C += 4;
            if (o->unk8C > 0x20)
                o->unk8C = 0x20;
        }
        return;
    default:
        if (o->animFrame & 1) {
            if (o->unk8C > 0x80)
                o->unk8C = (0x100 - o->unk8C) & 0xff;
            o->unk8C = (o->unk8C + 4) & 0xff;
            if (o->unk8C <= 0x40)
                return;
            if ((*(u16 *)&GAME) == 3 && D_8009BCAC != 0) {
                o->anim = D_80011440;
                readAnimFrameCount(o);
            } else {
                o->anim = D_80010C48;
                advanceAnimFrame(o, 3);
            }
        } else {
            if (o->unk8C < 0x80)
                o->unk8C = (0x100 - o->unk8C) & 0xff;
            o->unk8C = (o->unk8C - 4) & 0xff;
            if (o->unk8C >= 0xc0)
                return;
            if ((*(u16 *)&GAME) == 3 && D_8009BCAC != 0) {
                o->anim = D_80011440;
                readAnimFrameCount(o);
            } else {
                o->anim = D_80010C48;
                advanceAnimFrame(o, 3);
            }
        }
        break;
    }
    o->unk8C = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE1A0);
typedef struct { char pad[4]; u8 b4, b5, b6; } E_EE1A0;
extern E_EE1A0 *D_8009C650;
typedef struct { char pad[0xac]; u8 bac; } O_EE1A0;

void func_800EE1A0(O_EE1A0 *o)
{
    if (o->bac >= 2) {
        D_8009C650 = D_800A547C;
        D_8009C650->b4 = 2;
        D_8009C650->b5 = 2;
        D_8009C650->b6 = 0;
    }
    o->bac = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE1F0);
typedef struct { char p0[0x9d]; char b9d; char p1[0xac - 0x9e]; u8 bac; char p2[0xc6 - 0xad]; char bc6, bc7; char p3[0xe3 - 0xc8]; char be3; } TO_EE1F0;

void func_800EE1F0(TO_EE1F0 *o)
{
    if (o->bac > 1) {
        D_8009C650 = D_800A547C;
        D_8009C650->b4 = 2;
        D_8009C650->b5 = 2;
        D_8009C650->b6 = 0;
    }
    o->bac = 0;
    D_8009BC9C = 0;
    o->bc7 = 1;
    o->b9d = 0;
    o->bc6 = 0;
    o->be3 = 0;
    *D_8009B698 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE26C);
extern u8 D_8009BCF8;

s16 func_800EE26C(void)
{
    extern u16 D_80114530[];
    s16 s = 0;
    GameObject *o;
    switch (D_8009BCF8) {
    case 1:
        s = 5;
        break;
    case 2:
        s = (D_1F8001F8 & 1) + 5;
        break;
    case 3:
        s = 1;
        break;
    }
    if (s != 0) {
        if ((*(s16 *)&D_1F800238) < 6) return 0;
        o = allocObjectLayer3();
        if (o != 0) {
            u16 *t;
            Fix16 *h = o->h;
            o->active = 1;
            o->type = 0x4e;
            o->subtype = D_8009BCF8 - 1;
            o->unkC = s;
            o->x.p.whole = ((u16 *)&D_800A53AA)[0];
            o->y.p.whole = ((u16 *)&D_800A53AA)[2];
            o->z.p.whole = ((u16 *)&D_800A53AA)[4];
            t = D_80114530 + ((D_1F8001F8 + 2) & 7) * 2;
            h->p.whole += t[0];
            o->y.p.whole += t[1];
            o->subState = 1;
        }
    }
    return s;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE3BC);
extern s16 D_80114530[];
void func_800EE3BC(u32 a, s16 x, s16 y, s16 z)
{
    GameObject *p;
    s16 *t;
    if (func_800EE26C() == 0 && (*(s16 *)&D_1F800238) > 5 && (p = allocObjectLayer3()) != 0) {
        p->active = 1;
        p->type = 0x31;
        p->subtype = 1;
        p->x.p.whole = x;
        p->y.p.whole = y;
        p->z.p.whole = z;
        t = D_80114530 + (a & 1) * 16 + (D_1F8001F8 & 7) * 2;
        p->h->p.whole += t[0];
        p->y.p.whole += t[1];
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE4B0);
extern void playSFXWithVolume(s32, s32);
void func_800EE4B0(char *o)
{
    playSFXWithVolume(0x1c, 0x7f);
    D_8009B698[8] = 0;
    o[0xa7] = 0;
    o[0xac] = 0;
    o[0x9c] = 0;
    o[0x9e] = 0;
    o[0xaa] = 0;
    o[5] = 0;
    o[6] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE50C);
extern s16 probeSidesAndApplyTileResponse(GameObject *, s32, s32);

static __inline__ void setanim_EE50C(GameObject *o, u16 anim)
{
    GameObject *p = (*(GameObject **)&D_8009B698);
    p->animTimer = anim;
    if (p->animFrame != anim) {
        p->animTimer = anim;
        func_800EEF64(o);
        advanceAnimFrame(o, 0);
        (*(GameObject **)&D_8009B698)->animFrame = (*(GameObject **)&D_8009B698)->animTimer;
    }
}

void func_800EE50C(GameObject *o)
{
    if (o->touchFlag) {
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->unk9E = 0;
        o->unkA7 = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unk9C = 0;
        o->unk8C = D_80114638[o->unkB0];
        if (o->unkBE & 8) {
            *(u8 *)((u8 *)(*(GameObject **)&D_8009B698) + 8) = *(u8 *)((u8 *)o + 0x2e) & 1;
            if ((o->unkBE & 1) != o->animFrame) {
                setanim_EE50C(o, 8);
                advanceAnimFrame(o, 2);
            } else {
                setanim_EE50C(o, 0x11);
            }
            o->subState = 0x1b;
        } else {
            playSFXWithVolume(0x1c, 0x7f);
            *(u8 *)((u8 *)(*(GameObject **)&D_8009B698) + 8) = 0;
            o->subState = 0;
        }
        o->step = 0;
    }
    if ((*(GameObject **)&D_8009E454) && (*(GameObject **)&D_8009E454)->type == 0x14 && probeSidesAndApplyTileResponse(o, 0, 0)) {
        playSFXWithVolume(0x1c, 0x7f);
        *(u8 *)((u8 *)(*(GameObject **)&D_8009B698) + 8) = 0;
        o->unkA7 = 0;
        *(u8 *)((u8 *)o + 0xac) = 0;
        o->unk9C = 0;
        o->unk9E = 0;
        *(u8 *)((u8 *)o + 0xaa) = 0;
        o->subState = 0;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE6E8);
void func_800EE6E8(GameObject *o)
{
    if (o->touchFlag != 0) {
        playSFXWithVolume(0x1c, 0x7f);
        D_8009B698[8] = 0;
        o->unkA7 = 0;
        *(char *)&o->unkAC = 0;
        o->unk9C = 0;
        o->unk9E = 0;
        *(char *)&o->unkAA = 0;
        o->subState = 0;
        o->step = 0;
    }
    if (D_8009E454 != 0 && D_8009E454[2] == 0x14 && probeSidesAndApplyTileResponse(o, 0, 0) != 0) {
        playSFXWithVolume(0x1c, 0x7f);
        D_8009B698[8] = 0;
        o->unkA7 = 0;
        *(char *)&o->unkAC = 0;
        o->unk9C = 0;
        o->unk9E = 0;
        *(char *)&o->unkAA = 0;
        o->subState = 0;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE7C0);
void func_800EE7C0(GameObject *o)
{
    o->d->raw += o->velH << 8;
    o->y.raw += o->velV << 8;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE7F0);
void func_800EE7F0(char *o)
{
    u16 v = *(u16 *)(o + 0x2e) & 1;
    volatile u16 *p = &D_8009C9D8;
    *(u16 *)(o + 0x2e) = v;
    if (*p & 0x20) {
        *(s16 *)(o + 0x2e) = 0;
    } else {
        *(u16 *)(o + 0x2e) = (*p & 0x80) ? 1 : (v | 2);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE844);
void func_800EE844(char *o)
{
    u16 v = *(u16 *)(o + 0x2e) & 1;
    volatile u16 *p = &D_8009C9D8;
    volatile u16 *q;
    *(u16 *)(o + 0x2e) = v;
    if (*p & 0x20) {
        *(s16 *)(o + 0x2e) = 0;
    } else {
        *(u16 *)(o + 0x2e) = (*p & 0x80) ? 1 : (v | 2);
    }
    q = &D_8009C9D8;
    if (*q & 0x10)
        *(u16 *)(o + 0x2e) |= 8;
    if (*q & 0x40)
        *(u16 *)(o + 0x2e) |= 4;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE8E8);
void func_800EE8E8(GameObject *o)
{
    volatile u16 *k = D_8009C9D8;
    u16 f = o->animFrame & 1;
    o->animFrame = f;
    if (*k & 0x10) {
        if (*k & 0x80) o->animFrame = 5;
        else if (*k & 0x20) o->animFrame = 4;
        else if (f) o->animFrame = 7;
        else o->animFrame = 6;
    } else {
        if (*k & 0x80) o->animFrame = 3;
        else if (*k & 0x20) o->animFrame = 2;
        else if (f) o->animFrame = 3;
        else o->animFrame = 2;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EE98C);
void func_800EE98C(GameObject *o)
{
    volatile u16 *k = &D_8009C9D8;
    u16 f = o->animFrame & 1;

    o->animFrame = f;
    if (*k & 0x10) {
        if (*k & 0x80) {
            o->animFrame = 5;
        } else if (*k & 0x20) {
            o->animFrame = 4;
        } else if (f) {
            o->animFrame = 7;
        } else {
            o->animFrame = 6;
        }
    } else {
        if (*k & 0x80) {
            o->animFrame = 1;
        } else if (*k & 0x20) {
            o->animFrame = 0;
        } else if (f) {
            o->animFrame = 3;
        } else {
            o->animFrame = 2;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_1", func_800EEA38);
void func_800EEA38(GameObject *o)
{
    if (o->animFrame & 1) {
        volatile u16 *pad = &D_8009C9D8;
        if ((*pad & 0x10) == 0) o->animFrame = 3;
        else if ((*pad & 0x80) != 0) o->animFrame = 5;
        else o->animFrame = 7;
    } else {
        volatile u16 *pad = &D_8009C9D8;
        if ((*pad & 0x10) == 0) o->animFrame = 2;
        else if ((*pad & 0x20) != 0) o->animFrame = 4;
        else o->animFrame = 6;
    }
}
