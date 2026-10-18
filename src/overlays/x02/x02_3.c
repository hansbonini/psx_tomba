#include "common.h"
#include "game.h"
#include "x02.h"

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_801179D4);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_80117C4C);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_80117C60);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_80118340);


void func_80118340(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->anim = D_8011EEEC[o->subtype];
        readAnimFrameCount(o);
        o->step++;
        break;
    case 1:
        if (D_8009C068.unk68a == 2) {
            o->subState = 2;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_801183D8);

void func_801183D8(GameObject *o)
{
    void *e = D_8009E694[o->subtype];

    switch (o->step) {
    case 0:
        if (--o->timer <= 0) {
            o->velY = 0;
            o->step++;
        }
        break;
    case 1:
        o->y.raw += o->velY << 8;
        o->velY -= 0x10;
        if (o->velY == -0x80) {
            func_80115C78(e, 1, 0);
        }
        if (o->velY < -0x600) {
            o->velY = -0x600;
        }
        if (o->visible == 0) {
            o->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_801184C8);
void func_801184C8(GameObject *o)
{
    void *e;

    switch (o->subState) {
    case 0:
        if (D_8009C068.unk68a == 1) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 1:
        switch (o->step) {
        case 0:
            o->anim = D_8011EEEC[o->subtype];
            readAnimFrameCount(o);
            o->step++;
            break;
        case 1:
            if (D_8009C068.unk68a == 2) {
                o->subState = 2;
                o->step = 0;
            }
            break;
        }
        break;
    case 2:
        e = D_8009E694[o->subtype];
        switch (o->step) {
        case 0:
            if (--o->timer > 0) break;
            o->velY = 0;
            o->step++;
            break;
        case 1:
            o->y.raw += o->velY << 8;
            o->velY -= 0x10;
            if (o->velY == -0x80) func_80115C78(e, 1, 0);
            if (o->velY < -0x600) o->velY = -0x600;
            if (o->visible == 0) o->state = 3;
            break;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_3", func_80118680);
extern s32 D_1F8002D0[];

void func_80118680(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C068.event_9D != 0) {
            o->state = 2;
            break;
        }
        o->tpage = 7;
        o->unkD = 0;
        o->spriteBank = D_1F8002D0[0];
        o->anim = D_8011EF08[o->subtype];
        readAnimFrameCount(o);
        if (o->subtype >= 4)
            o->animFrame = 1;
        switch (o->subtype) {
        case 0:
            o->timer = 120;
            break;
        case 1:
            o->timer = 180;
            break;
        case 2:
            o->timer = 60;
            break;
        case 3:
            o->timer = 240;
            break;
        case 4:
            o->timer = 30;
            break;
        case 5:
            o->timer = 0;
            break;
        case 6:
            o->timer = 150;
            break;
        }
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        func_801184C8(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
