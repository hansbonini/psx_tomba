#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rdel", SsUtSetReverbDelay);

/**
 * @brief Set the reverb delay time
 * 
 * Only affects the echo and delay reverb types.
 * 
 * @param delay Delay time (0-127)
 */
void SsUtSetReverbDelay(short delay) {
    _svm_rattr.mask = SPU_REV_DELAYTIME;
    _svm_rattr.delay = delay;
    SpuSetReverbModeParam(&_svm_rattr);
}
