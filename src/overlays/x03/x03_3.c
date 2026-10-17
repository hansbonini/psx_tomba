#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D098);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D1A8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D41C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D4F4);
extern u8 D_80114638[];
extern void func_800EDEBC(GameObject *, s32);
extern void playSFX(s32);
extern s32 tickAnimation(GameObject *);
extern void func_800EDD9C(GameObject *);

void func_8011D4F4(GameObject *o)
{
    u8 one;

    switch (o->step) {
    case 0:
        one = 1;
        o->unkB2 = 0;
        ((u8 *)o)[0xa2] = one;
        func_800EDEBC(o, 0x42);
        playSFX(0x20);
        ((u8 *)o)[0xab] = one;
        o->timer = 0x78;
        o->step++;
        break;
    case 1:
        tickAnimation(o);
        if (--o->timer > 0) break;
        o->timer = 0x3c;
        o->step++;
        break;
    case 2:
        func_800EDD9C(o);
        tickAnimation(o);
        if (--o->timer > 0) break;
        o->unkB2 = 0;
        *(u8 *)&o->unkAC = 0;
        ((u8 *)o)[0xab] = 0;
        o->unk8C = D_80114638[o->unkB0];
        o->state = 1;
        o->subState = 0x20;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D620);
extern s32 clampToCeilingAndProbeSides(GameObject *);
extern void func_800ED788(GameObject *);

static __inline__ void fall_1D620(GameObject *o)
{
    o->unk9C = 2;
    *(char *)&o->unkAC = 1;
    func_800ED788(o);
    o->subState = 2;
    o->step = 3;
}

void func_8011D620(GameObject *o)
{
    if (clampToCeilingAndProbeSides(o)) {
        fall_1D620(o);
    }
    if (o->velY > 0) {
        fall_1D620(o);
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D6A8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011D9CC);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011DA00);
typedef struct GVars_1DA00 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_1DA00;

extern GameObject *D_8009B698;
extern void func_800FB38C(GameObject *);
extern void func_800224FC(s32, s32, s32, s32);
extern void func_80042C20(GameObject *);
extern s16 probeSidesAndApplyTileResponse(GameObject *, s32, s32);
extern void func_800FB774(GameObject *);

static __inline__ void land_1DA00(GameObject *o, s16 n)
{
    *(u8 *)&D_8009B698->clut = 0;
    o->unk9C = n;
    *(u8 *)&o->unkAC = 1;
    o->state = 1;
    func_800ED788(o);
    o->subState = n;
    o->step = 3;
    o->unk7 = 0;
}

void func_8011DA00(GameObject *o)
{
    s16 v;

    switch (o->step) {
    case 0:
        v = 0x200;
        if (o->animFrame & 1) {
            v = -0x200;
        }
        o->unk9C = 1;
        o->velX = v;
        o->velY = 0;
        o->timer = 0x14;
        o->step++;
    case 1:
        o->visible = 1;
        func_800EDEBC(o, 0x39);
        playSFXWithNote(0x23, 0x24);
        playSFX(0x1f);
        func_800FB38C(o);
        o->animFrame ^= 1;
        *(u8 *)&D_8009B698->clut = ((u8*)&(*(GVars_1DA00 *)&D_8009BC98).b38)[0];
        func_800224FC(3, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        break;
    case 2:
        o->h->raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s44)[0] << 8;
        o->y.raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s46)[0] << 8;
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        if (tickAnimation(o)) {
            func_800EDEBC(o, 0x10);
            o->step = 3;
        }
        break;
    case 3:
        o->h->raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s44)[0] << 8;
        o->y.raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s46)[0] << 8;
        {
            s32 d = o->unk8C;
            o->unk8C = ((o->animFrame & 1) ? d - 0x10 : d + 0x10) & 0xff;
        }
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        if (--o->timer <= 0) {
            o->step++;
        }
        if (*(u8 *)&D_8009B698->clut == 0) {
            if (o->velY > 0) {
                land_1DA00(o, 2);
            }
            if (clampToCeilingAndProbeSides(o)) {
                land_1DA00(o, 2);
            }
        }
        break;
    case 4:
        o->h->raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s44)[0] << 8;
        o->y.raw += ((s16*)&(*(GVars_1DA00 *)&D_8009BC98).s46)[0] << 8;
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x40;
        if (o->velY > 0x680) {
            o->velY = 0x680;
        }
        func_80042C20(o);
        if (o->touchFlag || probeSidesAndApplyTileResponse(o, 0, 0)) {
            o->unk9C = 0;
            o->unk7 = 0;
            o->animFrame ^= 1;
            o->step++;
        }
        if (*(u8 *)&D_8009B698->clut == 0) {
            if (clampToCeilingAndProbeSides(o)) {
                land_1DA00(o, 2);
            }
            if (o->velY > 0) {
                land_1DA00(o, 2);
            }
        }
        break;
    case 5:
        func_800FB774(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011DE38);
