#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012B424);

typedef struct { s16 w0; u16 w2; s16 w4; u16 w6; } AH_2B424;
typedef struct {
    s16 a;
    s16 b;
    s16 wb8;
} Sub_2B424;

extern AH_2B424 *D_8013CE68[];
extern AH_2B424 *D_8013CE6C[];
extern u8 D_8013BB38[];
extern u16 D_8013BC20[];
extern s16 fixedMulCos(s16, s32);
extern s16 fixedMulSin(s16, s32);
extern s16 probeCollisionAtDepthA(GameObject *o, s16 x, s16 y);
extern void func_800EA16C(s16, s32, s32, s32);
extern void playSFX(s32);
extern void func_8012AE50(GameObject *o);

static __inline__ s32 land2_2B424(GameObject *o)
{
    s16 t;
    s16 w;

    if (o->touchFlag == 1) {
        o->unk8C = 0;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkAE = -1;
        o->unk9C = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        t = SCRATCHPAD.unk27E;
        if (t < 0) t = -t;
        if (t >= 9) t = 8;
        if (SCRATCHPAD.unk27E < 0) t = -t;
        o->unk8C = -t & 0xff;
        o->unkB2 = t;
        w = SCRATCHPAD.unk284;
        o->unkB6 = (-t << 2) & 0xff;
        o->unk9C = 0;
        o->unkAE = w;
        return 1;
    }
    return 0;
}

#define CHK \
    if (o->h->p.whole >= 0x943) { \
        o->active = 2; \
        o->state = 3; \
        if (o->visible) { \
            func_800EA16C(o->h->p.whole + 10, 0x2e, o->d->p.whole, 1); \
            func_800EA16C(o->h->p.whole - 10, 0x2e, o->d->p.whole, 1); \
        } \
    }

#define MOVE { \
    c = fixedMulCos(s->b, 0x250); \
    d = fixedMulSin(s->b, 0x250); \
    if (o->animFrame) o->h->raw -= c << 8; \
    else o->h->raw += c << 8; \
    o->y.raw += d << 8; \
    o->velV += 0x40; \
    o->y.raw += o->velV << 8; \
}

void func_8012B424(GameObject *o)
{
    Sub_2B424 *s = (Sub_2B424 *)&o->unkB4;
    u8 *p0, *p1;
    s16 c, d;

    switch (o->unk7) {
    case 0:
        o->movetab = D_80077250;
        o->unk9C = 1;
        o->velV = -0x300;
        o->unk9D = 0;
        o->unkAC = 2;
        o->unk7++;
        o->anim = D_8013CE68[0];
        p0 = &D_8013BB38[((AH_2B424 *)o->anim)->w2 * 4];
        o->hitOffsetX = *p0++;
        o->hitWidth = *p0++;
        o->hitOffsetY = *p0++;
        o->hitHeight = *p0;
        o->animTimer = ((AH_2B424 *)o->anim)->w6 & 0x3fff;
        CHK
    case 1:
        func_8012AE50(o);
        MOVE
        if (o->velV > 0) {
            o->unk9C = 2;
            o->touchFlag = 0;
            o->unk7++;
        }
        CHK
        break;
    case 2:
        MOVE
        if (land2_2B424(o)) {
            o->velV = 0;
            o->unk8C = (u16)s->b;
            if (o->visible) {
                if (o->animFrame) s->wb8 = -0x10;
                else s->wb8 = 0x10;
                func_800EA16C(o->x.p.whole + s->wb8, o->y.p.whole, o->z.p.whole, 1);
                playSFX(0x3f);
            }
            o->timer = 0xf;
            o->velH = 0x250;
            o->unk7++;
            break;
        }
        CHK
        break;
    case 3:
        applyFrameVelocityY(o);
        if (land2_2B424(o)) {
            if (--o->timer == -1) {
                if (o->visible) {
                    if (o->animFrame) s->wb8 = -0x10;
                    else s->wb8 = 0x10;
                    func_800EA16C(o->x.p.whole + s->wb8, o->y.p.whole, o->z.p.whole, 1);
                    playSFX(0x3f);
                }
                o->timer = 0xf;
            }
            o->unk8C = (u16)s->b;
            if (o->animFrame) c = D_8013BC20[-o->unkB2];
            else c = D_8013BC20[o->unkB2];
            o->velH += c;
            if (o->velH > 0x300) o->velH = 0x300;
        }
        if (o->animFrame) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        if (o->velH < 0x150) {
            func_8012AE50(o);
            if (o->velH < 0) {
                o->velH = 0;
                o->unk7++;
            }
        }
        CHK
        break;
    case 4:
        o->timer = 100;
        o->unkAC = 3;
        o->unk7++;
        o->anim = D_8013CE6C[0];
        p1 = &D_8013BB38[((AH_2B424 *)o->anim)->w2 * 4];
        o->hitOffsetX = *p1++;
        o->hitWidth = *p1++;
        o->hitOffsetY = *p1++;
        o->hitHeight = *p1;
        o->animTimer = ((AH_2B424 *)o->anim)->w6 & 0x3fff;
    case 5:
        func_8012AE50(o);
        if (--o->timer == -1) {
            if (o->unkC == 0) {
                if (o->animFrame) {
                    if (o->unkB2 <= 0) goto z;
                } else {
                    if (o->unkB2 >= 0) goto z;
                }
                o->step = 9;
                o->unk7 = 2;
                break;
            }
            o->step = 9;
        z:
            o->unk7 = 0;
        }
        break;
    }
}
#undef CHK
#undef MOVE

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012BC24);
typedef struct A_2BC24 { s16 w0; u16 w2; u16 w4; u16 w6; } A_2BC24;
typedef struct B_2BC24 { u8 c[4]; } B_2BC24;
extern A_2BC24 *D_8013CE60[];

