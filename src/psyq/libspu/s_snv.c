#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_snv", SpuSetNoiseVoice);

/**
 * @brief Select the voices that output noise
 * 
 * Sets or clears voices in the noise mode register.
 * 
 * @param a SPU_ON (1) = enable noise, SPU_OFF (0) = disable
 * @param b Bit mask of the voices
 */
void SpuSetNoiseVoice(s32 a, s32 b) { _SpuSetAnyVoice(a, b, 0xCA, 0xCB); }
