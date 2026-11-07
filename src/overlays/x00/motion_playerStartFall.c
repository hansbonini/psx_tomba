#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8010e628 68 X000
// MATCHING 8010e628 68

void playerStartFall(GameObject *o)
{
    int v;
    o->unk84 = 0;
    v = 0x10;
    if (o->animFrame & 1) v = 0xf0;
    o->unk88 = v;
    *(unsigned char *)&o->unkAC = 1;
    o->unk9C = 2;
    o->timer = 10;
    o->subState = 2;
    o->step = 3;
}

#endif
