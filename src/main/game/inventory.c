#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/inventory", addPlayerAP);
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", spawnItemNotification);
void spawnItemNotification(s32 arg0, u8 arg1)
{
    u8* p;

    D_800B07CC[arg0] = arg1;
    p = allocObjectLayer3();
    if (p != NULL) {
        p[0] = 1;
        p[2] = 0x20;
        p[0xC] = arg0;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", addItemToInventory);
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
        printInfoMessage(item_id, MSG_TYPE_ITEM);
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
    GAME.inventory.sortMode |= INVENTORY_SORT_MODE_DEFAULT;
    return GAME.item[item_id];
}

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

// INCLUDE_ASM("nonmatchings/main/game/inventory", increaseMaxHealth);
u_long increaseMaxHealth(void)
{
    if (GAME.goldenBowlState == 0) {
        if (GAME.playerHealthDisplayed < 8) {
            GAME.playerHealthDisplayed++;
        } else {
            GAME.bonusHealth++;
        }
    } else {
        if (GAME.playerHealthDisplayed < 16) {
            GAME.playerHealthDisplayed++;
        }
    }
    GAME.playerHealth = D_800A5432 = D_800A5430 = GAME.playerHealthDisplayed;
    return GAME.playerHealthDisplayed;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", applyGoldenBowl);
u8 applyGoldenBowl(void)
{
    u8 health;

    if ((u8) GAME.playerHealthDisplayed < 0x10U) {
        health = GAME.playerHealthDisplayed + GAME.bonusHealth;
        GAME.playerHealthDisplayed = health;
        if ((u32) (health & 0xFF) >= 0x11U) {
            GAME.playerHealthDisplayed = 0x10;
        }
        printInfoMessage(ITEM_GOLDENBOWL, MSG_TYPE_ITEM);
        playSFX(10);
        (u16*)D_800A5430 = GAME.playerHealthDisplayed;
        D_800A5432 = GAME.playerHealthDisplayed;
        GAME.playerHealth = GAME.playerHealthDisplayed;
    }
    GAME.goldenBowlState = 1;
    D_800B078C = (u8* ) &D_800121C8;
    return GAME.playerHealth;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", tryStartItemInteraction);
#if defined(VERSION_SCES_01330)
typedef struct O_27054 { char pad[3]; char a; char pad2; unsigned char c; } O_27054;
extern char D_8009C10A__tryStartItemInteraction;
extern unsigned char D_8009C428__sces01330;
extern signed char D_8009C618__tryStartItemInteraction;
extern unsigned char D_8009BCDD__tryStartItemInteraction;
extern short D_8009BCEA__tryStartItemInteraction;

int tryStartItemInteraction(O_27054 *o, char x, unsigned char y)
{
    char *p = &D_8009C10A__tryStartItemInteraction;
    *p = 0;
    if (D_8009C428__sces01330 != 0)
        return 0;
    if (D_8009C618__tryStartItemInteraction == 3)
        return 0;
    if (D_8009BCDD__tryStartItemInteraction == 2)
        return 0;
    D_8009C618__tryStartItemInteraction = 0;
    o->c++;
    o->a = x;
    D_8009BCEA__tryStartItemInteraction = y;
    *p = 1;
    return 1;
}
#elif defined(VERSION_SCES_01331)
typedef struct O_270A0 { char pad[3]; char a; char pad2; unsigned char c; } O_270A0;
extern char D_8009C10A__tryStartItemInteraction;
extern unsigned char D_8009C938__sces01331;
extern signed char D_8009C618__tryStartItemInteraction;
extern unsigned char D_8009BCDD__tryStartItemInteraction;
extern short D_8009BCEA__tryStartItemInteraction;

int tryStartItemInteraction(O_270A0 *o, char x, unsigned char y)
{
    char *p = &D_8009C10A__tryStartItemInteraction;
    *p = 0;
    if (D_8009C938__sces01331 != 0)
        return 0;
    if (D_8009C618__tryStartItemInteraction == 3)
        return 0;
    if (D_8009BCDD__tryStartItemInteraction == 2)
        return 0;
    D_8009C618__tryStartItemInteraction = 0;
    o->c++;
    o->a = x;
    D_8009BCEA__tryStartItemInteraction = y;
    *p = 1;
    return 1;
}
#else
int tryStartItemInteraction(int arg0, char arg1, int arg2) {
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
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory", updateInventoryOverlay);
void updateInventoryOverlay(void)
{
    if (*(u_char*)&D_800A38B8 != 0) {
        func_8002D784(&D_800A38B8);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepPlayerXToward);
s32 stepPlayerXToward(s32 arg0) {
    s16* p = D_800A53D8;
    u16 x = p[1];
    s32 target = arg0;
    s16 d = x - arg0 + 3;

    if ((u16)d >= 7) {
        if (d < 0) {
            p[1] = x + 3;
        } else {
            p[1] = x - 3;
        }
        return 0;
    }
    p[1] = target;
    return 1;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_80029CDC);
typedef struct {
    char p0[7]; u8 step;
    char p8[0x20 - 8]; s32 d20; s32 d24;
    char p28[0x3f - 0x28]; u8 b3f;
    char p40[0x4a - 0x40]; s16 w4a, w4c; s16 w4e; s16 w50, w52; s16 w54; s16 w56;
    s16 w58; s16 w5a; s16 w5c; s16 w5e, w60, w62;
} S_29CDC;
#define F6 D_1F8000F6[0]

static __inline__ s32 body_29CDC(S_29CDC *s)
{
    s32 r;
    s16 n, v;
    volatile s16 *ee;
    r = 0;
    switch (s->step) {
    case 0:
        ee = D_1F8000EE;
        s->w4c -= *ee;
        s->w50 -= F6;
        s->w52 = *ee;
        s->w56 = F6;
        s->w62 = 0;
        s->w5e = 0;
        s->w60 = 0;
        s->w4a = 0;
        s->w5a = 0;
        s->step++;
        break;
    case 1:
        if (s->w4a != 90) {
            s->w4a++;
            if (s->w4a == 26) {
                D_8009BCA4 = 0;
                D_8009BCDD = 3;
            }
            D_1F8000EE[0] = s->w52 + s->w4c * s->w4a / 90;
            F6 = s->w56 + s->w50 * s->w4a / 90;
        }
        n = s->w4a;
        if (n != 90) {
            if (n >= 45) n = 90 - n;
            if (n < 32) s->w60 = ((n & 0x38) << 1) | 0x80;
            else s->w60 = 0x120;
        } else {
            s->w60 = 0x80;
        }
        if (s->b3f == 0) {
            s->w5e += s->w60;
            if (s->w5e >= 0x5a00) {
                s->w5e = 0x5a00;
                s->w5a++;
            }
            if (s->w5e <= 0x2d00) goto inc;
            if (s->w5e >= 0x4600) goto dec;
        } else {
            s->w5e -= s->w60;
            if (s->w5e < -0x59ff) {
                s->w5e = -0x5a00;
                s->w5a++;
            }
            if (s->w5e >= -0x2d00) {
            inc:
                s->w62 += 0x80;
                if (s->w62 > 0x1200) s->w62 = 0x1200;
            } else if (s->w5e < -0x1bff) {
            dec:
                s->w62 -= 0x80;
                if (s->w62 < 0) s->w62 = 0;
            }
        }
        s->d24 = s->w5e;
        s->d20 = s->w62;
        if (s->w5a != 0 || D_8009BCDD == 1) s->step++;
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}

s32 func_80029CDC(S_29CDC *s)
{
    return body_29CDC(s);
}
#undef F6

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchAreaItemHandler);
void dispatchAreaItemHandler(s32 arg0)
{
    loadSectionHeight();
    switch (GAME.selectedArea) {
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

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A0A0);

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A240);
typedef struct { u8 b0; char p[0x15]; s16 w16; } S_2A240;
typedef struct { s16 w0; s16 w2; } P_2A240;
typedef struct { char p0[0x30]; s16 w30; s16 w32; P_2A240 *d34; } O_2A240;

#if defined(VERSION_SCES_01330)
struct GSInventory_276D0 { unsigned char slots[256]; unsigned short counter; unsigned short sortMode; };
struct GSEquips_276D0 { unsigned char weapon; unsigned char pants; };
typedef struct GameState_276D0 {
    unsigned short selectedArea;
    unsigned short selectedSection;
    unsigned char selectedPlane;
    unsigned char area00_fogControl;
    unsigned char unk6;
    unsigned char keepBgm;
    int totalTimePlayed;
    unsigned long playerAP;
    unsigned char playerHealth;
    unsigned char playerHealthDisplayed;
    char unk12;
    char unk13;
    unsigned char areaTransition;
    unsigned char fadeScreenControl;
    unsigned char fadeScreenAmount;
    unsigned char saveSlot;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char playerLives;
    unsigned char unk21;
    unsigned short selectedSpawnPoint;
    int area00_eventControl;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char displayExpBar;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char area00_pickedItems[32];
    unsigned char area01_pickedItems[32];
    unsigned char area02_pickedItems[32];
    unsigned char area03_pickedItems[32];
    unsigned char area04_pickedItems[32];
    unsigned char area05_pickedItems[32];
    unsigned char area06_pickedItems[32];
    unsigned char area07_pickedItems[32];
    unsigned char area08_pickedItems[32];
    unsigned char area09_pickedItems[32];
    unsigned char area10_pickedItems[32];
    unsigned char area11_pickedItems[32];
    unsigned char area12_pickedItems[32];
    unsigned char area13_pickedItems[32];
    unsigned char area14_pickedItems[32];
    unsigned char area15_pickedItems[32];
    unsigned char area16_pickedItems[32];
    unsigned char area17_pickedItems[32];
    unsigned char area18_pickedItems[32];
    unsigned char area19_pickedItems[32];
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    unsigned char unk2b8;
    unsigned char unk2b9;
    unsigned char unk2ba;
    unsigned char unk2bb;
    unsigned char unk2bc;
    unsigned char unk2bd;
    unsigned char unk2be;
    unsigned char unk2bf;
    unsigned char unk2c0;
    unsigned char unk2c1;
    unsigned char unk2c2;
    unsigned char unk2c3;
    unsigned char unk2c4;
    unsigned char unk2c5;
    unsigned char unk2c6;
    unsigned char unk2c7;
    unsigned char unk2c8;
    unsigned char unk2c9;
    unsigned char unk2ca;
    unsigned char unk2cb;
    unsigned char unk2cc;
    unsigned char unk2cd;
    unsigned char unk2ce;
    unsigned char unk2cf;
    unsigned char unk2d0;
    unsigned char unk2d1;
    unsigned char unk2d2;
    unsigned char unk2d3;
    unsigned char unk2d4;
    unsigned char unk2d5;
    unsigned char unk2d6;
    unsigned char unk2d7;
    unsigned char unk2d8;
    unsigned char unk2d9;
    unsigned char unk2da;
    unsigned char unk2db;
    unsigned char unk2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    unsigned char unk2e0;
    unsigned char unk2e1;
    unsigned char unk2e2;
    unsigned char unk2e3;
    unsigned char unk2e4;
    unsigned char unk2e5;
    unsigned char unk2e6;
    unsigned char unk2e7;
    unsigned char unk2e8;
    unsigned char unk2e9;
    unsigned char unk2ea;
    unsigned char unk2eb;
    unsigned char unk2ec;
    unsigned char unk2ed;
    unsigned char unk2ee;
    unsigned char unk2ef;
    unsigned char unk2f0;
    unsigned char unk2f1;
    unsigned char unk2f2;
    unsigned char unk2f3;
    unsigned char unk2f4;
    unsigned char unk2f5;
    unsigned char unk2f6;
    unsigned char unk2f7;
    unsigned char unk2f8;
    unsigned char unk2f9;
    unsigned char unk2fa;
    unsigned char unk2fb;
    unsigned char unk2fc;
    unsigned char unk2fd;
    unsigned char unk2fe;
    unsigned char unk2ff;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
    unsigned char unk308;
    unsigned char unk309;
    unsigned char unk30a;
    unsigned char unk30b;
    unsigned char unk30c;
    unsigned char unk30d;
    unsigned char unk30e;
    unsigned char unk30f;
    unsigned char unk310;
    unsigned char unk311;
    unsigned char unk312;
    unsigned char unk313;
    unsigned char unk314;
    unsigned char unk315;
    unsigned char unk316;
    unsigned char unk317;
    unsigned char unk318;
    unsigned char unk319;
    unsigned char unk31a;
    unsigned char unk31b;
    unsigned char unk31c;
    unsigned char unk31d;
    unsigned char unk31e;
    unsigned char unk31f;
    unsigned char unk320;
    unsigned char unk321;
    unsigned char unk322;
    unsigned char unk323;
    unsigned char unk324;
    unsigned char unk325;
    unsigned char unk326;
    unsigned char unk327;
    unsigned char unk328;
    unsigned char unk329;
    unsigned char unk32a;
    unsigned char unk32b;
    unsigned char unk32c;
    unsigned char unk32d;
    unsigned char unk32e;
    unsigned char unk32f;
    unsigned char unk330;
    unsigned char unk331;
    unsigned char unk332;
    unsigned char unk333;
    unsigned char unk334;
    unsigned char unk335;
    unsigned char unk336;
    unsigned char unk337;
    unsigned char unk338;
    unsigned char unk339;
    unsigned char unk33a;
    unsigned char unk33b;
    unsigned char unk33c;
    unsigned char unk33d;
    unsigned char unk33e;
    unsigned char unk33f;
    unsigned char unk340;
    unsigned char unk341;
    unsigned char unk342;
    unsigned char unk343;
    unsigned char unk344;
    unsigned char unk345;
    unsigned char unk346;
    unsigned char unk347;
    unsigned char unk348;
    unsigned char unk349;
    unsigned char unk34a;
    unsigned char unk34b;
    unsigned char unk34c;
    unsigned char unk34d;
    unsigned char unk34e;
    unsigned char unk34f;
    unsigned char unk350;
    unsigned char unk351;
    unsigned char unk352;
    unsigned char unk353;
    unsigned char unk354;
    unsigned char unk355;
    unsigned char unk356;
    unsigned char unk357;
    unsigned char unk358;
    unsigned char unk359;
    unsigned char unk35a;
    unsigned char unk35b;
    unsigned char unk35c;
    unsigned char unk35d;
    unsigned char unk35e;
    unsigned char unk35f;
    unsigned char unk360;
    unsigned char unk361;
    unsigned char unk362;
    unsigned char unk363;
    unsigned char unk364;
    unsigned char unk365;
    unsigned char unk366;
    unsigned char unk367;
    unsigned char unk368;
    unsigned char unk369;
    unsigned char unk36a;
    unsigned char unk36b;
    unsigned char unk36c;
    unsigned char unk36d;
    unsigned char unk36e;
    unsigned char unk36f;
    unsigned char unk370;
    unsigned char unk371;
    unsigned char unk372;
    unsigned char unk373;
    unsigned char unk374;
    unsigned char unk375;
    unsigned char unk376;
    unsigned char unk377;
    unsigned char unk378;
    unsigned char unk379;
    unsigned char unk37a;
    unsigned char unk37b;
    unsigned char unk37c;
    unsigned char unk37d;
    unsigned char unk37e;
    unsigned char unk37f;
    unsigned char unk380;
    unsigned char unk381;
    unsigned char unk382;
    unsigned char unk383;
    unsigned char unk384;
    unsigned char unk385;
    unsigned char unk386;
    unsigned char unk387;
    unsigned char unk388;
    unsigned char unk389;
    unsigned char unk38a;
    unsigned char unk38b;
    unsigned char unk38c;
    unsigned char unk38d;
    unsigned char unk38e;
    unsigned char unk38f;
    unsigned char unk390;
    unsigned char unk391;
    unsigned char unk392;
    unsigned char unk393;
    unsigned char unk394;
    unsigned char unk395;
    unsigned char unk396;
    unsigned char unk397;
    unsigned char unk398;
    unsigned char unk399;
    unsigned char unk39a;
    unsigned char unk39b;
    unsigned char unk39c;
    unsigned char unk39d;
    unsigned char unk39e;
    unsigned char unk39f;
    unsigned char unk3a0;
    unsigned char unk3a1;
    unsigned char unk3a2;
    unsigned char unk3a3;
    unsigned char unk3a4;
    unsigned char unk3a5;
    unsigned char unk3a6;
    unsigned char unk3a7;
    unsigned char unk3a8;
    unsigned char unk3a9;
    unsigned char unk3aa;
    unsigned char unk3ab;
    unsigned char unk3ac;
    unsigned char unk3ad;
    unsigned char unk3ae;
    unsigned char unk3af;
    unsigned char unk3b0;
    unsigned char unk3b1;
    unsigned char unk3b2;
    unsigned char unk3b3;
    unsigned char unk3b4;
    unsigned char unk3b5;
    unsigned char unk3b6;
    unsigned char unk3b7;
    unsigned char unk3b8;
    unsigned char unk3b9;
    unsigned char unk3ba;
    unsigned char unk3bb;
    unsigned char unk3bc;
    unsigned char unk3bd;
    unsigned char unk3be;
    unsigned char unk3bf;
    unsigned char unk3c0;
    unsigned char unk3c1;
    unsigned char unk3c2;
    unsigned char unk3c3;
    unsigned char unk3c4;
    unsigned char unk3c5;
    unsigned char unk3c6;
    unsigned char unk3c7;
    unsigned char unk3c8;
    unsigned char unk3c9;
    unsigned char unk3ca;
    unsigned char unk3cb;
    unsigned char unk3cc;
    unsigned char unk3cd;
    unsigned char unk3ce;
    unsigned char unk3cf;
    unsigned char unk3d0;
    unsigned char unk3d1;
    unsigned char unk3d2;
    unsigned char unk3d3;
    unsigned char unk3d4;
    unsigned char unk3d5;
    unsigned char unk3d6;
    unsigned char unk3d7;
    unsigned char unk3d8;
    unsigned char unk3d9;
    unsigned char unk3da;
    unsigned char unk3db;
    unsigned char unk3dc;
    unsigned char unk3dd;
    unsigned char unk3de;
    unsigned char unk3df;
    unsigned char unk3e0;
    unsigned char unk3e1;
    unsigned char unk3e2;
    unsigned char unk3e3;
    unsigned char unk3e4;
    unsigned char unk3e5;
    unsigned char unk3e6;
    unsigned char unk3e7;
    unsigned char unk3e8;
    unsigned char unk3e9;
    unsigned char unk3ea;
    unsigned char unk3eb;
    unsigned char unk3ec;
    unsigned char unk3ed;
    unsigned char unk3ee;
    unsigned char unk3ef;
    unsigned char unk3f0;
    unsigned char unk3f1;
    unsigned char unk3f2;
    unsigned char unk3f3;
    unsigned char unk3f4;
    unsigned char unk3f5;
    unsigned char unk3f6;
    unsigned char unk3f7;
    unsigned char unk3f8;
    unsigned char unk3f9;
    unsigned char unk3fa;
    unsigned char unk3fb;
    unsigned char unk3fc;
    unsigned char unk3fd;
    unsigned char unk3fe;
    unsigned char unk3ff;
    unsigned char unk400;
    unsigned char unk401;
    unsigned char unk402;
    unsigned char unk403;
    unsigned char unk404;
    unsigned char unk405;
    unsigned char unk406;
    unsigned char unk407;
    unsigned char unk408;
    unsigned char unk409;
    unsigned char unk40a;
    unsigned char unk40b;
    unsigned char unk40c;
    unsigned char unk40d;
    unsigned char unk40e;
    unsigned char unk40f;
    unsigned char unk410;
    unsigned char unk411;
    unsigned char unk412;
    unsigned char unk413;
    unsigned char unk414;
    unsigned char unk415;
    unsigned char unk416;
    unsigned char unk417;
    unsigned char unk418;
    unsigned char unk419;
    unsigned char unk41a;
    unsigned char unk41b;
    unsigned char unk41c;
    unsigned char unk41d;
    unsigned char unk41e;
    unsigned char unk41f;
    unsigned char unk420;
    unsigned char unk421;
    unsigned char unk422;
    unsigned char unk423;
    unsigned char unk424;
    unsigned char unk425;
    unsigned char unk426;
    unsigned char unk427;
    unsigned char unk428;
    unsigned char unk429;
    unsigned char unk42a;
    unsigned char unk42b;
    unsigned char unk42c;
    unsigned char unk42d;
    unsigned char unk42e;
    unsigned char unk42f;
    unsigned char unk430;
    unsigned char unk431;
    unsigned char unk432;
    unsigned char unk433;
    unsigned short nextArea;
    unsigned short nextSection;
    unsigned char redExpLevel;
    unsigned char greenExpLevel;
    unsigned char blueExpLevel;
    unsigned char redExpBar;
    unsigned char greenExpBar;
    unsigned char blueExpBar;
    unsigned char unk43e;
    unsigned char unk43f;
    unsigned short nextSpawnPoint;
    unsigned char disableSelectMenu;
    unsigned char inventoryScreen;
    unsigned char event[256];
    unsigned char unk544;
    unsigned char unk545;
    unsigned char unk546;
    unsigned char unk547;
    unsigned char unk548;
    unsigned char unk549;
    unsigned char unk54a;
    unsigned char baronState;
    unsigned char unk54c;
    unsigned char unk54d;
    unsigned char unk54e;
    char unk54f;
    unsigned char unk550;
    unsigned char unk551;
    unsigned char unk552;
    unsigned char unk553;
    unsigned char unk554;
    unsigned char unk555;
    unsigned char unk556;
    unsigned char unk557;
    unsigned char unk558;
    unsigned char unk559;
    unsigned char unk55a;
    unsigned char unk55b;
    unsigned char unk55c;
    unsigned char unk55d;
    unsigned char unk55e;
    unsigned char unk55f;
    unsigned char unk560;
    unsigned char unk561;
    unsigned char unk562;
    unsigned char unk563;
    unsigned char unk564;
    unsigned char unk565;
    unsigned char unk566;
    unsigned char unk567;
    unsigned char unk568;
    unsigned char unk569;
    unsigned char unk56a;
    unsigned char unk56b;
    unsigned char unk56c;
    unsigned char unk56d;
    unsigned char unk56e;
    unsigned char unk56f;
    unsigned char unk570;
    unsigned char unk571;
    unsigned char unk572;
    unsigned char unk573;
    unsigned char unk574;
    unsigned char unk575;
    unsigned char unk576;
    unsigned char unk577;
    unsigned char unk578;
    unsigned char unk579;
    unsigned char unk57a;
    unsigned char unk57b;
    unsigned char unk57c;
    unsigned char unk57d;
    unsigned char unk57e;
    unsigned char unk57f;
    unsigned char unk580;
    unsigned char unk581;
    unsigned char unk582;
    unsigned char unk583;
    unsigned char unk584;
    unsigned char unk585;
    unsigned char unk586;
    unsigned char unk587;
    unsigned char unk588;
    unsigned char unk589;
    unsigned char unk58a;
    unsigned char unk58b;
    unsigned char unk58c;
    unsigned char unk58d;
    unsigned char unk58e;
    unsigned char unk58f;
    unsigned char unk590;
    unsigned char unk591;
    unsigned char unk592;
    unsigned char unk593;
    unsigned char unk594;
    unsigned char unk595;
    unsigned char unk596;
    unsigned char unk597;
    unsigned char unk598;
    unsigned char unk599;
    unsigned char unk59a;
    unsigned char unk59b;
    unsigned char unk59c;
    unsigned char unk59d;
    unsigned char unk59e;
    unsigned char unk59f;
    unsigned char unk5a0;
    unsigned char pipeState;
    unsigned char unk5a2;
    unsigned char unk5a3;
    unsigned char unk5a4;
    unsigned char unk5a5;
    unsigned char unk5a6;
    unsigned char unk5a7;
    unsigned char unk5a8;
    unsigned char unk5a9;
    unsigned char unk5aa;
    unsigned char unk5ab;
    unsigned char unk5ac;
    unsigned char unk5ad;
    unsigned char unk5ae;
    unsigned char unk5af;
    unsigned char unk5b0;
    unsigned char unk5b1;
    unsigned char unk5b2;
    unsigned char unk5b3;
    unsigned char unk5b4;
    unsigned char unk5b5;
    unsigned char unk5b6;
    unsigned char unk5b7;
    unsigned char unk5b8;
    unsigned char unk5b9;
    unsigned char unk5ba;
    unsigned char unk5bb;
    unsigned char unk5bc;
    unsigned char unk5bd;
    unsigned char unk5be;
    unsigned char unk5bf;
    unsigned char unk5c0;
    unsigned char unk5c1;
    unsigned char unk5c2;
    unsigned char unk5c3;
    unsigned char unk5c4;
    unsigned char unk5c5;
    unsigned char unk5c6;
    unsigned char unk5c7;
    unsigned char unk5c8;
    unsigned char unk5c9;
    unsigned char unk5ca;
    unsigned char unk5cb;
    unsigned char unk5cc;
    unsigned char unk5cd;
    unsigned char unk5ce;
    unsigned char unk5cf;
    unsigned char unk5d0;
    unsigned char unk5d1;
    unsigned char unk5d2;
    unsigned char unk5d3;
    unsigned char unk5d4;
    unsigned char unk5d5;
    unsigned char unk5d6;
    unsigned char unk5d7;
    unsigned char unk5d8;
    unsigned char unk5d9;
    unsigned char unk5da;
    unsigned char unk5db;
    unsigned char unk5dc;
    unsigned char unk5dd;
    unsigned char unk5de;
    unsigned char unk5df;
    unsigned char unk5e0;
    unsigned char unk5e1;
    unsigned char unk5e2;
    unsigned char unk5e3;
    unsigned char unk5e4;
    unsigned char unk5e5;
    unsigned char unk5e6;
    unsigned char unk5e7;
    unsigned char unk5e8;
    unsigned char unk5e9;
    unsigned char unk5ea;
    unsigned char unk5eb;
    unsigned char unk5ec;
    unsigned char unk5ed;
    unsigned char unk5ee;
    unsigned char unk5ef;
    unsigned char unk5f0;
    unsigned char unk5f1;
    unsigned char unk5f2;
    unsigned char unk5f3;
    unsigned char unk5f4;
    unsigned char unk5f5;
    unsigned char unk5f6;
    unsigned char unk5f7;
    unsigned char unk5f8;
    unsigned char unk5f9;
    unsigned char unk5fa;
    unsigned char unk5fb;
    unsigned char unk5fc;
    unsigned char unk5fd;
    unsigned char unk5fe;
    unsigned char unk5ff;
    unsigned char unk600;
    unsigned char unk601;
    unsigned char unk602;
    unsigned char unk603;
    unsigned char unk604;
    unsigned char unk605;
    unsigned char unk606;
    unsigned char unk607;
    unsigned char unk608;
    unsigned char unk609;
    unsigned char unk60a;
    unsigned char unk60b;
    unsigned char unk60c;
    unsigned char unk60d;
    unsigned char unk60e;
    unsigned char unk60f;
    unsigned char unk610;
    unsigned char unk611;
    unsigned char unk612;
    unsigned char unk613;
    unsigned char unk614;
    unsigned char unk615;
    unsigned char unk616;
    unsigned char unk617;
    unsigned char unk618;
    unsigned char unk619;
    unsigned char unk61a;
    unsigned char unk61b;
    unsigned char unk61c;
    unsigned char unk61d;
    unsigned char unk61e;
    unsigned char unk61f;
    unsigned char unk620;
    unsigned char unk621;
    unsigned char unk622;
    unsigned char unk623;
    unsigned char unk624;
    unsigned char unk625;
    unsigned char unk626;
    unsigned char unk627;
    unsigned char unk628;
    unsigned char unk629;
    unsigned char unk62a;
    unsigned char unk62b;
    unsigned char unk62c;
    unsigned char unk62d;
    unsigned char unk62e;
    unsigned char unk62f;
    unsigned char unk630;
    unsigned char unk631;
    unsigned char unk632;
    unsigned char unk633;
    unsigned char unk634;
    unsigned char unk635;
    unsigned char unk636;
    unsigned char unk637;
    unsigned char unk638;
    unsigned char unk639;
    unsigned char unk63a;
    unsigned char unk63b;
    unsigned char unk63c;
    unsigned char unk63d;
    unsigned char unk63e;
    unsigned char unk63f;
    unsigned char unk640;
    unsigned char unk641;
    unsigned char unk642;
    unsigned char unk643;
    unsigned char unk644;
    unsigned char unk645;
    unsigned char unk646;
    unsigned char unk647;
    unsigned char unk648;
    unsigned char unk649;
    unsigned char unk64a;
    unsigned char unk64b;
    unsigned char unk64c;
    unsigned char unk64d;
    unsigned char unk64e;
    unsigned char unk64f;
    unsigned char unk650;
    unsigned char unk651;
    unsigned char unk652;
    unsigned char unk653;
    unsigned char unk654;
    unsigned char unk655;
    unsigned char unk656;
    unsigned char unk657;
    unsigned char unk658;
    unsigned char unk659;
    unsigned char unk65a;
    unsigned char unk65b;
    unsigned char unk65c;
    unsigned char unk65d;
    unsigned char unk65e;
    unsigned char unk65f;
    unsigned char unk660;
    unsigned char unk661;
    unsigned char unk662;
    unsigned char unk663;
    unsigned char unk664;
    unsigned char unk665;
    unsigned char unk666;
    unsigned char unk667;
    unsigned char unk668;
    unsigned char unk669;
    unsigned char unk66a;
    unsigned char unk66b;
    unsigned char unk66c;
    unsigned char unk66d;
    unsigned char unk66e;
    unsigned char unk66f;
    short unk670;
    short unk672;
    short unk674;
    unsigned char unk676;
    unsigned char unk677;
    unsigned char unk678;
    unsigned char unk679;
    unsigned char unk67a;
    unsigned char unk67b;
    unsigned char unk67c;
    unsigned char unk67d;
    unsigned char unk67e;
    unsigned char unk67f;
    unsigned char unk680;
    unsigned char unk681;
    unsigned char unk682;
    unsigned char unk683;
    unsigned char goldenFlowerState;
    unsigned char unk685;
    unsigned char unk686;
    unsigned char unk687;
    unsigned char unk688;
    unsigned char unk689;
    unsigned char unk68a;
    unsigned char unk68b;
    unsigned char unk68c;
    unsigned char unk68d;
    unsigned char unk68e;
    unsigned char unk68f;
    unsigned char unk690;
    unsigned char unk691;
    unsigned char unk692;
    unsigned char unk693;
    unsigned char unk694;
    unsigned char unk695;
    unsigned char unk696;
    unsigned char unk697;
    unsigned char unk698;
    unsigned char unk699;
    unsigned char unk69a;
    unsigned char unk69b;
    unsigned char unk69c;
    unsigned char unk69d;
    unsigned char unk69e;
    unsigned char unk69f;
    unsigned char unk6a0;
    unsigned char unk6a1;
    unsigned char unk6a2;
    unsigned char unk6a3;
    unsigned char unk6a4;
    unsigned char unk6a5;
    unsigned char unk6a6;
    unsigned char unk6a7;
    unsigned char unk6a8;
    unsigned char unk6a9;
    unsigned char unk6aa;
    unsigned char unk6ab;
    unsigned char unk6ac;
    unsigned char unk6ad;
    unsigned char unk6ae;
    unsigned char playerIdleState;
    unsigned char unk6b0;
    unsigned char unk6b1;
    unsigned char unk6b2;
    unsigned char unk6b3;
    unsigned char unk6b4;
    unsigned char unk6b5;
    unsigned char unk6b6;
    unsigned char unk6b7;
    unsigned char unk6b8;
    unsigned char unk6b9;
    unsigned char unk6ba;
    unsigned char unk6bb;
    unsigned char unk6bc;
    unsigned char unk6bd;
    unsigned char unk6be;
    unsigned char unk6bf;
    unsigned char unk6c0;
    unsigned char unk6c1;
    unsigned char unk6c2;
    unsigned char unk6c3;
    unsigned char unk6c4;
    unsigned char unk6c5;
    unsigned char unk6c6;
    unsigned char unk6c7;
    unsigned char unk6c8;
    unsigned char unk6c9;
    unsigned char unk6ca;
    unsigned char unk6cb;
    unsigned char unk6cc;
    unsigned char unk6cd;
    unsigned char unk6ce;
    unsigned char unk6cf;
    unsigned char unk6d0;
    unsigned char unk6d1;
    unsigned char unk6d2;
    unsigned char unk6d3;
    unsigned char unk6d4;
    unsigned char unk6d5;
    unsigned char unk6d6;
    unsigned char unk6d7;
    unsigned char unk6d8;
    unsigned char unk6d9;
    unsigned char unk6da;
    unsigned char unk6db;
    unsigned char unk6dc;
    unsigned char unk6dd;
    unsigned char unk6de;
    unsigned char unk6df;
    unsigned char unk6e0;
    unsigned char unk6e1;
    unsigned char unk6e2;
    unsigned char unk6e3;
    unsigned char unk6e4;
    unsigned char unk6e5;
    unsigned char unk6e6;
    unsigned char unk6e7;
    unsigned char unk6e8;
    unsigned char unk6e9;
    unsigned char unk6ea;
    unsigned char unk6eb;
    unsigned char unk6ec;
    unsigned char unk6ed;
    unsigned char unk6ee;
    unsigned char unk6ef;
    unsigned char unk6f0;
    unsigned char unk6f1;
    unsigned char unk6f2;
    unsigned char unk6f3;
    unsigned char unk6f4;
    unsigned char unk6f5;
    unsigned char unk6f6;
    unsigned char unk6f7;
    unsigned char unk6f8;
    unsigned char unk6f9;
    unsigned char unk6fa;
    unsigned char unk6fb;
    unsigned char unk6fc;
    unsigned char unk6fd;
    unsigned char unk6fe;
    unsigned char unk6ff;
    unsigned char unk700;
    unsigned char unk701;
    unsigned char unk702;
    unsigned char unk703;
    unsigned char unk704;
    unsigned char unk705;
    unsigned char unk706;
    unsigned char unk707;
    unsigned char unk708;
    unsigned char unk709;
    unsigned char unk70a;
    unsigned char unk70b;
    unsigned char unk70c;
    unsigned char unk70d;
    unsigned char unk70e;
    unsigned char unk70f;
    unsigned char unk710;
    unsigned char unk711;
    unsigned char unk712;
    unsigned char unk713;
    unsigned char unk714;
    unsigned char unk715;
    unsigned char unk716;
    unsigned char unk717;
    unsigned char unk718;
    unsigned char unk719;
    unsigned char unk71a;
    unsigned char bittingPlantFlowerState;
    unsigned char unk71c;
    unsigned char unk71d;
    unsigned char unk71e;
    unsigned char goldenBowlState;
    unsigned char bonusHealth;
    unsigned char unk721;
    unsigned char unk722;
    unsigned char unk723;
    unsigned char unk724;
    unsigned char unk725;
    unsigned char unk726;
    unsigned char unk727;
    unsigned char unk728;
    unsigned char unk729;
    unsigned char unk72a;
    unsigned char unk72b;
    unsigned char unk72c;
    unsigned char unk72d;
    unsigned char unk72e;
    unsigned char unk72f;
    unsigned char unk730;
    unsigned char unk731;
    unsigned char unk732;
    unsigned char unk733;
    unsigned char unk734;
    unsigned char unk735;
    char unk736;
    unsigned char unk737;
    unsigned char unk738;
    unsigned char unk739;
    unsigned char unk73a;
    unsigned char unk73b;
    unsigned char unk73c;
    unsigned char unk73d;
    unsigned char unk73e;
    unsigned char unk73f;
    unsigned char unk740;
    unsigned char unk741;
    unsigned char unk742;
    unsigned char unk743;
    unsigned char item[256];
    struct GSInventory_276D0 inventory;
    unsigned short currentArea;
    unsigned short currentSection;
    unsigned short currentSpawnPoint;
    unsigned char inventoryButton;
    unsigned char playerState;
    struct GSEquips_276D0 playerEquips;
    unsigned char unk952;
    unsigned char unk953;
    unsigned char unk954;
    unsigned char unk955;
    unsigned char unk956;
    unsigned char unk957;
    unsigned char unk958;
    unsigned char unk959;
    unsigned char unk95a;
    unsigned char unk95b;
    unsigned char unk95c;
    unsigned char unk95d;
    unsigned char unk95e;
    unsigned char unk95f;
    unsigned char unk960;
    unsigned char unk961;
    unsigned char unk962;
    unsigned char purifiedAreas;
    unsigned char unk964;
    unsigned char unk965;
    unsigned char unk966;
    unsigned char unk967;
    unsigned char unk968;
    unsigned char unk969;
    unsigned char unk96a;
    unsigned char unk96b;
    unsigned char unk96c;
    unsigned char unk96d;
    unsigned char unk96e;
    unsigned char unk96f;
    unsigned char unk970;
    unsigned char unk971;
    unsigned char unk972;
    unsigned char unk973;
    unsigned char unk974;
    unsigned char unk975;
    unsigned char unk976;
    unsigned char unk977;
    unsigned char unk978;
    unsigned char unk979;
    unsigned char unk97a;
    unsigned char unk97b;
    unsigned char unk97c;
    unsigned char unk97d;
    unsigned char unk97e;
    unsigned char unk97f;
    unsigned char unk980;
    unsigned char unk981;
    unsigned char unk982;
    unsigned char unk983;
    unsigned char unk984;
} GameState_276D0;
extern GameState_276D0 GAME__8002A240;

typedef struct { unsigned char b0; char p[0x15]; short w16; } S_276D0;
typedef struct { short w0; short w2; } P_276D0;
typedef struct { char p0[0x30]; short w30; short w32; P_276D0 *d34; } O_276D0;
extern S_276D0 PLAYER__8002A240;
extern P_276D0 *D_800A53D8__8002A240;

void func_8002A240(O_276D0 *o)
{
    S_276D0 *s = &PLAYER__8002A240;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        unsigned short x = o->d34->w2;
        short t;
        t = x - 0x90;
        if (D_800A53D8__8002A240->w2 < t) {
            D_800A53D8__8002A240->w2 = t;
        } else {
            t = x + 0x90;
            if (t < D_800A53D8__8002A240->w2)
                D_800A53D8__8002A240->w2 = t;
        }
        if ((*(int*)&GAME__8002A240.selectedArea) == 0x2000E) {
            if (s->w16 < o->w30 - 0x5c)
                s->w16 = o->w30 - 0x5c;
        } else {
            if (s->w16 < o->w30 - 0x90)
                s->w16 = o->w30 - 0x90;
        }
    }
}
#elif defined(VERSION_SCES_01331)
struct GSInventory_2771C { unsigned char slots[256]; unsigned short counter; unsigned short sortMode; };
struct GSEquips_2771C { unsigned char weapon; unsigned char pants; };
typedef struct GameState_2771C {
    unsigned short selectedArea;
    unsigned short selectedSection;
    unsigned char selectedPlane;
    unsigned char area00_fogControl;
    unsigned char unk6;
    unsigned char keepBgm;
    int totalTimePlayed;
    unsigned long playerAP;
    unsigned char playerHealth;
    unsigned char playerHealthDisplayed;
    char unk12;
    char unk13;
    unsigned char areaTransition;
    unsigned char fadeScreenControl;
    unsigned char fadeScreenAmount;
    unsigned char saveSlot;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char playerLives;
    unsigned char unk21;
    unsigned short selectedSpawnPoint;
    int area00_eventControl;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char displayExpBar;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char area00_pickedItems[32];
    unsigned char area01_pickedItems[32];
    unsigned char area02_pickedItems[32];
    unsigned char area03_pickedItems[32];
    unsigned char area04_pickedItems[32];
    unsigned char area05_pickedItems[32];
    unsigned char area06_pickedItems[32];
    unsigned char area07_pickedItems[32];
    unsigned char area08_pickedItems[32];
    unsigned char area09_pickedItems[32];
    unsigned char area10_pickedItems[32];
    unsigned char area11_pickedItems[32];
    unsigned char area12_pickedItems[32];
    unsigned char area13_pickedItems[32];
    unsigned char area14_pickedItems[32];
    unsigned char area15_pickedItems[32];
    unsigned char area16_pickedItems[32];
    unsigned char area17_pickedItems[32];
    unsigned char area18_pickedItems[32];
    unsigned char area19_pickedItems[32];
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    unsigned char unk2b8;
    unsigned char unk2b9;
    unsigned char unk2ba;
    unsigned char unk2bb;
    unsigned char unk2bc;
    unsigned char unk2bd;
    unsigned char unk2be;
    unsigned char unk2bf;
    unsigned char unk2c0;
    unsigned char unk2c1;
    unsigned char unk2c2;
    unsigned char unk2c3;
    unsigned char unk2c4;
    unsigned char unk2c5;
    unsigned char unk2c6;
    unsigned char unk2c7;
    unsigned char unk2c8;
    unsigned char unk2c9;
    unsigned char unk2ca;
    unsigned char unk2cb;
    unsigned char unk2cc;
    unsigned char unk2cd;
    unsigned char unk2ce;
    unsigned char unk2cf;
    unsigned char unk2d0;
    unsigned char unk2d1;
    unsigned char unk2d2;
    unsigned char unk2d3;
    unsigned char unk2d4;
    unsigned char unk2d5;
    unsigned char unk2d6;
    unsigned char unk2d7;
    unsigned char unk2d8;
    unsigned char unk2d9;
    unsigned char unk2da;
    unsigned char unk2db;
    unsigned char unk2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    unsigned char unk2e0;
    unsigned char unk2e1;
    unsigned char unk2e2;
    unsigned char unk2e3;
    unsigned char unk2e4;
    unsigned char unk2e5;
    unsigned char unk2e6;
    unsigned char unk2e7;
    unsigned char unk2e8;
    unsigned char unk2e9;
    unsigned char unk2ea;
    unsigned char unk2eb;
    unsigned char unk2ec;
    unsigned char unk2ed;
    unsigned char unk2ee;
    unsigned char unk2ef;
    unsigned char unk2f0;
    unsigned char unk2f1;
    unsigned char unk2f2;
    unsigned char unk2f3;
    unsigned char unk2f4;
    unsigned char unk2f5;
    unsigned char unk2f6;
    unsigned char unk2f7;
    unsigned char unk2f8;
    unsigned char unk2f9;
    unsigned char unk2fa;
    unsigned char unk2fb;
    unsigned char unk2fc;
    unsigned char unk2fd;
    unsigned char unk2fe;
    unsigned char unk2ff;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
    unsigned char unk308;
    unsigned char unk309;
    unsigned char unk30a;
    unsigned char unk30b;
    unsigned char unk30c;
    unsigned char unk30d;
    unsigned char unk30e;
    unsigned char unk30f;
    unsigned char unk310;
    unsigned char unk311;
    unsigned char unk312;
    unsigned char unk313;
    unsigned char unk314;
    unsigned char unk315;
    unsigned char unk316;
    unsigned char unk317;
    unsigned char unk318;
    unsigned char unk319;
    unsigned char unk31a;
    unsigned char unk31b;
    unsigned char unk31c;
    unsigned char unk31d;
    unsigned char unk31e;
    unsigned char unk31f;
    unsigned char unk320;
    unsigned char unk321;
    unsigned char unk322;
    unsigned char unk323;
    unsigned char unk324;
    unsigned char unk325;
    unsigned char unk326;
    unsigned char unk327;
    unsigned char unk328;
    unsigned char unk329;
    unsigned char unk32a;
    unsigned char unk32b;
    unsigned char unk32c;
    unsigned char unk32d;
    unsigned char unk32e;
    unsigned char unk32f;
    unsigned char unk330;
    unsigned char unk331;
    unsigned char unk332;
    unsigned char unk333;
    unsigned char unk334;
    unsigned char unk335;
    unsigned char unk336;
    unsigned char unk337;
    unsigned char unk338;
    unsigned char unk339;
    unsigned char unk33a;
    unsigned char unk33b;
    unsigned char unk33c;
    unsigned char unk33d;
    unsigned char unk33e;
    unsigned char unk33f;
    unsigned char unk340;
    unsigned char unk341;
    unsigned char unk342;
    unsigned char unk343;
    unsigned char unk344;
    unsigned char unk345;
    unsigned char unk346;
    unsigned char unk347;
    unsigned char unk348;
    unsigned char unk349;
    unsigned char unk34a;
    unsigned char unk34b;
    unsigned char unk34c;
    unsigned char unk34d;
    unsigned char unk34e;
    unsigned char unk34f;
    unsigned char unk350;
    unsigned char unk351;
    unsigned char unk352;
    unsigned char unk353;
    unsigned char unk354;
    unsigned char unk355;
    unsigned char unk356;
    unsigned char unk357;
    unsigned char unk358;
    unsigned char unk359;
    unsigned char unk35a;
    unsigned char unk35b;
    unsigned char unk35c;
    unsigned char unk35d;
    unsigned char unk35e;
    unsigned char unk35f;
    unsigned char unk360;
    unsigned char unk361;
    unsigned char unk362;
    unsigned char unk363;
    unsigned char unk364;
    unsigned char unk365;
    unsigned char unk366;
    unsigned char unk367;
    unsigned char unk368;
    unsigned char unk369;
    unsigned char unk36a;
    unsigned char unk36b;
    unsigned char unk36c;
    unsigned char unk36d;
    unsigned char unk36e;
    unsigned char unk36f;
    unsigned char unk370;
    unsigned char unk371;
    unsigned char unk372;
    unsigned char unk373;
    unsigned char unk374;
    unsigned char unk375;
    unsigned char unk376;
    unsigned char unk377;
    unsigned char unk378;
    unsigned char unk379;
    unsigned char unk37a;
    unsigned char unk37b;
    unsigned char unk37c;
    unsigned char unk37d;
    unsigned char unk37e;
    unsigned char unk37f;
    unsigned char unk380;
    unsigned char unk381;
    unsigned char unk382;
    unsigned char unk383;
    unsigned char unk384;
    unsigned char unk385;
    unsigned char unk386;
    unsigned char unk387;
    unsigned char unk388;
    unsigned char unk389;
    unsigned char unk38a;
    unsigned char unk38b;
    unsigned char unk38c;
    unsigned char unk38d;
    unsigned char unk38e;
    unsigned char unk38f;
    unsigned char unk390;
    unsigned char unk391;
    unsigned char unk392;
    unsigned char unk393;
    unsigned char unk394;
    unsigned char unk395;
    unsigned char unk396;
    unsigned char unk397;
    unsigned char unk398;
    unsigned char unk399;
    unsigned char unk39a;
    unsigned char unk39b;
    unsigned char unk39c;
    unsigned char unk39d;
    unsigned char unk39e;
    unsigned char unk39f;
    unsigned char unk3a0;
    unsigned char unk3a1;
    unsigned char unk3a2;
    unsigned char unk3a3;
    unsigned char unk3a4;
    unsigned char unk3a5;
    unsigned char unk3a6;
    unsigned char unk3a7;
    unsigned char unk3a8;
    unsigned char unk3a9;
    unsigned char unk3aa;
    unsigned char unk3ab;
    unsigned char unk3ac;
    unsigned char unk3ad;
    unsigned char unk3ae;
    unsigned char unk3af;
    unsigned char unk3b0;
    unsigned char unk3b1;
    unsigned char unk3b2;
    unsigned char unk3b3;
    unsigned char unk3b4;
    unsigned char unk3b5;
    unsigned char unk3b6;
    unsigned char unk3b7;
    unsigned char unk3b8;
    unsigned char unk3b9;
    unsigned char unk3ba;
    unsigned char unk3bb;
    unsigned char unk3bc;
    unsigned char unk3bd;
    unsigned char unk3be;
    unsigned char unk3bf;
    unsigned char unk3c0;
    unsigned char unk3c1;
    unsigned char unk3c2;
    unsigned char unk3c3;
    unsigned char unk3c4;
    unsigned char unk3c5;
    unsigned char unk3c6;
    unsigned char unk3c7;
    unsigned char unk3c8;
    unsigned char unk3c9;
    unsigned char unk3ca;
    unsigned char unk3cb;
    unsigned char unk3cc;
    unsigned char unk3cd;
    unsigned char unk3ce;
    unsigned char unk3cf;
    unsigned char unk3d0;
    unsigned char unk3d1;
    unsigned char unk3d2;
    unsigned char unk3d3;
    unsigned char unk3d4;
    unsigned char unk3d5;
    unsigned char unk3d6;
    unsigned char unk3d7;
    unsigned char unk3d8;
    unsigned char unk3d9;
    unsigned char unk3da;
    unsigned char unk3db;
    unsigned char unk3dc;
    unsigned char unk3dd;
    unsigned char unk3de;
    unsigned char unk3df;
    unsigned char unk3e0;
    unsigned char unk3e1;
    unsigned char unk3e2;
    unsigned char unk3e3;
    unsigned char unk3e4;
    unsigned char unk3e5;
    unsigned char unk3e6;
    unsigned char unk3e7;
    unsigned char unk3e8;
    unsigned char unk3e9;
    unsigned char unk3ea;
    unsigned char unk3eb;
    unsigned char unk3ec;
    unsigned char unk3ed;
    unsigned char unk3ee;
    unsigned char unk3ef;
    unsigned char unk3f0;
    unsigned char unk3f1;
    unsigned char unk3f2;
    unsigned char unk3f3;
    unsigned char unk3f4;
    unsigned char unk3f5;
    unsigned char unk3f6;
    unsigned char unk3f7;
    unsigned char unk3f8;
    unsigned char unk3f9;
    unsigned char unk3fa;
    unsigned char unk3fb;
    unsigned char unk3fc;
    unsigned char unk3fd;
    unsigned char unk3fe;
    unsigned char unk3ff;
    unsigned char unk400;
    unsigned char unk401;
    unsigned char unk402;
    unsigned char unk403;
    unsigned char unk404;
    unsigned char unk405;
    unsigned char unk406;
    unsigned char unk407;
    unsigned char unk408;
    unsigned char unk409;
    unsigned char unk40a;
    unsigned char unk40b;
    unsigned char unk40c;
    unsigned char unk40d;
    unsigned char unk40e;
    unsigned char unk40f;
    unsigned char unk410;
    unsigned char unk411;
    unsigned char unk412;
    unsigned char unk413;
    unsigned char unk414;
    unsigned char unk415;
    unsigned char unk416;
    unsigned char unk417;
    unsigned char unk418;
    unsigned char unk419;
    unsigned char unk41a;
    unsigned char unk41b;
    unsigned char unk41c;
    unsigned char unk41d;
    unsigned char unk41e;
    unsigned char unk41f;
    unsigned char unk420;
    unsigned char unk421;
    unsigned char unk422;
    unsigned char unk423;
    unsigned char unk424;
    unsigned char unk425;
    unsigned char unk426;
    unsigned char unk427;
    unsigned char unk428;
    unsigned char unk429;
    unsigned char unk42a;
    unsigned char unk42b;
    unsigned char unk42c;
    unsigned char unk42d;
    unsigned char unk42e;
    unsigned char unk42f;
    unsigned char unk430;
    unsigned char unk431;
    unsigned char unk432;
    unsigned char unk433;
    unsigned short nextArea;
    unsigned short nextSection;
    unsigned char redExpLevel;
    unsigned char greenExpLevel;
    unsigned char blueExpLevel;
    unsigned char redExpBar;
    unsigned char greenExpBar;
    unsigned char blueExpBar;
    unsigned char unk43e;
    unsigned char unk43f;
    unsigned short nextSpawnPoint;
    unsigned char disableSelectMenu;
    unsigned char inventoryScreen;
    unsigned char event[256];
    unsigned char unk544;
    unsigned char unk545;
    unsigned char unk546;
    unsigned char unk547;
    unsigned char unk548;
    unsigned char unk549;
    unsigned char unk54a;
    unsigned char baronState;
    unsigned char unk54c;
    unsigned char unk54d;
    unsigned char unk54e;
    char unk54f;
    unsigned char unk550;
    unsigned char unk551;
    unsigned char unk552;
    unsigned char unk553;
    unsigned char unk554;
    unsigned char unk555;
    unsigned char unk556;
    unsigned char unk557;
    unsigned char unk558;
    unsigned char unk559;
    unsigned char unk55a;
    unsigned char unk55b;
    unsigned char unk55c;
    unsigned char unk55d;
    unsigned char unk55e;
    unsigned char unk55f;
    unsigned char unk560;
    unsigned char unk561;
    unsigned char unk562;
    unsigned char unk563;
    unsigned char unk564;
    unsigned char unk565;
    unsigned char unk566;
    unsigned char unk567;
    unsigned char unk568;
    unsigned char unk569;
    unsigned char unk56a;
    unsigned char unk56b;
    unsigned char unk56c;
    unsigned char unk56d;
    unsigned char unk56e;
    unsigned char unk56f;
    unsigned char unk570;
    unsigned char unk571;
    unsigned char unk572;
    unsigned char unk573;
    unsigned char unk574;
    unsigned char unk575;
    unsigned char unk576;
    unsigned char unk577;
    unsigned char unk578;
    unsigned char unk579;
    unsigned char unk57a;
    unsigned char unk57b;
    unsigned char unk57c;
    unsigned char unk57d;
    unsigned char unk57e;
    unsigned char unk57f;
    unsigned char unk580;
    unsigned char unk581;
    unsigned char unk582;
    unsigned char unk583;
    unsigned char unk584;
    unsigned char unk585;
    unsigned char unk586;
    unsigned char unk587;
    unsigned char unk588;
    unsigned char unk589;
    unsigned char unk58a;
    unsigned char unk58b;
    unsigned char unk58c;
    unsigned char unk58d;
    unsigned char unk58e;
    unsigned char unk58f;
    unsigned char unk590;
    unsigned char unk591;
    unsigned char unk592;
    unsigned char unk593;
    unsigned char unk594;
    unsigned char unk595;
    unsigned char unk596;
    unsigned char unk597;
    unsigned char unk598;
    unsigned char unk599;
    unsigned char unk59a;
    unsigned char unk59b;
    unsigned char unk59c;
    unsigned char unk59d;
    unsigned char unk59e;
    unsigned char unk59f;
    unsigned char unk5a0;
    unsigned char pipeState;
    unsigned char unk5a2;
    unsigned char unk5a3;
    unsigned char unk5a4;
    unsigned char unk5a5;
    unsigned char unk5a6;
    unsigned char unk5a7;
    unsigned char unk5a8;
    unsigned char unk5a9;
    unsigned char unk5aa;
    unsigned char unk5ab;
    unsigned char unk5ac;
    unsigned char unk5ad;
    unsigned char unk5ae;
    unsigned char unk5af;
    unsigned char unk5b0;
    unsigned char unk5b1;
    unsigned char unk5b2;
    unsigned char unk5b3;
    unsigned char unk5b4;
    unsigned char unk5b5;
    unsigned char unk5b6;
    unsigned char unk5b7;
    unsigned char unk5b8;
    unsigned char unk5b9;
    unsigned char unk5ba;
    unsigned char unk5bb;
    unsigned char unk5bc;
    unsigned char unk5bd;
    unsigned char unk5be;
    unsigned char unk5bf;
    unsigned char unk5c0;
    unsigned char unk5c1;
    unsigned char unk5c2;
    unsigned char unk5c3;
    unsigned char unk5c4;
    unsigned char unk5c5;
    unsigned char unk5c6;
    unsigned char unk5c7;
    unsigned char unk5c8;
    unsigned char unk5c9;
    unsigned char unk5ca;
    unsigned char unk5cb;
    unsigned char unk5cc;
    unsigned char unk5cd;
    unsigned char unk5ce;
    unsigned char unk5cf;
    unsigned char unk5d0;
    unsigned char unk5d1;
    unsigned char unk5d2;
    unsigned char unk5d3;
    unsigned char unk5d4;
    unsigned char unk5d5;
    unsigned char unk5d6;
    unsigned char unk5d7;
    unsigned char unk5d8;
    unsigned char unk5d9;
    unsigned char unk5da;
    unsigned char unk5db;
    unsigned char unk5dc;
    unsigned char unk5dd;
    unsigned char unk5de;
    unsigned char unk5df;
    unsigned char unk5e0;
    unsigned char unk5e1;
    unsigned char unk5e2;
    unsigned char unk5e3;
    unsigned char unk5e4;
    unsigned char unk5e5;
    unsigned char unk5e6;
    unsigned char unk5e7;
    unsigned char unk5e8;
    unsigned char unk5e9;
    unsigned char unk5ea;
    unsigned char unk5eb;
    unsigned char unk5ec;
    unsigned char unk5ed;
    unsigned char unk5ee;
    unsigned char unk5ef;
    unsigned char unk5f0;
    unsigned char unk5f1;
    unsigned char unk5f2;
    unsigned char unk5f3;
    unsigned char unk5f4;
    unsigned char unk5f5;
    unsigned char unk5f6;
    unsigned char unk5f7;
    unsigned char unk5f8;
    unsigned char unk5f9;
    unsigned char unk5fa;
    unsigned char unk5fb;
    unsigned char unk5fc;
    unsigned char unk5fd;
    unsigned char unk5fe;
    unsigned char unk5ff;
    unsigned char unk600;
    unsigned char unk601;
    unsigned char unk602;
    unsigned char unk603;
    unsigned char unk604;
    unsigned char unk605;
    unsigned char unk606;
    unsigned char unk607;
    unsigned char unk608;
    unsigned char unk609;
    unsigned char unk60a;
    unsigned char unk60b;
    unsigned char unk60c;
    unsigned char unk60d;
    unsigned char unk60e;
    unsigned char unk60f;
    unsigned char unk610;
    unsigned char unk611;
    unsigned char unk612;
    unsigned char unk613;
    unsigned char unk614;
    unsigned char unk615;
    unsigned char unk616;
    unsigned char unk617;
    unsigned char unk618;
    unsigned char unk619;
    unsigned char unk61a;
    unsigned char unk61b;
    unsigned char unk61c;
    unsigned char unk61d;
    unsigned char unk61e;
    unsigned char unk61f;
    unsigned char unk620;
    unsigned char unk621;
    unsigned char unk622;
    unsigned char unk623;
    unsigned char unk624;
    unsigned char unk625;
    unsigned char unk626;
    unsigned char unk627;
    unsigned char unk628;
    unsigned char unk629;
    unsigned char unk62a;
    unsigned char unk62b;
    unsigned char unk62c;
    unsigned char unk62d;
    unsigned char unk62e;
    unsigned char unk62f;
    unsigned char unk630;
    unsigned char unk631;
    unsigned char unk632;
    unsigned char unk633;
    unsigned char unk634;
    unsigned char unk635;
    unsigned char unk636;
    unsigned char unk637;
    unsigned char unk638;
    unsigned char unk639;
    unsigned char unk63a;
    unsigned char unk63b;
    unsigned char unk63c;
    unsigned char unk63d;
    unsigned char unk63e;
    unsigned char unk63f;
    unsigned char unk640;
    unsigned char unk641;
    unsigned char unk642;
    unsigned char unk643;
    unsigned char unk644;
    unsigned char unk645;
    unsigned char unk646;
    unsigned char unk647;
    unsigned char unk648;
    unsigned char unk649;
    unsigned char unk64a;
    unsigned char unk64b;
    unsigned char unk64c;
    unsigned char unk64d;
    unsigned char unk64e;
    unsigned char unk64f;
    unsigned char unk650;
    unsigned char unk651;
    unsigned char unk652;
    unsigned char unk653;
    unsigned char unk654;
    unsigned char unk655;
    unsigned char unk656;
    unsigned char unk657;
    unsigned char unk658;
    unsigned char unk659;
    unsigned char unk65a;
    unsigned char unk65b;
    unsigned char unk65c;
    unsigned char unk65d;
    unsigned char unk65e;
    unsigned char unk65f;
    unsigned char unk660;
    unsigned char unk661;
    unsigned char unk662;
    unsigned char unk663;
    unsigned char unk664;
    unsigned char unk665;
    unsigned char unk666;
    unsigned char unk667;
    unsigned char unk668;
    unsigned char unk669;
    unsigned char unk66a;
    unsigned char unk66b;
    unsigned char unk66c;
    unsigned char unk66d;
    unsigned char unk66e;
    unsigned char unk66f;
    short unk670;
    short unk672;
    short unk674;
    unsigned char unk676;
    unsigned char unk677;
    unsigned char unk678;
    unsigned char unk679;
    unsigned char unk67a;
    unsigned char unk67b;
    unsigned char unk67c;
    unsigned char unk67d;
    unsigned char unk67e;
    unsigned char unk67f;
    unsigned char unk680;
    unsigned char unk681;
    unsigned char unk682;
    unsigned char unk683;
    unsigned char goldenFlowerState;
    unsigned char unk685;
    unsigned char unk686;
    unsigned char unk687;
    unsigned char unk688;
    unsigned char unk689;
    unsigned char unk68a;
    unsigned char unk68b;
    unsigned char unk68c;
    unsigned char unk68d;
    unsigned char unk68e;
    unsigned char unk68f;
    unsigned char unk690;
    unsigned char unk691;
    unsigned char unk692;
    unsigned char unk693;
    unsigned char unk694;
    unsigned char unk695;
    unsigned char unk696;
    unsigned char unk697;
    unsigned char unk698;
    unsigned char unk699;
    unsigned char unk69a;
    unsigned char unk69b;
    unsigned char unk69c;
    unsigned char unk69d;
    unsigned char unk69e;
    unsigned char unk69f;
    unsigned char unk6a0;
    unsigned char unk6a1;
    unsigned char unk6a2;
    unsigned char unk6a3;
    unsigned char unk6a4;
    unsigned char unk6a5;
    unsigned char unk6a6;
    unsigned char unk6a7;
    unsigned char unk6a8;
    unsigned char unk6a9;
    unsigned char unk6aa;
    unsigned char unk6ab;
    unsigned char unk6ac;
    unsigned char unk6ad;
    unsigned char unk6ae;
    unsigned char playerIdleState;
    unsigned char unk6b0;
    unsigned char unk6b1;
    unsigned char unk6b2;
    unsigned char unk6b3;
    unsigned char unk6b4;
    unsigned char unk6b5;
    unsigned char unk6b6;
    unsigned char unk6b7;
    unsigned char unk6b8;
    unsigned char unk6b9;
    unsigned char unk6ba;
    unsigned char unk6bb;
    unsigned char unk6bc;
    unsigned char unk6bd;
    unsigned char unk6be;
    unsigned char unk6bf;
    unsigned char unk6c0;
    unsigned char unk6c1;
    unsigned char unk6c2;
    unsigned char unk6c3;
    unsigned char unk6c4;
    unsigned char unk6c5;
    unsigned char unk6c6;
    unsigned char unk6c7;
    unsigned char unk6c8;
    unsigned char unk6c9;
    unsigned char unk6ca;
    unsigned char unk6cb;
    unsigned char unk6cc;
    unsigned char unk6cd;
    unsigned char unk6ce;
    unsigned char unk6cf;
    unsigned char unk6d0;
    unsigned char unk6d1;
    unsigned char unk6d2;
    unsigned char unk6d3;
    unsigned char unk6d4;
    unsigned char unk6d5;
    unsigned char unk6d6;
    unsigned char unk6d7;
    unsigned char unk6d8;
    unsigned char unk6d9;
    unsigned char unk6da;
    unsigned char unk6db;
    unsigned char unk6dc;
    unsigned char unk6dd;
    unsigned char unk6de;
    unsigned char unk6df;
    unsigned char unk6e0;
    unsigned char unk6e1;
    unsigned char unk6e2;
    unsigned char unk6e3;
    unsigned char unk6e4;
    unsigned char unk6e5;
    unsigned char unk6e6;
    unsigned char unk6e7;
    unsigned char unk6e8;
    unsigned char unk6e9;
    unsigned char unk6ea;
    unsigned char unk6eb;
    unsigned char unk6ec;
    unsigned char unk6ed;
    unsigned char unk6ee;
    unsigned char unk6ef;
    unsigned char unk6f0;
    unsigned char unk6f1;
    unsigned char unk6f2;
    unsigned char unk6f3;
    unsigned char unk6f4;
    unsigned char unk6f5;
    unsigned char unk6f6;
    unsigned char unk6f7;
    unsigned char unk6f8;
    unsigned char unk6f9;
    unsigned char unk6fa;
    unsigned char unk6fb;
    unsigned char unk6fc;
    unsigned char unk6fd;
    unsigned char unk6fe;
    unsigned char unk6ff;
    unsigned char unk700;
    unsigned char unk701;
    unsigned char unk702;
    unsigned char unk703;
    unsigned char unk704;
    unsigned char unk705;
    unsigned char unk706;
    unsigned char unk707;
    unsigned char unk708;
    unsigned char unk709;
    unsigned char unk70a;
    unsigned char unk70b;
    unsigned char unk70c;
    unsigned char unk70d;
    unsigned char unk70e;
    unsigned char unk70f;
    unsigned char unk710;
    unsigned char unk711;
    unsigned char unk712;
    unsigned char unk713;
    unsigned char unk714;
    unsigned char unk715;
    unsigned char unk716;
    unsigned char unk717;
    unsigned char unk718;
    unsigned char unk719;
    unsigned char unk71a;
    unsigned char bittingPlantFlowerState;
    unsigned char unk71c;
    unsigned char unk71d;
    unsigned char unk71e;
    unsigned char goldenBowlState;
    unsigned char bonusHealth;
    unsigned char unk721;
    unsigned char unk722;
    unsigned char unk723;
    unsigned char unk724;
    unsigned char unk725;
    unsigned char unk726;
    unsigned char unk727;
    unsigned char unk728;
    unsigned char unk729;
    unsigned char unk72a;
    unsigned char unk72b;
    unsigned char unk72c;
    unsigned char unk72d;
    unsigned char unk72e;
    unsigned char unk72f;
    unsigned char unk730;
    unsigned char unk731;
    unsigned char unk732;
    unsigned char unk733;
    unsigned char unk734;
    unsigned char unk735;
    char unk736;
    unsigned char unk737;
    unsigned char unk738;
    unsigned char unk739;
    unsigned char unk73a;
    unsigned char unk73b;
    unsigned char unk73c;
    unsigned char unk73d;
    unsigned char unk73e;
    unsigned char unk73f;
    unsigned char unk740;
    unsigned char unk741;
    unsigned char unk742;
    unsigned char unk743;
    unsigned char item[256];
    struct GSInventory_2771C inventory;
    unsigned short currentArea;
    unsigned short currentSection;
    unsigned short currentSpawnPoint;
    unsigned char inventoryButton;
    unsigned char playerState;
    struct GSEquips_2771C playerEquips;
    unsigned char unk952;
    unsigned char unk953;
    unsigned char unk954;
    unsigned char unk955;
    unsigned char unk956;
    unsigned char unk957;
    unsigned char unk958;
    unsigned char unk959;
    unsigned char unk95a;
    unsigned char unk95b;
    unsigned char unk95c;
    unsigned char unk95d;
    unsigned char unk95e;
    unsigned char unk95f;
    unsigned char unk960;
    unsigned char unk961;
    unsigned char unk962;
    unsigned char purifiedAreas;
    unsigned char unk964;
    unsigned char unk965;
    unsigned char unk966;
    unsigned char unk967;
    unsigned char unk968;
    unsigned char unk969;
    unsigned char unk96a;
    unsigned char unk96b;
    unsigned char unk96c;
    unsigned char unk96d;
    unsigned char unk96e;
    unsigned char unk96f;
    unsigned char unk970;
    unsigned char unk971;
    unsigned char unk972;
    unsigned char unk973;
    unsigned char unk974;
    unsigned char unk975;
    unsigned char unk976;
    unsigned char unk977;
    unsigned char unk978;
    unsigned char unk979;
    unsigned char unk97a;
    unsigned char unk97b;
    unsigned char unk97c;
    unsigned char unk97d;
    unsigned char unk97e;
    unsigned char unk97f;
    unsigned char unk980;
    unsigned char unk981;
    unsigned char unk982;
    unsigned char unk983;
    unsigned char unk984;
} GameState_2771C;
extern GameState_2771C GAME__8002A240;

typedef struct { unsigned char b0; char p[0x15]; short w16; } S_2771C;
typedef struct { short w0; short w2; } P_2771C;
typedef struct { char p0[0x30]; short w30; short w32; P_2771C *d34; } O_2771C;
extern S_2771C PLAYER__8002A240;
extern P_2771C *D_800A53D8__8002A240;

void func_8002A240(O_2771C *o)
{
    S_2771C *s = &PLAYER__8002A240;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        unsigned short x = o->d34->w2;
        short t;
        t = x - 0x90;
        if (D_800A53D8__8002A240->w2 < t) {
            D_800A53D8__8002A240->w2 = t;
        } else {
            t = x + 0x90;
            if (t < D_800A53D8__8002A240->w2)
                D_800A53D8__8002A240->w2 = t;
        }
        if ((*(int*)&GAME__8002A240.selectedArea) == 0x2000E) {
            if (s->w16 < o->w30 - 0x5c)
                s->w16 = o->w30 - 0x5c;
        } else {
            if (s->w16 < o->w30 - 0x90)
                s->w16 = o->w30 - 0x90;
        }
    }
}
#else
void func_8002A240(O_2A240 *o)
{
    S_2A240 *s = &PLAYER;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        u16 x = o->d34->w2;
        s16 t;
        t = x - 0x90;
        if ((*(P_2A240 **)&D_800A53D8)->w2 < t) {
            (*(P_2A240 **)&D_800A53D8)->w2 = t;
        } else {
            t = x + 0x90;
            if (t < (*(P_2A240 **)&D_800A53D8)->w2)
                (*(P_2A240 **)&D_800A53D8)->w2 = t;
        }
        if ((*(s32 *)&GAME) == 0x2000E) {
            if (s->w16 < o->w30 - 0x54)
                s->w16 = o->w30 - 0x54;
        } else {
            if (s->w16 < o->w30 - 0x88)
                s->w16 = o->w30 - 0x88;
        }
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory", syncObjectTargetY);
void syncObjectTargetY(u8* self)
{
    (*(s16**)(self + 0x38))[1] = PLAYER.obj.d->p.whole;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A334);
typedef struct {
    char p0[0x2c];
    s16 s2c, s2e, s30, s32;
    Fix16 *f34;
} S_2A334;
typedef struct { char p[0x14]; s32 d14; } G_2A334;

void func_8002A334(S_2A334 *o)
{
    Fix16 *f;
    G_2A334 *g;
    Fix16 *c;
    s32 v;

    if (D_8009BCA1 != 0) return;
    o->f34->raw = PLAYER.obj.h->raw;
    f = o->f34;
    g = &PLAYER;
    if (o->s2e < f->p.whole) {
        f->raw = o->s2e << 16;
        if (D_8009C618[0] != 3) {
            if (o->s2e + 150 < PLAYER.obj.h->p.whole) PLAYER.obj.h->p.whole = o->s2e + 150;
        }
    } else if (f->p.whole < o->s2c) {
        f->raw = o->s2c << 16;
        if (D_8009C618[0] != 3) {
            if (PLAYER.obj.h->p.whole < o->s2c - 150) PLAYER.obj.h->p.whole = o->s2c - 150;
        }
    }
    if (D_8009C618[0] < 3) {
        c = &D_1F8000F0;
        c->raw = g->d14;
        if (D_1F8000F0.p.whole > o->s32) {
            c->raw = o->s32 << 16;
        } else if (D_1F8000F0.p.whole < o->s30) {
            c->raw = o->s30 << 16;
        }
    }
}

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A480);

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A798);
typedef struct O_2A798 { char p0[0x14]; s32 y; char p1[0x2c-0x18]; s16 h2c; s16 h2e; char p2[0x34-0x30]; s32 *d34;
  char p3[0x3c-0x38]; u8 b3c; char p4[0x44-0x3d]; u16 h44; char p5[0x58-0x46]; u16 w58; } O_2A798;
typedef struct G_2A798 { char p0[0x9c]; u8 f9c; } G_2A798;

void func_8002A798(O_2A798 *o)
{
    u16 u;
    s32 base, t, d;
    u8 neg;
    G_2A798 *g;
    u = D_800A53C6 & 1;
    base = *o->d34 - 0x100000;
    g = &PLAYER;
    if (D_800A5434)
        u = o->w58;
    o->w58 = u;
    if (u)
        base += 0x200000;
    if (PLAYER.obj.unk9E == 3)
        t = D_800A53C8 << 16;
    else
        t = *(*(s32 **)&D_800A53D8);
    d = t - base;
    neg = d < 0;
    if (d > 0x20000) {
        o->b3c = 0;
        if (d < o->y) {
            if (d < 0x40000)
                o->y = d;
            else {
                o->y = 0x40000;
                o->b3c = 1;
            }
        } else {
            if (o->y < 0)
                o->y = 0;
            o->y += 0x2000;
        }
        *o->d34 += o->y;
        if (o->h2e < ((s16 *)o->d34)[1]) {
            *o->d34 = o->h2e << 16;
            o->y = 0;
            o->h44 |= 1;
        }
        return;
    }
    if (d < -0x20000) {
        o->b3c = 0;
        if (o->y < d) {
            if (d > -0x40000)
                o->y = d;
            else {
                o->y = -0x40000;
                o->b3c = 1;
            }
        } else {
            if (o->y > 0)
                o->y = 0;
            o->y -= 0x2000;
        }
        *o->d34 += o->y;
        if (((s16 *)o->d34)[1] < o->h2c) {
            *o->d34 = o->h2c << 16;
            o->y = 0;
            o->h44 |= 2;
        }
        return;
    }
    o->b3c = 0;
    if (!g->f9c)
        o->b3c = 1;
    o->y = d;
    *o->d34 += d;
    if (neg) {
        if (((s16 *)o->d34)[1] < o->h2c) {
            *o->d34 = o->h2c << 16;
            o->y = 0;
            o->h44 |= 2;
        }
    }
L:
    if (o->h2e < ((s16 *)o->d34)[1]) {
        *o->d34 = o->h2e << 16;
        o->y = 0;
        o->h44 |= 1;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002A9FC);

static __inline__ void body_2A9FC(GameObject *o)
{
    s32 d;
    u8 neg;
    d = D_1F80018C - (*(Fix16 **)&o->unk34)->raw;
    neg = d < 0;
    if (d > 0x20000) {
        if (d < o->y.raw) {
            if (d < 0x40000)
                o->y.raw = d;
            else
                o->y.raw = 0x40000;
        } else {
            if (o->y.raw < 0)
                o->y.raw = 0;
            o->y.raw += 0x2000;
        }
        { s32 y = o->y.raw; (*(Fix16 **)&o->unk34)->raw += y; }
    } else if (d < -0x20000) {
        if (o->y.raw < d) {
            if (d > -0x40000)
                o->y.raw = d;
            else
                o->y.raw = -0x40000;
        } else {
            if (o->y.raw > 0)
                o->y.raw = 0;
            o->y.raw -= 0x2000;
        }
        (*(Fix16 **)&o->unk34)->raw += o->y.raw;
        if ((*(Fix16 **)&o->unk34)->p.whole < (s16)o->animTimer) {
            (*(Fix16 **)&o->unk34)->raw = (s16)o->animTimer << 16;
            o->y.raw = 0;
            *(u16 *)&o->d |= 2;
        }
        return;
    } else {
        o->y.raw = d;
        (*(Fix16 **)&o->unk34)->raw += d;
        if (neg) {
            if ((*(Fix16 **)&o->unk34)->p.whole < (s16)o->animTimer) {
                (*(Fix16 **)&o->unk34)->raw = (s16)o->animTimer << 16;
                o->y.raw = 0;
                *(u16 *)&o->d |= 2;
            }
        }
    }
    if ((*(Fix16 **)&o->unk34)->p.whole > (s16)o->animFrame) {
        (*(Fix16 **)&o->unk34)->raw = (s16)o->animFrame << 16;
        o->y.raw = 0;
        *(u16 *)&o->d |= 1;
    }
}

void func_8002A9FC(GameObject *o)
{
    body_2A9FC(o);
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002ABC0);
typedef struct {
    char p0[0x18]; s32 v; char p1[0x30 - 0x1c]; s16 s30, s32; char p2[0x44 - 0x34]; u16 f44;
} O_2ABC0;
typedef union { s32 i; struct { s16 lo, hi; } s; } FX_2ABC0;
#define VF (*(volatile s32 *)&(*(FX_2ABC0 *)&D_1F8000F0).i)

static __inline__ void inl_2ABC0(O_2ABC0 *o)
{
    s32 d = D_1F800190 - VF;
    if (d >= 0) {
        if (d > 0x10000) {
            if (d < o->v) {
                if (d > 0x3ffff) o->v = 0x40000;
                else o->v = d;
            } else {
                if (o->v < 0) o->v = 0;
                o->v += 0x8000;
            }
            VF += o->v;
            if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi > o->s32) {
                (*(FX_2ABC0 *)&D_1F8000F0).i = o->s32 << 16;
                o->v = 0;
                o->f44 |= 8;
            }
        } else {
            VF = D_1F800190;
            if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi > o->s32) {
                (*(FX_2ABC0 *)&D_1F8000F0).i = o->s32 << 16;
                o->v = 0;
                o->f44 |= 8;
            }
        }
    } else {
        if (d < -0x40000) {
            if (o->v < d) {
                if (d > -0x40000) o->v = d;
                else o->v = -0x40000;
            } else {
                if (o->v > 0) o->v = 0;
                o->v -= 0x4000;
            }
        } else {
            o->v = d;
        }
        VF += o->v;
        if ((*(FX_2ABC0 *)&D_1F8000F0).s.hi < o->s30) {
            (*(FX_2ABC0 *)&D_1F8000F0).i = o->s30 << 16;
            o->v = 0;
            o->f44 |= 4;
        }
    }
}

void func_8002ABC0(O_2ABC0 *o)
{
    inl_2ABC0(o);
}
#undef VF

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002AD74);

