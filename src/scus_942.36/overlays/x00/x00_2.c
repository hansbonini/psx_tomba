#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_80119FA8);
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A5401;
extern u8 D_8009C116;

void func_80119FA8(GameObject *o)
{
    switch (o->subState) {
    case 1:
        switch (o->step) {
        case 0:
            o->timer = 0xf0;
            o->step++;
        case 1:
            o->unk34++;
            if (--o->timer == 0) {
                o->subState = 2;
                o->step = 0;
                if (D_800A539C_U8Arr[0] != 1) {
                    D_800A53C6 = 0;
                    D_800A539C_U8Arr[0] = 1;
                    D_800A539D = 0;
                    D_800A539E = 0;
                    D_8009BCA7 = 0;
                }
            }
        }
        break;
    case 5:
        if (D_8009C116 == 0xff && (*(s16 *)&D_800A53AE) > -200 && D_800A5401 != 0 && D_800A539C != 1) {
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 0: case 2: case 3: case 4:
        break;
    case 6:
        o->unk34 = 0x54;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A0E8);
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void pushDrawListCapped(GameObject *);
extern void freeObjectLayer3(GameObject *);
extern void *D_8013A5EC;
extern void *D_8013A5F0;
extern void *D_8013A5F4[];
extern void *D_8013A600;
extern void *D_8013A604;
extern void *D_8013A608;
extern void *D_8013A60C[];
extern void *D_8013A610;

void func_8011A0E8(GameObject *o)
{
    s32 x;

    switch (o->state) {
    case 0:
        o->state++;
        o->unkD = 0x80;
        o->animFrame = 1;
        o->tpage = 0xb;
        o->unkA = 7;
        o->z.p.whole = 200;
        o->unkF = 0;
        o->unk30 = o->x.p.whole;
        o->unk34 = o->y.p.whole;
        switch (o->subtype) {
        case 0:
            o->anim = D_8013A5EC;
            break;
        case 1:
            o->unkD = 1;
            o->anim = D_8013A5F0;
            o->timer = 10;
            o->cooldownTimer = 0;
            break;
        case 2:
            o->anim = D_8013A5F4[o->unkC];
            break;
        case 3:
            o->unkD = 0x81;
            o->anim = D_8013A600;
            o->timer = 10;
            o->cooldownTimer = 0;
            break;
        case 4:
            o->anim = D_8013A604;
            o->tpage = 9;
            o->timer = 10;
            o->unkD = 0;
            o->cooldownTimer = 0;
            o->animFrame = 1;
            o->step = 0;
            break;
        case 5:
            o->z.p.whole = 0;
            o->anim = D_8013A608;
            o->unkD = 1;
            o->clut = GetClut(0x80, 0x1ff);
            o->animFrame = 1;
            o->tpage = 7;
            o->unkF = 10;
            break;
        case 6:
            o->z.p.whole = 0;
            o->anim = D_8013A60C[0];
            o->unkD = 1;
            o->clut = GetClut(0x80, 0x1ff);
            o->animFrame = 1;
            o->tpage = 7;
            o->unkF = 10;
            break;
        case 7:
            o->anim = D_8013A610;
            o->unkD = 1;
            o->clut = GetClut(0x80, 0x1ff);
            o->animFrame = 1;
            o->tpage = 7;
            break;
        }
        o->spriteBank = ((struct { char pad[0x2d4]; s32 v; } *)0x1F800000)->v;
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        o->x.p.whole = o->unk30 - ((struct { char pad[0x176]; u16 v; } *)0x1F800000)->v;
        o->y.p.whole = o->unk34 - ((struct { char pad[0x186]; u16 v; } *)0x1F800000)->v;
        pushDrawListCapped(o);
        switch (o->subtype) {
        case 1:
            if (--o->timer == 0) {
                x = 0xd0;
                goto common;
            }
            break;
        case 3:
            if (--o->timer == 0) {
                x = 0xe0;
            common:
                o->timer = 10;
                o->cooldownTimer ^= 1;
                o->clut = GetClut(x, o->cooldownTimer + 0x1ed);
            }
            break;
        case 4:
            func_80119FA8(o);
            break;
        }
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

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A424);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A4B4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A530);
extern void *D_8013A478;
extern s32 D_1F8002E8;

void func_8011A530(GameObject *o)
{
    u8 b = o->state;
    s32 v;
    void *p;
    switch (b) {
    case 0:
        switch (o->subState) {
        case 0:
            v = D_1F8002E8;
            p = D_8013A478;
            o->tpage = 1;
            o->unkA = 2;
            o->unkD = 0;
            *((u8 *)o + 0x68) = 0;
            o->unkF = 5;
            o->animFrame = 0;
            o->spriteBank = v;
            o->anim = p;
            o->subState++;
            break;
        case 1:
            o->state = b + 1;
            o->subState = 0;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectLayer3(o);
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A638);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A650);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A7C0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A800);
extern void freeObjectUnlayered(GameObject *);

void func_8011A800(GameObject *o)
{
    extern GameObject *showMessageBox(s32, s32, s32, s32);
    GameObject *q;
    switch (o->subState) {
    case 0:
        if (o->visible != 0)
            o->subState++;
        else
            o->subState = 2;
        break;
    case 1:
        if (D_8009BC9B == 0) {
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            (*(u8 *)&D_8009C618) = 0;
            o->subState++;
        }
        break;
    case 2:
        o->subState++;
        *(GameObject **)&o->category = showMessageBox(10, 0, 100, 236);
        break;
    case 3:
        q = *(GameObject **)&o->category;
        if (q->state == 2) {
            q->state = 3;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            D_8009BCAA = 0;
            freeObjectUnlayered(o);
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011A92C);
extern s16 D_1F80016E;
extern s16 D_1F80017A;
extern s16 D_801379EC[];
extern s32 showMessageBox(s32, s32, s32, s32);

void func_8011A92C(GameObject *o)
{
    u8 t = o->subState;
    switch (t) {
    case 0:
        o->subState = t + 1;
        if ((*(s16 *)&D_1F800176) + 0xa0 >= (*(s16 *)&D_1F80016A))
            o->x.p.whole = 0xf0;
        else
            o->x.p.whole = 0x50;
        if (D_1F80017A - 0x78 >= D_1F80016E)
            o->y.p.whole = 0xd8;
        else
            o->y.p.whole = 0x78;
        o->unk90 = showMessageBox(9, D_801379EC[(*(s16 *)&D_8009E744)], o->x.p.whole, o->y.p.whole);
        break;
    case 1:
        if (((char *)o->unk90)[4] == 2) {
            ((char *)o->unk90)[4] = 3;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            freeObjectLayer3(o);
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011AA30);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011AAF4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011AB40);
extern u8 D_8009C114;
extern s32 D_1F8002D4[];
extern void *D_8013A4B0[];
extern void freeObjectLayer3(GameObject *o);

void func_8011AB40(GameObject *o)
{
    u8 s = o->state;
    switch (s) {
    case 0:
        if (D_8009C114 != 0xff) {
            o->state = 3;
        } else {
            o->state = s + 1;
            o->tpage = 8;
            o->spriteBank = D_1F8002D4[0];
            o->unkD = 0;
            o->anim = D_8013A4B0[o->unkC];
        }
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011AC10);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011B1CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011B2B8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011B91C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011BA78);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011BB54);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011BD20);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011BFF8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C360);
typedef struct {
    char p0[3]; u8 sub, st, p1[7]; u8 b0c; char p2[0x20 - 0xd]; s16 w20; char p3[0x2c - 0x22]; u16 w2c, w2e;
    char p4[0x69 - 0x30]; u8 b69; char p5[0x6c - 0x6a]; u16 w6c, w6e, w70, w72; char p6[0x7c - 0x74]; u16 w7c, w7e;
    char p7[0x84 - 0x80]; s32 d84, d88, d8c; char p8[0xa5 - 0x90]; u8 ba5, ba6;
} O_1C360;
typedef void (*FN_1C360)(O_1C360 *);
extern char *D_80137EB4[];
extern FN_1C360 D_80137EC0[];
extern FN_1C360 D_80137ECC[];
extern FN_1C360 D_80137EDC[];

void func_8011C360(O_1C360 *o)
{
    extern void freeObjectLayer4(O_1C360 *);
    u16 *p;
    u8 s;
    u16 w;

    switch (o->st) {
    case 0:
        p = (u16 *)D_80137EB4[o->sub] + o->b0c * 8;
        o->w6c = *p++;
        o->w6e = *p++;
        o->w70 = *p++;
        o->w7c = *p;
        o->w72 = *p++;
        o->ba5 = *p++;
        o->ba6 = *p++;
        o->w2c = *p;
        w = p[1];
        o->d84 = 0;
        o->d88 = 0;
        o->d8c = 0;
        o->w2e = 0x80;
        o->w20 = 0;
        o->b69 = 0;
        o->st++;
        o->w7e = w;
        break;
    case 1:
        if (func_80022E44(o)) {
            switch (o->sub) {
            case 0:
                D_80137EC0[o->b0c](o);
                break;
            case 1:
                D_80137ECC[o->b0c](o);
                break;
            case 2:
                D_80137EDC[o->b0c](o);
                break;
            }
        }
        break;
    case 2:
        o->st = o->st + 1;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C554);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C580);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C5A0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C5CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C5F8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C624);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C650);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C678);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C730);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C914);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011C9C0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CB24);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CC08);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CCE8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CD28);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CE24);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CF50);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011CF9C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D098);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D1A8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D1D4);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D2B0);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D378);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D41C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D43C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D4F4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D500);
