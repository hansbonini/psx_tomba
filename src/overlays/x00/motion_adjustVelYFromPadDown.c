#include "version.h"

/* Other regions retain their existing assembly implementations. */
#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 801113bc 160 X000
// MATCHING 801113bc 160
extern unsigned short PAD_INFO;
extern unsigned char DAT_8009d619;
extern unsigned short MOTION_PAD_PRESSED;

void func_8011070C(GameObject *o)
{
    short v;
    v = 0x20;
    if (PAD_INFO == 7) { v = 0x20; v = v >> (3 - DAT_8009d619); }
    if (*(volatile unsigned short *)&MOTION_PAD_PRESSED & 0x40) o->velY = o->velY + v;
    else o->velY = o->velY - v;
    if (o->velY > 0x300) o->velY = 0x300;
    if (o->velY < 0xc0) o->velY = 0xc0;
}

#endif
