#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_80127D64);
typedef struct SPADBlock_27D64 {
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
} SPADBlock_27D64;

typedef struct { s16 w0, w2, w4, w6, w8; } S_27D64;
extern char D_80077208[];
extern void *D_8013EFE8[];
extern void *D_8013EFEC[];
extern void *D_8013EFF0[];
extern void *D_8013F03C[];
extern void *D_8013F040[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void playSFX(s32);
extern void applyFrameVelocityX(GameObject *);
extern void applyAnimVelocityX(GameObject *, u16);
extern s16 func_80043AB0(GameObject *, s16, s16, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);
extern s16 func_80043D2C(GameObject *, s16, s16);
extern void func_80127448(GameObject *);

static __inline__ void setAnim_27D64(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

static __inline__ s16 chk_27D64(GameObject *o)
{
    S_27D64 *q = (S_27D64 *)&o->unkB4;
    s16 f;
    s16 d;

    if (o->unk8C & 0x80) {
        d = -0x10;
        f = 1;
    } else {
        d = 0x10;
        f = 0;
    }
    if ((o->unk9D & 2) && f == (o->unk9D & 1)) {
        q->w6 = 1;
        return 1;
    }
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f)) {
        q->w6 = 0;
        return 1;
    }
    return 0;
}

static __inline__ s32 land_27D64(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->unkAE = -1;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkBA = 1;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        o->unkBA = 0;
        o->unkB2 = D_1F80027E;
        o->unkAE = D_1F800284;
        o->unk8C = (-D_1F80027E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_80127D64(GameObject *o)
{
    S_27D64 *p = (S_27D64 *)&o->unkB4;
    s32 dy, dx;

    if (o->visible && (((*(SPADBlock_27D64 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_27D64 *)&SCRATCHPAD).i198) & 0xf) == 0) playSFX(0x5e);
    switch (o->step) {
    case 0:
        o->unk9C = 0;
        if (p->w8) {
            if (o->unkB0 == 0) {
                if (o->animFrame & 1) o->unk8C = 0x40;
                else o->unk8C = 0xc0;
                o->movetab = ((char *)&D_800771FC);
                if (p->w6) o->step = 10;
                else o->step = 7;
                o->unkAC = 0x16;
            } else {
                o->unkAC = 2;
                o->step++;
                o->animFrame = 1 - o->animFrame;
            }
        } else {
            if (o->unkB0 == 0) {
                o->unkAC = 2;
                o->step++;
            } else {
                if (o->animFrame & 1) o->unk8C = 0x40;
                else o->unk8C = 0xc0;
                o->movetab = ((char *)&D_800771FC);
                o->animFrame = 1 - o->animFrame;
                if (p->w6) o->step = 10;
                else o->step = 7;
                o->unkAC = 0x16;
            }
        }
        setAnim_27D64(o, D_8013EFE8[o->unkAC]);
        break;
    case 1:
        if (!tickAnimation(o)) break;
        if (p->w8) {
            o->animFrame = 1 - o->animFrame;
            p->w8 = 0;
        }
        o->step++;
        if (o->animFrame & 1) o->unk8C = 0xc0;
        else o->unk8C = 0x40;
        o->unkAC = 1;
        setAnim_27D64(o, D_8013EFEC[0]);
        break;
    case 2:
        tickAnimation(o);
        if (o->unk8C & 0x80) {
            if (o->unkB0 == 0) {
                dy = -0x80;
                o->animFrame = 1;
            } else {
                dy = 0x80;
                o->animFrame = 0;
            }
            dx = -0x300;
        } else {
            if (o->unkB0 == 0) {
                dy = -0x80;
                o->animFrame = 0;
            } else {
                dy = 0x80;
                o->animFrame = 1;
            }
            dx = 0x300;
        }
        o->y.raw += dy << 8;
        o->h->raw += dx << 8;
        if (!chk_27D64(o)) {
            if (o->unkB0 & 1) {
                if (p->w6) o->step = 13;
                else o->step = 11;
            } else {
                if (p->w6) o->step = 8;
                else o->step = 3;
            }
            break;
        }
        if (o->unkB0 & 1) {
            if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
                p->w8 = 0;
                o->step = 5;
                break;
            }
        } else {
            if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
                p->w8 = 1;
                o->step = 5;
                break;
            }
        }
        if (--o->timer == -1) {
            o->timer = 0x80;
            func_80127448(o);
            if (o->subState == 1) {
                o->subState = 2;
                o->unkA7 = 0;
                if (o->cooldownTimer == 2) {
                    if (o->y.p.whole > o->unkB6) o->unkB0 = 0;
                    else o->unkB0 = 1;
                }
            } else {
                o->step = 0;
                o->unkA7 = 0;
            }
        }
        break;
    case 3:
    case 8:
        o->movetab = D_80077208;
        o->unk8C = 0;
        o->unkAC = 0x15;
        o->step++;
        setAnim_27D64(o, D_8013F03C[0]);
        break;
    case 4:
        applyFrameVelocityX(o);
        o->y.raw -= 0xc000;
        if (tickAnimation(o)) {
            o->subState = 1;
            o->y.raw += 0x40000;
            o->step = 0;
            land_27D64(o);
        }
        break;
    case 5:
        if (p->w8) {
            if (o->animFrame & 1) o->unk8C = 0xc0;
            else o->unk8C = 0x40;
        }
        o->movetab = D_80077208;
        o->touchFlag = 0;
        o->unkAC = 2;
        o->step++;
        setAnim_27D64(o, D_8013EFF0[0]);
        break;
    case 6:
        if (p->w8) {
            applyAnimVelocityX(o, 1 - o->animFrame);
            o->y.raw -= 0x8000;
            if (tickAnimation(o)) {
                o->step = 0;
                if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
                    o->unk8C = ((-D_1F80027E << 2) + 0x80) & 0xff;
                    p->w6 = 0;
                    o->subState = 8;
                    o->unkAC = 1;
                    o->animFrame = 1 - o->animFrame;
                    setAnim_27D64(o, D_8013EFEC[0]);
                } else {
                    p->w8 = 0;
                    o->subState = 7;
                }
            } else {
                func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10);
            }
        } else {
            applyFrameVelocityX(o);
            o->y.raw += 0x8000;
            if (tickAnimation(o)) {
                o->step = 0;
                if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
                    o->unkB2 = D_1F80027E;
                    o->unk8C = (-D_1F80027E << 2) & 0xff;
                    o->unkAE = D_1F800284;
                    p->w6 = 0;
                    o->subState = 1;
                    o->unkAC = 1;
                    setAnim_27D64(o, D_8013EFEC[0]);
                } else {
                    o->subState = 7;
                }
            } else {
                probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10);
            }
        }
        break;
    case 7:
        if (p->w8) {
            applyFrameVelocityX(o);
            o->y.p.whole--;
        } else {
            applyAnimVelocityX(o, 1 - o->animFrame);
            o->y.p.whole++;
        }
        if (!tickAnimation(o)) break;
        if (p->w8) {
            p->w8 = 0;
            o->animFrame = 1 - o->animFrame;
        } else if (o->animFrame & 1) {
            o->unk8C = 0xc0;
            o->animFrame = 0;
        } else {
            o->unk8C = 0x40;
            o->animFrame = 1;
        }
        o->step = 2;
        o->unkAC = 1;
        setAnim_27D64(o, D_8013EFEC[0]);
        break;
    case 9:
        applyFrameVelocityX(o);
        if (tickAnimation(o)) {
            o->subState = 1;
            o->step = 0;
            o->y.p.whole += 4;
        }
        break;
    case 10:
        if (p->w8) o->y.p.whole--;
        else o->y.p.whole++;
        if (!tickAnimation(o)) break;
        if (p->w8) {
            p->w8 = 0;
            if (o->animFrame & 1) {
                o->animFrame = 0;
                o->unk8C = 0x40;
            } else {
                o->unk8C = 0xc0;
                o->animFrame = 1;
            }
        } else if (o->animFrame & 1) {
            o->unk8C = 0xc0;
            o->animFrame = 0;
            o->h->p.whole -= 3;
        } else {
            o->unk8C = 0x40;
            o->animFrame = 1;
            o->h->p.whole += 3;
        }
        o->step = 2;
        o->unkAC = 1;
        setAnim_27D64(o, D_8013EFEC[0]);
        break;
    case 11:
    case 13:
        o->unk8C = 0x80;
        o->movetab = D_80077208;
        o->touchFlag = 0;
        o->unkAC = 0x16;
        o->animFrame = 1 - o->animFrame;
        o->step++;
        setAnim_27D64(o, D_8013F040[0]);
        break;
    case 12:
        applyFrameVelocityX(o);
        o->y.raw += 0x5000;
        if (tickAnimation(o)) {
            o->step = 0;
            o->y.p.whole -= 4;
            if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
                o->unk8C = ((-D_1F80027E << 2) + 0x80) & 0xff;
                p->w6 = 0;
                o->subState = 8;
            } else {
                o->subState = 7;
            }
        }
        break;
    case 14:
        applyFrameVelocityX(o);
        if (tickAnimation(o)) {
            o->touchFlag = 0;
            o->y.p.whole -= 3;
            o->step++;
        }
        break;
    case 15:
        o->step = 0;
        if (o->touchFlag == 4) {
            p->w6 = 1;
            o->touchFlag = 0;
            o->subState = 8;
        } else if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            o->touchFlag = 0;
            o->unk8C = ((-D_1F80027E << 2) + 0x80) & 0xff;
            p->w6 = 0;
            o->subState = 8;
        } else {
            o->subState = 7;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_801288C0);
