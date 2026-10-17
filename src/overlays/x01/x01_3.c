#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80120708);


typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7, b8;
    char p9[0x20 - 9];
    s16 w20;
    char p22[0x2c - 0x22];
    u16 w2c;
    u16 w2e;
} P_20708;

extern P_20708 *D_8009B698;
extern GameObject *D_8009C650;
extern GameObject *allocObjectLayer1(void);
extern void func_8010DE48(GameObject *);
extern void func_80104118(GameObject *);
extern void func_801041F0(GameObject *);
extern void func_800ED9E0(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s16 func_80045310(GameObject *, s16, s16);
extern s16 probeSidesAndApplyTileResponse(GameObject *, s32, s32);
extern void readAnimFrameCount(GameObject *);
extern void func_800EDEBC(GameObject *, s32);
extern void func_80104028(GameObject *);
extern void func_80103D54(GameObject *);

void func_80120708(GameObject *o)
{
    GameObject *n;
    GameObject *e;
    u16 f;

    switch (o->unk7) {
    case 0:
        D_8009C650->unk84 = o->unk88 - 0xc0;
        o->h->raw += ((s16*)&D_8009BC98.unk14)[0] << 8;
        o->y.raw += ((s16*)&D_8009BC98.unk16)[0] << 8;
        func_8010DE48(o);
        o->h->raw += o->velX << 8;
        func_80104118(o);
        func_801041F0(o);
        break;
    case 1:
        func_800EE7F0(o);
        e = D_8009C650;
        e->h->p.whole = o->h->p.whole;
        e->y.p.whole = o->y.p.whole + e->hitOffsetY;
        e->unk84 = o->unk88 - 0xc0;
        o->h->raw += ((s16*)&D_8009BC98.unk14)[0] << 8;
        o->y.raw += ((s16*)&D_8009BC98.unk16)[0] << 8;
        func_800ED9E0(o);
        tickAnimation(o);
        if (o->touchFlag == 0 && func_80045310(o, o->h->p.whole, o->y.p.whole + 0x30) == 0
            && (SCRATCHPAD.joypad_state & SCRATCHPAD.buttonAttack) == 0 && (SCRATCHPAD.joypad_state & SCRATCHPAD.buttonJump) == 0
            && probeSidesAndApplyTileResponse(o, 4, 0) == 0) break;
        if (*(volatile u16 *)&D_8009C968.w70 & 0x40) D_8009B698->w2c = 0xf;
        else D_8009B698->w2c = 0xe;
        o->unk9C = 0;
        o->velY = 0;
        o->unk7 = 2;
        break;
    case 2:
        if (D_8009B698->w2e != D_8009B698->w2c) {
            func_800EEF64(o);
            readAnimFrameCount(o);
            D_8009B698->w2e = D_8009B698->w2c;
        }
        if (tickAnimation(o)) {
            playSFXWithNote(0x22, 0x23);
            n = allocObjectLayer1();
            if (n) {
                n->active = 1;
                n->type = 1;
                n->subtype = 5;
                f = o->animFrame & 1;
                n->animFrame = f;
                if (*(volatile u16 *)&D_8009C968.w70 & 0x40) n->animFrame = f | 2;
                n->x.p.whole = o->x.p.whole;
                n->y.p.whole = o->y.p.whole;
                n->z.p.whole = o->z.p.whole;
                n->h->p.whole += (o->animFrame & 1) ? -0x10 : 0x10;
            }
            o->velY = 0;
            func_800EDEBC(o, 0x1d);
            o->unk8C = 0x200;
            o->unk7 = 3;
        } else {
            func_80104028(o);
        }
        break;
    case 3:
        D_8009C650->state = 2;
        D_8009C650->subState = 4;
        D_8009C650->step = 0;
        D_8009C650->unk7 = 0;
        o->unkB2 = 0x100;
        o->velY = 0;
        o->unk9C = 2;
        *(u8 *)&o->unkAC = 1;
        o->unk7 = 4;
        break;
    case 4:
        func_80103D54(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80120AC8);
typedef struct { GameObject o; u8 pc0[6]; u8 c6, c7; u8 pc8[0x1b]; u8 e3; } TX_20AC8;
#define X(o) ((TX_20AC8 *)(o))
extern void func_800EF40C(GameObject *);

static __inline__ s16 inc_20AC8(u8 x)
{
    if (x < 0xff) return x + 1;
    return x;
}

void func_80120AC8(GameObject *o)
{
    switch (o->step) {
    case 0:
        (*(GameObject **)&D_8009B698)->unkB = o->animFrame;
        if (o->animFrame &= 1) {
            if (o->unkB2 > 0) {
                o->unkB2 = -o->unkB2;
            }
        } else {
            if (o->unkB2 < 0) {
                o->unkB2 = -o->unkB2;
            }
        }
        *(u8 *)&o->unkAC = 0;
        o->unk9C = 0;
        o->objectIndex = 0;
        X(o)->c7 = 1;
        o->unk9D = 0;
        X(o)->c6 = 0;
        X(o)->e3 = 0;
        o->unk8C = 0;
        o->velX = 0;
        o->velY = 0x100;
        (*(GameObject **)&D_8009B698)->active = 0;
        o->unkA4 = 1;
        if ((o->unkBE & 1) != o->animFrame) {
            func_800EDEBC(o, 8);
        } else {
            func_800EDEBC(o, 0x11);
        }
        o->step++;
    case 1:
        o->objectIndex = inc_20AC8(o->objectIndex);
        tickAnimation(o);
        func_800EDD9C(o);
        o->y.raw += o->velY << 8;
        o->velY += 8;
        switch ((*(GameObject **)&D_8009B698)->animTimer) {
        case 8:
            o->unk8C = (o->animFrame & 1) ? 0x20 : 0xe0;
            break;
        case 0x11:
            o->unk8C = (o->animFrame & 1) ? 0x100 - (o->objectIndex >> 2) : o->objectIndex >> 2;
            break;
        }
        if (o->unkBE == 0) {
            if (o->animFrame != (o->unkBE & 1)) {
                o->unkB2 = 0;
            }
            o->unkA4 = 0;
            if ((*(GameObject **)&D_8009B698)->active == 0) {
                *(u8 *)&o->unkAC = 1;
                func_800ED788(o);
                o->subState = 2;
            } else {
                func_800ED788(o);
                o->subState = 4;
            }
            o->step = 3;
        }
        if (o->unkBE & 2) {
            o->subState = 0x13;
            o->step = 0;
        }
        func_800EF40C(o);
        break;
    }
}
#undef X

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80120D48);


typedef struct { GameObject o; char pc0[6]; u8 bc6; } PL_20D48;
extern u32 D_8009BCEC[];
extern void playSFX(s32);
extern void func_800EA16C(s32, s32, s32, s32);

void func_80120D48(PL_20D48 *o)
{
    if ((*(GameObject **)&D_8009B698)->active == 0 && o->bc6 == 0) {
        func_800EEDE0(o);
        o->o.unk9D = 0;
        if (o->o.unkBE & 0x20) {
            o->o.subState = 0x1f;
            o->o.step = 1;
        } else {
            o->o.subState = 0;
            o->o.step = 0;
        }
    }
    if (SCRATCHPAD.joypad_state & SCRATCHPAD.buttonJump) {
        D_8009C608.playerEquips = 0;
        playSFX(0x3e);
        func_800EA16C(o->o.h->p.whole, o->o.y.p.whole, o->o.d->p.whole, 0);
        func_800EA16C(o->o.h->p.whole, o->o.y.p.whole, o->o.d->p.whole, 0);
        o->o.unk9C = 1;
        o->o.state = 1;
        o->o.y.p.whole -= 8;
        if ((D_8009BCEC[0] & 0x40) && (PAD_PRESSED[0] & SCRATCHPAD.unk3C4)) o->o.unkA7 = 1;
        o->o.subState = 2;
        o->o.step = 0;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80120E90);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80120ECC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801210A4);


extern s32 func_80045780(s16, s16, s16);

void func_801210A4(GameObject *o)
{
    s16 y, z;
    s16 x;
    s16 w;

    switch (o->step) {
    case 0:
        (*(u8*)&o->unkA0) = 0;
        func_800EDEBC(o, 0x1b);
        o->unkB6 = 0;
        (*(s16*)&(*(GameObject **)&D_8009B698)->type) = 0;
        (*(u8*)((char*)&o->unkA0 + 2)) = 3;
        o->unkB0 = 0;
        o->unkB2 = 0;
        o->velH = 0;
        o->velV = 0;
        o->unk8C = 0;
        (*(u8*)&o->unkAA) = 1;
        o->timer = 0xf;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        o->step++;
    case 1:
        tickAnimation(o);
        if (--o->timer == 0) {
            o->timer = 8;
            func_800EDEBC(o, 0x17);
            o->step++;
        }
        break;
    case 2:
        if (!clampToCeilingAndProbeSides(o)) o->y.p.whole--;
        tickAnimation(o);
        if (!(SCRATCHPAD.unk1F8 & 0xf)) playSFXWithNote(0x1d, 0);
        y = o->y.p.whole - 8;
        w = o->h->p.whole + 8;
        z = o->d->p.whole;
        if ((func_80045780(o->h->p.whole - 8, y, z) & 2) || (func_80045780(w, y, z) & 2)) {
            o->state = 1;
            o->subState = 0x16;
            o->step = 0;
        }
        break;
    case 3:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 0x10;
        y = o->y.p.whole - 8;
        x = o->h->p.whole;
        w = x + 8;
        z = (s16)(o->d->p.whole / 90) * 90;
        if ((func_80045780(x - 8, y, z) & 2) || (func_80045780(w, y, z) & 2)) {
            ((u8*)&D_8009BC98.unk12)[0] = 0;
            o->state = 1;
            o->subState = 0x16;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012137C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121468);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012154C);
extern GameObject *D_8009E454_GameObjectPtr asm("D_8009E454");
extern s32 rsin(s32);
extern s32 rcos(s32);

void func_8012154C(GameObject *o)
{
    s32 a = (D_8009E454_GameObjectPtr->unk8C + 0x400) & 0xfff;
    s32 x = rcos(a) * o->unkBA >> 12;
    s32 y = rsin(a) * o->unkBA;
    o->h->p.whole = o->unkB8 + (D_8009E454_GameObjectPtr->h->p.whole + x) + D_8009E454_GameObjectPtr->unk30;
    o->y.p.whole = D_8009E454_GameObjectPtr->y.p.whole + (y >> 12);
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801215FC);

typedef struct L_215FC { u8 active; char p[0x94 - 1]; struct L_215FC *next; } L_215FC;

void func_801215FC(GameObject *o)
{
    L_215FC *q, *n;

    if (!(SCRATCHPAD.joypad_state & SCRATCHPAD.buttonJump)) return;
    D_8009C608.playerEquips = 0;
    ((u8 *)&o->unkA8)[1] = 0;
    if (D_8009C608.unk952 - 5 < 3) (*(L_215FC **)&D_8009E454)->active = 1;
    (*(GameObject **)&D_8009B698)->state = 0;
    o->unk9C = 1;
    o->timer = 10;
    o->velH = 0;
    o->velV = 0;
    o->velX = 0;
    o->velY = 0;
    n = (*(L_215FC **)&D_8009E454)->next;
    if (n != 0) {
        q = n;
        if (q->next == 0) {
            q->active = 1;
        } else {
        loop:
            q->active = 3;
            q = q->next;
            if (q->next != 0) goto loop;
            q->active = 1;
        }
    }
    o->h->p.whole += (o->animFrame & 1) ? 0x10 : -0x10;
    if ((D_8009BCEC[0] & 0x40) && (PAD_PRESSED[0] & SCRATCHPAD.unk3C4)) o->unkA7 = 1;
    o->subState = 2;
    o->step = 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121748);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121C00);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121CD4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121D5C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121F54);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80121FF4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80122258);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012228C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80122538);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80122B1C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80122E44);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80122E68);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123038);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123188);