void func_8002AD74(u8 *o)
{
    extern void stepScrollApproachX(u8 *);
    s32 *p, t;
    switch (*(s16 *)(o + 0x5c)) {
    case 0:
        o[0x6d] = 0;
        *(s8 *)(o + 0x6f) = -10;
        (*(s16 *)(o + 0x5c))++;
    case 1:
        *(s32 *)(o + 0x18) += 0x2000;
        if (*(s32 *)(o + 0x18) > 0x3ffff)
            *(s32 *)(o + 0x18) = 0x40000;
        if (*(s32 *)(o + 0x18) > 0x12000)
            stepScrollApproachX(o);
        p = &D_1F8000F0;
        *p += *(s32 *)(o + 0x18);
        if (D_1F8000F2 > *(s16 *)(o + 0x32)) {
            D_1F8000F0 = *(s16 *)(o + 0x32) << 16;
            *(s32 *)(o + 0x18) = 0;
            *(u16 *)(o + 0x44) |= 8;
        }
        t = *p - D_1F800190;
        if (t > 0x580000)
            (*(s16 *)(o + 0x5c))++;
        break;
    case 2:
        *(s32 *)(o + 0x18) += 0x2000;
        if (*(s32 *)(o + 0x18) > 0x2ffff)
            *(s32 *)(o + 0x18) = 0x30000;
        p = &D_1F8000F0;
        *p += *(s32 *)(o + 0x18);
        if (D_1F8000F2 > *(s16 *)(o + 0x32)) {
            D_1F8000F0 = *(s16 *)(o + 0x32) << 16;
            *(s32 *)(o + 0x18) = 0;
            *(u16 *)(o + 0x44) |= 8;
        }
        t = *p - D_1F800190;
        if (t <= 0)
            o[3] = 3;
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollReturnY);
s32 stepScrollReturnY(u8* self)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollApproachY);
s32 stepScrollApproachY(u8* self)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollApproachX);
s32 stepScrollApproachX(u8* self)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", dampCameraAngle);
s32 dampCameraAngle(void)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollReturnX);
s32 stepScrollReturnX(u8* self)
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

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002B110);

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002B278);

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002B3E8);
void func_8002B110();
void func_8002B278();

