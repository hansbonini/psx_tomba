#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80055E0C);
static __inline__ s32 hit_55E0C(GameObject *a, GameObject *b)
{
    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) >= 0x5b) return 0;
    if ((u16)(a->h->p.whole - b->h->p.whole + (b->hitOffsetX + (a->hitWidth - a->hitOffsetX))) > b->hitWidth + a->hitWidth) return 0;
    return (u16)(a->y.p.whole - b->y.p.whole + (b->hitOffsetY + (a->hitHeight - a->hitOffsetY))) <= a->hitHeight + b->hitHeight;
}

s32 func_80055E0C(GameObject *a, GameObject *b)
{
    return hit_55E0C(a, b);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80055ED4);
s32 func_80055ED4(GameObject *o, GameObject *p)
{
    char pad;
    s16 dx, wx, px;
    s16 cx;

    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = p->hitOffsetX + (o->hitWidth - o->hitOffsetX);
    px = wx;
    dx = o->h->p.whole - p->h->p.whole;
    if ((u16)(dx + wx) > p->hitWidth + o->hitWidth)
        return 0;
    if ((u16)((o->y.p.whole - p->y.p.whole) + (p->hitOffsetY + (o->hitHeight - o->hitOffsetY))) > o->hitHeight + p->hitHeight)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = o->hitOffsetX + (p->hitWidth - p->hitOffsetX);
        cx = px;
    }
    if ((u16)(cx - dx) < 4) {
        o->h->p.whole = p->h->p.whole + px;
        if (px < 0)
            o->unk9D = 2;
        else
            o->unk9D = 3;
        return 2;
    }
    if (o->unk9C & 1)
        return 0;
    {
        s16 w = p->y.p.whole - (p->hitOffsetY + (o->hitHeight - o->hitOffsetY));
        GameObject *q = o;
        o->y.p.frac = 0;
        o->touchFlag = 1;
        q->y.p.whole = w;
    }
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_8005606C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056284);
s32 func_80056284(GameObject *o, GameObject *p)
{
    char pad;
    s16 dx, wx, px;
    s16 dy, hy, py;
    s16 cx, cy;

    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = p->hitOffsetX + (o->hitWidth - o->hitOffsetX);
    px = wx;
    dx = o->h->p.whole - p->h->p.whole;
    if ((u16)(dx + wx) > p->hitWidth + o->hitWidth)
        return 0;
    dy = o->y.p.whole - p->y.p.whole;
    hy = p->hitOffsetY + (o->hitHeight - o->hitOffsetY);
    py = hy;
    if ((u16)(dy + hy) > o->hitHeight + p->hitHeight)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = o->hitOffsetX + (p->hitWidth - p->hitOffsetX);
        cx = px;
    }
    cy = py;
    if (dy < 0) {
        dy = -dy;
        py = -py;
    } else {
        py = o->hitOffsetY + (p->hitHeight - p->hitOffsetY);
        cy = py;
    }
    if (cx - dx < cy - dy) {
        o->h->p.whole = p->h->p.whole + px;
        if (px < 0)
            o->unk9D = 2;
        else
            o->unk9D = 3;
        return 2;
    }
    if (py <= 0) {
        if (o->unk9C & 1)
            return 0;
        {
            s16 w = p->y.p.whole;
            GameObject *q = o;
            o->y.p.frac = 0;
            o->touchFlag = 1;
            q->y.p.whole = w + py;
        }
        return 1;
    }
    if (o->category == 2 && *(u16 *)&o->state == 0x102)
        return 0;
    o->y.p.whole = p->y.p.whole + py;
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056498);
s32 func_80056498(GameObject *o, GameObject *p)
{
    char pad;
    s16 dx, wx, px;
    s16 dy, hy, py;
    s16 cx, cy;

    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = p->hitOffsetX + (o->hitWidth - o->hitOffsetX);
    px = wx;
    dx = o->h->p.whole - p->h->p.whole;
    if ((u16)(dx + wx) > p->hitWidth + o->hitWidth)
        return 0;
    dy = o->y.p.whole - p->y.p.whole;
    hy = p->hitOffsetY + (o->hitHeight - o->hitOffsetY);
    py = hy;
    if ((u16)(dy + hy) > o->hitHeight + p->hitHeight)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = o->hitOffsetX + (p->hitWidth - p->hitOffsetX);
        cx = px;
    }
    cy = py;
    if (dy < 0) {
        dy = -dy;
        py = -py;
    } else {
        py = o->hitOffsetY + (p->hitHeight - p->hitOffsetY);
        cy = py;
    }
    if (cx - dx < cy - dy) {
        o->h->p.whole = p->h->p.whole + px;
        if (px < 0)
            o->unk9D = 2;
        else
            o->unk9D = 3;
        return 2;
    }
    if (py <= 0) {
        if (o->unk9C & 1)
            return 0;
        if (px < 0)
            o->h->p.whole -= 1;
        else
            o->h->p.whole += 1;
        o->y.p.whole = p->y.p.whole + py;
        o->y.p.frac = 0;
        o->touchFlag = 1;
        return 1;
    }
    if (o->category == 2 && *(u16 *)&o->state == 0x102)
        return 0;
    o->y.p.whole = p->y.p.whole + py;
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_800566E4);
s32 func_800566E4(GameObject *o, GameObject *e)
{
    s16 dx, w, r;
    char pad;
    if ((u16)(o->d->p.whole - e->d->p.whole + 45) > 90)
        return 0;
    dx = o->h->p.whole - e->h->p.whole;
    w = e->hitOffsetX + (o->hitWidth - o->hitOffsetX);
    if ((u16)(dx + w) > e->hitWidth + o->hitWidth)
        return 0;
    if ((u16)(o->y.p.whole - e->y.p.whole + (e->hitOffsetY + (o->hitHeight - o->hitOffsetY))) > o->hitHeight + e->hitHeight)
        return 0;
    if (dx < 0)
        r = -w;
    else
        r = o->hitOffsetX + (e->hitWidth - e->hitOffsetX);
    o->h->p.whole = e->h->p.whole + r;
    o->unk9D = r < 0 ? 2 : 3;
    return 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056804);
