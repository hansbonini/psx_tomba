#include "common.h"
#include "game.h"
#include "x03.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118148);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_1", func_80115274);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011828C);



void func_8011828C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C608.purifiedAreas & 2) {
            o->state = 3;
            break;
        }
        o->state++;
        o->tpage = 8;
        o->unkD = 0x80;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_80138264[o->unkC];
        o->buffSize = 0x1400;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            o->subState++;
            func_80118148(o);
            break;
        case 1:
            switch (o->subtype) {
            case 0:
            case 2:
                o->x.raw += 0x180000;
                break;
            case 1:
            case 4:
                o->x.raw += 0x160000;
                o->y.raw += -0x80000;
                break;
            case 3:
                o->x.raw += 0x160000;
                o->y.raw += 0x60000;
                break;
            case 5:
            case 6:
                o->x.raw += 0xf0000;
                break;
            case 7:
                o->x.raw += 0xa0000;
                break;
            }
            if (!func_80022E44(o)) o->subState = 0;
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011845C);


void func_8011845C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 9;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013827C[o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118514);

typedef struct {
    char p[0xb4];
    s16 b4, b6, b8, ba, bc, be, c0, c2, c4, c6, c8, ca, cc, ce, d0;
} E_18514;

extern s16 D_1F800176_S16Arr[] asm("D_1F800176");

void func_80118514(GameObject *o)
{
    E_18514 *e = (E_18514 *)o;

    switch (o->subState) {
    case 0:
        o->subState++;
        o->d->p.whole -= o->subtype * 4;
        break;
    case 1:
        o->subState++;
        o->velX = 0x300;
        o->timer = 0x78;
        e->b4 = D_80134BEC[0];
        e->b6 = D_80134BEC[1];
        e->b8 = 0;
        e->bc = D_80134BEC[2];
        e->be = D_80134BEC[3];
        e->c0 = 0;
        e->c4 = D_80134BEC[4];
        e->c6 = D_80134BEC[5];
        e->c8 = 0;
        e->cc = D_80134BEC[6];
        e->ce = D_80134BEC[7];
        e->d0 = 0;
        o->x.raw = (D_1F800176_S16Arr[0] - 0xa0) << 16;
        { s16 r = (nextRandom() & 7) * 24 + 0x10; o->y.raw = (SCRATCHPAD.unk168[7].p.whole - r) << 16; }
        o->velH = o->subtype << 7;
        break;
    case 2:
        o->h->raw += 0x60000 + (o->velH << 8);
        o->y.raw += -0x8000;
        if (o->timer != 0) {
            e->b4 += o->velX >> 8;
            o->timer--;
            e->bc += o->velX >> 8;
        }
        if (o->h->p.whole + e->c4 > D_1F800176_S16Arr[0] + 0x168) o->subState = 1;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118720);

typedef struct { char p[0xb4]; SVECTOR v[4]; } OX_18720;

#define V(o) (((OX_18720 *)(o))->v)

#define INITV(o) { V(o)[0].vx = D_80134BEC[0]; V(o)[0].vy = D_80134BEC[1]; V(o)[0].vz = 0; V(o)[1].vx = D_80134BEC[2]; V(o)[1].vy = D_80134BEC[3]; V(o)[1].vz = 0; V(o)[2].vx = D_80134BEC[4]; V(o)[2].vy = D_80134BEC[5]; V(o)[2].vz = 0; V(o)[3].vx = D_80134BEC[6]; V(o)[3].vy = D_80134BEC[7]; V(o)[3].vz = 0; }

void func_80118720(GameObject *o)
{
    s32 k;

    switch (o->subState) {
    case 0:
        o->subState = 2;
        o->velX = 0x100;
        o->timer = 0x168;
        INITV(o);
        o->x.raw = (D_1F800176_S16Arr[0] + o->subtype * 52) << 16;
        k = 0x60;
        if (GAME.selectedSection == 3)
            o->y.raw = (-0x272 - (nextRandom() & 0xf) * 42) << 16;
        else
            o->y.raw = (SCRATCHPAD.unk168[7].p.whole - ((nextRandom() & 7) * 32 + k)) << 16;
        o->velH = o->subtype * 24;
        break;
    case 1:
        o->subState++;
        o->velX = 0x100;
        o->timer = 0x168;
        INITV(o);
        o->x.raw = (D_1F800176_S16Arr[0] - 0xa0) << 16;
        k = 0x18;
        if (GAME.selectedSection == 3)
            o->y.raw = (-0x272 - (nextRandom() & 0xf) * 42) << 16;
        else
            o->y.raw = (SCRATCHPAD.unk168[7].p.whole - ((nextRandom() & 7) * 32 + k)) << 16;
        o->velH = o->subtype * 24;
        break;
    case 2:
        o->h->raw += 0x10000 + (o->velH << 8);
        o->y.raw -= 0x1000;
        if (o->timer != 0) {
            V(o)[0].vx += o->velX >> 8;
            V(o)[1].vx += o->velX >> 8;
            o->timer--;
        }
        if (o->h->p.whole + V(o)[2].vx > D_1F800176_S16Arr[0] + 0x26c)
            o->subState = 1;
        break;
    }
}
#undef V
#undef INITV

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118A48);


