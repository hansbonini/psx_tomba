#ifndef GAME_OBJINIT_H
#define GAME_OBJINIT_H

#include "common.h"
#include "game.h"

static __inline__ void initObjectAC(GameObject *o)
{
    D_8009B6A0 = (ObjectAC *)&o->unkAC;
    if (o->step == 0) {
#if REGION == REGION_EU && VERSION == 0
        o->unkB0 = 0;
        o->unkB4 = 0x20;
#else
        ObjectAC *g;
        int v;

        if (GetGraphType() != 1) {
            GetGraphType();
        }
        g = D_8009B6A0;
        o->unkB0 = 0;
        if (GetGraphType() == 1 || GetGraphType() == 2) {
            v = 0x80;
        } else {
            v = 0x20;
        }
        g->tpage2 = v;
#endif
        D_8009B6A0->clut = GetClut(0x80, 0x1EF);
        D_8009B6A0->clut2 = GetClut(0x80, 0x1F0);
        D_8009C968.w0 = 0xF;
        D_8009C968.w2 = 8;
        D_8009C968.w4 = 0x5A;
        *(s8 *)&o->unkF = -9;
        o->unkA = 0;
        o->h->p.whole = D_800A53D8[1];
        o->y.p.whole = D_800A53AE[0] - 0x10;
        o->d->p.whole = D_800A53DC[1];
        o->velH = 0;
        o->velV = 0;
        o->animFrame = 0;
        o->visible = 1;
        o->step = 0;
    }
}

#endif
