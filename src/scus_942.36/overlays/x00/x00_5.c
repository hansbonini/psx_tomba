#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801211A0);
extern u8 D_8009C11C;
extern u8 D_800A543A;
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);

void func_801211A0(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (o->touchFlag == 1 && D_800A543A == 1)
            o->subState = o->subState + 1;
        break;
    case 1:
        if ((*(u32 *)&D_8009BCD4) < 100000) {
            if (D_8009C11C == 0) {
                setEventStarted(0x10, 0, 0);
                goto L;
            }
            o->subState = o->subState - 1;
            break;
        }
        if (D_8009C11C != 0xff) {
            setEventComplete(0x10, 0);
        L:
            o->subState = o->subState + 1;
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_8009BCA6 = 1;
            break;
        }
        o->state = 2;
        o->subState = 0;
        break;
    case 2:
        o->timer = 300;
        o->subState = o->subState + 1;
        break;
    case 3:
        o->timer = o->timer - 1;
        if (o->timer == -1)
            o->subState = o->subState + 1;
        break;
    case 4:
        D_8009BCA7 = 0;
        D_8009BCAA = 0;
        D_8009BCA6 = 0;
        o->subState = 1;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121330);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012137C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121468);
extern char D_80138248[];
extern void func_80120E78(GameObject *);
extern void freeObjectLayer4(GameObject *);
extern void spawnItemFromEntry(void *, Fix16 *, s32, s32, GameObject *);

void func_80121468(GameObject *o)
{
    Fix16 v[3];

    switch (o->state) {
    case 0:
        o->state++;
        o->unk88 = 0xc00;
        o->unkA = 0x13;
        o->unk74 = 0xc00;
        o->unk76 = 0xc00;
        o->unk78 = 0xc00;
        o->unk84 = 0;
        o->unk8C = 0;
        o->touchFlag = 0;
        o->timer = 0x20;
        if (o->unkC == 0) {
            o->hitOffsetX = 0xe;
            o->hitWidth = 0x1c;
            o->hitOffsetY = 0x24;
            o->hitHeight = 0x24;
        } else {
            o->active = 2;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->unkC == 0) {
            func_80120E78(o);
            func_801211A0(o);
            o->touchFlag = 0;
        } else {
            o->state = ((GameObject *)o->unk90)->state;
            o->subState = ((GameObject *)o->unk90)->subState;
            o->step = ((GameObject *)o->unk90)->step;
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (o->unkC == 0) {
                v[0].p.whole = o->h->p.whole;
                v[1].p.whole = o->y.p.whole - 0x20;
                v[2].p.whole = o->d->p.whole;
                spawnItemFromEntry(D_80138248, v, 0, -0x400, o);
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xb4)) + 4) = 2;
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xb8)) + 4) = 2;
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xbc)) + 4) = 2;
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xc0)) + 4) = 2;
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xc4)) + 4) = 2;
                *(u8 *)((u8 *)(*(void **)((u8 *)o + 0xc8)) + 4) = 2;
            }
            o->subState++;
            break;
        case 1:
            func_80121330(o);
            break;
        case 2:
            o->state = 3;
            break;
        }
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801216BC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121748);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121810);
extern void *D_8013A550[];
extern s32 D_1F8002D4[];
extern u16 D_1F80017A[];
extern s32 D_800A38D8[];
extern s32 D_800A38DC_S32Arr[] asm("D_800A38DC");
void pushDrawListLayer7(GameObject *o);
void freeObjectLayer7(GameObject *o);

static __inline__ void fin_21810(GameObject *o, s16 m)
{
    o->visible = 1;
    { s16 k = o->clut & 0x803f; o->clut = k | m; }
    o->timer--;
    pushDrawListLayer7(o);
}

void func_80121810(GameObject *o)
{
    u8 t;
    s32 m;
    s16 n;
    s16 pa;
    s16 py;
    s16 x;
    t = o->state;
    switch (t) {
    case 0:
        o->tpage = 8;
        o->clut = GetClut(0xc0, 0x1e7);
        o->unkD = 1;
        o->anim = D_8013A550[0];
        o->spriteBank = D_1F8002D4[0];
        o->cooldownTimer = 0;
        o->subState = 0;
        o->unkF = 2;
        o->state++;
        o->timer = 0xf;
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
        break;
    case 1:
        x = ((s16 *)&D_1F800176)[0];
        if (x >= 0x35d) break;
        pa = (s16)(o->unk30 - x) >> 1;
        py = (s16)(o->unk34 - D_1F80017A[0]) >> 1;
        o->x.p.whole = pa;
        o->y.p.whole = py;
        o->z.p.whole = 0;
        m = o->clut & 0x7fc0;
        n = m;
        o->y.p.whole -= (D_800A38D8[0] >> 8) << 2;
        o->x.p.whole -= D_800A38DC_S32Arr[0] >> 10;
        switch (o->subState) {
        case 0:
            if (o->timer == 0) {
                if (o->cooldownTimer == 6) {
                    n = m - 0x40;
                    o->cooldownTimer--;
                    o->subState++;
                } else {
                    n = m + 0x40;
                    o->cooldownTimer++;
                }
                o->timer = 0xf;
            }
            break;
        case 1:
            if (o->timer == 0) {
                if (o->cooldownTimer == 0) {
                    n = m + 0x40;
                    o->cooldownTimer++;
                    o->subState--;
                } else {
                    n = m - 0x40;
                    o->cooldownTimer--;
                }
                o->timer = 0xf;
            }
            break;
        }
        fin_21810(o, n);
        break;
    case 2:
        o->state = t + 1;
        break;
    case 3:
        freeObjectLayer7(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121A74);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121C00);
extern s32 D_8009BCEC;
extern void func_80133408(s32, s32, s32);
extern void func_80119498(s32, s32, s32, s32);

void func_80121C00(GameObject *o)
{
    u16 *p = &D_8009BCCA;
    if (*p == 4)
        o->unkF = 8;
    if (*p == 5)
        *(s8 *)&o->unkF = -5;
    if ((D_8009BCEC & 2) != 0)
        func_80133408(o->x.p.whole, o->y.p.whole, o->z.p.whole);
    if (D_8009C10E != 0xff)
        func_80119498(0, 0, 0, 6);
    if (D_8009C617 == 0) {
        o->state = 5;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
    }
    D_8009E454 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121CD4);
extern u8 D_8009C10D;

void func_80121CD4(char *o)
{
    if (D_8009BCCA == 3 && D_8009C10D == 0xff && (*(u16 *)&D_8009BCEA) == 0)
        *(s16 *)(o + 0x20) = 0x8c;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121D1C);
extern void func_800EDEBC(void *o, s32 a);
extern void func_800224FC(s32 a, s32 b, s32 c, s32 d);

void func_80121D1C(char *o)
{
    func_800EDEBC(o, 0xd);
    func_800224FC(2, *(s16 *)(o + 0x12), *(s16 *)(o + 0x16), *(s16 *)(o + 0x1a));
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121D5C);
typedef struct { s16 s0, s2; } H_21D5C;
typedef struct O_21D5C {
    char p0[6]; u8 b6; char p1[0x12 - 7]; s16 x12; char p2[2]; s16 y16; char p3[2]; s16 z1a;
    char p4[0x40 - 0x1c]; H_21D5C *h; char p5[0x70 - 0x44]; s16 s70; char p6[0x7c - 0x72]; s16 vx, vy;
    char p7[0x9c - 0x80]; u8 b9c; char p8[0xac - 0x9d]; u8 bac;
} O_21D5C;
extern O_21D5C *D_8009C650;
extern void func_8010DE48(void);
extern void applyObjectAltSpeedVertical(O_21D5C *);
extern s16 probeSidesAndApplyTileResponse(O_21D5C *, s32, s32);

void func_80121D5C(O_21D5C *o)
{
    s16 flag;
    O_21D5C *p;
    if (o->b6 != 1) return;
    func_8010DE48();
    *(s32 *)o->h += o->vx << 8;
    o->vy += 8;
    if (o->vy > 0x680) o->vy = 0x680;
    if (o->vy < -0x680) o->vy = -0x680;
    applyObjectAltSpeedVertical(o);
    flag = 0;
    o->y16 += 8;
    if (o->y16 + D_8009C650->s70 >= D_8009C650->y16) {
        o->y16 = D_8009C650->y16 - D_8009C650->s70;
        flag = 1;
    }
    if (o->vx < 0) {
        o->h->s2 -= 8;
        if (o->h->s2 <= D_8009C650->h->s2) {
            o->h->s2 = D_8009C650->h->s2;
            if (flag) {
                func_800EDEBC(o, 0xd);
                func_800224FC(2, o->x12, o->y16, o->z1a);
            }
        }
    } else {
        o->h->s2 += 8;
        if (o->h->s2 >= D_8009C650->h->s2) {
            o->h->s2 = D_8009C650->h->s2;
            if (flag) {
                func_800EDEBC(o, 0xd);
                func_800224FC(2, o->x12, o->y16, o->z1a);
            }
        }
    }
    if (probeSidesAndApplyTileResponse(o, 0x10e, 1)) {
        func_800EDEBC(o, 0xd);
        o->bac = 3;
        o->b9c = 0;
        o->vx = 0;
        o->vy = 0;
        p = D_8009C650;
        o->h->s2 = p->h->s2;
        o->y16 = p->y16 - p->s70;
        o->b6 = 2;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121F54);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80121FF4);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122258);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012228C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122538);
extern void tickAnimation(GameObject *);
extern void func_8012D3FC(s32, s32, s32);
extern void removeItemFromInventory(s32, s32);
void func_80122538(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->velX = 0;
        o->velY = 0;
        o->unkB6 = 0;
        func_800EDEBC(o, 0x22);
        o->step++;
    case 1:
        tickAnimation(o);
        if (*(u16 *)o->anim == 0xbd) {
            func_8012D3FC(o->x.p.whole, o->y.p.whole, o->z.p.whole);
            func_8012D3FC((s16)(o->x.p.whole + 1), (s16)(o->y.p.whole - 2), o->z.p.whole);
            func_8012D3FC((s16)(o->x.p.whole - 2), (s16)(o->y.p.whole + 2), o->z.p.whole);
            func_8012D3FC((s16)(o->x.p.whole + 2), o->y.p.whole, o->z.p.whole);
            removeItemFromInventory(0, 4);
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122688);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012298C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122A34);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122B1C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122D60);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122E44);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122EA8);
typedef struct Q_22EA8 {
    u8 b0, b1, b2, b3;
    char pad4[8];
    u8 bc;
    char pad5[2];
    u8 bf;
    char pad6[4];
    s32 w14;
    char pad7[5];
    u8 b1d;
    char pad8[0x2e - 0x1e];
    s16 s2e;
    char pad9[0x40 - 0x30];
    s32 *p40;
    s32 *p44;
} Q_22EA8;
extern Q_22EA8 *allocObjectLayer5(void);
extern u8 D_8007E632;

