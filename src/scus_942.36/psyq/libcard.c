#include "common.h"

BIOS_STUB(_card_info, 0xA0, 0xAB);

BIOS_STUB(_card_load, 0xA0, 0xAC);

void _card_clear(s32 arg0)
{
    _new_card();
    _card_write(arg0, 0x3F, 0);
}

BIOS_STUB(_card_write, 0xB0, 0x4E);

BIOS_STUB(_new_card, 0xB0, 0x50);

void InitCARD(long val)
{
    ChangeClearPAD(0);
    EnterCriticalSection();
    InitCARD2(val);
    _patch_card();
    _patch_card2();
    ExitCriticalSection();
    return;
}

void StartCARD(void) {
    EnterCriticalSection();
    StartCARD2();
    ChangeClearPAD(0);
    ExitCriticalSection();
    return;
}

void StopCARD(void)
{
    StopCARD2();
    _patch_card2();
    func_8005CF68();
    return;
}

BIOS_STUB(ChangeClearPAD, 0xB0, 0x5B);

BIOS_STUB(InitCARD2, 0xB0, 0x4A);

BIOS_STUB(StartCARD2, 0xB0, 0x4B);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StopCARD2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CEA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF68);
