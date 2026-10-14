#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_8011F7E4);
typedef struct {
    char p0[5];
    u8 step;
    u8 state;
    u8 substep;
    char p8[2];
    u8 b0a;
    char pb[0x80 - 0xb];
    s16 velH;
    s16 velV;
    char p84[0xa0 - 0x84];
    s32 da0;
    char pa4[4];
    s32 da8;
    s16 wac;
    char pae[0xb8 - 0xae];
    s32 db8;
    s32 dbc;
    char pc0[0xcc - 0xc0];
    s16 wcc;
} S_1F7E4;
extern s32 *D_1F800334_S32PtrArr[] asm("D_1F800334");
#define DAT_1f800334p D_1F800334_S32PtrArr[0]
extern s32 D_1F800334_S32Arr[] asm("D_1F800334");
#define DAT_1f800334 D_1F800334_S32Arr[0]
extern s32 *D_1F800318[];
#define DAT_1f800318p D_1F800318[0]
extern s32 D_1F800318_S32Arr[] asm("D_1F800318");
#define DAT_1f800318 D_1F800318_S32Arr[0]
extern s32 *D_1F800314[];
#define DAT_1f800314p D_1F800314[0]
extern s32 D_1F800314_S32Arr[] asm("D_1F800314");
#define DAT_1f800314 D_1F800314_S32Arr[0]
extern s32 *FOUR_DATA[];
#define DAT_1f800310p FOUR_DATA[0]
extern s32 FOUR_DATA_S32Arr[] asm("FOUR_DATA");
#define DAT_1f800310 FOUR_DATA_S32Arr[0]
extern char D_800E3188[];
extern void func_80028638(s32, s32);
extern void subtractScaledVertices(s32, s32, s32);

#define SETUP(o, n, w, v, P, Q) \
    o->wac = w; \
    o->substep++; \
    o->da0 = DAT_1f800334 + DAT_1f800334p[n]; \
    o->velH = v; \
    o->velV = 0; \
    o->b0a = 0x12; \
    p = P; \
    a = o->da0; \
    q = Q; \
    goto tail;

s32 func_8011F7E4(S_1F7E4 *o)
{
    s32 *p;
    register s32 q asm("$3");
    s32 a;
    switch (o->substep) {
    case 0:
        SETUP(o, 4, 3, 0x60, DAT_1f800318p, DAT_1f800318);
    case 2:
        SETUP(o, 3, 2, 0x100, DAT_1f800314p, DAT_1f800314);
    case 4:
        o->wac = 1;
        o->substep++;
        o->da0 = DAT_1f800334 + DAT_1f800334p[2];
        o->velH = 0x200;
        o->velV = 0;
        o->b0a = 0x12;
        p = DAT_1f800310p;
        a = o->da0;
        q = DAT_1f800310;
    tail:
        q += p[1];
        o->db8 = (s32)D_800E3188;
        o->da8 = (s32)D_800E3188;
        o->dbc = q;
        func_80028638(a, o->db8);
        return 0;
    case 5:
        o->velV += o->velH;
        if (o->velV > 0x1000) {
            o->velH = -0x280;
            o->substep++;
        }
        goto common;
    case 6:
        o->velV += o->velH;
        if (o->velV < 0x800) {
            o->velH = 0x280;
            o->substep++;
        }
        goto common;
    case 1:
    case 3:
    case 7:
        o->velV += o->velH;
        if (o->velV > 0x1000) {
            o->velV = 0x1000;
            o->substep++;
        }
    common:
        o->wcc = o->velV;
        func_80028638(o->da0, o->db8);
        subtractScaledVertices(o->db8, o->dbc, o->wcc);
        return 0;
    case 8:
        o->step = 0;
        o->substep = 0;
        o->b0a = 0x11;
        o->wac = 0;
        o->da0 = DAT_1f800334 + DAT_1f800334p[1];
        return 1;
    }
    return 0;
}
#undef DAT_1f800334p
#undef DAT_1f800334
#undef DAT_1f800318p
#undef DAT_1f800318
#undef DAT_1f800314p
#undef DAT_1f800314
#undef DAT_1f800310p
#undef DAT_1f800310
#undef SETUP

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_8011FA84);
extern u8 D_8009BCA9;

