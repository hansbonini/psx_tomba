#include "common.h"
#include "game.h"
#include "x03.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129010);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129A28);


extern ObjSetupHitbox D_80135108[];

void func_80129A28(GameObject *o)
{
    o->hitOffsetX = D_80135108[o->subtype].b0;
    o->hitWidth = D_80135108[o->subtype].b1;
    o->hitOffsetY = D_80135108[o->subtype].b2;
    o->hitHeight = D_80135108[o->subtype].b3;
    o->tpage = D_80135108[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80135108[o->subtype].w6];
    if (D_8009C068.event_23 != 0xff) o->anim = D_80135108[o->subtype].anim[1];
    else o->anim = D_80135108[o->subtype].anim[2];
    readAnimFrameCount(o);
    o->unkA = 2;
    o->unk8C = 0;
    o->unkD = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->unkF = PLAYER.obj.unkF + 1;
    o->state++;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_6", func_80129BE0);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_6", func_801158DC);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_6", jtbl_80115B60);
