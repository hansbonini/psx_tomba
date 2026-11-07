#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 80110760 1356 X000
// MATCHING 80110760 1356
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
extern unsigned char PLAYER_DECEL_PARAMS_BYTES[];
typedef struct { short f0, f2, f4, f6; char r[0x74 - 8]; } T74;
extern T74 PLAYER_DECEL_PARAMS[];
#define TS(i, o) (*(short *)(PLAYER_DECEL_PARAMS_BYTES + (i) + (o)))
#define WB2(p) (*(short *)((p) + 0xb2))

static __inline__ void dec(unsigned char *p, short u, int g)
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

static __inline__ void acc(unsigned char *p, short u)
{
    short s;
    int i;
    i = u * 0x74;
    s = WB2(p);
    if (TS(i, 4) < s)
        WB2(p) = s + TS(i, 0x5e);
    else if (TS(i, 2) < s)
        WB2(p) = s + TS(i, 0x60);
    else if (TS(i, 0) < s)
        WB2(p) = s + TS(i, 0x62);
    else if (s > 0)
        WB2(p) = s + TS(i, 0x64);
    else if (s < -TS(i, 4))
        WB2(p) = s - TS(i, 0x5e);
    else if (s < -TS(i, 2))
        WB2(p) = s - TS(i, 0x60);
    else if (s < -TS(i, 0))
        WB2(p) = s - TS(i, 0x62);
    else if (s < 0)
        WB2(p) = s - TS(i, 0x64);
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
    int m;
    m = 0;
    if (p[0xbe] != 0) {
        m = 1;
        if ((*(unsigned short *)(p + 0x2e) & 1) == (p[0xbe] & 1))
            m = 2;
    }
    switch (m) {
    case 0:
        dec(p, u, 0x4e);
        break;
    case 1:
        dec(p, u, 0x56);
        break;
    case 2:
        acc(p, u);
        break;
    }
    clamp(p, u);
}

void playerDecelerateSpeedB(unsigned char *p)
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
