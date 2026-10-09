#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/sr_gaks", SpuRGetAllKeysStatus);

inline s32 SpuRGetAllKeysStatus(s32 min, s32 max, s8* status) {
    s32 voice;
    u16 volumex;
    s32 bit;

    if (min < 0) {
        min = 0;
    }
    if (min >= NUM_SPU_CHANNELS) {
        return -3;
    }
    if (max >= NUM_SPU_CHANNELS) {
        max = NUM_SPU_CHANNELS - 1;
    }
    if (max < 0 || max < min) {
        return -3;
    }

    max++;
    for (voice = min; voice < max; voice++) {
        volumex = _spu_RXX->raw[(8 * voice) + 6];
        if (_spu_keystat & (u32)(1 << voice)) {
            if (volumex != 0) {
                status[voice] = 1;
            } else {
                status[voice] = 3;
            }
        } else {
            if (volumex != 0) {
                status[voice] = 2;
            } else {
                status[voice] = 0;
            }
        }
    }

    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/sr_gaks", SpuGetAllKeysStatus);

void SpuGetAllKeysStatus(s8* status) {
    SpuRGetAllKeysStatus(0, NUM_SPU_CHANNELS, status);
}
