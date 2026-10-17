#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115464);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801155A4);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801155A8);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115608);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115708);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801158DC);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011590C);


struct GSInventory_1590C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1590C { u8 weapon; u8 pants; };
typedef void (*Fn_1590C)(GameObject *);
extern Fn_1590C D_8007C5D4[];
extern void func_8002A334(GameObject *);
extern s32 tryStartItemInteraction(GameObject *, s32, u8);

void func_8011590C(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (D_8009BC98.unk0A) {
            o->subState++;
            o->subtype = 0;
        }
        func_8002A334(o);
        ((s16 *)o->unk38)[1] = 0;
        break;
    case 1:
        D_8007C5D4[o->subtype](o);
        switch (GAME.selectedSection) {
        case 1:
            if ((u16)((*(u16*)&PLAYER.obj.x.p.whole) - 0x2e7) < 0x80 && PLAYER.obj.z.p.whole >= 0x5b) {
                tryStartItemInteraction(o, 1, 0);
            } else if (SCRATCHPAD.unk168[0].p.whole >= 0x3ad && SCRATCHPAD.unk168[1].p.whole >= -0x3b) {
                tryStartItemInteraction(o, 1, 1);
            }
            break;
        case 2:
            if (SCRATCHPAD.unk168[0].p.whole < 0x1e && SCRATCHPAD.unk168[1].p.whole >= -0x3b)
                tryStartItemInteraction(o, 1, 0);
            break;
        }
        break;
    case 2:
        func_8002CFF4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115AB4);
struct GSInventory_15AB4 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_15AB4 { u8 weapon; u8 pants; };
void func_80115AB4(void)
{
    if (GAME.selectedSection) ((void (*)(void))func_8011590C)();
    else func_80115708();
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115AF0);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115C70);

INCLUDE_RODATA("overlays/x06/nonmatchings/x06/x06", func_80115214);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80115D0C);
typedef struct { char pad[0xc6]; u16 wc6; } XC_15D0C;
typedef struct { s16 s[10]; } E_15D0C;
typedef struct { E_15D0C e[6]; char pad[0x8c - 0x78]; } G_15D0C;
typedef struct { s16 s0, s2, s4, s6, s8, sa; char pad[0x8c - 0xc]; } G2_15D0C;
typedef struct { s16 a, b, c, d, e, f, g, h, i; } T_15D0C;
extern G2_15D0C D_800A33C0[];
extern T_15D0C D_8011E342[];
extern s16 *D_8011E4BC[];

#define g ((G2_15D0C *)e)

