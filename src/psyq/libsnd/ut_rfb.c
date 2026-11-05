#include "common.h"
#include "libsnd_i.h"

s32 SpuSetReverb(s32);

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rfb", SsUtSetReverbFeedback);

/**
 * @brief Set the reverb feedback
 * 
 * Only affects the echo reverb type.
 * 
 * @param feedback Feedback amount (0-127)
 */
void SsUtSetReverbFeedback(s16 feedback) {
    _svm_rattr.mask = SPU_REV_FEEDBACK;
    _svm_rattr.feedback = feedback;
    SpuSetReverbModeParam(&_svm_rattr);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rfb", SsUtReverbOff);

/**
 * @brief Turn reverb off
 * 
 * Disables the SPU reverb unit.
 */
void SsUtReverbOff(void) { SpuSetReverb(0); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rfb", SsUtReverbOn);

/**
 * @brief Turn reverb on
 * 
 * Enables the SPU reverb unit.
 */
void SsUtReverbOn(void) { SpuSetReverb(1); }
