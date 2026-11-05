#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Set the repeat count of a sequence
 * 
 * Sets how many times the sequence is played.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @param l_count Number of repetitions (0 = infinite)
 */
void SsSetLoop(s16 access_num, s16 seq_num, s16 l_count) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    score->unk46 = l_count;
    score->unk48 = 0;
}

/**
 * @brief Check whether a sequence is playing
 * 
 * Returns the playing flag of the sequence.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @return 1 while the sequence is playing, 0 at the end of the sequence
 */
s16 SsIsEos(s16 access_num, s16 seq_num) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    return score->unk2b;
}
