#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011b74c 524 X001
// MATCHING 8011b74c 524

typedef struct { short x, y, z, pad; } V8011B74C;

extern char D_8013E7D8[];
extern char D_8013E7E0[];
extern char D_8013E7F0[];
extern char D_8013E7E8[];
static void *D_8013E5BC[4] = {
    D_8013E7D8, D_8013E7E0, D_8013E7F0, D_8013E7E8,
};

void springVineRopeStep3(GameObject *o)
{
    V8011B74C *a = (V8011B74C *)&o->unkB4;
    V8011B74C *b = (V8011B74C *)&o->unkBC;
    V8011B74C *c = (V8011B74C *)((char *)o + 0xc4);
    V8011B74C *d = (V8011B74C *)((char *)o + 0xcc);
    GameObject *p;
    short dx, dy;

    switch (o->step) {
    case 0:
        {GameObject *q;
        q = (GameObject *)o->unk90;
        o->unkAC = 3;
        o->step++;
        dy = q->y.p.whole - o->y.p.whole;
        dx = q->h->p.whole - o->h->p.whole;}
        if (SPAD->unk1C8 & 1) {
            a->y = 0;
            a->x = 0;
            b->y = 0;
            b->x = 0;
            c->y = dy;
            c->x = 0;
            d->y = dy;
            d->x = 0;
            a->z = dx - o->hitOffsetX;
            b->z = dx + o->hitWidth;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            a->y = 0;
            a->z = 0;
            b->y = 0;
            b->z = 0;
            c->y = dy;
            c->z = 0;
            d->y = dy;
            d->z = 0;
            a->x = dx - o->hitOffsetX;
            b->x = dx + o->hitWidth;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 1:
        p = (GameObject *)o->unk90;
        o->unkAC = 3;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 2:
        p = (GameObject *)o->unk90;
        o->unkAC = 0;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SPAD->unk1C8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    }
    o->anim = D_8013E5BC[o->unkAC];
}

#endif
