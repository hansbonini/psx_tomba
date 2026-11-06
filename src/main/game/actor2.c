#include "common.h"
#include "game.h"
#include "game/area_module.h"

u32 D_8007EDFC_d[26] asm("D_8007EDFC") = {
    0x01010001, 0x00000000, 0x00010001, 0x00010001,
    0x01000100, 0x00010000, 0x00000001, 0x00000000,
    0x00010100, 0x01000000, 0x00000000, 0x00000001,
    0x00000000, 0x00000000, 0x00010001, 0x00000000,
    0x00000000, 0x01000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
u32 D_8007EE64_d[31] asm("D_8007EE64") = {
    0x00010000, 0x00000000, 0x00010001, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000100, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00010101, 0x00000000,
    0x00000000, 0x00000000, 0x00000000,
};

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80055E0C);
static __inline__ s32 hit_55E0C(GameObject *obj, GameObject *other)
{
    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b) return 0;
    if ((u16)(obj->h->p.whole - other->h->p.whole + (other->hitboxX + (obj->hitboxW - obj->hitboxX))) > other->hitboxW + obj->hitboxW) return 0;
    return (u16)(obj->y.p.whole - other->y.p.whole + (other->hitboxY + (obj->hitboxH - obj->hitboxY))) <= obj->hitboxH + other->hitboxH;
}

s32 func_80055E0C(GameObject *obj, GameObject *other)
{
    return hit_55E0C(obj, other);
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80055ED4);
s32 func_80055ED4(GameObject *obj, GameObject *other)
{
    char pad;
    s16 dx, wx, px;
    s16 cx;

    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = other->hitboxX + (obj->hitboxW - obj->hitboxX);
    px = wx;
    dx = obj->h->p.whole - other->h->p.whole;
    if ((u16)(dx + wx) > other->hitboxW + obj->hitboxW)
        return 0;
    if ((u16)((obj->y.p.whole - other->y.p.whole) + (other->hitboxY + (obj->hitboxH - obj->hitboxY))) > obj->hitboxH + other->hitboxH)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = obj->hitboxX + (other->hitboxW - other->hitboxX);
        cx = px;
    }
    if ((u16)(cx - dx) < 4) {
        obj->h->p.whole = other->h->p.whole + px;
        if (px < 0)
            obj->unk9D = 2;
        else
            obj->unk9D = 3;
        return 2;
    }
    if (obj->unk9C & 1)
        return 0;
    {
        s16 w = other->y.p.whole - (other->hitboxY + (obj->hitboxH - obj->hitboxY));
        GameObject *q = obj;
        obj->y.p.frac = 0;
        obj->touchFlag = 1;
        q->y.p.whole = w;
    }
    return 1;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_8005606C);
s32 func_8005606C(GameObject *obj, GameObject *other)
{
    char pad;
    s16 dx;
    s16 wx;
    s16 px;
    s16 dy;
    s32 di;
    s32 hy;
    s16 cx;

    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = other->hitboxX + (obj->hitboxW - obj->hitboxX);
    px = wx;
    dx = obj->h->p.whole - other->h->p.whole;
    if ((u16)(dx + wx) > other->hitboxW + obj->hitboxW)
        return 0;
    di = (u16)obj->y.p.whole - (u16)other->y.p.whole;
    hy = (u16)other->hitboxY + ((u16)obj->hitboxH - (u16)obj->hitboxY);
    dy = di;
    if ((u16)(di + hy) > obj->hitboxH + other->hitboxH)
        return 0;
    if (((u32)(hy - -di) & 0xffff) < 0xc) {
        obj->y.p.whole = other->y.p.whole - hy;
        obj->y.p.frac = 0;
        obj->touchFlag = 1;
        return 1;
    }
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = obj->hitboxX + (other->hitboxW - other->hitboxX);
        cx = px;
    }
    if ((u16)(cx - dx) < 4) {
        obj->h->p.whole = other->h->p.whole + px;
        if (px < 0)
            obj->unk9D = 2;
        else
            obj->unk9D = 3;
        return 2;
    }
    if (dy <= 0) {
        if (obj->unk9C & 1)
            return 0;
        {
            s16 w = other->y.p.whole - (other->hitboxY + (obj->hitboxH - obj->hitboxY));
            GameObject *q = obj;
            obj->y.p.frac = 0;
            obj->touchFlag = 1;
            q->y.p.whole = w;
        }
        return 1;
    }
    if (obj->category == 2 && *(u16 *)&obj->state == 0x102)
        return 0;
    obj->y.p.whole = other->y.p.whole + (obj->hitboxY + (other->hitboxH - other->hitboxY));
    return 3;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056284);
