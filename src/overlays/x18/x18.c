#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_801158A0);

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_801158CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_801158DC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_801158F8);
typedef struct SPADBlock_158F8 {
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
} SPADBlock_158F8;

extern void *D_8011BE40[];
extern u16 GetClut(s32, s32);
extern void readAnimFrameCount(GameObject *);
extern void pushDrawListCapped(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void freeObjectLayer3(GameObject *);

void func_801158F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->animFrame = 1;
        o->unkA = 7;
        o->unkD = 1;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        o->clut = GetClut(0x80, 0x1ff);
        o->tpage = 4;
        o->anim = D_8011BE40[o->unkC];
        o->spriteBank = ((s32*)&(*(SPADBlock_158F8 *)&SCRATCHPAD).i2d4)[0];
        readAnimFrameCount(o);
        break;
    case 1:
        o->x.p.whole = o->unk30 - (*(u16*)((char*)&(*(SPADBlock_158F8 *)&SCRATCHPAD).i174 + 2));
        {
            s32 y = o->unk34;
            o->y.p.whole = y - ((u16*)&(*(SPADBlock_158F8 *)&SCRATCHPAD).s186)[0];
        }
        o->visible = 1;
        pushDrawListCapped(o);
        tickAnimation(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_80115A40);
typedef struct SPADBlock_15A40 {
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
} SPADBlock_15A40;

typedef struct { s16 x, y, z, pad; } P4_15A40;

extern void *D_8011BDFC[];
extern s16 D_801197F0[];

#define PT(o) ((P4_15A40 *)((char *)(o) + 0xb4))

void func_80115A40(GameObject *o)
{
    u8 t = o->state;
    u8 u;

    switch (t) {
    case 0:
        o->state = t + 1;
        o->unkF = 0x40;
        o->unkD = 0x81;
        o->tpage = 0xb;
        o->clut = 0x7c0c;
        o->spriteBank = ((s32*)&(*(SPADBlock_15A40 *)&SCRATCHPAD).i2d0)[0];
        o->anim = D_8011BDFC[o->unkC];
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        u = o->subState;
        switch (u) {
        case 0:
            o->subState = u + 1;
            PT(o)[0].x = D_801197F0[0];
            PT(o)[0].y = D_801197F0[1];
            PT(o)[0].z = 0;
            PT(o)[1].x = D_801197F0[2];
            PT(o)[1].y = D_801197F0[3];
            PT(o)[1].z = 0;
            PT(o)[2].x = D_801197F0[4];
            PT(o)[2].y = D_801197F0[5];
            PT(o)[2].z = 0;
            PT(o)[3].x = D_801197F0[6];
            PT(o)[3].y = D_801197F0[7];
            PT(o)[3].z = 0;
            break;
        case 1:
            o->x.raw += 0xc000;
            if (o->x.p.whole >= 0x1e1) o->x.p.whole = -0x78;
            break;
        case 2:
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
#undef PT

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_80115BF0);

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_80115C70);

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_80115D0C);

INCLUDE_ASM("asm/scus_942.36/overlays/x18/nonmatchings/x18/x18", func_80115EA8);
