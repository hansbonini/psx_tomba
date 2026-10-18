#include "common.h"
#include "game.h"
#include "x02.h"

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02", func_801158D8);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02", func_801158DC);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02", func_8011592C);


void func_8011592C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unkD = 1;
        o->animFrame = 1;
        o->unkA = 0;
        switch (o->subtype) {
        case 0:
            o->tpage = 4;
            o->clut = GetClut(0x80, 0x1ff);
            o->anim = D_8011E5EC[o->subtype];
            *(s8 *)&o->unkF = -10;
            break;
        case 1:
            o->tpage = 4;
            o->clut = GetClut(0x80, 0x1ff);
            o->anim = D_8011E5EC[o->subtype];
            o->unkF = 0;
            o->unkD = 0x81;
            break;
        case 2:
        case 3:
            o->tpage = 4;
            o->clut = GetClut(0x80, 0x1ff);
            o->anim = D_8011E5EC[o->subtype];
            o->unkF = 0;
            break;
        case 4:
            o->tpage = 10;
            o->clut = GetClut(0x80, 0x1fe);
            o->unkF = 0;
            o->anim = D_8011E510;
            break;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->subtype != 4 && func_80022E44(o))
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

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02", func_80115B0C);

void func_80115C70(void) {
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02", func_80115C78);
