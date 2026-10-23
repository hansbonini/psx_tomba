#include "common.h"
#include "libsnd_i.h"

void _SsVmKeyOn(s16, s16, s16, u16, u16, u16);
void _SsVmKeyOff(s16, s16, s16, u16);

// INCLUDE_ASM("nonmatchings/psyq/libsnd/midinote", _SsNoteOn);
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
