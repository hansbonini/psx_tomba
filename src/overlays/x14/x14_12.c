#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80121DF0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80121F54);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80121FF4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_8012212C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122258);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_8012225C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_8012228C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_801222E4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122538);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_801229DC);
extern GameObject *allocObjectLayer2(void);

void func_801229DC(GameObject *o)
{
    GameObject *e = allocObjectLayer2();
    s16 d;

    if (e != 0) {
        e->active = 2;
        e->type = 0x4b;
        *(s8 *)&e->unkF = -12;
        e->unkA = 2;
        e->unk8C = 0;
        e->subtype = 1;
        e->unkC = 2;
        d = 8;
        if (o->animFrame) d = -8;
        e->x.p.whole = o->x.p.whole + d;
        e->y.p.whole = o->y.p.whole;
        e->z.p.whole = o->z.p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122A74);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122B1C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122DF0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80122E44);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123038);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_801230A8);

extern void *D_80129350[];
extern u16 D_80125A24[];
extern u16 D_1F80016E[];
extern s16 D_800A38E4;
extern void readAnimFrameCount(GameObject *);
extern s32 angleFromDelta(s16, s16);
extern s16 func_80044694(GameObject *, s32, s32);
extern s16 func_80045310(GameObject *, s32, s32);

static __inline__ s16 Out_230A8(GameObject *o)
{
    if (o->h->p.whole < D_800A38E4 - 0x9e) return 1;
    if (o->h->p.whole > D_800A38E6 + 0x9e) return 1;
    return o->y.p.whole > ((s16 *)&D_800A38E8)[1] + 0x78;
}

static __inline__ s32 Chk_230A8(GameObject *o, s16 k)
{
    s16 r = func_80044694(o, o->h->p.whole, o->y.p.whole);
    s32 n = k;
    if (r != 0 && n == r && SCRATCHPAD.unk284 == 0)
        n++;
    else if (func_80045310(o, o->h->p.whole, o->y.p.whole) == 0)
        n = 0;
    else
        n = SCRATCHPAD.unk284 == 0;
    return n;
}