typedef struct SPADBlock_288C0 {
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
} SPADBlock_288C0;

typedef struct { s16 w0, w2, w4, w6, w8; } S_288C0;
extern u8 D_8013BB00[];
extern char D_80077214[];
extern void *D_8013EFFC;
extern void *D_8013EFF4;
extern void *D_8013F018;

#define SET_ANIM(o, a) do { (o)->anim = (a); readAnimFrameCount(o); } while (0)

static __inline__ s16 chk_288C0(GameObject *o)
{
    S_288C0 *q = (S_288C0 *)&o->unkB4;
    s32 f;
    s16 d;

    if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1)) {
        o->unkBA = 1;
        return 1;
    }
    f = o->animFrame & 1;
    if ((u16)f) d = -0x10;
    else d = 0x10;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f)) {
        q->w6 = 0;
        return 1;
    }
    return 0;
}

static __inline__ u8 below_288C0(GameObject *o)
{
    return o->y.p.whole <= o->unkB6;
}

void func_801288C0(GameObject *o)
{
    S_288C0 *p = (S_288C0 *)&o->unkB4;
    s32 t;

    switch (o->step) {
    case 0:
        o->touchFlag = 0;
        o->unk9C = 0;
        o->unkAC = 5;
        o->step++;
        SET_ANIM(o, D_8013EFFC);
        break;
    case 1:
        if (tickAnimation(o))
            o->step++;
        break;
    case 2:
        o->unk9C = 1;
        o->unkAC = 3;
        SET_ANIM(o, D_8013EFF4);
        t = o->unk8C - 0x21;
        o->movetab = D_80077214;
        if ((u32)t < 0xc0) {
            o->velH = 0x300;
            o->step = 7;
            if (o->unk8C & 0x80)
                o->animFrame = 0;
            else
                o->animFrame = 1;
        } else {
            o->step++;
        }
        break;
    case 3:
        o->unk9C = 1;
        o->touchFlag = 0;
        o->unk8C = 0;
        o->velV = -0x400;
        o->step++;
    case 4:
        tickAnimation(o);
        o->velV += 0x20;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->unk9C = 1;
            o->step++;
        } else if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            o->velV = 0;
        }
        break;
    case 5:
        o->unk8C = 0;
        if (o->cooldownTimer)
            o->velV = -0x500;
        else if (D_8013BB00[nextRandom() & 0xf])
            o->velV = -0x500;
        else
            o->velV = -0x400;
        o->unk9C = 1;
        o->touchFlag = 0;
        o->unkAC = 0xc;
        o->step++;
        SET_ANIM(o, D_8013F018);
        break;
    case 6:
        tickAnimation(o);
        if (o->cooldownTimer && !below_288C0(o)) {
            if (o->velV > -0x100)
                o->velV = -0x100;
        } else {
            o->velV += 0x40;
        }
        o->y.raw += o->velV << 8;
        if (o->velV > 0) {
            o->subState = 5;
            o->step = 0;
            break;
        }
        if (o->touchFlag != 4 && !func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10))
            break;
        o->velV = 0;
        if (o->touchFlag == 4) {
            p->w6 = 1;
            o->unkB2 = 0x80;
        } else {
            o->unkB2 = ((-(*(SPADBlock_288C0 *)&SCRATCHPAD).s27e << 2) + 0x80) & 0xff;
            p->w6 = 0;
        }
        {
            s32 d = o->unk8C;
            if ((u32)((d - (u16)o->unkB2) & 0xff) > 0x80)
                o->step = 8;
            else
                o->step = 9;
        }
        break;
    case 7:
        o->velH -= 0x10;
        if (o->velH < 0) {
            o->velH = 0;
            o->step = 3;
        }
        if (o->animFrame & 1) {
            if (o->unk8C) o->unk8C--;
            o->h->raw -= o->velH << 8;
        } else {
            if (o->unk8C) o->unk8C++;
            o->h->raw += o->velH << 8;
        }
        o->unk8C = *(u8 *)&o->unk8C;
        o->y.raw += -0x8000;
        tickAnimation(o);
        func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10);
        chk_288C0(o);
        break;
    case 8:
        o->unk8C += 2;
        if ((u32)((o->unk8C - (u16)o->unkB2) & 0xff) < 0x80) {
            if (o->cooldownTimer)
                o->animFrame = o->h->p.whole > o->unkB4;
            else
                o->animFrame = (*(s16*)((char*)&(*(SPADBlock_288C0 *)&SCRATCHPAD).i168 + 2)) < o->h->p.whole;
            o->subState = 8;
            o->step = 0;
            o->unkAC = 1;
            o->unk8C = o->unkB2;
            SET_ANIM(o, (*(void **)&D_8013EFEC));
        }
        break;
    case 9:
        o->unk8C -= 2;
        if ((u32)((o->unk8C - (u16)o->unkB2) & 0xff) > 0x80) {
            if (o->cooldownTimer)
                o->animFrame = o->h->p.whole > o->unkB4;
            else
                o->animFrame = (*(s16*)((char*)&(*(SPADBlock_288C0 *)&SCRATCHPAD).i168 + 2)) < o->h->p.whole;
            o->subState = 8;
            o->step = 0;
            o->unkAC = 1;
            o->unk8C = o->unkB2;
            SET_ANIM(o, (*(void **)&D_8013EFEC));
        }
        break;
    }
}
#undef SET_ANIM

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_80128E64);
extern void *D_8013EFFC_VoidPtrArr[] asm("D_8013EFFC");

