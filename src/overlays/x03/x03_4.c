#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80125048);
typedef struct SPADBlock_25048 {
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
} SPADBlock_25048;

extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s16 isObjectPastReferenceX(GameObject *);
extern void applyFrameVelocityXY(GameObject *);
extern s32 func_80124A44(GameObject *, s16);
extern void *D_801388B4[];
extern u8 D_80135000[];
extern u8 D_801350A4[];
extern u8 D_8013509C[];
extern u16 D_8013507C[];
extern char D_80077244[];
extern char D_80077208[];

#define SET() \
    { u8 *p; \
    o->anim = D_801388B4[o->unkAC]; \
    p = &D_80135000[o->unkAC * 4]; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p++; \
    o->hitHeight = *p++; \
    readAnimFrameCount(o); }

#define SLOPE(o, Y) \
    if (o->touchFlag == 1) { \
        o->touchFlag = 0; \
    } else if (probeCollisionAtDepthA(o, o->h->p.whole, Y)) { \
        if (o->unkAC >= 0xc) { \
            o->unk8C = 0; \
        } else { \
            u32 v = (((*(u16*)&(*(SPADBlock_25048 *)&SCRATCHPAD).s27e) << 2) + o->unk8C) & 0xff; \
            if (v != 0) { \
                if (v < 0x80) o->unk8C = o->unk8C - 1; \
                else o->unk8C = o->unk8C + 1; \
                o->unk8C = *(u8 *)&o->unk8C; \
            } \
        } \
    }

static __inline__ s16 near_25048(GameObject *o)
{
    s16 lim = 0xc0;
    u16 a;
    a = (u16)((*(u16*)((char*)&(*(SPADBlock_25048 *)&SCRATCHPAD).i170 + 2)) - o->d->p.whole + 0x2d);
    if ((u32)a >= 0x5b) return 0;
    a = (u16)((*(u16*)((char*)&(*(SPADBlock_25048 *)&SCRATCHPAD).i168 + 2)) - o->h->p.whole + 0x60);
    if (a > lim) return 0;
    return (u16)((*(u16*)((char*)&(*(SPADBlock_25048 *)&SCRATCHPAD).i16c + 2)) - o->y.p.whole + 0x40) <= lim - 0x40;
}

void func_80125048(GameObject *o)
{
    s16 *w = &o->unkB4;
    s32 t;

    switch (o->unk7) {
    case 0:
        if (isObjectPastReferenceX(o) != o->animFrame) {
            o->unk7 = 3;
            if (*w) {
                o->movetab = D_80077244;
                o->unkAC = 0xf;
            } else {
                o->unkAC = 0x1e;
                o->movetab = D_80077208;
            }
            goto set;
        } else {
            o->unk7++;
        }
        break;
    case 1:
        o->unk7++;
        if (*w) {
            t = D_801350A4[nextRandom() & 7];
            o->movetab = D_80077244;
            o->unkAC = 8;
        } else {
            t = D_8013509C[nextRandom() & 7];
            o->unkAC = 1;
            o->movetab = D_80077208;
        }
    t1:
        o->timer = t;
        goto set;
    case 2:
        if (--o->timer == -1) {
            if (near_25048(o) && (nextRandom() & 1)) {
                o->step++;
                o->unk7 = 0;
                break;
            }
            o->unk7 = 5;
            if (*w) {
                t = D_8013509C[nextRandom() & 7];
                o->unkAC = 7;
                o->movetab = D_80077244;
                goto t1;
            } else {
                t = D_8013507C[nextRandom() & 7];
                o->unkAC = 0;
                o->movetab = D_80077208;
                goto t1;
            }
        }
        applyFrameVelocityXY(o);
        tickAnimation(o);
        SLOPE(o, (s16)(o->y.p.whole + 0xe));
        if (func_80124A44(o, o->animFrame)) {
            o->unk7++;
            if (*w) o->unkAC = 0xf;
            else o->unkAC = 0x1e;
            goto set;
        }
        if (!o->visible) goto off;
        break;
    case 3:
        if (tickAnimation(o)) {
            o->cooldownTimer = 0x1e;
            o->animFrame = 1 - o->animFrame;
            o->unk7++;
            if (*w) o->unkAC = 8;
            else o->unkAC = 0;
            goto set;
        }
        break;
    case 4:
        if (--o->cooldownTimer == -1) {
            if (*w) {
                o->unkAC = 8;
                o->timer = D_801350A4[nextRandom() & 7];
            } else {
                o->unkAC = 1;
                o->timer = D_8013509C[nextRandom() & 7];
            }
            o->unk7 = 2;
        }
        break;
    case 5:
        {
            s16 yy = o->y.p.whole;
            o->y.p.whole = yy + 1;
            SLOPE(o, (s16)(yy + 0xf));
        }
        if (o->visible) {
            if (--o->timer == -1) {
                if ((nextRandom() & 1) != o->animFrame) {
                    o->unk7 = 3;
                    if (*w) o->unkAC = 0xf;
                    else o->unkAC = 0x1e;
                set:
                    SET();
                } else {
                    o->unk7 = 1;
                }
            }
        } else {
        off:
            if (*w == 0 || (u16)(o->h->p.whole - (*(u16*)((char*)&(*(SPADBlock_25048 *)&SCRATCHPAD).i174 + 2)) + 0x70) >= 0x220 ||
                (u16)((*(SPADBlock_25048 *)&SCRATCHPAD).s186 - o->y.p.whole + 0x70) >= 0x1c0) {
                o->step = 0;
                o->unk7 = 0;
            }
        }
        break;
    }
}
#undef SET
#undef SLOPE

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012567C);
typedef struct SPADBlock_2567C {
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
} SPADBlock_2567C;
extern char D_80077214[];