extern GameObject *allocObjectLayer5(void);

void func_80123188(Fix16 *pos, u8 c, s16 vx)
{
    GameObject *o = allocObjectLayer5();

    if (o == 0) return;
    o->active = 1;
    o->type = 6;
    o->subtype = 0x13;
    o->unkC = 0x80;
    {
        u8 c2 = ((u8 **)&D_8007E6E4)[D_8007E61C[o->subtype]][3];
        o->animFrame = 0;
        o->objectIndex = c;
        o->unkF = c2;
    }
    o->h->raw = pos[0].p.whole << 16;
    o->y.raw = pos[1].p.whole << 16;
    o->d->raw = pos[2].p.whole << 16;
    o->velH = vx;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012325C);

extern void setEventStarted(s32, s32, s32);
extern void addItemToInventory(s32, s32, s32);

void func_8012325C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C068.event_16 == 0) {
            volatile s32 *g = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*g;
            s32 v;
            q += 9;
            v = *g + *q;
            o->unkA4 = 0;
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 8;
            o->hitHeight = 0x10;
            o->active = 1;
            o->touchFlag = 0;
            o->state++;
            o->unkA0 = v;
        } else {
            o->state = 3;
        }
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        if (D_8009C068.event_16 == 0) {
            setEventStarted(0x16, 0, 0);
            addItemToInventory(0xb, 1, 1);
        }
        o->state++;
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123390);
extern s16 boxesOverlap(GameObject *, GameObject *);

