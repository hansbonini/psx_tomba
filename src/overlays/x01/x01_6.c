#include "common.h"
#include "game.h"
#include "x01.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_8012F908);

typedef struct { s16 w0, w2, w4, w6, w8; } S_2F908;
extern s16 func_80043AB0(GameObject *, s16, s16, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

static __inline__ s16 side_2F908(GameObject *o)
{
    GameObject *p;
    s16 d;
    s32 f;

    if (o->unkB6) {
        if (o->unkB0 == 0) {
            if (o->animFrame & 1) goto neg;
            goto pos;
        } else {
            if (o->animFrame & 1) goto pos;
            goto neg;
        }
    }
    if (o->unk8C & 0x80) {
    neg:
        d = -0x10;
        f = 1;
        p = o;
    } else {
    pos:
        d = 0x10;
        f = 0;
        p = o;
    }
    return func_80043AB0(p, o->h->p.whole + d, o->y.p.whole, f);
}
static __inline__ s32 land_2F908(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->unk84 = (-SCRATCHPAD.unk27E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_8012F908(GameObject *o)
{
    S_2F908 *p;
    s32 t, k, dy, dx;

    tickAnimation(o);
    p = (S_2F908 *)&o->unkB4;
    switch (o->step) {
    case 0:
        if (p->w2) {
            if (o->unkB0 == 0) goto five;
        } else if (o->unkB0) {
            goto five;
        }
        o->step++;
        break;
    five:
        o->step = 5;
        break;
    case 1:
        k = 0xc0;
        if (o->animFrame & 1) {
            t = o->unk8C - 2;
        } else {
            k = 0x40;
            t = o->unk8C + 2;
        }
        t &= 0xff;
        o->unk8C = t;
        if (t == k) o->step++;
    case 2:
        if (o->unk8C & 0x80) {
            if (o->animFrame & 1) {
                dy = -0x100;
                o->unkB0 = 0;
            } else {
                dy = 0x100;
                o->unkB0 = 1;
            }
            dx = -0x300;
        } else {
            if (o->animFrame & 1) {
                dy = 0x100;
                o->unkB0 = 1;
            } else {
                dy = -0x100;
                o->unkB0 = 0;
            }
            dx = 0x300;
        }
        o->y.raw += dy << 8;
        o->h->raw += dx << 8;
        if (!side_2F908(o)) {
            if (o->unkB0 & 1) {
                o->timer = 0x10;
                o->step = 6;
            } else {
                o->step = 3;
            }
            break;
        }
        if (o->unkB0 & 1) {
            if (!probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) break;
            p->w2 = 0;
            o->timer = 0x10;
            o->step = 4;
        } else {
            if (!func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) break;
            p->w2 = 1;
            o->timer = 0x10;
            o->step = 4;
        }
        break;
    case 3:
        applyTableVelocityX(o, D_80077214);
        o->y.raw += -0xc000;
        if (o->animFrame & 1)
            o->unk8C += 2;
        else
            o->unk8C -= 2;
        o->unk8C = *(u8 *)&o->unk8C;
        if (land_2F908(o)) {
            o->subState = 1;
            o->step = 0;
            o->unk8C = o->unk84;
        }
        break;
    case 4:
        if (p->w2) {
            o->movetab = D_80077208;
            applyAnimVelocityX(o, (u16)(1 - o->animFrame));
            o->y.raw += -0x10000;
            if (o->animFrame & 1)
                o->unk8C -= 4;
            else
                o->unk8C += 4;
            o->unk8C = *(u8 *)&o->unk8C;
            if (o->timer) o->timer--;
            if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
                o->unk84 = ((-SCRATCHPAD.unk27E << 2) + 0x80) & 0xff;
                if (o->timer == 0 || o->unk8C == o->unk84) {
                    o->subState = 3;
                    o->step = 0;
                }
            } else if (o->timer == 0) {
                o->subState = 3;
                o->step = 0;
            }
        } else {
            applyTableVelocityX(o, D_80077214);
            o->y.raw += 0xc000;
            land_2F908(o);
            if (o->animFrame & 1) {
                o->unk8C = (o->unk8C - 2) & 0xff;
                if (o->unk8C == 0x80) {
                    o->subState = 1;
                    o->step = 0;
                }
            } else {
                o->unk8C = (o->unk8C + 2) & 0xff;
                if (o->unk8C == 0) {
                    o->subState = 1;
                    o->step = 0;
                }
            }
        }
        break;
    case 5:
        if (o->animFrame & 1)
            o->unk8C += 2;
        else
            o->unk8C -= 2;
        o->unk8C = *(u8 *)&o->unk8C;
        if (p->w2) {
            o->movetab = D_80077214;
            applyAnimVelocityX(o, (u16)(1 - o->animFrame));
            o->y.p.whole--;
        } else {
            applyTableVelocityX(o, D_80077214);
            o->y.p.whole++;
        }
        if (side_2F908(o)) {
            o->step = 2;
            if (p->w2) {
                p->w2 = 0;
                if (o->animFrame & 1)
                    o->unk8C = 0xc0;
                else
                    o->unk8C = 0x40;
            } else {
                if (o->animFrame & 1)
                    o->unk8C = 0x40;
                else
                    o->unk8C = 0xc0;
            }
        }
        break;
    case 6:
        o->movetab = D_80077208;
        applyAnimVelocityX(o, (u16)(1 - o->animFrame));
        o->y.raw += 0xc000;
        if (o->animFrame & 1)
            o->unk8C -= 4;
        else
            o->unk8C += 4;
        o->unk8C = *(u8 *)&o->unk8C;
        if (o->timer) o->timer--;
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            o->unk84 = ((-SCRATCHPAD.unk27E << 2) + 0x80) & 0xff;
            if (o->timer == 0 || o->unk8C == o->unk84) {
                o->subState = 3;
                o->step = 0;
            }
        } else if (o->timer == 0) {
            o->subState = 3;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801300FC);

extern void applyAnimVelocityX(GameObject *, u16);

void func_801300FC(GameObject *o)
{
    s16 d;

    switch (o->step) {
    case 0:
        o->movetab = D_8007725C;
        o->unkB6 = 1;
        o->step++;
    case 1:
        tickAnimation(o);
        if (o->y.p.whole < -0x5d5 && o->h->p.whole < 0x725) {
            o->subState = 4;
            o->step = 0;
            break;
        }
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->y.p.whole -= 3;
        d = 0x10;
        if (o->animFrame & 1) d = -0x10;
        if (((s16 (*)(GameObject *, s16, s16, s16))func_80043AB0)(o, o->h->p.whole + d, o->y.p.whole, o->animFrame)) {
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 1;
        } else if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            o->unk8C = (-SCRATCHPAD.unk27E * 4 + 0x80) & 0xff;
        } else {
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130284);

static __inline__ s32 land_30284(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->unk84 = (-SCRATCHPAD.unk27E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_80130284(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unkB6 = 0;
        o->velV = 0;
        o->step++;
        break;
    case 1:
        o->unk8C += 8;
        if (o->unk8C > 0x100) {
            o->unk8C = 0;
            o->step++;
        }
    case 2:
        tickAnimation(o);
        o->velV += 0x30;
        if (o->velV > 0x400) {
            o->velV = 0x400;
        }
        o->y.raw += o->velV << 8;
        if (land_30284(o)) {
            o->subState = 1;
            o->step = 0;
            o->animFrame = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801303D4);



static __inline__ s32 land_303D4(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->unk84 = (-SCRATCHPAD.unk27E << 2) & 0xff;
        return 1;
    }
    return 0;
}

static __inline__ void setAnim_303D4(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_801303D4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->h->p.whole = 0x542;
        o->y.p.whole = -0x615;
        o->animFrame = 1;
        o->unk8C = 0;
        o->timer = 10;
        o->unkAC = 0;
        o->step++;
        o->anim = D_8013DAB8[0];
        readAnimFrameCount(o);
    case 1:
        if (--o->timer == -1) {
            o->unkAC = 4;
            o->step++;
            setAnim_303D4(o, D_8013DAC8[0]);
        }
        break;
    case 2:
        tickAnimation(o);
        if (--o->y.p.whole < -0x6dd) {
            o->y.p.whole = -0x6dc;
            o->unkAC = 3;
            o->step++;
            setAnim_303D4(o, D_8013DAC4[0]);
        }
        break;
    case 3:
        tickAnimation(o);
        applyFrameVelocityXY(o);
        land_303D4(o);
        if (o->h->p.whole < 0x4fe) o->step++;
        break;
    case 4:
        o->animFrame = 0;
        o->y.p.whole += 4;
        land_303D4(o);
        o->unkAC = 0;
        o->unk8C = o->unk84;
        o->step++;
        setAnim_303D4(o, D_8013DAB8[0]);
        { u8 *c = &D_8009C068.unk57f; *c = *c + 0xfe; }
        break;
    case 5:
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130630);


void func_80130630(GameObject *o)
{
    s32 d;

    switch (o->state) {
    case 0:
        d = SCRATCHPAD.sprData[3];
        o->tpage = 0x12;
        o->unkD = 1;
        o->clut = 0x7813;
        o->spriteBank = d;
        o->unkF = (*(GameObject *)&PLAYER).unkF + 1;
        o->unk68 = 0;
        o->unkB6 = 0;
        o->unkB4 = 0;
        o->unk8C = 0;
        o->unk84 = 0;
        o->hitOffsetX = 0x18;
        o->hitWidth = 0x30;
        o->hitOffsetY = 0x18;
        o->hitHeight = 0x30;
        o->state++;
        o->unkAC = 0;
        o->anim = D_8013DAB8[0];
        readAnimFrameCount(o);
        switch (D_8009C068.event_B5) {
        case 1:
        case 3:
            o->subState = 0;
            break;
        case 2:
            o->subState = 1;
            break;
        }
        break;
    case 1:
        if (o->subtype) {
            func_80022E44(o);
            switch (o->subState) {
            case 0:
                func_8012F5D0(o);
                break;
            case 1:
                func_8012F758(o);
                break;
            case 2:
                func_8012F908(o);
                break;
            case 3:
                func_801300FC(o);
                break;
            case 4:
                func_80130284(o);
                break;
            case 5:
                func_801303D4(o);
                break;
            }
        } else {
            func_80022E44(o);
            switch (o->subState) {
            case 0:
                if (o->step == 0) {
                    o->anim = D_8013DAB8[0];
                    readAnimFrameCount(o);
                    o->y.p.whole += 4;
                    if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) {
                        o->unk84 = (-SCRATCHPAD.unk27E << 2) & 0xff;
                    }
                    o->step++;
                }
                break;
            case 1:
                func_8012F284(o);
                break;
            case 3:
                func_8012F44C(o);
                break;
            }
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130914);

extern void spawnItem(s32, s32, Fix16 *);

void func_80130914(GameObject *o)
{
    Fix16 v[3];
    GameObject *n;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 8;
        o->unkD = 0x80;
        o->anim = D_8013BCB4[o->subtype][0];
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->hitOffsetX = 0xb;
        o->hitWidth = 0x16;
        o->hitOffsetY = 0x10;
        o->hitHeight = 0x20;
        readAnimFrameCount(o);
        if (D_8009C068.event_B1 < 3) break;
        o->subtype = 1;
        o->tpage = 7;
        o->unkD = 0;
        v[0].p.whole = o->x.p.whole;
        v[1].p.whole = o->y.p.whole;
        v[2].p.whole = o->z.p.whole;
        if (D_8009C068.event_B1 == 3) spawnItem(0xf, 0, v);
        o->state = 2;
        o->subState = 0;
        o->step = 0;
        break;
    case 1:
        if (!func_80022E44(o)) break;
        tickAnimation(o);
        if (D_8009C068.event_B1 != 2) break;
        n = allocObjectLayer2();
        if (n) {
            n->active = 1;
            n->type = 0xf;
            n->subtype = 1;
            n->x = o->x;
            n->y = o->y;
            n->z = o->z;
            n->tpage = 7;
            n->unkD = 0;
            n->anim = D_8013BCB4[n->subtype][0];
            n->spriteBank = SCRATCHPAD.sprData[3];
            n->hitOffsetX = 0xb;
            n->hitWidth = 0x16;
            n->hitOffsetY = 0x10;
            n->hitHeight = 0x20;
            n->state = 2;
            n->subState = 0;
            n->step = 0;
        }
        D_8009C068.event_B1 = 3;
        o->tpage = 7;
        o->unkD = 0x80;
        o->state = 2;
        o->subState = 0;
        o->step = 0;
        break;
    case 2:
        if (!func_80022E44(o)) break;
        switch (o->subtype) {
        case 0:
            switch (o->step) {
            case 0:
                o->anim = D_8013D9EC;
                readAnimFrameCount(o);
                o->step++;
            case 1:
                if (tickAnimation(o)) o->state = 3;
                break;
            }
            break;
        case 1:
            if (o->step == 0) {
                o->anim = D_8013D9F8;
                readAnimFrameCount(o);
                o->active = 2;
                o->y.p.whole += 8;
                o->step++;
            }
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130C3C);


void func_80130C3C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->hitOffsetX = 8;
        o->unkD = 0;
        o->hitWidth = 0x10;
        o->hitHeight = 0xc;
        o->hitOffsetY = 0;
        o->tpage = 8;
        o->anim = D_8013DA08;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->state++;
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130D00);

typedef struct {
    s32 tag;
    s16 x0, y0;
    s32 c1;
    s16 x1, y1;
    s32 c2;
    s16 x2, y2;
    char pad[0x28 - 0x18];
} P40_30D00;
extern P40_30D00 D_800E3188[];

void func_80130D00(GameObject *o)
{
    GameObject *p;
    P40_30D00 *e;
    s32 n, k;

    switch (o->state) {
    case 0:
        p = (GameObject *)o->unk90;
        o->movetab = ((char *)&D_800771FC);
        o->state++;
        o->x.p.whole = p->x.p.whole;
        o->y.p.whole = p->y.p.whole;
        o->z.p.whole = p->z.p.whole;
        o->unkA0 = *(volatile s32 *)&SCRATCHPAD.wmdData[1] + ((s32 *)*(volatile s32 *)&SCRATCHPAD.wmdData[1])[11];
        o->unkA4 = 1;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->visible == 0)
            break;
        o->visible = 1;
        pushDrawListLayer8(o);
        o->x.p.whole = p->x.p.whole;
        o->y.p.whole = p->y.p.whole;
        o->z.p.whole = p->z.p.whole;
        o->unk8C = p->unk8C;
        break;
    case 2:
        switch (o->subState) {
        case 0:
            o->unkA = 0x12;
            o->unk8C = 0;
            *(P40_30D00 **)&o->unkA8 = D_800E3188;
            o->velV = -0x400;
            func_80028638(o->unkA0, D_800E3188);
            o->timer = 60;
            o->subState++;
        case 1:
            k = 0;
            e = D_800E3188;
            {
                register s32 *dp asm("$4");
                dp = (s32 *)o->unkA0;
                n = dp[4];
            }
            do {
                if (e->x0 < 0) {
                    e->x0--;
                    e->x1--;
                    e->x2--;
                    e->y0 += k >> 16;
                    e->y1 += k >> 16;
                    e->y2 += k >> 16;
                } else {
                    e->x0++;
                    e->x1++;
                    e->x2++;
                    e->y0 += k >> 16;
                    e->y1 += k >> 16;
                    e->y2 += k >> 16;
                }
                k += 0x2000;
                e++;
            } while (--n != 0);
            o->velV += 0x28;
            if (o->velV > 0x400)
                o->velV = 0x400;
            o->y.raw += o->velV << 8;
            if (o->timer >= 0x1e || ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1))
                func_80022E44(o);
            if (--o->timer == -1)
                o->state++;
            break;
        }
        break;
    case 3:
        freeObjectLayer8(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80130FDC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801319D0);

void func_801319D0(s16 x, s16 y, s16 z)
{
    s16 *t = D_8013BCDC;
    s32 i;
    GameObject *o;

    for (i = 0; i < 7; i++) {
        o = allocObjectLayer3();
        if (o != 0) {
            o->active = 2;
            o->type = 0x21;
            o->subtype = i;
            o->h->raw = (x + *t++) << 16;
            o->y.raw = (y + *t++) << 16;
            o->d->raw = z << 16;
        }
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80131A98);

typedef struct { s16 a, b; } S2_31A98;
extern S2_31A98 D_8013BCF8[];

void func_80131A98(GameObject *o)
{
    u8 k;

    switch (o->state) {
    case 0:
        o->state++;
        k = o->subtype;
        *(s8 *)&o->unkF = -20;
        o->unkA = 2;
        o->timer = 0x3c;
        o->movetab = D_80077214;
        o->unk8C = 0;
        o->unkD = 0;
        o->animFrame = 0;
        { S2_31A98 *p = &D_8013BCF8[k]; o->cooldownTimer = p->a; o->velV = p->b; }
        o->tpage = 10;
        o->spriteBank = SCRATCHPAD.sprData[3];
        k = o->subtype;
        o->anim = D_8013DA5C[k];
        readAnimFrameCount(o);
        break;
    case 1:
        o->velV += 0x28;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->cooldownTimer & 1) o->unk8C = (u8)(o->unk8C + 8);
        else o->unk8C = (u8)(o->unk8C - 8);
        if (o->cooldownTimer != 2) applyAnimVelocityX(o, o->cooldownTimer);
        if (o->timer >= 0x1e || ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1)) func_80022E44(o);
        if (--o->timer == -1) o->state = 2;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80131C9C);
s16 func_80131C9C(GameObject *o)
{
    s32 d = o->unk88;
    u8 c = (u32)(d - 0x40) < 0x80;

    if (o->touchFlag != 0) {
        if (c) {
            o->unk88 = d - 0x10;
        } else {
            o->unk88 = d + 0x10;
        }
        o->unk88 = *(u8 *)&o->unk88;
        return 1;
    }
    if (d < 0x81) {
        if (!func_80043AB0(o, o->h->p.whole, o->y.p.whole, c)) goto zero;
        return 2;
    }
    if (func_80043AB0(o, o->h->p.whole, o->y.p.whole, c)) {
        return 2;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole)) goto one;
zero:
    return 0;
one:
    return 1;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80131D74);
void func_80131D74(GameObject *o)
{
    s16 t;

    switch (o->unk7) {
    case 0:
        o->cooldownTimer = 0x10;
        o->unk7++;
    case 1:
        o->unk84 = (o->unk84 + 1) & 0xff;
        if (--o->cooldownTimer == -1) {
            o->cooldownTimer = 0x20;
            o->unk7++;
        }
        break;
    case 2:
        o->unk84 = (o->unk84 - 1) & 0xff;
        if (--o->cooldownTimer == -1) {
            o->cooldownTimer = 0x20;
            o->unk7--;
        }
        break;
    }
    t = o->timer;
    if (t) {
        o->timer = t - 1;
    } else if (o->unk88 == o->unk84) {
        o->unk7 = 0;
        o->step++;
    }
}

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_6", func_80115608);

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_6", jtbl_80115618);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80131E9C);

#define MOVE() \
    o->h->raw += (D_8007DB88[*(u8 *)&o->unk88] * o->velH) >> 4; \
    o->y.raw += (D_8007D988[*(u8 *)&o->unk88] * o->velH) >> 4; \
    o->unkAC = ((o->unk88 + 8) & 0xff) >> 4; \
    o->anim = D_8013E3AC[o->unkAC];

#define TURN3() \
    switch (o->unk7) { \
    case 0: \
        { \
            u8 v = o->unk30 - o->unk88; \
            if (v == 0) o->unk7 = 3; \
            else if (v < 0x80) o->unk7++; \
            else o->unk7 = 2; \
        } \
        break; \
    case 1: \
        o->unk88 = (o->unk88 + 1) & 0xff; \
        if (o->unk88 == o->unk30) o->unk7 = 3; \
        break; \
    case 2: \
        o->unk88 = (o->unk88 - 1) & 0xff; \
        if (o->unk88 == o->unk30) o->unk7 = 3; \
        break; \
    case 3: \
        o->step++; \
        o->unk7 = 0; \
        break; \
    } \
    o->unk84 = o->unk88; \
    MOVE();

#define TURN2(dir) \
    switch (o->unk7) { \
    case 0: \
        if (o->unk30 == o->unk88) o->unk7 = 2; \
        else o->unk7++; \
        break; \
    case 1: \
        o->unk88 = (o->unk88 dir 1) & 0xff; \
        if (o->unk88 == o->unk30) o->unk7 = 2; \
        break; \
    case 2: \
        o->step++; \
        o->unk7 = 0; \
        break; \
    } \
    o->unk84 = o->unk88; \
    MOVE();

void func_80131E9C(GameObject *o)
{
    GameObject *p;
    s32 r;

    switch (o->step) {
    case 0:
        o->active = 1;
        o->unk7A = 0x10;
        o->unk74 = 0x20;
        o->unk84 = 0xc0;
        o->unk88 = 0xc0;
        o->timer = 0x6e;
        o->velH = 0x100;
        o->unk7 = 0;
        o->unk8C = 0;
        o->unkAC = 0xc;
        o->step++;
        o->anim = D_8013E3DC[0];
        readAnimFrameCount(o);
        for (p = (GameObject *)o->unk94; p; p = (GameObject *)p->unk94) {
            p->unk84 = 0xc0;
            p->timer = 0x10;
            p->active = 1;
        }
        break;
    case 1:
        func_80131D74(o);
        MOVE();
        break;
    case 2:
        o->unk30 = 0;
        o->step++;
    case 3:
        TURN3();
        break;
    case 4:
        o->timer = -0x1000;
        o->step++;
    case 5:
        func_80131D74(o);
        MOVE();
        if (o->h->p.whole >= 0x551) {
            if (o->y.p.whole < -0x140) o->step = 0x15;
            else o->step = 0x1b;
            o->unk7 = 0;
        }
        r = ((s32 (*)(GameObject *))func_80131C9C)(o);
        if (r == 1) {
            o->step = 6;
            o->unk7 = 0;
        } else if (r == 2) {
            if (o->y.p.whole < -0x140) o->step = 0x15;
            else o->step = 0x1b;
            o->unk7 = 0;
        }
        break;
    case 6:
        o->unk30 = (o->unk88 + 0x10) & 0xff;
        o->step++;
    case 7:
        TURN3();
        break;
    case 8:
        o->timer = -0x1000;
        o->step++;
    case 9:
        func_80131D74(o);
        MOVE();
        if (o->y.p.whole < -0x140) {
            o->step = 0x12;
            o->unk7 = 0;
        }
        break;
    case 10:
        o->unk30 = (o->unk88 - 0x10) & 0xff;
        o->step++;
    case 11:
        TURN3();
        break;
    case 12:
        o->timer = -0x1000;
        o->step++;
    case 13:
        func_80131D74(o);
        MOVE();
        if (o->y.p.whole < -0x140) {
            o->step++;
            o->unk7 = 0;
        }
        break;
    case 14:
        o->unk30 = 0x80;
        o->step++;
    case 15:
        TURN3();
        break;
    case 16:
        o->timer = -0x1000;
        o->step++;
    case 17:
        func_80131D74(o);
        MOVE();
        if (o->h->p.whole < 0x118) {
            if (o->y.p.whole < -0x140) o->step = 0x18;
            else o->step = 0x12;
            o->unk7 = 0;
        }
        r = ((s32 (*)(GameObject *))func_80131C9C)(o);
        if (r == 1) {
            o->step = 0xa;
            o->unk7 = 0;
        } else if (r == 2) {
            if (o->y.p.whole < -0x140) o->step = 0x18;
            else o->step = 0x12;
            o->unk7 = 0;
        }
        break;
    case 18:
        o->unk30 = 0;
        o->step++;
    case 19:
        TURN2(-);
        break;
    case 20:
        o->step = 4;
        o->unk7 = 0;
        break;
    case 21:
        o->unk30 = 0x80;
        o->step++;
    case 22:
        TURN2(-);
        break;
    case 23:
        o->step = 0x10;
        o->unk7 = 0;
        break;
    case 24:
        o->unk30 = 0;
        o->step++;
    case 25:
        TURN2(+);
        break;
    case 26:
        o->step = 4;
        o->unk7 = 0;
        break;
    case 27:
        o->unk30 = 0x80;
        o->step++;
    case 28:
        TURN2(+);
        break;
    case 29:
        o->step = 0x10;
        o->unk7 = 0;
        break;
    }
}
#undef MOVE
#undef TURN3
#undef TURN2

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80132814);

#define MOVE() \
    o->h->raw += (D_8007DB88[*(u8 *)&o->unk88] * o->velH) >> 4; \
    o->y.raw += (D_8007D988[*(u8 *)&o->unk88] * o->velH) >> 4; \
    o->unkAC = ((o->unk88 + 8) & 0xff) >> 4; \
    o->anim = D_8013E3AC[o->unkAC];

void func_80132814(GameObject *o)
{
    GameObject *p;

    switch (o->step) {
    case 0:
        o->active = 1;
        o->unk7A = 0x10;
        o->unk74 = 0x20;
        o->unk84 = 0xc0;
        o->unk88 = 0xc0;
        o->timer = 0x3c;
        o->velH = 0x100;
        o->unk7 = 0;
        o->unk8C = 0;
        o->unkAC = 0xc;
        o->step++;
        o->anim = D_8013E3DC[0];
        readAnimFrameCount(o);
        for (p = (GameObject *)o->unk94; p; p = (GameObject *)p->unk94) {
            p->unk84 = 0xc0;
            p->timer = 0x10;
            p->active = 1;
        }
        break;
    case 1:
        func_80131D74(o);
        MOVE();
        break;
    case 2:
        o->unk30 = 0;
        o->step++;
    case 3:
        switch (o->unk7) {
        case 0:
            {
                u8 v = o->unk30 - o->unk88;
                if (v == 0) o->unk7 = 3;
                else if (v < 0x80) o->unk7++;
                else o->unk7 = 2;
            }
            break;
        case 1:
            o->unk88 = (o->unk88 + 1) & 0xff;
            if (o->unk88 == o->unk30) o->unk7 = 3;
            break;
        case 2:
            o->unk88 = (o->unk88 - 1) & 0xff;
            if (o->unk88 == o->unk30) o->unk7 = 3;
            break;
        case 3:
            o->step++;
            o->unk7 = 0;
            break;
        }
        o->unk84 = o->unk88;
        MOVE();
        break;
    case 4:
        o->timer = -0x1000;
        o->step++;
    case 5:
        func_80131D74(o);
        MOVE();
        if (o->h->p.whole >= 0x551) {
            o->step++;
            o->unk7 = 0;
        }
        break;
    case 6:
        o->unk30 = 0x80;
        o->step++;
    case 7:
        switch (o->unk7) {
        case 0:
            if (o->unk30 == o->unk88) o->unk7 = 2;
            else o->unk7++;
            break;
        case 1:
            o->unk88 = (o->unk88 - 1) & 0xff;
            if (o->unk88 == o->unk30) o->unk7 = 2;
            break;
        case 2:
            o->step++;
            o->unk7 = 0;
            break;
        }
        o->unk84 = o->unk88;
        MOVE();
        break;
    case 8:
        o->unk30 = 0x80;
        o->step++;
    case 9:
        switch (o->unk7) {
        case 0:
            if (o->unk30 == o->unk88) o->unk7 = 2;
            else o->unk7++;
            break;
        case 1:
            o->unk88 = (o->unk88 + 1) & 0xff;
            if (o->unk88 == o->unk30) o->unk7 = 2;
            break;
        case 2:
            o->step++;
            o->unk7 = 0;
            break;
        }
        o->unk84 = o->unk88;
        MOVE();
        break;
    case 10:
        o->timer = -0x1000;
        o->step++;
    case 11:
        func_80131D74(o);
        MOVE();
        if (o->h->p.whole < 0x118) {
            o->step++;
            o->unk7 = 0;
        }
        break;
    case 12:
        o->unk30 = 0;
        o->step++;
    case 13:
        switch (o->unk7) {
        case 0:
            if (o->unk30 == o->unk88) o->unk7 = 2;
            else o->unk7++;
            break;
        case 1:
            o->unk88 = (o->unk88 - 1) & 0xff;
            if (o->unk88 == o->unk30) o->unk7 = 2;
            break;
        case 2:
            o->step++;
            o->unk7 = 0;
            break;
        }
        o->unk84 = o->unk88;
        MOVE();
        break;
    }
}
#undef MOVE

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80132D5C);
void func_80132D5C(GameObject *o)
{
    u8 d;
    s32 v;
    GameObject *q;
    u16 t, s;

    d = ((GameObject *)o->unk90)->unk84 - o->unk84;
    q = *(GameObject **)&o->unkA8;
    t = q->unk7A;
    s = q->unk74;
    if (d == 0) o->step = 0;
    switch (o->step) {
    case 0:
        if (d) {
            if (d < 0x80) o->step = 1;
            else o->step = 2;
            o->timer = t;
        }
        return;
    case 1:
        if (d >= 0x80) {
            o->step = 2;
            o->unk84 = (u8)(o->unk84 - 1);
            return;
        } else if (o->timer) {
            s16 k = s;
            o->timer--;
            if (k < d) {
                v = ((GameObject *)o->unk90)->unk84 - k;
                o->timer = 0;
            } else return;
        } else {
            o->unk84 = (u8)(o->unk84 + 1);
            return;
        }
        break;
    case 2:
        if (d < 0x80) {
            o->step = 1;
            o->unk84 = (u8)(o->unk84 + 1);
            return;
        } else if (o->timer) {
            s16 k = s;
            o->timer--;
            if (d < 0x100 - k) {
                v = ((GameObject *)o->unk90)->unk84 + k;
                o->timer = 0;
            } else return;
        } else {
            v = o->unk84 - 1;
        }
        break;
    default:
        return;
    }
    o->unk84 = (u8)v;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80132EDC);

#define NEXT(o) (*(GameObject **)&(o)->unk94)


void func_80132EDC(GameObject *o)
{
    GameObject *n;

    switch (o->step) {
    case 0:
        o->velY = 0x10;
        o->step++;
        o->velV = 0;
        if (o->animFrame & 1) {
            o->velH = -0x400;
            o->velX = -0x20;
        } else {
            o->velH = 0x400;
            o->velX = 0x20;
        }
        o->unk84 = o->unk88;
        o->d->p.whole = (u16)SCRATCHPAD.unk168[5].p.whole;
        break;
    case 1:
        o->timer = 300;
        o->unk7A = 8;
        o->unk7 = 0;
        o->unk6A = 1;
        o->step++;
        o->anim = D_8013E578[0];
        o->unk74 = 0x10;
        readAnimFrameCount(o);
        for (n = NEXT(o); n; n = NEXT(n)) {
            n->unk6A = 1;
            n->anim = D_8013E580[0];
            readAnimFrameCount(n);
        }
    case 2:
        tickAnimation(o);
        for (n = NEXT(o); n; n = NEXT(n)) tickAnimation(n);
        if (o->touchFlag || probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            o->step++;
            break;
        }
        if (o->velH) {
            o->h->raw += (D_8007DB88[*(u8 *)&o->unk88] * o->velH) >> 4;
            o->y.raw += (D_8007D988[*(u8 *)&o->unk88] * o->velH) >> 4;
            o->velH -= o->velX;
        }
        o->y.raw += o->velV << 8;
        if (o->velV < 0x300) o->velV += o->velY;
        break;
    case 3:
        if (o->visible == 0) {
            o->timer = 0;
            o->step++;
            break;
        }
        tickAnimation(o);
        for (n = NEXT(o); n; n = NEXT(n)) tickAnimation(n);
        switch (o->unk7) {
        case 0:
            o->cooldownTimer = 0x10;
            o->unk7++;
        case 1:
            o->unk84 = (o->unk84 + 4) & 0xff;
            if (--o->cooldownTimer == -1) {
                o->cooldownTimer = 0x20;
                o->unk7++;
            }
            break;
        case 2:
            o->unk84 = (o->unk84 - 4) & 0xff;
            if (--o->cooldownTimer == -1) {
                o->cooldownTimer = 0x20;
                o->unk7--;
            }
            break;
        }
        if (o->timer == 0x30) {
            o->anim = D_8013E57C[0];
            readAnimFrameCount(o);
            for (n = NEXT(o); n; n = NEXT(n)) {
                n->anim = D_8013E584[0];
                readAnimFrameCount(n);
            }
        }
        if (--o->timer == -1) o->step++;
        break;
    case 4:
        o->state = 1;
        o->subState = 0;
        o->velH = 0x100;
        if ((u32)(o->unk88 - 0x40) < 0x80) o->step = 0x12;
        else o->step = 0x1b;
        o->unk7A = 0x10;
        o->unk74 = 0x20;
        o->unk7 = 0;
        o->active = 1;
        o->unk6A = 0;
        for (n = NEXT(o); n; n = NEXT(n)) {
            n->active = 1;
            n->unk6A = 0;
            n->anim = D_8013E534[0];
        }
        break;
    }
    if ((u32)(o->unk88 - 0x40) < 0x80) o->animFrame = 1;
    else o->animFrame = 0;
}
#undef NEXT

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801333A8);

void func_801333A8(GameObject *o)
{
    GameObject *p, *e;
    s16 k;

    if (o->step == 0) {
        o->step++;
        o->unk84 = 0;
        spawnItemNotification(2, 6);
        playSFX(0x54);
    }
    o->d->p.whole = (u16)SCRATCHPAD.unk168[5].p.whole;
    k = 0x10;
    if ((u32)((*(GameObject **)&o->unkA8)->unk88 - 0x40) < 0x80) o->animFrame = 1;
    else o->animFrame = 0;
    if (o->unkC == 0) {
        o->unkAC = ((o->unk84 + 8) & 0xff) >> 4;
        o->anim = D_8013E3AC[o->unkAC];
    } else {
        o->unkAC = ((o->unk84 + 8) & 0xff) >> 4;
        o->anim = D_8013E3EC[o->unkAC];
    }
    p = o;
    for (e = (GameObject *)p->unk90; e; e = (GameObject *)e->unk90) {
        e->h->raw = p->h->raw;
        e->y.raw = p->y.raw;
        e->d->p.whole = (u16)SCRATCHPAD.unk168[5].p.whole;
        if ((e->animFrame = o->animFrame) == 0) {
            e->unk84 = (p->unk84 + k) & 0xff;
            e->h->raw += D_8007DB88[e->unk84] * 3 << 6;
            e->y.raw += D_8007D988[(u8)e->unk84] * 3 << 6;
            if (e->unkC == 0) {
                e->unkAC = ((e->unk84 + 8) & 0xff) >> 4;
                e->anim = D_8013E3AC[e->unkAC];
            } else {
                e->unkAC = ((e->unk84 + 8) & 0xff) >> 4;
                e->anim = D_8013E3EC[e->unkAC];
            }
        } else {
            e->unk84 = (p->unk84 - k) & 0xff;
            e->h->raw -= D_8007DB88[e->unk84] * 3 << 6;
            e->y.raw -= D_8007D988[(u8)e->unk84] * 3 << 6;
            if (e->unkC == 0) {
                e->unkAC = ((-e->unk84 - 8) & 0xff) >> 4;
                e->anim = D_8013E3AC[e->unkAC];
            } else {
                e->unkAC = ((-e->unk84 - 8) & 0xff) >> 4;
                e->anim = D_8013E3EC[e->unkAC];
            }
        }
        p = e;
    }
    p = o;
    for (e = (GameObject *)p->unk94; e; e = (GameObject *)e->unk94) {
        e->h->raw = p->h->raw;
        e->y.raw = p->y.raw;
        e->d->p.whole = (u16)SCRATCHPAD.unk168[5].p.whole;
        if ((e->animFrame = o->animFrame) == 0) {
            e->unk84 = (p->unk84 - k) & 0xff;
            e->h->raw -= D_8007DB88[e->unk84] * 3 << 6;
            e->y.raw -= D_8007D988[(u8)e->unk84] * 3 << 6;
            e->unkAC = ((-e->unk84 - 8) & 0xff) >> 4;
            e->anim = D_8013E3EC[e->unkAC];
        } else {
            e->unk84 = (p->unk84 + k) & 0xff;
            e->h->raw += D_8007DB88[e->unk84] * 3 << 6;
            e->y.raw += D_8007D988[(u8)e->unk84] * 3 << 6;
            e->unkAC = ((e->unk84 + 8) & 0xff) >> 4;
            e->anim = D_8013E3EC[e->unkAC];
        }
        p = e;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80133834);

void func_80133834(GameObject *o)
{
    GameObject *p;

    switch (o->step) {
    case 0:
        p = (GameObject *)o->unk90;
        o->step++;
        o->movetab = ((char *)&D_8007722C);
        o->velV = -0x400;
        o->animFrame &= 1;
        o->anim = D_8013E574;
        o->unkA = 2;
        o->unkF -= 30;
        for (; p != 0; p = (GameObject *)p->unk90) {
            p->state = 3;
        }
        for (p = (GameObject *)o->unk94; p != 0; p = (GameObject *)p->unk94) {
            p->state = 3;
        }
        ((struct { char pad[0xa]; s16 n; } *)(*(GameObject **)&D_8009BC98.unk18))->n--;
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400) {
            o->velV = 0x400;
        }
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1) {
        o->unk8C = (u8)(o->unk8C + 0x14);
    } else {
        o->unk8C = (u8)(o->unk8C - 0x14);
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801339AC);
#define Q ((GameObject *)o->unk90)


void func_801339AC(GameObject *o)
{
    GameObject *p;

    switch (o->step) {
    case 0:
        o->step++;
        o->active = 2;
        o->velX = 0x10;
        o->unkF -= 0x1e;
        o->velH = -0x400;
        o->velY = 0x40;
        o->velV = -0x400;
        if (o->unkC == 0) {
            for (p = (GameObject *)o->unk94; p != 0; p = (GameObject *)p->unk94) {
                p->state = 2;
                p->subState = 5;
                p->step = 0;
            }
            playSFX(0x54);
            o->unk84 = o->unk88;
            if ((u32)(o->unk88 - 0x40) < 0x80)
                o->animFrame = 1;
            else
                o->animFrame = 0;
            o->unkAC = ((o->unk88 + 8) & 0xff) >> 4;
            o->anim = D_8013E3AC[o->unkAC];
        } else {
            if ((o->animFrame = Q->animFrame) == 0)
                o->unk84 = (Q->unk84 + 0x10) & 0xff;
            else
                o->unk84 = (Q->unk84 - 0x10) & 0xff;
            o->h->raw = Q->h->raw;
            o->y.raw = Q->y.raw;
            o->d->raw = Q->d->raw;
            o->h->raw -= D_8007DB88[(u8)o->unk84] * 192;
            o->y.raw -= D_8007D988[(u8)o->unk84] * 192;
            o->unkAC = ((o->unk84 + 8) & 0xff) >> 4;
            o->anim = D_8013E3EC[o->unkAC];
        }
        break;
    case 1:
        if (o->velH != 0) {
            if (o->animFrame)
                o->h->raw += o->velH << 8;
            else
                o->h->raw -= o->velH << 8;
            o->velH += o->velX;
        }
        o->y.raw += o->velV << 8;
        o->velV += o->velY;
        if (o->velV > 0x400)
            o->velV = 0x400;
        break;
    }
}
#undef Q

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80133C7C);

void func_80133C7C(GameObject *o)
{
    GameObject *e;

    switch (o->subState) {
    case 0:
        func_80022E44(o);
        if (o->unkC == 0) {
            if (o->unk98 == 0) {
                o->state = 2;
                o->subState = 5;
                o->step = 0;
            } else {
                func_80132EDC(o);
            }
        } else {
            func_80132D5C(o);
            o->d->raw = ((GameObject *)o->unk90)->d->raw;
            o->h->raw = ((GameObject *)o->unk90)->h->raw;
            o->h->raw -= D_8007DB88[*(u8 *)&o->unk84] << 8;
            if (o->touchFlag) {
                o->y.raw = ((GameObject *)o->unk90)->y.raw;
                o->y.raw -= D_8007D988[*(u8 *)&((GameObject *)*(s32 *)&o->unkA8)->unk74] << 8;
            } else {
                o->y.raw = ((GameObject *)o->unk90)->y.raw;
                o->y.raw -= D_8007D988[*(u8 *)&o->unk84] << 8;
            }
            probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole);
        }
        break;
    case 1:
        func_80022E44(o);
        func_801333A8(o);
        break;
    case 2:
        if (func_80022E44(o) == 0) o->state = 3;
        else func_80133834(o);
        break;
    case 3:
        func_80022E44(o);
        break;
    case 4:
        o->state = 3;
        (*(s16 *)&(*(GameObject **)&D_8009BC98.unk18)->unkA)--;
        {
            GameObject *q;
        for (q = (GameObject *)o->unk90; q; q = (GameObject *)q->unk90) q->state = 3;
        for (q = (GameObject *)o->unk94; q; q = (GameObject *)q->unk94) q->state = 3;
        }
        break;
    case 5:
        if (func_80022E44(o) == 0) {
            if (o->unkC == 0) {
                o->state = 3;
                for (e = (GameObject *)o->unk94; e; e = (GameObject *)e->unk94) e->state = 3;
                (*(s16 *)&(*(GameObject **)&D_8009BC98.unk18)->unkA)--;
            }
        } else {
            func_801339AC(o);
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80133F38);


typedef struct {
    GameObject t;
    char pad[0xd2 - 0xc0];
    s16 wd2;
} P_33F38;
extern s32 func_80022F6C(P_33F38 *);

void func_80133F38(P_33F38 *o)
{
    switch (o->t.state) {
    case 0:
        switch (o->t.subState) {
        case 0:
            if (D_8009C608.purifiedAreas & 1) {
                o->t.state = 3;
                break;
            }
            func_80134220(o);
            break;
        case 1:
            if (!func_80022F6C(o)) {
                o->t.subState = 0;
                o->t.state++;
            }
            break;
        }
        break;
    case 1:
        if (D_8009BC98.unk12) {
            func_80022E44(&o->t);
            break;
        }
        if (o->t.unkC == 0) {
            if (o->t.unk9E == 0) {
                switch (o->t.subtype) {
                case 0:
                case 1:
                    func_80131E9C(o);
                    break;
                case 2:
                    func_80131E9C(o);
                    break;
                case 3:
                    func_80131E9C(o);
                    break;
                }
                if ((u32)(o->t.unk88 - 0x40) < 0x80) o->t.animFrame = 1;
                else o->t.animFrame = 0;
            } else if (o->t.unk9F == 0) {
                o->wd2 = o->t.h->p.whole;
                o->t.unk9F = 0xf;
            } else {
                o->t.h->p.whole = (s16)(o->wd2 - 2) + (((s32 (*)(void))nextRandom)() & 3);
                if (--o->t.unk9F == 0) {
                    o->t.unk9E = 0;
                    o->t.h->p.whole = o->wd2;
                }
            }
        } else {
            func_80132D5C(o);
            o->t.h->raw = ((GameObject *)o->t.unk90)->h->raw;
            o->t.d->raw = ((GameObject *)o->t.unk90)->d->raw;
            o->t.y.raw = ((GameObject *)o->t.unk90)->y.raw;
            o->t.h->raw -= D_8007DB88[*(u8 *)&o->t.unk84] << 8;
            o->t.y.raw -= D_8007D988[*(u8 *)&o->t.unk84] << 8;
        }
        o->t.touchFlag = 0;
        if (!func_80022D3C(o, 0xa0)) {
            if (o->t.y.p.whole >= -0x190) o->t.y.p.whole = -0x190;
        }
        break;
    case 2:
        func_80133C7C(o);
        o->t.touchFlag = 0;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80134220);



void func_80134220(GameObject *o)
{
    GameObject *list[6];
    GameObject *e;
    s16 n;
    s32 i;
    u8 sub;
    u8 t;

    if (o->unkC) return;
    t = o->subtype;
    n = 4;
    if (!t) n = 6;
    if (SCRATCHPAD.freeObjectCount < n - 1) {
        o->state = 3;
        (*(s16 **)&D_8009BC98.unk18)[5]--;
        return;
    }
    list[0] = o;
    sub = t;
    for (i = 1; i < n; i++) list[i] = allocObjectLayer2();
    insertionSortU32(n, list);
    o = list[0];
    o->active = 2;
    o->type = 0x13;
    *(s16 *)((char *)o + 0x1e) = 1;
    o->unkD = 0;
    {
        s32 d = SCRATCHPAD.sprData[8];
        void *an = D_8013E4AC;
        o->subState = 1;
        o->unk98 = 2;
        o->unk9A = 2;
        o->state = 0;
        o->step = 0;
        o->subtype = sub;
        o->unkC = 0;
        o->unk6A = 0;
        o->unk68 = 0;
        o->touchFlag = 0;
        o->objectIndex = 0;
        o->animFrame = 0;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->unk90 = 0;
        o->spriteBank = d;
        o->anim = an;
    }
    o->unk94 = (s32)list[1];
    for (i = 1; i < n; i++) {
        e = list[i];
        e->active = 2;
        e->type = 0x13;
        *(s16 *)((char *)e + 0x1e) = 1;
        e->unkD = 0;
        {
            s32 d = SCRATCHPAD.sprData[8];
            void *an = (*(void **)&D_8013E534);
            e->animFrame = 0;
            e->state = 0;
            e->subState = 1;
            e->step = 0;
            e->spriteBank = d;
            e->anim = an;
        }
        e->subtype = o->subtype;
        e->unkC = i;
        e->unkA = o->unkA;
        e->unk6A = 0;
        e->unk68 = 0;
        e->touchFlag = 0;
        e->unk98 = 2;
        e->unk9A = 2;
        e->x.raw = o->x.raw;
        e->y.raw = o->y.raw;
        e->z.raw = o->z.raw;
        e->hitOffsetX = 8;
        e->hitWidth = 0x10;
        e->hitOffsetY = 8;
        e->hitHeight = 0x10;
        *(GameObject **)&e->unkA8 = o;
        e->unk90 = (s32)list[i - 1];
        if (i == n - 1)
            e->unk94 = 0;
        else
            e->unk94 = (s32)list[i + 1];
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_8013449C);

typedef struct { s8 a; u8 b; u8 c; s8 d; } E4_3449C;
extern E4_3449C D_80011F38[];
extern s16 fixedMulCos(s32, s32);
extern s16 fixedMulSin(s32, s32);
extern s32 showMessageBox(s32, s32, s32, s32);

static __inline__ void follow1_3449C(GameObject *o, E4_3449C *e)
{
    register s32 ang asm("$16");
    register s16 dx asm("$19");
    register s16 dy asm("$4");
    u16 u;
    register u32 t asm("$2");

    if ((*(u16 *)&GAME) == 1 && D_8009BCCA < 2)
        o->anim = D_8013D1C4[e->a];
    else
        o->anim = D_8013D170[e->a];
    if (o->animFrame & 1) {
        u = (*(GameObject *)&PLAYER).unk8C + 0x80 - (s8)e->c;
        t = u; t &= 0xff;
    } else {
        u = (s8)e->c + (*(GameObject *)&PLAYER).unk8C;
        t = u; t &= 0xff;
    }
    ang = t; asm("");
    dx = fixedMulCos(ang, e->d);
    dy = fixedMulSin(ang, e->d);
    (*(GameObject *)&PLAYER).unk7A = dy;
    o->h->p.whole = (*(GameObject *)&PLAYER).h->p.whole + dx;
    o->y.p.whole = (*(GameObject *)&PLAYER).y.p.whole + dy;
    o->d->p.whole = (*(GameObject *)&PLAYER).d->p.whole;
    o->unk8C = (*(GameObject *)&PLAYER).unk8C;
    o->unkF = (*(GameObject *)&PLAYER).unkF + e->b;
}

static __inline__ void follow0_3449C(GameObject *o, E4_3449C *e)
{
    register s32 ang asm("$16");
    register s16 dx asm("$19");
    s16 dy;
    u16 u;
    register u32 t asm("$2");

    if ((*(u16 *)&GAME) == 1 && D_8009BCCA < 2)
        o->anim = D_8013D1C4[e->a];
    else
        o->anim = D_8013D170[e->a];
    if (o->animFrame & 1) {
        u = (*(GameObject *)&PLAYER).unk8C + 0x80 - (s8)e->c;
        t = u; t &= 0xff;
    } else {
        u = (s8)e->c + (*(GameObject *)&PLAYER).unk8C;
        t = u; t &= 0xff;
    }
    ang = t; asm("");
    dx = fixedMulCos(ang, e->d);
    dy = fixedMulSin(ang, e->d);
    o->h->p.whole = (*(GameObject *)&PLAYER).h->p.whole + dx;
    o->y.p.whole = (*(GameObject *)&PLAYER).y.p.whole + dy;
    o->d->p.whole = (*(GameObject *)&PLAYER).d->p.whole;
    o->unk8C = (*(GameObject *)&PLAYER).unk8C;
    o->unkF = (*(GameObject *)&PLAYER).unkF + e->b;
}

void func_8013449C(GameObject *o)
{
    E4_3449C *e;
    GameObject *p;

    o->visible = (*(GameObject *)&PLAYER).visible;
    switch (o->step) {
    case 0:
        o->active = 2;
        o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
        o->category |= 0x80;
        e = &D_80011F38[((s8 *)&D_80012014)[*(u16 *)(*(GameObject *)&PLAYER).anim]];
        follow1_3449C(o, e);
        if (D_8009BC98.unk08) break;
        switch (D_8009BCCA) {
        case 1:
            if ((*(GameObject *)&PLAYER).h->p.whole >= 0x1000) break;
            (*(GameObject *)&PLAYER).h->p.whole = 0x1000;
            goto set;
        case 3:
            if ((u16)((*(GameObject *)&PLAYER).y.p.whole + 0x2d6) < 0x48) {
                if ((u16)((*(GameObject *)&PLAYER).h->p.whole - 0x7f0) >= 0x20) break;
                (*(GameObject *)&PLAYER).h->p.whole = 0x7ee;
            } else {
                if ((*(GameObject *)&PLAYER).h->p.whole < 0xad3) break;
                (*(GameObject *)&PLAYER).h->p.whole = 0xad2;
            }
        set:
            D_800A539C = 5;
            D_800A539D = 0;
            D_800A539E = 0;
            o->step = 1;
            break;
        }
        break;
    case 1: {
        register E4_3449C *tb asm("$4") = D_80011F38;
        asm("" : "=r"(tb) : "0"(tb));
        { register s32 ix asm("$3") = ((s8 *)&D_80012014)[*(u16 *)(*(GameObject *)&PLAYER).anim] * 4; e = (E4_3449C *)(ix + (s32)tb); } }
        if (e->a < 2 && (nextRandom() & 3) == 0)
            e->a = nextRandom() & 1;
        follow0_3449C(o, e);
        if ((*(GameObject *)&PLAYER).touchFlag) {
            D_8009BC98.unk12 = 1;
            o->unk90 = showMessageBox(2, 0xc, 0x80, 0x6c);
            o->step = 2;
        }
        break;
    case 2:
        p = (GameObject *)o->unk90;
        if (p->state == 2) {
            p->state = 3;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            D_8009BC98.unk0F = 0;
            D_800A539C = 1;
            D_800A539D = 0;
            D_800A539E = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801349F8);

extern s32 GAME_S32Arr[] asm("GAME");

void func_801349F8(GameObject *o)
{
    GameObject *p;

    o->hitOffsetX = 8;
    o->hitWidth = 0x10;
    o->hitOffsetY = 8;
    o->hitHeight = 0x10;
    if (GAME_S32Arr[0] == 0x20001) o->tpage = 2;
    else o->tpage = 1;
    if (((u16*)&GAME.selectedArea)[0] == 1 && GAME.selectedSection < 2) {
        o->spriteBank = SCRATCHPAD.sprData[2];
        switch (o->subtype) {
        case 2:
            o->anim = D_8013D1B0;
            break;
        case 3:
            o->anim = D_8013D1AC;
            break;
        default:
            o->anim = D_8013D180;
            break;
        }
    } else {
        o->spriteBank = SCRATCHPAD.sprData[7];
        switch (o->subtype) {
        case 2:
            o->anim = D_8013D154;
            break;
        case 3:
            o->anim = D_8013D150;
            break;
        default:
            o->anim = D_8013D0C8;
            break;
        }
    }
    o->unkD = 0;
    o->category |= 0x80;
    readAnimFrameCount(o);
    o->state++;
    if ((D_8009C608.unk960 >> (o->unkC - 1)) & 1) {
        p = (GameObject *)o->unk94;
        o->state = 3;
        p->state = 3;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80134B88);

void func_80134B88(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (GAME.selectedArea == AREA01_DWARFFOREST && GAME.selectedSection < 2) break;
        switch (o->step) {
        case 0:
            o->timer = 0x3c;
            o->movetab = ((char *)&D_800771FC);
            o->anim = D_8013D168[0];
            readAnimFrameCount(o);
            o->step++;
        case 1:
            tickAnimation(o);
            applyFrameVelocityX(o);
            if (--o->timer <= 0) {
                o->anim = D_8013D16C[0];
                readAnimFrameCount(o);
                o->step++;
            }
            break;
        case 2:
            if (tickAnimation(o)) {
                o->step = 0;
                o->animFrame ^= 1;
            }
            break;
        }
        break;
    case 1:
        if (GAME.selectedArea == AREA01_DWARFFOREST && GAME.selectedSection < 2) break;
        if (o->step == 0) {
            o->objectIndex = o->animFrame;
            o->animFrame = o->h->p.whole > (*(Fix16 **)&PLAYER.obj.h)->p.whole;
            o->anim = D_8013D16C[0];
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80134D4C);
void func_80134D4C(GameObject *o)
{
    s16 i;
    char pad[16];

    i = 0;
    while (((u8 *)&D_8009C068.unk561)[i] && i < 7) i++;
    if (i >= 7) {
        ((u8 *)&D_8009C068.unk561)[o->unkC + 11] = (nextRandom() & 1) - 0x64;
    } else {
        ((u8 *)&D_8009C068.unk561)[o->unkC + 11] = i - 0x6c;
        ((u8 *)&D_8009C068.unk561)[i] = 1;
    }
    for (i = 0; i < 7; i++) {
        if (((u8 *)&D_8009C068.unk561)[i + 12] == o->unkC + 0x93) ((u8 *)&D_8009C068.unk561)[i + 12] = (nextRandom() & 1) - 0x64;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80134E80);

void func_80134E80(GameObject *o)
{
    if (o->unkC != 0) {
        u16 *f = &D_8009C608.unk960;
        *f |= 1 << (o->unkC - 1);
    }
    {
        u8 *c = &D_8009C068.event_11;
        *c = *c + 1;
        if (*c >= 9) *c = 8;
        else printInfoMessage(*c - 1, MSG_TYPE_INFO);
    }
    switch (o->unkC) {
    case 1:
        D_8009C068.unk562 = 1;
        break;
    case 2:
        D_8009C068.unk561 = 1;
        break;
    case 3:
        D_8009C068.unk564 = 1;
        break;
    case 4:
        D_8009C068.unk563 = 1;
        break;
    case 5:
        D_8009C068.unk565 = 1;
        break;
    case 6:
        D_8009C068.unk566 = 1;
        break;
    case 7:
        D_8009C068.unk567 = 1;
        break;
    }
    func_80134D4C(o);
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80134FC8);
extern u16 GAME_U16Arr[] asm("GAME");

void func_80134FC8(GameObject *o)
{
    switch (o->step) {
    case 0:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        o->animFrame = o->h->p.whole > (*(Fix16 **)&PLAYER.obj.h)->p.whole;
        switch (o->subtype) {
        case 2:
        case 3:
            ((GameObject *)o->unk94)->state = 3;
        }
        func_80134E80(o);
        o->active = 4;
        o->movetab = ((char *)&D_800771FC);
        if (GAME_U16Arr[0] == 1 && ((u16 *)&D_8009BCCA)[0] < 2) o->anim = D_8013D184;
        else o->anim = D_8013D128;
        readAnimFrameCount(o);
        {
            s16 v = 0x120;
            o->touchFlag = 0;
            if (o->animFrame & 1) v = -0x120;
            o->velY = -0x100;
            o->timer = 0x3c;
            o->velX = v;
        }
        o->step = 1;
        break;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0) o->step++;
        break;
    case 2:
        if (--o->timer <= 0) o->step++;
        break;
    case 3:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0x500) o->velY = 0x500;
        if (o->touchFlag | probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + (o->hitHeight - o->hitOffsetY))) {
            if (GAME_U16Arr[0] == 1 && ((u16 *)&D_8009BCCA)[0] < 2) o->anim = D_8013D1A4;
            else o->anim = D_8013D140;
            readAnimFrameCount(o);
            { s32 t = (*(Fix16 **)&PLAYER.obj.h)->p.whole < o->h->p.whole;
            o->step++;
            o->animFrame = t; }
        }
        break;
    case 4:
        if (tickAnimation(o)) o->step++;
        break;
    case 5:
        o->active = 4;
        if (GAME_U16Arr[0] == 1 && ((u16 *)&D_8009BCCA)[0] < 2) o->anim = D_8013D184;
        else o->anim = D_8013D128;
        readAnimFrameCount(o);
        switch (((u16 *)&D_8009BCCA)[0]) {
        case 0:
        case 1:
        case 4:
            o->animFrame = 0;
            break;
        case 2:
        case 3:
        case 5:
            o->animFrame = 1;
            break;
        }
        {
            s16 v = 0x200;
            if (o->animFrame & 1) v = -0x200;
            o->velX = v;
            o->velY = -0x300;
            o->step++;
        }
    case 6:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0) o->step++;
        break;
    case 7:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + (o->hitHeight - o->hitOffsetY))) o->step = 5;
        break;
    }
    if (!o->visible) {
        D_8009BC98.unk0E = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0F = 0;
        o->state = 3;
        o->subState = 0;
        o->step = 0;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_8013549C);

void func_8013549C(GameObject *o)
{
    switch (o->step) {
    case 0:
        switch (o->subtype) {
        case 2:
        case 3:
            ((GameObject *)o->unk94)->state = 3;
            break;
        }
        func_80134E80(o);
        o->active = 4;
        if (GAME.selectedArea == AREA01_DWARFFOREST && GAME.selectedSection < 2) o->anim = D_8013D1A4;
        else o->anim = D_8013D140;
        readAnimFrameCount(o);
        o->animFrame = o->h->p.whole > (*(Fix16 **)&PLAYER.obj.h)->p.whole;
        o->timer = 0x3c;
        o->step = 1;
        break;
    case 1:
        if (--o->timer > 0) break;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        o->step++;
        break;
    case 2:
        if (tickAnimation(o)) o->step++;
        break;
    case 3:
        o->active = 4;
        switch (GAME.selectedSection) {
        case 0:
        case 1:
        case 4:
            o->animFrame = 0;
            break;
        case 2:
        case 3:
        case 5:
            o->animFrame = 1;
            break;
        }
        if (GAME.selectedArea == AREA01_DWARFFOREST && GAME.selectedSection < 2) o->anim = D_8013D184;
        else o->anim = D_8013D128;
        readAnimFrameCount(o);
        o->velX = (o->animFrame & 1) ? -0x200 : 0x200;
        o->velY = -0x300;
        o->step++;
    case 4:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0) o->step++;
        break;
    case 5:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + (o->hitHeight - o->hitOffsetY))) o->step = 3;
        break;
    }
    if (!o->visible) {
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        ((u8*)&D_8009BC98.unk0F)[0] = 0;
        ((u8*)&D_8009BC98.unk0E)[0] = 0;
        o->state = 3;
        o->subState = 0;
        o->step = 0;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_801357D4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80135A94);

GameObject *func_80135A94(s16 k, s16 d, s16 n, s16 x, s16 y, s16 z)
{
    GameObject *o;

    if (n != 0) {
    if ((D_8009C608.unk960 >> (n - 1)) & 1) return 0;
    o = allocObjectLayer2();
    if (o != 0) {
    o->active = 1;
    o->type = 0x16;
    o->x.raw = x << 16;
    o->y.raw = y << 16;
    o->z.raw = z << 16;
    o->animFrame = k & 1;
    o->subtype = (k >> 1) + 1;
    o->unk38 = d;
    o->tpage = 1;
    o->unkC = n;
    o->unk8C = 0;
    o->unkD = 0;
    o->unkA = 2;
    if (GAME_U16Arr[0] == 1 && D_8009BCCA < 2) {
        o->spriteBank = SCRATCHPAD.sprData[2];
        o->anim = D_8013D180;
    } else {
        o->spriteBank = SCRATCHPAD.sprData[7];
        o->anim = D_8013D0C8;
    }
    readAnimFrameCount(o);
    return o;
    }
    }
    return 0;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80135C0C);

void func_80135C0C(s16 x, s16 y, s16 z)
{
    GameObject *o = allocObjectLayer2();

    if (o != 0) {
        o->active = 1;
        o->type = 0x16;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->subtype = 0;
        o->tpage = 1;
        o->unk8C = 0;
        if (GAME_U16Arr[0] == 1
 && D_8009BCCA < 2) {
            o->spriteBank = SCRATCHPAD.sprData[2];
            o->anim = D_8013D1B4[0];
        } else {
            o->spriteBank = SCRATCHPAD.sprData[7];
            o->anim = D_8013D15C[0];
        }
        o->unkD = 0;
        o->unkA = 2;
        readAnimFrameCount(o);
        o->state = 2;
        o->subState = 3;
        o->step = 0;
        o->category |= 0x80;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80135D30);


void func_80135D30(GameObject *o)
{
    u8 k = D_8009C068.baronState;

    if (k != 0 && k < 3) {
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 0x18;
        o->hitHeight = 0x20;
        o->unk8C = 0;
        o->tpage = 10;
        o->unkD = 0;
        o->category |= 0x80;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013D8E8[0];
        o->unkA = 2;
        readAnimFrameCount(o);
        *(s8 *)&o->unkF = -10;
        o->state = 1;
    } else {
        o->state = 3;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80135DE4);

void func_80135DE4(void)
{
    s32 a;
    if ((u16)((*(u16 **)&PLAYER.obj.h)[1] - 0x8ae) < 0x200 && (nextRandom() & 0x3f) == 0) {
        if (PLAYER.obj.y.p.whole < -0x190) a = 0x7f;
        else if (PLAYER.obj.y.p.whole < -0xc8) a = 0x70;
        else a = 0x60;
        playSFXWithVolume(0x41, a);
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_6", func_80135E64);
