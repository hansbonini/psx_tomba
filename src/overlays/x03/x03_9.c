#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012C330);

INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012C5D0);

INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012C75C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012C868);
extern s16 func_80043D2C(GameObject *, s16, s16);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

static __inline__ s32 land_2C868(GameObject *o)
{
    if (o->touchFlag == 1) {
        o->touchFlag = 0;
        return 1;
    }
    if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        return 1;
    }
    return 0;
}

s32 func_8012C868(GameObject *o)
{
    switch (o->velX & 7) {
    case 1:
    case 3:
        if (func_80043D2C(o, o->h->p.whole, o->y.p.whole - 0x10)) return 1;
        break;
    case 5:
    case 7:
        if (land_2C868(o)) return 1;
        break;
    }
    if (o->animFrame & 1) {
        if (o->x.p.whole < o->unkB6) return 1;
    } else if (o->y.p.whole < -0x46a) {
        if (o->unkB8 - 0x14 < o->x.p.whole) return 1;
    } else {
        if (o->x.p.whole > o->unkB8) return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012C9BC);
extern s16 func_80043AB0(GameObject *, s16, s16, s16);

s32 func_8012C9BC(GameObject *o)
{
    s16 d;

    if ((o->unk9D & 2) && o->animFrame == (o->unk9D & 1))
        return 1;
    if (o->animFrame & 1)
        d = -0xe;
    else
        d = 0xe;
    if (func_80043AB0(o, o->h->p.whole + d, o->y.p.whole, o->animFrame) == 0)
        return func_80043AB0(o, o->h->p.whole + d, o->y.p.whole - 4, o->animFrame) != 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012CA90);
typedef struct SPADBlock_2CA90 {
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
} SPADBlock_2CA90;

extern u16 D_80135170[];
extern s32 isOnScreen(s16, s16);

static __inline__ s32 inview_2CA90(GameObject *o)
{
    if ((u16)(o->x.p.whole - (*(u16*)((char*)&(*(SPADBlock_2CA90 *)&SCRATCHPAD).i174 + 2)) + 0x64) >= 0x209) return 0;
    return (u16)((*(SPADBlock_2CA90 *)&SCRATCHPAD).s186 - o->y.p.whole + 0x80) < 0x1e1;
}

void func_8012CA90(GameObject *o)
{
    GameObject *e;

    switch (o->step) {
    case 0:
        if ((((*(SPADBlock_2CA90 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_2CA90 *)&SCRATCHPAD).i198) & 3) == 0 && inview_2CA90(o)) {
            o->timer = D_80135170[nextRandom() & 0xf];
            o->step++;
        }
        break;
    case 1:
        if (--o->timer == -1) {
            if ((o->subtype = nextRandom() & 1) == 0) {
                o->hitOffsetX = 8;
                o->hitWidth = 0x10;
                o->hitOffsetY = 8;
                o->hitHeight = 0x10;
            } else {
                o->hitOffsetX = 0xc;
                o->hitWidth = 0x1c;
                o->hitOffsetY = 0xc;
                o->hitHeight = 0x18;
            }
            o->timer = 0x1c;
            o->state++;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
            o->anim = 0;
            if (isOnScreen(o->x.p.whole, o->y.p.whole)) {
                e = allocObjectLayer3();
                if (e) {
                    e->active = 2;
                    e->type = 0x43;
                    e->x.p.whole = o->x.p.whole;
                    e->y.p.whole = o->y.p.whole + 0x10;
                    e->z.p.whole = o->z.p.whole;
                }
            }
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012CC64);
extern s16 D_80135190[];
extern void *D_80139ABC;
extern s32 tickAnimation(GameObject *);
extern void updateObjectSideFlag(GameObject *);
extern void readAnimFrameCount(GameObject *);

void func_8012CC64(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (--o->timer != -1)
            return;
        o->active = 3;
        o->timer = 0x78;
        o->unkAC = 0x1c;
        o->step++;
        break;
    case 1:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (--o->timer != -1)
            return;
        o->active = 1;
        o->step = 0;
        o->subState++;
        updateObjectSideFlag(o);
        o->timer = D_80135190[nextRandom() & 0xf];
        if (o->timer == 0)
            o->unkB4 = 0;
        else
            o->unkB4 = 1;
        o->unkAC = 0x1c;
        break;
    default:
        return;
    }
    o->anim = D_80139ABC;
    readAnimFrameCount(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012CDB8);
static __inline__ s16 past_2CDB8(GameObject *o)
{
    s16 c;

    if (o->animFrame & 1) c = o->x.p.whole < o->unkB6;
    else if (o->y.p.whole < -0x46a) c = o->unkB8 - 0x14 < o->x.p.whole;
    else c = o->x.p.whole > o->unkB8;
    if (c) return 1;
    return 0;
}

void func_8012CDB8(GameObject *o)
{
    GameObject *e;

    switch (o->step) {
    case 0:
        if (*(u16 *)&o->unkB4) o->step = 1;
        else o->step = 2;
        break;
    case 1:
        if (--o->timer == -1) {
            o->step = 3;
            o->active = 3;
        }
    case 2:
        if (o->animFrame) o->x.p.whole -= 2;
        else o->x.p.whole += 2;
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (func_8012C9BC(o) || past_2CDB8(o)) o->animFrame = 1 - o->animFrame;
        break;
    case 3:
        if (o->visible) {
            e = allocObjectLayer3();
            if (e) {
                e->active = 2;
                e->type = 0x43;
                e->x.p.whole = o->x.p.whole;
                e->y.p.whole = o->y.p.whole + 0x10;
                e->z.p.whole = o->z.p.whole;
            }
        }
        o->subtype = 1;
        o->timer = 0x1c;
        o->hitOffsetX = 0xc;
        o->hitWidth = 0x1c;
        o->hitOffsetY = 0xc;
        o->anim = 0;
        o->hitHeight = 0x18;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
        o->velX = o->animFrame;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x03/nonmatchings/x03/x03_9", func_8012CFFC);
extern void *D_80139AB4[];
extern void *D_80139A50[];

void func_8012CFFC(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (--o->timer == -1) {
            o->active = 3;
            o->timer = 0x78;
            o->unkAC = 0x1a;
            o->step++;
            o->anim = D_80139AB4[0];
            readAnimFrameCount(o);
        }
        break;
    case 1:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        if (--o->timer == -1) {
            o->active = 1;
            o->step = 0;
            o->subState++;
            updateObjectSideFlag(o);
            o->unkAC = 1;
            o->anim = D_80139A50[0];
            readAnimFrameCount(o);
        }
        break;
    }
}
