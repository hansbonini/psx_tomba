#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116814);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116C78);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116F24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80116FFC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011700C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011702C);
void func_8011702C(GameObject *o)
{
    switch (o->subState) {
    case 0:
        o->velY = 0;
        o->subState++;
        break;
    case 1:
        break;
    case 2:
        o->y.raw += o->velY << 8;
        o->velY -= 0x30;
        if (o->velY < -0x780)
            o->velY = -0x780;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801170C0);
void func_801170C0(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;

    o->h->p.whole = p->h->p.whole - 0x1e;
    o->y.p.whole = p->y.p.whole - 10;
    o->d->p.whole = p->d->p.whole - 0x32;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011710C);
void func_8011710C(GameObject *o)
{
    o->hitOffsetX = 0x33;
    o->hitWidth = 0x66;
    o->hitOffsetY = 0x1a;
    o->hitHeight = 0x34;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117130);
extern void func_80022C08(GameObject *, s32);
extern void freeObjectLayer8(GameObject *);

void func_80117130(GameObject *o)
{
    GameObject *p;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x33;
        o->hitWidth = 0x66;
        o->hitOffsetY = 0x1a;
        o->hitHeight = 0x34;
        o->state++;
        break;
    case 1:
        func_80022C08(o, 0x60);
        switch (o->subtype) {
        case 0:
            switch (o->subState) {
            case 0:
                o->velY = 0;
                o->subState++;
                break;
            case 1:
                break;
            case 2:
                o->y.raw += o->velY << 8;
                o->velY -= 0x30;
                if (o->velY < -0x780) o->velY = -0x780;
                break;
            }
            break;
        case 1:
            p = (GameObject *)o->unk90;
            o->h->p.whole = p->h->p.whole - 0x1e;
            o->y.p.whole = p->y.p.whole - 10;
            o->d->p.whole = p->d->p.whole - 0x32;
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer8(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801172E8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117390);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801173FC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011767C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117790);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801178B8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117A74);
#define U8(o,n)  (*(u8 *)((char *)(o) + (n)))
#define S8(o,n)  (*(s8 *)((char *)(o) + (n)))
#define U16(o,n) (*(u16 *)((char *)(o) + (n)))
#define S16(o,n) (*(s16 *)((char *)(o) + (n)))
#define S32(o,n) (*(s32 *)((char *)(o) + (n)))
#define PTR(o,n) (*(void **)((char *)(o) + (n)))

typedef struct SPADBlock_17A74 {
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
} SPADBlock_17A74;

extern void *D_8013D944[];
extern void func_80117BBC(GameObject *);
extern void freeObjectLayer3(GameObject *);

void func_80117A74(GameObject *o)
{
    s16 t;

    switch (o->state) {
    case 0:
        t = o->cooldownTimer;
        if (t != 0) {
            o->cooldownTimer = t - 1;
            break;
        }
        o->state++;
        o->tpage = 0xb;
        o->unkD = 0;
        o->spriteBank = ((s32*)&(*(SPADBlock_17A74 *)&SCRATCHPAD).i2d4)[0];
        o->anim = D_8013D944[o->subtype];
        if (o->subtype == 2) {
            o->unkB8 = -2;
            S16(o, 0xc8) = -2;
            o->unkB6 = 0;
            o->unkB4 = 0;
            S16(o, 0xc0) = 2;
            (*(s16*)&o->unkBE) = 0;
            o->unkBC = 0;
            S16(o, 0xc6) = 0x20;
            S16(o, 0xc4) = 0;
            S16(o, 0xd0) = 2;
            S16(o, 0xce) = 0x20;
            S16(o, 0xcc) = 0;
        }
        break;
    case 1:
        switch (o->subtype) {
        case 1:
            func_80117BBC(o);
            break;
        case 2:
            func_80022E44(o);
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
#undef U8
#undef S8
#undef U16
#undef S16
#undef S32
#undef PTR

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117BBC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117C4C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117C60);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117CE8);
extern s16 D_8007DB88[];
extern s16 D_8007D988[];
extern GameObject *allocObjectLayer3(void);

void func_80117CE8(s16 x, s16 y, s32 z)
{
    s32 i;
    GameObject *e;
    s32 w;
    s32 j;

    for (i = 0; i < 32; i++) {
        e = allocObjectLayer3();
        if (e) {
            j = i >> 1;
            e->type = 0xe;
            e->active = 1;
            e->h->raw = x << 16;
            e->y.raw = y << 16;
            e->d->raw = z << 16;
            e->timer = 0x40;
            w = (i & 1) << 3;
            e->subtype = 1;
            e->unkC = 0;
            e->cooldownTimer = w;
            if (j & 1) e->cooldownTimer = w + 8;
            e->unk84 = j << 4;
            e->animFrame = 1;
            e->unk88 = 0;
            e->h->raw += D_8007DB88[e->unk84] << 5;
            e->y.raw += D_8007D988[e->unk84] << 5;
        }
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117E10);
#define U8(o,n)  (*(u8 *)((char *)(o) + (n)))
#define S8(o,n)  (*(s8 *)((char *)(o) + (n)))
#define U16(o,n) (*(u16 *)((char *)(o) + (n)))
#define S16(o,n) (*(s16 *)((char *)(o) + (n)))
#define S32(o,n) (*(s32 *)((char *)(o) + (n)))
#define PTR(o,n) (*(void **)((char *)(o) + (n)))

typedef struct SPADBlock_17E10 {
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
} SPADBlock_17E10;

extern void *D_8013DA0C[];
extern void readAnimFrameCount(GameObject *);
extern void pushDrawListCapped(GameObject *);

void func_80117E10(GameObject *o)
{
    u8 h;

    switch (o->state) {
    case 0:
        if (o->subtype < 2) {
            o->tpage = 8;
        } else {
            o->tpage = 10;
        }
        o->unkD = 0;
        o->spriteBank = (*(SPADBlock_17E10 *)&SCRATCHPAD).i2d4;
        o->anim = D_8013DA0C[o->subtype];
        h = (*(u8*)&o->hitOffsetX) >> 4;
        o->state = o->state + 1;
        if (h < 12) {
            o->buffSize = (h << 10) + 0x1000;
        } else {
            o->buffSize = 0x1000 - ((h - 11) << 9);
        }
        h = (*(u8*)&o->hitOffsetX) & 0xf;
        if (h < 8) {
            o->unk8C = h << 2;
        } else {
            o->unk8C = (-((s32)(h - 7) << 5) / 8) & 0xff;
        }
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
#undef U8
#undef S8
#undef U16
#undef S16
#undef S32
#undef PTR

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80117F6C);
typedef struct SPADBlock_17F6C {
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
} SPADBlock_17F6C;

extern s16 D_8013B760[];
extern s16 D_8013B73C[];
extern void **D_8013B6FC[];

void func_80117F6C(GameObject *o)
{
    u8 v;

    switch (o->state) {
    case 0:
        o->tpage = 9;
        o->unkD = 0;
        if (D_8013B760[o->subtype]) {
            o->unkD = 1;
            o->clut = GetClut(D_8013B73C[o->subtype], D_8013B760[o->subtype] + o->unkC);
        }
        o->spriteBank = ((s32*)&(*(SPADBlock_17F6C *)&SCRATCHPAD).i2d4)[0];
        o->anim = *D_8013B6FC[o->subtype];
        o->state++;
        v = *(u8 *)&o->hitOffsetX >> 4;
        if (v < 12)
            o->buffSize = (v << 10) + 0x1000;
        else
            o->buffSize = 0x1000 - ((v - 11) << 9);
        v = *(u8 *)&o->hitOffsetX & 0xf;
        if (v < 8)
            o->unk8C = v << 2;
        else
            o->unk8C = (u8)(-((s32)(v - 7) << 5) / 8);
        break;
    case 1:
        func_80022C08(o, 0xf0);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801180F8);
typedef struct SPADBlock_180F8 {
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
} SPADBlock_180F8;

extern void *D_8013D928[];

void func_801180F8(GameObject *o)
{
    GameObject *e;
    s32 t;

    t = o->state;
    switch (t) {
    case 0:
        t = o->subtype;
        switch (t) {
        case 0:
            if (((*(SPADBlock_180F8 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_180F8 *)&SCRATCHPAD).i198) & 1) break;
            if (--o->timer == -1) goto done;
            e = allocObjectLayer3();
            if (e == 0) break;
            e->active = 1;
            e->type = 0x1f;
            e->subtype = 1;
            e->h->raw = o->h->raw;
            e->h->p.whole += o->timer - 0x10;
            e->y.raw = o->y.raw;
            e->d->raw = o->d->raw;
            e->unkC = nextRandom() & 3;
            e->unkAC = o->timer / 4;
            e->timer = (nextRandom() & 0x1f) + 0x30;
            e->animFrame = nextRandom() & 1;
            break;
        done:
            o->subtype = 1;
            o->unkC = 0;
            o->unkAC = 0;
            o->timer = 0x5a;
            o->animFrame = 0;
            break;
        case 1:
            o->tpage = 8;
            o->unkA = 2;
            o->unkD = 0;
            *(s8 *)&o->unkF = -10;
            o->anim = D_8013D928[o->unkAC];
            o->spriteBank = ((s32*)&(*(SPADBlock_180F8 *)&SCRATCHPAD).i2d4)[0];
            o->subState = 0;
            o->state++;
            switch (o->unkC) {
            case 0:
                o->velH = 0x200;
                o->velX = -4;
                break;
            case 1:
                o->velH = 0x180;
                o->velX = -2;
                break;
            case 2:
                o->velH = 0x100;
                o->velX = -2;
                break;
            case 3:
                o->velH = 0x80;
                o->velX = -1;
                break;
            }
            o->velV = 0;
            o->velY = 0x60;
            break;
        }
        break;
    case 1:
        o->y.raw += o->velV << 8;
        switch (o->unkAC) {
        case 0:
            if (o->velV < 0x200) o->velV += o->velY;
            break;
        case 1:
            if (o->velV < 0x180) o->velV += o->velY;
            break;
        case 2:
            if (o->velV < 0x100) o->velV += o->velY;
            break;
        }
        if (o->animFrame & 1) o->h->raw += o->velH << 8;
        else o->h->raw -= o->velH << 8;
        o->velH += o->velX;
        switch (o->subState) {
        case 0:
            if (func_80022E44(o)) o->subState++;
            break;
        case 1:
            if (o->timer < 0x1e) {
                if (((*(SPADBlock_180F8 *)&SCRATCHPAD).s1f8 + (*(SPADBlock_180F8 *)&SCRATCHPAD).i198) & 1) func_80022E44(o);
            } else {
                if (!func_80022E44(o)) o->state = 3;
            }
            if (--o->timer == -1) o->state = 3;
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118534);
extern GameObject *allocObjectLayer3(void);

void func_80118534(s32 x, s32 y, s32 z)
{
    GameObject *e = allocObjectLayer3();
    if (e) {
        e->active = 1;
        e->type = 0x1f;
        e->subtype = 0;
        e->h->raw = x << 16;
        e->y.raw = y << 16;
        e->d->raw = z << 16;
        e->timer = 0xc;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801185B8);
typedef struct SPADBlock_185B8 {
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
} SPADBlock_185B8;

typedef struct P_185B8 { char p[0x24]; s32 w24; char q[0x3c - 0x28]; s32 w3c; char r[0x64 - 0x40]; s32 w64; } P_185B8;
extern s32 D_8013D9FC[];
extern s32 tickAnimation(char *);

void func_801185B8(char *o)
{
    u8 s = o[4];
    switch (s) {
    case 0:
        o[4] = s + 1;
        *(s16 *)(o + 0x1e) = 8;
        o[0xa] = 1;
        *(s32 *)(o + 0x64) = 0x1400;
        *(s8 *)&o[0xf] = -0x14;
        o[0xd] = 0x80;
        ((P_185B8 *)o)->w3c = (*(SPADBlock_185B8 *)&SCRATCHPAD).i2d4;
        ((P_185B8 *)o)->w24 = D_8013D9FC[(u8)o[3]];
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        if (tickAnimation(o) != 0)
            o[4] = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_801186AC);
extern GameObject *allocObjectLayer3(void);

void func_801186AC(u8 sub, s32 x, s32 y, s32 z)
{
    GameObject *n = allocObjectLayer3();

    if (n != 0) {
        n->active = 1;
        n->type = 0x2d;
        n->subtype = sub;
        n->h->raw = x << 16;
        n->y.raw = y << 16;
        n->d->raw = z << 16;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118734);
extern void func_80118A30(GameObject *);

void func_80118734(GameObject *o)
{
    GameObject *e;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            if (!((D_1F8001F8 + D_1F800198) & 7)) break;
            if (--o->timer == -1) {
                o->state = 3;
                break;
            }
            e = allocObjectLayer3();
            if (e) {
                e->unkAC = o->timer & 1;
                e->subtype = 1;
                e->timer = 0x3c;
                e->unkC = (*(u8 *)&D_1F8001F8 + D_1F800198) & 3;
                e->h->raw = o->h->raw + 0x100000;
                e->y.raw = o->y.raw - 0x180000;
                e->d->raw = o->d->raw;
                func_80118A30(e);
            }
            break;
        case 1:
            o->state = 1;
            func_80118A30(o);
            o->animFrame = (D_1F8001F8 + D_1F800198) & 1;
            o->x.p.whole += (nextRandom() & 3) << 3;
            o->y.p.whole += (nextRandom() & 3) * 12;
            switch (o->unkC) {
            case 0:
                o->velH = 0x180;
                o->velX = -2;
                break;
            case 1:
                o->velH = 0x100;
                o->velX = -2;
                break;
            case 2:
                o->velH = 0x80;
                o->velX = -1;
                break;
            }
            o->velV = -0x180;
            o->velY = 0x10;
            break;
        }
        break;
    case 1:
        if (!func_80022E44(o)) {
            o->state = 3;
            break;
        }
        o->y.raw += o->velV << 8;
        o->velV += o->velY;
        if (o->animFrame & 1) o->h->raw += o->velH << 8;
        else o->h->raw -= o->velH << 8;
        o->velH += o->velX;
        if (o->animFrame & 1) o->unk8C = (o->unk8C + 4) & 0xff;
        else o->unk8C = (o->unk8C - 4) & 0xff;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118A30);
typedef struct SPADBlock_18A30 {
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
} SPADBlock_18A30;

extern void *D_8013DACC[];

void func_80118A30(GameObject *o)
{
    o->active = 1;
    o->type = 0x3d;
    o->unkA = 2;
    *(s8 *)&o->unkF = -0x1e;
    o->tpage = 0xb;
    o->unkB = 0;
    o->unkD = 0;
    o->spriteBank = ((s32*)&(*(SPADBlock_18A30 *)&SCRATCHPAD).i2d4)[0];
    o->anim = D_8013DACC[o->unkAC];
    readAnimFrameCount(o);
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118AA0);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118BC4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118E20);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80118F44);
typedef struct SPADBlock_18F44 {
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
} SPADBlock_18F44;

typedef struct GCDBlock_18F44 {
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
} GCDBlock_18F44;
extern GCDBlock_18F44 D_8009C068;

typedef struct GVars_18F44 {
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
} GVars_18F44;

extern void *D_8013D8B8[];
extern u16 D_1F80016E[];
typedef struct { s16 x; } SX_18F44;
extern void removeItemFromInventory(s32, s32);

void func_80118F44(GameObject *o)
{

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 10;
        o->unkD = 0;
        o->spriteBank = ((s32*)&(*(SPADBlock_18F44 *)&SCRATCHPAD).i2d4)[0];
        o->anim = D_8013D8B8[0];
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
        o->unk38 = o->d->p.whole;
        o->unkA = 2;
        o->unk8C = 0;
        *(s8 *)&o->unkF = -10;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if ((*(GVars_18F44 *)&D_8009BC98).b40 && (*(GVars_18F44 *)&D_8009BC98).b41 == 0xd) {
                o->h->p.whole = (*(SX_18F44 *)&D_1F80016A).x;
                o->y.p.whole = D_1F80016E[0] - 0x20;
                o->d->p.whole = D_1F800172[0];
                o->subState++;
            }
            break;
        case 1:
            func_80022E44(o);
            o->timer = 0x3c;
            o->velV = 0x180;
            o->subState++;
            o->velH = ((0xb5e - (*(SX_18F44 *)&D_1F80016A).x) << 8) / 32;
            if ((*(SX_18F44 *)&D_1F80016A).x < 0xb5e)
                o->animFrame = 0;
            else
                o->animFrame = 1;
            o->unk88 = 0;
            break;
        case 2:
            func_80022E44(o);
            if (o->unk88 < 0x41) {
                o->h->raw += o->velH << 8;
                o->y.raw -= (D_8007DB88[o->unk88 & 0xff] * o->velV) >> 4;
                o->unk88 += 2;
            }
            if (o->animFrame)
                o->unk8C += 4;
            else
                o->unk8C -= 4;
            func_80118E20(o);
            if (--o->timer == -1)
                o->subState++;
            break;
        case 3:
            D_8009C068.bd081 = 1;
            removeItemFromInventory(0xd, 1);
            o->state = 3;
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

INCLUDE_RODATA("overlays/x01/nonmatchings/x01/x01_1", func_80115274);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011923C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119404);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119510);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119798);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119878);
extern void (*D_8013B784[])(GameObject *);
extern void (*D_8013B798[])(GameObject *);
extern void pushDrawListLayer4(GameObject *o);

void func_80119878(GameObject *o)
{
    GameObject *p;

    if (o->subtype != 0) return;
    D_8013B784[o->subState](o);
    D_8013B798[o->subState]((GameObject *)o->unk94);
    ((GameObject *)o->unk94)->step = o->step;
    p = (GameObject *)o->unk94;
    if (p->visible == 0) {
        p->visible = 1;
        pushDrawListLayer4((GameObject *)o->unk94);
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011992C);
typedef struct SPADBlock_1992C {
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
} SPADBlock_1992C;

typedef struct { s16 x, y, z, pad; } SV_1992C;
typedef struct { char p[0xb4]; SV_1992C v[4]; } TX_1992C;

extern void *D_8013D934;

void func_8011992C(GameObject *o)
{
    GameObject *p;
    s16 dx, dy;
    SV_1992C *v;

    if (o->step != 0) return;
    o->y.raw = o->unk34;
    o->h->raw = o->unk30;
    o->velH = 0;
    o->velV = 0;
    o->velX = 0;
    o->velY = 0;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk74 = 0;
    if (o->subtype) {
        o->anim = D_8013D934;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        v = ((TX_1992C *)o)->v;
        if ((*(SPADBlock_1992C *)&SCRATCHPAD).s1c8 & 1) {
            v[0].y = 0;
            v[0].x = 0;
            v[1].y = 0;
            v[1].x = 0;
            v[2].y = dy;
            v[2].x = 0;
            v[3].y = dy;
            v[3].x = 0;
            v[0].z = dx - o->hitOffsetX;
            v[1].z = dx + o->hitWidth;
            v[2].z = dx - o->hitOffsetX;
            v[3].z = dx + o->hitWidth;
        } else {
            v[0].y = 0;
            v[0].z = 0;
            v[1].y = 0;
            v[1].z = 0;
            v[2].y = dy;
            v[2].z = 0;
            v[3].y = dy;
            v[3].z = 0;
            v[0].x = dx - o->hitOffsetX;
            v[1].x = dx + o->hitWidth;
            v[2].x = dx - o->hitOffsetX;
            v[3].x = dx + o->hitWidth;
        }
    }
    o->step++;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119A7C);
extern s16 D_8007D988[];

s32 func_80119A7C(GameObject *o)
{
    o->h->raw = o->unk30 + ((D_8007D988[((u8 *)&o->unk84)[1]] * *(s8 *)&o->unkA6) << 4);
    o->unk84 += o->velH;
    o->velH += o->velX;
    if (o->velH == o->unk74) {
        if (--o->timer == -1) {
            o->unk74 = 0;
            o->velH = 0;
            o->velX = 0;
            o->unk84 = 0;
            return 1;
        }
        o->velX *= -1;
        o->velH /= 2;
        o->unk74 /= 2;
        o->velX /= 2;
    } else if (o->velH == -o->unk74) {
        o->velX *= -1;
    }
    return 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_80119BAC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A24C);
typedef struct SPADBlock_1A24C {
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
} SPADBlock_1A24C;

typedef struct { s16 x, y, z, pad; } V8011AEFC_1A24C;

#define a ((V8011AEFC_1A24C *)&o->unkB4)
#define b ((V8011AEFC_1A24C *)&o->unkBC)
#define c ((V8011AEFC_1A24C *)((char *)o + 0xc4))
#define d ((V8011AEFC_1A24C *)((char *)o + 0xcc))

void func_8011A24C(GameObject *o)
{
    GameObject *p;
    s16 dx, dy;
    s32 v;

    switch (o->step) {
    case 0:
        {GameObject *q;
        q = (GameObject *)o->unk90;
        o->step++;
        o->unkAC = 0;
        dy = q->y.p.whole - o->y.p.whole;
        dx = q->h->p.whole - o->h->p.whole;}
        if ((*(SPADBlock_1A24C *)&SCRATCHPAD).s1c8 & 1) {
            a->y = 0;
            a->x = 0;
            b->y = 0;
            b->x = 0;
            c->y = dy;
            c->x = 0;
            d->y = dy;
            d->x = 0;
            a->z = dx - o->hitOffsetX;
            b->z = dx + o->hitWidth;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            a->y = 0;
            a->z = 0;
            b->y = 0;
            b->z = 0;
            c->y = dy;
            c->z = 0;
            d->y = dy;
            d->z = 0;
            a->x = dx - o->hitOffsetX;
            b->x = dx + o->hitWidth;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 1:
        o->unk88 = ((GameObject *)o->unk90)->unk88;
        v = (o->unk88 >> 8) & 0xff;
        if (v < 0x60) {
            o->hitOffsetX = 3;
            o->hitWidth = 3;
        } else if (v < 0xa0) {
            o->hitOffsetX = 4;
            o->hitWidth = 3;
        } else {
            o->hitOffsetX = 4;
            o->hitWidth = 4;
        }
    case 2:
        p = (GameObject *)o->unk90;
        o->unkAC = 0;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1A24C *)&SCRATCHPAD).s1c8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 3:
        p = (GameObject *)o->unk90;
        o->hitOffsetX = 4;
        o->hitWidth = 4;
        o->unkAC = 3;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1A24C *)&SCRATCHPAD).s1c8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 4:
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1A24C *)&SCRATCHPAD).s1c8 & 1) {
            c->y = dy;
            d->y = dy;
            c->z = dx - o->hitOffsetX;
            d->z = dx + o->hitWidth;
        } else {
            c->y = dy;
            d->y = dy;
            c->x = dx - o->hitOffsetX;
            d->x = dx + o->hitWidth;
        }
        break;
    case 5:
        o->unkAC = 0;
        break;
    }
    o->anim = ((void **)&D_8013D934)[o->unkAC];
}
#undef a
#undef b
#undef c
#undef d

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A4B4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A650);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A7C0);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A7E8);
typedef struct SPADBlock_1A7E8 {
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
} SPADBlock_1A7E8;

