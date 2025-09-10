#include "common.h"
#include "game.h"

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
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    u8 current_item;

    func_80029788(arg0->item_id, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    current_item = arg0->item_id;
    switch (current_item) {                              // irregular
        case ITEM_BOMB:
            func_8001E31C(EVENT_INEEDABOMB, 4);
            break;
        case ITEM_PIPE:
            D_8009C269 = 1;
            break;
        case ITEM_GOLDENFLOWER:
            D_8009C34C = 1;
            break;
        case ITEM_TEARJAR:
            func_8001E31C(EVENT_INEEDATEARBOTTLE, 1);
            break;
        case ITEM_MIGHTYFISHFOOD:
            func_8001E31C(EVENT_WHATSTHEUNDERWATER, 0);
            break;
        case ITEM_WHATTHETHIEFFORGOT:
            func_8001E220(EVENT_WHATTHETHIEFFORGOT, 1, 1);
            break;
        case ITEM_BOSSJEWEL:
            func_8001E31C(EVENT_THEBOSSTREASURE, 1);
            func_80029548(0x186A0);
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
        func_8001FFE8(9);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->unk6B);
        }
        if (!(arg0->unkC & 0x7F)) {
            *(s16*)&D_800A5430+=1;
            if ((s16)PLAYER_HEALTH_DISPLAYED < *(s16*)&D_800A5430 ) {
                *(s16*)&D_800A5430 = PLAYER_HEALTH_DISPLAYED;
            }
        } else {
            *(s16*)&D_800A5430+=2;
            if ((s16)PLAYER_HEALTH_DISPLAYED < *(s16*)&D_800A5430 ) {
                *(s16*)&D_800A5430 = PLAYER_HEALTH_DISPLAYED;
            }
        }
        D_800A5432 = D_800A5430;
        PLAYER_HEALTH = (u8) D_800A5430;
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
    func_8001FFE8(9);
    arg0->unk4+=1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800403E4);
void func_800403E4(unkstruct_800A6D50* arg0)
{
    func_80029788(ITEM_BAKEDYAM, 1, 1);
    if ((EVENT_LIST[EVENT_SOMETHINGCOOKIN] & 0xFF) == 3) {
        EVENT_LIST[EVENT_SOMETHINGCOOKIN] += 1;
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B, &EVENT_LIST[EVENT_SOMETHINGCOOKIN]);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040468);
void func_80040468(unkstruct_800A6D50* arg0)
{
    D_8009C216 = 5;
    func_80029788(ITEM_DIRTYMIRROR, 1, 1);
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
        func_80031124(0x15, 3);
        func_8001FFE8(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->unk6B);
        }
        arg0->unk4++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040564);
