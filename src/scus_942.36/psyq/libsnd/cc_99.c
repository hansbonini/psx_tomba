#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);
#define NRPN_LOOP_START 20
#define NRPN_LOOP_END 30

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/cc_99", _SsContNrpn2);

void _SsContNrpn2(s16 arg0, s16 arg1, u8 arg2) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];

    switch (arg2) {
    case NRPN_LOOP_START:
        score->unk16 = arg2;
        score->unk27 = 1;
        score->delta_value = _SsReadDeltaValue(arg0, arg1);
        score->loop_pos = score->read_pos;
        break;

    case NRPN_LOOP_END:
        score->unk16 = arg2;
        if (score->unk28 == 0) {
            score->unk10 = 0;
            score->delta_value = _SsReadDeltaValue(arg0, arg1);
        } else if (score->unk28 < 0x7FU) {
            score->unk28--;
            score->delta_value = _SsReadDeltaValue(arg0, arg1);
            if (score->unk28 != 0) {
                score->read_pos = score->loop_pos;
            } else {
                score->unk10 = 0;
            }
        } else {
            _SsReadDeltaValue(arg0, arg1);
            score->delta_value = 0;
            score->read_pos = score->loop_pos;
        }
        break;

    default:
        score->unk16 = arg2;
        score->unk2a += 1;
        score->delta_value = _SsReadDeltaValue(arg0, arg1);
        break;
    }
}
