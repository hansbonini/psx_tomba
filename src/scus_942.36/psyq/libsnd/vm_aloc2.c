#include "common.h"

#define NUM_VAB 16
typedef struct ProgAtr {
    unsigned char tones;
    unsigned char mvol;
    unsigned char prior;
    unsigned char mode;
    unsigned char mpan;
    char reserved0;
    short attr;
    unsigned long reserved1;
    unsigned long reserved2;
} ProgAtr;
typedef struct VagAtr {
    unsigned char prior;
    unsigned char mode;
    unsigned char vol;
    unsigned char pan;
    unsigned char center;
    unsigned char shift;
    unsigned char min;
    unsigned char max;
    unsigned char vibW;
    unsigned char vibT;
    unsigned char porW;
    unsigned char porT;
    unsigned char pbmin;
    unsigned char pbmax;
    unsigned char reserved1;
    unsigned char reserved2;
    unsigned short adsr1;
    unsigned short adsr2;
    short prog;
    short vag;
    short reserved[4];
} VagAtr;
typedef struct {
    short left;
    short right;
} SpuVolume;
typedef struct tagSpuVoiceRegister {
               SpuVolume volume;
               u16 pitch;
               u16 addr;
               u16 adsr[2];
               u16 volumex;
               u16 loop_addr;
} SPU_VOICE_REG;
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
extern s16 _svm_damper;
extern struct SpuVoice _svm_voice[24];
extern int _svm_envx_hist[16];
extern ProgAtr* _svm_pg;
extern VagAtr* _svm_tn;
extern SPU_VOICE_REG _svm_sreg_buf[24];
extern char _svm_sreg_dirty[24];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_aloc2", _SsVmDoAllocate);

void _SsVmDoAllocate(void) {
    int i;

    _svm_cur.voiceOffset = _svm_cur.voice * sizeof(SPU_VOICE_REG) / 2;
    _svm_cur.field_0x1e = _svm_cur.fake_program * 16 + _svm_cur.tone;
    _svm_voice[_svm_cur.voice].key_stat = 0x7FFF;
    for (i = 0; i < NUM_VAB; i++) {
        _svm_envx_hist[i] &= ~(1 << _svm_cur.voice);
    }
    if ((_svm_cur.tone_vag_idx & 1) > 0) {
        ((short*)_svm_sreg_buf)[_svm_cur.voiceOffset + 3] =
            ((u16*)&_svm_pg[(_svm_cur.tone_vag_idx - 1) / 2].reserved2)[0];
        _svm_sreg_dirty[_svm_cur.voice] |= 8;
    } else {
        ((short*)_svm_sreg_buf)[_svm_cur.voiceOffset + 3] =
            ((u16*)&_svm_pg[(_svm_cur.tone_vag_idx - 1) / 2].reserved2)[1];
        _svm_sreg_dirty[_svm_cur.voice] |= 8;
    }
    ((short*)_svm_sreg_buf)[_svm_cur.voiceOffset + 4] =
        _svm_tn[_svm_cur.fake_program * 16 + _svm_cur.tone].adsr1;
    ((short*)_svm_sreg_buf)[_svm_cur.voiceOffset + 5] =
        _svm_tn[_svm_cur.fake_program * 16 + _svm_cur.tone].adsr2 + _svm_damper;
    _svm_sreg_dirty[_svm_cur.voice] |= 0x30;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_aloc2", _SsVmDamperOff);

void _SsVmDamperOff(void) { _svm_damper = 0; }
