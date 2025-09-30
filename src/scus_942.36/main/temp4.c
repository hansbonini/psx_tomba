#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002E964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002EB3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002EB80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002EBC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002ED1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002EF20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F05C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F138);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F220);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F56C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F7C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002F948);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8002FA24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80030734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_8003076C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_800307AC);
void func_800307AC(s32 arg0, s32 arg1, s32 arg2)
{
    func_80030800(arg0, arg1, arg2, 1, -1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_800307D4);
void func_800307D4(s32 arg0, s32 arg1, s32 arg2, s16 arg3)
{
    func_80030800(arg0, arg1, arg2, 1, arg3);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80030800);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80030A54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80030E30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80030EF8);

/*
 0x00 = Adquired
 0x01 = Used the
 0x02 = It's Locked
 0x03 = Adquired
 0x04 = Hourglass
*/
INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", printInfoMessage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80031628);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_800316EC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp4", func_80031868);
void func_80031868(void)
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
