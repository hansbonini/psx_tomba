#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011530C);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115330);

extern void *D_801193B8[];
extern void readAnimFrameCount(GameObject *);
extern void tickAnimation(GameObject *);
extern void pushDrawListCapped(GameObject *);
extern void freeObjectLayer3(GameObject *);

void func_80115330(GameObject *o)
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
            o->unkD = 0x81;
            o->z.p.whole = 0x82;
            o->unkF = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        case 1:
            o->unkD = 1;
            o->z.p.whole = 0x82;
            o->unkF = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        case 2:
            o->unkD = 1;
            o->unkF = 1;
            o->z.p.whole = 0;
            o->tpage = 4;
            o->anim = D_801193B8[o->subtype];
            break;
        }
        o->spriteBank = SCRATCHPAD.sprData[3];
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        o->x.p.whole = o->unk30 - (*(u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2));
        o->y.p.whole = o->unk34 - (u16)SCRATCHPAD.unk168[7].p.whole;
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

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801154F8);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801155A8);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115604);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115608);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801158DC);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801159E0);

typedef struct GV2Block_159E0 {
    u8 _pad00[0x6];
    u16 sa6;
    u8 _pad08[0x6];
    u8 bae;
    u8 baf;
    u8 bb0;
    u8 bb1;
    u8 bb2;
    u8 bb3;
    u8 _pad14[0xc];
    u16 sc0;
    u8 bc2;
    u8 bc3;
    u8 _pad24[0x16];
    u16 sda;
    u8 _pad3c[0x4];
} GV2Block_159E0;
extern GV2Block_159E0 D_8009C608;

typedef struct GVars_159E0 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_159E0;

typedef struct { s16 v[6]; } V6_159E0;
extern s32 showMessageBoxDirect(s32, s32, V6_159E0 *);

void func_801159E0(GameObject *o)
{
    V6_159E0 v;
    GameObject *p;

    switch (o->step) {
    case 0:
        if (o->unk68 == 0) break;
        v = *(V6_159E0 *)&o->x;
        o->unk90 = showMessageBoxDirect(2, 0x33, &v);
        ((u8*)&(*(GVars_159E0 *)&D_8009BC98).b42)[0] = 1;
        D_8009C608.bb0 = 2;
        ((u8*)&PLAYER.obj.state)[0] = 5;
        ((u8*)&PLAYER.obj.subState)[0] = 0;
        ((u8*)&PLAYER.obj.step)[0] = 0;
        o->unkBC = o->animFrame;
        o->animFrame = o->unk68 & 1;
        o->step++;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        SCRATCHPAD.unk1C6 = 0;
        ((u8*)&(*(GVars_159E0 *)&D_8009BC98).b42)[0] = 0;
        ((s16*)&PLAYER.obj.unkB2)[0] = 0;
        if ((*(GVars_159E0 *)&D_8009BC98).b3f == 0) {
            ((u8*)&PLAYER.obj.state)[0] = 1;
            ((u8*)&PLAYER.obj.subState)[0] = 0;
            ((u8*)&PLAYER.obj.step)[0] = 0;
        }
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        o->animFrame = o->unkBC;
        break;
    }
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115B40);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115C70);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115CDC);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115D0C);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80115E94);

