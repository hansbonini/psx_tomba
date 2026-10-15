#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/render/camera", setSpawnAreaFlag);
void setSpawnAreaFlag(void)
{
    u8*  row = D_8007C110[GAME.selectedArea] + D_8009BCCA * 2;
    u16* dst = (u16*)((u8*)&GAME + 0x964 + row[0] * 2);

    *dst |= 1 << row[1];
}


// INCLUDE_ASM("nonmatchings/main/render/camera", loadSpawnPosition);
#if defined(VERSION_SLPS_01144)
INCLUDE_ASM("nonmatchings/main/render/camera", loadSpawnPosition);
#else
void loadSpawnPosition(u8* self)
{
    s16* row = (s16*)((u8*)D_8007BF78[GAME.selectedArea][GAME.selectedSection] + (u16)D_8009BCEA * 8);

    *(int*)(self + 0xEC) = *row++ << 16;
    *(int*)(self + 0xF0) = *row << 16;
    *(int*)(self + 0xF4) = row[1] << 16;
    switch (GAME.selectedArea) {
    case 0:
        if (D_8009C617 == 0 && GAME.selectedSection == 0) {
            *(s16*)(self + 0xEE) = 0x40;
        } else if (GAME.selectedSection == 3) {
            *(s16*)(self + 0xEE) = 0xD2;
        }
        break;
    case 2:
        if (GAME.selectedSection == 4) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    case 4:
        if (GAME.selectedSection == 0xF) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    case 10:
        if (GAME.selectedSection == 8) {
            *(s16*)(self + 0xEE) = 0x90;
        }
        break;
    }
}
#endif


// INCLUDE_ASM("nonmatchings/main/render/camera", initPlayerAtSpawn);
#if defined(VERSION_SLPS_01144)
INCLUDE_ASM("nonmatchings/main/render/camera", initPlayerAtSpawn);
#else
void initPlayerAtSpawn(void)
{
    u8* p = &PLAYER.obj;
    s16* row;
    u_int flags;
    u_int plane;

    p[0] = 3;
    if ((CURRENT_TASK)->loadGameSelected != 0) {
        D_8009C618[0] = 4;
        if (*(u_long*)&GAME.selectedArea == 0x20000) {
            D_8009BCEA = 2;
        }
    }
    row = (s16*)((u8*)D_8007BF78[GAME.selectedArea][GAME.selectedSection] + (u16)D_8009BCEA * 8);
    *(int*)(p + 0x10) = *row++ << 16;
    *(int*)(p + 0x14) = *row++ << 16;
    *(int*)(p + 0x18) = *row << 16;
    flags = (u16)row[1];
    plane = flags >> 8;
    flags &= 1;
    *(u16*)0x1F8001C8 = flags;
    GAME.area00_fogControl = plane;
    if (flags == 0) {
        *(u8**)(p + 0x40) = p + 0x10;
        *(u8**)(p + 0x44) = p + 0x18;
    } else {
        *(u8**)(p + 0x44) = p + 0x10;
        *(u8**)(p + 0x40) = p + 0x18;
    }
    GAME.selectedPlane = (s16)(*(u16**)(p + 0x44))[1] / 90;
    {
        u8*  r = D_8007C110[GAME.selectedArea] + GAME.selectedSection * 2;
        u16* dst = (u16*)((u8*)&GAME + 0x964 + r[0] * 2);

        *dst |= 1 << r[1];
    }
    if (D_8009C618[0] == 3 || D_8009C617 == 0) {
        loadSpawnPosition(p);
        *(s16*)(p + 0x12) = *(u16*)(p + 0xEE);
        *(s16*)(p + 0x16) -= 0x104;
    } else if ((CURRENT_TASK)->loadGameSelected != 0) {
        (CURRENT_TASK)->loadGameSelected = 0;
        *(VEC3*)&PLAYER.obj.x = D_8009C61C;
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/camera", loadSectionBounds);
void loadSectionBounds(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x2C) = *row++;
    *(u16*)(self + 0x2E) = *row++;
    *(u16*)(self + 0x30) = *row;
    *(u16*)(self + 0x32) = row[1];
}

// INCLUDE_ASM("nonmatchings/main/render/camera", loadSectionHeight);
void loadSectionHeight(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x32) = row[3];
}

