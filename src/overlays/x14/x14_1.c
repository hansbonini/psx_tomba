#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_801170E4);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_801172E8);

void func_80117390(void) {
}

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117398);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_801173FC);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117664);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_8011767C);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_801176E0);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117790);

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_8011781C);
typedef struct SPADBlock_1781C {
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
} SPADBlock_1781C;

void func_8011781C(void)
{
    GameObject *n = allocObjectLayer3();

    if (n) {
        n->active = 1;
        n->type = 0x61;
        n->subtype = 5;
        n->h->p.whole = ((u16*)((char*)&(*(SPADBlock_1781C *)&SCRATCHPAD).i174 + 2))[0];
        n->y.p.whole = ((u16*)&(*(SPADBlock_1781C *)&SCRATCHPAD).s17a)[0] - 0x104;
        n->d->p.whole = ((u16*)&(*(SPADBlock_1781C *)&SCRATCHPAD).s17e)[0];
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117894);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_801178B8);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117AB0);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117C4C);

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117C60);

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80117D3C);
typedef struct SPADBlock_17D3C {
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
} SPADBlock_17D3C;
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");
extern void getBaseMatrix(MATRIX *);
extern s32 insertPrimWithBias(void *, s32, s32, s32, u32);
extern s32 insertPrim(void *, s32, s32, s32, u32);

#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 0( %1 );lwc2 $3, 4( %1 );lwc2 $4, 0( %2 );lwc2 $5, 4( %2 )" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")

#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")

void func_80117D3C(GameObject *o)
{
    s32 m;
    char *vb4;
    char *vbc;
    char *vc4;
    u8 *p;
    u8 *q;

    getBaseMatrix(&D_1F800020);
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(&(*(MATRIX *)&D_1F8000C0), &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += (*(MATRIX *)&D_1F8000C0).t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += (*(MATRIX *)&D_1F8000C0).t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += (*(MATRIX *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    p = (u8 *)D_1F800164;
    p[7] = 0x33;
    if (o->subtype == 0) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0xe] = 0;
        p[0xd] = 0;
        p[0xc] = 0;
        {
            u8 c = *(u8 *)&o->unk30;
            p[0x16] = c;
            p[0x14] = p[0x15] = c;
        }
    } else if (o->subtype == 4) {
        switch (o->unkAC) {
        case 0:
            {
                u16 c = o->unk74;
                p[6] = c;
                p[4] = p[5] = (u8)c / 3;
            }
            {
                u16 c = o->unk76;
                p[0xe] = c;
                p[0xc] = p[0xd] = (u8)c / 3;
            }
            {
                u16 c = o->unk78;
                p[0x16] = c;
                p[0x14] = p[0x15] = (u8)c / 3;
            }
            break;
        case 1:
            {
                u16 c = o->unk74;
                p[6] = c;
                p[4] = p[5] = c;
            }
            {
                u16 c = o->unk76;
                p[0xe] = c;
                p[0xc] = p[0xd] = c;
            }
            {
                u16 c = o->unk78;
                p[0x16] = c;
                p[0x14] = p[0x15] = c;
            }
            break;
        case 2:
            {
                u8 c = *(u8 *)&o->unk74;
                p[6] = 0;
                p[4] = p[5] = c;
            }
            {
                u8 c = *(u8 *)&o->unk76;
                p[0xe] = 0;
                p[0xc] = p[0xd] = c;
            }
            {
                u8 c = *(u8 *)&o->unk78;
                p[0x16] = 0;
                p[0x14] = p[0x15] = c;
            }
            break;
        }
    }
    vb4 = (char *)o + 0xb4;
    vbc = (char *)o + 0xbc;
    vc4 = (char *)o + 0xc4;
    gte_ldv3(vb4, vbc, vc4);
    gte_rtpt();
    gte_stsxy3_g4(p);
    gte_avsz3();
    gte_stotz(&LZ_FILE_CTRL_Long);
    if (o->unkB) insertPrim(p, (*(SPADBlock_17D3C *)&SCRATCHPAD).i1e0 + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x6000000);
    else insertPrimWithBias(p, (*(SPADBlock_17D3C *)&SCRATCHPAD).i1e0 + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x6000000);
    D_1F800164 += 0x1c;
    q = (u8 *)D_1F800164;
    if (GetGraphType() == 1) m = 0x80;
    else if (GetGraphType() == 2) m = 0x80;
    else m = 0x20;
    SetDrawMode(q, 0, 0, m, 0);
    if (o->unkB) AddPrim((s32 *)((*(SPADBlock_17D3C *)&SCRATCHPAD).i1e0 + 0x10) + (s8)o->unkF, q);
    else AddPrim((s32 *)(*(SPADBlock_17D3C *)&SCRATCHPAD).i1e0 + (LZ_FILE_CTRL_Long + 4) + (s8)o->unkF, q);
    D_1F800164 += 0xc;
}
#undef gte_ldv3
#undef gte_rtpt
#undef gte_stsxy3_g4
#undef gte_ldv0
#undef gte_rtps
#undef gte_avsz4
#undef gte_stotz
#undef gte_stsxy
#undef gte_avsz3

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_8011812C);
typedef struct SPADBlock_1812C {
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
} SPADBlock_1812C;
extern void getBaseMatrix__1812C(MATRIX *);

