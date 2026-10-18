#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116814);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116C78);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116F24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", updatePointsBalloon);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011700C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011702C);
void func_8011702C(GameObject *o)
{
    switch (o->subState) {
    case 0:
        o->velY = 0;
        o->subState++;
        break;
    case 1:
        break;
    case 2:
        o->y.raw += o->velY << 8;
        o->velY -= 0x30;
        if (o->velY < -0x780)
            o->velY = -0x780;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801170C0);
void func_801170C0(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;

    o->h->p.whole = p->h->p.whole - 0x1e;
    o->y.p.whole = p->y.p.whole - 10;
    o->d->p.whole = p->d->p.whole - 0x32;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011710C);
void func_8011710C(GameObject *o)
{
    o->hitOffsetX = 0x33;
    o->hitWidth = 0x66;
    o->hitOffsetY = 0x1a;
    o->hitHeight = 0x34;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117130);
extern void func_80022C08(GameObject *, s32);

void func_80117130(GameObject *o)
{
    GameObject *p;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x33;
        o->hitWidth = 0x66;
        o->hitOffsetY = 0x1a;
        o->hitHeight = 0x34;
        o->state++;
        break;
    case 1:
        func_80022C08(o, 0x60);
        switch (o->subtype) {
        case 0:
            switch (o->subState) {
            case 0:
                o->velY = 0;
                o->subState++;
                break;
            case 1:
                break;
            case 2:
                o->y.raw += o->velY << 8;
                o->velY -= 0x30;
                if (o->velY < -0x780) o->velY = -0x780;
                break;
            }
            break;
        case 1:
            p = (GameObject *)o->unk90;
            o->h->p.whole = p->h->p.whole - 0x1e;
            o->y.p.whole = p->y.p.whole - 10;
            o->d->p.whole = p->d->p.whole - 0x32;
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer8(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801172E8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117390);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801173FC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011767C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117790);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801178B8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117A74);


extern void *D_8013D944[];
extern void func_80117BBC(GameObject *);

void func_80117A74(GameObject *o)
{
    s16 t;

    switch (o->state) {
    case 0:
        t = o->cooldownTimer;
        if (t != 0) {
            o->cooldownTimer = t - 1;
            break;
        }
        o->state++;
        o->tpage = 0xb;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013D944[o->subtype];
        if (o->subtype == 2) {
            o->unkB8 = -2;
            S16(o, 0xc8) = -2;
            o->unkB6 = 0;
            o->unkB4 = 0;
            S16(o, 0xc0) = 2;
            (*(s16*)&o->unkBE) = 0;
            o->unkBC = 0;
            S16(o, 0xc6) = 0x20;
            S16(o, 0xc4) = 0;
            S16(o, 0xd0) = 2;
            S16(o, 0xce) = 0x20;
            S16(o, 0xcc) = 0;
        }
        break;
    case 1:
        switch (o->subtype) {
        case 1:
            func_80117BBC(o);
            break;
        case 2:
            func_80022E44(o);
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

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117BBC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117C4C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117C60);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117CE8);
extern s16 D_8007DB88[];
extern s16 D_8007D988[];
extern GameObject *allocObjectLayer3(void);

void func_80117CE8(s16 x, s16 y, s32 z)
{
    s32 i;
    GameObject *e;
    s32 w;
    s32 j;

    for (i = 0; i < 32; i++) {
        e = allocObjectLayer3();
        if (e) {
            j = i >> 1;
            e->type = 0xe;
            e->active = 1;
            e->h->raw = x << 16;
            e->y.raw = y << 16;
            e->d->raw = z << 16;
            e->timer = 0x40;
            w = (i & 1) << 3;
            e->subtype = 1;
            e->unkC = 0;
            e->cooldownTimer = w;
            if (j & 1) e->cooldownTimer = w + 8;
            e->unk84 = j << 4;
            e->animFrame = 1;
            e->unk88 = 0;
            e->h->raw += D_8007DB88[e->unk84] << 5;
            e->y.raw += D_8007D988[e->unk84] << 5;
        }
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117E10);


extern void *D_8013DA0C[];
extern void readAnimFrameCount(GameObject *);
extern void pushDrawListCapped(GameObject *);

void func_80117E10(GameObject *o)
{
    u8 h;

    switch (o->state) {
    case 0:
        if (o->subtype < 2) {
            o->tpage = 8;
        } else {
            o->tpage = 10;
        }
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013DA0C[o->subtype];
        h = (*(u8*)&o->hitOffsetX) >> 4;
        o->state = o->state + 1;
        if (h < 12) {
            o->buffSize = (h << 10) + 0x1000;
        } else {
            o->buffSize = 0x1000 - ((h - 11) << 9);
        }
        h = (*(u8*)&o->hitOffsetX) & 0xf;
        if (h < 8) {
            o->unk8C = h << 2;
        } else {
            o->unk8C = (-((s32)(h - 7) << 5) / 8) & 0xff;
        }
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117F6C);

extern s16 D_8013B760[];
extern s16 D_8013B73C[];
extern void **D_8013B6FC[];

void func_80117F6C(GameObject *o)
{
    u8 v;

    switch (o->state) {
    case 0:
        o->tpage = 9;
        o->unkD = 0;
        if (D_8013B760[o->subtype]) {
            o->unkD = 1;
            o->clut = GetClut(D_8013B73C[o->subtype], D_8013B760[o->subtype] + o->unkC);
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = *D_8013B6FC[o->subtype];
        o->state++;
        v = *(u8 *)&o->hitOffsetX >> 4;
        if (v < 12)
            o->buffSize = (v << 10) + 0x1000;
        else
            o->buffSize = 0x1000 - ((v - 11) << 9);
        v = *(u8 *)&o->hitOffsetX & 0xf;
        if (v < 8)
            o->unk8C = v << 2;
        else
            o->unk8C = (u8)(-((s32)(v - 7) << 5) / 8);
        break;
    case 1:
        func_80022C08(o, 0xf0);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801180F8);

extern void *D_8013D928[];

void func_801180F8(GameObject *o)
{
    GameObject *e;
    s32 t;

    t = o->state;
    switch (t) {
    case 0:
        t = o->subtype;
        switch (t) {
        case 0:
            if ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1) break;
            if (--o->timer == -1) goto done;
            e = allocObjectLayer3();
            if (e == 0) break;
            e->active = 1;
            e->type = 0x1f;
            e->subtype = 1;
            e->h->raw = o->h->raw;
            e->h->p.whole += o->timer - 0x10;
            e->y.raw = o->y.raw;
            e->d->raw = o->d->raw;
            e->unkC = nextRandom() & 3;
            e->unkAC = o->timer / 4;
            e->timer = (nextRandom() & 0x1f) + 0x30;
            e->animFrame = nextRandom() & 1;
            break;
        done:
            o->subtype = 1;
            o->unkC = 0;
            o->unkAC = 0;
            o->timer = 0x5a;
            o->animFrame = 0;
            break;
        case 1:
            o->tpage = 8;
            o->unkA = 2;
            o->unkD = 0;
            *(s8 *)&o->unkF = -10;
            o->anim = D_8013D928[o->unkAC];
            o->spriteBank = SCRATCHPAD.sprData[3];
            o->subState = 0;
            o->state++;
            switch (o->unkC) {
            case 0:
                o->velH = 0x200;
                o->velX = -4;
                break;
            case 1:
                o->velH = 0x180;
                o->velX = -2;
                break;
            case 2:
                o->velH = 0x100;
                o->velX = -2;
                break;
            case 3:
                o->velH = 0x80;
                o->velX = -1;
                break;
            }
            o->velV = 0;
            o->velY = 0x60;
            break;
        }
        break;
    case 1:
        o->y.raw += o->velV << 8;
        switch (o->unkAC) {
        case 0:
            if (o->velV < 0x200) o->velV += o->velY;
            break;
        case 1:
            if (o->velV < 0x180) o->velV += o->velY;
            break;
        case 2:
            if (o->velV < 0x100) o->velV += o->velY;
            break;
        }
        if (o->animFrame & 1) o->h->raw += o->velH << 8;
        else o->h->raw -= o->velH << 8;
        o->velH += o->velX;
        switch (o->subState) {
        case 0:
            if (func_80022E44(o)) o->subState++;
            break;
        case 1:
            if (o->timer < 0x1e) {
                if ((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 1) func_80022E44(o);
            } else {
                if (!func_80022E44(o)) o->state = 3;
            }
            if (--o->timer == -1) o->state = 3;
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118534);
extern GameObject *allocObjectLayer3(void);

void func_80118534(s32 x, s32 y, s32 z)
{
    GameObject *e = allocObjectLayer3();
    if (e) {
        e->active = 1;
        e->type = 0x1f;
        e->subtype = 0;
        e->h->raw = x << 16;
        e->y.raw = y << 16;
        e->d->raw = z << 16;
        e->timer = 0xc;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801185B8);

typedef struct P_185B8 { char p[0x24]; s32 w24; char q[0x3c - 0x28]; s32 w3c; char r[0x64 - 0x40]; s32 w64; } P_185B8;
extern s32 D_8013D9FC[];
extern s32 tickAnimation(char *);

void func_801185B8(char *o)
{
    u8 s = o[4];
    switch (s) {
    case 0:
        o[4] = s + 1;
        *(s16 *)(o + 0x1e) = 8;
        o[0xa] = 1;
        *(s32 *)(o + 0x64) = 0x1400;
        *(s8 *)&o[0xf] = -0x14;
        o[0xd] = 0x80;
        ((P_185B8 *)o)->w3c = SCRATCHPAD.sprData[3];
        ((P_185B8 *)o)->w24 = D_8013D9FC[(u8)o[3]];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        if (tickAnimation(o) != 0)
            o[4] = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801186AC);
extern GameObject *allocObjectLayer3(void);

void func_801186AC(u8 sub, s32 x, s32 y, s32 z)
{
    GameObject *n = allocObjectLayer3();

    if (n != 0) {
        n->active = 1;
        n->type = 0x2d;
        n->subtype = sub;
        n->h->raw = x << 16;
        n->y.raw = y << 16;
        n->d->raw = z << 16;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118734);
extern void func_80118A30(GameObject *);

void func_80118734(GameObject *o)
{
    GameObject *e;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            if (!((D_1F8001F8 + D_1F800198) & 7)) break;
            if (--o->timer == -1) {
                o->state = 3;
                break;
            }
            e = allocObjectLayer3();
            if (e) {
                e->unkAC = o->timer & 1;
                e->subtype = 1;
                e->timer = 0x3c;
                e->unkC = (*(u8 *)&D_1F8001F8 + D_1F800198) & 3;
                e->h->raw = o->h->raw + 0x100000;
                e->y.raw = o->y.raw - 0x180000;
                e->d->raw = o->d->raw;
                func_80118A30(e);
            }
            break;
        case 1:
            o->state = 1;
            func_80118A30(o);
            o->animFrame = (D_1F8001F8 + D_1F800198) & 1;
            o->x.p.whole += (nextRandom() & 3) << 3;
            o->y.p.whole += (nextRandom() & 3) * 12;
            switch (o->unkC) {
            case 0:
                o->velH = 0x180;
                o->velX = -2;
                break;
            case 1:
                o->velH = 0x100;
                o->velX = -2;
                break;
            case 2:
                o->velH = 0x80;
                o->velX = -1;
                break;
            }
            o->velV = -0x180;
            o->velY = 0x10;
            break;
        }
        break;
    case 1:
        if (!func_80022E44(o)) {
            o->state = 3;
            break;
        }
        o->y.raw += o->velV << 8;
        o->velV += o->velY;
        if (o->animFrame & 1) o->h->raw += o->velH << 8;
        else o->h->raw -= o->velH << 8;
        o->velH += o->velX;
        if (o->animFrame & 1) o->unk8C = (o->unk8C + 4) & 0xff;
        else o->unk8C = (o->unk8C - 4) & 0xff;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118A30);

extern void *D_8013DACC[];

void func_80118A30(GameObject *o)
{
    o->active = 1;
    o->type = 0x3d;
    o->unkA = 2;
    *(s8 *)&o->unkF = -0x1e;
    o->tpage = 0xb;
    o->unkB = 0;
    o->unkD = 0;
    o->spriteBank = SCRATCHPAD.sprData[3];
    o->anim = D_8013DACC[o->unkAC];
    readAnimFrameCount(o);
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118AA0);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118BC4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118E20);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118F44);



extern void *D_8013D8B8[];
extern u16 D_1F80016E[];
typedef struct { s16 x; } SX_18F44;
extern void removeItemFromInventory(s32, s32);

void func_80118F44(GameObject *o)
{

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 10;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013D8B8[0];
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
        o->unk38 = o->d->p.whole;
        o->unkA = 2;
        o->unk8C = 0;
        *(s8 *)&o->unkF = -10;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (D_8009BC98.unk10 && D_8009BC98.unk11 == 0xd) {
                o->h->p.whole = (*(SX_18F44 *)&D_1F80016A).x;
                o->y.p.whole = D_1F80016E[0] - 0x20;
                o->d->p.whole = D_1F800172[0];
                o->subState++;
            }
            break;
        case 1:
            func_80022E44(o);
            o->timer = 0x3c;
            o->velV = 0x180;
            o->subState++;
            o->velH = ((0xb5e - (*(SX_18F44 *)&D_1F80016A).x) << 8) / 32;
            if ((*(SX_18F44 *)&D_1F80016A).x < 0xb5e)
                o->animFrame = 0;
            else
                o->animFrame = 1;
            o->unk88 = 0;
            break;
        case 2:
            func_80022E44(o);
            if (o->unk88 < 0x41) {
                o->h->raw += o->velH << 8;
                o->y.raw -= (D_8007DB88[o->unk88 & 0xff] * o->velV) >> 4;
                o->unk88 += 2;
            }
            if (o->animFrame)
                o->unk8C += 4;
            else
                o->unk8C -= 4;
            func_80118E20(o);
            if (--o->timer == -1)
                o->subState++;
            break;
        case 3:
            D_8009C068.unk721 = 1;
            removeItemFromInventory(ITEM_FLOWERTEARS, 1);
            o->state = 3;
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

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_1", func_80115274);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011923C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119404);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119510);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119798);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119878);
extern void (*D_8013B784[])(GameObject *);
extern void (*D_8013B798[])(GameObject *);
extern void pushDrawListLayer4(GameObject *o);

void func_80119878(GameObject *o)
{
    GameObject *p;

    if (o->subtype != 0) return;
    D_8013B784[o->subState](o);
    D_8013B798[o->subState]((GameObject *)o->unk94);
    ((GameObject *)o->unk94)->step = o->step;
    p = (GameObject *)o->unk94;
    if (p->visible == 0) {
        p->visible = 1;
        pushDrawListLayer4((GameObject *)o->unk94);
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011992C);

typedef struct { s16 x, y, z, pad; } SV_1992C;
typedef struct { char p[0xb4]; SV_1992C v[4]; } TX_1992C;

extern void *D_8013D934;

void func_8011992C(GameObject *o)
{
    GameObject *p;
    s16 dx, dy;
    SV_1992C *v;

    if (o->step != 0) return;
    o->y.raw = o->unk34;
    o->h->raw = o->unk30;
    o->velH = 0;
    o->velV = 0;
    o->velX = 0;
    o->velY = 0;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk74 = 0;
    if (o->subtype) {
        o->anim = D_8013D934;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        v = ((TX_1992C *)o)->v;
        if (SCRATCHPAD.unk1C8 & 1) {
            v[0].y = 0;
            v[0].x = 0;
            v[1].y = 0;
            v[1].x = 0;
            v[2].y = dy;
            v[2].x = 0;
            v[3].y = dy;
            v[3].x = 0;
            v[0].z = dx - o->hitOffsetX;
            v[1].z = dx + o->hitWidth;
            v[2].z = dx - o->hitOffsetX;
            v[3].z = dx + o->hitWidth;
        } else {
            v[0].y = 0;
            v[0].z = 0;
            v[1].y = 0;
            v[1].z = 0;
            v[2].y = dy;
            v[2].z = 0;
            v[3].y = dy;
            v[3].z = 0;
            v[0].x = dx - o->hitOffsetX;
            v[1].x = dx + o->hitWidth;
            v[2].x = dx - o->hitOffsetX;
            v[3].x = dx + o->hitWidth;
        }
    }
    o->step++;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119A7C);
extern s16 D_8007D988[];

s32 func_80119A7C(GameObject *o)
{
    o->h->raw = o->unk30 + ((D_8007D988[((u8 *)&o->unk84)[1]] * *(s8 *)&o->unkA6) << 4);
    o->unk84 += o->velH;
    o->velH += o->velX;
    if (o->velH == o->unk74) {
        if (--o->timer == -1) {
            o->unk74 = 0;
            o->velH = 0;
            o->velX = 0;
            o->unk84 = 0;
            return 1;
        }
        o->velX *= -1;
        o->velH /= 2;
        o->unk74 /= 2;
        o->velX /= 2;
    } else if (o->velH == -o->unk74) {
        o->velX *= -1;
    }
    return 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119BAC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A24C);

typedef struct { s16 x, y, z, pad; } V8011AEFC_1A24C;

#define a ((V8011AEFC_1A24C *)&o->unkB4)
#define b ((V8011AEFC_1A24C *)&o->unkBC)
#define c ((V8011AEFC_1A24C *)((char *)o + 0xc4))
#define d ((V8011AEFC_1A24C *)((char *)o + 0xcc))

void func_8011A24C(GameObject *o)
{
    GameObject *p;
    s16 dx, dy;
    s32 v;

    switch (o->step) {
    case 0:
        {GameObject *q;
        q = (GameObject *)o->unk90;
        o->step++;
        o->unkAC = 0;
        dy = q->y.p.whole - o->y.p.whole;
        dx = q->h->p.whole - o->h->p.whole;}
        if (SCRATCHPAD.unk1C8 & 1) {
            a->y = 0;
            a->x = 0;
            b->y = 0;
            b->x = 0;
            c->y = dy;
            c->x = 0;
            d->y = dy;
            d->x = 0;
            a->z = dx - o->hitOffsetX;
            b->z = dx + o->hitWidth;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            a->y = 0;
            a->z = 0;
            b->y = 0;
            b->z = 0;
            c->y = dy;
            c->z = 0;
            d->y = dy;
            d->z = 0;
            a->x = dx - o->hitOffsetX;
            b->x = dx + o->hitWidth;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 1:
        o->unk88 = ((GameObject *)o->unk90)->unk88;
        v = (o->unk88 >> 8) & 0xff;
        if (v < 0x60) {
            o->hitOffsetX = 3;
            o->hitWidth = 3;
        } else if (v < 0xa0) {
            o->hitOffsetX = 4;
            o->hitWidth = 3;
        } else {
            o->hitOffsetX = 4;
            o->hitWidth = 4;
        }
    case 2:
        p = (GameObject *)o->unk90;
        o->unkAC = 0;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 3:
        p = (GameObject *)o->unk90;
        o->hitOffsetX = 4;
        o->hitWidth = 4;
        o->unkAC = 3;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 4:
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 5:
        o->unkAC = 0;
        break;
    }
    o->anim = ((void **)&D_8013D934)[o->unkAC];
}
#undef a
#undef b
#undef c
#undef d

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A4B4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A650);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A7C0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A7E8);

typedef struct { s16 x, y, z, pad; } SV_1A7E8;
#define V(o) ((SV_1A7E8 *)((char *)(o) + 0xb4))

void func_8011A7E8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->anim = D_8013D934;
    {
        GameObject *e = (GameObject *)o->unk90;
        s16 dy = e->y.p.whole - o->y.p.whole;
        s16 dx = e->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            V(o)[0].y = 0;
            V(o)[0].x = 0;
            V(o)[1].y = 0;
            V(o)[1].x = 0;
            V(o)[2].y = dy;
            V(o)[2].x = 0;
            V(o)[3].y = dy;
            V(o)[3].x = 0;
            V(o)[0].z = dx - o->hitOffsetX;
            V(o)[1].z = dx + o->hitWidth;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[0].y = 0;
            V(o)[0].z = 0;
            V(o)[1].y = 0;
            V(o)[1].z = 0;
            V(o)[2].y = dy;
            V(o)[2].z = 0;
            V(o)[3].y = dy;
            V(o)[3].z = 0;
            V(o)[0].x = dx - o->hitOffsetX;
            V(o)[1].x = dx + o->hitWidth;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 1:
    {
        GameObject *e = (GameObject *)o->unk90;
        s16 dy = e->y.p.whole - o->y.p.whole;
        s16 dx = e->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 2:
        break;
    }
}
#undef V

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A974);
extern s16 D_8007DB88[];

#define RESET(o) \
    (o)->y.raw = (o)->unk34; \
    (o)->h->raw = (o)->unk30; \
    (o)->velH = 0; \
    (o)->velV = 0; \
    (o)->velX = 0; \
    (o)->velY = 0; \
    (o)->unk84 = 0; \
    (o)->unk88 = 0; \
    (o)->unk74 = 0;

void func_8011A974(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        RESET(o);
        o->velV = 0x200;
        break;
    case 1:
        o->unk88 += 4;
        if (o->unk88 & 0x80) {
            o->step++;
            break;
        }
        o->y.raw -= (D_8007DB88[o->unk88 & 0xff] * o->velV) >> 4;
        break;
    case 2:
        o->subState = 0;
        o->step = 0;
        RESET(o);
        break;
    }
}
#undef RESET

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AA9C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AAF4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011ACA8);
extern s16 D_8007DB88[];

void func_8011ACA8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velV = 0;
        o->velH = 0;
        o->velV = 0x200;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->velY = -0x80;
        o->timer = 0;
        o->step++;
        break;
    case 1:
        if (o->timer > 0) {
            o->step = 2;
            break;
        }
        o->unk88 += 4;
        if ((o->unk88 & 0xff) == 0) {
            o->velV += o->velY;
            o->y.raw = o->unk34;
            o->timer++;
        }
        o->y.raw += (D_8007DB88[(u8)o->unk88] * o->velV) >> 4;
        if (o->unk6A == 1) {
            o->step++;
        }
        break;
    case 2:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->timer = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AE2C);

typedef struct {
    char p[0xb4];
    s16 b4, b6, b8, ba, bc, be, c0, c2, c4, c6, c8, ca, cc, ce, d0;
} E_1AE2C;

void func_8011AE2C(GameObject *o)
{

    switch (o->step) {
    case 0: {
        GameObject *p;
        s16 dy, dx;
        o->step++;
        *(s16 *)((char *)o + 0xac) = 0;
        o->anim = D_8013D934;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            o->unkB6 = 0;
            ((E_1AE2C *)o)->b4 = 0;
            ((E_1AE2C *)o)->be = 0;
            o->unkBC = 0;
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->c4 = 0;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->cc = 0;
            o->unkB8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->c0 = dx + o->hitWidth;
            ((E_1AE2C *)o)->c8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->d0 = dx + o->hitWidth;
        } else {
            o->unkB6 = 0;
            o->unkB8 = 0;
            ((E_1AE2C *)o)->be = 0;
            ((E_1AE2C *)o)->c0 = 0;
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->c8 = 0;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->d0 = 0;
            ((E_1AE2C *)o)->b4 = dx - o->hitOffsetX;
            o->unkBC = dx + o->hitWidth;
            ((E_1AE2C *)o)->c4 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 1: {
        GameObject *p;
        s16 dy, dx;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if (SCRATCHPAD.unk1C8 & 1) {
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->c8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->d0 = dx + o->hitWidth;
        } else {
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->c4 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 2:
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AFBC);

void func_8011AFBC(GameObject *o)
{
    switch (o->step) {
    case 0:
        switch (GAME.selectedSection) {
        case 0:
        case 1:
            o->step++;
            break;
        case 2:
            o->unk88 = 0x800;
            o->step = 4;
            break;
        }
        break;
    case 1:
        if (SCRATCHPAD.unk168[1].p.whole >= -0x140 && (u16)(SCRATCHPAD.unk168[0].p.whole - 0xb23) < 0x95)
            o->step++;
        break;
    case 2:
        o->unk88 = (o->unk88 + 8) & 0xfff;
        if (o->unk88 >= 0x600) o->step++;
        break;
    case 3:
        if (o->visible == 0 && ((GameObject *)o->unk94)->visible == 0) {
            o->unk88 = 0;
            o->step = 1;
        }
        break;
    case 4:
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B0D4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B1CC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B4A8);
extern u16 D_8013B7BC[];
extern u16 D_8013B7BE[];
extern u16 D_8013B7C0[];
extern u16 D_8013B7C2[];
extern void freeObjectLayer4(GameObject *);

void func_8011B4A8(GameObject *o)
{

    switch (o->state) {
    case 0:
        o->hitOffsetX = -D_8013B7BC[0];
        o->hitWidth = o->hitOffsetX + D_8013B7BE[0];
        o->hitOffsetY = -D_8013B7C0[0];
        o->hitHeight = o->hitOffsetY + D_8013B7C2[0];
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (D_8009C068.event_A4 != 0) {
            o->state = 3;
        } else {
            o->state = 1;
        }
        break;
    case 1:
        if (D_8009C068.unk721 >= 4) {
            o->state = 3;
        } else {
            func_80022C08(o, 0x92);
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B5C4);
void func_8011B5C4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (o->subtype == 0) {
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0x44;
            o->hitHeight = 0x60;
        } else {
            o->hitOffsetX = 0x18;
            o->hitWidth = 0x30;
            o->hitOffsetY = 0;
            o->hitHeight = 0x50;
        }
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B6A4);
extern Fix16 *D_800A53DC_Fix16PtrArr[] asm("D_800A53DC");
extern s32 func_80022D3C(GameObject *, s32);
extern void playSFX(s32);
extern s16 fixedMulSin2(s32, s32);

void func_8011B6A4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = 10;
        o->hitOffsetY = 10;
        o->hitWidth = 0x14;
        o->hitHeight = 0x14;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            o->subState++;
            o->unkB4 = 0;
            o->unk8C = 0;
            o->touchFlag = 0;
        case 1:
            if (func_80022D3C(o, 0x60)) {
                if (o->touchFlag) {
                    if ((u16)o->unkB4 == 0) playSFX(0x4b);
                    if (o->unk8C >= -0x6f) {
                        o->unk8C -= (u16)o->unkB4 >> 8;
                        o->unkB4 += 0x10;
                    }
                }
                { s32 t = ((s16 (*)(s32, s32))fixedMulCos2)(((o->unk8C >> 4) + 0x40) & 0xff, 0x19a) + 0x10; o->unk30 = o->h->p.whole + t; }
                o->unk34 = o->y.p.whole + fixedMulSin2(((o->unk8C >> 4) + 0x40) & 0xff, 0x19a);
                o->unk38 = D_800A53DC_Fix16PtrArr[0]->p.whole;
            }
            if ((*(Fix16 **)&PLAYER.obj.h)->p.whole < 0x53c) o->subState++;
            break;
        case 2:
            if (func_80022D3C(o, 0x24)) o->subState = 0;
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B8C4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B91C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BA78);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BD20);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BFF8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C218);
typedef struct {
    s16 x0, x2, x4, x6, x8, xa, xc, n;
    s16 w10, w12, w14, w16, w18;
    u8 b1a, b1b;
    s16 w1c, w1e, w20;
} Seg_1C218;

typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe;
} Ctx_1C218;

extern Seg_1C218 D_800A37D8[];
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_8011C218(Ctx_1C218 *c)
{
    Seg_1C218 *s = &D_800A37D8[c->f4];
    Seg_1C218 *n;
    s32 a;
    register s32 b asm("$17");
    register s32 h asm("$2");
    s32 d;
    s32 e;
    s32 k;
    register s32 v asm("$2");
    s32 f0;
    s32 kp;
    s32 a2;
    s32 a3;
    s32 b2;
    s32 w;
    s16 t;
    s16 dx;
    s16 dy;

    f0 = c->f0; a = ((c->f2 - f0) * s->w20) / c->f2;
    w = s->w10;
    kp = c->f0 * w;
    b = kp / c->f2;
    a2 = (kp * (100 - a) / 100) / c->f2;
    n = &D_800A37D8[c->f4 + 1];
    dy = n->x2 - s->x2;
    dx = n->x0 - s->x0;
    h = (0x800 - w) / 2;
    t = h;
    b2 = h + b;
    a3 = h + a2;
    dx = (dx << 12) / rcos(t);
    d = rcos(t) - rcos((s16)b2);
    k = dx / 2;
    c->fa = (d * k) / 4096;
    e = rsin(t) - rsin((s16)a3);
    e = -((e * k) / 4096);
    if (c->f6 == c->f4) {
        if (c->f0 < c->f8) v = ((c->f0 - c->f8) << 6) / c->f8;
        else { register s32 q asm("$3"); q = ((c->f0 - c->f8) << 6); q = q / (c->f2 - c->f8); v = q; }
        e += fixedMulCos2(v & 0xff, s->w16);
    }
    c->fc = (c->f0 * dy) / c->f2 + ((s16)e * s->w12) / 100;
    c->fe = 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C5B4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C5DC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C678);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C730);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C820);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C914);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CA8C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CB24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CC08);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CCE8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CDD8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CE24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CEAC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CF50);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CF9C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D098);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D0E4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D1A8);

