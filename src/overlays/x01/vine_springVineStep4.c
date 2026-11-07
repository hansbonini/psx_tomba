#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011b958 388 X001
// MATCHING 8011b958 388
extern short COS_TABLE[];

void springVineStep4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velV = 0;
        o->velH = 0;
        o->velV = 0x200;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->velY = -0x80;
        o->timer = 0;
        o->step++;
        break;
    case 1:
        if (o->timer > 0) {
            o->step = 2;
            break;
        }
        o->unk88 += 4;
        if ((o->unk88 & 0xff) == 0) {
            o->velV += o->velY;
            o->y.raw = o->unk34;
            o->timer++;
        }
        o->y.raw += (COS_TABLE[(unsigned char)o->unk88] * o->velV) >> 4;
        if (o->unk6A == 1) {
            o->step++;
        }
        break;
    case 2:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->timer = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

#endif
