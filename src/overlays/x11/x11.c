#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801154A4);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801154CC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801155A8);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115608);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115724);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801158DC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801159D8);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115C70);

INCLUDE_RODATA("overlays/x11/nonmatchings/x11/x11", func_80115214);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115C74);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115D0C);

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80115EA8);
extern void freeObjectLayer5(GameObject *);

void func_80115EA8(GameObject *o)
{
    u8 t = o->state;

    switch (t) {
    case 0:
        initItemObject(o);
        o->velH = -0x80;
        o->velV = 0xd5;
        o->unk30 = 0x3c0000;
        o->unk34 = -0x500000;
        o->unk38 = 0;
        o->h->raw = o->unk30;
        o->y.raw = o->unk34;
        o->d->raw = o->unk38;
        o->velY = -0x500;
        o->timer = 0x3c;
        o->unkA = 0;
        o->unkF = 0;
        o->active = 4;
        o->state++;
        break;
    case 1:
        if (func_80022E44(o)) {
            o->unk30 += o->velH << 8;
            o->unk34 += o->velV << 8;
            o->unk34 += o->velY << 8;
            o->h->raw = o->unk30;
            o->y.raw = o->unk34;
            o->d->raw = o->unk38;
            if (o->velY < 0x800) o->velY += 0x28;
            if (o->velY > 0) o->active = 1;
            if (--o->timer == 0) o->state++;
        }
        break;
    case 2:
        o->state = t + 1;
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_80116064);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801160A0);

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801161A4);
extern s16 D_8007DB88[];
extern char D_800771F0[];
extern void *D_8011B750[];
extern s32 tickAnimation(GameObject *);
extern void applyAnimVelocityX(GameObject *, s32);
extern void readAnimFrameCount(GameObject *);

static inline void SetAnim_161A4(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_801161A4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->movetab = D_800771F0;
        o->unk88 = 0;
        o->velV = 0x60;
        o->unkAC = 0;
        SetAnim_161A4(o, D_8011B750[0]);
        break;
    case 1:
        tickAnimation(o);
        applyAnimVelocityX(o, o->animFrame);
        o->y.raw -= (D_8007DB88[*(u8 *)&o->unk88] * o->velV) >> 4;
        o->unk88 = (o->unk88 + 1) & 0xff;
        if (o->unk88 == 0)
            o->step++;
        break;
    case 2:
        tickAnimation(o);
        o->y.raw -= (D_8007DB88[*(u8 *)&o->unk88] * o->velV) >> 4;
        o->unk88 = (o->unk88 + 1) & 0xff;
        if (o->unk88 == 0)
            o->step++;
        break;
    case 3:
        tickAnimation(o);
        o->step = 1;
        o->animFrame = 1 - o->animFrame;
        break;
    }
}

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11", func_801162F8);
extern void freeObjectLayer2(GameObject *);
static __inline__ void setanim_162F8(GameObject *p)
{
    p->spriteBank = SCRATCHPAD.sprData[10];
    p->unkAC = 0;
    p->anim = (*(void **)&D_8011B750);
    readAnimFrameCount(p);
}
static __inline__ void setbox_162F8(GameObject *p, s16 a, s16 b, s16 c, s16 d)
{
    p->hitOffsetX = a;
    p->hitWidth = b;
    p->hitOffsetY = c;
    p->hitHeight = d;
}

void func_801162F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        setbox_162F8(o, 0x10, 0x20, 0x10, 0x20);
        o->unkD = 1;
        o->clut = 0x7952;
        o->tpage = 9;
        setanim_162F8(o);
        break;
    case 1:
        func_80022E44(o);
        func_801161A4(o);
        break;
    case 2:
    case 3:
        freeObjectLayer2(o);
        break;
    }
}
