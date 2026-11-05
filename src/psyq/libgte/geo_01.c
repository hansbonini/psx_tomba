#include "common.h"

extern s16 RSIN_TABLE[];

// INCLUDE_ASM("nonmatchings/psyq/libgte/geo_01", rcos);
/**
 * @brief Fixed-point cosine
 * 
 * Looks up the cosine of an angle in the sine table. 4096 = 360 degrees,
 * 4096 = 1.0.
 * 
 * @param a Angle (4096 = 360 degrees)
 * @return Cosine in 1.3.12 fixed point
 */
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