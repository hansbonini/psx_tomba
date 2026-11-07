#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 801191e4 132 X001
// MATCHING 801191e4 132

extern GameObject *ObjAlloc(void);

void spawnSpringVineLeafBurst(int x, int y, int z)
{
    GameObject *e = ObjAlloc();
    if (e) {
        e->active = 1;
        e->type = 0x1f;
        e->subtype = 0;
        e->h->raw = x << 16;
        e->y.raw = y << 16;
        e->d->raw = z << 16;
        e->timer = 0xc;
    }
}

#endif
