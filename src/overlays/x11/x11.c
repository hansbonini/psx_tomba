#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801154A4);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801154CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801155A8);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115608);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115724);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801158DC);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801159D8);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115C70);

INCLUDE_RODATA("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115214);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115C74);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115D0C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80115EA8);
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

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_80116064);

INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801160A0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801161A4);
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

// INCLUDE_ASM("asm/scus_942.36/overlays/x11/nonmatchings/x11/x11", func_801162F8);
typedef struct SPADBlock_162F8 {
    u8 b0;
    u8 _pad1[0x5f];
    s16 s60;
    s16 s62;
    s16 s64;
    u8 _pad66[0xe];
    s32 i74;
    s32 i78;
    u8 _pad7c[0x10];
    s32 i8c;
    u8 _pad90[0x30];
    u8 bc0;
    u8 _padc1[0x13];
    s32 id4;
    s32 id8;
    s32 idc;
    s32 ie0;
    u8 _pade4[0x2];
    s16 se6;
    u8 _pade8[0x2];
    s16 sea;
    s32 iec;
    s32 if0;
    s32 if4;
    u8 _padf8[0x20];
    u8 b118;
    u8 _pad119[0x4b];
    void * p164;
    s32 i168;
    s32 i16c;
    s32 i170;
    s32 i174;
    u8 _pad178[0x2];
    u16 s17a;
    u8 _pad17c[0x2];
    u16 s17e;
    u8 _pad180[0x6];
    u16 s186;
    u8 _pad188[0x4];
    s32 i18c;
    s32 i190;
    u8 _pad194[0x4];
    s32 i198;
    s16 s19c;
    s16 s19e;
    u8 b1a0;
    u8 _pad1a1[0x3];
    u8 b1a4;
    u8 b1a5;
    u8 _pad1a6[0x1c];
    u8 b1c2;
    u8 _pad1c3[0x1];
    u8 b1c4;
    u8 b1c5;
    s16 s1c6;
    u16 s1c8;
    u8 _pad1ca[0x2];
    u8 b1cc;
    u8 b1cd;
    u8 _pad1ce[0x1];
    u8 b1cf;
    u8 b1d0;
    u8 b1d1;
    u8 b1d2;
    u8 b1d3;
    u8 _pad1d4[0xc];
    s32 i1e0;
    u8 _pad1e4[0x4];
    s16 s1e8;
    u8 _pad1ea[0xa];
    s16 s1f4;
    s16 s1f6;
    u16 s1f8;
    u8 _pad1fa[0x2];
    u16 s1fc;
    u16 s1fe;
    u8 _pad200[0x1c];
    void * p21c;
    u8 _pad220[0x4];
    void * p224;
    void * p228;
    u8 _pad22c[0xc];
    s16 s238;
    u8 _pad23a[0xc];
    s16 s246;
    u16 s248;
    u8 _pad24a[0x2];
    s16 s24c;
    u8 _pad24e[0x2];
    u16 s250;
    u8 _pad252[0x2];
    u16 s254;
    s16 s256;
    u8 _pad258[0x8];
    void * p260;
    u8 _pad264[0x4];
    void * p268;
    void * p26c;
    u8 _pad270[0x8];
    void * p278;
    u8 _pad27c[0x2];
    s16 s27e;
    s16 s280;
    u16 s282;
    s16 s284;
    s16 s286;
    u8 _pad288[0x2c];
    s32 i2b4;
    u8 _pad2b8[0x18];
    s32 i2d0;
    s32 i2d4;
    s32 i2d8;
    s32 i2dc;
    s32 i2e0;
    s32 i2e4;
    s32 i2e8;
    u8 _pad2ec[0x4];
    s32 i2f0;
    u8 _pad2f4[0x4];
    s32 i2f8;
    u8 _pad2fc[0x4];
    s32 i300;
    s32 i304;
    void * p308;
    void * p30c;
    s32 i310;
    s32 i314;
    s32 i318;
    void * p31c;
    u8 _pad320[0x14];
    s32 i334;
    void * p338;
    void * p33c;
    u8 _pad340[0x1c];
    s32 i35c;
    u8 _pad360[0x10];
    s32 i370;
    s32 i374;
    s32 i378;
    u8 _pad37c[0x3c];
    u16 s3b8;
    u16 s3ba;
    s16 s3bc;
    u8 _pad3be[0x2];
    void * p3c0;
    u16 s3c4;
    u16 s3c6;
    u16 s3c8;
    u8 _pad3ca[0x4];
    u8 b3ce;
    u8 _pad3cf[0x1];
    u8 b3d0;
    u8 b3d1;
    u8 _pad3d2[0x2e];
} SPADBlock_162F8;
extern void freeObjectLayer2(GameObject *);
static __inline__ void setanim_162F8(GameObject *p)
{
    p->spriteBank = ((s32*)&(*(SPADBlock_162F8 *)&SCRATCHPAD).i2f0)[0];
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
