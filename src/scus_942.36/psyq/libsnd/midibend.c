#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midibend", _SsSetPitchBend);

void _SsSetPitchBend(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    u8 channel = score->channel;
    u8* temp_v1;

    temp_v1 = score->read_pos++;
    _SsVmPitchBend(
        (s16)(arg0 | (arg1 << 8)), score->unk4c, score->programs[channel], *temp_v1);
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
