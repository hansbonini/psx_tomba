#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vs_srv", SsSetReservedVoice);

/**
 * @brief Set the number of voices managed by libsnd
 * 
 * Limits voice allocation to the first voices, leaving the others free for
 * direct use.
 * 
 * @param voices Number of voices (1-24)
 * @return Number of voices set, or -1 if invalid
 */
char SsSetReservedVoice(char voices) {
    if ((voices >= 0x19) || (voices == 0)) {
        return -1;
    }
    spuVmMaxVoice = voices;
    return spuVmMaxVoice;
}
