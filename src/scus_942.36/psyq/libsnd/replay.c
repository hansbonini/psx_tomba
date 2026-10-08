#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/replay", _SsSndReplay);

void _SsSndReplay(s16 arg0, s16 arg1) {
    struct SeqStruct* p;

    p = &_ss_score[arg0][arg1];
    p->unk2b = 1;
    _ss_score[arg0][arg1].unk90 &= ~8;
}