static __inline__ void set_2567C(GameObject *o)
{
    u8 *p;
    o->anim = D_801388B4[o->unkAC];
    p = &D_80135000[o->unkAC * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    readAnimFrameCount(o);
}

#define SET() set_2567C(o)

static __inline__ void go3_2567C(GameObject *o, s16 w, s16 n)
{
    u8 t = o->unk7;
    t++;
    o->unk7 = t;
    o->cooldownTimer = w;
    o->unkAC = n;
    set_2567C(o);
}

static __inline__ void slope_2567C(GameObject *o)
{
    u32 v;

    if (o->touchFlag == 1) {
        o->touchFlag = 0;
    } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0xe))) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            v = (((*(u16*)&(*(SPADBlock_2567C *)&SCRATCHPAD).s27e) << 2) + o->unk8C) & 0xff;
            if (v != 0) {
                if (v < 0x80) o->unk8C = o->unk8C - 1;
                else o->unk8C = o->unk8C + 1;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
    }
}

static __inline__ s32 near_2567C(GameObject *o)
{
    u16 t;
    s16 lim = 0x40;
    t = (*(u16*)((char*)&(*(SPADBlock_2567C *)&SCRATCHPAD).i170 + 2)) - o->d->p.whole + 0x2d;
    if (t >= 0x5b) return 0;
    t = (*(u16*)((char*)&(*(SPADBlock_2567C *)&SCRATCHPAD).i168 + 2)) - o->h->p.whole + 0x20;
    if (t > lim) return 0;
    t = (*(u16*)((char*)&(*(SPADBlock_2567C *)&SCRATCHPAD).i16c + 2)) - o->y.p.whole + 0xa0;
    return t <= lim + 0xa0;
}

