#include "common.h"

typedef struct VabHdr {
    long form;
    long ver;
    long id;
    unsigned long fsize;
    unsigned short reserved0;
    unsigned short ps;
    unsigned short ts;
    unsigned short vs;
    unsigned char mvol;
    unsigned char pan;
    unsigned char attr1;
    unsigned char attr2;
    unsigned long reserved1;
} VabHdr;
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
struct SeqStruct {
    u8 unk0;
    u8 pad1[3];
    u8* read_pos;
    u8* next_sep_pos;
    u8* loop_pos;
    u8 unk10;
    u8 unk11;
    u8 channel;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 panpot[16];
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 programs[16];
    u8 unk3C;
    u8 pad3D;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4a;
    s16 unk4c;
    s16 vol[16];
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    u16 unk74;
    u16 unk76;
    s16 unk78;
    s16 unk7A;
    s32 unk7c;
    u32 unk80;
    s32 unk84;
    s32 delta_value;
    s32 unk8c;
    s32 unk90;
    u32 unk94;
    u32 unk98;
    s32 unk9C;
    u32 unkA0;
    u32 unkA4;
    s16 padA6;
    s16 padaa;
};
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
extern struct SeqStruct* _ss_score[32];
extern struct struct_svm _svm_cur;
extern unsigned short _svm_okon1;
extern unsigned short _svm_okon2;
extern unsigned short _svm_okof1;
extern unsigned short _svm_okof2;
extern unsigned short _svm_orev1;
extern unsigned short _svm_orev2;
extern struct SpuVoice _svm_voice[24];
extern VabHdr* _svm_vh;
extern short _svm_stereo_mono;
extern SPU_VOICE_REG _svm_sreg_buf[24];
extern char _svm_sreg_dirty[24];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_nowon", _SsVmKeyOnNow);

void _SsVmKeyOnNow(unsigned short vagCount, unsigned short pitch) {
    volatile int pad;
    unsigned chL;
    unsigned chR;
    unsigned vol;
    short keyon1, keyon2;
    struct SeqStruct* ss;
    unsigned short voice;
    int volMul;

    volMul = _svm_vh->mvol * 16383;
    vol = (_svm_cur.volume * volMul) / 16129;
    chR = ((vol * _svm_cur.mvol) * _svm_cur.tone_vol) / 16129;
    voice = _svm_cur.voice * 8;
    vol = chR;
#ifndef __psyz
    ss = &_ss_score[_svm_cur.seq_sep_no & 0xFF]
                   [(_svm_cur.seq_sep_no >> 8) & 0xFF];
#endif
    if (_svm_cur.seq_sep_no != 0x21) {
#ifdef __psyz

        ss = &_ss_score[_svm_cur.seq_sep_no & 0xFF]
                       [(_svm_cur.seq_sep_no >> 8) & 0xFF];
#endif
        vol = (chR * ss->unk74) / 127;
        chR = (chR * ss->unk76) / 127;
    }
    if (_svm_cur.tone_pan < 64) {
        chR = (chR * _svm_cur.tone_pan) / 63;
        chL = vol;
    } else {
        chL = (vol * (127 - _svm_cur.tone_pan)) / 63;
    }
    if (_svm_cur.mpan < 64) {
        chR = (chR * _svm_cur.mpan) / 63;
    } else {
        chL = (chL * (127 - _svm_cur.mpan)) / 63;
    }
    if (_svm_cur.pan < 64) {
        chR = (chR * _svm_cur.pan) / 63;
    } else {
        chL = (chL * (127 - _svm_cur.pan)) / 63;
    }
    if (_svm_stereo_mono == 1) {
        if (chL < chR) {
            chL = chR;
        } else {
            chR = chL;
        }
    }
    chL = (chL * chL) / 16383;
    chR = (chR * chR) / 16383;
    ((short*)_svm_sreg_buf)[voice + 2] = pitch;
    ((short*)_svm_sreg_buf)[voice + 0] = chL;
    ((short*)_svm_sreg_buf)[voice + 1] = chR;
    _svm_sreg_dirty[_svm_cur.voice] |= 7;
    _svm_voice[_svm_cur.voice].unk04 = pitch;
    _svm_voice[_svm_cur.voice].unk1b = 1;
    if (_svm_cur.voice < 16) {
        keyon1 = 1 << _svm_cur.voice;
        keyon2 = 0;
    } else {
        keyon1 = 0;
        keyon2 = 1 << (_svm_cur.voice - 16);
    }
    if (_svm_cur.tone_mode & 4) {
        _svm_orev1 |= keyon1;
        _svm_orev2 |= keyon2;
    } else {
        _svm_orev1 &= ~keyon1;
        _svm_orev2 &= ~keyon2;
    }
    _svm_okon1 |= keyon1;
    _svm_okon2 |= keyon2;
    _svm_okof1 &= ~_svm_okon1;
    _svm_okof2 &= ~_svm_okon2;
}