typedef struct { s16 x, y, z, pad; } SV_1A7E8;
#define V(o) ((SV_1A7E8 *)((char *)(o) + 0xb4))

void func_8011A7E8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->anim = D_8013D934;
    {
        GameObject *e = (GameObject *)o->unk90;
        s16 dy = e->y.p.whole - o->y.p.whole;
        s16 dx = e->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1A7E8 *)&SCRATCHPAD).s1c8 & 1) {
            V(o)[0].y = 0;
            V(o)[0].x = 0;
            V(o)[1].y = 0;
            V(o)[1].x = 0;
            V(o)[2].y = dy;
            V(o)[2].x = 0;
            V(o)[3].y = dy;
            V(o)[3].x = 0;
            V(o)[0].z = dx - o->hitOffsetX;
            V(o)[1].z = dx + o->hitWidth;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[0].y = 0;
            V(o)[0].z = 0;
            V(o)[1].y = 0;
            V(o)[1].z = 0;
            V(o)[2].y = dy;
            V(o)[2].z = 0;
            V(o)[3].y = dy;
            V(o)[3].z = 0;
            V(o)[0].x = dx - o->hitOffsetX;
            V(o)[1].x = dx + o->hitWidth;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 1:
    {
        GameObject *e = (GameObject *)o->unk90;
        s16 dy = e->y.p.whole - o->y.p.whole;
        s16 dx = e->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1A7E8 *)&SCRATCHPAD).s1c8 & 1) {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].z = dx - o->hitOffsetX;
            V(o)[3].z = dx + o->hitWidth;
        } else {
            V(o)[2].y = dy;
            V(o)[3].y = dy;
            V(o)[2].x = dx - o->hitOffsetX;
            V(o)[3].x = dx + o->hitWidth;
        }
    }
        break;
    case 2:
        break;
    }
}
#undef V

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011A974);
extern s16 D_8007DB88[];

