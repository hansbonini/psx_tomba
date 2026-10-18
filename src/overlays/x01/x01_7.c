#include "common.h"
#include "game.h"
#include "x01.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_80135E84);

typedef struct { s8 a; u8 b; u8 c; s8 d; } R4_35E84;
extern u8 D_800A5399[];
extern u16 *D_800A53BC;
extern s32 D_800A5424[];
extern Fix16 *D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
extern Fix16 *D_800A53DC_Fix16PtrArr[] asm("D_800A53DC");
extern u8 D_800A53A7[];
extern s32 D_800A53FC[];
extern R4_35E84 D_80011F64[];
extern s32 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);
extern void func_80023020(GameObject *);

void func_80135E84(GameObject *o)
{
    R4_35E84 *r;
    register s32 a asm("$16"); s16 dx, dy;
    u16 u;
    register u32 t asm("$2");

    switch (o->subState) {
    case 0:
        o->subState = 1;
        break;
    case 1:
        tickAnimation(o);
        break;
    case 2:
        D_8009C213[0] = 2;
        o->subState = 5;
        o->step = 0;
        break;
    case 3:
        {register u8 v asm("$3") = D_800A5399[0];
        D_8009C213[0] = 3;
        o->active = 2;
        o->visible = v;
        o->animFrame = ((u16 *)&D_800A53C6)[0] & 1;
        o->category |= 0x80;
        *(s8 *)&o->unkF = -7;}
        asm("");
        r = &D_80011F64[((s8 *)&D_80012014)[*D_800A53BC]];
        o->anim = D_8013D8E0[r->a];
        if (r->a == 6) {
            o->animFrame ^= 1;
        }
        if (o->animFrame & 1) {
            u = D_800A5424[0] + 0x80 - (s8)r->c;
            t = u; t &= 0xff;
        } else {
            u = (s8)r->c + D_800A5424[0];
            t = u; t &= 0xff;
        }
        a = t; asm("");
        dx = fixedMulCos(a, r->d);
        dy = fixedMulSin(a, r->d);
        o->h->p.whole = D_800A53D8_Fix16PtrArr[0]->p.whole + dx;
        o->y.p.whole = D_800A53AE[0] + dy;
        o->d->p.whole = D_800A53DC_Fix16PtrArr[0]->p.whole;
        o->unk8C = D_800A5424[0];
        o->unkF = D_800A53A7[0] + r->b;
        if (D_800A53FC[0]) {
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk0E = 1;
            o->animFrame = 0;
            D_8009C213[0] = 2;
            o->timer = 0x3c;
            o->state = 2;
            o->subState = 5;
            o->step = 0;
            break;
        }
        if (D_800A53D8_Fix16PtrArr[0]->p.whole < 0x371) {
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk0E = 1;
            o->animFrame = 0;
            D_8009C213[0] = 2;
            o->timer = 0x3c;
            o->state = 2;
            o->subState = 5;
            o->step = 0;
        }
        if ((u16)(D_800A53D8_Fix16PtrArr[0]->p.whole - 0xb6f) < 0x50 && (s16)D_800A53AE[0] >= -0x118) {
            o->animFrame = 1;
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk0E = 1;
            D_8009C213[0] = 2;
            o->timer = 0x3c;
            o->state = 2;
            o->subState = 5;
            o->step = 0;
        }
        if (D_800A53DC_Fix16PtrArr[0]->p.whole > 0) {
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk0E = 1;
            D_8009C213[0] = 2;
            o->animFrame = 1;
            o->state = 2;
            o->subState = 5;
            o->step = 0;
        }
        break;
    case 5:
        switch (o->step) {
        case 0:
            o->active = 2;
            D_8009C213[0] = 2;
            o->anim = D_8013D8E0[0];
            readAnimFrameCount(o);
            o->movetab = D_8007725C;
            o->velY = -0x400;
            printInfoMessage(0x11, MSG_TYPE_INFO);
            o->step++;
        case 1:
            applyFrameVelocityX(o);
            tickAnimation(o);
            o->y.raw += o->velY << 8;
            o->velY += 0x20;
            if (o->velY > 0) {
                o->step++;
            }
            break;
        case 2:
            applyFrameVelocityX(o);
            tickAnimation(o);
            o->y.raw += o->velY << 8;
            o->velY += 0x20;
            if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x20))) {
                o->anim = D_8013D8E0[0];
                readAnimFrameCount(o);
                o->step++;
            }
            break;
        case 3:
            applyFrameVelocityX(o);
            tickAnimation(o);
            o->y.raw += o->velY << 8;
            o->velY += 0x20;
            if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) {
                o->step++;
            }
            break;
        case 4:
            if (tickAnimation(o)) {
                o->step++;
            }
            break;
        case 5:
            o->anim = D_8013D8E0[0];
            readAnimFrameCount(o);
            o->movetab = D_8007725C;
            o->velY = -0x300;
            o->animFrame = !((*(GameObject *)&PLAYER).h->p.whole < o->h->p.whole);
            func_80023020(o);
            o->step++;
            break;
        case 6:
            applyFrameVelocityX(o);
            tickAnimation(o);
            o->y.raw += o->velY << 8;
            o->velY += 0x20;
            if (o->velY > 0) {
                o->step++;
            }
            break;
        case 7:
            applyFrameVelocityX(o);
            tickAnimation(o);
            o->y.raw += o->velY << 8;
            o->velY += 0x20;
            if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) {
                o->anim = D_8013D8E0[0];
                readAnimFrameCount(o);
                o->step = 5;
            }
            break;
        }
        if (o->visible == 0) {
            o->state = 1;
            o->subState = 0;
            o->step = 0;
            o->h->p.whole = 0x9a8;
            o->y.p.whole = -0x200;
            o->d->p.whole = 0;
            o->active = 1;
            o->animFrame = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk0E = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_80136554);


