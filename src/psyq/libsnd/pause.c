#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/pause", _SsSndPause);

/**
 * @brief Internal: pause a sequence
 * 
 * Keys off its voices and clears the pause request flag.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 */
void _SsSndPause(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    _SsVmSeqKeyOff((s16)(arg0 | arg1 << 8));
    score->unk2b = 0;
    _ss_score[arg0][arg1].unk90 &= ~2;
}