#define RESET(o) \
    (o)->y.raw = (o)->unk34; \
    (o)->h->raw = (o)->unk30; \
    (o)->velH = 0; \
    (o)->velV = 0; \
    (o)->velX = 0; \
    (o)->velY = 0; \
    (o)->unk84 = 0; \
    (o)->unk88 = 0; \
    (o)->unk74 = 0;

void func_8011A974(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        RESET(o);
        o->velV = 0x200;
        break;
    case 1:
        o->unk88 += 4;
        if (o->unk88 & 0x80) {
            o->step++;
            break;
        }
        o->y.raw -= (D_8007DB88[o->unk88 & 0xff] * o->velV) >> 4;
        break;
    case 2:
        o->subState = 0;
        o->step = 0;
        RESET(o);
        break;
    }
}
#undef RESET

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AA9C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AAF4);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011ACA8);
extern s16 D_8007DB88[];

void func_8011ACA8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velV = 0;
        o->velH = 0;
        o->velV = 0x200;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->velY = -0x80;
        o->timer = 0;
        o->step++;
        break;
    case 1:
        if (o->timer > 0) {
            o->step = 2;
            break;
        }
        o->unk88 += 4;
        if ((o->unk88 & 0xff) == 0) {
            o->velV += o->velY;
            o->y.raw = o->unk34;
            o->timer++;
        }
        o->y.raw += (D_8007DB88[(u8)o->unk88] * o->velV) >> 4;
        if (o->unk6A == 1) {
            o->step++;
        }
        break;
    case 2:
        o->y.raw = o->unk34;
        o->h->raw = o->unk30;
        o->velH = 0;
        o->velV = 0;
        o->velX = 0;
        o->velY = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk74 = 0;
        o->timer = 0;
        o->subState = 0;
        o->step = 0;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AE2C);
