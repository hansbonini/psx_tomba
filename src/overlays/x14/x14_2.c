#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_801189F4);
extern void playSFX(s32);

static __inline__ s32 add_189F4(s32 a, s32 b)
{
    return a + b;
}

u8 func_801189F4(GameObject *o, s32 d)
{
    s32 t;
    s32 r;

    switch ((u8)d) {
    case 0:
        if (SCRATCHPAD.unk168[3].p.whole + 300 < o->h->p.whole) {
            t = 8;
            t -= d;
            t += nextRandom() & 3;
            d = t & 0xf;
            playSFX(7);
        }
        break;
    case 1:
    case 2:
    case 3:
        if (SCRATCHPAD.unk168[3].p.whole + 300 < o->h->p.whole) {
            t = 8;
            t -= d;
            r = (nextRandom() & 3) - 2;
            t += r;
            d = t & 0xf;
            playSFX(7);
        } else if (o->y.p.whole < SCRATCHPAD.unk168[7].p.whole - 200) {
            d = -d & 0xf;
            playSFX(7);
        }
        break;
    case 4:
        if (o->y.p.whole < SCRATCHPAD.unk168[7].p.whole - 200) {
            d = add_189F4(-d, nextRandom() & 1) & 0xf;
            playSFX(7);
        }
        break;
    case 5:
    case 6:
    case 7:
        if (SCRATCHPAD.unk168[3].p.whole + 20 > o->h->p.whole) {
            d = (8 - d) & 0xf;
            playSFX(7);
        } else if (o->y.p.whole < SCRATCHPAD.unk168[7].p.whole - 200) {
            d = -d & 0xf;
            playSFX(7);
        }
        break;
    case 8:
        if (SCRATCHPAD.unk168[3].p.whole + 20 > o->h->p.whole) {
            t = 8;
            t -= d;
            t += nextRandom() & 1;
            d = t & 0xf;
            playSFX(7);
        }
        break;
    case 9:
    case 10:
    case 11:
        if (SCRATCHPAD.unk168[3].p.whole + 20 > o->h->p.whole) {
            t = 8;
            t -= d;
            r = (nextRandom() & 3) - 2;
            t += r;
            d = t & 0xf;
            playSFX(7);
        } else if (SCRATCHPAD.unk168[7].p.whole - 40 < o->y.p.whole) {
            d = -d & 0xf;
            playSFX(7);
        }
        break;
    case 12:
        if (SCRATCHPAD.unk168[7].p.whole - 40 < o->y.p.whole) {
            d = add_189F4(-d, nextRandom() & 0x10) & 0xf;
            playSFX(7);
        }
        break;
    case 13:
    case 14:
    case 15:
        if (SCRATCHPAD.unk168[3].p.whole + 300 < o->h->p.whole) {
            d = (8 - d) & 0xf;
            playSFX(7);
        } else if (SCRATCHPAD.unk168[7].p.whole - 40 < o->y.p.whole) {
            d = -d & 0xf;
            playSFX(7);
        }
        break;
    }
    return d;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80118C64);
extern s32 angleFromDelta(s32, s32);

s32 func_80118C64(GameObject *o, GameObject *t)
{
    s32 dx, dy, a, b;

    dx = t->h->p.whole - o->h->p.whole;
    dy = t->y.p.whole - o->y.p.whole;
    if (SquareRoot0(dx * dx + dy * dy) < 0x11) return 1;
    a = angleFromDelta(dx, dy) & 0xff;
    o->unk38 = a;
    b = (a + 0x80) & 0xff;
    dy = (o->velH * D_8007D788[b]) >> 12;
    dx = (o->velH * D_8007DB88[b]) >> 12;
    t->h->raw += dx << 8;
    t->y.raw += dy << 8;
    o->velH -= 0x20;
    if (o->velH < 0x200) o->velH = 0x200;
    return 0;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80118D9C);
