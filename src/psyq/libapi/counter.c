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

int (*_interruptReg)[2] = (int (*)[2])0x1F801070;
volatile RootCounter (*_rootCounter0)[3] = (volatile RootCounter (*)[3])0x1F801100;
long _interruptMasks[6] = {0x10, 0x20, 0x40, 0x01, 0, 0};

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", SetRCnt);

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

long GetRCnt(u_long spec) {
    int i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return (*_rootCounter0)[i].currentVal;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", StartRCnt);

long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] |= _interruptMasks[i];
    return i < 3;
}

long StopRCnt(u_long spec) {
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] &= ~_interruptMasks[i];
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", ResetRCnt);

long ResetRCnt(u_long spec) {
    int i;

    i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    (*((RootCounter(*)[3])_rootCounter0))[i].currentVal = 0;
    return 1;
}
