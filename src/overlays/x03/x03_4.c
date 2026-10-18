#include "common.h"
#include "game.h"
#include "x03.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80125048);

extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);
extern s16 isObjectPastReferenceX(GameObject *);
extern s32 func_80124A44(GameObject *, s16);

#define SET() \
    { u8 *p; \
    o->anim = D_801388B4[o->unkAC]; \
    p = &D_80135000[o->unkAC * 4]; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p++; \
    o->hitHeight = *p++; \
    readAnimFrameCount(o); }

#define SLOPE(o, Y) \
    if (o->touchFlag == 1) { \
        o->touchFlag = 0; \
    } else if (probeCollisionAtDepthA(o, o->h->p.whole, Y)) { \
        if (o->unkAC >= 0xc) { \
            o->unk8C = 0; \
        } else { \
            u32 v = (((*(u16*)&SCRATCHPAD.unk27E) << 2) + o->unk8C) & 0xff; \
            if (v != 0) { \
                if (v < 0x80) o->unk8C = o->unk8C - 1; \
                else o->unk8C = o->unk8C + 1; \
                o->unk8C = *(u8 *)&o->unk8C; \
            } \
        } \
    }

static __inline__ s16 near_25048(GameObject *o)
{
    s16 lim = 0xc0;
    u16 a;
    a = (u16)((*(u16*)((char*)&SCRATCHPAD.unk168[2].raw + 2)) - o->d->p.whole + 0x2d);
    if ((u32)a >= 0x5b) return 0;
    a = (u16)((*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) - o->h->p.whole + 0x60);
    if (a > lim) return 0;
    return (u16)((*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole + 0x40) <= lim - 0x40;
}

void func_80125048(GameObject *o)
{
    s16 *w = &o->unkB4;
    s32 t;

    switch (o->unk7) {
    case 0:
        if (isObjectPastReferenceX(o) != o->animFrame) {
            o->unk7 = 3;
            if (*w) {
                o->movetab = D_80077244;
                o->unkAC = 0xf;
            } else {
                o->unkAC = 0x1e;
                o->movetab = D_80077208;
            }
            goto set;
        } else {
            o->unk7++;
        }
        break;
    case 1:
        o->unk7++;
        if (*w) {
            t = D_801350A4[nextRandom() & 7];
            o->movetab = D_80077244;
            o->unkAC = 8;
        } else {
            t = D_8013509C[nextRandom() & 7];
            o->unkAC = 1;
            o->movetab = D_80077208;
        }
    t1:
        o->timer = t;
        goto set;
    case 2:
        if (--o->timer == -1) {
            if (near_25048(o) && (nextRandom() & 1)) {
                o->step++;
                o->unk7 = 0;
                break;
            }
            o->unk7 = 5;
            if (*w) {
                t = D_8013509C[nextRandom() & 7];
                o->unkAC = 7;
                o->movetab = D_80077244;
                goto t1;
            } else {
                t = D_8013507C[nextRandom() & 7];
                o->unkAC = 0;
                o->movetab = D_80077208;
                goto t1;
            }
        }
        applyFrameVelocityXY(o);
        tickAnimation(o);
        SLOPE(o, (s16)(o->y.p.whole + 0xe));
        if (func_80124A44(o, o->animFrame)) {
            o->unk7++;
            if (*w) o->unkAC = 0xf;
            else o->unkAC = 0x1e;
            goto set;
        }
        if (!o->visible) goto off;
        break;
    case 3:
        if (tickAnimation(o)) {
            o->cooldownTimer = 0x1e;
            o->animFrame = 1 - o->animFrame;
            o->unk7++;
            if (*w) o->unkAC = 8;
            else o->unkAC = 0;
            goto set;
        }
        break;
    case 4:
        if (--o->cooldownTimer == -1) {
            if (*w) {
                o->unkAC = 8;
                o->timer = D_801350A4[nextRandom() & 7];
            } else {
                o->unkAC = 1;
                o->timer = D_8013509C[nextRandom() & 7];
            }
            o->unk7 = 2;
        }
        break;
    case 5:
        {
            s16 yy = o->y.p.whole;
            o->y.p.whole = yy + 1;
            SLOPE(o, (s16)(yy + 0xf));
        }
        if (o->visible) {
            if (--o->timer == -1) {
                if ((nextRandom() & 1) != o->animFrame) {
                    o->unk7 = 3;
                    if (*w) o->unkAC = 0xf;
                    else o->unkAC = 0x1e;
                set:
                    SET();
                } else {
                    o->unk7 = 1;
                }
            }
        } else {
        off:
            if (*w == 0 || (u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + 0x70) >= 0x220 ||
                (u16)((*(u16 *)&SCRATCHPAD.unk168[7].p.whole) - o->y.p.whole + 0x70) >= 0x1c0) {
                o->step = 0;
                o->unk7 = 0;
            }
        }
        break;
    }
}
#undef SET
#undef SLOPE

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012567C);

