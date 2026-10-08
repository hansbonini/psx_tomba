#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midiread", _SsSeqPlay);

void _SsSeqPlay(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    s32 var_s0;

    if (score->delta_value - score->unk70 > 0) {
        if (score->unk6E > 0) {
            score->unk6E--;
        } else if (score->unk6E == 0) {
            score->unk6E = score->unk70;
            score->delta_value--;
        } else {
            score->delta_value -= score->unk70;
        }
    } else if (score->delta_value <= score->unk70) {
        var_s0 = score->delta_value;
        do {
            do {
                _SsGetSeqData(arg0, arg1);
            } while (score->delta_value == 0);
            var_s0 += score->delta_value;
        } while (var_s0 < score->unk70);
        score->delta_value = var_s0 - score->unk70;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midiread", _SsSeqGetEof);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midiread", _SsGetSeqData);