typedef struct SPADBlock_1AE2C {
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
} SPADBlock_1AE2C;

typedef struct {
    char p[0xb4];
    s16 b4, b6, b8, ba, bc, be, c0, c2, c4, c6, c8, ca, cc, ce, d0;
} E_1AE2C;

void func_8011AE2C(GameObject *o)
{

    switch (o->step) {
    case 0: {
        GameObject *p;
        s16 dy, dx;
        o->step++;
        *(s16 *)((char *)o + 0xac) = 0;
        o->anim = D_8013D934;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1AE2C *)&SCRATCHPAD).s1c8 & 1) {
            ((E_1AE2C *)o)->b6 = 0;
            ((E_1AE2C *)o)->b4 = 0;
            ((E_1AE2C *)o)->be = 0;
            ((E_1AE2C *)o)->bc = 0;
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->c4 = 0;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->cc = 0;
            ((E_1AE2C *)o)->b8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->c0 = dx + o->hitWidth;
            ((E_1AE2C *)o)->c8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->d0 = dx + o->hitWidth;
        } else {
            ((E_1AE2C *)o)->b6 = 0;
            ((E_1AE2C *)o)->b8 = 0;
            ((E_1AE2C *)o)->be = 0;
            ((E_1AE2C *)o)->c0 = 0;
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->c8 = 0;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->d0 = 0;
            ((E_1AE2C *)o)->b4 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->bc = dx + o->hitWidth;
            ((E_1AE2C *)o)->c4 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 1: {
        GameObject *p;
        s16 dy, dx;
        p = (GameObject *)o->unk90;
        dy = p->y.p.whole - o->y.p.whole;
        dx = p->h->p.whole - o->h->p.whole;
        if ((*(SPADBlock_1AE2C *)&SCRATCHPAD).s1c8 & 1) {
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->c8 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->d0 = dx + o->hitWidth;
        } else {
            ((E_1AE2C *)o)->c6 = dy;
            ((E_1AE2C *)o)->ce = dy;
            ((E_1AE2C *)o)->c4 = dx - o->hitOffsetX;
            ((E_1AE2C *)o)->cc = dx + o->hitWidth;
        }
        break;
    }
    case 2:
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011AFBC);
typedef struct SPADBlock_1AFBC {
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
} SPADBlock_1AFBC;