void addItemToInventory(s32 a, s32 b, s32 c);

void func_80136554(GameObject *o)
{
    s32 v;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            if (D_8009C068.baronState == 0 || D_8009C068.baronState >= 3) {
                o->state = 3;
                break;
            }
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x20;
            o->unk8C = 0;
            o->tpage = 0xa;
            o->unkD = 0;
            o->category |= 0x80;
            o->spriteBank = SCRATCHPAD.sprData[3];
            o->anim = D_8013D8E8[0];
            o->unkA = 2;
            readAnimFrameCount(o);
            *(s8 *)&o->unkF = -10;
            o->state = 1;
            break;
        case 1:
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0x18;
            o->hitHeight = 0x20;
            o->unk8C = 0;
            o->tpage = 0xa;
            o->unkD = 0;
            o->category |= 0x80;
            o->spriteBank = SCRATCHPAD.sprData[3];
            o->anim = D_8013DA78;
            o->unkA = 2;
            readAnimFrameCount(o);
            o->state = 1;
            if (D_8009C068.unk54d) {
                o->state = 3;
            }
            break;
        }
        break;
    case 1:
        if ((u16)((*(u16 **)&PLAYER.obj.h)[1] - 0x8ae) < 0x200 && (nextRandom() & 0x3f) == 0) {
            if (PLAYER.obj.y.p.whole < -0x190) {
                v = 0x7f;
            } else if (PLAYER.obj.y.p.whole < -0xc8) {
                v = 0x70;
            } else {
                v = 0x60;
            }
            playSFXWithVolume(0x41, v);
        }
        if (func_80022E44(o) && o->subtype == 0) {
            tickAnimation(o);
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subtype) {
        case 0:
            func_80135E84(o);
            break;
        case 1:
            addItemToInventory(ITEM_BUCKET, 1, 1);
            D_8009C068.unk54d = 1;
            o->state = 3;
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_801367F8);
void func_801367F8(u8 sub, s16 x, s16 y, s16 z)
{
    GameObject *o = allocObjectLayer2();
    u16 t;
    if (o != 0) {
        o->active = 1;
        o->type = 0x17;
        t = (*(GameObject *)&PLAYER).animFrame;
        o->x.raw = x << 16;
        o->y.raw = y << 16;
        o->z.raw = z << 16;
        o->subtype = sub;
        o->tpage = 10;
        o->unkD = 0;
        o->animFrame = t & 1;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = (*(void **)&D_8013D8E0);
        o->unkA = 2;
        readAnimFrameCount(o);
        o->state = 2;
        o->subState = 3;
        o->step = 0;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_801368D4);


void func_801368D4(GameObject *o)
{
    GameObject *e;

    o->hitOffsetX = 10;
    o->hitWidth = 0x14;
    o->hitOffsetY = 10;
    o->hitHeight = 0x14;
    o->unkD = 0;
    o->unkA = 0;
    *(s8 *)&o->unkF = -10;
    o->animFrame = nextRandom() & 1;
    o->tpage = 8;
    o->unk84 = 0;
    {
        s32 a = SCRATCHPAD.sprData[3];
        void *b = D_8013DA50[0];
        o->spriteBank = a;
        o->anim = b;
    }
    readAnimFrameCount(o);
    switch (o->subtype) {
    case 0:
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        o->step = 0;
        break;
    case 1:
        o->category |= 0x80;
        { u8 *c = &D_8009C068.unk54f; *c = *c + 1; }
        e = (GameObject *)o->unk90;
        o->active = 2;
        o->state = 2;
        o->subState = 3;
        *(s8 *)&o->unkF = -4;
        o->step = 0;
        o->unk30 = o->h->raw - e->h->raw;
        o->unk34 = o->y.raw - e->y.raw;
        break;
    case 2:
        e = (GameObject *)o->unk90;
        o->active = 2;
        o->state = 2;
        o->subState = 4;
        o->step = 0;
        o->category |= 0x80;
        o->unk30 = o->h->raw - e->h->raw;
        o->unk34 = o->y.raw - e->y.raw;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_80136A4C);

extern s16 func_80043AB0(GameObject *, s16, s16, s16);

static __inline__ s32 inView_36A4C(GameObject *o)
{
    if ((u16)(o->y.p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2)) + 0xb0) >= 0x161) return 0;
    return (u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.unk168[0].raw + 2)) + 0x12c) < 0x259;
}

