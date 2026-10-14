#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80118944);
extern s32 D_1F8002D4;
extern u8 D_800A53A7;
extern void readAnimFrameCount(GameObject *);
extern void func_80118CD8(GameObject *);
extern void func_80118BB4(GameObject *);
extern void tickAnimation(GameObject *);
extern void removeItemFromInventory(s32, s32);
extern void queueSfxKeyOff(s32);
extern void freeObjectLayer3(GameObject *);

typedef struct P_18944 { char p[0xcc]; s16 cc; } P_18944;
void func_80118944(GameObject *o)
{
    u8 s = o->state;
    switch (s) {
    case 0:
        o->state = s + 1;
        o->tpage = 9;
        o->unkA = 1;
        *(s16 *)((u8 *)o + 0x2e) = 1;
        o->spriteBank = D_1F8002D4;
        *(s32 *)((u8 *)o + 0x5c) = 0x1000;
        *(s32 *)((u8 *)o + 0x60) = 0x1000;
        *(s32 *)((u8 *)o + 0x64) = 0x1000;
        o->timer = 0;
        o->unkB4 = 0;
        o->unkB6 = 0;
        o->unkB8 = 0;
        ((P_18944 *)o)->cc = 0x78;
        switch (o->subtype) {
        case 0:
        case 1:
            o->unkD = 0x80;
            o->subState = 10;
            break;
        case 2:
        case 3:
            *(s16 *)((u8 *)o + 0xc0) = 0;
            *(s16 *)((u8 *)o + 0xc2) = 0;
            *(s16 *)((u8 *)o + 0xc4) = 0;
            o->unkD = 0x80;
            o->subState = 7;
            *(s16 *)((u8 *)o + 0xc6) = *(s16 *)((u8 *)o + 0xc0);
            *(s16 *)((u8 *)o + 0xc8) = *(s16 *)((u8 *)o + 0xc2);
            *(s16 *)((u8 *)o + 0xca) = *(s16 *)((u8 *)o + 0xc4);
            break;
        case 4:
            o->unkD = 0;
            break;
        case 5:
            break;
        case 6:
            (*(u8 *)&D_8009BC98) = 2;
        case 7:
            *(s16 *)((u8 *)o + 0xc0) = 0;
            *(s16 *)((u8 *)o + 0xc2) = 0;
            *(s16 *)((u8 *)o + 0xc4) = 0;
            o->unkD = 0x80;
            o->subState = 5;
            *(s16 *)((u8 *)o + 0xc6) = *(s16 *)((u8 *)o + 0xc0);
            *(s16 *)((u8 *)o + 0xc8) = *(s16 *)((u8 *)o + 0xc2);
            *(s16 *)((u8 *)o + 0xca) = *(s16 *)((u8 *)o + 0xc4);
            break;
        }
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->subtype != 4) {
            func_80118CD8(o);
            if (o->subtype == 1)
                o->unkF = D_800A53A7 + 10;
            else
                o->unkF = D_800A53A7 - 2;
        } else {
            func_80118BB4(o);
            o->unkF = D_800A53A7;
        }
        tickAnimation(o);
        if (((GameObject *)o->unk90)->subState != 5)
            func_80022E44(o);
        if ((*(u8 *)&D_8009BC98) != 0)
            break;
        o->state++;
        break;
    case 2:
        if (o->subtype == 0 || o->subtype == 6) {
            removeItemFromInventory(4, 1);
            queueSfxKeyOff(*(u16 *)((char *)o + 0xce));
        }
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80118BB4);
struct V3_18BB4 { s32 x, y, z; };
extern s16 fixedMulSin2(s32, s32);

void func_80118BB4(GameObject *o)
{
    GameObject *p;
    s32 r;

    p = (GameObject *)o->unk90;
    *(struct V3_18BB4 *)&o->x = *(struct V3_18BB4 *)&p->x;
    r = fixedMulSin2(o->unkB4, *(s16 *)&o[1].active);
    o->h->raw = o->h->raw + r * 0x10000;
    r = fixedMulCos2(o->unkB6, *(s16 *)&o[1].type);
    o->y.raw = o->y.raw + r * 0x10000;
    r = fixedMulCos2(o->unkB8, *(s16 *)&o[1].state);
    o->d->raw = o->d->raw + r * 0x10000;
    o->unkB4 = (o->unkB4 + o->unkBA) & 0xff;
    o->unkB6 = (o->unkB6 + o->unkBC) & 0xff;
    o->unkB8 = (o->unkB8 + *(s16 *)&o->unkBE) & 0xff;
    o->buffSize = p->buffSize;
    if (p->state > 1)
        o->state = o->state + 1;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80118CD8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119404);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119498);