void func_8011FA84(GameObject *o)
{
    if (o->unkC == 1) {
        switch (o->step) {
        case 0:
            if (D_8009BCA8 == 0)
                break;
            if (D_8009BCA9 != 0x33)
                break;
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            o->unk7 = 0;
            o->step++;
            break;
        case 1:
            if (func_8011F7E4(o)) {
                o->timer = 0x78;
                o->step++;
            }
            break;
        case 2:
            if (--o->timer == -1)
                o->step++;
            break;
        case 3:
            D_8009BCA8 = 0;
            o->subState++;
            ((GameObject *)o->unk90)->subState++;
            break;
        }
    } else if (o->unkC != 0) {
        o->subState = ((GameObject *)o->unk90)->subState;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_8011FBE0);
extern void func_800EDDDC(GameObject *, s32, s32);
extern s32 tickAnimation(GameObject *);
void func_8011FBE0(GameObject *o)
{
    GameObject *g;
    s16 d;
    if (o->unkC == 0) {
        g = &PLAYER;
        switch (o->step) {
        case 0:
            d = o->h->p.whole - (*(u16 *)0x1F80016A + 0x20);
            if (d == 0) {
                o->step = 2;
                break;
            }
            if (d < 0)
                g->animFrame = 1;
            else
                g->animFrame = 0;
            func_800EDDDC(g, 1, 0);
            g->active = 6;
            g->state = 5;
            g->subState = 0x65;
            g->step = 0;
            o->timer = 0x20;
            o->velH = (d << 8) / 32;
            o->step++;
            break;
        case 1:
            g->h->raw += o->velH << 8;
            tickAnimation(g);
            if (--o->timer == -1)
                o->step++;
            break;
        case 2:
            o->step++;
            func_800EDDDC(g, 4, 0);
            g->active = 6;
            g->state = 5;
            g->subState = 0x65;
            *(s8 *)&g->unkF = -16;
            g->step = 0;
            g->animFrame = 0;
            o->timer = 0x30;
            o->velV = 0x280;
            o->velH = 0xaa;
            o->velX = 0;
            o->velY = 0;
            o->unk88 = 0;
            break;
        case 3:
            g->unk8C--;
            g->h->raw += o->velH << 8;
            g->y.raw -= (D_8007DB88[*(u8 *)&o->unk88] * o->velV) >> 4;
            o->unk88 += 2;
            if (--o->timer == -1)
                o->step++;
            break;
        case 4:
            o->step++;
            func_800EDDDC(g, 0xd, 0);
            g->h->p.whole = o->h->p.whole;
            g->y.p.whole = o->y.p.whole - 8;
            g->d->p.whole = o->d->p.whole;
            g->unk8C = 0;
            o->timer = 0x20;
            break;
        case 5:
            if (--o->timer == -1) {
                o->step = 0;
                o->unk7 = 0;
                o->subState++;
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                D_8009BCA6 = 0;
            }
            break;
        }
    } else {
        o->subState = ((GameObject *)o->unk90)->subState;
        o->step = ((GameObject *)o->unk90)->step;
        o->unk7 = ((GameObject *)o->unk90)->unk7;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_8011FF1C);
extern void probeCollisionAtDepthA(GameObject *, s32, s32);
typedef struct G_1FF1C { char p[0x16]; s16 y; } G_1FF1C;
extern s32 D_800A5424;

void func_8011FF1C(GameObject *o)
{
    s32 s, t;
    s16 y;
    s = o->step;
    t = s & 0xff;
    if (t != 1) {
        if (t < 2 && t == 0) {
        o->step = s + 1;
        o->unkB6 = 0x180;
        o->unkB4 = 0;
        o->velH = 0;
        }
    } else {
        o->velX = (s16)*(u16 *)&o->unkB6 >> 1;
        o->h->raw = o->h->raw + o->unkB6 * 0x100;
        y = o->y.p.whole;
        o->y.p.whole = y + 2;
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(y + 0x12));
        o->unk84 = (-(s32)D_1F80027E << 6) & 0xfff;
        (*(Fix16 **)&D_800A53D8)->p.whole = o->h->p.whole;
        (*(G_1FF1C *)&PLAYER).y = o->y.p.whole - 8;
        (*(Fix16 **)&D_800A53DC)->p.whole = o->d->p.whole;
        D_800A5424 = o->unk84 >> 4;

    }
    o->velH = o->velH - o->velX;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120054);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120474);
