#include "common.h"
#include "game.h"
#include "x16.h"

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801154B8);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801154C0);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801154D0);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801155A8);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115608);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16", D_801151F8);

INCLUDE_RODATA("overlays/x16/nonmatchings/x16/x16", func_80115214);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115620);



void func_80115620(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->animFrame = 1;
        o->clut = GetClut(0x80, 0x1ff);
        o->unkA = 7;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        switch (o->subtype) {
        case 0:
        case 1:
            o->unkD = 1;
            o->tpage = 4;
            o->unkF = 2;
            o->anim = D_8011A7A8[o->unkC];
            break;
        case 2:
            o->unkD = 1;
            o->tpage = 4;
            o->unkF = 2;
            o->z.p.whole = 200;
            o->anim = D_8011A7A8[o->unkC];
            break;
        case 3:
            o->unkD = 1;
            o->tpage = 4;
            o->unkF = 2;
            o->anim = D_8011A7B8[o->unkC];
            break;
        case 4:
            o->unkD = 1;
            o->tpage = 4;
            o->unkF = 2;
            o->anim = D_8011A7C4[o->unkC];
            break;
        }
        o->spriteBank = D_1F8002D4_S32;
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->subtype != 2 || D_8009C068.event_61 == 0xff) {
            o->visible = 1;
            o->x.p.whole = o->unk30 - ((u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))[0];
            o->y.p.whole = o->unk34 - (u16)SCRATCHPAD.unk168[7].p.whole;
            pushDrawListCapped(o);
            tickAnimation(o);
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

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_8011585C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801158DC);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115970);




void func_80115970(GameObject *o)
{
    switch (o->step) {
    case 0:
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        SCRATCHPAD.unk18C = o->h->raw;
        o->timer = 60;
        o->step++;
        break;
    case 1:
        if (--o->timer == -1) {
            o->step++;
        }
        break;
    case 2:
        o->unk74 += 0x80;
        if (o->unk74 > 0x1000) {
            GameObject *p = (GameObject *)o->unk94;
            o->unk74 = 0x1000;
            o->timer = 30;
            o->active = 1;
            o->step++;
            p->unk6A = 1;
            p = (GameObject *)p->unk94;
            p->unk6A = 1;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        break;
    case 3:
        if (--o->timer == -1) {
            o->step = 0;
            o->subState++;
            D_800A38BB[0] = 6;
            D_8009C068.unk5ad = 1;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115B00);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115C70);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115D0C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80115DB0);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801160A0);

void func_801161A8(void) {
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801161B0);

void func_801161B0(GameObject *o)
{
    char pad[16];

    switch (o->step) {
    case 0:
        D_800A5440 = 8;
        break;
    case 1:
        (*(GameObject *)&PLAYER).d->p.whole--;
        break;
    case 2:
        (*(GameObject *)&PLAYER).d->p.whole++;
        break;
    }
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80116240);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_8011624C);

void func_8011624C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        break;
    case 1:
        func_801161B0(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801162D8);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_162D8;
extern E28_162D8 *D_80118024;

void func_801162D8(GameObject *o)
{
    E28_162D8 *base;
    E28_162D8 *p;
    s16 i;
    GameObject *n;

    if (D_8009C068.event_49 != 0xff) {
        o->state = 2;
        return;
    }
    base = D_80118024;
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
            if (n == 0) continue;
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
    }
}

void func_801164CC(void) {
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801164D4);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801164E0);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80116578);
typedef struct {
    s16 flags;
    s16 frame;
    s16 wb4;
    s16 w74, w76, w78, w7a;
    s16 wba, wb8;
    s16 x, y, z;
    s16 subtype;
    s16 b0c;
} E_16578;
extern E_16578 *D_80118060;

void func_80116578(GameObject *o)
{
    E_16578 *tbl = D_80118060;
    E_16578 *e;
    s16 i;
    GameObject *p;

    for (i = 0, e = tbl; e->flags != 0xff; e = &tbl[++i]) {
        if (*(volatile u16 *)&e->flags & 0x80) {
            p = allocObjectLayer4();
            if (p) {
                p->active = 1;
                p->type = 0x1a;
                p->unkA = 0x10;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
            }
        } else {
            p = allocObjectLayer2();
            if (p) {
                p->active = 3;
                p->type = 0x32;
                p->unkA = 0;
                p->animFrame = e->frame;
                p->subtype = e->subtype;
                p->unkC = e->b0c;
                p->x.p.whole = e->x;
                p->y.p.whole = e->y;
                p->z.p.whole = e->z;
                p->unkB4 = e->wb4;
                p->unkB8 = e->wb8;
                p->unkBA = e->wba;
                p->unk74 = e->w74;
                p->unk76 = e->w76;
                p->unk78 = e->w78;
                p->unk7A = e->w7a;
                p->unk90 = (s32)o;
            }
        }
    }
}

void func_80116744(void) {
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_8011674C);

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80116758);

// INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_801167F0);
void func_801167F0(GameObject *o)
{
    o->subState = 0;
    o->step = 0;
    o->state++;
}

INCLUDE_ASM("overlays/x16/nonmatchings/x16/x16", func_80116808);
