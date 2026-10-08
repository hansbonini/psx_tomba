#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_snv", SpuSetNoiseVoice);

void SpuSetNoiseVoice(s32 a, s32 b) { _SpuSetAnyVoice(a, b, 0xCA, 0xCB); }