void func_801230A8(GameObject *o)
{
    GameObject *n;
    GameObject *p;
    s16 s;

    switch (o->subState) {
    case 0:
        func_80022E44(o);
        o->y.p.whole -= 4;
        if (o->visible) break;
        o->timer = 0x1e;
        o->subState++;
        break;
    case 1:
        if (--o->timer != -1) break;
        o->subState++;
        o->anim = D_80129350[0];
        readAnimFrameCount(o);
        o->velH = 0x480;
        o->h->p.whole = (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2)) + D_80125A24[nextRandom() & 7];
        o->y.p.whole = (u16)SCRATCHPAD.unk168[4].p.whole - 0xf0;
        o->d->p.whole = D_1F800172[0];
        o->unk38 = angleFromDelta(((u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2))[0] - o->h->p.whole, D_1F80016E[0] - o->y.p.whole);
        o->unk8C = (u8)(o->unk38 + 0x40);
        o->unk38 = *(u8 *)&o->unk38;
        n = allocObjectLayer2();
        if (n) {
            u8 f;
            n->active = 2;
            n->type = 0x4b;
            f = o->unkF;
            n->unkA = 10;
            n->subtype = 0;
            n->unkC = 0;
            n->unkA5 = 0;
            n->unkA6 = 0;
            n->unkA7 = 0;
            n->velX = 0x50;
            n->unkF = f - 4;
            n->unk8C = o->unk8C;
            n->x.p.whole = o->x.p.whole;
            n->y.p.whole = o->y.p.whole - 10;
            n->z.p.whole = o->z.p.whole;
            o->unk94 = (s32)n;
        }
        o->active = 1;
        break;
    case 2:
        func_80022E44(o);
        p = (GameObject *)o->unk94;
        {
            s32 i = o->unk38;
            s16 v = o->velH;
            s32 a = v * D_8007DB88[i];
            s32 b = v * D_8007D788[i];
            o->h->raw += (a << 4 >> 16) << 8;
            o->y.raw += (b << 4 >> 16) << 8;
        }
        p->h->p.whole = o->h->p.whole;
        p->y.p.whole = o->y.p.whole - 10;
        s = 2;
        if (((o->unk38 - 0x40) & 0xff) > 0x80) s = 1;
        if ((o->touchFlag = Chk_230A8(o, s)) != 0) {
            o->active = 2;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
            break;
        }
        if (o->y.p.whole > D_800A38EA + 0x98 || Out_230A8(o)) {
            o->active = 2;
            o->state = 3;
            p->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_801234A0);


extern u8 D_80125A34[];
extern void *D_8012934C[];
extern void playSFX(s32);
extern s32 tickAnimation(GameObject *);

#define SFX() do { s32 c = 0xda; if (GAME.selectedSection == 7) c = 0xf2; playSFX(c); } while (0)

void func_801234A0(GameObject *o)
{
    u8 *t;
    s32 a;

    switch (o->state) {
    case 0:
        o->state++;
        t = &D_80125A34[o->subtype * 2];
        {
        s32 b;
        a = t[0];
        o->hitOffsetX = a;
        a <<= 1;
        o->hitWidth = a;
        b = t[1];
        o->hitOffsetY = b;
        b <<= 1;
        o->hitHeight = b;
        o->tpage = 1;
        o->unk84 = 0;
        o->unk88 = 0;
        }
        if (o->unkC == 1) {
            o->unkD = 0;
            o->cooldownTimer = 0;
            SFX();
            o->cooldownTimer++;
        } else {
            o->unkD = 0x80;
        }
        o->spriteBank = SCRATCHPAD.sprData[5];
        o->anim = D_8012934C[o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        switch (o->subtype) {
        case 0:
            if (D_8009BC98.unk12 == 1) goto cull;
            func_80022E44(o);
            tickAnimation(o);
            break;
        case 1:
            if (D_8009BC98.unk12 == 1) {
            cull:
                func_80022E44(o);
                break;
            }
            if (!(o->cooldownTimer & 0x3f)) {
                SFX();
            }
            o->cooldownTimer++;
            func_801230A8(o);
            break;
        case 2:
            func_80122DF0(o);
            break;
        }
        break;
    case 2:
        if (o->subtype == 0) {
            func_80022E44(o);
            if (D_8009BC98.unk12) break;
            tickAnimation(o);
            o->velX -= 4;
            if (o->velX <= 0) {
                o->velX = 0;
                o->state++;
            }
        } else if (o->subtype != 1) {
            o->state++;
        } else {
            o->state++;
            ((GameObject *)o->unk94)->state = 2;
            func_80122A74(o);
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef SFX

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123760);
extern GameObject *allocObjectLayer2(void);

s32 func_80123760(GameObject *o, u8 k)
{
    GameObject *n = allocObjectLayer2();
    s32 x;

    if (n != 0) {
        n->active = 1;
        n->type = 0x4f;
        n->subtype = 0;
        n->unkC = 0;
        if (o->animFrame & 1) {
            x = o->x.p.whole - 0x10;
        } else {
            x = o->x.p.whole + 0x10;
        }
        n->x.raw = x << 16;
        n->y.raw = (o->y.p.whole - 4) << 16;
        n->z.raw = o->z.p.whole << 16;
        n->unk8C = k;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123814);


extern void *D_80129398;
extern void func_801163EC(GameObject *, s32);
extern s16 probeCollisionAtDepthB(GameObject *, s32, s32);

static __inline__ void setup_23814(GameObject *p)
{
    p->spriteBank = SCRATCHPAD.sprData[5];
    p->unkAC = 0;
    p->anim = D_80129398;
    readAnimFrameCount(p);
}

static __inline__ s16 out_23814(GameObject *o)
{
    if (o->h->p.whole < D_800A38E4 - 0xa0) return 1;
    if (D_800A38E6 + 0xa0 < o->h->p.whole) return 1;
    if (D_800A38EA + 0x78 < o->y.p.whole) return 1;
    return o->y.p.whole < D_800A38E8 - 0x78;
}

void func_80123814(GameObject *o)
{
    u8 t = o->state;
    s32 r;
    s16 k;
    s32 a, v, x, y;

    switch (t) {
    case 0:
        o->state = t + 1;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitHeight = 0x10;
        *(s8 *)&o->unkF = -9;
        o->unkA = 2;
        o->hitOffsetY = 8;
        o->unk84 = 0;
        o->unk88 = 0;
        o->tpage = 1;
        o->animFrame = 1;
        o->unkD = 0;
        setup_23814(o);
        break;
    case 1:
        if (D_8009BC98.unk12 == 1) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            o->velH = 0x80;
            o->velX = 8;
            o->subState++;
            if (GAME.selectedSection != 7) func_801163EC(o, 1);
            o->timer = 6;
            break;
        case 1:
            if (--o->timer == -1) {
                o->timer = (nextRandom() & 3) + 6;
                r = nextRandom() & 3;
                k = r;
                if (r == 0) k = 2;
                if (GAME.selectedSection != 7) func_801163EC(o, k);
            }
            a = o->unk8C;
            v = o->velH;
            x = v * D_8007DB88[a];
            y = v * D_8007D988[a];
            o->h->raw += ((x << 4) >> 16) << 8;
            o->y.raw += ((y << 4) >> 16) << 8;
            o->velH += o->velX;
            if (o->velH > 0x300) o->velH = 0x300;
            if (o->velH > 0x140) o->velX = 0x10;
            if (probeCollisionAtDepthB(o, o->h->p.whole, o->y.p.whole)) {
                o->active = 2;
                o->state = 2;
                o->subState = 0;
                o->step = 0;
            } else if (out_23814(o)) {
                o->active = 2;
                o->state = 3;
            }
            break;
        }
        tickAnimation(o);
        break;
    case 2:
        func_801163EC(o, 0);
        o->state++;
        func_80022E44(o);
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123B8C);
extern GameObject *allocObjectLayer2(void);

s32 func_80123B8C(GameObject *o, u8 sub, u8 k)
{
    GameObject *n = allocObjectLayer2();
    s32 x;

    if (n != 0) {
        n->active = 1;
        n->type = 0x50;
        n->subtype = sub;
        n->unkC = 0;
        n->unkB4 = k;
        if (o->animFrame & 1) {
            x = o->x.p.whole - 0x20;
        } else {
            x = o->x.p.whole + 0x20;
        }
        n->x.raw = x << 16;
        n->y.raw = (o->y.p.whole - 4) << 16;
        n->z.raw = o->z.p.whole << 16;
        n->animFrame = o->animFrame & 1;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123C60);
extern s16 D_800A38E4;
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

s32 func_80123C60(GameObject *o)
{
    s16 d;
    s16 f;

    d = 8;
    if (o->velH < 0) {
        d = -8;
        f = 1;
        if (o->h->p.whole < D_800A38E4 - 0x98) {
            o->h->p.whole = D_800A38E4 - 0x98;
            return 1;
        }
    } else {
        f = 0;
        if (D_800A38E6 + 0x98 < o->h->p.whole) {
            o->h->p.whole = D_800A38E6 + 0x98;
            return 1;
        }
    }
    return func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f) != 0;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123D14);

extern u8 D_80125A3C[];
extern u8 D_80125A4C[];

static __inline__ s32 Near_23D14(GameObject *o, s32 r, s16 lim)
{
    if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + r) > lim) return 0;
    return (u16)(o->y.p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) + r) <= lim;
}

s32 func_80123D14(GameObject *o)
{
    if (Near_23D14(o, 0x40, 0x80)) return D_80125A3C[nextRandom() & 0xf];
    if (Near_23D14(o, 0x80, 0x100)) return D_80125A4C[nextRandom() & 0xf];
    return 0;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_80123E14);

extern s16 D_80125A5C[];
extern s16 probeCollisionAtDepthA(GameObject *o, s16 x, s16 y);

static __inline__ s32 land_23E14(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 10)) {
        o->unkAE = SCRATCHPAD.unk284;
        o->unkB2 = D_1F80027E;
        return 1;
    }
    if (func_80043AB0(o, o->h->p.whole - 8, o->y.p.whole, 1)) return 0;
    func_80043AB0(o, o->h->p.whole + 8, o->y.p.whole, 0);
    return 0;
}

