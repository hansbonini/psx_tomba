#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80032DB4);
typedef struct { void **p; s32 a, b; } E12_32DB4;
extern s32 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);

void func_80032DB4(GameObject *o)
{
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
#if REGION != REGION_JP
        if (o->unkC == 0 && !(D_1F8001F8 & 3))
            func_80028A74(0, 0, 0xff, 2);
#endif
        tickAnimation(o);
        o->visible = D_800A5399;
        o->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos((s16)o->unk84, (s16)o->unk88);
        if (o->unkC)
        {
            t = fixedMulSin((s16)o->unk84, 8) + 8;
            o->y.p.whole = PLAYER.obj.y.p.whole + t;
        }
        else
        {
            t = fixedMulSin((s16)o->unk84, 8) + 0x18;
            o->y.p.whole = PLAYER.obj.y.p.whole + t;
        }
        o->d->p.whole = PLAYER.obj.d->p.whole + fixedMulSin((s16)o->unk84, (s16)o->unk88);
        o->unk84 = (o->unk84 + 0x10) & 0xff;
        o->unk88 += o->unk88 < 0xc;
        o->unkF = D_800A53A7[0];
        if (((u8 *)&PLAYER.obj.touchFlag)[0])
            o->timer = 0;
        if (--o->timer <= 0) {
#if REGION == REGION_JP
            if (D_800A5468 > 0)
                PLAYER.obj.active = 3;
            else
                PLAYER.obj.active = 1;
            D_800A5464[0] = 3;
            o->timer = 0;
            o->objectIndex = o->objectIndex == 0 ? 0 : o->objectIndex - 2;
            if (o->objectIndex == 0)
                o->state = 2;
#else
            o->timer = 0;
            D_800A5464[0] = 3;
            o->objectIndex = 0;
            o->state = 2;
#endif
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
    if ((SPAD->unk1F8 & 3) == 0) playSFXWithNote(3, 0xc);
#else
    if (o[3] != 9 && (SPAD->unk1F8 & 3) == 0) playSFXWithNote(3, 0xc);
#endif
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_800330EC);
extern s32 *D_8007D2F0[];

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
#if REGION != REGION_JP
        case 9:
            func_800327D8(o);
            break;
#endif
        }
#if REGION == REGION_JP
        if ((D_1F8001F8 & 3) == 0)
#else
        if (o->subtype != 9 && (D_1F8001F8 & 3) == 0)