void func_8012567C(GameObject *o)
{
    s16 *w = &o->unkB4;

    switch (o->unk7) {
    case 0:
        o->unk7++;
        o->timer = D_801350A4[nextRandom() & 7];
        if (*w != 0) o->unkAC = 7;
        else o->unkAC = 0x1e;
        SET();
        break;
    case 1:
        o->y.p.whole++;
        slope_2567C(o);
        if (--o->timer == -1)
            o->unk7++;
        break;
    case 2:
        if (*w != 0) {
            w[1] = 1;
            o->unk7 = 7;
            o->unkAC = 0xd;
            o->unk8C = 0;
        } else {
            o->unkAC = 0x1b;
            o->unk7++;
        }
        SET();
        break;
    case 3:
        if (tickAnimation(o)) {
            o->movetab = D_80077214;
            o->timer = D_8013509C[nextRandom() & 7];
            if (isObjectPastReferenceX(o) != o->animFrame) {
                o->cooldownTimer = 0x1e;
                o->unk7 = 5;
                o->unkAC = 0x1d;
            } else {
                o->unkAC = 3;
                o->unk7++;
            }
            SET();
        }
        break;
    case 4:
        if (--o->timer != -1) {
        applyFrameVelocityXY(o);
        tickAnimation(o);
        slope_2567C(o);
        if (func_80124A44(o, o->animFrame)) {
            go3_2567C(o, 0x3c, 0x1d);
        } else if ((((*(SPADBlock_2567C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2567C *)&SCRATCHPAD).i198) & 0x3f) == 0 && isObjectPastReferenceX(o) != o->animFrame) {
            go3_2567C(o, 0x1e, 0x1d);
        }
        } else {
            o->step = 1;
            o->unk7 = 2;
        }
        break;
    case 5:
        if (tickAnimation(o)) {
            o->unk7++;
            o->animFrame = 1 - o->animFrame;
            o->unkAC = 3;
            SET();
        }
        break;
    case 6:
        tickAnimation(o);
        if (--o->cooldownTimer == -1)
            o->unk7 = 4;
        break;
    case 7:
        if (tickAnimation(o)) {
            o->timer = D_8013507C[nextRandom() & 7];
            w[1] = 1;
            o->movetab = ((char *)&D_800771FC);
            o->unkAC = 0xc;
            SET();
            if (isObjectPastReferenceX(o) != o->animFrame) {
                o->unk7 = 9;
                o->cooldownTimer = 0x14;
            } else {
                o->unk7++;
            }
        }
        break;
    case 8:
        if (near_2567C(o)) {
            o->unk7 = 0;
            o->step++;
            break;
        }
        if (--o->timer == 0) {
            o->unk7 = 10;
            w[1] = 0;
            o->unkAC = 0xe;
            SET();
            break;
        }
        applyFrameVelocityXY(o);
        tickAnimation(o);
        slope_2567C(o);
        if (func_80124A44(o, o->animFrame)) {
            o->cooldownTimer = 0x3c;
            o->unk7++;
        } else if ((((*(SPADBlock_2567C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2567C *)&SCRATCHPAD).i198) & 0x3f) == 0 && isObjectPastReferenceX(o) != o->animFrame) {
            o->cooldownTimer = 0x1e;
            o->unk7++;
        }
        break;
    case 9:
        tickAnimation(o);
        if (--o->cooldownTimer == -1) {
            o->unk7--;
            o->animFrame = 1 - o->animFrame;
        }
        break;
    case 10:
        if (tickAnimation(o)) {
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    }
}
#undef SET

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80125EB8);
typedef struct B_25EB8 { u8 c[4]; } B_25EB8;
extern u8 D_801350AB[];
extern u8 D_801350B3[];
extern void updateObjectSideFlag(GameObject *);

void func_80125EB8(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->unk8C = 0;
        updateObjectSideFlag(o);
        o->timer = D_8013507C[nextRandom() & 7];
        o->unk7++;
        o->unkAC = D_801350AB[o->unkB6];
        o->anim = D_801388B4[o->unkAC];
        { u8 *p = ((B_25EB8 *)&D_80135000)[o->unkAC].c;
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1]; }
        readAnimFrameCount(o);
        break;
    case 1:
        updateObjectSideFlag(o);
        tickAnimation(o);
        if (--o->timer == -1 || o->unkB6 == 5) {
            o->unk7++;
            o->unkAC = D_801350B3[o->unkB6];
            o->unkB6 = 0;
            o->anim = D_801388B4[o->unkAC];
            { u8 *p = ((B_25EB8 *)&D_80135000)[o->unkAC].c;
            o->hitOffsetX = *p++;
            o->hitWidth = *p++;
            o->hitOffsetY = *p;
            o->hitHeight = p[1]; }
            readAnimFrameCount(o);
        }
        break;
    case 2:
        if (tickAnimation(o)) {
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126068);
typedef struct SPADBlock_26068 {
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
} SPADBlock_26068;
extern void *D_8013892C;
extern s16 func_80043D2C(GameObject *, s16, s16);

void func_80126068(GameObject *o)
{
    u8 *p;

    switch (o->step) {
    case 0:
        o->step++;
        o->unkAC = 0x1e;
        o->anim = D_8013892C;
        p = D_80135000 + (o->unkAC << 2);
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        readAnimFrameCount(o);
        break;
    case 1:
        o->y.p.whole -= 4;
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10) != 0) {
            o->unk8C = (-(*(SPADBlock_26068 *)&SCRATCHPAD).s27e * 4 + 0x80) & 0xff;
            o->step++;
        }
        break;
    case 2:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126174);
