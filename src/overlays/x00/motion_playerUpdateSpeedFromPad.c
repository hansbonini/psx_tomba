#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 8010f400 2672 X000
// MATCHING 8010f400 2672
// FLAGS -O2 -G0 -fno-cse-skip-blocks
/* -fno-cse-skip-blocks (debt): with it gcc recomputes u*0x74 in every arm like the game (18 index computations);
   without it CSE follows the path past chkr's skipped then-block and reuses one product (660). */
typedef struct {
    short f0, f2, f4, f6;
    unsigned short g8, ga, gc, ge, g10, g12;
    unsigned short g14, g16, g18, g1a;
    unsigned short g1c, g1e, g20, g22;
    char r[0x74 - 0x24];
} T74;
extern T74 PLAYER_DECEL_PARAMS[];
extern unsigned char GAME_EQUIPPED_PANTS, DAT_8009cf06, DAT_8009d006;
extern unsigned char DAT_8009c990;
extern unsigned short PAD_INFO;
extern unsigned char DAT_8009d618;
typedef struct {
    char p0[0x2e]; unsigned short animFrame;
    char p30[0xa6 - 0x30]; unsigned char ba6;
    char pa7[0xb2 - 0xa7]; short wb2;
    char pb4[0xbc - 0xb4]; short wbc;
    char pbe; unsigned char bbf;
    char pc0; unsigned char bc1;
} P;
#define T PLAYER_DECEL_PARAMS[u]
static __inline__ T74 *TB(short u) { return &PLAYER_DECEL_PARAMS[u]; }

static __inline__ void chkr(P *o, short u)
{
    if (o->wb2 >= T.f2) {
        o->bbf = 2;
        o->wbc = o->wb2;
    }
}
static __inline__ void chkl(P *o, short u)
{
    if (o->wb2 <= -T.f2) {
        o->bbf = 3;
        o->wbc = o->wb2;
    }
}
static __inline__ void setr(P *o, short u, short b)
{
    short w;
    switch (b) {
    case 1:
        if (o->wb2 < 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = TB(u)->ge;
        else o->wb2 = TB(u)->f0;
        break;
    case 2:
        if (o->wb2 < 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = TB(u)->ge;
        else o->wb2 = TB(u)->f2;
        break;
    case 3:
        if (o->wb2 < 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = TB(u)->ge;
        else o->wb2 = TB(u)->f4;
        break;
    }
    return;
zero:
    o->wb2 = 0;
}

static __inline__ void setl(P *o, short u, short b)
{
    short w;
    switch (b) {
    case 1:
        if (o->wb2 > 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = -TB(u)->ge;
        else o->wb2 = -TB(u)->f0;
        break;
    case 2:
        if (o->wb2 > 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = -TB(u)->ge;
        else o->wb2 = -TB(u)->f2;
        break;
    case 3:
        if (o->wb2 > 0 && (o->ba6 & 2)) goto zero;
        if (o->wb2 == 0) o->wb2 = -TB(u)->ge;
        else o->wb2 = -TB(u)->f4;
        break;
    }
    return;
zero:
    o->wb2 = 0;
}

static __inline__ void accr(P *o, short u)
{
    int s;
    if (o->wb2 < 0 && (o->ba6 & 2))
        o->wb2 = 0;
    s = o->wb2;
    if (s < -T.f2) o->wb2 = o->wb2 + T.g8;
    else if (s < -T.f0) o->wb2 = o->wb2 + T.ga;
    else if (s < 0) o->wb2 = o->wb2 + T.gc;
    else if (s == 0) o->wb2 = T.ge;
    else if (s < T.f2) o->wb2 = o->wb2 + T.g10;
    else if (s < T.f4) o->wb2 = o->wb2 + T.g12;
    else o->wb2 = T.f4;
}

static __inline__ void accl(P *o, short u)
{
    int s;
    if (o->wb2 > 0 && (o->ba6 & 2))
        o->wb2 = 0;
    s = o->wb2;
    if (T.f2 < s) o->wb2 = o->wb2 - T.g8;
    else if (T.f0 < s) o->wb2 = o->wb2 - T.ga;
    else if (s > 0) o->wb2 = o->wb2 - T.gc;
    else if (s == 0) o->wb2 = -T.ge;
    else if (-T.f2 < s) o->wb2 = o->wb2 - T.g10;
    else if (-T.f4 < s) o->wb2 = o->wb2 - T.g12;
    else o->wb2 = -T.f4;
}

static __inline__ void dec(P *o, short u, int g)
{
    unsigned short s;
    short n;
    s = o->wb2;
    if ((unsigned short)(s + 0x50) < 0xa1) {
        o->wb2 = 0;
        return;
    }
    n = s;
    if (n > T.f4) o->wb2 = s - *(unsigned short *)((char *)&T + g + 0);
    else if (T.f2 < n) o->wb2 = s - *(unsigned short *)((char *)&T + g + 2);
    else if (T.f0 < n) o->wb2 = s - *(unsigned short *)((char *)&T + g + 4);
    else if (n > 0) o->wb2 = s - *(unsigned short *)((char *)&T + g + 6);
    else if (n < -T.f4) o->wb2 = s + *(unsigned short *)((char *)&T + g + 0);
    else if (n < -T.f2) o->wb2 = s + *(unsigned short *)((char *)&T + g + 2);
    else if (n < -T.f0) o->wb2 = s + *(unsigned short *)((char *)&T + g + 4);
    else if (n < 0) o->wb2 = s + *(unsigned short *)((char *)&T + g + 6);
}

static __inline__ void mid(P *o, short u)
{
    if (PAD_INFO == 7) {
        unsigned char b = DAT_8009d618;
        switch (o->animFrame) {
        case 0: case 4: case 8:
            chkr(o, u);
            setr(o, u, b);
            break;
        case 1: case 5: case 9:
            chkl(o, u);
            setl(o, u, b);
            break;
        case 2: case 3: case 6: case 7: case 10: case 11:
            o->wb2 = 0;
            break;
        }
    } else {
        switch (o->animFrame) {
        case 0: case 4: case 8:
            accr(o, u);
            break;
        case 1: case 5: case 9:
            accl(o, u);
            break;
        case 2: case 3: case 6: case 7: case 10: case 11:
            if (o->ba6 & 2)
                dec(o, u, 0x14);
            else
                dec(o, u, 0x1c);
            break;
        }
    }
}

void playerUpdateSpeedFromPad(P *o)
{
    int u;
    int c;
    c = o->bc1;
    u = GAME_EQUIPPED_PANTS + c * 4;
    if ((DAT_8009c990 & 3) != 0)
        u = (unsigned char)c << 2 | 3;
    if (DAT_8009cf06 != 0)
        u = 8;
    if (DAT_8009d006 != 0)
        u = 8;
    mid(o, u);
}

#endif
