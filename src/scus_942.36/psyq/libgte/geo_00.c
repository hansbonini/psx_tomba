#include "common.h"

extern s16 RSIN_TABLE[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/geo_00", rsin);
s32 rsin(s32 arg0) {
    if (arg0 < 0) {
        return -sin_1(-arg0 & 0xFFF);
    }
    return sin_1(arg0 & 0xFFF);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/geo_00", sin_1);
s32 sin_1(s32 arg0) {
    if (arg0 < 0x801) {
        if (arg0 < 0x401) {
            return RSIN_TABLE[arg0];
        } else {
            return RSIN_TABLE[0x800 - arg0];
        }
    } else {
        if (arg0 < 0xC01) {
            return -1 * RSIN_TABLE[arg0 - 0x800];
        } else {
            return -1 * RSIN_TABLE[0x1000 - arg0];
        }
    }
}
