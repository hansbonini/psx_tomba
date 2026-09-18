#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", updateItemPickupAnim);
void updateItemPickupAnim(unkstruct_800A6D50* arg0)
{
    int var_a1;
    int var_v0;
    u_short temp_a1;
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = arg0->unk6;
    switch (temp_v1) {                              // irregular
        case 0:
            playSFX(*(&D_8007D6D0 + arg0->item_id));
            func_800E92D4(0x1F4, arg0->unk12, arg0->unk16, arg0->unk1A);
            arg0->unkA5 = 0;
            if (arg0->item_id != ITEM_FLOWERTEARS) {
                arg0->unkB = 1;
                arg0->unkF = 4;
            }
            arg0->unk82 = -1024;
            *(int*)&arg0->unk28 = &D_8007722C;
            if (arg0->unk2E & 2) {
                *(int*)&arg0->unk28 = &D_800771FC;
            }
            arg0->unk6 = (u_char) (arg0->unk6 + 1);
            break;
        case 1:
            temp_a1 = arg0->unk2E;
            if (temp_a1 & 2) {
                applyAnimVelocityX(arg0, temp_a1 & 1);
            } else {
                applyAnimVelocityX(arg0, (temp_v1 - temp_a1) & 0xFFFF);
            }
            temp_v0 = arg0->unk82 + 64;
            arg0->unk82 = temp_v0;
            if ((short) temp_v0 >= 1025) {
                arg0->unk82 = 1024;
            }
            *(int*)&arg0->unk14 = (int) (*(int*)&arg0->unk14 + ((short) arg0->unk82 << 8));
            break;
    }
    if (arg0->unk2E & 1) {
        var_v0 = arg0->unk8C + 24;
    } else {
        var_v0 = arg0->unk8C - 24;
    }
    arg0->unk8C = (int) (var_v0 & 0xFF);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F3D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", func_8003F9A4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", applyItemEffect);