static __inline__ void decay_2B3E8(void)
{
    s16 v = D_1F8000E6;
    if (v == 0) return;
    if (v > 0) {
        v -= 2;
        D_1F8000E6 = v;
        if (v < 0) D_1F8000E6 = 0;
    } else {
        v += 2;
        D_1F8000E6 = v;
        if (v > 0) D_1F8000E6 = 0;
    }
}

void func_8002B3E8(char *o, s32 a)
{
    volatile u16 *k;

    if (D_800A5434 != 0) {
        decay_2B3E8();
        return;
    }
    k = D_8009C9D8;
    if (*k & 0x10) {
        if (a != 0 || *(s32 *)(o + 0x20) < -0x9ff) {
            func_8002B110(o, a);
            return;
        }
        decay_2B3E8();
    } else if (*k & 0x40) {
        if (a != 0 || *(s32 *)(o + 0x20) >= 0xa00) {
            func_8002B278(o, a);
            return;
        }
        decay_2B3E8();
    } else {
        decay_2B3E8();
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollAndAngle);
s32 stepScrollAndAngle(u8* self)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", stepScrollClearX);
s32 stepScrollClearX(u8* self)
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

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002B6A8);

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002B704);
typedef struct { char p[0x24]; s32 d24; char q[0x70 - 0x28]; s8 b70, b71, b72, b73; } S_2B704;
static __inline__ s32 approach_2B704(S_2B704 *o)
{
    switch (o->b71) {
    case 0:
        if ((o->b73 << 8) < o->d24) {
            o->d24 -= 0x80;
            return 0;
        }
        return 1;
    case 1:
        if (o->d24 >= (o->b73 << 8)) return 1;
        o->d24 += 0x80;
        return 0;
    }
    return 0;
}
static __inline__ s32 decel_2B704(S_2B704 *o)
{
    s32 v = o->d24;
    if (v != 0) {
        if (v > 0) v -= 0x80;
        else v += 0x80;
        o->d24 = v;
        return 0;
    }
    o->b71 = 0;
    o->b72 = 0;
    o->b73 = 0;
    return 1;
}