typedef struct SPADBlock_26174 {
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
} SPADBlock_26174;
extern void applyFrameVelocityY(GameObject *);

void func_80126174(GameObject *o)
{
    u8 *p;

    switch (o->step) {
    case 0:
        o->movetab = ((char *)&D_800771FC);
        o->unkAC = 0x1e;
        o->step++;
        o->anim = D_8013892C;
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p++;
        o->hitHeight = *p++;
        readAnimFrameCount(o);
    case 1:
        applyFrameVelocityY(o);
        if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe) != 0) {
            o->unk8C = (-(*(SPADBlock_26174 *)&SCRATCHPAD).s27e * 4) & 0xff;
            o->step = 0;
            o->subState++;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80126288);
typedef struct SPADBlock_26288 {
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
} SPADBlock_26288;

extern char D_8007725C[];
extern void *D_801388C4;
extern void playSFX(s32);
extern void applyFrameVelocityX(GameObject *);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

void func_80126288(GameObject *o)
{
    u8 *b;
    s32 v;

    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->movetab = D_8007725C;
        o->unkAC = 4;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->step++;
        o->anim = D_801388C4;
        b = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *b++;
        o->hitWidth = *b++;
        o->hitOffsetY = *b++;
        o->hitHeight = *b++;
        readAnimFrameCount(o);
    case 1:
        if (o->visible && (((*(SPADBlock_26288 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_26288 *)&SCRATCHPAD).i198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        applyFrameVelocityX(o);
        if (o->animFrame & 1)
            v = -0x18;
        else
            v = 0x18;
        if (func_80043AB0(o, o->h->p.whole + v, o->y.p.whole, o->animFrame)
            || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)
            || (u16)(v = (u16)(*(s16*)((char*)&(*(SPADBlock_26288 *)&SCRATCHPAD).i168 + 2)) - (u16)o->h->p.whole + 0x40) < 0x80) {
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        if (o->visible && (((*(SPADBlock_26288 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_26288 *)&SCRATCHPAD).i198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        o->y.p.whole++;
        if (o->animFrame & 1)
            v = -0x18;
        else
            v = 0x18;
        func_80043AB0(o, o->h->p.whole + v, o->y.p.whole, o->animFrame);
        if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)) {
            o->unk8C = (-(*(SPADBlock_26288 *)&SCRATCHPAD).s27e << 2) & 0xff;
            o->step = 1;
            o->unk9C = 0;
            o->subState++;
        }
        break;
    }
    if ((((*(SPADBlock_26288 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_26288 *)&SCRATCHPAD).i198) & 0xf) == 0 && D_800A38EA + 0x98 < o->y.p.whole) o->state = 3;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012659C);
typedef struct SPADBlock_2659C {
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
} SPADBlock_2659C;

void func_8012659C(GameObject *o)
{
    u8 *b;

    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->movetab = D_8007725C;
        o->unkAC = 4;
        o->animFrame = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->step++;
        o->anim = D_801388C4;
        b = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *b++;
        o->hitWidth = *b++;
        o->hitOffsetY = *b++;
        o->hitHeight = *b++;
        readAnimFrameCount(o);
    case 1:
        tickAnimation(o);
        if (o->visible && (((*(SPADBlock_2659C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2659C *)&SCRATCHPAD).i198) & 0x1f) == 0) playSFX(0x76);
        applyFrameVelocityX(o);
        if (func_80043AB0(o, o->h->p.whole + 0x18, o->y.p.whole, 0)) {
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        if (o->visible && (((*(SPADBlock_2659C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2659C *)&SCRATCHPAD).i198) & 0x1f) == 0) playSFX(0x76);
        tickAnimation(o);
        o->y.p.whole++;
        func_80043AB0(o, o->h->p.whole + 0x18, o->y.p.whole, 0);
        if (o->y.p.whole > D_800A38EA + 0x98) o->state = 3;
        break;
    }
    if (isObjectPastReferenceX(o) == 1 && o->visible == 0) o->state = 3;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801267DC);
typedef struct SPADBlock_267DC {
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
} SPADBlock_267DC;

typedef struct { s16 w0, w2; } X_267DC;
#define XS(o) ((X_267DC *)((char *)(o) + 0xb4))
extern void *D_801388D4[];

static __inline__ s32 Side_267DC(GameObject *o)
{
    u16 w = o->unk7A;
    s32 d;
    if (w & 1) d = -0x18;
    else d = 0x18;
    return func_80043AB0(o, (s16)(o->h->p.whole + d), o->y.p.whole, (s16)w);
}

static __inline__ s32 Ground_267DC(GameObject *o)
{
    u8 t;
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return 1;
    }
    if ((s16)probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0xe)) != 0) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            t = (*(u16*)&(*(SPADBlock_267DC *)&SCRATCHPAD).s27e) * 4 + o->unk8C;
            if (t) {
                s32 w;
                if (t < 0x80) w = o->unk8C - 1; else w = o->unk8C + 1;
                o->unk8C = w;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
        return 1;
    }
    return 0;
}