void func_80115D0C(GameObject *o)
{
    E_15D0C *e;
    s16 *p;
    s32 i;

    switch (o->state) {
    case 0:
        if (--o->timer == 0) o->state++;
        break;
    case 1:
        if (func_80022E44(o) == 0) o->state++;
        for (i = 0; i < 6; i++) {
            e = &((G_15D0C *)&LOAD_BUFFER)[((XC_15D0C *)o)->wc6].e[i];
            switch (e->s[0]) {
            case 0:
            case 6:
                break;
            case 2:
            case 3:
                if (e->s[6] <= 0) e->s[7] = 0;
                if (e->s[8] <= 0) e->s[9] = 0;
            case 1:
            case 4:
            case 5:
                e->s[3] -= e->s[6];
                e->s[5] -= e->s[8];
                e->s[6] += e->s[7];
                e->s[8] += e->s[9];
                if (--e->s[1] <= 0) {
                    p = &D_8011E342[e->s[0]].a;
                    e->s[1] = *p++;
                    e->s[6] = *p++;
                    e->s[7] = *p++;
                    e->s[8] = p[0];
                    e->s[9] = p[1];
                    e->s[0]++;
                }
                break;
            }
        }
        e = (E_15D0C *)&D_800A33C0[((XC_15D0C *)o)->wc6];
        switch (g->s0) {
        case 0:
            break;
        case 1:
            if (--g->s2 > 0) break;
            o->unk90 = (s32)D_8011E4BC[o->subtype];
            g->s2 = 0x12;
            g->s0++;
            break;
        case 2:
            p = (s16 *)o->unk90;
            g->s4 += p[0];
            g->s6 += p[1];
            g->s8 -= p[0];
            g->sa -= p[1];
            o->unk90 = (s32)(p + 2);
            if (--g->s2 > 0) break;
            g->s2 = 0x1e;
            g->s0++;
            break;
        case 3:
            if (--g->s2 > 0) break;
            o->state = 2;
            break;
        }
        break;
    case 2:
        ((G_15D0C *)&LOAD_BUFFER)[((XC_15D0C *)o)->wc6].e[0].s[0] = -1;
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
#undef g

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801160A0);

typedef struct {
    s16 a, b, c, d, e, f, g, h, i, j;
} E118_160A0;
extern E118_160A0 LOAD_BUFFER_E118_160A0ArrArr7[][7] asm("LOAD_BUFFER");
typedef struct { char pad[0xc2]; u16 wc2, wc4, wc6; s16 wc8; } X118_160A0;
#define X(o) ((X118_160A0 *)(o))
extern u16 GetClut(s32, s32);

void func_801160A0(s32 n, s16 x, s16 y, s16 z, s16 t)
{
    s32 i;
    GameObject *o;
    s32 cnt;
    s16 px;
    s16 py;
    s16 zero;
    s16 w800;
    E118_160A0 *e;
    u8 c;
    s32 h;
    u16 *dp;
    s32 off;
    char *q;
    s32 w, m;

    addPlayerAP(n);
    for (i = 7; i >= 0; i--) {
        if (LOAD_BUFFER_E118_160A0ArrArr7[i][0].a == -1)
            break;
    }
    if (i < 0)
        return;
    o = allocObjectLayer3();
    if (o == 0)
        return;
    h = n / 100000;
    o->unkB4 = h % 10;
    o->type = 0;
    o->active = 1;
    o->unkA = 4;
    o->spriteBank = (*(s32 *)&D_1F8002D8);
    o->tpage = 0x15;
    o->unkF = 5;
    o->x.raw = x << 16;
    o->y.raw = y << 16;
    o->z.raw = z << 16;
    (*(s16*)&o->animTimer) = 0;
    S16(o, 0x20) = t;
    S16(o, 0xc6) = i;
    o->unkB6 = n / 10000 - h * 10;
    o->unkB8 = n / 1000 - n / 10000 * 10;
    o->unkBA = n / 100 - n / 1000 * 10;
    o->unkBC = n / 10 - n / 100 * 10;
    (*(s16*)&o->unkBE) = n - n / 10 * 10;
    if (t == 1)
        X(o)->wc8 = 0;
    else
        X(o)->wc8 = 1;
    if (n < 1000) {
        o->subtype = 0;
    } else {
        if (n < 10000) o->subtype = 1;
        else if (n < 20000) o->subtype = 2;
        else if (n > 49999) o->subtype = 4;
        else o->subtype = 3;
    }
    X(o)->wc2 = GetClut(0x210, 0x1e1);
    X(o)->wc4 = GetClut(0x210, o->subtype + 0x1e1);
    cnt = 0;
    px = 0;
    zero = 0;
    w800 = 800;
    dp = (u16 *)o;
    off = 0;
    py = 1;
    i = 0;
loop:
        w = X(o)->wc6;
        m = (w << 3) + w;
        m = (m << 2) - w;
        m = m << 2;
        q = (char *)LOAD_BUFFER_E118_160A0ArrArr7 + off;
        e = (E118_160A0 *)(m + (s32)q);
        e->a = 0;
        if (dp[0x5a] != 0 || cnt != 0) {
            e->b = py;
            e->a = 1;
            e->c = px * 100;
            e->d = zero;
            e->e = (px + 8) * 100;
            e->f = w800;
            e->g = 0;
            e->h = 0;
            e->i = 0;
            e->j = 0;
            px += 8;
            py += 4;
            cnt++;
        }
            dp++;
        i++;
        off += 20;
    if (i < 6) goto loop;
    (*(char **)&D_800A37D0) = D_80012260;
    D_800AFF10 = D_800123F8;
    e = &LOAD_BUFFER_E118_160A0ArrArr7[X(o)->wc6][6];
    e->a = 1;
    e->b = (cnt << 2) | 1;
    e->c = cnt * 400;
    e->d = -3200;
    e->e = cnt * 400;
    e->f = -3200;
}
#undef X

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80116498);


struct GSInventory_16498 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_16498 { u8 weapon; u8 pants; };

typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MAT_16498;
extern s32 D_1F800168_S32Arr[] asm("D_1F800168");
extern s32 D_1F80016C_S32Arr[] asm("D_1F80016C");
extern s32 D_1F800170[];
extern void *D_80121D50[];
extern void *D_8011E620;
extern void *D_8011E634;
extern void *D_8011E610[];
extern void *D_8011E624[];
extern u8 PLAYER_U8Arr[] asm("PLAYER");
extern s16 D_800A5404[];
extern s16 D_800A5406[];
extern s16 D_800A5408_S16Arr[] asm("D_800A5408");
extern s16 D_800A540A[];
extern s32 D_800A53A8[];
extern s32 D_800A53AC[];
extern s32 D_800A53B0_S32Arr[] asm("D_800A53B0");
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void loadImageRect(void *, s32, s32, s32, s32);

