#include "common.h"
#include "libsnd_i.h"

s32 _SsReadDeltaValue(s16, s16);
void _SsVmDamperOff(void);
void _SsVmDamperOn(void);

void _SsContDamper(s16 access_num, s16 seq_num, u8 data) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    if (data < 0x40) {
        _SsVmDamperOff();
    } else {
        _SsVmDamperOn();
    }
    score->delta_value = _SsReadDeltaValue(access_num, seq_num);
}