#define SETANIM8(o) { \
    u8 *p; \
    x->w0 = 1; \
    *(volatile s16 *)&o->unkAC = 8; \
    p = &D_80135000[o->unkAC * 4]; \
    o->anim = D_801388D4[0]; \
    o->hitOffsetX = *p++; \
    o->hitWidth = *p++; \
    o->hitOffsetY = *p; \
    o->hitHeight = p[1]; \
    readAnimFrameCount(o); \
}

#define SPAWN(o) { \
    GameObject *e = allocObjectLayer3(); \
    if (e) { \
        e->active = 2; \
        e->type = 0x2f; \
        e->animFrame = 1 - o->unk7A; \
        e->x.p.whole = o->x.p.whole; \
        e->y.p.whole = o->y.p.whole; \
        e->z.p.whole = o->z.p.whole; \
        e->unk8C = o->unk8C; \
    } \
}

void func_801267DC(GameObject *o)
{
    X_267DC *x = XS(o);

    switch (o->step) {
    case 0:
        if (x->w0 == 0 && o->unk98 == 0) {
            o->step = 4;
            break;
        }
        if (x->w2) {
            x->w2 += o->unk68;
            if (x->w2 > 5) x->w2 = 5;
            o->unk68 = 1;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->unk9A = 0;
            o->step = 4;
            o->unk7 = 0;
            break;
        }
        o->velV = -0x400;
        o->movetab = D_80077214;
        o->unk8C = 0;
        o->unk9C = 1;
        o->step++;
        break;
    case 1:
        tickAnimation(o);
        applyAnimVelocityX(o, (u16)o->unk7A);
        Side_267DC(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if ((s16)func_80043D2C(o, o->h->p.whole, (s16)(o->y.p.whole - 0x10))) o->velV = 0;
        if (o->velV > 0) {
            o->touchFlag = 0;
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        applyAnimVelocityX(o, (u16)o->unk7A);
        Side_267DC(o);
        if (Ground_267DC(o)) {
            o->unk9C = 0;
            o->velH = 0x180;
            o->step++;
        }
        break;
    case 3:
        if ((s16)Side_267DC(o)) o->velH = 0;
        applyFrameVelocityY(o);
        Ground_267DC(o);
        if (o->unk7A & 1) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        o->velH -= 0x20;
        if (o->velH < 0) {
            o->velH = 0;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->step = 1;
            o->unk7 = 0;
        }
        break;
    case 4:
        if (o->subtype == 2 && o->unk9C) {
            SETANIM8(o);
            SPAWN(o);
            o->velV = -0x400;
            o->movetab = D_80077214;
            o->unk8C = 0;
            o->step++;
            o->unk9C = 1;
            o->step = 1;
            playSFX(0x77);
            break;
        }
        if ((u8)(o->unk8C - 0x70) < 0x21) {
            o->active = 5;
            o->step++;
            break;
        }
        playSFX(0x77);
        o->active = 1;
        o->state = 1;
        o->subState = 1;
        o->step = 1;
        o->unk7 = 0;
        SETANIM8(o);
        SPAWN(o);
        break;
    case 5:
        o->velV = 0;
        o->touchFlag = 0;
        o->unk9C = 2;
        if (o->unk8C >= 0x80) o->step = 6;
        else o->step = 7;
        break;
    case 6:
    case 7:
        if (o->step == 6) o->unk8C += 8;
        else o->unk8C -= 8;
        o->unk8C = *(u8 *)&o->unk8C;
        o->velV += 0x20;
        if (o->velV > 0x600) o->velV = 0x600;
        o->y.raw += o->velV << 8;
        if (Ground_267DC(o)) {
            o->unk8C = (-(s16)(*(u16*)&(*(SPADBlock_267DC *)&SCRATCHPAD).s27e) << 2) & 0xff;
            o->active = 1;
            o->state = 1;
            o->subState = 1;
            o->step = 2;
            o->unk7 = 0;
            SETANIM8(o);
            SPAWN(o);
        }
        break;
    }
}
#undef XS
#undef SETANIM8
#undef SPAWN

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127098);
typedef struct SPADBlock_27098 {
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
} SPADBlock_27098;

extern void spawnItemNotification(s32, s32);

static __inline__ void setAnimN_27098(GameObject *o, s16 n)
{
    u8 *p;
    o->unkAC = n;
    o->anim = D_801388B4[n];
    p = &D_80135000[o->unkAC * 4];
    o->hitOffsetX = *p++;
    o->hitWidth = *p++;
    o->hitOffsetY = *p;
    o->hitHeight = p[1];
    readAnimFrameCount(o);
}

static __inline__ void fall_27098(GameObject *o)
{
    u32 t;
    o->y.p.whole++;
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return;
    }
    if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0xe)) {
        if (o->unkAC >= 0xc) {
            o->unk8C = 0;
        } else {
            t = (((*(u16*)&(*(SPADBlock_27098 *)&SCRATCHPAD).s27e) << 2) + o->unk8C) & 0xff;
            if (t) {
                if (t < 0x80) o->unk8C--;
                else o->unk8C++;
                o->unk8C = *(u8 *)&o->unk8C;
            }
        }
    }
}