s32 func_80118D9C(GameObject *o, GameObject *p)
{
    u8 a;
    s32 dx, dy;

    if (p == 0)
        goto fail;
    if (p->unk6A == 0)
        return 0;
    a = 0x40;
    if ((p->animFrame & 2) == 0)
        a = ((p->animFrame & 1) == 0) << 7;
    if ((u8)(a - o->unk8C + 0x20) > 0x40)
        return 0;
    dx = p->h->p.whole - o->h->p.whole;
    dy = p->y.p.whole - o->y.p.whole;
    a = angleFromDelta(dx, dy);
    o->unkB0 = (u8)a;
    o->unk38 = a & 0xff;
    if ((u8)(a - o->unk8C + 0x20) > 0x40) {
    fail:
        return 0;
    }
    return SquareRoot0(dx * dx + dy * dy) < 0x29;
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80118EA8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80119404);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80119798);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_801197E8);
struct GSInventory_197E8 { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_197E8 { u8 weapon; u8 pants; };
typedef struct { s16 a, b; } P2_197E8;
extern P2_197E8 D_80124FD4[];

void func_801197E8(GameObject *o)
{
    char pad;

    switch (o->unk7) {
    case 0:
        switch (GAME.selectedSection) {
        case 1:
            o->unk74 = D_80124FD4[2].a;
            o->unk76 = D_80124FD4[2].b;
            break;
        case 5:
            o->unk74 = D_80124FD4[0].a;
            o->unk76 = D_80124FD4[0].b;
            break;
        case 7:
            o->unk74 = D_80124FD4[1].a;
            o->unk76 = D_80124FD4[1].b;
            break;
        }
        o->unk7++;
        break;
    case 1:
        o->y.p.whole++;
        if (o->y.p.whole > o->unk74) {
            o->y.p.whole = o->unk74;
            o->unk7++;
        }
        break;
    case 2:
        o->y.p.whole--;
        if (o->y.p.whole < o->unk76) {
            o->y.p.whole = o->unk76;
            o->unk7 = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011994C);

struct GSInventory_1994C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1994C { u8 weapon; u8 pants; };
extern s16 D_80124FC4[];
extern u16 D_80124FB4[];
extern s16 D_80124FE0;
extern s16 D_80124FE2;
extern void *D_80129320;
extern s32 D_1F8002DC[];
extern void readAnimFrameCount(GameObject *);
extern void freeObjectLayer4(GameObject *);

void func_8011994C(GameObject *o)
{
    GameObject *p;
    s32 v;
    s32 c, sn;
    s32 n;

    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        v = D_80124FC4[((u16*)&GAME.selectedSection)[0]];
        o->unkA = 9;
        o->tpage = 8;
        o->unk8C = v;
        o->unkA6 = 0;
        o->unkA5 = 0;
        o->unkA7 = 0;
        o->unk6A = 0;
        o->unkD = 1;
        o->unk38 = v;
        o->unk30 = o->unk8C;
        o->clut = (D_80124FB4[((u16*)&GAME.selectedSection)[0]] << 6) | 0xf;
        o->spriteBank = D_1F8002DC[0];
        o->anim = D_80129320;
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        if (D_8009BC98.unk08) break;
        switch (((u16*)&GAME.selectedSection)[0]) {
        case 0:
            p = (*(GameObject **)&D_8009BC98.unk24);
            if (!o->unk6A && p) {
                o->unk8C = ((0x1000 - p->unk8C) >> 4) & 0xff;
                o->h->p.whole = p->x.p.whole;
                o->y.p.whole = p->y.p.whole;
            }
            break;
        case 2:
            p = (*(GameObject **)&D_8009BC98.unk24);
            if (!o->unk6A && p) {
                {
                    s32 i = (o->unk30 + 1) & 0xff;
                    o->unk30 = i;
                    c = D_8007DB88[i];
                    sn = D_8007D788[i];
                }
                o->h->raw = p->h->raw + c * 0x700;
                o->y.raw = p->y.raw + sn * 0x700;
                o->unk8C = (o->unk30 + 0x80) & 0xff;
            }
            break;
        case 3:
            if (!o->unk6A) o->unk8C = (o->unk8C - 1) & 0xff;
            break;
        case 4:
            if (!o->unk6A) o->unk8C = (o->unk8C + 1) & 0xff;
            break;
        case 5:
            if (!o->unk6A) {
                o->unk8C = (o->unk8C + 1) & 0xff;
                func_801197E8(o);
            }
            break;
        case 6:
            if (!o->unk6A) {
                o->unk8C = (o->unk8C + 1) & 0xff;
                switch (o->unk7) {
                case 0:
                    *(s16 *)((char *)o + 0x74) = D_80124FE0;
                    o->unk76 = D_80124FE2;
                    o->unk7++;
                    break;
                case 1:
                    if (++o->x.p.whole > o->unk74) {
                        o->x.p.whole = o->unk74;
                        n = o->unk7 + 1;
                        goto set;
                    }
                    break;
                case 2:
                    if (--o->x.p.whole < o->unk76) {
                        n = 1;
                        o->x.p.whole = o->unk76;
                    set:
                        o->unk7 = n;
                    }
                    break;
                }
            }
            break;
        case 1:
        case 7:
            if (!o->unk6A) func_801197E8(o);
            break;
        default:
            return;
        }
        func_80118EA8(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80119D30);


extern void *D_8012933C;

static __inline__ void setup_19D30(GameObject *p)
{
    (*(GameObject **)&D_8009BC98.unk24) = p;
    p->spriteBank = SCRATCHPAD.sprData[3];
    p->anim = D_8012933C;
    readAnimFrameCount(p);
}

void func_80119D30(GameObject *o)
{
    s32 t = o->state;
    u8 s;
    s16 dx, dy;
    s32 d, a;

    switch (t) {
    case 0:
        o->active = 2;
        o->unkA = 2;
        o->tpage = 0x10;
        o->unkD = 0x80;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->timer = 0x14;
        o->state++;
        setup_19D30(o);
        break;
    case 1:
        func_80022E44(o);
        o->unk8C = (o->unk8C + 2) & 0xff;
        s = o->subState;
        switch (s) {
        case 0:
            if (--o->timer == -1) o->subState++;
            break;
        case 1:
            if (D_8009BC98.unk0A == 1) o->subState = s + 1;
            break;
        case 2:
            if (D_8009BC98.unk0F == 0) {
                dx = (*(Fix16 **)&PLAYER.obj.h)->p.whole - o->h->p.whole;
                dy = (*(u16*)&PLAYER.obj.y.p.whole) - o->y.p.whole;
                d = SquareRoot0(dx * dx + dy * dy);
                if (d >= 11) {
                    if (d > 0xa0) d = 0xa0;
                    d = 0xaa - d;
                    a = angleFromDelta(dx, dy) & 0xff;
                    o->unk38 = a;
                    d <<= 2;
                    ((s16*)&D_8009BC98.unk16)[0] = (d * D_8007D988[(a + 0x48) & 0xff]) >> 12;
                    ((s16*)&D_8009BC98.unk14)[0] = (d * D_8007DB88[(o->unk38 + 0x48) & 0xff]) >> 12;
                    break;
                }
            }
            ((s16*)&D_8009BC98.unk14)[0] = 0;
            ((s16*)&D_8009BC98.unk16)[0] = 0;
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_80119FEC);

extern void *D_80129338;
extern u16 D_80124FE4[];

void func_80119FEC(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = 2;
        o->hitWidth = 6;
        o->hitOffsetY = 0x38;
        o->hitHeight = D_80124FE4[o->unkC];
        o->tpage = 0x10;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_80129338;
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A0C8);
typedef struct { s16 vx, vy, vz, pad; } SVEC_1A0C8;
extern char SCRATCHPAD_CharArr[] asm("SCRATCHPAD");

#define V5C (*(s32 *)((char *)o + 0x5c))
#define V60 (o->unk60)
#define V64 (o->buffSize)

void func_8011A0C8(GameObject *o)
{
    GameObject *e;
    SVEC_1A0C8 v;

    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkA = 0x10;
        o->unkA0 = 0;
        o->hitOffsetX = 6;
        o->hitWidth = 0xc;
        o->hitOffsetY = 6;
        o->hitHeight = 0xc;
        break;
    case 1:
        e = (GameObject *)o->unk90;
        getBaseMatrix(&SCRATCHPAD.workMatrix);
        v.vx = o->unk30 >> 16;
        v.vy = o->unk34 >> 16;
        v.vz = o->unk38 >> 16;
        MulMatrix0(&e->unk48, SCRATCHPAD_CharArr, &o->unk48);
        ApplyRotMatrix(&v, &o->unk5C);
        V5C += e->x.p.whole;
        V60 += e->y.p.whole;
        V64 += e->z.p.whole;
        o->x.p.whole = V5C;
        o->y.p.whole = V60;
        o->z.p.whole = V64;
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
#undef V5C
#undef V60
#undef V64

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A22C);
typedef struct { s16 vx, vy, vz, pad; } SVEC_1A22C;

#define V5C (*(s32 *)((char *)o + 0x5c))
#define V60 (o->unk60)
#define V64 (o->buffSize)

void func_8011A22C(GameObject *o)
{
    GameObject *e;
    SVEC_1A22C v;

    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkA = 0;
        o->anim = 0;
        o->hitOffsetX = 0xa;
        o->hitWidth = 0x14;
        o->hitOffsetY = 0xa;
        o->hitHeight = 0x14;
        break;
    case 1:
        e = (GameObject *)o->unk90;
        getBaseMatrix(&SCRATCHPAD.workMatrix);
        v.vx = o->unk30 >> 16;
        v.vy = o->unk34 >> 16;
        v.vz = o->unk38 >> 16;
        MulMatrix0(&e->unk48, SCRATCHPAD_CharArr, &o->unk48);
        ApplyRotMatrix(&v, &o->unk5C);
        V5C += e->x.p.whole;
        V60 += e->y.p.whole;
        V64 += e->z.p.whole;
        o->x.p.whole = V5C;
        o->y.p.whole = V60;
        o->z.p.whole = V64;
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
#undef V5C
#undef V60
#undef V64

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A38C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A4B4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A650);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011A7C0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011AAF4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011AB74);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011B1CC);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011B350);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011B91C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BA78);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BB50);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BC04);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BCE0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BD20);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BDA4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BEE4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BF60);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011BFF8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C0B0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C1A8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C270);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C334);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C384);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C47C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C620);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C678);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C6B4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C730);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C73C);

