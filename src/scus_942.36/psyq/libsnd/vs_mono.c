#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vs_mono", SsSetMono);

void SsSetMono(void) { _svm_stereo_mono = 1; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vs_mono", SsSetStereo);

void SsSetStereo(void) { _svm_stereo_mono = 0; }