void func_80123390(GameObject *a, GameObject *b)
{
    b->touchFlag = 0;
    if (boxesOverlap(a, b)) {
        *(u8 *)&a->unkA0 = 0x35;
        b->touchFlag = 1;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801233E0);

typedef struct { GameObject o; char pad[0x24]; GameObject *e4; } TObjX_233E0;
extern s16 func_80051604(GameObject *, GameObject *);
extern void decreaseObjectTimer(GameObject *, s32);

void func_801233E0(GameObject *o, GameObject *e)
{
    s16 r;

    r = func_80051604(o, e);
    if (r == -1) return;
    switch (*(u8 *)&o->unkAC) {
    case 1:
        if (r < 3) {
            if (e->subtype == 8) {
                if ((*(s32 *)&e->state & 0xffffff) == 0x80301 && e->unk7 < 4) {
                    e->subState = 3;
                    e->step = 0;
                    goto common;
                }
                if (e->unkC == 0) (*(s16 *)e->unk94)--;
                e->subtype = 0;
                e->subState = 1;
                e->step = 0;
                e->touchFlag = 0;
                goto common;
            }
            e->subState = 1;
            e->step = 0;
            e->touchFlag = 0;
        common:
            e->active = 4;
            e->state = 2;
            e->animFrame = o->animFrame & 1;
            ((TObjX_233E0 *)o)->e4 = e;
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
        playSFX(7);
        func_800E92D4(0x1f4, e->x.p.whole, e->y.p.whole, e->z.p.whole);
        r = o->h->p.whole > e->h->p.whole;
        e->active = 2;
        e->state = 2;
        e->subState = 2;
        e->step = 0;
        e->touchFlag = 0;
        e->unk7A = r;
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801235F8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123680);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012370C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123748);
typedef struct {
    GameObject o;
    u8 pad[0x24];
    GameObject *e4;
} P_23748;
extern void func_800224FC(s32, s16, s16, s16);

void func_80123748(P_23748 *a, GameObject *b)
{
    s16 r = func_80051604(a, b);

    if (r != -1 && r < 3 && *(u8 *)&a->o.unkAC == 1) {
        b->active = 2;
        b->state = 2;
        b->subState = 0;
        b->step = 0;
        b->touchFlag = 0;
        a->e4 = b;
        *(u8 *)&a->o.unkAC = 2;
        func_800224FC(2, a->o.x.p.whole, a->o.y.p.whole, a->o.z.p.whole);
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801237D8);

static __inline__ s16 sabs_237D8(s16 x)
{
    s16 r;
    if (x < 0) r = -x; else r = x;
    asm("" ::: "$3");
    return r;
}

s32 func_801237D8(GameObject *a, GameObject *b, u8 mode, s32 ang)
{
    s16 dx, dy, cx, cy, ax, ay, s2, s7;
    s16 kind;
    s16 v;
    s16 u;
    s32 q, r, c1;

    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) >= 0x5b) return 0;
    dx = a->h->p.whole - b->h->p.whole;
    ax = b->hitOffsetX + dx;
    if ((u16)ax > b->hitWidth) return 0;
    dy = a->y.p.whole - b->y.p.whole;
    ay = b->hitOffsetX + dy;
    if ((u16)ay > b->hitWidth) return 0;
    switch (mode) {
    case 1:
    case 2:
        q = (dy < 0) ? 0xc00 : 0;
        r = q;
        if (dx > 0) {
            if (q == 0) r = 0x400;
            else r = q - 0x400;
        }
        asm("" ::: "$5", "$6");
        if ((u32)(((ang - r) & 0xfff) - 0x500) > 0x900) return 1;
    case 0:
        do { c1 = rcos(ang); } while (0);
        cx = (u32)(c1 * b->hitOffsetX) >> 12;
        cy = (u32)(rsin(ang) * b->hitOffsetX) >> 12;
    }
    ax = cx;
    ay = cy;
    if (cx < 0) ax = -cx;
    if (ay < 0) ay = -ay;
    kind = ax < ay;
    if (ax == 0) kind = 3;
    else if (ay == 0) kind = 2;
    switch (kind) {
    case 0:
        if (ax < sabs_237D8(dx)) return 2;
        s2 = dx * cy / cx;
        break;
    case 1:
        if (ay < sabs_237D8(dy)) return 2;
        s7 = dy * cx / -cy;
        break;
    case 2:
        s2 = 0;
        break;
    case 3:
        s7 = 0;
        break;
    }
    if (!(kind & 1)) {
        if (a->y.p.whole < b->y.p.whole - s2) {
            if ((-(s2 + 4) + b->y.p.whole) > a->y.p.whole + a->hitOffsetY) return 3;
            if (SCRATCHPAD.unk1D2 != 0) {
                if (dx > 0) a->h->p.whole = b->h->p.whole + cx;
                else a->h->p.whole = b->h->p.whole - cx;
                return 3;
            }
            a->y.p.whole = (-(s2 + 4) + b->y.p.whole) - a->hitOffsetY;
            a->y.p.frac = 0;
            a->velY = 0;
            a->touchFlag = 1;
            if (a->unk9E != 0) return 3;
            b->velX = dx;
            b->touchFlag = 1;
            if ((u32)(ang - 0x401) < 0x400 || ang > 0xc00) {
                u = (u32)(~ang + 1 & 0x3ff) >> 6;
                if (u > 8) u = 8;
            } else {
                u = (u32)(ang & 0x3ff) >> 6;
                asm("" : "=r"(v));
                if (u > 8) u = 8;
                u = -u;
                asm("" :: "r"(v));
            }
            a->unkB0 = u;
        } else {
            if (a->state == 1 && a->subState < 2 && sabs_237D8(dy) < 8) {
                if ((-(s2 + -4) + b->y.p.whole) < a->y.p.whole - (a->hitHeight - a->hitOffsetY)) return 3;
                a->y.p.whole = (-(s2 + -4) + b->y.p.whole) + (a->hitHeight - a->hitOffsetY);
                if (dx < 0) a->h->p.whole -= s2;
                else a->h->p.whole += s2;
                return 3;
            }
            { s32 by = b->y.p.whole; if ((-(s2 + -4) + by) < a->y.p.whole - (a->hitHeight - a->hitOffsetY)) return 3; }
            if (SCRATCHPAD.unk1D2 != 0) {
                s16 d = a->y.p.whole - ((-(s2 + -4) + b->y.p.whole) + (a->hitHeight - a->hitOffsetY));
                if (dx > 0) {
                    s16 t;
                    t = b->h->p.whole + cx;
asm("" : "=r"(t) : "0"(t));
                    v = t - a->h->p.whole + 2;
                    if ((u16)v >= 8) a->h->p.whole += d;
                    else a->h->p.whole = t;
                } else {
                    s16 t;
                    t = b->h->p.whole - cx;
asm("" : "=r"(t) : "0"(t));
                    v = a->h->p.whole - t + 2;
                    if ((u16)v >= 8) a->h->p.whole -= d;
                    else a->h->p.whole = t;
                }
                return 3;
            }
            a->y.p.whole = (-(s2 + -4) + b->y.p.whole) + (a->hitHeight - a->hitOffsetY);
            if (a->velY < 0) a->velY = 0;
        }
    } else {
        s2 = 0x10;
        if (a->touchFlag != 0 && sabs_237D8(dx) < 10) s2 = 4;
        if (b->h->p.whole + s7 < a->h->p.whole) {
            if (b->h->p.whole + s2 + s7 < a->h->p.whole - (a->hitWidth - a->hitOffsetX)) return 3;
            a->h->p.whole = s7 + (b->h->p.whole + s2) + (a->hitWidth - a->hitOffsetX);
            if (a->velY > 0x300) a->velY = 0x300;
        } else {
            if (b->h->p.whole - s2 + s7 > a->h->p.whole + a->hitOffsetX) return 3;
            a->h->p.whole = s7 + (b->h->p.whole - s2) - a->hitOffsetX;
            if (a->velY > 0x300) a->velY = 0x300;
        }
    }
    ay = q;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123EE0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80123F58);
extern u16 *D_8013B9DC[];

s32 func_80123F58(GameObject *a, GameObject *b)
{
    s16 dx, off, n, k;
    s32 d;
    u16 t, s;
    u16 *p;

    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) > 0x5a) return 0;
    d = (u16)a->y.p.whole - (u16)b->y.p.whole;
    t = d + (b->hitOffsetY + a->hitOffsetY);
    if ((u16)t > a->hitHeight + b->hitHeight) return 0;
    n = -d;
    k = n - 0x18;
    p = D_8013B9DC[b->subtype];
    if (k < 0) k = 0;
    t = p[k >> 3];
    dx = a->h->p.whole - (b->h->p.whole + t);
    if ((u16)(dx + (b->hitOffsetX + a->hitOffsetX)) > b->hitWidth + a->hitWidth) return 0;
    if (dx < 0) {
        off = -(b->hitOffsetX + a->hitOffsetX);
    } else {
        off = (b->hitWidth - b->hitOffsetX) + (a->hitWidth - a->hitOffsetX);
    }
    s = b->hitOffsetY + a->hitOffsetY;
    if (s - n >= 9) {
        a->h->p.whole = b->h->p.whole + t + off;
        if (off < 0) a->unkA6 = 2; else a->unkA6 = 3;
        return 2;
    }
    if (a->unk9C & 1) {
        a->h->p.whole = b->h->p.whole + t + off;
        return 2;
    }
    a->y.p.whole = b->y.p.whole - s;
    a->y.p.frac = 0;
    a->touchFlag = 1;
    b->touchFlag = 1;
    if (off >= 0) {
        a->unkBE = 8;
        a->unkB0 = 2;
    } else {
        a->unkBE = 9;
        a->unkB0 = -2;
    }
    return 1;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012416C);

