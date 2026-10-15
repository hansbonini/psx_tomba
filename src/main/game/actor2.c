#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80055E0C);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80055ED4);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_8005606C);
s32 func_8005606C(GameObject *o, GameObject *p)
{
    char pad;
    s16 dx;
    s16 wx;
    s16 px;
    s16 dy;
    s32 di;
    s32 hy;
    s16 cx;

    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = p->hitOffsetX + (o->hitWidth - o->hitOffsetX);
    px = wx;
    dx = o->h->p.whole - p->h->p.whole;
    if ((u16)(dx + wx) > p->hitWidth + o->hitWidth)
        return 0;
    di = (u16)o->y.p.whole - (u16)p->y.p.whole;
    hy = (u16)p->hitOffsetY + ((u16)o->hitHeight - (u16)o->hitOffsetY);
    dy = di;
    if ((u16)(di + hy) > o->hitHeight + p->hitHeight)
        return 0;
    if (((u32)(hy - -di) & 0xffff) < 0xc) {
        o->y.p.whole = p->y.p.whole - hy;
        o->y.p.frac = 0;
        o->touchFlag = 1;
        return 1;
    }
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
    if (dy <= 0) {
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
    if (o->category == 2 && *(u16 *)&o->state == 0x102)
        return 0;
    o->y.p.whole = p->y.p.whole + (o->hitOffsetY + (p->hitHeight - p->hitOffsetY));
    return 3;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056284);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056498);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_800566E4);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056804);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056970);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056BBC);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", dispatchAreaEnemyInit);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", dispatchAreaEnemyUpdate);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056D24);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056E00);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056F94);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80057044);

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

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80057188);
struct GSInventory_57188 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_57188 { u8 weapon; u8 pants; };
typedef struct GameState_57188 {
    u16 selectedArea;
    u16 selectedSection;
    u8 selectedPlane;
    u8 area00_fogControl;
    u8 unk6;
    u8 keepBgm;
    s32 totalTimePlayed;
    unsigned long playerAP;
    u8 playerHealth;
    u8 playerHealthDisplayed;
    char unk12;
    char unk13;
    u8 areaTransition;
    u8 fadeScreenControl;
    u8 fadeScreenAmount;
    u8 saveSlot;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 playerLives;
    u8 unk21;
    u16 selectedSpawnPoint;
    s32 area00_eventControl;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 displayExpBar;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 area00_pickedItems[32];
    u8 area01_pickedItems[32];
    u8 area02_pickedItems[32];
    u8 area03_pickedItems[32];
    u8 area04_pickedItems[32];
    u8 area05_pickedItems[32];
    u8 area06_pickedItems[32];
    u8 area07_pickedItems[32];
    u8 area08_pickedItems[32];
    u8 area09_pickedItems[32];
    u8 area10_pickedItems[32];
    u8 area11_pickedItems[32];
    u8 area12_pickedItems[32];
    u8 area13_pickedItems[32];
    u8 area14_pickedItems[32];
    u8 area15_pickedItems[32];
    u8 area16_pickedItems[32];
    u8 area17_pickedItems[32];
    u8 area18_pickedItems[32];
    u8 area19_pickedItems[32];
    u8 unk2b4;
    u8 unk2b5;
    u8 unk2b6;
    u8 unk2b7;
    u8 unk2b8;
    u8 unk2b9;
    u8 unk2ba;
    u8 unk2bb;
    u8 unk2bc;
    u8 unk2bd;
    u8 unk2be;
    u8 unk2bf;
    u8 unk2c0;
    u8 unk2c1;
    u8 unk2c2;
    u8 unk2c3;
    u8 unk2c4;
    u8 unk2c5;
    u8 unk2c6;
    u8 unk2c7;
    u8 unk2c8;
    u8 unk2c9;
    u8 unk2ca;
    u8 unk2cb;
    u8 unk2cc;
    u8 unk2cd;
    u8 unk2ce;
    u8 unk2cf;
    u8 unk2d0;
    u8 unk2d1;
    u8 unk2d2;
    u8 unk2d3;
    u8 unk2d4;
    u8 unk2d5;
    u8 unk2d6;
    u8 unk2d7;
    u8 unk2d8;
    u8 unk2d9;
    u8 unk2da;
    u8 unk2db;
    u8 unk2dc;
    u8 unk2dd;
    u8 unk2de;
    u8 unk2df;
    u8 unk2e0;
    u8 unk2e1;
    u8 unk2e2;
    u8 unk2e3;
    u8 unk2e4;
    u8 unk2e5;
    u8 unk2e6;
    u8 unk2e7;
    u8 unk2e8;
    u8 unk2e9;
    u8 unk2ea;
    u8 unk2eb;
    u8 unk2ec;
    u8 unk2ed;
    u8 unk2ee;
    u8 unk2ef;
    u8 unk2f0;
    u8 unk2f1;
    u8 unk2f2;
    u8 unk2f3;
    u8 unk2f4;
    u8 unk2f5;
    u8 unk2f6;
    u8 unk2f7;
    u8 unk2f8;
    u8 unk2f9;
    u8 unk2fa;
    u8 unk2fb;
    u8 unk2fc;
    u8 unk2fd;
    u8 unk2fe;
    u8 unk2ff;
    u8 unk300;
    u8 unk301;
    u8 unk302;
    u8 unk303;
    u8 unk304;
    u8 unk305;
    u8 unk306;
    u8 unk307;
    u8 unk308;
    u8 unk309;
    u8 unk30a;
    u8 unk30b;
    u8 unk30c;
    u8 unk30d;
    u8 unk30e;
    u8 unk30f;
    u8 unk310;
    u8 unk311;
    u8 unk312;
    u8 unk313;
    u8 unk314;
    u8 unk315;
    u8 unk316;
    u8 unk317;
    u8 unk318;
    u8 unk319;
    u8 unk31a;
    u8 unk31b;
    u8 unk31c;
    u8 unk31d;
    u8 unk31e;
    u8 unk31f;
    u8 unk320;
    u8 unk321;
    u8 unk322;
    u8 unk323;
    u8 unk324;
    u8 unk325;
    u8 unk326;
    u8 unk327;
    u8 unk328;
    u8 unk329;
    u8 unk32a;
    u8 unk32b;
    u8 unk32c;
    u8 unk32d;
    u8 unk32e;
    u8 unk32f;
    u8 unk330;
    u8 unk331;
    u8 unk332;
    u8 unk333;
    u8 unk334;
    u8 unk335;
    u8 unk336;
    u8 unk337;
    u8 unk338;
    u8 unk339;
    u8 unk33a;
    u8 unk33b;
    u8 unk33c;
    u8 unk33d;
    u8 unk33e;
    u8 unk33f;
    u8 unk340;
    u8 unk341;
    u8 unk342;
    u8 unk343;
    u8 unk344;
    u8 unk345;
    u8 unk346;
    u8 unk347;
    u8 unk348;
    u8 unk349;
    u8 unk34a;
    u8 unk34b;
    u8 unk34c;
    u8 unk34d;
    u8 unk34e;
    u8 unk34f;
    u8 unk350;
    u8 unk351;
    u8 unk352;
    u8 unk353;
    u8 unk354;
    u8 unk355;
    u8 unk356;
    u8 unk357;
    u8 unk358;
    u8 unk359;
    u8 unk35a;
    u8 unk35b;
    u8 unk35c;
    u8 unk35d;
    u8 unk35e;
    u8 unk35f;
    u8 unk360;
    u8 unk361;
    u8 unk362;
    u8 unk363;
    u8 unk364;
    u8 unk365;
    u8 unk366;
    u8 unk367;
    u8 unk368;
    u8 unk369;
    u8 unk36a;
    u8 unk36b;
    u8 unk36c;
    u8 unk36d;
    u8 unk36e;
    u8 unk36f;
    u8 unk370;
    u8 unk371;
    u8 unk372;
    u8 unk373;
    u8 unk374;
    u8 unk375;
    u8 unk376;
    u8 unk377;
    u8 unk378;
    u8 unk379;
    u8 unk37a;
    u8 unk37b;
    u8 unk37c;
    u8 unk37d;
    u8 unk37e;
    u8 unk37f;
    u8 unk380;
    u8 unk381;
    u8 unk382;
    u8 unk383;
    u8 unk384;
    u8 unk385;
    u8 unk386;
    u8 unk387;
    u8 unk388;
    u8 unk389;
    u8 unk38a;
    u8 unk38b;
    u8 unk38c;
    u8 unk38d;
    u8 unk38e;
    u8 unk38f;
    u8 unk390;
    u8 unk391;
    u8 unk392;
    u8 unk393;
    u8 unk394;
    u8 unk395;
    u8 unk396;
    u8 unk397;
    u8 unk398;
    u8 unk399;
    u8 unk39a;
    u8 unk39b;
    u8 unk39c;
    u8 unk39d;
    u8 unk39e;
    u8 unk39f;
    u8 unk3a0;
    u8 unk3a1;
    u8 unk3a2;
    u8 unk3a3;
    u8 unk3a4;
    u8 unk3a5;
    u8 unk3a6;
    u8 unk3a7;
    u8 unk3a8;
    u8 unk3a9;
    u8 unk3aa;
    u8 unk3ab;
    u8 unk3ac;
    u8 unk3ad;
    u8 unk3ae;
    u8 unk3af;
    u8 unk3b0;
    u8 unk3b1;
    u8 unk3b2;
    u8 unk3b3;
    u8 unk3b4;
    u8 unk3b5;
    u8 unk3b6;
    u8 unk3b7;
    u8 unk3b8;
    u8 unk3b9;
    u8 unk3ba;
    u8 unk3bb;
    u8 unk3bc;
    u8 unk3bd;
    u8 unk3be;
    u8 unk3bf;
    u8 unk3c0;
    u8 unk3c1;
    u8 unk3c2;
    u8 unk3c3;
    u8 unk3c4;
    u8 unk3c5;
    u8 unk3c6;
    u8 unk3c7;
    u8 unk3c8;
    u8 unk3c9;
    u8 unk3ca;
    u8 unk3cb;
    u8 unk3cc;
    u8 unk3cd;
    u8 unk3ce;
    u8 unk3cf;
    u8 unk3d0;
    u8 unk3d1;
    u8 unk3d2;
    u8 unk3d3;
    u8 unk3d4;
    u8 unk3d5;
    u8 unk3d6;
    u8 unk3d7;
    u8 unk3d8;
    u8 unk3d9;
    u8 unk3da;
    u8 unk3db;
    u8 unk3dc;
    u8 unk3dd;
    u8 unk3de;
    u8 unk3df;
    u8 unk3e0;
    u8 unk3e1;
    u8 unk3e2;
    u8 unk3e3;
    u8 unk3e4;
    u8 unk3e5;
    u8 unk3e6;
    u8 unk3e7;
    u8 unk3e8;
    u8 unk3e9;
    u8 unk3ea;
    u8 unk3eb;
    u8 unk3ec;
    u8 unk3ed;
    u8 unk3ee;
    u8 unk3ef;
    u8 unk3f0;
    u8 unk3f1;
    u8 unk3f2;
    u8 unk3f3;
    u8 unk3f4;
    u8 unk3f5;
    u8 unk3f6;
    u8 unk3f7;
    u8 unk3f8;
    u8 unk3f9;
    u8 unk3fa;
    u8 unk3fb;
    u8 unk3fc;
    u8 unk3fd;
    u8 unk3fe;
    u8 unk3ff;
    u8 unk400;
    u8 unk401;
    u8 unk402;
    u8 unk403;
    u8 unk404;
    u8 unk405;
    u8 unk406;
    u8 unk407;
    u8 unk408;
    u8 unk409;
    u8 unk40a;
    u8 unk40b;
    u8 unk40c;
    u8 unk40d;
    u8 unk40e;
    u8 unk40f;
    u8 unk410;
    u8 unk411;
    u8 unk412;
    u8 unk413;
    u8 unk414;
    u8 unk415;
    u8 unk416;
    u8 unk417;
    u8 unk418;
    u8 unk419;
    u8 unk41a;
    u8 unk41b;
    u8 unk41c;
    u8 unk41d;
    u8 unk41e;
    u8 unk41f;
    u8 unk420;
    u8 unk421;
    u8 unk422;
    u8 unk423;
    u8 unk424;
    u8 unk425;
    u8 unk426;
    u8 unk427;
    u8 unk428;
    u8 unk429;
    u8 unk42a;
    u8 unk42b;
    u8 unk42c;
    u8 unk42d;
    u8 unk42e;
    u8 unk42f;
    u8 unk430;
    u8 unk431;
    u8 unk432;
    u8 unk433;
    u16 nextArea;
    u16 nextSection;
    u8 redExpLevel;
    u8 greenExpLevel;
    u8 blueExpLevel;
    u8 redExpBar;
    u8 greenExpBar;
    u8 blueExpBar;
    u8 unk43e;
    u8 unk43f;
    u16 nextSpawnPoint;
    u8 disableSelectMenu;
    u8 inventoryScreen;
    u8 event[256];
    u8 unk544;
    u8 unk545;
    u8 unk546;
    u8 unk547;
    u8 unk548;
    u8 unk549;
    u8 unk54a;
    u8 baronState;
    u8 unk54c;
    u8 unk54d;
    u8 unk54e;
    char unk54f;
    u8 unk550;
    u8 unk551;
    u8 unk552;
    u8 unk553;
    u8 unk554;
    u8 unk555;
    u8 unk556;
    u8 unk557;
    u8 unk558;
    u8 unk559;
    u8 unk55a;
    u8 unk55b;
    u8 unk55c;
    u8 unk55d;
    u8 unk55e;
    u8 unk55f;
    u8 unk560;
    u8 unk561;
    u8 unk562;
    u8 unk563;
    u8 unk564;
    u8 unk565;
    u8 unk566;
    u8 unk567;
    u8 unk568;
    u8 unk569;
    u8 unk56a;
    u8 unk56b;
    u8 unk56c;
    u8 unk56d;
    u8 unk56e;
    u8 unk56f;
    u8 unk570;
    u8 unk571;
    u8 unk572;
    u8 unk573;
    u8 unk574;
    u8 unk575;
    u8 unk576;
    u8 unk577;
    u8 unk578;
    u8 unk579;
    u8 unk57a;
    u8 unk57b;
    u8 unk57c;
    u8 unk57d;
    u8 unk57e;
    u8 unk57f;
    u8 unk580;
    u8 unk581;
    u8 unk582;
    u8 unk583;
    u8 unk584;
    u8 unk585;
    u8 unk586;
    u8 unk587;
    u8 unk588;
    u8 unk589;
    u8 unk58a;
    u8 unk58b;
    u8 unk58c;
    u8 unk58d;
    u8 unk58e;
    u8 unk58f;
    u8 unk590;
    u8 unk591;
    u8 unk592;
    u8 unk593;
    u8 unk594;
    u8 unk595;
    u8 unk596;
    u8 unk597;
    u8 unk598;
    u8 unk599;
    u8 unk59a;
    u8 unk59b;
    u8 unk59c;
    u8 unk59d;
    u8 unk59e;
    u8 unk59f;
    u8 unk5a0;
    u8 pipeState;
    u8 unk5a2;
    u8 unk5a3;
    u8 unk5a4;
    u8 unk5a5;
    u8 unk5a6;
    u8 unk5a7;
    u8 unk5a8;
    u8 unk5a9;
    u8 unk5aa;
    u8 unk5ab;
    u8 unk5ac;
    u8 unk5ad;
    u8 unk5ae;
    u8 unk5af;
    u8 unk5b0;
    u8 unk5b1;
    u8 unk5b2;
    u8 unk5b3;
    u8 unk5b4;
    u8 unk5b5;
    u8 unk5b6;
    u8 unk5b7;
    u8 unk5b8;
    u8 unk5b9;
    u8 unk5ba;
    u8 unk5bb;
    u8 unk5bc;
    u8 unk5bd;
    u8 unk5be;
    u8 unk5bf;
    u8 unk5c0;
    u8 unk5c1;
    u8 unk5c2;
    u8 unk5c3;
    u8 unk5c4;
    u8 unk5c5;
    u8 unk5c6;
    u8 unk5c7;
    u8 unk5c8;
    u8 unk5c9;
    u8 unk5ca;
    u8 unk5cb;
    u8 unk5cc;
    u8 unk5cd;
    u8 unk5ce;
    u8 unk5cf;
    u8 unk5d0;
    u8 unk5d1;
    u8 unk5d2;
    u8 unk5d3;
    u8 unk5d4;
    u8 unk5d5;
    u8 unk5d6;
    u8 unk5d7;
    u8 unk5d8;
    u8 unk5d9;
    u8 unk5da;
    u8 unk5db;
    u8 unk5dc;
    u8 unk5dd;
    u8 unk5de;
    u8 unk5df;
    u8 unk5e0;
    u8 unk5e1;
    u8 unk5e2;
    u8 unk5e3;
    u8 unk5e4;
    u8 unk5e5;
    u8 unk5e6;
    u8 unk5e7;
    u8 unk5e8;
    u8 unk5e9;
    u8 unk5ea;
    u8 unk5eb;
    u8 unk5ec;
    u8 unk5ed;
    u8 unk5ee;
    u8 unk5ef;
    u8 unk5f0;
    u8 unk5f1;
    u8 unk5f2;
    u8 unk5f3;
    u8 unk5f4;
    u8 unk5f5;
    u8 unk5f6;
    u8 unk5f7;
    u8 unk5f8;
    u8 unk5f9;
    u8 unk5fa;
    u8 unk5fb;
    u8 unk5fc;
    u8 unk5fd;
    u8 unk5fe;
    u8 unk5ff;
    u8 unk600;
    u8 unk601;
    u8 unk602;
    u8 unk603;
    u8 unk604;
    u8 unk605;
    u8 unk606;
    u8 unk607;
    u8 unk608;
    u8 unk609;
    u8 unk60a;
    u8 unk60b;
    u8 unk60c;
    u8 unk60d;
    u8 unk60e;
    u8 unk60f;
    u8 unk610;
    u8 unk611;
    u8 unk612;
    u8 unk613;
    u8 unk614;
    u8 unk615;
    u8 unk616;
    u8 unk617;
    u8 unk618;
    u8 unk619;
    u8 unk61a;
    u8 unk61b;
    u8 unk61c;
    u8 unk61d;
    u8 unk61e;
    u8 unk61f;
    u8 unk620;
    u8 unk621;
    u8 unk622;
    u8 unk623;
    u8 unk624;
    u8 unk625;
    u8 unk626;
    u8 unk627;
    u8 unk628;
    u8 unk629;
    u8 unk62a;
    u8 unk62b;
    u8 unk62c;
    u8 unk62d;
    u8 unk62e;
    u8 unk62f;
    u8 unk630;
    u8 unk631;
    u8 unk632;
    u8 unk633;
    u8 unk634;
    u8 unk635;
    u8 unk636;
    u8 unk637;
    u8 unk638;
    u8 unk639;
    u8 unk63a;
    u8 unk63b;
    u8 unk63c;
    u8 unk63d;
    u8 unk63e;
    u8 unk63f;
    u8 unk640;
    u8 unk641;
    u8 unk642;
    u8 unk643;
    u8 unk644;
    u8 unk645;
    u8 unk646;
    u8 unk647;
    u8 unk648;
    u8 unk649;
    u8 unk64a;
    u8 unk64b;
    u8 unk64c;
    u8 unk64d;
    u8 unk64e;
    u8 unk64f;
    u8 unk650;
    u8 unk651;
    u8 unk652;
    u8 unk653;
    u8 unk654;
    u8 unk655;
    u8 unk656;
    u8 unk657;
    u8 unk658;
    u8 unk659;
    u8 unk65a;
    u8 unk65b;
    u8 unk65c;
    u8 unk65d;
    u8 unk65e;
    u8 unk65f;
    u8 unk660;
    u8 unk661;
    u8 unk662;
    u8 unk663;
    u8 unk664;
    u8 unk665;
    u8 unk666;
    u8 unk667;
    u8 unk668;
    u8 unk669;
    u8 unk66a;
    u8 unk66b;
    u8 unk66c;
    u8 unk66d;
    u8 unk66e;
    u8 unk66f;
    s16 unk670;
    s16 unk672;
    s16 unk674;
    u8 unk676;
    u8 unk677;
    u8 unk678;
    u8 unk679;
    u8 unk67a;
    u8 unk67b;
    u8 unk67c;
    u8 unk67d;
    u8 unk67e;
    u8 unk67f;
    u8 unk680;
    u8 unk681;
    u8 unk682;
    u8 unk683;
    u8 goldenFlowerState;
    u8 unk685;
    u8 unk686;
    u8 unk687;
    u8 unk688;
    u8 unk689;
    u8 unk68a;
    u8 unk68b;
    u8 unk68c;
    u8 unk68d;
    u8 unk68e;
    u8 unk68f;
    u8 unk690;
    u8 unk691;
    u8 unk692;
    u8 unk693;
    u8 unk694;
    u8 unk695;
    u8 unk696;
    u8 unk697;
    u8 unk698;
    u8 unk699;
    u8 unk69a;
    u8 unk69b;
    u8 unk69c;
    u8 unk69d;
    u8 unk69e;
    u8 unk69f;
    u8 unk6a0;
    u8 unk6a1;
    u8 unk6a2;
    u8 unk6a3;
    u8 unk6a4;
    u8 unk6a5;
    u8 unk6a6;
    u8 unk6a7;
    u8 unk6a8;
    u8 unk6a9;
    u8 unk6aa;
    u8 unk6ab;
    u8 unk6ac;
    u8 unk6ad;
    u8 unk6ae;
    u8 playerIdleState;
    u8 unk6b0;
    u8 unk6b1;
    u8 unk6b2;
    u8 unk6b3;
    u8 unk6b4;
    u8 unk6b5;
    u8 unk6b6;
    u8 unk6b7;
    u8 unk6b8;
    u8 unk6b9;
    u8 unk6ba;
    u8 unk6bb;
    u8 unk6bc;
    u8 unk6bd;
    u8 unk6be;
    u8 unk6bf;
    u8 unk6c0;
    u8 unk6c1;
    u8 unk6c2;
    u8 unk6c3;
    u8 unk6c4;
    u8 unk6c5;
    u8 unk6c6;
    u8 unk6c7;
    u8 unk6c8;
    u8 unk6c9;
    u8 unk6ca;
    u8 unk6cb;
    u8 unk6cc;
    u8 unk6cd;
    u8 unk6ce;
    u8 unk6cf;
    u8 unk6d0;
    u8 unk6d1;
    u8 unk6d2;
    u8 unk6d3;
    u8 unk6d4;
    u8 unk6d5;
    u8 unk6d6;
    u8 unk6d7;
    u8 unk6d8;
    u8 unk6d9;
    u8 unk6da;
    u8 unk6db;
    u8 unk6dc;
    u8 unk6dd;
    u8 unk6de;
    u8 unk6df;
    u8 unk6e0;
    u8 unk6e1;
    u8 unk6e2;
    u8 unk6e3;
    u8 unk6e4;
    u8 unk6e5;
    u8 unk6e6;
    u8 unk6e7;
    u8 unk6e8;
    u8 unk6e9;
    u8 unk6ea;
    u8 unk6eb;
    u8 unk6ec;
    u8 unk6ed;
    u8 unk6ee;
    u8 unk6ef;
    u8 unk6f0;
    u8 unk6f1;
    u8 unk6f2;
    u8 unk6f3;
    u8 unk6f4;
    u8 unk6f5;
    u8 unk6f6;
    u8 unk6f7;
    u8 unk6f8;
    u8 unk6f9;
    u8 unk6fa;
    u8 unk6fb;
    u8 unk6fc;
    u8 unk6fd;
    u8 unk6fe;
    u8 unk6ff;
    u8 unk700;
    u8 unk701;
    u8 unk702;
    u8 unk703;
    u8 unk704;
    u8 unk705;
    u8 unk706;
    u8 unk707;
    u8 unk708;
    u8 unk709;
    u8 unk70a;
    u8 unk70b;
    u8 unk70c;
    u8 unk70d;
    u8 unk70e;
    u8 unk70f;
    u8 unk710;
    u8 unk711;
    u8 unk712;
    u8 unk713;
    u8 unk714;
    u8 unk715;
    u8 unk716;
    u8 unk717;
    u8 unk718;
    u8 unk719;
    u8 unk71a;
    u8 bittingPlantFlowerState;
    u8 unk71c;
    u8 unk71d;
    u8 unk71e;
    u8 goldenBowlState;
    u8 bonusHealth;
    u8 unk721;
    u8 unk722;
    u8 unk723;
    u8 unk724;
    u8 unk725;
    u8 unk726;
    u8 unk727;
    u8 unk728;
    u8 unk729;
    u8 unk72a;
    u8 unk72b;
    u8 unk72c;
    u8 unk72d;
    u8 unk72e;
    u8 unk72f;
    u8 unk730;
    u8 unk731;
    u8 unk732;
    u8 unk733;
    u8 unk734;
    u8 unk735;
    char unk736;
    u8 unk737;
    u8 unk738;
    u8 unk739;
    u8 unk73a;
    u8 unk73b;
    u8 unk73c;
    u8 unk73d;
    u8 unk73e;
    u8 unk73f;
    u8 unk740;
    u8 unk741;
    u8 unk742;
    u8 unk743;
    u8 item[256];
    struct GSInventory_57188 inventory;
    u16 currentArea;
    u16 currentSection;
    u16 currentSpawnPoint;
    u8 inventoryButton;
    u8 playerState;
    struct GSEquips_57188 playerEquips;
    u8 unk952;
    u8 unk953;
    u8 unk954;
    u8 unk955;
    u8 unk956;
    u8 unk957;
    u8 unk958;
    u8 unk959;
    u8 unk95a;
    u8 unk95b;
    u8 unk95c;
    u8 unk95d;
    u8 unk95e;
    u8 unk95f;
    u8 unk960;
    u8 unk961;
    u8 unk962;
    u8 purifiedAreas;
    u8 unk964;
    u8 unk965;
    u8 unk966;
    u8 unk967;
    u8 unk968;
    u8 unk969;
    u8 unk96a;
    u8 unk96b;
    u8 unk96c;
    u8 unk96d;
    u8 unk96e;
    u8 unk96f;
    u8 unk970;
    u8 unk971;
    u8 unk972;
    u8 unk973;
    u8 unk974;
    u8 unk975;
    u8 unk976;
    u8 unk977;
    u8 unk978;
    u8 unk979;
    u8 unk97a;
    u8 unk97b;
    u8 unk97c;
    u8 unk97d;
    u8 unk97e;
    u8 unk97f;
    u8 unk980;
    u8 unk981;
    u8 unk982;
    u8 unk983;
    u8 unk984;
} GameState_57188;
extern u8 D_8007EDFC[];
void func_8012608C(GameObject *o);
void func_8012738C(GameObject *o);
void func_8011C840(GameObject *o);