typedef struct {
    GameObject t;
    char pad[0xe8 - 0xc0];
    u16 e8;
    u16 ea;
} P_1C73C;

void func_8011C73C(P_1C73C *o, GameObject *e)
{
    s16 d;
    u16 x;
    u16 w;

    if ((u16)(o->t.d->p.whole - e->d->p.whole + 45) < 91) {
        d = o->e8 - o->t.h->p.whole;
        if (d < 0) d = -d;
        w = o->e8 - e->h->p.whole;
        if (o->t.animFrame & 1)
            x = e->hitOffsetX + d + w;
        else
            x = e->hitOffsetX + w;
        if (x > e->hitWidth + d) return;
        d = e->hitOffsetY + (o->ea - e->y.p.whole);
        if ((u16)d <= e->hitHeight) {
            o->t.unk9E = 3;
            o->t.velY = 0;
            o->t.unkB8 = 0;
            o->t.unkBA = 0;
            e->touchFlag = 2;
            SCRATCHPAD.unk19E = 0;
            (*(GameObject **)&(*(void * *)&SCRATCHPAD.unk3C0)) = e;
        }
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C840);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C914);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011C948);
extern s16 D_800A38E4;
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

s32 func_8011C948(GameObject *o)
{
    s16 d;

    if (o->unk7A & 1) {
        d = -0x10;
        if (o->h->p.whole < D_800A38E4 - 0x90) {
            o->h->p.whole = D_800A38E4 - 0x90;
            return 1;
        }
    } else {
        d = 0x10;
        if (D_800A38E6 + 0x90 < o->h->p.whole) {
            o->h->p.whole = D_800A38E6 + 0x90;
            return 1;
        }
    }
    return func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, o->unk7A) != 0;
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CA00);
extern s16 D_800A38E4;
extern s16 func_80043AB0(GameObject *, s16, s16, s16);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