void applyItemEffect(unkstruct_800A6D50* arg0, int arg1, short arg2, short arg3, int arg4)
{

    if (func_800236F4(arg0->item_id) == ITEM_CHICK) {
        switch (arg0->spawnMode) {
            case 0:
                spawnItem(arg0->unk1, arg0->unk2, arg1);
                break;
            case 1:
                spawnItemDrop(arg0->unk1, arg0->unk2, arg1);
                break;
            case 2:
                spawnItemAtPos(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 3:
                spawnItemDropAtPos(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 4:
                spawnItemBounce(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 5:
                spawnItemFixed(arg0->unk1, arg0->unk2, arg1);
                break;
            case 6:
                func_80123188(arg1, arg0->item_id, arg2, arg3);
                break;
            case 8:
                spawnItemChest(arg0->unk1, arg0->unk2, arg1);
                break;
        }
        if (arg4 != 0) {
            func_80023794(arg0->item_id);
        }
        if (arg0->subState == 0) {
            playSFX(21);
        }
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", initItemObject);
void initItemObject(unkstruct_800A6D50* arg0)
{

    
    short x;
    short y;
    int temp_v0;
    int color;
    int* var_v0;
    u_char temp_v1;
    u_char temp_v1_2;
    itemDef* temp_s1;

    if ((arg0->item_id == ITEM_JEWELOFWIND) && (GAME.event[EVENT_THEJUNGLEPIGBAG] == 0)) {
        arg0->state = 2;
        return;
    }
    arg0->unk68 = 0;
    arg0->unk69 = 0;
    temp_s1 = D_8007E6E4[D_8007E61C[arg0->item_id]];
    arg0->unkA = temp_s1->unk0;
    arg0->unk1E = (short)temp_s1->unk2;
    arg0->unkF = -9;
    arg0->unkD = (u_char)temp_s1->unk5;
    arg0->unk6C = (short)temp_s1->unkC;
    arg0->unk6E = (short)temp_s1->unkD;
    arg0->unk70 = (short)temp_s1->unkE;
    arg0->unk72 = (short)temp_s1->unkF;

    arg0->unk3C = *(&D_1F8002C8[temp_s1->unk4]);
    arg0->unk2E = 1;
    if (arg0->item_id == 2) {
        if ((u_long) (arg0->unkC & 0x7F) >= 4U) {
            arg0->buffSize = 0x2000;
            arg0->unk6C = (short) (temp_s1->unkC * 2);
            arg0->unk6E = (short) (temp_s1->unkD * 2);
            arg0->unk70 = (short) (temp_s1->unkE * 2);
            arg0->unk72 = (short) (temp_s1->unkF * 2);
        } else {
            arg0->buffSize = 0x1000;
        }
    }

    switch (temp_s1->unk6) {                              // irregular
        case 0:
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut((int) x, (int) y);
            break;
        case 1:
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut((int) x, (int) y + (arg0->unkC & 0x7F));
            break;
        case 2:
            temp_v0 = (arg0->unkC & 0x7F) * 2;
            x = *(u_short*)(&D_8007E86C + temp_v0);
            y = *(u_short*)(&D_8007E86E + temp_v0);
            arg0->clut = GetClut((int) x, (int) y);
            break;
        case 3:
            if (GAME.item[ITEM_JUMPINGPANTS] == 0) {
                color = 0;
            } else {
                color = 2;
                if (GAME.item[ITEM_DASHINGPANTS] == 0) {
                    color = 1;
                }
            }
            x = temp_s1->x;
            y = temp_s1->y;
            arg0->clut = GetClut(x, y + color);
            break;
    }

    switch (temp_s1->unk7) {
        case 0:
            var_v0 = temp_s1->unk10;
            arg0->unk24 = (int) *var_v0;
            break;
        case 1:
            var_v0 = (int) ((arg0->unkC & 0x7F) * 4) + *(int*)&temp_s1->unk10;
            arg0->unk24 = (int) *var_v0;
            break;
    }
    readAnimFrameCount(arg0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardNone);
void rewardNone(unkstruct_800A6D50* arg0)
{
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardItem);
void rewardItem(unkstruct_800A6D50* arg0)
{
    int var_a0;
    int var_a1;
    int var_a2;
    u_char current_item;

    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    current_item = arg0->item_id;
    switch (current_item) {
        case ITEM_BOMB:
            setEventComplete(EVENT_INEEDABOMB, 4);
            break;
        case ITEM_PIPE:
            GAME.pipeState = 1;
            break;
        case ITEM_GOLDENFLOWER:
            GAME.goldenFlowerState = 1;
            break;
        case ITEM_TEARJAR:
            setEventComplete(EVENT_INEEDATEARBOTTLE, 1);
            break;
        case ITEM_MIGHTYFISHFOOD:
            setEventComplete(EVENT_WHATSTHEUNDERWATER, 0);
            break;
        case ITEM_WHATTHETHIEFFORGOT:
            setEventStarted(EVENT_WHATTHETHIEFFORGOT, 1, 1);
            break;
        case ITEM_BOSSJEWEL:
            setEventComplete(EVENT_THEBOSSTREASURE, 1);
            addPlayerAP(100000);
            break;
        case ITEM_SEASHELLNECKLACE:
            setEventStarted(EVENT_THEMERMAIDNECKLACE, 0, 0);
            break;
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardHeart);
void rewardHeart(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        func_800E92D4(0x64, arg0->unk12, arg0->unk16, arg0->unk1A);
        playSFX(9);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        if (!(arg0->unkC & 0x7F)) {
            *(short*)&D_800A5430+=1;
            if ((short)GAME.playerHealthDisplayed < *(short*)&D_800A5430 ) {
                *(short*)&D_800A5430 = GAME.playerHealthDisplayed;
            }
        } else {
            *(short*)&D_800A5430+=2;
            if ((short)GAME.playerHealthDisplayed < *(short*)&D_800A5430 ) {
                *(short*)&D_800A5430 = GAME.playerHealthDisplayed;
            }
        }
        D_800A5432 = D_800A5430;
        GAME.playerHealth = (u_char) D_800A5430;
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardEffectOnly);
void rewardEffectOnly(unkstruct_800A6D50* arg0)
{
    func_800E92D4(*(&D_8007E868 + ((arg0->unkC & 0x7F) * 2)), arg0->unk12, arg0->unk16, arg0->unk1A);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    playSFX(9);
    arg0->state+=1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardBakedYam);
void rewardBakedYam(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_BAKEDYAM, 1, true);
    if ((GAME.event[EVENT_SOMETHINGCOOKIN] & 0xFF) == 3) {
        GAME.event[EVENT_SOMETHINGCOOKIN] += 1;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex, &GAME.event[EVENT_SOMETHINGCOOKIN]);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardDirtyMirror);
void rewardDirtyMirror(unkstruct_800A6D50* arg0)
{
    GAME.unk54e = 5;
    addItemToInventory(ITEM_DIRTYMIRROR, 1, true);
    setEventStarted(EVENT_AMAGICMIRROR, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardVitalityMaxUp);
void rewardVitalityMaxUp(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        increaseMaxHealth();
        printInfoMessage(MSG_VITALITYMAXUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardWoodBoomerang);
void rewardWoodBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_WOODBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardStoneBoomerang);
void rewardStoneBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_STONEBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardIronBoomerang);
void rewardIronBoomerang(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_IRONBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardOneUp);
void rewardOneUp(unkstruct_800A6D50* arg0)
{
    u_char lives = GAME.playerLives;
    if (lives < 99) {
        GAME.playerLives = (u_char)(lives+1);
        printInfoMessage(MSG_ONEUP_ACQUIRED, MSG_TYPE_REWARD);
        playSFX(10);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGoldenBowl);
void rewardGoldenBowl(unkstruct_800A6D50* arg0)
{
    u_char health;

    if (D_8009BCA0 == 0) {
        health = GAME.playerHealthDisplayed;
        if (health < 16) {
            health += GAME.bonusHealth;
            GAME.playerHealthDisplayed = health;
            if ((u_long) ((byte)health & 0xFF) >= 17) {
                GAME.playerHealthDisplayed = 16;
            }
            playSFX(10);
            D_800A5430 = (u_short*)(*(char*)&GAME.playerHealthDisplayed);
            D_800A5432 = *(char*)&GAME.playerHealthDisplayed;
            *(char*)&GAME.playerHealth = *(char*)&GAME.playerHealthDisplayed;
        }
        GAME.goldenBowlState = 1;
        D_800B078C = &D_800121C8;
        playSFX(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->objectIndex);
        }
        arg0->state++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardBitingPlantFlower);
void rewardBitingPlantFlower(unkstruct_800A6D50* arg0)
{
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = arg0->subState;
    switch (temp_v1) {
        case 0:
            addItemToInventory(ITEM_BITINGPLANTFLOWER, 1, true);
            setEventStarted(EVENT_BITINGPLANTFLOWER, 0, 0);
            if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
                GAME.bittingPlantFlowerState = 2;
            }
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->objectIndex);
            }
            arg0->cooldownTimer = 0x12CU;
            asm("");
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_800A539C = 5;
            D_800A539D = 0;
            D_800A539E = 0;
            D_800A539F = 0;
            arg0->subState++;
            return;
        case 1:
            temp_v0 = arg0->cooldownTimer - 1;
            arg0->cooldownTimer = temp_v0;
            if ((temp_v0 << 0x10) == 0) {
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                D_800A539F = 0;
                arg0->state++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGrapple);
void rewardGrapple(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLE, 1, true);
    setEventComplete(EVENT_APRECIOUSTREASURECHEST, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardGrappleJack);
void rewardGrappleJack(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLEJACK, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardCrystalBalls);
void rewardCrystalBalls(unkstruct_800A6D50* arg0)
{
    switch (GAME.event[EVENT_LOSTANDFOUND]) {
        case 0:
            setEventStarted(EVENT_LOSTANDFOUND, 0, 0);
            printInfoMessage(MSG_LOSTANDFOUND_STARTED, MSG_TYPE_REWARD);
            break;
        case 1:
            printInfoMessage(MSG_LOSTANDFOUND_PROGRESS, MSG_TYPE_REWARD);
            GAME.event[EVENT_LOSTANDFOUND]+= 1;
            break;
        case 2:
            addItemToInventory(ITEM_THREECRYSTALBALLS, 1, true);
            setEventComplete(EVENT_LOSTANDFOUND, 0);
            break;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardMysteriousMushroom);
void rewardMysteriousMushroom(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_THEMISTERIOUSMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardFlowerSeeds);
void rewardFlowerSeeds(unkstruct_800A6D50* arg0)
{
    setEventStarted(EVENT_FLOWERSEEDS, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    addItemToInventory(arg0->item_id, 1, true);
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardPigBag);
void rewardPigBag(unkstruct_800A6D50* arg0)
{
    int temp;

    switch (arg0->subState) {                              // switch 3; irregular
        case 0:                                     // switch 3
            addItemToInventory(arg0->item_id, 1, true);
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->objectIndex);
            }
            switch (arg0->item_id) {
                case ITEM_REDPIGBAG:
                    setEventComplete(EVENT_ASTORMYPIGBAG, 2);
                    break;
                case ITEM_ORANGEPIGBAG:
                    setEventComplete(EVENT_THEMOUSEPIGBAG, 2);
                    break;
                case ITEM_YELLOWPIGBAG:
                    setEventComplete(EVENT_THEUNDERWATERPIG, 2);
                    break;
                case ITEM_GREENPIGBAG:
                    setEventComplete(EVENT_THEFIREPIGBAG, 2);
                    break;
                case ITEM_BLUEEVILPIGBAG:
                    setEventComplete(EVENT_THEEVILPIGBAG, 2);
                    break;
                case ITEM_NAVYPIGBAG:
                    setEventComplete(EVENT_THEJUNGLEPIGBAG, 2);
                    break;
                case ITEM_PINKPIGBAG:
                    setEventComplete(EVENT_THEHAUNTEDPIGBAG, 2);
                    break;
            }
            arg0->cooldownTimer = 0x168U;
            arg0->subState++;
            return;
        case 1:
            temp = arg0->cooldownTimer - 1;
            arg0->cooldownTimer = temp;
            if ((temp << 0x10) == 0) {
                switch (arg0->item_id) {
                    case ITEM_REDPIGBAG:        
                        setEventStarted(EVENT_PHOENIXMOUNTAIN, 0, 3);
                        break;
                    case ITEM_ORANGEPIGBAG:
                        setEventStarted(EVENT_BACCUSVILLAGE, 0, 3);
                        break;
                    case ITEM_YELLOWPIGBAG:
                        setEventStarted(EVENT_TRICKVILLAGE, 0, 3);
                        break;
                    case ITEM_GREENPIGBAG:
                        setEventStarted(EVENT_LAVACAVES, 0, 3);
                        break;
                    case ITEM_BLUEEVILPIGBAG:
                        setEventStarted(EVENT_THE100FLOWERFOREST, 0, 3);
                        break;
                    case ITEM_NAVYPIGBAG:
                        setEventStarted(EVENT_THEDEEPJUNGLEPIG, 0, 3);
                        break;
                    case ITEM_PINKPIGBAG:
                        setEventStarted(EVENT_THEHAUNTEDMANSION, 0, 3);
                        break;
                }
                arg0->state++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardConditionalItem);
void rewardConditionalItem(unkstruct_800A6D50* arg0)
{
    if ((GAME.selectedArea == AREA10_DEEPJUNGLE) || (arg0->unkC == 1)) {
        addItemToInventory(arg0->item_id, 1, true);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardJewel);
void rewardJewel(unkstruct_800A6D50* arg0)
{
    int var_a0;
    int var_a2;
    u_char current_item;
    u_char var_v0;
    
    current_item = arg0->item_id;
    switch (current_item) {
        case ITEM_JEWELOFFIRE: 
            if (GAME.redExpLevel == 9) {
                setEventComplete(EVENT_REDHIDDENPOWERS, 1);
                addItemToInventory(arg0->item_id, 1, true);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                    asm("");
                }
                arg0->state++;
            } else {
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
        case ITEM_JEWELOFWATER: 
            if (GAME.blueExpLevel == 9) {
                setEventComplete(EVENT_BLUEHIDDENPOWERS, 0);
                addItemToInventory(arg0->item_id, 1, true);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                    asm("");
                }
                arg0->state++;
            } else {
                setEventStarted(EVENT_BLUEHIDDENPOWERS, 0, 0);
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
        case ITEM_JEWELOFWIND:
            if (GAME.greenExpLevel == 9) {
                setEventComplete(EVENT_GREENHIDDENPOWERS, 1);
                addItemToInventory(arg0->item_id, 1, true);
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->objectIndex);
                }
                arg0->state++;
            } else {
                setEventStarted(EVENT_GREENHIDDENPOWERS, 0, 1);
                if ((short)arg0->cooldownTimer == 0) {
                    printInfoMessage(MSG_ITS_LOCKED, MSG_TYPE_INFO);
                    arg0->cooldownTimer = 0x78;
                } 
                arg0->state--;
            }
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardSafeMushroom);
void rewardSafeMushroom(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_ASAFEMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardAnimalDash);
void rewardAnimalDash(unkstruct_800A6D50* arg0)
{
    printInfoMessage(MSG_ANIMALDASH_ACQUIRED, MSG_TYPE_REWARD);
    GAME.area00_eventControl |= 0x40;
    playSFX(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    GAME.unk6ad = 1;
    GAME.unk736 = 1;
    arg0->state++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/reward", rewardPants);
void rewardPants(unkstruct_800A6D50* arg0)
{   
    if (GAME.item[ITEM_JUMPINGPANTS] == 0) {
        addItemToInventory(ITEM_JUMPINGPANTS, 1, true);
    } else if ((GAME.item[ITEM_DASHINGPANTS] == 0)) {
        addItemToInventory(ITEM_DASHINGPANTS, 1, true);
    } else if (GAME.item[ITEM_FLASHPANTS] == 0) {
        addItemToInventory(ITEM_FLASHPANTS, 1, true);
    }
    playSFX(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->objectIndex);
    }
    arg0->state++;
}