typedef struct { char p0[6]; u8 st; char p1[0x16 - 7]; u16 w16; char p2[0x88 - 0x18]; s32 d88; } O_1D500;
extern u8 D_800A543A;

void func_8011D500(O_1D500 *o)
{
    s32 t;
    u8 c;
    switch (o->st) {
    case 0:
        if ((u16)((*(u16 *)&D_1F80016A) - 0x400) >= 0x18) break;
        if ((u16)(o->w16 - D_1F80016E + 0x30) > 0x60) break;
        if (D_800A543A == 1) break;
        if (D_800A543A == 2) {
            c = o->st;
            o->d88 = 0;
            goto inc2;
        }
        if (D_8009BCA2 != 0) break;
        if ((*(s8 *)&D_8009C618) >= 3) break;
        if ((*(s16 *)&D_1F800172) <= 0) break;
        o->st = 3;
        o->d88 = 0xa00;
        break;
    case 1:
        t = (o->d88 - 0x20) & 0xfff;
        o->d88 = t;
        if (t > 0xa00) break;
        goto inc;
    case 2:
        break;
    case 3:
        t = (o->d88 + 0x20) & 0xfff;
        o->d88 = t;
        if (t != 0) break;
    inc:
        c = o->st;
    inc2:
        o->st = c + 1;
        break;
    case 4:
        if (D_8009BCA2 != 0)
            o->st = 0;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D65C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D6A8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011D9CC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011DA00);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011DB88);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011DE38);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011DFB8);