void func_80123E14(GameObject *o)
{
    s16 *e;
    s16 v;

    switch (o->subState) {
    case 0:
        { s32 ix;
        o->subState++;
        ix = *(u16 *)&o->unkB4 << 2;
        ix += (s32)D_80125A5C;
        o->velH = *(s16 *)ix;
        ix += 2;
        o->velV = *(s16 *)ix;
        }
        if (o->animFrame) o->velH = -o->velH;
        break;
    case 1:
        o->x.raw += o->velH << 8;
        if (func_80123C60(o)) o->velH = 0;
        o->velV += 0x20;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->touchFlag = 0;
            o->unk9C = 2;
            o->subState++;
        }
        break;
    case 4:
        v = o->velH;
        if (v < 0) {
            o->velH = v + 0x30;
            if (o->velH >= 0) o->velH = 0;
        } else {
            o->velH = v - 0x30;
            if (o->velH <= 0) o->velH = 0;
        }
    case 2:
        o->x.raw += o->velH << 8;
        if (func_80123C60(o)) o->velH = 0;
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->unkB2 = 0;
        o->y.raw += o->velV << 8;
        if (land_23E14(o)) {
            if (o->unkAE == 1 || func_80123D14(o)) {
                o->active = 2;
                o->state = 2;
                o->subState = 0;
                o->step = 0;
            } else if (GAME.selectedSection != 7) {
                o->subState = 3;
                o->velH = 0;
                o->velV = 0;
            } else {
                o->active = 2;
                o->state = 2;
                o->subState = 0;
                o->step = 0;
            }
        }
        break;
    case 3:
        o->y.p.whole += 3;
        o->unkB2 = 0;
        if (land_23E14(o)) {
            if (o->unkB2) {
                if (o->unkB2 > 0) {
                    o->velH += 0x38;
                    if (o->velH > 0x400) o->velH = 0x400;
                } else {
                    o->velH -= 0x38;
                    if (o->velH < -0x400) o->velH = -0x400;
                }
            }
            o->x.raw += o->velH << 8;
            if (func_80123C60(o)) o->velH = 0;
        } else {
            o->subState = 4;
            o->y.p.whole -= 3;
        }
        break;
    }
    if (o->velH < 0) o->unk8C += 0x10;
    else o->unk8C -= 0x10;
    o->unk8C = *(u8 *)&o->unk8C;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_8012426C);
