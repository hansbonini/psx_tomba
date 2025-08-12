#include "common.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_info);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_load);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_clear);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_write);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _new_card);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", ChangeClearPAD);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", InitCARD2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StartCARD2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StopCARD2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CEA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF68);
