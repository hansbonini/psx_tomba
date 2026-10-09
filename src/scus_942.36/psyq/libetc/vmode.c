#include "common.h"

extern int D_80097504;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", SetVideoMode);

long SetVideoMode(long mode) {
    long prev = D_80097504;
    D_80097504 = mode;
    return prev;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vmode", GetVideoMode);

int GetVideoMode(void) { return D_80097504; }
