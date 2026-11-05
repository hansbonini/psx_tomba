#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);
void _SsVmDamperOff(void);
void _SsVmDamperOn(void);

/**
 * @brief Internal: handle MIDI controller 64 (damper pedal)
 * 
 * Turns the damper on for values of 64 and above, off otherwise.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @param data Controller data value
 */
void _SsContDamper(s16 access_num, s16 seq_num, u8 data) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    if (data < 0x40) {
        _SsVmDamperOff();
    } else {
        _SsVmDamperOn();
    }
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
