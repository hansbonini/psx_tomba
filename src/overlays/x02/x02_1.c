#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80115D0C);

INCLUDE_RODATA("overlays/x02/nonmatchings/x02/x02_1", func_80115214);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_801160A0);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_801166F0);

s32 func_801166F0(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) goto ret0;
    if (D_8009BC98.unk0F | D_8009BC98.unk10) return 0;
    if ((*(GameObject *)&PLAYER).active == 2) return 0;
    if ((u16)((*(GameObject *)&PLAYER).d->p.whole - o->d->p.whole + 0x2d) >= 0x5b) return 0;
    if ((u16)((*(GameObject *)&PLAYER).h->p.whole - o->h->p.whole + (o->hitOffsetX + (*(GameObject *)&PLAYER).hitOffsetX)) > o->hitWidth + (*(GameObject *)&PLAYER).hitWidth) {
    ret0:
        return 0;
    }
    return (u16)((*(GameObject *)&PLAYER).y.p.whole - o->y.p.whole + ((*(GameObject *)&PLAYER).hitOffsetY + o->hitOffsetY)) <= (*(GameObject *)&PLAYER).hitHeight + o->hitHeight;
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116804);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116814);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116994);


typedef struct GameTask_16994 {
    s16 status;
    s16 sleepTimer;
    s32 task_id;
    s32 task_sp;
    s32 task_func;
    s32 task_gp;
    volatile u16 unk14;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 unk30;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 unk34;
    u8 unk35;
    u8 unk36;
    u8 unk37;
    u8 unk38;
    u8 unk39;
    u8 unk3a;
    u8 unk3b;
    u8 unk3c;
    u8 unk3d;
    u8 unk3e;
    u8 unk3f;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 unk45;
    u8 unk46;
    u8 unk47;
    s16 state0;
    s16 state1;
    s16 mode;
    s16 step;
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 unk56;
    u8 unk57;
    u16 timer;
    u16 unk5A;
    u16 countdown;
    u16 unk5E;
    s16 unk60;
    s16 unk62;
    u16 unk64;
    u8 unk66;
    u8 unk67;
    u8 loadGameSelected;
    u8 titleScreenSelectedOption;
    u8 unk6A;
    u8 unk6B;
    u8 unk6C;
    u8 unk6D;
    u8 unk6E;
    u8 unk6F;
} GameTask_16994;

extern u8 D_8009D6DD_U8Arr[] asm("D_8009D6DD");
extern u8 D_8009D6DE_U8Arr[] asm("D_8009D6DE");
extern u8 D_8009D6DF_U8Arr[] asm("D_8009D6DF");
extern u8 D_8009E3ED_U8Arr[] asm("D_8009E3ED");
extern u8 D_8009E3EE_U8Arr[] asm("D_8009E3EE");
extern u8 D_8009E3EF_U8Arr[] asm("D_8009E3EF");

void func_80116994(GameObject *o)
{
    s16 t;

    switch (o->step) {
    case 0:
        if (o->visible == 0) break;
        if (func_801166F0(o) == 0) break;
        o->step++;
        (*(GameObject *)&PLAYER).active = 2;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        o->timer = 10;
        break;
    case 1:
        if (--o->timer == -1) {
            (*(GameObject *)&PLAYER).active = 5;
            ((u8 *)&D_800A539C)[0] = 5;
            ((u8*)&D_8009BC98.unk0E)[0] = 0;
            (*(GameObject *)&PLAYER).visible = 0;
            ((u8 *)&D_800A539D)[0] = 0x40;
            o->timer = 0x14;
            o->step++;
            ((s16 *)&GAME.nextArea)[0] = 0xe;
            ((s16 *)&GAME.nextSection)[0] = 4;
            ((s16 *)&GAME.nextSpawnPoint)[0] = 0;
        }
        break;
    case 2:
        t = o->timer;
        if (t == 0) {
            GAME.fadeScreenControl = 3;
            ((u8*)&D_8009BC98.unk0C)[0] = 1;
            ((u8*)&SCRATCHPAD.unk3D1)[0] = 1;
            o->step++;
        } else {
            o->timer = t - 1;
        }
        o->unk74 += 0x80;
        if (o->unk74 > 0x4000) {
            o->unk74 = 0x4000;
            o->step++;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        break;
    case 3:
        o->unk74 += 0x80;
        if (o->unk74 > 0x4000) {
            o->unk74 = 0x4000;
        }
        o->unk76 = o->unk74;
        o->unk78 = o->unk74;
        if (GAME.fadeScreenControl == 1) {
            (*(GameTask_16994 **)&D_1F8001D4)->mode = 7;
            (*(GameTask_16994 **)&D_1F8001D4)->step = 0;
            D_8009D6DD_U8Arr[0] = 0xff;
            D_8009D6DE_U8Arr[0] = 0xff;
            D_8009D6DF_U8Arr[0] = 0xff;
            D_8009E3ED_U8Arr[0] = 0xff;
            D_8009E3EE_U8Arr[0] = 0xff;
            D_8009E3EF_U8Arr[0] = 0xff;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116C44);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116C78);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80116FFC);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_8011700C);

// INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_8011703C);
typedef struct { void **anims; s32 a; s32 b; } AT_1703C;
typedef struct { GameObject o; char pc0[0xd2 - 0xc0]; u16 wd2; } TX_1703C;
extern AT_1703C D_8011BAA0[];
extern void advanceAnimFrame(GameObject *, s16);

void func_8011703C(GameObject *o, s16 n, s16 k)
{
    if (n != ((TX_1703C *)o)->wd2) {
        o->anim = D_8011BAA0[o->subtype].anims[n];
        advanceAnimFrame(o, k);
        ((TX_1703C *)o)->wd2 = n;
    }
}

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_801170C0);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_801172E8);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80117378);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_80117390);

INCLUDE_ASM("overlays/x02/nonmatchings/x02/x02_1", func_801173FC);
