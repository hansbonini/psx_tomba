#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80115F2C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801160A0);

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011629C);
extern void func_80115F2C(GameObject *o);
void func_8011629C(GameObject *o)
{
    if (o->subState == 0) func_80115F2C(o);
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801162CC);

typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80116F7C_162CC;

extern T80116F7C_162CC D_80119800[];
extern s32 SPR_DATA[];
extern void readAnimFrameCount(GameObject *);

void func_801162CC(GameObject *o)
{
    o->hitOffsetX = D_80119800[o->subtype].b0;
    o->hitWidth = D_80119800[o->subtype].b1;
    o->hitOffsetY = D_80119800[o->subtype].b2;
    o->hitHeight = D_80119800[o->subtype].b3;
    o->tpage = D_80119800[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80119800[o->subtype].w6];
    o->anim = D_80119800[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    *(s8 *)&o->unkF = -4;
    o->unk8C = 0;
    o->unkD = 0;
    o->unkA = 0;
    o->subState = 0;
    o->category |= 0x80;
    o->state++;
    if (D_8009C068.event_49 != 0xff) o->state = 3;
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116444);

void func_80116444(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_801162CC(o);
        break;
    case 1:
        func_80022E44(o);
        if (o->subState == 0) func_80115F2C(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801164FC);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_164FC;
extern E28_164FC *D_8011986C;
extern GameObject *allocObjectLayer2(void);

void func_801164FC(GameObject *o)
{
    E28_164FC *base;
    E28_164FC *p;
    s16 i;
    GameObject *n;

    base = D_8011986C;
    i = 0;
    p = base;

    for (; p->f0 != 0xff; p = &base[++i]) {
        if (*(volatile u16 *)&p->f0 & 0x80) {
            n = allocObjectLayer4();
            if (n == 0) continue;
            n->active = 1;
            n->type = 0x1a;
            n->unkA = 0x10;
            n->animFrame = p->f2;
            n->subtype = p->f18;
            n->unkC = p->f1a;
            n->x.p.whole = p->f12;
            n->y.p.whole = p->f14;
            n->z.p.whole = p->f16;
        } else {
            n = allocObjectLayer2();
            if (n) {
                n->active = 3;
                n->type = 0x32;
                n->unkA = 0;
                n->animFrame = p->f2;
                n->subtype = p->f18;
                n->unkC = p->f1a;
                n->x.p.whole = p->f12;
                n->y.p.whole = p->f14;
                n->z.p.whole = p->f16;
                n->unkB4 = p->f4;
                n->unkB8 = p->f10;
                n->unkBA = p->fe;
                n->unk74 = p->f6;
                n->unk76 = p->f8;
                n->unk78 = p->fa;
                n->unk7A = p->fc;
                n->unk90 = (s32)o;
            }
            if ((n->unkBA & 0xffff) == 1) {
                if (D_8009C068.event_9D != 1) n->state = 2;
                if (((u8 *)&D_8009C068.event_9D)[0x19f]) n->state = 2;
            }
        }
    }
}

void func_80116728(void) {
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116730);
void func_80116730(GameObject *o)
{
    o->state = 3;
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011673C);
extern void func_801164FC(GameObject *);
extern void freeObjectUnlayered(GameObject *);

void func_8011673C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_801164FC(o);
        o->state++;
        break;
    case 1:
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801167D4);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116814);

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801169AC);
void func_801169AC(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_801167D4(o);
        if (D_8009C068.event_72 == 0xff) D_8009C068.unk679 = 1;
        else D_8009C068.unk679 = 0;
        if (D_8009C068.event_74 == 0xff) D_8009C068.unk67a = 1;
        else D_8009C068.unk67a = 0;
        o->state++;
        break;
    case 1:
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116A9C);

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_80115214);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116B20);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116C78);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80116F88);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", updatePointsBalloon);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011700C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801172E8);

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_80115274);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801172FC);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80117390);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801173FC);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011764C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011767C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80117790);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801178B8);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801178DC);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80117C4C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80117C60);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80117FD4);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80118264);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011852C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80118824);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80118A8C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80119388);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80119404);

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80119504);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T8011A1B4_19504;

extern T8011A1B4_19504 D_801198AC[];

void func_80119504(GameObject *o)
{
    o->hitOffsetX = D_801198AC[o->subtype].b0;
    o->hitWidth = D_801198AC[o->subtype].b1;
    o->hitOffsetY = D_801198AC[o->subtype].b2;
    o->hitHeight = D_801198AC[o->subtype].b3;
    o->tpage = D_801198AC[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_801198AC[o->subtype].w6];
    o->anim = D_801198AC[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unkD = 1;
    o->clut = 0x780c;
    o->unkA = 2;
    o->unk8C = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->unkF = PLAYER.obj.unkF + 1;
    o->state++;
}

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_801155A8);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011967C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80119798);

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_80115608);