void func_8002B704(S_2B704 *o)
{
    GameObject *p;
    if (D_8009BCA7) {
        if (o->d24 != 0) {
            if (o->d24 > 0) o->d24 -= 0x80;
            else o->d24 += 0x80;
        } else {
            o->b71 = 0;
            o->b72 = 0;
            o->b73 = 0;
        }
        return;
    }
    p = &PLAYER;
    switch (o->b70) {
    case 0:
        if (p->unkA4) {
            o->b70 = 5;
            if (p->animFrame & 1) {
                o->b71 = 0;
                o->b73 = -10;
            } else {
                o->b71 = 1;
                o->b73 = 10;
            }
            break;
        }
        switch (p->unk9E) {
        case 2: case 3: case 5: case 6: case 8: case 9:
            o->b70 = 1;
            if (p->animFrame & 1) {
                o->b71 = 1;
                o->b73 = 10;
            } else {
                o->b71 = 0;
                o->b73 = -10;
            }
            break;
        }
        break;
    case 1:
        if ((p->animFrame & 1) != o->b71) {
            o->b71 = p->animFrame & 1;
            o->b73 = -o->b73;
        }
        if (approach_2B704(o)) o->b70 = 2;
    case 2:
        switch (p->unk9E) {
        case 0: case 1: case 4: case 7: case 10: case 11: case 12:
            o->b70 = 3;
            o->b71 = 0;
            break;
        case 2: case 3: case 5: case 6: case 8: case 9:
            if ((p->animFrame & 1) != o->b71) {
                o->b70 = 1;
                o->b71 = p->animFrame & 1;
                o->b73 = -o->b73;
            }
            break;
        }
        break;
    case 3:
        if (decel_2B704(o)) o->b70 = 0;
        break;
    case 4:
        if (approach_2B704(o)) o->b70 = 0;
        break;
    case 5:
        if (approach_2B704(o)) o->b70++;
    case 6:
        if (!p->unkA4) o->b70++;
        break;
    case 7:
        if (decel_2B704(o)) o->b70 = 0;
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", handleLookScrollInput);
s32 handleLookScrollInput(u8* self)
{
    s8 st;

    if ((JOYPAD_STATE & JOY_UP) && D_800A5438 != 4) {
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
    if (JOYPAD_STATE & JOY_DOWN) {
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002BB9C);
typedef struct {
    char p0[0x20];
    s32 spd;
    char p24[0x30 - 0x24];
    s16 w30, w32;
    char p34[0x6c - 0x34];
    s8 b6c, b6d, b6e, b6f;
    char p70[0x75 - 0x70];
    u8 b75, b76, b77;
} S_2BB9C;
typedef struct {
    char p0[0x9e];
    u8 b9e;
    char p9f;
    union { s32 i; u8 b[4]; } a0;
} G_2BB9C;

static __inline__ s16 ramp_2BB9C(S_2BB9C *o)
{
    switch (o->b6d) {
    case 0:
        if (o->spd > o->b6f << 8) {
            o->spd -= 0x100;
            return 0;
        }
        return 1;
    case 1:
        if (o->spd >= o->b6f << 8) return 1;
        o->spd += 0x100;
        return 0;
    }
    return 0;
}

static __inline__ s32 decay_2BB9C(void)
{
    s16 v = D_1F8000E6;
    if (v != 0) {
        if (v > 0) {
            v -= 2;
            D_1F8000E6 = v;
            if (v < 0) D_1F8000E6 = 0;
        } else {
            v += 2;
            D_1F8000E6 = v;
            if (v > 0) D_1F8000E6 = 0;
        }
        return 1;
    }
    return 0;
}

static __inline__ void clamp_2BB9C(S_2BB9C *o)
{
    s16 f = D_1F8000F2;
    s32 s = f + D_1F8000E6;
    if (o->w30 > s) D_1F8000E6 = o->w30 - f;
    else if (o->w32 < s) D_1F8000E6 = o->w32 - f;
}

void func_8002BB9C(S_2BB9C *o)
{
    s32 f;
    G_2BB9C *g = &PLAYER;
    s32 a, b;
    u8 c;
    u8 t1, t2, t3;

    switch (o->b6c) {
    case 0:
        if (D_8009BCA2 == 0) break;
        if (D_8009BCA7 != 0) {
            o->b6c = 6;
            break;
        }
        if (!(g->a0.b[0] & 1) && g->a0.b[2] >= 2) {
            o->b6c = 8;
            o->b6e = 1;
            o->b6d = 0;
            o->b6f = -10;
            break;
        }
        if ((g->a0.i & 0xff000002) == 0x2000000) {
            o->b6c = 4;
            o->b6d = 1;
            o->b6e = 2;
            o->b6f = 10;
            break;
        }
        switch (g->b9e) {
        case 0:
            c = g->a0.b[0];
            if (c & 0x12) {
                if (D_8009C9D8[0] & 0xc00) {
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        if (o->b6e != 1) {
                            o->b6c = 7;
                            o->b6e = 1;
                            o->b6d = 0;
                            o->b6f = -10;
                        }
                    } else if ((D_1F8001FC & 0x40) && o->b6e != 2) {
                        o->b6c = 7;
                        o->b6d = 1;
                        o->b6e = 2;
                        o->b6f = 10;
                    }
                    func_8002B3E8(o, 0);
                } else if ((u8)c == 0x12) {
                    if (handleLookScrollInput(o) == 0) break;
                    decay_2BB9C();
                } else if (c & 0x10) {
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        f = 0;
                        if (o->b6e == 0) goto t2;
                        o->b6c = 7;
                        o->b6d = 0;
                        o->b6e = 0;
                        o->b6f = 0;
                    } else {
                        if (!(D_1F8001FC & 0x40)) goto t2;
                        if (o->b6e == 2) goto t2;
                        if (o->b6e == 0) {
                            o->b6c = 7;
                            o->b6d = 1;
                            o->b6e = 2;
                            o->b6f = 10;
                        } else {
                            o->b6c = 7;
                            o->b6d = 1;
                            o->b6e = 0;
                            o->b6f = 0;
                        }
                        f = 0;
                        if (0) {
                        t2:
                            f = 1;
                        }
                    }
                    if (f) decay_2BB9C();
                } else if (c & 2) {
                    if (c & 1) break;
                    if ((D_1F8001FC & 0x10) && D_800A5438 != 4) {
                        if (o->b6e == 1) goto t1;
                        {
                            if (o->b6e == 0) {
                                o->b6c = 7;
                                o->b6e = 1;
                                o->b6d = 0;
                                o->b6f = -10;
                            } else {
                                o->b6c = 7;
                                o->b6d = 0;
                                o->b6e = 0;
                                o->b6f = 0;
                            }
                            f = 0;
                        }
                    } else {
                        f = 1;
                        if (D_1F8001FC & 0x40) {
                            f = 0;
                            if (o->b6e != 0) {
                                o->b6c = 7;
                                o->b6d = 1;
                                o->b6e = 0;
                                o->b6f = 0;
                            } else {
                            t1:
                                f = 1;
                            }
                        }
                    }
                    if (f) decay_2BB9C();
                }
            } else if (D_8009C9D8[0] & 0xc00) {
                handleLookScrollInput(o);
                func_8002B3E8(o, 0);
            } else {
                decay_2BB9C();
            }
            break;
        case 2:
            t1 = o->b6d;
            t2 = o->b6e;
            t3 = o->b6f;
            o->b6c = 1;
            o->b6d = 1;
            o->b6f = 10;
            o->b75 = t1;
            o->b76 = t2;
            o->b77 = t3;
            break;
        case 1:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
        default:
            if ((g->a0.b[0] & 0x12) || (D_8009C9D8[0] & 0xc00)) func_8002B3E8(o, 1);
            else decay_2BB9C();
            break;
        }
        break;
    case 1:
        if (ramp_2BB9C(o)) o->b6c = 2;
    case 2:
        if (g->b9e != 2) {
            o->b6c = 3;
            o->b6d = o->b75;
            o->b6f = o->b77;
            if (o->b6f == 0) o->b6d = 0;
        }
        decay_2BB9C();
        break;
    case 3:
        a = decay_2BB9C();
        if (ramp_2BB9C(o) && !a) {
            o->b6c = 0;
            o->b6e = o->b76;
        }
        break;
    case 4:
        if (ramp_2BB9C(o)) o->b6c++;
        clamp_2BB9C(o);
        break;
    case 5:
        clamp_2BB9C(o);
        if (g->a0.b[3] != 0) break;
        if ((g->a0.b[0] & 0x10) && (D_8009C9D8[0] & 0x40)) goto zero;
        if (D_8009BCCC > D_8009BCCD) goto zero;
        o->b6c = 7;
        o->b6d = 0;
        o->b6e = 0;
        o->b6f = 0;
        break;
    case 6:
        a = 0;
        if (o->spd != 0) {
            if (o->spd > 0) o->spd -= 0x100;
            else o->spd += 0x100;
            a = 1;
        }
        b = decay_2BB9C();
        if (!(a | b)) {
            o->b6e = 0;
            o->b6f = 0;
            b = 1;
        } else b = 0;
        if (b) o->b6c = 10;
        break;
    case 7:
        func_8002B3E8(o, 0);
        if (ramp_2BB9C(o)) o->b6c = 0;
        break;
    case 8:
        if (ramp_2BB9C(o)) o->b6c++;
        clamp_2BB9C(o);
        break;
    case 9:
        if (g->a0.b[2] != 0) break;
        if (g->a0.b[0] & 2) {
            if (D_8009C9D8[0] & 0x10) {
                if (!(g->a0.b[0] & 1)) o->b6c = 0;
                break;
            }
        }
        o->b6c = 7;
        o->b6d = 1;
        o->b6e = 2;
        o->b6f = 10;
        break;
    case 10:
        if (D_8009BCA7 != 0) break;
        if ((*(s16 *)&D_1F8001C8) == 0) {
            if (D_8009BCCC <= D_8009BCCD) {
                o->b6c = 0;
                break;
            }
        } else if (D_8009BCCC >= D_8009BCCD) {
            goto zero;
        }
        o->b6d = 1;
        o->b6e = 2;
        o->b6f = 10;
        o->b6c++;
        break;
    case 11:
        if (ramp_2BB9C(o)) {
        zero:
            o->b6c = 0;
        }
        break;
    }
    loadSectionHeight(o);
    switch (GAME.selectedArea) {
    case 0:
        func_80115AA8(o);
        break;
    case 1:
    case 7:
        func_80115910(o);
        break;
    case 3:
        func_801162C4(o);
        break;
    }
    if (D_1F8000F2 > o->w32) D_1F8000F0 = o->w32 << 16;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002C7D8);
typedef struct { u8 b0; char p0[0x15]; s16 w16; char p1[0x16]; u16 w2e; char p2[0x79]; u8 ba9; } S_2C7D8;
typedef struct { s16 w0; s16 w2; } P_2C7D8;
typedef struct {
    char p0[0x24]; s32 d24; char p1[8]; s16 w30; s16 w32; P_2C7D8 *d34; P_2C7D8 *d38;
    u8 b3c; u8 b3d; char p2[0x1a]; u16 w58;
} O_2C7D8;
extern u8 D_800A5436;

static __inline__ void Clamp_2C7D8(O_2C7D8 *o)
{
    S_2C7D8 *s = &PLAYER;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        u16 x = o->d34->w2;
        s16 t;
        t = x - 0x90;
        if ((*(P_2C7D8 **)&D_800A53D8)->w2 < t) {
            (*(P_2C7D8 **)&D_800A53D8)->w2 = t;
        } else {
            t = x + 0x90;
            if (t < (*(P_2C7D8 **)&D_800A53D8)->w2)
                (*(P_2C7D8 **)&D_800A53D8)->w2 = t;
        }
        if ((*(s32 *)&GAME) == 0x2000E) {
            if (s->w16 < o->w30 - 0x54)
                s->w16 = o->w30 - 0x54;
        } else {
            if (s->w16 < o->w30 - 0x88)
                s->w16 = o->w30 - 0x88;
        }
    }
}

#if defined(VERSION_SCES_01330)
typedef struct SPADBlock_29C68 {
    unsigned char b0;
    unsigned char _pad1[0x5f];
    short s60;
    short s62;
    short s64;
    unsigned char _pad66[0xe];
    int i74;
    int i78;
    unsigned char _pad7c[0x10];
    int i8c;
    unsigned char _pad90[0x30];
    unsigned char bc0;
    unsigned char _padc1[0x13];
    int id4;
    int id8;
    int idc;
    int ie0;
    unsigned char _pade4[0x2];
    short se6;
    unsigned char _pade8[0x2];
    short sea;
    int iec;
    int if0;
    int if4;
    unsigned char _padf8[0x20];
    unsigned char b118;
    unsigned char _pad119[0x4b];
    void * p164;
    int i168;
    int i16c;
    int i170;
    int i174;
    unsigned char _pad178[0x2];
    unsigned short s17a;
    unsigned char _pad17c[0x2];
    unsigned short s17e;
    unsigned char _pad180[0x6];
    unsigned short s186;
    unsigned char _pad188[0x4];
    int i18c;
    int i190;
    unsigned char _pad194[0x4];
    int i198;
    short s19c;
    short s19e;
    unsigned char b1a0;
    unsigned char _pad1a1[0x3];
    unsigned char b1a4;
    unsigned char b1a5;
    unsigned char _pad1a6[0x1c];
    unsigned char b1c2;
    unsigned char _pad1c3[0x1];
    unsigned char b1c4;
    unsigned char b1c5;
    short s1c6;
    unsigned short s1c8;
    unsigned char _pad1ca[0x2];
    unsigned char b1cc;
    unsigned char b1cd;
    unsigned char _pad1ce[0x1];
    unsigned char b1cf;
    unsigned char b1d0;
    unsigned char b1d1;
    unsigned char b1d2;
    unsigned char b1d3;
    unsigned char _pad1d4[0xc];
    int i1e0;
    unsigned char _pad1e4[0x4];
    short s1e8;
    unsigned char _pad1ea[0xa];
    short s1f4;
    short s1f6;
    unsigned short s1f8;
    unsigned char _pad1fa[0x2];
    unsigned short s1fc;
    unsigned short s1fe;
    unsigned char _pad200[0x1c];
    void * p21c;
    unsigned char _pad220[0x4];
    void * p224;
    void * p228;
    unsigned char _pad22c[0xc];
    short s238;
    unsigned char _pad23a[0xc];
    short s246;
    unsigned short s248;
    unsigned char _pad24a[0x2];
    short s24c;
    unsigned char _pad24e[0x2];
    unsigned short s250;
    unsigned char _pad252[0x2];
    unsigned short s254;
    short s256;
    unsigned char _pad258[0x8];
    void * p260;
    unsigned char _pad264[0x4];
    void * p268;
    void * p26c;
    unsigned char _pad270[0x8];
    void * p278;
    unsigned char _pad27c[0x2];
    short s27e;
    short s280;
    unsigned short s282;
    short s284;
    short s286;
    unsigned char _pad288[0x2c];
    int i2b4;
    unsigned char _pad2b8[0x18];
    int i2d0;
    int i2d4;
    int i2d8;
    int i2dc;
    int i2e0;
    int i2e4;
    int i2e8;
    unsigned char _pad2ec[0x4];
    int i2f0;
    unsigned char _pad2f4[0x4];
    int i2f8;
    unsigned char _pad2fc[0x4];
    int i300;
    int i304;
    void * p308;
    void * p30c;
    int i310;
    int i314;
    int i318;
    void * p31c;
    unsigned char _pad320[0x14];
    int i334;
    void * p338;
    void * p33c;
    unsigned char _pad340[0x1c];
    int i35c;
    unsigned char _pad360[0x10];
    int i370;
    int i374;
    int i378;
    unsigned char _pad37c[0x3c];
    unsigned short s3b8;
    unsigned short s3ba;
    short s3bc;
    unsigned char _pad3be[0x2];
    void * p3c0;
    unsigned short s3c4;
    unsigned short s3c6;
    unsigned short s3c8;
    unsigned char _pad3ca[0x4];
    unsigned char b3ce;
    unsigned char _pad3cf[0x1];
    unsigned char b3d0;
    unsigned char b3d1;
    unsigned char _pad3d2[0x2e];
} SPADBlock_29C68;
extern SPADBlock_29C68 SCRATCHPAD__8002C7D8;

typedef struct GVars_29C68 {
    unsigned char b30;
    unsigned char _pad31[3];
    int i34;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    unsigned char b43;
    short s44;
    short s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    unsigned char b58;
    unsigned char b59;
    unsigned char _pad5a[2];
    int i5c;
} GVars_29C68;
extern GVars_29C68 D_8009BC98__8002C7D8;

struct GSInventory_29C68 { unsigned char slots[256]; unsigned short counter; unsigned short sortMode; };
struct GSEquips_29C68 { unsigned char weapon; unsigned char pants; };
typedef struct GameState_29C68 {
    unsigned short selectedArea;
    unsigned short selectedSection;
    unsigned char selectedPlane;
    unsigned char area00_fogControl;
    unsigned char unk6;
    unsigned char keepBgm;
    int totalTimePlayed;
    unsigned long playerAP;
    unsigned char playerHealth;
    unsigned char playerHealthDisplayed;
    char unk12;
    char unk13;
    unsigned char areaTransition;
    unsigned char fadeScreenControl;
    unsigned char fadeScreenAmount;
    unsigned char saveSlot;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char playerLives;
    unsigned char unk21;
    unsigned short selectedSpawnPoint;
    int area00_eventControl;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char displayExpBar;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char area00_pickedItems[32];
    unsigned char area01_pickedItems[32];
    unsigned char area02_pickedItems[32];
    unsigned char area03_pickedItems[32];
    unsigned char area04_pickedItems[32];
    unsigned char area05_pickedItems[32];
    unsigned char area06_pickedItems[32];
    unsigned char area07_pickedItems[32];
    unsigned char area08_pickedItems[32];
    unsigned char area09_pickedItems[32];
    unsigned char area10_pickedItems[32];
    unsigned char area11_pickedItems[32];
    unsigned char area12_pickedItems[32];
    unsigned char area13_pickedItems[32];
    unsigned char area14_pickedItems[32];
    unsigned char area15_pickedItems[32];
    unsigned char area16_pickedItems[32];
    unsigned char area17_pickedItems[32];
    unsigned char area18_pickedItems[32];
    unsigned char area19_pickedItems[32];
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    unsigned char unk2b8;
    unsigned char unk2b9;
    unsigned char unk2ba;
    unsigned char unk2bb;
    unsigned char unk2bc;
    unsigned char unk2bd;
    unsigned char unk2be;
    unsigned char unk2bf;
    unsigned char unk2c0;
    unsigned char unk2c1;
    unsigned char unk2c2;
    unsigned char unk2c3;
    unsigned char unk2c4;
    unsigned char unk2c5;
    unsigned char unk2c6;
    unsigned char unk2c7;
    unsigned char unk2c8;
    unsigned char unk2c9;
    unsigned char unk2ca;
    unsigned char unk2cb;
    unsigned char unk2cc;
    unsigned char unk2cd;
    unsigned char unk2ce;
    unsigned char unk2cf;
    unsigned char unk2d0;
    unsigned char unk2d1;
    unsigned char unk2d2;
    unsigned char unk2d3;
    unsigned char unk2d4;
    unsigned char unk2d5;
    unsigned char unk2d6;
    unsigned char unk2d7;
    unsigned char unk2d8;
    unsigned char unk2d9;
    unsigned char unk2da;
    unsigned char unk2db;
    unsigned char unk2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    unsigned char unk2e0;
    unsigned char unk2e1;
    unsigned char unk2e2;
    unsigned char unk2e3;
    unsigned char unk2e4;
    unsigned char unk2e5;
    unsigned char unk2e6;
    unsigned char unk2e7;
    unsigned char unk2e8;
    unsigned char unk2e9;
    unsigned char unk2ea;
    unsigned char unk2eb;
    unsigned char unk2ec;
    unsigned char unk2ed;
    unsigned char unk2ee;
    unsigned char unk2ef;
    unsigned char unk2f0;
    unsigned char unk2f1;
    unsigned char unk2f2;
    unsigned char unk2f3;
    unsigned char unk2f4;
    unsigned char unk2f5;
    unsigned char unk2f6;
    unsigned char unk2f7;
    unsigned char unk2f8;
    unsigned char unk2f9;
    unsigned char unk2fa;
    unsigned char unk2fb;
    unsigned char unk2fc;
    unsigned char unk2fd;
    unsigned char unk2fe;
    unsigned char unk2ff;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
    unsigned char unk308;
    unsigned char unk309;
    unsigned char unk30a;
    unsigned char unk30b;
    unsigned char unk30c;
    unsigned char unk30d;
    unsigned char unk30e;
    unsigned char unk30f;
    unsigned char unk310;
    unsigned char unk311;
    unsigned char unk312;
    unsigned char unk313;
    unsigned char unk314;
    unsigned char unk315;
    unsigned char unk316;
    unsigned char unk317;
    unsigned char unk318;
    unsigned char unk319;
    unsigned char unk31a;
    unsigned char unk31b;
    unsigned char unk31c;
    unsigned char unk31d;
    unsigned char unk31e;
    unsigned char unk31f;
    unsigned char unk320;
    unsigned char unk321;
    unsigned char unk322;
    unsigned char unk323;
    unsigned char unk324;
    unsigned char unk325;
    unsigned char unk326;
    unsigned char unk327;
    unsigned char unk328;
    unsigned char unk329;
    unsigned char unk32a;
    unsigned char unk32b;
    unsigned char unk32c;
    unsigned char unk32d;
    unsigned char unk32e;
    unsigned char unk32f;
    unsigned char unk330;
    unsigned char unk331;
    unsigned char unk332;
    unsigned char unk333;
    unsigned char unk334;
    unsigned char unk335;
    unsigned char unk336;
    unsigned char unk337;
    unsigned char unk338;
    unsigned char unk339;
    unsigned char unk33a;
    unsigned char unk33b;
    unsigned char unk33c;
    unsigned char unk33d;
    unsigned char unk33e;
    unsigned char unk33f;
    unsigned char unk340;
    unsigned char unk341;
    unsigned char unk342;
    unsigned char unk343;
    unsigned char unk344;
    unsigned char unk345;
    unsigned char unk346;
    unsigned char unk347;
    unsigned char unk348;
    unsigned char unk349;
    unsigned char unk34a;
    unsigned char unk34b;
    unsigned char unk34c;
    unsigned char unk34d;
    unsigned char unk34e;
    unsigned char unk34f;
    unsigned char unk350;
    unsigned char unk351;
    unsigned char unk352;
    unsigned char unk353;
    unsigned char unk354;
    unsigned char unk355;
    unsigned char unk356;
    unsigned char unk357;
    unsigned char unk358;
    unsigned char unk359;
    unsigned char unk35a;
    unsigned char unk35b;
    unsigned char unk35c;
    unsigned char unk35d;
    unsigned char unk35e;
    unsigned char unk35f;
    unsigned char unk360;
    unsigned char unk361;
    unsigned char unk362;
    unsigned char unk363;
    unsigned char unk364;
    unsigned char unk365;
    unsigned char unk366;
    unsigned char unk367;
    unsigned char unk368;
    unsigned char unk369;
    unsigned char unk36a;
    unsigned char unk36b;
    unsigned char unk36c;
    unsigned char unk36d;
    unsigned char unk36e;
    unsigned char unk36f;
    unsigned char unk370;
    unsigned char unk371;
    unsigned char unk372;
    unsigned char unk373;
    unsigned char unk374;
    unsigned char unk375;
    unsigned char unk376;
    unsigned char unk377;
    unsigned char unk378;
    unsigned char unk379;
    unsigned char unk37a;
    unsigned char unk37b;
    unsigned char unk37c;
    unsigned char unk37d;
    unsigned char unk37e;
    unsigned char unk37f;
    unsigned char unk380;
    unsigned char unk381;
    unsigned char unk382;
    unsigned char unk383;
    unsigned char unk384;
    unsigned char unk385;
    unsigned char unk386;
    unsigned char unk387;
    unsigned char unk388;
    unsigned char unk389;
    unsigned char unk38a;
    unsigned char unk38b;
    unsigned char unk38c;
    unsigned char unk38d;
    unsigned char unk38e;
    unsigned char unk38f;
    unsigned char unk390;
    unsigned char unk391;
    unsigned char unk392;
    unsigned char unk393;
    unsigned char unk394;
    unsigned char unk395;
    unsigned char unk396;
    unsigned char unk397;
    unsigned char unk398;
    unsigned char unk399;
    unsigned char unk39a;
    unsigned char unk39b;
    unsigned char unk39c;
    unsigned char unk39d;
    unsigned char unk39e;
    unsigned char unk39f;
    unsigned char unk3a0;
    unsigned char unk3a1;
    unsigned char unk3a2;
    unsigned char unk3a3;
    unsigned char unk3a4;
    unsigned char unk3a5;
    unsigned char unk3a6;
    unsigned char unk3a7;
    unsigned char unk3a8;
    unsigned char unk3a9;
    unsigned char unk3aa;
    unsigned char unk3ab;
    unsigned char unk3ac;
    unsigned char unk3ad;
    unsigned char unk3ae;
    unsigned char unk3af;
    unsigned char unk3b0;
    unsigned char unk3b1;
    unsigned char unk3b2;
    unsigned char unk3b3;
    unsigned char unk3b4;
    unsigned char unk3b5;
    unsigned char unk3b6;
    unsigned char unk3b7;
    unsigned char unk3b8;
    unsigned char unk3b9;
    unsigned char unk3ba;
    unsigned char unk3bb;
    unsigned char unk3bc;
    unsigned char unk3bd;
    unsigned char unk3be;
    unsigned char unk3bf;
    unsigned char unk3c0;
    unsigned char unk3c1;
    unsigned char unk3c2;
    unsigned char unk3c3;
    unsigned char unk3c4;
    unsigned char unk3c5;
    unsigned char unk3c6;
    unsigned char unk3c7;
    unsigned char unk3c8;
    unsigned char unk3c9;
    unsigned char unk3ca;
    unsigned char unk3cb;
    unsigned char unk3cc;
    unsigned char unk3cd;
    unsigned char unk3ce;
    unsigned char unk3cf;
    unsigned char unk3d0;
    unsigned char unk3d1;
    unsigned char unk3d2;
    unsigned char unk3d3;
    unsigned char unk3d4;
    unsigned char unk3d5;
    unsigned char unk3d6;
    unsigned char unk3d7;
    unsigned char unk3d8;
    unsigned char unk3d9;
    unsigned char unk3da;
    unsigned char unk3db;
    unsigned char unk3dc;
    unsigned char unk3dd;
    unsigned char unk3de;
    unsigned char unk3df;
    unsigned char unk3e0;
    unsigned char unk3e1;
    unsigned char unk3e2;
    unsigned char unk3e3;
    unsigned char unk3e4;
    unsigned char unk3e5;
    unsigned char unk3e6;
    unsigned char unk3e7;
    unsigned char unk3e8;
    unsigned char unk3e9;
    unsigned char unk3ea;
    unsigned char unk3eb;
    unsigned char unk3ec;
    unsigned char unk3ed;
    unsigned char unk3ee;
    unsigned char unk3ef;
    unsigned char unk3f0;
    unsigned char unk3f1;
    unsigned char unk3f2;
    unsigned char unk3f3;
    unsigned char unk3f4;
    unsigned char unk3f5;
    unsigned char unk3f6;
    unsigned char unk3f7;
    unsigned char unk3f8;
    unsigned char unk3f9;
    unsigned char unk3fa;
    unsigned char unk3fb;
    unsigned char unk3fc;
    unsigned char unk3fd;
    unsigned char unk3fe;
    unsigned char unk3ff;
    unsigned char unk400;
    unsigned char unk401;
    unsigned char unk402;
    unsigned char unk403;
    unsigned char unk404;
    unsigned char unk405;
    unsigned char unk406;
    unsigned char unk407;
    unsigned char unk408;
    unsigned char unk409;
    unsigned char unk40a;
    unsigned char unk40b;
    unsigned char unk40c;
    unsigned char unk40d;
    unsigned char unk40e;
    unsigned char unk40f;
    unsigned char unk410;
    unsigned char unk411;
    unsigned char unk412;
    unsigned char unk413;
    unsigned char unk414;
    unsigned char unk415;
    unsigned char unk416;
    unsigned char unk417;
    unsigned char unk418;
    unsigned char unk419;
    unsigned char unk41a;
    unsigned char unk41b;
    unsigned char unk41c;
    unsigned char unk41d;
    unsigned char unk41e;
    unsigned char unk41f;
    unsigned char unk420;
    unsigned char unk421;
    unsigned char unk422;
    unsigned char unk423;
    unsigned char unk424;
    unsigned char unk425;
    unsigned char unk426;
    unsigned char unk427;
    unsigned char unk428;
    unsigned char unk429;
    unsigned char unk42a;
    unsigned char unk42b;
    unsigned char unk42c;
    unsigned char unk42d;
    unsigned char unk42e;
    unsigned char unk42f;
    unsigned char unk430;
    unsigned char unk431;
    unsigned char unk432;
    unsigned char unk433;
    unsigned short nextArea;
    unsigned short nextSection;
    unsigned char redExpLevel;
    unsigned char greenExpLevel;
    unsigned char blueExpLevel;
    unsigned char redExpBar;
    unsigned char greenExpBar;
    unsigned char blueExpBar;
    unsigned char unk43e;
    unsigned char unk43f;
    unsigned short nextSpawnPoint;
    unsigned char disableSelectMenu;
    unsigned char inventoryScreen;
    unsigned char event[256];
    unsigned char unk544;
    unsigned char unk545;
    unsigned char unk546;
    unsigned char unk547;
    unsigned char unk548;
    unsigned char unk549;
    unsigned char unk54a;
    unsigned char baronState;
    unsigned char unk54c;
    unsigned char unk54d;
    unsigned char unk54e;
    char unk54f;
    unsigned char unk550;
    unsigned char unk551;
    unsigned char unk552;
    unsigned char unk553;
    unsigned char unk554;
    unsigned char unk555;
    unsigned char unk556;
    unsigned char unk557;
    unsigned char unk558;
    unsigned char unk559;
    unsigned char unk55a;
    unsigned char unk55b;
    unsigned char unk55c;
    unsigned char unk55d;
    unsigned char unk55e;
    unsigned char unk55f;
    unsigned char unk560;
    unsigned char unk561;
    unsigned char unk562;
    unsigned char unk563;
    unsigned char unk564;
    unsigned char unk565;
    unsigned char unk566;
    unsigned char unk567;
    unsigned char unk568;
    unsigned char unk569;
    unsigned char unk56a;
    unsigned char unk56b;
    unsigned char unk56c;
    unsigned char unk56d;
    unsigned char unk56e;
    unsigned char unk56f;
    unsigned char unk570;
    unsigned char unk571;
    unsigned char unk572;
    unsigned char unk573;
    unsigned char unk574;
    unsigned char unk575;
    unsigned char unk576;
    unsigned char unk577;
    unsigned char unk578;
    unsigned char unk579;
    unsigned char unk57a;
    unsigned char unk57b;
    unsigned char unk57c;
    unsigned char unk57d;
    unsigned char unk57e;
    unsigned char unk57f;
    unsigned char unk580;
    unsigned char unk581;
    unsigned char unk582;
    unsigned char unk583;
    unsigned char unk584;
    unsigned char unk585;
    unsigned char unk586;
    unsigned char unk587;
    unsigned char unk588;
    unsigned char unk589;
    unsigned char unk58a;
    unsigned char unk58b;
    unsigned char unk58c;
    unsigned char unk58d;
    unsigned char unk58e;
    unsigned char unk58f;
    unsigned char unk590;
    unsigned char unk591;
    unsigned char unk592;
    unsigned char unk593;
    unsigned char unk594;
    unsigned char unk595;
    unsigned char unk596;
    unsigned char unk597;
    unsigned char unk598;
    unsigned char unk599;
    unsigned char unk59a;
    unsigned char unk59b;
    unsigned char unk59c;
    unsigned char unk59d;
    unsigned char unk59e;
    unsigned char unk59f;
    unsigned char unk5a0;
    unsigned char pipeState;
    unsigned char unk5a2;
    unsigned char unk5a3;
    unsigned char unk5a4;
    unsigned char unk5a5;
    unsigned char unk5a6;
    unsigned char unk5a7;
    unsigned char unk5a8;
    unsigned char unk5a9;
    unsigned char unk5aa;
    unsigned char unk5ab;
    unsigned char unk5ac;
    unsigned char unk5ad;
    unsigned char unk5ae;
    unsigned char unk5af;
    unsigned char unk5b0;
    unsigned char unk5b1;
    unsigned char unk5b2;
    unsigned char unk5b3;
    unsigned char unk5b4;
    unsigned char unk5b5;
    unsigned char unk5b6;
    unsigned char unk5b7;
    unsigned char unk5b8;
    unsigned char unk5b9;
    unsigned char unk5ba;
    unsigned char unk5bb;
    unsigned char unk5bc;
    unsigned char unk5bd;
    unsigned char unk5be;
    unsigned char unk5bf;
    unsigned char unk5c0;
    unsigned char unk5c1;
    unsigned char unk5c2;
    unsigned char unk5c3;
    unsigned char unk5c4;
    unsigned char unk5c5;
    unsigned char unk5c6;
    unsigned char unk5c7;
    unsigned char unk5c8;
    unsigned char unk5c9;
    unsigned char unk5ca;
    unsigned char unk5cb;
    unsigned char unk5cc;
    unsigned char unk5cd;
    unsigned char unk5ce;
    unsigned char unk5cf;
    unsigned char unk5d0;
    unsigned char unk5d1;
    unsigned char unk5d2;
    unsigned char unk5d3;
    unsigned char unk5d4;
    unsigned char unk5d5;
    unsigned char unk5d6;
    unsigned char unk5d7;
    unsigned char unk5d8;
    unsigned char unk5d9;
    unsigned char unk5da;
    unsigned char unk5db;
    unsigned char unk5dc;
    unsigned char unk5dd;
    unsigned char unk5de;
    unsigned char unk5df;
    unsigned char unk5e0;
    unsigned char unk5e1;
    unsigned char unk5e2;
    unsigned char unk5e3;
    unsigned char unk5e4;
    unsigned char unk5e5;
    unsigned char unk5e6;
    unsigned char unk5e7;
    unsigned char unk5e8;
    unsigned char unk5e9;
    unsigned char unk5ea;
    unsigned char unk5eb;
    unsigned char unk5ec;
    unsigned char unk5ed;
    unsigned char unk5ee;
    unsigned char unk5ef;
    unsigned char unk5f0;
    unsigned char unk5f1;
    unsigned char unk5f2;
    unsigned char unk5f3;
    unsigned char unk5f4;
    unsigned char unk5f5;
    unsigned char unk5f6;
    unsigned char unk5f7;
    unsigned char unk5f8;
    unsigned char unk5f9;
    unsigned char unk5fa;
    unsigned char unk5fb;
    unsigned char unk5fc;
    unsigned char unk5fd;
    unsigned char unk5fe;
    unsigned char unk5ff;
    unsigned char unk600;
    unsigned char unk601;
    unsigned char unk602;
    unsigned char unk603;
    unsigned char unk604;
    unsigned char unk605;
    unsigned char unk606;
    unsigned char unk607;
    unsigned char unk608;
    unsigned char unk609;
    unsigned char unk60a;
    unsigned char unk60b;
    unsigned char unk60c;
    unsigned char unk60d;
    unsigned char unk60e;
    unsigned char unk60f;
    unsigned char unk610;
    unsigned char unk611;
    unsigned char unk612;
    unsigned char unk613;
    unsigned char unk614;
    unsigned char unk615;
    unsigned char unk616;
    unsigned char unk617;
    unsigned char unk618;
    unsigned char unk619;
    unsigned char unk61a;
    unsigned char unk61b;
    unsigned char unk61c;
    unsigned char unk61d;
    unsigned char unk61e;
    unsigned char unk61f;
    unsigned char unk620;
    unsigned char unk621;
    unsigned char unk622;
    unsigned char unk623;
    unsigned char unk624;
    unsigned char unk625;
    unsigned char unk626;
    unsigned char unk627;
    unsigned char unk628;
    unsigned char unk629;
    unsigned char unk62a;
    unsigned char unk62b;
    unsigned char unk62c;
    unsigned char unk62d;
    unsigned char unk62e;
    unsigned char unk62f;
    unsigned char unk630;
    unsigned char unk631;
    unsigned char unk632;
    unsigned char unk633;
    unsigned char unk634;
    unsigned char unk635;
    unsigned char unk636;
    unsigned char unk637;
    unsigned char unk638;
    unsigned char unk639;
    unsigned char unk63a;
    unsigned char unk63b;
    unsigned char unk63c;
    unsigned char unk63d;
    unsigned char unk63e;
    unsigned char unk63f;
    unsigned char unk640;
    unsigned char unk641;
    unsigned char unk642;
    unsigned char unk643;
    unsigned char unk644;
    unsigned char unk645;
    unsigned char unk646;
    unsigned char unk647;
    unsigned char unk648;
    unsigned char unk649;
    unsigned char unk64a;
    unsigned char unk64b;
    unsigned char unk64c;
    unsigned char unk64d;
    unsigned char unk64e;
    unsigned char unk64f;
    unsigned char unk650;
    unsigned char unk651;
    unsigned char unk652;
    unsigned char unk653;
    unsigned char unk654;
    unsigned char unk655;
    unsigned char unk656;
    unsigned char unk657;
    unsigned char unk658;
    unsigned char unk659;
    unsigned char unk65a;
    unsigned char unk65b;
    unsigned char unk65c;
    unsigned char unk65d;
    unsigned char unk65e;
    unsigned char unk65f;
    unsigned char unk660;
    unsigned char unk661;
    unsigned char unk662;
    unsigned char unk663;
    unsigned char unk664;
    unsigned char unk665;
    unsigned char unk666;
    unsigned char unk667;
    unsigned char unk668;
    unsigned char unk669;
    unsigned char unk66a;
    unsigned char unk66b;
    unsigned char unk66c;
    unsigned char unk66d;
    unsigned char unk66e;
    unsigned char unk66f;
    short unk670;
    short unk672;
    short unk674;
    unsigned char unk676;
    unsigned char unk677;
    unsigned char unk678;
    unsigned char unk679;
    unsigned char unk67a;
    unsigned char unk67b;
    unsigned char unk67c;
    unsigned char unk67d;
    unsigned char unk67e;
    unsigned char unk67f;
    unsigned char unk680;
    unsigned char unk681;
    unsigned char unk682;
    unsigned char unk683;
    unsigned char goldenFlowerState;
    unsigned char unk685;
    unsigned char unk686;
    unsigned char unk687;
    unsigned char unk688;
    unsigned char unk689;
    unsigned char unk68a;
    unsigned char unk68b;
    unsigned char unk68c;
    unsigned char unk68d;
    unsigned char unk68e;
    unsigned char unk68f;
    unsigned char unk690;
    unsigned char unk691;
    unsigned char unk692;
    unsigned char unk693;
    unsigned char unk694;
    unsigned char unk695;
    unsigned char unk696;
    unsigned char unk697;
    unsigned char unk698;
    unsigned char unk699;
    unsigned char unk69a;
    unsigned char unk69b;
    unsigned char unk69c;
    unsigned char unk69d;
    unsigned char unk69e;
    unsigned char unk69f;
    unsigned char unk6a0;
    unsigned char unk6a1;
    unsigned char unk6a2;
    unsigned char unk6a3;
    unsigned char unk6a4;
    unsigned char unk6a5;
    unsigned char unk6a6;
    unsigned char unk6a7;
    unsigned char unk6a8;
    unsigned char unk6a9;
    unsigned char unk6aa;
    unsigned char unk6ab;
    unsigned char unk6ac;
    unsigned char unk6ad;
    unsigned char unk6ae;
    unsigned char playerIdleState;
    unsigned char unk6b0;
    unsigned char unk6b1;
    unsigned char unk6b2;
    unsigned char unk6b3;
    unsigned char unk6b4;
    unsigned char unk6b5;
    unsigned char unk6b6;
    unsigned char unk6b7;
    unsigned char unk6b8;
    unsigned char unk6b9;
    unsigned char unk6ba;
    unsigned char unk6bb;
    unsigned char unk6bc;
    unsigned char unk6bd;
    unsigned char unk6be;
    unsigned char unk6bf;
    unsigned char unk6c0;
    unsigned char unk6c1;
    unsigned char unk6c2;
    unsigned char unk6c3;
    unsigned char unk6c4;
    unsigned char unk6c5;
    unsigned char unk6c6;
    unsigned char unk6c7;
    unsigned char unk6c8;
    unsigned char unk6c9;
    unsigned char unk6ca;
    unsigned char unk6cb;
    unsigned char unk6cc;
    unsigned char unk6cd;
    unsigned char unk6ce;
    unsigned char unk6cf;
    unsigned char unk6d0;
    unsigned char unk6d1;
    unsigned char unk6d2;
    unsigned char unk6d3;
    unsigned char unk6d4;
    unsigned char unk6d5;
    unsigned char unk6d6;
    unsigned char unk6d7;
    unsigned char unk6d8;
    unsigned char unk6d9;
    unsigned char unk6da;
    unsigned char unk6db;
    unsigned char unk6dc;
    unsigned char unk6dd;
    unsigned char unk6de;
    unsigned char unk6df;
    unsigned char unk6e0;
    unsigned char unk6e1;
    unsigned char unk6e2;
    unsigned char unk6e3;
    unsigned char unk6e4;
    unsigned char unk6e5;
    unsigned char unk6e6;
    unsigned char unk6e7;
    unsigned char unk6e8;
    unsigned char unk6e9;
    unsigned char unk6ea;
    unsigned char unk6eb;
    unsigned char unk6ec;
    unsigned char unk6ed;
    unsigned char unk6ee;
    unsigned char unk6ef;
    unsigned char unk6f0;
    unsigned char unk6f1;
    unsigned char unk6f2;
    unsigned char unk6f3;
    unsigned char unk6f4;
    unsigned char unk6f5;
    unsigned char unk6f6;
    unsigned char unk6f7;
    unsigned char unk6f8;
    unsigned char unk6f9;
    unsigned char unk6fa;
    unsigned char unk6fb;
    unsigned char unk6fc;
    unsigned char unk6fd;
    unsigned char unk6fe;
    unsigned char unk6ff;
    unsigned char unk700;
    unsigned char unk701;
    unsigned char unk702;
    unsigned char unk703;
    unsigned char unk704;
    unsigned char unk705;
    unsigned char unk706;
    unsigned char unk707;
    unsigned char unk708;
    unsigned char unk709;
    unsigned char unk70a;
    unsigned char unk70b;
    unsigned char unk70c;
    unsigned char unk70d;
    unsigned char unk70e;
    unsigned char unk70f;
    unsigned char unk710;
    unsigned char unk711;
    unsigned char unk712;
    unsigned char unk713;
    unsigned char unk714;
    unsigned char unk715;
    unsigned char unk716;
    unsigned char unk717;
    unsigned char unk718;
    unsigned char unk719;
    unsigned char unk71a;
    unsigned char bittingPlantFlowerState;
    unsigned char unk71c;
    unsigned char unk71d;
    unsigned char unk71e;
    unsigned char goldenBowlState;
    unsigned char bonusHealth;
    unsigned char unk721;
    unsigned char unk722;
    unsigned char unk723;
    unsigned char unk724;
    unsigned char unk725;
    unsigned char unk726;
    unsigned char unk727;
    unsigned char unk728;
    unsigned char unk729;
    unsigned char unk72a;
    unsigned char unk72b;
    unsigned char unk72c;
    unsigned char unk72d;
    unsigned char unk72e;
    unsigned char unk72f;
    unsigned char unk730;
    unsigned char unk731;
    unsigned char unk732;
    unsigned char unk733;
    unsigned char unk734;
    unsigned char unk735;
    char unk736;
    unsigned char unk737;
    unsigned char unk738;
    unsigned char unk739;
    unsigned char unk73a;
    unsigned char unk73b;
    unsigned char unk73c;
    unsigned char unk73d;
    unsigned char unk73e;
    unsigned char unk73f;
    unsigned char unk740;
    unsigned char unk741;
    unsigned char unk742;
    unsigned char unk743;
    unsigned char item[256];
    struct GSInventory_29C68 inventory;
    unsigned short currentArea;
    unsigned short currentSection;
    unsigned short currentSpawnPoint;
    unsigned char inventoryButton;
    unsigned char playerState;
    struct GSEquips_29C68 playerEquips;
    unsigned char unk952;
    unsigned char unk953;
    unsigned char unk954;
    unsigned char unk955;
    unsigned char unk956;
    unsigned char unk957;
    unsigned char unk958;
    unsigned char unk959;
    unsigned char unk95a;
    unsigned char unk95b;
    unsigned char unk95c;
    unsigned char unk95d;
    unsigned char unk95e;
    unsigned char unk95f;
    unsigned char unk960;
    unsigned char unk961;
    unsigned char unk962;
    unsigned char purifiedAreas;
    unsigned char unk964;
    unsigned char unk965;
    unsigned char unk966;
    unsigned char unk967;
    unsigned char unk968;
    unsigned char unk969;
    unsigned char unk96a;
    unsigned char unk96b;
    unsigned char unk96c;
    unsigned char unk96d;
    unsigned char unk96e;
    unsigned char unk96f;
    unsigned char unk970;
    unsigned char unk971;
    unsigned char unk972;
    unsigned char unk973;
    unsigned char unk974;
    unsigned char unk975;
    unsigned char unk976;
    unsigned char unk977;
    unsigned char unk978;
    unsigned char unk979;
    unsigned char unk97a;
    unsigned char unk97b;
    unsigned char unk97c;
    unsigned char unk97d;
    unsigned char unk97e;
    unsigned char unk97f;
    unsigned char unk980;
    unsigned char unk981;
    unsigned char unk982;
    unsigned char unk983;
    unsigned char unk984;
} GameState_29C68;
extern GameState_29C68 GAME__8002C7D8_2;

typedef struct { unsigned char b0; char p0[0x15]; short w16; char p1[0x16]; unsigned short w2e; char p2[0x79]; unsigned char ba9; } S_29C68;
typedef struct { short w0; short w2; } P_29C68;
typedef struct {
    char p0[0x24]; int d24; char p1[8]; short w30; short w32; P_29C68 *d34; P_29C68 *d38;
    unsigned char b3c; unsigned char b3d; char p2[0x1a]; unsigned short w58;
} O_29C68;
extern S_29C68 PLAYER__8002C7D8;
extern P_29C68 *D_800A53D8__8002C7D8;
extern P_29C68 *D_800A53DC__8002C7D8;
extern unsigned short GAME__8002C7D8;
extern unsigned char D_800A5436__8002C7D8;
extern void func_8002A798__8002C7D8(O_29C68 *);
extern void func_8002A480__8002C7D8(O_29C68 *);
extern void func_8002B704__8002C7D8(O_29C68 *);
extern void func_8002BB9C__8002C7D8(O_29C68 *);

static __inline__ void Clamp_29C68(O_29C68 *o)
{
    S_29C68 *s = &PLAYER__8002C7D8;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        unsigned short x = o->d34->w2;
        short t;
        t = x - 0x90;
        if (D_800A53D8__8002C7D8->w2 < t) {
            D_800A53D8__8002C7D8->w2 = t;
        } else {
            t = x + 0x90;
            if (t < D_800A53D8__8002C7D8->w2)
                D_800A53D8__8002C7D8->w2 = t;
        }
        if ((*(int*)&GAME__8002C7D8_2.selectedArea) == 0x2000E) {
            if (s->w16 < o->w30 - 0x5c)
                s->w16 = o->w30 - 0x5c;
        } else {
            if (s->w16 < o->w30 - 0x90)
                s->w16 = o->w30 - 0x90;
        }
    }
}