s32 func_8012416C(GameObject *o, GameObject *e)
{
    u16 dy0;
    s16 dx, dx2;
    s16 dy, r;
    s32 d;
    s16 v;

    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) > 0x5a) return 0;
    dx = o->h->p.whole - e->h->p.whole;
    if ((u16)(e->hitOffsetX + dx) > e->hitWidth) return 0;
    dy0 = o->y.p.whole - e->y.p.whole;
    if ((u16)(dy0 + (o->hitOffsetY + e->hitOffsetY)) > o->hitHeight + e->hitHeight) return 0;
    if ((s16)dy0 < 0x19) {
        dx2 = e->unk30 - e->h->p.whole;
        dy = e->unk34 - e->y.p.whole;
        if (dx <= 0) r = 0;
        else r = dx * dy / dx2;
        if (e->y.p.whole + r > o->y.p.whole + o->hitOffsetY) return 0;
        o->y.p.whole = e->y.p.whole + r - o->hitOffsetY;
        o->y.p.frac = 0;
        o->velY = 0;
        o->touchFlag = 1;
        if ((*(u8*)&o->unkAC) != 3) e->touchFlag = 1;
        d = e->unk8C;
        if (d > 0x800) {
            v = ((u32)(-d) & 0xfff) >> 6;
            if (v >= 9) v = 8;
        } else {
            v = (d >> 6) & 0xff;
            if (v >= 9) v = 8;
            v = -v;
        }
        o->unkB0 = v;
        return 1;
    }
    o->y.p.whole = e->y.p.whole + ((e->hitHeight - e->hitOffsetY) + (o->hitHeight - o->hitOffsetY));
    if (o->velY < 0) o->velY = 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012437C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801243AC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801243DC);

extern s16 func_80051A18(GameObject *, GameObject *);