extern void func_800EDEBC(GameObject *, s32);
extern void func_800FB38C(GameObject *);

void func_8011DE38(GameObject *o)
{
    s32 t, u;

    switch (o->step) {
    case 0:
        func_800EDEBC(o, 0x37);
        o->timer = 8;
        func_800FB38C(o);
        break;
    case 2:
        if (--o->timer > 0)
            break;
        func_800EDEBC(o, 0x10);
        o->step++;
        break;
    case 3:
        t = o->unk8C;
        if (o->animFrame & 1)
            u = t + 0x10;
        else
            u = t - 0x10;
        o->unk8C = u & 0xff;
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011DF10);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E660);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E680);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E6DC);

extern s16 func_80059514(GameObject *, GameObject *);
extern s16 D_1F8003BC;

void func_8011E6DC(GameObject *o, GameObject *p)
{
    p->unk6A = 0;
    if (func_80059514(o, p)) {
        o->unk9E = 4;
        o->unkBA = 0;
        o->velY = 0;
        SCRATCHPAD.unk19E = 0;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = p;
        o->unkB8 = D_1F8003BC;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E748);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E768);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E7C4);

extern s16 func_80059638(GameObject *, GameObject *);

void func_8011E7C4(GameObject *o, GameObject *p)
{
    GameObject *q;
    if (func_80059638(o, p)) {
        o->unk9E = 1;
        o->unkB8 = SCRATCHPAD.unk3BC;
        o->unkBA = -((s16)(u16)p->hitOffsetY >> 1);
        o->velY = 0;
        q = (GameObject *)p->movetab;
        q->touchFlag = 1;
        D_1F80019E = 0;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = p;
        q->animFrame = o->animFrame & 1;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E858);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011E984);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EB3C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EC1C);

typedef struct { GameObject o; char pad[0x24]; GameObject *e4; } TObjX_1EC1C;
extern s16 func_80051604(GameObject *, GameObject *);
extern void decreaseObjectTimer(GameObject *, s32);

void func_8011EC1C(GameObject *o, GameObject *e)
{
    s16 r;

    if (e->subtype == 4) return;
    r = func_80051604(o, e);
    if (r == -1) return;
    switch (*(u8 *)&o->unkAC) {
    case 1:
        if (r < 3) {
            e->active = 4;
            e->state = 2;
            e->subState = 1;
            e->step = 0;
            e->touchFlag = 0;
            e->animFrame = o->animFrame & 1;
            ((TObjX_1EC1C *)o)->e4 = e;
            *(u8 *)&o->unkAC = 2;
            break;
        }
    case 0:
    case 3:
        if (e->active & 2) break;
        e->touchFlag = 8;
        if (SCRATCHPAD.unk1A4) break;
        if (o->active & 2) break;
        o->active = 2;
        r = e->h->p.whole > o->h->p.whole;
        o->state = 2;
        o->subState = 0;
        o->step = 0;
        o->animFrame = r;
        decreaseObjectTimer(o, 1);
        break;
    case 2:
        if (e->active == 3) break;
        r = o->h->p.whole > e->h->p.whole;
        e->active = 3;
        e->state = 2;
        e->subState = 0;
        e->step = 0;
        e->touchFlag = 0;
        e->unk7A = r;
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EDBC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EE24);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EF08);
void func_8011EF08(GameObject *o, GameObject *p)
{
    u8 v;
    s16 d;

    d = o->z.p.whole - p->d->p.whole + 0x3c;
    if ((u16)d >= 0x79) return;
    d = o->x.p.whole - p->h->p.whole;
    if ((u16)d >= 0x5b) return;
    if ((u16)(o->y.p.whole - p->y.p.whole + 0x40) >= 0x81) return;
    switch (p->subtype) {
    case 0:
        v = 1;
        break;
    case 4:
        v = 7;
        break;
    case 8:
        v = 0xb;
        break;
    case 0xa:
        v = 2;
        break;
    default:
        return;
    }
    *(u8 *)&o->unkA8 = v;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011EFD4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F070);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F158);