static __inline__ void set_2567C(GameObject *o)
{
    u8 *p;
    o->anim = D_801388B4[o->unkAC];
    p = &D_80135000[o->unkAC * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    readAnimFrameCount(o);
}

#define SET() set_2567C(o)

static __inline__ void go3_2567C(GameObject *o, s16 w, s16 n)
{
    u8 t = o->unk7;
    t++;
    o->unk7 = t;
    o->cooldownTimer = w;
    o->unkAC = n;
    set_2567C(o);
}

static __inline__ void slope_2567C(GameObject *o)
{
    u32 v;

    if (o->touchFlag == 1) {
        o->touchFlag = 0;
    } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0xe))) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            v = (((*(u16*)&SCRATCHPAD.unk27E) << 2) + o->unk8C) & 0xff;
            if (v != 0) {
                if (v < 0x80) o->unk8C = o->unk8C - 1;
                else o->unk8C = o->unk8C + 1;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
    }
}

static __inline__ s32 near_2567C(GameObject *o)
{
    u16 t;
    s16 lim = 0x40;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[2].raw + 2)) - o->d->p.whole + 0x2d;
    if (t >= 0x5b) return 0;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) - o->h->p.whole + 0x20;
    if (t > lim) return 0;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole + 0xa0;
    return t <= lim + 0xa0;
}

void func_8012567C(GameObject *o)
{
    s16 *w = &o->unkB4;

    switch (o->unk7) {
    case 0:
        o->unk7++;
        o->timer = D_801350A4[nextRandom() & 7];
        if (*w != 0) o->unkAC = 7;
        else o->unkAC = 0x1e;
        SET();
        break;
    case 1:
        o->y.p.whole++;
        slope_2567C(o);
        if (--o->timer == -1)
            o->unk7++;
        break;
    case 2:
        if (*w != 0) {
            w[1] = 1;
            o->unk7 = 7;
            o->unkAC = 0xd;
            o->unk8C = 0;
        } else {
            o->unkAC = 0x1b;
            o->unk7++;
        }
        SET();
        break;
    case 3:
        if (tickAnimation(o)) {
            o->movetab = D_80077214;
            o->timer = D_8013509C[nextRandom() & 7];
            if (isObjectPastReferenceX(o) != o->animFrame) {
                o->cooldownTimer = 0x1e;
                o->unk7 = 5;
                o->unkAC = 0x1d;
            } else {
                o->unkAC = 3;
                o->unk7++;
            }
            SET();
        }
        break;
    case 4:
        if (--o->timer != -1) {
        applyFrameVelocityXY(o);
        tickAnimation(o);
        slope_2567C(o);
        if (func_80124A44(o, o->animFrame)) {
            go3_2567C(o, 0x3c, 0x1d);
        } else if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x3f) == 0 && isObjectPastReferenceX(o) != o->animFrame) {
            go3_2567C(o, 0x1e, 0x1d);
        }
        } else {
            o->step = 1;
            o->unk7 = 2;
        }
        break;
    case 5:
        if (tickAnimation(o)) {
            o->unk7++;
            o->animFrame = 1 - o->animFrame;
            o->unkAC = 3;
            SET();
        }
        break;
    case 6:
        tickAnimation(o);
        if (--o->cooldownTimer == -1)
            o->unk7 = 4;
        break;
    case 7:
        if (tickAnimation(o)) {
            o->timer = D_8013507C[nextRandom() & 7];
            w[1] = 1;
            o->movetab = ((char *)&D_800771FC);
            o->unkAC = 0xc;
            SET();
            if (isObjectPastReferenceX(o) != o->animFrame) {
                o->unk7 = 9;
                o->cooldownTimer = 0x14;
            } else {
                o->unk7++;
            }
        }
        break;
    case 8:
        if (near_2567C(o)) {
            o->unk7 = 0;
            o->step++;
            break;
        }
        if (--o->timer == 0) {
            o->unk7 = 10;
            w[1] = 0;
            o->unkAC = 0xe;
            SET();
            break;
        }
        applyFrameVelocityXY(o);
        tickAnimation(o);
        slope_2567C(o);
        if (func_80124A44(o, o->animFrame)) {
            o->cooldownTimer = 0x3c;
            o->unk7++;
        } else if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x3f) == 0 && isObjectPastReferenceX(o) != o->animFrame) {
            o->cooldownTimer = 0x1e;
            o->unk7++;
        }
        break;
    case 9:
        tickAnimation(o);
        if (--o->cooldownTimer == -1) {
            o->unk7--;
            o->animFrame = 1 - o->animFrame;
        }
        break;
    case 10:
        if (tickAnimation(o)) {
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    }
}
#undef SET

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80125EB8);
typedef struct B_25EB8 { u8 c[4]; } B_25EB8;

