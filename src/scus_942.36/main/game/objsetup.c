#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031908);
extern u16 D_1F80016E[];
extern void pushDrawListCapped(GameObject *o);
extern s16 fixedMulSin2(s16 a, s16 b);
extern void freeObjectLayer3(GameObject *o);

void func_80031908(GameObject *o)
{
    extern void readAnimFrameCount(GameObject *o);
    s16 v;
    switch (o->state) {
    case 0:
        o->state++;
        if (GetGraphType() == 1 || GetGraphType() == 2) v = 0xa5;
        else v = 0x35;
        o->tpage = v;
        *(s8 *)&o->unkF = -9;
        o->unkA = 14;
        o->unkD = 0x81;
        o->clut = GetClut(0x160, o->unkC + 0x1f1);
        o->animFrame = 0;
        o->anim = D_80012680;
        o->spriteBank = D_1F8002D8[0];
        o->unk30 = D_1F80016A[0] << 16;
        o->y.p.whole = D_1F80016E[0];
        o->d->p.whole = D_1F800172[0];
        o->velV = -0xc00;
        o->timer = 1;
        o->unkB4 = 0x80;
        o->unkB6 = 0;
        o->unkB8 = 100;
        readAnimFrameCount(o);
        break;
    case 1:
        o->visible = 1;
        pushDrawListCapped(o);
        if (--o->timer == 0) {
            o->timer = 1;
            if (--*(u16 *)&o->unkB4 == 0) o->state++;
        }
        o->unkB6 = (o->unkB6 + 8) & 0xff;
        o->unkB8 += 2;
        o->h->raw = o->unk30 + (fixedMulSin2(o->unkB6, 0x10) << 16);
        o->y.raw += o->velV << 4;
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031B18);
extern void pushDrawListCapped(GameObject *);
extern void freeObjectLayer3(GameObject *);

void func_80031B18(GameObject *o)
{
    extern void readAnimFrameCount(GameObject *);
    switch (o->state) {
    case 0:
        o->unkA = 7;
        *(s8 *)&o->unkF = -20;
        o->tpage = 0x14;
        o->unkD = 0;
        o->spriteBank = ((struct { char pad[0x2d8]; s32 v; } *)0x1F800000)->v;
        o->anim = ((void **)&D_800122B0)[o->unkC];
        readAnimFrameCount(o);
        o->subState = 0;
        o->timer = o->unkB4;
        o->state++;
        break;
    case 1:
        switch (o->subState) {
        case 0:
            if (--o->timer == 0) {
                o->timer = o->unkB6;
                o->subState++;
            }
            break;
        case 1:
            if (--o->timer == 0) {
                o->state++;
            }
            o->visible = 1;
            pushDrawListCapped(o);
            break;
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031C90);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031F00);
extern GameObject *allocObjectLayer3();

void func_80031F00(s32 a, s32 b, s32 c)
{
    GameObject *o = allocObjectLayer3();
    if (o != 0) {
        o->active = 1;
        o->type = 0x31;
        o->subtype = 0;
        o->unkC = 0;
        o->h->raw = a << 16;
        o->y.raw = b << 16;
        o->d->raw = c << 16;
        o->timer = 0x20;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031F88);
extern s32 tickAnimation(GameObject *o);

void func_80031F88(GameObject *o)
{
    extern void func_80032230(GameObject *o);
    GameObject *n;
    s16 r;
    s16 s;
    s16 b;
    s16 i;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0:
            if ((*(u16 *)0x1F8001F8 + *(s32 *)0x1F800198) & 1) {
                if (--o->timer == -1) {
                    o->state = 3;
                    break;
                }
                n = allocObjectLayer3();
                if (n == 0) break;
                r = ((s32 (*)(void))nextRandom)();
                b = r & 1;
                s = b;
                switch (o->unkC) {
                case 0:
                    s = (b << 11) + 0x800;
                    n->unkAC = 0;
                    n->unkA = 0;
                    break;
                case 1:
                    s = (b * 3 << 10) + 0xc00;
                    n->unkAC = ((s32 (*)(void))nextRandom)() & 1;
                    if (n->unkAC) goto one;
                    n->unkA = 0;
                    break;
                case 2:
                    s = (b << 12) + 0x1000;
                    n->unkAC = 1;
                one:
                    n->unkA = 1;
                    n->buffSize = 0x1800;
                    break;
                }
                n->h->raw = o->h->raw;
                n->y.raw = o->y.raw;
                n->d->raw = o->d->raw;
                i = r & 0xf0;
                n->h->raw += (D_8007DB88[i] * s) >> 4;
                n->y.raw += (D_8007D988[i] * s) >> 4;
                n->state = 1;
                func_80032230(n);
            }
            break;
        case 1:
            o->state = 1;
            func_80032230(o);
            break;
        }
        break;
    case 1:
        func_80022E44(o);
        if (o->unkAC == 1) o->buffSize += 0x200;
        if (tickAnimation(o)) o->state = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032230);
void func_80032230(u8* self)
{
    self[0] = 1;
    self[2] = 0x32;
    *(s16*)(self + 0x2E) = 1;
    *(s8*)(self + 0xF) = -0x1E;
    *(s16*)(self + 0x1E) = 0x14;
    self[0xD] = 0x80;
    self[0xB] = 0;
    *(void**)(self + 0x3C) = (void *)D_1F8002D8[0];
    *(s32*)(self + 0x24) = D_80012368[*(s16*)(self + 0xAC)];
    readAnimFrameCount(self);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800322A4);
typedef struct O_322A4 {
    char act;
    char pad0;
    char type;
    char sub;
    char pad1[0xc - 4];
    u8 b0c;
    char pad2[0x14 - 0xd];
    s32 y;
    char pad3[0x20 - 0x18];
    s16 w20;
    char pad4[0x40 - 0x22];
    s32 *h;
    s32 *d;
} O_322A4;

void func_800322A4(char a, s32 x, s32 y, s32 z)
{
    O_322A4 *p = allocObjectLayer3();
    s16 s;
    if (p == 0) return;
    p->act = 1;
    p->type = 0x32;
    p->sub = 0;
    p->b0c = a;
    *p->h = x << 16;
    p->y = y << 16;
    *p->d = z << 16;
    switch (p->b0c) {
    case 0: s = 0x10; break;
    case 1: s = 0x18; break;
    case 2: s = 0x20; break;
    default: return;
    }
    p->w20 = s;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032374);
typedef struct T_32374 { u16 w; s16 p0; s16 i; s16 p1; s32 *a; } T_32374;
extern T_32374 D_8007D2E8[];

void func_80032374(u8 *o)
{
    if (o[3] != 9) {
        *(u16 *)(o + 0x1e) = D_8007D2E8[o[3]].w;
        *(s32 *)(o + 0x3c) = SPR_DATA[D_8007D2E8[o[3]].i];
        *(s32 *)(o + 0x24) = D_8007D2E8[o[3]].a[o[0xc]];
    } else {
        *(u16 *)(o + 0x1e) = D_8007D2E8[0].w;
        *(s32 *)(o + 0x3c) = SPR_DATA[D_8007D2E8[0].i];
        *(s32 *)(o + 0x24) = *D_8007D2E8[0].a;
    }
    readAnimFrameCount(o);
    o[0xa] = 0xd;
    o[0xd] = 0x80;
    *(s8 *)(o + 0xf) = -7;
    *(s32 *)(o + 0x8c) = 0;
    o[0x6b] = 0;
    o[0x1c] |= 0x80;
    o[4]++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800324B4);
typedef struct { void **a; s32 p[2]; } A12_324B4;
extern A12_324B4 D_8007D2F0[];
extern u8 D_800A5399;
extern u8 D_800A53A7;
extern u8 D_8009BCF8;
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);

void func_800324B4(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->anim = D_8007D2F0[o->subtype].a[o->unkC];
        readAnimFrameCount(o);
        o->visible = D_800A5399;
        o->unkF = D_800A53A7 - 1;
        o->objectIndex = 0x7f;
        if (D_8009BCF8 == 3) {
            o->objectIndex = 0x40;
        }
        o->step++;
        break;
    case 1:
        if (tickAnimation(o)) {
            o->state = 2;
            o->subState = 0;
            o->step = 0;
        }
        if (o->visible == 0) {
            o->state = 2;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800325C0);
extern char D_800A5464;

void func_800325C0(GameObject *o)
{
    u8 b;
    s32 s;
    Fix16 *f;
    s16 t;
    u8 v;
    switch (o->step) {
    case 0:
        o->anim = *(void **)(((char **)&D_8007D2F0)[o->subtype * 3] + o->unkC * 4);
        readAnimFrameCount(o);
        o->timer = 0xb4;
        o->step = o->step + 1;
    case 1:
        break;
    default:
        return;
    }
    if (o->unkC == 0 && (D_1F8001F8 & 3) == 0)
        func_80028A74(0, 0, 0xff, 2);
    tickAnimation(o);
    o->timer = o->timer - 1;
    o->visible = D_800A5399;
    if (o->timer >= 0x3d) {
        if (o->objectIndex < 0x7f)
            b = o->objectIndex + 8;
        else
            b = o->objectIndex;
    } else {
        if (o->timer < 0) {
            if (D_800A5478 > 0)
                PLAYER.obj.active = 3;
            else
                PLAYER.obj.active = 1;
            D_800A5464 = 3;
            o->objectIndex = 0;
            o->state = 2;
            goto L;
        }
        if (o->objectIndex != 0)
            b = o->objectIndex - 2;
        else
            b = 0;
    }
    o->objectIndex = b;
L:
    s = PLAYER.obj.h->p.whole;
    f = o->h;
    if (PLAYER.obj.animFrame & 1)
        f->p.whole = s + 4;
    else
        f->p.whole = s - 4;
    o->y.p.whole = PLAYER.obj.y.p.whole - 8;
    o->d->p.whole = PLAYER.obj.d->p.whole;
    switch (o->unkC) {
    case 0:
        b = D_800A53A7 + 1;
        break;
    case 1:
        b = D_800A53A7 - 1;
        break;
    default:
        return;
    }
    o->unkF = b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800327D8);

void func_800327D8(GameObject *o)
{
    u8 t;
    switch (o->step) {
    case 0:
        o->anim = *(*(void ***)&D_8007D2F0);
        readAnimFrameCount(o);
        o->timer = 0x3c;
        o->step++;
    case 1:
        break;
    default:
        return;
    }
    tickAnimation(o);
    o->timer = o->timer - 1;
    o->visible = D_800A5399;
    if (o->timer > 0x20) {
        if (o->objectIndex > 0x7e) t = o->objectIndex;
        else t = o->objectIndex + 8;
        o->objectIndex = t;
    } else if (o->timer < 0) {
        o->objectIndex = 0;
        o->state = 2;
    } else {
        if (o->objectIndex == 0) t = 0;
        else t = o->objectIndex - 8;
        o->objectIndex = t;
    }
    {
        s32 x = PLAYER.obj.h->p.whole;
        o->h->p.whole = (PLAYER.obj.animFrame & 1) ? x + 4 : x - 4;
    }
    o->y.p.whole = (u16)PLAYER.obj.y.p.whole - 8;
    o->d->p.whole = ((s16 **)&D_800A53DC)[0][1];
    o->unkF = PLAYER.obj.unkF - 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032934);
typedef struct { s16 w0; s16 w2; } P_32934;
typedef struct { void **tab; s32 a; s32 b; } AT_32934;
extern P_32934 *D_800A6078;
extern P_32934 *D_800A607C;
extern s16 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);

void func_80032934(GameObject *o)
{
    u8 v;
    s32 t;
    switch (o->step) {
    case 0:
        switch (o->unkC) {
        case 5:
            o->unk84 = 0;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[5];
            break;
        case 6:
            o->unk84 = 0x56;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[6];
            break;
        case 7:
            o->unk84 = 0xab;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[7];
            break;
        case 8:
            o->unk84 = 0x2c;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[5];
            break;
        case 9:
            o->unk84 = 0x7f;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[6];
            break;
        case 10:
            o->unk84 = 0xd4;
            o->anim = ((AT_32934 *)&D_8007D2F0)[o->subtype].tab[7];
            break;
        }
        readAnimFrameCount(o);
        o->unk88 = 0;
        o->timer = 0xb4;
        o->step++;
    case 1:
        if (o->unkC == 0 && (D_1F8001F8 & 3) == 0)
            func_80028A74(0, 0, 0xff, 2);
        o->timer--;
        o->visible = PLAYER.obj.visible;
        if (o->timer >= 0x3d) {
            if (o->objectIndex < 0x7f)
                v = o->objectIndex + 8;
            else
                v = o->objectIndex;
        } else if (o->timer < 0) {
            if (D_800A5478 > 0) PLAYER.obj.active = 3; else PLAYER.obj.active = 1;
            D_800A5464 = 3;
            o->objectIndex = 0;
            o->state = 2;
            goto anim;
        } else {
            if (o->objectIndex)
                v = o->objectIndex - 2;
            else
                v = 0;
        }
        o->objectIndex = v;
    anim:
        tickAnimation(o);
        switch (o->unkC) {
        case 0:
            o->h->p.whole = PLAYER.obj.h->p.whole;
            o->y.p.whole = PLAYER.obj.y.p.whole - 8;
            o->d->p.whole = PLAYER.obj.d->p.whole;
            break;
        case 5:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 8);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 28) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        case 6:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 16);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 16) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        case 7:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 24);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 8) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        case 8:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 4);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 24) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        case 9:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 20);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 20) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        case 10:
            o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&o->unk84, 28);
            o->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 12) - 8);
            o->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&o->unk84, 4) - 4);
            break;
        }
        o->unk84 = (o->unk84 + 0x10) & 0xff;
        break;
    }
}
