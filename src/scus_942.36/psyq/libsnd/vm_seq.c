#include "common.h"

void _SsVmKeyOffNow(int mode);
struct SpuVoice {
    s16 vag_idx;
    s16 unk2;
    s16 unk04;
    u16 key_stat;
    s16 voll1;
    char pan;
    char unkb;
    s16 note;
    s16 seq_sep_no;
    s16 fake_program;
    s16 prog;
    s16 tone;
    s16 vabId;
    s16 priority;
    u8 pad4[1];
    u8 unk1b;
    s16 auto_vol;
    s16 unk1e;
    s16 unk20;
    s16 unk22;
    s16 start_vol;
    s16 end_vol;
    s16 auto_pan;
    s16 unk2a;
    s16 unk2c;
    s16 unk2e;
    s16 start_pan;
    s16 end_pan;
};
struct struct_svm {
    char prog_tones;
    char vabId;
    char note;
    char fine;
    char volume;
    char pan;
    char prog;
    char fake_program;
    char field_8_unknown;
    char field_0x9;
    char mvol;
    char mpan;
    char tone;
    char tone_vol;
    char tone_pan;
    char tone_prior;
    char tone_center;
    unsigned char tone_shift;
    char tone_min;
    char tone_max;
    u8 tone_mode;
    u8 pad;
                          short seq_sep_no;
    short tone_vag_idx;
    short voice;
    short voiceOffset;
    short field_0x1e;
};
extern struct struct_svm _svm_cur;
extern struct SpuVoice _svm_voice[24];
extern char spuVmMaxVoice;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmSetSeqVol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmGetSeqVol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmGetSeqLVol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmGetSeqRVol);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmSeqKeyOff);

void _SsVmSeqKeyOff(s16 seq_sep_num) {
    u8 i;

    for (i = 0; i < spuVmMaxVoice; i++) {
        if (_svm_voice[i].seq_sep_no == seq_sep_num) {
            _svm_cur.voice = i;
            _SsVmKeyOffNow(0);
        }
    }
}
