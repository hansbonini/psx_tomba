#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80135728);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80135A94);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80135DD0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80135DDC);
extern GameObject *allocObjectLayer2(void);
extern u8 D_8009C111;
extern u32 D_8009BCEC[];

void func_80135DDC(GameObject *o)
{
    GameObject **p = (GameObject **)&o->category;
    GameObject *n;
    u32 f;
    switch (D_8009C111) {
    case 0:
        n = allocObjectLayer2();
        if (n != 0) {
            n->active = 1;
            n->type = 0x14;
            n->x.p.whole = 0xa38;
            n->y.p.whole = -0x124;
            n->animFrame = 0;
            n->subtype = 0;
            n->z.p.whole = -0x28;
            *(GameObject **)&o->timer = n;
        }
        o->state = 1;
        break;
    case 0xff:
        o->state = 3;
        break;
    default:
        n = allocObjectLayer2();
        if (n != 0) {
            n->active = 1;
            n->type = 0x14;
            n->x.p.whole = 0xa38;
            n->y.p.whole = -0x124;
            n->animFrame = 0;
            n->subtype = 0;
            n->z.p.whole = -0x28;
            f = D_8009BCEC[0];
            if (f & 8) if (f & 0x10) {
                n->x.p.whole = 0xc29;
                n->y.p.whole = -0x2e3;
                n->active = 1;
                n->type = 0x14;
                n->animFrame = 0;
                n->subtype = 1;
                n->z.p.whole = 0x5a;
            }
            p[1] = n;
        }
        o->state = 1;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80135F04);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80136024);
extern GameObject PLAYER_GameObject asm("PLAYER");
extern GameObject *D_800A5428;
extern u8 D_800A5458;
extern u8 D_8009C226_U8 asm("D_8009C226");
extern u8 D_8009C226[];
extern s32 D_8009BCEC_S32 asm("D_8009BCEC");
extern char D_800108A8[];
extern void readAnimFrameCount(GameObject *);
extern GameObject *showMessageBox(s32, s32, s32, s32);
extern void setEventStarted(s32, s32, s32);
extern void setEventComplete(s32, s32);

