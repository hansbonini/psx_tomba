#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80032DB4);
typedef struct { void **p; s32 a, b; } E12_32DB4;
extern s32 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);

void func_80032DB4(GameObject *obj)
{
    extern E12_32DB4 D_8007D2F0[];
    s32 t;
    u32 u, w;
    switch (obj->step) {
    case 0:
        obj->anim = *D_8007D2F0[obj->id].p;
        readAnimFrameCount(obj);
        obj->step++;
        switch (obj->param) {
        case 0: obj->rotX = 0; break;
        case 1: obj->rotX = 0x56; break;
        case 2: obj->rotX = 0xab; break;
        }
        obj->timer = 0x31;
        obj->rotY = 0;
        break;
    case 1:
#if REGION != REGION_JP
        if (obj->param == 0 && !(SCRATCHPAD.activeFrameCount & 3))
            func_80028A74(0, 0, 0xff, 2);
#endif
        tickAnimation(obj);
        obj->visible = D_800A5399;
        obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos((s16)obj->rotX, (s16)obj->rotY);
        if (obj->param)
        {
            t = fixedMulSin((s16)obj->rotX, 8) + 8;
            obj->y.p.whole = PLAYER.obj.y.p.whole + t;
        }
        else
        {
            t = fixedMulSin((s16)obj->rotX, 8) + 0x18;
            obj->y.p.whole = PLAYER.obj.y.p.whole + t;
        }
        obj->d->p.whole = PLAYER.obj.d->p.whole + fixedMulSin((s16)obj->rotX, (s16)obj->rotY);
        obj->rotX = (obj->rotX + 0x10) & 0xff;
        obj->rotY += obj->rotY < 0xc;
        obj->priority = D_800A53A7[0];
        if (((u8 *)&PLAYER.obj.touchFlag)[0])
            obj->timer = 0;
        if (--obj->timer <= 0) {
#if REGION == REGION_JP
            if (D_800A5468 > 0)
                PLAYER.obj.active = 3;
            else
                PLAYER.obj.active = 1;
            D_800A5464[0] = 3;
            obj->timer = 0;
            obj->objectIndex = obj->objectIndex == 0 ? 0 : obj->objectIndex - 2;
            if (obj->objectIndex == 0)
                obj->state = 2;
#else
            obj->timer = 0;
            D_800A5464[0] = 3;
            obj->objectIndex = 0;
            obj->state = 2;
#endif
        } else {
            u = obj->objectIndex;
            if (u >= 0x7f)
                w = u;
            else
                w = u + 8;
            obj->objectIndex = w;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_8003301C);
void func_8003301C(u8 *o)
{
    switch (o[3]) {
    case 0: func_800325C0(o); break;
    case 1: func_80032934(o); break;
    case 2: func_80032DB4(o); break;
#if REGION != REGION_JP
    case 9: func_800327D8(o); break;
#endif
    }
#if REGION == REGION_JP
    if ((SPAD->activeFrameCount & 3) == 0) playSFXWithNote(3, 0xc);
#else
    if (o[3] != 9 && (SPAD->activeFrameCount & 3) == 0) playSFXWithNote(3, 0xc);
#endif
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_800330EC);
extern s32 *D_8007D2F0[];

void func_800330EC(GameObject *obj)
{
    char c;
    cullAndQueueDraw(obj);
    switch (obj->subState) {
    case 0:
        switch (obj->id) {
        case 0:
            func_800325C0(obj);
            break;
        case 1:
            func_80032934(obj);
            break;
        case 2:
            func_80032DB4(obj);
            break;
#if REGION != REGION_JP
        case 9:
            func_800327D8(obj);
            break;
#endif
        }
#if REGION == REGION_JP
        if ((SCRATCHPAD.activeFrameCount & 3) == 0)
#else
        if (obj->id != 9 && (SCRATCHPAD.activeFrameCount & 3) == 0)
#endif
            playSFXWithNote(3, 12);
        break;
    case 1:
        switch (obj->step) {
        case 0:
            obj->anim = (void *)D_8007D2F0[obj->id * 3][obj->param];
            readAnimFrameCount(obj);
            obj->visible = D_800A5399;
            c = D_800A53A7_U8;
            obj->objectIndex = 0x7f;
            obj->priority = c - 1;
            if (D_8009BCF8 == 3)
                obj->objectIndex = 0x40;
            obj->step = obj->step + 1;
            break;
        case 1:
            if (tickAnimation(obj)) {
                setObjState(obj, 2, 0, 0);
            }
            if (obj->visible == 0) {
                setObjState(obj, 2, 0, 0);
            }
            break;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_800332CC);
void func_800332CC(GameObject *obj)
{
    switch (obj->state) {
    case 0:
#if REGION == REGION_JP
        {
            u8 *p = (u8 *)obj;
            *(u16 *)(p + 0x1e) = D_8007D2E8[p[3]].tpage;
            *(s32 *)(p + 0x3c) = SPR_DATA[D_8007D2E8[p[3]].sprite];
            *(s32 *)(p + 0x24) = D_8007D2E8[p[3]].anims[p[0xc]];
            readAnimFrameCount(obj);
            p[0xa] = 0xd;
            p[0xd] = 0x80;
            *(s8 *)(p + 0xf) = -7;
            *(s32 *)(p + 0x8c) = 0;
            p[0x6b] = 0;
            p[0x1c] |= 0x80;
            p[4]++;
        }
#else
        func_80032374(obj);
#endif
        break;
    case 1:
        if (PLAYER.obj.active != 5)
            func_800330EC(obj);
        break;
    case 2:
        obj->state++;
        break;
    case 3:
        freeEffectObject(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80033374);

void func_80033374(char a, char b, char c)
{
    s32 t;
    char *p = allocEffectObject();
    if (p != 0) {
        p[0] = 1;
        p[2] = 0x4e;
        p[3] = a;
        p[0xc] = b;
        *(s32 *)(p + 0x10) = D_800A53A8_S32;
        *(s32 *)(p + 0x14) = D_800A53AC_S32;
        t = D_800A53B0;
        p[5] = c;
        *(s32 *)(p + 0x18) = t;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80033404);

void func_80033404(s32 a, s32 b)
{
    GameObject *obj = allocEffectObject();
    if (obj) {
        obj->active = 1;
        obj->type = 0x4e;
        obj->id = a;
        obj->param = b;
        obj->x.raw = D_800A53A8[0];
        obj->y.raw = D_800A53A8[1];
        obj->z.raw = D_800A53A8[2];
        obj->subState = 1;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80033488);
typedef struct { s32 a, y, b; } P3_33488;

static __inline__ void spawn_33488(s16 sub, s32 idx)
{
    GameObject *obj = allocEffectObject();
    if (obj != 0) {
        obj->active = 1;
        obj->type = 0x4e;
        obj->id = sub;
        obj->param = idx;
        obj->x.raw = (*(P3_33488 *)&D_800A53A8).a;
        obj->y.raw = (*(P3_33488 *)&D_800A53A8).y;
        obj->z.raw = (*(P3_33488 *)&D_800A53A8).b;
        obj->subState = 0;
    }
}

void func_80033488(s16 n)
{
#if REGION == REGION_JP
    PLAYER.obj.active = 7;
#else
    if (n != 2) PLAYER.obj.active = 7;
#endif
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

#if REGION != REGION_JP
void func_80033858(void) {
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/areainit", dispatchAreaFrontPlaneInit);
void dispatchAreaFrontPlaneInit(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            func_8011BB54();
    } else if (GAME.selectedArea == AREA03_PHOENIXMOUNTAIN) {
            func_80119894();
    }
    return;
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", dispatchAreaBackPlaneInit);
void dispatchAreaBackPlaneInit(void)
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
