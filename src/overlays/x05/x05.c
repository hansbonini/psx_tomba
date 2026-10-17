#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011530C);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115330);

extern void *D_801193B8[];
extern void readAnimFrameCount(GameObject *);
extern void tickAnimation(GameObject *);
extern void pushDrawListCapped(GameObject *);

void func_80115330(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->animFrame = 1;
        o->clut = GetClut(0x80, 0x1ff);
        o->unkA = 7;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        switch (o->subtype) {
        case 0:
            o->unkD = 0x81;
            o->z.p.whole = 0x82;
            o->unkF = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        case 1:
            o->unkD = 1;
            o->z.p.whole = 0x82;
            o->unkF = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        case 2:
            o->unkD = 1;
            o->unkF = 1;
            o->z.p.whole = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        o->x.p.whole = o->unk30 - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2));
        o->y.p.whole = o->unk34 - (u16)SCRATCHPAD.unk168[7].p.whole;
        pushDrawListCapped(o);
        tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801154F8);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801155A8);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115604);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115608);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801158DC);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801159E0);



typedef struct { s16 v[6]; } V6_159E0;
extern s32 showMessageBoxDirect(s32, s32, V6_159E0 *);

void func_801159E0(GameObject *o)
{
    V6_159E0 v;
    GameObject *p;

    switch (o->step) {
    case 0:
        if (o->unk68 == 0) break;
        v = *(V6_159E0 *)&o->x;
        o->unk90 = showMessageBoxDirect(2, 0x33, &v);
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_8009C608.playerEquips = 2;
        ((u8*)&PLAYER.obj.state)[0] = 5;
        ((u8*)&PLAYER.obj.subState)[0] = 0;
        ((u8*)&PLAYER.obj.step)[0] = 0;
        o->unkBC = o->animFrame;
        o->animFrame = o->unk68 & 1;
        o->step++;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        SCRATCHPAD.unk1C6 = 0;
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((s16*)&PLAYER.obj.unkB2)[0] = 0;
        if (D_8009BC98.unk0F == 0) {
            ((u8*)&PLAYER.obj.state)[0] = 1;
            ((u8*)&PLAYER.obj.subState)[0] = 0;
            ((u8*)&PLAYER.obj.step)[0] = 0;
        }
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        o->animFrame = o->unkBC;
        break;
    }
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115B40);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115C70);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115CDC);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115D0C);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115E94);



typedef struct { s16 v[6]; } V6_15E94;
extern void addItemToInventory(s32, s32, s32);

void func_80115E94(GameObject *o)
{
    V6_15E94 v;
    GameObject *p;
    u8 *f;

    switch (o->step) {
    case 0:
        if (o->unk68 == 0) break;
        v = *(V6_15E94 *)&o->x;
        if (D_8009C068.unk6a8) {
            o->unk90 = showMessageBoxDirect(2, 0x66, &v);
        } else {
            o->unk90 = showMessageBoxDirect(2, 0x65, &v);
        }
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_8009C608.playerEquips = 2;
        ((u8*)&PLAYER.obj.state)[0] = 5;
        ((u8*)&PLAYER.obj.subState)[0] = 0;
        ((u8*)&PLAYER.obj.step)[0] = 0;
        o->unkBC = o->animFrame;
        o->animFrame = o->unk68 & 1;
        o->step++;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        f = &D_8009C068.unk6a8;
        if (*f == 0) {
            addItemToInventory(ITEM_WINE, 1, 1);
            *f = 1;
        }
        SCRATCHPAD.unk1C6 = 0;
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((s16*)&PLAYER.obj.unkB2)[0] = 0;
        if (((u8*)&D_8009BC98.unk0F)[0] == 0) {
            ((u8*)&PLAYER.obj.state)[0] = 1;
            ((u8*)&PLAYER.obj.subState)[0] = 0;
            ((u8*)&PLAYER.obj.step)[0] = 0;
        }
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        o->animFrame = o->unkBC;
        break;
    }
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116048);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801160A0);

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", func_80115214);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801161C8);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801163A0);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80117050_163A0;

extern T80117050_163A0 D_80116A14[];
extern s32 SPR_DATA[];

extern void readAnimFrameCount(GameObject *);

void func_801163A0(GameObject *o)
{
    o->hitOffsetX = D_80116A14[o->subtype].b0;
    o->hitWidth = D_80116A14[o->subtype].b1;
    o->hitOffsetY = D_80116A14[o->subtype].b2;
    o->hitHeight = D_80116A14[o->subtype].b3;
    o->tpage = D_80116A14[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80116A14[o->subtype].w6];
    o->anim = D_80116A14[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unk8C = 0;
    o->unkD = 0;
    o->unkF = 0;
    o->category |= 0x80;
    o->state++;
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801164F4);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011659C);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116814);

void func_80116968(void) {
}

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116970);
void func_80116970(GameObject *o)
{
    o->state = 3;
}

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011697C);
extern void func_8011659C(GameObject *);
extern void freeObjectUnlayered(GameObject *);

void func_8011697C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8011659C(o);
        o->state++;
        break;
    case 1:
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", D_80115234);

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", func_80115274);