void func_80128E64(GameObject *o)
{
    s32 r;
    s16 t;

    switch (o->step) {
    case 0:
        o->unk9C = 2;
        if (o->unk8C == 0) o->step = 3;
        else if (o->unk8C >= 0x80) o->step = 1;
        else o->step = 2;
        break;
    case 1:
        o->unk8C += 4;
        if (o->unk8C >= 0x100) {
            o->step = 3;
            o->unk8C = 0;
        }
        o->velV += 8;
        o->y.raw += o->velV << 8;
        break;
    case 2:
        o->unk8C -= 4;
        if (o->unk8C <= 0) {
            o->step = 3;
            o->unk8C = 0;
        }
        o->velV += 8;
        o->y.raw += o->velV << 8;
        break;
    case 3:
        o->hitOffsetX = 0x10;
        o->hitWidth = 0x20;
        o->touchFlag = 0;
        o->unk6A = 1;
        o->step++;
    case 4:
        if (o->unk6A == 2) {
            *(s8 *)&o->unkF = -11;
            playSFX(0x5f);
            o->hitOffsetX = 0xc;
            o->hitWidth = 0x18;
            o->subState = 6;
            o->step = 0;
            o->unkAC = 5;
            o->anim = D_8013EFFC_VoidPtrArr[0];
            readAnimFrameCount(o);
            break;
        }
        tickAnimation(o);
        o->velV += 0x10;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->touchFlag == 1) {
            r = 1;
            o->unkAE = -1;
            o->unkB2 = 0;
            o->touchFlag = 0;
            o->unkBA = 1;
        } else if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            r = 1;
            o->touchFlag = 0;
            o->unkBA = 0;
            t = D_1F80027E;
            o->unkB2 = t;
            o->unkAE = D_1F800284;
            o->unk8C = -(t << 2) & 0xff;
        } else {
            r = 0;
        }
        if (r) {
            o->hitOffsetX = 0xc;
            o->hitWidth = 0x18;
            o->unk9C = 0;
            o->unk6A = 0;
            o->touchFlag &= 1;
            func_80127448(o);
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_801290E4);
typedef struct SPADBlock_290E4 {
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
} SPADBlock_290E4;
extern char D_80077220[];

