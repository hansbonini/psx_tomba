#include "common.h"
#include "libsnd_i.h"

extern s16 _svm_sreg_buf[NUM_SPU_CHANNELS * 8];
extern char _svm_sreg_dirty[NUM_SPU_CHANNELS];
extern struct SpuVoice _svm_voice[NUM_SPU_CHANNELS];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_cp", SsUtChangePitch);

short SsUtChangePitch(short voice, short vabId, short prog, short old_note,
                      short old_fine, u_short new_note, u_short new_fine) {
    if (voice >= 0 && voice < NUM_SPU_CHANNELS) {
        if ((_svm_voice[voice].vabId == vabId) &&
            (_svm_voice[voice].prog == prog) &&
            (_svm_voice[voice].note == old_note)) {
            _SsVmVSetUp(_svm_voice[voice].vabId, _svm_voice[voice].prog);
            _svm_cur.field_16_vag_idx = 0x21;
            _svm_cur.field_0x1a = voice;
            _svm_cur.field_C_vag_idx = _svm_voice[voice].tone;
            _svm_sreg_buf[voice * 8 + 2] = note2pitch2(new_note, new_fine);
            _svm_sreg_dirty[voice] |= 4;
            return 0;
        }
    }
    return -1;
}
