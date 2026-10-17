#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80115774);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", D_801151F8);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", func_80115214);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801158DC);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80115C70);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80115D0C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116068);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801160A0);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116520);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116574);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116814);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", func_80115274);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_8011685C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116BB4);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116C78);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116D3C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116FD4);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80116FFC);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_8011700C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801171EC);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801172E8);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117364);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117390);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801173FC);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_8011740C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117460);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_8011767C);

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117688);
extern void tickAnimation(GameObject *);
extern void func_80117460(GameObject *);

void func_80117688(GameObject *o)
{
    switch (o->subState) {
    case 0:
        tickAnimation(o);
        break;
    case 1:
        func_80117460(o);
        break;
    }
}

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801176D8);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117790);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_8011784C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801178B8);

void func_8011792C(void) {
}

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117934);


extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");
extern u8 D_800A539E_U8Arr[] asm("D_800A539E");
extern u8 TALK_POSE[];
extern u8 D_8009BCA1_U8Arr[] asm("D_8009BCA1");
extern s16 D_1F8000F2_S16Arr[] asm("D_1F8000F2");
extern void playSFXWithVolume(s32, s32);
extern void func_800EDDDC(GameObject *, s32, s32);
extern void func_800EDEBC(GameObject *, s32);

void func_80117934(GameObject *o)
{
    s16 *s;
    s32 k;

    switch (o->step) {
    case 0:
        if (GAME.selectedSpawnPoint == 0) {
            D_800A5440 = 8;
            break;
        }
        if ((*(GameObject *)&PLAYER).d->p.whole >= 100)
            break;
        o->step = 2;
        if (D_8009C068.unk676 == 0)
            break;
        if (D_8009C068.unk6a7 != 0)
            break;
        D_800A539C_U8Arr[0] = 5;
        D_800A539D_U8Arr[0] = 100;
        D_800A539E_U8Arr[0] = 0;
        TALK_POSE[0] = 2;
        o->clut = 30;
        o->x.raw = D_1F8000EE[0];
        o->y.raw = D_1F8000F2_S16Arr[0];
        D_8009BCA1_U8Arr[0] = 1;
        playSFXWithVolume(0x28, 0x7f);
        o->step = 3;
        D_8009C068.unk6a7 = 1;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        break;
    case 1:
    case 2:
        D_800A5440 = 8;
        break;
    case 3:
        s = &D_1F8000EE;
        k = 4;
        *s = o->x.raw - k + (s32)(nextRandom() & 7);
        k = 2;
        D_1F8000F2_S16Arr[0] = o->y.raw - k + (s32)(nextRandom() & 3);
        if (--o->clut > 0)
            break;
        TALK_POSE[0] = 0;
        *s = o->x.raw;
        D_8009BCA2 = 1;
        D_8009BCA1 = 0;
        D_1F8000F2 = o->y.raw;
        o->step = 4;
        *(s16 *)((char *)o + 8) = 60;
        break;
    case 4:
        if (--o->clut > 0)
            break;
        func_800EDDDC(&(*(GameObject *)&PLAYER), 0x24, 0);
        o->clut = 60;
        o->step++;
        break;
    case 5:
        if (--o->clut > 0)
            break;
        func_800EDEBC(&(*(GameObject *)&PLAYER), 0x2b);
        o->step++;
        break;
    case 6:
        (*(GameObject *)&PLAYER).d->p.whole += 3;
        break;
    }
}

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117BC4);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117BD0);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117C4C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117C5C);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117C60);

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117E80);
typedef struct { s16 s0, s2; } S2_17E80;
typedef struct { char p[0x1e]; u8 b1e; } PLY_17E80;
extern PLY_17E80 *D_8009B698;

void func_80117E80(void)
{
    if ((u16)((*(S2_17E80 **)&PLAYER.obj.h)->s2 - 0x100) < 0x90 && D_8009C068.unk676 == 0) D_8009B698->b1e = 0;
}

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117ED0);

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117EDC);
extern void freeObjectUnlayered(GameObject *);

void func_80117EDC(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80117C5C(o);
        o->state++;
        break;
    case 1:
        if ((u16)((*(GameObject *)&PLAYER).h->p.whole - 0x100) < 0x90 && D_8009C068.unk676 == 0)
            *((u8 *)D_8009B698 + 0x1e) = 0;
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80117FBC);
typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe, f10, f12, f14, f16, f18, f1a;
} E28_17FBC;
extern E28_17FBC *D_80118DA8;
extern GameObject *allocObjectLayer2(void);

void func_80117FBC(GameObject *o)
{
    E28_17FBC *base;
    E28_17FBC *p;
    s16 i;
    GameObject *n;

    base = D_80118DA8;
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
            SCRIPT_OBJECTS[i] = n;
            n->unk90 = (s32)o;
            if (D_8009C068.event_96) {
                switch (n->subtype) {
                case 0:
                    n->x.p.whole = 100;
                    n->animFrame = 0;
                    break;
                case 1:
                    n->x.p.whole = 0xa0;
                    n->animFrame = 0;
                    break;
                }
            }
        }
    }
}

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_801181F0);

INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80118A90);

// INCLUDE_ASM("overlays/x17/nonmatchings/x17/x17", func_80118A9C);
void func_80118A9C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80117FBC(o);
        o->state++;
        if (D_8009C068.event_18 == 0xff) o->state = 3;
        break;
    case 1:
        func_801181F0(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", D_8011546C);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", D_801154B0);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", D_801154E8);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", D_80115540);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", func_801155A8);

INCLUDE_RODATA("overlays/x17/nonmatchings/x17/x17", func_80115608);
