#include "common.h"
#include "libsnd_i.h"

u8 _SsVmSelectToneAndVag(u8* tones, u8* vags) {
    u8 count;
    u8 i;

    count = 0;
    for (i = 0; i < (u8)_svm_cur.field_0_sep_sep_no_tonecount; i++) {
        if (_svm_tn[_svm_cur.field_7_fake_program * 16 + i].min <=
                (u8)_svm_cur.field_2_note &&
            (u8)_svm_cur.field_2_note <=
                _svm_tn[_svm_cur.field_7_fake_program * 16 + i].max) {
            vags[count] = _svm_tn[_svm_cur.field_7_fake_program * 16 + i].vag;
            tones[count++] = i;
        }
    }
    return count;
}