void func_80118A48(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unkD = 0x81;
        if (GAME.selectedSection == 3) {
            o->tpage = 8;
            o->clut = 0x780c;
        } else {
            o->tpage = 9;
            o->clut = 0x780b;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_80138290[o->unkC];
        o->d->p.whole -= o->subtype * 4;
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        if (GAME.selectedSection != 3 && GAME.selectedSection < 4) func_80118514(o);
        else func_80118720(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118B88);


void func_80118B88(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (D_8009C608.purifiedAreas & 4) {
            o->state = 3;
            break;
        }
        o->state++;
        o->tpage = 0xe;
        o->unkD = 0x81;
        o->clut = 0x7c0e;
        o->spriteBank = SCRATCHPAD.sprData[3];

        o->anim = D_8013828C;
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        tickAnimation(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118C7C);


void func_80118C7C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (!(D_8009C608.purifiedAreas & 4)) {
            o->state = 3;
            break;
        }
        o->state++;
        if (o->unkC == 0) {
            o->unkD = 0x80;
            o->tpage = 8;
            o->buffSize = 0x2000;
        } else {
            o->unkD = 0x81;
            o->clut = 0x7811;
            o->tpage = 9;
            o->buffSize = 0x1800;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_80138238[o->unkC];
        readAnimFrameCount(o);
        break;
    case 1:
        switch (o->unkC) {
        case 0:
            o->visible = 1;
            pushDrawListCapped(o);
            switch (o->subState) {
            case 0:
                o->subState++;
                o->timer = 0x30;
                break;
            case 1:
                if (--o->timer == -1) {
                    o->timer = 0x30;
                    o->subState++;
                } else {
                    o->buffSize -= 0x10;
                }
                break;
            case 2:
                if (--o->timer == -1) {
                    o->timer = 0x30;
                    o->subState--;
                } else {
                    o->buffSize += 0x10;
                }
                break;
            }
            switch (o->step) {
            case 0:
                o->step++;
                o->cooldownTimer = 0x3c;
                break;
            case 1:
                if (--o->cooldownTimer == -1) {
                    o->cooldownTimer = 0x3c;
                    o->step++;
                } else {
                    o->y.raw -= 0x2000;
                }
                break;
            case 2:
                if (--o->cooldownTimer == -1) {
                    o->cooldownTimer = 0x3c;
                    o->step--;
                } else {
                    o->y.raw += 0x2000;
                }
                break;
            }
            break;
        case 2:
            if (func_80022E44(o)) {
                tickAnimation(o);
            }
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80118F9C);
static __inline__ void init_18F9C(GameObject *p)
{
    GameObject *q;
    char pad[56];

    p->active = 2;
    p->unk84 = 0;
    p->unk88 = 0;
    p->unk8C = 0;
    p->velX = 0;
    q = (GameObject *)p->unk90;
    if (q != 0) {
        p->unk30 = p->x.raw - q->x.raw;
        p->unk34 = p->y.raw - q->y.raw;
        p->unk38 = p->z.raw - q->z.raw;
        if (p->unk94 == 0) {
            p->hitOffsetX = 0x14;
            p->hitWidth = 0x28;
            p->hitOffsetY = 0xf;
            p->hitHeight = 0x1e;
            p->active = 1;
        }
    }
}

void func_80118F9C(GameObject *o)
{
    char pad2[16];

    init_18F9C(o);
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119038);
typedef struct {
    char pad[0xb8];
    void *db8, *dbc, *dc0, *dc4, *dc8, *dcc, *dd0;
} TObjX_19038;
#define X(p) ((TObjX_19038 *)(p))

void func_80119038(GameObject *o)
{
    GameObject *p, *q;
    s32 x, y, z;
    char pad[72];

    o->objectIndex = 0;
    if (o->unk90 != 0) return;
    p = o;
    q = p;
    while (1) {
        x = p->x.raw;
        y = p->y.raw;
        do {} while (0);
        z = p->z.raw;
        p->unkB4 = 0;
        p->unkB6 = 0;
        X(p)->db8 = D_80134CC4;
        X(p)->dbc = D_80134CC4;
        X(p)->dc0 = D_80134CC4;
        X(p)->dc4 = D_80134C7C + o->subtype * 8;
        X(p)->dc8 = D_80134C84 + o->subtype * 8;
        X(p)->dcc = D_80134C8C + o->subtype * 8;
        if (p->unk94 == 0) {
            p->hitOffsetX = 0x14;
            p->hitWidth = 0x28;
            p->hitOffsetY = 0xf;
            p->hitHeight = 0x1e;
            X(p)->dd0 = D_80134BFC;
        } else {
            p->active = 2;
            X(p)->dd0 = D_80134BFC;
        }
        p = (GameObject *)p->unk94;
        if (p == 0) break;
        q->unk30 = p->x.raw - x;
        q->unk34 = p->y.raw - y;
        q->unk38 = p->z.raw - z;
        q = p;
    }
}
#undef X

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119158);
extern s16 fixedMulSin2(u8, s32);

void func_80119158(GameObject *o)
{
    GameObject *p;
    VECTOR in;
    VECTOR out;
    SVECTOR v;
    MATRIX m;

    switch (o->subState) {
    case 0:
        o->velH = 0;
        if (o->subtype == 0)
            o->subState++;
        break;
    case 1:
        if (o->unk90 == 0)
            o->velX += nextRandom() & 0x1f;
        else {
            p = (GameObject *)o->unk90;
            o->velX = p->velX;
        }
        o->velH = fixedMulSin2(o->velX, 0x1000);
        o->unk8C = (o->velH >> 8) & 0xfff;
        break;
    }
    if (o->unk90 != 0) {
        p = (GameObject *)o->unk90;
        v.vx = 0;
        v.vy = 0;
        v.vz = o->unk8C;
        RotMatrix(&v, &m);
        in.vx = o->unk30;
        in.vy = o->unk34;
        in.vz = o->unk38;
        ApplyMatrixLV(&m, &in, &out);
        o->x.raw = p->x.raw + out.vx;
        o->y.raw = p->y.raw + out.vy;
        o->z.raw = p->z.raw + out.vz;
        if (o->unk94 == 0)
            o->unk8C = fixedMulSin2(o->velH, 0x40);
    }
    func_80022E44(o);
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_801192E0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119404);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119798);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119894);

void func_80119894(GameObject *o)
{
    GameObject *e;
    s32 v;
    char pad[0x48];

    u8 s = o->state;

    v = s;
    switch (v) {
    case 0:
        o->unkA4 = 0;
        v = GAME.selectedSection;
        if (v < 0) goto d0;
        if (v < 2) {
            o->active = 2;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            o->velX = 0;
            e = (GameObject *)o->unk90;
            if (e) {
                o->unk30 = o->x.raw - e->x.raw;
                o->unk34 = o->y.raw - e->y.raw;
                o->unk38 = o->z.raw - e->z.raw;
                if (o->unk94 == 0) {
                    o->hitOffsetX = 0x14;
                    o->hitWidth = 0x28;
                    o->hitOffsetY = 0xf;
                    o->hitHeight = 0x1e;
                    o->active = 1;
                }
            }
        } else {
        d0:
            func_80119038(o);
        }
        o->state++;
        break;
    case 1:
        v = GAME.selectedSection;
        if (v < 0) goto d1;
        if (v < 2) func_80119158(o);
        else { d1: func_801192E0(o); }
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119A14);


s32 func_80119A14(GameObject *o)
{
    switch (o->step) {
    case 0:
        if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + 0x20) > 0x40) return 0;
        if ((u16)(o->y.p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) + 0x30) > 0x60) break;
        if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 1) return 1;
        if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 2)) == 2) {
            o->unk30 = 0;
            o->step++;
            return 2;
        }
        if (D_8009BC98.unk0A) return 0;
        o->step = 3;
        o->unk30 = 0;
        o->h->p.whole -= 0x20;
        return 2;
    case 1:
        o->h->raw += -0x18000;
        o->unk30 += -0x18000;
        if ((o->unk30 >> 16) < -0x1f) o->step++;
        break;
    case 2:
        if ((*(u8*)((char*)&PLAYER.obj.unkA0 + 3)) == 2) o->step++;
        break;
    case 3:
        if (!(*(u8*)((char*)&PLAYER.obj.unkA0 + 3))) o->step++;
        break;
    case 4:
        o->h->raw += 0x18000;
        o->unk30 += 0x18000;
        if (o->unk30 >= 0) o->step = 0;
        break;
    }
    return 0;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_80119BC4);

extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);

#define DOOR(o) \
    switch (o->step) { \
    case 0: \
        o->step = ((GameObject *)o->unk90)->step; \
        o->unk30 = 0; \
        if (o->step == 3) { \
            o->unk30 = 0; \
            o->h->p.whole += 0x20; \
        } \
        break; \
    case 1: \
        o->h->raw += 0x18000; \
        o->unk30 += 0x18000; \
        if ((o->unk30 >> 16) >= 0x20) o->step++; \
        break; \
    case 2: \
    case 3: \
        o->step = ((GameObject *)o->unk90)->step; \
        break; \
    case 4: \
        o->h->raw -= 0x18000; \
        o->unk30 -= 0x18000; \
        if ((o->unk30 >> 16) <= 0) o->step = 0; \
        break; \
    }

void func_80119BC4(GameObject *o)
{
    u8 s = o->state;
    u8 t;
    s32 r;

    switch (s) {
    case 0:
        o->state = s + 1;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            r = func_80119A14(o);
            if (r == 1) {
                if (D_800A5443 == r) {
                    if (D_8009C068.event_29 == 0xff) break;
                    o->unk7 = 4;
                } else {
                    if (D_8009C068.event_29 != 0) break;
                    o->unk7 = 1;
                }
                o->unkAC = 0x29;
            }
            break;
        case 1:
            DOOR(o);
            break;
        case 2:
            t = o->step;
            switch (t) {
            case 0:
                if (D_8009C068.unk590) o->step = 2;
                else o->step = t + 1;
                break;
            case 1:
                if ((*(GameObject *)&PLAYER).h->p.whole < 0x25) (*(GameObject *)&PLAYER).h->p.whole = 0x25;
                o->unk88 = 0;
                break;
            case 2:
                o->unk88 = 0x400;
                break;
            }
            break;
        case 3:
            switch (o->step) {
            case 0:
                o->step = ((GameObject *)o->unk90)->step;
                break;
            case 1:
                o->unk88 = 0;
                break;
            case 2:
                o->unk88 = 0xc00;
                break;
            }
            break;
        case 4:
            r = func_80119A14(o);
            if (D_8009C608.purifiedAreas & 2) {
                if (r != 2) break;
                if (D_8009C068.event_AA == 0xff) break;
                o->unk7 = 4;
            } else {
                if (r != 1) break;
                if (D_8009C068.event_AA != 0) break;
                o->unk7 = 1;
            }
            o->unkAC = 0xaa;
            break;
        case 5:
            DOOR(o);
            break;
        case 8:
            r = func_80119A14(o);
            if (D_8009C068.item_35) {
                if (r != 2) break;
                if (D_8009C068.event_37 == 0xff) break;
                o->unk7 = 4;
            } else {
                if (r != 1) break;
                if (D_8009C068.event_37 != 0) break;
                o->unk7 = 1;
            }
            o->unkAC = 0x37;
            break;
        case 9:
            DOOR(o);
            break;
        }
        switch (o->unk7) {
        case 0:
            break;
        case 1:
            ((u8*)&D_8009BC98.unk0F)[0] = 1;
            ((u8*)&D_8009BC98.unk12)[0] = 1;
            ((u8*)&D_8009BC98.unk0E)[0] = 1;
            o->timer = 0x12c;
            o->unk7++;
            setEventStarted(o->unkAC, 0, 0);
            break;
        case 4:
            ((u8*)&D_8009BC98.unk0F)[0] = 1;
            ((u8*)&D_8009BC98.unk12)[0] = 1;
            ((u8*)&D_8009BC98.unk0E)[0] = 1;
            o->timer = 0x12c;
            o->unk7++;
            setEventComplete(o->unkAC, 0);
            break;
        case 2:
        case 5:
            if (--o->timer == -1) o->unk7++;
            break;
        case 3:
        case 6:
            ((u8*)&D_8009BC98.unk0F)[0] = 0;
            ((u8*)&D_8009BC98.unk12)[0] = 0;
            ((u8*)&D_8009BC98.unk0E)[0] = 0;
            o->unk7 = 0;
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
#undef DOOR

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A124);

void func_8011A124(GameObject *o)
{
    switch (o->subState) {
    case 0:
        o->subState++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
    case 1:
        if (o->touchFlag) {
            o->velH = 0x400;
            o->unk74 = 0x400;
            o->velX = -0x80;
            o->velV = -0x180;
            o->velY = 0xc0;
            o->timer = 4;
            o->subState++;
        }
        break;
    case 2:
        o->unk8C = (o->unk8C + (o->velH >> 4)) & 0xfff;
        o->velH += o->velX;
        o->y.raw += o->velV << 8;
        o->velV += o->velY;
        if ((u16)(o->velV + 0xff) >= 0x1ff) {
            { s32 t = o->velY; o->velY = -t; }
            if (o->touchFlag) {
                func_80028A74(0, 0, 0xff, 4);
            }
        }
        if (o->velH == o->unk74) {
            if (--o->timer == 0) {
                o->subState++;
                o->unkF -= 10;
                playSFX(0x7c);
                break;
            }
            { s32 t = o->velX; o->velX = -t; }
        } else if (o->velH == -o->unk74) {
            { s32 t = o->velX; o->velX = -t; }
        }
        break;
    case 3:
        o->unk8C = (o->unk8C + (o->velH >> 4)) & 0xfff;
        o->y.p.whole += 2;
        if (o->visible == 0) {
            o->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A318);
typedef struct { u8 a, b, c; } T3_1A318;
extern T3_1A318 D_80134DBC[];

void func_8011A318(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = D_80134DBC[o->subtype].a;
        o->hitWidth = D_80134DBC[o->subtype].b;
        o->hitHeight = o->hitOffsetY = D_80134DBC[o->subtype].c;
        break;
    case 1:
        func_80022E44(o);
        func_8011A124(o);
        o->touchFlag = 0;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A408);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A4B4);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A650);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A674);