void func_801290E4(GameObject *o)
{
    s16 *q = &o->unkB4;
    s16 *r;
    s32 f, n;
    s32 t;
    s32 af;
    s16 d;

    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->unk9C = 1;
        if (o->cooldownTimer != 0) {
            o->movetab = D_80077220;
            o->timer = 500;
        } else {
            if (D_8013BB00[nextRandom() & 0xf])
                o->movetab = D_80077214;
            else
                o->movetab = D_80077220;
            if (D_8013BB00[nextRandom() & 0xf])
                o->timer = 0x78;
            else
                o->timer = 0x3c;
        }
        o->step++;
        if (o->cooldownTimer)
            o->animFrame = o->h->p.whole > o->unkB4;
        else
            o->animFrame = (*(s16*)((char*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).i168 + 2)) < o->h->p.whole;
        break;
    case 1:
        tickAnimation(o);
        applyFrameVelocityX(o);
        if (o->cooldownTimer == 0) {
            if (o->animFrame) {
                if (!(o->h->p.whole > (*(s16*)((char*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).i168 + 2)))) {
                    o->step = 0;
                    o->subState = 4;
                    break;
                }
            } else {
                if (!(o->h->p.whole < (*(s16*)((char*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).i168 + 2)))) {
                    o->step = 0;
                    o->subState = 4;
                    break;
                }
            }
        } else {
            t = o->h->p.whole > o->unkB4;
            if (t != o->animFrame) {
            o->step = 0;
            o->subState = 4;
            break;
            }
        }
        if (o->touchFlag == 4 || func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            o->velV = 0;
            if (o->touchFlag == 4) {
                q[3] = 1;
                o->unkB2 = 0x80;
            } else {
                o->unkB2 = (-(*(u16*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).s27e) * 4 + 0x80) & 0xff;
                q[3] = 0;
            }
            o->subState = 3;
            n = o->unk8C;
            if ((u32)((n - (u16)o->unkB2) & 0xff) > 0x80)
                o->step = 8;
            else
                o->step = 9;
            break;
        }
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->step = 0;
            o->subState = 4;
            break;
        }
        r = &o->unkB4;
        if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1)) {
            o->unkBA = 1;
            f = 1;
        } else {
            af = o->animFrame & 1;
            if ((u16)af)
                d = -0x10;
            else
                d = 0x10;
            if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, af)) {
                r[3] = 0;
                f = 1;
            } else
                f = 0;
        }
        if (f) {
            if (o->animFrame)
                o->step = 3;
            else
                o->step = 2;
        }
        break;
    case 2:
        o->unk8C = (o->unk8C + 2) & 0xff;
        if (o->unk8C > 0x40) {
            o->unk8C = 0x40;
            o->subState = 2;
            o->step = 2;
            o->unk9C = 0;
            o->unkBC = 0;
            if (o->cooldownTimer ? (o->y.p.whole > o->unkB6) : (o->y.p.whole > (*(s16*)((char*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).i16c + 2))))
                o->unkB0 = 0;
            else
                o->unkB0 = 1;
            o->movetab = ((char *)&D_800771FC);
            o->unkAC = 1;
            o->anim = D_8013EFEC[0];
            readAnimFrameCount(o);
        }
        break;
    case 3:
        o->unk8C = (o->unk8C - 2) & 0xff;
        if (o->unk8C < 0xc0) {
            o->unk8C = 0xc0;
            o->subState = 2;
            o->step = 2;
            o->unk9C = 0;
            if (o->cooldownTimer ? (o->y.p.whole > o->unkB6) : (o->y.p.whole > (*(s16*)((char*)&(*(SPADBlock_290E4 *)&SCRATCHPAD).i16c + 2))))
                o->unkB0 = 0;
            else
                o->unkB0 = 1;
            q[4] = 0;
            o->movetab = ((char *)&D_800771FC);
            o->unkAC = 1;
            o->anim = D_8013EFEC[0];
            readAnimFrameCount(o);
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_801295C8);
extern void *D_8013F000[];
extern void *D_8013F004[];
extern void *D_8013F044[];
extern void decreaseObjectTimer(GameObject *, s32);

void func_801295C8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk9C = 1;
        o->step++;
    case 1:
        if (tickAnimation(o)) {
            o->velV = -0x400;
            o->unkAC = 6;
            o->step++;
            o->anim = D_8013F000[0];
            readAnimFrameCount(o);
        }
        (*(GameObject *)&PLAYER).touchFlag = 1;
        (*(GameObject *)&PLAYER).h->p.whole = o->h->p.whole;
        {
            s16 t = (*(GameObject *)&PLAYER).y.p.whole - 0x18;
            o->velY = o->y.p.whole - t;
        }
        if (o->velY != 0) {
            if (o->velY < 0) (*(GameObject *)&PLAYER).y.p.whole--;
            else (*(GameObject *)&PLAYER).y.p.whole++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->velV += 0x10;
        o->y.raw += o->velV << 8;
        if (o->velV > 0) o->step++;
        else if ((s16)func_80043D2C(o, o->h->p.whole, (s16)(o->y.p.whole - 0x10))) o->velV = 0;
        (*(GameObject *)&PLAYER).touchFlag = 1;
        (*(GameObject *)&PLAYER).h->p.whole = o->h->p.whole;
        (*(GameObject *)&PLAYER).y.p.whole = o->y.p.whole + ((*(GameObject *)&PLAYER).hitHeight - (*(GameObject *)&PLAYER).hitOffsetY);
        break;
    case 3: {
        GameObject *p = &(*(GameObject *)&PLAYER);
        *(s8 *)&o->unkF = -9;
        o->unk6A = 0;
        D_800A53C6 = 2;
        D_800A5416 = 0;
        p->active = 2;
        D_800A539C = 2;
        D_800A539D = 0;
        D_800A539E = 1;
        decreaseObjectTimer(p, 1);
        D_800A5416 = 0x200;
        o->unkAC = 7;
        o->step++;
        o->anim = D_8013F004[0];
        readAnimFrameCount(o);
        break;
    }
    case 4:
        if (tickAnimation(o)) {
            o->active = 1;
            o->step++;
        }
        break;
    case 5:
        o->step++;
        if (D_8013BB00[nextRandom() & 0xf]) o->timer = 0x50;
        else o->timer = 0x32;
        o->unkAC = 0x17;
        o->anim = D_8013F044[0];
        readAnimFrameCount(o);
        break;
    case 6:
        applyFrameVelocityX(o);
        tickAnimation(o);
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->subState = 7;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_80129904);
typedef struct SPADBlock_29904 {
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
} SPADBlock_29904;