void func_80127098(GameObject *o)
{
    s16 *w = &o->unkB4;
    u8 t;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        spawnItemNotification(2, 6);
        if (w[1] == 0 || w[1] == 5) {
            o->step = 2;
            o->timer = 2;
            setAnimN_27098(o, 9);
        } else {
            o->timer = 7;
            o->step++;
            w[1]++;
            setAnimN_27098(o, D_801350AB[w[1]]);
        }
        break;
    case 1:
        if (--o->timer == -1) o->step = 0;
        fall_27098(o);
        break;
    case 2:
        if (--o->timer == -1) o->step++;
        fall_27098(o);
        break;
    case 3:
        {
        u8 t;
        u8 *p;
        ((u8*)&PLAYER.obj.step)[0] = 2;
        ((u8*)&PLAYER.obj.unkAC)[0] = 3;

        t = *(volatile u8 *)&o->step;
        *(volatile s16 *)&o->unkAC = 10;
        o->step = t + 1;
        o->anim = D_801388B4[10];
        p = &D_80135000[o->unkAC * 4];
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1];
        readAnimFrameCount(o);
        }
        break;
    case 4:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801273B0);
typedef struct B_273B0 { u8 c[4]; } B_273B0;
extern void applyAnimVelocityX(GameObject *, u16);

void func_801273B0(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unkB = 1;
        o->active = 2;
        o->unkF = 4;
        o->unkA = 2;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unk8C = 0;
        o->unk88 = 0;
        o->unk84 = 0;
        o->animFrame &= 1;
        o->step++;
        if (o->subtype == 3)
            o->unkAC = 4;
        else
            o->unkAC = 10;
        o->anim = D_801388B4[o->unkAC];
        { u8 *p = ((B_273B0 *)&D_80135000)[o->unkAC].c;
        o->hitOffsetX = *p++;
        o->hitWidth = *p++;
        o->hitOffsetY = *p;
        o->hitHeight = p[1]; }
        readAnimFrameCount(o);
        break;
    case 1:
        applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400)
            o->velV = 0x400;
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1)
        o->unk8C = (o->unk8C + 0x14) & 0xff;
    else
        o->unk8C = (o->unk8C - 0x14) & 0xff;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_8012754C);
typedef struct SPADBlock_2754C {
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
} SPADBlock_2754C;

typedef struct GVars_2754C {
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
} GVars_2754C;

typedef struct { s16 a, b, x, y, z; } Q_2754C;
typedef struct { char p[0xd2]; s16 wd2; } E_2754C;
typedef void (*Fn_2754C)(GameObject *);

