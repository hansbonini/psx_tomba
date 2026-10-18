#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116814);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801169CC);


extern void setEventComplete(s32, s32);
extern void removeItemFromInventory(s32, s32);

void func_801169CC(GameObject *o)
{
    switch (o->step) {
    case 0:
        PLAYER.obj.state = PLAYER_SCRIPTED;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        o->step++;
        break;
    case 1:
        D_8009BC98.unk0E = 1;
        setEventComplete(0x61, 0);
        removeItemFromInventory(ITEM_IRONWHEEL, D_8009C068.item_3E);
        o->clut = 200;
        o->step++;
        break;
    case 2:
        if (--o->clut <= 0) {
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            PLAYER.obj.unkB2 = 0;
            PLAYER.obj.state = PLAYER_ACTIVE;
            PLAYER.obj.subState = PLAYER_IDLE;
            PLAYER.obj.step = 0;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116B00);


typedef struct { s16 s0, s2; } S2_16B00;

void func_80116B00(GameObject *o)
{
    if (D_8009C068.event_61 == 0xff) return;
    if ((u16)((*(S2_16B00 **)&PLAYER.obj.h)->s2 - 0x82) >= 0x28) return;
    if (PLAYER.obj.y.p.whole != -0x3d) return;
    if (D_8009BC98.unk10 != 0 && D_8009BC98.unk11 == 0x3e) {
        o->subState = 2;
        o->step = 0;
    } else if ((*(volatile u16 *)&D_8009C968.w70 & 0x10) && (SCRATCHPAD.joypad_state & JOY_CIRCLE)) {
        D_8009BC98.unk0E = 1;
        o->subState = 1;
        o->step = 0;
    }
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116BC0);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116C78);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116CE8);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116CF4);


extern void func_80116808(GameObject *);
extern void freeObjectUnlayered(GameObject *);

void func_80116CF4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->subState = 0;
        o->step = 0;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (D_8009C068.event_61 == 0xff) break;
            if ((u16)((*(Fix16 **)&PLAYER.obj.h)->p.whole - 0x82) >= 0x28) break;
            if (PLAYER.obj.y.p.whole != -0x3d) break;
            if (D_8009BC98.unk10 != 0 && D_8009BC98.unk11 == 0x3e) {
                o->subState = 2;
                o->step = 0;
                break;
            }
            if ((*(volatile u16 *)&D_8009C968.w70 & 0x10) && (SCRATCHPAD.joypad_state & JOY_CIRCLE)) {
                D_8009BC98.unk0E = 1;
                o->subState = 1;
                o->step = 0;
            }
            break;
        case 1:
            func_80116808(o);
            break;
        case 2:
            func_801169CC(o);
            break;
        }
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80116E90);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", updatePointsBalloon);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_8011700C);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117084);
void func_80117084(GameObject *o)
{
    if (o->h->p.whole < (*(Fix16 **)&PLAYER.obj.h)->p.whole) (*(Fix16 **)&PLAYER.obj.h)->p.whole = o->h->p.whole;
    if (o->unk68) {
        o->subState = 1;
        o->step = 0;
    }
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801170D0);
void func_801170D0(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (o->h->p.whole < (*(Fix16 **)&PLAYER.obj.h)->p.whole) {
            (*(Fix16 **)&PLAYER.obj.h)->p.whole = o->h->p.whole;
        }
        if (o->unk68) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 1:
        func_80116E90(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117154);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80117E04_17154;

extern T80117E04_17154 D_80118064[];
extern s32 SPR_DATA[];

extern void readAnimFrameCount(GameObject *);

void func_80117154(GameObject *o)
{
    o->hitOffsetX = D_80118064[o->subtype].b0;
    o->hitWidth = D_80118064[o->subtype].b1;
    o->hitOffsetY = D_80118064[o->subtype].b2;
    o->hitHeight = D_80118064[o->subtype].b3;
    o->tpage = D_80118064[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80118064[o->subtype].w6];
    o->anim = D_80118064[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unk8C = 0;
    o->unkD = 0;
    o->unkA = 0;
    o->unkF = 0;
    o->subState = 0;
    o->category |= 0x80;
    o->state++;
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801172B0);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801172E8);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117390);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801173C4);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801173FC);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", func_80115274);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_8011744C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_8011767C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117790);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801177A8);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_801178B8);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117B74);

extern u8 D_8009C497;

void func_80117B74(GameObject *o)
{
    if (D_8009BC98.unk10 != 0) {
        if (D_8009BC98.unk11 == 3 && D_8009C497 == 0) {
            o->subState = 2;
            o->step = 0;
        }
        D_8009BC98.unk10 = 0;
    } else if (o->unk68 != 0) {
        o->subState = 1;
        o->step = 0;
    }
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117BE8);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117C4C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117C60);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117CC4);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80118974_17CC4;

extern T80118974_17CC4 D_8011807C[];

void func_80117CC4(GameObject *o)
{
    o->hitOffsetX = D_8011807C[o->subtype].b0;
    o->hitWidth = D_8011807C[o->subtype].b1;
    o->hitOffsetY = D_8011807C[o->subtype].b2;
    o->hitHeight = D_8011807C[o->subtype].b3;
    o->tpage = D_8011807C[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_8011807C[o->subtype].w6];
    o->anim = D_8011807C[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unk8C = 0;
    o->unkD = 0;
    o->unkA = 0;
    o->unkF = 0;
    o->subState = 0;
    o->category |= 0x80;
    o->state++;
    if (D_8009C068.event_49 == 0xff) o->state = 3;
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16_1", func_80117E38);

void func_80117E38(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80117CC4(o);
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (D_8009BC98.unk10 != 0) {
                if (D_8009BC98.unk11 == 3 && D_8009C497 == 0) {
                    o->subState = 2;
                    o->step = 0;
                }
                D_8009BC98.unk10 = 0;
            } else if (o->unk68 != 0) {
                o->subState = 1;
                o->step = 0;
            }
            break;
        case 1:
            func_8011744C(o);
            break;
        case 2:
            func_801177A8(o);
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_801152D8);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_8011531C);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_80115354);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_801153AC);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_80115408);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16_1", D_8011547C);
