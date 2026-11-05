#include "common.h"
#include "game.h"
#include "x14.h"

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011F7E0);


typedef struct { s32 a; s16 t; s16 b; } E8_1F7E0;
typedef struct { s16 w[8]; } B4_1F7E0;


void func_8011F7E0(GameObject *o)
{
    B4_1F7E0 *b = (B4_1F7E0 *)&o->unkB4;

    switch (o->unk7) {
    case 0:
        o->active = 2;
        D_8009C608.playerEquips = 0;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        func_8011CBD0(o, 0x14);
        o->unk7++;
        func_8011EB94();
        break;
    case 1:
        if (tickAnimation(o)) {
            func_8011CBD0(o, 0x15);
            o->unk7++;
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            func_80116778(o);
            D_8009BC98.unk28 = 0;
            func_8011CC8C(o);
            func_80115FEC(o);
            o->unk7++;
            func_8011EBCC();
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            E8_1F7E0 *e = (E8_1F7E0 *)o->child;
            o->unk7++;
            e += o->unkAE;
            o->timer = e->t;
            func_8011CBD0(o, 0x12);
        }
        break;
    case 4:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            b->w[7] = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011F97C);

s32 func_8011F97C(GameObject *o)
{
    GameObject *n = allocObjectLayer2();

    if (n) {
        n->active = 1;
        n->type = 0x43;
        n->id = o->animFrame & 1;
        n->unkB4 = o->animFrame & 1;
        n->x.p.whole = o->x.p.whole;
        n->y.p.whole = o->y.p.whole;
        n->z.p.whole = o->z.p.whole;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011FA04);
extern s16 probeCollisionAtDepthB(GameObject *, s16, s16);

static __inline__ s32 touch_1FA04(GameObject *o, GameObject *p)
{
    if ((u16)(p->h->p.whole - o->h->p.whole + (o->hitboxX + p->hitboxX)) > o->hitboxW + p->hitboxW)
        return 0;
    return !((u16)(p->y.p.whole - o->y.p.whole + (o->hitboxY + p->hitboxY)) > p->hitboxH + o->hitboxH + 0x40);
}

static __inline__ s32 out_1FA04(GameObject *o)
{
    if (o->h->p.whole < D_800A38E4 - 0xa0)
        return 1;
    if (D_800A38E6 + 0xa0 < o->h->p.whole)
        return 1;
    if (D_800A38EA + 0x78 < o->y.p.whole)
        return 1;
    return o->y.p.whole < D_800A38E8 - 0x78;
}

void func_8011FA04(GameObject *o)
{
    GameObject *p = &PLAYER;
    s16 d, v;
    s32 t;

    switch (o->state) {
    case 0:
        o->state++;
        o->hitboxX = 0x18;
        o->hitboxW = 0x30;
        o->hitboxY = 0x40;
        o->hitboxH = 0x70;
        *(s8 *)&o->priority = -0x10;
        o->velX = 0x80;
        o->drawType = 0xa;
        o->tpage = 1;
        o->drawFlags = 0x80;
        o->unk6A = 0;
        o->unkA5 = 0;
        o->unkA6 = 0;
        o->unkA7 = 0;
        o->animFrame = 0;
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
        o->spriteBank = D_1F8002DC[0];
        o->anim = D_80129344[o->id];
        readAnimFrameCount(o);
        o->timer = 20;
        if (*(u16 *)&o->unkB4)
            o->velH = -0x200;
        else
            o->velH = 0x200;
        o->velV = 0;
        o->cooldownTimer = 0;
        break;
    case 1:
        if (D_8009BC98.unk12 == 1) {
            cullAndQueueDraw(o);
            break;
        }
        cullAndQueueDraw(o);
        tickAnimation(o);
        if (o->subState != 0)
            break;
        if (o->timer == 0) {
            o->unkA5 += 2;
            if (o->unkA5 >= 0xc0)
                *(s8 *)&o->unkA5 = -0x40;
            v = o->velV + 8;
            o->velV = v;
            t = o->unkA5;
            *((u8 *)o + 0xa5) = t;
            *((u8 *)o + 0xa6) = t;
            if (v > 0x100)
                o->velV = 0x100;
            if (o->velH < 0) {
                o->velH += 8;
                if (o->velH >= -0x100)
                    o->velH = -0x100;
            } else {
                o->velH -= 8;
                if (o->velH <= 0x100)
                    o->velH = 0x100;
            }
        } else {
            o->timer--;
        }
        o->h->raw += o->velH << 8;
        o->y.raw -= o->velV << 8;
        if (probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole)) {
            o->active = 2;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
        } else {
            if (out_1FA04(o)) {
                o->active = 2;
                o->state = 3;
            }
        }
        if (o->unk6A == 0)
            break;
        p->h->raw += o->velH << 8;
        p->y.raw -= o->velV << 8;
        p->active = 6;
        if (o->id)
            p->rotZ += 0x14;
        else
            p->rotZ -= 0x14;
        p->rotZ = (u8)p->rotZ;
        if (o->h->p.whole != p->h->p.whole) {
            if (p->h->p.whole < o->h->p.whole) {
                t = (s16)(o->h->p.whole - p->h->p.whole);
                if (t >= 4)
                    d = 3;
                else
                    d = t;
            } else {
                t = (s16)(o->h->p.whole - p->h->p.whole);
                d = (t < -3) ? -3 : t;
            }
        } else
            d = 0;
        p->h->p.whole += d;
        p->y.p.whole += 6;
        if (probeCollisionAtDepthB(p, p->h->p.whole, p->y.p.whole)) {
            p->y.p.whole -= 6;
            o->state = 2;
        }
        if (touch_1FA04(o, p) && o->state == 1)
            break;
        p->active = 1;
        p->state = 1;
        p->subState = 0x3e;
        p->step = 0;
        o->active = 2;
        o->state = 2;
        o->subState = 0;
        o->step = 0;
        o->unk6A = 0;
        break;
    case 2:
        if (D_8009BC98.unk12 == 1) {
            cullAndQueueDraw(o);
            break;
        }
        cullAndQueueDraw(o);
        tickAnimation(o);
        o->velX -= 4;
        if (o->velX < 0) {
            o->velX = 0;
            o->state++;
        } else {
            func_800230BC(o, 0x50);
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8011FF98);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801200E4);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801204B4);

s32 func_801204B4(GameObject *o)
{
    GameObject *n = allocObjectLayer2();
    if (n) {
        n->active = 1;
        n->type = 0x46;
        n->id = 0;
        n->param = 0;
        n->x.p.whole = (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + 0xa0;
        n->y.p.whole = (u16)SCRATCHPAD.unk168[4].p.whole - 0xf0;
        n->z.p.whole = o->z.p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120534);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801205D8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120708);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120738);


void func_80120738(GameObject *o)
{
    s16 v;

    switch (o->subState) {
    case 0:
        o->timer = (nextRandom() & 0x30) + 0x5a;
        o->subState++;
        o->velY = D_80125900[o->id];
        if (o->param) {
            v = o->velH;
            if (v < 0) o->velH = v - 0x80;
            else o->velH = v + 0x80;
        }
        break;
    case 1:
        o->visible = 1;
        o->h->raw += o->velH << 8;
        o->velV += o->velY;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->animFrame) o->rotZ = (o->rotZ + 0x80) & 0xfff;
        else o->rotZ = (o->rotZ - 0x80) & 0xfff;
        if (o->timer < 0x28) {
            if ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1) o->visible = 1;
            else o->visible = 0;
        }
        if (--o->timer == -1) o->state++;
        break;
    }
    if (o->visible) cullAndQueueDraw(o);
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801208F4);