#define SETANIM(k) \
    o->anim = D_8013CE60[k]; \
    { u8 *p; { B_2BC24 *t = D_8013BB38; p = t[((A_2BC24 *)o->anim)->w2].c; } \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; } \
    o->animTimer = ((A_2BC24 *)o->anim)->w6 & 0x3fff;

void func_8012BC24(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->timer = 0x5a;
        o->unk9D = 0;
        o->unkAC = 1;
        o->unk7++;
        SETANIM(1);
        break;
    case 1:
        if (--o->timer == 0) o->unk7++;
        func_8012AE50(o);
        break;
    case 2:
        o->step = 8;
        o->unk7 = 0;
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012BD40);
typedef struct A_2BD40 { s16 w0; u16 w2; u16 w4; u16 w6; } A_2BD40;
typedef struct B_2BD40 { u8 c[4]; } B_2BD40;
extern void applyAnimVelocityX(GameObject *, u16);

#define SETANIM(k) \
    o->anim = D_8013CE60[k]; \
    { u8 *p; { B_2BD40 *t = D_8013BB38; p = t[((A_2BD40 *)o->anim)->w2].c; } \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; } \
    o->animTimer = ((A_2BD40 *)o->anim)->w6 & 0x3fff;

void func_8012BD40(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unkB = 1;
        o->unkF = 4;
        o->active = 2;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 9;
        o->step++;
        SETANIM(9);
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1)
        o->unk8C = (o->unk8C + 0x14) & 0xff;
    else
        o->unk8C = (o->unk8C - 0x14) & 0xff;
}
#undef SETANIM

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012BEB0);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012C75C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012C7E4);
typedef struct A_2C7E4 { s16 w0; u16 w2; u16 w4; u16 w6; } A_2C7E4;
typedef struct B_2C7E4 { u8 c[4]; } B_2C7E4;
extern u8 D_800A5444[];
extern void spawnItemNotification(s32, s32);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

static __inline__ s32 land_2C7E4(GameObject *o)
{
    s16 t;
    s16 w;

    if (o->touchFlag == 1) {
        o->unk8C = 0;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkAE = -1;
        o->unk9C = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        t = D_1F80027E;
        if (t < 0) t = -t;
        if (t >= 9) t = 8;
        if (D_1F80027E < 0) t = -t;
        o->unk8C = -t & 0xff;
        o->unkB2 = t;
        w = D_1F800284;
        o->unkB6 = (-t << 2) & 0xff;
        o->unk9C = 0;
        o->unkAE = w;
        return 1;
    }
    return 0;
}

