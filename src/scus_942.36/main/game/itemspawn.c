#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_8004117C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItem);
void spawnItem(short id, short arg1, int arg2)
{
    func_80041940(0, id, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemDrop);
void spawnItemDrop(short arg0, short arg1, int arg2)
{
    func_80041940(1, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemAtPos);
void spawnItemAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(2, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemDropAtPos);
void spawnItemDropAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(3, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemBounce);
void spawnItemBounce(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(4, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemFixed);
void spawnItemFixed(short arg0, short arg1, int arg2)
{
    func_80041940(5, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemChest);
void spawnItemChest(short arg0, short arg1, int arg2)
{
    func_80041940(8, arg0, arg1, arg2, 0, 0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80041940);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemInit);
void dispatchAreaItemInit(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80122688();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D498();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemUpdate);
void dispatchAreaItemUpdate(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_8012298C();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D79C();
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80041DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042104);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042204);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042478);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemDraw);
void dispatchAreaItemDraw(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80122F64();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D844();
    } else if (GAME.selectedArea == AREA10_DEEPJUNGLE) {
        func_8011CD70();
    } else if (GAME.selectedArea == AREA13_PIGISLAND) {
        func_8011602C();
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042654);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042978);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_800429EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042C20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042FE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_800431CC);
