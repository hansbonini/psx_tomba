#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/cc_121", _SsContResetAll);

/**
 * @brief Internal: handle MIDI controller 121 (reset all controllers)
 * 
 * Turns reverb and the damper off and resets the program, volume, pan and
 * RPN state of the current channel.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 */
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
