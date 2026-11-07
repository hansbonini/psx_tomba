#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 80125ae4 164 X001
// MATCHING 80125ae4 164
extern int boxesOverlapSideB(GameObject *, GameObject *);

void springVineObjectCollision(GameObject *a, GameObject *b)
{
    int r;
    short s;

    if (b->subtype == 0) {
        r = boxesOverlapSideB(a, b);
        s = r;
        if (s >= 0) {
            b->unk9A = (short)resolveHitResultA((u8 *)a, (u8 *)b) >> 1;
            if (s == 2) b->animFrame = r * 2;
            else b->animFrame = (a->animFrame & 1) * 2;
            SPAD->unk19E = 0;
        }
    }
}

#endif