void func_801243DC(GameObject *a, GameObject *b)
{
    s16 r;

    if (a->subState == 0x22) return;
    if (b->subtype == 7) r = func_80051A18(a, b);
    else r = func_80123F58(a, b);
    if (r == 1 && !SCRATCHPAD.unk1A4 && !(a->active & 2) && !(b->active & 2)) {
        a->active = 2;
        if (b->h->p.whole > a->h->p.whole) a->animFrame = 1;
        else a->animFrame = 0;
        a->state = 2;
        a->subState = 0;
        a->step = 0;
        decreaseObjectTimer(a, 1);
        SCRATCHPAD.unk19E = 0;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801244E8);
static __inline__ void coll_244E8(GameObject *a, GameObject *b)
{
    s16 s, dx, ax, w, off, d0, sy;
    s32 dy, d; u16 t;
    if ((u16)(a->d->p.whole - b->unk38 + 0x2d) > 0x5a) return;
    dx = a->h->p.whole - b->unk30;
    ax = dx;
    s = b->hitOffsetX + a->hitOffsetX;
    off = s;
    if ((u16)(dx + s) > b->hitWidth + a->hitWidth) return;
    d = (u16)a->y.p.whole - 0x10;
    d -= b->unk34;
    t = d + (b->hitOffsetY + a->hitOffsetY);
    dy = d;
    if ((u16)t > a->hitHeight + b->hitHeight) return;
    w = off;
    d0 = ax;
    if (dx < 0) {
        ax = -dx;
        off = -s;
    } else {
        off = (b->hitWidth - b->hitOffsetX) + (a->hitWidth - a->hitOffsetX);
        w = off;
    }
    if ((u16)(w - ax) < 4) {
        a->h->p.whole = b->unk30 + off;
        return;
    }
    sy = dy;
    if (sy <= 0) {
        if (a->unk9C & 1) return;
        a->y.p.whole = b->unk34 - (s16)((b->hitOffsetY + a->hitOffsetY) - 0x10);
        a->touchFlag = 1;
        a->y.p.frac = 0;
        if (d0 >= 0) {
            a->unkBE = 8;
            a->unkB0 = 2;
        } else {
            a->unkBE = 9;
            a->unkB0 = -2;
        }
        return;
    }
    a->y.p.whole = b->unk34 + (s16)((b->hitHeight - b->hitOffsetY) + (a->hitHeight - a->hitOffsetY) + 0x10);
    if (a->velY < 0) a->velY = 0;
}

void func_801244E8(GameObject *o, GameObject *e)
{
    if (o->active != 4 && e->subtype == 6) coll_244E8(o, e);
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801246C4);
void func_801246C4(GameObject *o, GameObject *p)
{
    p->touchFlag = 0;
    func_8012416C(o, p);
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801246E4);

extern u8 D_8013BAE8[];
static __inline__ s16 sabs_246E4(s16 x)
{
    s16 r = x;
    if (x < 0) r = -x;
    return r;
}

s32 func_801246E4(GameObject *a, GameObject *b, u8 k, s32 ang)
{
    s16 dx, dy, c, s, ac, as;
    s32 q, r;
    s16 kind;
    s32 d; register s32 d0 asm("$3");
    asm("" : "=r"(ang) : "0"(ang));

    if ((u16)(a->d->p.whole - b->d->p.whole + 0x2d) >= 0x5b) return 0;
    dx = a->h->p.whole - b->h->p.whole;
    ac = b->hitOffsetX + dx;
    if (b->hitWidth < (u16)ac) return 0;
    dy = a->y.p.whole - b->y.p.whole;
    as = b->hitOffsetX + dy;
    if (b->hitWidth < (u16)as) return 0;
    switch (k) {
    case 1:
    case 2:
        q = dy < 0 ? 0xc00 : 0;
        ac = q;
        if (dx > 0) {
            if (q == 0) ac = 0x400;
            else ac = q - 0x400;
        }
        if ((u32)(((s16)(ang - ac) & 0xfff) - 0x600) > 0x700) return 0;
    case 0:
        c = ((u32)(rcos(ang) * b->hitOffsetX)) >> 12;
        s = ((u32)(rsin(ang) * b->hitOffsetX)) >> 12;
        break;
    }
    ac = c;
    as = s;
    if (c < 0) ac = -c;
    if (s < 0) as = -s;
    kind = ac < as;
    if (ac == 0) kind = 3;
    else if (as == 0) kind = 2;
    switch (kind) {
    case 0:
        if (ac < sabs_246E4(dx)) return 0;
        as = (a->y.p.whole - (b->y.p.whole - dx * s / c)) + 6; as = a->hitOffsetY + as;
        if ((u16)as > a->hitHeight + 0xc) return 0;
        break;
    case 1:
        if (as < sabs_246E4(dy)) return 0;
        ac = (a->h->p.whole - (b->h->p.whole - dy * c / s)) + 6; ac = a->hitOffsetX + ac;
        if ((u16)ac > a->hitWidth + 0xc) return 0;
        break;
    case 2:
        as = (a->y.p.whole - b->y.p.whole) + 6; as = a->hitOffsetY + as;
        if ((u16)as > a->hitHeight + 0xc) return 0;
        break;
    case 3:
        ac = (a->h->p.whole - b->h->p.whole) + 6; ac = a->hitOffsetX + ac;
        if ((u16)ac > a->hitWidth + 0xc) return 0;
        break;
    }
    { register s32 t asm("$2") = ang >> 4; d0 = t & 0xff; }
    d = d0;
    if (k == 0) {
        if (kind & 1) {
            if (s > 0) {
                if (dy > 0) { register s32 t asm("$2") = d0 + 0x80; d = t & 0xff; }
            } else {
                if (dy < 0) { register s32 t asm("$2") = d0 + 0x80; d = t & 0xff; }
            }
        } else {
            if (c > 0) {
                if (dx < 0) { register s32 t asm("$2") = d0 + 0x80; d = t & 0xff; }
            } else {
                if (dx > 0) { register s32 t asm("$2") = d0 + 0x80; d = t & 0xff; }
            }
        }
    }
    if ((u8)(D_8013BAE8[a->animFrame & 7] - d) < 0x80) b->velH = 0x600;
    else b->velH = -0x600;
    r = resolveHitResultB(a, b);
    if (r) {
        if (r >= 4) {
            if (b->velH > 0) b->velH += 0x400;
            else b->velH -= 0x400;
        } else if (r >= 2) {
            if (b->velH > 0) b->velH += 0x200;
            else b->velH -= 0x200;
        }
        playSFX(5);
        func_800224FC(1, a->x.p.whole, a->y.p.whole, a->z.p.whole);
    }
    SCRATCHPAD.unk19E = 0;
    return 1;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124BA0);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124C1C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124C74);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124CCC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124E1C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80124EC0);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012523C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801252F4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012533C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125484);
typedef struct { char p0[2]; u16 s2; } H_25484;
typedef struct {
    char p00[0x16]; u16 s16;
    char p1b[0x40 - 0x18]; H_25484 *h40; H_25484 *h44;
    char p3[0x6c - 0x48]; u16 s6c; s16 s6e; u16 s70; s16 s72;
    char p6[0xac - 0x74]; u8 bac;
} TO_25484;
typedef struct {
    char p00[0x16]; u16 s16;
    char p1b[0x40 - 0x18]; H_25484 *h40; H_25484 *h44;
    u16 s48; s16 s4a; char p4c[2]; u16 s4e; s16 s50;
} TB_25484;

s32 func_80125484(TO_25484 *a, TB_25484 *b)
{
    s16 k, sw, dx, dy, sh, dxs, dys, ex, ey;

    k = a->h44->s2 - b->h44->s2 + 0x2d;
    if ((u16)k >= 0x5b) return -1;
    k = a->bac == 1;
    sw = k + (b->s48 + a->s6c);
    dx = a->h40->s2 - b->h40->s2;
    if ((u16)(dx + sw) > b->s4a + a->s6e + k * 2) return -1;
    dy = a->s16 - b->s16;
    sh = b->s4e + a->s70;
    if ((u16)(dy + sh) > a->s72 + b->s50) return -1;
    dxs = dx;
    if (dx < 0) {
        dx = -dx;
    } else {
        sw = k + ((b->s4a - b->s48) + (a->s6e - a->s6c));
    }
    ex = sw - dx;
    dys = dy;
    if (dy < 0) {
        dy = -dy;
    } else {
        sh = (a->s72 - a->s70) + (b->s50 - b->s4e);
    }
    ey = sh - dy;
    if (dys < 9) {
        if (ex >= ey) return 2;
        return dxs >= 0;
    }
    if (ex >= ey) return 3;
    return dxs >= 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125630);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012589C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125BB4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125DA8);


