#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8010f328 216 X000
// MATCHING 8010f328 216
extern unsigned char GAME_EQUIPPED_PANTS;
extern unsigned char DAT_8009c990;
extern unsigned char DAT_8009cf06;
extern unsigned char DAT_8009d006;
extern GameObject *PLAYER_EXT;
extern unsigned short PLAYER_MOVE_PARAMS_JUMP_RISE_VEL[][10];

void playerSetJumpRiseVelocity(GameObject *o)
{
    int b = ((unsigned char *)o)[0xc1];
    int u = GAME_EQUIPPED_PANTS + b * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)b << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    switch ((unsigned short)PLAYER_EXT->timer) {
    case 0 ... 12:
        o->velY = PLAYER_MOVE_PARAMS_JUMP_RISE_VEL[u][2];
        break;
    case 13:
        o->velY = PLAYER_MOVE_PARAMS_JUMP_RISE_VEL[u][1];
        break;
    }
}

#endif
