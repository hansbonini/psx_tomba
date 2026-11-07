#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011badc 400 X001
// MATCHING 8011badc 400

typedef struct {
    char p[0xb4];
    short b4, b6, b8, ba, bc, be, c0, c2, c4, c6, c8, ca, cc, ce, d0;
} E;

extern void *D_8013E5BC;

void springVineRopeStep4(GameObject *o)
{

    switch (o->step) {
    case 0: {
        GameObject *p;
        short dy, dx;
        o->step++;
        *(short *)((char *)o + 0xac) = 0;
        o->anim = D_8013E5BC;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            ((E *)o)->b6 = 0;
            ((E *)o)->b4 = 0;
            ((E *)o)->be = 0;
            ((E *)o)->bc = 0;
            ((E *)o)->c6 = dy;
            ((E *)o)->c4 = 0;
            ((E *)o)->ce = dy;
            ((E *)o)->cc = 0;
            ((E *)o)->b8 = dx - o->hitOffsetX;
            ((E *)o)->c0 = dx + o->hitWidth;
            ((E *)o)->c8 = dx - o->hitOffsetX;
            ((E *)o)->d0 = dx + o->hitWidth;
        } else {
            ((E *)o)->b6 = 0;
            ((E *)o)->b8 = 0;
            ((E *)o)->be = 0;
            ((E *)o)->c0 = 0;
            ((E *)o)->c6 = dy;
            ((E *)o)->c8 = 0;
            ((E *)o)->ce = dy;
            ((E *)o)->d0 = 0;
            ((E *)o)->b4 = dx - o->hitOffsetX;
            ((E *)o)->bc = dx + o->hitWidth;
            ((E *)o)->c4 = dx - o->hitOffsetX;
            ((E *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 1: {
        GameObject *p;
        short dy, dx;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            ((E *)o)->c6 = dy;
            ((E *)o)->ce = dy;
            ((E *)o)->c8 = dx - o->hitOffsetX;
            ((E *)o)->d0 = dx + o->hitWidth;
        } else {
            ((E *)o)->c6 = dy;
            ((E *)o)->ce = dy;
            ((E *)o)->c4 = dx - o->hitOffsetX;
            ((E *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 2:
        break;
    }
}

#endif