void func_80125EB8(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->unk8C = 0;
        updateObjectSideFlag(o);
        o->timer = D_8013507C[nextRandom() & 7];
        o->unk7++;
        o->unkAC = D_801350AB[o->unkB6];
        o->anim = D_801388B4[o->unkAC];
        { u8 *p = ((B_25EB8 *)&D_80135000)[o->unkAC].c;
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1]; }
        readAnimFrameCount(o);
        break;
    case 1:
        updateObjectSideFlag(o);
        tickAnimation(o);
        if (--o->timer == -1 || o->unkB6 == 5) {
            o->unk7++;
            o->unkAC = D_801350B3[o->unkB6];
            o->unkB6 = 0;
            o->anim = D_801388B4[o->unkAC];
            { u8 *p = ((B_25EB8 *)&D_80135000)[o->unkAC].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1]; }
            readAnimFrameCount(o);
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126068);

void func_80126068(GameObject *o)
{
    u8 *p;

    switch (o->step) {
    case 0:
        o->step++;
        o->unkAC = 0x1e;
        o->anim = D_8013892C;
        p = D_80135000 + (o->unkAC << 2);
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        readAnimFrameCount(o);
        break;
    case 1:
        o->y.p.whole -= 4;
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10) != 0) {
            o->unk8C = (-SCRATCHPAD.unk27E * 4 + 0x80) & 0xff;
            o->step++;
        }
        break;
    case 2:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126174);

void func_80126174(GameObject *o)
{
    u8 *p;

    switch (o->step) {
    case 0:
        o->movetab = ((char *)&D_800771FC);
        o->unkAC = 0x1e;
        o->step++;
        o->anim = D_8013892C;
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        readAnimFrameCount(o);
    case 1:
        applyFrameVelocityY(o);
        if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe) != 0) {
            o->unk8C = (-SCRATCHPAD.unk27E * 4) & 0xff;
            o->step = 0;
            o->subState++;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126288);

extern s16 func_80043AB0(GameObject *, s16, s16, s16);

#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126288);
#else
void func_80126288(GameObject *o)
{
    u8 *b;
    s32 v;

    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->movetab = D_8007725C;
        o->unkAC = 4;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->step++;
        o->anim = D_801388C4;
        b = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *b++;
        o->hitWidth = *b++;
        o->hitOffsetY = *b++;
        o->hitHeight = *b++;
        readAnimFrameCount(o);
    case 1:
        if (o->visible && ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        applyFrameVelocityX(o);
        if (o->animFrame & 1)
            v = -0x18;
        else
            v = 0x18;
        if (func_80043AB0(o, o->h->p.whole + v, o->y.p.whole, o->animFrame)
            || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)
            || (u16)(v = (u16)SCRATCHPAD.unk168[0].p.whole - (u16)o->h->p.whole + 0x40) < 0x80) {
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        if (o->visible && ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        o->y.p.whole++;
        if (o->animFrame & 1)
            v = -0x18;
        else
            v = 0x18;
        func_80043AB0(o, o->h->p.whole + v, o->y.p.whole, o->animFrame);
        if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)) {
            o->unk8C = (-SCRATCHPAD.unk27E << 2) & 0xff;
            o->step = 1;
            o->unk9C = 0;
            o->subState++;
        }
        break;
    }
    if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0xf) == 0 && D_800A38EA + 0x98 < o->y.p.whole) o->state = 3;
}
#endif

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012659C);

