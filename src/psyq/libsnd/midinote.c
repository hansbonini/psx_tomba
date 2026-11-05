#include "common.h"
#include "libsnd_i.h"

void _SsVmKeyOn(s16, s16, s16, u16, u16, u16);
void _SsVmKeyOff(s16, s16, s16, u16);

// INCLUDE_ASM("nonmatchings/psyq/libsnd/midinote", _SsNoteOn);
/**
 * @brief Internal: handle a MIDI note on event
 * 
 * Keys on the note on the current channel (unless the channel is muted),
 * or keys it off when the velocity is 0.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @param note Note number
 * @param vel Velocity
 */
void _SsNoteOn(s16 access_num, s16 seq_num, s32 note, s32 vel)
{
    struct SeqStruct* score = &_ss_score[access_num][seq_num];
    u8 tmp = vel;
    u8 ch = score->channel;
    s32 v = tmp & 0xFF;
    u8 pan = score->panpot[ch];

    if (score->unk74 != 0) {
        if (vel & 0xFF) {
            if (!((score->padA6 >> ch) & 1)) {
                _SsVmKeyOn(access_num | (seq_num << 8), score->unk4c,
                           score->programs[ch], note & 0xFF, v, pan);
            }
        } else {
            _SsVmKeyOff(access_num | (seq_num << 8), score->unk4c,
                        score->programs[ch], note & 0xFF);
        }
    }
}
