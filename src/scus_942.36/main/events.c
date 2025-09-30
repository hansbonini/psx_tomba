#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003F268);
void func_8003F268(unkstruct_800A6D50* arg0)
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
                func_80022618(arg0, temp_a1 & 1);
            } else {
                func_80022618(arg0, (temp_v1 - temp_a1) & 0xFFFF);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003F3D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003F78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003F9A4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003FC18);
void func_8003FC18(unkstruct_800A6D50* arg0, int arg1, short arg2, short arg3, int arg4)
{

    if (func_800236F4(arg0->item_id) == ITEM_CHICK) {
        switch (arg0->unk0) {
            case 0:
                func_80041754(arg0->unk1, arg0->unk2, arg1);
                break;
            case 1:
                func_80041790(arg0->unk1, arg0->unk2, arg1);
                break;
            case 2:
                func_800417CC(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 3:
                func_80041820(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 4:
                func_80041874(arg0->unk1, arg0->unk2, arg1, arg2, (int) arg3);
                break;
            case 5:
                func_800418C8(arg0->unk1, arg0->unk2, arg1);
                break;
            case 6:
                func_80123188(arg1, arg0->item_id, arg2, arg3);
                break;
            case 8:
                func_80041904(arg0->unk1, arg0->unk2, arg1);
                break;
        }
        if (arg4 != 0) {
            func_80023794(arg0->item_id);
        }
        if (arg0->unk5 == 0) {
            playSFX(21);
        }
    }
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8003FDD4);
void func_8003FDD4(unkstruct_800A6D50* arg0)
{

    typedef struct {
        u_char unk0;
        u_char unk1;
        u_char unk2;
        u_char unk3;
        u_char unk4;
        u_char unk5;
        u_char unk6;
        u_char unk7;
        short x;
        short y;
        u_char unkC;
        u_char unkD;
        u_char unkE;
        u_char unkF;
        int unk10;
    } unkstruct;

    
    short x;
    short y;
    int temp_v0;
    int color;
    int* var_v0;
    u_char temp_v1;
    u_char temp_v1_2;
    unkstruct* temp_s1;

    if ((arg0->item_id == ITEM_JEWELOFWIND) && (GAME.event[EVENT_THEJUNGLEPIGBAG] == 0)) {
        arg0->unk4 = 2;
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
    func_800229FC(arg0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004008C);
void func_8004008C(unkstruct_800A6D50* arg0)
{
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800400E0);
void func_800400E0(unkstruct_800A6D50* arg0)
{
    int var_a0;
    int var_a1;
    int var_a2;
    u_char current_item;

    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
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
            func_8001E220(EVENT_WHATTHETHIEFFORGOT, 1, 1);
            break;
        case ITEM_BOSSJEWEL:
            setEventComplete(EVENT_THEBOSSTREASURE, 1);
            setPlayerAP(100000);
            break;
        case ITEM_SEASHELLNECKLACE:
            func_8001E220(EVENT_THEMERMAIDNECKLACE, 0, 0);
            break;
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040268);
void func_80040268(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        func_800E92D4(0x64, arg0->unk12, arg0->unk16, arg0->unk1A);
        playSFX(9);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->unk6B);
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
        arg0->unk4++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004035C);
void func_8004035C(unkstruct_800A6D50* arg0)
{
    func_800E92D4(*(&D_8007E868 + ((arg0->unkC & 0x7F) * 2)), arg0->unk12, arg0->unk16, arg0->unk1A);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    playSFX(9);
    arg0->unk4+=1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800403E4);
void func_800403E4(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_BAKEDYAM, 1, true);
    if ((GAME.event[EVENT_SOMETHINGCOOKIN] & 0xFF) == 3) {
        GAME.event[EVENT_SOMETHINGCOOKIN] += 1;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B, &GAME.event[EVENT_SOMETHINGCOOKIN]);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040468);
void func_80040468(unkstruct_800A6D50* arg0)
{
    GAME.baronState = 5;
    addItemToInventory(ITEM_DIRTYMIRROR, 1, true);
    func_8001E220(EVENT_AMAGICMIRROR, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800404E8);
void func_800404E8(unkstruct_800A6D50* arg0)
{
    if (D_8009BCA0 == 0) {
        func_80029A84();
        printInfoMessage(0x15, 3);
        playSFX(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->unk6B);
        }
        arg0->unk4++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040564);
void func_80040564(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_WOODBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800405C8);
void func_800405C8(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_STONEBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004062C);
void func_8004062C(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_IRONBOOMERANG, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040690);
void func_80040690(unkstruct_800A6D50* arg0)
{
    u_char lives = GAME.playerLives;
    if (lives < 99) {
        GAME.playerLives = (u_char)(lives+1);
        printInfoMessage(0x14, 3); // "1UP"
        playSFX(10);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040718);
void func_80040718(unkstruct_800A6D50* arg0)
{
    u_char health;

    if (D_8009BCA0 == 0) {
        health = GAME.playerHealthDisplayed;
        if (health < 16) {
            health += GAME.unk720;
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
            func_8002367C(arg0->unk6B);
        }
        arg0->unk4++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004080C);
void func_8004080C(unkstruct_800A6D50* arg0)
{
    u_short temp_v0;
    u_char temp_v1;

    temp_v1 = arg0->unk5;
    switch (temp_v1) {
        case 0:
            addItemToInventory(ITEM_BITINGPLANTFLOWER, 1, true);
            func_8001E220(EVENT_BITINGPLANTFLOWER, 0, 0);
            if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
                GAME.bittingPlantFlowerState = 2;
            }
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->unk6B);
            }
            arg0->unk22 = 0x12CU;
            asm("");
            D_8009BCA7 = 1;
            D_8009BCAA = 1;
            D_800A539C = 5;
            D_800A539D = 0;
            D_800A539E = 0;
            D_800A539F = 0;
            arg0->unk5++;
            return;
        case 1:
            temp_v0 = arg0->unk22 - 1;
            arg0->unk22 = temp_v0;
            if ((temp_v0 << 0x10) == 0) {
                D_8009BCA7 = 0;
                D_8009BCAA = 0;
                D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                D_800A539F = 0;
                arg0->unk4++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004095C);
void func_8004095C(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLE, 1, true);
    setEventComplete(EVENT_APRECIOUSTREASURECHEST, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800409CC);
void func_800409CC(unkstruct_800A6D50* arg0)
{
    addItemToInventory(ITEM_GRAPPLEJACK, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040A30);
void func_80040A30(unkstruct_800A6D50* arg0)
{
    switch (GAME.event[EVENT_LOSTANDFOUND]) {
        case 0:
            func_8001E220(EVENT_LOSTANDFOUND, 0, 0);
            printInfoMessage(0x16, 3);
            break;
        case 1:
            printInfoMessage(0x17, 3);
            GAME.event[EVENT_LOSTANDFOUND]+= 1;
            break;
        case 2:
            addItemToInventory(ITEM_THREECRYSTALBALLS, 1, true);
            setEventComplete(EVENT_LOSTANDFOUND, 0);
            break;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040B28);
void func_80040B28(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_THEMISTERIOUSMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040B98);
void func_80040B98(unkstruct_800A6D50* arg0)
{
    func_8001E220(EVENT_FLOWERSEEDS, 0, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    addItemToInventory(arg0->item_id, 1, true);
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040C0C);
void func_80040C0C(unkstruct_800A6D50* arg0)
{
    int temp;

    switch (arg0->unk5) {                              // switch 3; irregular
        case 0:                                     // switch 3
            addItemToInventory(arg0->item_id, 1, true);
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->unk6B);
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
            arg0->unk22 = 0x168U;
            arg0->unk5++;
            return;
        case 1:
            temp = arg0->unk22 - 1;
            arg0->unk22 = temp;
            if ((temp << 0x10) == 0) {
                switch (arg0->item_id) {
                    case ITEM_REDPIGBAG:        
                        func_8001E220(EVENT_PHOENIXMOUNTAIN, 0, 3);
                        break;
                    case ITEM_ORANGEPIGBAG:
                        func_8001E220(EVENT_BACCUSVILLAGE, 0, 3);
                        break;
                    case ITEM_YELLOWPIGBAG:
                        func_8001E220(EVENT_TRICKVILLAGE, 0, 3);
                        break;
                    case ITEM_GREENPIGBAG:
                        func_8001E220(EVENT_LAVACAVES, 0, 3);
                        break;
                    case ITEM_BLUEEVILPIGBAG:
                        func_8001E220(EVENT_THE100FLOWERFOREST, 0, 3);
                        break;
                    case ITEM_NAVYPIGBAG:
                        func_8001E220(EVENT_THEDEEPJUNGLEPIG, 0, 3);
                        break;
                    case ITEM_PINKPIGBAG:
                        func_8001E220(EVENT_THEHAUNTEDMANSION, 0, 3);
                        break;
                }
                arg0->unk4++;
            }
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040DA0);
void func_80040DA0(unkstruct_800A6D50* arg0)
{
    if ((GAME.selectedArea == AREA10_DEEPJUNGLE) || (arg0->unkC == 1)) {
        addItemToInventory(arg0->item_id, 1, true);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040E24);
void func_80040E24(unkstruct_800A6D50* arg0)
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
                    func_8002367C(arg0->unk6B);
                    asm("");
                }
                arg0->unk4++;
            } else {
                if ((short)arg0->unk22 == 0) {
                    printInfoMessage(0x26, 2);
                    arg0->unk22 = 0x78;
                } 
                arg0->unk4--;
            }
            break;
        case ITEM_JEWELOFWATER: 
            if (GAME.blueExpLevel == 9) {
                setEventComplete(EVENT_BLUEHIDDENPOWERS, 0);
                addItemToInventory(arg0->item_id, 1, true);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->unk6B);
                    asm("");
                }
                arg0->unk4++;
            } else {
                func_8001E220(EVENT_BLUEHIDDENPOWERS, 0, 0);
                if ((short)arg0->unk22 == 0) {
                    printInfoMessage(0x26, 2);
                    arg0->unk22 = 0x78;
                } 
                arg0->unk4--;
            }
            break;
        case ITEM_JEWELOFWIND:
            if (GAME.greenExpLevel == 9) {
                setEventComplete(EVENT_GREENHIDDENPOWERS, 1);
                addItemToInventory(arg0->item_id, 1, true);
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->unk6B);
                }
                arg0->unk4++;
            } else {
                func_8001E220(EVENT_GREENHIDDENPOWERS, 0, 1);
                if ((short)arg0->unk22 == 0) {
                    printInfoMessage(0x26, 2);
                    arg0->unk22 = 0x78;
                } 
                arg0->unk4--;
            }
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040FD8);
void func_80040FD8(unkstruct_800A6D50* arg0)
{
    setEventComplete(EVENT_ASAFEMUSHROOM, 0);
    addItemToInventory(arg0->item_id, 1, true);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80041048);
void func_80041048(unkstruct_800A6D50* arg0)
{
    printInfoMessage(0xC, 3); // "Animal Dash"
    GAME.area00_eventControl |= 0x40;
    playSFX(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    GAME.unk6ad = 1;
    GAME.unk736 = 1;
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800410D8);
void func_800410D8(unkstruct_800A6D50* arg0)
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
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}