void func_80057188(void)
{
    extern void func_80127414(GameObject *o);
    extern void func_80127314(GameObject *o);
    extern void func_80126BC4(GameObject *o);
    extern void func_801260C0(GameObject *o);
    extern void func_80125FA4(GameObject *o);
    extern void func_80125E94(GameObject *o);
    extern void func_80120D60(GameObject *o);
    extern void func_80120CB4(GameObject *o);
    extern void func_801209E4(GameObject *o);
    extern void func_801203D4(GameObject *o);
    extern void func_8011F720(GameObject *o);
    extern void func_8011ED98(GameObject *o);
    extern void func_8011ED24(GameObject *o);
    s16 n;
    GameObject **list;
    GameObject **l2;
    GameObject *o;
    GameObject *e;
    s16 d;
    u8 two;
    n = *(u16 *)0x1F800246;
    list = *(GameObject ***)0x1F80021C;
    if (*(s16 *)0x1F80024C == 0) return;
    if (n == 0) return;
    do {
        o = *list++;
        n--;
        if (o->active != 2 && D_8007EDFC[o->type] != 0) {
        l2 = *(GameObject ***)0x1F800224;
        if ((D_1F80019E = *(u16 *)0x1F80024C) != 0)
        do {
            e = *l2++;
            D_1F80019E--;
            if (!(e->active & 1)) continue;
            switch (e->type) {
            case 0: two = 2; ((void (*)(GameObject *o))func_80056970)(o); break;
            case 1: func_80125E94(o); break;
            case 2: func_80125FA4(o); break;
            case 4:
                switch (GAME.selectedArea) {
                case 0: ((void (*)(GameObject *o))func_80125FE8)(o); break;
                case 3: ((void (*)(GameObject *o))func_8011F67C)(o); break;
                }
                break;
            case 6: func_801260C0(o); break;
            case 10: func_8012608C(o); break;
            case 15: func_80127414(o); break;
            case 20: func_80127314(o); break;
            case 28: func_801209E4(o); break;
            case 32:
                if (o->type == 0x22 || o->type == 0x2c) {
                    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) < 0x5b) {
                        if ((u16)(e->hitOffsetX + (o->h->p.whole - e->h->p.whole)) <= e->hitWidth) {
                            if ((u16)(e->hitOffsetY + (o->y.p.whole - e->y.p.whole)) <= e->hitHeight) {
                                two = 2;
                                o->active = two;
                                o->state = two;
                                o->subState = 0;
                                o->step = 0;
                                e->step++;
                            }
                        }
                    }
                }
                break;
            case 33: func_8012738C(o); break;
            case 35: func_80126BC4(o); break;
            case 40: func_801203D4(o); break;
            case 31: func_8011ED24(o); break;
            case 34: func_8011F720(o); break;
            case 66:
            case 67: func_8011C840(o); break;

            case 52: func_80120CB4(o); break;
            case 51: func_80120D60(o); break;
            case 30: func_8011ED98(o); break;
            }
        } while (D_1F80019E != 0);
        }
    } while (n != 0);
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_800574BC);
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

// INCLUDE_ASM("nonmatchings/main/game/actor2", dispatchAreaEnemyDraw);
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

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014C8C);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014C90);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014C94);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014CB4);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014CBC);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014CC4);

INCLUDE_RODATA("nonmatchings/main/game/actor2", D_80014CD0);

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_8005788C);
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