struct GSInventory_1AFBC { u8 slots[256]; u16 counter; u16 sortMode; };
struct GSEquips_1AFBC { u8 weapon; u8 pants; };
typedef struct GameState_1AFBC {
    u16 selectedArea;
    u16 selectedSection;
    u8 selectedPlane;
    u8 area00_fogControl;
    u8 unk6;
    u8 keepBgm;
    s32 totalTimePlayed;
    unsigned long playerAP;
    u8 playerHealth;
    u8 playerHealthDisplayed;
    char unk12;
    char unk13;
    u8 areaTransition;
    u8 fadeScreenControl;
    u8 fadeScreenAmount;
    u8 saveSlot;
    u8 unk18;
    u8 unk19;
    u8 unk1a;
    u8 unk1b;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 playerLives;
    u8 unk21;
    u16 selectedSpawnPoint;
    s32 area00_eventControl;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    u8 unk2f;
    u8 displayExpBar;
    u8 unk31;
    u8 unk32;
    u8 unk33;
    u8 area00_pickedItems[32];
    u8 area01_pickedItems[32];
    u8 area02_pickedItems[32];
    u8 area03_pickedItems[32];
    u8 area04_pickedItems[32];
    u8 area05_pickedItems[32];
    u8 area06_pickedItems[32];
    u8 area07_pickedItems[32];
    u8 area08_pickedItems[32];
    u8 area09_pickedItems[32];
    u8 area10_pickedItems[32];
    u8 area11_pickedItems[32];
    u8 area12_pickedItems[32];
    u8 area13_pickedItems[32];
    u8 area14_pickedItems[32];
    u8 area15_pickedItems[32];
    u8 area16_pickedItems[32];
    u8 area17_pickedItems[32];
    u8 area18_pickedItems[32];
    u8 area19_pickedItems[32];
    u8 unk2b4;
    u8 unk2b5;
    u8 unk2b6;
    u8 unk2b7;
    u8 unk2b8;
    u8 unk2b9;
    u8 unk2ba;
    u8 unk2bb;
    u8 unk2bc;
    u8 unk2bd;
    u8 unk2be;
    u8 unk2bf;
    u8 unk2c0;
    u8 unk2c1;
    u8 unk2c2;
    u8 unk2c3;
    u8 unk2c4;
    u8 unk2c5;
    u8 unk2c6;
    u8 unk2c7;
    u8 unk2c8;
    u8 unk2c9;
    u8 unk2ca;
    u8 unk2cb;
    u8 unk2cc;
    u8 unk2cd;
    u8 unk2ce;
    u8 unk2cf;
    u8 unk2d0;
    u8 unk2d1;
    u8 unk2d2;
    u8 unk2d3;
    u8 unk2d4;
    u8 unk2d5;
    u8 unk2d6;
    u8 unk2d7;
    u8 unk2d8;
    u8 unk2d9;
    u8 unk2da;
    u8 unk2db;
    u8 unk2dc;
    u8 unk2dd;
    u8 unk2de;
    u8 unk2df;
    u8 unk2e0;
    u8 unk2e1;
    u8 unk2e2;
    u8 unk2e3;
    u8 unk2e4;
    u8 unk2e5;
    u8 unk2e6;
    u8 unk2e7;
    u8 unk2e8;
    u8 unk2e9;
    u8 unk2ea;
    u8 unk2eb;
    u8 unk2ec;
    u8 unk2ed;
    u8 unk2ee;
    u8 unk2ef;
    u8 unk2f0;
    u8 unk2f1;
    u8 unk2f2;
    u8 unk2f3;
    u8 unk2f4;
    u8 unk2f5;
    u8 unk2f6;
    u8 unk2f7;
    u8 unk2f8;
    u8 unk2f9;
    u8 unk2fa;
    u8 unk2fb;
    u8 unk2fc;
    u8 unk2fd;
    u8 unk2fe;
    u8 unk2ff;
    u8 unk300;
    u8 unk301;
    u8 unk302;
    u8 unk303;
    u8 unk304;
    u8 unk305;
    u8 unk306;
    u8 unk307;
    u8 unk308;
    u8 unk309;
    u8 unk30a;
    u8 unk30b;
    u8 unk30c;
    u8 unk30d;
    u8 unk30e;
    u8 unk30f;
    u8 unk310;
    u8 unk311;
    u8 unk312;
    u8 unk313;
    u8 unk314;
    u8 unk315;
    u8 unk316;
    u8 unk317;
    u8 unk318;
    u8 unk319;
    u8 unk31a;
    u8 unk31b;
    u8 unk31c;
    u8 unk31d;
    u8 unk31e;
    u8 unk31f;
    u8 unk320;
    u8 unk321;
    u8 unk322;
    u8 unk323;
    u8 unk324;
    u8 unk325;
    u8 unk326;
    u8 unk327;
    u8 unk328;
    u8 unk329;
    u8 unk32a;
    u8 unk32b;
    u8 unk32c;
    u8 unk32d;
    u8 unk32e;
    u8 unk32f;
    u8 unk330;
    u8 unk331;
    u8 unk332;
    u8 unk333;
    u8 unk334;
    u8 unk335;
    u8 unk336;
    u8 unk337;
    u8 unk338;
    u8 unk339;
    u8 unk33a;
    u8 unk33b;
    u8 unk33c;
    u8 unk33d;
    u8 unk33e;
    u8 unk33f;
    u8 unk340;
    u8 unk341;
    u8 unk342;
    u8 unk343;
    u8 unk344;
    u8 unk345;
    u8 unk346;
    u8 unk347;
    u8 unk348;
    u8 unk349;
    u8 unk34a;
    u8 unk34b;
    u8 unk34c;
    u8 unk34d;
    u8 unk34e;
    u8 unk34f;
    u8 unk350;
    u8 unk351;
    u8 unk352;
    u8 unk353;
    u8 unk354;
    u8 unk355;
    u8 unk356;
    u8 unk357;
    u8 unk358;
    u8 unk359;
    u8 unk35a;
    u8 unk35b;
    u8 unk35c;
    u8 unk35d;
    u8 unk35e;
    u8 unk35f;
    u8 unk360;
    u8 unk361;
    u8 unk362;
    u8 unk363;
    u8 unk364;
    u8 unk365;
    u8 unk366;
    u8 unk367;
    u8 unk368;
    u8 unk369;
    u8 unk36a;
    u8 unk36b;
    u8 unk36c;
    u8 unk36d;
    u8 unk36e;
    u8 unk36f;
    u8 unk370;
    u8 unk371;
    u8 unk372;
    u8 unk373;
    u8 unk374;
    u8 unk375;
    u8 unk376;
    u8 unk377;
    u8 unk378;
    u8 unk379;
    u8 unk37a;
    u8 unk37b;
    u8 unk37c;
    u8 unk37d;
    u8 unk37e;
    u8 unk37f;
    u8 unk380;
    u8 unk381;
    u8 unk382;
    u8 unk383;
    u8 unk384;
    u8 unk385;
    u8 unk386;
    u8 unk387;
    u8 unk388;
    u8 unk389;
    u8 unk38a;
    u8 unk38b;
    u8 unk38c;
    u8 unk38d;
    u8 unk38e;
    u8 unk38f;
    u8 unk390;
    u8 unk391;
    u8 unk392;
    u8 unk393;
    u8 unk394;
    u8 unk395;
    u8 unk396;
    u8 unk397;
    u8 unk398;
    u8 unk399;
    u8 unk39a;
    u8 unk39b;
    u8 unk39c;
    u8 unk39d;
    u8 unk39e;
    u8 unk39f;
    u8 unk3a0;
    u8 unk3a1;
    u8 unk3a2;
    u8 unk3a3;
    u8 unk3a4;
    u8 unk3a5;
    u8 unk3a6;
    u8 unk3a7;
    u8 unk3a8;
    u8 unk3a9;
    u8 unk3aa;
    u8 unk3ab;
    u8 unk3ac;
    u8 unk3ad;
    u8 unk3ae;
    u8 unk3af;
    u8 unk3b0;
    u8 unk3b1;
    u8 unk3b2;
    u8 unk3b3;
    u8 unk3b4;
    u8 unk3b5;
    u8 unk3b6;
    u8 unk3b7;
    u8 unk3b8;
    u8 unk3b9;
    u8 unk3ba;
    u8 unk3bb;
    u8 unk3bc;
    u8 unk3bd;
    u8 unk3be;
    u8 unk3bf;
    u8 unk3c0;
    u8 unk3c1;
    u8 unk3c2;
    u8 unk3c3;
    u8 unk3c4;
    u8 unk3c5;
    u8 unk3c6;
    u8 unk3c7;
    u8 unk3c8;
    u8 unk3c9;
    u8 unk3ca;
    u8 unk3cb;
    u8 unk3cc;
    u8 unk3cd;
    u8 unk3ce;
    u8 unk3cf;
    u8 unk3d0;
    u8 unk3d1;
    u8 unk3d2;
    u8 unk3d3;
    u8 unk3d4;
    u8 unk3d5;
    u8 unk3d6;
    u8 unk3d7;
    u8 unk3d8;
    u8 unk3d9;
    u8 unk3da;
    u8 unk3db;
    u8 unk3dc;
    u8 unk3dd;
    u8 unk3de;
    u8 unk3df;
    u8 unk3e0;
    u8 unk3e1;
    u8 unk3e2;
    u8 unk3e3;
    u8 unk3e4;
    u8 unk3e5;
    u8 unk3e6;
    u8 unk3e7;
    u8 unk3e8;
    u8 unk3e9;
    u8 unk3ea;
    u8 unk3eb;
    u8 unk3ec;
    u8 unk3ed;
    u8 unk3ee;
    u8 unk3ef;
    u8 unk3f0;
    u8 unk3f1;
    u8 unk3f2;
    u8 unk3f3;
    u8 unk3f4;
    u8 unk3f5;
    u8 unk3f6;
    u8 unk3f7;
    u8 unk3f8;
    u8 unk3f9;
    u8 unk3fa;
    u8 unk3fb;
    u8 unk3fc;
    u8 unk3fd;
    u8 unk3fe;
    u8 unk3ff;
    u8 unk400;
    u8 unk401;
    u8 unk402;
    u8 unk403;
    u8 unk404;
    u8 unk405;
    u8 unk406;
    u8 unk407;
    u8 unk408;
    u8 unk409;
    u8 unk40a;
    u8 unk40b;
    u8 unk40c;
    u8 unk40d;
    u8 unk40e;
    u8 unk40f;
    u8 unk410;
    u8 unk411;
    u8 unk412;
    u8 unk413;
    u8 unk414;
    u8 unk415;
    u8 unk416;
    u8 unk417;
    u8 unk418;
    u8 unk419;
    u8 unk41a;
    u8 unk41b;
    u8 unk41c;
    u8 unk41d;
    u8 unk41e;
    u8 unk41f;
    u8 unk420;
    u8 unk421;
    u8 unk422;
    u8 unk423;
    u8 unk424;
    u8 unk425;
    u8 unk426;
    u8 unk427;
    u8 unk428;
    u8 unk429;
    u8 unk42a;
    u8 unk42b;
    u8 unk42c;
    u8 unk42d;
    u8 unk42e;
    u8 unk42f;
    u8 unk430;
    u8 unk431;
    u8 unk432;
    u8 unk433;
    u16 nextArea;
    u16 nextSection;
    u8 redExpLevel;
    u8 greenExpLevel;
    u8 blueExpLevel;
    u8 redExpBar;
    u8 greenExpBar;
    u8 blueExpBar;
    u8 unk43e;
    u8 unk43f;
    u16 nextSpawnPoint;
    u8 disableSelectMenu;
    u8 inventoryScreen;
    u8 event[256];
    u8 unk544;
    u8 unk545;
    u8 unk546;
    u8 unk547;
    u8 unk548;
    u8 unk549;
    u8 unk54a;
    u8 baronState;
    u8 unk54c;
    u8 unk54d;
    u8 unk54e;
    char unk54f;
    u8 unk550;
    u8 unk551;
    u8 unk552;
    u8 unk553;
    u8 unk554;
    u8 unk555;
    u8 unk556;
    u8 unk557;
    u8 unk558;
    u8 unk559;
    u8 unk55a;
    u8 unk55b;
    u8 unk55c;
    u8 unk55d;
    u8 unk55e;
    u8 unk55f;
    u8 unk560;
    u8 unk561;
    u8 unk562;
    u8 unk563;
    u8 unk564;
    u8 unk565;
    u8 unk566;
    u8 unk567;
    u8 unk568;
    u8 unk569;
    u8 unk56a;
    u8 unk56b;
    u8 unk56c;
    u8 unk56d;
    u8 unk56e;
    u8 unk56f;
    u8 unk570;
    u8 unk571;
    u8 unk572;
    u8 unk573;
    u8 unk574;
    u8 unk575;
    u8 unk576;
    u8 unk577;
    u8 unk578;
    u8 unk579;
    u8 unk57a;
    u8 unk57b;
    u8 unk57c;
    u8 unk57d;
    u8 unk57e;
    u8 unk57f;
    u8 unk580;
    u8 unk581;
    u8 unk582;
    u8 unk583;
    u8 unk584;
    u8 unk585;
    u8 unk586;
    u8 unk587;
    u8 unk588;
    u8 unk589;
    u8 unk58a;
    u8 unk58b;
    u8 unk58c;
    u8 unk58d;
    u8 unk58e;
    u8 unk58f;
    u8 unk590;
    u8 unk591;
    u8 unk592;
    u8 unk593;
    u8 unk594;
    u8 unk595;
    u8 unk596;
    u8 unk597;
    u8 unk598;
    u8 unk599;
    u8 unk59a;
    u8 unk59b;
    u8 unk59c;
    u8 unk59d;
    u8 unk59e;
    u8 unk59f;
    u8 unk5a0;
    u8 pipeState;
    u8 unk5a2;
    u8 unk5a3;
    u8 unk5a4;
    u8 unk5a5;
    u8 unk5a6;
    u8 unk5a7;
    u8 unk5a8;
    u8 unk5a9;
    u8 unk5aa;
    u8 unk5ab;
    u8 unk5ac;
    u8 unk5ad;
    u8 unk5ae;
    u8 unk5af;
    u8 unk5b0;
    u8 unk5b1;
    u8 unk5b2;
    u8 unk5b3;
    u8 unk5b4;
    u8 unk5b5;
    u8 unk5b6;
    u8 unk5b7;
    u8 unk5b8;
    u8 unk5b9;
    u8 unk5ba;
    u8 unk5bb;
    u8 unk5bc;
    u8 unk5bd;
    u8 unk5be;
    u8 unk5bf;
    u8 unk5c0;
    u8 unk5c1;
    u8 unk5c2;
    u8 unk5c3;
    u8 unk5c4;
    u8 unk5c5;
    u8 unk5c6;
    u8 unk5c7;
    u8 unk5c8;
    u8 unk5c9;
    u8 unk5ca;
    u8 unk5cb;
    u8 unk5cc;
    u8 unk5cd;
    u8 unk5ce;
    u8 unk5cf;
    u8 unk5d0;
    u8 unk5d1;
    u8 unk5d2;
    u8 unk5d3;
    u8 unk5d4;
    u8 unk5d5;
    u8 unk5d6;
    u8 unk5d7;
    u8 unk5d8;
    u8 unk5d9;
    u8 unk5da;
    u8 unk5db;
    u8 unk5dc;
    u8 unk5dd;
    u8 unk5de;
    u8 unk5df;
    u8 unk5e0;
    u8 unk5e1;
    u8 unk5e2;
    u8 unk5e3;
    u8 unk5e4;
    u8 unk5e5;
    u8 unk5e6;
    u8 unk5e7;
    u8 unk5e8;
    u8 unk5e9;
    u8 unk5ea;
    u8 unk5eb;
    u8 unk5ec;
    u8 unk5ed;
    u8 unk5ee;
    u8 unk5ef;
    u8 unk5f0;
    u8 unk5f1;
    u8 unk5f2;
    u8 unk5f3;
    u8 unk5f4;
    u8 unk5f5;
    u8 unk5f6;
    u8 unk5f7;
    u8 unk5f8;
    u8 unk5f9;
    u8 unk5fa;
    u8 unk5fb;
    u8 unk5fc;
    u8 unk5fd;
    u8 unk5fe;
    u8 unk5ff;
    u8 unk600;
    u8 unk601;
    u8 unk602;
    u8 unk603;
    u8 unk604;
    u8 unk605;
    u8 unk606;
    u8 unk607;
    u8 unk608;
    u8 unk609;
    u8 unk60a;
    u8 unk60b;
    u8 unk60c;
    u8 unk60d;
    u8 unk60e;
    u8 unk60f;
    u8 unk610;
    u8 unk611;
    u8 unk612;
    u8 unk613;
    u8 unk614;
    u8 unk615;
    u8 unk616;
    u8 unk617;
    u8 unk618;
    u8 unk619;
    u8 unk61a;
    u8 unk61b;
    u8 unk61c;
    u8 unk61d;
    u8 unk61e;
    u8 unk61f;
    u8 unk620;
    u8 unk621;
    u8 unk622;
    u8 unk623;
    u8 unk624;
    u8 unk625;
    u8 unk626;
    u8 unk627;
    u8 unk628;
    u8 unk629;
    u8 unk62a;
    u8 unk62b;
    u8 unk62c;
    u8 unk62d;
    u8 unk62e;
    u8 unk62f;
    u8 unk630;
    u8 unk631;
    u8 unk632;
    u8 unk633;
    u8 unk634;
    u8 unk635;
    u8 unk636;
    u8 unk637;
    u8 unk638;
    u8 unk639;
    u8 unk63a;
    u8 unk63b;
    u8 unk63c;
    u8 unk63d;
    u8 unk63e;
    u8 unk63f;
    u8 unk640;
    u8 unk641;
    u8 unk642;
    u8 unk643;
    u8 unk644;
    u8 unk645;
    u8 unk646;
    u8 unk647;
    u8 unk648;
    u8 unk649;
    u8 unk64a;
    u8 unk64b;
    u8 unk64c;
    u8 unk64d;
    u8 unk64e;
    u8 unk64f;
    u8 unk650;
    u8 unk651;
    u8 unk652;
    u8 unk653;
    u8 unk654;
    u8 unk655;
    u8 unk656;
    u8 unk657;
    u8 unk658;
    u8 unk659;
    u8 unk65a;
    u8 unk65b;
    u8 unk65c;
    u8 unk65d;
    u8 unk65e;
    u8 unk65f;
    u8 unk660;
    u8 unk661;
    u8 unk662;
    u8 unk663;
    u8 unk664;
    u8 unk665;
    u8 unk666;
    u8 unk667;
    u8 unk668;
    u8 unk669;
    u8 unk66a;
    u8 unk66b;
    u8 unk66c;
    u8 unk66d;
    u8 unk66e;
    u8 unk66f;
    s16 unk670;
    s16 unk672;
    s16 unk674;
    u8 unk676;
    u8 unk677;
    u8 unk678;
    u8 unk679;
    u8 unk67a;
    u8 unk67b;
    u8 unk67c;
    u8 unk67d;
    u8 unk67e;
    u8 unk67f;
    u8 unk680;
    u8 unk681;
    u8 unk682;
    u8 unk683;
    u8 goldenFlowerState;
    u8 unk685;
    u8 unk686;
    u8 unk687;
    u8 unk688;
    u8 unk689;
    u8 unk68a;
    u8 unk68b;
    u8 unk68c;
    u8 unk68d;
    u8 unk68e;
    u8 unk68f;
    u8 unk690;
    u8 unk691;
    u8 unk692;
    u8 unk693;
    u8 unk694;
    u8 unk695;
    u8 unk696;
    u8 unk697;
    u8 unk698;
    u8 unk699;
    u8 unk69a;
    u8 unk69b;
    u8 unk69c;
    u8 unk69d;
    u8 unk69e;
    u8 unk69f;
    u8 unk6a0;
    u8 unk6a1;
    u8 unk6a2;
    u8 unk6a3;
    u8 unk6a4;
    u8 unk6a5;
    u8 unk6a6;
    u8 unk6a7;
    u8 unk6a8;
    u8 unk6a9;
    u8 unk6aa;
    u8 unk6ab;
    u8 unk6ac;
    u8 unk6ad;
    u8 unk6ae;
    u8 playerIdleState;
    u8 unk6b0;
    u8 unk6b1;
    u8 unk6b2;
    u8 unk6b3;
    u8 unk6b4;
    u8 unk6b5;
    u8 unk6b6;
    u8 unk6b7;
    u8 unk6b8;
    u8 unk6b9;
    u8 unk6ba;
    u8 unk6bb;
    u8 unk6bc;
    u8 unk6bd;
    u8 unk6be;
    u8 unk6bf;
    u8 unk6c0;
    u8 unk6c1;
    u8 unk6c2;
    u8 unk6c3;
    u8 unk6c4;
    u8 unk6c5;
    u8 unk6c6;
    u8 unk6c7;
    u8 unk6c8;
    u8 unk6c9;
    u8 unk6ca;
    u8 unk6cb;
    u8 unk6cc;
    u8 unk6cd;
    u8 unk6ce;
    u8 unk6cf;
    u8 unk6d0;
    u8 unk6d1;
    u8 unk6d2;
    u8 unk6d3;
    u8 unk6d4;
    u8 unk6d5;
    u8 unk6d6;
    u8 unk6d7;
    u8 unk6d8;
    u8 unk6d9;
    u8 unk6da;
    u8 unk6db;
    u8 unk6dc;
    u8 unk6dd;
    u8 unk6de;
    u8 unk6df;
    u8 unk6e0;
    u8 unk6e1;
    u8 unk6e2;
    u8 unk6e3;
    u8 unk6e4;
    u8 unk6e5;
    u8 unk6e6;
    u8 unk6e7;
    u8 unk6e8;
    u8 unk6e9;
    u8 unk6ea;
    u8 unk6eb;
    u8 unk6ec;
    u8 unk6ed;
    u8 unk6ee;
    u8 unk6ef;
    u8 unk6f0;
    u8 unk6f1;
    u8 unk6f2;
    u8 unk6f3;
    u8 unk6f4;
    u8 unk6f5;
    u8 unk6f6;
    u8 unk6f7;
    u8 unk6f8;
    u8 unk6f9;
    u8 unk6fa;
    u8 unk6fb;
    u8 unk6fc;
    u8 unk6fd;
    u8 unk6fe;
    u8 unk6ff;
    u8 unk700;
    u8 unk701;
    u8 unk702;
    u8 unk703;
    u8 unk704;
    u8 unk705;
    u8 unk706;
    u8 unk707;
    u8 unk708;
    u8 unk709;
    u8 unk70a;
    u8 unk70b;
    u8 unk70c;
    u8 unk70d;
    u8 unk70e;
    u8 unk70f;
    u8 unk710;
    u8 unk711;
    u8 unk712;
    u8 unk713;
    u8 unk714;
    u8 unk715;
    u8 unk716;
    u8 unk717;
    u8 unk718;
    u8 unk719;
    u8 unk71a;
    u8 bittingPlantFlowerState;
    u8 unk71c;
    u8 unk71d;
    u8 unk71e;
    u8 goldenBowlState;
    u8 bonusHealth;
    u8 unk721;
    u8 unk722;
    u8 unk723;
    u8 unk724;
    u8 unk725;
    u8 unk726;
    u8 unk727;
    u8 unk728;
    u8 unk729;
    u8 unk72a;
    u8 unk72b;
    u8 unk72c;
    u8 unk72d;
    u8 unk72e;
    u8 unk72f;
    u8 unk730;
    u8 unk731;
    u8 unk732;
    u8 unk733;
    u8 unk734;
    u8 unk735;
    char unk736;
    u8 unk737;
    u8 unk738;
    u8 unk739;
    u8 unk73a;
    u8 unk73b;
    u8 unk73c;
    u8 unk73d;
    u8 unk73e;
    u8 unk73f;
    u8 unk740;
    u8 unk741;
    u8 unk742;
    u8 unk743;
    u8 item[256];
    struct GSInventory_1AFBC inventory;
    u16 currentArea;
    u16 currentSection;
    u16 currentSpawnPoint;
    u8 inventoryButton;
    u8 playerState;
    struct GSEquips_1AFBC playerEquips;
    u8 unk952;
    u8 unk953;
    u8 unk954;
    u8 unk955;
    u8 unk956;
    u8 unk957;
    u8 unk958;
    u8 unk959;
    u8 unk95a;
    u8 unk95b;
    u8 unk95c;
    u8 unk95d;
    u8 unk95e;
    u8 unk95f;
    u8 unk960;
    u8 unk961;
    u8 unk962;
    u8 purifiedAreas;
    u8 unk964;
    u8 unk965;
    u8 unk966;
    u8 unk967;
    u8 unk968;
    u8 unk969;
    u8 unk96a;
    u8 unk96b;
    u8 unk96c;
    u8 unk96d;
    u8 unk96e;
    u8 unk96f;
    u8 unk970;
    u8 unk971;
    u8 unk972;
    u8 unk973;
    u8 unk974;
    u8 unk975;
    u8 unk976;
    u8 unk977;
    u8 unk978;
    u8 unk979;
    u8 unk97a;
    u8 unk97b;
    u8 unk97c;
    u8 unk97d;
    u8 unk97e;
    u8 unk97f;
    u8 unk980;
    u8 unk981;
    u8 unk982;
    u8 unk983;
    u8 unk984;
} GameState_1AFBC;