s32 func_8011CA00(GameObject *o)
{
    s16 d;

    if (o->animFrame & 1) {
        d = -0x10;
        if (o->h->p.whole < D_800A38E4 - 0x90) {
            o->h->p.whole = D_800A38E4 - 0x90;
            return 1;
        }
    } else {
        d = 0x10;
        if (D_800A38E6 + 0x90 < o->h->p.whole) {
            o->h->p.whole = D_800A38E6 + 0x90;
            return 1;
        }
    }
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, o->animFrame & 1) == 0) {
        return probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x12) != 0;
    }
    return 1;
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CAF4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CB24);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CBD0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CC08);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CC3C);

s32 func_8011CC3C(u16 *p)
{
    if ((u16)(p[0] - (*(u16*)((char*)&SCRATCHPAD.vpx.raw + 2)) + 0xa0) < 0x141)
        return (u16)(p[1] - (*(u16*)((char*)&SCRATCHPAD.vpy.raw + 2)) + 0x6e) < 0xdd;
    return 0;
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CC8C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CCE8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CD14);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CE24);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CE54);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CF50);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CF9C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011CFA0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D098);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D1A8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D41C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D4F4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D534);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D6A8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D894);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011D9CC);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011DA00);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011DAB0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011DE38);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011DE4C);
extern s32 tickAnimation(GameObject *);
extern void decreaseObjectTimer(void *, s32);

#define ANIMS(o) (*(void ***)((char *)(o) + 0xa8))

#define setBox(o, i) { u8 *b = (u8 *)(o)->unk90; b += (i) * 4; \
    (o)->hitOffsetX = *b++; (o)->hitWidth = *b++; (o)->hitOffsetY = b[0]; (o)->hitHeight = b[1]; (o)->unkAC = (i); }