void func_80136024(GameObject *o)
{
    GameObject *t = *(GameObject **)&o->timer;

    switch (o->subState) {
    case 0:
        o->clut = 0x14;
        PLAYER_GameObject.animFrame = 0;
        PLAYER_GameObject.state = 1;
        D_8009BCA7 = 1;
        D_8009BCA6 = 1;
        D_8009BCAA = 1;
        PLAYER_GameObject.subState = 0;
        PLAYER_GameObject.step = 0;
        (*(u8 *)&D_8009C618) = 0;
        PLAYER_GameObject.anim = D_800108A8;
        readAnimFrameCount(&PLAYER_GameObject);
        o->subState++;
        break;
    case 1:
        if (--o->clut != 0)
            break;
        D_8009C226[0] = 0;
        if (D_8009BCEC_S32 & 0x80)
            { if (D_8009BCEC_S32 & 8) { if (D_8009BCEC_S32 & 0x10) D_8009C226[0] = 6; else D_8009C226[0] = 4; } else D_8009C226[0] = 5; }
        D_800A5428 = showMessageBox(6, D_8009C226_U8, 0xe0, 0x6c);
        D_8009BCEC_S32 |= 0x80;
        o->subState++;
        break;
    case 2:
        if (D_800A5428->state != 2)
            break;
        *(s16 *)&o->category = 0;
        switch (D_8009C226_U8) {
        case 0:
            D_800A5428->state = 3;
            D_8009C226_U8 = 1;
            o->clut = 1;
            o->subState = 4;
            *(s16 *)&o->category = 1;
            break;
        case 1:
            D_800A5428->state = 3;
            D_8009C226_U8 = 2;
            setEventStarted(5, 0, 0);
            *(s16 *)&o->category = 1;
            o->clut = 0x168;
            o->subState = 4;
            break;
        case 2:
            D_800A5428->state = 3;
            if (D_8009BCEC_S32 & 0x18) {
                D_8009C226_U8 = 3;
                D_800A5428 = showMessageBox(6, 3, 0xe0, 0x6c);
                o->subState = 2;
                *(s16 *)&o->category = 1;
            } else {
                o->clut = 4;
                o->subState = 3;
                *(s16 *)&o->category = 1;
            }
            break;
        case 3:
            D_800A5428->state = 3;
            { if (D_8009BCEC_S32 & 8) { if (D_8009BCEC_S32 & 0x10) D_8009C226_U8 = 7; else D_8009C226_U8 = 4; } else D_8009C226_U8 = 5; }
            D_800A5428 = showMessageBox(6, D_8009C226_U8, 0xe0, 0x6c);
            *(s16 *)&o->category = 1;
            o->subState = 2;
            break;
        case 4:
            D_800A5428->state = 3;
            if (D_8009BCEC_S32 & 0x10) {
                D_8009C226_U8 = 3;
                D_800A5428 = showMessageBox(6, 3, 0xe0, 0x6c);
                o->subState = 2;
                *(s16 *)&o->category = 1;
            } else {
                PLAYER_GameObject.state = 1;
                PLAYER_GameObject.subState = 0;
                PLAYER_GameObject.step = 0;
                D_800A5458 = 0;
                o->state = 0;
                o->subState = 0;
                o->step = 0;
                D_8009BCA6 = 0;
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                *(s16 *)&o->category = 0;
            }
            break;
        case 5:
            D_800A5428->state = 3;
            if (D_8009BCEC_S32 & 8) {
                D_8009C226_U8 = 3;
                D_800A5428 = showMessageBox(6, 3, 0xe0, 0x6c);
                o->subState = 2;
                *(s16 *)&o->category = 1;
            } else {
                PLAYER_GameObject.state = 1;
                PLAYER_GameObject.subState = 0;
                PLAYER_GameObject.step = 0;
                D_800A5458 = 0;
                o->state = 1;
                o->subState = 0;
                o->step = 0;
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                D_8009BCA6 = 0;
                *(s16 *)&o->category = 0;
            }
            break;
        case 6:
            D_800A5428->state = 3;
            D_8009C226_U8 = 7;
            D_800A5428 = showMessageBox(6, 7, 0xe0, 0x6c);
            *(s16 *)&o->category = 1;
            o->subState = 2;
            break;
        case 7:
            D_800A5428->state = 3;
            setEventComplete(5, 0);
            D_8009C226_U8 = 8;
            o->clut = 0x168;
            o->subState = 5;
            *(s16 *)&o->category = 1;
            break;
        case 8:
            D_800A5428->state = 3;
            D_8009C226_U8 = 9;
            D_800A5428 = showMessageBox(6, 9, 0xe0, 0x6c);
            *(s16 *)&o->category = 1;
            o->subState = 2;
            break;
        case 9:
            D_800A5428->state = 3;
            D_8009C226_U8 = 0xb;
            PLAYER_GameObject.state = 1;
            PLAYER_GameObject.subState = 0;
            PLAYER_GameObject.step = 0;
            t->state = 2;
            t->subState = 2;
            t->step = 0;
            o->state = 2;
            o->subState = 0;
            o->step = 0;
            D_8009BCA6 = 0;
            D_8009BCA7 = 0;
            D_8009BCAA = 0;
            *(s16 *)&o->category = 0;
            D_800A5458 = 0;
            break;
        }
        break;
    case 3:
        if (--o->clut != 0)
            break;
        PLAYER_GameObject.timer = 0x50;
        PLAYER_GameObject.active = 3;
        PLAYER_GameObject.state = 5;
        PLAYER_GameObject.animFrame = 0;
        D_800A53C6 = 0;
        PLAYER_GameObject.subState = 1;
        PLAYER_GameObject.step = 0;
        PLAYER_GameObject.unk7 = 0;
        o->state = 0;
        o->subState = 0;
        *(s16 *)&o->category = 0;
        D_800A5458 = 0;
        D_8009BCA6 = 0;
        D_8009BCA7 = 0;
        D_8009BCAA = 0;
        D_8009BCEC[0] |= 0x80;
        break;
    case 4:
        if (--o->clut != 0)
            break;
        D_800A5428 = showMessageBox(6, D_8009C226_U8, 0xe0, 0x6c);
        o->subState = 2;
        *(s16 *)&o->category = 1;
        break;
    case 5:
        if (--o->clut != 0)
            break;
        setEventStarted(7, 0, 0);
        o->clut = 300;
        o->subState = 4;
        *(s16 *)&o->category = 1;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_801366B0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_801366BC);
typedef struct N_366BC { char p0; char f1; char f2; char f3; char p1[0xe]; s16 x; char p2[2]; s16 y; char p3[2]; s16 z; char p4[0x2e - 0x1c]; s16 w; } N_366BC;
typedef struct O_366BC { char p0[4]; u8 state; char p1[0x1c-5]; N_366BC *n; } O_366BC;
extern u8 D_8009C1B2;
extern u8 D_8009C225;
extern u8 D_8009C376;

void func_801366BC(O_366BC *o)
{
    N_366BC **pp = &o->n;
    N_366BC *n;
    u8 st;
    if (D_8009C1B2 == 0xff)
        o->state = 3;
    if (D_8009C225 >= 6) st = 3; else {
        n = allocObjectLayer2();
        if (n) {
            n->p0 = 1;
            n->f2 = 0x15;
            if (D_8009C376 == 0) {
                n->w = 1;
                n->x = 0x140;
                n->y = -0x32;
                n->z = 0;
                n->f3 = 99;
            } else {
                n->x = 0x138;
                n->w = 0;
                n->y = -0x11c;
                n->z = 0;
                n->f3 = 0;
            }
            *pp = n;
        }
        st = 1;
    }
    o->state = st;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_8013679C);
extern u8 D_800A5401;
extern u8 D_8009BCA9;
extern u8 D_800A5458;
extern u8 D_8009C40F;
extern u8 D_800A5444;
extern u8 D_8009C375;
extern u8 D_8009C363;

s16 func_8013679C(GameObject *o)
{
    s16 n = 0;
    u8 **p = (u8 **)((char *)o + 0x1c);

    if (D_8009BCCA == 0) {
        if (D_8009C1B2 != 0xff) {
            if ((*(s16 *)&D_800A53AE) < -0x122 && D_800A5401 != 0 && (u16)(D_800A53D8[1] - 0x148) < 0x10 &&
                (*(s8 *)&D_8009C618) == 1 && (D_1F8001FC & (*(u16 *)&D_1F8003C4)) != 0 && D_8009BCA8 == 0) {
                D_800A5458 = 1;
                ((u8 *)&D_8009BCAA)[0] = 0;
                *(s16 *)&o->anim = 1;
                n = 1;
            }
            if (D_8009C40F != 0) {
                if (D_8009C225 == 0) {
                    if ((*(s16 *)&D_800A53AE) < -0x110) {
                        if (D_800A5444 == 3)
                            goto l6ac;
                        if (D_8009BCA8 == 0)
                            return n;
                        if (D_8009BCA9 == 3) {
                            ((u8 *)&D_8009BCAA)[0] = 1;
                            n++;
                            D_800A5458 = 1;
                            *(s16 *)&o->anim = 0;
                        }
                    }
                } else {
                    if ((*(s16 *)&D_800A53AE) < -0x110 && D_800A53D8[1] < 0x17c && D_800A5401 != 0) {
                        ((u8 *)&D_8009BCAA)[0] = 0;
                        D_800A5458 = 0;
                        *(s16 *)&o->anim = 0;
                        n++;
                        if (D_8009BCA8 != 0 && D_8009BCA9 == 3) {
                            ((u8 *)&D_8009BCAA)[0] = 1;
                            D_800A5458 = 1;
                            *(s16 *)&o->anim = 0;
                        }
                    }
                }
            } else {
                if (D_8009C225 == 0) {
                    if ((*(s16 *)&D_800A53AE) < -0x110 && D_800A5444 == 3) {
                    l6ac:
                        if ((*(u8 **)&D_800A547C)[2] == 0x15) {
                            n++;
                            ((u8 *)&D_8009BCAA)[0] = 0;
                            D_800A5458 = 0;
                            *p = (*(u8 **)&D_800A547C);
                            *(s16 *)&o->anim = 0;
                        }
                    }
                } else {
                    if ((*(s16 *)&D_800A53AE) < -0x110 && D_800A53D8[1] < 0x17c && D_800A5401 != 0) {
                        n++;
                        ((u8 *)&D_8009BCAA)[0] = 0;
                        D_800A5458 = 0;
                        *(s16 *)&o->anim = 0;
                    }
                }
            }
        } else {
            if (D_8009C375 != 0)
                n = 1;
            if (((*(s32 *)&D_8009BCEC) & 0x40) == 0 || D_8009C363 != 0)
                n++;
            if (n == 0)
                o->state = 2;
        }
    }
    return n;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80136AFC);
typedef struct { GameObject o; u8 bc0; } BigObj_36AFC;
extern BigObj_36AFC PLAYER_BigObj_36AFC asm("PLAYER");
#define X PLAYER_BigObj_36AFC.o
extern u8 D_8009C375_U8Arr[] asm("D_8009C375");
extern u8 *D_8009B698;
extern void *D_80139F5C;
extern void *D_80139F60;
extern void *D_80139F68;
extern void *D_80139F6C;
extern void *D_80139F74;
extern char D_80138A0E[];
extern char D_800108A8[];
extern s32 tickAnimation(GameObject *);
extern void applyItemEffect(void *, void *, s32, s32, s32);
extern void removeItemFromInventory(s32, s32);
extern void printInfoMessage(s32, s32);
extern void playSFX(s32);

#define CEBD (*(volatile u8 *)&D_8009C225)

static __inline__ s16 chk_36AFC(void)
{
    s16 r = 0;
    if (D_8009C40F != 0 && D_8009BCA8 != 0)
        r = D_8009BCA9 == 3;
    return r;
}
static __inline__ s32 chk2_36AFC(void)
{
    s32 r = 0;
    if (D_8009C40F != 0) {
        r = 0;
        if (D_8009BCA8 != 0)
            r = D_8009BCA9 == 3;
    }
    return r;
}

void func_80136AFC(GameObject *o)
{
    GameObject *p = *(GameObject **)&o->category;
    s16 buf[6];
    s32 f;

    switch (o->subState) {
    case 0:
        D_8009BCA7 = 1;
        if (*(u16 *)&o->anim != 0) {
            PLAYER_BigObj_36AFC.bc0 = 1;
            D_8009C225 = 1;
            o->subState = 3;
            break;
        }
        if (chk_36AFC()) {
            X.animFrame = 1;
            D_8009C225 = 2;
            D_8009BCA6 = 1;
            X.state = 1;
            X.subState = 0;
            X.step = 0;
            (*(u8 *)&D_8009C618) = 0;
            X.unk90 = showMessageBox(4, 2, 0x80, 0x6c);
            p->anim = D_80139F68;
            readAnimFrameCount(p);
            p->state = 2;
            p->subState = 4;
            p->step = 0;
        } else {
            D_8009C225 = 0;
            X.unk90 = showMessageBox(4, 0, 0x80, 0x6c);
        }
        o->subState++;
        break;
    case 1:
        tickAnimation(p);
        if (((GameObject *)X.unk90)->state != 2)
            break;
        switch (D_8009C225) {
        case 0:
            ((GameObject *)X.unk90)->state = 3;
            p->state = 2;
            p->subState = 1;
            p->step = 0;
            X.animFrame = 1;
            X.state = 6;
            X.subState = 5;
            X.step = 0;
            D_8009B698[9] = 10;
            X.unkB2 = 0;
            X.velH = 0;
            X.velV = 0;
            X.velX = 0xc0;
            X.touchFlag = 0;
            D_8009C225 = 1;
            o->subState = 3;
            break;
        case 1:
            ((GameObject *)X.unk90)->state = 3;
            p->anim = D_80139F60;
            readAnimFrameCount(p);
            p->active = 1;
            p->state = 1;
            p->subState = 0;
            p->step = 0;
            if (D_8009C1B2 == 0) {
                setEventStarted(0xa6, 0, 0);
                o->clut = 300;
                o->subState = 6;
                o->step = 0;
                o->unk7 = 0;
                break;
            }
            D_8009C225 = 0;
            X.animFrame = 1;
            X.state = 1;
            X.subState = 0;
            X.step = 0;
            X.velX = 0;
            X.velY = 0;
            X.touchFlag = 1;
            D_8009B698[9] = 0;
            o->subState = 0;
            o->step = 0;
            goto clear;
        case 2:
            ((GameObject *)X.unk90)->state = 3;
            buf[1] = p->h->p.whole + 0x10;
            buf[3] = p->y.p.whole;
            buf[5] = p->d->p.whole;
            applyItemEffect(D_80138A0E, buf, 0, 0, 1);
            X.state = 5;
            X.subState = 0;
            X.step = 0;
            p->active = 1;
            D_8009C225 = 3;
            removeItemFromInventory(3, 1);
            o->clut = 0x50;
            o->subState = 4;
            if (D_8009C375_U8Arr[0] != 0)
                o->subState = 7;
            break;
        case 3:
            ((GameObject *)X.unk90)->state = 3;
            CEBD = 4;
            CEBD = D_8009E744 + 4;
            p->anim = D_80139F74;
            readAnimFrameCount(p);
            o->subState = 4;
            break;
        case 4: case 5: case 6: case 7: case 8: case 9:
            ((GameObject *)X.unk90)->state = 3;
            p->anim = D_80139F5C;
            readAnimFrameCount(p);
            CEBD = 10;
            CEBD = D_8009E744 + 10;
            o->subState = 4;
            break;
        case 10: case 11: case 12: case 13: case 14: case 15:
            ((GameObject *)X.unk90)->state = 3;
            setEventComplete(0xa6, 0);
            o->subState = 5;
            if (D_8009C375 == 0)
                printInfoMessage(0xc, 3);
            p->state = 2;
            p->subState = 3;
            p->step = 0;
            o->clut = 0x50;
            break;
        }
        break;
    case 3:
        tickAnimation(p);
        if (X.touchFlag != 0) {
            p->active = 1;
            p->anim = D_80139F6C;
            readAnimFrameCount(p);
            p->state = 2;
            p->subState = 4;
            p->step = 0;
            X.animFrame = 1;
            X.state = 5;
            X.subState = 0;
            X.step = 0;
            X.touchFlag = 4;
            X.anim = D_800108A8;
            readAnimFrameCount(&X);
            D_8009C225 = 1;
            X.unk90 = showMessageBox(4, 1, 0x80, 0x6c);
            o->subState = 1;
        }
        break;
    case 4:
        if (o->clut == 10)
            playSFX(9);
        if (--o->clut > 0)
            break;
        X.unk90 = showMessageBox(4, D_8009C225, 0x80, 0x6c);
        o->subState = 1;
        break;
    case 5:
        if (--o->clut > 0)
            break;
        D_8009C375 = 0;
        X.state = 1;
        X.subState = 0;
        X.step = 0;
        D_8009BCAA = 0;
        PLAYER_BigObj_36AFC.bc0 = 0;
        D_8009BCA6 = 0;
        D_8009BCA7 = 0;
        { u8 *c = &D_8009C225; *c = *c + 1; }
        o->state = 2;
        D_8009BCA8 = 0;
        D_8009BCEC_S32 |= 0x40;
        break;
    case 6:
        if (--o->clut > 0)
            break;
        X.animFrame = 1;
        X.state = 1;
        X.subState = 0;
        X.step = 0;
        X.velX = 0;
        X.velY = 0;
        X.touchFlag = 1;
        o->subState = 0;
        o->step = 0;
        D_8009C225 = 0;
    clear:
        *(s16 *)&o->anim = 0;
        PLAYER_BigObj_36AFC.bc0 = 0;
        D_8009BCA7 = 0;
        D_8009BCAA = 0;
        D_8009BCA6 = 0;
        break;
    case 7:
        if (o->clut == 10)
            playSFX(9);
        if (--o->clut > 0)
            break;
        X.unk90 = showMessageBox(4, 3, 0x80, 0x6c);
        o->subState = 1;
        break;
    }
}
#undef X
#undef CEBD

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_8013728C);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_80137298);
extern void func_80135528(u8 *);

