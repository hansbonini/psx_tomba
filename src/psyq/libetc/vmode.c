#include "common.h"

#if defined(VERSION_SLPS_01144)
u32 D_80097504_d[3] asm("D_80097504") = {
    0x00000000, 0x00000000, 0x00000000,
};
#elif defined(VERSION_SCES_01331)
u32 D_80097504_d[3] asm("D_80097504") = {
    0x00000000, 0x280C7350, 0x1043062C,
};
#else
u32 D_80097504_d[3] asm("D_80097504") = {
    0x00000000, 0x220C7350, 0x1042998B,
};
#endif

extern int D_80097504;

// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", SetVideoMode);

long SetVideoMode(long mode) {
    long prev = D_80097504;
    D_80097504 = mode;
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", GetVideoMode);

int GetVideoMode(void) { return D_80097504; }
