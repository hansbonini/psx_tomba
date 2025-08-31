#include "common.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_info);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(_card_info, 0xA0, 0xAB);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_load);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(_card_load, 0xA0, 0xAC);
// #endif

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_clear);
void _card_clear(s32 arg0)
{
    _new_card();
    _card_write(arg0, 0x3F, 0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _card_write);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(_card_write, 0xB0, 0x4E);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _new_card);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(_new_card, 0xB0, 0x50);
// #endif

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", InitCARD);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StartCARD);
void StartCARD(void) {
    EnterCriticalSection();
    StartCARD2();
    ChangeClearPAD(0);
    ExitCriticalSection();
    return;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StopCARD);
void StopCARD(void)
{
    StopCARD2();
    _patch_card2();
    func_8005CF68();
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", ChangeClearPAD);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(ChangeClearPAD, 0xB0, 0x5B);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", InitCARD2);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(InitCARD2, 0xB0, 0x4A);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StartCARD2);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(StartCARD2, 0xB0, 0x4B);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", StopCARD2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CEA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", _patch_card2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcard", func_8005CF68);
