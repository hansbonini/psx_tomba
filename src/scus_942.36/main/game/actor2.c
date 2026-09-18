#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80055E0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80055ED4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_8005606C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056498);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_800566E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056970);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056BBC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyInit);
void dispatchAreaEnemyInit(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80125FE8();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011F67C();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyUpdate);
void dispatchAreaEnemyUpdate(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_80126048();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_8011F6DC();
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056D24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056E00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80056F94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80057044);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_80057188);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_800574BC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", dispatchAreaEnemyDraw);
void dispatchAreaEnemyDraw(void)
{
    switch (GAME.selectedArea) {
    case AREA00_VILLAGEOFALLBEGINNINGS:
        func_8012C03C();
        break;
    case AREA01_DWARFFOREST:
        func_8012E2FC();
        break;
    case AREA03_PHOENIXMOUNTAIN:
        func_80123EC8();
        break;
    case AREA04_HAUNTEDMANSION:
        func_80122A00();
        break;
    }
}

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C8C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C90);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014C94);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CB4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CBC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CC4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/actor2", D_80014CD0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/actor2", func_8005788C);