void func_80116498(GameObject *o)
{
    GameObject *p;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 1;
        o->unkD = 0;
        o->unkAC = 0;
        o->spriteBank = D_1F8002E0[0];
        o->unkA = 3;
        o->buffSize = 0xe80;
        *(s8 *)&o->unkF = -4;
        o->unk8C = 0;
        o->animFrame = 0;
        o->anim = D_80121D50[0];
        readAnimFrameCount(o);
        if (D_8009C068.unk5a6 || D_8009C068.unk6a6) {
            loadImageRect(D_8011E620, 0x90, 0x1f0, 0x10, 1);
            loadImageRect(D_8011E634, 0x90, 0x1f1, 0x10, 1);
        } else {
            loadImageRect(D_8011E610[GAME.displayExpBar], 0x90, 0x1f0, 0x10, 1);
            loadImageRect(D_8011E624[D_8009C608.unk953], 0x90, 0x1f1, 0x10, 1);
        }
        break;
    case 1:
        func_80022E44(o);
        tickAnimation(o);
        p = (GameObject *)o->unk90;
        getBaseMatrix(&SCRATCHPAD.workMatrix);
        D_1F800060.vx = o->unk30;
        D_1F800060.vy = o->unk34;
        D_1F800060.vz = o->unk38;
        MulMatrix0((MAT_16498 *)((char *)p + 0x48), &SCRATCHPAD, &D_1F800020);
        ApplyRotMatrix(&D_1F800060, D_1F800020.t);
        D_1F800020.t[0] += p->x.p.whole;
        D_1F800020.t[1] += p->y.p.whole;
        D_1F800020.t[2] += p->z.p.whole;
        o->x.p.whole = D_1F800020.t[0];
        o->y.p.whole = D_1F800020.t[1];
        o->z.p.whole = D_1F800020.t[2];
        o->unk8C = ((0x1000 - ((GameObject *)o->unk90)->unk8C) & 0xfff) >> 4;
        PLAYER_U8Arr[0] = 3;
        D_800A5404[0] = 0x18;
        D_800A5406[0] = 0x30;
        D_800A5408_S16Arr[0] = 0x18;
        D_800A540A[0] = 0x30;
        D_800A53A8[0] = o->x.raw;
        D_800A53AC[0] = o->y.raw;
        D_800A53B0_S32Arr[0] = o->z.raw;
        D_1F800168_S32Arr[0] = o->x.raw;
        D_1F80016C_S32Arr[0] = o->y.raw;
        D_1F800170[0] = o->z.raw;
        GAME.selectedPlane = 0;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801167B8);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80116814);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80116A00);

INCLUDE_RODATA("overlays/x06/nonmatchings/x06/x06", func_80115274);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80116C78);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80116FFC);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011700C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011712C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801172E8);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117390);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801173FC);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117654);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011767C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117740);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117790);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117840);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801178B8);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_801179BC);
extern s32 rsin(s32);

void func_801179BC(GameObject *o)
{
    s16 y;
    s16 t;
    s16 *q;

    y = o->y.p.whole;
    q = &o->unkB4;
    switch (o->unk7A & 3) {
    case 0:
        o->unk74 = 0;
        break;
    case 1:
        o->unk74 = nextRandom() & 3;
        if (o->unkB6 == 0)
            o->unk74 = 2;
        break;
    case 2:
        o->unk74 = (nextRandom() & 3) + 2;
        if (o->unkB6 == 0)
            o->unk74 = 4;
        break;
    case 3:
        o->unk74 = 4;
        break;
    }
    t = o->unk74 + o->unk34;
    if (t <= y) {
        o->touchFlag = 1;
        o->y.p.whole += t - y;
    } else {
        o->touchFlag = 0;
    }
    if (o->touchFlag == 0) {
        o->velV += 0x28;
        if (o->velV > 0x600)
            o->velV = 0x600;
        o->y.raw += o->velV << 8;
    } else {
        o->y.raw += (rsin(q[3]) * q[1]) >> 4;
        o->velV = 0;
        o->y.p.whole++;
    }
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117B60);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117C4C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117C60);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80117FBC);

typedef struct {
    s16 a;
    s16 b;
    s16 ang;
    s16 pad;
    s32 rad;
    s32 div;
    s32 pad2;
    s16 c8;
    s16 ca;
    s16 cc;
} Sub_17FBC;
typedef struct { s16 x, y, z, w; } E_17FBC;

