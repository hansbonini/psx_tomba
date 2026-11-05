#include "common.h"
#include "game.h"
#include "x14.h"

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_801212D4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_8012137C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121468);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121748);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_8012175C);


typedef struct { void *a[3]; } AT_2175C;
extern AT_2175C D_80129374[];

void func_8012175C(GameObject *o)
{
    u8 s = o->state;
    GameObject *e;

    switch (s) {
    case 0:
        switch (o->id) {
        case 0:
        case 1:
        case 2:
            o->hitboxX = 10;
            o->hitboxW = 0x14;
            o->hitboxY = 10;
            o->hitboxH = 0x14;
            *(s8 *)&o->priority = -9;
            o->drawType = 0;
            o->tpage = 1;
            o->param = 0;
            o->drawFlags = 0;
            o->spriteBank = SCRATCHPAD.sprData[5];
            o->unkAC = 0;
            o->anim = D_80129374[o->id].a[0];
            readAnimFrameCount(o);
            break;
        case 3: {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->model = *pp + q[4];
            else o->model = *pp + q[1];
            o->active = 2;
            o->modelLit = 1;
            o->hitboxX = 0x50;
            o->hitboxW = 0xa0;
            o->hitboxY = 0x50;
            o->hitboxH = 0xa0;
            o->drawType = 0x11;
            o->param = 0;
            func_80120C90(o, 0);
            e = allocObjectLayer4();
            if (e) {
                e->type = 0x42;
                e->localX = 0x150000;
                e->localY = -0x40000;
                e->active = 1;
                e->id = 0;
                e->localZ = -0x5a0000;
                e->h->raw = o->h->raw + e->localX;
                e->y.raw = o->y.raw + e->localY;
                e->d->raw = o->d->raw + e->localZ;
                e->parent = (s32)o;
            }
            *(s8 *)&o->priority = 0;
            break;
        }
        case 4: {
            s32 *pp = &SCRATCHPAD.wmdData[1];
            s32 *q = (s32 *)*pp;
            q += 1;
            if (GAME.selectedSection == 7) o->model = *pp + q[3];
            else o->model = *pp + q[0];
            o->active = 2;
            o->modelLit = 1;
            o->hitboxX = 0x38;
            o->hitboxW = 0x70;
            o->hitboxY = 0x38;
            o->hitboxH = 0x70;
            o->drawType = 0x11;
            o->param = 0;
            func_80120C90(o, 1);
            *(s8 *)&o->priority = 0;
            break;
        }
        }
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
        o->state++;
        break;
    case 1:
        if (D_8009BC98.unk12 == 1) {
            cullAndQueueDraw(o);
            break;
        }
        switch (o->id) {
        case 0:
        case 1:
        case 2:
            func_80120E90(o);
            cullAndQueueDraw(o);
            break;
        case 3:
        case 4: {
            SVECTOR v;
            void *m = &o->unk48;
            getBaseMatrix(m);
            v.vx = o->rotX;
            v.vy = o->rotY;
            v.vz = o->rotZ;
            RotMatrix(&v, m);
            func_80022C08(o, o->hitboxX);
            if (D_8009BC98.unk0F != 1) func_801212D4(o);
            break;
        }
        }
        break;
    case 2:
        switch (o->id) {
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


s32 func_80121B04(GameObject *o)
{
    GameObject *n = allocObjectLayer2();

    if (n) {
        n->active = 1;
        n->type = 0x48;
        n->id = 0;
        n->param = 0;
        n->x.raw = (((s16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))[0] + 0xa0) << 16;
        n->y.raw = (D_1F80017A_S16Arr[0] - 0xf0) << 16;
        n->z.raw = o->z.p.whole << 16;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121B90);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121C00);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121CD4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_11", func_80121D5C);
