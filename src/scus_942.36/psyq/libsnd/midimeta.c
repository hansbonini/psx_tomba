#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);

void _SsGetMetaEvent(s16 access_num, s16 seq_num, u8 type) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];
    u8 b0;
    u8 b1;
    u8 b2;

    b0 = *score->read_pos++;
    b1 = *score->read_pos++;
    b2 = *score->read_pos++;
    score->unk8c = 60000000 / ((b0 << 16) | (b1 << 8) | b2);

    if ((score->unk4a * score->unk8c * 10) < (VBLANK_MINUS * 60)) {
        score->unk70 = score->unk6E =
            (VBLANK_MINUS * 600) / (score->unk4a * score->unk8c);
    } else {
        score->unk6E = -1;
        score->unk70 = (score->unk4a * score->unk8c * 10) / (VBLANK_MINUS * 60);
        if ((VBLANK_MINUS * 30) <
            (score->unk4a * score->unk8c * 10) % (VBLANK_MINUS * 60)) {
            score->unk70++;
        }
    }
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