#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012659C);
#else
void func_8012659C(GameObject *o)
{
    u8 *b;

    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->movetab = D_8007725C;
        o->unkAC = 4;
        o->animFrame = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->step++;
        o->anim = D_801388C4;
        b = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *b++;
        o->hitWidth = *b++;
        o->hitOffsetY = *b++;
        o->hitHeight = *b++;
        readAnimFrameCount(o);
    case 1:
        tickAnimation(o);
        if (o->visible && ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x1f) == 0) playSFX(0x76);
        applyFrameVelocityX(o);
        if (func_80043AB0(o, o->h->p.whole + 0x18, o->y.p.whole, 0)) {
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        if (o->visible && ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        o->y.p.whole++;
        func_80043AB0(o, o->h->p.whole + 0x18, o->y.p.whole, 0);
        if (o->y.p.whole > D_800A38EA + 0x98) o->state = 3;
        break;
    }
    if (isObjectPastReferenceX(o) == 1 && o->visible == 0) o->state = 3;
}
#endif

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801267DC);

typedef struct { s16 w0, w2; } X_267DC;
#define XS(o) ((X_267DC *)((char *)(o) + 0xb4))

static __inline__ s32 Side_267DC(GameObject *o)
{
    u16 w = o->unk7A;
    s32 d;
    if (w & 1) d = -0x18;
    else d = 0x18;
    return func_80043AB0(o, (s16)(o->h->p.whole + d), o->y.p.whole, (s16)w);
}

static __inline__ s32 Ground_267DC(GameObject *o)
{
    u8 t;
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return 1;
    }
    if ((s16)probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0xe)) != 0) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            t = (*(u16*)&SCRATCHPAD.unk27E) * 4 + o->unk8C;
            if (t) {
                s32 w;
                if (t < 0x80) w = o->unk8C - 1; else w = o->unk8C + 1;
                o->unk8C = w;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
        return 1;
    }
    return 0;
}

#define SETANIM8(o) { \
    u8 *p; \
    x->w0 = 1; \
    *(volatile s16 *)&o->unkAC = 8; \
    p = &D_80135000[o->unkAC * 4]; \
    o->anim = D_801388D4[0]; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; \
    readAnimFrameCount(o); \
}

#define SPAWN(o) { \
    GameObject *e = allocObjectLayer3(); \
    if (e) { \
        e->active = 2; \
        e->type = 0x2f; \
        e->animFrame = 1 - o->unk7A; \
        e->x.p.whole = o->x.p.whole; \
        e->y.p.whole = o->y.p.whole; \
        e->z.p.whole = o->z.p.whole; \
        e->unk8C = o->unk8C; \
    } \
}

