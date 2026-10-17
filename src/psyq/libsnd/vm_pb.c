#include "common.h"
#include "libsnd_i.h"

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
