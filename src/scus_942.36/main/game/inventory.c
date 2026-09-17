#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", addPlayerAP);
void addPlayerAP(int arg0) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029734);
void func_80029734(s32 arg0, u8 arg1)
{
    u8* p;

    (&D_800B07CC)[arg0] = arg1;
    p = allocObjectLayer3();
    if (p != NULL) {
        p[0] = 1;
        p[2] = 0x20;
        p[0xC] = arg0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", addItemToInventory);
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

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", removeItemFromInventory);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", increaseMaxHealth);
u_long increaseMaxHealth(void)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", applyGoldenBowl);
u8 applyGoldenBowl(void)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029BD8);
int func_80029BD8(int arg0, char arg1, int arg2) {
    GAME.disableSelectMenu = 0;
    if ((GAME.playerEquips.weapon != 3) && (GAME.fadeScreenControl != 2)) {
        GAME.playerEquips.weapon = 0;
        *(u_char*)(arg0 + 3) = arg1;
        (*(u_char*)(arg0 + 5))++;
        D_8009BCEA = arg2 & 0xFF;
        GAME.disableSelectMenu = 1;
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029C48);
void func_80029C48(void)
{
    if (*(u_char*)&D_800A38B8 != 0) {
        func_8002D784(&D_800A38B8);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_80029CDC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A008);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A0A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A240);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A31C);
void func_8002A31C(u8* self)
{
    (*(s16**)(self + 0x38))[1] = D_800A53DC[1];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A334);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A798);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002A9FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002ABC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002AD74);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002AF44);
s32 func_8002AF44(u8* self)
{
    s32 v = *(s32*)(self + 0x24);

    if (v != 0) {
        if (v > 0) {
            v -= 0x80;
        } else {
            v += 0x80;
        }
        *(s32*)(self + 0x24) = v;
        return 0;
    }
    self[0x71] = 0;
    self[0x72] = 0;
    self[0x73] = 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002AF8C);
s32 func_8002AF8C(u8* self)
{
    s32 t;
    s32 cur;

    switch (*(s8*)(self + 0x71)) {
    case 0:
        t = *(s8*)(self + 0x73) << 8;
        cur = *(s32*)(self + 0x24);
        if (t < cur) {
            *(s32*)(self + 0x24) = cur - 0x80;
            return 0;
        }
        return 1;
    case 1:
        t = *(s8*)(self + 0x73) << 8;
        cur = *(s32*)(self + 0x24);
        if (cur >= t) {
            return 1;
        }
        *(s32*)(self + 0x24) = cur + 0x80;
        return 0;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002AFFC);
s32 func_8002AFFC(u8* self)
{
    s32 t;
    s32 cur;

    switch (*(s8*)(self + 0x6D)) {
    case 0:
        t = *(s8*)(self + 0x6F) << 8;
        cur = *(s32*)(self + 0x20);
        if (t < cur) {
            *(s32*)(self + 0x20) = cur - 0x100;
            return 0;
        }
        return 1;
    case 1:
        t = *(s8*)(self + 0x6F) << 8;
        cur = *(s32*)(self + 0x20);
        if (cur >= t) {
            return 1;
        }
        *(s32*)(self + 0x20) = cur + 0x100;
        return 0;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B06C);
s32 func_8002B06C(void)
{
    s16* p = &D_1F8000E6;
    s16  v = *p;

    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            *p = v;
            if (v < 0) {
                *p = 0;
            }
        } else {
            v = v + 2;
            *p = v;
            if (v > 0) {
                *p = 0;
            }
        }
        return 1;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B0D4);
s32 func_8002B0D4(u8* self)
{
    s32 v = *(s32*)(self + 0x20);

    if (v != 0) {
        if (v > 0) {
            v -= 0x100;
        } else {
            v += 0x100;
        }
        *(s32*)(self + 0x20) = v;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B278);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B3E8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B5A4);
s32 func_8002B5A4(u8* self)
{
    s32 w = *(s32*)(self + 0x20);
    s16 v;
    s32 a;
    s32 b;

    if (w != 0) {
        if (w > 0) {
            *(s32*)(self + 0x20) = w - 0x100;
        } else {
            *(s32*)(self + 0x20) = w + 0x100;
        }
        a = 1;
    } else {
        a = 0;
    }
    v = D_1F8000E6;
    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            D_1F8000E6 = v;
            if (v < 0) {
                D_1F8000E6 = 0;
            }
        } else {
            v = v + 2;
            D_1F8000E6 = v;
            if (v > 0) {
                D_1F8000E6 = 0;
            }
        }
        b = 1;
    } else {
        b = 0;
    }
    if ((a | b) != 0) {
        return 0;
    }
    self[0x6E] = 0;
    self[0x6F] = 0;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B664);
