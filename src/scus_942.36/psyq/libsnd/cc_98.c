#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);
typedef void (*SndSsMarkCallbackProc)(short seq_no, short sep_no, short data);
extern SndSsMarkCallbackProc _SsMarkCallback[32][16];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/cc_98", _SsContNrpn1);

void _SsContNrpn1(s16 arg0, s16 arg1, s16 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    SndSsMarkCallbackProc temp_v0;

    if ((score->unk27 == 1) && (score->unk10 == 0)) {
        score->unk28 = arg2;
        score->unk27 = 0;
        score->unk10 = 1;
    } else {
        if (score->unk16 != 0x1E) {
            if (score->unk16 != 0x14) {
                score->unk15 = arg2;
                score->unk27 = 0;
                score->unk2a++;
            }
        }
    }
    if (score->unk16 == 0x28) {
        temp_v0 = _SsMarkCallback[arg0][arg1];
        if (temp_v0 != NULL) {
            temp_v0(arg0, arg1, arg2 & 0xFF);
        }
    }
    score->delta_value = _SsReadDeltaValue(arg0, arg1);
}