void func_80129904(GameObject *o)
{
    s32 r;
    s16 t;

    switch (o->step) {
    case 0:
        o->unk9C = 2;
        o->touchFlag = 0;
        o->unk6A = 0;
        o->unk8C = 0;
        o->velV = 0;
        o->unkAC = 6;
        o->step++;
        o->anim = D_8013F000[0];
        readAnimFrameCount(o);
        break;
    case 1:
        tickAnimation(o);
        o->velV += 0x10;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        if (o->touchFlag == 1) {
            r = 1;
            o->unkAE = -1;
            o->unkB2 = 0;
            o->touchFlag = 0;
            o->unkBA = 1;
        } else if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
            r = 1;
            o->touchFlag = 0;
            o->unkBA = 0;
            t = D_1F80027E;
            o->unkB2 = t;
            o->unkAE = D_1F800284;
            o->unk8C = -(t << 2) & 0xff;
        } else {
            r = 0;
        }
        if (r) {
            o->subState = 1;
            o->step = 0;
            o->touchFlag &= 1;
            if (o->cooldownTimer) o->animFrame = o->h->p.whole > o->unkB4;
            else o->animFrame = (*(s16*)((char*)&(*(SPADBlock_29904 *)&SCRATCHPAD).i168 + 2)) < o->h->p.whole;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_80129ACC);
typedef struct SPADBlock_29ACC {
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
} SPADBlock_29ACC;

typedef struct { s16 w0, w2, w4, w6, w8; } X_29ACC;
extern u8 D_8013BB10[];
extern void *D_8013F018_VoidPtrArr[] asm("D_8013F018");

static __inline__ s16 wall_29ACC(GameObject *o)
{
    X_29ACC *x = (X_29ACC *)((char *)o + 0xb4);
    s32 f;
    s16 d;

    if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1)) {
        o->unkBA = 1;
        return 1;
    }
    f = o->animFrame & 1;
    if ((u16)f) d = -0x10;
    else d = 0x10;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f)) {
        x->w6 = 0;
        return 1;
    }
    return 0;
}

static __inline__ void mv_29ACC(GameObject *o, s32 a, s16 sp)
{
    a &= 0xff;
    o->h->raw += (D_8007DB88[a] * sp) >> 4;
    o->y.raw += (D_8007D788[a] * sp) >> 4;
}

void func_80129ACC(GameObject *o)
{
    X_29ACC *x = (X_29ACC *)((char *)o + 0xb4);
    s16 d;

    switch (o->step) {
    case 0:
        o->unk9C = 0;
        o->unkBC = 1;
        o->unkAC = 1;
        o->step++;
        o->anim = D_8013EFEC[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->visible && !(((*(SPADBlock_29ACC *)&SCRATCHPAD).s1f8 + (*(SPADBlock_29ACC *)&SCRATCHPAD).i198) & 0xf)) playSFX(0x5e);
        tickAnimation(o);
        if (x->w6) {
            {
            s16 sp;
            s16 a;
            d = o->unk8C;
            sp = *(s16 *)o->movetab;
            a = d;
            if (!o->animFrame) a = d + 0x80;
            mv_29ACC(o, a, sp);
            }
            o->y.p.whole -= 2;
        } else {
            applyFrameVelocityX(o);
            o->y.p.whole -= 3;
        }
        if (wall_29ACC(o)) {
            x->w8 = 1;
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 1;
            break;
        }
        if (o->touchFlag == 4) {
            x->w6 = 1;
            o->touchFlag = 0;
        } else if (!func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) {
            x->w8 = 1;
            o->subState = 2;
            o->step = 0;
            o->unkB0 = 0;
            break;
        } else {
            o->touchFlag = 0;
            o->unk8C = (-(*(SPADBlock_29ACC *)&SCRATCHPAD).s27e * 4 + 0x80) & 0xff;
            x->w6 = 0;
        }
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->step++;
        }
        break;
    case 2:
        func_80127448(o);
        o->step = 0;
        if (o->subState == 1) {
            if (D_8013BB00[nextRandom() & 0xf]) o->movetab = D_80077208;
            else o->movetab = D_80077214;
            if (D_8013BB10[nextRandom() & 7]) {
                o->timer = 300;
                o->unkA7 = 0;
            } else {
                o->timer = 200;
                o->unkA7 = 1;
            }
            o->subState = 8;
            o->step = 1;
        } else if (o->subState == 3) {
            o->subState = 4;
            o->velV = 0;
            o->step = 0;
            o->unkAC = 0xc;
            o->anim = D_8013F018_VoidPtrArr[0];
            readAnimFrameCount(o);
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_80129E9C);
extern void *D_8013F034[];
extern void *D_8013F038[];
extern void applyFrameVelocityY(GameObject *);
extern void cloneItemPickupObject(GameObject *);

static __inline__ void setAnim_29E9C(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

static __inline__ s16 wall_29E9C(GameObject *o)
{
    s32 f;
    s16 d;

    f = o->unk7A & 1;
    if (f) d = -0x10;
    else d = 0x10;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, f)) {
        o->unkBA = 0;
        return 1;
    }
    return 0;
}

static __inline__ s32 land_29E9C(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->unkAE = -1;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkBA = 1;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        o->unkBA = 0;
        o->unkB2 = D_1F80027E;
        o->unkAE = D_1F800284;
        o->unk8C = (-D_1F80027E << 2) & 0xff;
        return 1;
    }
    return 0;
}

