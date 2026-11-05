#include "common.h"
#include "game.h"
#include "x03.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129010);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129A28);


extern ObjSetupHitbox D_80135108[];

void func_80129A28(GameObject *o)
{
    o->hitboxX = D_80135108[o->id].b0;
    o->hitboxW = D_80135108[o->id].b1;
    o->hitboxY = D_80135108[o->id].b2;
    o->hitboxH = D_80135108[o->id].b3;
    o->tpage = D_80135108[o->id].w4;
    o->spriteBank = SPR_DATA[D_80135108[o->id].w6];
    if (D_8009C068.event_23 != 0xff) o->anim = D_80135108[o->id].anim[1];
    else o->anim = D_80135108[o->id].anim[2];
    readAnimFrameCount(o);
    o->drawType = 2;
    o->rotZ = 0;
    o->drawFlags = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->priority = PLAYER.obj.priority + 1;
    o->state++;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129BE0);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_6", func_801158DC);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_6", jtbl_80115B60);