#define SETANIM(k) \
    o->anim = D_8013CE60[k]; \
    { u8 *p; { B_2C7E4 *t = D_8013BB38; p = t[((A_2C7E4 *)o->anim)->w2].c; } \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; } \
    o->animTimer = ((A_2C7E4 *)o->anim)->w6 & 0x3fff;

#define COMMON() \
    applyFrameVelocityY(o); \
    func_80043AB0(o, o->h->p.whole + 0x10, o->y.p.whole + 8, 0); \
    func_80043AB0(o, o->h->p.whole - 0x10, o->y.p.whole + 8, 1); \
    land_2C7E4(o);

void func_8012C7E4(GameObject *o)
{
    s16 *e = &o->unkB4;
    GameObject *n;
    s16 v;
    s32 d;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        spawnItemNotification(0, 6);
        o->movetab = D_80077214;
        *(s8 *)&o->unkF = -7;
        o->unk68 = 0;
        o->unk8C = 0;
        o->velV = 0;
        o->step++;
    case 1:
        o->velV += 0x40;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        func_80043AB0(o, o->h->p.whole + 0x10, o->y.p.whole + 8, 0);
        func_80043AB0(o, o->h->p.whole - 0x10, o->y.p.whole + 8, 1);
        if (land_2C7E4(o)) o->velV = 0;
        break;
    case 2:
        PLAYER.obj.step = 2;
        o->timer = 4;
        o->unkAC = 6;
        o->step++;
        SETANIM(6);
        COMMON();
        break;
    case 3:
        if (--o->timer == -1) {
            o->timer = 8;
            o->unkAC = 7;
            o->step++;
            SETANIM(7);
            n = allocObjectLayer3();
            if (n) {
                n->active = 1;
                n->type = 0x10;
                n->subtype = 0;
                d = -0x10;
                if (o->animFrame & 1) d = 0x10;
                n->x.p.whole = o->x.p.whole + d;
                n->y.p.whole = o->y.p.whole;
                n->z.p.whole = o->z.p.whole;
                n->animFrame = o->animFrame & 1;
            }
        }
        COMMON();
        break;
    case 4:
        if (--o->timer == -1) {
            o->unkAC = 8;
            SETANIM(8);
            o->step++;
            o->timer = 0xe;
        }
        COMMON();
        break;
    case 5:
        applyFrameVelocityX(o);
        o->y.p.whole += 3;
        func_80043AB0(o, o->h->p.whole + 0x10, o->y.p.whole + 8, 0);
        func_80043AB0(o, o->h->p.whole - 0x10, o->y.p.whole + 8, 1);
        if (land_2C7E4(o)) {
            v = D_1F80027E;
            if (v < 0) v = -v;
            if (v > 8) v = 8;
            if (D_1F80027E < 0) v = -v;
            o->unkB2 = v;
            o->unk8C = -v & 0xff;
            o->unkB6 = (-v << 2) & 0xff;
            o->unkAE = D_1F800284;
            o->unk9C = 0;
            if (o->animFrame) {
                if (o->unkB2 < 0) {
                    o->velH = 0x200;
                    o->subState = 3;
                    o->step = 1;
                    e[8] = 1;
                    break;
                }
            } else if (o->unkB2 >= 2) {
                o->velH = 0x200;
                o->subState = 3;
                o->step = 1;
                e[8] = 0;
                break;
            }
        }
        if (--o->timer == -1) {
            D_800A5444[0] = 3;
            o->unkAC = 6;
            SETANIM(6);
            o->step++;
        }
        break;
    case 6:
        o->unkAC = 6;
        SETANIM(6);
        COMMON();
        break;
    case 7:
        o->unkAC = 9;
        SETANIM(9);
        o->step++;
        break;
    case 8:
        break;
    }
}
#undef SETANIM
#undef COMMON

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012D2D0);