void func_8002C7D8(O_29C68 *o)
{
    S_29C68 *s = &PLAYER__8002C7D8;
    int t;
    if (D_8009BC98__8002C7D8.b39 == 0) {
        switch (D_800A5436__8002C7D8) {
        case 4:
            if (GAME__8002C7D8 != 10 && s->ba9 == 0)
                goto c4;
        case 0: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            func_8002A798__8002C7D8(o);
            func_8002A480__8002C7D8(o);
            o->b3d = 0;
            o->b3c = 0;
            break;
        c4:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798__8002C7D8(o);
            func_8002A480__8002C7D8(o);
            o->b3d = 0;
            break;
        case 3:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
            }
            func_8002A798__8002C7D8(o);
            if (o->b3d == 0)
                func_8002A480__8002C7D8(o);
            break;
        case 1: case 2: case 5:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798__8002C7D8(o);
            if (o->b3d == 0)
                func_8002A480__8002C7D8(o);
            break;
        }
        o->d38->w2 = D_800A53DC__8002C7D8->w2;
    }
    func_8002B704__8002C7D8(o);
    func_8002BB9C__8002C7D8(o);
    SCRATCHPAD__8002C7D8.s286 = -o->d24 >> 6;
    Clamp_29C68(o);
}
#elif defined(VERSION_SCES_01331)
typedef struct SPADBlock_29CB4 {
    unsigned char b0;
    unsigned char _pad1[0x5f];
    short s60;
    short s62;
    short s64;
    unsigned char _pad66[0xe];
    int i74;
    int i78;
    unsigned char _pad7c[0x10];
    int i8c;
    unsigned char _pad90[0x30];
    unsigned char bc0;
    unsigned char _padc1[0x13];
    int id4;
    int id8;
    int idc;
    int ie0;
    unsigned char _pade4[0x2];
    short se6;
    unsigned char _pade8[0x2];
    short sea;
    int iec;
    int if0;
    int if4;
    unsigned char _padf8[0x20];
    unsigned char b118;
    unsigned char _pad119[0x4b];
    void * p164;
    int i168;
    int i16c;
    int i170;
    int i174;
    unsigned char _pad178[0x2];
    unsigned short s17a;
    unsigned char _pad17c[0x2];
    unsigned short s17e;
    unsigned char _pad180[0x6];
    unsigned short s186;
    unsigned char _pad188[0x4];
    int i18c;
    int i190;
    unsigned char _pad194[0x4];
    int i198;
    short s19c;
    short s19e;
    unsigned char b1a0;
    unsigned char _pad1a1[0x3];
    unsigned char b1a4;
    unsigned char b1a5;
    unsigned char _pad1a6[0x1c];
    unsigned char b1c2;
    unsigned char _pad1c3[0x1];
    unsigned char b1c4;
    unsigned char b1c5;
    short s1c6;
    unsigned short s1c8;
    unsigned char _pad1ca[0x2];
    unsigned char b1cc;
    unsigned char b1cd;
    unsigned char _pad1ce[0x1];
    unsigned char b1cf;
    unsigned char b1d0;
    unsigned char b1d1;
    unsigned char b1d2;
    unsigned char b1d3;
    unsigned char _pad1d4[0xc];
    int i1e0;
    unsigned char _pad1e4[0x4];
    short s1e8;
    unsigned char _pad1ea[0xa];
    short s1f4;
    short s1f6;
    unsigned short s1f8;
    unsigned char _pad1fa[0x2];
    unsigned short s1fc;
    unsigned short s1fe;
    unsigned char _pad200[0x1c];
    void * p21c;
    unsigned char _pad220[0x4];
    void * p224;
    void * p228;
    unsigned char _pad22c[0xc];
    short s238;
    unsigned char _pad23a[0xc];
    short s246;
    unsigned short s248;
    unsigned char _pad24a[0x2];
    short s24c;
    unsigned char _pad24e[0x2];
    unsigned short s250;
    unsigned char _pad252[0x2];
    unsigned short s254;
    short s256;
    unsigned char _pad258[0x8];
    void * p260;
    unsigned char _pad264[0x4];
    void * p268;
    void * p26c;
    unsigned char _pad270[0x8];
    void * p278;
    unsigned char _pad27c[0x2];
    short s27e;
    short s280;
    unsigned short s282;
    short s284;
    short s286;
    unsigned char _pad288[0x2c];
    int i2b4;
    unsigned char _pad2b8[0x18];
    int i2d0;
    int i2d4;
    int i2d8;
    int i2dc;
    int i2e0;
    int i2e4;
    int i2e8;
    unsigned char _pad2ec[0x4];
    int i2f0;
    unsigned char _pad2f4[0x4];
    int i2f8;
    unsigned char _pad2fc[0x4];
    int i300;
    int i304;
    void * p308;
    void * p30c;
    int i310;
    int i314;
    int i318;
    void * p31c;
    unsigned char _pad320[0x14];
    int i334;
    void * p338;
    void * p33c;
    unsigned char _pad340[0x1c];
    int i35c;
    unsigned char _pad360[0x10];
    int i370;
    int i374;
    int i378;
    unsigned char _pad37c[0x3c];
    unsigned short s3b8;
    unsigned short s3ba;
    short s3bc;
    unsigned char _pad3be[0x2];
    void * p3c0;
    unsigned short s3c4;
    unsigned short s3c6;
    unsigned short s3c8;
    unsigned char _pad3ca[0x4];
    unsigned char b3ce;
    unsigned char _pad3cf[0x1];
    unsigned char b3d0;
    unsigned char b3d1;
    unsigned char _pad3d2[0x2e];
} SPADBlock_29CB4;
extern SPADBlock_29CB4 SCRATCHPAD__8002C7D8;