extern void func_80051804();

void func_8011F158(s32 a, char *p)
{
    if (*(s32 *)(p + 0x94) == 0)
        func_80051804();
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F188);
extern GameObject *D_1F8003C0;

void func_8011F188(GameObject *a, GameObject *b)
{
    if (b->unk94 == 0 && ((s16 (*)(void))func_80059514)() != 0) {
        a->unk9E = 4;
        a->unkBA = -3;
        a->velY = 0;
        D_1F80019E = 0;
        a->unkB8 = D_1F8003BC;
        b->unk68 = 2;
        D_1F8003C0 = b;
        b->animFrame = a->animFrame & 1;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F218);

extern s16 boxesOverlapSigned(GameObject *, GameObject *);
extern s32 resolveHitResultA(GameObject *, GameObject *);

void func_8011F218(GameObject *o, GameObject *e)
{
    if (e->unk94 == 0 && boxesOverlapSigned(o, e) >= 0) {
        resolveHitResultA(o, e);
        if (o->type != 1) {
            if (o->animFrame < 4) e->animFrame = o->animFrame & 1;
            else e->animFrame = 3;
        } else {
            e->animFrame = o->animFrame & 1;
        }
        SCRATCHPAD.unk19E = 0;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F2B4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F490);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F634);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F67C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F6DC);
extern s16 func_80056284(void);
void func_8011F6DC(s32 a, char *p)
{
    if (*(s32 *)(p + 0x94) == 0 && func_80056284() != 0)
        SPAD->unk19E = 0;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F720);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F754);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F788);
typedef struct AE_1F788 { char p0[2]; u16 i; char p1[2]; u16 v; } AE_1F788;
typedef struct { char p0[0x24]; AE_1F788 *a; char p1[4]; u16 t; char p2[0x3e]; u16 b0, b1, b2, b3; } TA_1F788;
extern u8 D_80134E80[];

static __inline__ void box_1F788(TA_1F788 *o, s32 idx)
{
    u8 *b = D_80134E80 + idx * 4;
    o->b0 = *b++;
    o->b1 = *b++;
    o->b2 = *b;
    o->b3 = b[1];
}