#endif
            playSFXWithNote(3, 12);
        break;
    case 1:
        switch (o->step) {
        case 0:
            o->anim = (void *)D_8007D2F0[o->subtype * 3][o->unkC];
            readAnimFrameCount(o);
            o->visible = D_800A5399;
            c = D_800A53A7_U8;
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

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_800332CC);
void func_800332CC(GameObject *o)
{
    switch (o->state) {
    case 0:
#if REGION == REGION_JP
        {
            u8 *p = (u8 *)o;
            *(u16 *)(p + 0x1e) = D_8007D2E8[p[3]].tpage;
            *(s32 *)(p + 0x3c) = SPR_DATA[D_8007D2E8[p[3]].sprite];
            *(s32 *)(p + 0x24) = D_8007D2E8[p[3]].anims[p[0xc]];
            readAnimFrameCount(o);
            p[0xa] = 0xd;
            p[0xd] = 0x80;
            *(s8 *)(p + 0xf) = -7;
            *(s32 *)(p + 0x8c) = 0;
            p[0x6b] = 0;
            p[0x1c] |= 0x80;
            p[4]++;
        }
#else
        func_80032374(o);
#endif
        break;
    case 1:
        if (PLAYER.obj.active != 5)
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

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80033374);

void func_80033374(char a, char b, char c)
{
    s32 t;
    char *p = allocObjectLayer3();
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

// INCLUDE_ASM("nonmatchings/main/game/areainit", func_80033488);
typedef struct { s32 a, y, b; } P3_33488;

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

// INCLUDE_ASM("nonmatchings/main/game/areainit", dispatchAreaInitA);
void dispatchAreaInitA(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            func_8011BB54();
    } else if (GAME.selectedArea == AREA03_PHOENIXMOUNTAIN) {
            func_80119894();
    }
    return;
}

// INCLUDE_ASM("nonmatchings/main/game/areainit", dispatchAreaInitB);
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
#if REGION == REGION_JP
typedef struct { u16 msg; u16 tone; u8 pad[4]; } SignText;
extern u8 D_8009E954_slps01144;
extern s16 D_800A7B8A_slps01144;
extern s16 D_800A7B8A_slps01144_Arr[] asm("D_800A7B8A_slps01144");
extern s32 D_80135D08_slps01144, D_8013BF6C_slps01144;
extern u8 D_800A7C38_slps01144;
extern u8 D_8009E97A_slps01144, D_8009E97D_slps01144, D_8009E97E_slps01144, D_8009EA95_slps01144;
extern SignText D_80076A1C_slps01144[];
extern u16 D_800A0F6C_slps01144;
extern s32 D_8009E52C_slps01144;
extern u8 D_8009E4D8_slps01144;
extern GameObject *func_8002E3B4_slps01144();
void func_8001C88C_slps01144(s32 id, s32 a, s32 b);
void func_80017E0C_slps01144(GameObject *o);

void func_80031688_slps01144(GameObject *o)
{
    GameObject *box;
    s32 msg, tone;

    switch (o->state) {
    case 0:
        switch (o->subtype) {
        case 0x13:
            o->unkA0 = 0;
            break;
        case 0x22:
            if (D_8009E954_slps01144 != 0 || D_800A7B8A_slps01144 < 0x280) {
                o->state = 3;
                return;
            }
            break;
        case 0x12:
            o->state = 3;
            return;
        case 0x63:
            o->unkB4 = -0x10;
            o->unkB6 = -0x18;
            o->unkB8 = 0;
            o->unkBC = 0x18;
            *(s16 *)&o->unkBE = -0x18;
            *(s16 *)((u8 *)o + 0xC0) = 0;
            *(s16 *)((u8 *)o + 0xC4) = -0x10;
            *(s16 *)((u8 *)o + 0xC6) = 0x18;
            *(s16 *)((u8 *)o + 0xC8) = 0;
            *(s16 *)((u8 *)o + 0xCC) = 0x18;
            *(s16 *)((u8 *)o + 0xCE) = 0x18;
            *(s16 *)((u8 *)o + 0xD0) = 0;
            if (GAME.selectedArea == 1 || GAME.selectedArea == 7) {
                o->unkD = 1;
                o->clut = GetClut(0xD0, 0x1E5);
                o->tpage = 7;
                o->anim = (void *)D_8013BF6C_slps01144;
            } else {
                o->unkD = 0;
                o->tpage = 8;
                o->anim = (void *)D_80135D08_slps01144;
            }
            o->spriteBank = SPR_DATA[3];
            o->active = 2;
            o->unkE = 0;
            break;
        }
        o->hitOffsetX = 4;
        o->hitWidth = 8;
        o->hitOffsetY = 0x28;
        o->hitHeight = 0x28;
        o->state++;
        o->touchFlag = 0;
        o->subState = 0;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        if (o->animFrame == 1) {
            o->unk88 = -0x400;
        }
        break;
    case 1:
        func_80022E44((u8 *)o);
        switch (o->subState) {
        case 0:
            if (o->touchFlag == 1) {
                if (D_800A7C38_slps01144 & 1) {
                    switch (o->subtype) {
                    case 19:
                        if (D_8009EA95_slps01144 == 2) o->subtype = 0x14;
                        break;
                    case 20:
                        if (D_8009E97E_slps01144 == 0xFF) o->subtype = 0x23;
                        break;
                    }
                    tone = D_80076A1C_slps01144[o->subtype].tone;
                    msg = D_80076A1C_slps01144[o->subtype].msg;
                    switch (o->subtype) {
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                        tone += D_800A0F6C_slps01144;
                        break;
                    }
                    o->unk90 = (s32)func_8002E3B4_slps01144((s16)msg, (s16)tone, 0xA0, 0x8C);
                    o->subState++;
                }
                o->touchFlag = 0;
            }
            break;
        case 1:
            box = (GameObject *)o->unk90;
            if (box->state >= 2) {
                box->state++;
                D_8009BCAA = 0;
                D_8009BCA7 = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                D_1F8001C6 = 0;
                D_800A7C38_slps01144 = 0;
                o->subState = 0;
                if (o->subtype == 0x11) {
                    func_8001C88C_slps01144(0x25, 0, 0);
                }
                if (o->subtype == 0x13 && D_8009E97A_slps01144 == 0) {
                    func_8001C88C_slps01144(0x2E, 0, 0);
                    D_8009EA95_slps01144 = 1;
                }
                if (o->subtype == 0x14 && D_8009E97D_slps01144 == 0) {
                    func_8001C88C_slps01144(0x31, 0, 0);
                }
            } else if (o->subtype == 1 && (D_8009E52C_slps01144 & 1) && D_8009E4D8_slps01144 == o->subtype) {
                o->subState++;
            }
            break;
        case 2:
            box = (GameObject *)o->unk90;
            if (*(u16 *)&box->state == 0x101) {
                box->subState = 0;
                o->subState++;
            }
            break;
        case 3:
            box = (GameObject *)o->unk90;
            if (box->state >= 2) {
                box->state++;
                D_800A7C38_slps01144 = 0;
                o->subState++;
            }
            break;
        case 4:
            if (D_8009E4D8_slps01144 >= 2) {
                o->subState = 0;
            }
            break;
        }
        if (o->subtype == 0x22 && D_800A7B8A_slps01144_Arr[0] < 0x3E8) {
            D_800A7B8A_slps01144_Arr[0] = 0x3E8;
        }
        break;
    case 2:
        break;
    case 3:
        func_80017E0C_slps01144(o);
        break;
    }
}
#endif