void func_801267DC(GameObject *o)
{
    X_267DC *x = XS(o);

    switch (o->step) {
    case 0:
        if (x->w0 == 0 && o->unk98 == 0) {
            o->step = 4;
            break;
        }
        if (x->w2) {
            x->w2 += o->unk68;
            if (x->w2 > 5) x->w2 = 5;
            o->unk68 = 1;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->unk9A = 0;
            o->step = 4;
            o->unk7 = 0;
            break;
        }
        o->velV = -0x400;
        o->movetab = D_80077214;
        o->unk8C = 0;
        o->unk9C = 1;
        o->step++;
        break;
    case 1:
        tickAnimation(o);
        applyAnimVelocityX(o, (u16)o->unk7A);
        Side_267DC(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if ((s16)func_80043D2C(o, o->h->p.whole, (s16)(o->y.p.whole - 0x10))) o->velV = 0;
        if (o->velV > 0) {
            o->touchFlag = 0;
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        applyAnimVelocityX(o, (u16)o->unk7A);
        Side_267DC(o);
        if (Ground_267DC(o)) {
            o->unk9C = 0;
            o->velH = 0x180;
            o->step++;
        }
        break;
    case 3:
        if ((s16)Side_267DC(o)) o->velH = 0;
        applyFrameVelocityY(o);
        Ground_267DC(o);
        if (o->unk7A & 1) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        o->velH -= 0x20;
        if (o->velH < 0) {
            o->velH = 0;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    case 4:
        if (o->subtype == 2 && o->unk9C) {
            SETANIM8(o);
            SPAWN(o);
            o->velV = -0x400;
            o->movetab = D_80077214;
            o->unk8C = 0;
            o->step++;
            o->unk9C = 1;
            o->step = 1;
            playSFX(0x77);
            break;
        }
        if ((u8)(o->unk8C - 0x70) < 0x21) {
            o->active = 5;
            o->step++;
            break;
        }
        playSFX(0x77);
        o->active = 1;
        o->state = 1;
        o->subState = 1;
        o->step = 1;
        o->unk7 = 0;
        SETANIM8(o);
        SPAWN(o);
        break;
    case 5:
        o->velV = 0;
        o->touchFlag = 0;
        o->unk9C = 2;
        if (o->unk8C >= 0x80) o->step = 6;
        else o->step = 7;
        break;
    case 6:
    case 7:
        if (o->step == 6) o->unk8C += 8;
        else o->unk8C -= 8;
        o->unk8C = *(u8 *)&o->unk8C;
        o->velV += 0x20;
        if (o->velV > 0x600) o->velV = 0x600;
        o->y.raw += o->velV << 8;
        if (Ground_267DC(o)) {
            o->unk8C = (-(s16)(*(u16*)&SCRATCHPAD.unk27E) << 2) & 0xff;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->step = 2;
            o->unk7 = 0;
            SETANIM8(o);
            SPAWN(o);
        }
        break;
    }
}
#undef XS
#undef SETANIM8
#undef SPAWN

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127098);


static __inline__ void setAnimN_27098(GameObject *o, s16 n)
{
    u8 *p;
    o->unkAC = n;
    o->anim = D_801388B4[n];
    p = &D_80135000[o->unkAC * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    readAnimFrameCount(o);
}

static __inline__ void fall_27098(GameObject *o)
{
    u32 t;
    o->y.p.whole++;
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return;
    }
    if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            t = (((*(u16*)&SCRATCHPAD.unk27E) << 2) + o->unk8C) & 0xff;
            if (t) {
                if (t < 0x80) o->unk8C--;
                else o->unk8C++;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
    }
}

void func_80127098(GameObject *o)
{
    s16 *w = &o->unkB4;
    u8 t;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        spawnItemNotification(2, 6);
        if (w[1] == 0 || w[1] == 5) {
            o->step = 2;
            o->timer = 2;
            setAnimN_27098(o, 9);
        } else {
            o->timer = 7;
            o->step++;
            w[1]++;
            setAnimN_27098(o, D_801350AB[w[1]]);
        }
        break;
    case 1:
        if (--o->timer == -1) o->step = 0;
        fall_27098(o);
        break;
    case 2:
        if (--o->timer == -1) o->step++;
        fall_27098(o);
        break;
    case 3:
        {
        u8 t;
        u8 *p;
        ((u8*)&PLAYER.obj.step)[0] = 2;
        ((u8*)&PLAYER.obj.unkAC)[0] = 3;

        t = *(volatile u8 *)&o->step;
        *(volatile s16 *)&o->unkAC = 10;
        o->step = t + 1;
        o->anim = D_801388B4[10];
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        readAnimFrameCount(o);
        }
        break;
    case 4:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801273B0);
typedef struct B_273B0 { u8 c[4]; } B_273B0;
extern void applyAnimVelocityX(GameObject *, u16);

void func_801273B0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unkB = 1;
        o->active = 2;
        o->unkF = 4;
        o->unkA = 2;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unk8C = 0;
        o->unk88 = 0;
        o->unk84 = 0;
        o->animFrame &= 1;
        o->step++;
        if (o->subtype == 3)
            o->unkAC = 4;
        else
            o->unkAC = 10;
        o->anim = D_801388B4[o->unkAC];
        { u8 *p = ((B_273B0 *)&D_80135000)[o->unkAC].c;
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1]; }
        readAnimFrameCount(o);
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
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
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012754C);