void func_80129E9C(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (o->unk98 == 0) {
            o->active = 2;
            o->subState = 2;
            o->animFrame = o->unk7A;
            func_800E92D4(0x1f4, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            break;
        }
        o->unk9C = 1;
        o->unk8C = 0;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->animFrame = 1 - o->unk7A;
        o->step++;
        if (o->unkAC == 0xd || o->unkAC == 0x13) o->unkAC = 0xf;
        else o->unkAC = 0xd;
        setAnim_29E9C(o, D_8013EFE8[o->unkAC]);
        break;
    case 1:
        tickAnimation(o);
        applyAnimVelocityX(o, o->unk7A);
        wall_29E9C(o);
        o->velV += 0x40;
        o->y.raw += o->velV << 8;
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) o->velV = 0;
        if (o->velV > 0) {
            o->unk9C = 2;
            o->step++;
        }
        break;
    case 2:
        tickAnimation(o);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        applyAnimVelocityX(o, o->unk7A);
        wall_29E9C(o);
        if (land_29E9C(o)) {
            o->velH = 0x180;
            o->step++;
        }
        break;
    case 3:
        applyFrameVelocityY(o);
        land_29E9C(o);
        if (o->unk7A & 1) o->h->raw -= o->velH << 8;
        else o->h->raw += o->velH << 8;
        if (wall_29E9C(o)) o->velH = 0;
        o->velH -= 0x20;
        if (o->velH < 0) {
            o->velH = 0;
            o->timer = 0x78;
            o->step++;
            if (o->unkAC == 0xd) {
                o->unk50 = 0xc;
                o->active = 1;
                o->unk4E = 0;
                o->unkAC = 0x13;
                setAnim_29E9C(o, D_8013F034[0]);
            } else {
                cloneItemPickupObject(o);
            }
        }
        break;
    case 4:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->timer = 0x80;
            o->step++;
            if (o->unkAC == 0x13) {
                o->unk4E = 7;
                o->unk50 = 0xe;
                o->unkAC = 0x14;
                o->anim = D_8013F038[0];
                readAnimFrameCount(o);
            }
        }
        applyFrameVelocityY(o);
        land_29E9C(o);
        break;
    case 5:
        if (tickAnimation(o)) {
            o->hitOffsetX = 0xc;
            o->hitWidth = 0x18;
            o->active = 1;
            o->unk68 = 0;
            o->state = 1;
            o->subState = 1;
            o->step = 0;
            o->unk9C = 0;
        }
        applyFrameVelocityY(o);
        land_29E9C(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_8012A4BC);
extern void *D_8013F00C[];

void func_8012A4BC(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->active = 2;
        o->unkB = 1;
        o->unkF = 4;
        o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 9;
        o->animFrame &= 1;
        o->step++;
        o->anim = D_8013F00C[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->unk98 == 0) applyFrameVelocityX(o);
        else applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x40;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1) o->unk8C = (o->unk8C + 0x14) & 0xff;
    else o->unk8C = (o->unk8C - 0x14) & 0xff;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_8012A60C);
typedef struct SPADBlock_2A60C {
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
} SPADBlock_2A60C;

typedef struct GCDBlock_2A60C {
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
} GCDBlock_2A60C;
extern GCDBlock_2A60C D_8009C068;

typedef struct GVars_2A60C {
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
} GVars_2A60C;
extern s16 D_800A38E6;
extern u16 D_800A38E4;
extern void *D_8013F008[];
extern void *D_8013F028[];
extern s32 func_80022F6C(GameObject *);
extern void spawnItemNotification(s32, s32);
extern void func_80127608(GameObject *);
extern void func_8012791C(GameObject *);

static __inline__ void setAnim_2A60C(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

static __inline__ s32 land_2A60C(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->unkAE = -1;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkBA = 1;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        o->unkBA = 0;
        o->unkB2 = D_1F80027E;
        o->unkAE = D_1F800284;
        o->unk8C = (-D_1F80027E << 2) & 0xff;
        return 1;
    }
    return 0;
}

static __inline__ void setbox_2A60C(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a; o->hitWidth = b; o->hitOffsetY = c; o->hitHeight = d;
}

static __inline__ void setw_2A60C(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->unk48 = a; o->unk4A = b; o->unk4E = c; o->unk50 = d;
}

