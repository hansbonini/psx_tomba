#include "common.h"
#include "psyq/libstamp.h"

PsyqStamp libcard_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_CARD, 19, 14, 52);

// INCLUDE_ASM("nonmatchings/psyq/libcard/init", InitCARD);
/**
 * @brief Initialize the memory card system
 * 
 * Disables the BIOS pad clearing, initializes the BIOS card driver and
 * installs the library's card patches, all inside a critical section.
 * 
 * @param val Pad sharing mode: 1 = card and pad share the controller port interrupt
 */
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
/**
 * @brief Start the memory card system
 * 
 * Starts the BIOS card driver and disables the BIOS pad clearing inside a
 * critical section.
 */
void StartCARD(void) {
    EnterCriticalSection();
    StartCARD2();
    ChangeClearPAD(0);
    ExitCriticalSection();
    return;
}

// INCLUDE_ASM("nonmatchings/psyq/libcard/init", StopCARD);
/**
 * @brief Stop the memory card system
 * 
 * Stops the BIOS card driver, reapplies the card patch and calls an
 * internal cleanup routine.
 */
void StopCARD(void)
{
    StopCARD2();
    _patch_card2();
    func_8005CF68();
    return;
}