typedef struct GCDBlock_15E94 {
    u8 _pad0[0x94];
    u16 scd94;
    u8 _pad96[0x2];
    u8 bcd98;
    u8 bcd99;
    u8 bcd9a;
    u8 _pad9b[0x1];
    u8 bcd9c;
    u8 bcd9d;
    u8 bcd9e;
    u8 _pad9f[0x3];
    u8 bcda2;
    u8 _pada3[0x2];
    u8 bcda5;
    u8 bcda6;
    u8 bcda7;
    u8 _pada8[0x1];
    u8 bcda9;
    u8 _padaa[0x1];
    u8 bcdab;
    u8 bcdac;
    u8 bcdad;
    u8 bcdae;
    u8 _padaf[0x2];
    u8 bcdb1;
    u8 bcdb2;
    u8 _padb3[0x1];
    u8 bcdb4;
    u8 bcdb5;
    u8 _padb6[0x2];
    u8 bcdb8;
    u8 _padb9[0x1];
    u8 bcdba;
    u8 bcdbb;
    u8 bcdbc;
    u8 _padbd[0x2];
    u8 bcdbf;
    u8 bcdc0;
    u8 bcdc1;
    u8 _padc2[0x1];
    u8 bcdc3;
    u8 _padc4[0x1];
    u8 bcdc5;
    u8 _padc6[0x1];
    u8 bcdc7;
    u8 bcdc8;
    u8 bcdc9;
    u8 bcdca;
    u8 bcdcb;
    u8 bcdcc;
    u8 bcdcd;
    u8 bcdce;
    u8 _padcf[0x3];
    u8 bcdd2;
    u8 _padd3[0x2];
    u8 bcdd5;
    u8 bcdd6;
    u8 bcdd7;
    u8 _padd8[0x1];
    u8 bcdd9;
    u8 _padda[0x1];
    u8 bcddb;
    u8 bcddc;
    u8 bcddd;
    u8 bcdde;
    u8 _paddf[0x3];
    u8 bcde2;
    u8 bcde3;
    u8 _pade4[0x1];
    u8 bcde5;
    u8 _pade6[0x7];
    u8 bcded;
    u8 _padee[0x3];
    u8 bcdf1;
    u8 bcdf2;
    u8 bcdf3;
    u8 _padf4[0x1];
    u8 bcdf5;
    u8 _padf6[0xf];
    u8 bce05;
    u8 _pad106[0x4];
    u8 bce0a;
    u8 bce0b;
    u8 bce0c;
    u8 bce0d;
    u8 _pad10e[0x7];
    u8 bce15;
    u8 bce16;
    u8 bce17;
    u8 bce18;
    u8 _pad119[0x1];
    u8 bce1a;
    u8 bce1b;
    u8 bce1c;
    u8 _pad11d[0x2];
    u8 bce1f;
    u8 _pad120[0x2];
    u8 bce22;
    u8 bce23;
    u8 bce24;
    u8 _pad125[0x3];
    u8 bce28;
    u8 _pad129[0xb];
    u8 bce34;
    u8 _pad135[0x5];
    u8 bce3a;
    u8 bce3b;
    u8 _pad13c[0x1];
    u8 bce3d;
    u8 _pad13e[0x2];
    u8 bce40;
    u8 bce41;
    u8 _pad142[0x2];
    u8 bce44;
    u8 _pad145[0x3];
    u8 bce48;
    u8 _pad149[0x1];
    u8 bce4a;
    u8 _pad14b[0x2];
    u8 bce4d;
    u8 bce4e;
    u8 bce4f;
    u8 bce50;
    u8 bce51;
    u8 bce52;
    u8 bce53;
    u8 bce54;
    u8 bce55;
    u8 bce56;
    u8 bce57;
    u8 bce58;
    u8 bce59;
    u8 _pad15a[0x1];
    u8 bce5b;
    u8 _pad15c[0x1];
    u8 bce5d;
    u8 _pad15e[0x3];
    u8 bce61;
    u8 bce62;
    u8 bce63;
    u8 _pad164[0x47];
    u8 bceab;
    u8 _pad1ac[0x1];
    u8 bcead;
    u8 bceae;
    u8 bceaf;
    u8 bceb0;
    u8 _pad1b1[0xb];
    u8 bcebc;
    u8 bcebd;
    u8 _pad1be[0x1];
    u8 bcebf;
    u8 _pad1c0[0x1];
    u8 bcec1;
    u8 bcec2;
    u8 bcec3;
    u8 bcec4;
    u8 bcec5;
    u8 bcec6;
    u8 bcec7;
    u8 _pad1c8[0x4];
    u8 bcecc;
    u8 bcecd;
    u8 _pad1ce[0x10];
    u8 bcede;
    u8 bcedf;
    u8 _pad1e0[0x1];
    u8 bcee1;
    u8 bcee2;
    u8 _pad1e3[0xa];
    u8 bceed;
    u8 _pad1ee[0x1];
    u8 bceef;
    u8 bcef0;
    u8 _pad1f1[0x5];
    u8 bcef6;
    u8 bcef7;
    u8 _pad1f8[0x3];
    u8 bcefb;
    u8 bcefc;
    u8 _pad1fd[0x3];
    u8 bcf00;
    u8 _pad201[0x2];
    u8 bcf03;
    u8 bcf04;
    u8 _pad205[0x1];
    u8 bcf06;
    u8 _pad207[0x3];
    u8 bcf0a;
    u8 bcf0b;
    u8 bcf0c;
    u8 bcf0d;
    u8 bcf0e;
    u8 bcf0f;
    u8 bcf10;
    u8 bcf11;
    u8 _pad212[0xa];
    u8 bcf1c;
    u8 _pad21d[0x7];
    u8 bcf24;
    u8 _pad225[0x4];
    u8 bcf29;
    u8 _pad22a[0x3];
    u8 bcf2d;
    u8 bcf2e;
    u8 bcf2f;
    u8 _pad230[0x98];
    u8 bcfc8;
    u8 _pad2c9[0x1];
    u8 bcfca;
    u8 bcfcb;
    u8 bcfcc;
    u8 bcfcd;
    u8 bcfce;
    u8 bcfcf;
    s16 scfd0;
    s16 scfd2;
    s16 scfd4;
    u8 bcfd6;
    u8 _pad2d7[0x2];
    u8 bcfd9;
    u8 bcfda;
    u8 bcfdb;
    u8 bcfdc;
    u8 bcfdd;
    u8 bcfde;
    u8 bcfdf;
    u8 bcfe0;
    u8 bcfe1;
    s16 scfe2;
    u8 _pad2e4[0x1];
    u8 bcfe5;
    u8 _pad2e6[0x4];
    u8 bcfea;
    u8 _pad2eb[0x2];
    u8 bcfed;
    u8 bcfee;
    u8 _pad2ef[0x1];
    u8 bcff0;
    u8 bcff1;
    u8 bcff2;
    u8 bcff3;
    u8 bcff4;
    u8 bcff5;
    u8 _pad2f6[0x1];
    u8 bcff7;
    u8 bcff8;
    u8 bcff9;
    u8 bcffa;
    u8 bcffb;
    u8 bcffc;
    u8 bcffd;
    u8 _pad2fe[0x2];
    u8 bd000;
    u8 bd001;
    u8 bd002;
    u8 bd003;
    u8 bd004;
    u8 _pad305[0x1];
    u8 bd006;
    u8 bd007;
    u8 bd008;
    u8 _pad309[0x1];
    u8 bd00a;
    u8 _pad30b[0x2];
    u8 bd00d;
    u8 bd00e;
    u8 _pad30f[0x67];
    u8 bd076;
    u8 bd077;
    u8 bd078;
    u8 _pad379[0x1];
    u8 bd07a;
    u8 bd07b;
    u8 bd07c;
    u8 bd07d;
    u8 bd07e;
    u8 _pad37f[0x2];
    u8 bd081;
    u8 bd082;
    u8 bd083;
    u8 bd084;
    u8 _pad385[0x1];
    u8 bd086;
    u8 bd087;
    u8 bd088;
    u8 _pad389[0x7];
    u8 bd090;
    u8 bd091;
    u8 bd092;
    u8 bd093;
    u8 bd094;
    u8 bd095;
    u8 _pad396[0xe];
    u8 bd0a4;
    u8 _pad3a5[0x2];
    u8 bd0a7;
    u8 _pad3a8[0x1];
    u8 bd0a9;
    u8 bd0aa;
    u8 _pad3ab[0x5];
    u16 sd0b0;
    u8 bd0b2;
    u8 _pad3b3[0x1];
    u8 bd0b4;
    u8 _pad3b5[0x2];
    u8 bd0b7;
    u8 bd0b8;
    u8 bd0b9;
    u8 bd0ba;
    u8 bd0bb;
    u8 bd0bc;
    u8 _pad3bd[0x1];
    u8 bd0be;
    u8 bd0bf;
    u8 bd0c0;
    u8 bd0c1;
    u8 _pad3c2[0x2];
    u8 bd0c4;
    u8 bd0c5;
    u8 bd0c6;
    u8 _pad3c7[0x1];
    u8 bd0c8;
    u8 bd0c9;
    u8 bd0ca;
    u8 bd0cb;
    u8 bd0cc;
    u8 bd0cd;
    u8 bd0ce;
    u8 bd0cf;
    u8 bd0d0;
    u8 bd0d1;
    u8 _pad3d2[0x7];
    u8 bd0d9;
    u8 bd0da;
    u8 _pad3db[0x7];
    u8 bd0e2;
    u8 _pad3e3[0x3];
    u8 bd0e6;
    u8 bd0e7;
    u8 _pad3e8[0x13];
    u8 bd0fb;
    u8 bd0fc;
    u8 bd0fd;
    u8 _pad3fe[0x2];
} GCDBlock_15E94;
extern GCDBlock_15E94 D_8009C068;

