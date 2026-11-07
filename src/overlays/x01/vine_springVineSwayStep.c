#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011a72c 304 X001
// MATCHING 8011a72c 304
extern short NEG_SIN_TABLE[];

int springVineSwayStep(GameObject *o)
{
    o->h->raw = o->unk30 + ((NEG_SIN_TABLE[((unsigned char *)&o->unk84)[1]] * *(signed char *)&o->unkA6) << 4);
    o->unk84 += o->velH;
    o->velH += o->velX;
    if (o->velH == o->unk74) {
        if (--o->timer == -1) {
            o->unk74 = 0;
            o->velH = 0;
            o->velX = 0;
            o->unk84 = 0;
            return 1;
        }
        o->velX *= -1;
        o->velH /= 2;
        o->unk74 /= 2;
        o->velX /= 2;
    } else if (o->velH == -o->unk74) {
        o->velX *= -1;
    }
    return 0;
}

#endif