s32 func_8011F788(TA_1F788 *o)
{
    AE_1F788 *e, *n; u16 v; s32 k;
    o->t = o->t - 1;
    if (o->t != 0) return 0;
    e = o->a;
    v = e->v;
    k = v & 0xc000;
    switch (k) {
    case 0:
        o->a = e + 1;
        box_1F788(o, e[1].i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x4000:
        o->a = e + 1;
        n = *(AE_1F788 **)(e + 1);
        o->a = n;
        box_1F788(o, n->i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x8000:
        o->t = v & 0x3fff;
        return 1;
    case 0xc000:
        o->a = e + 1;
        n = *(AE_1F788 **)(e + 1);
        o->a = n;
        box_1F788(o, n->i);
        o->t = o->a->v & 0x3fff;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011F8F4);
typedef struct A_1F8F4 { s16 w0; u16 w2; u16 w4; u16 w6; } A_1F8F4;
typedef struct B_1F8F4 { u8 c[4]; } B_1F8F4;
s32 func_8011F8F4(GameObject *o)
{
    A_1F8F4 *a;
    u8 *p;
    s32 idx, dy, d;
    s16 sx;
    u16 v;
    if (--o->animTimer == 0) {
        a = o->anim;
        d = a->w6;
        switch (d & 0xc000) {
        case 0:
            o->anim = a + 1;
            idx = a[1].w2;
            goto merge;
        case 0x4000:
            o->anim = a + 1;
            o->anim = *(A_1F8F4 **)(a + 1);
            idx = ((A_1F8F4 *)o->anim)->w2;
        merge:
            { B_1F8F4 *t = D_80134E80; p = t[idx].c; }
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1];
            o->animTimer = ((A_1F8F4 *)o->anim)->w6 & 0x3fff;
            v = ((A_1F8F4 *)o->anim)->w4;
            d = v & 0xff;
            dy = v >> 8;
            sx = d;
            if (o->animFrame & 1) sx = -d;
            o->h->p.whole += sx;
            o->y.p.whole += dy;
            break;
        case 0x8000:
            o->animTimer = d & 0x3fff;
            return 1;
        case 0xc000:
            o->animTimer = d & 0x3fff;
            return 1;
        }
    }
    return 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011FA40);
extern u16 D_1F800282;
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

s32 func_8011FA40(GameObject *o)
{
    s16 v;

    if (o->touchFlag == 1) {
        o->unk8C = 0;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkAE = -1;
        o->unk9C = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10)) == 0)
        return 0;
    o->touchFlag = 0;
    v = D_1F80027E;
    if (v < 0)
        v = -v;
    if (v > 8)
        v = 8;
    if (D_1F80027E < 0)
        v = -v;
    o->unkB2 = v;
    o->unk8C = -v & 0xff;
    o->unkB6 = (-v << 2) & 0xff;
    o->unkAE = (*(u16*)&SCRATCHPAD.unk284);
    o->unk9C = 0;
    if ((s16)((D_1F800282 >> 5) & 0xf) >= 0xe)
        o->unk98 = 0;
    return 1;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011FB5C);
typedef struct P_1FB5C { s16 w0; u16 w2; s16 w4; } P_1FB5C;
typedef struct H_1FB5C { char p0[2]; s16 x; } H_1FB5C;
typedef struct O_1FB5C {
    char p0[3]; u8 subtype;
    char p1[0x16 - 4]; s16 y;
    char p2[0x2e - 0x18]; u16 af;
    char p3[0x40 - 0x30]; H_1FB5C *h;
    char p4[0x9d - 0x44]; u8 b9d;
    char p5[0xb4 - 0x9e]; P_1FB5C p;
} O_1FB5C;
extern s16 D_8007D788[];
extern s16 D_8007DB88[];
extern s16 func_80043AB0(O_1FB5C *, s32, s32, s32);

s32 func_8011FB5C(O_1FB5C *o)
{
    u16 a, b;
    P_1FB5C *p = &o->p;
    if ((o->b9d & 2) && o->af == (o->b9d & 1))
        return 1;
    if (o->af == 0)
        p->w4 = 0x10;
    else
        p->w4 = -0x10;
    if (p->w2 != 0) {
        s32 i = (p->w2 & 0xff) * 2;
        a = (u32)(p->w4 * *(s16 *)((char *)D_8007D788 + i)) >> 12;
        b = (u32)(p->w4 * *(s16 *)((char *)D_8007DB88 + i)) >> 12;
    } else {
        a = 0;
        b = p->w4;
    }
    return func_80043AB0(o, (s16)(o->h->x + b), (s16)(o->y + a), (s16)o->af) != 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011FC48);
extern u16 D_1F80016E;
extern u8 *D_80134FA0[];

