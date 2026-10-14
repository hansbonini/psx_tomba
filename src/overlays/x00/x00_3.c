#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_3", func_8011ED30);
typedef struct { u8 p0[9]; u8 b9; } P8011F9E0_1ED30;

extern P8011F9E0_1ED30 *D_8009B698;
extern Fix16 *D_800A53D8_Fix16PtrArr[] asm("D_800A53D8");
#define D_800A6078 D_800A53D8_Fix16PtrArr[0]
extern void *D_8013A49C;
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");
extern u8 D_800A539E_U8Arr[] asm("D_800A539E");
#define D_800A603C D_800A539C_U8Arr[0]
#define D_800A603D D_800A539D_U8Arr[0]
#define D_800A603E D_800A539E_U8Arr[0]
extern u8 D_800A5401[];
#define D_800A60A1 D_800A5401[0]
extern s16 D_800A5414;
extern s16 D_800A5418;
extern s16 D_800A541A;
extern u8 D_8009C227;
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s16 fixedMulSin(s32, s32);
extern void setEventStarted(s32, s32, s32);

#define BOB() \
    o->unk88 += 4; \
    o->y.p.whole = o->velX + fixedMulSin(o->unk88 & 0xff, 4);

void func_8011ED30(GameObject *o)
{
    extern void *D_8013A498;
    extern void *D_8013A494;
    GameObject *p;
    u8 *k;

    switch (o->step) {
    case 0:
        o->unk88 = 0;
        o->anim = D_8013A494;
        o->velH = o->h->p.whole - D_800A6078->p.whole;
        o->velV = 0;
        readAnimFrameCount(o);
        o->step++;
    case 1:
        o->h->p.whole++;
        D_800A6078->p.whole = o->h->p.whole;
        p = (GameObject *)o->unk90;
        p->h->p.whole = D_800A6078->p.whole - 6;
        BOB();
        tickAnimation(o);
        tickAnimation(p);
        if (o->h->p.whole >= 0x237) {
            k = &D_800A603D;
            if (*k != 4) {
                p = (GameObject *)o->unk90;
                p->anim = D_8013A498;
                readAnimFrameCount(p);
                o->h->p.whole = 0x236;
                p->h->p.whole = o->h->p.whole - 5;
                o->touchFlag = 0;
                o->timer = 0x20;
                o->step++;
                D_800A53C6 = 0;
                D_8009B698->b9 = 0x14;
                D_800A5434 = 1;
                D_800A5414 = 0x130;
                D_800A603C = 6;
                D_800A60A1 = 0;
                D_800A544A = 0;
                D_800A5418 = 0;
                D_800A541A = 0;
                D_800A5416 = 0;
                *k = 4;
                D_800A603E = 0;
            }
        }
        break;
    case 2:
        p = (GameObject *)o->unk90;
        tickAnimation(o);
        tickAnimation(p);
        BOB();
        if (D_800A60A1) {
            D_800A603C = 5;
            D_800A603D = 0;
            D_800A603E = 0;
            o->timer = 0x3c;
            o->step = 3;
            o->velX = o->y.p.whole;
        }
        break;
    case 3:
        p = (GameObject *)o->unk90;
        tickAnimation(o);
        tickAnimation(p);
        BOB();
        o->velX++;
        if (--o->timer > 0) {
            if (o->timer == 0x14) {
                p = (GameObject *)o->unk90;
                p->anim = D_8013A49C;
                readAnimFrameCount(p);
            }
        } else {
            p = (GameObject *)o->unk90;
            p->unkF = 0x1e;
            o->step++;
        }
    case 4:
        p = (GameObject *)o->unk90;
        tickAnimation(o);
        tickAnimation(p);
        BOB();
        if (D_800A603D == 3) {
            o->timer = 0x3c;
            o->step++;
        }
        break;
    case 5:
        if (--o->timer == 0) {
            p = (GameObject *)o->unk90;
            p->y.p.whole += 4;
            o->timer = 0x3a;
            o->step++;
        }
        break;
    case 6:
        tickAnimation((GameObject *)o->unk90);
        tickAnimation(o);
        BOB();
        o->velX--;
        if (--o->timer > 0) {
            if (o->timer == 0x28) {
                setEventStarted(8, 0, 0);
                D_800A603C = 5;
                D_800A603D = 0;
                D_800A603E = 0;
            }
            if (o->timer == 0x14) {
                p = (GameObject *)o->unk90;
                p->anim = D_8013A498;
                readAnimFrameCount(p);
                *(s8 *)&p->unkF = -10;
            }
        } else {
            D_800A547C->state = 3;
            o->step++;
        }
        break;
    case 7:
        tickAnimation((GameObject *)o->unk90);
        tickAnimation(o);
        BOB();
        if (D_8009C227 == 3) {
            o->timer = 0x3c;
            o->step++;
        }
        break;
    case 8:
        tickAnimation((GameObject *)o->unk90);
        tickAnimation(o);
        BOB();
        if (--o->timer == 0) {
            *(volatile u16 *)&D_800A53C6 ^= 1;
            p = (GameObject *)o->unk90;
            p->animFrame ^= 1;
            o->step++;
        }
        break;
    case 9:
        tickAnimation((GameObject *)o->unk90);
        tickAnimation(o);
        o->h->p.whole--;
        D_800A6078->p.whole = o->h->p.whole;
        p = (GameObject *)o->unk90;
        p->h->p.whole = D_800A6078->p.whole + 6;
        BOB();
        if (o->h->p.whole < 0x129) {
            D_800A53C6 = 1;
            D_8009B698->b9 = 0xe;
            D_800A5434 = 1;
            D_800A5414 = -0x100;
            D_800A603C = 6;
            D_800A60A1 = 0;
            D_800A5416 = 0;
            D_800A603D = 4;
            D_800A603E = 0;
            o->timer = 0x40;
            o->step++;
        }
        break;
    case 10:
        p = (GameObject *)o->unk90;
        tickAnimation(o);
        tickAnimation(p);
        BOB();
        o->velX++;
        if (--o->timer > 0) {
            if (o->timer == 0x14) {
                p = (GameObject *)o->unk90;
                p->anim = D_8013A49C;
                readAnimFrameCount(p);
            }
        } else {
            p = (GameObject *)o->unk90;
            p->state = 2;
            o->state = 2;
            D_800A603C = 1;
            D_800A603D = 0;
            D_800A603E = 0;
            D_8009BCA7 = 0;
        }
        break;
    }
}
#undef D_800A6078
#undef D_800A603C
#undef D_800A603D
#undef D_800A603E
#undef D_800A60A1
#undef BOB

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_3", func_8011F4B4);
extern void func_8011EAEC(u8 *);
extern s16 fixedMulSin(s32, s32);
extern u8 *D_8013A494;

