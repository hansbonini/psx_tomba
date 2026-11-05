#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/play", _SsSndPlay);

/**
 * @brief Internal: play one tick of a sequence
 * 
 * Calls _SsSeqPlay().
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 */
void _SsSndPlay(s16 arg0, s16 arg1) { _SsSeqPlay(arg0, arg1); }