void func_8011D41C(void) {
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D424);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D4F4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D6A8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D75C);
extern void func_8011D874(GameObject *, s16);

void func_8011D75C(GameObject *o)
{
    u8 *p;
    s16 n;

    switch (o->state) {
    case 0:
        p = (u8 *)o + 0xa5;
        n = *(u16 *)(o->unkA0 + 4);
        do {
            *p++ = 0;
        } while (--n);
        o->unk68 = 0;
        o->objectIndex = 0;
        o->unk6A = 0;
        o->velV = 0;
        o->unk34 = 0;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        if (SCRATCHPAD.vpx.p.whole < 0x4b0) {
            o->visible = 1;
            pushDrawListLayer4(o);
        }
        func_8011D874(o, (s16)((*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) - o->x.p.whole) >> 4);
        o->unk68 = 0;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D874);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D9CC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011DA00);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011DE38);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E210);

typedef struct {
    s16 w0[5];
    s16 a;
    s16 w0c[3];
    s16 b;
    s16 w14[3];
    s16 c;
    s16 w1c[3];
    s16 d;
    s16 w24[2];
} Seg_1E210;

extern s16 D_8007DB08[];

void func_8011E210(GameObject *o)
{
    s32 *q;
    Seg_1E210 *s;
    Seg_1E210 *e;
    s16 n, k;
    s32 i, v;
    s32 one;
    u8 *b;

    s = (Seg_1E210 *)o->unkA0;
    k = o->objectIndex;
    s = (Seg_1E210 *)((s32 *)s + 1);
    n = *(s32 *)s;
    s = (Seg_1E210 *)((s32 *)s + 1);
    if (k == 0) return;
    if (k == n - 1) return;
    e = s;
    e->c = 5;
    e->a = 0;
    e += k;
    for (i = 1; i < k; i++) {
        s32 d = k;
        v = (e->a + e->a * D_8007DB08[(i << 6) / d]) >> 12;
        (s + k - i)->a = v;
        (s + k - i)->c = v + 5;
    }
    for (i = 1; i <= k; i++) {
        e = s + k - i;
        b = (u8 *)o + 0xa5;
        b = b + (k - i);
        e->b = e[1].a;
        e->d = e[1].c;
        *b = 1;
    }
    e = &s[k];
    for (i = 1; i < n - k; i++) {
        s32 d = k;
        v = (e->a + e->a * D_8007DB08[(i << 6) / (n - d)]) >> 12;
        { Seg_1E210 *m = s + d + i; m->a = v; m->c = v + 5; }
    }
    for (i = 1; one = 1, i < n - (k + one); i++) {
        e = s + k + i;
        b = (u8 *)o + 0xa5;
    asm("");
        b += k + i;
        e->b = e[1].a;
        e->d = e[1].c;
        *b = 2;
    }
    e = s + (n - 1);
    e->d = 5;
    e->b = 0;
    *((u8 *)o + n + 0xa4) = 2;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E4F8);

