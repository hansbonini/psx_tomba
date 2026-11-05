#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/replay", _SsSndReplay);

/**
 * @brief Internal: resume a paused sequence
 * 
 * Marks the sequence as playing and clears the replay request flag.
 * 
 * @param arg0 SEQ/SEP access number
 * @param arg1 SEQ number within the SEP (0 for a SEQ)
 */
void _SsSndReplay(s16 arg0, s16 arg1) {
    struct SeqStruct* p;

    p = &_ss_score[arg0][arg1];
    p->unk2b = 1;
    _ss_score[arg0][arg1].unk90 &= ~8;
}