s32 func_80056284(GameObject *obj, GameObject *other)
{
    char pad;
    s16 dx, wx, px;
    s16 dy, hy, py;
    s16 cx, cy;

    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = other->hitboxX + (obj->hitboxW - obj->hitboxX);
    px = wx;
    dx = obj->h->p.whole - other->h->p.whole;
    if ((u16)(dx + wx) > other->hitboxW + obj->hitboxW)
        return 0;
    dy = obj->y.p.whole - other->y.p.whole;
    hy = other->hitboxY + (obj->hitboxH - obj->hitboxY);
    py = hy;
    if ((u16)(dy + hy) > obj->hitboxH + other->hitboxH)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = obj->hitboxX + (other->hitboxW - other->hitboxX);
        cx = px;
    }
    cy = py;
    if (dy < 0) {
        dy = -dy;
        py = -py;
    } else {
        py = obj->hitboxY + (other->hitboxH - other->hitboxY);
        cy = py;
    }
    if (cx - dx < cy - dy) {
        obj->h->p.whole = other->h->p.whole + px;
        if (px < 0)
            obj->unk9D = 2;
        else
            obj->unk9D = 3;
        return 2;
    }
    if (py <= 0) {
        if (obj->unk9C & 1)
            return 0;
        {
            s16 w = other->y.p.whole;
            GameObject *q = obj;
            obj->y.p.frac = 0;
            obj->touchFlag = 1;
            q->y.p.whole = w + py;
        }
        return 1;
    }
    if (obj->category == 2 && *(u16 *)&obj->state == 0x102)
        return 0;
    obj->y.p.whole = other->y.p.whole + py;
    return 3;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056498);
s32 func_80056498(GameObject *obj, GameObject *other)
{
    char pad;
    s16 dx, wx, px;
    s16 dy, hy, py;
    s16 cx, cy;

    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    wx = other->hitboxX + (obj->hitboxW - obj->hitboxX);
    px = wx;
    dx = obj->h->p.whole - other->h->p.whole;
    if ((u16)(dx + wx) > other->hitboxW + obj->hitboxW)
        return 0;
    dy = obj->y.p.whole - other->y.p.whole;
    hy = other->hitboxY + (obj->hitboxH - obj->hitboxY);
    py = hy;
    if ((u16)(dy + hy) > obj->hitboxH + other->hitboxH)
        return 0;
    cx = px;
    if (dx < 0) {
        dx = -dx;
        px = -px;
    } else {
        px = obj->hitboxX + (other->hitboxW - other->hitboxX);
        cx = px;
    }
    cy = py;
    if (dy < 0) {
        dy = -dy;
        py = -py;
    } else {
        py = obj->hitboxY + (other->hitboxH - other->hitboxY);
        cy = py;
    }
    if (cx - dx < cy - dy) {
        obj->h->p.whole = other->h->p.whole + px;
        if (px < 0)
            obj->unk9D = 2;
        else
            obj->unk9D = 3;
        return 2;
    }
    if (py <= 0) {
        if (obj->unk9C & 1)
            return 0;
        if (px < 0)
            obj->h->p.whole -= 1;
        else
            obj->h->p.whole += 1;
        obj->y.p.whole = other->y.p.whole + py;
        obj->y.p.frac = 0;
        obj->touchFlag = 1;
        return 1;
    }
    if (obj->category == 2 && *(u16 *)&obj->state == 0x102)
        return 0;
    obj->y.p.whole = other->y.p.whole + py;
    return 3;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_800566E4);