typedef struct GV2Block_15E94 {
    u8 _pad00[0x6];
    u16 sa6;
    u8 _pad08[0x6];
    u8 bae;
    u8 baf;
    u8 bb0;
    u8 bb1;
    u8 bb2;
    u8 bb3;
    u8 _pad14[0xc];
    u16 sc0;
    u8 bc2;
    u8 bc3;
    u8 _pad24[0x16];
    u16 sda;
    u8 _pad3c[0x4];
} GV2Block_15E94;

typedef struct GVars_15E94 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_15E94;

typedef struct { s16 v[6]; } V6_15E94;
extern void addItemToInventory(s32, s32, s32);

void func_80115E94(GameObject *o)
{
    V6_15E94 v;
    GameObject *p;
    u8 *f;

    switch (o->step) {
    case 0:
        if (o->unk68 == 0) break;
        v = *(V6_15E94 *)&o->x;
        if (D_8009C068.bd008) {
            o->unk90 = showMessageBoxDirect(2, 0x66, &v);
        } else {
            o->unk90 = showMessageBoxDirect(2, 0x65, &v);
        }
        ((u8*)&(*(GVars_15E94 *)&D_8009BC98).b42)[0] = 1;
        ((u8*)&D_8009C608.bb0)[0] = 2;
        ((u8*)&PLAYER.obj.state)[0] = 5;
        ((u8*)&PLAYER.obj.subState)[0] = 0;
        ((u8*)&PLAYER.obj.step)[0] = 0;
        o->unkBC = o->animFrame;
        o->animFrame = o->unk68 & 1;
        o->step++;
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        f = &D_8009C068.bd008;
        if (*f == 0) {
            addItemToInventory(0x41, 1, 1);
            *f = 1;
        }
        SCRATCHPAD.unk1C6 = 0;
        ((u8*)&(*(GVars_15E94 *)&D_8009BC98).b42)[0] = 0;
        ((s16*)&PLAYER.obj.unkB2)[0] = 0;
        if (((u8*)&(*(GVars_15E94 *)&D_8009BC98).b3f)[0] == 0) {
            ((u8*)&PLAYER.obj.state)[0] = 1;
            ((u8*)&PLAYER.obj.subState)[0] = 0;
            ((u8*)&PLAYER.obj.step)[0] = 0;
        }
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        o->animFrame = o->unkBC;
        break;
    }
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116048);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801160A0);

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", func_80115214);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801161C8);

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801163A0);
typedef struct {
    u8 b0, b1, b2, b3;
    u16 w4;
    s16 w6;
    void **anim;
} T80117050_163A0;