u8 func_8011FC48(s32 a)
{
    s16 s;
    s32 d;
    s16 u;
    s32 v;
    u8 *t;
    if ((u16)(*(u16 *)(*(s32 *)(a + 0x44) + 2) - (*(u16 *)&D_1F800172) + 0x2d) >= 0x5b) return 0xff;
    if ((u16)(*(u16 *)(a + 0x16) - D_1F80016E + 0x46) >= 0x6f) return 0xff;
    d = *(u16 *)(*(s32 *)(a + 0x40) + 2) - (*(u16 *)&D_1F80016A);
    if ((u16)(d + 0x80) >= 0x101) return 0xff;
                s = d;
                if ((s16)d < 0)
                    s = -d;
                v = s >= 0x42;
                u = v;
                if (s >= 0x52)
                    u = v + 1;
                t = D_80134FA0[u];
    return t[nextRandom() & 0xf];
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8011FD48);
typedef struct A_1FD48 { s16 w0; u16 w2; u16 w4; u16 w6; } A_1FD48;
typedef struct B_1FD48 { u8 c[4]; } B_1FD48;
typedef struct { s16 w0, w2, w4, w6, w8; u8 bA, bB; s16 wC, wE; } X_1FD48;
extern char D_80077214[];
extern A_1FD48 *D_80137AAC[];
extern void applyFrameVelocityX(GameObject *);

#define SETANIM(k) \
    { A_1FD48 *a = D_80137AAC[k]; u8 *p; \
    o->anim = a; \
    p = ((B_1FD48 *)&D_80134E80)[a->w2].c; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; \
    o->animTimer = ((A_1FD48 *)o->anim)->w6 & 0x3fff; }

#define SPAWN() \
    { GameObject *e = allocObjectLayer3(); \
    if (e) { \
        e->active = 1; \
        e->type = 0x10; \
        e->subtype = 1; \
        e->x.p.whole = o->x.p.whole; \
        e->y.p.whole = o->y.p.whole + 0x10; \
        e->z.p.whole = o->z.p.whole; \
    } }

void func_8011FD48(GameObject *o)
{
    X_1FD48 *x = (X_1FD48 *)((char *)o + 0xb4);

    switch (o->unk7) {
    case 0:
        {
            s32 t = o->unk8C;
            o->unk9C = 2;
            x->wE = 0;
            x->wC = t;
        }
        o->unk7++;
        o->touchFlag = 0;
        o->velV = 0;
        if (o->movetab == 0) o->movetab = D_80077214;
        break;
    case 1:
        applyFrameVelocityX(o);
        func_8011FB5C(o);
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        x->wC += 8;
        if (x->wC < 0x33) break;
        o->touchFlag = 0;
        o->unk7++;
        x->wC = 0xc0;
        o->unkAC = 0x17;
        SETANIM(0x17);
        break;
    case 2:
        applyFrameVelocityX(o);
        func_8011FB5C(o);
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        x->wC += 5;
        if (x->wC >= 0x100) x->wC = 0x100;
        if (!func_8011FA40(o)) break;
        if (!(o->touchFlag & 8)) SPAWN();
        o->touchFlag = 0;
        x->wC = 0x100;
        o->movetab = ((char *)&D_800771FC);
        o->timer = 2;
        o->unkAC = 0x16;
        o->unk7++;
        SETANIM(0x16);
        break;
    case 3:
        if (--o->timer != -1) break;
        o->timer = 0;
        o->touchFlag = 0;
        x->wC = 0;
        o->velV = -0x300;
        o->unk9C = 1;
        o->unkAC = 0x17;
        o->unk7++;
        SETANIM(0x17);
        break;
    case 4:
        applyFrameVelocityX(o);
        func_8011FB5C(o);
        o->velV += 0x40;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (o->velV <= 0) break;
        o->unk9C = 2;
        if (!func_8011FA40(o)) break;
        if (!(o->touchFlag & 8)) SPAWN();
        o->timer = 2;
        o->unkAC = 0x16;
        o->unk7++;
        SETANIM(0x16);
        break;
    case 5:
        if (--o->timer != -1) break;
        o->timer = 0;
        x->wC = 0;
        o->unk9C = 1;
        o->velV = -0x200;
        o->touchFlag = 0;
        o->unkAC = 0x17;
        o->unk7++;
        SETANIM(0x17);
        break;
    case 6:
        applyFrameVelocityX(o);
        func_8011FB5C(o);
        o->velV += 0x40;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (o->timer == 0) {
            x->wC += 2;
            if (x->wC >= 0x16) {
                x->wC = 0xe0;
                o->timer = 1;
                o->unkAC = 0x18;
                SETANIM(0x18);
            }
        } else {
            x->wC += 4;
            if (x->wC >= 0x100) x->wC = 0x100;
        }
        if (o->velV <= 0) break;
        o->unk9C = 2;
        if (!func_8011FA40(o)) break;
        if (!(o->touchFlag & 8)) SPAWN();
        o->touchFlag = 0;
        x->wC = 0;
        o->timer = 0x14;
        o->unkAC = 0x10;
        o->unk7++;
        SETANIM(0x10);
        break;
    case 7:
        func_8011F788(o);
        if (--o->timer != -1) break;
        o->step = x->bA;
        o->unk7 = x->bB;
        o->unk68 = 0;
        break;
    }
    if (o->animFrame) o->unk8C = (u8)x->wC;
    else o->unk8C = -x->wC & 0xff;
}
#undef SETANIM
#undef SPAWN

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801203F8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801205D8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801206E8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80120708);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80120AC8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80120DD8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80120E90);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80120ECC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801210A4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121320);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8012137C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121468);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121748);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801219F0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121C00);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121CD4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121D5C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121F54);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121F94);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80121FF4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122104);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122258);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8012228C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122538);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_3", func_801155A8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801226DC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122B1C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122E44);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122E70);
typedef struct A_22E70 { s16 w0; u16 w2; u16 w4; u16 w6; } A_22E70;
typedef struct B_22E70 { u8 c[4]; } B_22E70;
extern u8 D_80134FAC[];
extern void applyFrameVelocityY(GameObject *);

