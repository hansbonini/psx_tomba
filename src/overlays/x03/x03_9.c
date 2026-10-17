#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012C330);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012C5D0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012C75C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012C868);
extern s16 func_80043D2C(GameObject *, s16, s16);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

static __inline__ s32 land_2C868(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        return 1;
    }
    return 0;
}

s32 func_8012C868(GameObject *o)
{
    switch (o->velX & 7) {
    case 1:
    case 3:
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) return 1;
        break;
    case 5:
    case 7:
        if (land_2C868(o)) return 1;
        break;
    }
    if (o->animFrame & 1) {
        if (o->x.p.whole < o->unkB6) return 1;
    } else if (o->y.p.whole < -0x46a) {
        if (o->unkB8 - 0x14 < o->x.p.whole) return 1;
    } else {
        if (o->x.p.whole > o->unkB8) return 1;
    }
    return 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012C9BC);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

s32 func_8012C9BC(GameObject *o)
{
    s16 d;

    if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1))
        return 1;
    if (o->animFrame & 1)
        d = -0xe;
    else
        d = 0xe;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, o->animFrame) == 0)
        return func_80043AB0(o, o->h->p.whole + d, o->y.p.whole - 4, o->animFrame) != 0;
    return 1;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012CA90);

extern u16 D_80135170[];
extern s32 isOnScreen(s16, s16);

static __inline__ s32 inview_2CA90(GameObject *o)
{
    if ((u16)(o->x.p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + 0x64) >= 0x209) return 0;
    return (u16)((*(u16 *)&SCRATCHPAD.unk168[7].p.whole) - o->y.p.whole + 0x80) < 0x1e1;
}

void func_8012CA90(GameObject *o)
{
    GameObject *e;

    switch (o->step) {
    case 0:
        if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 3) == 0 && inview_2CA90(o)) {
            o->timer = D_80135170[nextRandom() & 0xf];
            o->step++;
        }
        break;
    case 1:
        if (--o->timer == -1) {
            if ((o->subtype = nextRandom() & 1) == 0) {
                o->hitOffsetX = 8;
                o->hitWidth = 0x10;
                o->hitOffsetY = 8;
                o->hitHeight = 0x10;
            } else {
                o->hitOffsetX = 0xc;
                o->hitWidth = 0x1c;
                o->hitOffsetY = 0xc;
                o->hitHeight = 0x18;
            }
            o->timer = 0x1c;
            o->state++;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            o->anim = 0;
            if (isOnScreen(o->x.p.whole, o->y.p.whole)) {
                e = allocObjectLayer3();
                if (e) {
                    e->active = 2;
                    e->type = 0x43;
                    e->x.p.whole = o->x.p.whole;
                    e->y.p.whole = o->y.p.whole + 0x10;
                    e->z.p.whole = o->z.p.whole;
                }
            }
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012CC64);
extern s16 D_80135190[];
extern void *D_80139ABC;
extern s32 tickAnimation(GameObject *);
extern void updateObjectSideFlag(GameObject *);
extern void readAnimFrameCount(GameObject *);

void func_8012CC64(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (--o->timer != -1)
            return;
        o->active = 3;
        o->timer = 0x78;
        o->unkAC = 0x1c;
        o->step++;
        break;
    case 1:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (--o->timer != -1)
            return;
        o->active = 1;
        o->step = 0;
        o->subState++;
        updateObjectSideFlag(o);
        o->timer = D_80135190[nextRandom() & 0xf];
        if (o->timer == 0)
            o->unkB4 = 0;
        else
            o->unkB4 = 1;
        o->unkAC = 0x1c;
        break;
    default:
        return;
    }
    o->anim = D_80139ABC;
    readAnimFrameCount(o);
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012CDB8);
static __inline__ s16 past_2CDB8(GameObject *o)
{
    s16 c;

    if (o->animFrame & 1) c = o->x.p.whole < o->unkB6;
    else if (o->y.p.whole < -0x46a) c = o->unkB8 - 0x14 < o->x.p.whole;
    else c = o->x.p.whole > o->unkB8;
    if (c) return 1;
    return 0;
}

void func_8012CDB8(GameObject *o)
{
    GameObject *e;

    switch (o->step) {
    case 0:
        if (*(u16 *)&o->unkB4) o->step = 1;
        else o->step = 2;
        break;
    case 1:
        if (--o->timer == -1) {
            o->step = 3;
            o->active = 3;
        }
    case 2:
        if (o->animFrame) o->x.p.whole -= 2;
        else o->x.p.whole += 2;
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (func_8012C9BC(o) || past_2CDB8(o)) o->animFrame = 1 - o->animFrame;
        break;
    case 3:
        if (o->visible) {
            e = allocObjectLayer3();
            if (e) {
                e->active = 2;
                e->type = 0x43;
                e->x.p.whole = o->x.p.whole;
                e->y.p.whole = o->y.p.whole + 0x10;
                e->z.p.whole = o->z.p.whole;
            }
        }
        o->subtype = 1;
        o->timer = 0x1c;
        o->hitOffsetX = 0xc;
        o->hitWidth = 0x1c;
        o->hitOffsetY = 0xc;
        o->anim = 0;
        o->hitHeight = 0x18;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
        o->velX = o->animFrame;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_9", func_8012CFFC);
extern void *D_80139AB4[];
extern void *D_80139A50[];

void func_8012CFFC(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (--o->timer == -1) {
            o->active = 3;
            o->timer = 0x78;
            o->unkAC = 0x1a;
            o->step++;
            o->anim = D_80139AB4[0];
            readAnimFrameCount(o);
        }
        break;
    case 1:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (--o->timer == -1) {
            o->active = 1;
            o->step = 0;
            o->subState++;
            updateObjectSideFlag(o);
            o->unkAC = 1;
            o->anim = D_80139A50[0];
            readAnimFrameCount(o);
        }
        break;
    }
}
