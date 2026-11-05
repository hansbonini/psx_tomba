#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssvol", _SsSndSetVol);

/**
 * @brief Internal: set the volume of a sequence
 * 
 * Sets the left and right volume of a SEQ/SEP sequence and updates its
 * voices.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 * @param arg2 Left volume (0-127)
 * @param arg3 Right volume (0-127)
 */
void _SsSndSetVol(s32 arg0, s32 arg1, u16 arg2, u16 arg3) {
    _SsVmSetSeqVol(arg0 | (arg1 << 8), arg2, arg3, 1);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssvol", SsSeqSetVol);

/**
 * @brief Set the volume of a SEQ
 * 
 * Sets the left and right volume of the sequence and updates its voices.
 * 
 * @param arg0 SEQ access number
 * @param arg1 Left volume (0-127)
 * @param arg2 Right volume (0-127)
 */
void SsSeqSetVol(short arg0, short arg1, short arg2) {
    _SsVmSetSeqVol(arg0, arg1, arg2, 1);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssvol", SsSepSetVol);

/**
 * @brief Set the volume of a sequence of a SEP
 * 
 * Sets the left and right volume of one sequence of the SEP.
 * 
 * @param sep_access_num SEP access number
 * @param seq_num Sequence number within the SEP
 * @param voll Left volume (0-127)
 * @param volr Right volume (0-127)
 */
void SsSepSetVol(s16 sep_access_num, s16 seq_num, s16 voll, s16 volr) {
    _SsVmSetSeqVol(
        sep_access_num | (seq_num << 8), voll & 0xFFFF, volr & 0xFFFF, 1);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssvol", SsSeqGetVol);

/**
 * @brief Get the volume of a sequence
 * 
 * Returns the current left and right volume of a SEQ/SEP sequence.
 * 
 * @param access_num SEQ/SEP access number
 * @param seq_num SEQ number within the SEP (0 for a SEQ)
 * @param voll Receives the left volume
 * @param volr Receives the right volume
 */
void SsSeqGetVol(s16 access_num, s16 seq_num, s16* voll, s16* volr) {
    _SsVmGetSeqVol(access_num | (seq_num << 8), voll, volr);
}
