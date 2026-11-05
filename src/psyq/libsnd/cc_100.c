#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/cc_100", _SsContRpn1);

/**
 * @brief Internal: handle MIDI controller 100 (RPN LSB)
 * 
 * Stores the low byte of the registered parameter number for a following
 * data entry and reads the next delta time.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 * @param arg2 Controller data value
 */
void _SsContRpn1(s16 arg0, s16 arg1, u8 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];

    score->unk13 = arg2;
    score->unk29 += 1;
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