typedef struct { s16 w0; u16 w2; s16 w4; u16 w6; } AH_2D2D0;
typedef struct {
    u8 a0, a1;
    u16 b;
    s16 wb8;
} Sub_2D2D0;

extern AH_2D2D0 *D_8013CE88[];
extern AH_2D2D0 *D_8013CE70[];
extern AH_2D2D0 *D_8013CE74[];
extern AH_2D2D0 *D_8013CE8C[];
extern AH_2D2D0 *D_8013CE90[];
extern AH_2D2D0 *D_8013CE94[];

#define SETANIM(A) { u8 *pv; \
    o->anim = (A)[0]; \
    pv = &D_8013BB38[((AH_2D2D0 *)o->anim)->w2 * 4]; \
    o->hitOffsetX = *pv++; \
    o->hitWidth = *pv++; \
    o->hitOffsetY = *pv++; \
    o->hitHeight = *pv; \
    o->animTimer = ((AH_2D2D0 *)o->anim)->w6 & 0x3fff; }

static __inline__ s32 land2_2D2D0(GameObject *o)
{
    s16 t;
    s16 w;

    if (o->touchFlag == 1) {
        o->unk8C = 0;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkAE = -1;
        o->unk9C = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        t = SCRATCHPAD.unk27E;
        if (t < 0) t = -t;
        if (t >= 9) t = 8;
        if (SCRATCHPAD.unk27E < 0) t = -t;
        o->unk8C = -t & 0xff;
        o->unkB2 = t;
        w = SCRATCHPAD.unk284;
        o->unkB6 = (-t << 2) & 0xff;
        o->unk9C = 0;
        o->unkAE = w;
        return 1;
    }
    return 0;
}

static __inline__ void blk_2D2D0(GameObject *o)
{
    Sub_2D2D0 *s = (Sub_2D2D0 *)&o->unkB4;
    if (o->movetab) applyAnimVelocityX(o, 1 - o->animFrame);
    if ((o->unk9D & 2) && o->animFrame != (o->unk9D & 1)) o->movetab = 0;
    if (o->animFrame == 1) s->wb8 = 0x10;
    else s->wb8 = -0x10;
    if (func_80043AB0(o, o->h->p.whole + s->wb8, o->y.p.whole, 1 - o->animFrame)) o->movetab = 0;
}

void func_8012D2D0(GameObject *o)
{
    Sub_2D2D0 *t = (Sub_2D2D0 *)&o->unkB4;
    u8 c;

    switch (o->step) {
    case 0:
        o->unk9D = 0;
        playSFX(0xf);
        o->velV = -0x400;
        o->touchFlag = 0;
        o->unk8C = 0;
        o->animFrame = 1 - o->unk7A;
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 10;
        o->step++;
        SETANIM(D_8013CE88);
    case 1:
        blk_2D2D0(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->touchFlag = 0;
            o->step++;
        }
        break;
    case 2:
        blk_2D2D0(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (!land2_2D2D0(o)) break;
        if (o->movetab == 0) {
            o->unk8C = t->b;
            o->step = 4;
            o->timer = 0x168;
            o->unkAC = 5;
            SETANIM(D_8013CE74);
            cloneItemPickupObject(o);
            break;
        }
        o->active = 3;
        o->velV = -0x280;
        o->unk8C = 0;
        o->movetab = D_80077214;
        o->step++;
        t->a1 = 1;
        o->touchFlag = 0;
        o->unkAC = 4;
        SETANIM(D_8013CE70);
        break;
    case 3:
        if (o->animFrame) o->unk8C = (u8)(o->unk8C - 0x14);
        else o->unk8C = (u8)(o->unk8C + 0x14);
        blk_2D2D0(o);
        o->velV += 0x30;
        o->y.raw += o->velV << 8;
        if (o->velV <= 0) break;
        if (!land2_2D2D0(o)) break;
        if (o->movetab == 0) {
            o->unk8C = t->b;
            o->step = 4;
            o->timer = 0x168;
            o->unkAC = 5;
            SETANIM(D_8013CE74);
            cloneItemPickupObject(o);
            break;
        }
        c = t->a1--;
        if (c) {
            o->movetab = ((char *)&D_800771FC);
            o->velV = ~(o->velV - 0x80) + 1;
            break;
        }
        o->unk8C = t->b;
        o->timer = 0x168;
        o->unkAC = 5;
        o->step++;
        SETANIM(D_8013CE74);
        cloneItemPickupObject(o);
        break;
    case 4:
        if (--o->timer == -1) {
            o->unkAC = 0xb;
            o->step++;
            SETANIM(D_8013CE8C);
        }
        o->y.p.whole += 2;
        land2_2D2D0(o);
        break;
    case 5:
        if (((s32 (*)(GameObject *))func_8012AE50)(o)) {
            o->timer = 0x78;
            o->unkAC = 0xc;
            o->step++;
            SETANIM(D_8013CE90);
        }
        o->y.p.whole += 2;
        land2_2D2D0(o);
        break;
    case 6:
        ((s32 (*)(GameObject *))func_8012AE50)(o);
        if (--o->timer == -1) {
            o->timer = 0x3c;
            o->unkAC = 0xd;
            o->step++;
            SETANIM(D_8013CE94);
        }
        o->y.p.whole += 2;
        land2_2D2D0(o);
        break;
    case 7:
        ((s32 (*)(GameObject *))func_8012AE50)(o);
        if (--o->timer == -1) {
            *(s8 *)&o->unkF = -9;
            o->active = 1;
            o->state = 1;
            o->subState = 3;
            o->step = 0;
            o->unk7 = 0;
            o->touchFlag = 0;
            o->unk68 = 0;
        }
        o->y.p.whole += 2;
        land2_2D2D0(o);
        break;
    }
}
#undef SETANIM

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012DE20);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012E0A4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012E2FC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012E780);

