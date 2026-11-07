#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011b164 820 X001
// MATCHING 8011b164 820

extern short NEG_SIN_TABLE[];
extern short COS_TABLE[];
extern void FUN_8001e4f0(int);

void springVineStep2(GameObject *o)
{
    int s;
    int c;
    int b;
    short v;

    switch (o->step) {
    case 0:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        if (o->unk9A != 0) {
            if ((o->animFrame >> 1) & 1) {
                o->unk74 = 0x300;
                o->velH = 0x300;
                o->velX = -0x18;
            } else {
                o->unk74 = -0x300;
                o->velH = -0x300;
                o->velX = 0x18;
            }
            o->timer = 3;
        } else {
            if ((o->animFrame >> 1) & 1) {
                o->unk74 = 0x200;
                o->velH = 0x200;
                o->velX = -0x10;
            } else {
                o->unk74 = -0x200;
                o->velH = -0x200;
                o->velX = 0x10;
            }
            o->timer = 2;
        }
        o->unkA6 = 0x40;
        o->unk68 = 0;
        o->step++;
        break;
    case 1:
        o->h->raw = o->unk30 + ((NEG_SIN_TABLE[((unsigned char *)&o->unk84)[1]] * (signed char)o->unkA6) << 4);
        b = (signed char)o->unkA6;
        c = COS_TABLE[((unsigned char *)&o->unk84)[1]] * b;
        o->unk84 += o->velH;
        v = o->velH + o->velX;
        o->velH = v;
        o->y.raw = o->unk34 - (b << 16) + (c << 4);
        if (v == o->unk74) {
            if (--o->timer == -1) {
                o->step++;
                break;
            }
            o->velX *= -1;
            o->velH = o->velH / 2;
            o->unk74 = o->unk74 / 2;
            o->velX = o->velX / 2;
        } else if (v == -o->unk74) {
            o->velX *= -1;
        }
        if (o->unk6A != 0) {
            o->subState = 1;
            o->step = 1;
            o->velV = 0x340;
            o->unk88 = 0;
            o->unkA6 = 0x20;
            o->objectIndex = 0;
            FUN_8001e4f0(GAME_U16Arr[1] == 0 ? 0x42 : 0x47);
        }
        if (o->unk68 != 0) {
            o->step = 0;
        }
        break;
    case 2:
        o->subState = 0;
        o->step = 0;
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        break;
    }
}

#endif
