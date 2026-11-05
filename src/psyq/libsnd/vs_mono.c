#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vs_mono", SsSetMono);

/**
 * @brief Select monaural output
 * 
 * Voices use the same volume on both sides.
 */
void SsSetMono(void) { _svm_stereo_mono = 1; }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vs_mono", SsSetStereo);

/**
 * @brief Select stereo output
 * 
 * Voices are panned normally.
 */
void SsSetStereo(void) { _svm_stereo_mono = 0; }
