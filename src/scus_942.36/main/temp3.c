#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", setPlayerAP);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029734);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", addItemToInventory);
u_char addItemToInventory(u_long item_id, u_char qty, bool printMessage)
{
    int i;
    
    for(i = 0; D_8007C2B8[i].first != sizeof(GAME.item)-1; ++i)
    {
        if (D_8007C2B8[i].first == item_id)
        {
            if (D_8007C2B8[i].second <= GAME.item[item_id])
            {
                return GAME.item[item_id];
            }
        }
    }
    if (printMessage != false) {
        printInfoMessage(item_id, 0);
    }
    for(i = 0; i < GAME.inventory.counter; ++i)
    {
        if (GAME.inventory.slots[i] == item_id)
        {
            GAME.item[item_id] = GAME.item[item_id] + qty;
            playSFX(10);
            return GAME.item[item_id];
        }
    }
    for(i = GAME.inventory.counter - 1; i >= 0; --i)
    {
        GAME.inventory.slots[i+1] = GAME.inventory.slots[i];
    }
    GAME.inventory.slots[0] = item_id;
    GAME.item[item_id] = qty;
    GAME.inventory.counter += 1;
    playSFX(10);
    GAME.inventory.sortMode |= SORT_MODE_DEFAULT;
    return GAME.item[item_id];
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", removeItemFromInventory);
int removeItemFromInventory(ITEM id, int qty)
{
    int i;
    for (i = 0; i < GAME.inventory.counter; i++) {
        if (GAME.inventory.slots[i] == id) {
            if (qty == -1) {
                GAME.item[id] = 0;
                while (i < GAME.inventory.counter - 1) {
                    GAME.inventory.slots[i] = GAME.inventory.slots[i+1];
                    i++;
                }
                GAME.inventory.counter -= 1;
                return 0;
            }
            GAME.item[id] = GAME.item[id] - qty;
            if (GAME.item[id] == 0) {
                GAME.item[id] = 0;
                while (i < GAME.inventory.counter - 1) {
                    GAME.inventory.slots[i] = GAME.inventory.slots[i+1];
                    i++;
                }
                GAME.inventory.counter -= 1;
                return 0;
            }
            return GAME.item[id];
        }
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029A84);
u_long func_80029A84(void)
{
    if (GAME.goldenBowlState == 0) {
        if (GAME.playerHealthDisplayed < 8) {
            GAME.playerHealthDisplayed++;
        } else {
            GAME.unk720++;
        }
    } else {
        if (GAME.playerHealthDisplayed < 16) {
            GAME.playerHealthDisplayed++;
        }
    }
    GAME.playerHealth = D_800A5432 = D_800A5430 = GAME.playerHealthDisplayed;
    return GAME.playerHealthDisplayed;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029B20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029BD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029C48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A0A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A240);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A31C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A334);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A798);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A9FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002ABC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002AD74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002AF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002AF8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002AFFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B06C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B278);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B664);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B6A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002B704);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002BAB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002BB9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002C7D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CB58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CC20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CD7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CEF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002CFF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D4C8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D534);
void func_8002D534(void)
{
    switch (GAME.selectedSection) {                     // irregular
        case 2:
        case 0:
            func_800E7E70();
            return;
        case 1:
        case 3:
            func_80115234();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D5AC);
void func_8002D5AC(void)
{
    switch (GAME.selectedSection) {                     // irregular
        case 2:
        case 0:
            func_800E7FE0();
            return;
        case 1:
        case 3:
            func_801151F8();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D624);
void func_8002D624(void)
{
    if (GAME.selectedSection == 0) {
        func_800E80E0();
        return;
    }
    func_80115310();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D660);
void func_8002D660(void)
{
    if (GAME.selectedSection == 0) {
        func_800E821C();
        return;
    }
    func_801152D8();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D69C);
void func_8002D69C(void)
{
    if (GAME.selectedSection == 0) {
        func_800E8388();
        return;
    }
    func_8011546C();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D6D8);
void func_8002D6D8(void)
{
    if (GAME.selectedSection == 0) {
        func_80115584();
        return;
    }
    func_80115628();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D714);
void func_8002D714(void)
{
    switch (GAME.selectedSection) {                     // irregular
        case 1:
            func_801151F8();
            return;
        case 2:
        case 0:
            func_800E84BC();
            return;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D784);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DA2C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DB34);
void func_8002DB34(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DB3C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DBD0);
void func_8002DBD0(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DBD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002DEC4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002E3A8);
void func_8002E3A8(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002E3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002E404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002E494);
