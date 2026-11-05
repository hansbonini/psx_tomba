#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);

/**
 * @brief Internal: handle MIDI controller 91 (effect depth)
 * 
 * Sets the reverb depth of both channels to the controller value.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @param data Controller data value
 */
void _SsContExternal(s16 access_num, s16 seq_num, u8 data) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    SsUtSetReverbDepth(data, data);
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