void func_80125DA8(u8 *a, u8 *b)
{
    u8 *c;

    if (U8(a, 0xac) == 2)
        return;
    if (boxesOverlap(a, b) == 0)
        return;
    if (D_1F8001A4 != 0)
        return;
    if (a[0] & 2)
        return;
    a[0] = 2;
    if (U8(a, 0xac) == 1)
        U8(a, 0xac) = 0;
    if (S16(a, 0x98) != 1) {
        c = &D_8009C068.unk56c;
        if (*c == 0) {
            setEventStarted(0xb1, 0, 1);
            *c = 1;
        }
    }
    if (S16(PTR(b, 0x40), 2) > S16(PTR(a, 0x40), 2))
        S16(a, 0x2e) = 1;
    else
        S16(a, 0x2e) = 0;
    a[4] = 2;
    a[5] = 0;
    a[6] = 0;
    U8(a, 0xd1) = 1;
    decreaseObjectTimer(a, 1);
    SCRATCHPAD.unk19E = 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125ED4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125EF4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80125FFC);
extern s16 func_80051284(u8 *, u8 *);

void func_80125FFC(u8 *a, u8 *b)
{
    b[0x6a] = 0;
    if (func_80051284(a, b) == 2 && a[0xc3] != 0) b[0x6a] = a[0xa6];
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80126064);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801261C4);

typedef struct {
    GameObject t;
    char pad[0xe8 - 0xc0];
    u16 e8;
    u16 ea;
} P_261C4;

