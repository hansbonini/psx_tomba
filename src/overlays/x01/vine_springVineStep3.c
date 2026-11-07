#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011b624 296 X001
// MATCHING 8011b624 296

extern short COS_TABLE[];

#define RESET(o) \
    (o)->y.raw = (o)->unk34; \
    (o)->h->raw = (o)->unk30; \
    (o)->velH = 0; \
    (o)->velV = 0; \
    (o)->velX = 0; \
    (o)->velY = 0; \
    (o)->unk84 = 0; \
    (o)->unk88 = 0; \
    (o)->unk74 = 0;

void springVineStep3(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        RESET(o);
        o->velV = 0x200;
        break;
    case 1:
        o->unk88 += 4;
        if (o->unk88 & 0x80) {
            o->step++;
            break;
        }
        o->y.raw -= (COS_TABLE[o->unk88 & 0xff] * o->velV) >> 4;
        break;
    case 2:
        o->subState = 0;
        o->step = 0;
        RESET(o);
        break;
    }
}

#endif