typedef union { s32 raw; struct { u16 frac; s16 whole; } p; } FX_1DFB8;
typedef struct S_1DFB8 {
    u8 active, visible, p02[2], b04, p05[7], b0c, p0d[2], b0f;
    FX_1DFB8 a, y, b;
    char p1c[0x2e - 0x1c];
    u16 animFrame;
    char p30[0x68 - 0x30];
    u8 b68, b69, p6a[2];
    s16 box0, box1, box2, box3;
    char p74[0x84 - 0x74];
    s32 d84, d88, d8c, d90;
    struct S_1DFB8 *next;
    char p98[0xb4 - 0x98];
    u16 wb4, wb6;
    u16 *pb8, *pbc;
    u16 wc0, pc2;
    s32 c4, c8, cc;
} S_1DFB8;
extern u16 *D_801380A4[];
extern u16 *D_80138098[];
extern u16 D_80138050[];
extern s32 DAT_8009c984;
extern s32 D_8009BCEC[];
extern s32 D_8009BCEC[];
extern u8 D_8009BCA0_U8Arr[] asm("D_8009BCA0");
extern u8 DAT_8009c938;
extern void func_80119498(s32, s32, s32, s32);
extern void setEventStarted(s32, s32, s32);
extern void playSFX(s32);

void func_8011DFB8(S_1DFB8 *o)
{
    S_1DFB8 *q, *p;
    s32 a, y, b;
    s32 flag;
    u16 **pp;
    VECTOR in, out;
    SVECTOR v;
    MATRIX m;
    char pad[16];

    switch (o->b04) {
    case 0:
        if (o->d90 == 0) {
            q = o;
            p = o;
            a = o->a.raw;
            y = o->y.raw;
            b = o->b.raw;
            for (;;) {
                q->wb4 = 0;
                q->wb6 = 0;
                q->pb8 = D_801380A4[q->b0c];
                q->pbc = D_801380A4[q->b0c];
                switch (q->b0c) {
                case 1:
                    q->box0 = 0x10;
                    q->box1 = 0x20;
                    q->box2 = 0x1e;
                    q->box3 = 100;
                    q->wc0 = 0;
                    q->b0f = 0;
                    if (!(D_8009BCEC[0] & 1))
                        func_80119498(q->a.p.whole, q->y.p.whole, q->b.p.whole, 0);
                    break;
                case 0:
                    q->active = 2;
                    q->b0f = 0;
                    break;
                case 2:
                    q->active = 2;
                    *(s8 *)&q->b0f = -1;
                    break;
                }
                q = q->next;
                if (q == 0)
                    break;
                p->c4 = q->a.raw - a;
                p->c8 = q->y.raw - y;
                p->cc = q->b.raw - b;
                a = q->a.raw;
                y = q->y.raw;
                b = q->b.raw;
                p = q;
            }
        }
        o->b04++;
        break;
    case 1:
        if (o->d90 == 0) {
            for (q = o; ; q = q->next) {
                if (q->b0c == 1) {
                    flag = 0;
                    if (!(D_8009BCEC[0] & 1) && (nextRandom() & 0x3f) == 0) {
                        o->wb4 = 2;
                        flag = 0; if (!(D_8009BCEC[0] & 1)) flag = 1;
                    }
                    if (q->b69 == 1 && o->wb6 == 0) {
                        o->wb4 = 1;
                        o->wb6 = 4;
                        if (!(D_8009BCEC[0] & 1))
                            flag = 1;
                        q->wc0 = 0x28;
                    }
                    if (q->b68 == 1 && o->wb6 == 0) {
                        o->wb4 = 1;
                        o->wb6 = 4;
                        if (!(D_8009BCEC[0] & 1))
                            flag = 1;
                        q->wc0 = 0x28;
                    }
                    q->b69 = 0;
                    q->b68 = 0;
                    o->animFrame = q->animFrame;
                    if (D_8009BCA0_U8Arr[0] == 0 && q->wc0 != 0 && --q->wc0 == 0 && !(D_8009BCEC[0] & 1)) {
                        D_8009BCEC[0] |= 1;
                        setEventStarted(2, 0, 0);
                        playSFX(0x35);
                    }
                    break;
                }
            }
            q = o;
            a = o->a.raw;
            y = o->y.raw;
            b = o->b.raw;
            for (;;) {
                pp = &q->pb8;
                if (flag) {
                    q->wb4 = o->wb4;
                    switch (o->wb4) {
                    case 1:
                        q->pb8 = D_80138098[q->b0c];
                        break;
                    case 2:
                        q->pbc = D_80138050;
                        break;
                    }
                }
                v.vx = *pp[0];
                v.vy = 0;
                v.vz = *pp[1];
                RotMatrix(&v, &m);
                q->d84 = v.vx;
                q->d88 = v.vy;
                q->d8c = v.vz;
                if (*++pp[0] == 0x8000) {
                    q->wb4 = 0;
                    pp[0] = D_801380A4[q->b0c];
                }
                if (*++pp[1] == 0x8000)
                    pp[1] = D_801380A4[q->b0c];
                in.vx = q->c4;
                in.vy = q->c8;
                in.vz = q->cc;
                ApplyMatrixLV(&m, &in, &out);
                a += out.vx;
                y += out.vy;
                b += out.vz;
                if (q->next == 0)
                    break;
                q = q->next;
                q->a.raw = a;
                q->y.raw = y;
                q->b.raw = b;
            }
        }
        func_80022E44(o);
        break;
    case 2:
        o->b04++;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011E520);
extern s32 D_1F800334;
extern u8 D_8009C114;
extern void pushDrawListLayer4(void);
extern void freeObjectLayer4(void);

void func_8011E520(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->active = 2;
        if (D_8009C114 == 0xff) {
            s32 *pp = &D_1F800334;
            pp = (s32 *)(*pp + ((s32 *)*(s32 *volatile *)pp)[12]);
            o->unkA0 = (s32)pp;
        }
        break;
    case 1:
        o->visible = 1;
        pushDrawListLayer4();
        break;
    case 2:
    case 3:
        freeObjectLayer4();
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011E5D8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011E850);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011E8D0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011E958);
extern void func_80022C08(GameObject *, s32);
extern u8 D_800A53A7[];
extern s16 *D_800A53DC_S16PtrArr[] asm("D_800A53DC");