void func_8011AFBC(GameObject *o)
{
    switch (o->step) {
    case 0:
        switch (GAME.selectedSection) {
        case 0:
        case 1:
            o->step++;
            break;
        case 2:
            o->unk88 = 0x800;
            o->step = 4;
            break;
        }
        break;
    case 1:
        if ((*(s16*)((char*)&(*(SPADBlock_1AFBC *)&SCRATCHPAD).i16c + 2)) >= -0x140 && (u16)((*(s16*)((char*)&(*(SPADBlock_1AFBC *)&SCRATCHPAD).i168 + 2)) - 0xb23) < 0x95)
            o->step++;
        break;
    case 2:
        o->unk88 = (o->unk88 + 8) & 0xfff;
        if (o->unk88 >= 0x600) o->step++;
        break;
    case 3:
        if (o->visible == 0 && ((GameObject *)o->unk94)->visible == 0) {
            o->unk88 = 0;
            o->step = 1;
        }
        break;
    case 4:
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B0D4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B1CC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B4A8);
typedef struct GCDBlock_1B4A8 {
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
} GCDBlock_1B4A8;

extern u16 D_8013B7BC[];
extern u16 D_8013B7BE[];
extern u16 D_8013B7C0[];
extern u16 D_8013B7C2[];
extern void freeObjectLayer4(GameObject *);

void func_8011B4A8(GameObject *o)
{

    switch (o->state) {
    case 0:
        o->hitOffsetX = -D_8013B7BC[0];
        o->hitWidth = o->hitOffsetX + D_8013B7BE[0];
        o->hitOffsetY = -D_8013B7C0[0];
        o->hitHeight = o->hitOffsetY + D_8013B7C2[0];
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (((u8*)&D_8009C068.bce48)[0] != 0) {
            o->state = 3;
        } else {
            o->state = 1;
        }
        break;
    case 1:
        if (D_8009C068.bd081 >= 4) {
            o->state = 3;
        } else {
            func_80022C08(o, 0x92);
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B5C4);
void func_8011B5C4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (o->subtype == 0) {
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 0x44;
            o->hitHeight = 0x60;
        } else {
            o->hitOffsetX = 0x18;
            o->hitWidth = 0x30;
            o->hitOffsetY = 0;
            o->hitHeight = 0x50;
        }
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B6A4);
extern Fix16 *D_800A53DC_Fix16PtrArr[] asm("D_800A53DC");
extern s32 func_80022D3C(GameObject *, s32);
extern void playSFX(s32);
extern s16 fixedMulSin2(s32, s32);

void func_8011B6A4(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->hitOffsetX = 10;
        o->hitOffsetY = 10;
        o->hitWidth = 0x14;
        o->hitHeight = 0x14;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            o->subState++;
            o->unkB4 = 0;
            o->unk8C = 0;
            o->touchFlag = 0;
        case 1:
            if (func_80022D3C(o, 0x60)) {
                if (o->touchFlag) {
                    if ((u16)o->unkB4 == 0) playSFX(0x4b);
                    if (o->unk8C >= -0x6f) {
                        o->unk8C -= (u16)o->unkB4 >> 8;
                        o->unkB4 += 0x10;
                    }
                }
                { s32 t = ((s16 (*)(s32, s32))fixedMulCos2)(((o->unk8C >> 4) + 0x40) & 0xff, 0x19a) + 0x10; o->unk30 = o->h->p.whole + t; }
                o->unk34 = o->y.p.whole + fixedMulSin2(((o->unk8C >> 4) + 0x40) & 0xff, 0x19a);
                o->unk38 = D_800A53DC_Fix16PtrArr[0]->p.whole;
            }
            if ((*(Fix16 **)&PLAYER.obj.h)->p.whole < 0x53c) o->subState++;
            break;
        case 2:
            if (func_80022D3C(o, 0x24)) o->subState = 0;
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B8C4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011B91C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BA78);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BD20);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011BFF8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C218);
typedef struct {
    s16 x0, x2, x4, x6, x8, xa, xc, n;
    s16 w10, w12, w14, w16, w18;
    u8 b1a, b1b;
    s16 w1c, w1e, w20;
} Seg_1C218;