s32 func_800566E4(GameObject *obj, GameObject *other)
{
    s16 dx, w, r;
    char pad;
    if ((u16)(obj->d->p.whole - other->d->p.whole + 45) > 90)
        return 0;
    dx = obj->h->p.whole - other->h->p.whole;
    w = other->hitboxX + (obj->hitboxW - obj->hitboxX);
    if ((u16)(dx + w) > other->hitboxW + obj->hitboxW)
        return 0;
    if ((u16)(obj->y.p.whole - other->y.p.whole + (other->hitboxY + (obj->hitboxH - obj->hitboxY))) > obj->hitboxH + other->hitboxH)
        return 0;
    if (dx < 0)
        r = -w;
    else
        r = obj->hitboxX + (other->hitboxW - other->hitboxX);
    obj->h->p.whole = other->h->p.whole + r;
    obj->unk9D = r < 0 ? 2 : 3;
    return 2;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056804);
s32 func_80056804(GameObject *obj, GameObject *other)
{
    s16 w;
    s16 dy;
    s16 t;
    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    if (obj->animFrame & 1)
        w = obj->hitboxX;
    else
        w = obj->hitboxW - obj->hitboxX;
    if ((u16)(obj->h->p.whole - other->h->p.whole + (other->hitboxX + w)) > other->hitboxW + obj->hitboxW)
        return 0;
    dy = obj->y.p.whole - other->y.p.whole;
    t = other->hitboxY + (obj->hitboxH - obj->hitboxY);
    if ((u16)(dy + t) > obj->hitboxH + other->hitboxH)
        return 0;
    if (dy <= 0) {
        if (obj->unk9C & 1)
            return 0;
        obj->y.p.whole = other->y.p.whole - t;
        obj->y.p.frac = 0;
        obj->touchFlag = 1;
        return 1;
    }
    if (obj->category == 2 && *(u16 *)&obj->state == 0x102)
        return 0;
    obj->y.p.whole = other->y.p.whole + (obj->hitboxY + (other->hitboxH - other->hitboxY));
    return 3;
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056970);
#define B0(p) ((u16)(p)->hitboxX)
#define B2(p) ((u16)(p)->hitboxY)