#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 0( %1 );lwc2 $3, 4( %1 );lwc2 $4, 0( %2 );lwc2 $5, 4( %2 )" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")

void func_8011812C(GameObject *o)
{
    s32 m;
    char *vb4;
    char *vbc;
    char *vc4;
    char *vcc;
    u8 *p;
    u8 *q;

    getBaseMatrix__1812C(&D_1F800020);
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(&(*(MATRIX *)&D_1F8000C0), &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += (*(MATRIX *)&D_1F8000C0).t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += (*(MATRIX *)&D_1F8000C0).t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += (*(MATRIX *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    p = (u8 *)D_1F800164;
    p[7] = 0x3b;
    {
        u16 c = o->unk74;
        p[6] = c;
        p[4] = p[5] = (u8)c / 3;
    }
    {
        u16 c = o->unk76;
        p[0xe] = c;
        p[0xc] = p[0xd] = (u8)c / 3;
    }
    {
        u16 c = o->unk78;
        p[0x16] = c;
        p[0x14] = p[0x15] = (u8)c / 3;
    }
    {
        u16 c = o->unk7A;
        p[0x1e] = c;
        p[0x1c] = p[0x1d] = (u8)c / 3;
    }
    vb4 = (char *)o + 0xb4;
    vbc = (char *)o + 0xbc;
    vcc = (char *)o + 0xcc;
    vc4 = (char *)o + 0xc4;
    gte_ldv3(vb4, vbc, vc4);
    gte_rtpt();
    gte_stsxy3_g4(p);
    gte_ldv0(vcc);
    gte_rtps();
    gte_avsz4();
    gte_stotz(&LZ_FILE_CTRL_Long);
    gte_stsxy(p + 0x20);
    insertPrimWithBias(p, (*(SPADBlock_1812C *)&SCRATCHPAD).i1e0 + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x8000000);
    D_1F800164 += 0x24;
    q = (u8 *)D_1F800164;
    if (GetGraphType() == 1) m = 0x80;
    else if (GetGraphType() == 2) m = 0x80;
    else m = 0x20;
    SetDrawMode(q, 0, 0, m, 0);
    AddPrim((s32 *)(*(SPADBlock_1812C *)&SCRATCHPAD).i1e0 + (LZ_FILE_CTRL_Long + 4) + (s8)o->unkF, q);
    D_1F800164 += 0xc;
}
#undef gte_ldv3
#undef gte_rtpt
#undef gte_stsxy3_g4
#undef gte_ldv0
#undef gte_rtps
#undef gte_avsz4
#undef gte_stotz
#undef gte_stsxy

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80118420);
typedef struct GVars_18420 {
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
} GVars_18420;

void func_80118420(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->timer = 600;
        o->velH = 0x1800;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->velX = -0x40;
        o->animFrame = 0;
        (*(GameObject **)&(*(GVars_18420 *)&D_8009BC98).p54) = o;
        break;
    case 1:
        o->unk8C = (o->unk8C - (o->velH >> 8)) & 0xfff;
        if (--o->timer == -1) {
            o->step++;
            o->animFrame = 1 - o->animFrame;
        }
        break;
    case 2:
        o->unk8C = (o->unk8C - (o->velH >> 8)) & 0xfff;
        o->velH += o->velX;
        if ((u16)(o->velH + 0x17ff) >= 0x2fff) {
            o->timer = 600;
            o->step--;
            o->velX *= -1;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_8011855C);
extern s16 D_80124F74[];

void func_8011855C(GameObject *o)
{
    GameObject *p;

    switch (o->step) {
    case 0:
        o->step++;
        o->unk8C = D_80124F74[o->unkC];
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->velH != 0) break;
        if (o->animFrame = p->animFrame) {
            o->step = 2;
            o->velV = 0;
            o->velY = 0x40;
        } else {
            o->step = 3;
            o->velV = 0;
            o->velY = -0x40;
        }
        break;
    case 2:
        o->velV += o->velY;
        o->unk84 += o->velV >> 8;
        if (o->unk84 >= 0x800) {
            o->unk84 = 0x800;
            o->step = 1;
        }
        break;
    case 3:
        o->velV += o->velY;
        o->unk84 += o->velV >> 8;
        if (o->unk84 <= 0) {
            o->unk84 = 0;
            o->step = 1;
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80118694);

// INCLUDE_ASM("asm/scus_942.36/overlays/x14/nonmatchings/x14/x14_1", func_80118960);
extern void freeObjectLayer4(GameObject *);

void func_80118960(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->active = 2;
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
