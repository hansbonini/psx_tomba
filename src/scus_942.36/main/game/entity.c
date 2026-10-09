#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022C08);
extern u16 D_1F800176;
extern u16 D_1F800186;
void pushDrawListLayer1(GameObject *o);
void pushDrawListMain(GameObject *o);
void pushDrawListCapped(GameObject *o);
void pushDrawListLayer4(GameObject *o);
void pushDrawListLayer5(GameObject *o);
void pushDrawListLayer7(GameObject *o);
void pushDrawListLayer8(GameObject *o);

s32 func_80022C08(GameObject *o, s32 x)
{
    if (o->active == 0) return 0;
    o->visible = 0;
    if ((u16)(o->h->p.whole - D_1F800176 + x) > (s16)x * 2 + 0x140) return 0;
    if ((u16)(D_1F800186 - o->y.p.whole + x) > (s16)x * 2 + 0xf0) return 0;
    o->visible = 1;
    switch (o->category & 0x7f) {
    case 1: pushDrawListLayer1(o); return 1;
    case 2: pushDrawListMain(o); return 1;
    case 3: pushDrawListCapped(o); return 1;
    case 4: pushDrawListLayer4(o); return 1;
    case 5: pushDrawListLayer5(o); return 1;
    case 7: pushDrawListLayer7(o); return 1;
    case 8: pushDrawListLayer8(o);
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022D3C);
extern u16 D_1F800176;
void pushDrawListLayer1(GameObject *o);
void pushDrawListMain(GameObject *o);
void pushDrawListCapped(GameObject *o);
void pushDrawListLayer4(GameObject *o);
void pushDrawListLayer5(GameObject *o);
void pushDrawListLayer7(GameObject *o);
void pushDrawListLayer8(GameObject *o);

s32 func_80022D3C(GameObject *o, s32 x)
{
    if (o->active == 0) return 0;
    o->visible = 0;
    if ((u16)(o->h->p.whole - D_1F800176 + x) > (s16)x * 2 + 0x140) return 0;
    o->visible = 1;
    switch (o->category & 0x7f) {
    case 1: pushDrawListLayer1(o); return 1;
    case 2: pushDrawListMain(o); return 1;
    case 3: pushDrawListCapped(o); return 1;
    case 4: pushDrawListLayer4(o); return 1;
    case 5: pushDrawListLayer5(o); return 1;
    case 7: pushDrawListLayer7(o); return 1;
    case 8: pushDrawListLayer8(o);
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022E44);
s32 func_80022E44(u8 *o)
{
    if (o[0] == 0)
        return 0;
    o[1] = 0;
    if ((u16)(*(u16 *)(*(s32 *)(o + 0x40) + 2) - D_1F800176 + 0x40) >= 0x1c1)
        return 0;
    if ((u16)(D_1F800186 - *(u16 *)(o + 0x16) + 0x40) >= 0x171)
        return 0;
    o[1] = 1;
    switch (o[0x1c] & 0x7f) {
    case 1: pushDrawListLayer1(o); return 1;
    case 2: pushDrawListMain(o); return 1;
    case 3: pushDrawListCapped(o); return 1;
    case 4: pushDrawListLayer4(o); return 1;
    case 5: pushDrawListLayer5(o); return 1;
    case 7: pushDrawListLayer7(o); return 1;
    case 8: pushDrawListLayer8(o);
    default: return 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022F6C);
typedef struct P_22F6C { s16 x; u16 y; } P_22F6C;
typedef struct S_22F6C { u8 on; char p[0x15]; u16 z; char q[0x28]; P_22F6C *pos; } S_22F6C;
static __inline__ s32 vis_22F6C(void *q)
{
    S_22F6C *p = q;
    if (p->on == 0) return 0;
    if ((u16)(p->pos->y - *(u16 *)0x1F800176 + 0x40) >= 0x1c1) return 0;
    return (u16)(*(u16 *)0x1F800186 - p->z + 0x40) < 0x171;
}
s32 func_80022F6C(S_22F6C *o)
{
    return vis_22F6C(o);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", isOnScreen);
s32 isOnScreen(s16 x, s16 y)
{
    if ((u16)(x - D_1F800176 + 0x40) < 0x1C1) {
        return (u16)(D_1F800186 - y + 0x40) < 0x171;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800230BC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", angleFromDelta);
s32 angleFromDelta(s32 a, s32 b)
{
    s32 q;
    if (a == 0) {
        if (b < 0) return 0x40;
        return 0xc0;
    }
    if (b == 0) return (a < 1) << 7;
    if (a > 0) {
        if (b < 1) {
            if (b + a > 0) {
                q = (b << 16) / a >> 11;
                return -q;
            }
            goto L1;
        }
        if (b - a > 0) goto L2;
        q = (b << 16) / a >> 11;
        if (q == 0) return 0;
        return 0x100 - q;
    } else {
        if (b < 1) {
            if (b - a <= 0) {
L1:
                q = (a << 16) / b >> 11;
                return q + 0x40;
            }
        } else {
            if (b + a > 0) {
L2:
                q = (a << 16) / b >> 11;
                return q + 0xc0;
            }
        }
        q = (b << 16) / a >> 11;
        return 0x80 - q;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", angleBetweenPoints);

s32 angleBetweenPoints(Vec2s a, Vec2s b) {
    if (a.x == b.x && a.y == b.y) {
        return 0;
    }
    return angleFromDelta(b.x - a.x, b.y - a.y);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", setObjectAxisPointers);
void setObjectAxisPointers(u8* self)
{
    if ((*(u16*)0x1F8001C8 & 1) == 0) {
        *(u8**)(self + 0x40) = self + 0x10;
        *(u8**)(self + 0x44) = self + 0x18;
    } else {
        *(u8**)(self + 0x44) = self + 0x10;
        *(u8**)(self + 0x40) = self + 0x18;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800233B8);
typedef struct { u8 act; char p01[0xf]; char a10[8]; char a18[0x28]; void *p40; void *p44; char rest[0xec - 0x48]; } S1_233B8;
typedef struct { u8 act; char p01[0xf]; char a10[8]; char a18[0x28]; void *p40; void *p44; char rest[0xd4 - 0x48]; } S2_233B8;
typedef struct { u8 act; char p01[0xf]; char a10[8]; char a18[0x28]; void *p40; void *p44; char rest[0x6c - 0x48]; } S3_233B8;
extern s16 D_1F80019C;
extern char D_1F8000EC[];
extern void *D_800A38EC;
extern void *D_800A38F0;
void func_800233B8(void)
{
    S2_233B8 *e2;
    S3_233B8 *e3;
    S1_233B8 *e1;
    char *b = PLAYER;
    if (!(D_1F8001C8 & 1)) {
        D_800A53D8 = b + 0x10;
        D_800A53DC = b + 0x18;
    } else {
        D_800A53DC = b + 0x10;
        D_800A53D8 = b + 0x18;
    }
    if (!(D_1F8001C8 & 1)) {
        D_800A38EC = D_1F8000EC;
        D_800A38F0 = D_1F8000EC + 8;
    } else {
        D_800A38F0 = D_1F8000EC;
        D_800A38EC = D_1F8000EC + 8;
    }
    e1 = ((S1_233B8 *)&D_800B07D8);
    for (D_1F80019C = 0; D_1F80019C < 4; D_1F80019C++, e1++) {
        if (e1->act) {
            if (!(D_1F8001C8 & 1)) {
                e1->p40 = e1->a10;
                e1->p44 = e1->a18;
            } else {
                e1->p44 = e1->a10;
                e1->p40 = e1->a18;
            }
        }
    }
    e2 = ((S2_233B8 *)&D_800A5970);
    for (D_1F80019C = 0; D_1F80019C < 200; D_1F80019C++, e2++) {
        if (e2->act) {
            if (!(D_1F8001C8 & 1)) {
                e2->p40 = e2->a10;
                e2->p44 = e2->a18;
            } else {
                e2->p44 = e2->a10;
                e2->p40 = e2->a18;
            }
        }
    }
    e3 = ((S3_233B8 *)&D_800A3D08);
    for (D_1F80019C = 0; D_1F80019C < 10; D_1F80019C++, e3++) {
        if (e3->act) {
            if (!(D_1F8001C8 & 1)) {
                e3->p40 = e3->a10;
                e3->p44 = e3->a18;
            } else {
                e3->p44 = e3->a10;
                e3->p40 = e3->a18;
            }
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023608);

s32 func_80023608(s32 n)
{
    s32 q = n / 32;
    s32 r = n % 32;
    s32 k;
    if (GAME.selectedArea == 0x10)
        k = 7;
    else if (GAME.selectedArea == 0x11)
        k = 0xc;
    else
        k = GAME.selectedArea;
    return D_8009BCFC[k][q] & (1 << r);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_8002367C);

void func_8002367C(s32 bit)
{
    s32 w, b;
    u32 k;

    w = bit / 32;
    b = bit % 32;
    if (GAME.selectedArea == 0x10)
        k = 7;
    else if ((k = GAME.selectedArea) == 0x11)
        k = 0xc;
    D_8009BCFC[k][w] |= 1 << b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800236F4);
typedef struct { u16 a; u16 pad[0x118]; u16 bits[2]; } S_236F4;

s32 func_800236F4(s32 n)
{
    s32 i;
    s32 s = 0;
    s32 m;
    for (i = 0; i < GAME.selectedArea; i++) s += ((u16 *)&D_8007B294)[i];
    s += (*(S_236F4 *)&D_8009BCCA).a;
    if (n >= 32) s++;
    m = n % 32;
    return *(s32 *)&(*(S_236F4 *)&D_8009BCCA).bits[s * 2] & (1 << m);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023794);
void func_80023794(s32 p)
{
    char pad;
    s32 i, s = 0, r;
    u16 *q;
    s32 *b;
    for (i = 0; i < (s32)GAME.selectedArea; i++)
        s += ((u16 *)&D_8007B294)[i];
    q = &D_8009BCCA;
    s += *q;
    if (p >= 0x20) s++;
    r = p % 32;
    b = (s32 *)((char *)q + 0x232);
    b[s] |= 1 << r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", insertionSortU32);
void insertionSortU32(s32 n, u32* arr)
{
    s32 i;
    s32 j;
    u32 key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", spawnLayer3Object);
void spawnLayer3Object(u8 arg0, s16 arg1, s16 arg2, s16 arg3)
{
    u8* p = allocObjectLayer3();

    if (p != NULL) {
        p[0] = 1;
        p[2] = arg0;
        *(s32*)(p + 0x10) = arg1 << 16;
        *(s32*)(p + 0x14) = arg2 << 16;
        *(s32*)(p + 0x18) = arg3 << 16;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023928);
extern u32 D_8009BEFC[];
extern GameObject *allocObjectLayer2(void);

GameObject *func_80023928(GameObject *p)
{
    s32 i, n, k;
    GameObject *o;
    char pad;
    k = p->subtype;
    n = 0;
    for (i = 0; i < GAME.selectedArea; i++) {
        n += ((u16 *)&D_8007B294)[i];
    }
    n += D_8009BCCA;
    if (k >= 32) n++;
    { s32 s = k % 32; if (D_8009BEFC[n] & (1 << s)) return 0; }
    if (p->state != 2) return 0;
    o = allocObjectLayer2();
    if (o == 0) return 0;
o->type = p->active;
o->subtype = p->visible;
o->active = 2;
o->unkC = p->type | 0x80;
    o->objectIndex = p->subtype;
    return o;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", loadCollisionBounds);
void loadCollisionBounds(void)
{
    s32 i = (s16)D_8009E744 * 4;

    D_1F8003C4 = D_8007B2C4[i];
    D_1F8003C6 = D_8007B2C6[i];
    D_1F8003C8 = D_8007B2C8[i];
    D_1F8003CA = D_8007B2CA[i];
}