extern T80117050_163A0 D_80116A14[];
extern s32 SPR_DATA[];

extern void readAnimFrameCount(GameObject *);

void func_801163A0(GameObject *o)
{
    o->hitOffsetX = D_80116A14[o->subtype].b0;
    o->hitWidth = D_80116A14[o->subtype].b1;
    o->hitOffsetY = D_80116A14[o->subtype].b2;
    o->hitHeight = D_80116A14[o->subtype].b3;
    o->tpage = D_80116A14[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80116A14[o->subtype].w6];
    o->anim = D_80116A14[o->subtype].anim[(u16)o->unkB4];
    readAnimFrameCount(o);
    o->unk8C = 0;
    o->unkD = 0;
    o->unkF = 0;
    o->category |= 0x80;
    o->state++;
}

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_801164F4);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011659C);

INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116814);

void func_80116968(void) {
}

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_80116970);
void func_80116970(GameObject *o)
{
    o->state = 3;
}

// INCLUDE_ASM("overlays/x05/nonmatchings/x05/x05", func_8011697C);
extern void func_8011659C(GameObject *);
extern void freeObjectUnlayered(GameObject *);

void func_8011697C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8011659C(o);
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

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", D_80115234);

INCLUDE_RODATA("overlays/x05/nonmatchings/x05/x05", func_80115274);
