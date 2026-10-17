#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128590);

extern s16 D_801350DE[];
extern s32 SPR_DATA[];
void tickAnimation(GameObject *o);
s16 fixedMulSin(s32 a, s32 b);

void func_80128590(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 0;
        o->unk30 = o->h->p.whole;
        o->velX = -0x180;
        o->velY = 0x20;
        o->tpage = 1;
        o->unk34 = o->y.p.whole;
        o->unk84 = 0;
        o->subtype = 1;
        o->spriteBank = SPR_DATA[D_801350DE[0]];
        o->step++;
        break;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->unk84 = (o->unk84 + 4) & 0xfff;
        o->y.p.whole = fixedMulSin(*(s16 *)&o->unk8C, 0x40) + o->unk34;
        if (o->h->p.whole < 0x12fc) {
            o->h->p.whole = 0x12fc;
            o->velY = 0x40;
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->y.raw += o->velY << 8;
        o->velY += 8;
        if (o->velY > 0x180) o->velY = 0x180;
        if (o->y.p.whole >= -0x961) {
            o->y.p.whole = -0x962;
            o->velY = 0;
            o->timer = 0x1e;
            o->step++;
        }
        break;
    case 3:
        if (--o->timer <= 0) {
            o->timer = 0x3c;
            o->step++;
        }
        break;
    case 4:
        if (--o->timer <= 0) {
            o->subState = 0;
            o->step = 0;
            D_8009C068.unk590 = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128780);

typedef struct { s32 *p; s32 pad[2]; } E12_28780;
extern E12_28780 D_801350D4[];
void readAnimFrameCount(GameObject *o);

void func_80128780(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->animFrame = 0;
        o->velX = 0x80;
        o->velY = -0x10;
        o->unk34 = o->y.raw;
        ((u8*)&D_8009BC98.unk09)[0] = 1;
        o->anim = (void *)D_801350D4[o->subtype].p[5];
        readAnimFrameCount(o);
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->unk84 = (o->unk84 + 4) & 0xfff;
        o->y.raw = o->unk34 + (fixedMulSin(*(s16 *)&o->unk8C, 0x40) << 16);
        o->unk34 += o->velY << 8;
        o->velY -= 0x10;
        if (o->velY < -0x180) {
            o->velY = -0x180;
        }
        (*(u16 **)&PLAYER.obj.h)[1] = o->h->p.whole;
        PLAYER.obj.y.p.whole = o->y.p.whole - 0x10;
        if (o->visible == 0) {
            D_8009C068.event_23 = 2;
            o->state = 3;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128900);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_8012897C);

typedef struct { char c[12]; } V12_2897C;
typedef struct { void **anims; s32 a; s32 b; } AT_2897C;
extern Fix16 *D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
extern void advanceAnimFrame(GameObject *, s32);
extern s32 showMessageBoxDirect(s32, s32, V12_2897C *);

void func_8012897C(GameObject *o)
{
    V12_2897C b;
    GameObject *p;
    s32 t;

    switch (o->step) {
    case 0:
        if (o->unk68) {
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            b = *(V12_2897C *)&o->x;
            o->unk90 = showMessageBoxDirect(2, 0xf, &b);
            o->anim = ((AT_2897C *)&D_801350D4)[o->subtype].anims[9];
            advanceAnimFrame(o, 0);
#if defined(VERSION_SLPS_01144)
            PLAYER.obj.animFrame = 0;
            PLAYER.obj.state = 5;
            PLAYER.obj.subState = 0;
            PLAYER.obj.step = 0;
#else
            o->animFrame = o->unk68 & 1;
            t = o->h->p.whole < *(s16 *)((char *)D_800A53D8_Fix16PtrArr[0] + 2);
            PLAYER.obj.state = 5;
            PLAYER.obj.subState = 0;
            PLAYER.obj.step = 0;
            PLAYER.obj.animFrame = t;
#endif
            o->step++;
        }
        break;
    case 1:
        tickAnimation(o);
        p = (GameObject *)o->unk90;
        if (p->state == 2) {
            p->state = 3;
#if !defined(VERSION_SLPS_01144)
            o->animFrame = 1;
#endif
            o->anim = ((AT_2897C *)&D_801350D4)[o->subtype].anims[0];
            advanceAnimFrame(o, 0);
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
            PLAYER.obj.unkB2 = 0;
            PLAYER.obj.state = 1;
            PLAYER.obj.subState = 0;
            PLAYER.obj.step = 0;
            o->unk68 = 0;
            o->step = 0;
        }
        break;
    }
    if (!o->visible) o->state = 3;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128B68);
extern void tickAnimation(GameObject *);
extern void func_8012897C(GameObject *);

void func_80128B68(GameObject *o)
{
    switch (o->subState) {
    case 0:
        tickAnimation(o);
        break;
    case 1:
        func_8012897C(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128BB8);

extern void func_80127D6C(GameObject *);
extern void func_80128148(GameObject *);
extern void func_80127F58(GameObject *);
extern void func_801282F0(GameObject *);

void func_80128BB8(GameObject *o)
{
    switch ((u16)o->unkBA) {
    case 0:
        switch (o->subState) {
        case 0:
            func_80127D6C(o);
            break;
        case 1:
            goto anim;
        case 2:
            func_80128148(o);
            break;
        }
        break;
    case 1:
        switch (o->subState) {
        case 0:
            func_80127F58(o);
            break;
        case 1:
            goto anim;
        case 2:
            func_801282F0(o);
            break;
        }
        break;
    case 2:
        switch (o->subState) {
        case 0:
            goto anim;
        case 1:
            func_80128590(o);
            break;
        case 2:
            func_80128780(o);
            break;
        }
        break;
    case 3:
        switch (o->subState) {
        case 0:
            goto anim;
        case 1:
            func_8012897C(o);
            break;
        }
        break;
    case 4:
        if (!(D_8009C608.purifiedAreas & 4)) {
            if ((*(s16 **)&PLAYER.obj.h)[1] > 0xa0) (*(s16 **)&PLAYER.obj.h)[1] = 0xa0;
        }
    anim:
        tickAnimation(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128D7C);
struct GSInventory_28D7C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_28D7C { u8 weapon; u8 pants; };

typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80129A2C_28D7C;

extern T80129A2C_28D7C D_801350CC[];

void func_80128D7C(GameObject *o)
{
    o->hitOffsetX = D_801350CC[o->subtype].b0;
    o->hitWidth = D_801350CC[o->subtype].b1;
    o->hitOffsetY = D_801350CC[o->subtype].b2;
    o->hitHeight = D_801350CC[o->subtype].b3;
    o->tpage = D_801350CC[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_801350CC[o->subtype].w6];
    o->anim = D_801350CC[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unk8C = 0;
    o->unkD = 0;
    o->unkA = 0;
    if (GAME.selectedSection == 2) {
        o->anim = D_801350CC[o->subtype].anim[0];
        readAnimFrameCount(o);
        o->active = 10;
        o->unkD = 1;
        o->clut = 0x784e;
    }
    o->unk68 = 0;
    o->unkF = 0;
    o->category |= 0x80;
    o->state++;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_5", func_80128F34);

void func_80128F34(GameObject *o)
{
    u8 b = o->state;

    switch (b) {
    case 0:
        func_80128D7C(o);
        break;
    case 1:
        func_80022E44(o);
        func_80128BB8(o);
        break;
    case 2:
        if ((u16)o->unkBA == 3) {
            func_80022E44(o);
            tickAnimation(o);
            if (o->visible == 0)
                o->state = 3;
        } else {
            o->state = b + 1;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
