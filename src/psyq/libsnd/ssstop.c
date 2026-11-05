#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssstop", _SsSndStop);

/**
 * @brief Internal: stop a sequence and rewind it
 * 
 * Keys off its voices and resets the playback state, tempo, position and
 * channel settings to their initial values.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 */
void _SsSndStop(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    int i;

    _ss_score[arg0][arg1].unk90 &= ~1;
    _ss_score[arg0][arg1].unk90 &= ~2;
    _ss_score[arg0][arg1].unk90 &= ~8;
    _ss_score[arg0][arg1].unk90 |= 4;
    _SsVmSeqKeyOff((s16)(arg0 | arg1 << 8));
    score->unk2b = 0;
    score->unk80 = 0;
    score->unk27 = 0;
    score->unk13 = 0;
    score->unk14 = 0;
    score->unk29 = 0;
    score->unk15 = 0;
    score->unk16 = 0;
    score->unk2a = 0;
    score->channel = 0;
    score->unk48 = 0;
    score->unk27 = 0;
    score->unk28 = 0;
    score->unk10 = 0;
    score->unk11 = 0;
    score->delta_value = score->unk7c;
    score->unk8c = score->unk84;
    score->unk70 = score->unk72;
    score->read_pos = score->next_sep_pos;
    score->loop_pos = score->next_sep_pos;
    for (i = 0; i < 16; i++) {
        score->programs[i] = i;
        score->panpot[i] = 0x40;
        score->vol[i] = 127;
    }

    score->unk78 = 0x7F;
    score->unk7A = 0x7F;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssstop", SsSeqStop);

/**
 * @brief Stop a SEQ
 * 
 * Stops the sequence and rewinds it to the beginning.
 * 
 * @param seq_access_num SEQ access number
 */
void SsSeqStop(short seq_access_num) { _SsSndStop(seq_access_num, 0); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssstop", SsSepStop);

/**
 * @brief Stop a sequence of a SEP
 * 
 * Stops one sequence of the SEP and rewinds it.
 * 
 * @param sep_access_num SEP access number
 * @param arg1 Sequence number within the SEP
 */
void SsSepStop(short sep_access_num, short arg1) {
    _SsSndStop(sep_access_num, arg1);
}
