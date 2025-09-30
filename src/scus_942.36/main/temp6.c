#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_80032DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_8003301C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_800330EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_800332CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_80033374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_80033404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_80033488);

void func_80033858(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_80033860);
void func_80033860(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            func_8011BB54();
    } else if (GAME.selectedArea == AREA03_PHOENIXMOUNTAIN) {
            func_80119894();
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp6", func_800338A8);
void func_800338A8(void)
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