typedef struct GVars_29CB4 {
    unsigned char b30;
    unsigned char _pad31[3];
    int i34;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    unsigned char b3b;
    unsigned char b3c;
    unsigned char b3d;
    unsigned char b3e;
    unsigned char b3f;
    unsigned char b40;
    unsigned char b41;
    unsigned char b42;
    unsigned char b43;
    short s44;
    short s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    unsigned char b58;
    unsigned char b59;
    unsigned char _pad5a[2];
    int i5c;
} GVars_29CB4;
extern GVars_29CB4 D_8009BC98__8002C7D8;

struct GSInventory_29CB4 { unsigned char slots[256]; unsigned short counter; unsigned short sortMode; };
struct GSEquips_29CB4 { unsigned char weapon; unsigned char pants; };
typedef struct GameState_29CB4 {
    unsigned short selectedArea;
    unsigned short selectedSection;
    unsigned char selectedPlane;
    unsigned char area00_fogControl;
    unsigned char unk6;
    unsigned char keepBgm;
    int totalTimePlayed;
    unsigned long playerAP;
    unsigned char playerHealth;
    unsigned char playerHealthDisplayed;
    char unk12;
    char unk13;
    unsigned char areaTransition;
    unsigned char fadeScreenControl;
    unsigned char fadeScreenAmount;
    unsigned char saveSlot;
    unsigned char unk18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    unsigned char unk1c;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    unsigned char playerLives;
    unsigned char unk21;
    unsigned short selectedSpawnPoint;
    int area00_eventControl;
    unsigned char unk28;
    unsigned char unk29;
    unsigned char unk2a;
    unsigned char unk2b;
    unsigned char unk2c;
    unsigned char unk2d;
    unsigned char unk2e;
    unsigned char unk2f;
    unsigned char displayExpBar;
    unsigned char unk31;
    unsigned char unk32;
    unsigned char unk33;
    unsigned char area00_pickedItems[32];
    unsigned char area01_pickedItems[32];
    unsigned char area02_pickedItems[32];
    unsigned char area03_pickedItems[32];
    unsigned char area04_pickedItems[32];
    unsigned char area05_pickedItems[32];
    unsigned char area06_pickedItems[32];
    unsigned char area07_pickedItems[32];
    unsigned char area08_pickedItems[32];
    unsigned char area09_pickedItems[32];
    unsigned char area10_pickedItems[32];
    unsigned char area11_pickedItems[32];
    unsigned char area12_pickedItems[32];
    unsigned char area13_pickedItems[32];
    unsigned char area14_pickedItems[32];
    unsigned char area15_pickedItems[32];
    unsigned char area16_pickedItems[32];
    unsigned char area17_pickedItems[32];
    unsigned char area18_pickedItems[32];
    unsigned char area19_pickedItems[32];
    unsigned char unk2b4;
    unsigned char unk2b5;
    unsigned char unk2b6;
    unsigned char unk2b7;
    unsigned char unk2b8;
    unsigned char unk2b9;
    unsigned char unk2ba;
    unsigned char unk2bb;
    unsigned char unk2bc;
    unsigned char unk2bd;
    unsigned char unk2be;
    unsigned char unk2bf;
    unsigned char unk2c0;
    unsigned char unk2c1;
    unsigned char unk2c2;
    unsigned char unk2c3;
    unsigned char unk2c4;
    unsigned char unk2c5;
    unsigned char unk2c6;
    unsigned char unk2c7;
    unsigned char unk2c8;
    unsigned char unk2c9;
    unsigned char unk2ca;
    unsigned char unk2cb;
    unsigned char unk2cc;
    unsigned char unk2cd;
    unsigned char unk2ce;
    unsigned char unk2cf;
    unsigned char unk2d0;
    unsigned char unk2d1;
    unsigned char unk2d2;
    unsigned char unk2d3;
    unsigned char unk2d4;
    unsigned char unk2d5;
    unsigned char unk2d6;
    unsigned char unk2d7;
    unsigned char unk2d8;
    unsigned char unk2d9;
    unsigned char unk2da;
    unsigned char unk2db;
    unsigned char unk2dc;
    unsigned char unk2dd;
    unsigned char unk2de;
    unsigned char unk2df;
    unsigned char unk2e0;
    unsigned char unk2e1;
    unsigned char unk2e2;
    unsigned char unk2e3;
    unsigned char unk2e4;
    unsigned char unk2e5;
    unsigned char unk2e6;
    unsigned char unk2e7;
    unsigned char unk2e8;
    unsigned char unk2e9;
    unsigned char unk2ea;
    unsigned char unk2eb;
    unsigned char unk2ec;
    unsigned char unk2ed;
    unsigned char unk2ee;
    unsigned char unk2ef;
    unsigned char unk2f0;
    unsigned char unk2f1;
    unsigned char unk2f2;
    unsigned char unk2f3;
    unsigned char unk2f4;
    unsigned char unk2f5;
    unsigned char unk2f6;
    unsigned char unk2f7;
    unsigned char unk2f8;
    unsigned char unk2f9;
    unsigned char unk2fa;
    unsigned char unk2fb;
    unsigned char unk2fc;
    unsigned char unk2fd;
    unsigned char unk2fe;
    unsigned char unk2ff;
    unsigned char unk300;
    unsigned char unk301;
    unsigned char unk302;
    unsigned char unk303;
    unsigned char unk304;
    unsigned char unk305;
    unsigned char unk306;
    unsigned char unk307;
    unsigned char unk308;
    unsigned char unk309;
    unsigned char unk30a;
    unsigned char unk30b;
    unsigned char unk30c;
    unsigned char unk30d;
    unsigned char unk30e;
    unsigned char unk30f;
    unsigned char unk310;
    unsigned char unk311;
    unsigned char unk312;
    unsigned char unk313;
    unsigned char unk314;
    unsigned char unk315;
    unsigned char unk316;
    unsigned char unk317;
    unsigned char unk318;
    unsigned char unk319;
    unsigned char unk31a;
    unsigned char unk31b;
    unsigned char unk31c;
    unsigned char unk31d;
    unsigned char unk31e;
    unsigned char unk31f;
    unsigned char unk320;
    unsigned char unk321;
    unsigned char unk322;
    unsigned char unk323;
    unsigned char unk324;
    unsigned char unk325;
    unsigned char unk326;
    unsigned char unk327;
    unsigned char unk328;
    unsigned char unk329;
    unsigned char unk32a;
    unsigned char unk32b;
    unsigned char unk32c;
    unsigned char unk32d;
    unsigned char unk32e;
    unsigned char unk32f;
    unsigned char unk330;
    unsigned char unk331;
    unsigned char unk332;
    unsigned char unk333;
    unsigned char unk334;
    unsigned char unk335;
    unsigned char unk336;
    unsigned char unk337;
    unsigned char unk338;
    unsigned char unk339;
    unsigned char unk33a;
    unsigned char unk33b;
    unsigned char unk33c;
    unsigned char unk33d;
    unsigned char unk33e;
    unsigned char unk33f;
    unsigned char unk340;
    unsigned char unk341;
    unsigned char unk342;
    unsigned char unk343;
    unsigned char unk344;
    unsigned char unk345;
    unsigned char unk346;
    unsigned char unk347;
    unsigned char unk348;
    unsigned char unk349;
    unsigned char unk34a;
    unsigned char unk34b;
    unsigned char unk34c;
    unsigned char unk34d;
    unsigned char unk34e;
    unsigned char unk34f;
    unsigned char unk350;
    unsigned char unk351;
    unsigned char unk352;
    unsigned char unk353;
    unsigned char unk354;
    unsigned char unk355;
    unsigned char unk356;
    unsigned char unk357;
    unsigned char unk358;
    unsigned char unk359;
    unsigned char unk35a;
    unsigned char unk35b;
    unsigned char unk35c;
    unsigned char unk35d;
    unsigned char unk35e;
    unsigned char unk35f;
    unsigned char unk360;
    unsigned char unk361;
    unsigned char unk362;
    unsigned char unk363;
    unsigned char unk364;
    unsigned char unk365;
    unsigned char unk366;
    unsigned char unk367;
    unsigned char unk368;
    unsigned char unk369;
    unsigned char unk36a;
    unsigned char unk36b;
    unsigned char unk36c;
    unsigned char unk36d;
    unsigned char unk36e;
    unsigned char unk36f;
    unsigned char unk370;
    unsigned char unk371;
    unsigned char unk372;
    unsigned char unk373;
    unsigned char unk374;
    unsigned char unk375;
    unsigned char unk376;
    unsigned char unk377;
    unsigned char unk378;
    unsigned char unk379;
    unsigned char unk37a;
    unsigned char unk37b;
    unsigned char unk37c;
    unsigned char unk37d;
    unsigned char unk37e;
    unsigned char unk37f;
    unsigned char unk380;
    unsigned char unk381;
    unsigned char unk382;
    unsigned char unk383;
    unsigned char unk384;
    unsigned char unk385;
    unsigned char unk386;
    unsigned char unk387;
    unsigned char unk388;
    unsigned char unk389;
    unsigned char unk38a;
    unsigned char unk38b;
    unsigned char unk38c;
    unsigned char unk38d;
    unsigned char unk38e;
    unsigned char unk38f;
    unsigned char unk390;
    unsigned char unk391;
    unsigned char unk392;
    unsigned char unk393;
    unsigned char unk394;
    unsigned char unk395;
    unsigned char unk396;
    unsigned char unk397;
    unsigned char unk398;
    unsigned char unk399;
    unsigned char unk39a;
    unsigned char unk39b;
    unsigned char unk39c;
    unsigned char unk39d;
    unsigned char unk39e;
    unsigned char unk39f;
    unsigned char unk3a0;
    unsigned char unk3a1;
    unsigned char unk3a2;
    unsigned char unk3a3;
    unsigned char unk3a4;
    unsigned char unk3a5;
    unsigned char unk3a6;
    unsigned char unk3a7;
    unsigned char unk3a8;
    unsigned char unk3a9;
    unsigned char unk3aa;
    unsigned char unk3ab;
    unsigned char unk3ac;
    unsigned char unk3ad;
    unsigned char unk3ae;
    unsigned char unk3af;
    unsigned char unk3b0;
    unsigned char unk3b1;
    unsigned char unk3b2;
    unsigned char unk3b3;
    unsigned char unk3b4;
    unsigned char unk3b5;
    unsigned char unk3b6;
    unsigned char unk3b7;
    unsigned char unk3b8;
    unsigned char unk3b9;
    unsigned char unk3ba;
    unsigned char unk3bb;
    unsigned char unk3bc;
    unsigned char unk3bd;
    unsigned char unk3be;
    unsigned char unk3bf;
    unsigned char unk3c0;
    unsigned char unk3c1;
    unsigned char unk3c2;
    unsigned char unk3c3;
    unsigned char unk3c4;
    unsigned char unk3c5;
    unsigned char unk3c6;
    unsigned char unk3c7;
    unsigned char unk3c8;
    unsigned char unk3c9;
    unsigned char unk3ca;
    unsigned char unk3cb;
    unsigned char unk3cc;
    unsigned char unk3cd;
    unsigned char unk3ce;
    unsigned char unk3cf;
    unsigned char unk3d0;
    unsigned char unk3d1;
    unsigned char unk3d2;
    unsigned char unk3d3;
    unsigned char unk3d4;
    unsigned char unk3d5;
    unsigned char unk3d6;
    unsigned char unk3d7;
    unsigned char unk3d8;
    unsigned char unk3d9;
    unsigned char unk3da;
    unsigned char unk3db;
    unsigned char unk3dc;
    unsigned char unk3dd;
    unsigned char unk3de;
    unsigned char unk3df;
    unsigned char unk3e0;
    unsigned char unk3e1;
    unsigned char unk3e2;
    unsigned char unk3e3;
    unsigned char unk3e4;
    unsigned char unk3e5;
    unsigned char unk3e6;
    unsigned char unk3e7;
    unsigned char unk3e8;
    unsigned char unk3e9;
    unsigned char unk3ea;
    unsigned char unk3eb;
    unsigned char unk3ec;
    unsigned char unk3ed;
    unsigned char unk3ee;
    unsigned char unk3ef;
    unsigned char unk3f0;
    unsigned char unk3f1;
    unsigned char unk3f2;
    unsigned char unk3f3;
    unsigned char unk3f4;
    unsigned char unk3f5;
    unsigned char unk3f6;
    unsigned char unk3f7;
    unsigned char unk3f8;
    unsigned char unk3f9;
    unsigned char unk3fa;
    unsigned char unk3fb;
    unsigned char unk3fc;
    unsigned char unk3fd;
    unsigned char unk3fe;
    unsigned char unk3ff;
    unsigned char unk400;
    unsigned char unk401;
    unsigned char unk402;
    unsigned char unk403;
    unsigned char unk404;
    unsigned char unk405;
    unsigned char unk406;
    unsigned char unk407;
    unsigned char unk408;
    unsigned char unk409;
    unsigned char unk40a;
    unsigned char unk40b;
    unsigned char unk40c;
    unsigned char unk40d;
    unsigned char unk40e;
    unsigned char unk40f;
    unsigned char unk410;
    unsigned char unk411;
    unsigned char unk412;
    unsigned char unk413;
    unsigned char unk414;
    unsigned char unk415;
    unsigned char unk416;
    unsigned char unk417;
    unsigned char unk418;
    unsigned char unk419;
    unsigned char unk41a;
    unsigned char unk41b;
    unsigned char unk41c;
    unsigned char unk41d;
    unsigned char unk41e;
    unsigned char unk41f;
    unsigned char unk420;
    unsigned char unk421;
    unsigned char unk422;
    unsigned char unk423;
    unsigned char unk424;
    unsigned char unk425;
    unsigned char unk426;
    unsigned char unk427;
    unsigned char unk428;
    unsigned char unk429;
    unsigned char unk42a;
    unsigned char unk42b;
    unsigned char unk42c;
    unsigned char unk42d;
    unsigned char unk42e;
    unsigned char unk42f;
    unsigned char unk430;
    unsigned char unk431;
    unsigned char unk432;
    unsigned char unk433;
    unsigned short nextArea;
    unsigned short nextSection;
    unsigned char redExpLevel;
    unsigned char greenExpLevel;
    unsigned char blueExpLevel;
    unsigned char redExpBar;
    unsigned char greenExpBar;
    unsigned char blueExpBar;
    unsigned char unk43e;
    unsigned char unk43f;
    unsigned short nextSpawnPoint;
    unsigned char disableSelectMenu;
    unsigned char inventoryScreen;
    unsigned char event[256];
    unsigned char unk544;
    unsigned char unk545;
    unsigned char unk546;
    unsigned char unk547;
    unsigned char unk548;
    unsigned char unk549;
    unsigned char unk54a;
    unsigned char baronState;
    unsigned char unk54c;
    unsigned char unk54d;
    unsigned char unk54e;
    char unk54f;
    unsigned char unk550;
    unsigned char unk551;
    unsigned char unk552;
    unsigned char unk553;
    unsigned char unk554;
    unsigned char unk555;
    unsigned char unk556;
    unsigned char unk557;
    unsigned char unk558;
    unsigned char unk559;
    unsigned char unk55a;
    unsigned char unk55b;
    unsigned char unk55c;
    unsigned char unk55d;
    unsigned char unk55e;
    unsigned char unk55f;
    unsigned char unk560;
    unsigned char unk561;
    unsigned char unk562;
    unsigned char unk563;
    unsigned char unk564;
    unsigned char unk565;
    unsigned char unk566;
    unsigned char unk567;
    unsigned char unk568;
    unsigned char unk569;
    unsigned char unk56a;
    unsigned char unk56b;
    unsigned char unk56c;
    unsigned char unk56d;
    unsigned char unk56e;
    unsigned char unk56f;
    unsigned char unk570;
    unsigned char unk571;
    unsigned char unk572;
    unsigned char unk573;
    unsigned char unk574;
    unsigned char unk575;
    unsigned char unk576;
    unsigned char unk577;
    unsigned char unk578;
    unsigned char unk579;
    unsigned char unk57a;
    unsigned char unk57b;
    unsigned char unk57c;
    unsigned char unk57d;
    unsigned char unk57e;
    unsigned char unk57f;
    unsigned char unk580;
    unsigned char unk581;
    unsigned char unk582;
    unsigned char unk583;
    unsigned char unk584;
    unsigned char unk585;
    unsigned char unk586;
    unsigned char unk587;
    unsigned char unk588;
    unsigned char unk589;
    unsigned char unk58a;
    unsigned char unk58b;
    unsigned char unk58c;
    unsigned char unk58d;
    unsigned char unk58e;
    unsigned char unk58f;
    unsigned char unk590;
    unsigned char unk591;
    unsigned char unk592;
    unsigned char unk593;
    unsigned char unk594;
    unsigned char unk595;
    unsigned char unk596;
    unsigned char unk597;
    unsigned char unk598;
    unsigned char unk599;
    unsigned char unk59a;
    unsigned char unk59b;
    unsigned char unk59c;
    unsigned char unk59d;
    unsigned char unk59e;
    unsigned char unk59f;
    unsigned char unk5a0;
    unsigned char pipeState;
    unsigned char unk5a2;
    unsigned char unk5a3;
    unsigned char unk5a4;
    unsigned char unk5a5;
    unsigned char unk5a6;
    unsigned char unk5a7;
    unsigned char unk5a8;
    unsigned char unk5a9;
    unsigned char unk5aa;
    unsigned char unk5ab;
    unsigned char unk5ac;
    unsigned char unk5ad;
    unsigned char unk5ae;
    unsigned char unk5af;
    unsigned char unk5b0;
    unsigned char unk5b1;
    unsigned char unk5b2;
    unsigned char unk5b3;
    unsigned char unk5b4;
    unsigned char unk5b5;
    unsigned char unk5b6;
    unsigned char unk5b7;
    unsigned char unk5b8;
    unsigned char unk5b9;
    unsigned char unk5ba;
    unsigned char unk5bb;
    unsigned char unk5bc;
    unsigned char unk5bd;
    unsigned char unk5be;
    unsigned char unk5bf;
    unsigned char unk5c0;
    unsigned char unk5c1;
    unsigned char unk5c2;
    unsigned char unk5c3;
    unsigned char unk5c4;
    unsigned char unk5c5;
    unsigned char unk5c6;
    unsigned char unk5c7;
    unsigned char unk5c8;
    unsigned char unk5c9;
    unsigned char unk5ca;
    unsigned char unk5cb;
    unsigned char unk5cc;
    unsigned char unk5cd;
    unsigned char unk5ce;
    unsigned char unk5cf;
    unsigned char unk5d0;
    unsigned char unk5d1;
    unsigned char unk5d2;
    unsigned char unk5d3;
    unsigned char unk5d4;
    unsigned char unk5d5;
    unsigned char unk5d6;
    unsigned char unk5d7;
    unsigned char unk5d8;
    unsigned char unk5d9;
    unsigned char unk5da;
    unsigned char unk5db;
    unsigned char unk5dc;
    unsigned char unk5dd;
    unsigned char unk5de;
    unsigned char unk5df;
    unsigned char unk5e0;
    unsigned char unk5e1;
    unsigned char unk5e2;
    unsigned char unk5e3;
    unsigned char unk5e4;
    unsigned char unk5e5;
    unsigned char unk5e6;
    unsigned char unk5e7;
    unsigned char unk5e8;
    unsigned char unk5e9;
    unsigned char unk5ea;
    unsigned char unk5eb;
    unsigned char unk5ec;
    unsigned char unk5ed;
    unsigned char unk5ee;
    unsigned char unk5ef;
    unsigned char unk5f0;
    unsigned char unk5f1;
    unsigned char unk5f2;
    unsigned char unk5f3;
    unsigned char unk5f4;
    unsigned char unk5f5;
    unsigned char unk5f6;
    unsigned char unk5f7;
    unsigned char unk5f8;
    unsigned char unk5f9;
    unsigned char unk5fa;
    unsigned char unk5fb;
    unsigned char unk5fc;
    unsigned char unk5fd;
    unsigned char unk5fe;
    unsigned char unk5ff;
    unsigned char unk600;
    unsigned char unk601;
    unsigned char unk602;
    unsigned char unk603;
    unsigned char unk604;
    unsigned char unk605;
    unsigned char unk606;
    unsigned char unk607;
    unsigned char unk608;
    unsigned char unk609;
    unsigned char unk60a;
    unsigned char unk60b;
    unsigned char unk60c;
    unsigned char unk60d;
    unsigned char unk60e;
    unsigned char unk60f;
    unsigned char unk610;
    unsigned char unk611;
    unsigned char unk612;
    unsigned char unk613;
    unsigned char unk614;
    unsigned char unk615;
    unsigned char unk616;
    unsigned char unk617;
    unsigned char unk618;
    unsigned char unk619;
    unsigned char unk61a;
    unsigned char unk61b;
    unsigned char unk61c;
    unsigned char unk61d;
    unsigned char unk61e;
    unsigned char unk61f;
    unsigned char unk620;
    unsigned char unk621;
    unsigned char unk622;
    unsigned char unk623;
    unsigned char unk624;
    unsigned char unk625;
    unsigned char unk626;
    unsigned char unk627;
    unsigned char unk628;
    unsigned char unk629;
    unsigned char unk62a;
    unsigned char unk62b;
    unsigned char unk62c;
    unsigned char unk62d;
    unsigned char unk62e;
    unsigned char unk62f;
    unsigned char unk630;
    unsigned char unk631;
    unsigned char unk632;
    unsigned char unk633;
    unsigned char unk634;
    unsigned char unk635;
    unsigned char unk636;
    unsigned char unk637;
    unsigned char unk638;
    unsigned char unk639;
    unsigned char unk63a;
    unsigned char unk63b;
    unsigned char unk63c;
    unsigned char unk63d;
    unsigned char unk63e;
    unsigned char unk63f;
    unsigned char unk640;
    unsigned char unk641;
    unsigned char unk642;
    unsigned char unk643;
    unsigned char unk644;
    unsigned char unk645;
    unsigned char unk646;
    unsigned char unk647;
    unsigned char unk648;
    unsigned char unk649;
    unsigned char unk64a;
    unsigned char unk64b;
    unsigned char unk64c;
    unsigned char unk64d;
    unsigned char unk64e;
    unsigned char unk64f;
    unsigned char unk650;
    unsigned char unk651;
    unsigned char unk652;
    unsigned char unk653;
    unsigned char unk654;
    unsigned char unk655;
    unsigned char unk656;
    unsigned char unk657;
    unsigned char unk658;
    unsigned char unk659;
    unsigned char unk65a;
    unsigned char unk65b;
    unsigned char unk65c;
    unsigned char unk65d;
    unsigned char unk65e;
    unsigned char unk65f;
    unsigned char unk660;
    unsigned char unk661;
    unsigned char unk662;
    unsigned char unk663;
    unsigned char unk664;
    unsigned char unk665;
    unsigned char unk666;
    unsigned char unk667;
    unsigned char unk668;
    unsigned char unk669;
    unsigned char unk66a;
    unsigned char unk66b;
    unsigned char unk66c;
    unsigned char unk66d;
    unsigned char unk66e;
    unsigned char unk66f;
    short unk670;
    short unk672;
    short unk674;
    unsigned char unk676;
    unsigned char unk677;
    unsigned char unk678;
    unsigned char unk679;
    unsigned char unk67a;
    unsigned char unk67b;
    unsigned char unk67c;
    unsigned char unk67d;
    unsigned char unk67e;
    unsigned char unk67f;
    unsigned char unk680;
    unsigned char unk681;
    unsigned char unk682;
    unsigned char unk683;
    unsigned char goldenFlowerState;
    unsigned char unk685;
    unsigned char unk686;
    unsigned char unk687;
    unsigned char unk688;
    unsigned char unk689;
    unsigned char unk68a;
    unsigned char unk68b;
    unsigned char unk68c;
    unsigned char unk68d;
    unsigned char unk68e;
    unsigned char unk68f;
    unsigned char unk690;
    unsigned char unk691;
    unsigned char unk692;
    unsigned char unk693;
    unsigned char unk694;
    unsigned char unk695;
    unsigned char unk696;
    unsigned char unk697;
    unsigned char unk698;
    unsigned char unk699;
    unsigned char unk69a;
    unsigned char unk69b;
    unsigned char unk69c;
    unsigned char unk69d;
    unsigned char unk69e;
    unsigned char unk69f;
    unsigned char unk6a0;
    unsigned char unk6a1;
    unsigned char unk6a2;
    unsigned char unk6a3;
    unsigned char unk6a4;
    unsigned char unk6a5;
    unsigned char unk6a6;
    unsigned char unk6a7;
    unsigned char unk6a8;
    unsigned char unk6a9;
    unsigned char unk6aa;
    unsigned char unk6ab;
    unsigned char unk6ac;
    unsigned char unk6ad;
    unsigned char unk6ae;
    unsigned char playerIdleState;
    unsigned char unk6b0;
    unsigned char unk6b1;
    unsigned char unk6b2;
    unsigned char unk6b3;
    unsigned char unk6b4;
    unsigned char unk6b5;
    unsigned char unk6b6;
    unsigned char unk6b7;
    unsigned char unk6b8;
    unsigned char unk6b9;
    unsigned char unk6ba;
    unsigned char unk6bb;
    unsigned char unk6bc;
    unsigned char unk6bd;
    unsigned char unk6be;
    unsigned char unk6bf;
    unsigned char unk6c0;
    unsigned char unk6c1;
    unsigned char unk6c2;
    unsigned char unk6c3;
    unsigned char unk6c4;
    unsigned char unk6c5;
    unsigned char unk6c6;
    unsigned char unk6c7;
    unsigned char unk6c8;
    unsigned char unk6c9;
    unsigned char unk6ca;
    unsigned char unk6cb;
    unsigned char unk6cc;
    unsigned char unk6cd;
    unsigned char unk6ce;
    unsigned char unk6cf;
    unsigned char unk6d0;
    unsigned char unk6d1;
    unsigned char unk6d2;
    unsigned char unk6d3;
    unsigned char unk6d4;
    unsigned char unk6d5;
    unsigned char unk6d6;
    unsigned char unk6d7;
    unsigned char unk6d8;
    unsigned char unk6d9;
    unsigned char unk6da;
    unsigned char unk6db;
    unsigned char unk6dc;
    unsigned char unk6dd;
    unsigned char unk6de;
    unsigned char unk6df;
    unsigned char unk6e0;
    unsigned char unk6e1;
    unsigned char unk6e2;
    unsigned char unk6e3;
    unsigned char unk6e4;
    unsigned char unk6e5;
    unsigned char unk6e6;
    unsigned char unk6e7;
    unsigned char unk6e8;
    unsigned char unk6e9;
    unsigned char unk6ea;
    unsigned char unk6eb;
    unsigned char unk6ec;
    unsigned char unk6ed;
    unsigned char unk6ee;
    unsigned char unk6ef;
    unsigned char unk6f0;
    unsigned char unk6f1;
    unsigned char unk6f2;
    unsigned char unk6f3;
    unsigned char unk6f4;
    unsigned char unk6f5;
    unsigned char unk6f6;
    unsigned char unk6f7;
    unsigned char unk6f8;
    unsigned char unk6f9;
    unsigned char unk6fa;
    unsigned char unk6fb;
    unsigned char unk6fc;
    unsigned char unk6fd;
    unsigned char unk6fe;
    unsigned char unk6ff;
    unsigned char unk700;
    unsigned char unk701;
    unsigned char unk702;
    unsigned char unk703;
    unsigned char unk704;
    unsigned char unk705;
    unsigned char unk706;
    unsigned char unk707;
    unsigned char unk708;
    unsigned char unk709;
    unsigned char unk70a;
    unsigned char unk70b;
    unsigned char unk70c;
    unsigned char unk70d;
    unsigned char unk70e;
    unsigned char unk70f;
    unsigned char unk710;
    unsigned char unk711;
    unsigned char unk712;
    unsigned char unk713;
    unsigned char unk714;
    unsigned char unk715;
    unsigned char unk716;
    unsigned char unk717;
    unsigned char unk718;
    unsigned char unk719;
    unsigned char unk71a;
    unsigned char bittingPlantFlowerState;
    unsigned char unk71c;
    unsigned char unk71d;
    unsigned char unk71e;
    unsigned char goldenBowlState;
    unsigned char bonusHealth;
    unsigned char unk721;
    unsigned char unk722;
    unsigned char unk723;
    unsigned char unk724;
    unsigned char unk725;
    unsigned char unk726;
    unsigned char unk727;
    unsigned char unk728;
    unsigned char unk729;
    unsigned char unk72a;
    unsigned char unk72b;
    unsigned char unk72c;
    unsigned char unk72d;
    unsigned char unk72e;
    unsigned char unk72f;
    unsigned char unk730;
    unsigned char unk731;
    unsigned char unk732;
    unsigned char unk733;
    unsigned char unk734;
    unsigned char unk735;
    char unk736;
    unsigned char unk737;
    unsigned char unk738;
    unsigned char unk739;
    unsigned char unk73a;
    unsigned char unk73b;
    unsigned char unk73c;
    unsigned char unk73d;
    unsigned char unk73e;
    unsigned char unk73f;
    unsigned char unk740;
    unsigned char unk741;
    unsigned char unk742;
    unsigned char unk743;
    unsigned char item[256];
    struct GSInventory_29CB4 inventory;
    unsigned short currentArea;
    unsigned short currentSection;
    unsigned short currentSpawnPoint;
    unsigned char inventoryButton;
    unsigned char playerState;
    struct GSEquips_29CB4 playerEquips;
    unsigned char unk952;
    unsigned char unk953;
    unsigned char unk954;
    unsigned char unk955;
    unsigned char unk956;
    unsigned char unk957;
    unsigned char unk958;
    unsigned char unk959;
    unsigned char unk95a;
    unsigned char unk95b;
    unsigned char unk95c;
    unsigned char unk95d;
    unsigned char unk95e;
    unsigned char unk95f;
    unsigned char unk960;
    unsigned char unk961;
    unsigned char unk962;
    unsigned char purifiedAreas;
    unsigned char unk964;
    unsigned char unk965;
    unsigned char unk966;
    unsigned char unk967;
    unsigned char unk968;
    unsigned char unk969;
    unsigned char unk96a;
    unsigned char unk96b;
    unsigned char unk96c;
    unsigned char unk96d;
    unsigned char unk96e;
    unsigned char unk96f;
    unsigned char unk970;
    unsigned char unk971;
    unsigned char unk972;
    unsigned char unk973;
    unsigned char unk974;
    unsigned char unk975;
    unsigned char unk976;
    unsigned char unk977;
    unsigned char unk978;
    unsigned char unk979;
    unsigned char unk97a;
    unsigned char unk97b;
    unsigned char unk97c;
    unsigned char unk97d;
    unsigned char unk97e;
    unsigned char unk97f;
    unsigned char unk980;
    unsigned char unk981;
    unsigned char unk982;
    unsigned char unk983;
    unsigned char unk984;
} GameState_29CB4;
extern GameState_29CB4 GAME__8002C7D8_2;

