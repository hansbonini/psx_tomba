#include "common.h"
#include "libsnd_i.h"

void _SsVmKeyOn(int seq_sep_no, short vabId, short prog, unsigned short note,
                unsigned short voll, unsigned short pan);
int _SsVmKeyOff(short seq_sep_no, short vabId, short prog, unsigned short note);
void _SsVmKeyOffNow(int mode);
void vmNoiseOff(u8 voice);
extern struct SpuVoice _svm_voice[24];

INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_key", _SsVmKeyOn);

int _SsVmKeyOff(short seq_sep_no, short vabId, short prog, unsigned short note) {
    u8 i;
    int count;

    count = 0;
    for (i = 0; i < spuVmMaxVoice; i++) {
        if (_svm_voice[i].note == note && _svm_voice[i].prog == prog &&
            _svm_voice[i].unke == seq_sep_no && _svm_voice[i].vabId == vabId) {
            if (_svm_voice[i].unk0 == 0xFF) {
                vmNoiseOff(i);
            } else {
                _svm_cur.field_0x1a = i;
                _SsVmKeyOffNow(0);
            }
            count++;
        }
    }
    return count;
}

void _SsVmSeKeyOn(short vabId, short prog, unsigned short note,
                  unsigned short pitch, unsigned short voll,
                  unsigned short volr) {
    unsigned short vol;
    unsigned short pan;

    if (voll == volr) {
        pan = 64;
        vol = voll;
    } else if (volr < voll) {
        vol = voll;
        pan = (volr << 6) / voll;
    } else {
        vol = volr;
        pan = 127 - (voll << 6) / volr;
    }
    _SsVmKeyOn(0x21, vabId, prog, note, vol, pan);
}

void _SsVmSeKeyOff(short vabId, short prog, unsigned short note) {
    _SsVmKeyOff(0x21, vabId, prog, note);
}

void KeyOnCheck(void) {
}
