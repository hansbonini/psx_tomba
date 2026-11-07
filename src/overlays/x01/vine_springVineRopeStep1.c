#include "version.h"

#if REGION == REGION_EU
/* Adapted from afsenovilla/Tombi-Decomp (MIT); see LICENSES/Tombi-Decomp-MIT.txt. */
#include "common.h"
#include "game.h"
// FUNC 8011aefc 616 X001
// MATCHING 8011aefc 616

typedef struct { short x, y, z, pad; } V8011AEFC;

extern void *D_8013E5BC[];

#define a ((V8011AEFC *)&o->unkB4)
#define b ((V8011AEFC *)&o->unkBC)
#define c ((V8011AEFC *)((char *)o + 0xc4))
#define d ((V8011AEFC *)((char *)o + 0xcc))

void springVineRopeStep1(GameObject *o)
{
    GameObject *p;
    short dx, dy;
    int v;

    switch (o->step) {
    case 0:
        {GameObject *q;
        q = (GameObject *)o->unk90;
        o->step++;
        o->unkAC = 0;
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
        o->unk88 = ((GameObject *)o->unk90)->unk88;
        v = (o->unk88 >> 8) & 0xff;
        if (v < 0x60) {
            o->hitOffsetX = 3;
            o->hitWidth = 3;
        } else if (v < 0xa0) {
            o->hitOffsetX = 4;
            o->hitWidth = 3;
        } else {
            o->hitOffsetX = 4;
            o->hitWidth = 4;
        }
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
    case 3:
        p = (GameObject *)o->unk90;
        o->hitOffsetX = 4;
        o->hitWidth = 4;
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
    case 4:
        p = (GameObject *)o->unk90;
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
    case 5:
        o->unkAC = 0;
        break;
    }
    o->anim = D_8013E5BC[o->unkAC];
}

#endif