void func_801261C4(P_261C4 *o, GameObject *e)
{
    if (e->subtype == 6
        && (u16)(o->t.d->p.whole - e->unk38 + 45) < 91
        && (u16)(e->hitOffsetX + (o->e8 - e->unk30)) <= e->hitWidth
        && (u16)(e->hitOffsetY + (o->ea - e->unk34)) <= e->hitHeight) {
        o->t.unk9E = 3;
        o->t.unkB8 = e->unk30 - e->h->p.whole;
        o->t.unkBA = e->unk34 - e->y.p.whole;
        o->t.velY = 0;
        e->touchFlag = 1;
        SCRATCHPAD.unk19E = 0;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012629C);

extern s16 func_80059514(GameObject *, GameObject *);

void func_8012629C(GameObject *o, GameObject *e)
{
    if (e->subtype && func_80059514(o, e)) {
        o->unk9E = 4;
        o->unkBA = 0;
        o->velY = 0;
        SCRATCHPAD.unk19E = 0;
        o->unkB8 = D_1F8003BC;
        e->unk68 = 1;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012631C);

void func_8012631C(GameObject *o, GameObject *e)
{
    if (e->subtype == 0 && func_80059514(o, e)) {
        o->unk9E = 4;
        o->unkBA = 0;
        o->velY = 0;
        SCRATCHPAD.unk19E = 0;
        o->unkB8 = (*(u16*)&SCRATCHPAD.unk3BC);
        e->unk6A = 1;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
        e->animFrame = (o->animFrame & 1) << 1;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801263AC);

typedef struct {
    GameObject t;
    char pad[0xe8 - 0xc0];
    u16 we8, wea;
} PL_263AC;

#define o (&p->t)
s32 func_801263AC(PL_263AC *p, GameObject *e, u8 t, s32 ang)
{
    u16 dx, dy;
    s16 cx;
    s16 cy;
    s16 m;
    s16 k;
    s16 fy;
    s16 fx;
    s32 base, b;
    s16 ax;
    s16 ay;
asm("" :: "r"(cx)); asm("" :: "r"(cx));

    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b) return 0;
asm("" : "=r"(e) : "0"(e));
    dx = p->we8 - e->h->p.whole;
    ax = e->hitOffsetX + dx;
    if ((u16)ax > e->hitWidth) return 0;
    dy = p->wea - e->y.p.whole;
    ay = e->hitOffsetX + dy;
    if ((u16)ay > e->hitWidth) return 0;
    switch (t) {
    case 1:
    case 2:
        base = (s16)dy < 0 ? 0xc00 : 0;
        ax = base;
        if ((s16)dx > 0) {
            if (base == 0) ax = 0x400;
            else ax = base - 0x400;
        }
        if ((u32)(((s16)(ang - ax) & 0xfff) - 0x500) >= 0x901) return 0;
    case 0:
        cx = (u32)(rcos(ang) * e->hitOffsetX) >> 12;
        cy = (u32)(rsin(ang) * e->hitOffsetX) >> 12;
        break;
    }
    ax = cx;
    ay = cy;
    if (ax < 0) ax = -ax;
    if (ay < 0) ay = -ay;
    k = ax < ay;
    if (ax == 0) k = 3;
    else if (ay == 0) k = 2;
    switch (k) {
    case 0:
        if ((s16)dx < 0) m = -dx; else m = dx;
        if (m > ax) return 2;
        fy = (s16)dx * (s16)cy / (s16)cx;
        break;
    case 1:
        if ((s16)dy < 0) m = -dy; else m = dy;
        if (m > ay) return 2;
        fx = (s16)dy * (s16)cx / -(s16)cy;
        break;
    case 2:
        if ((s16)dx < 0) m = -dx; else m = dx;
        if (m > ax) return 2;
        fy = 0;
        break;
    case 3:
        if ((s16)dy < 0) m = -dy; else m = dy;
        if (m > ay) return 2;
        fx = 0;
        break;
    }
    if ((k & 1) == 0) {
        ay = p->wea - (e->y.p.whole - fy) + 4;
        if ((u16)ay >= 9) return 0;
        m = ax - m;
        if ((u16)m >= 0x1d) return 0;
        switch (t) {
        case 0:
            if ((s16)dx < 0) {
                if (o->animFrame & 1) return 0;
            } else {
                if ((o->animFrame & 1) == 0) return 0;
            }
            break;
        case 1:
        case 2:
            if ((s16)cx >= 0) goto pos;
        neg:
            if (o->animFrame & 1) return 0;
            break;
        pos:
            if ((o->animFrame & 1) == 0) return 0;
            break;
        }
        o->unk9E = 9;
        if (t == 0 && (s16)dx <= 0) o->unkB8 = -cx;
        else o->unkB8 = cx;
asm("" :: "r"(dy));
        o->unkBA = -fy + 0x10;
        o->velY = 0;
        e->velX = dx;
        e->touchFlag = 1;
        SCRATCHPAD.unk19E = 0;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
        e->unk7A = t;
        return 1;
    } else {
        ax = (o->animFrame & 1) ? 8 : -8;
        if (o->h->p.whole + ax > e->h->p.whole + fx) {
            if (o->unk9E == 8) {
                ax = p->we8 - (e->h->p.whole + fx) + 0x13;
                if ((u16)ax >= 0x24) return 0;
                m = ay - m;
                if ((u16)m < 8) return 0;
            } else {
                ax = p->we8 - (e->h->p.whole + fx) + 0xb;
                if ((u16)ax >= 0x14) return 0;
                m = ay - m;
                if ((u16)m < 0x10) return 0;
            }
asm("" :: "r"(cx)); asm("" :: "r"(cx));
            o->unkBA = dy;
            o->unkB8 = fx + 8;
        } else {
            if (o->unk9E == 8) {
                ax = p->we8 - (e->h->p.whole + fx) + 0x10;
                if ((u16)ax >= 0x24) return 0;
            } else {
                ax = p->we8 - (e->h->p.whole + fx) + 8;
                if ((u16)ax >= 0x14) return 0;
            }
            m = ay - m;
            if ((u16)m < 8) return 0;
            o->unkBA = dy;
            o->unkB8 = fx - 8;
        }
        e->touchFlag = 1;
        if ((s16)dx > 0) dx += 10;
        else if ((s16)dx < 0) dx -= 10;
        e->velX = dx;
        e->unk7A = t;
        o->velY = 0;
        o->unk9E = 8;
        SCRATCHPAD.unk19E = 0;
        (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
        return 1;
    }
}
#undef o

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_801269B4);
s32 func_801269B4(GameObject *a, GameObject *b)
{
    if (b->subtype == 0) return func_801263AC(a, b, 0, b->unk8C);
    if (func_801263AC(a, b, b->subtype, b->unk8C)) return 1;
    return func_801263AC(a, b, 2, (b->unk8C + 0x400) & 0xfff);
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80126A38);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80126BC4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80126BF8);
extern s32 rcos(s32);
extern s32 rsin(s32);

static __inline__ s16 sabs_26BF8(s16 x)
{
    s16 r;
    if (x < 0) r = -x; else r = x;
    return r;
}

s32 func_80126BF8(GameObject *o, GameObject *e, u8 mode, s32 ang)
{
    s16 dx, dy, cy, ax, ay, s2, s7; s32 cx;
    s16 kind;
    u32 v;
    s32 q, r;
asm("" :: "r"(cx));

    if ((u16)(o->d->p.whole - e->d->p.whole + 0x2d) >= 0x5b) return 0;
    dx = o->h->p.whole - e->h->p.whole;
    ax = e->hitOffsetX + dx;
asm("" : "=r"(ax) : "0"(ax));
    if ((u16)ax > e->hitWidth) return 0;
    dy = o->y.p.whole - e->y.p.whole;
    ay = e->hitOffsetX + dy;
    if ((u16)ay > e->hitWidth) return 0;
    switch (mode) {
    case 1:
    case 2:
        q = (dy < 0) ? 0xc00 : 0;
        r = q;
        if (dx > 0) {
            if (q == 0) r = 0x400;
            else r = q - 0x400;
asm("" :: "r"(cx));
        }
        if ((u32)(((ang - r) & 0xfff) - 0x500) > 0x900) return 1;
    case 0:
        cx = (u32)(rcos(ang) * e->hitOffsetX) >> 12;
        cy = (u32)(rsin(ang) * e->hitOffsetX) >> 12;
    }
    ax = cx;
    ay = cy;
    if ((s16)cx < 0) ax = -cx;
    if (ay < 0) ay = -ay;
    kind = ax < ay;
    if (ax == 0) kind = 3;
    else if (ay == 0) kind = 2;
    switch (kind) {
    case 0:
        if (ax < sabs_26BF8(dx)) return 2;
        s2 = dx * cy / (s16)cx;
        break;
    case 1:
        if (ay < sabs_26BF8(dy)) return 2;
        s7 = dy * (s16)cx / -cy;
        break;
    case 2:
        s2 = 0;
        break;
    case 3:
        s7 = 0;
        break;
    }
    if (!(kind & 1)) {
        if (o->y.p.whole < e->y.p.whole - s2) {
            if (-(s2 + 4) + e->y.p.whole > o->y.p.whole + o->hitHeight - o->hitOffsetY) return 3;
            o->y.p.whole = (-(s2 + 4) + e->y.p.whole) - (o->hitHeight - o->hitOffsetY);
            o->touchFlag = 1;
            if (o->category != 2) return 2;
            if (o->unk9C) return;
            if (o->type == 0 && o->subState == 2) return;
            if ((u32)(ang - 0x401) < 0x3ff || ang >= 0xc01) v = (ang & 0x3ff) + 0xc00;
            else v = ang & 0x3ff;
            o->unk8C = v >> 4;
            return;
        } else {
            if (-(s2 + -4) + e->y.p.whole < o->y.p.whole - o->hitOffsetY) return 3;
            o->y.p.whole = o->hitOffsetY + (-(s2 + -4) + e->y.p.whole);
            if (o->category != 2) return 2;
            o->touchFlag = 4;
            if (o->unk9C == 1) {
                if (o->velV < 0) o->velV = 0;
                return;
            }
            if (o->unk9C) return;
            if (o->type == 0 && o->subState == 2) return;
            if ((u32)(ang - 0x401) < 0x3ff || ang >= 0xc01) v = (ang & 0x3ff) + 0xc00;
            else v = ang & 0x3ff;
            o->unk8C = ((v >> 4) + 0x80) & 0xff;
            return;
        }
    }
    if (o->category == 2 && o->type != 0) {
        Fix16 *oh = o->h;
        if (e->h->p.whole + s7 < oh->p.whole) {
            if (e->h->p.whole - -(s7 + 0xc) < oh->p.whole) return 3;
            oh->p.whole = e->h->p.whole - -(s7 + 0xc);
            o->unk9D = 3;
            if (ang < 0x800) o->unk8C = ((ang + 0x800) & 0xfff) >> 4;
            else o->unk8C = ang >> 4;
        } else {
            if (oh->p.whole < e->h->p.whole - -(s7 + -0xc)) return 3;
            oh->p.whole = e->h->p.whole - -(s7 + -0xc);
            o->unk9D = 2;
            if (ang >= 0x800) o->unk8C = ((ang + 0x800) & 0xfff) >> 4;
            else o->unk8C = ang >> 4;
        }
        return 3;
    }
    if (e->h->p.whole + s7 < o->h->p.whole) {
        if (e->h->p.whole - -(s7 + 0xc) < o->h->p.whole - o->hitOffsetX) return 3;
        o->h->p.whole = o->hitOffsetX + (e->h->p.whole - -(s7 + 0xc));
        o->unk9D = 3;
        if (o->category != 2) return 2;
        if (o->unk9C) return;
        if (o->type == 0 && o->subState == 2 && o->step != 2) return;
        if (ang < 0x800) o->unk8C = ((ang + 0x800) & 0xfff) >> 4;
        else o->unk8C = ang >> 4;
    } else {
        if (e->h->p.whole - -(s7 + -0xc) > o->h->p.whole + (o->hitWidth - o->hitOffsetX)) return 3;
        o->h->p.whole = (e->h->p.whole - -(s7 + -0xc)) - (o->hitWidth - o->hitOffsetX);
        o->unk9D = 2;
        if (o->category != 2) return 2;
        if (o->unk9C) return;
        if (o->type == 0 && o->subState == 2 && o->step != 2) return;
        if (ang >= 0x800) o->unk8C = ((ang + 0x800) & 0xfff) >> 4;
        else o->unk8C = ang >> 4;
    }
    ay = q;
asm("" : "=r"(cy) : "0"(cy));
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80127314);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012738C);
extern s16 func_80056284(GameObject *, GameObject *);
extern void playSFX(s32);