typedef struct { s16 a, b, x, y, z; } Q_2754C;
typedef struct { char p[0xd2]; s16 wd2; } E_2754C;
typedef void (*Fn_2754C)(GameObject *);

extern Fn_2754C D_801350BC[];
extern void func_80023020(GameObject *);
extern s32 func_80022F6C(GameObject *);

void func_8012754C(GameObject *o)
{
    Q_2754C *q = (Q_2754C *)&o->unkB4;
    s16 yy;
    u32 v;

    switch (o->state) {
    case 0:
        if (o->subState == 0) {
            q->x = o->h->p.whole;
            q->y = o->y.p.whole;
            q->z = o->d->p.whole;
            o->tpage = 0xb;
            o->subState++;
            o->spriteBank = SCRATCHPAD.sprData[5];
        } else {
            q->a = 0;
            q->b = 0;
            *(s8 *)&o->unkF = -9;
            o->unk84 = 0;
            o->unk88 = 0;
            o->touchFlag = 0;
            o->unk98 = 3;
            o->unk9A = 0;
            o->unk68 = 0;
            o->unk9E = 0;
            o->subState = 0;
            *(s32 *)&o->anim = 0;
            o->state++;
        }
        break;
    case 1:
        if (D_8009BC98.unk12) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        if (!(o->unk68 | o->unk9E)) {
            switch (o->subState) {
            case 0:
                D_801350BC[o->subtype](o);
                break;
            case 1:
                switch (o->step) {
                case 0:
                    func_80124B84(o);
                    break;
                case 1:
                    func_80124CFC(o);
                    break;
                case 2:
                    func_80125048(o);
                    break;
                case 3:
                    func_8012567C(o);
                    break;
                case 4:
                    func_80125EB8(o);
                    break;
                }
                break;
            }
        } else {
            if (o->unk9E) {
                if (o->unk9F == 0) {
                    ((E_2754C *)o)->wd2 = o->h->p.whole;
                    o->unk9F = 15;
                } else {
                    o->h->p.whole = (s16)(((E_2754C *)o)->wd2 - 2) + (((s32 (*)(void))nextRandom)() & 3);
                    if (--o->unk9F == 0) {
                        o->unk9E = 0;
                        o->h->p.whole = ((E_2754C *)o)->wd2;
                    }
                }
            } else {
                if (o->unk9A == 0) {
                    o->unk30 = o->h->p.whole;
                    o->unk9A = 0x14;
                } else {
                    o->h->p.whole = (s16)(o->unk30 - 2) + (((s32 (*)(void))nextRandom)() & 3);
                    if (o->unkAC != 0x1e && q->b == 0) {
                        if (o->unk7A) o->unk30--;
                        else o->unk30++;
                        if (func_80124A44(o, o->unk7A)) {
                            if (o->unk7A) o->unk30++;
                            else o->unk30--;
                        }
                        yy = o->y.p.whole;
                        o->y.p.whole = yy + 2;
                        if (o->touchFlag == 1) {
                            o->touchFlag = 0;
                        } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(yy + 0x10))) {
                            if (o->unkAC >= 0xc) {
                                o->unk8C = 0;
                            } else {
                                v = (((*(u16*)&SCRATCHPAD.unk27E) << 2) + o->unk8C) & 0xff;
                                if (v != 0) {
                                    if (v < 0x80) o->unk8C = o->unk8C - 1;
                                    else o->unk8C = o->unk8C + 1;
                                    o->unk8C = *(u8 *)&o->unk8C;
                                }
                            }
                        }
                    }
                    if (--o->unk9A == 0) {
                        o->unk68 = 0;
                        if (o->unkAC == 0x1e || q->b != 0) o->h->p.whole = o->unk30;
                    }
                }
            }
        }
        o->unk9D = 0;
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_801267DC(o);
            if (!o->visible) func_80023020(o);
            break;
        case 1:
            func_80127098(o);
            break;
        case 2:
            func_801273B0(o);
            if (!o->visible) o->state = 3;
            break;
        }
        break;
    case 3:
        if (o->subtype >= 2) {
            (*(s16 *)o->unk90)--;
            freeObjectLayer2(o);
        } else {
            *(s8 *)&o->unkF = -9;
            o->timer = D_8013508C[((s32 (*)(void))nextRandom)() & 7] + 0x12c;
            o->unkB = 0;
            o->h->p.whole = q->x;
            o->y.p.whole = q->y;
            o->d->p.whole = q->z;
            o->state++;
        }
        break;
    case 4:
        if (o->timer) {
            o->timer--;
        } else if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0x3f) == 0 && !func_80022F6C(o)) {
            o->active = 1;
            o->state = 0;
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127B48);
extern s32 D_1F8002DC[];

