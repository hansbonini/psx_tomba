#include "common.h"
#include "game.h"
#include "x05.h"

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011530C);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115330);


void func_80115330(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->animFrame = 1;
        o->clut = GetClut(0x80, 0x1ff);
        o->drawType = 7;
        o->localX = o->x.p.whole;
        o->localY = o->y.p.whole;
        switch (o->id) {
        case 0:
            o->drawFlags = 0x81;
            o->z.p.whole = 0x82;
            o->priority = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->id];
            break;
        case 1:
            o->drawFlags = 1;
            o->z.p.whole = 0x82;
            o->priority = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->id];
            break;
        case 2:
            o->drawFlags = 1;
            o->priority = 1;
            o->z.p.whole = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->id];
            break;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        o->x.p.whole = o->localX - (*(u16*)((char*)&SCRATCHPAD.cameraPos.x.raw + 2));
        o->y.p.whole = o->localY - (u16)SCRATCHPAD.screenOrigin.y.p.whole;
        pushEffectDrawList(o);
        tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeEffectObject(o);
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
        o->parent = showMessageBoxDirect(2, 0x33, &v);
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
        p = (GameObject *)o->parent;
        if (p->state != 2) break;
        p->state = 3;
        SCRATCHPAD.drawFrozen = 0;
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
            o->parent = showMessageBoxDirect(2, 0x66, &v);
        } else {
            o->parent = showMessageBoxDirect(2, 0x65, &v);
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
        p = (GameObject *)o->parent;
        if (p->state != 2) break;
        p->state = 3;
        f = &D_8009C068.unk6a8;
        if (*f == 0) {
            addItemToInventory(ITEM_WINE, 1, 1);
            *f = 1;
        }
        SCRATCHPAD.drawFrozen = 0;
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

extern ObjSetupHitbox D_80116A14[];
extern s32 SPR_DATA[];


void func_801163A0(GameObject *o)
{
    o->hitboxX = D_80116A14[o->id].b0;
    o->hitboxW = D_80116A14[o->id].b1;
    o->hitboxY = D_80116A14[o->id].b2;
    o->hitboxH = D_80116A14[o->id].b3;
    o->tpage = D_80116A14[o->id].w4;
    o->spriteBank = SPR_DATA[D_80116A14[o->id].w6];
    o->anim = D_80116A14[o->id].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->rotZ = 0;
    o->drawFlags = 0;
    o->priority = 0;
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
        freeAreaCtrlObject(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", D_80115234);

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", func_80115274);
