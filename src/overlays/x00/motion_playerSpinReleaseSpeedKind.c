#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 8010f254 212 X000
// MATCHING 8010f254 212
typedef struct T { short lim; unsigned short inc; char pad[16]; } T;
typedef struct O {
    char p0[0x7e]; short w7e;
    char p1[0xb2 - 0x80]; short wb2;
    char p2[0xc1 - 0xb4]; unsigned char bc1;
} O;
typedef struct G { char p0[0x20]; unsigned short w20; } G;
extern G *PLAYER_EXT;
extern T PLAYER_MOVE_PARAMS_GRAVITY[];

void playerSpinReleaseSpeedKind(O *o)
{
    short a; short k;
    a = o->wb2 < 0 ? -o->wb2 : o->wb2;
    k = 0;
    switch (PLAYER_EXT->w20) {
    case 0 ... 12:
        o->w7e += PLAYER_MOVE_PARAMS_GRAVITY[k].inc;
        break;
    default:
        o->w7e += PLAYER_MOVE_PARAMS_GRAVITY[k].inc - (a >> 7) - 8;
        break;
    }
    if (PLAYER_MOVE_PARAMS_GRAVITY[k].lim < o->w7e)
        o->w7e = PLAYER_MOVE_PARAMS_GRAVITY[k].lim;
    if (o->w7e < -PLAYER_MOVE_PARAMS_GRAVITY[k].lim)
        o->w7e = -PLAYER_MOVE_PARAMS_GRAVITY[k].lim;
}

#endif