s32 func_80056804(GameObject *o, GameObject *p)
{
    s16 w;
    s16 dy;
    s16 t;
    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    if (o->animFrame & 1)
        w = o->hitOffsetX;
    else
        w = o->hitWidth - o->hitOffsetX;
    if ((u16)(o->h->p.whole - p->h->p.whole + (p->hitOffsetX + w)) > p->hitWidth + o->hitWidth)
        return 0;
    dy = o->y.p.whole - p->y.p.whole;
    t = p->hitOffsetY + (o->hitHeight - o->hitOffsetY);
    if ((u16)(dy + t) > o->hitHeight + p->hitHeight)
        return 0;
    if (dy <= 0) {
        if (o->unk9C & 1)
            return 0;
        o->y.p.whole = p->y.p.whole - t;
        o->y.p.frac = 0;
        o->touchFlag = 1;
        return 1;
    }
    if (o->category == 2 && *(u16 *)&o->state == 0x102)
        return 0;
    o->y.p.whole = p->y.p.whole + (o->hitOffsetY + (p->hitHeight - p->hitOffsetY));
    return 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056970);
#define B0(p) ((u16)(p)->hitOffsetX)
#define B2(p) ((u16)(p)->hitOffsetY)

void func_80056970(GameObject *o, GameObject *e)
{
    s16 ox;
    s16 w;
    s16 r;
    s16 v;
    s16 dx;
    s16 adx;
    s16 b1;

    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b) return;
    if (o->animFrame & 1) ox = B0(o); else ox = (u16)o->hitWidth - B0(o);
    w = B0(e) + ox;
    r = w;
    dx = o->h->p.whole - e->h->p.whole;
    adx = dx;
    if ((u16)(dx + w) > e->hitWidth + (b1 = o->hitWidth)) return;
    if ((u16)(o->y.p.whole - e->y.p.whole + (B2(e) + (o->hitHeight - B2(o)))) > o->hitHeight + e->hitHeight) return;
    v = r;
    if (dx < 0) {
        adx = -dx;
        r = -w;
    } else {
        if (o->animFrame & 1) ox = b1 - B0(o); else ox = B0(o);
        r = ox + ((u16)e->hitWidth - B0(e));
        v = r;
    }
    if ((u16)(v - adx) < 9) {
        if (o->unk68) {
            e->unk68 = o->unk68;
            e->animFrame = o->animFrame & 1;
            o->unk68 = 0;
        }
        o->h->p.whole = e->h->p.whole + r;
        if ((s16)r < 0) o->unk9D = 2;
        else o->unk9D = 3;
        return;
    }
    if (o->unk9C & 1) return;
    *(s16 *)0x1F80019E = 0;
    o->y.p.whole = e->y.p.whole - (B2(e) + (o->hitHeight - B2(o)));
    o->y.p.frac = 0;
    o->touchFlag = 1;
    if (o->category == 2) {
        switch (o->type) {
        case 2:
            e->touchFlag = 2;
            break;
        case 0x22:
            o->active = 2;
            o->subState = 5;
            break;
        }
    }
}
#undef B0
#undef B2

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056BBC);
void func_80056BBC(GameObject *o, GameObject *p)
{
    if (o->type == 0x22 || o->type == 0x2c) {
        if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) < 0x5b) {
            if ((u16)(p->hitOffsetX + (o->h->p.whole - p->h->p.whole)) <= p->hitWidth) {
                if ((u16)(p->hitOffsetY + (o->y.p.whole - p->y.p.whole)) <= p->hitHeight) {
                    o->active = 2;
                    o->state = 2;
                    o->subState = 0;
                    o->step = 0;
                    p->step++;
                }
            }
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyInit);
void dispatchAreaEnemyInit(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80125FE8();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011F67C();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyUpdate);
void dispatchAreaEnemyUpdate(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80126048();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011F6DC();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056D24);
static __inline__ s16 hit_56D24(GameObject *o, GameObject *e)
{
    if ((u16)(o->d->p.whole - e->d->p.whole + 45) > 90)
        return 0;
    if ((u16)((o->h->p.whole - e->h->p.whole) + (e->hitOffsetX + (o->hitWidth - o->hitOffsetX))) > e->hitWidth + o->hitWidth)
        return 0;
    if ((u16)((o->y.p.whole - e->y.p.whole) + (e->hitOffsetY + (o->hitHeight - o->hitOffsetY))) <= o->hitHeight + e->hitHeight)
        return 1;
    return 0;
}
void func_80056D24(GameObject *o, GameObject *e)
{
    if (hit_56D24(o, e)) {
        e->unk68 = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056E00);
#define CNT (*(s16 *)0x1f800246)
#define LST (*(u8 ***)0x1f80021c)

void func_80056E00(void)
{
    s16 n;
    u8 **p;
    u8 *o, *q;
    u8 **r;
    s16 v;

    n = CNT;
    p = LST;
    while (n != 0) {
        o = *p;
        p++;
        n--;
        if (o[0] != 2 && D_8007EE64[o[2]] != 0) {
            r = LST;
            D_1F80019E = CNT;
            while (D_1F80019E != 0) {
                q = *r;
                D_1F80019E = D_1F80019E - 1;
                r++;
                if (q[0] != 2) {
                    switch (q[2]) {
                    case 4:
                        v = func_80055ED4(o, q);
                        if (v != 0) D_1F80019E = 0;
                        break;
                    case 6:
                        v = func_800566E4(o, q);
                        if (v != 0) D_1F80019E = 0;
                        break;
                    case 7:
                        v = func_80056498(o, q);
                        if (v != 0) D_1F80019E = 0;
                        break;
                    case 0xe:
                    case 0x10:
                        v = func_80056284(o, q);
                        if (v != 0) D_1F80019E = 0;
                        break;
                    case 0x1c:
                        func_80120C78(o);
                        break;
                    case 0x21:
                        func_80120B3C(o);
                        break;
                    }
                }
            }
        }
    }
}
#undef CNT
#undef LST

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056F94);
static __inline__ s32 hit_56F94(char *a, char *b)
{
    if ((u16)(*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x44)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x44)) + 2) + 0x2d) >= 0x5b)
        return 0;
    if ((u16)((*(u16 *)((u8 *)(*(char **)((u8 *)a + 0x40)) + 2) - *(u16 *)((u8 *)(*(char **)((u8 *)b + 0x40)) + 2)) + (*(u16 *)((u8 *)a + 0x6c) + *(u16 *)((u8 *)b + 0x6c))) > *(s16 *)((u8 *)a + 0x6e) + *(s16 *)((u8 *)b + 0x6e))
        return 0;
    return (u16)((*(u16 *)((u8 *)a + 0x16) - *(u16 *)((u8 *)b + 0x16)) + (*(u16 *)((u8 *)a + 0x70) + *(u16 *)((u8 *)b + 0x70))) <= *(s16 *)((u8 *)a + 0x72) + *(s16 *)((u8 *)b + 0x72);
}

