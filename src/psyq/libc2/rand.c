#include "common.h"
#include "psyq/rand.h"

extern u32 RAND_SEED;

//INCLUDE_ASM("nonmatchings/psyq/libc2/rand", rand);
/**
 * @brief Generate a pseudo-random number
 * 
 * Advances the linear congruential generator seed and returns its upper
 * bits.
 * 
 * @return Pseudo-random value between 0 and RAND_MAX (0x7FFF)
 */
int rand(void) {
    RAND_SEED = (RAND_SEED * 0x41C64E6D) + 12345;
    return (RAND_SEED >> 0x10) & RAND_MAX;
}

// INCLUDE_ASM("nonmatchings/psyq/libc2/rand", srand);
/**
 * @brief Seed the pseudo-random number generator
 * 
 * Sets the seed used by rand().
 * 
 * @param seed New seed value
 */
void srand(unsigned int seed) {
    RAND_SEED = seed;
}