typedef struct { u16 b0, b1, b2, b3, w1e, wac; s32 idx; void **anims; } E20_2E780;
typedef struct { Fix16 a, y, b; } FV_2E780;
extern E20_2E780 D_8013BC60[];
extern char D_8013BC82[];
extern void readAnimFrameCount(GameObject *);
extern s32 rcos(s32);
extern s32 rsin(s32);
extern void applyItemEffect(char *, FV_2E780 *, s32, s32, s32);

void func_8012E780(GameObject *o)
{
    GameObject *p;
    FV_2E780 v;
    s32 a, s, t;

    switch (o->state) {
    case 0:
        o->state++;
        o->objectIndex = o->animFrame;
        o->animFrame = 0;
        o->unkD = 0;
        o->hitOffsetX = D_8013BC60[o->subtype].b0;
        o->hitWidth = D_8013BC60[o->subtype].b1;
        o->hitOffsetY = D_8013BC60[o->subtype].b2;
        o->hitHeight = D_8013BC60[o->subtype].b3;
        o->tpage = D_8013BC60[o->subtype].w1e;
        o->spriteBank = SPR_DATA[D_8013BC60[o->subtype].idx];
        o->unkAC = D_8013BC60[o->subtype].wac;
        o->anim = D_8013BC60[o->subtype].anims[o->unkAC];
        readAnimFrameCount(o);
        if (o->unk94)
            o->active = 3;
        else
            o->active = 1;
        o->unkA = 2;
        o->unk68 = 0;
        o->unk8C = 0;
        if (o->unk90) {
            p = (GameObject *)o->unk90;
            while (p->unk90)
                p = (GameObject *)p->unk90;
            *(GameObject **)&o->unkA8 = p;
            o->velX = o->h->p.whole - p->h->p.whole;
            o->velY = o->y.p.whole - p->y.p.whole;
        } else {
            *(GameObject **)&o->unkA8 = 0;
        }
        break;
    case 1:
        if (D_8009BC98.unk12) {
            func_80022E44(o);
            break;
        }
        if (func_80022E44(o) == 0) break;
        o->unkF = PLAYER.obj.unkF + 1;
        p = *(GameObject **)&o->unkA8;
        if (p == 0) break;
        if (o->unk68) {
            p->unk68 = 1;
            o->unk68 = 0;
        }
        a = (p->unk8C + 0x400) & 0xfff;
        s = (rcos(a) * o->velY) >> 12;
        t = rsin(a) * o->velY;
        o->h->p.whole = s + (p->h->p.whole + o->velX);
        o->y.p.whole = p->y.p.whole + (t >> 12);
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            p = (GameObject *)o->unk90;
            p->active = 1;
            p->unk94 = 0;
            o->subState = 1;
            o->step = 0;
            if (o->subtype == 0)
                spawnItemNotification(0, 6);
            break;
        case 1:
            if (o->step == 1) {
                o->step++;
                if (o->objectIndex) {
                    v.a.p.whole = o->h->p.whole;
                    v.y.p.whole = o->y.p.whole;
                    v.b.p.whole = o->d->p.whole;
                    applyItemEffect(D_8013BC82 + o->objectIndex * 6, &v, 0, 0, 1);
                }
            }
            break;
        case 2:
            switch (o->step) {
            case 0:
                o->velV = -0x400;
                o->movetab = ((char *)&D_8007722C);
                o->animFrame &= 1;
                o->step++;
                break;
            case 1:
                applyAnimVelocityX(o, (u16)(1 - o->animFrame));
                o->velV += 0x40;
                if (o->velV > 0x400)
                    o->velV = 0x400;
                o->y.raw += o->velV << 8;
                break;
            }
            if (o->animFrame & 1)
                o->unk8C = (o->unk8C + 0x14) & 0xff;
            else
                o->unk8C = (o->unk8C - 0x14) & 0xff;
            if (!o->visible)
                o->state = 3;
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012ECA0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012ECC0);



extern s16 D_800A3914[];
extern void func_8002367C(s32);
extern void playSFXWithPitchSlide(s32, s32, s32, s32);
extern void freeObjectByLayer(GameObject *);

void func_8012ECC0(GameObject *o)
{
    u8 t = o->state;

    switch (t) {
    case 0:
        o->state = t + 1;
        o->hitOffsetX = 0x20;
        o->hitWidth = 0x40;
        o->hitOffsetY = 0x18;
        o->hitHeight = 0x38;
        o->touchFlag = 0;
        o->unkB4 = o->objectIndex;
        o->objectIndex = 0;
        o->unk84 = 0;
        o->unk88 = -0x400;
        o->unk8C = 0;
        break;
    case 1:
        if (!func_80022E44(o)) break;
        switch (o->subState) {
        case 0:
            o->y.p.whole += 4;
            if (probeCollisionAtDepthA(o, o->h->p.whole + 0x20, o->y.p.whole + 0x18)) {
                o->unk8C = (-SCRATCHPAD.unk27E << 6) & 0xfc0;
                o->subState++;
            }
            break;
        case 1:
            if (o->unk6A) {
                if (o->unk6A & 1) o->h->p.whole--;
                else o->h->p.whole++;
            }
            o->y.p.whole += 2;
            func_80043AB0(o, o->h->p.whole + 0x20, o->y.p.whole, 0);
            if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x18)) o->unk8C = (-SCRATCHPAD.unk27E << 6) & 0xfc0;
            if (o->h->p.whole >= 0x2d0) break;
            func_8002367C(*(u16 *)&o->unkB4);
            o->type = 0xc;
            o->category = 2;
            ((u8*)&D_8009BC98.unk0F)[0] = 1;
            ((u8*)&D_8009BC98.unk0E)[0] = 1;
            ((u8*)&D_8009BC98.unk12)[0] = 1;
            D_8009C068.unk54e = 1;
            D_800A38BB[0] = 5;
            D_800A38D0[0] = 0;
            D_800A3914[0] = 0;
            D_1F800190 = o->y.raw;
            D_1F80018C = o->h->raw;
            o->timer = 0x20;
            o->velH = 0;
            o->subState++;
            break;
        case 2:
            o->velH += 0x10;
            if (o->velH >= 0x300) o->velH = 0x300;
            o->h->raw -= o->velH << 8;
            o->y.p.whole += 3;
            if (!probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x18)) {
                o->touchFlag = 0;
                o->velV = 0;
                o->subState++;
                break;
            }
            o->unk8C = (-SCRATCHPAD.unk27E << 6) & 0xfc0;
            break;
        case 3:
            if (o->unk8C == 0x200) o->subState++;
            o->unk8C += 0x20;
            o->h->p.whole--;
            break;
        case 4:
            if (o->timer) {
                o->h->p.whole--;
                if (--o->timer == 0) playSFXWithPitchSlide(0xd, 1, -8, 0xb4);
            }
            o->unk8C += 0x10;
            if (o->unk8C >= 0x1000) o->unk8C = 0x1000;
            o->velV += 0x10;
            if (o->velV > 0x400) o->velV = 0x400;
            o->y.raw += o->velV << 8;
            func_80043AB0(o, o->h->p.whole + 0x20, o->y.p.whole, 0);
            if (o->touchFlag || probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x18)) {
                playSFXWithNote(5, 0);
                o->subState++;
                D_8009C068.unk54e = 2;
            }
            D_1F800190 = o->y.raw;
            D_1F80018C = o->h->raw;
            break;
        case 5:
            if (D_8009C068.unk54e == 3) o->subState++;
            o->y.p.whole += 4;
            probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x1e);
            break;
        case 6:
            o->y.p.whole += 4;
            probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x1e);
            if (D_8009C068.unk54e == 4) o->state++;
            break;
        }
        break;
    case 2:
        o->state = t + 1;
        break;
    case 3:
        freeObjectByLayer(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012F284);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012F400);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012F44C);
