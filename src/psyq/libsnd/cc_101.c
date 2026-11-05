#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/cc_101", _SsContRpn2);

/**
 * @brief Internal: handle MIDI controller 101 (RPN MSB)
 * 
 * Stores the high byte of the registered parameter number for a following
 * data entry and reads the next delta time.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 * @param arg2 Controller data value
 */
void _SsContRpn2(s16 arg0, s16 arg1, u8 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];

    score->unk14 = arg2;
    score->unk29 += 1;
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
