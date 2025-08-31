#include "common.h"

extern u32 D_8009B138;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/rand", rand);
int rand(void) {
    u_long nNext;

    nNext = (D_8009B138 * 0x41C64E6D) + 0x3039;
    D_8009B138 = nNext;
    return (nNext >> 0x10) & 0x7FFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/rand", srand);
void srand(u_long seed) {
    D_8009B138 = seed;
}