void func_801208F4(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (o->id == 0) {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->model = *pp + q[2];
            else o->model = *pp + q[1];
            o->modelLit = 1;
            o->hitboxX = 0x1c;
            o->hitboxW = 0x38;
            o->hitboxY = 0x1c;
            o->hitboxH = 0x38;
        } else {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->model = *pp + q[1];
            else o->model = *pp + q[0];
            o->modelLit = 1;
            o->hitboxX = 6;
            o->hitboxW = 0xc;
            o->hitboxY = 6;
            o->hitboxH = 0xc;
        }
        o->drawType = 0x11;
        o->priority = 0;
        o->param = 0;
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
        o->state++;
        break;
    case 1:
        if (D_8009BC98.unk12 == 1) {
            cullAndQueueDraw(o);
        } else if (o->id == 0) {
            cullAndQueueDraw(o);
            func_80120534(o);
        } else {
            func_80120738(o);
        }
        break;
    case 2:
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120AB0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120AC8);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120BA0);

void func_80120BA0(GameObject *o, s32 sub)
{
    s32 i;
    GameObject *e;

    for (i = 0; i < 6; i++) {
        e = allocObjectLayer2();
        if (e) {
            e->type = 0x47;
            e->active = 2;
            e->id = sub;
            e->param = i + 1;
            e->state = 2;
            e->drawType = o->drawType;
            e->tpage = o->tpage;
            e->drawFlags = o->drawFlags;
            e->spriteBank = o->spriteBank;
            e->priority = o->priority;
            e->x.raw = o->x.p.whole << 16;
            e->y.raw = o->y.p.whole << 16;
            e->z.raw = o->z.p.whole << 16;
        }
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120C90);

#define SPAWN(o, X, Y, Z) { \
    e = allocObjectLayer4(); \
    if (e) { \
        e->active = 1; \
        e->type = 0x43; \
        e->localX = X; \
        e->localY = Y; \
        e->id = 0; \
        e->localZ = Z; \
        e->h->raw = o->h->raw + e->localX; \
        e->y.raw = o->y.raw + e->localY; \
        e->d->raw = o->d->raw + e->localZ; \
        e->parent = (s32)o; \
    } }

void func_80120C90(GameObject *o, s16 n)
{
    GameObject *e;

    switch (n) {
    case 0:
        SPAWN(o, -0x350000, -0x190000, -0x5a0000);
        SPAWN(o, -0x30000, 0x440000, -0x5a0000);
        break;
    case 1:
        SPAWN(o, 0x130000, -0x2b0000, -0x5a0000);
        SPAWN(o, -0x120000, 0x2a0000, -0x5a0000);
        break;
    }
}
#undef SPAWN

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120E90);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_80120ECC);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_8012104C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_10", func_801210A4);