void func_80056970(GameObject *obj, GameObject *other)
{
    s16 ox;
    s16 w;
    s16 r;
    s16 v;
    s16 dx;
    s16 adx;
    s16 b1;

    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b) return;
    if (obj->animFrame & 1) ox = B0(obj); else ox = (u16)obj->hitboxW - B0(obj);
    w = B0(other) + ox;
    r = w;
    dx = obj->h->p.whole - other->h->p.whole;
    adx = dx;
    if ((u16)(dx + w) > other->hitboxW + (b1 = obj->hitboxW)) return;
    if ((u16)(obj->y.p.whole - other->y.p.whole + (B2(other) + (obj->hitboxH - B2(obj)))) > obj->hitboxH + other->hitboxH) return;
    v = r;
    if (dx < 0) {
        adx = -dx;
        r = -w;
    } else {
        if (obj->animFrame & 1) ox = b1 - B0(obj); else ox = B0(obj);
        r = ox + ((u16)other->hitboxW - B0(other));
        v = r;
    }
    if ((u16)(v - adx) < 9) {
        if (obj->unk68) {
            other->unk68 = obj->unk68;
            other->animFrame = obj->animFrame & 1;
            obj->unk68 = 0;
        }
        obj->h->p.whole = other->h->p.whole + r;
        if ((s16)r < 0) obj->unk9D = 2;
        else obj->unk9D = 3;
        return;
    }
    if (obj->unk9C & 1) return;
    (*(s16 *)&SPAD->listCounter) = 0;
    obj->y.p.whole = other->y.p.whole - (B2(other) + (obj->hitboxH - B2(obj)));
    obj->y.p.frac = 0;
    obj->touchFlag = 1;
    if (obj->category == 2) {
        switch (obj->type) {
        case 2:
            other->touchFlag = 2;
            break;
        case 0x22:
            obj->active = 2;
            obj->subState = 5;
            break;
        }
    }
}
#undef B0
#undef B2

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056BBC);
void func_80056BBC(GameObject *obj, GameObject *other)
{
    if (obj->type == 0x22 || obj->type == 0x2c) {
        if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) < 0x5b) {
            if ((u16)(other->hitboxX + (obj->h->p.whole - other->h->p.whole)) <= other->hitboxW) {
                if ((u16)(other->hitboxY + (obj->y.p.whole - other->y.p.whole)) <= other->hitboxH) {
                    obj->active = 2;
                    setObjState(obj, 2, 0, 0);
                    other->step++;
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
static __inline__ s16 hit_56D24(GameObject *obj, GameObject *other)
{
    if ((u16)(obj->d->p.whole - other->d->p.whole + 45) > 90)
        return 0;
    if ((u16)((obj->h->p.whole - other->h->p.whole) + (other->hitboxX + (obj->hitboxW - obj->hitboxX))) > other->hitboxW + obj->hitboxW)
        return 0;
    if ((u16)((obj->y.p.whole - other->y.p.whole) + (other->hitboxY + (obj->hitboxH - obj->hitboxY))) <= obj->hitboxH + other->hitboxH)
        return 1;
    return 0;
}
void func_80056D24(GameObject *obj, GameObject *other)
{
    if (hit_56D24(obj, other)) {
        other->unk68 = 1;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_80056E00);
#define CNT (SPAD->actorDrawCount)
#define LST ((*(u8 ** *)&SPAD->actorDrawList))

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
        n = SCRATCHPAD.actorDrawCount;
        pp = SCRATCHPAD.actorDrawList;
        while (n != 0) {
            o = *pp++;
            n--;
            if ((o[0] & 3) && o[2] == 7 && o[3] != 0 && o[0xc] == 1 && o[0x69] == 0) {
                qq = SCRATCHPAD.itemDrawList;
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
void func_8012608C(GameObject *o);
void func_8012738C(GameObject *o);

void func_80057188(void)
{
    extern void func_8011ED98(GameObject *obj);
    extern void func_8011ED24(GameObject *obj);
    s16 n;
    GameObject **list;
    GameObject **l2;
    GameObject *obj;
    GameObject *other;
    s16 d;
    u8 two;
    n = (*(u16 *)&SPAD->actorDrawCount);
    list = (*(GameObject ** *)&SPAD->actorDrawList);
    if ((*(s16 *)&SPAD->areaDrawCount) == 0) return;
    if (n == 0) return;
    do {
        obj = *list++;
        n--;
        if (obj->active != 2 && D_8007EDFC[obj->type] != 0) {
        l2 = (*(GameObject ** *)&SPAD->areaDrawList);
        if ((D_1F80019E = SPAD->areaDrawCount) != 0)
        do {
            other = *l2++;
            D_1F80019E--;
            if (!(other->active & 1)) continue;
            switch (other->type) {
            case 0: two = 2; ((void (*)(GameObject *obj))func_80056970)(obj); break;
            case 1: func_80125E94(obj); break;
            case 2: func_80125FA4(obj); break;
            case 4:
                switch (GAME.selectedArea) {
                case 0: ((void (*)(GameObject *obj))func_80125FE8)(obj); break;
                case 3: ((void (*)(GameObject *obj))func_8011F67C)(obj); break;
                }
                break;
            case 6: func_801260C0(obj); break;
            case 10: func_8012608C(obj); break;
            case 15: func_80127414(obj); break;
            case 20: func_80127314(obj); break;
            case 28: func_801209E4(obj); break;
            case 32:
                if (obj->type == 0x22 || obj->type == 0x2c) {
                    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) < 0x5b) {
                        if ((u16)(other->hitboxX + (obj->h->p.whole - other->h->p.whole)) <= other->hitboxW) {
                            if ((u16)(other->hitboxY + (obj->y.p.whole - other->y.p.whole)) <= other->hitboxH) {
                                two = 2;
                                obj->active = two;
                                setObjState(obj, two, 0, 0);
                                other->step++;
                            }
                        }
                    }
                }
                break;
            case 33: func_8012738C(obj); break;
            case 35: func_80126BC4(obj); break;
            case 40: func_801203D4(obj); break;
            case 31: func_8011ED24(obj); break;
            case 34: func_8011F720(obj); break;
            case 66:
            case 67: func_8011C840(obj); break;

            case 52: func_80120CB4(obj); break;
            case 51: func_80120D60(obj); break;
            case 30: func_8011ED98(obj); break;
            }
        } while (D_1F80019E != 0);
        }
    } while (n != 0);
}

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_800574BC);
void func_8011ED98(GameObject *o, GameObject *e);
void func_8011ED24(GameObject *o, GameObject *e);

static __inline__ s16 hit_574BC(GameObject *obj, GameObject *other)
{
    if ((u16)(obj->d->p.whole - other->d->p.whole + 0x2d) >= 0x5b)
        return 0;
    if ((u16)((obj->h->p.whole - other->h->p.whole) + (other->hitboxX + (obj->hitboxW - obj->hitboxX))) > other->hitboxW + obj->hitboxW)
        return 0;
    if ((u16)((obj->y.p.whole - other->y.p.whole) + (other->hitboxY + (obj->hitboxH - obj->hitboxY))) > obj->hitboxH + other->hitboxH)
        return 0;
    return 1;
}

void func_800574BC(void)
{
    s16 n;
    GameObject **pp, **qq;
    GameObject *obj, *other;

    n = D_1F800248;
    pp = SCRATCHPAD.itemDrawList;
    if ((*(s16 *)&SCRATCHPAD.areaDrawCount) == 0)
        return;
    while (n != 0) {
        obj = *pp++;
        n--;
        if (!(obj->active & 1))
            continue;
        qq = SCRATCHPAD.areaDrawList;
        for (D_1F80019E = (*(s16 *)&SCRATCHPAD.areaDrawCount); D_1F80019E != 0; ) {
            other = *qq++;
            D_1F80019E--;
            if (!(other->active & 1))
                continue;
            switch (other->type) {
            case 0: func_80056970(obj, other); break;
            case 1: func_80125E94(obj, other); break;
            case 2: func_80125FA4(obj, other); break;
            case 4:
                switch (GAME.selectedArea) {
                case 0: func_80126048(obj, other); break;
                case 3: func_8011F6DC(obj, other); break;
                }
                break;
            case 6: func_801260C0(obj, other); break;
            case 0xf: func_80127414(obj, other); break;
            case 0x14: func_80127314(obj, other); break;
            case 0x1c: func_801209E4(obj, other); break;
            case 0x23: func_80126BC4(obj, other); break;
            case 0x28: func_801203D4(obj, other); break;
            case 0x1f: func_8011ED24(obj, other); break;
            case 0x22: func_8011F720(obj, other); break;
            case 0x1b:
                if (hit_574BC(obj, other))
                    other->unk68 = 1;
                break;
            case 0x34: func_80120CB4(obj, other); break;
            case 0x33: func_80120D60(obj, other); break;
            case 0x1e: func_8011ED98(obj, other); break;
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

extern const u32 D_80014CBC_ro[] asm("D_80014CBC");
extern const u32 D_80014CC4_ro[] asm("D_80014CC4");
extern const u32 D_80014CD0_ro[] asm("D_80014CD0");

const u32 D_80014C8C_ro[] asm("D_80014C8C") = { (u32)D_80014CBC_ro };
const u32 D_80014C90_ro[] asm("D_80014C90") = { (u32)D_80014CC4_ro };
const u32 D_80014C94_ro[] asm("D_80014C94") = {
    0x00000000, 0x00020000, 0x00000001, 0x00020000,
    0x00000002, 0x00020000, 0x00000003, 0x80020000,
};
const u32 D_80014CB4_ro[] asm("D_80014CB4") = { 0x00000004, 0x80020000 };
const u32 D_80014CBC_ro[] asm("D_80014CBC") = { 0x00000005, 0x803C0000 };
const u32 D_80014CC4_ro[] asm("D_80014CC4") = { 0x00000006, 0x803C0000, (u32)D_80014CD0_ro };
const u32 D_80014CD0_ro[] asm("D_80014CD0") = { 0x001A0052, 0x80050000 };

// INCLUDE_ASM("nonmatchings/main/game/actor2", func_8005788C);
typedef struct S_5788C { char p[0xc]; u8 b0c; } S_5788C;
extern void func_80117884(S_5788C *);
extern void func_80129BE0(S_5788C *);
extern void func_801287D4(S_5788C *);
extern void func_8012EDFC(S_5788C *);
extern void func_801164F4(S_5788C *);
extern void func_80118C0C(S_5788C *);
extern void func_801172B0(S_5788C *);
extern void func_8011784C(S_5788C *);
extern void func_80117364(S_5788C *);
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
