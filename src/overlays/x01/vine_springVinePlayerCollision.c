#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 80125044 48 X001
// MATCHING 80125044 48

extern int pushObjectOutOfObjectBoxC(GameObject *a, GameObject *b);

void springVinePlayerCollision(GameObject *a, GameObject *b)
{
    if (b->subtype == 0)
        pushObjectOutOfObjectBoxC(a, b);
}

#endif
