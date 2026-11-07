#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8010e5e4 68 X000
// MATCHING 8010e5e4 68
// VERSION SLPS_01144 x00 8010E0B0 68
#if defined(VERSION_SLPS_01144)
// Japanese version of PAL x000 8010E5E4 (playerAccelerateUpCapped.c): -16 -> -80.
void playerAccelerateUpCapped(GameObject *o)
{
    o->velY -= 0x50;
    if (o->velY < -0x800) {
        o->velY = -0x800;
    }
    if (((unsigned char *)o)[0xcc] == 3) {
        o->step = 2;
    }
}
#else
void playerAccelerateUpCapped(GameObject *o)
{
    o->velY -= 0x10;
    if (o->velY < -0x800) {
        o->velY = -0x800;
    }
    if (((unsigned char *)o)[0xcc] == 3) {
        o->step = 2;
    }
}
#endif

#endif
