#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", initGameConfig);
void initGameConfig(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    memset((u_char *)&GAME, 0, sizeof(gameConfig));
    memset(&D_8009BC98, 0, 0x2C);
    getBaseMatrix((MATRIX* ) D_1F8000C0);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -120;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    *(int* )0x1F800200 = 69; // ?
    *(u_char* )0x1F8003D2 = 0xFF;
    *(u_char* )0x1F8003D3 = 0xFF;
    GAME.playerAP = 0;
    *&GAME.selectedArea = AREA00_VILLAGEOFALLBEGINNINGS;
    GAME.playerLives = 3;
    GAME.saveSlot = 0xFF;
    GAME.unk730 = 0xFF;
    *(char* )0x1F8003CE = 0; // INVENTORY ENABLED
    *(short* )0x1F8001C8 = 0; // SPRITE ZOOM
    *(char* )0x1F8003D1 = 0; 
    D_8009EBA0 = 0;
    GAME.selectedSection = AREA00_SECTION00_VILLAGEOFALLBEGINNINGS;
    GAME.inventoryScreen = INVENTORY_SCREEN_ITEM;
    GAME.unk13 = 1;
    GAME.unk54f = 1;
    GAME.event[EVENT_GRANDPASBRACELET] = 1;
    GAME.unk12 = 9;
    GAME.playerHealthDisplayed = 4;
    GAME.playerHealth = 4;
    GAME.unk670 = 0x5DA;
    GAME.unk672 = 0x639;
    GAME.unk674 = 0x691;
    GAME.unk5bc = D_8009E744;
    if (*(u8* )0x1F8001B3 == 0) {
        // 0 = NORMAL MODE | 1 = EASY MODE
        if (*(u8* )0x1F8001AB != 0) {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_GRAPPLE;
            GAME.inventory.slots[2] = ITEM_GRAPPLEJACK;
            GAME.inventory.slots[3] = ITEM_WOODBOOMERANG;
            GAME.inventory.slots[4] = ITEM_STONEBOOMERANG;
            GAME.inventory.slots[5] = ITEM_IRONBOOMERANG;
            GAME.inventory.slots[6] = ITEM_NORMALPANTS;
            GAME.inventory.slots[7] = ITEM_JUMPINGPANTS;
            GAME.inventory.slots[8] = ITEM_DASHINGPANTS;
            GAME.inventory.slots[9] = ITEM_FLASHPANTS;
            GAME.inventory.slots[10] = ITEM_100YEAROLDBELL;
            GAME.inventory.slots[11] = ITEM_100YEAROLDKEY;
            GAME.inventory.slots[12] = ITEM_1000YEAROLDKEY;
            GAME.inventory.slots[13] = ITEM_FUNKYPARASOL;
            GAME.inventory.counter = 14;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_GRAPPLE] = 1;
            GAME.item[ITEM_GRAPPLEJACK] = 1;
            GAME.item[ITEM_WOODBOOMERANG] = 1;
            GAME.item[ITEM_STONEBOOMERANG] = 1;
            GAME.item[ITEM_IRONBOOMERANG] = 1;
            GAME.item[ITEM_DASHINGPANTS] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.item[ITEM_JUMPINGPANTS] = 1;
            GAME.item[ITEM_FLASHPANTS] = 1;
            GAME.item[ITEM_100YEAROLDBELL] = 1;
            GAME.item[ITEM_100YEAROLDKEY] = 1;
            GAME.item[ITEM_1000YEAROLDKEY] = 1;
            GAME.item[ITEM_FUNKYPARASOL] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        } else {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_NORMALPANTS;
            GAME.inventory.counter = 2;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        }
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", initHud);
void initHud(void)
{
    char *tmp;

    memset(&D_8009BC98, 0, 0x2C);
    *(s16* )0x1F8001C6 = 0;
    GAME.fadeScreenControl = 1;
    *(s8* )0x1F8003D0 = 0;
    GAME.playerIdleState = 0;
    func_80018F04();
    func_80020CB0();
    
    tmp = D_800B07AC;
    *tmp++ = (GAME.playerAP / 10000000) % 10;
    *tmp++ = (GAME.playerAP / 1000000 ) % 10;
    *tmp++ = (GAME.playerAP / 100000  ) % 10;
    *tmp++ = (GAME.playerAP / 10000   ) % 10;
    *tmp++ = (GAME.playerAP / 1000    ) % 10;
    *tmp++ = (GAME.playerAP / 100     ) % 10;
    *tmp++ = (GAME.playerAP / 10      ) % 10;
    *tmp++ = (GAME.playerAP / 1       ) % 10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017CA0);
void func_80017CA0(void)
{
    memset(&D_800A5398, 0, 0x178);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017CCC);
void func_80017CCC(void)
{
    s32 i;
    u8* p;
    u8* q;

    i = 0;
    p = &D_800A55C8;
    do {
        memset(p, 0, 0x3C);
        p += 0x3C;
        i++;
    } while (i < 10);
    q = &D_800A57E4;
    D_1F800210 = (s32*)&D_800B0518;
    i = 0;
    do {
        *--D_1F800210 = (s32)q;
        q -= 0x3C;
        i++;
    } while (i < 10);
    D_1F80023E = 10;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017D70);
void func_80017D70(void)
{
    s32 i;
    u8* p;
    u8* q;

    i = 0;
    p = &D_800B07D8;
    do {
        memset(p, 0, 0xEC);
        p += 0xEC;
        i++;
    } while (i < 0x4);
    q = &D_800B0A9C;
    D_1F800204 = (s32*)D_800A38B8;
    i = 0;
    do {
        ((unkstruct_800183E4*)q)->unk1C = 1;
        *--D_1F800204 = (s32)q;
        q -= 0xEC;
        i++;
    } while (i < 0x4);
    D_1F800236 = 0x4;
    D_1F800218 = (s32*)&D_800B0528;
    D_1F80025C = (s32*)&D_800B0528;
    D_1F80024E = 0;
    D_1F800244 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017E44);
void func_80017E44(void)
{
    s32 i;
    u8* p;
    u8* q;

    i = 0;
    p = &D_800A5970;
    do {
        memset(p, 0, 0xD4);
        p += 0xD4;
        i++;
    } while (i < 0xC8);
    q = &D_800AFE3C;
    D_1F800208 = (s32*)&D_800A3D08;
    i = 0;
    do {
        ((unkstruct_800183E4*)q)->unk1C = 0;
        *--D_1F800208 = (s32)q;
        q -= 0xD4;
        i++;
    } while (i < 0xC8);
    D_1F800238 = 0xC8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017EEC);
void func_80017EEC(void)
{
    *(int* )0x1F80021C = &D_800A5970;
    *(int* )0x1F800260 = &D_800A5970;
    *(short* )0x1F800250 = 0;
    *(short* )0x1F800246 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017F1C);
void func_80017F1C(void)
{
    s32 i;
    s32 off;

    *(s32** )0x1F800264 = *(s32** )0x1F800220 = &D_800B0680;
    *(s16* )0x1F80024A = *(s16* )0x1F800252 = 0;
    for (i = 7; 0 <= i; --i) {
        off = i * 0x8C;
        *(s16*)&D_800A3348[off] = 0xFFFF;
    }
    func_80018D7C();
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017F88);
void func_80017F88(void)
{
    *(int** )0x1F800224 = &D_800B0470;
    *(int** )0x1F800268 = &D_800B0470;
    *(short* )0x1F800254 = 0;
    *(short* )0x1F80024C = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80017FB8);
void func_80017FB8(void)
{
    s32 i;
    u8* p;
    u8* q;

    i = 0;
    p = &D_800B0B88;
    do {
        memset(p, 0, 0xD4);
        p += 0xD4;
        i++;
    } while (i < 0x2D);
    q = &D_800B2FF8;
    D_1F80020C = (s32*)&D_800A55C4;
    i = 0;
    do {
        ((unkstruct_800183E4*)q)->unk1C = 8;
        *--D_1F80020C = (s32)q;
        q -= 0xD4;
        i++;
    } while (i < 0x2D);
    D_1F80023A = 0x2D;
    D_1F800230 = (s32*)&D_800B3184;
    D_1F800274 = (s32*)&D_800B3184;
    D_1F800258 = 0;
    D_1F800242 = 0;
    func_80018E58();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018094);
void func_80018094(void)
{
    *(int** )0x1F800228 = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    *(short* )0x1F800256 = 0;
    *(short* )0x1F800248 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800180C4);
void func_800180C4(void)
{
    memset(&D_800A38B8, 0, 0x84);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800180F0);
void func_800180F0(void)
{
    memset(&D_800B00F8, 0, 0x16C);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_8001811C);
void func_8001811C(void)
{
    s32 i;
    u8* p;
    u8* q;

    i = 0;
    p = &D_800A3D08;
    do {
        memset(p, 0, 0x6C);
        p += 0x6C;
        i++;
    } while (i < 0xA);
    q = &D_800A40D4;
    D_1F800214 = (s32*)&D_800A37D0;
    i = 0;
    do {
        ((unkstruct_800183E4*)q)->unk1C = 7;
        *--D_1F800214 = (s32)q;
        q -= 0x6C;
        i++;
    } while (i < 0xA);
    D_1F80023C = 0xA;
    D_1F80022C = (s32*)&D_800A5858;
    D_1F800270 = (s32*)&D_800A5858;
    D_1F80025A = 0;
    D_1F800240 = 0;
}

void func_800181F0(void)
{
    memset(&D_800B0770, 0, 0x68);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_8001821C);
void func_8001821C(void)
{
    memset(&D_800A3940, 0, 0x70);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018248);
void* func_80018248(void)
{
    s16  n = D_1F800236;
    s32* p;
    unkstruct_800183E4* obj;

    if (n > 0) {
        p = D_1F800204;
        D_1F800236 = n - 1;
        D_1F800204 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800182C8);
void* func_800182C8(u8 arg0)
{
    s16  n = D_1F800238;
    s32* p;
    unkstruct_800183E4* obj;

    if (n > 0) {
        p = D_1F800208;
        D_1F800238 = n - 1;
        D_1F800208 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        obj->unk1C = arg0;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018354);
void* func_80018354(void)
{
    s16  n = D_1F800238;
    s32* p;
    unkstruct_800183E4* obj;
    u8   layer = 2;

    if (n > 0) {
        p = D_1F800208;
        D_1F800238 = n - 1;
        D_1F800208 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        obj->unk1C = layer;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", allocObjectLayer3);
void* allocObjectLayer3(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_800183E4* obj;
    u_char layer = 3;

    if (scratch->freeObjectCount > 0) {
        scratch->freeObjectCount -= 1;
        obj = *scratch->freeObjects++;
        obj->unk1C = layer;

        if ((scratch->unk1C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018474);
void* func_80018474(void)
{
    s16  n = D_1F800238;
    s32* p;
    unkstruct_800183E4* obj;
    u8   layer = 4;

    if (n > 0) {
        p = D_1F800208;
        D_1F800238 = n - 1;
        D_1F800208 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        obj->unk1C = layer;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018504);
void* func_80018504(void)
{
    s16  n = D_1F800238;
    s32* p;
    unkstruct_800183E4* obj;
    u8   layer = 5;

    if (n > 0) {
        p = D_1F800208;
        D_1F800238 = n - 1;
        D_1F800208 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        obj->unk1C = layer;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018594);
void* func_80018594(void)
{
    s16  n = D_1F80023A;
    s32* p;
    unkstruct_800183E4* obj;

    if (n > 0) {
        p = D_1F80020C;
        D_1F80023A = n - 1;
        D_1F80020C = p + 1;
        obj = (unkstruct_800183E4*)*p;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018614);
void* func_80018614(void)
{
    s16  n = D_1F80023C;
    s32* p;
    unkstruct_800183E4* obj;

    if (n > 0) {
        p = D_1F800214;
        D_1F80023C = n - 1;
        D_1F800214 = p + 1;
        obj = (unkstruct_800183E4*)*p;
        if ((D_1F8001C8 & 1) == 0) {
            obj->unk40 = &obj->data[0x10];
            obj->unk44 = &obj->data[0x18];
        } else {
            obj->unk44 = &obj->data[0x10];
            obj->unk40 = &obj->data[0x18];
        }
        return obj;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018694);
u8* func_80018694(void)
{
    s16  n = D_1F80023E;
    s32* p;

    if (n > 0) {
        p = D_1F800210;
        D_1F80023E = n - 1;
        D_1F800210 = p + 1;
        return (u8*)*p;
    }
    return NULL;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800186E0);
void func_800186E0(s32* arg0)
{
    ((u8*)arg0)[0x1C] &= 0x7F;
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    D_1F800236++;
    *--D_1F800204 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_8001872C);
void func_8001872C(s32* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    asm("");
    ((u8*)arg0)[0x1C] = 0;
    ((u8*)arg0)[0x9C] = 0;
    ((u8*)arg0)[0x9D] = 0;
    ((u8*)arg0)[0x9E] = 0;
    ((u8*)arg0)[0x9F] = 0;
    D_1F800238++;
    *--D_1F800208 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018780);
void func_80018780(s32* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    asm("");
    ((u8*)arg0)[0x1C] = 0;
    ((u8*)arg0)[0x9C] = 0;
    ((u8*)arg0)[0x9D] = 0;
    ((u8*)arg0)[0x9E] = 0;
    ((u8*)arg0)[0x9F] = 0;
    D_1F800238++;
    *--D_1F800208 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800187D4);
void func_800187D4(s32* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    asm("");
    ((u8*)arg0)[0x1C] = 0;
    ((u8*)arg0)[0x9C] = 0;
    ((u8*)arg0)[0x9D] = 0;
    ((u8*)arg0)[0x9E] = 0;
    ((u8*)arg0)[0x9F] = 0;
    D_1F800238++;
    *--D_1F800208 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018828);
void func_80018828(s32* arg0)
{
    ((u8*)arg0)[0x1C] &= 0x7F;
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    ((u8*)arg0)[0x9C] = 0;
    ((u8*)arg0)[0x9D] = 0;
    D_1F80023A++;
    *--D_1F80020C = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_8001887C);
void func_8001887C(s32* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    asm("");
    ((u8*)arg0)[0x1C] = 0;
    ((u8*)arg0)[0x9C] = 0;
    ((u8*)arg0)[0x9D] = 0;
    ((u8*)arg0)[0x9E] = 0;
    ((u8*)arg0)[0x9F] = 0;
    D_1F800238++;
    *--D_1F800208 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_800188D0);
void func_800188D0(s32* arg0)
{
    ((u8*)arg0)[0x1C] &= 0x7F;
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    D_1F80023C++;
    *--D_1F800214 = (s32)arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_8001891C);
void func_8001891C(s32* arg0)
{
    arg0[0] = 0;
    arg0[1] = 0;
    D_1F80023E++;
    *--D_1F800210 = (s32)arg0;
}

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/gameinit", D_80010000);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/game/gameinit", D_80010008);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018954);
void func_80018954(s32* self)
{
    switch (((u8*)self)[0x1C] & 0x7F) {
    case 1:
        ((u8*)self)[0x1C] &= 0x7F;
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        D_1F800236++;
        *--D_1F800204 = (s32)self;
        break;
    case 2:
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        asm("");
        ((u8*)self)[0x1C] = 0;
        ((u8*)self)[0x9C] = 0;
        ((u8*)self)[0x9D] = 0;
        ((u8*)self)[0x9E] = 0;
        ((u8*)self)[0x9F] = 0;
        D_1F800238++;
        *--D_1F800208 = (s32)self;
        break;
    case 3:
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        asm("");
        ((u8*)self)[0x1C] = 0;
        ((u8*)self)[0x9C] = 0;
        ((u8*)self)[0x9D] = 0;
        ((u8*)self)[0x9E] = 0;
        ((u8*)self)[0x9F] = 0;
        D_1F800238++;
        *--D_1F800208 = (s32)self;
        break;
    case 4:
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        asm("");
        ((u8*)self)[0x1C] = 0;
        ((u8*)self)[0x9C] = 0;
        ((u8*)self)[0x9D] = 0;
        ((u8*)self)[0x9E] = 0;
        ((u8*)self)[0x9F] = 0;
        D_1F800238++;
        *--D_1F800208 = (s32)self;
        break;
    case 5:
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        asm("");
        ((u8*)self)[0x1C] = 0;
        ((u8*)self)[0x9C] = 0;
        ((u8*)self)[0x9D] = 0;
        ((u8*)self)[0x9E] = 0;
        ((u8*)self)[0x9F] = 0;
        D_1F800238++;
        *--D_1F800208 = (s32)self;
        break;
    case 7:
        ((u8*)self)[0x1C] &= 0x7F;
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        D_1F80023C++;
        *--D_1F800214 = (s32)self;
        break;
    case 8:
        ((u8*)self)[0x1C] &= 0x7F;
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
        self[3] = 0;
        ((u8*)self)[0x9C] = 0;
        ((u8*)self)[0x9D] = 0;
        D_1F80023A++;
        *--D_1F80020C = (s32)self;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018BC8);
void func_80018BC8(s32 arg0)
{
    *--D_1F800218 = arg0;
    D_1F800244++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018C04);
void func_80018C04(s32 arg0)
{
    *--D_1F80021C = arg0;
    D_1F800246++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018C40);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018C8C);
void func_80018C8C(s32 arg0)
{
    *--D_1F800224 = arg0;
    D_1F80024C++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018CC8);
void func_80018CC8(s32 arg0)
{
    *--D_1F800230 = arg0;
    D_1F800242++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018D04);
void func_80018D04(s32 arg0)
{
    *--D_1F800228 = arg0;
    D_1F800248++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018D40);
void func_80018D40(s32 arg0)
{
    *--D_1F80022C = arg0;
    D_1F800240++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018D7C);
void func_80018D7C(void)
{
    int u;
    int v;

    int i;
    
    u = 0;
    v = 0x6A;
    
    for (i = 0; i < 60; i++) {
        D_800A5140[i].val[0] = u;
        D_800A5140[i].unk0 = -1;
        D_800A5140[i].unk2 = 0;
        D_800A5140[i].val[1] = v;
        D_800A5140[i].val[2] = 4;
        D_800A5140[i].val[3] = 16;
        D_800A5140[i].val[4] = 0;
        D_800A5140[i].val[5] = 0;

        u += 4;
        
        if (u >= 61) {
            u = 0;
            v += 16;
        }
    }
    for (i=0; i < 8; i+=2) {
        D_800A39B0[i].unk0 = -1;
        D_800A39B0[i].unk2 = -1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018E58);
void func_80018E58(void)
{
    int u;
    int v;

    int i;
    
    u = 0;
    v = 0x9E;
    
    for (i = 0; i < 48; i++) {
        D_800AFF18[i].val[0] = u;
        D_800AFF18[i].unk0 = -1;
        D_800AFF18[i].unk2 = 0;
        D_800AFF18[i].val[1] = v;
        D_800AFF18[i].val[2] = 4;
        D_800AFF18[i].val[3] = 24;
        D_800AFF18[i].val[4] = 0;
        D_800AFF18[i].val[5] = 0;

        u += 4;
        
        if (u >= 60) {
            u = 0;
            v += 24;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gameinit", func_80018F04);
void func_80018F04(void) {
    int u;
    int p;

    if (D_8009CA04 == 0) return;
    p = &D_8009EBA8;
    func_8003B478(p);
            
    switch(GAME.selectedArea&0xFFFF) {
        case AREA00_VILLAGEOFALLBEGINNINGS:
            switch (GAME.selectedSection) {
                case AREA00_SECTION00_VILLAGEOFALLBEGINNINGS:
                case AREA00_SECTION01_FORESTOFALLBEGINNINGS:
                case AREA00_SECTION02_FORESTOFALLBEGINNINGSHUTENTRANCE:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
        case AREA01_DWARFFOREST:
            switch (GAME.selectedSection) {
                 case AREA01_SECTION00_FORESTOF100FLOWERS:
                 case AREA01_SECTION01_FORESTOF100FLOWERSRIGHTENTRANCE:
                 case AREA01_SECTION02_WOBBLYWHARF:
                 case AREA01_SECTION03_WATCHTOWER:
                 case AREA01_SECTION04_CHARITYSQUARE:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
        case AREA02_DWARFVILLAGE:
            switch(GAME.selectedSection) {
                case AREA02_SECTION00_DWARFVILLAGE:
                    u = *(int* )0x1F8002BC;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
                 case AREA02_SECTION01_DWARFELDERSHUT:
                 case AREA02_SECTION02_UNDERGROUNDPRISON:
                    u = *(int* )0x1F8002B8;
                    func_8003B2C8(u, p);
                    func_8003B410(p, 0);
                    break;
            }
            break;
    }
}