void func_80136A4C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->timer = 4;
        if (o->animFrame) o->velH = -0x100;
        else o->velH = 0x100;
        o->velY = 0;
        o->velX = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velH << 8;
        o->y.raw = o->y.raw + (D_8007D988[o->unk84] * o->velH >> 4) - 0x8000;
        o->unk84 = (o->unk84 + 2) & 0xff;
        func_80043AB0(o, o->h->p.whole, o->y.p.whole, o->animFrame);
        ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 8);
        if (o->unk84 == 0) {
            if (--o->timer == -1) {
                o->timer = 8;
                o->step++;
            }
        }
        break;
    case 2:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->step = 0;
            o->velH = -o->velH;
            o->animFrame = 1 - o->animFrame;
        }
        break;
    }
    if (o->visible == 0 && !inView_36A4C(o)) {
        o->active = 2;
        o->state = 3;
        { u8 *c = &D_8009BC98.unk29; *c = *c - 1; }
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_80136CA0);
extern GameObject PLAYER_GameObject asm("PLAYER");
extern void func_800EDDDC(GameObject *, s32, s32);
extern void setEventStarted(s32, s32, s32);

void func_80136CA0(GameObject *o)
{
    switch (o->step) {
    case 0:
        *(s8 *)&o->unkF = -7;
        o->anim = D_8013DA54;
        readAnimFrameCount(o);
        o->unk8C = 0;
        o->step++;
        o->category |= 0x80;
    case 1:
        if (D_8009C068.unk54f == 1 && !D_8009C068.item_10 && !D_8009C068.event_B2) {
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            D_8009BC98.unk0E = 1;
            o->animFrame = PLAYER_GameObject.animFrame & 1;
            func_800EDDDC(&PLAYER_GameObject, 0xd, 0);
            D_800A5424[0] = 0;
            PLAYER_GameObject.h->p.whole = o->h->p.whole;
            o->y.p.whole = PLAYER_GameObject.y.p.whole + 8;
            setEventStarted(EVENT_LEAFBUTTERFLIES, 0, 0);
            o->timer = 250;
            o->step++;
        }
        break;
    case 2:
        if (--o->timer <= 0) {
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            o->step = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_80136E34);


void func_80136E34(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;
    u16 t;

    switch (o->step) {
    case 0:
        o->animFrame = PLAYER.obj.animFrame & 1;
        t = p->h->p.whole - p->hitOffsetX;
        if (o->h->p.whole < (s16)t) {
            o->h->p.whole = t;
            o->animFrame = 0;
        }
        t = p->h->p.whole + p->hitOffsetX;
        if ((s16)t < o->h->p.whole) {
            o->h->p.whole = t;
            o->animFrame = 1;
        }
        o->velH = nextRandom() & 0xf;
        if (o->animFrame & 1) o->velH = -o->velH;
        o->velX = 0;
        o->velY = 0;
        removeItemFromInventory(ITEM_LEAFBUTTERFLY, 1);
        o->step++;
    case 1:
        tickAnimation(o);
        t = o->h->p.whole - (p->h->p.whole - p->hitOffsetX);
        if (t > p->hitWidth) o->velH = -o->velH;
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->velX += o->velH;
        o->velY -= 0x10;
        t = p->h->p.whole - p->hitOffsetX;
        if (o->h->p.whole < (s16)t) {
            o->h->p.whole = t;
        } else {
            t = p->h->p.whole + p->hitOffsetX;
            if ((s16)t < o->h->p.whole) o->h->p.whole = t;
        }
        o->unk84 = (o->unk84 + 2) & 0xff;
        t = p->y.p.whole - p->hitOffsetY;
        if (o->y.p.whole < (s16)t) {
            {
                u8 *q = &D_8009BC98.unk12;
                D_8009C618[0] = 0;
                *q = 0;
                ((u8*)&D_8009BC98.unk0F)[0] = 0;
                *q = 0;
            }
            o->y.p.whole = t;
            o->unk30 = o->h->raw - p->h->raw;
            o->unk34 = o->y.raw - p->y.raw;
            o->subState = 4;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_801370C4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_7", func_801376D4);

void func_801376D4(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_801368D4(o);
        break;
    case 1:
        func_80022E44(o);
        if (o->subState == 0) {
            func_80136A4C(o);
        }
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_80136CA0(o);
            break;
        case 1:
        case 2:
            if (o->step == 0) {
                o->anim = D_8013DA54;
                readAnimFrameCount(o);
                D_8009BCC1--;
                addItemToInventory(ITEM_LEAFBUTTERFLY, 1, 1);
                if (GAME.selectedArea == AREA01_DWARFFOREST) {
                    D_8009C272++;
                    o->state = 3;
                    o->subState = 0;
                    o->step = 0;
                } else {
                    D_8009C330++;
                    o->state = 3;
                    o->subState = 0;
                    o->step = 0;
                }
            }
            break;
        case 3:
            func_80136E34(o);
            break;
        case 4:
            func_801370C4(o);
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
