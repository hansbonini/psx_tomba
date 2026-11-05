#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/playmode", Snd_SetPlayMode);

/**
 * @brief Internal: start or pause a sequence
 * 
 * Sets the loop count and either starts playback (restoring the sequence
 * volume) or requests a pause.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 * @param arg2 SSPLAY_PLAY (1) or SSPLAY_PAUSE (0)
 * @param arg3 Number of repetitions (SSPLAY_INFINITY = 0)
 */
void Snd_SetPlayMode(s16 arg0, s16 arg1, u8 arg2, s16 arg3) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];

    _ss_score[arg0][arg1].unk90 &= ~0x200;
    _ss_score[arg0][arg1].unk90 &= ~4;
    score->unk46 = arg3;

    if (arg2 == 1) {
        _ss_score[arg0][arg1].unk90 |= 1;
        score->unk48 = 0;
        score->unk2b = 1;
        _SsVmSetSeqVol(arg0 | (arg1 << 8), score->unk74, score->unk76, 0);
    } else if (arg2 == 0) {
        _ss_score[arg0][arg1].unk90 |= 2;
    }
}