typedef struct { unsigned char b0; char p0[0x15]; short w16; char p1[0x16]; unsigned short w2e; char p2[0x79]; unsigned char ba9; } S_29CB4;
typedef struct { short w0; short w2; } P_29CB4;
typedef struct {
    char p0[0x24]; int d24; char p1[8]; short w30; short w32; P_29CB4 *d34; P_29CB4 *d38;
    unsigned char b3c; unsigned char b3d; char p2[0x1a]; unsigned short w58;
} O_29CB4;
extern S_29CB4 PLAYER__8002C7D8;
extern P_29CB4 *D_800A53D8__8002C7D8;
extern P_29CB4 *D_800A53DC__8002C7D8;
extern unsigned short GAME__8002C7D8;
extern unsigned char D_800A5436__8002C7D8;
extern void func_8002A798__8002C7D8(O_29CB4 *);
extern void func_8002A480__8002C7D8(O_29CB4 *);
extern void func_8002B704__8002C7D8(O_29CB4 *);
extern void func_8002BB9C__8002C7D8(O_29CB4 *);

static __inline__ void Clamp_29CB4(O_29CB4 *o)
{
    S_29CB4 *s = &PLAYER__8002C7D8;
    char pad;
    if (s->b0 < 4 || s->b0 == 7) {
        unsigned short x = o->d34->w2;
        short t;
        t = x - 0x90;
        if (D_800A53D8__8002C7D8->w2 < t) {
            D_800A53D8__8002C7D8->w2 = t;
        } else {
            t = x + 0x90;
            if (t < D_800A53D8__8002C7D8->w2)
                D_800A53D8__8002C7D8->w2 = t;
        }
        if ((*(int*)&GAME__8002C7D8_2.selectedArea) == 0x2000E) {
            if (s->w16 < o->w30 - 0x5c)
                s->w16 = o->w30 - 0x5c;
        } else {
            if (s->w16 < o->w30 - 0x90)
                s->w16 = o->w30 - 0x90;
        }
    }
}