void func_80122E70(GameObject *o)
{
    u8 *p;

    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->touchFlag = 0;
        o->step++;
        o->unkAC = D_80134FAC[o->unkC];
        o->anim = D_80137AAC[o->unkAC];
        { B_22E70 *t = D_80134E80; p = t[((A_22E70 *)o->anim)->w2].c; }
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        o->animTimer = ((A_22E70 *)o->anim)->w6 & 0x3fff;
        break;
    case 1:
        func_8011F788(o);
        applyFrameVelocityY(o);
        if (func_8011FA40(o) != 0) {
            o->timer = 0;
            o->step++;
        }
        break;
    case 2:
        func_8011F788(o);
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80122FB0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80123038);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801231F8);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80123510);
extern u16 *D_80137B48[];

void func_80123510(GameObject *o)
{
    u16 *a;
    u16 dx, dz;

    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->touchFlag = 0;
        o->unkAC = 0x27;
        o->step++;
        a = D_80137B48[0];
        o->anim = a;
        {
            u8 *pp = &D_80134E80[a[1] * 4];
            o->hitOffsetX = *pp++;
            o->hitWidth = *pp++;
            o->hitOffsetY = *pp;
            o->hitHeight = pp[1];
        }
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 1:
        func_8011F788(o);
        applyFrameVelocityY(o);
        if (func_8011FA40(o)) {
            o->timer = 0;
            o->step++;
        }
        break;
    case 2:
        func_8011F788(o);
        dx = o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + 0x60;
        dz = o->d->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[2].raw + 2)) + 0x2d;
        if (dz >= 0x5b || dx >= 0xc1) {
            o->timer = 0;
            break;
        }
        if (o->timer++ < 0x46)
            break;
        o->timer = 10;
        o->step++;
        break;
    case 3:
        func_8011F788(o);
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 0;
            o->unk7 = 6;
            o->touchFlag = 0;
            o->unk68 = 0;
        }
        break;
    }
}

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_3", func_80115608);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80123708);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80123EC8);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8012434C);