typedef struct { s32 x, y, z; } V3_19498;
typedef struct { s16 x, y, z; } S3_19498;
typedef struct {
    u8 active, visible, type, subtype;
    u8 _p04[0xc];
    V3_19498 pos;
    u8 _p1c;
    s8 b1d;
    u8 _p1e[6];
    void *anim;
    u8 _p28[8];
    V3_19498 pos30;
    u8 _p3c[0x54];
    void *d90;
    void *d94;
    u8 _p98[0x22];
    s16 wba;
    s16 wbc;
    s16 wbe;
    S3_19498 c0;
    S3_19498 c6;
    s16 cc;
} OX_19498;
extern void *D_8013A500[];
extern void *D_8013A4FC;

void func_80119498(s32 x, s32 y, s32 z, u8 sub)
{
    extern void func_80119648(OX_19498 *, s32);
    OX_19498 *o;
    OX_19498 *p;
    void *a;

    if (D_8009BCCE < 3) {
        o = allocObjectLayer3();
        if (o != 0) {
            o->active = 1;
            o->type = 9;
            o->subtype = sub;
            o->pos.x = x << 16;
            if (sub == 0) {
                o->pos.y = (y << 16) - 0x100000;
                o->pos.z = (z << 16) - 0x680000;
            } else {
                o->pos.y = y << 16;
                o->pos.z = z << 16;
            }
            o->b1d = -1;
            o->pos30 = o->pos;
            a = D_8013A500[0];
            o->c0.x = 0x28;
            o->c0.y = 4;
            o->c0.z = 0x80;
            o->d90 = o;
            o->wba = 0;
            o->wbc = 0;
            o->wbe = 0;
            o->cc = 0x80;
            o->anim = a;
            o->c6.x = *(volatile s16 *)&o->c0.x;
            o->c6.y = *(volatile s16 *)&o->c0.y;
            o->c6.z = *(volatile s16 *)&o->c0.z;
            p = allocObjectLayer3();
            if (p != 0) {
                p->active = 1;
                p->type = 9;
                p->subtype = sub + 1;
                p->pos = o->pos;
                p->b1d = -1;
                p->pos30 = p->pos;
                p->anim = D_8013A4FC;
                o->d94 = p;
                p->d90 = o;
            }
            func_80119648(o, 4);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119648);
typedef struct { s32 x, y, z; } V3_19648;
typedef struct P_19648 {
    u8 active, b01, type, subtype;
    char pad1[0x10 - 4];
    V3_19648 pos;
    char pad2[0x1d - 0x1c];
    s8 b1d;
    char pad3[0x24 - 0x1e];
    s32 d24;
    char pad4[0x90 - 0x28];
    s32 d90, d94;
    char pad5[0xba - 0x98];
    u16 ba, bc, be, c0, c2, c4, c6, c8, ca, cc;
} P_19648;
extern s32 D_8013A504[];

void func_80119648(P_19648 *s, u8 t)
{
    s32 i, a, b, c;
    s32 *tp;
    P_19648 *p;
    s32 v, one;
    u16 x0, x1, x2;
    for (i = 0, one = 1, b = 4, c = 16, a = 5, tp = D_8013A504; i < 4; b += 4, c += 4, a += 2, i++, tp++) {
        p = allocObjectLayer3();
        if (p) {
            p->active = one;
            p->type = 9;
            p->subtype = t;
            p->pos = s->pos;
            p->b1d = -1;
            v = *tp;
            p->c0 = c;
            x0 = *(volatile u16 *)&p->c0;
            p->c2 = b;
            x1 = *(volatile u16 *)&p->c2;
            p->c4 = one;
            x2 = *(volatile u16 *)&p->c4;
            p->d90 = (s32)s;
            p->d94 = 0;
            p->ba = a;
            p->bc = i + 2;
            p->be = a;
            p->cc = 0;
            p->d24 = v;
            p->c6 = x0;
            p->c8 = x1;
            p->ca = x2;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119768);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119798);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_8011998C);
extern void *D_8013A55C[];
extern s32 D_1F8002D4_S32Arr[] asm("D_1F8002D4");
void func_8011998C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->unk98 = 10;
        o->tpage = 0xc;
        *(s8 *)&o->unkF = -5;
        o->unk9A = 0;
        o->unkD = 0;
        o->unkA = 0;
        o->animFrame = 0;
        o->state = o->state + 1;
        o->anim = D_8013A55C[o->subtype];
        o->spriteBank = D_1F8002D4_S32Arr[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o) != 0 && o->subtype == 0)
            func_80119768(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119A94);
extern void *D_8013A58C[];
void func_80119A94(GameObject *o)
{
    s16 f;
    switch (o->state) {
    case 0:
        if (o->timer == 0) {
        o->state++;
        o->tpage = 9;
        o->unkA = 3;
        o->buffSize = 0xac8;
        o->unkD = 0;
        *(s8 *)&o->unkF = -10;
        o->anim = D_8013A58C[o->unkC];
        o->spriteBank = D_1F8002D4_S32Arr[0];
        o->animFrame = nextRandom() & 1;
        switch (o->subtype) {
        case 0:
            o->unk8C = 0x40;
            o->unk84 = -2;
            o->velH = 0x100;
            o->velX = -8;
            o->velV = 0x100;
            break;
        case 1:
            o->unk8C = -0x40;
            o->unk84 = 2;
            o->velH = -0x100;
            o->velX = 8;
            o->velV = 0xc0;
            break;
        case 2:
            o->unk8C = -0x60;
            o->unk84 = 2;
            o->velH = 0x100;
            o->velX = -8;
            o->velV = 0x80;
            break;
        case 3:
            o->unk8C = 0x60;
            o->unk84 = -2;
            o->velH = -0x100;
            o->velX = 8;
            o->velV = 0x80;
            break;
        }
        readAnimFrameCount(o);
        } else {
            o->timer--;
        }
        break;
    case 1:
        if (func_80022E44(o) == 0) {
            o->state = 3;
            break;
        }
        o->y.raw += o->velV << 8;
        o->h->raw += o->velH << 8;
        o->velH += o->velX;
        {
            s32 vx = o->velX;
            if (vx < 0 && o->velH < -0xff)
                o->velX = -vx;
            else {
                s32 w = o->velX;
                if (w > 0 && o->velH > 0xff)
                    o->velX = -w;
            }
        }
        o->unk8C += o->unk84;
        switch (o->subtype) {
        case 0 ... 1:
            f = (u32)(o->unk8C + 0x3f) < 0x7f;
            goto tail;
        case 2 ... 3:
            f = (u32)(o->unk8C + 0x5f) < 0xbf;
        tail:
            if (!f)
                o->unk84 = -o->unk84;
            break;
        }
        if (++o->timer >= 0x78)
            o->state = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119D80);
void func_80119D80(s16 x, s16 y, s16 z)
{
    s32 i;
    char *o;
    for (i = 0; i < 3; i++) {
        o = allocObjectLayer3();
        if (o != 0) {
            *(u8 *)((u8 *)o + 0) = 1;
            *(u8 *)((u8 *)o + 2) = 0xb;
            **(s32 **)(o + 0x40) = (x + i * 0x18 - 0x18) << 16;
            *(s32 *)((u8 *)o + 0x14) = (y + (i - 1) * 0x10) << 16;
            **(s32 **)(o + 0x44) = z << 16;
            *(u8 *)((u8 *)o + 3) = nextRandom() & 3;
            *(u8 *)((u8 *)o + 0xc) = nextRandom() & 1;
            *(u16 *)((u8 *)o + 0x20) = nextRandom() & 0x1f;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_1", func_80119E60);
extern u8 *D_8013A460;
extern u8 *D_8009B698;

void func_80119E60(u8 *o)
{
    u8 s;
    s32 t;
    u8 *u;
    s = o[4];
    switch (s) {
    case 0:
        o[4] = s + 1;
        *(s16 *)(o + 0x2e) = 0;
        *(s16 *)(o + 0x1e) = 0xc;
        t = D_1F8002D4;
        o[0xd] = 0;
        o[0xa] = 0;
        *(s8 *)(o + 0xf) = -7;
        u = D_8013A460;
        *(s32 *)(o + 0x3c) = t;
        *(u8 **)(o + 0x24) = u;
        readAnimFrameCount(o);
        break;
    case 1:
        func_80022E44(o);
        switch (o[5]) {
        case 0:
            if (D_8009B698[10] == o[0xc]) {
                *(u8 **)(o + 0x24) = D_8013A460;
                readAnimFrameCount(o);
                o[5]++;
            }
            break;
        case 1:
            if (((s32 (*)(u8 *))tickAnimation)(o) != 0)
                o[5] = 0;
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