extern char D_8011F1E4[];
extern char D_8011E73C[];
extern void *D_80121D78[];
extern void *D_80121D50[];
extern s32 rcos(s32);
extern void readAnimFrameCount(GameObject *);
extern void func_80117B60(GameObject *);

#define SUB(o) ((Sub_17FBC *)((char *)(o) + 0xb4))

static __inline__ void upd_17FBC(GameObject *o, Sub_17FBC *t)
{
    switch (SUB(o)->c8) {
    case 0:
        if (o->animTimer < 0x40) {
            if (o->animTimer >= 0x3e && (((volatile u16*)&D_8009C968.w70)[0] & 0x10)) {
                *(char **)&o->unkA8 = D_8011F1E4;
                SUB(o)->c8 = 2;
                o->animTimer -= 0x3e;
            }
        } else {
            SUB(o)->c8 = 1;
        }
        break;
    case 1:
        if ((u16)(o->animTimer - 0x72) < 0x12) SUB(o)->cc = 1;
        else SUB(o)->cc = 0;
        break;
    case 2:
        if ((u16)(o->animTimer - 0x35) < 0x19) SUB(o)->cc = 1;
        else SUB(o)->cc = 0;
        if (o->animTimer == 0x77) {
            *(char **)&o->unkA8 = D_8011E73C;
            o->animTimer = 0xaa;
            t->c8 = 1;
        }
        break;
    }
}

static __inline__ void pos_17FBC(GameObject *o)
{
    Sub_17FBC *s;
    E_17FBC *e;
    s16 d;

    func_80117B60(o);
    upd_17FBC(o, SUB(o));
    func_80117840(o);
    s = SUB(o);
    e = *(E_17FBC **)&o->unkA8;
    e += o->animTimer;
    o->unk34 = (SUB(o)->div > 0 ? (o->unk34 = SUB(o)->rad * o->unk76 / SUB(o)->div) + e->y : e->y) - 0x20;
    o->unk38 = (rsin(s->ang) * s->rad) >> 20;
    o->unk30 = (rcos(s->ang) * s->rad) >> 20;
    o->x.p.whole = e->x + o->unk30;
    o->z.p.whole = e->z + o->unk38;
}

void func_80117FBC(GameObject *o)
{
    GameObject *p = (*(GameObject **)&D_8009BC98.unk20);
    Sub_17FBC *t;
    u16 y;
    s16 lim;
    s32 r;
    s16 d;

    t = SUB(o);
    pos_17FBC(o);
    switch (o->step) {
    case 0:
        o->step++;
        o->unk9C = 0;
        break;
    case 1:
        o->unk9C = 1;
        o->velX -= 0x10;
        if (o->velX < 0) o->velX = 0;
        o->velV += 0x40;
        if (o->velV > 0) {
            o->velV = 0;
            o->unk9C = 2;
            o->step++;
            p->anim = D_80121D78[0];
            readAnimFrameCount(p);
        }
        o->y.raw += o->velV << 8;
        d = o->y.p.whole;
        r = o->unk34;
        if (r <= d) o->y.p.whole += r - d;
        break;
    case 2:
        o->velX -= 0x10;
        if (o->velX < 0) o->velX = 0;
        o->velV += 0x40;
        if (o->velV > 0x600) o->velV = 0x600;
        o->y.raw += o->velV << 8;
        y = o->y.p.whole;
        switch (o->unk7A & 3) {
        case 0:
            o->unk74 = 0;
            break;
        case 1:
            o->unk74 = nextRandom() & 3;
            if (SUB(o)->b == 0) o->unk74 = 2;
            break;
        case 2:
            o->unk74 = (nextRandom() & 3) + 2;
            if (SUB(o)->b == 0) o->unk74 = 4;
            break;
        case 3:
            o->unk74 = 4;
            break;
        }
        lim = o->unk34 + (u16)o->unk74;
        if ((s16)lim <= (s16)y) {
            r = 1;
            o->touchFlag = 1;
            o->y.p.whole += lim - y;
        } else {
            r = 0;
            o->touchFlag = 0;
        }
        if (r) {
            func_80028A74(0, 0, 0x80, 5);
            p->anim = D_80121D50[0];
            readAnimFrameCount(p);
            o->subState = 1;
            o->step = 0;
            o->unk9C = 0;
        }
        break;
    }
}
#undef SUB

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80118470);

typedef struct {
    s16 a;
    s16 b;
    s16 ang;
    s16 pad;
    s32 rad;
    s32 div;
    s32 pad2;
    s16 c8;
    s16 ca;
    s16 cc;
} Sub_18470;
typedef struct { s16 x, y, z, w; } E_18470;
extern void *D_80121D7C[];
extern void *D_80121D80[];