// INCLUDE_ASM("nonmatchings/main/render/camera", func_800246B0);
typedef struct SPADBlock_246B0 {
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
} SPADBlock_246B0;

typedef struct GCDBlock_246B0 {
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
} GCDBlock_246B0;
extern GCDBlock_246B0 D_8009C068;

typedef struct { s32 x, y, z; } V3_246B0;
typedef struct { s16 x, y; } SP_246B0;
typedef struct { s16 a, b, c, d; } S4_246B0;
typedef struct {
    u8 b0; char p1[7]; V3_246B0 pos; char p14[0x20 - 0x14]; s32 d20; s32 d24;
    char p28[0x2c - 0x28]; s16 w2c, w2e, w30, w32; s32 *p34; char p38[0x78 - 0x38]; s32 d78; s32 d7c;
} C_246B0;
typedef struct { char p[0x4c]; u16 w4c; } O_246B0;
extern s16 D_800A38E4;
extern s16 D_800A38E6;
extern void func_8002A0A0(C_246B0 *);
#define FLAG (*(u16 *)0x1F8001C8)
#define SFLAG (*(s16 *)0x1F8001C8)

static __inline__ s32 smax_246B0(s32 a, s16 b) { s16 r = a; asm("" : "=r"(r) : "0"(r)); if (a < b) r = b; return r; }
static __inline__ s32 smin_246B0(s32 a, s16 b) { register s16 r asm("$4") = a; if ((s16)a > b) r = b; return r; }

