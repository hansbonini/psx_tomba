#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_80033F50);
void func_80033F50(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80120054();
    } else if (GAME.selectedArea == AREA06_DIRTMOTOCROSS) {
        func_80119BCC();
    } else if (GAME.selectedArea == AREA11_VILLAGEOFCIVILIZATION){
        func_80115724();
    }
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_80033FB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_80033FF0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_800340FC);
void func_800340FC(void)
{
    switch (GAME.selectedArea) {
        case AREA01_DWARFFOREST:
            func_8011FD7C();
            return;
        case AREA02_DWARFVILLAGE:
            func_80116C44();
            return;
        case AREA03_PHOENIXMOUNTAIN:
            func_8011CB9C();
            return;
        case AREA04_HAUNTEDMANSION:
            func_8011C210();
            return;
        case AREA09_MUSHROOMVILLAGE:
            func_8011C0D4();
            return;
        case AREA10_DEEPJUNGLE:
            func_80119AC8();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_80115DB0();
            // fallthrough
        default:
            return;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_800341AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_8003438C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_80034420);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_80034524);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp8", func_800346A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800108AC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800108C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010974);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800109E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010A6C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010B10);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010BFC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010D48);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010D6C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010E48);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010E7C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010ED8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010F0C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010F58);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010FBC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80010FE0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011000);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011020);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011040);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011048);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011050);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011058);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011060);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011068);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011070);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011090);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110B0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110D0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110D8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800110F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800111A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800111E4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800111F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011244);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800112A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800112DC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011340);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011384);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800113B8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800113FC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011440);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001153C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011678);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800116DC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011760);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011794);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800117C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80011804);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L800118F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011934);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011978);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L800119BC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011A00);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011A44);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011A88);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011ACC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011B10);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011B54);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011B98);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011BDC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011C20);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011C64);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011CA8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011CEC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011CFC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D0C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D1C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D3C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D5C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D7C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011D9C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DA4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DAC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DB4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DCC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DE4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011DFC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E1C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E3C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E5C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E6C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E7C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011E8C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011EB4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", .L80011EDC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012014);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012194);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800121A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800121C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012208);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001224C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012260);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800122B0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012310);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012314);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012318);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001232C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012330);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012334);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012354);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012364);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012368);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800123C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800123CC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800123E4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800123F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800123F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012400);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012408);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012410);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012418);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012420);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012428);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012430);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012438);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012440);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012448);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012450);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012490);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124C0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124D0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124D8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800124F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012500);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012508);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012510);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012518);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012520);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012528);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012530);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012538);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012540);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012548);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012550);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012558);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012560);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012568);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012570);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012578);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012580);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012588);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012590);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012598);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125A0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125B0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125B8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125C0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125D0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125D8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800125F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012600);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012608);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012610);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012650);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012658);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012660);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012668);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012670);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012678);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012680);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012688);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012698);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126A0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126B0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126B8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126C0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126C8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126D0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126D8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800126F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012700);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012708);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012710);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012718);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012720);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012728);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012730);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012780);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127D0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127D8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127E8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800127F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012800);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012808);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012810);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012818);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012820);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012828);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012830);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012854);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001287C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012894);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128AC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128B4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128BC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128C4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128CC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128D4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128DC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128E4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128EC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128F4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800128FC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012904);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001290C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012914);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012954);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001296C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_8001298C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012994);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129B4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129BC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129DC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129E4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129EC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129F4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_800129FC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A04);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A0C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A14);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A1C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A24);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A2C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A34);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012A98);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012AA0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012AA8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012B68);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012B9C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012BB8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012BFC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012C18);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012C34);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012C5C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012C80);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012C98);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012CBC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012CC4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012CCC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012CD4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012CE8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D0C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D20);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D28);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D78);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D80);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012D88);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012DAC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp8", D_80012DE0);