#define SUB(o) ((Sub_18470 *)((char *)(o) + 0xb4))

static __inline__ void upd_18470(GameObject *o, Sub_18470 *t)
{
    switch (SUB(o)->c8) {
    case 0:
        if (o->animTimer < 0x40) {
            if (o->animTimer >= 0x3e && (((volatile u16*)&D_8009C968.w70)[0] & 0x10)) {
                *(char **)&o->unkA8 = D_8011F1E4;
                SUB(o)->c8 = 2;
                o->animTimer -= 0x3e;
            }
        } else {
            SUB(o)->c8 = 1;
        }
        break;
    case 1:
        if ((u16)(o->animTimer - 0x72) < 0x12) SUB(o)->cc = 1;
        else SUB(o)->cc = 0;
        break;
    case 2:
        if ((u16)(o->animTimer - 0x35) < 0x19) SUB(o)->cc = 1;
        else SUB(o)->cc = 0;
        if (o->animTimer == 0x77) {
            *(char **)&o->unkA8 = D_8011E73C;
            o->animTimer = 0xaa;
            t->c8 = 1;
        }
        break;
    }
}

static __inline__ void pos_18470(GameObject *o)
{
    Sub_18470 *s;
    E_18470 *e;

    upd_18470(o, SUB(o));
    func_80117840(o);
    s = SUB(o);
    e = *(E_18470 **)&o->unkA8;
    e += o->animTimer;
    o->unk34 = (SUB(o)->div > 0 ? (o->unk34 = SUB(o)->rad * o->unk76 / SUB(o)->div) + e->y : e->y) - 0x20;
    o->unk38 = (rsin(s->ang) * s->rad) >> 20;
    o->unk30 = (rcos(s->ang) * s->rad) >> 20;
    o->x.p.whole = e->x + o->unk30;
    o->z.p.whole = e->z + o->unk38;
}

void func_80118470(GameObject *o)
{
    GameObject *p = (*(GameObject **)&D_8009BC98.unk20);
    Sub_18470 *t;
    u16 y;
    s16 lim;
    s32 r;
    s16 d;

    t = SUB(o);
    pos_18470(o);
    switch (o->step) {
    case 0:
        func_80028A74(0, 1, 0x50, 0x3c);
        o->velV = -0x200;
        t->b -= t->b >> 2;
        if (t->b < 0) t->b = 0;
        else o->velV -= t->b >> 2;
        o->step++;
        p->anim = D_80121D7C[0];
        readAnimFrameCount(p);
        break;
    case 1:
        o->velX -= 0x10;
        if (o->velX < 0) o->velX = 0;
        o->velV += 0x40;
        if (o->velV > 0) {
            o->velV = 0;
            o->unk9C = 2;
            o->step++;
        }
        o->y.raw += o->velV << 8;
        d = o->y.p.whole;
        r = o->unk34;
        if (r <= d) o->y.p.whole += r - d;
        break;
    case 2:
        o->velX -= 0x10;
        if (o->velX < 0) o->velX = 0;
        o->velV += 0x40;
        if (o->velV > 0x600) o->velV = 0x600;
        o->y.raw += o->velV << 8;
        y = o->y.p.whole;
        switch (o->unk7A & 3) {
        case 0:
            o->unk74 = 0;
            break;
        case 1:
            o->unk74 = nextRandom() & 3;
            if (SUB(o)->b == 0) o->unk74 = 2;
            break;
        case 2:
            o->unk74 = (nextRandom() & 3) + 2;
            if (SUB(o)->b == 0) o->unk74 = 4;
            break;
        case 3:
            o->unk74 = 4;
            break;
        }
        lim = o->unk34 + (u16)o->unk74;
        if ((s16)lim <= (s16)y) {
            r = 1;
            o->touchFlag = 1;
            o->y.p.whole += lim - y;
        } else {
            r = 0;
            o->touchFlag = 0;
        }
        if (r) {
            func_80028A74(0, 0, 0xa0, 5);
            o->step++;
            p->anim = D_80121D80[0];
            readAnimFrameCount(p);
            o->timer = 0xc;
            o->unk9C = 0;
        }
        break;
    case 3:
        if (t->b > 0x100) t->b -= 8;
        if (--o->timer == -1) {
            p->anim = D_80121D50[0];
            readAnimFrameCount(p);
            o->subState = 1;
            o->step = 0;
        }
        func_801179BC(o);
        if (o->touchFlag) {
            o->velX = t->b >> 1;
        } else {
            o->velX -= 0x10;
            if (o->velX < 0) o->velX = 0;
        }
        break;
    }
}
#undef SUB

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80118A4C);
static __inline__ void calc_18A4C(GameObject *o, s16 *p)
{
    u16 u = (o->unk8C - p[3]) & 0xfff;
    s16 d = u;
    if (d == 0) {
        o->velV = o->unkB6 / 4 + 0x200;
    } else {
        if (u < 0x800) {
            if (d >= 0x200) o->unkB6 = o->unkB6 / 2;
            else if (d >= 0x100) o->unkB6 = o->unkB6 - o->unkB6 / 4;
            else o->unkB6 = o->unkB6 - o->unkB6 / 6;
            o->velV += p[1] / 2;
        } else {
            if (d <= 0xe00) o->unkB6 = o->unkB6 - o->unkB6 / 4;
            else if (d <= 0xf00) o->unkB6 = o->unkB6 - o->unkB6 / 6;
            else o->unkB6 = o->unkB6 - o->unkB6 / 8;
            o->velV += p[1] / 3;
        }
        if (p[1] < 0) p[1] = 0;
    }
}