typedef struct A_2434C { s16 w0; u16 w2; } A_2434C;
typedef struct B_2434C { u16 c[4]; } B_2434C;
extern A_2434C *D_80138274[];
extern B_2434C D_80134FC8[];
extern void readAnimFrameCount(GameObject *);
extern void freeObjectLayer2(GameObject *);

void func_8012434C(GameObject *o)
{
    u16 *p;

    switch (o->state) {
    case 0:
        o->state++;
        *(s8 *)&o->unkF = -6;
        o->tpage = 8;
        o->unkD = 0;
        o->touchFlag = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = 0;
        break;
    case 1:
        if (func_80022E44(o)) {
            switch (o->subState) {
            case 0:
                if (o->touchFlag) {
                    playSFX(0x73);
                    o->active = 2;
                    o->subState++;
                    o->anim = D_80138274[o->subtype];
                    readAnimFrameCount(o);
                }
                break;
            case 1:
                if (tickAnimation(o)) {
                    o->active = 1;
                    o->touchFlag = 0;
                    o->anim = 0;
                    o->subState--;
                }
                break;
            }
            if (o->anim) p = D_80134FC8[((A_2434C *)o->anim)->w2].c;
            else p = D_80134FC8[D_80138274[o->subtype]->w2].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1];
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80124514);

void func_80124514(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->unkD = 0;
        o->tpage = 8;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_801245BC);
void func_801245BC(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->velH = 0x100;
        o->velX = 8;
        o->unk8C = 0;
        o->velY = 0;
        o->timer = 1 - o->objectIndex;
        o->step++;
        break;
    case 1: {
        s16 v = o->velH - o->velX;
        o->velH = v;
        if (o->timer) {
            o->velY -= v;
        } else {
            o->velY += v;
        }
        o->unk8C = (u16)o->velY >> 8;
        if (o->velH <= 0) {
            o->velH = 0;
            o->step++;
        }
        break;
    }
    case 2: {
        s16 v = o->velH + o->velX;
        o->velH = v;
        if (o->timer) {
            o->velY += v;
        } else {
            o->velY -= v;
        }
        o->unk8C = (u16)o->velY >> 8;
        if (o->velH >= 0x100) {
            o->velH = 0x100;
            o->step--;
            o->timer = 1 - o->timer;
        }
        break;
    }
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80124700);
extern void *D_80138248;
extern void *D_8013824C;
extern void *D_80138250;

void func_80124700(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->velV = 0x200;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->velY = 0x20;
        o->step++;
        break;
    case 1:
        o->y.raw -= o->velV << 8;
        o->velV -= o->velY;
        if (o->velV < 0x100) {
            o->step++;
            o->anim = D_8013824C;
        }
        break;
    case 2:
        o->y.raw -= o->velV << 8;
        o->velV -= o->velY;
        if (o->velV < -0x100) {
            o->step++;
            o->anim = D_80138250;
        }
        break;
    case 3:
        o->y.raw -= o->velV << 8;
        o->velV -= o->velY;
        if (o->velV < -0x1ff) {
            o->step++;
        }
        break;
    case 4: {
        s32 d = o->unk34;
        void *a = D_80138248;
        o->velV = 0x200;
        o->velY = 0x20;
        o->subState = 0;
        o->step = 0;
        o->y.raw = d << 16;
        o->anim = a;
        break;
    }
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_8012487C);

static __inline__ s32 near_2487C(GameObject *o)
{
    if ((u16)(o->d->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[2].raw + 2)) + 0x2d) >= 0x5b) return 0;
    if ((s16)((*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole) < -0xb0) return 0;
    return (u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + 0x10) < 0x21;
}