typedef struct { s16 w0; u16 w2; } AH_2426C;

typedef struct B_2426C { u16 c[4]; } B_2426C;
extern B_2426C D_80125A9C[];
extern B_2426C D_80125A6C[];

void func_8012426C(GameObject *o)
{
    u32 v;
    u16 *p;

    switch (o->subState) {
    case 0:
        if (o->unkC) {
            p = D_80125A9C[0].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p++;
            o->hitHeight = *p;
        }
        if (GAME.selectedSection == 7) playSFX(0xf4);
        else playSFX(0xe4);
        o->subState++;
    case 1:
        if (o->unkC) {
            o->visible = 0;
            o->y.p.whole--;
        } else {
            p = D_80125A6C[((AH_2426C *)o->anim)->w2].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1];
            o->visible = 1;
        }
        if (tickAnimation(o)) {
            o->timer = 0x3c;
            o->subState++;
        }
        break;
    case 2:
        if (o->unkC) {
            o->visible = 1;
            o->anim = 0;
            v = o->unkA5 + 4;
            o->y.p.whole--;
            if (v >= 0x100) *(s8 *)&o->unkA5 = -1;
            else o->unkA5 = v;
            p = D_80125A9C[o->unkA5 >> 4].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1];
        } else {
            o->active = 2;
            o->visible = 1;
            o->velX -= 2;
            if (o->velX <= 0) o->velX = 0;
            v = o->unkA5 + 4;
            if (v >= 0x100) *(s8 *)&o->unkA5 = -1;
            else o->unkA5 = v;
            o->unkA6 = o->unkA5;
        }
        if (--o->timer == -1) {
            o->active = 2;
            o->state = 3;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_12", func_801244F8);


extern void *D_801293AC[];

static __inline__ void setbox_244F8(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a;
    o->hitWidth = b;
    o->hitOffsetY = c;
    o->hitHeight = d;
}

#define SPAWN(o, st, c) { \
    GameObject *e = allocObjectLayer2(); \
    if (e) { \
        e->active = 2; \
        e->type = 0x50; \
        e->subtype = st; \
        e->unkC = c; \
        e->x.raw = o->x.p.whole << 16; \
        e->y.raw = o->y.p.whole << 16; \
        e->z.raw = o->z.p.whole << 16; \
        e->animFrame = o->animFrame & 1; \
    } }

static __inline__ void fin_244F8(GameObject *o, u8 st, u8 n)
{
    SPAWN(o, st, 1);
    o->state = n;
    o->y.p.whole -= 8;
}

static __inline__ void sp2_244F8(GameObject *o, u8 st)
{
    SPAWN(o, st, 0);
    fin_244F8(o, st, 3);
}

void func_801244F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            o->active = 1;
            setbox_244F8(o, 0x10, 0x20, 0x10, 0x20);
            o->unkA = 0;
            o->unkD = 0x80;
            break;
        case 1:
            setbox_244F8(o, 8, 0x10, 10, 0x14);
            o->unkA = 2;
            o->unkD = 0;
            break;
        case 2:
            o->active = 1;
            setbox_244F8(o, 0x10, 0x18, 4, 8);
            o->unkA = 10;
            o->velX = 0xc0;
            o->unkA5 = 0;
            o->unkA6 = 0;
            o->unkA7 = 0;
            o->unkD = 0x80;
            break;
        }
        *(s8 *)&o->unkF = -12;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->tpage = 1;
        o->state++;
        o->spriteBank = SCRATCHPAD.sprData[5];
        o->anim = D_801293AC[o->subtype];
        readAnimFrameCount(o);
        break;
    case 1:
        switch (o->subtype) {
        case 0:
            if (D_8009BC98.unk12 == 1) goto anim;
            if (!tickAnimation(o)) goto anim;
            o->y.p.whole += 8;
            sp2_244F8(o, 2);
            goto anim;
        case 1:
            if (D_8009BC98.unk12 != 1) func_80123E14(o);
            goto anim;
        case 2:
            if (D_8009BC98.unk12 == 1) {
                if (o->visible == 1) func_80022E44(o);
            } else {
                func_8012426C(o);
                if (o->visible == 1) goto anim;
            }
            break;
        }
        break;
    case 2:
        if (D_8009BC98.unk12 == 1) {
        anim:
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        if (o->subtype == 1) {
            SPAWN(o, 0, 0);
            o->state++;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef SPAWN
