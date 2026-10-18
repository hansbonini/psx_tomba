#include "common.h"
#include "game.h"
#include "x11.h"

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801163DC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80116814);

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801168B0);


typedef struct V_168B0 { char c[12]; } V_168B0;
typedef struct { void **p; s32 pad[2]; } E12_168B0;
extern E12_168B0 D_80118F14[];
extern GameObject *showMessageBoxDirect(s32, s32, V_168B0 *);

void func_801168B0(GameObject *o)
{
    GameObject *p;
    V_168B0 v;

    switch (o->step) {
    case 0:
        if (((u8*)&D_8009BC98.unk10)[0]) {
            if (D_8009BC98.unk11 == 0x41) {
                o->subState = 3;
                o->step = 0;
                ((u8*)&D_8009BC98.unk10)[0] = 0;
            }
            break;
        }
        if (D_8009C618[0] == 3)
            break;
        if ((u16)((*(GameObject *)&PLAYER).x.p.whole - 0x40) >= 0x20)
            break;
        if ((*(GameObject *)&PLAYER).d->p.whole != 0)
            break;
        if ((SCRATCHPAD.joypad_state & SCRATCHPAD.unk3C4) == 0)
            break;
        v = *(V_168B0 *)&o->x;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_8009C618[0] = 0;
        D_800A539C_U8Arr[0] = 5;
        D_800A539D_U8Arr[0] = 0;
        D_800A539E_U8Arr[0] = 0;
        o->unkBC = o->animFrame;
        o->animFrame = o->unk68 & 1;
        o->anim = D_80118F14[o->subtype].p[2];
        readAnimFrameCount(o);
        o->unk90 = (s32)showMessageBoxDirect(2, 0xa, &v);
        o->step++;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->state != 2)
            break;
        p->state = 3;
        o->anim = D_80118F14[o->subtype].p[0];
        readAnimFrameCount(o);
        o->step++;
        break;
    case 2:
        ((u8*)&D_8009BC98.unk12)[0] = 0;
        D_800A544A_S16Arr[0] = 0;
        D_1F8001C6 = 0;
        o->animFrame = o->unkBC;
        D_800A539C_U8Arr[0] = 1;
        D_800A539D_U8Arr[0] = 0;
        D_800A539E_U8Arr[0] = 0;
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

INCLUDE_RODATA("overlays/x11/nonmatchings/x11/x11_1", func_80115274);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80116B2C);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80116C78);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80116F84);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", updatePointsBalloon);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_8011700C);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801171EC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801172E8);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117390);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801173FC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_8011740C);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801175F4);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_8011767C);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117790);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801178B8);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117AA0);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117C4C);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117C60);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117CC4);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80117EAC);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118094);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118300);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_801184E8);

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118764);

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118A48);

extern ObjSetupHitbox D_80118F0C[];

void func_80118A48(GameObject *o)
{
    o->hitOffsetX = D_80118F0C[o->subtype].b0;
    o->hitWidth = D_80118F0C[o->subtype].b1;
    o->hitOffsetY = D_80118F0C[o->subtype].b2;
    o->hitHeight = D_80118F0C[o->subtype].b3;
    o->tpage = D_80118F0C[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80118F0C[o->subtype].w6];
    o->anim = D_80118F0C[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unkD = 1;
    o->unk8C = 0;
    switch (o->subtype) {
    case 1:
        o->clut = GetClut(0xc0, 0x1e2);
        break;
    case 0:
    case 3:
        o->clut = GetClut(0xc0, 0x1e0);
        break;
    case 2:
        o->clut = GetClut(0xc0, 0x1e0);
        break;
    }
    *(s8 *)&o->unkF = -10;
    o->unkA = 0;
    o->category |= 0x80;
    o->state++;
}

INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118C0C);

void func_80118CB4(void) {
}

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118CBC);

typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_18CBC;
extern E28_18CBC *D_80118FC8;

void func_80118CBC(GameObject *o)
{
    E28_18CBC *tbl = D_80118FC8;
    E28_18CBC *e;
    s16 i;
    GameObject *p;

    for (i = 0, e = tbl; e->f0 != 0xff; e = &tbl[++i]) {
        p = allocObjectLayer2();
        if (p) {
            p->active = 3;
            p->type = 0x32;
            p->unkA = 0;
            p->animFrame = e->f2;
            p->subtype = e->f18;
            p->unkC = e->f1a;
            p->x.p.whole = e->f12;
            p->y.p.whole = e->f14;
            p->z.p.whole = e->f16;
            p->unkB4 = e->f4;
            p->unkB8 = e->f10;
            p->unkBA = e->fe;
            p->unk74 = e->f6;
            p->unk76 = e->f8;
            p->unk78 = e->fa;
            p->unk7A = e->fc;
            p->unk90 = (s32)o;
            if (i == 3) {
                if (D_8009C068.event_9D != 1) p->state = 2;
                if (((u8 *)&D_8009C068.event_9D)[0x19e] != 0) p->state = 2;
            }
        }
    }
}

void func_80118E60(void) {
}

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118E68);
void func_80118E68(GameObject *o)
{
    o->state = 3;
}

// INCLUDE_ASM("overlays/x11/nonmatchings/x11/x11_1", func_80118E74);

void func_80118E74(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80118CBC(o);
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

INCLUDE_RODATA("overlays/x11/nonmatchings/x11/x11_1", D_80115310);