void func_8011DE4C(GameObject *o)
{
    u8 *q;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        o->timer = 8;
        o->step++;
        setBox(o, 11);
        o->anim = ANIMS(o)[11];
        readAnimFrameCount(o);
        break;
    case 1:
        if (--o->timer != -1) break;
        setBox(o, 12);
        o->anim = ANIMS(o)[12];
        readAnimFrameCount(o);
        o->timer = 8;
        o->step++;
        break;
    case 3:
        setBox(o, 12);
        o->anim = ANIMS(o)[12];
        readAnimFrameCount(o);
        o->timer = 0x78;
        o->step++;
        break;
    case 4:
        if (--o->timer != -1) break;
        setBox(o, 12);
        o->anim = ANIMS(o)[12];
        readAnimFrameCount(o);
        o->timer = 0x3c;
        o->step++;
        break;
    case 5:
        tickAnimation(o);
        if (*q & 2) break;
        if (--o->timer != -1) break;
        setBox(o, 14);
        o->anim = ANIMS(o)[14];
        readAnimFrameCount(o);
        q = (u8 *)&(*(GameObject *)&PLAYER);
        o->step++;
        *q = 2;
        (*(GameObject *)&PLAYER).animFrame = o->h->p.whole > (*(GameObject *)&PLAYER).h->p.whole;
        (*(GameObject *)&PLAYER).state = 2;
        (*(GameObject *)&PLAYER).subState = 0;
        (*(GameObject *)&PLAYER).step = 0;
        decreaseObjectTimer(q, 1);
        break;
    case 2:
    case 7:
        break;
    case 6:
        if (tickAnimation(o)) {
            o->active = 1;
            o->unk68 = 0;
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            o->unk8C = 0;
        }
        break;
    }
}
#undef ANIMS
#undef setBox

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011E194);
extern char D_8007728C[];
extern void func_800224FC(s32, s16, s16, s16);
extern void applyAnimVelocityX(GameObject *, u16);
extern void func_80115F60(GameObject *);

#define setbox(o, q) { u8 *p_; p_ = (u8 *)o->unk90; p_ += (q); (o)->hitOffsetX = *p_++; (o)->hitWidth = *p_++; (o)->hitOffsetY = *p_; (o)->hitHeight = p_[1]; }

typedef struct { char pad[0xa8]; void **tbl; } TB_1E194;

void func_8011E194(GameObject *o)
{
    u8 *p;
    s32 r;

    switch (o->step) {
    case 0:
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        o->unk9C = 0;
        o->unk6A = 1;
        o->step++;
        setbox(o, 0x3c);
        o->unkAC = 0xf;
        o->anim = ((TB_1E194 *)o)->tbl[15];
        readAnimFrameCount(o);
        o->movetab = D_8007728C;
        break;
    case 1:
        if (o->animFrame & 2) {
            o->y.raw += 0x48000;
            r = func_8011CAF4(o);
            if (r) {
                o->unk6A = 0;
                o->step++;
                func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                playSFX(6);
            }
        } else {
            applyFrameVelocityX(o);
            r = func_8011CA00(o);
            if (r) {
                o->unk6A = 0;
                o->step++;
                func_800224FC(1, o->x.p.whole, o->y.p.whole, o->z.p.whole);
                playSFX(6);
            }
        }
        if (o->animFrame & 1) o->unk8C = (u8)(o->unk8C + 0x14);
        else o->unk8C = (u8)(o->unk8C - 0x14);
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        break;
    case 2:
        if (o->animFrame & 2) o->unk7A = o->animFrame & 1;
        else o->unk7A = ~o->animFrame & 1;
        playSFX(7);
        o->velV = -0x400;
        o->unk9C = 1;
        o->unk6A = 0;
        o->movetab = ((char *)&D_8007722C);
        o->step++;
    case 3:
        if (o->unk7A) o->unk8C = (u8)(o->unk8C + 0x14);
        else o->unk8C = (u8)(o->unk8C - 0x14);
        applyAnimVelocityX(o, o->unk7A);
        func_8011C948(o);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 2;
            if (func_8011CAF4(o)) {
                o->unk9C = 0;
                o->unk8C = 0;
                o->step++;
                o->animFrame &= 1;
            }
        }
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        break;
    case 4:
        setbox(o, 0x34);
        o->unkAC = 0xd;
        o->anim = ((TB_1E194 *)o)->tbl[13];
        readAnimFrameCount(o);
        o->timer = 0x3c;
        o->step++;
        D_1F80018C = o->h->raw;
        D_1F800190 = o->y.raw;
        D_800A38BB[0] = 6;
        func_80115F60(o);
        break;
    case 5:
        if (--o->timer == -1) {
            o->unk8C = 0;
            o->subState = 2;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}
#undef setbox

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011E55C);


