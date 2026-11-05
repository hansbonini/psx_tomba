#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/sr_gaks", SpuRGetAllKeysStatus);

/**
 * @brief Get the key status of a range of voices
 * 
 * For each voice in the range, reports whether it is keyed on/off and
 * whether its envelope is still sounding.
 * 
 * @param min First voice
 * @param max Last voice
 * @param status Receives one status per voice (SPU_OFF, SPU_ON, SPU_OFF_ENV_ON, SPU_ON_ENV_OFF)
 * @return 0 on success, -3 for an invalid range
 */
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

// INCLUDE_ASM("nonmatchings/psyq/libspu/sr_gaks", SpuGetAllKeysStatus);

/**
 * @brief Get the key status of all voices
 * 
 * Calls SpuRGetAllKeysStatus() for every voice.
 * 
 * @param status Receives 24 status values
 */
void SpuGetAllKeysStatus(s8* status) {
    SpuRGetAllKeysStatus(0, NUM_SPU_CHANNELS, status);
}