static __inline__ s32 chk_37298(void)
{
    return D_800A53D8[1] > 0xd8;
}

void func_80137298(u8 *o)
{
    extern void freeObjectUnlayered(void);
    switch (o[4]) {
    case 0:
        func_80135528(o);
        break;
    case 1:
        if (chk_37298())
            func_80135728(o);
        break;
    case 2:
        o[4] = 3;
        break;
    case 3:
        freeObjectUnlayered();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_8013734C);
extern void func_80135DDC(GameObject *);
extern s16 func_80135F04(GameObject *);
extern void func_80136024(GameObject *);
extern void freeObjectUnlayered(GameObject *);

void func_8013734C(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80135DDC(o);
        break;
    case 1:
        if (func_80135F04(o) != 0)
            func_80136024(o);
        break;
    case 2:
        o->state = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_801373FC);
void func_801373FC(u8 *o)
{
    u8 *q;
    u8 **p;
    switch (o[4]) {
    case 0:
        p = (u8 **)(o + 0x1c);
        if (D_8009C1B2 == 0xff)
            o[4] = 3;
        if (D_8009C225 < 6) {
            q = allocObjectLayer2();
            if (q != 0) {
                q[0] = 1;
                q[2] = 0x15;
                if (D_8009C376 == 0) {
                    *(s16 *)(q + 0x2e) = 1;
                    *(s16 *)(q + 0x12) = 0x140;
                    *(s16 *)(q + 0x16) = -0x32;
                    *(s16 *)(q + 0x1a) = 0;
                    q[3] = 0x63;
                } else {
                    *(s16 *)(q + 0x12) = 0x138;
                    *(s16 *)(q + 0x2e) = 0;
                    *(s16 *)(q + 0x16) = -0x11c;
                    *(s16 *)(q + 0x1a) = 0;
                    q[3] = 0;
                }
                *p = q;
            }
            o[4] = 1;
        } else
            o[4] = 3;
        break;
    case 1:
        if (func_8013679C(o) != 0)
            func_80136AFC(o);
        break;
    case 2:
        o[4] = 3;
        break;
    case 3:
        freeObjectUnlayered(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_8013755C);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_10", func_801376D4);
