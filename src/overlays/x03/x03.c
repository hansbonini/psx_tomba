#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801162C4);
typedef struct { u16 frac; s16 whole; } FP_162C4;
typedef struct { char pad[0x32]; s16 y; FP_162C4 *p; } S_162C4;

void func_801162C4(S_162C4 *o)
{
    s16 x = o->p->whole;

    if (GAME.selectedSection == 0 || GAME.selectedSection == 4) {
        if (x < 0xfa) o->y = -0x78;
        else if (x < 0x1b9) o->y = -((s16)(x - 0xfa) * 248) / 190 - 0x78;
        else if (x < 0x505) o->y = -((s16)(x - 0x1b8) * 245) / 844 - 0x170;
        else if (x < 0x760) o->y = -((s16)(x - 0x504) * 108) / 603 - 0x265;
        else if (x < 0x9c5) o->y = -((s16)(x - 0x760) * 279) / 612 - 0x2d1;
        else o->y = -0x3e8;
    } else if (GAME.selectedSection == 1 || GAME.selectedSection == 5) {
        if (x < 0xc24) o->y = -0x41a;
        else if (x < 0xd2b) o->y = -((s16)(x - 0xc24) * 130) / 262 - 0x41a;
        else if (x < 0xe42) o->y = -((s16)(x - 0xd2a) * 182) / 279 - 0x49c;
        else if (x < 0xfbf) o->y = -((s16)(x - 0xe41) * 238) / 381 - 0x552;
        else if (x < 0x10b2) o->y = (s16)(x - 0xfbe) * 170 / 243 - 0x640;
        else if (x < 0x1268) o->y = -((s16)(x - 0x10b1) * 470) / 438 - 0x596;
        else if (x < 0x1384) o->y = -((s16)(x - 0x1267) * 270) / 284 - 0x76c;
        else if (x < 0x1548) o->y = -((s16)(x - 0x1383) * 145) / 452 - 0x87a;
        else o->y = -0x90b;
    } else if (GAME.selectedSection == 2) {
        if (x < 0x259) o->y = -0x168;
        else if (x < 0x385) o->y = -((s16)(x - 0x258) * 150) / 300 - 0x168;
        else if (x < 0x3e9) o->y = -((s16)(x - 0x384) * 70) / 100 - 0x1fe;
        else if (x < 0x641) o->y = -((s16)(x - 0x3e8) * 30) / 600 - 0x244;
        else o->y = -0x262;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801167E4);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03", D_801151F8);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03", func_80115214);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80116814);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80116C78);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", updatePointsBalloon);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_8011700C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117114);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117134);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801172E8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117390);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801173FC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801175D4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_8011767C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117790);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_801178B8);
typedef struct { char pad[0xc6]; u16 wc6; } XC_178B8;
typedef struct { s16 s[10]; } E_178B8;
typedef struct { E_178B8 e[6]; char pad[0x8c - 0x78]; } G_178B8;
typedef struct { s16 s0, s2, s4, s6, s8, sa; char pad[0x8c - 0xc]; } G2_178B8;
typedef struct { s16 a, b, c, d, e, f, g, h, i; } T_178B8;
extern G2_178B8 D_800A33C0[];
extern T_178B8 D_80134A5E[];
extern s16 *D_80134BD8[];

#define g ((G2_178B8 *)e)

void func_801178B8(GameObject *o)
{
    E_178B8 *e;
    s16 *p;
    s32 i;

    switch (o->state) {
    case 0:
        if (--o->timer == 0) o->state++;
        break;
    case 1:
        if (func_80022E44(o) == 0) o->state++;
        for (i = 0; i < 6; i++) {
            e = &((G_178B8 *)&LOAD_BUFFER)[((XC_178B8 *)o)->wc6].e[i];
            switch (e->s[0]) {
            case 0:
            case 6:
                break;
            case 2:
            case 3:
                if (e->s[6] <= 0) e->s[7] = 0;
                if (e->s[8] <= 0) e->s[9] = 0;
            case 1:
            case 4:
            case 5:
                e->s[3] -= e->s[6];
                e->s[5] -= e->s[8];
                e->s[6] += e->s[7];
                e->s[8] += e->s[9];
                if (--e->s[1] <= 0) {
                    p = &D_80134A5E[e->s[0]].a;
                    e->s[1] = *p++;
                    e->s[6] = *p++;
                    e->s[7] = *p++;
                    e->s[8] = p[0];
                    e->s[9] = p[1];
                    e->s[0]++;
                }
                break;
            }
        }
        e = (E_178B8 *)&D_800A33C0[((XC_178B8 *)o)->wc6];
        switch (g->s0) {
        case 0:
            break;
        case 1:
            if (--g->s2 > 0) break;
            o->unk90 = (s32)D_80134BD8[o->subtype];
            g->s2 = 0x12;
            g->s0++;
            break;
        case 2:
            p = (s16 *)o->unk90;
            g->s4 += p[0];
            g->s6 += p[1];
            g->s8 -= p[0];
            g->sa -= p[1];
            o->unk90 = (s32)(p + 2);
            if (--g->s2 > 0) break;
            g->s2 = 0x1e;
            g->s0++;
            break;
        case 3:
            if (--g->s2 > 0) break;
            o->state = 2;
            break;
        }
        break;
    case 2:
        ((G_178B8 *)&LOAD_BUFFER)[((XC_178B8 *)o)->wc6].e[0].s[0] = -1;
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
#undef g

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117C4C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80117C60);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03", func_80118044);


extern void *D_80138254[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);

void func_80118044(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C608.purifiedAreas & 2) o->subtype += 2;
        o->tpage = 8;
        o->unkD = 0;
        o->state++;
        o->spriteBank = SCRATCHPAD.sprData[3];

        o->anim = D_80138254[o->subtype];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o)) tickAnimation(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