extern void *D_8013DAC4[];
extern void readAnimFrameCount(GameObject *o);
extern s16 probeCollisionAtDepthA(GameObject *o, s16 x, s16 y);

void func_8012F44C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = D_8013DAC4[0];
        readAnimFrameCount(o);
        o->velX = -0x200;
        o->velY = -0x300;
        o->active = 2;
        o->step++;
    case 1:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x30;
        if (o->velY > 0) o->step++;
        break;
    case 2:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x30;
        if (o->touchFlag || probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + o->hitHeight - o->hitOffsetY)) {
            o->velY = -0x300;
            o->step = 1;
        }
        break;
    }
    if (!o->visible) o->state = 3;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012F5D0);

extern void *D_8013DAB8[];

static __inline__ s32 land_2F5D0(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->unk84 = (-SCRATCHPAD.unk27E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_8012F5D0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->y.p.whole += 4;
        land_2F5D0(o);
        o->step++;
        o->unk8C = 0;
        o->unkB0 = 0;
        o->unkAC = 0;
        o->anim = D_8013DAB8[0];
        readAnimFrameCount(o);
    case 1:
        o->y.p.whole += 4;
        land_2F5D0(o);
        if (o->visible) o->step++;
        break;
    case 2:
        if (o->h->p.whole < SCRATCHPAD.unk168[0].p.whole) {
            o->step = 0;
            o->animFrame = 0;
            o->subState++;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_5", func_8012F758);
extern s32 tickAnimation(GameObject *);

static __inline__ s32 ground_2F758(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 16)) {
        o->unk84 = -SCRATCHPAD.unk27E * 4 & 0xff;
        return 1;
    }
    return 0;
}

void func_8012F758(GameObject *o)
{
    s16 *w = &o->unkB4;
    s32 d;

    switch (o->step) {
    case 0:
        o->active = 1;
        o->movetab = D_8007725C;
        o->unkAC = 3;
        o->anim = D_8013DAC4[0];
        readAnimFrameCount(o);
        o->unkB6 = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        applyFrameVelocityXY(o);
        d = (o->animFrame & 1) ? -16 : 16;
        if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, o->animFrame)) {
            w[1] = 0;
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 0;
            break;
        }
        if (!ground_2F758(o)) {
            w[1] = 0;
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 1;
        }
        o->unk8C = o->unk84;
        break;
    }
    if (o->y.p.whole < -0x602 && o->h->p.whole < 0x543) {
        o->subState = 5;
        o->step = 0;
    }
}

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_5", func_801155A8);