void func_80122EA8(s16 *o)
{
    Q_22EA8 *q = allocObjectLayer5();
    if (q) {
        q->b0 = 1;
        q->b2 = 0xc;
        q->b3 = 8;
        q->bc = 0x80;
        q->bf = ((u8 **)&D_8007E6E4)[D_8007E632][3];
        q->s2e = 0;
        *q->p40 = o[1] << 16;
        q->w14 = o[3] << 16;
        *q->p44 = o[5] << 16;
        q->b1d = D_8009BCCA;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80122F64);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123038);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123148);
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0; u16 uv0, clut;
    s16 x1, y1; u16 uv1, tpage;
    s16 x2, y2; u16 uv2, pad1;
    s16 x3, y3; u16 uv3, pad2;
} PFT4_23148;
typedef struct { u16 uv0, p0, uv1, p1, uv2; u8 w, h; u16 uv3; s8 dx, dy; } Spr_23148;
extern char LZ_FILE_CTRL_CharArr[] asm("LZ_FILE_CTRL");
extern s32 LZ_FILE_CTRL_S32 asm("LZ_FILE_CTRL");
s32 projectActorPosition(GameObject *o, void *a, void *b);
void insertPrimWithBias(PFT4_23148 *p, s32 a, s32 b, s32 c, s32 d);
void func_80123148(GameObject *o)
{
    Spr_23148 *s;
    PFT4_23148 *p;
    s32 xy; s16 x, y;
    s = (Spr_23148 *)(*(volatile s32 *)&o->spriteBank + ((s16 *)((char *)o->spriteBank + (*(u16 *)o->anim << 2)))[1]);
    if (projectActorPosition(o, LZ_FILE_CTRL_CharArr, ((char *)&D_1F800074)) != 0) return;
    xy = LZ_FILE_CTRL_S32;
    y = xy >> 16;
    p = D_1F800164;
    p->code = 0x2c;
    p->r0 = o->unkB6;
    p->g0 = o->unkB6;
    p->b0 = o->unkB6;
    p->code |= 2;
    p->uv0 = s->uv0;
    p->uv1 = s->uv1;
    p->uv2 = s->uv2;
    p->uv3 = s->uv3;
    p->tpage = o->tpage;
    p->clut = o->clut;
    x = xy;
    p->x0 = x + s->dx - o->unkB8;
    p->y0 = y + s->dy - o->unkBA;
    p->x1 = p->x0 + s->w + (u16)o->unkB8 * 2 - 1;
    p->y1 = p->y0;
    p->x2 = p->x0;
    p->y2 = p->y0 + s->h + (u16)o->unkBA * 2 - 1;
    p->x3 = p->x1;
    p->y3 = p->y2;
    insertPrimWithBias(p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->unkF, 0x9000000);
    D_1F800164 = (PFT4_23148 *)((char *)D_1F800164 + 0x28);
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123314);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123AC4);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123D24);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123DC8);
s32 func_80123DC8(GameObject *a, GameObject *b)
{
    u16 u5; s32 u6; s32 w;
    s16 d; s16 e; s16 s; s16 t;
    Fix16 *ah = a->h, *bh = b->h;
    u5 = (u16)b->hitOffsetX;
    u6 = (u16)ah->p.whole;
    w = u6; w -= u5;
    d = bh->p.whole - u5;
    if ((u16)w <= d) {
        u16 sm;
        sm = a->hitOffsetY + (a->y.p.whole - b->y.p.whole);
        e = b->hitOffsetY - b->y.p.whole;
        if (sm > e + a->hitHeight)
            return 0;
        t = u6 - u5;
        if (t <= 0)
            s = 0;
        else
            s = t * e / d;
        if (b->hitOffsetY - s <= a->y.p.whole + a->hitOffsetY) {
            a->y.p.whole = b->hitOffsetY - s - a->hitOffsetY;
            a->y.p.frac = 0;
            a->velY = 0;
            a->touchFlag = 1;
            return 1;
        }
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80123F00);
s32 func_80123F00(GameObject *o, GameObject *p)
{
    s16 dy;
    s16 e;
    s16 s;
    u16 h;
    u16 uy;
    u16 sm;
    s32 lim;
    Fix16 *oh = o->h, *ph = p->h;
    u16 u6 = oh->p.whole;
    u16 u5 = ph->p.whole;

    { s32 d;
    uy = u6 - u5;
    d = u5 - (u16)p->hitOffsetX;
    uy += 6;
    { u16 t = d; t += o->hitOffsetX; uy += t; }
    dy = d;
    }
    lim = 0xe;
    if (uy > dy + (o->hitWidth + lim))
        return 0;
    sm = o->hitOffsetY + (o->y.p.whole - p->y.p.whole);
    e = p->hitOffsetY - p->y.p.whole;
    if (sm > e + o->hitHeight)
        return 0;
    s = o->y.p.whole + o->hitOffsetY - p->y.p.whole;
    if (s <= 0)
        h = 0;
    else
        h = s * dy / e;
    if (p->h->p.whole - (s16)h > o->h->p.whole + o->hitOffsetX)
        return 0;
    o->h->p.whole = p->h->p.whole - h - o->hitOffsetX;
    o->h->p.frac = 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124054);
void func_80124054(GameObject *o, u8 *b)
{
    u8 c;
    if ((u16)(o->d->p.whole - (*(Fix16 **)(b + 0x44))->p.whole + 0x2d) >= 0x5b)
        return;
    switch (b[0xc]) {
    case 0:
    case 1:
    case 2:
        func_80123F00(o, b);
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if (func_80123F00(o, b) != 0) {
            if (o->subState != 0x17) {
                o->subState = 0x17;
                o->step = 0;
            }
            o->unkBE = 5;
            c = b[0xc];
            o->touchFlag = 1;
            o->unkB0 = c - 0xc;
            b[0x69] = 1;
        }
        break;
    case 8:
    case 9:
        if (func_80123DC8(o, b) != 0) {
            if (o->state != 2 && o->subState != 0x17) {
                o->subState = 0x17;
                o->step = 0;
            }
            o->unkBE = 5;
            o->unkB0 = b[0xc] - 0xc;
            b[0x69] = 1;
        }
        break;
    case 10:
    case 11:
        if (func_80123DC8(o, b) == 0)
            return;
        o->unkBE = 5;
        o->unkB0 = b[0xc] - 0xc;
        b[0x69] = 1;
        *((u8 *)o + 0xa1) = 1;
        break;
    case 12:
        if (func_80123DC8(o, b) == 0)
            return;
        b[0x69] = 1;
        o->unkBE = 5;
        o->unkB0 = -1;
        *((u8 *)o + 0xa1) = 1;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124200);
typedef struct S_24200 { char pad[0x94]; s32 f; } S_24200;
extern void func_80051090(void);
extern void pushOutOfBoxX(void);
void func_80124200(s32 a, S_24200 *b)
{
if (b->f == 0) func_80051090(); else pushOutOfBoxX();
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124240);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124260);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124280);
extern s16 func_80051A18(void);
void func_80124280(s32 a, char *o)
{
    s16 s;
    s16 v;
    if (*(s32 *)(o + 0x94) == 0 && (s = func_80051A18(), 0 < s)) {
        if (s == 1)
            v = 2;
        else if (s == 3)
            v = 3;
        else
            return;
        *(s16 *)(o + 0x2e) = v;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801242E8);
extern void func_80051804();

void func_801242E8(s32 a, char *p)
{
    if (*(s32 *)(p + 0x94) == 0)
        func_80051804();
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124318);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124338);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801245FC);
extern s16 func_80124338(GameObject *o, GameObject *e);

void func_801245FC(GameObject *o, GameObject *e)
{
    s16 dy0;
    s32 d;
    s16 dx, dx2, sx, px;
    s16 dy, r;
    s16 t;
    s32 v;
    e->touchFlag = 0;
    if (e->unkC) {
        if (e->subtype == 2) {
            if (((u8 *)&o->unkA0)[2] == 3) return;
            if (func_80124338(o, e) == 1) *(u8 *)&o->unkA0 = e->animTimer;
        } else {
            if (func_80124338(o, e) == 1) *(u8 *)&o->unkA0 = e->animTimer;
        }
        return;
    }
    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) > 0x5a) return;
    dx = o->h->p.whole - e->h->p.whole;
    sx = e->hitOffsetX + o->hitOffsetX;
    if ((u16)(dx + sx) > e->hitWidth + o->hitWidth) return;
    d = (u16)o->y.p.whole - (u16)e->y.p.whole;
    {
        s16 t = d + (e->hitOffsetY + o->hitOffsetY);
        dy0 = d;
        if ((u16)t > o->hitHeight + e->hitHeight) return;
    }
    if (dx < 0) {
        dx = -dx;
        px = -sx;
        if ((u16)(sx - dx) < 4) {
            o->h->p.whole = e->h->p.whole + px;
            return;
        }
    }
    if ((s16)dy0 <= 0) {
        v = e->unk30;
        dx2 = e->h->p.whole - v;
        dy = e->unk34 - (u16)e->y.p.whole;
        dx = o->h->p.whole - v;
        if (dx <= 0) {
            r = 0;
        } else if (dx2 < dx) {
            r = dy;
        } else {
            r = dx * (s16)dy / dx2;
        }
        t = r + e->hitOffsetY;
        if (e->unk34 - t > o->y.p.whole + o->hitOffsetY) return;
        o->y.p.whole = e->unk34 - t - o->hitOffsetY;
        o->y.p.frac = 0;
        o->velY = 0;
        o->touchFlag = 1;
        e->touchFlag = 1;
        return;
    }
    o->y.p.whole = e->y.p.whole + ((e->hitHeight - e->hitOffsetY) + (o->hitHeight - o->hitOffsetY));
    if (o->velY < 0) o->velY = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801248A0);
extern u8 D_1F8001A4;

void func_801248A0(GameObject *o, GameObject *p)
{
    extern void decreaseObjectTimer(GameObject *o, s32 n);
    s16 d, w, t, e0, e1, sx, c;
    s32 dy, dd;
    u16 u;

    if (p->subtype == 0) {
        ((void (*)())pushOutOfBoxX)(o, p);
        return;
    }
    if ((u16)(o->d->p.whole - p->d->p.whole + 0x2d) >= 0x5b)
        return;
    w = p->hitOffsetX + o->hitOffsetX;
    t = w;
    d = o->h->p.whole - p->h->p.whole;
    e0 = p->hitWidth; e1 = o->hitWidth;
    if ((u16)(d + w) > e0 + e1)
        return;
    dd = (u16)o->y.p.whole - (u16)p->y.p.whole;
    u = dd + (p->hitOffsetY + o->hitOffsetY);
    dy = dd;
    if (u > o->hitHeight + p->hitHeight)
        return;
    sx = d;
    c = t;
    if ((d << 16) < 0) {
        d = -d;
        t = -t;
    } else {
        t = (e0 - p->hitOffsetX) + (e1 - o->hitOffsetX);
        c = t;
    }
    if ((u16)(c - d) < 5) {
        o->h->p.whole = p->h->p.whole + t;
        return;
    }
    if ((s16)dy <= 0) {
        if (*(u8 *)&o->unkAC == 2) {
            s16 a = p->hitOffsetY, b = p->y.p.whole, c = o->hitOffsetY;
            o->y.p.frac = 0;
            o->touchFlag = 1;
            o->y.p.whole = b - (a + c);
        } else if (!(o->active & 2) && p->unk6A != 0) {
            if (D_1F8001A4 == 0) {
                GameObject *a = (GameObject *)p->unk90;
                GameObject *b = (GameObject *)p->unk94;
                p->unk6A = 0;
                p->touchFlag = 1;
                a->touchFlag = 1;
                b->touchFlag = 1;
                p->active = 2;
                a->active = 2;
                b->active = 2;
                o->active = 2;
                o->state = 2;
                o->subState = 1;
                o->step = 0;
                decreaseObjectTimer(o, 1);
            }
        } else {
            s16 a = p->hitOffsetY, b = p->y.p.whole, c = o->hitOffsetY;
            u8 t;
            o->touchFlag = 1;
            t = o->unkA6;
            o->y.p.frac = 0;
            o->y.p.whole = b - (a + c);
            if (t == 0) {
                if (sx >= 0) {
                    o->unkBE = 8;
                    o->unkB0 = 2;
                } else {
                    o->unkBE = 9;
                    o->unkB0 = -2;
                }
            }
        }
        return;
    }
    o->y.p.whole = p->y.p.whole + ((p->hitHeight - p->hitOffsetY) + (o->hitHeight - o->hitOffsetY));
    if (o->velY < 0)
        o->velY = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124B38);
extern s16 func_80051604(u8 *, u8 *);
extern void decreaseObjectTimer(u8 *, s32);
extern u8 D_1F8001A4;

void func_80124B38(u8 *a, u8 *b)
{
    s16 r = func_80051604(a, b);
    if (r == -1)
        return;
    switch (*(u8 *)(a + 0xac)) {
    case 1:
        if (r < 3) {
            b[0] = 4;
            b[4] = 2;
            b[5] = 1;
            b[6] = 0;
            b[0x69] = 0;
            *(u16 *)(b + 0x2e) = *(u16 *)(a + 0x2e) & 1;
            *(u8 **)(a + 0xe4) = b;
            *(u8 *)(a + 0xac) = 2;
            break;
        }
    case 0:
    case 3:
        if ((b[0] & 2) == 0) {
            b[0x69] = 8;
            if (D_1F8001A4 == 0 && (a[0] & 2) == 0) {
                s32 ah, bh;
                a[0] = 2;
                bh = *(s16 *)((*(u8 **)(b + 0x40)) + 2);
                ah = *(s16 *)((*(u8 **)(a + 0x40)) + 2);
                a[4] = 2;
                a[5] = 0;
                a[6] = 0;
                *(u16 *)(a + 0x2e) = ah < bh;
                decreaseObjectTimer(a, 1);
            }
        }
        break;
    case 2:
        if (b[0] != 3) {
            s32 ah, bh;
            ah = *(s16 *)((*(u8 **)(a + 0x40)) + 2);
            bh = *(s16 *)((*(u8 **)(b + 0x40)) + 2);
            b[0] = 3;
            b[4] = 2;
            b[5] = 0;
            b[6] = 0;
            b[0x69] = 0;
            *(u16 *)(b + 0x7a) = bh < ah;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124CC8);
extern s16 boxesOverlapSigned(char *, char *);
extern void resolveHitResultA(char *, char *);
extern s16 D_1F80019E;
void func_80124CC8(char *a, char *b)
{
    if (*(s32 *)((u8 *)b + 0x94) == 0 && boxesOverlapSigned(a, b) >= 0) {
        u16 v;
        resolveHitResultA(a, b);
        if (*(u8 *)((u8 *)a + 2) != 10) {
            if (*(u8 *)((u8 *)a + 2) != 1) {
                u16 x = *(u16 *)((u8 *)a + 0x2e);
                v = x < 4 ? x & 1 : 3;
            } else {
                v = *(u16 *)((u8 *)a + 0x2e) & 1;
            }
            *(u16 *)((u8 *)b + 0x2e) = v;
            D_1F80019E = 0;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124D6C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124DF0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124F60);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80124FC8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801250E8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125274);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125354);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012543C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801254DC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125584);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801257A8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801259DC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125AB4);
