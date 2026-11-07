#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 80110cac 576 X000
// MATCHING 80110cac 576
// probably: player speed friction: index from GAME_EQUIPPED_PANTS / flags, steps wb2 toward 0 by the D_80115510 table rows and clamps to f6; unreferenced
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
extern unsigned char PLAYER_DECEL_PARAMS_BYTES[];
typedef struct { short f0, f2, f4, f6; char r[0x74 - 8]; } T74;
extern T74 PLAYER_DECEL_PARAMS[];
#define TS(i, o) (*(short *)(PLAYER_DECEL_PARAMS_BYTES + (i) + (o)))
#define WB2(p) (*(short *)((p) + 0xb2))

static __inline__ void dec(unsigned char *p, int u, int g)
{
    unsigned short s;
    int i, n;
    s = WB2(p);
    if ((unsigned short)(s + 0x50) < 0xa1) {
        WB2(p) = 0;
        return;
    }
    i = u * 0x74;
    n = (short)s;
    if (TS(i, 4) < n)
        WB2(p) = s - TS(i, g);
    else if (TS(i, 2) < n)
        WB2(p) = s - TS(i, g + 2);
    else if (TS(i, 0) < n)
        WB2(p) = s - TS(i, g + 4);
    else if (n > 0)
        WB2(p) = s - TS(i, g + 6);
    else if (n < -TS(i, 4))
        WB2(p) = s + TS(i, g);
    else if (n < -TS(i, 2))
        WB2(p) = s + TS(i, g + 2);
    else if (n < -TS(i, 0))
        WB2(p) = s + TS(i, g + 4);
    else if (n < 0)
        WB2(p) = s + TS(i, g + 6);
}

static __inline__ void clamp(unsigned char *p, short u)
{
    if (WB2(p) < -PLAYER_DECEL_PARAMS[u].f6)
        WB2(p) = -PLAYER_DECEL_PARAMS[u].f6;
    if (PLAYER_DECEL_PARAMS[u].f6 < WB2(p))
        WB2(p) = PLAYER_DECEL_PARAMS[u].f6;
}

static __inline__ void mid(unsigned char *p, short u)
{
    dec(p, u, 0x56);
    clamp(p, u);
}

void func_80110CAC(unsigned char *p)
{
    int u;
    int c;
    c = p[0xc1];
    u = GAME_EQUIPPED_PANTS + c * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)c << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    mid(p, u);
}

#endif
