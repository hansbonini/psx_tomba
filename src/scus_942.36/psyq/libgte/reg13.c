#include "common.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", SetGeomScreen);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", LightColor);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", DpqColorLight);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", DpqColor3);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", Intpl);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", Square12);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", Square0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", AverageZ3);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", AverageZ4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", OuterProduct12);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", OuterProduct0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", Lzc);

long Lzc(long data) {
    long result;

    __asm__ volatile("mtc2 %0, $30" : : "r"(data));
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("mfc2 %0, $31" : "=r"(result));
    return result;
}

__asm__("nop");

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", RotTransPers);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", RotMatrix);