void func_80125AB4(GameObject *o)
{
    s16 v;
    s16 r;
    s16 y;

    if (o->d->p.whole > 0xb4) return;
    if (o->d->p.whole == 0xb4) {
        y = o->y.p.whole;
        if (y >= -0x3a6) {
            v = o->h->p.whole - 0xc36;
            if (v >= 0) {
                r = (v * -132) / 138;
                if (r - 0x323 < y) {
                    o->y.p.whole = r - 0x323;
                    o->y.p.frac = 0;
                    o->velY = 0;
                    if (o->active & 2) {
                        o->unkBE = 9;
                        o->unkB0 = -2;
                        o->touchFlag = 1;
                        return;
                    }
                    if (D_1F8001A4 != 0) return;
                    o->active = 2;
                    o->animFrame = 1;
                    o->state = 2;
                    o->subState = 0;
                    o->step = 0;
                    decreaseObjectTimer(o, 1);
                }
            }
        }
    }
    if (o->d->p.whole < 0x5b && o->h->p.whole >= 0xc35 && (u16)(-0x23f - o->y.p.whole) < 0xfb) {
        o->h->p.whole = 0xc35;
        if (!(o->active & 2) && D_1F8001A4 == 0) {
            o->active = 2;
            o->animFrame = 1;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
            decreaseObjectTimer(o, 1);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125C84);
extern s16 func_80059514(void);
extern s16 D_1F8003BC;
extern s16 D_1F80019E;
extern GameObject *D_1F8003C0;

void func_80125C84(GameObject *a, GameObject *b)
{
    if (b->unk94 == 0 && func_80059514() != 0) {
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

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125D14);
extern s16 func_80059638(void);
extern s16 D_1F8003BC;
extern s16 D_1F80019E;
extern GameObject *D_1F8003C0;

void func_80125D14(GameObject *o, GameObject *t)
{
    if (*(s32 *)((char *)t + 0x94) == 0 && func_80059638() != 0) {
        GameObject *m;
        s16 s;
        o->unk9E = 1;
        s = D_1F8003BC;
        o->unkBA = 0xc;
        o->velY = 0;
        o->unkB8 = s;
        m = t->movetab;
        m->touchFlag = 1;
        D_1F80019E = 0;
        D_1F8003C0 = t;
        m->animFrame = o->animFrame & 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125DA8);
typedef struct {
    GameObject t;
    char pad[0xe8 - 0xc0];
    u16 e8;
    u16 ea;
} P80126A64_25DA8;

void func_80125DA8(P80126A64_25DA8 *o, GameObject *p)
{
    if (p->unkC == 0 && p->subtype != 2
        && (u16)(o->t.d->p.whole - p->d->p.whole + 45) < 91
        && (u16)(p->hitOffsetX + (o->e8 - p->h->p.whole)) < 19
        && (u16)(p->hitOffsetY + (o->ea - p->y.p.whole + 2)) <= p->hitHeight
        && !(o->t.animFrame & 1)) {
        s16 b;
        o->t.unk9E = 2;
        b = p->hitOffsetX;
        o->t.unkBA = 0x14;
        o->t.velY = 0;
        *(s16 *)0x1F80019E = 0;
        *(GameObject **)0x1F8003C0 = p;
        o->t.unkB8 = -b;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125E94);
extern s16 func_80056284(void);
extern s16 func_800566E4(u8 *, u8 *);
extern s16 D_1F80019E;

void func_80125E94(u8 *a, u8 *b)
{
    s16 r;
    u8 *c;
    u32 x;
    if (*(s32 *)(b + 0x94) == 0) {
        r = func_80056284();
        if (r == 0)
            return;
        if (r == 2) {
            if (a[0x68] == 0)
                return;
            x = *(u16 *)(a + 0x2e);
            c = *(u8 **)(b + 0x28);
            goto tail;
        }
        if (r != 1)
            return;
        if (a[0] == 5)
            a[0x69] = 0;
        return;
    }
    r = func_800566E4(a, b);
    if (r != 2)
        return;
    if (a[0x68] == 0)
        return;
    c = b;
    if (*(u16 *)(c + 0x2c) == 0)
        return;
    x = *(u16 *)(a + 0x2e);
    c = *(u8 **)(c + 0x28);
tail:
    *(u16 *)(c + 0x2e) = x & 1;
    c[0x6b] = *(u16 *)(b + 0x2c);
    c[0x68] = a[0x68];
    a[0x68] = 0;
    D_1F80019E = 0;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125FA4);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80125FE8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126048);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012608C);
extern s16 func_80056284();

void func_8012608C(void)
{
    if (func_80056284() != 0)
        *(s16 *)0x1f80019e = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801260C0);
void func_80056804(GameObject *o, GameObject *e);

void func_801260C0(GameObject *o, GameObject *e)
{
    s16 sx, dx, w, a, t; s32 dy; s32 d; u16 u;
    if (e->subtype != 2) {
        func_80056804(o, e);
        return;
    }
    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b)
        return;
    if (o->animFrame & 1)
        sx = o->hitOffsetX;
    else
        sx = o->hitWidth - o->hitOffsetX;
    dx = o->h->p.whole - e->h->p.whole;
    w = e->hitOffsetX + sx;
    if ((u16)dx > e->hitWidth + o->hitWidth)
        return;
    d = (u16)o->y.p.whole - (u16)e->y.p.whole;
    t = o->hitHeight;
    u = d + (e->hitOffsetY + (t - o->hitOffsetY));
    dy = d;
    if (u > t + e->hitHeight)
        return;
    if (dx < 0) {
        a = -dx;
        dx = -w;
        if ((u16)(w - a) < 4) {
            if (w == a)
                return;
            o->h->p.whole = e->h->p.whole + dx;
            ((u8 *)o)[0x9d] = 2;
            return;
        }
    }
    if ((s16)dy <= 0) {
        if (o->unk9C & 1)
            return;
        o->y.p.whole = e->y.p.whole - (e->hitOffsetY + (o->hitHeight - o->hitOffsetY));
        o->y.p.frac = 0;
        o->touchFlag = 1;
        return;
    }
    if (o->category == 2 && *(u16 *)&o->state == 0x102)
        return;
    o->y.p.whole = e->y.p.whole + (o->hitOffsetY + (e->hitHeight - e->hitOffsetY));
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801262AC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126330);
extern u8 D_800A53A7[];
extern s16 D_800A544A_S16Arr[] asm("D_800A544A");
extern void *D_8013A514;
extern void *D_8013A518;
extern void readAnimFrameCount(GameObject *o);
extern void playSFX(s32 id);
extern void func_801180DC(GameObject *o, s32 x, s32 y, s32 z);
extern void freeObjectLayer2(GameObject *o);

void func_80126330(GameObject *o)
{
    u16 t;
    u8 c;
    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 0xc;
        o->subState = 0;
        o->hitHeight = 0x1c;
        c = D_800A53A7[0];
        o->timer = 0;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->unkD = 0;
        o->unkF = c - 1;
        o->tpage = 9;
        o->anim = D_8013A514;
        o->spriteBank = D_1F8002D4[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) == 0)
            break;
        switch (o->subState) {
        case 0:
            if (o->touchFlag == 1) {
                o->subState = 1;
                o->touchFlag = 0;
                o->anim = D_8013A518;
                readAnimFrameCount(o);
            }
            break;
        case 1:
            if (o->touchFlag == 0) {
                o->subState = 0;
                o->anim = D_8013A514;
                o->timer = 0;
                readAnimFrameCount(o);
            } else if (o->touchFlag == 1) {
                o->touchFlag = 0;
                t = o->timer + 1;
                o->timer = t;
                if (D_800A544A_S16Arr[0] != 0) {
                    if (t % 32 == 0)
                        playSFX(0x2e);
                    else if (t % 16 == 0)
                        playSFX(0x2f);
                }
            }
            break;
        }
        tickAnimation(o);
        break;
    case 2:
        o->state++;
        if (o->unk6A != 0)
            playSFX(0x31);
        func_801180DC(o, (s16)(o->x.p.whole + 8), (s16)(o->y.p.whole - 6), o->z.p.whole);
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126558);
typedef struct AE_26558 { char p0[2]; u16 i; char p1[2]; u16 v; } AE_26558;
typedef struct { char p0[0x24]; AE_26558 *a; char p1[4]; u16 t; char p2[0x3e]; u16 b0, b1, b2, b3; } TA_26558;
extern u8 D_8013831C[];

static __inline__ void box_26558(TA_26558 *o, s32 idx)
{
    u8 *b = D_8013831C + idx * 4;
    o->b0 = *b++;
    o->b1 = *b++;
    o->b2 = *b;
    o->b3 = b[1];
}

s32 func_80126558(TA_26558 *o)
{
    AE_26558 *e, *n; u16 v; s32 k;
    o->t = o->t - 1;
    if (o->t != 0) return 0;
    e = o->a;
    v = e->v;
    k = v & 0xc000;
    switch (k) {
    case 0:
        o->a = e + 1;
        box_26558(o, e[1].i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x4000:
        o->a = e + 1;
        n = *(AE_26558 **)(e + 1);
        o->a = n;
        box_26558(o, n->i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x8000:
        o->t = v & 0x3fff;
        return 1;
    case 0xc000:
        o->a = e + 1;
        n = *(AE_26558 **)(e + 1);
        o->a = n;
        box_26558(o, n->i);
        o->t = o->a->v & 0x3fff;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801266C4);
typedef struct A_266C4 { s16 w0; u16 w2; u16 w4; u16 w6; } A_266C4;
typedef struct B_266C4 { u8 c[4]; } B_266C4;
s32 func_801266C4(GameObject *o)
{
    A_266C4 *a;
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
            o->anim = *(A_266C4 **)(a + 1);
            idx = ((A_266C4 *)o->anim)->w2;
        merge:
            { B_266C4 *t = D_8013831C; p = t[idx].c; }
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1];
            o->animTimer = ((A_266C4 *)o->anim)->w6 & 0x3fff;
            v = ((A_266C4 *)o->anim)->w4;
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

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126810);
typedef struct O_26810 {
    char p0[0x16]; u16 y;
    char p1[0x40 - 0x18]; s16 *t;
    char p2[0x69 - 0x44]; u8 b69;
    char p3[0x8c - 0x6a]; s32 d8c;
    char p4[0x98 - 0x90]; s16 w98;
    char p5[0x9c - 0x9a]; u8 b9c;
    char p6[0xae - 0x9d]; s16 wae;
    char p7[0xb2 - 0xb0]; s16 wb2;
    char p8[0xb6 - 0xb4]; s16 wb6;
} O_26810;
extern s16 D_1F80027E;
extern u16 D_1F800282;
extern u16 D_1F800284;
extern s16 probeCollisionAtDepthA(O_26810 *, s32, s32);

s32 func_80126810(O_26810 *o)
{
    s16 v;
    s32 r;
    s16 s;
    u16 u;
    if (o->b69 == 1) {
        o->d8c = 0;
        o->wb2 = 0;
        o->b69 = 0;
        o->wae = -1;
        o->b9c = 0;
        return 1;
    } else {
        s = probeCollisionAtDepthA(o, o->t[1], (s16)(o->y + 0x10));
        if (s != 0) {
            o->b69 = 0;
            v = D_1F80027E;
            if (v < 0) v = -v;
            if (v > 8) v = 8;
            if (D_1F80027E < 0) v = -v;
            o->d8c = (-v) & 0xff;
            s = D_1F800284;
            o->wb2 = v;
            o->b9c = 0;
            u = D_1F800282;
            o->wb6 = ((-v) << 2) & 0xff;
            o->wae = s;
            if ((u >> 5) & 8)
                o->w98 = 0;
            return 1;
        }
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126928);
typedef struct P_26928 { s16 w0; u16 w2; s16 w4; } P_26928;
typedef struct H_26928 { char p0[2]; s16 x; } H_26928;
typedef struct O_26928 {
    char p0[3]; u8 subtype;
    char p1[0x16 - 4]; s16 y;
    char p2[0x2e - 0x18]; u16 af;
    char p3[0x40 - 0x30]; H_26928 *h;
    char p4[0x9d - 0x44]; u8 b9d;
    char p5[0xb4 - 0x9e]; P_26928 p;
} O_26928;
extern s16 D_8007D788[];
extern s16 D_8007DB88[];
extern s16 func_80043AB0(O_26928 *, s32, s32, s32);

s32 func_80126928(O_26928 *o)
{
    u16 a, b;
    P_26928 *p = &o->p;
    if (o->subtype == 9 && o->af == 1 && o->y < -0x64 && o->h->x < 0x446)
        return 2;
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

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126A64);
extern u16 D_1F80016E;
extern u8 *D_80138424[];

u8 func_80126A64(s32 a)
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
                t = D_80138424[u];
    return t[nextRandom() & 0xf];
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80126B64);
typedef struct { u8 _p[0xa]; u8 ba, bb; s16 wc, we; } EX_26B64;
extern void applyFrameVelocityX(GameObject *);
extern char D_80077214[];
extern u16 *D_80139504[];
extern u16 *D_8013951C[];
extern u16 *D_80139520[];
extern u16 *D_80139524[];
extern u16 *D_8013951C_U16PtrArr[] asm("D_8013951C");
extern u16 *D_80139520_U16PtrArr[] asm("D_80139520");

void func_80126B64(GameObject *o)
{
    EX_26B64 *x = (EX_26B64 *)((char *)o + 0xb4);
    u8 *p;
    u16 *a;
    GameObject *q;
    s32 t;

    switch (o->unk7) {
    case 0:
        t = o->unk8C;
        o->unk9C = 2;
        x->we = 0;
        x->wc = t;
        o->touchFlag = 0;
        o->velV = 0;
        o->unk7++;
        if (o->movetab == 0) o->movetab = D_80077214;
        break;
    case 1:
        applyFrameVelocityX(o);
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        x->wc += 8;
        if (x->wc >= 0x33) {
            o->touchFlag = 0;
            o->unk7++;
            x->wc = 0xc0;
            o->unkAC = 0x1e;
            a = D_80139520[0];
            goto common;
        }
        break;
    case 2:
        applyFrameVelocityX(o);
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        x->wc += 5;
        if (x->wc > 0xff) x->wc = 0x100;
        if (func_80126810(o)) {
            if (!(o->touchFlag & 8)) {
                q = allocObjectLayer3();
                if (q != 0) {
                    q->active = 1;
                    q->type = 0x10;
                    q->subtype = 1;
                    q->x.p.whole = o->x.p.whole;
                    q->y.p.whole = o->y.p.whole + 0x10;
                    q->z.p.whole = o->z.p.whole;
                }
            }
            o->touchFlag = 0;
            x->wc = 0x100;
            o->movetab = ((char *)&D_800771FC);
            o->timer = 2;
            o->unkAC = 0x1d;
            o->unk7++;
            a = D_8013951C[0];
            goto common;
        }
        break;
    case 3:
        if (--o->timer == -1) {
            o->timer = 0;
            o->touchFlag = 0;
            x->wc = 0;
            o->velV = -0x300;
            o->unk9C = 1;
            o->unkAC = 0x1e;
            o->unk7++;
            a = D_80139520[0];
            goto common;
        }
        break;
    case 4:
        applyFrameVelocityX(o);
        o->velV += 0x40;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            if (func_80126810(o)) {
                if (!(o->touchFlag & 8)) {
                    q = allocObjectLayer3();
                    if (q != 0) {
                        q->active = 1;
                        q->type = 0x10;
                        q->subtype = 1;
                        q->x.p.whole = o->x.p.whole;
                        q->y.p.whole = o->y.p.whole + 0x10;
                        q->z.p.whole = o->z.p.whole;
                    }
                }
                o->timer = 2;
                o->unk7++;
                o->unkAC = 0x1d;
                a = D_8013951C_U16PtrArr[0];
                goto common;
            }
        }
        break;
    case 5:
        if (--o->timer == -1) {
            o->timer = 0;
            x->wc = 0;
            o->unk9C = 1;
            o->velV = -0x200;
            o->touchFlag = 0;
            o->unk7++;
            o->unkAC = 0x1e;
            a = D_80139520_U16PtrArr[0];
            goto common;
        }
        break;
    case 6:
        applyFrameVelocityX(o);
        o->velV += 0x40;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (o->timer == 0) {
            x->wc += 2;
            if (x->wc > 0x15) {
                x->wc = 0xe0;
                o->timer = 1;
                o->unkAC = 0x1f;
                a = D_80139524[0];
                o->anim = a;
                {
                u8 *pp = &D_8013831C[a[1] * 4];
                o->hitOffsetX = *pp++;
                o->hitWidth = *pp++;
                o->hitOffsetY = *pp++;
                o->hitHeight = *pp++;
                }
                o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
            }
        } else {
            x->wc += 4;
            if (x->wc > 0xff) x->wc = 0x100;
        }
        if (o->velV > 0) {
            o->unk9C = 2;
            if (func_80126810(o)) {
                if (!(o->touchFlag & 8)) {
                    q = allocObjectLayer3();
                    if (q != 0) {
                        q->active = 1;
                        q->type = 0x10;
                        q->subtype = 1;
                        q->x.p.whole = o->x.p.whole;
                        q->y.p.whole = o->y.p.whole + 0x10;
                        q->z.p.whole = o->z.p.whole;
                    }
                }
                o->touchFlag = 0;
                x->wc = 0;
                o->timer = 0x14;
                o->unkAC = 0x17;
                o->unk7++;
                a = D_80139504[0];
            common:
                o->anim = a;
                {
                u8 *pp = &D_8013831C[a[1] * 4];
                o->hitOffsetX = *pp++;
                o->hitWidth = *pp++;
                o->hitOffsetY = *pp++;
                o->hitHeight = *pp++;
                }
                o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
            }
        }
        break;
    case 7:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = x->ba;
            o->unk7 = x->bb;
            o->unk68 = 0;
        }
        break;
    }
    if (o->animFrame) o->unk8C = (u8)x->wc;
    else o->unk8C = -x->wc & 0xff;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801271F4);
typedef struct { u8 _p[0xa]; u8 ba, bb; s16 wc, we; } EX_271F4;
extern u16 *D_80139500[];
extern u16 *D_80139504[];

void func_801271F4(GameObject *o)
{
    EX_271F4 *x = (EX_271F4 *)((char *)o + 0xb4);
    u8 *p;
    u16 *a;
    GameObject *q;

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        o->unk7++;
    case 1:
        x->wc = o->unk8C;
        x->we = 0;
        o->movetab = ((char *)&D_800771FC);
        o->velV = -0x280;
        o->unk9C = 1;
        o->touchFlag = 0;
        o->unkAC = 0x16;
        o->unk7++;
        a = D_80139500[0];
        goto common;
    case 2:
        applyFrameVelocityX(o);
        func_80126558(o);
        o->velV += 0x20;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) o->unk9C = 2;
        o->touchFlag = 0;
        o->timer = 0;
        o->unk7++;
        break;
    case 3:
        if (o->velV < 0x400) applyFrameVelocityX(o);
        func_80126558(o);
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (func_80126810(o)) {
            if (!(o->touchFlag & 8)) {
                q = allocObjectLayer3();
                if (q != 0) {
                    q->active = 1;
                    q->type = 0x10;
                    q->subtype = 1;
                    q->x.p.whole = o->x.p.whole;
                    q->y.p.whole = o->y.p.whole + 0x10;
                    q->z.p.whole = o->z.p.whole;
                }
            }
            o->unk7++;
        } else {
            if (o->timer++ >= 0x35) {
                o->step = 7;
                o->unk7 = 1;
            }
        }
        break;
    case 4:
        o->timer = 0x1e;
        o->unkAC = 0x17;
        o->unk7++;
        a = D_80139504[0];
    common:
        o->anim = a;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 5:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = x->ba;
            o->unk7 = x->bb;
            o->unk68 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801274D4);