typedef struct { GameObject t; char pad[0xd2 - 0xc0]; u16 wd2; } BX;
#define o (&b->t)
void func_8012A60C(BX *b)
{
    s16 *q = &o->unkB4;

    switch (o->state) {
    case 0:
        if (o->subState == 0) {
            q[3] = 0;
            q[0] = o->h->p.whole;
            q[1] = o->y.p.whole;
            q[2] = o->d->p.whole;
            o->spriteBank = ((s32*)&(*(SPADBlock_2A60C *)&SCRATCHPAD).i2d0)[0];
            o->cooldownTimer = 0;
            o->unkD = 0;
            o->unk68 = 0;
            o->tpage = 1;
            o->unkA7 = 0;
            q[4] = 0;
            setw_2A60C(o, 0xc, 0x18, 7, 0xe);
            setbox_2A60C(o, 0xc, 0x18, 0x10, 0x20);
            o->subState++;
        } else {
            o->active = 1;
            *(s8 *)&o->unkF = -9;
            o->unk6A = 0;
            o->unk9E = 0;
            o->touchFlag = 0;
            o->unkB0 = 0;
            o->unk8C = 0;
            o->unk88 = 0;
            o->unk84 = 0;
            o->cooldownTimer = 0;
            o->subState = 0;
            o->unk98 = 3;
            o->unk9A = 3;
            o->anim = 0;
            o->state++;
        }
        break;
    case 1:
        if (o->unkC == 1 && D_8009C068.bceae == 1) {
            o->state = 5;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            break;
        }
        if ((*(GVars_2A60C *)&D_8009BC98).b42) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        if (o->unk9E == 0) {
            switch (o->subState) {
            case 0: func_80127608(o); break;
            case 1: func_8012791C(o); break;
            case 2: func_80127D64(o); break;
            case 3: func_801288C0(o); break;
            case 4: func_80128E64(o); break;
            case 5: func_801290E4(o); break;
            case 6: func_801295C8(o); break;
            case 7: func_80129904(o); break;
            case 8: func_80129ACC(o); break;
            }
            if ((((*(SPADBlock_2A60C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2A60C *)&SCRATCHPAD).i198) & 7) == 0) {
                if (o->y.p.whole > D_800A38EA + 0x98 ||
                    (u16)(o->h->p.whole + 0xaa - D_800A38E4) > D_800A38E6 + 0xb0) {
                    o->state = 3;
                    o->active = 2;
                    o->visible = 0;
                }
            }
        } else if (o->unk9F == 0) {
            s16 t = o->h->p.whole;
            o->unk9F = 0xf;
            b->wd2 = t;
        } else {
            { s32 r = nextRandom() & 3; o->h->p.whole = (s16)(b->wd2 - 2) + r; }
            if (--o->unk9F == 0) {
                o->unk9E = 0;
                o->h->p.whole = b->wd2;
            }
        }
        o->unk9D = 0;
        break;
    case 2:
        switch (o->subState) {
        case 0:
            func_80129E9C(o);
            func_80022E44(o);
            break;
        case 1:
            switch (o->step) {
            case 0:
                o->unk9C = 0;
                spawnItemNotification(1, 6);
                o->hitOffsetY = 4;
                o->hitHeight = 0x14;
                o->unkAC = 8;
                o->step++;
                o->anim = D_8013F008[0];
                readAnimFrameCount(o);
                break;
            case 1:
                break;
            case 2:
                o->step++;
                o->unkAC = 9;
                o->anim = D_8013F00C[0];
                readAnimFrameCount(o);
                break;
            }
            func_80022E44(o);
            break;
        case 2:
            func_8012A4BC(o);
            if (!func_80022E44(o)) o->state = 3;
            break;
        }
        break;
    case 3:
        *(s8 *)&o->unkF = -9;
        o->unkB = 0;
        o->h->p.whole = q[0];
        o->y.p.whole = q[1];
        o->d->p.whole = q[2];
        o->state++;
        break;
    case 4:
        if (o->unkC == 1 && D_8009C068.bceae == 1) {
            o->state = 5;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            break;
        }
        if ((((*(SPADBlock_2A60C *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2A60C *)&SCRATCHPAD).i198) & 0xf) == 0 && !func_80022F6C(o)) {
            o->hitOffsetY = 0x10;
            o->hitHeight = 0x20;
            o->state = 0;
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    case 5:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            o->h->p.whole = 0x304;
            o->y.p.whole = -0x1da;
            o->d->p.whole = q[2];
            o->active = 3;
            *(s8 *)&o->unkF = -9;
            o->hitOffsetY = 0x10;
            o->hitHeight = 0x20;
            o->unk9E = 0;
            o->unk6A = 0;
            o->touchFlag = 0;
            o->unkB0 = 0;
            o->unk8C = 0;
            o->subState++;
            q[4] = 0;
            o->unkAC = 0x10;
            setAnim_2A60C(o, D_8013F028[0]);
            break;
        case 1:
            tickAnimation(o);
            if (D_8009C068.bceae == 2) o->subState++;
            break;
        case 2:
            tickAnimation(o);
            if (D_8009C068.bceae == 3) o->subState++;
            D_1F80018C = o->h->raw;
            (*(SPADBlock_2A60C *)&SCRATCHPAD).i190 = o->y.raw;
            break;
        case 3:
            tickAnimation(o);
            o->y.p.whole -= 4;
            if (o->y.p.whole < -0x3ac) {
                o->velV = -0x400;
                o->subState++;
            }
            o->unk8C = (o->unk8C - 6) & 0xff;
            D_1F80018C = o->h->raw;
            (*(SPADBlock_2A60C *)&SCRATCHPAD).i190 = o->y.raw;
            break;
        case 4:
            tickAnimation(o);
            o->velV += 0x10;
            o->y.raw += o->velV << 8;
            if (o->velV > 0) {
                o->touchFlag = 0;
                o->subState++;
            }
            o->unk8C = (o->unk8C - 6) & 0xff;
            D_1F80018C = o->h->raw;
            (*(SPADBlock_2A60C *)&SCRATCHPAD).i190 = o->y.raw;
            break;
        case 5:
            tickAnimation(o);
            o->velV += 0x10;
            if (o->velV > 0x400) o->velV = 0x400;
            o->y.raw += o->velV << 8;
            o->unk8C = (o->unk8C - 6) & 0xff;
            D_1F80018C = o->h->raw;
            (*(SPADBlock_2A60C *)&SCRATCHPAD).i190 = o->y.raw;
            if (land_2A60C(o)) o->subState++;
            break;
        case 6:
            tickAnimation(o);
            break;
        }
        break;
    }
}
#undef o

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_8012AE50);
typedef struct AE_2AE50 { char p0[2]; u16 i; char p1[2]; u16 v; } AE_2AE50;
typedef struct { char p0[0x24]; AE_2AE50 *a; char p1[4]; u16 t; char p2[0x3e]; u16 b0, b1, b2, b3; } TA_2AE50;
extern u8 D_8013BB38[];

static __inline__ void box_2AE50(TA_2AE50 *o, s32 idx)
{
    u8 *b = D_8013BB38 + idx * 4;
    o->b0 = *b++;
    o->b1 = *b++;
    o->b2 = *b;
    o->b3 = b[1];
}