extern s32 angleFromDelta(s32, s32);

s32 func_8011A674(GameObject *o)
{
    s32 dx, dy;
    s32 a;

    dx = SCRATCHPAD.unk168[0].p.whole - o->h->p.whole;
    dy = SCRATCHPAD.unk168[1].p.whole - o->y.p.whole;
    if (SquareRoot0(dx * dx + dy * dy) > 0x10) {
    a = (u8)angleFromDelta(dx, dy);
    o->unkB0 = a;
    a += 0x80;
    a &= 0xff;
    dy = (o->velH * D_8007D788[a]) >> 12;
    dx = (o->velH * D_8007DB88[a]) >> 12;
    *(*(s32 **)&D_800A53D8) += dx << 8;
    ((s32*)&PLAYER.obj.y.raw)[0] += dy << 8;
    o->velH += 0x80;
    if (o->velH > 0x800) o->velH = 0x800;
    return 0;
    }
    return 1;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A7B0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A7C0);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011A8D8);
extern s32 angleFromDelta(s32, s32);

s32 func_8011A8D8(GameObject *o, s32 mode, s32 target)
{
    s32 t;
    s32 cur;
    u8 d;
    u8 thr;

    if (mode == 0)
        t = angleFromDelta(SCRATCHPAD.unk168[0].p.whole - o->h->p.whole, SCRATCHPAD.unk168[1].p.whole - o->y.p.whole);
    else if (mode == 1) {
        if (o->subtype & 2)
            t = (o->subtype & 1) << 7;
        else
            t = ((*(GameObject *)&PLAYER).h->p.whole < o->h->p.whole) << 7;
    } else
        t = target;
    cur = o->unk38;
    d = t - cur;
    thr = D_80134DC8[(cur & 0xff) >> 4];
    if (d != 0) {
        if (thr >= d) {
            if (d >= 2)
                d = 2;
            if ((u8)cur >= 0xc1)
                o->unk38 = cur + d;
            else {
                o->unk38 = cur + d;
                if ((u8)o->unk38 >= 0xa0)
                    o->unk38 = 0xa0;
            }
        } else {
            if (d < 0xff)
                d = 0xfe;
            if ((u8)cur < 0xc0)
                o->unk38 = cur + d;
            else {
                o->unk38 = cur + d;
                if ((u8)o->unk38 < 0xe1)
                    o->unk38 = 0xe0;
            }
        }
        o->unk38 = (u8)o->unk38;
        return 0;
    }
    return 1;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011AA44);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011AAF4);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011ABC0);


