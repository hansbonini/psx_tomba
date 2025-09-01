#include "common.h"
#include "psyq/rand.h"

extern u32 RAND_SEED;

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/rand", rand);
int rand(void) {
    RAND_SEED = (RAND_SEED * 0x41C64E6D) + 12345;
    return (RAND_SEED >> 0x10) & RAND_MAX;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/rand", srand);
void srand(unsigned int seed) {
    RAND_SEED = seed;
}
