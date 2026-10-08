#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/pause", _SsSndPause);

void _SsSndPause(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    _SsVmSeqKeyOff((s16)(arg0 | arg1 << 8));
    score->unk2b = 0;
    _ss_score[arg0][arg1].unk90 &= ~2;
}
