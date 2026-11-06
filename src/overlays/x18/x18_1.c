#include "common.h"
#include "game.h"
#include "x18.h"

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80115F2C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801160A0);

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011629C);
void func_8011629C(GameObject *o)
{
    if (o->subState == 0) func_80115F2C(o);
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801162CC);


extern ObjSetupHitbox D_80119800[];
extern s32 SPR_DATA[];

void func_801162CC(GameObject *o)
{
    o->hitboxX = D_80119800[o->id].b0;
    o->hitboxW = D_80119800[o->id].b1;
    o->hitboxY = D_80119800[o->id].b2;
    o->hitboxH = D_80119800[o->id].b3;
    o->tpage = D_80119800[o->id].w4;
    o->spriteBank = SPR_DATA[D_80119800[o->id].w6];
    o->anim = D_80119800[o->id].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    *(s8 *)&o->priority = -4;
    o->rotZ = 0;
    o->drawFlags = 0;
    o->drawType = 0;
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
        cullAndQueueDraw(o);
        if (o->subState == 0) func_80115F2C(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeActorObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_801164FC);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_164FC;
extern E28_164FC *D_8011986C;

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
            n = allocAreaObject();
            if (n == 0) continue;
            n->active = 1;
            n->type = 0x1a;
            n->drawType = 0x10;
            n->animFrame = p->f2;
            n->id = p->f18;
            n->param = p->f1a;
            n->x.p.whole = p->f12;
            n->y.p.whole = p->f14;
            n->z.p.whole = p->f16;
        } else {
            n = allocActorObject();
            if (n) {
                n->active = 3;
                n->type = 0x32;
                n->drawType = 0;
                n->animFrame = p->f2;
                n->id = p->f18;
                n->param = p->f1a;
                n->x.p.whole = p->f12;
                n->y.p.whole = p->f14;
                n->z.p.whole = p->f16;
                n->unkB4 = p->f4;
                n->unkB8 = p->f10;
                n->unkBA = p->fe;
                n->scaleX = p->f6;
                n->scaleY = p->f8;
                n->scaleZ = p->fa;
                n->unk7A = p->fc;
                n->parent = (s32)o;
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
        freeAreaCtrlObject(o);
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
        freeAreaCtrlObject(o);
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

extern ObjSetupHitbox D_801198AC[];

void func_80119504(GameObject *o)
{
    o->hitboxX = D_801198AC[o->id].b0;
    o->hitboxW = D_801198AC[o->id].b1;
    o->hitboxY = D_801198AC[o->id].b2;
    o->hitboxH = D_801198AC[o->id].b3;
    o->tpage = D_801198AC[o->id].w4;
    o->spriteBank = SPR_DATA[D_801198AC[o->id].w6];
    o->anim = D_801198AC[o->id].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->drawFlags = 1;
    o->clut = 0x780c;
    o->drawType = 2;
    o->rotZ = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->priority = PLAYER.obj.priority + 1;
    o->state++;
}

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_801155A8);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_8011967C);

INCLUDE_ASM("overlays/x18/nonmatchings/x18/x18_1", func_80119798);

INCLUDE_RODATA("overlays/x18/nonmatchings/x18/x18_1", func_80115608);
