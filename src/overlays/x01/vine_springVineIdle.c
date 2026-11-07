#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011a5dc 336 X001
// MATCHING 8011a5dc 336
typedef struct { short x, y, z, pad; } SV;
typedef struct { char p[0xb4]; SV v[4]; } TX;

extern void *D_8013E5BC;

void springVineIdle(GameObject *o)
{
    GameObject *p;
    short dx, dy;
    SV *v;

    if (o->step != 0) return;
    o->y.raw = o->unk34;
    o->h->raw = o->unk30;
    o->velH = 0;
    o->velV = 0;
    o->velX = 0;
    o->velY = 0;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk74 = 0;
    if (o->subtype) {
        o->anim = D_8013E5BC;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        v = ((TX *)o)->v;
        if (SPAD->unk1C8 & 1) {
            v[0].y = 0;
            v[0].x = 0;
            v[1].y = 0;
            v[1].x = 0;
            v[2].y = dy;
            v[2].x = 0;
            v[3].y = dy;
            v[3].x = 0;
            v[0].z = dx - o->hitOffsetX;
            v[1].z = dx + o->hitWidth;
            v[2].z = dx - o->hitOffsetX;
            v[3].z = dx + o->hitWidth;
        } else {
            v[0].y = 0;
            v[0].z = 0;
            v[1].y = 0;
            v[1].z = 0;
            v[2].y = dy;
            v[2].z = 0;
            v[3].y = dy;
            v[3].z = 0;
            v[0].x = dx - o->hitOffsetX;
            v[1].x = dx + o->hitWidth;
            v[2].x = dx - o->hitOffsetX;
            v[3].x = dx + o->hitWidth;
        }
    }
    o->step++;
}

#endif
