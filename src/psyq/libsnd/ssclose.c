#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssclose", _SsClose);

/**
 * @brief Internal: close a SEQ/SEP
 * 
 * Silences and keys off its voices, frees the access number and resets the
 * score state of all its sequences.
 * 
 * @param seq_sep_num Access number
 */
void _SsClose(s16 seq_sep_num) {
    s32 seq_num;
    _SsVmSetSeqVol(seq_sep_num, 0, 0, 1);
    _SsVmSeqKeyOff(seq_sep_num);
    _snd_openflag &= ~(1 << seq_sep_num);
    for (seq_num = 0; seq_num < _snd_seq_t_max; seq_num++) {
        _ss_score[seq_sep_num][seq_num].unk90 = 0;
        _ss_score[seq_sep_num][seq_num].unk3C = 0xFF;
        _ss_score[seq_sep_num][seq_num].unk0 = 0;
        _ss_score[seq_sep_num][seq_num].unk3E = 0;
        _ss_score[seq_sep_num][seq_num].unk40 = 0;
        _ss_score[seq_sep_num][seq_num].unk94 = 0;
        _ss_score[seq_sep_num][seq_num].unk98 = 0;
        _ss_score[seq_sep_num][seq_num].unk42 = 0;
        _ss_score[seq_sep_num][seq_num].unkA4 = 0;
        _ss_score[seq_sep_num][seq_num].unkA0 = 0;
        _ss_score[seq_sep_num][seq_num].unk9C = 0;
        _ss_score[seq_sep_num][seq_num].unk44 = 0;
        _ss_score[seq_sep_num][seq_num].unk74 = 0x7f;
        _ss_score[seq_sep_num][seq_num].unk76 = 0x7f;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssclose", SsSeqClose);

/**
 * @brief Close a SEQ
 * 
 * Releases the access number obtained with SsSeqOpen().
 * 
 * @param seq_access_num SEQ access number
 */
void SsSeqClose(short seq_access_num) { _SsClose(seq_access_num); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssclose", SsSepClose);

/**
 * @brief Close a SEP
 * 
 * Releases the access number obtained with SsSepOpen().
 * 
 * @param sep_access_num SEP access number
 */
void SsSepClose(short sep_access_num) { _SsClose(sep_access_num); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssclose", SsEnd);

/**
 * @brief Stop the sound system tick
 * 
 * Removes the interrupt or VSync callback installed by SsStart().
 */
void SsEnd(void) {
    if (_snd_seq_tick_env.unk4 == 0) {
        _snd_seq_tick_env.unk17 = 0;
        if (_snd_seq_tick_env.unk18 != 0x7F) {
            EnterCriticalSection();
            if (_snd_seq_tick_env.unk16 != 0) {
                VSyncCallback(NULL);
                _snd_seq_tick_env.unk16 = 0;
            } else if (_snd_seq_tick_env.unk18 == 0) {
                InterruptCallback(0, _snd_seq_tick_env.unk12);
                _snd_seq_tick_env.unk12 = 0;
            } else {
                InterruptCallback(6, NULL);
            }
            ExitCriticalSection();
            _snd_seq_tick_env.unk18 = 0x7F;
        }
    }
}
