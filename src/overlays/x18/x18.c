#include "common.h"
#include "game.h"
#include "x18.h"

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_801158A0);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_801158CC);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_801158DC);

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_801158F8);


void func_801158F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->animFrame = 1;
        o->unkA = 7;
        o->unkD = 1;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        o->clut = GetClut(0x80, 0x1ff);
        o->tpage = 4;
        o->anim = D_8011BE40[o->unkC];
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        o->x.p.whole = o->unk30 - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2));
        {
            s32 y = o->unk34;
            o->y.p.whole = y - (u16)SCRATCHPAD.unk168[7].p.whole;
        }
        o->visible = 1;
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

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_80115A40);



#define PT(o) ((Vec3s *)((char *)(o) + 0xb4))

void func_80115A40(GameObject *o)
{
    u8 t = o->state;
    u8 u;

    switch (t) {
    case 0:
        o->state = t + 1;
        o->unkF = 0x40;
        o->unkD = 0x81;
        o->tpage = 0xb;
        o->clut = 0x7c0c;
        o->spriteBank = SCRATCHPAD.sprData[2];
        o->anim = D_8011BDFC[o->unkC];
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        u = o->subState;
        switch (u) {
        case 0:
            o->subState = u + 1;
            PT(o)[0].x = D_801197F0[0];
            PT(o)[0].y = D_801197F0[1];
            PT(o)[0].z = 0;
            PT(o)[1].x = D_801197F0[2];
            PT(o)[1].y = D_801197F0[3];
            PT(o)[1].z = 0;
            PT(o)[2].x = D_801197F0[4];
            PT(o)[2].y = D_801197F0[5];
            PT(o)[2].z = 0;
            PT(o)[3].x = D_801197F0[6];
            PT(o)[3].y = D_801197F0[7];
            PT(o)[3].z = 0;
            break;
        case 1:
            o->x.raw += 0xc000;
            if (o->x.p.whole >= 0x1e1) o->x.p.whole = -0x78;
            break;
        case 2:
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
#undef PT

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_80115BF0);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_80115C70);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_80115D0C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18", func_80115EA8);
