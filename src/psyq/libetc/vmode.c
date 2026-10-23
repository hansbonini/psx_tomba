#include "common.h"

u32 D_80097504_d[1] asm("D_80097504") = {
    0x00000000,
};

extern int D_80097504;

// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", SetVideoMode);

long SetVideoMode(long mode) {
    long prev = D_80097504;
    D_80097504 = mode;
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", GetVideoMode);

int GetVideoMode(void) { return D_80097504; }
