#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midiprog", _SsSetProgramChange);

void _SsSetProgramChange(s16 arg0, s16 arg1, u8 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    score->programs[score->channel] = arg2;
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
