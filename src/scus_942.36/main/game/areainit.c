#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_80032DB4);
typedef struct { void **p; s32 a, b; } E12_32DB4;
extern u16 D_1F8001F8;
extern u8 D_800A5399;
extern u8 D_800A5464[];
extern void readAnimFrameCount(GameObject *);
extern void func_80028A74(s32, s32, s32, s32);
extern s32 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);

void func_80032DB4(GameObject *o)
{
    extern void tickAnimation(GameObject *);
    extern u8 D_800A53A7[];
    extern E12_32DB4 D_8007D2F0[];
    s32 t;
    u32 u, w;
    switch (o->step) {
    case 0:
        o->anim = *D_8007D2F0[o->subtype].p;
        readAnimFrameCount(o);
        o->step++;
        switch (o->unkC) {
        case 0: o->unk84 = 0; break;
        case 1: o->unk84 = 0x56; break;
        case 2: o->unk84 = 0xab; break;
        }
        o->timer = 0x31;
        o->unk88 = 0;
        break;
    case 1:
        if (o->unkC == 0 && !(D_1F8001F8 & 3))
            func_80028A74(0, 0, 0xff, 2);
        tickAnimation(o);
        o->visible = D_800A5399;
        o->h->p.whole = (*(Fix16 **)&D_800A53D8)->p.whole + fixedMulCos((s16)o->unk84, (s16)o->unk88);
        if (o->unkC)
        {
            t = fixedMulSin((s16)o->unk84, 8) + 8;
            o->y.p.whole = D_800A53AE + t;
        }
        else
        {
            t = fixedMulSin((s16)o->unk84, 8) + 0x18;
            o->y.p.whole = D_800A53AE + t;
        }
        o->d->p.whole = (*(Fix16 **)&D_800A53DC)->p.whole + fixedMulSin((s16)o->unk84, (s16)o->unk88);
        o->unk84 = (o->unk84 + 0x10) & 0xff;
        o->unk88 += o->unk88 < 0xc;
        o->unkF = D_800A53A7[0];
        if (((u8 *)&D_800A5401)[0])
            o->timer = 0;
        if (--o->timer <= 0) {
            o->timer = 0;
            D_800A5464[0] = 3;
            o->objectIndex = 0;
            o->state = 2;
        } else {
            u = o->objectIndex;
            if (u >= 0x7f)
                w = u;
            else
                w = u + 8;
            o->objectIndex = w;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_8003301C);
void func_800325C0(u8 *o);
void func_80032934(u8 *o);
void func_800327D8(u8 *o);
void func_8003301C(u8 *o)
{
    switch (o[3]) {
    case 0: func_800325C0(o); break;
    case 1: func_80032934(o); break;
    case 2: func_80032DB4(o); break;
    case 9: func_800327D8(o); break;
    }
    if (o[3] != 9 && (*(u16 *)0x1F8001F8 & 3) == 0) playSFXWithNote(3, 0xc);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_800330EC);
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern s32 *D_8007D2F0[];
extern u8 D_800A5399;
extern u8 D_800A53A7;
extern u8 D_8009BCF8;
extern u16 D_1F8001F8;

void func_800330EC(GameObject *o)
{
    char c;
    func_80022E44(o);
    switch (o->subState) {
    case 0:
        switch (o->subtype) {
        case 0:
            func_800325C0(o);
            break;
        case 1:
            func_80032934(o);
            break;
        case 2:
            func_80032DB4(o);
            break;
        case 9:
            func_800327D8(o);
            break;
        }
        if (o->subtype != 9 && (D_1F8001F8 & 3) == 0)
            playSFXWithNote(3, 12);
        break;
    case 1:
        switch (o->step) {
        case 0:
            o->anim = (void *)D_8007D2F0[o->subtype * 3][o->unkC];
            readAnimFrameCount(o);
            o->visible = D_800A5399;
            c = D_800A53A7;
            o->objectIndex = 0x7f;
            o->unkF = c - 1;
            if (D_8009BCF8 == 3)
                o->objectIndex = 0x40;
            o->step = o->step + 1;
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
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_800332CC);
extern void func_80032374(GameObject *);
extern void freeObjectLayer3(GameObject *);
void func_800332CC(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_80032374(o);
        break;
    case 1:
        if ((*(u8 *)&PLAYER) != 5)
            func_800330EC(o);
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_80033374);
extern s32 D_800A53AC;
extern s32 D_800A53B0;

void func_80033374(char a, char b, char c)
{
    extern s32 D_800A53A8;
    s32 t;
    char *p = allocObjectLayer3();
    if (p != 0) {
        p[0] = 1;
        p[2] = 0x4e;
        p[3] = a;
        p[0xc] = b;
        *(s32 *)(p + 0x10) = D_800A53A8;
        *(s32 *)(p + 0x14) = D_800A53AC;
        t = D_800A53B0;
        p[5] = c;
        *(s32 *)(p + 0x18) = t;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_80033404);
extern GameObject *allocObjectLayer3();
extern s32 D_800A53A8[];

void func_80033404(s32 a, s32 b)
{
    GameObject *o = allocObjectLayer3();
    if (o) {
        o->active = 1;
        o->type = 0x4e;
        o->subtype = a;
        o->unkC = b;
        o->x.raw = D_800A53A8[0];
        o->y.raw = D_800A53A8[1];
        o->z.raw = D_800A53A8[2];
        o->subState = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", func_80033488);
typedef struct { s32 a, y, b; } P3_33488;
extern void func_80110DA0(s32 a, s32 b, s32 c);

static __inline__ void spawn_33488(s16 sub, s32 idx)
{
    GameObject *o = allocObjectLayer3();
    if (o != 0) {
        o->active = 1;
        o->type = 0x4e;
        o->subtype = sub;
        o->unkC = idx;
        o->x.raw = (*(P3_33488 *)&D_800A53A8).a;
        o->y.raw = (*(P3_33488 *)&D_800A53A8).y;
        o->z.raw = (*(P3_33488 *)&D_800A53A8).b;
        o->subState = 0;
    }
}

void func_80033488(s16 n)
{
    if (n != 2) (*(u8 *)&PLAYER) = 7;
    (*(u8 *)&D_800A5464) = 2;
    switch (n) {
    case 0:
        func_80110DA0(0, 0, 0);
        spawn_33488(n, 1);
        break;
    case 1:
        func_80110DA0(1, 0, 0);
        spawn_33488(n, 5);
        spawn_33488(n, 6);
        spawn_33488(n, 7);
        spawn_33488(n, 8);
        spawn_33488(n, 9);
        spawn_33488(n, 10);
        break;
    case 2:
        spawn_33488(n, 0);
        spawn_33488(n, 1);
        spawn_33488(n, 2);
        break;
    }
}

void func_80033858(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", dispatchAreaInitA);
void dispatchAreaInitA(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            func_8011BB54();
    } else if (GAME.selectedArea == AREA03_PHOENIXMOUNTAIN) {
            func_80119894();
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/areainit", dispatchAreaInitB);
void dispatchAreaInitB(void)
{
    switch (GAME.selectedArea) {
        case AREA00_VILLAGEOFALLBEGINNINGS:
            func_8011D65C();
            return;
        case AREA01_DWARFFOREST:
        case AREA07_DWARFFORESTPURIFIED:
            func_8011B0D4();
            return;
        case AREA02_DWARFVILLAGE:
            func_800E80F0();
            return;
        case AREA03_PHOENIXMOUNTAIN:
            func_80119BC4();
            return;
        case AREA04_HAUNTEDMANSION:
        case AREA12_HAUNTEDMANSIONPURIFIED:
            func_8011AB14();
            return;
        case AREA09_MUSHROOMVILLAGE:
            func_80119E94();
            return;
        case AREA10_DEEPJUNGLE:
            func_801178A8();
            return;
        case AREA18_VILLAGEOFCIVILIZATIONYCROSSING:
            func_80115D20();
        default:
            return;
    }
}
