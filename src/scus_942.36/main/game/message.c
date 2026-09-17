#include "common.h"
#include "game.h"

typedef struct msgBox {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
} msgBox;


INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002E964);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", initMsgBoxA);
void initMsgBoxA(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C94;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 0;
    self[6] = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", initMsgBoxB);
void initMsgBoxB(u8* self)
{
    *(void**)(self + 0x24) = &D_80014C8C;
    readAnimFrameCount(self);
    self[4] = 1;
    self[5] = 1;
    self[6] = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002EBC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002ED1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002EF20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F05C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F138);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F220);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F56C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", dispatchMsgBoxHandler);
void dispatchMsgBoxHandler(u8* self)
{
    D_8007C848[self[3]]();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002F948);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_8002FA24);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBox);
void showMessageBox(s32 arg0, s32 arg1, s16 arg2, s16 arg3)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    func_80030800(arg0, arg1, &box, 0, -1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxTimed);
void showMessageBoxTimed(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4)
{
    msgBox box;

    box.unk2 = arg2;
    box.unk6 = arg3;
    box.unkA = 0;
    func_80030800(arg0, arg1, &box, 0, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxDirect);
void showMessageBoxDirect(s32 arg0, s32 arg1, s32 arg2)
{
    func_80030800(arg0, arg1, arg2, 1, -1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", showMessageBoxDirectTimed);
void showMessageBoxDirectTimed(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    func_80030800(arg0, arg1, arg2, 1, arg3);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_80030800);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_80030A54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_80030E30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_80030EF8);

/*
 0x00 = Adquired
 0x01 = Equipped the
 0x02 = Special Message
 0x03 = Special Message Adquired
 0x04 = Hourglass
*/
INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", printInfoMessage);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", drawInfoMessageText);
void drawInfoMessageText(void* obj, s32 stringIndex)
{
    u8*      base;
    s16*     tbl;
    s16*     ent;
    u_short* str;
    s32      token;

    base = *(u8**)(PSX_SCRATCH + 0x398);
    tbl  = (s16*)(base + *(s16*)(base + 8));
    ent  = tbl + stringIndex;
    str  = (u_short*)((u8*)tbl + *ent);

    for (;;) {
        token = *str++;

        if ((u_short)(token + 2) < 2) {
            return;
        }
        if ((s16)token == -3) continue;
        if ((s16)token == -7) continue;
        if ((s16)token == -6) {
            str += 2;
            continue;
        }
        func_800316EC(obj, (s16)token);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", func_800316EC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/message", dispatchAreaDialogInit);
void dispatchAreaDialogInit(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF7C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F5D5C();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800EFC0C();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F026C();
            return;
        case AREA08_BACCUSLAKE:
            func_800F0A60();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F0590();
        default:
            return;
    }
}
