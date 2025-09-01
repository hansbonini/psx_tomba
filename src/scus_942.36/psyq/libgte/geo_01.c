#include "common.h"

extern s16 RSIN_TABLE[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/geo_01", rcos);
int rcos(int a) {
    if (a < 0) {
        a = -a;
    }
    a &= 0xFFF;

    if (a < 0x801) {
        if (a < 0x401) {
            return RSIN_TABLE[0x400 - a];
        }
        return -RSIN_TABLE[a - 0x400];
    } else {
        if (a < 0xC01) {
            return -RSIN_TABLE[0xC00 - a];
        }
        return RSIN_TABLE[a - 0xC00];
    }
}