void func_8012738C(GameObject *o, GameObject *e)
{
    if (o->type == 0 && o->unkC == 1 && func_80056284(o, e)) {
        o->active = 2;
        o->state = 2;
        o->subState = 2;
        o->step = 0;
        e->active = 2;
        e->state = 2;
        e->subState = 0;
        e->step = 0;
        playSFX(7);
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80127414);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80127448);
extern u8 D_8013BB18[];
extern u8 D_8013BB28[];

static __inline__ s32 outside_27448(GameObject *o, s16 *c)
{
    if ((u16)(o->y.p.whole - c[1] + 0xc8) > 0x190) return 2;
    return (u16)(o->h->p.whole - c[0] + 0xf0) > 0x1e0;
}

void func_80127448(GameObject *o)
{
    s16 *c = &o->unkB4;
    s32 r = outside_27448(o, c);
    Fix16 *h;

    if (r) {
        o->cooldownTimer = 1;
        h = o->h;
        o->animFrame = h->p.whole > c[0];
        o->subState = 1;
        if (r == 2) {
            if (o->y.p.whole > c[1]) o->subState = 3;
            else if (c[4] == 1) o->subState = 3;
            else o->cooldownTimer = 2;
        }
    } else {
        o->cooldownTimer = 0;
        o->subState = 0;
        h = o->h;
        if ((u16)(D_1F80016A[0] - h->p.whole + 0xf0) < 0x1e1
            && (u16)((*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole + 0xa0) < 0x141) {
            if (o->unkA7) o->subState = D_8013BB18[nextRandom() & 0xf];
            else o->subState = D_8013BB28[nextRandom() & 0xf];
            if (o->subState == 0) o->subState++;
            o->animFrame = (s16)D_1F80016A[0] < o->h->p.whole;
        }
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_80127608);

extern u8 D_8013BAF0[];
extern u8 D_8013BB00[];
extern void *D_8013F028[];
extern void *D_8013F030[];
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

void func_80127608(GameObject *o)
{
    s16 t;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        o->unkB0 = 0;
        if (D_8013BAF0[nextRandom() & 0xf])
            o->timer = 0x180;
        else
            o->timer = 0xc0;
        o->movetab = D_80077208;
        o->unkAC = 0x10;
        o->step++;
        o->anim = D_8013F028[0];
        readAnimFrameCount(o);
    case 1:
        if (o->visible)
            o->step++;
        break;
    case 2:
        tickAnimation(o);
        if (o->unk8C != 0x40 && o->unk8C != 0xc0) {
            applyFrameVelocityY(o);
            if (o->touchFlag == 1) {
                o->unkAE = -1;
                o->unkB2 = 0;
                o->touchFlag = 0;
                o->unkBA = 1;
            } else if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
                o->touchFlag = 0;
                o->unkBA = 0;
                t = D_1F80027E;
                o->unkB2 = t;
                o->unkAE = D_1F800284;
                o->unk8C = -(t << 2) & 0xff;
            }
        }
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->step++;
            if (o->cooldownTimer)
                o->animFrame = o->h->p.whole > o->unkB4;
            else
                o->animFrame = SCRATCHPAD.unk168[0].p.whole < o->h->p.whole;
            o->unkAC = 0x12;
            o->anim = D_8013F030[0];
            readAnimFrameCount(o);
        }
        break;
    case 3:
        if (tickAnimation(o)) {
            o->step = 0;
            switch (o->unk98) {
            case 0:
            case 1:
                if (D_8013BAF0[nextRandom() & 0xf])
                    o->subState = 3;
                else
                    o->subState = 1;
                break;
            case 2:
                if (D_8013BB00[nextRandom() & 0xf])
                    o->subState = 1;
                else
                    o->subState = 3;
                break;
            case 3:
                if (D_8013BAF0[nextRandom() & 0xf])
                    o->subState = 1;
                else
                    o->subState = 3;
                break;
            }
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_3", func_8012791C);

typedef struct { s16 w0, w2, w4, w6, w8; } S_2791C;
extern u8 D_8013BB10[];
extern void *D_8013EFEC[];
extern s16 func_80043AB0(GameObject *, s16, s16, s32);

static __inline__ s16 chk_2791C(GameObject *o)
{
    S_2791C *q = (S_2791C *)&o->unkB4;
    s32 f;
    s16 d;

    if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1)) {
        o->unkBA = 1;
        return 1;
    }
    f = o->animFrame & 1;
    if ((u16)f) d = -0x10;
    else d = 0x10;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f)) {
        q->w6 = 0;
        return 1;
    }
    return 0;
}

static __inline__ s32 land_2791C(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->unkAE = -1;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkBA = 1;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        o->unkBA = 0;
        o->unkB2 = D_1F80027E;
        o->unkAE = D_1F800284;
        o->unk8C = (-D_1F80027E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_8012791C(GameObject *o)
{
    S_2791C *p = (S_2791C *)&o->unkB4;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        if (D_8013BB00[nextRandom() & 0xf])
            o->movetab = D_80077208;
        else
            o->movetab = D_80077214;
        if (D_8013BB10[nextRandom() & 7]) {
            o->timer = 300;
            o->unkA7 = 0;
        } else {
            o->timer = 200;
            o->unkA7 = 1;
        }
        o->unkAC = 1;
        o->anim = D_8013EFEC[0];
        readAnimFrameCount(o);
        o->step++;
        p->w8 = 0;
        break;
    case 1:
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->step++;
            break;
        }
        tickAnimation(o);
        if (o->visible && ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0xf) == 0)
            playSFX(0x5e);
        if (p->w6) {
            s32 t = o->unk8C;
            u16 a;
            s16 s = *(s16 *)o->movetab;
            a = t;
            if (o->animFrame) a = t + 0x80;
            a &= 0xff;
            o->h->raw += (D_8007DB88[a] * s) >> 4;
            o->y.raw += (D_8007D788[a] * s) >> 4;
            o->y.p.whole += 2;
            if (chk_2791C(o) && p->w6 == 0) {
                p->w8 = 0;
                o->subState = 2;
                o->step = 0;
                o->unkB0 = 0;
                break;
            }
        } else {
            o->unk9C = 1;
            applyFrameVelocityXY(o);
            if (chk_2791C(o)) {
                p->w8 = 0;
                o->subState = 2;
                o->step = 0;
                o->unkB0 = 0;
                break;
            }
        }
        if (!land_2791C(o)) {
            p->w8 = 0;
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 1;
        }
        break;
    case 2:
        func_80127448(o);
        o->step = 0;
        o->unkA7 = 0;
        break;
    }
}