typedef struct {
    s16 f0, f2, f4, f6, f8, fa, fc, fe;
} Ctx_1C218;

extern Seg_1C218 D_800A37D8[];
extern s32 rcos(s32);
extern s32 rsin(s32);

void func_8011C218(Ctx_1C218 *c)
{
    Seg_1C218 *s = &D_800A37D8[c->f4];
    Seg_1C218 *n;
    s32 a;
    register s32 b asm("$17");
    register s32 h asm("$2");
    s32 d;
    s32 e;
    s32 k;
    register s32 v asm("$2");
    s32 f0;
    s32 kp;
    s32 a2;
    s32 a3;
    s32 b2;
    s32 w;
    s16 t;
    s16 dx;
    s16 dy;

    f0 = c->f0; a = ((c->f2 - f0) * s->w20) / c->f2;
    w = s->w10;
    kp = c->f0 * w;
    b = kp / c->f2;
    a2 = (kp * (100 - a) / 100) / c->f2;
    n = &D_800A37D8[c->f4 + 1];
    dy = n->x2 - s->x2;
    dx = n->x0 - s->x0;
    h = (0x800 - w) / 2;
    t = h;
    b2 = h + b;
    a3 = h + a2;
    dx = (dx << 12) / rcos(t);
    d = rcos(t) - rcos((s16)b2);
    k = dx / 2;
    c->fa = (d * k) / 4096;
    e = rsin(t) - rsin((s16)a3);
    e = -((e * k) / 4096);
    if (c->f6 == c->f4) {
        if (c->f0 < c->f8) v = ((c->f0 - c->f8) << 6) / c->f8;
        else { register s32 q asm("$3"); q = ((c->f0 - c->f8) << 6); q = q / (c->f2 - c->f8); v = q; }
        e += fixedMulCos2(v & 0xff, s->w16);
    }
    c->fc = (c->f0 * dy) / c->f2 + ((s16)e * s->w12) / 100;
    c->fe = 0;
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C5B4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C5DC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C678);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C730);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C820);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011C914);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CA8C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CB24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CC08);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CCE8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CDD8);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CE24);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CEAC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CF50);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011CF9C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D098);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D0E4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D1A8);