extern Fn_2754C D_801350BC[];
extern u16 D_8013508C[];
extern void func_80124B84(GameObject *);
extern void func_80124CFC(GameObject *);
extern void func_80023020(GameObject *);
extern void freeObjectLayer2(GameObject *);
extern s32 func_80022F6C(GameObject *);

void func_8012754C(GameObject *o)
{
    Q_2754C *q = (Q_2754C *)&o->unkB4;
    s16 yy;
    u32 v;

    switch (o->state) {
    case 0:
        if (o->subState == 0) {
            q->x = o->h->p.whole;
            q->y = o->y.p.whole;
            q->z = o->d->p.whole;
            o->tpage = 0xb;
            o->subState++;
            o->spriteBank = ((s32*)&(*(SPADBlock_2754C *)&SCRATCHPAD).i2dc)[0];
        } else {
            q->a = 0;
            q->b = 0;
            *(s8 *)&o->unkF = -9;
            o->unk84 = 0;
            o->unk88 = 0;
            o->touchFlag = 0;
            o->unk98 = 3;
            o->unk9A = 0;
            o->unk68 = 0;
            o->unk9E = 0;
            o->subState = 0;
            *(s32 *)&o->anim = 0;
            o->state++;
        }
        break;
    case 1:
        if ((*(GVars_2754C *)&D_8009BC98).b42) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        if (!(o->unk68 | o->unk9E)) {
            switch (o->subState) {
            case 0:
                D_801350BC[o->subtype](o);
                break;
            case 1:
                switch (o->step) {
                case 0:
                    func_80124B84(o);
                    break;
                case 1:
                    func_80124CFC(o);
                    break;
                case 2:
                    func_80125048(o);
                    break;
                case 3:
                    func_8012567C(o);
                    break;
                case 4:
                    func_80125EB8(o);
                    break;
                }
                break;
            }
        } else {
            if (o->unk9E) {
                if (o->unk9F == 0) {
                    ((E_2754C *)o)->wd2 = o->h->p.whole;
                    o->unk9F = 15;
                } else {
                    o->h->p.whole = (s16)(((E_2754C *)o)->wd2 - 2) + (((s32 (*)(void))nextRandom)() & 3);
                    if (--o->unk9F == 0) {
                        o->unk9E = 0;
                        o->h->p.whole = ((E_2754C *)o)->wd2;
                    }
                }
            } else {
                if (o->unk9A == 0) {
                    o->unk30 = o->h->p.whole;
                    o->unk9A = 0x14;
                } else {
                    o->h->p.whole = (s16)(o->unk30 - 2) + (((s32 (*)(void))nextRandom)() & 3);
                    if (o->unkAC != 0x1e && q->b == 0) {
                        if (o->unk7A) o->unk30--;
                        else o->unk30++;
                        if (func_80124A44(o, o->unk7A)) {
                            if (o->unk7A) o->unk30++;
                            else o->unk30--;
                        }
                        yy = o->y.p.whole;
                        o->y.p.whole = yy + 2;
                        if (o->touchFlag == 1) {
                            o->touchFlag = 0;
                        } else if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(yy + 0x10))) {
                            if (o->unkAC >= 0xc) {
                                o->unk8C = 0;
                            } else {
                                v = (((*(u16*)&(*(SPADBlock_2754C *)&SCRATCHPAD).s27e) << 2) + o->unk8C) & 0xff;
                                if (v != 0) {
                                    if (v < 0x80) o->unk8C = o->unk8C - 1;
                                    else o->unk8C = o->unk8C + 1;
                                    o->unk8C = *(u8 *)&o->unk8C;
                                }
                            }
                        }
                    }
                    if (--o->unk9A == 0) {
                        o->unk68 = 0;
                        if (o->unkAC == 0x1e || q->b != 0) o->h->p.whole = o->unk30;
                    }
                }
            }
        }
        o->unk9D = 0;
        break;
    case 2:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            func_801267DC(o);
            if (!o->visible) func_80023020(o);
            break;
        case 1:
            func_80127098(o);
            break;
        case 2:
            func_801273B0(o);
            if (!o->visible) o->state = 3;
            break;
        }
        break;
    case 3:
        if (o->subtype >= 2) {
            (*(s16 *)o->unk90)--;
            freeObjectLayer2(o);
        } else {
            *(s8 *)&o->unkF = -9;
            o->timer = D_8013508C[((s32 (*)(void))nextRandom)() & 7] + 0x12c;
            o->unkB = 0;
            o->h->p.whole = q->x;
            o->y.p.whole = q->y;
            o->d->p.whole = q->z;
            o->state++;
        }
        break;
    case 4:
        if (o->timer) {
            o->timer--;
        } else if ((((*(SPADBlock_2754C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2754C *)&SCRATCHPAD).i198) & 0x3f) == 0 && !func_80022F6C(o)) {
            o->active = 1;
            o->state = 0;
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127B48);
extern s32 D_1F8002DC[];
extern void *D_801388C8[];
extern void freeObjectLayer3(GameObject *);

