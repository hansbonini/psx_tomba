#include "common.h"

typedef struct {
    u_short currentVal;
    short : 16;
    u_short mode;
    short : 16;
    u_short targetVal;
    short : 16;
    int : 32;
} RootCounter;

/** @brief Interrupt status/mask registers (I_STAT/I_MASK) */
int (*_interruptReg)[2] = (int (*)[2])0x1F801070;
/** @brief Hardware root counter register blocks 0-2 */
volatile RootCounter (*_rootCounter0)[3] = (volatile RootCounter (*)[3])0x1F801100;
/** @brief Interrupt mask bit of each root counter (index 3 = VBlank) */
long _interruptMasks[6] = {0x10, 0x20, 0x40, 0x01, 0, 0};

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", SetRCnt);

/**
 * @brief Configure a root counter
 * 
 * Stops the selected root counter, writes its target value and programs
 * its mode register. Counters 0 and 1 can use the pixel/hblank clock
 * source (RCntMdSC) and free-run when interrupt mode is not set; counter 2
 * can use the 1/8 system clock prescaler. Bit 0x1000 of mode enables the
 * counter interrupt.
 * 
 * @param counter Root counter specifier (RCntCNT0..RCntCNT2; only the low 16 bits are used)
 * @param targetVal Target value at which the counter resets / raises an interrupt
 * @param mode Mode flags (RCntMdINTR, RCntMdSC, ...)
 * @return 1 on success, 0 if the counter number is invalid
 */
long SetRCnt(u_long counter, u_short targetVal, long mode) {
    int i;
    u_short newMode;

    i = counter & 0xFFFF;
    newMode = 0x48;

    if (i >= 3) {
        return 0;
    }

    (*_rootCounter0)[i].mode = 0;
    (*_rootCounter0)[i].targetVal = targetVal;

    if (i < 2u) {
        if (mode & 0x10) {
            newMode = 0x49;
        }
        if (!(mode & 1)) {
            newMode |= 0x100;
        }
    } else {
        if (i == 2) {
            if (!(mode & 1)) {
                newMode = 0x248;
            }
        }
    }
    if ((mode & 0x1000) != 0) {
        newMode |= 0x10;
    }
    (*_rootCounter0)[i].mode = newMode;
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", GetRCnt);

/**
 * @brief Read the current value of a root counter
 * 
 * Returns the live count register of the requested root counter.
 * 
 * @param spec Root counter specifier (RCntCNT0..RCntCNT2)
 * @return Current counter value, or 0 if the counter number is invalid
 */
long GetRCnt(u_long spec) {
    int i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return (*_rootCounter0)[i].currentVal;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", StartRCnt);

/**
 * @brief Enable the interrupt of a root counter
 * 
 * Sets the counter bit in the interrupt mask register so that the counter
 * starts delivering interrupts.
 * 
 * @param spec Root counter specifier (RCntCNT0..RCntCNT3; 3 selects VBlank)
 * @return 1 if the counter number is below 3, 0 otherwise
 */
long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] |= _interruptMasks[i];
    return i < 3;
}

/**
 * @brief Disable the interrupt of a root counter
 * 
 * Clears the counter bit in the interrupt mask register.
 * 
 * @param spec Root counter specifier (RCntCNT0..RCntCNT3)
 * @return Always 1
 */
long StopRCnt(u_long spec) {
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] &= ~_interruptMasks[i];
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", ResetRCnt);

/**
 * @brief Reset a root counter to zero
 * 
 * Clears the current count register of the requested root counter.
 * 
 * @param spec Root counter specifier (RCntCNT0..RCntCNT2)
 * @return 1 on success, 0 if the counter number is invalid
 */
long ResetRCnt(u_long spec) {
    int i;

    i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    (*((RootCounter(*)[3])_rootCounter0))[i].currentVal = 0;
    return 1;
}
