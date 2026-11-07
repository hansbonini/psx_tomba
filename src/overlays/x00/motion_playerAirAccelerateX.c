#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009c990, DAT_8009cf06, DAT_8009d006;
extern unsigned short MOTION_PAD_INFO;
// FUNC 8010eaf8 1532 X000
// MATCHING 8010eaf8 1532

typedef struct { short f0, f2, f4, f6, f8; short pad[5]; } T8010EAF8;

extern T8010EAF8 PLAYER_MOVE_PARAMS[];

static __inline__ int getU(GameObject *o)
{
    int b = (*(unsigned char *)((char *)o + 0xc1));
    int u = GAME_EQUIPPED_PANTS + b * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)b << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    return u;
}

static __inline__ void decel(GameObject *o, int u)
{
    unsigned short x = o->velX;
    int xs;
    int r;
    if ((unsigned short)(x + PLAYER_MOVE_PARAMS[u].f6) <= PLAYER_MOVE_PARAMS[u].f6 * 2) {
        o->velX = 0;
        return;
    }
    if (o->animFrame & 1) {
        xs = (short)x;
        if (xs < 0)
            r = xs + PLAYER_MOVE_PARAMS[(*(unsigned char *)((char *)o + 0xc1))].f6;
        else
            r = xs - PLAYER_MOVE_PARAMS[u].f8;
    } else {
        xs = (short)x;
        if (xs > 0)
            r = xs - PLAYER_MOVE_PARAMS[(*(unsigned char *)((char *)o + 0xc1))].f6;
        else
            r = xs + PLAYER_MOVE_PARAMS[u].f8;
    }
    o->velX = r;
}

void func_8010DE48(GameObject *o)
{
    short u = getU(o);
    unsigned short acc = PLAYER_MOVE_PARAMS[u].f4;
    unsigned short lim = PLAYER_MOVE_PARAMS[u].f0;
    unsigned short max = PLAYER_MOVE_PARAMS[u].f2;
    unsigned char b;

    if (MOTION_PAD_INFO == 7) {
        if (o->velY > 0) {
            switch (o->animFrame) {
            case 0:
            case 4:
                b = o->unkA6;
                if (b & 2)
                    if (!(b & 1))
                        return;
                if (o->velX >= (short)lim)
                    o->velX = o->velX - acc;
                else
                    o->velX = o->velX + acc;
                break;
            case 1:
            case 5:
                b = o->unkA6;
                if (b & 2)
                    if (b & 1)
                        return;
                if (o->velX <= -(short)lim)
                    o->velX = o->velX + acc;
                else
                    o->velX = o->velX - acc;
                break;
            default:
                decel(o, u);
                break;
            }
        } else {
            switch (o->animFrame) {
            case 0:
            case 4:
                b = o->unkA6;
                if (b & 2)
                    if (!(b & 1))
                        return;
                o->velX += acc;
                if (o->velX > (short)max)
                    o->velX = max;
                break;
            case 1:
            case 5:
                b = o->unkA6;
                if (b & 2)
                    if (b & 1)
                        return;
                o->velX -= acc;
                if (o->velX < -(short)max)
                    o->velX = -max;
                break;
            default:
                decel(o, u);
                break;
            }
        }
    } else {
        if (o->velY > 0) {
            switch (o->animFrame) {
            case 0:
            case 4:
                b = o->unkA6;
                if (b & 2)
                    if (!(b & 1))
                        return;
                if (o->velX >= (short)lim)
                    o->velX = o->velX - acc;
                else
                    o->velX = o->velX + acc;
                break;
            case 1:
            case 5:
                b = o->unkA6;
                if (b & 2)
                    if (b & 1)
                        return;
                if (o->velX <= -(short)lim)
                    o->velX = o->velX + acc;
                else
                    o->velX = o->velX - acc;
                break;
            default:
                decel(o, u);
                break;
            }
        } else {
            switch (o->animFrame) {
            case 0:
            case 4:
                b = o->unkA6;
                if (b & 2)
                    if (!(b & 1))
                        return;
                o->velX += acc;
                if (o->velX > (short)max)
                    o->velX = max;
                break;
            case 1:
            case 5:
                b = o->unkA6;
                if (b & 2)
                    if (b & 1)
                        return;
                o->velX -= acc;
                if (o->velX < -(short)max)
                    o->velX = -max;
                break;
            default:
                decel(o, u);
                break;
            }
        }
    }
}

#endif
