#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg12", SetGeomOffset);

void SetGeomOffset(long ofx, long ofy) {
    __asm__ volatile("sll $4, %0, 16; sll $5, %1, 16; ctc2 $4, $24; ctc2 $5, $25" : : "r"(ofx), "r"(ofy));
}

__asm__("nop");
__asm__("nop");