extern void *D_8013D960[];

void func_8011E4F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 8;
        o->unkD = 0;
        o->anim = D_8013D960[o->subtype];
        o->spriteBank = SCRATCHPAD.sprData[3];
        switch (o->subtype) {
        case 0 ... 1:
            o->hitWidth = 0x10;
            o->hitOffsetY = 2;
            o->hitOffsetX = 8;
            o->hitHeight = 0x72;
            break;
        case 2:
            o->active = 2;
            break;
        }
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022C08(o, 0x60);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E600);

typedef struct { s8 anim, z, ang, rad; } E4_1E600;

extern u8 D_800A5399[];
extern Fix16 * D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
extern Fix16 * D_800A53DC__1E600[];
extern s32 D_800A5424[];
extern u8 D_800A53A7[];
extern u8 D_8009BCED;
extern E4_1E600 D_80011F90[];
extern void *D_8013DA84;
extern void *D_8013DA80;
extern s32 fixedMulCos(s16 a, s32 b);
extern s32 fixedMulSin(s16 a, s32 b);
extern void printInfoMessage(s32, s32);
extern void addItemToInventory(s32, s32, s32);

void func_8011E600(GameObject *o)
{
    E4_1E600 *e;
    s16 c;
    s32 x, y;
    u16 u;

    o->visible = D_800A5399[0];
    switch (o->step) {
    case 0:
        c = D_8009BCED & 1;
        if (D_8009BC98.unk10) {
            switch (D_8009BC98.unk11) {
            case 5:
            case 7:
            case 0xe:
            case 0x7c:
            case 0x97:
            case 0x98:
                c++;
            }
        }
        if (c) {
            printInfoMessage(MSG_EFFECT_NOTICE, MSG_TYPE_INFO);
            o->state = 3;
            o->subState = 0;
            o->step = 0;
        }
        e = &D_80011F90[((s8 *)&D_80012014)[*(*(u16 **)&PLAYER.obj.anim)]];
        if (D_8009C068.unk54d == 0) {
            o->state = 3;
            break;
        }
        if (D_8009C068.unk54d == 1) o->anim = D_8013DA84;
        else o->anim = D_8013DA80;
        if (o->animFrame & 1) {
            u = D_800A5424[0] + 0x80 - e->ang;
            c = u; c &= 0xff;
        } else {
            u = e->ang + D_800A5424[0];
            c = u; c &= 0xff;
        }
        y = fixedMulCos(c, e->rad);
        x = fixedMulSin(c, e->rad);
        o->visible = D_800A5399[0];
        o->animFrame = ((u16 *)&D_800A53C6)[0] & 1;
        o->h->p.whole = D_800A53D8_Fix16PtrArr[0]->p.whole + y;
        o->y.p.whole = D_800A53AE[0] + x;
        o->d->p.whole = D_800A53DC__1E600[0]->p.whole;
        o->unk8C = D_800A5424[0];
        o->unkF = D_800A53A7[0] + e->z;
        o->category |= 0x80;
        readAnimFrameCount(o);
        break;
    case 1:
        e = &D_80011F90[((s8 *)&D_80012014)[*(*(u16 **)&PLAYER.obj.anim)]];
        if (o->animFrame & 1) {
            u = D_800A5424[0] + 0x80 - e->ang;
            c = u; c &= 0xff;
        } else {
            u = e->ang + D_800A5424[0];
            c = u; c &= 0xff;
        }
        o->h->p.whole = D_800A53D8_Fix16PtrArr[0]->p.whole + fixedMulCos(c, e->rad);
        o->y.p.whole = D_800A53AE[0] + fixedMulSin(c, e->rad);
        o->d->p.whole = D_800A53DC__1E600[0]->p.whole;
        o->unk8C = D_800A5424[0];
        o->unkF = D_800A53A7[0] + e->z;
        if (tickAnimation(o)) {
            playSFX(9);
            {
                u8 *k = &D_8009C068.unk54d;
                s32 a;
                *k = *k + 1;
                switch (*k) {
                case 2:
                    a = 0xd;
                    goto call;
                case 3:
                    a = 0xe;
                call:
                    printInfoMessage(a, MSG_TYPE_REWARD);
                    o->step = 0;
                    break;
                default:
                    o->state = 3;
                    do { } while (0);
                    removeItemFromInventory(ITEM_BUCKET, 1);
                    addItemToInventory(ITEM_BUCKETOFWATER, 1, 1);
                    o->step = 0;
                    break;
                }
            }
        }
        break;
    }
}
