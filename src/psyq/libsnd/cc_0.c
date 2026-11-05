#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);

/**
 * @brief Internal: handle MIDI controller 0 (bank change)
 * 
 * Reads the new VAB number from the score data, makes it the current bank
 * of the sequence and reads the next delta time.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 */
void _SsContBankChange(s16 access_num, s16 seq_num) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    score->unk4c = *score->read_pos++;
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