void func_8011E958(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (o->subtype == 0) {
            o->hitOffsetX = 0x58;
            o->hitWidth = 0x60;
            o->hitOffsetY = 4;
            o->hitHeight = 8;
            o->unkA = 0x11;
            o->unkF = D_800A53A7[0] + 1;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            o->d->p.whole = D_800A53DC_S16PtrArr[0][1];
            o->state++;
        }
        break;
    case 1:
        func_80022C08(o, 0x5a);
        switch (o->subState) {
        case 0:
            if (D_800A539D == 5) {
                o->timer = 0x80;
                o->subState++;
            }
            break;
        case 1:
            o->unk8C += 0x20;
            o->y.p.whole += 2;
            if (--o->timer == 0) {
                o->state = 2;
                o->subState = 0;
            }
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        ((void (*)(GameObject *))freeObjectLayer4)(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_2", func_8011EAEC);
extern void *D_8013A494;
extern void *D_8013A498;
extern u8 D_800A5403;
extern s32 fixedMulSin(s32, s32);

void func_8011EAEC(GameObject *o)
{
    s32 t;
    GameObject *p;
    switch (o->step) {
    case 0:
        o->touchFlag = 0;
        o->anim = D_8013A494;
        readAnimFrameCount(o);
        p = (GameObject *)o->unk90;
        o->unk88 = 0x100;
        o->velX = o->y.p.whole;
        o->velY = o->y.p.whole;
        p->h->p.whole = o->h->p.whole - 6;
        o->step++;
    case 1:
        o->unk88 += 4;
        o->y.p.whole = o->velX + fixedMulSin((u8)o->unk88, 4);
        tickAnimation((GameObject *)o->unk90);
        tickAnimation(o);
        if ((*(u16 *)&D_800A539C) == 5 && D_800A5401 && D_800A5403) {
            o->step = 2;
            o->timer = 0x28;
        }
        break;
    case 2:
        o->unk88 += 4;
        o->y.p.whole = o->velX + fixedMulSin((u8)o->unk88, 4);
        tickAnimation(o);
        tickAnimation((GameObject *)o->unk90);
        if (o->touchFlag) {
            p = (GameObject *)o->unk90;
            p->anim = D_8013A498;
            readAnimFrameCount(p);
            D_800A5403 = 0;
            o->subState = 1;
            o->step = 0;
        }
        break;
    case 3:
        tickAnimation(o);
        o->unk88 += 4;
        if (o->unk88 > 0x200)
            o->unk88 = 0x200;
        t = fixedMulSin((u8)o->unk88, 4);
        if ((s16)t < 0)
            t = -t;
        o->y.p.whole = o->velX + t;
        o->velX++;
        if (o->velX < o->velY) {
            o->velX = o->velY;
            o->step = 2;
            o->velY = o->y.p.whole + 0x10;
        }
        break;
    }
}
