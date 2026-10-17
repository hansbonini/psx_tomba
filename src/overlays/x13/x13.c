#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13", func_80115304);


typedef struct GameTask_15304 {
    s16 status;
    s16 sleepTimer;
    s32 task_id;
    s32 task_sp;
    s32 task_func;
    s32 task_gp;
    volatile u16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
    u8 unk3a;
    u8 unk3b;
    u8 unk3c;
    u8 unk3d;
    u8 unk3e;
    u8 unk3f;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    s16 state0;
    s16 state1;
    s16 mode;
    s16 step;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u16 timer;
    u16 unk5A;
    u16 countdown;
    u16 unk5E;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    u8 unk66;
    u8 unk67;
    u8 loadGameSelected;
    u8 titleScreenSelectedOption;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
} GameTask_15304;

typedef void (*Fn_15304)(GameObject *);

extern Fn_15304 D_8007C59C[];
extern u32 stepScrollReturnY(GameObject *);
extern u32 stepScrollClearX(GameObject *);
extern void func_8002A798(GameObject *);
extern void func_8002A480(GameObject *);
extern void syncObjectTargetY(GameObject *);
extern void func_8002BB9C(GameObject *);
extern s32 stepPlayerXToward(s32);

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
            (*(GameTask_15304 **)&D_1F8001D4)->mode = 7;
            (*(GameTask_15304 **)&D_1F8001D4)->step = 0;
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
