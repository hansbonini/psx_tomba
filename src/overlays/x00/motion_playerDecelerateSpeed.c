#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 8011116c 464 X000
// MATCHING 8011116c 464
typedef struct { short a[3]; char pad[0x6c - 6]; unsigned short b[4]; } T74;
extern T74 PLAYER_DECEL_PARAMS[];
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009c990, DAT_8009cf06, DAT_8009d006;
typedef struct { char pad[0xb2]; unsigned short wb2; char pad2[0xc1 - 0xb4]; unsigned char bc1; } P;

static __inline__ void body(P *o)
{
    short i;
    unsigned short w;
    short s;
    i = GAME_EQUIPPED_PANTS + o->bc1 * 4;
    if (DAT_8009c990 & 3)
        i = (o->bc1 << 2) | 3;
    if (DAT_8009cf06)
        i = 8;
    if (DAT_8009d006)
        i = 8;
    w = o->wb2;
    if ((unsigned short)(w + 0x50) <= 0xa0) {
        o->wb2 = 0;
        return;
    }
    s = w;
    if (s > PLAYER_DECEL_PARAMS[i].a[2])
        o->wb2 = w - PLAYER_DECEL_PARAMS[i].b[0];
    else if (s > PLAYER_DECEL_PARAMS[i].a[1])
        o->wb2 = w - PLAYER_DECEL_PARAMS[i].b[1];
    else if (s > PLAYER_DECEL_PARAMS[i].a[0])
        o->wb2 = w - PLAYER_DECEL_PARAMS[i].b[2];
    else if (s > 0)
        o->wb2 = w - PLAYER_DECEL_PARAMS[i].b[3];
    else if (s < -PLAYER_DECEL_PARAMS[i].a[2])
        o->wb2 = w + PLAYER_DECEL_PARAMS[i].b[0];
    else if (s < -PLAYER_DECEL_PARAMS[i].a[1])
        o->wb2 = w + PLAYER_DECEL_PARAMS[i].b[1];
    else if (s < -PLAYER_DECEL_PARAMS[i].a[0])
        o->wb2 = w + PLAYER_DECEL_PARAMS[i].b[2];
    else if (s < 0)
        o->wb2 = w + PLAYER_DECEL_PARAMS[i].b[3];
}

void playerDecelerateSpeed(P *o)
{
    body(o);
}

#endif