void func_80127B48(GameObject *o)
{
    s32 t;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xb;
        o->unkA = 2;
        o->unk84 = 0;
        o->unk88 = 0;
        o->spriteBank = D_1F8002DC[0];
        o->unkAC = 5;
        o->anim = D_801388C8[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) != 0) {
            switch (o->subState) {
            case 0:
                o->unkB = 1;
                o->unkF = 4;
                o->velV = -0x400;
                o->movetab = ((char *)&D_8007722C);
                o->unkAC = 5;
                o->subState++;
                o->anim = D_801388C8[0];
                readAnimFrameCount(o);
                break;
            case 1:
                applyAnimVelocityX(o, 1 - o->animFrame);
                o->velV += 0x40;
                if (o->velV > 0x400)
                    o->velV = 0x400;
                o->y.raw += o->velV << 8;
                break;
            }
            if (o->animFrame & 1)
                t = o->unk8C + 0x14;
            else
                t = o->unk8C - 0x14;
            o->unk8C = t & 0xff;
        } else {
            o->state = 3;
        }
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127D18);
typedef struct { void **anims; s32 a; s32 b; } AT_27D18;
extern AT_27D18 D_801350D4[];
extern void advanceAnimFrame(GameObject *, s16);

void func_80127D18(GameObject *o, s16 n, s16 k)
{
    o->anim = D_801350D4[o->subtype].anims[n];
    advanceAnimFrame(o, k);
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127D6C);

typedef struct { s32 *p; s32 pad[2]; } E12_27D6C;

void func_80127D6C(GameObject *o)
{
    u8 *c;

    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = (void *)((E12_27D6C *)&D_801350D4)[o->subtype].p[1];
        readAnimFrameCount(o);
        o->velX = -0x200;
        o->velY = 0x800;
        o->step++;
    case 1:
        if (D_8009C068.unk58f) {
            o->anim = (void *)((E12_27D6C *)&D_801350D4)[o->subtype].p[1];
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        if (o->h->p.whole < 0x1f4) {
            o->h->p.whole = 0x1f4;
        }
        o->y.raw += o->velY << 8;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10)) && o->h->p.whole < 0x1f5) {
            o->animFrame = 0;
            c = &D_8009C068.unk58f;
            *c = *c + 1;
            o->step++;
        }
        break;
    case 3:
        if (D_8009C068.unk58f == 4) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127F58);
void func_80127F58(GameObject *o)
{
    u8 *c;

    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = D_801350D4[o->subtype].anims[1];
        readAnimFrameCount(o);
        o->velX = -0x200;
        o->velY = 0x800;
        o->step++;
    case 1:
        tickAnimation(o);
        if (D_8009C068.unk58f) {
            o->anim = D_801350D4[o->subtype].anims[1];
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        if (o->h->p.whole < 0x218) o->h->p.whole = 0x218;
        o->y.raw += o->velY << 8;
        if (((s16 (*)(GameObject *o, s16 x, s16 y))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10) && o->h->p.whole < 0x219) {
            c = &D_8009C068.unk58f;
            *c = *c + 1;
            o->step++;
        }
        break;
    case 3:
        if (D_8009C068.unk58f == 4) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128148);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801282F0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128498);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128514);
