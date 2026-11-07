#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009c990, DAT_8009cf06, DAT_8009d006;
// FUNC 8010e918 100 X000
// MATCHING 8010e918 100
typedef struct { char p[0xc1]; unsigned char c1; } O;
int playerGetSpeedTableIndex(O *o)
{
    int b = o->c1;
    int u = GAME_EQUIPPED_PANTS + b * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)b << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    return u;
}

#endif