s32 func_8002B664(u8* self)
{
    s32 v = *(s32*)(self + 0x20);

    if (v != 0) {
        if (v > 0) {
            v -= 0x100;
        } else {
            v += 0x100;
        }
        *(s32*)(self + 0x20) = v;
        return 0;
    }
    self[0x6E] = 0;
    self[0x6F] = 0;
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B6A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002B704);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002BAB8);
s32 func_8002BAB8(u8* self)
{
    s8 st;

    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
        st = *(s8*)(self + 0x6E);
        if (st == 1) {
            return 1;
        }
        if (st == 0) {
            self[0x6C] = 7;
            self[0x6E] = 1;
            self[0x6D] = 0;
            *(s8*)(self + 0x6F) = -0xA;
        } else {
            self[0x6C] = 7;
            self[0x6D] = 0;
            self[0x6E] = 0;
            self[0x6F] = 0;
        }
        return 0;
    }
    if (D_1F8001FC & 0x40) {
        st = *(s8*)(self + 0x6E);
        if (st == 2) {
            return 1;
        }
        if (st == 0) {
            self[0x6C] = 7;
            self[0x6D] = 1;
            self[0x6E] = 2;
            self[0x6F] = 0xA;
        } else {
            self[0x6C] = 7;
            self[0x6D] = 1;
            self[0x6E] = 0;
            self[0x6F] = 0;
        }
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002BB9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002C7D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CA40);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CB58);
void func_8002CB58(u8* self)
{
    s16 v = D_1F8000E6;
    s32 w;

    if (v != 0) {
        if (v > 0) {
            v = v - 2;
            D_1F8000E6 = v;
            if (v < 0) {
                D_1F8000E6 = 0;
            }
        } else {
            v = v + 2;
            D_1F8000E6 = v;
            if (v > 0) {
                D_1F8000E6 = 0;
            }
        }
    }
    w = *(s32*)(self + 0x24);
    if (w != 0) {
        if (w > 0) {
            *(s32*)(self + 0x24) = w - 0x80;
        } else {
            *(s32*)(self + 0x24) = w + 0x80;
        }
    } else {
        self[0x71] = 0;
        self[0x72] = 0;
        self[0x73] = 0;
    }
    func_8002A9FC(self);
    func_8002AD74(self);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CC20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CD7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CEF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002CFF4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D4C8);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D534);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D5AC);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D624);
void func_8002D624(void)
{
    if (GAME.selectedSection == 0) {
        func_800E80E0();
        return;
    }
    func_80115310();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D660);
void func_8002D660(void)
{
    if (GAME.selectedSection == 0) {
        func_800E821C();
        return;
    }
    func_801152D8();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D69C);
void func_8002D69C(void)
{
    if (GAME.selectedSection == 0) {
        func_800E8388();
        return;
    }
    func_8011546C();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D6D8);
void func_8002D6D8(void)
{
    if (GAME.selectedSection == 0) {
        func_80115584();
        return;
    }
    func_80115628();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D714);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D784);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D964);
s16 func_8002D964(void)
{
    s32 x = D_800A38DC;
    s32 v = (&D_8007D988)[(x >> 8) / 360];
    s32 r = (v * 567) >> 12;

    if (x > 0) {
        r = r - 0x14;
    } else {
        r = r + 0x14;
    }
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002D9D4);
s32 func_8002D9D4(void)
{
    s16 v = (&D_8007D988)[(D_800A38DC >> 8) / 360];

    return (v * 1027) >> 12;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DA2C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DB34);
void func_8002DB34(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DB3C);
void func_8002DB3C(void)
{
    u8* p = &D_800B0B88;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            (&D_8007C68C)[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xD4;
    } while (D_1F800198 < 0x2D);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DBD0);
void func_8002DBD0(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DBD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002DEC4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002E3A8);
void func_8002E3A8(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002E3B0);
void func_8002E3B0(u8 arg0)
{
    u8* p;

    if (D_8009BCBC == 0) {
        p = allocObjectLayer3();
        if (p != NULL) {
            p[0] = 1;
            p[2] = 0xD;
            p[0xC] = arg0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002E404);
void func_8002E404(u8* src)
{
    u8* p = allocObjectLayer3();

    if (p != NULL) {
        p[0] = 1;
        p[2] = 0xD;
        p[3] = 1;
        p[0xC] = src[2];
        p[0xF] = src[0xF] - 1;
        *(u8**)(p + 0x90) = src;
        *(u16*)(p + 0x12) = *(u16*)(src + 0x12);
        *(u16*)(p + 0x16) = *(u16*)(src + 0x16);
        *(u16*)(p + 0x1A) = *(u16*)(src + 0x1A);
        *(u16*)(p + 0xAC) = *(u16*)(src + 0xAC);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/inventory", func_8002E494);
