#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
// FUNC 8010e97c 380 X000
// MATCHING 8010e97c 380
typedef struct S { char p[0xb2]; short wb2; char q[0xc1 - 0xb4]; unsigned char bC1; } S;
void playerDecelerateIfFlag(S *o)
{
    S *p = o;
    unsigned short u;
    short v;
    if (o->bC1 & 1) {
        u = o->wb2;
        if ((unsigned short)(u + 8) < 0x11) {
            o->wb2 = 0;
        } else {
            v = u;
            if (v > 0x200) o->wb2 = u - 0x20;
            else if (v > 0x144) o->wb2 = u - 0x10;
            else if (v > 0x84) o->wb2 = u - 0xc;
            else if (v > 0) o->wb2 = u - 8;
            else if (v < -0x200) o->wb2 = u + 0x20;
            else if (v < -0x144) o->wb2 = u + 0x10;
            else if (v < -0x84) o->wb2 = u + 0xc;
            else if (v < 0) o->wb2 = u + 8;
        }
    } else {
        u = o->wb2;
        if ((unsigned short)(u + 8) < 0x11) {
            o->wb2 = 0;
        } else {
            v = u;
            if (v > 0x200) o->wb2 = u - 8;
            else if (v > 0x144) o->wb2 = u - 4;
            else if (v > 0x84) o->wb2 = u - 6;
            else if (v > 0) o->wb2 = u - 7;
            else if (v < -0x200) o->wb2 = u + 8;
            else if (v < -0x144) o->wb2 = u + 4;
            else if (v < -0x84) o->wb2 = u + 6;
            else if (v < 0) p->wb2 = u + 7;
        }
    }
}

#endif
