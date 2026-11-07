#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011a1c0 872 X001
// MATCHING 8011a1c0 872
typedef struct { short x, y, z, pad; } E8;
extern unsigned char D_8013C47C[];
extern void *D_8013E5AC, *D_8013E5BC;
extern int cullObjectToDrawListMargin(GameObject *, int);
extern void stepSpringVine(GameObject *);
extern void FUN_80018838(GameObject *);

#define E(i) (((E8 *)&o->unkB4)[i])

void updateSpringVine(GameObject *o)
{
    GameObject *p;
    short dx, dy;

    switch (o->state) {
    case 0:
        o->tpage = 8;
        o->unkD = 0;
        o->unkE = o->unkF;
        o->spriteBank = SPAD->sprData[3];
        o->state++;
        o->subState = 0;
        o->step = 0;
        *(short *)((char *)o + 0x98) = 0;
        o->unk30 = o->h->raw;
        o->unk34 = o->y.raw;
        o->unk74 = 0;
        o->unk76 = D_8013C47C[o->unkC];
        o->unk9A = 0;
        switch (o->subtype) {
        case 0:
            o->anim = D_8013E5AC;
            o->hitOffsetX = 0xc;
            o->hitWidth = 0x18;
            o->hitOffsetY = 0xe;
            o->unk68 = 0;
            o->touchFlag = 0;
            o->unk6A = 0;
            o->hitHeight = 0x1a;
            break;
        case 1:
            o->active = 2;
            o->hitOffsetY = 0;
            o->hitOffsetX = 4;
            o->hitWidth = 4;
            o->unkF = o->unkE + 6;
            break;
        case 2:
            o->unkF = 2;
            o->active = 2;
            o->anim = D_8013E5BC;
            p = (GameObject *)o->unk90;
            o->hitOffsetX = 4;
            o->hitWidth = 4;
            o->hitOffsetY = 0;
            dy = p->y.p.whole - o->y.p.whole;
            dx = p->h->p.whole - o->h->p.whole;
            if (SPAD->unk1C8 & 1) {
                E(0).y = 0;
                E(0).x = 0;
                E(1).y = 0;
                E(1).x = 0;
                E(2).y = dy;
                E(2).x = 0;
                E(3).y = dy;
                E(3).x = 0;
                E(0).z = dx - o->hitOffsetX;
                E(1).z = dx + o->hitWidth;
                E(2).z = dx - o->hitOffsetX;
                E(3).z = dx + o->hitWidth;
            } else {
                E(0).y = 0;
                E(0).z = 0;
                E(1).y = 0;
                E(1).z = 0;
                E(2).y = dy;
                E(2).z = 0;
                E(3).y = dy;
                E(3).z = 0;
                E(0).x = dx - o->hitOffsetX;
                E(1).x = dx + o->hitWidth;
                E(2).x = dx - o->hitOffsetX;
                E(3).x = dx + o->hitWidth;
            }
            break;
        }
        break;
    case 1:
        if (D_8009BC98.unk12 != 0 || o->subtype == 2) {
            cullObjectToDrawListMargin(o, 0x40);
            break;
        }
        if (o->subState == 0) {
            if (cullObjectToDrawListMargin(o, 0x40) == 0) goto clear;
            if (o->unk6A == 1) {
                o->subState = 1;
                o->step = 0;
            } else if (o->unk68 == 1) {
                if ((o->animFrame >> 1) != 2) o->subState = 2;
                else o->subState = 3;
                o->step = 0;
            } else if (o->touchFlag == 4) {
                o->subState = 3;
                o->step = 0;
            } else if (o->touchFlag == 1) {
                o->subState = 4;
                o->step = 0;
            }
        } else {
            cullObjectToDrawListMargin(o, 0x40);
        }
        stepSpringVine(o);
    clear:
        o->unk68 = 0;
        o->touchFlag = 0;
        o->unk9A = 0;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        FUN_80018838(o);
        break;
    }
}

#endif