void func_80118A4C(GameObject *o)
{
    o->subState = 5;
    o->velV = 0x200;
    o->step = 0;
    calc_18A4C(o, &o->unkB4);
    o->velV = -o->velV;
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80118C40);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80119404);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80119798);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80119A8C);

typedef struct { char p[0x1c]; s16 w1c; } X_19A8C;
extern s32 func_8011A304(GameObject *);
extern s32 func_8011A588(GameObject *);

void func_80119A8C(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;
    X_19A8C *x = (X_19A8C *)((char *)p + 0xb4);

    switch (o->subState) {
    case 0:
        o->velY = 0;
        o->velV = 0;
        o->subState++;
        *(s32 *)&o->unkB4 = o->unk34;
        break;
    case 1:
        if (p->unk9C) {
            o->subState++;
            break;
        }
        if (x->w1c == 0) {
            o->subState = 4;
        }
        break;
    case 2:
        if (p->unk9C == 0) {
            func_8011A304(o);
            o->subState++;
        }
        break;
    case 3:
        if (func_8011A304(o) == 1) {
            o->subState = 1;
        }
        break;
    case 4:
        func_8011A588(o);
        break;
    }
    if (D_8009BC98.unk12 == 0) {
        o->velY = (o->velY + 0x20) & 0xff;
        o->velV = D_8007D988[o->velY];
        o->unk34 = (u16)o->unkB4 + (o->velV << 4);
    }
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_80119BCC);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A238);
extern void func_80022C08(GameObject *, s32);
extern void freeObjectLayer4(GameObject *);

void func_8011A238(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->active = 2;
        o->unk84 = 0;
        o->unk8C = 0;
        o->unk88 = o->animFrame << 8;
        o->state++;
        break;
    case 1:
        func_80022C08(o, 0x80);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A2D4);

void func_8011A2D4(GameObject *o)
{
    s32 *pp = &SCRATCHPAD.wmdData[1];
    s32 i;
    char *b;

    b = (char *)*pp;
    i = o->unkAC << 2;
    b += i;
    i = *(s32 *volatile *)pp;
    i += ((s32 *)b)[1];
    o->unkA0 = i;
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A304);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A4B4);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A588);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A650);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A7C0);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011A8B0);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AAF4);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011ABF4);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AD80);
extern void (*D_8007DE28[])(GameObject *);
extern s32 func_8011DF14(GameObject *o);
extern s32 tickAnimation(GameObject *o);

void func_8011AD80(GameObject *o)
{
    switch (o->state) {
    case 0:
        initItemObject(o);
        o->active = 2;
        o->state++;
        break;
    case 1:
        if (func_8011DF14(o) != 0) {
            tickAnimation(o);
        }
        break;
    case 2:
        D_8007DE28[D_8007DD88[o->subtype]](o);
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AE68);

typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
} SP8_1AE68;

void func_8011AE68(s16 x, s16 y, u8 u, u8 v, s16 c)
{
    SP8_1AE68 *p = D_1F800164;
    SetSprt8(p);
    p->code |= 1;
    SetSemiTrans(p, 0);
    p->x0 = x;
    p->y0 = y;
    p->u0 = u;
    p->v0 = v;
    p->clut = GetClut(0x170, c + 0x1f0);
    AddPrim((*(char **)&SCRATCHPAD.ot) + 4, p);
    D_1F800164 = (SP8_1AE68 *)((char *)D_1F800164 + 0x10);
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AF40);
void func_8011AF40(void)
{
    (*(u8 *)&D_800B0770) = 1;
    D_800B0772 = 0;
    D_800B0773 = 0;
    D_800B07BC = 1;
    D_800B07BA = 0;
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AF78);

