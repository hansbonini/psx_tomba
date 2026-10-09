#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", addPlayerAP);
void addPlayerAP(int arg0) {
    u_long* ptr;
	char *mytemp;
    int i = 0;
    
    do
    {
        if ((GAME.playerAP < D_8007C290[i] && (D_8007C290[i] <= (GAME.playerAP + arg0)))) {
            GAME.unk13 = (i + 2);
            GAME.playerLives += 3;
            if (GAME.playerLives > 99) {
                GAME.playerLives = 99;
            }
        }
        i++;
    } while(D_8007C290[i] != -1); 
    GAME.playerAP += arg0;
    mytemp = D_800B07AC;
    *mytemp++ = (GAME.playerAP / 10000000) % 10;
    *mytemp++ = (GAME.playerAP / 1000000 ) % 10;
    *mytemp++ = (GAME.playerAP / 100000  ) % 10;
    *mytemp++ = (GAME.playerAP / 10000   ) % 10;
    *mytemp++ = (GAME.playerAP / 1000    ) % 10;
    *mytemp++ = (GAME.playerAP / 100     ) % 10;
    *mytemp++ = (GAME.playerAP / 10      ) % 10;
    *mytemp++ = (GAME.playerAP / 1       ) % 10;
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", spawnItemNotification);
void spawnItemNotification(s32 arg0, u8 arg1)
{
    u8* p;

    D_800B07CC[arg0] = arg1;
    p = allocObjectLayer3();
    if (p != NULL) {
        p[0] = 1;
        p[2] = 0x20;
        p[0xC] = arg0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", addItemToInventory);
u_char addItemToInventory(u_long item_id, u_char qty, bool printMessage)
{
    int i;
    
    for(i = 0; D_8007C2B8[i].first != sizeof(GAME.item)-1; ++i)
    {
        if (D_8007C2B8[i].first == item_id)
        {
            if (D_8007C2B8[i].second <= GAME.item[item_id])
            {
                return GAME.item[item_id];
            }
        }
    }
    if (printMessage != false) {
        printInfoMessage(item_id, MSG_TYPE_ITEM);
    }
    for(i = 0; i < GAME.inventory.counter; ++i)
    {
        if (GAME.inventory.slots[i] == item_id)
        {
            GAME.item[item_id] = GAME.item[item_id] + qty;
            playSFX(10);
            return GAME.item[item_id];
        }
    }
    for(i = GAME.inventory.counter - 1; i >= 0; --i)
    {
        GAME.inventory.slots[i+1] = GAME.inventory.slots[i];
    }
    GAME.inventory.slots[0] = item_id;
    GAME.item[item_id] = qty;
    GAME.inventory.counter += 1;
    playSFX(10);
    GAME.inventory.sortMode |= INVENTORY_SORT_MODE_DEFAULT;
    return GAME.item[item_id];
}

int removeItemFromInventory(ITEM id, int qty)
{
    int i;
    for (i = 0; i < GAME.inventory.counter; i++) {
        if (GAME.inventory.slots[i] == id) {
            if (qty == -1) {
                GAME.item[id] = 0;
                while (i < GAME.inventory.counter - 1) {
                    GAME.inventory.slots[i] = GAME.inventory.slots[i+1];
                    i++;
                }
                GAME.inventory.counter -= 1;
                return 0;
            }
            GAME.item[id] = GAME.item[id] - qty;
            if (GAME.item[id] == 0) {
                GAME.item[id] = 0;
                while (i < GAME.inventory.counter - 1) {
                    GAME.inventory.slots[i] = GAME.inventory.slots[i+1];
                    i++;
                }
                GAME.inventory.counter -= 1;
                return 0;
            }
            return GAME.item[id];
        }
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", increaseMaxHealth);
u_long increaseMaxHealth(void)
{
    if (GAME.goldenBowlState == 0) {
        if (GAME.playerHealthDisplayed < 8) {
            GAME.playerHealthDisplayed++;
        } else {
            GAME.bonusHealth++;
        }
    } else {
        if (GAME.playerHealthDisplayed < 16) {
            GAME.playerHealthDisplayed++;
        }
    }
    GAME.playerHealth = D_800A5432 = D_800A5430 = GAME.playerHealthDisplayed;
    return GAME.playerHealthDisplayed;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", applyGoldenBowl);
u8 applyGoldenBowl(void)
{
    u8 health;

    if ((u8) GAME.playerHealthDisplayed < 0x10U) {
        health = GAME.playerHealthDisplayed + GAME.bonusHealth;
        GAME.playerHealthDisplayed = health;
        if ((u32) (health & 0xFF) >= 0x11U) {
            GAME.playerHealthDisplayed = 0x10;
        }
        printInfoMessage(ITEM_GOLDENBOWL, MSG_TYPE_ITEM);
        playSFX(10);
        (u16*)D_800A5430 = GAME.playerHealthDisplayed;
        D_800A5432 = GAME.playerHealthDisplayed;
        GAME.playerHealth = GAME.playerHealthDisplayed;
    }
    GAME.goldenBowlState = 1;
    D_800B078C = (u8* ) &D_800121C8;
    return GAME.playerHealth;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", tryStartItemInteraction);
int tryStartItemInteraction(int arg0, char arg1, int arg2) {
    GAME.disableSelectMenu = 0;
    if ((GAME.playerEquips.weapon != 3) && (GAME.fadeScreenControl != 2)) {
        GAME.playerEquips.weapon = 0;
        *(u_char*)(arg0 + 3) = arg1;
        (*(u_char*)(arg0 + 5))++;
        D_8009BCEA = arg2 & 0xFF;
        GAME.disableSelectMenu = 1;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", updateInventoryOverlay);
void updateInventoryOverlay(void)
{
    if (*(u_char*)&D_800A38B8 != 0) {
        func_8002D784(&D_800A38B8);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepPlayerXToward);
s32 stepPlayerXToward(s32 arg0) {
    s16* p = D_800A53D8;
    u16 x = p[1];
    s32 target = arg0;
    s16 d = x - arg0 + 3;

    if ((u16)d >= 7) {
        if (d < 0) {
            p[1] = x + 3;
        } else {
            p[1] = x - 3;
        }
        return 0;
    }
    p[1] = target;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029CDC);
typedef struct {
    char p0[7]; u8 step;
    char p8[0x20 - 8]; s32 d20; s32 d24;
    char p28[0x3f - 0x28]; u8 b3f;
    char p40[0x4a - 0x40]; s16 w4a, w4c; s16 w4e; s16 w50, w52; s16 w54; s16 w56;
    s16 w58; s16 w5a; s16 w5c; s16 w5e, w60, w62;
} S_29CDC;
#define F6 D_1F8000F6[0]

static __inline__ s32 body_29CDC(S_29CDC *s)
{
    s32 r;
    s16 n, v;
    volatile s16 *ee;
    r = 0;
    switch (s->step) {
    case 0:
        ee = D_1F8000EE;
        s->w4c -= *ee;
        s->w50 -= F6;
        s->w52 = *ee;
        s->w56 = F6;
        s->w62 = 0;
        s->w5e = 0;
        s->w60 = 0;
        s->w4a = 0;
        s->w5a = 0;
        s->step++;
        break;
    case 1:
        if (s->w4a != 90) {
            s->w4a++;
            if (s->w4a == 26) {
                D_8009BCA4 = 0;
                D_8009BCDD = 3;
            }
            D_1F8000EE[0] = s->w52 + s->w4c * s->w4a / 90;
            F6 = s->w56 + s->w50 * s->w4a / 90;
        }
        n = s->w4a;
        if (n != 90) {
            if (n >= 45) n = 90 - n;
            if (n < 32) s->w60 = ((n & 0x38) << 1) | 0x80;
            else s->w60 = 0x120;
        } else {
            s->w60 = 0x80;
        }
        if (s->b3f == 0) {
            s->w5e += s->w60;
            if (s->w5e >= 0x5a00) {
                s->w5e = 0x5a00;
                s->w5a++;
            }
            if (s->w5e <= 0x2d00) goto inc;
            if (s->w5e >= 0x4600) goto dec;
        } else {
            s->w5e -= s->w60;
            if (s->w5e < -0x59ff) {
                s->w5e = -0x5a00;
                s->w5a++;
            }
            if (s->w5e >= -0x2d00) {
            inc:
                s->w62 += 0x80;
                if (s->w62 > 0x1200) s->w62 = 0x1200;
            } else if (s->w5e < -0x1bff) {
            dec:
                s->w62 -= 0x80;
                if (s->w62 < 0) s->w62 = 0;
            }
        }
        s->d24 = s->w5e;
        s->d20 = s->w62;
        if (s->w5a != 0 || D_8009BCDD == 1) s->step++;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

s32 func_80029CDC(S_29CDC *s)
{
    return body_29CDC(s);
}
#undef F6

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchAreaItemHandler);
void dispatchAreaItemHandler(s32 arg0)
{
    loadSectionHeight();
    switch (GAME.selectedArea) {
        case AREA00_VILLAGEOFALLBEGINNINGS:
            func_80115AA8(arg0);
            return;
        case AREA01_DWARFFOREST:
        case AREA07_DWARFFORESTPURIFIED:
            func_80115910(arg0);
            return;
        case AREA03_PHOENIXMOUNTAIN:
            func_801162C4(arg0);
            return;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A0A0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A240);
typedef struct { u8 b0; char p[0x15]; s16 w16; } S_2A240;
typedef struct { s16 w0; s16 w2; } P_2A240;
typedef struct { char p0[0x30]; s16 w30; s16 w32; P_2A240 *d34; } O_2A240;

void func_8002A240(O_2A240 *o)
{
    S_2A240 *s = &PLAYER;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        u16 x = o->d34->w2;
        s16 t;
        t = x - 0x90;
        if ((*(P_2A240 **)&D_800A53D8)->w2 < t) {
            (*(P_2A240 **)&D_800A53D8)->w2 = t;
        } else {
            t = x + 0x90;
            if (t < (*(P_2A240 **)&D_800A53D8)->w2)
                (*(P_2A240 **)&D_800A53D8)->w2 = t;
        }
        if ((*(s32 *)&GAME) == 0x2000E) {
            if (s->w16 < o->w30 - 0x54)
                s->w16 = o->w30 - 0x54;
        } else {
            if (s->w16 < o->w30 - 0x88)
                s->w16 = o->w30 - 0x88;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", syncObjectTargetY);
void syncObjectTargetY(u8* self)
{
    (*(s16**)(self + 0x38))[1] = PLAYER.obj.d->p.whole;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A334);
typedef struct {
    char p0[0x2c];
    s16 s2c, s2e, s30, s32;
    Fix16 *f34;
} S_2A334;
typedef struct { char p[0x14]; s32 d14; } G_2A334;

void func_8002A334(S_2A334 *o)
{
    Fix16 *f;
    G_2A334 *g;
    Fix16 *c;
    s32 v;

    if (D_8009BCA1 != 0) return;
    o->f34->raw = PLAYER.obj.h->raw;
    f = o->f34;
    g = &PLAYER;
    if (o->s2e < f->p.whole) {
        f->raw = o->s2e << 16;
        if (D_8009C618[0] != 3) {
            if (o->s2e + 150 < PLAYER.obj.h->p.whole) PLAYER.obj.h->p.whole = o->s2e + 150;
        }
    } else if (f->p.whole < o->s2c) {
        f->raw = o->s2c << 16;
        if (D_8009C618[0] != 3) {
            if (PLAYER.obj.h->p.whole < o->s2c - 150) PLAYER.obj.h->p.whole = o->s2c - 150;
        }
    }
    if (D_8009C618[0] < 3) {
        c = &D_1F8000F0;
        c->raw = g->d14;
        if (D_1F8000F0.p.whole > o->s32) {
            c->raw = o->s32 << 16;
        } else if (D_1F8000F0.p.whole < o->s30) {
            c->raw = o->s30 << 16;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A480);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A798);
typedef struct O_2A798 { char p0[0x14]; s32 y; char p1[0x2c-0x18]; s16 h2c; s16 h2e; char p2[0x34-0x30]; s32 *d34;
  char p3[0x3c-0x38]; u8 b3c; char p4[0x44-0x3d]; u16 h44; char p5[0x58-0x46]; u16 w58; } O_2A798;
typedef struct G_2A798 { char p0[0x9c]; u8 f9c; } G_2A798;

void func_8002A798(O_2A798 *o)
{
    u16 u;
    s32 base, t, d;
    u8 neg;
    G_2A798 *g;
    u = D_800A53C6 & 1;
    base = *o->d34 - 0x100000;
    g = &PLAYER;
    if (D_800A5434)
        u = o->w58;
    o->w58 = u;
    if (u)
        base += 0x200000;
    if (PLAYER.obj.unk9E == 3)
        t = D_800A53C8 << 16;
    else
        t = *(*(s32 **)&D_800A53D8);
    d = t - base;
    neg = d < 0;
    if (d > 0x20000) {
        o->b3c = 0;
        if (d < o->y) {
            if (d < 0x40000)
                o->y = d;
            else {
                o->y = 0x40000;
                o->b3c = 1;
            }
        } else {
            if (o->y < 0)
                o->y = 0;
            o->y += 0x2000;
        }
        *o->d34 += o->y;
        if (o->h2e < ((s16 *)o->d34)[1]) {
            *o->d34 = o->h2e << 16;
            o->y = 0;
            o->h44 |= 1;
        }
        return;
    }
    if (d < -0x20000) {
        o->b3c = 0;
        if (o->y < d) {
            if (d > -0x40000)
                o->y = d;
            else {
                o->y = -0x40000;
                o->b3c = 1;
            }
        } else {
            if (o->y > 0)
                o->y = 0;
            o->y -= 0x2000;
        }
        *o->d34 += o->y;
        if (((s16 *)o->d34)[1] < o->h2c) {
            *o->d34 = o->h2c << 16;
            o->y = 0;
            o->h44 |= 2;
        }
        return;
    }
    o->b3c = 0;
    if (!g->f9c)
        o->b3c = 1;
    o->y = d;
    *o->d34 += d;
    if (neg) {
        if (((s16 *)o->d34)[1] < o->h2c) {
            *o->d34 = o->h2c << 16;
            o->y = 0;
            o->h44 |= 2;
        }
    }
L:
    if (o->h2e < ((s16 *)o->d34)[1]) {
        *o->d34 = o->h2e << 16;
        o->y = 0;
        o->h44 |= 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A9FC);
#define D34(o) (*(Fix16 **)&(o)->unk34)
#define W44(o) (*(u16 *)&(o)->d)

static __inline__ void body_2A9FC(GameObject *o)
{
    s32 d;
    u8 neg;
    d = D_1F80018C - D34(o)->raw;
    neg = d < 0;
    if (d > 0x20000) {
        if (d < o->y.raw) {
            if (d < 0x40000)
                o->y.raw = d;
            else
                o->y.raw = 0x40000;
        } else {
            if (o->y.raw < 0)
                o->y.raw = 0;
            o->y.raw += 0x2000;
        }
        { s32 y = o->y.raw; D34(o)->raw += y; }
    } else if (d < -0x20000) {
        if (o->y.raw < d) {
            if (d > -0x40000)
                o->y.raw = d;
            else
                o->y.raw = -0x40000;
        } else {
            if (o->y.raw > 0)
                o->y.raw = 0;
            o->y.raw -= 0x2000;
        }
        D34(o)->raw += o->y.raw;
        if (D34(o)->p.whole < (s16)o->animTimer) {
            D34(o)->raw = (s16)o->animTimer << 16;
            o->y.raw = 0;
            W44(o) |= 2;
        }
        return;
    } else {
        o->y.raw = d;
        D34(o)->raw += d;
        if (neg) {
            if (D34(o)->p.whole < (s16)o->animTimer) {
                D34(o)->raw = (s16)o->animTimer << 16;
                o->y.raw = 0;
                W44(o) |= 2;
            }
        }
    }
    if (D34(o)->p.whole > (s16)o->animFrame) {
        D34(o)->raw = (s16)o->animFrame << 16;
        o->y.raw = 0;
        W44(o) |= 1;
    }
}

void func_8002A9FC(GameObject *o)
{
    body_2A9FC(o);
}
#undef D34
#undef W44

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002ABC0);
typedef struct {
    char p0[0x18]; s32 v; char p1[0x30 - 0x1c]; s16 s30, s32; char p2[0x44 - 0x34]; u16 f44;
} O_2ABC0;
typedef union { s32 i; struct { s16 lo, hi; } s; } FX_2ABC0;
#define VF (*(volatile s32 *)&(*(FX_2ABC0 *)&D_1F8000F0).i)

static __inline__ void inl_2ABC0(O_2ABC0 *o)
{
    s32 d = D_1F800190 - VF;
    if (d >= 0) {
        if (d > 0x10000) {
            if (d < o->v) {
                if (d > 0x3ffff) o->v = 0x40000;
                else o->v = d;
            } else {
                if (o->v < 0) o->v = 0;
                o->v += 0x8000;
            }
            VF += o->v;
            if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi > o->s32) {
                (*(FX_2ABC0 *)&D_1F8000F0).i = o->s32 << 16;
                o->v = 0;
                o->f44 |= 8;
            }
        } else {
            VF = D_1F800190;
            if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi > o->s32) {
                (*(FX_2ABC0 *)&D_1F8000F0).i = o->s32 << 16;
                o->v = 0;
                o->f44 |= 8;
            }
        }
    } else {
        if (d < -0x40000) {
            if (o->v < d) {
                if (d > -0x40000) o->v = d;
                else o->v = -0x40000;
            } else {
                if (o->v > 0) o->v = 0;
                o->v -= 0x4000;
            }
        } else {
            o->v = d;
        }
        VF += o->v;
        if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi < o->s30) {
            (*(FX_2ABC0 *)&D_1F8000F0).i = o->s30 << 16;
            o->v = 0;
            o->f44 |= 4;
        }
    }
}

void func_8002ABC0(O_2ABC0 *o)
{
    inl_2ABC0(o);
}
#undef VF

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002AD74);
#define W(o) (*(s32 *)((o) + 0x18))

void func_8002AD74(u8 *o)
{
    extern void stepScrollApproachX(u8 *);
    s32 *p, t;
    switch (*(s16 *)(o + 0x5c)) {
    case 0:
        o[0x6d] = 0;
        *(s8 *)(o + 0x6f) = -10;
        (*(s16 *)(o + 0x5c))++;
    case 1:
        W(o) += 0x2000;
        if (W(o) > 0x3ffff)
            W(o) = 0x40000;
        if (W(o) > 0x12000)
            stepScrollApproachX(o);
        p = &D_1F8000F0;
        *p += W(o);
        if (D_1F8000F2 > *(s16 *)(o + 0x32)) {
            D_1F8000F0 = *(s16 *)(o + 0x32) << 16;
            W(o) = 0;
            *(u16 *)(o + 0x44) |= 8;
        }
        t = *p - D_1F800190;
        if (t > 0x580000)
            (*(s16 *)(o + 0x5c))++;
        break;
    case 2:
        W(o) += 0x2000;
        if (W(o) > 0x2ffff)
            W(o) = 0x30000;
        p = &D_1F8000F0;
        *p += W(o);
        if (D_1F8000F2 > *(s16 *)(o + 0x32)) {
            D_1F8000F0 = *(s16 *)(o + 0x32) << 16;
            W(o) = 0;
            *(u16 *)(o + 0x44) |= 8;
        }
        t = *p - D_1F800190;
        if (t <= 0)
            o[3] = 3;
        break;
    }
}
#undef W

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollReturnY);
s32 stepScrollReturnY(u8* self)
{
    s32 v = *(s32*)(self + 0x24);

    if (v != 0) {
        if (v > 0) {
            v -= 0x80;
        } else {
            v += 0x80;
        }
        *(s32*)(self + 0x24) = v;
        return 0;
    }
    self[0x71] = 0;
    self[0x72] = 0;
    self[0x73] = 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollApproachY);
s32 stepScrollApproachY(u8* self)
{
    s32 t;
    s32 cur;

    switch (*(s8*)(self + 0x71)) {
    case 0:
        t = *(s8*)(self + 0x73) << 8;
        cur = *(s32*)(self + 0x24);
        if (t < cur) {
            *(s32*)(self + 0x24) = cur - 0x80;
            return 0;
        }
        return 1;
    case 1:
        t = *(s8*)(self + 0x73) << 8;
        cur = *(s32*)(self + 0x24);
        if (cur >= t) {
            return 1;
        }
        *(s32*)(self + 0x24) = cur + 0x80;
        return 0;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollApproachX);
s32 stepScrollApproachX(u8* self)
{
    s32 t;
    s32 cur;

    switch (*(s8*)(self + 0x6D)) {
    case 0:
        t = *(s8*)(self + 0x6F) << 8;
        cur = *(s32*)(self + 0x20);
        if (t < cur) {
            *(s32*)(self + 0x20) = cur - 0x100;
            return 0;
        }
        return 1;
    case 1:
        t = *(s8*)(self + 0x6F) << 8;
        cur = *(s32*)(self + 0x20);
        if (cur >= t) {
            return 1;
        }
        *(s32*)(self + 0x20) = cur + 0x100;
        return 0;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dampCameraAngle);
s32 dampCameraAngle(void)
{
    s16* p = &D_1F8000E6;
    s16  v = *p;

    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            *p = v;
            if (v < 0) {
                *p = 0;
            }
        } else {
            v = v + 2;
            *p = v;
            if (v > 0) {
                *p = 0;
            }
        }
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollReturnX);
s32 stepScrollReturnX(u8* self)
{
    s32 v = *(s32*)(self + 0x20);

    if (v != 0) {
        if (v > 0) {
            v -= 0x100;
        } else {
            v += 0x100;
        }
        *(s32*)(self + 0x20) = v;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B278);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B3E8);
void func_8002B110();
void func_8002B278();

static __inline__ void decay_2B3E8(void)
{
    s16 v = D_1F8000E6;
    if (v == 0) return;
    if (v > 0) {
        v -= 2;
        D_1F8000E6 = v;
        if (v < 0) D_1F8000E6 = 0;
    } else {
        v += 2;
        D_1F8000E6 = v;
        if (v > 0) D_1F8000E6 = 0;
    }
}

void func_8002B3E8(char *o, s32 a)
{
    volatile u16 *k;

    if (D_800A5434 != 0) {
        decay_2B3E8();
        return;
    }
    k = D_8009C9D8;
    if (*k & 0x10) {
        if (a != 0 || *(s32 *)(o + 0x20) < -0x9ff) {
            func_8002B110(o, a);
            return;
        }
        decay_2B3E8();
    } else if (*k & 0x40) {
        if (a != 0 || *(s32 *)(o + 0x20) >= 0xa00) {
            func_8002B278(o, a);
            return;
        }
        decay_2B3E8();
    } else {
        decay_2B3E8();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollAndAngle);
s32 stepScrollAndAngle(u8* self)
{
    s32 w = *(s32*)(self + 0x20);
    s16 v;
    s32 a;
    s32 b;

    if (w != 0) {
        if (w > 0) {
            *(s32*)(self + 0x20) = w - 0x100;
        } else {
            *(s32*)(self + 0x20) = w + 0x100;
        }
        a = 1;
    } else {
        a = 0;
    }
    v = D_1F8000E6;
    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            D_1F8000E6 = v;
            if (v < 0) {
                D_1F8000E6 = 0;
            }
        } else {
            v = v + 2;
            D_1F8000E6 = v;
            if (v > 0) {
                D_1F8000E6 = 0;
            }
        }
        b = 1;
    } else {
        b = 0;
    }
    if ((a | b) != 0) {
        return 0;
    }
    self[0x6E] = 0;
    self[0x6F] = 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stepScrollClearX);
s32 stepScrollClearX(u8* self)
{
    s32 v = *(s32*)(self + 0x20);

    if (v != 0) {
        if (v > 0) {
            v -= 0x100;
        } else {
            v += 0x100;
        }
        *(s32*)(self + 0x20) = v;
        return 0;
    }
    self[0x6E] = 0;
    self[0x6F] = 0;
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B6A8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B704);
typedef struct { char p[0x24]; s32 d24; char q[0x70 - 0x28]; s8 b70, b71, b72, b73; } S_2B704;
static __inline__ s32 approach_2B704(S_2B704 *o)
{
    switch (o->b71) {
    case 0:
        if ((o->b73 << 8) < o->d24) {
            o->d24 -= 0x80;
            return 0;
        }
        return 1;
    case 1:
        if (o->d24 >= (o->b73 << 8)) return 1;
        o->d24 += 0x80;
        return 0;
    }
    return 0;
}
static __inline__ s32 decel_2B704(S_2B704 *o)
{
    s32 v = o->d24;
    if (v != 0) {
        if (v > 0) v -= 0x80;
        else v += 0x80;
        o->d24 = v;
        return 0;
    }
    o->b71 = 0;
    o->b72 = 0;
    o->b73 = 0;
    return 1;
}

void func_8002B704(S_2B704 *o)
{
    GameObject *p;
    if (D_8009BCA7) {
        if (o->d24 != 0) {
            if (o->d24 > 0) o->d24 -= 0x80;
            else o->d24 += 0x80;
        } else {
            o->b71 = 0;
            o->b72 = 0;
            o->b73 = 0;
        }
        return;
    }
    p = &PLAYER;
    switch (o->b70) {
    case 0:
        if (p->unkA4) {
            o->b70 = 5;
            if (p->animFrame & 1) {
                o->b71 = 0;
                o->b73 = -10;
            } else {
                o->b71 = 1;
                o->b73 = 10;
            }
            break;
        }
        switch (p->unk9E) {
        case 2: case 3: case 5: case 6: case 8: case 9:
            o->b70 = 1;
            if (p->animFrame & 1) {
                o->b71 = 1;
                o->b73 = 10;
            } else {
                o->b71 = 0;
                o->b73 = -10;
            }
            break;
        }
        break;
    case 1:
        if ((p->animFrame & 1) != o->b71) {
            o->b71 = p->animFrame & 1;
            o->b73 = -o->b73;
        }
        if (approach_2B704(o)) o->b70 = 2;
    case 2:
        switch (p->unk9E) {
        case 0: case 1: case 4: case 7: case 10: case 11: case 12:
            o->b70 = 3;
            o->b71 = 0;
            break;
        case 2: case 3: case 5: case 6: case 8: case 9:
            if ((p->animFrame & 1) != o->b71) {
                o->b70 = 1;
                o->b71 = p->animFrame & 1;
                o->b73 = -o->b73;
            }
            break;
        }
        break;
    case 3:
        if (decel_2B704(o)) o->b70 = 0;
        break;
    case 4:
        if (approach_2B704(o)) o->b70 = 0;
        break;
    case 5:
        if (approach_2B704(o)) o->b70++;
    case 6:
        if (!p->unkA4) o->b70++;
        break;
    case 7:
        if (decel_2B704(o)) o->b70 = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", handleLookScrollInput);
s32 handleLookScrollInput(u8* self)
{
    s8 st;

    if ((JOYPAD_STATE & JOY_UP) && D_800A5438 != 4) {
        st = *(s8*)(self + 0x6E);
        if (st == 1) {
            return 1;
        }
        if (st == 0) {
            self[0x6C] = 7;
            self[0x6E] = 1;
            self[0x6D] = 0;
            *(s8*)(self + 0x6F) = -0xA;
        } else {
            self[0x6C] = 7;
            self[0x6D] = 0;
            self[0x6E] = 0;
            self[0x6F] = 0;
        }
        return 0;
    }
    if (JOYPAD_STATE & JOY_DOWN) {
        st = *(s8*)(self + 0x6E);
        if (st == 2) {
            return 1;
        }
        if (st == 0) {
            self[0x6C] = 7;
            self[0x6D] = 1;
            self[0x6E] = 2;
            self[0x6F] = 0xA;
        } else {
            self[0x6C] = 7;
            self[0x6D] = 1;
            self[0x6E] = 0;
            self[0x6F] = 0;
        }
        return 0;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002BB9C);
typedef struct {
    char p0[0x20];
    s32 spd;
    char p24[0x30 - 0x24];
    s16 w30, w32;
    char p34[0x6c - 0x34];
    s8 b6c, b6d, b6e, b6f;
    char p70[0x75 - 0x70];
    u8 b75, b76, b77;
} S_2BB9C;
typedef struct {
    char p0[0x9e];
    u8 b9e;
    char p9f;
    union { s32 i; u8 b[4]; } a0;
} G_2BB9C;

static __inline__ s16 ramp_2BB9C(S_2BB9C *o)
{
    switch (o->b6d) {
    case 0:
        if (o->spd > o->b6f << 8) {
            o->spd -= 0x100;
            return 0;
        }
        return 1;
    case 1:
        if (o->spd >= o->b6f << 8) return 1;
        o->spd += 0x100;
        return 0;
    }
    return 0;
}

static __inline__ s32 decay_2BB9C(void)
{
    s16 v = D_1F8000E6;
    if (v != 0) {
        if (v > 0) {
            v -= 2;
            D_1F8000E6 = v;
            if (v < 0) D_1F8000E6 = 0;
        } else {
            v += 2;
            D_1F8000E6 = v;
            if (v > 0) D_1F8000E6 = 0;
        }
        return 1;
    }
    return 0;
}

static __inline__ void clamp_2BB9C(S_2BB9C *o)
{
    s16 f = D_1F8000F2;
    s32 s = f + D_1F8000E6;
    if (o->w30 > s) D_1F8000E6 = o->w30 - f;
    else if (o->w32 < s) D_1F8000E6 = o->w32 - f;
}

void func_8002BB9C(S_2BB9C *o)
{
    s32 f;
    G_2BB9C *g = &PLAYER;
    s32 a, b;
    u8 c;
    u8 t1, t2, t3;

    switch (o->b6c) {
    case 0:
        if (D_8009BCA2 == 0) break;
        if (D_8009BCA7 != 0) {
            o->b6c = 6;
            break;
        }
        if (!(g->a0.b[0] & 1) && g->a0.b[2] >= 2) {
            o->b6c = 8;
            o->b6e = 1;
            o->b6d = 0;
            o->b6f = -10;
            break;
        }
        if ((g->a0.i & 0xff000002) == 0x2000000) {
            o->b6c = 4;
            o->b6d = 1;
            o->b6e = 2;
            o->b6f = 10;
            break;
        }
        switch (g->b9e) {
        case 0:
            c = g->a0.b[0];
            if (c & 0x12) {
                if (D_8009C9D8[0] & 0xc00) {
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        if (o->b6e != 1) {
                            o->b6c = 7;
                            o->b6e = 1;
                            o->b6d = 0;
                            o->b6f = -10;
                        }
                    } else if ((D_1F8001FC & 0x40) && o->b6e != 2) {
                        o->b6c = 7;
                        o->b6d = 1;
                        o->b6e = 2;
                        o->b6f = 10;
                    }
                    func_8002B3E8(o, 0);
                } else if ((u8)c == 0x12) {
                    if (handleLookScrollInput(o) == 0) break;
                    decay_2BB9C();
                } else if (c & 0x10) {
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        f = 0;
                        if (o->b6e == 0) goto t2;
                        o->b6c = 7;
                        o->b6d = 0;
                        o->b6e = 0;
                        o->b6f = 0;
                    } else {
                        if (!(D_1F8001FC & 0x40)) goto t2;
                        if (o->b6e == 2) goto t2;
                        if (o->b6e == 0) {
                            o->b6c = 7;
                            o->b6d = 1;
                            o->b6e = 2;
                            o->b6f = 10;
                        } else {
                            o->b6c = 7;
                            o->b6d = 1;
                            o->b6e = 0;
                            o->b6f = 0;
                        }
                        f = 0;
                        if (0) {
                        t2:
                            f = 1;
                        }
                    }
                    if (f) decay_2BB9C();
                } else if (c & 2) {
                    if (c & 1) break;
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        if (o->b6e == 1) goto t1;
                        {
                            if (o->b6e == 0) {
                                o->b6c = 7;
                                o->b6e = 1;
                                o->b6d = 0;
                                o->b6f = -10;
                            } else {
                                o->b6c = 7;
                                o->b6d = 0;
                                o->b6e = 0;
                                o->b6f = 0;
                            }
                            f = 0;
                        }
                    } else {
                        f = 1;
                        if (D_1F8001FC & 0x40) {
                            f = 0;
                            if (o->b6e != 0) {
                                o->b6c = 7;
                                o->b6d = 1;
                                o->b6e = 0;
                                o->b6f = 0;
                            } else {
                            t1:
                                f = 1;
                            }
                        }
                    }
                    if (f) decay_2BB9C();
                }
            } else if (D_8009C9D8[0] & 0xc00) {
                handleLookScrollInput(o);
                func_8002B3E8(o, 0);
            } else {
                decay_2BB9C();
            }
            break;
        case 2:
            t1 = o->b6d;
            t2 = o->b6e;
            t3 = o->b6f;
            o->b6c = 1;
            o->b6d = 1;
            o->b6f = 10;
            o->b75 = t1;
            o->b76 = t2;
            o->b77 = t3;
            break;
        case 1:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
        default:
            if ((g->a0.b[0] & 0x12) || (D_8009C9D8[0] & 0xc00)) func_8002B3E8(o, 1);
            else decay_2BB9C();
            break;
        }
        break;
    case 1:
        if (ramp_2BB9C(o)) o->b6c = 2;
    case 2:
        if (g->b9e != 2) {
            o->b6c = 3;
            o->b6d = o->b75;
            o->b6f = o->b77;
            if (o->b6f == 0) o->b6d = 0;
        }
        decay_2BB9C();
        break;
    case 3:
        a = decay_2BB9C();
        if (ramp_2BB9C(o) && !a) {
            o->b6c = 0;
            o->b6e = o->b76;
        }
        break;
    case 4:
        if (ramp_2BB9C(o)) o->b6c++;
        clamp_2BB9C(o);
        break;
    case 5:
        clamp_2BB9C(o);
        if (g->a0.b[3] != 0) break;
        if ((g->a0.b[0] & 0x10) && (D_8009C9D8[0] & 0x40)) goto zero;
        if (D_8009BCCC > D_8009BCCD) goto zero;
        o->b6c = 7;
        o->b6d = 0;
        o->b6e = 0;
        o->b6f = 0;
        break;
    case 6:
        a = 0;
        if (o->spd != 0) {
            if (o->spd > 0) o->spd -= 0x100;
            else o->spd += 0x100;
            a = 1;
        }
        b = decay_2BB9C();
        if (!(a | b)) {
            o->b6e = 0;
            o->b6f = 0;
            b = 1;
        } else b = 0;
        if (b) o->b6c = 10;
        break;
    case 7:
        func_8002B3E8(o, 0);
        if (ramp_2BB9C(o)) o->b6c = 0;
        break;
    case 8:
        if (ramp_2BB9C(o)) o->b6c++;
        clamp_2BB9C(o);
        break;
    case 9:
        if (g->a0.b[2] != 0) break;
        if (g->a0.b[0] & 2) {
            if (D_8009C9D8[0] & 0x10) {
                if (!(g->a0.b[0] & 1)) o->b6c = 0;
                break;
            }
        }
        o->b6c = 7;
        o->b6d = 1;
        o->b6e = 2;
        o->b6f = 10;
        break;
    case 10:
        if (D_8009BCA7 != 0) break;
        if ((*(s16 *)&D_1F8001C8) == 0) {
            if (D_8009BCCC <= D_8009BCCD) {
                o->b6c = 0;
                break;
            }
        } else if (D_8009BCCC >= D_8009BCCD) {
            goto zero;
        }
        o->b6d = 1;
        o->b6e = 2;
        o->b6f = 10;
        o->b6c++;
        break;
    case 11:
        if (ramp_2BB9C(o)) {
        zero:
            o->b6c = 0;
        }
        break;
    }
    loadSectionHeight(o);
    switch (GAME.selectedArea) {
    case 0:
        func_80115AA8(o);
        break;
    case 1:
    case 7:
        func_80115910(o);
        break;
    case 3:
        func_801162C4(o);
        break;
    }
    if (D_1F8000F2 > o->w32) D_1F8000F0 = o->w32 << 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002C7D8);
typedef struct { u8 b0; char p0[0x15]; s16 w16; char p1[0x16]; u16 w2e; char p2[0x79]; u8 ba9; } S_2C7D8;
typedef struct { s16 w0; s16 w2; } P_2C7D8;
typedef struct {
    char p0[0x24]; s32 d24; char p1[8]; s16 w30; s16 w32; P_2C7D8 *d34; P_2C7D8 *d38;
    u8 b3c; u8 b3d; char p2[0x1a]; u16 w58;
} O_2C7D8;
extern u8 D_800A5436;

static __inline__ void Clamp_2C7D8(O_2C7D8 *o)
{
    S_2C7D8 *s = &PLAYER;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        u16 x = o->d34->w2;
        s16 t;
        t = x - 0x90;
        if ((*(P_2C7D8 **)&D_800A53D8)->w2 < t) {
            (*(P_2C7D8 **)&D_800A53D8)->w2 = t;
        } else {
            t = x + 0x90;
            if (t < (*(P_2C7D8 **)&D_800A53D8)->w2)
                (*(P_2C7D8 **)&D_800A53D8)->w2 = t;
        }
        if ((*(s32 *)&GAME) == 0x2000E) {
            if (s->w16 < o->w30 - 0x54)
                s->w16 = o->w30 - 0x54;
        } else {
            if (s->w16 < o->w30 - 0x88)
                s->w16 = o->w30 - 0x88;
        }
    }
}

void func_8002C7D8(O_2C7D8 *o)
{
    S_2C7D8 *s = &PLAYER;
    s32 t;
    if (D_8009BCA1 == 0) {
        switch (D_800A5436) {
        case 4:
            if ((*(u16 *)&GAME) != 10 && s->ba9 == 0)
                goto c4;
        case 0: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            func_8002A798(o);
            func_8002A480(o);
            o->b3d = 0;
            o->b3c = 0;
            break;
        c4:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798(o);
            func_8002A480(o);
            o->b3d = 0;
            break;
        case 3:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
            }
            func_8002A798(o);
            if (o->b3d == 0)
                func_8002A480(o);
            break;
        case 1: case 2: case 5:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798(o);
            if (o->b3d == 0)
                func_8002A480(o);
            break;
        }
        o->d38->w2 = (*(P_2C7D8 **)&D_800A53DC)->w2;
    }
    func_8002B704(o);
    func_8002BB9C(o);
    D_1F800286 = -o->d24 >> 6;
    Clamp_2C7D8(o);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CA40);
typedef struct S_2CA40 {
    char p0[0x20]; s32 vy; s32 vx; char p1[0x6e - 0x28];
    u8 b6e, b6f, b70, b71, b72, b73;
} S_2CA40;
void func_8002A9FC();
void func_8002ABC0();
void func_8002CA40(S_2CA40 *o)
{
    s32 f1, f2;
    s16 s;
    if (o->vx != 0) {
        if (o->vx > 0) o->vx -= 0x80;
        else o->vx += 0x80;
    } else {
        o->b71 = 0;
        o->b72 = 0;
        o->b73 = 0;
    }
    f1 = 0;
    if (o->vy != 0) {
        if (o->vy > 0) o->vy -= 0x100;
        else o->vy += 0x100;
        f1 = 1;
    }
    s = D_1F8000E6;
    if (s != 0) {
        if (s > 0) {
            D_1F8000E6 = s -= 2;
            if (s < 0) D_1F8000E6 = 0;
        } else {
            D_1F8000E6 = s += 2;
            if (s > 0) D_1F8000E6 = 0;
        }
        f2 = 1;
    } else {
        f2 = 0;
    }
    if ((f1 | f2) == 0) {
        o->b6e = 0;
        o->b6f = 0;
    }
    func_8002A9FC(o);
    func_8002ABC0(o);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", updateLookScroll);
void updateLookScroll(u8* self)
{
    s16 v = D_1F8000E6;
    s32 w;

    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            D_1F8000E6 = v;
            if (v < 0) {
                D_1F8000E6 = 0;
            }
        } else {
            v = v + 2;
            D_1F8000E6 = v;
            if (v > 0) {
                D_1F8000E6 = 0;
            }
        }
    }
    w = *(s32*)(self + 0x24);
    if (w != 0) {
        if (w > 0) {
            *(s32*)(self + 0x24) = w - 0x80;
        } else {
            *(s32*)(self + 0x24) = w + 0x80;
        }
    } else {
        self[0x71] = 0;
        self[0x72] = 0;
        self[0x73] = 0;
    }
    func_8002A9FC(self);
    func_8002AD74(self);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CC20);
typedef struct {
    u8 b0, b1, b2, b3;
    char p4[0x34 - 4];
    u16 *p34;
    char p38[0x44 - 0x38];
    u16 f44;
} S_2CC20;
extern u16 D_1F80016E;

void func_8002CC20(S_2CC20 *o)
{
    s16 v;
    o->f44 = 0;
    v = (*(SVECTOR *)&D_1F8000E6).vx;
    if (v != 0) {
        if (v > 0) {
            v -= 2;
            D_1F8000E6 = v;
            if (v < 0) D_1F8000E6 = 0;
        } else {
            v += 2;
            D_1F8000E6 = v;
            if (v > 0) D_1F8000E6 = 0;
        }
    }
    func_8002A798(o);
    func_8002A480(o);
    if ((u16)(o->p34[1] - (*(u16 *)&D_1F80016A) + 0x8c) < 0x118 || (o->f44 & 3)) {
        if ((u16)(D_1F8000F2 - D_1F80016E + 0xb4) < 0x168 || (o->f44 & 0xc)) {
            o->b3 = 1;
            if (D_8009BCCE == 3 || D_8009C10E == 0xff) o->b3 = 0;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            D_8009BCAA = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CD7C);
typedef struct {
    u8 b0, b1, b2, b3;
    char pad[0x34 - 4];
    u16 *p34;
    char pad2[0x44 - 0x38];
    u16 w44;
} S8002A258_2CD7C;
extern s16 D_1F8000E6_S16Arr[] asm("D_1F8000E6");

void func_8002CD7C(S8002A258_2CD7C *o)
{
    s16 v;
    o->w44 = 0;
    v = D_1F8000E6_S16Arr[0];
    if (v != 0) {
        if (v > 0) {
            D_1F8000E6 = v - 2;
            if (D_1F8000E6 < 0) D_1F8000E6 = 0;
        } else {
            D_1F8000E6 = v + 2;
            if (D_1F8000E6 > 0) D_1F8000E6 = 0;
        }
    }
    D_1F80018C = D_1F800168;
    D_1F800190 = D_1F80016C;
    func_8002A9FC(o);
    func_8002ABC0(o);
    if ((u16)(o->p34[1] - (*(u16 *)&D_1F80016A) + 0x40) < 0x80 || (o->w44 & 3)) {
        if ((u16)(D_1F8000F2 - D_1F80016E + 0x5a) < 0xb4 || (o->w44 & 0xc)) {
            o->b3 = 1;
            if (D_8009BCCE == 3 || D_8009C10E == 0xff) o->b3 = 0;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            D_8009BCAA = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CEF8);
extern u8 PLAYER_U8Arr[] asm("PLAYER");
static __inline__ void lim_2CEF8(s16 *q, s16 x, s32 k) { if (*q < x - k) *q = x - k; }
void func_8002CEF8(GameObject *o)
{
    s16 a, b;
    u8 *g;
    func_8002A798(o);
    func_8002A480(o);
    g = PLAYER_U8Arr;
    if (PLAYER.obj.active < 4 || PLAYER.obj.active == 7) {
        b = *(s16 *)(o->unk34 + 2);
        if (PLAYER.obj.h->p.whole < (a = b - 0x90)) PLAYER.obj.h->p.whole = a;
        else if ((a = b + 0x90) < PLAYER.obj.h->p.whole) PLAYER.obj.h->p.whole = a;
        if ((*(s32 *)&GAME) == 0x2000e) {
            lim_2CEF8((s16 *)(g + 0x16), *(s16 *)&o->unk30, 0x54);
        } else {
            lim_2CEF8((s16 *)(g + 0x16), *(s16 *)&o->unk30, 0x88);
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CFF4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionInit);
void dispatchSectionInit(void)
{
    switch (GAME.selectedSection) {
        case 0:
            func_800E7574();
            return;
        case 3:
            func_800E79F8();
            return;
        case 1:
        case 2:
        case 4:
        case 5:
            func_801156A8();
        default:
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionUpdate);
void dispatchSectionUpdate(void)
{
    switch (GAME.selectedSection) {
        case 2:
        case 0:
            func_800E7E70();
            return;
        case 1:
        case 3:
            func_80115234();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionDraw);
void dispatchSectionDraw(void)
{
    switch (GAME.selectedSection) {
        case 2:
        case 0:
            func_800E7FE0();
            return;
        case 1:
        case 3:
            func_801151F8();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionInput);
void dispatchSectionInput(void)
{
    if (GAME.selectedSection == 0) {
        func_800E80E0();
        return;
    }
    func_80115310();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionScroll);
void dispatchSectionScroll(void)
{
    if (GAME.selectedSection == 0) {
        func_800E821C();
        return;
    }
    func_801152D8();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionSelect);
void dispatchSectionSelect(void)
{
    if (GAME.selectedSection == 0) {
        func_800E8388();
        return;
    }
    func_8011546C();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionClose);
void dispatchSectionClose(void)
{
    if (GAME.selectedSection == 0) {
        func_80115584();
        return;
    }
    func_80115628();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", dispatchSectionConfirm);
void dispatchSectionConfirm(void)
{
    switch (GAME.selectedSection) {
        case 1:
            func_801151F8();
            return;
        case 2:
        case 0:
            func_800E84BC();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D784);
typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    s32 d8;
    s32 dc;
    s32 d10;
    char p14[0x3c - 0x14];
    u8 b3c, b3d, b3e, b3f;
    char p40[0x58 - 0x40];
    u16 w58;
    char p5a[0x6c - 0x5a];
    u8 b6c, b6d, b6e, b6f;
    u8 b70, b71, b72, b73;
    u8 b74, b75, b76, b77;
} S_2D784;
extern void (*D_8007C5F0[])(S_2D784 *);

void func_8002D784(S_2D784 *o)
{
    u16 w;
    s32 t;

    switch (o->b4) {
    case 0:
        o->b3c = 0;
        o->b3d = 0;
        o->b3e = 0;
        w = PLAYER.obj.animFrame;
        o->b3 = 0;
        o->b70 = 0;
        o->b71 = 0;
        o->b72 = 0;
        o->b73 = 0;
        o->b6c = 10;
        o->b6d = 0;
        o->b6e = 0;
        o->b6f = 0;
        o->b74 = 0;
        o->b75 = 0;
        o->b76 = 0;
        o->b77 = 0;
        D_1F800286 = 0;
        o->w58 = w;
        o->b4++;
        if ((*(s32 *)&GAME) == 6) {
            o->b4 = 2;
            SetGeomScreen(0x220);
        } else if ((*(s32 *)&GAME) == 0x60009) {
            o->b4 = 2;
            D_8009D6DD = 0;
            D_8009D6DE = 0;
            D_8009D6DF = 0;
            D_8009E3ED = 0;
            D_8009E3EE = 0;
            D_8009E3EF = 0;
        } else {
            SetGeomScreen(0x220);
        }
        break;
    case 1:
        D_8007C5F0[(*(u16 *)&GAME)](o);
        func_8002A0A0(o);
        goto tail;
    case 2:
        D_8007C5F0[(*(u16 *)&GAME)](o);
    tail:
        D_1F800174[0] = o->d8;
        t = o->dc;
        D_1F800178[0] = t;
        D_1F80017C[0] = o->d10;
        D_1F800184[0] = D_1F8000E4 + t;
        D_1F800180 = o->d8;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", getScrollOffsetX);
s16 getScrollOffsetX(void)
{
    s32 x = D_800A38DC;
    s32 v = D_8007D988[(x >> 8) / 360];
    s32 r = (v * 567) >> 12;

    if (x > 0) {
        r = r - 0x14;
    } else {
        r = r + 0x14;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", getScrollOffsetY);
s32 getScrollOffsetY(void)
{
    s16 v = D_8007D988[(D_800A38DC >> 8) / 360];

    return (v * 1027) >> 12;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DA2C);
extern s32 WMD_DATA;
extern void (*D_8007C640[])(char *, s32);

void func_8002DA2C(void)
{
    u16 v, x;
    D_800B00FB = 0;
    switch (GAME.selectedArea) {
    case 0:
        break;
    case 0xd:
        if (D_8009BCCA != 0) return;
        break;
    case 2:
        x = D_8009BCCA;
        v = 3;
        goto cmp;
    case 6:
        if (D_8009BCCA > 1) return;
        break;
    case 9:
        x = D_8009BCCA;
        if (x == 0) break;
        v = 6;
        goto cmp;
    case 0x12:
        x = D_8009BCCA;
        v = 1;
    cmp:
        if (x != v) return;
        break;
    case 5: case 8: case 0xb: case 0x10: case 0x11: case 0x13:
        return;
    }
    D_8007C640[GAME.selectedArea](D_800B00F8, WMD_DATA);
    D_800B00F9 = D_8009C10A;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stubInventory1);
void stubInventory1(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", updateObjectsLayer8);
void updateObjectsLayer8(void)
{
    u8* p = &D_800B0B88;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007C68C[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xD4;
    } while (D_1F800198 < 0x2D);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stubInventory2);
void stubInventory2(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DBD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DEC4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", stubInventory3);
void stubInventory3(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", spawnItemPickupObject);
void spawnItemPickupObject(u8 arg0)
{
    u8* p;

    if (D_8009BCBC == 0) {
        p = allocObjectLayer3();
        if (p != NULL) {
            p[0] = 1;
            p[2] = 0xD;
            p[0xC] = arg0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", cloneItemPickupObject);
void cloneItemPickupObject(u8* src)
{
    u8* p = allocObjectLayer3();

    if (p != NULL) {
        p[0] = 1;
        p[2] = 0xD;
        p[3] = 1;
        p[0xC] = src[2];
        p[0xF] = src[0xF] - 1;
        *(u8**)(p + 0x90) = src;
        *(u16*)(p + 0x12) = *(u16*)(src + 0x12);
        *(u16*)(p + 0x16) = *(u16*)(src + 0x16);
        *(u16*)(p + 0x1A) = *(u16*)(src + 0x1A);
        *(u16*)(p + 0xAC) = *(u16*)(src + 0xAC);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002E494);