typedef struct { s16 w0; u16 w2; s16 w4; char p6[4]; u8 ba, bb; } EX_274D4;
extern void updateObjectSideFlag(GameObject *);
extern void applyFrameVelocityY(GameObject *);
extern void applyFrameVelocityXY(GameObject *);
extern void func_800EA16C(s16, s16, s16, u8);
extern char D_80077250[];
extern u16 *D_801394CC[];
extern u16 *D_801394D4[];
extern u16 *D_801394DC[];
extern u16 *D_801394E0[];
extern u16 *D_801394EC[];

#define SETBOX(a) \
    o->anim = a; { u8 *p; \
    p = &D_8013831C[a[1] * 4]; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p++; \
    o->hitHeight = *p++; } \
    o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;

static __inline__ void fin_274D4(GameObject *t)
{
    t->y.p.whole += 2;
    func_80126810(t);
}

void func_801274D4(GameObject *o)
{
    EX_274D4 *x = (EX_274D4 *)((char *)o + 0xb4);
    u16 *a;
    s16 s;
    u8 r;

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        o->unk9C = 0;
        o->unk7++;
        updateObjectSideFlag(o);
        o->timer = 0x28;
        o->movetab = ((char *)&D_800771FC);
        o->unkAC = 9;
        a = D_801394CC[0];
        SETBOX(a);
        fin_274D4(o);
        break;
    case 1:
        func_80126558(o);
        if (--o->timer != -1) goto move;
        o->timer = 0xc;
        o->unk68 = 1;
        o->velH = 0x200;
        o->touchFlag = 0;
        o->unkAC = 0x11;
        o->unk7++;
        a = D_801394EC[0];
        goto common;
    case 2:
        if (--o->timer == -1) o->unk7++;
        func_80126558(o);
        applyFrameVelocityY(o);
        if (o->animFrame != 0) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        if (!func_80126810(o)) goto fall;
        if (func_80126928(o)) {
            o->step = 4;
            o->unk7 = 0;
        }
        o->velH += 8;
        if (o->velH > 0x250) o->velH = 0x250;
        break;
    case 3:
        o->unk9C = 1;
        o->movetab = D_80077250;
        o->velV = -0x300;
        o->touchFlag = 0;
        o->unkAC = 0xd;
        o->unk7++;
        a = D_801394DC[0];
        SETBOX(a);
    case 4:
        func_80126558(o);
        applyFrameVelocityX(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            o->touchFlag = 0;
            o->unk7++;
        }
        if (!func_80126928(o)) break;
        o->step = 4;
        o->unk7 = 0;
        break;
    case 5:
        func_80126558(o);
        applyFrameVelocityX(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (func_80126810(o)) {
            o->unk8C = x->w2;
            if (o->visible) {
                if (o->animFrame) x->w4 = -0x10;
                else x->w4 = 0x10;
                func_800EA16C(o->x.p.whole + x->w4, o->y.p.whole, o->z.p.whole, 1);
            }
            o->timer = 0xf;
            o->unk7++;
        }
        if (!func_80126928(o)) break;
        o->step = 4;
        o->unk7 = 0;
        break;
    case 6:
        if (--o->timer == -1) o->unk7++;
        func_80126558(o);
        applyFrameVelocityXY(o);
        if (!func_80126810(o)) goto fall;
        if (o->unkB2 != 0) {
            s32 g = (o->unkB2 > 0);
            g ^= o->animFrame;
            if (g) o->timer = 0xf;
        }
        if (!func_80126928(o)) break;
        o->step = 4;
        o->unk7 = 0;
        break;
    case 7:
        o->unk68 = 0;
        o->velH = 0x250;
        o->unk7++;
    case 8:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (o->animFrame != 0) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        func_80126928(o);
        if (func_80126810(o)) {
            s = o->unkB2;
            if (s != 0) {
                s32 g = (s > 0);
                g ^= o->animFrame;
                if (!g) {
                    s16 t = s;
                    if (t < 0) t = -t;
                    o->velH -= t;
                }
            }
        } else {
        fall:
            x->ba = 1;
            x->bb = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        if ((o->velH -= 0x10) < 0) o->unk7++;
        break;
    case 9:
        o->timer = 0x78;
        o->unkAC = 0xe;
        o->unk7++;
        a = D_801394E0[0];
        SETBOX(a);
    case 10:
        func_80126558(o);
        if (--o->timer == -1) {
            o->timer = 0x3c;
            o->unkAC = 0xb;
            o->unk7++;
            a = D_801394D4[0];
        common:
            SETBOX(a);
        }
        goto move;
    case 11:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = 0;
            o->unk7 = 0;
            r = func_80126A64(o);
            if (r == 0xff) break;
            o->step = r;
        }
    move:
        fin_274D4(o);
        break;
    }
}
#undef SETBOX

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80127BFC);
typedef struct P_27BFC { u8 b0; u8 b1; u16 w2; s16 w4; } P_27BFC;
extern void *D_80139528[];
extern void *D_8013952C[];
extern void *D_80139530[];
extern void *D_80139550[];
extern void *D_80139554[];
extern void *D_80139558[];
extern void applyAnimVelocityX(GameObject *, u16);

#define SETBOX(o, A) \
    { \
        u16 *a = A; u8 *b; \
        o->anim = a; \
        b = D_8013831C + a[1] * 4; \
        o->hitOffsetX = *b++; \
        o->hitWidth = *b++; \
        o->hitOffsetY = b[0]; \
        o->hitHeight = b[1]; \
    }
#define ANIMT(o) o->animTimer = ((u16 *)o->anim)[3] & 0x3fff

static __inline__ void move_27BFC(GameObject *o)
{
    P_27BFC *p = (P_27BFC *)&o->unkB4;
    if (o->movetab != 0) {
        applyAnimVelocityX(o, 1 - o->animFrame);
    }
    if (o->unk9D != 0) {
        if (o->animFrame != (o->unk9D & 1)) {
            o->movetab = 0;
        }
        o->unk9D = 0;
    }
    if (o->animFrame == 1) p->w4 = 0x10;
    else p->w4 = -0x10;
    if (((s16 (*)(GameObject *, s16, s16, s16))func_80043AB0)(o, o->h->p.whole + p->w4, o->y.p.whole, 1 - o->animFrame)) {
        o->movetab = 0;
    }
}

void func_80127BFC(GameObject *o)
{
    P_27BFC *p = (P_27BFC *)&o->unkB4;
    u8 t;

    switch (o->unk7) {
    case 0:
        playSFX(7);
        o->timer = 4;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 0x20;
        o->unk7++;
        SETBOX(o, D_80139528[0]);
        ANIMT(o);
        o->unk9C = 1;
    case 1:
        func_80126558(o);
        move_27BFC(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            o->unk7++;
        }
        return;
    case 2:
        func_80126558(o);
        move_27BFC(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (func_80126810(o)) {
            if (o->movetab == 0) {
                o->unk8C = p->w2;
                o->unk7 = 4;
                o->timer = 0x1e;
                o->unkAC = 0x22;
                SETBOX(o, D_80139530[0]);
                ANIMT(o);
            } else {
                o->unk9C = 1;
                o->velV = -0x280;
                o->unk8C = 0;
                o->movetab = D_80077214;
                o->unk7++;
                p->b1 = 1;
                o->unkAC = 0x21;
                SETBOX(o, D_8013952C[0]);
                ANIMT(o);
            }
        }
        return;
    case 3:
        {
            s32 x;
            if (o->animFrame != 0) x = o->unk8C - 20;
            else x = o->unk8C + 20;
            o->unk8C = x & 0xff;
        }
        move_27BFC(o);
        o->velV += 0x30;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            if (func_80126810(o)) {
                if (o->movetab == 0) {
                    o->unk8C = p->w2;
                    o->unk7 = 4;
                    o->timer = 0x1e;
                    o->unkAC = 0x22;
                    SETBOX(o, D_80139530[0]);
                    ANIMT(o);
                } else if (t = p->b1, p->b1 = t + 0xff, t != 0) {
                    o->velV = ~(o->velV - 0x80) + 1;
                    if (o->velV < 0) o->unk9C = 1;
                    o->movetab = ((char *)&D_800771FC);
                } else {
                    o->unk8C = p->w2;
                    o->timer = 0x1e;
                    o->unkAC = 0x22;
                    o->unk7++;
                    SETBOX(o, D_80139530[0]);
                    ANIMT(o);
                }
            }
        }
        return;
    case 4:
        if (--o->timer == -1) {
            o->unkAC = 0x2a;
            o->unk7++;
            SETBOX(o, D_80139550[0]);
            ANIMT(o);
        }
        break;
    case 5:
        if (func_80126558(o)) {
            o->timer = 0x3c;
            o->unkAC = 0x2b;
            o->unk7++;
            SETBOX(o, D_80139554[0]);
            ANIMT(o);
        }
        break;
    case 6:
        func_80126558(o);
        if (--o->timer == -1) {
            o->timer = 0x3c;
            o->unkAC = 0x2c;
            o->unk7++;
            SETBOX(o, D_80139558[0]);
            ANIMT(o);
        }
        break;
    case 7:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = 1;
            o->touchFlag = 0;
            o->unk7 = 2;
            o->unk68 = 0;
            o->unk9C = 0;
        }
        break;
    default:
        return;
    }
    o->y.p.whole += 2;
    func_80126810(o);
}
#undef SETBOX
#undef ANIMT

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801282F0);
typedef struct { char p0; u8 b01; char p2[2]; s16 w04; char p6[4]; u8 b0a, b0b; char p0c[2]; s16 w0e; } X_282F0;
extern char D_8007725C[];
extern u16 *D_801394CC[];
extern u16 *D_801394EC[];
extern u16 *D_801394F0[];
extern u16 *D_801394F4[];
extern u16 *D_80139544[];

#define SETANIM(o, T) \
    { \
        u16 *a; \
        u8 *p; \
        a = T[0]; \
        o->anim = a; \
        p = &D_8013831C[a[1] * 4]; \
        o->hitOffsetX = *p++; \
        o->hitWidth = *p++; \
        o->hitOffsetY = p[0]; \
        o->hitHeight = p[1]; \
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff; \
    }

static __inline__ s16 past_282F0(GameObject *o)
{
    if (o->animFrame) {
        if (o->h->p.whole >= (*(s16 *)&D_1F80016A) - 0x30) return 0;
        return 1;
    }
    if ((*(s16 *)&D_1F80016A) + 0x30 < o->h->p.whole) return 1;
    return 0;
}