typedef struct {
    u8 b0;
    u8 pad[7];
    s16 w8;
} S_1AF78;

void func_8011AF78(void)
{
    extern void func_8011AFF0(S_1AF78 *);
    S_1AF78 *p = &(*(S_1AF78 *)&D_800B0770);

    if (D_8009BC98.unk0A) {
        if (D_8009BC98.unk0F) (*(S_1AF78 *)&D_800B0770).w8 = 0x78;
        if ((*(S_1AF78 *)&D_800B0770).w8 == 0 && (p->b0 & 1)) func_8011AFF0(p);
    }
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AFF0);

typedef struct { char p0[0x14]; u16 w14; char p16[0x60 - 0x16]; } L_1AFF0;
typedef struct { char p0[0x18]; s32 f18; } P_1AFF0;
extern void addDrawModePrim(s32, s32);
extern void func_8011B084(P_1AFF0 *, s32, s32);
extern void func_8011B7F0(P_1AFF0 *, s32, s32);
extern void func_8011BF5C(P_1AFF0 *, s32, s32, s32);

#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011AFF0);
#else
void func_8011AFF0(P_1AFF0 *p)
{
    extern void func_8011C0BC(P_1AFF0 *, s32, s32);
    L_1AFF0 l;
    GetDrawEnv(&l);
    addDrawModePrim(l.w14, 1);
    p->f18 = SCRATCHPAD.sprData[3];
    func_8011B084(p, 0x10, 0x10);
    func_8011B7F0(p, 0x10, 0x1a);
    func_8011BF5C(p, 0, 0x88, 0xD0);
    p->f18 = SCRATCHPAD.sprData[4];
    func_8011C0BC(p, 0x18, 0xD0);
}
#endif

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011B084);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011B1CC);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011B7F0);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011B91C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011BA78);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011BD20);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011BF5C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011BFF8);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C0BC);
struct GSInventory_1C0BC { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1C0BC { u8 weapon; u8 pants; };
extern void func_8004F2CC(void *, s32, s32, s32);
extern void addDrawModePrim(s32, s32);

void func_8011C0BC(void *o, s16 x, s16 y)
{
    s32 n;
    if (((u8*)&GAME.playerLives)[0] - 1 >= 10) {
        n = *((u16 **)&D_80012260)[(((u8*)&GAME.playerLives)[0] - 1) / 10];
        func_8004F2CC(o, x - 5, y, n);
        n = *((u16 **)&D_80012260)[(((u8*)&GAME.playerLives)[0] - 1) % 10];
        func_8004F2CC(o, x + 5, y, n);
    } else {
        n = *((u16 **)&D_80012260)[((u8*)&GAME.playerLives)[0] - 1];
        func_8004F2CC(o, x, y, n);
    }

    func_8004F2CC(o, x, y - 4, (*(u16 *)&D_80012650));
    addDrawModePrim(0x15, 1);
}

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C234);

typedef struct {
    u32 tag;
    u8 r, g, b, code;
    s16 x0, y0; u16 uv0, clut;
    s16 x1, y1; u16 uv1, tpage;
    s16 x2, y2; u16 uv2, pad2;
    s16 x3, y3; u16 uv3, pad3;
} FT4_1C234;

typedef struct {
    s32 uvclut;
    s32 uvtp;
    u16 uv2;
    u8 w, h;
    u16 uv3;
    s8 dx, dy;
} EL_1C234;
extern s32 LZ_FILE_CTRL_S32 asm("LZ_FILE_CTRL");
extern void SetSemiTrans(void *, s32);

static __inline__ s32 ot_1C234(u32 *a, s32 b, s32 c, s32 z, u32 e)
{
    s32 d = (z + c) << 2;
    if (d < 0) d = 0;
    d += b;
    if ((u32)(d - SCRATCHPAD.ot) >= 0xca0) return 1;
    {
        u32 v = *(u32 *)d;
        *(u32 *)d = (u32)a;
        *a = v | e;
    }
    return 0;
}

