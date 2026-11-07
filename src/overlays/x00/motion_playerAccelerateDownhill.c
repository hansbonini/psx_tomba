#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 80110eec 240 X000
// MATCHING 80110eec 240

static __inline__ void inc(GameObject *o, short w)
{
    if (w < -0x144) o->unkB2 = w + 0x20;
    else if (w < -0x84) o->unkB2 = w + 0x22;
    else if (w < 0) o->unkB2 = w + 0x26;
    else if (w == 0) o->unkB2 = 0x88;
    else if (w < 0x144) o->unkB2 = w + 0x10;
    else if (w < 0x500) o->unkB2 = w + 0x20;
    else o->unkB2 = 0x500;
}

static __inline__ void dec(GameObject *o, short w)
{
    if (w >= 0x145) o->unkB2 = w - 0x20;
    else if (w >= 0x85) o->unkB2 = w - 0x22;
    else if (w > 0) o->unkB2 = w - 0x26;
    else if (w == 0) o->unkB2 = -0x88;
    else if (w >= -0x143) o->unkB2 = w - 0x10;
    else if (w >= -0x4ff) o->unkB2 = w - 0x20;
    else o->unkB2 = -0x500;
}

void playerAccelerateDownhill(GameObject *o)
{
    switch (o->unkBE & 1) {
    case 0:
        inc(o, o->unkB2);
        break;
    case 1:
        dec(o, o->unkB2);
        break;
    }
}

#endif
