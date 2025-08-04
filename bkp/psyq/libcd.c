#include "common.h"
#include "libdma.h"
#include "psyq/libcd.h"
#include "psyq/stdio.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdInit);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", EVENT_OBJ_10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", EVENT_OBJ_5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", EVENT_OBJ_7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbsync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbready);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbread);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", DeliverEvent);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdStatus);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdLastCom);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdLastPos);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReset);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_68);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdFlush);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSetDebug);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdComstr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_108);

void SYS_OBJ_110(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdIntstr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_13C);

void SYS_OBJ_144(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReady);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSyncCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadyCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControl);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_214);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_250);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_280);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_2A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_2C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControlF);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_344);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_380);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_3D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_3F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControlB);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_470);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_4AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_4DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_500);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_518);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_534);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SYS_OBJ_538);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdMix);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdGetSector);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdDataCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdDataSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdIntToPos);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdPosToInt);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", getintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_64);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_154);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_198);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_23C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_26C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_298);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_2B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_304);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_31C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_324);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_34C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_36C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_378);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_398);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_3B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_3D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_3DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_3FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_414);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_43C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_470);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_488);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_4A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_4B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_4C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_4F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_510);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_528);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_540);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_548);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_56C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_sync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_5F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_63C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_6B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_6B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_6E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_728);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_72C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_764);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_774);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_7B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_7CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_7D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_7DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_ready);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_87C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_8C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_938);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_93C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_96C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_9B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_9B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_9EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_9FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_A2C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_A4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_A7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_A94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_A9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_AA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_cw);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_B38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_B98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_BB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_BE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_BF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_C28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_C58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_CEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_D34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_DA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_DAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_E94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_EAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_EC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_vol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_flush);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_FAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_FFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_initvol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1094);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1098);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_initintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_init);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1298);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1328);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1378);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_datasync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_13E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1430);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_14A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_14A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_14D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_getsector);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_157C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_15C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_15DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_set_test_parmnum);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", callback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_167C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_1680);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", BIOS_OBJ_16B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", puts);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", PUTS_OBJ_24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", PUTS_OBJ_2C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", cb_read);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_108);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_160);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_198);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_1F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_1FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", cd_read_retry);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_274);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_2A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_2F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_32C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_350);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_3C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadBreak);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdRead);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_46C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_4F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_538);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_588);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_59C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_5A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD_OBJ_5B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdRead2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD2_OBJ_48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD2_OBJ_50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CDREAD2_OBJ_70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StCdInterrupt2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StClearRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StUnSetRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", data_ready_callback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_004_OBJ_78);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StGetBackloc);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_004_OBJ_D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_004_OBJ_DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetStream);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StFreeRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_007_OBJ_64);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_007_OBJ_78);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_007_OBJ_9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_007_OBJ_AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", init_ring_status);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_008_OBJ_C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_008_OBJ_30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StGetNext);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_009_OBJ_4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_009_OBJ_64);

void C_009_OBJ_BC(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetMask);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StCdInterrupt);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_144);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_1C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_1F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_20C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_24C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_270);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_294);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_364);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_36C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_3A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_3CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_3D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_3F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_42C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_4A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_4B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_564);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_594);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_640);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_650);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_6A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_6B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_6D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_6FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_710);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_7A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_7BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_838);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_85C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_884);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_8DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_900);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_960);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", mem2mem);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_97C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_998);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", dma_execute);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_A08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_A54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_A78);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_A90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_B14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", C_011_OBJ_B28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_108);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_130);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", v_wait);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_170);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_1BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSYNC_OBJ_1D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", ChangeClearRCnt);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", ResetCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", InterruptCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", DMACallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSyncCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSyncCallbacks);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StopCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", RestartCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CheckCallback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", GetIntrMask);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", SetIntrMask);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", startIntr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", INTR_OBJ_210);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", INTR_OBJ_260);
