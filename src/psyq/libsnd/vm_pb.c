#include "common.h"
#include "libsnd_i.h"

extern s16 _svm_sreg_buf[24 * 8];
extern char _svm_sreg_dirty[24];
extern struct SpuVoice _svm_voice[24];
s16 note2pitch2(u16 note, u16 fine);
short _SsVmPBVoice(short voice, short seq_sep_no, short vabId, short prog,
                   int pitch);

INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_pb", _SsVmPBVoice);

int _SsVmPitchBend(short seq_sep_no, short vabId, short prog,
                   unsigned short pitch) {
    short voice;
    int count;

    _SsVmVSetUp(vabId, prog);
    _svm_cur.field_16_vag_idx = seq_sep_no;
    count = 0;
    for (voice = 0; voice < spuVmMaxVoice; voice++) {
        count += _SsVmPBVoice(voice, seq_sep_no, vabId, prog, pitch);
    }
    return count;
}