void func_80120474(u8 *o)
{
    extern void func_80120E30(void *);
    extern s32 func_80120DAC(s32, s32, s32, s32);
    switch (o[6]) {
    case 0:
        if (o[0x69] == 1) {
            *(s32 *)(o + 0xb4) = func_80120DAC(5, 0xa78, -0x4d8, 0x172);
            *(s32 *)(o + 0xb8) = func_80120DAC(0, 0xa88, -0x4d8, 0x172);
            *(s32 *)(o + 0xbc) = func_80120DAC(0, 0xa98, -0x4d8, 0x172);
            *(s32 *)(o + 0xc0) = func_80120DAC(0, 0xaa8, -0x4d8, 0x172);
            *(s32 *)(o + 0xc8) = *(s32 *)(o + 0xc4) = func_80120DAC(0, 0xab8, -0x4d8, 0x172);
            *(s16 *)(o + 0x22) = 0x78;
            o[6] = o[6] + 1;
        }
        break;
    case 1:
        *(s16 *)(o + 0x22) = *(s16 *)(o + 0x22) - 1;
        if (*(s16 *)(o + 0x22) == -1) {
            func_80120E30(o);
            *(s16 *)(o + 0x22) = 0x1e;
            o[6] = o[6] + 1;
        }
        break;
    case 2:
        *(s16 *)(o + 0x22) = *(s16 *)(o + 0x22) - 1;
        if (*(s16 *)(o + 0x22) == -1)
            o[6] = 0;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_801205CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_801205D8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120708);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_8012095C);
extern s8 D_80138238[];

void func_8012095C(GameObject *o)
{
    u16 u;
    GameObject *n;
    u32 i;
    Fix16 *hp;

    u = o->timer + 1;
    o->timer = u;
    if ((u & 7) == 0)
        func_801205CC(o);
    o->unk88 = (o->unk88 + 0x18) & 0xfff;
    u = o->cooldownTimer + 1;
    o->cooldownTimer = u;
    if ((u & 7) == 0 && (n = allocObjectLayer3()) != 0) {
        n->active = 1;
        n->type = 0x31;
        n->subtype = 1;
        hp = n->h;
        n->unkC = (D_1F8001F8 + (char)D_1F800198) & 3;
        i = ((u32)o->unk88 >> 8) & 0x1fe;
        hp->raw = o->h->raw + D_80138238[i] * 0x10000;
        n->y.raw = o->y.raw + D_80138238[i + 1] * 0x10000;
        n->d->raw = o->d->raw + -0x100000;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120A6C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120AC8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120BC0);
extern void setEventStarted(s32, s32, s32);
extern s32 setEventComplete(s32, s32);
extern void freeObjectLayer4(GameObject *);

void func_80120BC0(GameObject *o)
{
    u8 s = o->state;
    switch (s) {
    case 0:
        o->state = s + 1;
        o->unkA = 0x13;
        *(s32 *)((char *)o + 0x84) = 0;
        *(s32 *)((char *)o + 0x88) = 0;
        o->unk8C = 0;
        o->timer = 0;
        o->cooldownTimer = 0;
        *(s16 *)((char *)o + 0x74) = 0xa00;
        *(s16 *)((char *)o + 0x76) = 0xa00;
        *(s16 *)((char *)o + 0x78) = 0xa00;
        o->touchFlag = 0;
        if (o->unkC == 0) {
            o->hitOffsetX = 12;
            o->hitWidth = 24;
            o->hitOffsetY = 12;
            o->hitHeight = 24;
        } else {
            o->active = 2;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->unkC == 0) {
            func_80120474(o);
            switch (o->subState) {
            case 0:
                if (o->touchFlag == 1)
                    o->subState++;
                break;
            case 1:
                if ((*(u32 *)&D_8009BCD4) <= 0xc34f) {
                    setEventStarted(0x10, 0, 0);
                    o->subState--;
                } else {
                    setEventComplete(0x10, 0);
                    o->state = 2;
                    o->subState = 0;
                    if (o->unkC == 0)
                        func_80120E30(o);
                }
                break;
            }
            o->touchFlag = 0;
        } else {
            func_8012095C(o);
            o->state = ((GameObject *)o->unk90)->state;
        }
        break;
    case 2:
        func_80022E44(o);
        if (o->unkC != 0)
            func_8012095C(o);
        func_80120A6C(o);
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120DAC);
GameObject *func_80120DAC(u8 a, s32 x, s32 y, s32 z)
{
    GameObject *p = allocObjectLayer3();

    if (p) {
        p->unkC = a;
        p->active = 1;
        p->type = 0x44;
        p->x.raw = x << 16;
        p->y.raw = y << 16;
        p->z.raw = z << 16;
    }
    return p;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120E30);
void func_80120E30(char *o)
{
    *(char *)(*(s32 *)(o + 0xb4) + 4) = 2;
    *(char *)(*(s32 *)(o + 0xb8) + 4) = 2;
    *(char *)(*(s32 *)(o + 0xbc) + 4) = 2;
    *(char *)(*(s32 *)(o + 0xc0) + 4) = 2;
    *(char *)(*(s32 *)(o + 0xc4) + 4) = 2;
    *(char *)(*(s32 *)(o + 0xc8) + 4) = 2;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120E78);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120E90);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_80120ECC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_4", func_801210A4);
