#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);

void _SsContExternal(s16 access_num, s16 seq_num, u8 data) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    SsUtSetReverbDepth(data, data);
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