void func_80040564(unkstruct_800A6D50* arg0)
{
    func_80029788(ITEM_WOODBOOMERANG, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800405C8);
void func_800405C8(unkstruct_800A6D50* arg0)
{
    func_80029788(ITEM_STONEBOOMERANG, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004062C);
void func_8004062C(unkstruct_800A6D50* arg0)
{
    func_80029788(ITEM_IRONBOOMERANG, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040690);
void func_80040690(unkstruct_800A6D50* arg0)
{
    u8 lives = *(s8*)&PLAYER_LIVES;
    if (lives < 99) {
        *(s8*)&PLAYER_LIVES=(u8)(lives+1);
        func_80031124(0x14, 3);
        func_8001FFE8(10);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040718);
void func_80040718(unkstruct_800A6D50* arg0)
{
    u8 health;

    if (D_8009BCA0 == 0) {
        health = *(u8*)&PLAYER_HEALTH_DISPLAYED;
        if (health < 16) {
            health += D_8009C3E8;
            *(u8*)&PLAYER_HEALTH_DISPLAYED = health;
            if ((u32) ((s8)health & 0xFF) >= 17) {
                *(u8*)&PLAYER_HEALTH_DISPLAYED = 16;
            }
            func_8001FFE8(10);
            D_800A5430 = (u16*)(*(u8*)&PLAYER_HEALTH_DISPLAYED);
            D_800A5432 = *(u8*)&PLAYER_HEALTH_DISPLAYED;
            *(u8*)&PLAYER_HEALTH = *(u8*)&PLAYER_HEALTH_DISPLAYED;
        }
        D_8009C3E7 = 1;
        D_800B078C = &D_800121C8;
        func_8001FFE8(10);
        if (!(arg0->unkC & 0x80)) {
            func_8002367C(arg0->unk6B);
        }
        arg0->unk4++;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_8004080C);
void func_8004080C(unkstruct_800A6D50* arg0)
{
    u16 temp_v0;
    u8 temp_v1;

    temp_v1 = arg0->unk5;
    switch (temp_v1) {
        case 0:
            func_80029788(ITEM_BITINGPLANTFLOWER, 1, 1);
            func_8001E220(EVENT_BITINGPLANTFLOWER, 0, 0);
            if (*(u16*)&SELECTED_AREA == 0) {
                D_8009C3E3 = 2;
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
    func_80029788(ITEM_GRAPPLE, 1, 1);
    func_8001E31C(EVENT_APRECIOUSTREASURECHEST, 0);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800409CC);
void func_800409CC(unkstruct_800A6D50* arg0)
{
    func_80029788(ITEM_GRAPPLEJACK, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040A30);
void func_80040A30(unkstruct_800A6D50* arg0)
{
    switch (EVENT_LIST[EVENT_LOSTANDFOUND]) {
        case 0:
            func_8001E220(EVENT_LOSTANDFOUND, 0, 0);
            func_80031124(0x16, 3);
            break;
        case 1:
            func_80031124(0x17, 3);
            EVENT_LIST[EVENT_LOSTANDFOUND]+= 1;
            break;
        case 2:
            func_80029788(ITEM_THREECRYSTALBALLS, 1, 1);
            func_8001E31C(EVENT_LOSTANDFOUND, 0);
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
    func_8001E31C(EVENT_THEMISTERIOUSMUSHROOM, 0);
    func_80029788(arg0->item_id, 1, 1);
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
    func_80029788(arg0->item_id, 1, 1);
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040C0C);
void func_80040C0C(unkstruct_800A6D50* arg0)
{
    int temp;

    switch (arg0->unk5) {                              // switch 3; irregular
        case 0:                                     // switch 3
            func_80029788(arg0->item_id, 1, 1);
            if (!(arg0->unkC & 0x80)) {
                func_8002367C(arg0->unk6B);
            }
            switch (arg0->item_id) {
                case ITEM_REDPIGBAG:
                    func_8001E31C(EVENT_ASTORMYPIGBAG, 2);
                    break;
                case ITEM_ORANGEPIGBAG:
                    func_8001E31C(EVENT_THEMOUSEPIGBAG, 2);
                    break;
                case ITEM_YELLOWPIGBAG:
                    func_8001E31C(EVENT_THEUNDERWATERPIG, 2);
                    break;
                case ITEM_GREENPIGBAG:
                    func_8001E31C(EVENT_THEFIREPIGBAG, 2);
                    break;
                case ITEM_BLUEEVILPIGBAG:
                    func_8001E31C(EVENT_THEEVILPIGBAG, 2);
                    break;
                case ITEM_NAVYPIGBAG:
                    func_8001E31C(EVENT_THEJUNGLEPIGBAG, 2);
                    break;
                case ITEM_PINKPIGBAG:
                    func_8001E31C(EVENT_THEHAUNTEDPIGBAG, 2);
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
    if ((*(u16*)&SELECTED_AREA == 0xA) || (arg0->unkC == 1)) {
        func_80029788(arg0->item_id, 1, 1);
    }
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80040E24);
void func_80040E24(unkstruct_800A6D50* arg0)
{
    s32 var_a0;
    s32 var_a2;
    u8 current_item;
    u8 var_v0;
    
    current_item = arg0->item_id;
    switch (current_item) {
        case ITEM_JEWELOFFIRE: 
            if (RED_EXP_LEVEL == 9) {
                func_8001E31C(EVENT_REDHIDDENPOWERS, 1);
                func_80029788(arg0->item_id, 1, 1);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->unk6B);
                    asm("");
                }
                arg0->unk4++;
            } else {
                if ((s16)arg0->unk22 == 0) {
                    func_80031124(0x26, 2);
                    arg0->unk22 = 0x78;
                } 
                arg0->unk4--;
            }
            break;
        case ITEM_JEWELOFWATER: 
            if (BLUE_EXP_LEVEL == 9) {
                func_8001E31C(EVENT_BLUEHIDDENPOWERS, 0);
                func_80029788(arg0->item_id, 1, 1);
                asm("");
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->unk6B);
                    asm("");
                }
                arg0->unk4++;
            } else {
                func_8001E220(EVENT_BLUEHIDDENPOWERS, 0, 0);
                if ((s16)arg0->unk22 == 0) {
                    func_80031124(0x26, 2);
                    arg0->unk22 = 0x78;
                } 
                arg0->unk4--;
            }
            break;
        case ITEM_JEWELOFWIND:
            if (GREEN_EXP_LEVEL == 9) {
                func_8001E31C(EVENT_GREENHIDDENPOWERS, 1);
                func_80029788(arg0->item_id, 1, 1);
                if (!(arg0->unkC & 0x80)) {
                    func_8002367C(arg0->unk6B);
                }
                arg0->unk4++;
            } else {
                func_8001E220(EVENT_GREENHIDDENPOWERS, 0, 1);
                if ((s16)arg0->unk22 == 0) {
                    func_80031124(0x26, 2);
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
    func_8001E31C(EVENT_ASAFEMUSHROOM, 0);
    func_80029788(arg0->item_id, 1, 1);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_80041048);
void func_80041048(unkstruct_800A6D50* arg0)
{
    func_80031124(0xC, 3);
    *(s32*)&AREA00_EVENT_CONTROL |= 0x40;
    func_8001FFE8(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    D_8009C375 = 1;
    D_8009C3FE = 1;
    arg0->unk4++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/events", func_800410D8);
void func_800410D8(unkstruct_800A6D50* arg0)
{   
    if (ITEM_LIST[ITEM_JUMPINGPANTS] == 0) {
        func_80029788(ITEM_JUMPINGPANTS, 1, 1);
    } else if ((ITEM_LIST[ITEM_DASHINGPANTS] == 0)) {
        func_80029788(ITEM_DASHINGPANTS, 1, 1);
    } else if (ITEM_LIST[ITEM_FLASHPANTS] == 0) {
        func_80029788(ITEM_FLASHPANTS, 1, 1);
    }
    func_8001FFE8(10);
    if (!(arg0->unkC & 0x80)) {
        func_8002367C(arg0->unk6B);
    }
    arg0->unk4++;
}