void func_801282F0(GameObject *o)
{
    X_282F0 *x = (X_282F0 *)((char *)o + 0xb4);

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        o->unk9C = 0;
        x->w0e = 0;
        o->unk7++;
        updateObjectSideFlag(o);
        o->timer = 0x28;
        o->unkAC = 9;
        SETANIM(o, D_801394CC);
        func_80126810(o);
        break;
    case 1:
        func_80126558(o);
        if (--o->timer == -1) {
            o->unk68 = 1;
            o->velH = 0x280;
            o->movetab = D_8007725C;
            o->touchFlag = 0;
            o->unkAC = 0x11;
            o->unk7++;
            SETANIM(o, D_801394EC);
            break;
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 2:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (o->animFrame)
            o->h->raw = o->h->raw - (o->velH << 8);
        else
            o->h->raw = o->h->raw + (o->velH << 8);
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        if (func_80126928(o) != 0) {
            o->step = 4;
            o->unk7 = 0;
            break;
        }
        if (past_282F0(o)) {
            o->unk7 = 3;
            x->w0e = 0;
        }
        o->velH += 0x10;
        if (o->velH > 0x300) o->velH = 0x300;
        break;
    case 3:
        o->velH = 0x200;
        o->unk68 = 0;
        o->unkAC = 0x12;
        o->unk7++;
        SETANIM(o, D_801394F0);
    case 4:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (o->animFrame)
            o->h->raw = o->h->raw - (o->velH << 8);
        else
            o->h->raw = o->h->raw + (o->velH << 8);
        func_80126928(o);
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        o->velH -= 0x10;
        if (o->velH < 0) {
            o->timer = 0x28;
            o->unkAC = 0x13;
            o->unk7++;
            SETANIM(o, D_801394F4);
        }
        break;
    case 5:
        func_80126558(o);
        if (--o->timer == -1) {
            o->timer = 0x5a;
            o->unkAC = 0x27;
            o->unk7++;
            SETANIM(o, D_80139544);
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 6:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = 1;
            o->unk7 = 2;
            o->animFrame = 1 - o->animFrame;
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80128840);
typedef struct { char p0; u8 b01; char p2[2]; s16 w04; char p6[4]; u8 b0a, b0b; char p0c[2]; s16 w0e; } X_28840;
extern u8 D_801382EC[];
extern u8 D_801382FC[];
extern u16 *D_801394E4[];
extern u16 *D_801394E8[];
extern void applyAnimVelocityXY(GameObject *, u16);
extern s16 func_80044694(GameObject *, s16, s16);

#define SETANIM(o, T) \
    { \
        u16 *a; \
        u8 *p; \
        a = T[0]; \
        o->anim = a; \
        p = &D_8013831C[a[1] * 4]; \
        o->hitOffsetX = *p++; \
        o->hitWidth = *p++; \
        o->hitOffsetY = p[0]; \
        o->hitHeight = p[1]; \
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff; \
    }

static __inline__ s32 inRange_28840(GameObject *o)
{
    if ((u16)(o->d->p.whole - *(u16 *)0x1F800172 + 45) >= 91) return 0;
    if ((u16)(o->y.p.whole - *(u16 *)0x1F80016E + 70) >= 111) return 0;
    return (u16)(o->h->p.whole - *(u16 *)0x1F80016A + 128) < 257;
}

void func_80128840(GameObject *o)
{
    X_28840 *x = (X_28840 *)((char *)o + 0xb4);
    u8 *t;
    u8 c;

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        o->unk9C = 0;
        x->w0e = 0;
        x->b01 = 0;
        o->timer = 0x3c;
        o->unk7++;
        updateObjectSideFlag(o);
        o->movetab = D_80077214;
        o->unkAC = 0xf;
        SETANIM(o, D_801394E4);
    case 1:
        func_80126558(o);
        if (--o->timer == -1) {
            if (inRange_28840(o)) {
                o->timer = 8;
                o->unkAC = 0x10;
                o->unk7++;
                SETANIM(o, D_801394E8);
            } else {
                o->step = 0;
                o->unk7 = 0;
            }
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 2:
        func_80126558(o);
        applyFrameVelocityXY(o);
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        if (--o->timer == -1 || func_80126928(o) != 0) {
            o->timer = 0x3c;
            o->unkAC = 0xf;
            o->unk7++;
            SETANIM(o, D_801394E4);
        }
        break;
    case 3:
        func_80126558(o);
        if (--o->timer == -1) {
            if (inRange_28840(o)) {
                o->unk7++;
                x->w0e = 0;
                o->timer = 8;
                o->unkAC = 0x10;
                SETANIM(o, D_801394E8);
            } else {
                o->step = 0;
                o->unk7 = 0;
            }
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 4:
        func_80126558(o);
        applyAnimVelocityXY(o, 1 - o->animFrame);
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        if (o->unk9D != 0) {
            if (o->animFrame != (o->unk9D & 1)) o->timer = 0;
            o->unk9D = 0;
        }
        if (o->animFrame == 1) x->w04 = 0x10;
        else x->w04 = -0x10;
        if (func_80044694(o, o->h->p.whole + x->w04, o->y.p.whole) != 0) o->timer = 0;
        if (--o->timer == -1) {
            o->unk7++;
            updateObjectSideFlag(o);
            o->timer = 0x3c;
            o->unkAC = 0xf;
            SETANIM(o, D_801394E4);
        }
        break;
    case 5:
        func_80126558(o);
        if (inRange_28840(o)) {
            if (--o->timer == -1) o->unk7++;
        } else {
            o->step = 0;
            o->unk7 = 0;
        }
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 6:
        o->y.p.whole += 2;
        func_80126810(o);
        c = x->b01;
        if (c != 2) {
            t = D_801382EC;
            if (c != 0) t = D_801382FC;
            if (t[nextRandom() & 0xf] == 0) goto ok;
        }
        o->step = 3;
        o->unk7 = 0;
        break;
    ok:
        o->unk7 = 2;
        x->b01++;
        o->timer = 8;
        o->unkAC = 0x10;
        SETANIM(o, D_801394E8);
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80128EF4);
typedef struct { char p0[0xa]; u8 b0a, b0b; char p0c[2]; s16 w0e; } X_28EF4;
extern u16 *D_801394C8[];
extern u16 *D_801394C0[];
extern void updateObjectSideFlag(GameObject *);

static __inline__ s16 ahead_28EF4(GameObject *o)
{
    if (o->animFrame != 0) {
        if (o->h->p.whole >= *(s16 *)0x1F80016A - 0x20) return 0;
        return 1;
    }
    if (o->h->p.whole > *(s16 *)0x1F80016A + 0x20) return 1;
    return 0;
}
void func_80128EF4(GameObject *o)
{
    X_28EF4 *x = (X_28EF4 *)((char *)o + 0xb4);
    u8 *p;
    u16 *a;
    s16 s;
    u8 r;
    s16 f;
    s32 k;

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        o->unk9C = 0;
        x->w0e = 0;
        o->touchFlag = 0;
        o->unk7++;
        updateObjectSideFlag(o);
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 8;
        {
        u16 *a;
        u8 *p;
        a = D_801394C8[0];
        o->anim = a;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        }
    case 1:
        func_80126558(o);
        applyFrameVelocityXY(o);
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        if (func_80126928(o) != 0) {
            o->unk7 = 5;
            break;
        }
        if (ahead_28EF4(o)) o->unk7 = 2;
        break;
    case 2:
        o->timer = 0x5a;
        o->unk9D = 0;
        o->unkAC = 0xb;
        o->unk7++;
        a = D_801394D4[0];
        o->anim = a;
        {
        u8 *p;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        }
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 3:
        if (--o->timer == 0) o->unk7++;
        func_80126558(o);
        o->y.p.whole += 2;
        func_80126810(o);
        break;
    case 4:
        o->step = 0;
        o->unk7 = 0;
        r = func_80126A64(o);
        if (r != 0xff) o->step = r;
        break;
    case 5:
        o->unkAC = 6;
        o->unk7++;
        a = D_801394C0[0];
        o->anim = a;
        {
        u8 *p;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        }
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 6:
        if (o->animTimer == 1) {
            k = func_80126558(o);
            s = ((u16 *)o->anim)[2];
            if (s != 0) playSFXWithNote((s16)s >> 8, s & 0xff);
        } else {
            k = func_80126558(o);
        }
        if (k != 0) {
            r = func_80126A64(o);
            if (r != 0xff) {
                o->step = r;
                o->unk7 = 0;
            } else {
                o->step = 0;
                o->unk7 = 0;
                o->animFrame = 1 - o->animFrame;
            }
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801292F8);
typedef struct { u8 b0, b1; char p2[8]; u8 b0a, b0b; char p0c[2]; s16 w0e; } X_292F8;
extern u8 D_8013830C[];
extern u16 *D_801394A8[];
extern u16 *D_801394A8_U16PtrArr[] asm("D_801394A8");
extern u16 *D_801394C4[];
extern u16 *D_801394D0[];
extern u16 *D_80139548[];

void func_801292F8(GameObject *o)
{
    X_292F8 *x = (X_292F8 *)((char *)o + 0xb4);
    u8 *p;
    u16 *a;
    s16 s;
    s16 t;
    u8 r;
    u8 c;
    s32 k;
    s32 m;

    switch (o->unk7) {
    case 12:
        o->unk7 = 0;
        o->animFrame = 1 - o->animFrame;
    case 0:
        o->movetab = D_80077214;
        x->b1 = 0;
        o->unk7++;
    case 1:
        x->w0e = 0;
        o->touchFlag = 0;
        o->unk9D = 0;
        o->timer = 0x38;
        o->unk7++;
        if (D_801382FC[nextRandom() & 0xf] != 0) o->timer = 0x60;
        o->unkAC = 7;
        a = D_801394C4[0];
        goto common;
    case 2:
        if (--o->timer == -1) o->unk7++;
        func_801266C4(o);
        o->y.p.whole += 4;
        if (func_80126810(o) == 0 && x->w0e++ > 3) {
            x->b0a = 1;
            x->b0b = 2;
            o->step = 7;
            o->unk7 = 0;
            break;
        }
        k = func_80126928(o);
        if (k != 0) {
            if (k == 1) {
                o->unk7 = 8;
                break;
            }
            o->unk7 = 8;
            if ((u16)(o->d->p.whole - (*(u16 *)&D_1F800172) + 0x2d) > 0x5a) break;
            if ((u16)(o->h->p.whole - (*(u16 *)&D_1F80016A) + 0x60) > 0xc0) break;
            if ((*(s16 *)&D_1F80016E) < o->y.p.whole + 0x10) break;
            o->unk7 = 13;
            o->timer = 0x50;
            o->unkAC = 0x28;
            a = D_80139548[0];
            goto common;
        }
        r = func_80126A64(o);
        if (r != 0xff) {
            o->step = r;
            o->unk7 = 0;
        }
        break;
    case 3:
        c = x->b1;
        if (c == 3) {
            o->unk7 = 6;
            break;
        }
        x->b1 = c + 1;
        o->unk7++;
        x->b0 = 0;
        m = D_8013830C[nextRandom() & 0xf];
        o->unkAC = m;
        a = D_801394A8[m];
        goto common;
    case 4:
        applyFrameVelocityY(o);
        func_80126810(o);
        if (o->animTimer == 1) {
            k = func_80126558(o);
            s = ((u16 *)o->anim)[2];
            if (s != 0) playSFXWithNote(s >> 8, s & 0xff);
        } else {
            k = func_80126558(o);
        }
        if (k == 0) break;
        if (x->b0 == 0) {
            r = func_80126A64(o);
            if (r != 0xff) {
                o->step = r;
                o->unk7 = 0;
            } else {
                o->unk7 = 1;
            }
            break;
        }
        o->unkAC = 3;
        o->unk7++;
        if (x->b0 == 1) o->unkAC = 5;
        a = D_801394A8_U16PtrArr[o->unkAC];
        goto common;
    case 5:
        applyFrameVelocityY(o);
        func_80126810(o);
        if (o->animTimer == 1) {
            k = func_80126558(o);
            s = ((u16 *)o->anim)[2];
            if (s != 0) playSFXWithNote(s >> 8, s & 0xff);
        } else {
            k = func_80126558(o);
        }
        if (k == 0) break;
        r = func_80126A64(o);
        if (r != 0xff) {
            o->step = r;
            o->unk7 = 0;
        } else {
            o->unk7 = 1;
        }
        break;
    case 6:
        t = 0x5a;
        goto c10;
    case 7:
        if (--o->timer == -1) {
            updateObjectSideFlag(o);
            o->step = 0;
            o->unk7 = 0;
            r = func_80126A64(o);
            if (r == 0xff) break;
            o->step = r;
        }
        func_80126558(o);
        applyFrameVelocityY(o);
        func_80126810(o);
        break;
    case 8:
        o->unkAC = 6;
        o->unk7++;
        a = D_801394C0[0];
        goto common;
    case 9:
        if (o->animTimer == 1) {
            k = func_80126558(o);
            s = ((u16 *)o->anim)[2];
            if (s != 0) playSFXWithNote(s >> 8, s & 0xff);
        } else {
            k = func_80126558(o);
        }
        if (k != 0) o->unk7++;
        applyFrameVelocityY(o);
        func_80126810(o);
        break;
    case 10:
        t = 0x3c;
    c10:
        o->timer = t;
        o->unk9D = 0;
        o->unkAC = 10;
        o->unk7++;
        a = D_801394D0[0];
    common:
        o->anim = a;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 11:
        if (--o->timer == -1) {
            o->unk7 = 12;
            r = func_80126A64(o);
            if (r == 0xff) break;
            o->step = r;
            o->unk7 = 0;
        }
        func_80126558(o);
        applyFrameVelocityY(o);
        func_80126810(o);
        break;
    case 13:
        func_80126558(o);
        if (--o->timer != -1) break;
        o->animFrame = 0;
        o->unk7 = 0;
        if ((u16)(o->d->p.whole - D_1F800172[0] + 0x2d) > 0x5a) break;
        if ((u16)(o->h->p.whole - (*(u16 *)&D_1F80016A) + 0x40) > 0x80) break;
        if ((*(s16 *)&D_1F80016E) < o->y.p.whole + 0x10) break;
        o->animFrame = 1;
        x->b0a = 1;
        x->b0b = 2;
        o->step = 6;
        o->unk7 = 0;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_801299E8);
extern u16 *D_80139540[];

void func_801299E8(GameObject *o)
{
    u8 *p;
    s32 x;
    u16 *a;

    switch (o->step) {
    case 0:
        o->unkB = 1;
        o->unkF = 4;
        o->active = 2;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 0x26;
        o->category |= 0x80;
        o->step++;
        a = D_80139540[0];
        o->anim = a;
        p = &D_8013831C[a[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1) x = o->unk8C + 20;
    else x = o->unk8C - 20;
    o->unk8C = x & 0xff;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_80129B64);
extern u8 D_800A5444[];
extern void *D_80139534[];
extern void *D_80139538[];
extern void *D_8013953C[];
extern void func_8002367C(s32);
extern void spawnItemNotification(s32, s32);

#define SETBOX(o) \
    { \
        u8 *b = D_8013831C + ((u16 *)o->anim)[1] * 4; \
        o->hitOffsetX = *b++; \
        o->hitWidth = *b++; \
        o->hitOffsetY = b[0]; \
        o->hitHeight = b[1]; \
    }
#define ANIMT(o) o->animTimer = ((u16 *)o->anim)[3] & 0x3fff

#define COLLIDE(o) \
    ((void (*)(GameObject *, s16, s16, s32))func_80043AB0)(o, o->h->p.whole + 8, o->y.p.whole + 8, 0); \
    ((void (*)(GameObject *, s16, s16, s32))func_80043AB0)(o, o->h->p.whole - 8, o->y.p.whole + 8, 1);

void func_80129B64(GameObject *o)
{
    GameObject *n;
    s16 a;
    s32 off;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        o->category |= 0x80;
        if ((u32)(o->subtype - 9) < 2) {
            func_8002367C(o->objectIndex);
        }
        spawnItemNotification(0, 6);
        o->movetab = D_80077214;
        *(s8 *)&o->unkF = -7;
        o->unk68 = 0;
        o->unk8C = 0;
        o->velV = 0;
        o->step++;
    case 1:
        o->velV += 0x40;
        if (o->velV > 0x500) {
            o->velV = 0x500;
        }
        COLLIDE(o);
        o->y.raw += o->velV << 8;
        if (func_80126810(o)) {
            o->velV = 0;
        }
        break;
    case 2:
        D_800A539E = 2;
        o->timer = 4;
        o->unkAC = 0x23;
        o->step++;
        goto set23;
    case 3:
        if (--o->timer == -1) {
            o->timer = 8;
            o->unkAC = 0x24;
            o->step++;
            o->anim = D_80139538[0];
            SETBOX(o);
            ANIMT(o);
            n = allocObjectLayer3();
            if (n != 0) {
                n->active = 1;
                n->type = 0x10;
                n->subtype = 0;
                off = -16;
                if (o->animFrame & 1) off = 16;
                n->x.p.whole = o->x.p.whole + off;
                n->y.p.whole = o->y.p.whole;
                n->z.p.whole = o->z.p.whole;
                n->animFrame = o->animFrame & 1;
            }
        }
        applyFrameVelocityY(o);
        COLLIDE(o);
        func_80126810(o);
        break;
    case 4:
        if (--o->timer == -1) {
            o->unkAC = 0x25;
            o->anim = D_8013953C[0];
            SETBOX(o);
            ANIMT(o);
            o->step++;
            o->timer = 0xe;
        }
        applyFrameVelocityY(o);
        COLLIDE(o);
        func_80126810(o);
        break;
    case 5:
        applyFrameVelocityX(o);
        o->y.p.whole += 3;
        COLLIDE(o);
        if (func_80126810(o)) {
            a = D_1F80027E;
            if (a < 0) a = -a;
            if (a > 8) a = 8;
            if (D_1F80027E < 0) a = -a;
            o->unk8C = -a & 0xff;
            o->unkB2 = a;
            o->unkB6 = (-a << 2) & 0xff;
            o->unkAE = *(u16 *)0x1F800284;
            o->unk9C = 0;
            if ((*(u16 *)0x1F800282 >> 5) & 8) {
                o->unk98 = 0;
            }
        }
        if (--o->timer == -1) {
            D_800A5444[0] = 3;
            o->unkAC = 0x23;
            o->anim = D_80139534[0];
            SETBOX(o);
            ANIMT(o);
            o->step++;
        }
        break;
    case 6:
        o->unkAC = 0x23;
    set23:
        o->anim = D_80139534[0];
        SETBOX(o);
        ANIMT(o);
        applyFrameVelocityY(o);
        COLLIDE(o);
        func_80126810(o);
        break;
    case 7:
        o->unkAC = 0x26;
        o->anim = D_80139540[0];
        SETBOX(o);
        ANIMT(o);
        o->step++;
        break;
    case 8:
        break;
    }
}
#undef SETBOX
#undef ANIMT
#undef COLLIDE

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012A160);
typedef struct P_2A160 { u8 b0; u8 b1; u16 w2; s16 w4; } P_2A160;
extern u16 *D_8013954C[];
extern void cloneItemPickupObject(GameObject *);

#define SETBOX(o, A) \
    { \
        u16 *aa = A; u8 *b; \
        o->anim = aa; \
        b = D_8013831C + aa[1] * 4; \
        o->hitOffsetX = *b++; \
        o->hitWidth = *b++; \
        o->hitOffsetY = b[0]; \
        o->hitHeight = b[1]; \
    }
#define ANIMT(o) o->animTimer = ((u16 *)o->anim)[3] & 0x3fff

static __inline__ void move_2A160(GameObject *o)
{
    P_2A160 *p = (P_2A160 *)&o->unkB4;
    if (o->movetab != 0) {
        applyAnimVelocityX(o, 1 - o->animFrame);
    }
    if (o->unk9D != 0) {
        if (o->animFrame != (o->unk9D & 1)) {
            o->movetab = 0;
        }
        o->unk9D = 0;
    }
    if (o->animFrame == 1) p->w4 = 0x10;
    else p->w4 = -0x10;
    if (((s16 (*)(GameObject *, s16, s16, s16))func_80043AB0)(o, o->h->p.whole + p->w4, o->y.p.whole, 1 - o->animFrame)) {
        o->movetab = 0;
    }
}

static __inline__ void fin_2A160(GameObject *t)
{
    t->y.p.whole += 2;
    func_80126810(t);
}

static __inline__ void fin2_2A160(GameObject *t)
{
    ANIMT(t);
    cloneItemPickupObject(t);
}

void func_8012A160(GameObject *o)
{
    P_2A160 *p = (P_2A160 *)&o->unkB4;
    u8 t;
    u16 *a;

    switch (o->step) {
    case 0:
        o->category |= 0x80;
        playSFX(0xf);
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unk9C = 1;
        o->unkAC = 0x29;
        o->touchFlag = 0;
        o->unk8C = 0;
        o->animFrame = (1 - o->unk7A) & 1;
        o->step++;
        SETBOX(o, D_8013954C[0]);
        ANIMT(o);
    case 1:
        move_2A160(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            o->touchFlag = 0;
            o->step++;
        }
        return;
    case 2:
        move_2A160(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (func_80126810(o)) {
            if (o->movetab == 0) {
                { u16 u = p->w2; o->step = 4; o->timer = 0x168; o->unkAC = 0x22; o->unk8C = u; SETBOX(o, D_80139530[0]); fin2_2A160(o); }
            } else {
                o->unk9C = 1;
                o->active = 3;
                o->velV = -0x280;
                o->unk8C = 0;
                o->movetab = D_80077214;
                o->step++;
                p->b1 = 1;
                o->touchFlag = 0;
                o->unkAC = 0x21;
                SETBOX(o, D_8013952C[0]);
                ANIMT(o);
            }
        }
        return;
    case 3:
        {
            s32 x;
            if (o->animFrame != 0) x = o->unk8C - 20;
            else x = o->unk8C + 20;
            o->unk8C = x & 0xff;
        }
        move_2A160(o);
        o->velV += 0x30;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            if (func_80126810(o)) {
                if (o->movetab == 0) {
                    { u16 u = p->w2; o->step = 4; o->timer = 0x168; o->unkAC = 0x22; o->unk8C = u; SETBOX(o, D_80139530[0]); fin2_2A160(o); }
                } else if (t = p->b1, p->b1 = t + 0xff, t != 0) {
                    o->velV = ~(o->velV - 0x80) + 1;
                    if (o->velV < 0) o->unk9C = 1;
                    o->movetab = ((char *)&D_800771FC);
                } else {
                    o->unk8C = p->w2;
                    o->timer = 0x168;
                    o->unkAC = 0x22;
                    o->step++;
                    SETBOX(o, D_80139530[0]);
                    fin2_2A160(o);
                }
            }
        }
        return;
    case 4:
        if (--o->timer == -1) {
            o->unkAC = 0x2a;
            o->step++;
            a = D_80139550[0];
            goto common;
        }
        break;
    case 5:
        if (func_80126558(o)) {
            o->timer = 0x78;
            o->unkAC = 0x2b;
            o->step++;
            a = D_80139554[0];
            goto common;
        }
        break;
    case 6:
        func_80126558(o);
        if (--o->timer == -1) {
            o->timer = 0x3c;
            o->unkAC = 0x2c;
            o->step++;
            a = D_80139558[0];
        common:
            SETBOX(o, a);
            ANIMT(o);
        }
        break;
    case 7:
        func_80126558(o);
        if (--o->timer == -1) {
            *(s8 *)&o->unkF = -9;
            o->active = 1;
            o->state = 1;
            o->category &= 0x7f;
            if (o->subtype == 8) o->subState = 3;
            else o->subState = 1;
            o->step = 1;
            o->unk7 = 2;
            o->touchFlag = 0;
            o->unk68 = 0;
            o->unk9C = 0;
        }
        break;
    default:
        return;
    }
    fin_2A160(o);
}
#undef SETBOX
#undef ANIMT

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012A914);
extern u8 D_80138430[];
extern u8 D_80138438[];
extern u16 *D_80139564;

static __inline__ void SetBox_2A914(GameObject *o)
{
    u8 *p;
    p = &D_8013831C[((u16 *)o->anim)[1] * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p++;
    o->hitHeight = *p;
    o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
}

static __inline__ s16 InRange_2A914(GameObject *o)
{
    if ((u16)(o->d->p.whole - (*(u16 *)&D_1F800172) + 0x2d) >= 0x5b) return 0;
    if ((u16)(o->y.p.whole - D_1F80016E + 0x46) >= 0x6f) return 0;
    return (u16)(o->h->p.whole - (*(u16 *)&D_1F80016A) + 0x80) < 0x101;
}

void func_8012A914(GameObject *o)
{
    extern u16 *D_801395B0;
    extern u16 *D_80139568;
    s16 *q = &o->unkB4;
    s32 r;
    u16 dx;
    u16 dy;
    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->touchFlag = 0;
        o->step++;
        o->unkAC = D_80138430[o->subtype];
        o->anim = D_801394A8[o->unkAC];
        SetBox_2A914(o);
        break;
    case 1:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (func_80126810(o)) {
            s32 t = (u16)q[1];
            o->timer = 0;
            o->unk8C = t;
            o->step++;
        }
        break;
    case 2:
        func_80126558(o);
        if (o->unkC == 1)
            break;
        dx = o->h->p.whole - (*(u16 *)&D_1F80016A);
        dx += 0xa0;
        if ((u16)(o->d->p.whole - (*(u16 *)&D_1F800172) + 0x2d) >= 0x5b
            || dx >= 0x141) {
            o->timer = 0;
        } else if (o->timer++ > 0x3c) {
            o->step++;
        }
        break;
    case 3:
        o->timer = 0x78;
        o->step++;
        o->unkAC = D_80138438[o->subtype];
        o->anim = D_801394A8[o->unkAC];
        SetBox_2A914(o);
        break;
    case 4:
        func_80126558(o);
        if (--o->timer == -1) {
            if (o->subtype) {
                r = ((s32 (*)(GameObject *))func_80126A64)(o);
                if ((u8)r == 0xff) {
                    o->step = 2;
                    o->unkAC = D_80138430[o->subtype];
                    o->anim = D_801394A8[o->unkAC];
                    SetBox_2A914(o);
                } else {
                    o->step = r;
                    o->unk7 = 0;
                    o->subState++;
                }
            } else {
                o->timer = 0x78;
                o->step++;
                updateObjectSideFlag(o);
                *(char **)((char *)o + 0x28) = ((char *)&D_800771FC);
                *(s16 *)((char *)o + 0xac) = 0x2f;
                o->anim = D_80139564;
                SetBox_2A914(o);
            }
        }
        break;
    case 5:
        func_80126558(o);
        applyFrameVelocityXY(o);
        if (func_80126928(o))
            o->timer = 0;
        func_80126810(o);
        if (--o->timer == -1) {
            *(s16 *)((char *)o + 0x20) = 0x3c;
            *(s16 *)((char *)o + 0xac) = 0x30;
            o->step++;
            o->anim = D_80139568;
            SetBox_2A914(o);
        }
        break;
    case 6:
        func_80126558(o);
        if (--o->timer == -1) {
            if (InRange_2A914(o)) {
                o->step = 2;
                o->unkAC = D_80138430[o->subtype];
                o->anim = D_801394A8[o->unkAC];
                SetBox_2A914(o);
            } else {
                *(s16 *)((char *)o + 0xac) = 0x42;
                o->step++;
                o->anim = D_801395B0;
                SetBox_2A914(o);
            }
        }
        break;
    case 7:
        if (func_80126558(o)) {
            o->subState++;
            updateObjectSideFlag(o);
            o->step = 0;
            o->unk7 = 0;
            r = ((s32 (*)(GameObject *))func_80126A64)(o);
            if ((u8)r != 0xff)
                o->step = r;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012ADD8);
extern u16 *D_80139520[];
extern u16 *D_8013951C[];
extern u16 *D_80139524[];

static __inline__ void SetBox_2ADD8(GameObject *o)
{
    u8 *p;
    p = &D_8013831C[((u16 *)o->anim)[1] * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p++;
    o->hitHeight = *p;
    o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
}

static __inline__ void Spawn_2ADD8(GameObject *o)
{
    GameObject *n = allocObjectLayer3();
    if (n) {
        n->active = 1;
        n->type = 0x10;
        n->subtype = 1;
        n->x.p.whole = o->x.p.whole;
        n->y.p.whole = o->y.p.whole + 0x10;
        n->z.p.whole = o->z.p.whole;
    }
}

#define FALL() \
    applyFrameVelocityX(o); \
    o->velV += 0x40; \
    if (o->velV > 0x500) \
        o->velV = 0x500; \
    o->y.raw += o->velV << 8;

void func_8012ADD8(GameObject *o)
{
    GameObject *p;
    u8 k;

    switch (o->step) {
    case 0:
        o->active = 5;
        o->movetab = ((char *)&D_800771FC);
        o->timer = 0;
        o->cooldownTimer = 0;
        o->touchFlag = 0;
        o->step++;
        k = D_80138430[o->subtype];
        o->unkAC = k;
        o->anim = D_801394A8[k];
        SetBox_2ADD8(o);
        break;
    case 1:
        func_80126558(o);
        p = (GameObject *)o->unk94;
        o->h->p.whole = (s16)(p->h->p.whole - 0xe) - (o->cooldownTimer << 1);
        o->y.p.whole = p->y.p.whole - 0x17;
        o->unk8C = -(p->unk8C >> 4) & 0xff;
        if (o->timer == 0) {
            if (o->unk8C != 0)
                o->timer = 1;
        } else if (o->unk8C == 0) {
            o->timer = 0;
            if (++o->cooldownTimer == 3)
                o->step++;
        }
        break;
    case 2:
        p = (GameObject *)o->unk94;
        o->h->p.whole = (s16)(p->h->p.whole - 0xe) - (o->cooldownTimer << 1);
        o->y.p.whole = p->y.p.whole - 0x17;
        o->unk8C = -(p->unk8C >> 4) & 0xff;
        if (o->unk8C >= 4) {
            o->velV = 0;
            o->step++;
        }
        break;
    case 3:
        FALL();
        o->unk8C += 5;
        if (o->unk8C >= 0x33) {
            o->unk9C = 2;
            o->unk8C = 0xc0;
            o->touchFlag = 0;
            o->unkAC = 0x1e;
            o->step++;
            o->anim = D_80139520[0];
            SetBox_2ADD8(o);
        }
        break;
    case 4:
        FALL();
        o->unk8C += 5;
        if (o->unk8C >= 0x100)
            o->unk8C = 0x100;
        if (o->touchFlag == 1 || (o->touchFlag & 8) || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            if (((D_1F800282 >> 5) & 0xf) == 0xf)
                o->unk98 = 0;
            if (!(o->touchFlag & 8))
                Spawn_2ADD8(o);
            o->active = 1;
            o->timer = 2;
            o->touchFlag = 0;
            o->unk9C = 0;
            o->unkAC = 0x1d;
            o->step++;
            o->anim = D_8013951C[0];
            SetBox_2ADD8(o);
        }
        break;
    case 5:
        if (--o->timer == -1) {
            o->unk9C = 1;
            o->velV = -0x300;
            o->timer = 0;
            o->touchFlag = 0;
            o->unk8C = 0;
            o->unkAC = 0x1e;
            o->step++;
            o->anim = D_80139520[0];
            SetBox_2ADD8(o);
        }
        break;
    case 6:
        FALL();
        if (o->velV > 0)
            o->unk9C = 2;
        if (o->touchFlag == 1 || (o->touchFlag & 8) || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            if (((D_1F800282 >> 5) & 0xf) == 0xf)
                o->unk98 = 0;
            if (!(o->touchFlag & 8))
                Spawn_2ADD8(o);
            o->timer = 2;
            o->touchFlag = 0;
            o->unk9C = 0;
            o->unkAC = 0x1d;
            o->step++;
            o->anim = D_8013951C[0];
            SetBox_2ADD8(o);
        }
        break;
    case 7:
        if (--o->timer == -1) {
            o->unk9C = 1;
            o->velV = -0x200;
            o->timer = 0;
            o->unk8C = 0;
            o->unkAC = 0x1e;
            o->step++;
            o->anim = D_80139520[0];
            SetBox_2ADD8(o);
        }
        break;
    case 8:
        FALL();
        if (o->velV > 0)
            o->unk9C = 2;
        if (o->timer == 0) {
            o->unk8C += 2;
            if (o->unk8C >= 0x16) {
                o->unk8C = 0xe0;
                o->timer = 1;
                o->unkAC = 0x1f;
                o->anim = D_80139524[0];
                SetBox_2ADD8(o);
            }
        } else {
            o->unk8C += 4;
            if (o->unk8C >= 0x100)
                o->unk8C = 0x100;
        }
        if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            if (((D_1F800282 >> 5) & 0xf) == 0xf)
                o->unk98 = 0;
            Spawn_2ADD8(o);
            o->timer = 0x14;
            o->touchFlag = 0;
            o->unk9C = 0;
            o->unk8C = 0;
            o->unkAC = 0x17;
            o->step++;
            o->anim = D_80139504[0];
            SetBox_2ADD8(o);
        }
        break;
    case 9:
        func_80126558(o);
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 1;
            o->unk7 = 2;
            o->touchFlag = 0;
            o->unk68 = 0;
        }
        break;
    }
}
#undef FALL

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012B60C);
extern u16 *D_80139568[];
extern u16 *D_801395B0[];
extern u16 *D_8013959C[];
extern u16 *D_801394D4[];

static __inline__ void SetBox_2B60C(GameObject *o)
{
    u8 *p;
    p = &D_8013831C[((u16 *)o->anim)[1] * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p++;
    o->hitHeight = *p;
    o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
}

void func_8012B60C(GameObject *o)
{
    extern u16 *D_8013955C[];
    u16 *w = (u16 *)&o->unkB4;
    u16 dx, dz;
    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->touchFlag = 0;
        o->unkAC = 0x2d;
        o->step++;
        o->anim = D_8013955C[0];
        SetBox_2B60C(o);
        break;
    case 1:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (func_80126810(o)) {
            o->unk8C = w[1];
            o->timer = 0;
            o->step++;
        }
        break;
    case 2:
        func_80126558(o);
        dx = o->h->p.whole - (*(u16 *)&D_1F80016A) + 0xa0;
        dz = o->d->p.whole - (*(u16 *)&D_1F800172) + 0x2d;
        if (dx > 0x140) {
            o->timer = 0;
            break;
        }
        if (o->timer++ < 0x3c) break;
        if (dz < 0x5a) {
            o->step = 3;
        } else {
            o->step = 5;
        }
        break;
    case 3:
        o->timer = 0xb4;
        o->unkAC = 0x30;
        o->step++;
        o->anim = D_80139568[0];
        SetBox_2B60C(o);
        break;
    case 4:
        func_80126558(o);
        if (--o->timer == -1) {
            o->step = 8;
            o->unkAC = 0x42;
            o->anim = D_801395B0[0];
            SetBox_2B60C(o);
        }
        break;
    case 5:
        o->unkAC = 0x3d;
        o->step++;
        o->anim = D_8013959C[0];
        SetBox_2B60C(o);
        break;
    case 6:
        if (func_80126558(o)) {
            o->timer = 0xb4;
            o->unkAC = 0xb;
            o->step++;
            o->anim = D_801394D4[0];
            SetBox_2B60C(o);
        }
        break;
    case 7:
        func_80126558(o);
        if (--o->timer == -1) goto next;
        break;
    case 8:
        if (func_80126558(o)) {
        next:
            o->subState++;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012B8DC);
extern void *D_8013956C[];

#define SETBOX(o) \
    { \
        u8 *b = D_8013831C + ((u16 *)o->anim)[1] * 4; \
        o->hitOffsetX = *b++; \
        o->hitWidth = *b++; \
        o->hitOffsetY = b[0]; \
        o->hitHeight = b[1]; \
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff; \
    }

#define FOLLOW(o, p) \
    p = (GameObject *)o->unk94; \
    o->h->p.whole = p->h->p.whole; \
    o->y.p.whole = p->y.p.whole - 30; \
    o->unk8C = -(p->unk8C >> 4) & 0xff;

void func_8012B8DC(GameObject *o)
{
    GameObject *p;
    char k;

    switch (o->step) {
    case 0:
        o->movetab = ((char *)&D_800771FC);
        o->timer = 0;
        o->cooldownTimer = 0;
        o->touchFlag = 0;
        o->step++;
        o->unkAC = D_80138430[o->subtype];
        o->anim = D_801394A8[o->unkAC];
        SETBOX(o);
        break;
    case 1:
        func_80126558(o);
        FOLLOW(o, p);
        if ((u16)(o->d->p.whole - *(u16 *)0x1F800172 + 45) >= 91
            || (u16)(o->h->p.whole - *(u16 *)0x1F80016A + 64) >= 129
            || (u16)(o->y.p.whole - *(u16 *)0x1F80016E + 32) >= 65) {
            o->timer = 0;
        } else if (o->timer++ > 0x78) {
            o->step++;
        }
        break;
    case 2:
        FOLLOW(o, p);
        o->step++;
        o->timer = 0xb4;
        o->unkAC = 0x31;
        o->anim = D_8013956C[0];
        SETBOX(o);
        break;
    case 3:
        FOLLOW(o, p);
        func_80126558(o);
        k = 0x42;
        if (--o->timer == -1) {
            o->unkAC = k;
            o->step++;
            o->anim = D_801395B0[0];
            SETBOX(o);
        }
        break;
    case 4:
        FOLLOW(o, p);
        if (func_80126558(o)) {
            o->step = 0;
            o->subState++;
        }
        break;
    }
}
#undef SETBOX
#undef FOLLOW

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012BC30);
extern u16 *D_80139508[];
extern u16 *D_8013950C[];

static __inline__ void SetBox_2BC30(GameObject *o)
{
    u8 *p;
    p = &D_8013831C[((u16 *)o->anim)[1] * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p++;
    o->hitHeight = *p;
    o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
}

void func_8012BC30(GameObject *o)
{
    u8 *p;
    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->velV = -0x200;
        o->touchFlag = 0;
        o->unkAC = 0x18;
        o->step++;
        o->anim = D_80139508[0];
        SetBox_2BC30(o);
        break;
    case 1:
        func_80126558(o);
        o->velV += 0x30;
        o->y.raw += o->velV << 8;
        if (o->velV > 0)
            o->step++;
        break;
    case 2:
        func_80126558(o);
        o->velV += 0x30;
        if (o->velV > 0x800)
            o->velV = 0x800;
        o->y.raw += o->velV << 8;
        if (func_80126810(o))
            o->step++;
        break;
    case 3:
        o->active = 1;
        o->timer = 0x3c;
        o->unkAC = 0x19;
        o->step++;
        o->anim = D_8013950C[0];
        SetBox_2BC30(o);
        break;
    case 4:
        func_80126558(o);
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 1;
            o->unk7 = 2;
            o->touchFlag = 0;
            o->unk68 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012BE28);
extern u8 D_80138430[];
extern u16 *D_801394A8[];
extern void applyFrameVelocityY(GameObject *);

void func_8012BE28(GameObject *o)
{
    u8 *p;
    u16 k;
    s32 dx;
    switch (o->step) {
    case 0:
        o->movetab = D_80077214;
        o->step++;
        o->touchFlag = 0;
        k = D_80138430[o->subtype];
        o->unkAC = k;
        o->anim = D_801394A8[k];
        p = &D_8013831C[((u16 *)o->anim)[1] * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 1:
        func_80126558(o);
        applyFrameVelocityY(o);
        if (func_80126810(o) != 0) {
            o->timer = 0;
            o->step++;
        }
        break;
    case 2:
        func_80126558(o);
        dx = (u16)o->h->p.whole - (*(u16 *)&D_1F80016A) + 0x60;
        if ((u16)(o->d->p.whole - (*(u16 *)&D_1F800172) + 0x2d) >= 0x5b || (u16)dx >= 0xc1) {
            o->timer = 0;
        } else if (o->timer++ >= 0x46) {
            o->timer = 10;
            o->step++;
        }
        break;
    case 3:
        func_80126558(o);
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 1;
            o->unk7 = 2;
            o->touchFlag = 0;
            o->unk68 = 0;
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012C03C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012C5D8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012C75C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012CB40);
extern u16 *D_8013955C;

void func_8012CB40(GameObject *o)
{
    u8 *p;
    GameObject *q;
    switch (o->step) {
    case 0:
        *(void **)((u8 *)o + 0x28) = ((char *)&D_800771FC);
        *(u8 *)((u8 *)o + 0x69) = 0;
        *(s16 *)((u8 *)o + 0xac) = 0x2d;
        *(u8 *)((u8 *)o + 6) = *(u8 *)((u8 *)o + 6) + 1;
        o->anim = D_8013955C;
        p = D_8013831C + D_8013955C[1] * 4;
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 1:
        func_80126558(o);
        q = (GameObject *)o->unk94;
        o->h->p.whole = q->h->p.whole;
        o->y.p.whole = q->y.p.whole - 0x17;
        o->unk8C = (-(q->unk8C >> 4)) & 0xff;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012CC5C);
extern u16 *D_80139590[];
extern u8 D_8013831C[];
void func_8012CC5C(GameObject *o)
{
    u8 *q;
    u16 *a;
    switch (o->step) {
    case 0:
        o->touchFlag = 1;
        o->movetab = ((char *)&D_800771FC);
        o->unkAC = 0x3a;
        o->step++;
        o->anim = a = D_80139590[0];
        q = D_8013831C + a[1] * 4;
        o->hitOffsetX = *q++;
        o->hitWidth = *q++;
        o->hitOffsetY = *q;
        o->hitHeight = q[1];
        o->animTimer = ((u16 *)o->anim)[3] & 0x3fff;
        break;
    case 1:
        func_80126558(o);
        func_80126810(o);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012CD40);
extern void *D_8013A5B4;
extern u8 D_80138468[];
extern void applyFrameVelocityXY(GameObject *);

void func_8012CD40(GameObject *o)
{
    s16 t;
    switch (o->step) {
    case 0:
        o->movetab = ((char *)&D_800771FC);
        o->animFrame = nextRandom() & 1;
        o->anim = D_8013A5B4;
        readAnimFrameCount(o);
        switch (D_80138468[nextRandom() & 0xf]) {
        case 0:
            o->timer = 60;
            o->unkAC = 0;
            o->step = 1;
            break;
        case 1:
            o->unkAC = 1;
            o->timer = 0x5a;
            o->step = 2;
            break;
        case 2:
            o->unkAC = 2;
            o->velY = -0x200;
            o->timer = 0;
            o->step = 4;
            break;
        }
        break;
    case 1:
        if (--o->timer == 0)
            o->step++;
        tickAnimation(o);
        break;
    case 2:
        o->anim = D_8013A5B4;
        readAnimFrameCount(o);
        o->timer = 0x60;
        o->step++;
    case 3:
        tickAnimation(o);
        applyFrameVelocityXY(o);
        if (o->velH + 8 < o->h->p.whole)
            o->h->p.whole = o->velH + 8;
        if (o->h->p.whole < o->velH - 8)
            o->h->p.whole = o->velH - 8;
        (t = o->y.p.whole + 0x10, ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, t - o->unkC * 16));
        if ((D_1F8001F8 & 0xf) == 0 && (nextRandom() & 3) == 0)
            playSFXWithNote(0x3a, 0);
        if (--o->timer == 0)
            o->step = 0;
        break;
    case 4:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0)
            o->step = 5;
        break;
    case 5:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if ((t = o->y.p.whole + 0x10, ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, t - o->unkC * 16)))
            o->step = 0;
        break;
    case 6:
        *(s8 *)&o->unkF = -7;
        tickAnimation(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D040);
void func_8012D040(GameObject *o)
{
    s16 v;
    u16 u;
    switch (o->step) {
    case 0:
        o->active = 2;
        o->movetab = ((char *)&D_800771FC);
        o->animFrame = nextRandom() & 1;
        o->unkAC = 0;
        o->anim = D_8013A5B4;
        if (o->unkC == 0) o->velY = -0x400;
        else o->velY = 0x80;
        v = o->h->p.whole;
        o->velV = o->y.p.whole;
        o->velH = v;
        readAnimFrameCount(o);
        o->step = 1;
        break;
    case 1:
        tickAnimation(o);
        o->y.raw += o->velY * 0x100;
        o->velY += 0x20;
        if (o->velY > 0) o->step = 2;
        break;
    case 2:
        tickAnimation(o);
        o->y.raw += o->velY * 0x100;
        v = o->y.p.whole + 0x10;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(v - o->unkC * 16)) != 0) {
            if (o->unk7A == 0) o->active = 1;
            o->subState = 1;
            o->step = 0;
            o->touchFlag = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D1D0);
extern void func_8012D040(GameObject *);
extern void func_8012CD40(GameObject *);

void func_8012D1D0(GameObject *o)
{
    switch (o->subState) {
    case 0:
        func_8012D040(o);
        break;
    case 1:
        func_8012CD40(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D220);
typedef struct {
    char p0[1]; u8 vis; char p1[2]; u8 st, step; char p2[4]; u8 b0a; char p3[2]; u8 b0d; char p4; u8 b0f;
    char p5[0x1e - 0x10]; u16 w1e; char p6[2]; s32 anim; char p7[0x3c - 0x28]; s32 d3c; char p8[0x68 - 0x40]; u8 b68, b69, p9, b6b;
    u16 w6c, w6e, w70, w72;
} O_2D220;
extern void func_8002367C(s32);
extern s32 func_80022F6C(O_2D220 *);
extern void addItemToInventory(s32, s32, s32);

void func_8012D220(O_2D220 *o)
{
    u8 c = o->st;
    switch (c) {
    case 0:
        o->w6c = 6;
        o->w6e = 0xc;
        o->w70 = 6;
        o->w72 = 0xc;
        o->w1e = 0xb;
        o->d3c = D_1F8002D4[0];
        o->b0a = 0;
        o->b0d = 0;
        o->b69 = 0;
        o->b68 = 0;
        o->anim = D_8013A5B4;
        *(s8 *)&o->b0f = -9;
        readAnimFrameCount(o);
        if (func_80022F6C(o))
            o->st = o->st + 1;
        break;
    case 1:
        func_80022E44(o);
        if (o->vis != 0) {
            switch (o->step) {
            case 0:
                func_8012D040(o);
                break;
            case 1:
                func_8012CD40(o);
                break;
            }
        }
        break;
    case 2:
        func_80022E44(o);
        if (o->vis != 0) {
            switch (o->step) {
            case 0:
                o->step = 1;
                break;
            case 1:
                tickAnimation(o);
                break;
            case 2:
                addItemToInventory(0, 1, 1);
                func_8002367C(o->b6b);
                o->st = 3;
                break;
            }
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D3FC);
extern GameObject *allocObjectLayer2(void);
extern u8 D_800A53A7[];
extern void *D_8013A5B4;

void func_8012D3FC(s32 x, s32 y, s32 z)
{
    GameObject *o = allocObjectLayer2();
    if (o != 0) {
        o->active = 2;
        o->hitOffsetX = 6;
        o->hitWidth = 12;
        o->hitOffsetY = 6;
        o->hitHeight = 12;
        o->type = 3;
        o->animFrame = nextRandom() & 1;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->tpage = 11;
        o->unkC = 1;
        o->unkD = 0;
        o->touchFlag = 0;
        o->unk7A = 1;
        o->unkF = D_800A53A7[0] - 1;
        o->spriteBank = (*(s32 *)&D_1F8002D4);
        o->anim = D_8013A5B4;
        o->unkA = 2;
        readAnimFrameCount(o);
        o->state = 1;
        o->subState = 0;
        o->step = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D504);
extern GameObject *allocObjectLayer1(void);
extern u8 D_8009C616_U8Arr[] asm("D_8009C616");
extern s32 D_800A53A8;
extern s32 DAT_800a604c;
extern s32 DAT_800a6050;

typedef struct { s32 a, b, c; } V3_2D504;

void func_8012D504(GameObject *o)
{
    GameObject *n;
    u8 d;

    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            *(s16 *)((u8 *)o + 0x6c) = 0x14;
            *(s16 *)((u8 *)o + 0x6e) = 0x28;
            *(s16 *)((u8 *)o + 0x70) = 0x18;
            *(s16 *)((u8 *)o + 0x72) = 0x30;
            o->spriteBank = (*(s32 *)&D_1F8002D4);
            o->subState++;
            o->tpage = 10;
            o->unkD = 0;
            o->unkA = 0;
            o->touchFlag = 0;
            o->unk68 = 0;
            o->unkF = 0;
            if ((D_8009C616_U8Arr[0] >> o->subtype) & 1) {
                n = allocObjectLayer2();
                if (n != 0) {
                    n->active = 1;
                    n->type = 3;
                    n->subtype = o->subtype;
                    n->unkC = o->unkC;
                    *(V3_2D504 *)&n->x = *(V3_2D504 *)&o->x;
                    n->objectIndex = o->objectIndex;
                    d = o->unk1D;
                    n->unk7A = 0;
                    n->unk1D = d;
                }
                o->state = 3;
            }
            break;
        case 1:
            if (func_80022F6C(o)) {
                o->subState = 0;
                o->step = 0;
                o->unk7 = 0;
                o->state++;
            }
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->visible) {
            if (o->subState == 0) {
                if (o->step == 0) {
                    o->touchFlag = 0;
                    o->anim = D_8013A44C;
                    readAnimFrameCount(o);
                    o->step++;
                }
            }
        }
        break;
    case 2:
        func_80022E44(o);
        if (o->visible) {
            switch (o->subState) {
            case 0:
                o->anim = D_8013A44C;
                readAnimFrameCount(o);
                o->subState = 1;
                break;
            case 1:
                break;
            case 2:
                n = allocObjectLayer1();
                if (n != 0) {
                    n->active = 1;
                    n->type = 2;
                    n->animFrame = (o->animFrame & 1) | 2;
                    *(V3_2D504 *)&n->x = *(V3_2D504 *)&D_800A53A8;
                    n->subtype = o->subtype;
                    n->unkC = o->unkC;
                    n->objectIndex = o->objectIndex;
                    n->unk1D = o->unk1D;
                }
                o->state = 3;
                break;
            }
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012D808);
typedef struct { GameObject t; char pad[0xec - 0xc0]; } E_2D808;
extern void func_80119D80(s32, s32, s32);
extern void spawnLayer3Object(s32, s32, s32, s32);

static __inline__ s32 Hit_2D808(GameObject *o, GameObject *p)
{
    if (o->subtype && (u16)(p->z.p.whole - o->z.p.whole + 0x2d) >= 0x5b)
        return 0;
    if ((u16)(p->x.p.whole - o->x.p.whole + (p->hitOffsetX + o->hitOffsetX)) > p->hitWidth + o->hitWidth)
        return 0;
    if ((u16)(p->y.p.whole - o->y.p.whole + (o->hitOffsetY + p->hitOffsetY)) > o->hitHeight + p->hitHeight)
        return 0;
    o->unk68 = 1;
    return 1;
}

static __inline__ void Act_2D808(GameObject *o)
{
    playSFXWithNote(0x39, 10);
    if (o->subtype == 0) {
        spawnLayer3Object(0x16, 0x154, -0xbe, 0);
        spawnLayer3Object(0x16, 0x17c, -0xbe, 0);
    } else {
        spawnLayer3Object(0x16, 0x352, -0x96, 0x5a);
    }
    o->timer = 0x78;
    o->subState++;
}

void func_8012D808(GameObject *o)
{
    GameObject *pl;
    E_2D808 *e;
    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x19;
        o->hitWidth = 0x32;
        o->hitOffsetY = 0x19;
        o->hitHeight = 0x32;
        o->state++;
        break;
    case 1:
        pl = &PLAYER;
        switch (o->subState) {
        case 0:
            if (func_80022F6C(o) == 0)
                break;
            if ((D_1F8001F8 + D_1F800198) & 1) {
                if (Hit_2D808(o, pl)) {
                    func_80119D80(pl->x.p.whole, (s16)(pl->y.p.whole - 0x10), pl->z.p.whole);
                    Act_2D808(o);
                }
            } else {
                e = ((E_2D808 *)&D_800B07D8);
                for (D_1F80019C = 0; D_1F80019C < 4; D_1F80019C++, e++) {
                    if (e->t.active == 1 && Hit_2D808(o, &e->t)) {
                        func_80119D80(e->t.x.p.whole, e->t.y.p.whole, e->t.z.p.whole);
                        Act_2D808(o);
                        break;
                    }
                }
            }
            break;
        case 1:
            if (--o->timer == -1)
                o->subState = 0;
            break;
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

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_5", func_8012DC08);
extern void *D_80138498[][3];
extern u16 *D_80138528[];
extern s16 D_80138478[];
extern s16 D_80138480[][3];
extern void spawnItemDropAtPos(s32, s32, s16 *, s32, s32);
extern void advanceAnimFrame(GameObject *, s32);
extern void func_801188D4(GameObject *, s16, s16, s16);

#define BOX(o) { b = D_80138528[(o)->subtype] + *(u16 *)&((o)->unkB4) * 4; \
    (o)->hitOffsetX = *b++; (o)->hitOffsetY = *b++; (o)->hitWidth = *b; (o)->hitHeight = b[1]; }

void func_8012DC08(GameObject *o)
{
    s16 sv[6];
    u16 *b;
    GameObject *q;
    s32 s;

    switch (o->state) {
    case 0:
        o->tpage = 10;
        o->unkD = 0;
        *(u16 *)&(o->unkB4) = 0;
        *(u16 *)&(o->unkB6) = 0;
        *(u16 *)&(o->unkB8) = 0;
        o->anim = D_80138498[o->subtype][*(u16 *)&(o->unkB4)];
        o->spriteBank = D_1F8002D4[0];
        o->animFrame = 1;
        o->unkA = 0;
        *(s8 *)&o->unkF = -12;
        switch (o->subtype) {
        case 0:
        case 2:
        case 3:
            BOX(o);
            break;
        case 1:
            o->active = 2;
            o->hitOffsetX = 0;
            o->hitWidth = 0;
            o->hitOffsetY = 0;
            o->hitHeight = 0;
            break;
        }
        o->timer = 0;
        o->state++;
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) == 0)
            break;
        if (o->unk68) {
            if (o->unk68 == 1) {
                (*(u16 *)&(o->unkB4))++;
                if (*(u16 *)&(o->unkB4) >= D_80138478[o->subtype])
                    o->unkA = 0xff;
                q = (GameObject *)o->unk94;
                if (q != 0 && *(u16 *)&(o->unkB4) - *(u16 *)&(q->unkB4) >= 2)
                    q->unk68 = 1;
                if (o->subtype == 0 && *(u16 *)&(o->unkB4) == 2) {
                    sv[1] = o->h->p.whole - 0x28;
                    sv[3] = o->y.p.whole - 0x18;
                    sv[5] = 0;
                    spawnItemDropAtPos(0, 0, sv, -0x100, -0x100);
                }
                o->anim = D_80138498[o->subtype][*(u16 *)&(o->unkB4)];
                advanceAnimFrame(o, 0);
                BOX(o);
                *(u16 *)&(o->unkB6) = (nextRandom() & 1) + 3;
                *(u16 *)&(o->unkB8) = (nextRandom() & 7) + 5;
                o->timer = 0x1e;
            }
            o->unk68 = 0;
        }
        if (*(u16 *)&(o->unkB8) != 0) {
            if (--*(u16 *)&(o->unkB6) == 0) {
                s = (nextRandom() & 0x1f) + D_80138480[o->subtype][*(u16 *)&(o->unkB4)];
                func_801188D4(o, o->x.p.whole - s, o->y.p.whole - (nextRandom() & 0x3f), o->z.p.whole);
                if ((*(u16 *)&(o->unkB8) & 3) == 0)
                    playSFX(0x33);
                *(u16 *)&(o->unkB6) = (nextRandom() & 1) + 1;
                (*(u16 *)&(o->unkB8))--;
            }
        }
        if (o->timer != 0) {
            if (--o->timer == 0) {
                if (*(u16 *)&(o->unkB4) >= D_80138478[o->subtype]) {
                    func_8002367C(o->objectIndex);
                    o->state++;
                } else {
                    o->active = 1;
                }
            }
        }
        tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef BOX
