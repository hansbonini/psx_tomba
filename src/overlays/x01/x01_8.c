#include "common.h"
#include "game.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80137888);
typedef struct { s16 z, y, x; } P3_37888;

extern P3_37888 D_8013BD24[];
extern void *D_8013DA88_VoidPtrArr[] asm("D_8013DA88");
extern void *D_8013DA88;
extern s32 D_1F8002D4[];
extern s32 tickAnimation(GameObject *);
extern void readAnimFrameCount(GameObject *);
extern void freeObjectLayer2(GameObject *);
extern void applyObjectAltSpeedVertical(GameObject *);
extern s32 fixedMulSin(s32, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

void func_80137888(GameObject *o)
{
    s32 s1;
    s32 s2;
    s32 b;

    switch (o->state) {
    case 0:
        o->active = 2;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->objectIndex = 1;
        o->x.raw = D_8013BD24[o->unkC].x << 16;
        o->y.raw = D_8013BD24[o->unkC].y << 16;
        o->z.raw = D_8013BD24[o->unkC].z << 16;
        o->tpage = 7;
        *(s8 *)&o->unkF = -9;
        o->unkD = 0x80;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->spriteBank = D_1F8002D4[0];
        o->anim = D_8013DA88;
        readAnimFrameCount(o);
        o->timer = (nextRandom() & 0xff) + 1;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (--o->timer == 0) {
                o->anim = D_8013DA88_VoidPtrArr[1];
                readAnimFrameCount(o);
                o->unk6A = 0;
                o->active = 1;
                o->subState++;
            }
            break;
        case 1:
            if (tickAnimation(o)) {
                o->anim = D_8013DA88_VoidPtrArr[5];
                o->y.p.whole += 0x18;
                readAnimFrameCount(o);
                o->velY = 0;
                o->unk8C = 0;
                o->subState++;
            }
            break;
        case 2:
            if (o->velY < 0x600) o->velY += 0x20;
            applyObjectAltSpeedVertical(o);
            if (o->unk6A && !PLAYER.obj.touchFlag && (*(u8*)&PLAYER.obj.unkAC) < 2 && PLAYER.obj.unk9C && (u8)(PLAYER.obj.unk9E - 5) >= 2)
                PLAYER.obj.y.raw += o->velY << 8;
            if (o->touchFlag) {
                o->anim = D_8013DA88_VoidPtrArr[2];
                readAnimFrameCount(o);
                o->touchFlag = 0;
                o->subState++;
            } else if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 8)) {
                o->unk8C = 0;
                o->active = 2;
                o->anim = D_8013DA88_VoidPtrArr[6];
                readAnimFrameCount(o);
                o->velY = 0;
                o->subState = 6;
            }
            break;
        case 3:
            if (o->touchFlag) {
                o->touchFlag = 0;
                if ((u32)((o->unk8C + 0x40) & 0xff) >= 0x81) {
                    o->anim = D_8013DA88_VoidPtrArr[4];
                    readAnimFrameCount(o);
                    o->cooldownTimer = 4;
                    o->subState++;
                }
                s1 = (o->unk8C + 4) & 0x7f;
                if ((u32)s1 < 8) {
                    if (o->unk6A) {
                        if (tickAnimation(o)) {
                            o->anim = D_8013DA88_VoidPtrArr[9];
                            readAnimFrameCount(o);
                        }
                    } else {
                        o->anim = D_8013DA88_VoidPtrArr[2];
                    }
                } else {
                    s1 = o->unk8C;
                    if (s1 < 0x80) {
                        s1 += 0x80;
                        o->animFrame = 1;
                    } else {
                        o->animFrame = 0;
                    }
                    s1 &= 0xff;
                    s2 = -(s16)fixedMulSin((o->unk8C << 1) & 0x7e, 0x300);
                    b = (s16)fixedMulSin(o->unk8C & 0x7f, 0x400);
                    o->h->raw += (D_8007DB88[s1] * s2) >> 4;
                    o->y.raw += (D_8007D788[s1] * -b) >> 4;
                    if (o->unk6A) {
                        if ((u8)(PLAYER.obj.unk9E - 5) >= 2) {
                            (*(Fix16 **)&PLAYER.obj.h)->raw += (D_8007DB88[s1] * s2) >> 4;
                            PLAYER.obj.y.raw += (D_8007D788[s1] * -b) >> 4;
                        }
                        if (tickAnimation(o)) {
                            o->anim = D_8013DA88_VoidPtrArr[10];
                            readAnimFrameCount(o);
                        }
                    } else {
                        o->anim = D_8013DA88_VoidPtrArr[3];
                    }
                    o->y.p.whole += 2;
                }
                readAnimFrameCount(o);
            } else {
                o->anim = D_8013DA88_VoidPtrArr[4];
                readAnimFrameCount(o);
                o->cooldownTimer = 4;
                o->subState++;
            }
            break;
        case 4:
            if (--o->cooldownTimer == 0) {
                o->anim = D_8013DA88_VoidPtrArr[5];
                readAnimFrameCount(o);
                o->unk6A = 0;
                o->velY = 0;
                o->unk8C = 0;
                o->subState = 2;
            }
            break;
        case 5:
            o->unk8C = 0;
            o->active = 2;
            o->anim = D_8013DA88_VoidPtrArr[6];
            readAnimFrameCount(o);
            o->velY = 0;
            o->subState++;
        case 6:
            if (tickAnimation(o)) {
                o->x.raw = D_8013BD24[o->unkC].x << 16;
                o->y.raw = D_8013BD24[o->unkC].y << 16;
                o->z.raw = D_8013BD24[o->unkC].z << 16;
                o->unk8C = 0;
                o->anim = D_8013DA88;
                readAnimFrameCount(o);
                o->timer = (nextRandom() & 0xff) + 1;
                o->subState = 0;
            }
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80137F84);
typedef struct SPADBlock_37F84 {
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
} SPADBlock_37F84;

extern void *D_8013DAA4[];
extern s32 tickAnimation(GameObject *);
extern void readAnimFrameCount(GameObject *);
extern void freeObjectLayer2(GameObject *);

void func_80137F84(GameObject *o)
{
    u8 s = o->state;
    switch (s) {
    case 0:
        o->active = 2;
        o->tpage = 7;
        *(s8 *)&o->unkF = -9;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkD = 0x80;
        o->spriteBank = ((s32*)&(*(SPADBlock_37F84 *)&SCRATCHPAD).i2d4)[0];
        o->anim = D_8013DAA4[0];
        readAnimFrameCount(o);
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        if (tickAnimation(o)) o->state++;
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80138084);
typedef struct SPADBlock_38084 {
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
} SPADBlock_38084;

void func_80138084(GameObject *o)
{
    switch (o->subtype) {
    case 0:
        func_80137888(o);
        break;
    case 1:
        switch (o->state) {
        case 0:
            o->active = 2;
            o->tpage = 7;
            *(s8 *)&o->unkF = -9;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            o->unkD = 0x80;
            o->spriteBank = ((s32*)&(*(SPADBlock_38084 *)&SCRATCHPAD).i2d4)[0];
            o->anim = D_8013DAA4[0];
            readAnimFrameCount(o);
            o->state++;
            break;
        case 1:
            func_80022E44(o);
            if (tickAnimation(o) != 0) {
                o->state++;
            }
            break;
        case 2:
            o->state++;
            break;
        case 3:
            freeObjectLayer2(o);
            break;
        }
        break;
    }
}