s32 func_80056F94(char *a, char *b)
{
    return hit_56F94(a, b);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80057044);

void func_80057044(void)
{
    s16 n;
    u8 **pp, **qq;
    u8 *o, *e;
    if ((*(s32 *)&GAME) == 0x10000) {
        n = D_1F800246;
        pp = D_1F80021C;
        while (n != 0) {
            o = *pp++;
            n--;
            if ((o[0] & 3) && o[2] == 7 && o[3] != 0 && o[0xc] == 1 && o[0x69] == 0) {
                qq = D_1F800228;
                for (D_1F80019E = D_1F800248; D_1F80019E != 0; ) {
                    e = *qq++;
                    D_1F80019E--;
                    if ((e[0] & 3) && e[2] == 0xb) {
                        func_801262AC(o, e);
                        break;
                    }
                }
            }
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80057188);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_800574BC);
void func_80125E94(GameObject *o, GameObject *e);
void func_80125FA4(GameObject *o, GameObject *e);
void func_801260C0(GameObject *o, GameObject *e);
void func_80127414(GameObject *o, GameObject *e);
void func_80127314(GameObject *o, GameObject *e);
void func_801209E4(GameObject *o, GameObject *e);
void func_8011ED98(GameObject *o, GameObject *e);
void func_8011ED24(GameObject *o, GameObject *e);
void func_8011F720(GameObject *o, GameObject *e);
void func_80126BC4(GameObject *o, GameObject *e);
void func_801203D4(GameObject *o, GameObject *e);
void func_80120D60(GameObject *o, GameObject *e);
void func_80120CB4(GameObject *o, GameObject *e);

static __inline__ s16 hit_574BC(GameObject *o, GameObject *p)
{
    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    if ((u16)((o->h->p.whole - p->h->p.whole) + (p->hitOffsetX + (o->hitWidth - o->hitOffsetX))) > p->hitWidth + o->hitWidth)
        return 0;
    if ((u16)((o->y.p.whole - p->y.p.whole) + (p->hitOffsetY + (o->hitHeight - o->hitOffsetY))) > o->hitHeight + p->hitHeight)
        return 0;
    return 1;
}

void func_800574BC(void)
{
    s16 n;
    GameObject **pp, **qq;
    GameObject *o, *e;

    n = D_1F800248;
    pp = D_1F800228;
    if ((*(s16 *)&D_1F80024C) == 0)
        return;
    while (n != 0) {
        o = *pp++;
        n--;
        if (!(o->active & 1))
            continue;
        qq = D_1F800224;
        for (D_1F80019E = (*(s16 *)&D_1F80024C); D_1F80019E != 0; ) {
            e = *qq++;
            D_1F80019E--;
            if (!(e->active & 1))
                continue;
            switch (e->type) {
            case 0: func_80056970(o, e); break;
            case 1: func_80125E94(o, e); break;
            case 2: func_80125FA4(o, e); break;
            case 4:
                switch (GAME.selectedArea) {
                case 0: func_80126048(o, e); break;
                case 3: func_8011F6DC(o, e); break;
                }
                break;
            case 6: func_801260C0(o, e); break;
            case 0xf: func_80127414(o, e); break;
            case 0x14: func_80127314(o, e); break;
            case 0x1c: func_801209E4(o, e); break;
            case 0x23: func_80126BC4(o, e); break;
            case 0x28: func_801203D4(o, e); break;
            case 0x1f: func_8011ED24(o, e); break;
            case 0x22: func_8011F720(o, e); break;
            case 0x1b:
                if (hit_574BC(o, e))
                    e->unk68 = 1;
                break;
            case 0x34: func_80120CB4(o, e); break;
            case 0x33: func_80120D60(o, e); break;
            case 0x1e: func_8011ED98(o, e); break;
            }
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyDraw);
void dispatchAreaEnemyDraw(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_8012C03C();
        break;
    case AREA01_DWARFFOREST:
        func_8012E2FC();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_80123EC8();
        break;
    case AREA04_HAUNTEDMANSION:
        func_80122A00();
        break;
    }
}

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C8C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C90);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C94);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CB4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CBC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CC4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CD0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_8005788C);
typedef struct S_5788C { char p[0xc]; u8 b0c; } S_5788C;
extern void func_80117884(S_5788C *);
extern void func_8012A7A4(S_5788C *);
extern void func_80128F34(S_5788C *);
extern void func_801341B0(S_5788C *);
extern void func_8012B22C(S_5788C *);
extern void func_8012BBA8(S_5788C *);
extern void func_80129BE0(S_5788C *);
extern void func_80128D4C(S_5788C *);
extern void func_801287D4(S_5788C *);
extern void func_8012EDFC(S_5788C *);
extern void func_8012F5D0(S_5788C *);
extern void func_80129B68(S_5788C *);
extern void func_801293D4(S_5788C *);
extern void func_801164F4(S_5788C *);
extern void func_801287FC(S_5788C *);
extern void func_8012D330(S_5788C *);
extern void func_80124F70(S_5788C *);
extern void func_801263CC(S_5788C *);
extern void func_80118C0C(S_5788C *);
extern void func_801172B0(S_5788C *);
extern void func_80117E38(S_5788C *);
extern void func_8011784C(S_5788C *);
extern void func_80117364(S_5788C *);
extern void func_80116444(S_5788C *);
extern void func_8011967C(S_5788C *);
void func_8005788C(S_5788C *o)
{
    switch (GAME.selectedArea) {
    case 2:
        switch (D_8009BCCA) {
        case 2:
        case 3:
            break;
        case 5:
            func_80117884(o);
            break;
        }
        break;
    case 3:
        switch (D_8009BCCA) {
        case 0:
        case 4:
            if (o->b0c == 0x28)
                func_8012A7A4(o);
            else
                func_80128F34(o);
            break;
        case 1:
        case 5:
            switch (o->b0c) {
            case 9:
                func_80128F34(o);
                break;
            case 3:
                func_801341B0(o);
                break;
            case 0x28:
                func_8012B22C(o);
                break;
            case 0x29:
                func_8012BBA8(o);
                break;
            }
            break;
        case 2:
            func_80128F34(o);
            break;
        case 3:
            func_80129BE0(o);
            break;
        }
        break;
    case 4:
    case 12:
        switch (D_8009BCCA) {
        case 7: func_80128D4C(o); break;
        case 8: func_801287D4(o); break;
        case 9: func_8012EDFC(o); break;
        case 12: func_8012F5D0(o); break;
        case 17: func_80129B68(o); break;
        case 18: func_801293D4(o); break;
        }
        break;
    case 5:
        func_801164F4(o);
        break;
    case 9:
        func_801287FC(o);
        break;
    case 10:
        switch (D_8009BCCA) {
        case 0:
        case 4:
            switch (o->b0c) {
            case 0: func_8012D330(o); break;
            case 0x28: func_80124F70(o); break;
            }
            break;
        case 8:
            func_801263CC(o);
            break;
        case 1:
            break;
        case 2:
            break;
        }
        break;
    case 11:
        switch (D_8009BCCA) {
        case 1:
        case 3:
            func_80118C0C(o);
            break;
        case 4:
            break;
        case 0:
            break;
        case 2:
            break;
        }
        break;
    case 16:
        switch (D_8009BCCA) {
        case 5: func_801172B0(o); break;
        case 6: func_80117E38(o); break;
        }
        break;
    case 17:
        switch (D_8009BCCA) {
        case 0: case 1: case 3: case 4: case 5: case 10:
            func_8011784C(o);
            break;
        case 2: case 7:
            func_80117364(o);
            break;
        }
        break;
    case 18:
        switch (D_8009BCCA) {
        case 1: func_80116444(o); break;
        case 2: func_8011967C(o); break;
        case -1: break;
        }
        break;
    }
}