void func_80127B48(GameObject *o)
{
    s32 t;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xb;
        o->unkA = 2;
        o->unk84 = 0;
        o->unk88 = 0;
        o->spriteBank = D_1F8002DC[0];
        o->unkAC = 5;
        o->anim = D_801388C8[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) != 0) {
            switch (o->subState) {
            case 0:
                o->unkB = 1;
                o->unkF = 4;
                o->velV = -0x400;
                o->movetab = ((char *)&D_8007722C);
                o->unkAC = 5;
                o->subState++;
                o->anim = D_801388C8[0];
                readAnimFrameCount(o);
                break;
            case 1:
                applyAnimVelocityX(o, 1 - o->animFrame);
                o->velV += 0x40;
                if (o->velV > 0x400)
                    o->velV = 0x400;
                o->y.raw += o->velV << 8;
                break;
            }
            if (o->animFrame & 1)
                t = o->unk8C + 0x14;
            else
                t = o->unk8C - 0x14;
            o->unk8C = t & 0xff;
        } else {
            o->state = 3;
        }
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127D18);
typedef struct { void **anims; s32 a; s32 b; } AT_27D18;
extern AT_27D18 D_801350D4[];
extern void advanceAnimFrame(GameObject *, s16);

void func_80127D18(GameObject *o, s16 n, s16 k)
{
    o->anim = D_801350D4[o->subtype].anims[n];
    advanceAnimFrame(o, k);
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127D6C);
typedef struct GCDBlock_27D6C {
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
} GCDBlock_27D6C;
extern GCDBlock_27D6C D_8009C068;

typedef struct { s32 *p; s32 pad[2]; } E12_27D6C;

void func_80127D6C(GameObject *o)
{
    u8 *c;

    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = (void *)((E12_27D6C *)&D_801350D4)[o->subtype].p[1];
        readAnimFrameCount(o);
        o->velX = -0x200;
        o->velY = 0x800;
        o->step++;
    case 1:
        if (D_8009C068.bceef) {
            o->anim = (void *)((E12_27D6C *)&D_801350D4)[o->subtype].p[1];
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        if (o->h->p.whole < 0x1f4) {
            o->h->p.whole = 0x1f4;
        }
        o->y.raw += o->velY << 8;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10)) && o->h->p.whole < 0x1f5) {
            o->animFrame = 0;
            c = &D_8009C068.bceef;
            *c = *c + 1;
            o->step++;
        }
        break;
    case 3:
        if (D_8009C068.bceef == 4) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80127F58);
typedef struct GCDBlock_27F58 {
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
} GCDBlock_27F58;

void func_80127F58(GameObject *o)
{
    u8 *c;

    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->anim = D_801350D4[o->subtype].anims[1];
        readAnimFrameCount(o);
        o->velX = -0x200;
        o->velY = 0x800;
        o->step++;
    case 1:
        tickAnimation(o);
        if (D_8009C068.bceef) {
            o->anim = D_801350D4[o->subtype].anims[1];
            readAnimFrameCount(o);
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        if (o->h->p.whole < 0x218) o->h->p.whole = 0x218;
        o->y.raw += o->velY << 8;
        if (((s16 (*)(GameObject *o, s16 x, s16 y))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10) && o->h->p.whole < 0x219) {
            c = &D_8009C068.bceef;
            *c = *c + 1;
            o->step++;
        }
        break;
    case 3:
        if (D_8009C068.bceef == 4) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128148);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_801282F0);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128498);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_4", func_80128514);
