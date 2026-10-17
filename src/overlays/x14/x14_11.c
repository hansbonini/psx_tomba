#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_801212D4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_8012137C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121468);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121748);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_8012175C);


struct GSInventory_2175C { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_2175C { u8 weapon; u8 pants; };
typedef struct { void *a[3]; } AT_2175C;
extern AT_2175C D_80129374[];
extern void readAnimFrameCount(GameObject *);
extern void func_80022C08(GameObject *, s32);
extern void func_80120C90(GameObject *, s32);
extern void func_80120E90(GameObject *);
extern void func_8012104C(GameObject *);

void func_8012175C(GameObject *o)
{
    u8 s = o->state;
    GameObject *e;

    switch (s) {
    case 0:
        switch (o->subtype) {
        case 0:
        case 1:
        case 2:
            o->hitOffsetX = 10;
            o->hitWidth = 0x14;
            o->hitOffsetY = 10;
            o->hitHeight = 0x14;
            *(s8 *)&o->unkF = -9;
            o->unkA = 0;
            o->tpage = 1;
            o->unkC = 0;
            o->unkD = 0;
            o->spriteBank = SCRATCHPAD.sprData[5];
            o->unkAC = 0;
            o->anim = D_80129374[o->subtype].a[0];
            readAnimFrameCount(o);
            break;
        case 3: {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->unkA0 = *pp + q[4];
            else o->unkA0 = *pp + q[1];
            o->active = 2;
            o->unkA4 = 1;
            o->hitOffsetX = 0x50;
            o->hitWidth = 0xa0;
            o->hitOffsetY = 0x50;
            o->hitHeight = 0xa0;
            o->unkA = 0x11;
            o->unkC = 0;
            func_80120C90(o, 0);
            e = allocObjectLayer4();
            if (e) {
                e->type = 0x42;
                e->unk30 = 0x150000;
                e->unk34 = -0x40000;
                e->active = 1;
                e->subtype = 0;
                e->unk38 = -0x5a0000;
                e->h->raw = o->h->raw + e->unk30;
                e->y.raw = o->y.raw + e->unk34;
                e->d->raw = o->d->raw + e->unk38;
                e->unk90 = (s32)o;
            }
            *(s8 *)&o->unkF = 0;
            break;
        }
        case 4: {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->unkA0 = *pp + q[3];
            else o->unkA0 = *pp + q[0];
            o->active = 2;
            o->unkA4 = 1;
            o->hitOffsetX = 0x38;
            o->hitWidth = 0x70;
            o->hitOffsetY = 0x38;
            o->hitHeight = 0x70;
            o->unkA = 0x11;
            o->unkC = 0;
            func_80120C90(o, 1);
            *(s8 *)&o->unkF = 0;
            break;
        }
        }
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->state++;
        break;
    case 1:
        if (D_8009BC98.unk12 == 1) {
            func_80022E44(o);
            break;
        }
        switch (o->subtype) {
        case 0:
        case 1:
        case 2:
            func_80120E90(o);
            func_80022E44(o);
            break;
        case 3:
        case 4: {
            SVECTOR v;
            void *m = &o->unk48;
            getBaseMatrix(m);
            v.vx = o->unk84;
            v.vy = o->unk88;
            v.vz = o->unk8C;
            RotMatrix(&v, m);
            func_80022C08(o, o->hitOffsetX);
            if (D_8009BC98.unk0F != 1) func_801212D4(o);
            break;
        }
        }
        break;
    case 2:
        switch (o->subtype) {
        case 0:
        case 1:
        case 2:
            func_8012104C(o);
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121B04);

extern s16 D_1F80017A[];
extern GameObject *allocObjectLayer2(void);

s32 func_80121B04(GameObject *o)
{
    GameObject *n = allocObjectLayer2();

    if (n) {
        n->active = 1;
        n->type = 0x48;
        n->subtype = 0;
        n->unkC = 0;
        n->x.raw = (((s16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))[0] + 0xa0) << 16;
        n->y.raw = (D_1F80017A[0] - 0xf0) << 16;
        n->z.raw = o->z.p.whole << 16;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121B90);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121C00);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121CD4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121D5C);