void func_8012487C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->hitOffsetY = 8;
        o->hitOffsetX = 2;
        o->tpage = 8;
        o->unkD = 0;
        o->hitWidth = 4;
        o->hitHeight = 0x10;
        o->animFrame = 1;
        o->anim = D_80138248;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->objectIndex = 0;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->unk68 = 0;
        o->state++;
        o->subState = 0;
        o->step = 0;
        o->unk34 = o->y.p.whole;
        break;
    case 1:
        if (func_80022E44(o)) {
            switch (o->subState) {
            case 0:
                if (near_2487C(o)) {
                    o->subState = 1;
                    o->step = 0;
                } else {
                    func_801245BC(o);
                }
                break;
            case 1:
                func_80124700(o);
                break;
            }
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80124A44);
typedef struct H_24A44 { char p0[2]; s16 x; } H_24A44;
typedef struct O_24A44 {
    char p0[0x16]; s16 y;
    char p2[0x40 - 0x18]; H_24A44 *h;
    char p4[0x8c - 0x44]; s32 d8c;
    char p5[0x9d - 0x90]; u8 b9d;
} O_24A44;
extern s16 probeCollisionAtDepthB(O_24A44 *, s16, s16);

s32 func_80124A44(O_24A44 *o, s16 k)
{
    u16 a, b;
    s16 v;

    if ((o->b9d & 2) && k == (o->b9d & 1))
        return 1;
    if (k & 1)
        v = -0x18;
    else
        v = 0x18;
    if (o->d8c != 0) {
        a = (u32)(v * D_8007D788[o->d8c & 0xff]) >> 12;
        b = (u32)(v * D_8007DB88[o->d8c & 0xff]) >> 12;
    } else {
        a = 0;
        b = v;
    }
    if (func_80043AB0(o, (s16)(o->h->x + b), (s16)(o->y + a), k) == 0)
        return probeCollisionAtDepthB(o, (s16)(o->h->x + b), (s16)(a + o->y + 0x22)) == 0;
    return 1;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80124B84);
extern void *D_8013892C;
extern u8 D_80135000[];

void func_80124B84(GameObject *o)
{
    u8 *p;
    s16 yy;
    u32 v;

    switch (o->unk7) {
    case 0:
        o->unk98 = 3;
        o->unkAC = 0x1e;
        o->unkB4 = 0;
        o->unkB6 = 0;
        o->unk7++;
        o->anim = D_8013892C;
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        readAnimFrameCount(o);
        break;
    case 1:
        yy = o->y.p.whole;
        o->y.p.whole = yy + 1;
        if (o->touchFlag == 1) {
            o->touchFlag = 0;
        } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(yy + 0xf))) {
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
        if (o->visible) {
            o->step = 2;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_3", func_80124CFC);
extern void *D_801388B4[];
extern void *D_80138924;
extern u8 D_801350A4[];

static __inline__ void fall_24CFC(GameObject *o)
{
    s16 yy;
    u32 v;

    yy = o->y.p.whole;
    o->y.p.whole = yy + 1;
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
    } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(yy + 0xf))) {
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

void func_80124CFC(GameObject *o)
{
    s16 *w = &o->unkB4;

    switch (o->unk7) {
    case 0: {
        u8 *p;
        o->unk7++;
        o->timer = D_801350A4[nextRandom() & 7];
        if (o->unkB4 != 0) o->unkAC = 7;
        else o->unkAC = 0x1e;
        o->anim = D_801388B4[o->unkAC];
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        readAnimFrameCount(o);
        break;
    }
    case 1:
        fall_24CFC(o);
        if (o->visible) {
            if (--o->timer == -1) {
                o->step = 2;
                o->unk7 = 0;
            }
        } else if (*w == 0 || (u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + 0x70) >= 0x220 ||
                   (u16)((*(u16 *)&SCRATCHPAD.unk168[7].p.whole) - o->y.p.whole + 0x70) >= 0x1c0) {
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    case 2: {
        u8 *p;
        o->unk7++;
        o->unkAC = 0x1c;
        o->anim = D_80138924;
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        readAnimFrameCount(o);
        break;
    }
    case 3:
        if (tickAnimation(o)) o->unk7 = 0;
        fall_24CFC(o);
        break;
    }
}
