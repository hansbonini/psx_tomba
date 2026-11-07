#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 80110fdc 400 X000
// MATCHING 80110fdc 400
// VERSION SLPM_80165 x00 8010C0C4 328
#if defined(VERSION_SLPM_80165)
// Demo version of PAL x000 80110FDC (func_80110FDC.c): 3 speed sets per level (PAL 4), no special cases.
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
extern unsigned char PLAYER_DECEL_PARAMS[];
#define TS(i, o) (*(short *)(PLAYER_DECEL_PARAMS + (i) + (o)))

void func_80110FDC(unsigned char *p)
{
    unsigned u;
    unsigned short s;
    int i, n, c;
    unsigned char *q = p;
    c = p[0xc1];
    u = GAME_EQUIPPED_PANTS + c * 3;
    s = *(unsigned short *)(p + 0xb2);
    if ((unsigned short)(s + 0x50) < 0xa1) {
        *(short *)(p + 0xb2) = 0;
        return;
    }
    i = u * 0x74;
    n = (short)s;
    if (TS(i, 2) < n)
        *(short *)(p + 0xb2) = s - TS(i, 0x66);
    else if (TS(i, 0) < n)
        *(short *)(p + 0xb2) = s - TS(i, 0x68);
    else if (n > 0)
        *(short *)(p + 0xb2) = s - TS(i, 0x6a);
    else if (n < -TS(i, 2))
        *(short *)(p + 0xb2) = s + TS(i, 0x66);
    else if (n < -TS(i, 0))
        *(short *)(p + 0xb2) = s + TS(i, 0x68);
    else if (n < 0)
        *(short *)(q + 0xb2) = s + TS(i, 0x6a);
}
#else
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
extern unsigned char PLAYER_DECEL_PARAMS[];
#define TS(i, o) (*(short *)(PLAYER_DECEL_PARAMS + (i) + (o)))

void playerAttackDecelerate(unsigned char *p)
{
    unsigned u;
    unsigned short s;
    int i, n, c;
    unsigned char *q = p;
    c = p[0xc1];
    u = GAME_EQUIPPED_PANTS + c * 4; if ((DAT_8009c990 & 3) != 0) u = (unsigned char)c << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    s = *(unsigned short *)(p + 0xb2);
    if ((unsigned short)(s + 0x50) < 0xa1) {
        *(short *)(p + 0xb2) = 0;
        return;
    }
    i = u * 0x74;
    n = (short)s;
    if (TS(i, 2) < n)
        *(short *)(p + 0xb2) = s - TS(i, 0x66);
    else if (TS(i, 0) < n)
        *(short *)(p + 0xb2) = s - TS(i, 0x68);
    else if (n > 0)
        *(short *)(p + 0xb2) = s - TS(i, 0x6a);
    else if (n < -TS(i, 2))
        *(short *)(p + 0xb2) = s + TS(i, 0x66);
    else if (n < -TS(i, 0))
        *(short *)(p + 0xb2) = s + TS(i, 0x68);
    else if (n < 0)
        *(short *)(q + 0xb2) = s + TS(i, 0x6a);
}
#endif

#endif
