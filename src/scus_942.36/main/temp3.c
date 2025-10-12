#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", setPlayerAP);
void setPlayerAP(int arg0) {
    u_long* ptr;
	char *mytemp;
    int i = 0;
    
    do
    {
        if ((GAME.playerAP < D_8007C290[i] && (D_8007C290[i] <= (GAME.playerAP + arg0)))) {
            GAME.unk13 = (i + 2);
            GAME.playerLives += 3;
            if (GAME.playerLives > 99) {
                GAME.playerLives = 99;
            }
        }
        i++;
    } while(D_8007C290[i] != -1); 
    GAME.playerAP += arg0;
    mytemp = D_800B07AC;
    *mytemp++ = (GAME.playerAP / 10000000) % 10;
    *mytemp++ = (GAME.playerAP / 1000000 ) % 10;
    *mytemp++ = (GAME.playerAP / 100000  ) % 10;
    *mytemp++ = (GAME.playerAP / 10000   ) % 10;
    *mytemp++ = (GAME.playerAP / 1000    ) % 10;
    *mytemp++ = (GAME.playerAP / 100     ) % 10;
    *mytemp++ = (GAME.playerAP / 10      ) % 10;
    *mytemp++ = (GAME.playerAP / 1       ) % 10;
    return;
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029B20);
u8 func_80029B20(void)
{
    u8 health;

    if ((u8) GAME.playerHealthDisplayed < 0x10U) {
        health = GAME.playerHealthDisplayed + GAME.unk720;
        GAME.playerHealthDisplayed = health;
        if ((u32) (health & 0xFF) >= 0x11U) {
            GAME.playerHealthDisplayed = 0x10;
        }
        printInfoMessage(0x87, 0);
        playSFX(10);
        (u16*)D_800A5430 = GAME.playerHealthDisplayed;
        D_800A5432 = GAME.playerHealthDisplayed;
        GAME.playerHealth = GAME.playerHealthDisplayed;
    }
    GAME.goldenBowlState = 1;
    D_800B078C = (u8* ) &D_800121C8;
    return GAME.playerHealth;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029BD8);
int func_80029BD8(int arg0, char arg1, int arg2) {
    GAME.disableSelectMenu = 0;
    if ((GAME.playerEquips.weapon != 3) && (GAME.unk15 != 2)) {
        GAME.playerEquips.weapon = 0;
        *(u_char*)(arg0 + 3) = arg1;
        (*(u_char*)(arg0 + 5))++;
        D_8009BCEA = arg2 & 0xFF;
        GAME.disableSelectMenu = 1;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029C48);
void func_80029C48(void)
{
    if (*(u_char*)&D_800A38B8 != 0) {
        func_8002D784(&D_800A38B8);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_80029CDC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002A008);
void func_8002A008(s32 arg0)
{
    func_8002467C();
    switch (GAME.selectedArea) {                    // irregular
        case AREA00_VILLAGEOFALLBEGINNINGS:
            func_80115AA8(arg0);
            return;
        case AREA01_DWARFFOREST:
        case AREA07_DWARFFORESTPURIFIED:
            func_80115910(arg0);
            return;
        case AREA03_PHOENIXMOUNTAIN:
            func_801162C4(arg0);
            return;
    }
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp3", func_8002D4C8);
void func_8002D4C8(void)
{
    switch (GAME.selectedSection) {
        case 0:
            func_800E7574();
            return;
        case 3:
            func_800E79F8();
            return;
        case 1:
        case 2:
        case 4:
        case 5:
            func_801156A8();
            // fallthrough
        default:
            return;
    }
}

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