void func_8011F4B4(u8 *o)
{
    u32 v;
    switch (o[5]) {
    case 0:
        func_8011EAEC(o);
        break;
    case 1:
        func_8011ED30(o);
        break;
    case 2:
        switch (o[6]) {
        case 0:
            o[0x69] = 0;
            *(u8 **)(o + 0x24) = D_8013A494;
            *(s32 *)(o + 0x88) = 0;
            *(u16 *)(o + 0x7e) = *(u16 *)(o + 0x16);
            readAnimFrameCount(o);
            o[6] = o[6] + 1;
        case 1:
            (*(u16 **)(o + 0x40))[1] -= 1;
            v = *(s32 *)(o + 0x88) + 1;
            *(s32 *)(o + 0x88) = v;
            *(u16 *)(o + 0x16) = *(u16 *)(o + 0x7c) + fixedMulSin(v & 0xff, 4);
            tickAnimation(o);
            if ((*(s16 **)(o + 0x40))[1] < 0x128) {
                (*(s16 **)(o + 0x40))[1] = 0x128;
                o[5] = 0;
                o[6] = 0;
            }
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_3", func_8011F5F4);
typedef struct O_1F5F4 {
    u8 active, vis, type, b3, state, step, b6, b7;
    char p0[2]; u8 b0a; char p1[2]; u8 b0d; char p2; s8 b0f;
    s32 x, y, z; char p3; u8 b1d; u16 w1e; char p4[4]; s32 anim; char p5[6]; u16 w2e;
    char p6[0x3c - 0x30]; s32 d3c; char p7[0x68 - 0x40]; u8 b68, b69; char p8[2];
    u16 w6c, w6e, w70, w72; char p9[0x90 - 0x74]; struct O_1F5F4 *child;
} O_1F5F4;
extern s32 D_1F8002D4;
extern s32 D_8013A498;
extern void freeObjectLayer4(O_1F5F4 *);

void func_8011F5F4(O_1F5F4 *o)
{
    O_1F5F4 *c;
    s32 *g;
    switch (o->state) {
    case 0:
        switch (o->step) {
        case 0:
            g = &D_1F8002D4;
            o->w6c = 20;
            o->w6e = 40;
            o->w70 = 12;
            o->w72 = 24;
            o->d3c = *g;
            o->w1e = 8;
            o->b0d = 0;
            o->b0a = 0;
            o->b69 = 0;
            o->b68 = 0;
            o->b0f = 4;
            c = allocObjectLayer3();
            if (c != 0) {
                c->active = 1;
                c->type = 4;
                c->x = o->x;
                c->y = o->y + 0x100000;
                c->z = o->z;
                c->w1e = o->w1e;
                c->b0f = -10;
                c->b0d = 0;
                c->b0a = 0;
                c->w2e = 1;
                c->d3c = *g;
                c->b1d = o->b1d;
                c->anim = D_8013A498;
                readAnimFrameCount(c);
                o->child = c;
                c->state = 1;
            }
            o->step++;
            break;
        case 1:
            o->state++;
            o->step = 0;
            o->b6 = 0;
            o->b7 = 0;
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->vis != 0) func_8011F4B4(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
