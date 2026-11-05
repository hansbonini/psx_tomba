#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsSeqPlay);

/**
 * @brief Play a SEQ
 * 
 * Starts or pauses the sequence.
 * 
 * @param seq_access_num SEQ access number
 * @param play_mode SSPLAY_PLAY (1) or SSPLAY_PAUSE (0)
 * @param l_count Number of repetitions (SSPLAY_INFINITY = 0)
 */
void SsSeqPlay(short seq_access_num, char play_mode, short l_count) {
    Snd_SetPlayMode(seq_access_num, 0, play_mode, l_count);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsSepPlay);

/**
 * @brief Play a sequence of a SEP
 * 
 * Starts or pauses one sequence of the SEP.
 * 
 * @param sep_access_num SEP access number
 * @param seq_num Sequence number within the SEP
 * @param play_mode SSPLAY_PLAY (1) or SSPLAY_PAUSE (0)
 * @param l_count Number of repetitions (SSPLAY_INFINITY = 0)
 */
void SsSepPlay(
    short sep_access_num, short seq_num, char play_mode, short l_count) {
    Snd_SetPlayMode(sep_access_num, seq_num, play_mode, l_count);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsQuit);

/**
 * @brief Shut down the sound system
 * 
 * Calls SpuQuit().
 */
void SsQuit(void) { SpuQuit(); }
