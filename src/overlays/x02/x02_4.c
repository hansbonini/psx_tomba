#include "common.h"
#include "game.h"
#include "x02.h"

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_801187FC);

void func_801187FC(GameObject *o)
{
    u8 *p;
    u8 r, g, b;
    u8 *k;
    u8 n;

    switch (o->state) {
    case 0:
        p = D_8007F938[GAME.selectedArea] + GAME.selectedSection * 4;
        r = *p++;
        g = p[0];
        b = p[1];
        GAME.fadeScreenControl = 1;
        GAME.fadeScreenAmount = 0;
        D_8009D6DD = r;
        D_8009D6DE = g;
        D_8009D6DF = b;
        D_8009E3ED = r;
        D_8009E3EE = g;
        D_8009E3EF = b;
        o->state++;
        switch (D_8009C068.event_B3) {
        case 1: case 2: case 3:
            GAME.fadeScreenControl = 0x10;
            GAME.fadeScreenAmount = 0xc0;
            o->state = 5;
            break;
        }
        break;
    case 1:
        k = &GAME.fadeScreenControl;
        n = GAME.fadeScreenAmount + 8;
        *k = 2;
        GAME.fadeScreenAmount = n;
        if (n == 0) {
            *k = 0;
            o->state++;
        }
        break;
    case 2:
        k = &GAME.fadeScreenControl;
        if (*k == 3) {
            { s32 m = -GAME.fadeScreenAmount;
            *k = 2;
            GAME.fadeScreenAmount = m; }
            o->state++;
        }
        break;
    case 3:
        k = &GAME.fadeScreenControl;
        n = GAME.fadeScreenAmount - 8;
        *k = 2;
        GAME.fadeScreenAmount = n;
        if (n == 0) {
            *k = 1;
            o->state++;
            D_8009D6DD = 0;
            D_8009D6DE = 0;
            D_8009D6DF = 0;
            D_8009E3ED = 0;
            D_8009E3EE = 0;
            D_8009E3EF = 0;
        }
        break;
    case 4:
        if (GAME.fadeScreenControl == 4) o->state = 0;
        break;
    case 5:
        k = &GAME.fadeScreenControl;
        if (*k == 3) {
            n = -GAME.fadeScreenAmount;
            *k = 2;
            GAME.fadeScreenAmount = n;
            o->state = 3;
        } else if (D_8009C068.event_B3 == 0xff) {
            o->state = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80118A60);
extern void spawnItem(s16, s16, void *);

void func_80118A60(void)
{
    Fix16 v[3];

    if (GAME.playerAP >= D_8009BCF4 && D_8009C068.event_27 != 0 && GAME.goldenFlowerState == 0) {
        v[0].p.whole = 0xb0;
        v[1].p.whole = -0x38;
        v[2].p.whole = 0;
        spawnItem(0x5f, 0, v);
    }
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80118AD8);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80118C58);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80118C64);
typedef struct { s16 xf, x, yf, y, zf, z; } V6_18C64;

void func_80118C64(GameObject *o)
{
    V6_18C64 v;

    switch (o->state) {
    case 0:
        if (GAME.playerAP >= D_8009BCF4 && D_8009C068.event_27 != 0 && GAME.goldenFlowerState == 0) {
            v.x = 0xb0;
            v.y = -0x38;
            v.z = 0;
            spawnItem(0x5f, 0, &v);
        }
        o->state++;
        break;
    case 1:
        func_80118AD8(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80118D6C);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80119268);
typedef struct { s16 v[2][8][2]; } T_19268;
extern T_19268 D_80115344;

void func_80119268(s32 k, s32 x, s32 y, s32 z)
{
    T_19268 t;
    GameObject *o;
    s16 *p;

    t = D_80115344;
    o = allocObjectLayer3();
    if (o != 0) {
        o->active = 1;
        o->type = 0x31;
        o->subtype = 1;
        p = t.v[k & 1][D_1F8001F8 & 7];
        o->x.p.whole = x;
        o->y.p.whole = y;
        o->z.p.whole = z;
        o->h->p.whole += p[0];
        o->y.p.whole += p[1];
    }
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_801193D0);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80119404);

INCLUDE_RODATA("overlays/x02/nonmatchings/x02/x02_4", D_80115344);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011943C);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_80119798);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011A4B4);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011A650);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011A7C0);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011AAF4);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B0D0);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B1CC);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B814);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B91C);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B944);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_4", func_8011B950);

void func_8011B950(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80118D6C(o);
        o->state++;
        break;
    case 1:
        func_8011B814(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

void func_8011B9F8(void) {
}

INCLUDE_RODATA("overlays/x02/nonmatchings/x02/x02_4", func_801155A8);

INCLUDE_RODATA("overlays/x02/nonmatchings/x02/x02_4", func_80115608);
