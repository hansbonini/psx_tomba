#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011b498 396 X001
// MATCHING 8011b498 396

typedef struct { short x, y, z, pad; } SV;
#define V(o) ((SV *)((char *)(o) + 0xb4))
extern void *D_8013E5BC;

void springVineRopeStep2(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->anim = D_8013E5BC;
    {
        GameObject *e = (GameObject *)o->unk90;
        short dy = e->y.p.whole - o->y.p.whole;
        short dx = e->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            V(o)[0].y = 0;
            V(o)[0].x = 0;
            V(o)[1].y = 0;
            V(o)[1].x = 0;
            V(o)[2].y = dy;
            V(o)[2].x = 0;
            V(o)[3].y = dy;
            V(o)[3].x = 0;
            V(o)[0].z = dx - o->hitOffsetX;
            V(o)[1].z = dx + o->hitWidth;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[0].y = 0;
            V(o)[0].z = 0;
            V(o)[1].y = 0;
            V(o)[1].z = 0;
            V(o)[2].y = dy;
            V(o)[2].z = 0;
            V(o)[3].y = dy;
            V(o)[3].z = 0;
            V(o)[0].x = dx - o->hitOffsetX;
            V(o)[1].x = dx + o->hitWidth;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 1:
    {
        GameObject *e = (GameObject *)o->unk90;
        short dy = e->y.p.whole - o->y.p.whole;
        short dx = e->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 2:
        break;
    }
}

#endif