#if defined(VERSION_SLPS_01144)
INCLUDE_ASM("nonmatchings/main/render/camera", func_800246B0);
#else
void func_800246B0(void)
{
    C_246B0 *c;
    s16 *p, *q;
    s32 off, x, v;
    u16 w;
    char pad[0x10];
    c = &D_800A38B8;
    c->b0 = 1;
    p = (s16 *)&((S4_246B0 **)&D_8007B680)[((u16 *)&GAME)[0]][D_8009BCCA];
    D_800A38E4 = *p++;
    D_800A38E6 = *p++;
    D_800A38E8 = *p++;
    D_800A38EA = *p;
    if (!(FLAG & 1)) {
        D_800A38EC = &((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[3];
        D_800A38F0 = &((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[5];
    } else {
        D_800A38F0 = &((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[3];
        D_800A38EC = &((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[5];
    }
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[0] = 0;
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[1] = 0;
    if ((((u16 *)&GAME)[0] == 4 && D_8009BCCA < 4) || *(s32 *)((u16 *)&GAME) == 0x50000)
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[2] = 0xFDC00000;
    else
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[2] = 0xFDE00000;
    q = D_8007BF78[((u16 *)&GAME)[0]][D_8009BCCA];
    w = (*(O_246B0 **)&D_1F8001D4)->w4c;
    q += (*(u16 *)&D_8009BCEA) * 4;
    switch (w) {
    case 1: case 2:
        off = -0x38;
        break;
    case 4: case 5: case 6:
        off = 0;
        break;
    }
    if (!(FLAG & 1)) {
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[3] = smax_246B0(*q++, c->w2c) << 16;
        { register s32 t asm("$2"); t = smin_246B0((u16)*q++ + off, c->w32) << 16; ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[4] = t; }
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[5] = *q << 16;
    } else {
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[3] = *q++ << 16;
        { register s32 t asm("$2"); t = smin_246B0((u16)*q++ + off, c->w32) << 16; ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[4] = t; }
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[5] = smax_246B0(*q, c->w2c) << 16;
    }
    x = *(s16 *)0x1F8000F2;
    asm("");
    v = c->w30;
    if (x < v || (v = c->w32, v < x))
        ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[4] = v << 16;
    { register s32 *pp asm("$4") = c->p34;
    v = c->w2e;
    if (v < ((SP_246B0 *)pp)->y || (v = c->w2c, ((SP_246B0 *)pp)->y < v))
        *pp = v << 16; }
    if (D_8009C068.bcda2) {
        c->d20 = 0x1000;
        if (FLAG & 1) c->d24 = -0x1000;
        else c->d24 = 0x1000;
        c->d78 = 0;
        c->d7c = SFLAG * 0x5A00;
    } else {
        c->d20 = 0;
        c->d24 = 0;
        c->d78 = 0;
        c->d7c = SFLAG * 0x5A00;
    }
    func_8002A0A0(c);
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[0] = c->pos.x;
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[1] = c->pos.y;
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[2] = c->pos.z;
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[3] = c->pos.x;
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[4] = c->pos.y + ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).ie0)[1];
    ((s32*)&(*(SPADBlock_246B0 *)&SCRATCHPAD).i174)[5] = c->pos.z;
}
#endif
#undef FLAG
#undef SFLAG

// INCLUDE_ASM("nonmatchings/main/render/camera", copyMatrix32);
void copyMatrix32(s32* src, s32* dst)
{
    s32 a, b, c, d;

    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    a = src[4];
    b = src[5];
    c = src[6];
    d = src[7];
    dst[4] = a;
    dst[5] = b;
    dst[6] = c;
    dst[7] = d;
}

void getBaseMatrix(MATRIX* dst)
{
    *dst=*SCRATCH_BASE_MATRIX;
    return;
}


// INCLUDE_ASM("nonmatchings/main/render/camera", initLighting);
void initLighting(u8* self)
{
    ((LightEnv*)self)->rotX = 0x638;
    ((LightEnv*)self)->rotY = 0x800;
    ((LightEnv*)self)->rotZ = 0;
    ((LightEnv*)self)->color = *SCRATCH_BASE_MATRIX;
    ((LightEnv*)self)->color.m[0][0] = 0xD00;
    ((LightEnv*)self)->color.m[1][0] = 0xD00;
    ((LightEnv*)self)->color.m[2][0] = 0xD00;
    ((LightEnv*)self)->backR = 0xC0;
    ((LightEnv*)self)->backG = 0xC0;
    ((LightEnv*)self)->backB = 0xC0;
    applyLighting(self);
}

// INCLUDE_ASM("nonmatchings/main/render/camera", applyLighting);
void applyLighting(u8* self)
{
    SVECTOR v;
    VECTOR out;
    MATRIX* m = &((LightEnv*)self)->light;

    SetFarColor(255, 255, 255);
    SetBackColor(((LightEnv*)self)->backR, ((LightEnv*)self)->backG, ((LightEnv*)self)->backB);
    SetColorMatrix(&((LightEnv*)self)->color);
    *m = *SCRATCH_BASE_MATRIX;
    RotMatrixX(((LightEnv*)self)->rotX, m);
    RotMatrixY(((LightEnv*)self)->rotY, m);
    v.vx = 0;
    v.vy = 0x1000;
    v.vz = 0;
    ApplyMatrix(m, &v, &out);
    m->m[0][0] = out.vx;
    m->m[0][1] = out.vy;
    m->m[0][2] = out.vz;
    m->m[1][0] = 0;
    m->m[1][1] = 0;
    m->m[1][2] = 0;
    m->m[2][0] = 0;
    m->m[2][1] = 0;
    m->m[2][2] = 0;
    SetFogNear(0x118, 0x220);
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera1);
void stubCamera1(void) {
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera2);
void stubCamera2(void) {
}

// INCLUDE_ASM("nonmatchings/main/render/camera", stubCamera3);
void stubCamera3(void) {
}
