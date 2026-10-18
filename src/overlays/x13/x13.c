#include "common.h"
#include "game.h"
#include "x13.h"

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115304);



typedef void (*Fn_15304)(GameObject *);

extern Fn_15304 D_8007C59C[];
extern void func_8002A798(GameObject *);
extern void func_8002BB9C(GameObject *);

void func_80115304(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (((u8*)&GAME.disableSelectMenu)[0] != 0) {
            if (stepScrollReturnY(o) & stepScrollClearX(o)) ((u8*)&GAME.disableSelectMenu)[0] = 0;
            break;
        }
        o->subtype = 0;
        o->subState++;
        break;
    case 1:
        if (D_8009BC98.unk0A != 0) o->subState++;
        func_8002A798(o);
        func_8002A480(o);
        syncObjectTargetY(o);
        func_8002BB9C(o);
        GAME.selectedSpawnPoint = 0;
        break;
    case 2:
        D_8007C59C[o->subtype](o);
        if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 2) {
            stepPlayerXToward(0xa0);
            if (SCRATCHPAD.unk168[2].p.whole >= 0x50) {
                PLAYER.obj.state = PLAYER_SCRIPTED;
                PLAYER.obj.visible = 0;
                PLAYER.obj.subState = 0x41;
                PLAYER.obj.step = 0;
                o->subState++;
            }
        }
        break;
    case 3:
        o->unk48 = 0x2d;
        o->subState++;
        PLAYER.obj.velY = 0;
        break;
    case 4:
        if (--o->unk48 == -1) {
            (*(s16*)&GAME.nextArea) = 1;
            (*(s16*)&GAME.nextSection) = 4;
            (*(s16*)&GAME.nextSpawnPoint) = 4;
            D_8009BC98.unk0C = 0;
            GAME.fadeScreenControl = 3;
            o->subState++;
        }
    case 5:
        {
            s16 *k = &PLAYER.obj.velY;
            *k += 0x20;
            if (*k > 0x500) *k = 0x500;
            { s32 *g = &SCRATCHPAD.vpy.raw; *g += *k << 8; }
        }
        if (GAME.fadeScreenControl == 1) {
            (*(GameTask **)&D_1F8001D4)->mode = 7;
            (*(GameTask **)&D_1F8001D4)->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115584);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_801155A8);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115608);

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115620);
typedef struct {
    char pad[0x2c];
    s16 xmin, xmax, ymin, ymax;
    Fix16 *pos;
} Cam_15620;

void func_80115620(Cam_15620 *c)
{
    GameObject *pl;

    if (GAME.selectedSection == 0) {
        func_80115304(c);
        return;
    }
    pl = &PLAYER;
    c->pos->raw = pl->h->raw;
    if (c->xmax < c->pos->p.whole) {
        c->pos->raw = c->xmax << 16;
    } else if (c->pos->p.whole < c->xmin) {
        c->pos->raw = c->xmin << 16;
    }
    D_1F8000F0.raw = pl->y.raw;
    if (D_1F8000F0.p.whole > c->ymax) {
        D_1F8000F0 = c->ymax << 16;
    } else if (D_1F8000F0.p.whole < c->ymin) {
        D_1F8000F0 = c->ymin << 16;
    }
}

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_801156E8);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_801158DC);

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115A30);
typedef struct { u8 b0, b1, b2, b3; s32 d4; } S_15A30;

void func_80115A30(S_15A30 *a, S_15A30 *b)
{
    a->d4 = (s32)b + b->d4;
    a->b3 = 1;
}

INCLUDE_RODATA("overlays/x13/nonmatchings/x13/x13", func_80115214);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115A48);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115C70);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115D0C);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_8011602C);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_801160A0);

INCLUDE_RODATA("overlays/x13/nonmatchings/x13/x13", func_80115274);