void func_8002C7D8(O_29CB4 *o)
{
    S_29CB4 *s = &PLAYER__8002C7D8;
    int t;
    if (D_8009BC98__8002C7D8.b39 == 0) {
        switch (D_800A5436__8002C7D8) {
        case 4:
            if (GAME__8002C7D8 != 10 && s->ba9 == 0)
                goto c4;
        case 0: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            func_8002A798__8002C7D8(o);
            func_8002A480__8002C7D8(o);
            o->b3d = 0;
            o->b3c = 0;
            break;
        c4:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798__8002C7D8(o);
            func_8002A480__8002C7D8(o);
            o->b3d = 0;
            break;
        case 3:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
            }
            func_8002A798__8002C7D8(o);
            if (o->b3d == 0)
                func_8002A480__8002C7D8(o);
            break;
        case 1: case 2: case 5:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798__8002C7D8(o);
            if (o->b3d == 0)
                func_8002A480__8002C7D8(o);
            break;
        }
        o->d38->w2 = D_800A53DC__8002C7D8->w2;
    }
    func_8002B704__8002C7D8(o);
    func_8002BB9C__8002C7D8(o);
    SCRATCHPAD__8002C7D8.s286 = -o->d24 >> 6;
    Clamp_29CB4(o);
}
#else
void func_8002C7D8(O_2C7D8 *o)
{
    S_2C7D8 *s = &PLAYER;
    s32 t;
    if (D_8009BCA1 == 0) {
        switch (D_800A5436) {
        case 4:
            if ((*(u16 *)&GAME) != 10 && s->ba9 == 0)
                goto c4;
        case 0: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            func_8002A798(o);
            func_8002A480(o);
            o->b3d = 0;
            o->b3c = 0;
            break;
        c4:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798(o);
            func_8002A480(o);
            o->b3d = 0;
            break;
        case 3:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
            }
            func_8002A798(o);
            if (o->b3d == 0)
                func_8002A480(o);
            break;
        case 1: case 2: case 5:
            t = s->w2e & 1;
            if (t != o->w58) {
                o->w58 = t;
                o->b3d = 0;
                o->b3c = 0;
            }
            if (o->b3c == 0)
                func_8002A798(o);
            if (o->b3d == 0)
                func_8002A480(o);
            break;
        }
        o->d38->w2 = (*(P_2C7D8 **)&D_800A53DC)->w2;
    }
    func_8002B704(o);
    func_8002BB9C(o);
    D_1F800286 = -o->d24 >> 6;
    Clamp_2C7D8(o);
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002CA40);
typedef struct S_2CA40 {
    char p0[0x20]; s32 vy; s32 vx; char p1[0x6e - 0x28];
    u8 b6e, b6f, b70, b71, b72, b73;
} S_2CA40;
void func_8002A9FC();
void func_8002ABC0();
void func_8002CA40(S_2CA40 *o)
{
    s32 f1, f2;
    s16 s;
    if (o->vx != 0) {
        if (o->vx > 0) o->vx -= 0x80;
        else o->vx += 0x80;
    } else {
        o->b71 = 0;
        o->b72 = 0;
        o->b73 = 0;
    }
    f1 = 0;
    if (o->vy != 0) {
        if (o->vy > 0) o->vy -= 0x100;
        else o->vy += 0x100;
        f1 = 1;
    }
    s = D_1F8000E6;
    if (s != 0) {
        if (s > 0) {
            D_1F8000E6 = s -= 2;
            if (s < 0) D_1F8000E6 = 0;
        } else {
            D_1F8000E6 = s += 2;
            if (s > 0) D_1F8000E6 = 0;
        }
        f2 = 1;
    } else {
        f2 = 0;
    }
    if ((f1 | f2) == 0) {
        o->b6e = 0;
        o->b6f = 0;
    }
    func_8002A9FC(o);
    func_8002ABC0(o);
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", updateLookScroll);
void updateLookScroll(u8* self)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002CC20);
typedef struct {
    u8 b0, b1, b2, b3;
    char p4[0x34 - 4];
    u16 *p34;
    char p38[0x44 - 0x38];
    u16 f44;
} S_2CC20;
extern u16 D_1F80016E;

void func_8002CC20(S_2CC20 *o)
{
    s16 v;
    o->f44 = 0;
    v = (*(SVECTOR *)&D_1F8000E6).vx;
    if (v != 0) {
        if (v > 0) {
            v -= 2;
            D_1F8000E6 = v;
            if (v < 0) D_1F8000E6 = 0;
        } else {
            v += 2;
            D_1F8000E6 = v;
            if (v > 0) D_1F8000E6 = 0;
        }
    }
    func_8002A798(o);
    func_8002A480(o);
    if ((u16)(o->p34[1] - (*(u16 *)&D_1F80016A) + 0x8c) < 0x118 || (o->f44 & 3)) {
        if ((u16)(D_1F8000F2 - D_1F80016E + 0xb4) < 0x168 || (o->f44 & 0xc)) {
            o->b3 = 1;
            if (D_8009BCCE == 3 || D_8009C10E == 0xff) o->b3 = 0;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            D_8009BCAA = 0;
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002CD7C);
typedef struct {
    u8 b0, b1, b2, b3;
    char pad[0x34 - 4];
    u16 *p34;
    char pad2[0x44 - 0x38];
    u16 w44;
} S8002A258_2CD7C;
extern s16 D_1F8000E6_S16Arr[] asm("D_1F8000E6");

void func_8002CD7C(S8002A258_2CD7C *o)
{
    s16 v;
    o->w44 = 0;
    v = D_1F8000E6_S16Arr[0];
    if (v != 0) {
        if (v > 0) {
            D_1F8000E6 = v - 2;
            if (D_1F8000E6 < 0) D_1F8000E6 = 0;
        } else {
            D_1F8000E6 = v + 2;
            if (D_1F8000E6 > 0) D_1F8000E6 = 0;
        }
    }
    D_1F80018C = D_1F800168;
    D_1F800190 = D_1F80016C;
    func_8002A9FC(o);
    func_8002ABC0(o);
    if ((u16)(o->p34[1] - (*(u16 *)&D_1F80016A) + 0x40) < 0x80 || (o->w44 & 3)) {
        if ((u16)(D_1F8000F2 - D_1F80016E + 0x5a) < 0xb4 || (o->w44 & 0xc)) {
            o->b3 = 1;
            if (D_8009BCCE == 3 || D_8009C10E == 0xff) o->b3 = 0;
            D_8009BCA7 = 0;
            D_8009BCA6 = 0;
            D_8009BCAA = 0;
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002CEF8);
extern u8 PLAYER_U8Arr[] asm("PLAYER");
static __inline__ void lim_2CEF8(s16 *q, s16 x, s32 k) { if (*q < x - k) *q = x - k; }
#if defined(VERSION_SCES_01330)
extern unsigned char PLAYER__8002CEF8;
extern unsigned char PLAYER__8002CEF8_2[];
extern short *D_800A53D8__8002CEF8;
extern int GAME__8002CEF8;
extern void func_8002A798__8002CEF8(GameObject *);
extern void func_8002A480__8002CEF8(GameObject *);
static __inline__ void lim_2A388(short *q, short x, int k) { if (*q < x - k) *q = x - k; }
void func_8002CEF8(GameObject *o)
{
    short a, b;
    unsigned char *g;
    func_8002A798__8002CEF8(o);
    func_8002A480__8002CEF8(o);
    g = PLAYER__8002CEF8_2;
    if (PLAYER__8002CEF8 < 4 || PLAYER__8002CEF8 == 7) {
        b = *(short *)(o->unk34 + 2);
        if (D_800A53D8__8002CEF8[1] < (a = b - 0x90)) D_800A53D8__8002CEF8[1] = a;
        else if ((a = b + 0x90) < D_800A53D8__8002CEF8[1]) D_800A53D8__8002CEF8[1] = a;
        if (GAME__8002CEF8 == 0x2000e) {
            lim_2A388((short *)(g + 0x16), *(short *)&o->unk30, 0x5c);
        } else {
            lim_2A388((short *)(g + 0x16), *(short *)&o->unk30, 0x90);
        }
    }
}
#elif defined(VERSION_SCES_01331)
extern unsigned char PLAYER__8002CEF8;
extern unsigned char PLAYER__8002CEF8_2[];
extern short *D_800A53D8__8002CEF8;
extern int GAME__8002CEF8;
extern void func_8002A798__8002CEF8(GameObject *);
extern void func_8002A480__8002CEF8(GameObject *);
static __inline__ void lim_2A3D4(short *q, short x, int k) { if (*q < x - k) *q = x - k; }
void func_8002CEF8(GameObject *o)
{
    short a, b;
    unsigned char *g;
    func_8002A798__8002CEF8(o);
    func_8002A480__8002CEF8(o);
    g = PLAYER__8002CEF8_2;
    if (PLAYER__8002CEF8 < 4 || PLAYER__8002CEF8 == 7) {
        b = *(short *)(o->unk34 + 2);
        if (D_800A53D8__8002CEF8[1] < (a = b - 0x90)) D_800A53D8__8002CEF8[1] = a;
        else if ((a = b + 0x90) < D_800A53D8__8002CEF8[1]) D_800A53D8__8002CEF8[1] = a;
        if (GAME__8002CEF8 == 0x2000e) {
            lim_2A3D4((short *)(g + 0x16), *(short *)&o->unk30, 0x5c);
        } else {
            lim_2A3D4((short *)(g + 0x16), *(short *)&o->unk30, 0x90);
        }
    }
}
#else
void func_8002CEF8(GameObject *o)
{
    s16 a, b;
    u8 *g;
    func_8002A798(o);
    func_8002A480(o);
    g = PLAYER_U8Arr;
    if (PLAYER.obj.active < 4 || PLAYER.obj.active == 7) {
        b = *(s16 *)(o->unk34 + 2);
        if (PLAYER.obj.h->p.whole < (a = b - 0x90)) PLAYER.obj.h->p.whole = a;
        else if ((a = b + 0x90) < PLAYER.obj.h->p.whole) PLAYER.obj.h->p.whole = a;
        if ((*(s32 *)&GAME) == 0x2000e) {
            lim_2CEF8((s16 *)(g + 0x16), *(s16 *)&o->unk30, 0x54);
        } else {
            lim_2CEF8((s16 *)(g + 0x16), *(s16 *)&o->unk30, 0x88);
        }
    }
}
#endif

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002CFF4);

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionInit);
void dispatchSectionInit(void)
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
        default:
            return;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionUpdate);
void dispatchSectionUpdate(void)
{
    switch (GAME.selectedSection) {
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionDraw);
void dispatchSectionDraw(void)
{
    switch (GAME.selectedSection) {
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionInput);
void dispatchSectionInput(void)
{
    if (GAME.selectedSection == 0) {
        func_800E80E0();
        return;
    }
    func_80115310();
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionScroll);
void dispatchSectionScroll(void)
{
    if (GAME.selectedSection == 0) {
        func_800E821C();
        return;
    }
    func_801152D8();
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionSelect);
void dispatchSectionSelect(void)
{
    if (GAME.selectedSection == 0) {
        func_800E8388();
        return;
    }
    func_8011546C();
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionClose);
void dispatchSectionClose(void)
{
    if (GAME.selectedSection == 0) {
        func_80115584();
        return;
    }
    func_80115628();
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", dispatchSectionConfirm);
void dispatchSectionConfirm(void)
{
    switch (GAME.selectedSection) {
        case 1:
            func_801151F8();
            return;
        case 2:
        case 0:
            func_800E84BC();
            return;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002D784);
typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    s32 d8;
    s32 dc;
    s32 d10;
    char p14[0x3c - 0x14];
    u8 b3c, b3d, b3e, b3f;
    char p40[0x58 - 0x40];
    u16 w58;
    char p5a[0x6c - 0x5a];
    u8 b6c, b6d, b6e, b6f;
    u8 b70, b71, b72, b73;
    u8 b74, b75, b76, b77;
} S_2D784;
extern void (*D_8007C5F0[])(S_2D784 *);

void func_8002D784(S_2D784 *o)
{
    u16 w;
    s32 t;

    switch (o->b4) {
    case 0:
        o->b3c = 0;
        o->b3d = 0;
        o->b3e = 0;
        w = PLAYER.obj.animFrame;
        o->b3 = 0;
        o->b70 = 0;
        o->b71 = 0;
        o->b72 = 0;
        o->b73 = 0;
        o->b6c = 10;
        o->b6d = 0;
        o->b6e = 0;
        o->b6f = 0;
        o->b74 = 0;
        o->b75 = 0;
        o->b76 = 0;
        o->b77 = 0;
        D_1F800286 = 0;
        o->w58 = w;
        o->b4++;
        if ((*(s32 *)&GAME) == 6) {
            o->b4 = 2;
            SetGeomScreen(0x220);
        } else if ((*(s32 *)&GAME) == 0x60009) {
            o->b4 = 2;
            D_8009D6DD = 0;
            D_8009D6DE = 0;
            D_8009D6DF = 0;
            D_8009E3ED = 0;
            D_8009E3EE = 0;
            D_8009E3EF = 0;
        } else {
            SetGeomScreen(0x220);
        }
        break;
    case 1:
        D_8007C5F0[(*(u16 *)&GAME)](o);
        func_8002A0A0(o);
        goto tail;
    case 2:
        D_8007C5F0[(*(u16 *)&GAME)](o);
    tail:
        D_1F800174[0] = o->d8;
        t = o->dc;
        D_1F800178[0] = t;
        D_1F80017C[0] = o->d10;
        D_1F800184[0] = D_1F8000E4 + t;
        D_1F800180 = o->d8;
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", getScrollOffsetX);
s16 getScrollOffsetX(void)
{
    s32 x = D_800A38DC;
    s32 v = D_8007D988[(x >> 8) / 360];
    s32 r = (v * 567) >> 12;

    if (x > 0) {
        r = r - 0x14;
    } else {
        r = r + 0x14;
    }
    return r;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", getScrollOffsetY);
s32 getScrollOffsetY(void)
{
    s16 v = D_8007D988[(D_800A38DC >> 8) / 360];

    return (v * 1027) >> 12;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002DA2C);
extern s32 WMD_DATA;
extern void (*D_8007C640[])(char *, s32);

void func_8002DA2C(void)
{
    u16 v, x;
    D_800B00FB = 0;
    switch (GAME.selectedArea) {
    case 0:
        break;
    case 0xd:
        if (D_8009BCCA != 0) return;
        break;
    case 2:
        x = D_8009BCCA;
        v = 3;
        goto cmp;
    case 6:
        if (D_8009BCCA > 1) return;
        break;
    case 9:
        x = D_8009BCCA;
        if (x == 0) break;
        v = 6;
        goto cmp;
    case 0x12:
        x = D_8009BCCA;
        v = 1;
    cmp:
        if (x != v) return;
        break;
    case 5: case 8: case 0xb: case 0x10: case 0x11: case 0x13:
        return;
    }
    D_8007C640[GAME.selectedArea](D_800B00F8, WMD_DATA);
    D_800B00F9 = D_8009C10A;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", stubInventory1);
void stubInventory1(void) {
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", updateObjectsLayer8);
void updateObjectsLayer8(void)
{
    u8* p = &D_800B0B88;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007C68C[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xD4;
    } while (D_1F800198 < 0x2D);
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", stubInventory2);
void stubInventory2(void) {
}

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002DBD8);

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002DEC4);

// INCLUDE_ASM("nonmatchings/main/game/inventory", stubInventory3);
void stubInventory3(void) {
}

// INCLUDE_ASM("nonmatchings/main/game/inventory", spawnItemPickupObject);
void spawnItemPickupObject(u8 arg0)
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

// INCLUDE_ASM("nonmatchings/main/game/inventory", cloneItemPickupObject);
void cloneItemPickupObject(u8* src)
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

INCLUDE_ASM("nonmatchings/main/game/inventory", func_8002E494);
