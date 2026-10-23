#include "common.h"
#include "psyq/libstamp.h"

PsyqStamp libcard_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_CARD, 19, 14, 52);

// INCLUDE_ASM("nonmatchings/psyq/libcard/init", InitCARD);
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

// INCLUDE_ASM("nonmatchings/psyq/libcard/init", StartCARD);
void StartCARD(void) {
    EnterCriticalSection();
    StartCARD2();
    ChangeClearPAD(0);
    ExitCriticalSection();
    return;
}

// INCLUDE_ASM("nonmatchings/psyq/libcard/init", StopCARD);
void StopCARD(void)
{
    StopCARD2();
    _patch_card2();
    func_8005CF68();
    return;
}