s32 func_8012AE50(TA_2AE50 *o)
{
    AE_2AE50 *e, *n; u16 v; s32 k;
    o->t = o->t - 1;
    if (o->t != 0) return 0;
    e = o->a;
    v = e->v;
    k = v & 0xc000;
    switch (k) {
    case 0:
        o->a = e + 1;
        box_2AE50(o, e[1].i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x4000:
        o->a = e + 1;
        n = *(AE_2AE50 **)(e + 1);
        o->a = n;
        box_2AE50(o, n->i);
        o->t = o->a->v & 0x3fff;
        break;
    case 0x8000:
        o->t = v & 0x3fff;
        return 1;
    case 0xc000:
        o->a = e + 1;
        n = *(AE_2AE50 **)(e + 1);
        o->a = n;
        box_2AE50(o, n->i);
        o->t = o->a->v & 0x3fff;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_8012AFBC);
typedef struct P_2AFBC { s16 w0; u16 w2; s16 w4; } P_2AFBC;
typedef struct H_2AFBC { char p0[2]; s16 x; } H_2AFBC;
typedef struct O_2AFBC {
    char p0[3]; u8 subtype;
    char p1[0x16 - 4]; s16 y;
    char p2[0x2e - 0x18]; u16 af;
    char p3[0x40 - 0x30]; H_2AFBC *h;
    char p4[0x9d - 0x44]; u8 b9d;
    char p5[0xb4 - 0x9e]; P_2AFBC p;
} O_2AFBC;
extern s16 D_8007D788[];
extern s16 D_8007DB88[];
extern s16 func_80044694(O_2AFBC *, s16, s16);

s32 func_8012AFBC(O_2AFBC *o)
{
    u16 a, b;
    s16 c;
    P_2AFBC *p = &o->p;
    if ((o->b9d & 2) && o->af == (o->b9d & 1))
        return 1;
    if (o->af == 0)
        p->w4 = 0x10;
    else
        p->w4 = -0x10;
    c = (u8)p->w2; p->w2 = c;
    if (c != 0) {
        s32 i = c * 2;
        a = (u32)(p->w4 * *(s16 *)((char *)D_8007D788 + i)) >> 12;
        b = (u32)(p->w4 * *(s16 *)((char *)D_8007DB88 + i)) >> 12;
    } else {
        a = 0;
        b = p->w4;
    }
    return func_80044694(o, (s16)(o->h->x + b), (s16)(o->y + a)) != 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x01/nonmatchings/x01/x01_4", func_8012B0A4);
typedef struct SPADBlock_2B0A4 {
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
} SPADBlock_2B0A4;

typedef struct { s16 w0; u16 w2; s16 w4; u16 w6; } AH_2B0A4;

extern AH_2B0A4 *D_8013CE60[];
extern void updateObjectSideFlag(GameObject *o);
extern void applyFrameVelocityXY(GameObject *o);
extern void func_800EA16C(s16, s32, s32, s32);

static __inline__ s32 land2_2B0A4(GameObject *o)
{
    s16 t;
    s16 w;

    if (o->touchFlag == 1) {
        o->unk8C = 0;
        o->unkB2 = 0;
        o->touchFlag = 0;
        o->unkAE = -1;
        o->unk9C = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        t = (*(SPADBlock_2B0A4 *)&SCRATCHPAD).s27e;
        if (t < 0) t = -t;
        if (t >= 9) t = 8;
        if ((*(SPADBlock_2B0A4 *)&SCRATCHPAD).s27e < 0) t = -t;
        o->unk8C = -t & 0xff;
        o->unkB2 = t;
        w = (*(SPADBlock_2B0A4 *)&SCRATCHPAD).s284;
        o->unkB6 = (-t << 2) & 0xff;
        o->unk9C = 0;
        o->unkAE = w;
        return 1;
    }
    return 0;
}

void func_8012B0A4(GameObject *o)
{
    u8 *p1, *p2;
    s32 r;

    switch (o->unk7) {
    case 0:
        o->unk9D = 0;
        r = nextRandom() & 1;
        if (o->unkC == 0) r = 0;
        if (r == 0) {
            o->unk7 = 2;
            updateObjectSideFlag(o);
            break;
        }
        o->timer = 0x3c;
        o->unkAC = 1;
        o->unk7++;
        o->anim = D_8013CE60[1];
        p1 = &D_8013BB38[((AH_2B0A4 *)o->anim)->w2 * 4];
        o->hitOffsetX = *p1++;
        o->hitWidth = *p1++;
        o->hitOffsetY = *p1++;
        o->hitHeight = *p1;
        o->animTimer = ((AH_2B0A4 *)o->anim)->w6 & 0x3fff;
    case 1:
        func_8012AE50(o);
        if (--o->timer != -1) break;
        o->unk7++;
        updateObjectSideFlag(o);
    case 2:
        o->movetab = ((char *)&D_8007722C);
        o->unkAC = 0;
        o->unk7++;
        o->anim = D_8013CE60[0];
        p2 = &D_8013BB38[((AH_2B0A4 *)o->anim)->w2 * 4];
        o->hitOffsetX = *p2++;
        o->hitWidth = *p2++;
        o->hitOffsetY = *p2++;
        o->hitHeight = *p2;
        o->animTimer = ((AH_2B0A4 *)o->anim)->w6 & 0x3fff;
    case 3:
        applyFrameVelocityXY(o);
        func_8012AE50(o);
        land2_2B0A4(o);
        if (o->h->p.whole >= 0x943) {
            o->active = 2;
            o->state = 3;
            if (o->visible) {
                func_800EA16C(o->h->p.whole + 10, 0x2e, o->d->p.whole, 1);
                func_800EA16C(o->h->p.whole - 10, 0x2e, o->d->p.whole, 1);
            }
        }
        if (o->animFrame) {
            if (o->unkB2 > 0) break;
        } else {
            if (o->unkB2 < 0) break;
        }
        o->step = 8;
        o->unk7 = 0;
        break;
    }
}
