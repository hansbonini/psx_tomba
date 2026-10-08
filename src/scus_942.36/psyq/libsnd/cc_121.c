#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/cc_121", _SsContResetAll);

void _SsContResetAll(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];

    SsUtReverbOff();
    _SsVmDamperOff();
    score->programs[score->channel] = score->channel;
    score->unk13 = 0;
    score->unk14 = 0;
    score->vol[score->channel] = 0x7f;
    score->panpot[score->channel] = 0x40;
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
