#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/midiprog", _SsSetProgramChange);

/**
 * @brief Internal: handle a MIDI program change event
 * 
 * Sets the program of the current channel and reads the next delta time.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 * @param arg2 Program number
 */
void _SsSetProgramChange(s16 arg0, s16 arg1, u8 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    score->programs[score->channel] = arg2;
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