struct GSInventory_1E55C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1E55C { u8 weapon; u8 pants; };

typedef struct { s16 v[6]; } V6_1E55C;
extern u8 TALK_POSE;
extern s16 D_80125164[];
extern s32 func_80022E44__1E55C(GameObject *);
extern GameObject *showMessageBoxDirect(s32, s32, V6_1E55C *);

static __inline__ void SetAnim_1E55C(GameObject *o, s16 n)
{
    u8 *p;
    p = (u8 *)o->unk90;
    p += n * 4;
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    o->unkAC = n;
    o->anim = (*(void ***)&o->unkA8)[n];
    readAnimFrameCount(o);
}

void func_8011E55C(GameObject *o)
{
    V6_1E55C v;
    GameObject *e;

    func_80022E44__1E55C(o);
    tickAnimation(o);
    switch (o->step) {
    case 0:
        updateObjectSideFlag(o);
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        o->timer = 0x3c;
        if (((u8 *)&D_8009C068.unk5ab)[GAME.selectedSection] == 2) {
            o->step = 4;
        } else {
            TALK_POSE = 2;
            ((u8 *)&D_8009C068.unk5ab)[GAME.selectedSection] = 2;
            o->step++;
        }
        break;
    case 1:
        if (--o->timer == -1) {
            o->step++;
            SetAnim_1E55C(o, 0x13);
            TALK_POSE = 0;
        }
        break;
    case 2:
        v = *(V6_1E55C *)&o->x;
        o->unkA0 = (s32)showMessageBoxDirect(2, D_80125164[GAME.selectedSection], &v);
        o->step++;
        break;
    case 3:
        e = (GameObject *)o->unkA0;
        if (e->state == 2) {
            e->state = 3;
            o->timer = 0x3c;
            o->step++;
        }
        break;
    case 4:
        if (--o->timer == -1) {
            ((u8*)&D_8009BC98.unk0F)[0] = 0;
            o->state++;
            o->subState = 0;
            o->step = 0;
            if (o->subtype == 0) SetAnim_1E55C(o, 0);
            else SetAnim_1E55C(o, 2);
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011E824);

#define WC2(o) (*(u16 *)((char *)(o) + 0xc2))

static __inline__ void setanim_1E824(GameObject *o, s16 k)
{
    u8 *p;
    p = (u8 *)o->unk90;
    p += k * 4;
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    o->unkAC = k;
    o->anim = ((void **)*(s32 *)&o->unkA8)[k];
    readAnimFrameCount(o);
}

void func_8011E824(GameObject *o)
{
    u8 *p;

    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            updateObjectSideFlag(o);
            func_8011CD14(o);
            if (o->subtype == 0) {
                setanim_1E824(o, 0);
            } else {
                setanim_1E824(o, 2);
            }
            (*(GameObject **)&D_8009BC98.unk18) = o;
            o->subState++;
            break;
        case 1:
            if (D_8009BC98.unk0A) func_8011E55C(o);
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_8011CFA0(o);
            break;
        case 1:
            func_8011D894(o);
            break;
        case 2:
            func_8011CE54(o);
            break;
        }
        o->unkB4++;
        break;
    case 2:
        if (WC2(o) == 1) {
            D_8009BC98.unk0E = 0;
            D_8009BC98.unk12 = 0;
            WC2(o) = 0;
        }
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_8011DAB0(o);
            break;
        case 1:
            func_8011DE4C(o);
            break;
        case 2:
            switch (o->step) {
            case 0:
                func_80115F60(o);
                o->unk8C = 0;
                o->step++;
                setanim_1E824(o, 0xe);
                break;
            case 1:
                if (tickAnimation(o)) {
                    o->unk68 = 0;
                    o->active = 1;
                    o->state = 1;
                    o->subState = 0;
                    o->step = 0;
                    o->unk7 = 0;
                }
                break;
            }
            break;
        case 3:
            func_8011E194(o);
            break;
        case 4:
            if (o->step == 1) o->visible = 0;
            break;
        }
        o->unkB4++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
#undef WC2

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011EB94);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_2", func_8011EBCC);
