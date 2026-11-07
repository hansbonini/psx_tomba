#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 8010fe70 1092 X000
// MATCHING 8010fe70 1092
typedef struct { short a[3]; char pad[0x24 - 6]; unsigned short g[10]; char pad2[0x74 - 0x38]; } T74;
extern T74 PLAYER_DECEL_PARAMS[];
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009c990, DAT_8009cf06, DAT_8009d006;
typedef struct { char pad[0x2e]; unsigned short animFrame; char p1[0xb2 - 0x30]; short wb2; char pad2[0xc1 - 0xb4]; unsigned char bc1; } P;

static __inline__ void decel(P *o, int u)
{
    unsigned short w = o->wb2;
    short n;
    if ((unsigned short)(w + 0x50) < 0xa1) {
        o->wb2 = 0;
        return;
    }
    n = w;
    if (n > PLAYER_DECEL_PARAMS[u].a[2])
        o->wb2 = w - PLAYER_DECEL_PARAMS[u].g[6];
    else if (PLAYER_DECEL_PARAMS[u].a[1] < n)
        o->wb2 = w - PLAYER_DECEL_PARAMS[u].g[7];
    else if (PLAYER_DECEL_PARAMS[u].a[0] < n)
        o->wb2 = w - PLAYER_DECEL_PARAMS[u].g[8];
    else if (n > 0)
        o->wb2 = w - PLAYER_DECEL_PARAMS[u].g[9];
    else if (n < -PLAYER_DECEL_PARAMS[u].a[2])
        o->wb2 = w + PLAYER_DECEL_PARAMS[u].g[6];
    else if (n < -PLAYER_DECEL_PARAMS[u].a[1])
        o->wb2 = w + PLAYER_DECEL_PARAMS[u].g[7];
    else if (n < -PLAYER_DECEL_PARAMS[u].a[0])
        o->wb2 = w + PLAYER_DECEL_PARAMS[u].g[8];
    else if (n < 0)
        o->wb2 = w + PLAYER_DECEL_PARAMS[u].g[9];
}

static __inline__ void step(P *o, int u)
{
    int v, s;
    short k = u;
    switch (o->animFrame & 3) {
    case 0:
        v = o->wb2;
        s = v;
        if (v < -PLAYER_DECEL_PARAMS[u].a[1])
            o->wb2 = o->wb2 + PLAYER_DECEL_PARAMS[u].g[0];
        else if (v < -PLAYER_DECEL_PARAMS[u].a[0])
            o->wb2 = o->wb2 + PLAYER_DECEL_PARAMS[u].g[1];
        else if (v < 0)
            o->wb2 = o->wb2 + PLAYER_DECEL_PARAMS[u].g[2];
        else if (v == 0)
            o->wb2 = PLAYER_DECEL_PARAMS[u].g[3];
        else if (v < PLAYER_DECEL_PARAMS[u].a[1])
            o->wb2 = o->wb2 + PLAYER_DECEL_PARAMS[u].g[4];
        else if (v < PLAYER_DECEL_PARAMS[u].a[2])
            o->wb2 = o->wb2 + PLAYER_DECEL_PARAMS[u].g[5];
        else
            o->wb2 = PLAYER_DECEL_PARAMS[u].a[2];
        break;
    case 1:
        v = o->wb2;
        s = v;
        if (PLAYER_DECEL_PARAMS[u].a[1] < v)
            o->wb2 = o->wb2 - PLAYER_DECEL_PARAMS[u].g[0];
        else if (PLAYER_DECEL_PARAMS[u].a[0] < v)
            o->wb2 = o->wb2 - PLAYER_DECEL_PARAMS[u].g[1];
        else if (v > 0)
            o->wb2 = o->wb2 - PLAYER_DECEL_PARAMS[u].g[2];
        else if (v == 0)
            o->wb2 = -PLAYER_DECEL_PARAMS[u].g[3];
        else if (-PLAYER_DECEL_PARAMS[u].a[1] < v)
            o->wb2 = o->wb2 - PLAYER_DECEL_PARAMS[u].g[4];
        else if (-PLAYER_DECEL_PARAMS[u].a[2] < v)
            o->wb2 = o->wb2 - PLAYER_DECEL_PARAMS[u].g[5];
        else
            o->wb2 = -PLAYER_DECEL_PARAMS[u].a[2];
        break;
    case 2:
    case 3:
        decel(o, k);
        break;
    }
}

static __inline__ void body(P *o)
{
    int b = o->bc1;
    int u = GAME_EQUIPPED_PANTS + b * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)b << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    step(o, u);
}
void playerSkidDecelerate(P *o)
{
    body(o);
}

#endif
