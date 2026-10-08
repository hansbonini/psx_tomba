#include "common.h"
#include "libsnd_i.h"

s32 SpuSetReverb(s32);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_rfb", SsUtSetReverbFeedback);

void SsUtSetReverbFeedback(s16 feedback) {
    _svm_rattr.mask = SPU_REV_FEEDBACK;
    _svm_rattr.feedback = feedback;
    SpuSetReverbModeParam(&_svm_rattr);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_rfb", SsUtReverbOff);

void SsUtReverbOff(void) { SpuSetReverb(0); }

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_rfb", func_80070884);
