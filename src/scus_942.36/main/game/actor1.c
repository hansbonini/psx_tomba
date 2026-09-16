#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8004FD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8004FE24);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800505B0);
void func_800505B0(u8* self, u8 arg1)
{
    s16 v = *(s16*)(self + 0x98);

    if (v != 0) {
        v -= arg1;
        *(s16*)(self + 0x98) = v;
        if (v <= 0) {
            *(s16*)(self + 0x98) = 0;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800505E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800508E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800509F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050AD0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050BBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050C94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050D80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050EA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80050FE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051090);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051488);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051A18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051C98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051DA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80051EE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052100);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800521E0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800522B4);
void func_800522B4(void)
{
    func_80051090();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800522D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052350);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005242C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052558);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800526E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800527C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800529A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052B88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052D5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80052F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800530F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800532B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005334C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053588);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005368C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053808);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_800539E0);
void func_800539E0(void)
{
    if (GAME.selectedArea == 0) {
        func_801242E8();
    } else {
        func_8011F158();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053A1C);
void func_80053A1C(void)
{
    if (GAME.selectedArea == 0) {
        func_80124CC8();
    } else {
        func_8011F218();
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053A58);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053AF0);
void func_80053AF0(void)
{
    if (GAME.selectedArea == 1) {
        func_80123748();
    } else {
        func_8011D178();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053B30);
void func_80053B30(u8* arg0, u8* arg1)
{
    s32* q;

    arg1[0x69] = 0;
    if (func_80051284() == 1) {
        q = *(s32**)(arg0 + 0x40);
        *q = *q + (*(s16*)(arg1 + 0x80) << 8);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053B94);
void func_80053B94(void)
{
    func_80051284();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053BB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053D14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80053F08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80054618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80054D60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_8005548C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055A44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor1", func_80055BA0);