static __inline__ s32 near_1ABC0(GameObject *o)
{
    u16 t;
    s16 lim = 0xc8;
    if (((u8 *)&PLAYER)[0] == 2) return 0;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[2].raw + 2)) - o->d->p.whole + 0x2d;
    if (t >= 0x5b) return 0;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) - o->h->p.whole + 0x64;
    if (t > lim) return 0;
    t = (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) - o->y.p.whole + 0x78;
    return t <= lim - 0x10;
}

void func_8011ABC0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->unkAC = 0;
        o->anim = D_80138C18[0];
        readAnimFrameCount(o);
        break;
    case 1:
        o->unkA7 += 2;
        if (o->unkA7 > 0x80) o->unkA7 = 0;
        { s16 t = (s16)D_8007D788[o->unkA7] >> 6; o->unkA6 = t; }
        func_8011A8D8(o, 0, 0);
        if (func_8011A7B0(o)) {
            o->unkA = 2;
            o->velH = 0x80;
            ((u8 *)&D_800A539C)[0] = 1;
            D_8009C618[0] = 0;
            ((u8 *)&PLAYER)[0] = 2;
            ((u8 *)&D_800A539D)[0] = 0x36;
            ((u8 *)&D_800A539E)[0] = 0;
            o->step = 0;
            o->subState++;
        } else if (!near_1ABC0(o)) {
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_1", func_8011AD84);
extern u8 PLAYER_U8Arr[] asm("PLAYER");
extern u8 D_800A5399[];
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");

static __inline__ void move_1AD84(GameObject *o)
{
    o->velY = (o->velV * D_8007D788[*(u8 *)&o->unk8C]) >> 12;
    o->velX = (o->velV * D_8007DB88[*(u8 *)&o->unk8C]) >> 12;
    if (o->animFrame == 0) {
        o->velX = -o->velX;
        o->velY = -o->velY;
    }
    o->h->raw += o->velX << 8;
    o->y.raw += o->velY << 8;
}

void func_8011AD84(GameObject *o)
{
    s16 v;

    switch (o->step) {
    case 0:
        func_8011A8D8(o, 0, 0);
        if (func_8011A674(o)) {
            o->step++;
            PLAYER_U8Arr[0] = 5;
            D_800A539C_U8Arr[0] = 5;
            D_800A539D_U8Arr[0] = 0x40;
            D_800A5399[0] = 0;
            o->unkAC = 2;
            o->anim = D_80138C20[0];
            readAnimFrameCount(o);
            o->velV = 0xe00;
            move_1AD84(o);
        }
        break;
    case 1:
        playSFX(0x70);
        o->velV = 0x380;
        o->step++;
    case 2:
        move_1AD84(o);
        v = o->velV;
        if (v < 0) {
            o->velV = v - 0x50;
            if (o->velV < -0x400) {
                o->velV = -0x400;
                o->step = 0;
                o->subState++;
                o->h->p.whole = o->unk30;
                o->y.p.whole = o->unkB4;
            }
        } else {
            o->velV = v - 0x40;
        }
        tickAnimation(o);
        break;
    }
}