void func_8011C234(GameObject *o)
{
    s16 *f;
    s32 n;
    EL_1C234 *e;
    FT4_1C234 *p;
    s32 r;

    if (o->anim == 0) return;
    projectActorPosition(o, &LZ_FILE_CTRL_S32, &SCRATCHPAD.lz.offset);
    f = (s16 *)(o->spriteBank + (*(s16 *)o->anim << 2));
    n = f[0];
    e = (EL_1C234 *)(*(volatile s32 *)&o->spriteBank + f[1]);
    do {
        p = D_1F800164;
        if (o->animFrame & 1) {
            p->x0 = e->dx + LZ_FILE_CTRL_S32;
            p->y0 = e->dy + (LZ_FILE_CTRL_S32 >> 16);
            p->x1 = p->x0 + e->w;
            p->x2 = p->x0;
            p->y1 = *(s16 *)((char *)p + 10);
            p->y2 = p->y0 + e->h;
            p->x3 = p->x1;
            p->y3 = p->y2;
        } else {
            p->x0 = LZ_FILE_CTRL_S32 - e->dx;
            p->y0 = e->dy + (LZ_FILE_CTRL_S32 >> 16);
            p->x1 = p->x0 - e->w;
            p->x2 = p->x0;
            p->y1 = *(s16 *)((char *)p + 10);
            p->y2 = p->y0 + e->h;
            p->x3 = p->x1;
            p->y3 = p->y2;
        }
        if (isPolyFT4OnScreen(p)) {
            p->code = 0x2d;
            SetSemiTrans(p, o->unkD >> 7);
            *(s32 *)&p->uv0 = e->uvclut;
            *(s32 *)&p->uv1 = e->uvtp;
            p->uv2 = e->uv2;
            p->uv3 = e->uv3;
            p->tpage += o->tpage;
            if (o->unkD & 1) p->clut = o->clut;
            if (o->unkB) r = ot_1C234((u32 *)p, SCRATCHPAD.ot + 0x10, 0, (s8)o->unkF, 0x9000000);
            else { s32 c = SCRATCHPAD.lz.offset; r = ot_1C234((u32 *)p, SCRATCHPAD.ot + 0x10, c, (s8)o->unkF, 0x9000000); }
            if (!r) D_1F800164 = (FT4_1C234 *)((char *)D_1F800164 + 0x28);
        }
        e++;
    } while (--n);
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C500);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C678);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C730);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C824);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011C914);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CB24);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CC08);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CCE8);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CE24);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CF38);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CF50);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011CF9C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D098);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D1A8);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D41C);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D4F4);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D6A8);

s32 func_8011D6A8(void)
{
    s16 x = D_8009C068.unk682;
    s32 r;

    if (x > D_8009C068.unk674) {
        r = -1;
    } else if (D_8009C068.unk672 < x) {
        r = 2;
    } else {
        r = D_8009C068.unk670 < x;
    }
    return r;
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D6F8);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D858);
extern void func_80055A44(void *);
extern void func_8005548C(void *);

void func_8011D858(void)
{
    char *p = ((char *)&PLAYER);

    func_80055A44(p);
    func_8005548C(p);
}

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D890);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011D9CC);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011DA00);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011DE38);

INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011DF14);

// INCLUDE_ASM("overlays/x06/nonmatchings/x06/x06", func_8011E068);
extern void *D_80122360[];
extern void *D_80122364;
extern void *D_8012236C[];
extern void applyAnimVelocityX(GameObject *, u16);

static __inline__ void setbox_1E068(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a;
    o->hitWidth = b;
    o->hitOffsetY = c;
    o->hitHeight = d;
}

void func_8011E068(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 3;
        *(s8 *)&o->unkF = -0x10;
        o->unkA = 2;
        o->unkD = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        setbox_1E068(o, 0x10, 0x20, 0x10, 0x20);
        o->spriteBank = SCRATCHPAD.sprData[2];
        o->anim = D_80122360[o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        func_8011DF14(o);
        tickAnimation(o);
        break;
    case 2:
        func_8011DF14(o);
        switch (o->subState) {
        case 0:
            o->unkB = 1;
            o->unkF = 4;
            o->active = 2;
            o->velV = -0x400;
            o->movetab = ((char *)&D_8007722C);
            o->subState++;
            o->anim = D_8012236C[0];
            readAnimFrameCount(o);
            break;
        case 1:
            if (o->velV > 0) {
                o->anim = D_80122364;
                readAnimFrameCount(o);
                o->subState++;
            }
        case 2:
            tickAnimation(o);
            applyAnimVelocityX(o, 1 - o->animFrame);
            o->velV += 0x40;
            if (o->velV > 0x400)
                o->velV = 0x400;
            o->y.raw += o->velV << 8;
            if (!o->visible)
                o->state++;
            break;
        }
        if (o->animFrame & 1)
            o->unk8C = (o->unk8C + 0x14) & 0xff;
        else
            o->unk8C = (o->unk8C - 0x14) & 0xff;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x06/nonmatchings/x06/x06", func_8011545C);