void func_8011D41C(void) {
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D424);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D4F4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D6A8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D75C);
typedef struct SPADBlock_1D75C {
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
} SPADBlock_1D75C;
extern void func_8011D874(GameObject *, s16);

void func_8011D75C(GameObject *o)
{
    u8 *p;
    s16 n;

    switch (o->state) {
    case 0:
        p = (u8 *)o + 0xa5;
        n = *(u16 *)(o->unkA0 + 4);
        do {
            *p++ = 0;
        } while (--n);
        o->unk68 = 0;
        o->objectIndex = 0;
        o->unk6A = 0;
        o->velV = 0;
        o->unk34 = 0;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        if ((*(s16*)((char*)&(*(SPADBlock_1D75C *)&SCRATCHPAD).iec + 2)) < 0x4b0) {
            o->visible = 1;
            pushDrawListLayer4(o);
        }
        func_8011D874(o, (s16)((*(u16*)((char*)&(*(SPADBlock_1D75C *)&SCRATCHPAD).i168 + 2)) - o->x.p.whole) >> 4);
        o->unk68 = 0;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D874);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011D9CC);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011DA00);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011DE38);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E210);
#define U8(o,n)  (*(u8 *)((char *)(o) + (n)))
#define S8(o,n)  (*(s8 *)((char *)(o) + (n)))
#define U16(o,n) (*(u16 *)((char *)(o) + (n)))
#define S16(o,n) (*(s16 *)((char *)(o) + (n)))
#define S32(o,n) (*(s32 *)((char *)(o) + (n)))
#define PTR(o,n) (*(void **)((char *)(o) + (n)))

typedef struct {
    s16 w0[5];
    s16 a;
    s16 w0c[3];
    s16 b;
    s16 w14[3];
    s16 c;
    s16 w1c[3];
    s16 d;
    s16 w24[2];
} Seg_1E210;

extern s16 D_8007DB08[];

void func_8011E210(GameObject *o)
{
    s32 *q;
    Seg_1E210 *s;
    Seg_1E210 *e;
    s16 n, k;
    s32 i, v;
    s32 one;
    u8 *b;

    s = (Seg_1E210 *)o->unkA0;
    k = o->objectIndex;
    s = (Seg_1E210 *)((s32 *)s + 1);
    n = *(s32 *)s;
    s = (Seg_1E210 *)((s32 *)s + 1);
    if (k == 0) return;
    if (k == n - 1) return;
    e = s;
    e->c = 5;
    e->a = 0;
    e += k;
    for (i = 1; i < k; i++) {
        s32 d = k;
        v = (e->a + e->a * D_8007DB08[(i << 6) / d]) >> 12;
        (s + k - i)->a = v;
        (s + k - i)->c = v + 5;
    }
    for (i = 1; i <= k; i++) {
        e = s + k - i;
        b = (u8 *)o + 0xa5;
        b = b + (k - i);
        e->b = e[1].a;
        e->d = e[1].c;
        *b = 1;
    }
    e = &s[k];
    for (i = 1; i < n - k; i++) {
        s32 d = k;
        v = (e->a + e->a * D_8007DB08[(i << 6) / (n - d)]) >> 12;
        { Seg_1E210 *m = s + d + i; m->a = v; m->c = v + 5; }
    }
    for (i = 1; one = 1, i < n - (k + one); i++) {
        e = s + k + i;
        b = (u8 *)o + 0xa5;
    asm("");
        b += k + i;
        e->b = e[1].a;
        e->d = e[1].c;
        *b = 2;
    }
    e = s + (n - 1);
    e->d = 5;
    e->b = 0;
    *((u8 *)o + n + 0xa4) = 2;
}
#undef U8
#undef S8
#undef U16
#undef S16
#undef S32
#undef PTR

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E4F8);
typedef struct SPADBlock_1E4F8 {
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
} SPADBlock_1E4F8;

extern void *D_8013D960[];

void func_8011E4F8(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 8;
        o->unkD = 0;
        o->anim = D_8013D960[o->subtype];
        o->spriteBank = ((s32*)&(*(SPADBlock_1E4F8 *)&SCRATCHPAD).i2d4)[0];
        switch (o->subtype) {
        case 0 ... 1:
            o->hitWidth = 0x10;
            o->hitOffsetY = 2;
            o->hitOffsetX = 8;
            o->hitHeight = 0x72;
            break;
        case 2:
            o->active = 2;
            break;
        }
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022C08(o, 0x60);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_1", func_8011E600);
typedef struct GCDBlock_1E600 {
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
} GCDBlock_1E600;

typedef struct GVars_1E600 {
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
} GVars_1E600;

typedef struct { s8 anim, z, ang, rad; } E4_1E600;

extern u8 D_800A5399[];
extern Fix16 * D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
extern Fix16 * D_800A53DC__1E600[];
extern s32 D_800A5424[];
extern u8 D_800A53A7[];
extern u8 D_8009BCED;
extern E4_1E600 D_80011F90[];
extern void *D_8013DA84;
extern void *D_8013DA80;
extern s32 fixedMulCos(s16 a, s32 b);
extern s32 fixedMulSin(s16 a, s32 b);
extern void printInfoMessage(s32, s32);
extern void addItemToInventory(s32, s32, s32);

void func_8011E600(GameObject *o)
{
    E4_1E600 *e;
    s16 c;
    s32 x, y;
    u16 u;

    o->visible = D_800A5399[0];
    switch (o->step) {
    case 0:
        c = D_8009BCED & 1;
        if ((*(GVars_1E600 *)&D_8009BC98).b40) {
            switch ((*(GVars_1E600 *)&D_8009BC98).b41) {
            case 5:
            case 7:
            case 0xe:
            case 0x7c:
            case 0x97:
            case 0x98:
                c++;
            }
        }
        if (c) {
            printInfoMessage(0xf, 2);
            o->state = 3;
            o->subState = 0;
            o->step = 0;
        }
        e = &D_80011F90[((s8 *)&D_80012014)[*(*(u16 **)&PLAYER.obj.anim)]];
        if (D_8009C068.bcead == 0) {
            o->state = 3;
            break;
        }
        if (D_8009C068.bcead == 1) o->anim = D_8013DA84;
        else o->anim = D_8013DA80;
        if (o->animFrame & 1) {
            u = D_800A5424[0] + 0x80 - e->ang;
            c = u; c &= 0xff;
        } else {
            u = e->ang + D_800A5424[0];
            c = u; c &= 0xff;
        }
        y = fixedMulCos(c, e->rad);
        x = fixedMulSin(c, e->rad);
        o->visible = D_800A5399[0];
        o->animFrame = ((u16 *)&D_800A53C6)[0] & 1;
        o->h->p.whole = D_800A53D8_Fix16PtrArr[0]->p.whole + y;
        o->y.p.whole = D_800A53AE[0] + x;
        o->d->p.whole = D_800A53DC__1E600[0]->p.whole;
        o->unk8C = D_800A5424[0];
        o->unkF = D_800A53A7[0] + e->z;
        o->category |= 0x80;
        readAnimFrameCount(o);
        break;
    case 1:
        e = &D_80011F90[((s8 *)&D_80012014)[*(*(u16 **)&PLAYER.obj.anim)]];
        if (o->animFrame & 1) {
            u = D_800A5424[0] + 0x80 - e->ang;
            c = u; c &= 0xff;
        } else {
            u = e->ang + D_800A5424[0];
            c = u; c &= 0xff;
        }
        o->h->p.whole = D_800A53D8_Fix16PtrArr[0]->p.whole + fixedMulCos(c, e->rad);
        o->y.p.whole = D_800A53AE[0] + fixedMulSin(c, e->rad);
        o->d->p.whole = D_800A53DC__1E600[0]->p.whole;
        o->unk8C = D_800A5424[0];
        o->unkF = D_800A53A7[0] + e->z;
        if (tickAnimation(o)) {
            playSFX(9);
            {
                u8 *k = &D_8009C068.bcead;
                s32 a;
                *k = *k + 1;
                switch (*k) {
                case 2:
                    a = 0xd;
                    goto call;
                case 3:
                    a = 0xe;
                call:
                    printInfoMessage(a, 3);
                    o->step = 0;
                    break;
                default:
                    o->state = 3;
                    do { } while (0);
                    removeItemFromInventory(0xa, 1);
                    addItemToInventory(0x12, 1, 1);
                    o->step = 0;
                    break;
                }
            }
        }
        break;
    }
}
