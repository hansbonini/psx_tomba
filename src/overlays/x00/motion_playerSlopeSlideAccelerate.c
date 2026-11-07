#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 801102b4 1196 X000
// MATCHING 801102b4 1196
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
typedef struct {
    short f0, f2, f4, f6;
    char r[0x38 - 8];
    unsigned short g38, g3a, g3c, g3e, g40, g42, g44, g46, g48, g4a, g4c;
    char r2[0x74 - 0x4e];
} T74;
extern T74 PLAYER_DECEL_PARAMS[];
#define TB PLAYER_DECEL_PARAMS[u]
#define WB2(p) (*(short *)((p) + 0xb2))

/* wb2 (speed) ramp towards the table limits; l = facing left, r = right; 38/42 = table group */
static __inline__ void l38(unsigned char *p, int u)
{
    if (WB2(p) > TB.f2)
        WB2(p) -= TB.g38;
    else if (TB.f0 < WB2(p))
        WB2(p) -= TB.g3a;
    else if (WB2(p) > 0)
        WB2(p) -= TB.g3c;
    else if (WB2(p) == 0)
        WB2(p) = -TB.g3e;
    else if (-TB.f2 < WB2(p))
        WB2(p) -= TB.g40;
    else if (WB2(p) < -TB.f2)
        WB2(p) = -TB.f2;
}

static __inline__ void r42(unsigned char *p, int u)
{
    if (WB2(p) < -TB.f2)
        WB2(p) += TB.g42;
    else if (WB2(p) < -TB.f0)
        WB2(p) += TB.g44;
    else if (WB2(p) < 0)
        WB2(p) += TB.g46;
    else if (WB2(p) == 0)
        WB2(p) = TB.g48;
    else if (WB2(p) < TB.f2)
        WB2(p) += TB.g4a;
    else {
        if (WB2(p) < TB.f6)
            WB2(p) += TB.g4c;
        else
            WB2(p) = TB.f6;
    }
}

static __inline__ void l42(unsigned char *p, int u)
{
    if (TB.f2 < WB2(p))
        WB2(p) -= TB.g42;
    else if (TB.f0 < WB2(p))
        WB2(p) -= TB.g44;
    else if (WB2(p) > 0)
        WB2(p) -= TB.g46;
    else if (WB2(p) == 0)
        WB2(p) = -TB.g48;
    else if (-TB.f2 < WB2(p))
        WB2(p) -= TB.g4a;
    else {
        if (-TB.f6 < WB2(p))
            WB2(p) -= TB.g4c;
        else
            WB2(p) = -TB.f6;
    }
}

static __inline__ void r38(unsigned char *p, int u)
{
    if (WB2(p) < -TB.f2)
        WB2(p) += TB.g38;
    else if (WB2(p) < -TB.f0)
        WB2(p) += TB.g3a;
    else if (WB2(p) < 0)
        WB2(p) += TB.g3c;
    else if (WB2(p) == 0)
        WB2(p) = TB.g3e;
    else if (WB2(p) < TB.f2)
        WB2(p) += TB.g40;
    else if (TB.f2 < WB2(p))
        WB2(p) = TB.f2;
}

static __inline__ void mid(unsigned char *p, int u)
{
    switch (p[0xbe] & 1) {
    case 0:
        if (*(unsigned short *)(p + 0x2e) & 1)
            l38(p, u);
        else
            r42(p, u);
        break;
    case 1:
        if (*(unsigned short *)(p + 0x2e) & 1)
            l42(p, u);
        else
            r38(p, u);
        break;
    }
}

void playerSlopeSlideAccelerate(unsigned char *p)
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
