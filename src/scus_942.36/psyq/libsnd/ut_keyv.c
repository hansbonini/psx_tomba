#include "common.h"

#define NUM_VOICES 24
void _SsVmKeyOffNow(int mode);
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
extern s32 _snd_ev_flag;
extern struct struct_svm _svm_cur;
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
extern struct SpuVoice _svm_voice[24];
extern ProgAtr* _svm_pg;
extern VagAtr* _svm_tn;
void vmNoiseOn(char voice);
unsigned short note2pitch2(unsigned short note, unsigned short fine);
void _SsVmKeyOnNow(unsigned short vagCount, unsigned short pitch);
int _SsVmVSetUp(short vabId, short prog);
void _SsVmDoAllocate(void);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_keyv", SsUtKeyOnV);

short SsUtKeyOnV(short voice, short vabId, short prog, short tone, short note,
                 short fine, short voll, short volr) {
    int tn;

    if (_snd_ev_flag == 1) {
        return -1;
    }
    _snd_ev_flag = 1;
    if (voice < 0 || voice >= NUM_VOICES) {
        _snd_ev_flag = 0;
        return -1;
    }
    if (_SsVmVSetUp(vabId, prog)) {
        _snd_ev_flag = 0;
        return -1;
    }
    _svm_cur.seq_sep_no = 0x21;
    _svm_cur.note = note;
    _svm_cur.fine = fine;
    _svm_cur.tone = tone;
    if (voll == volr) {
        _svm_cur.pan = 0x40;
        _svm_cur.volume = voll;
    } else if (volr < voll) {
        _svm_cur.volume = voll;
        _svm_cur.pan = (volr << 6) / voll;
    } else {
        _svm_cur.volume = volr;
        _svm_cur.pan = 127 - (voll << 6) / volr;
    }
    _svm_cur.mvol = _svm_pg[prog].mvol;
    _svm_cur.mpan = _svm_pg[prog].mpan;
    _svm_cur.prog_tones = _svm_pg[prog].tones;
    tn = _svm_cur.tone + (_svm_cur.fake_program * 16);
    _svm_cur.tone_prior = _svm_tn[tn].prior;
    _svm_cur.tone_vag_idx = _svm_tn[tn].vag;
    _svm_cur.tone_vol = _svm_tn[tn].vol;
    _svm_cur.tone_pan = _svm_tn[tn].pan;
    _svm_cur.tone_center = _svm_tn[tn].center;
    _svm_cur.tone_shift = _svm_tn[tn].shift;
    _svm_cur.tone_mode = _svm_tn[tn].mode;
    _svm_cur.tone_min = _svm_tn[tn].min;
    _svm_cur.tone_max = _svm_tn[tn].max;
    if (_svm_cur.tone_vag_idx == 0) {
        _snd_ev_flag = 0;
        return -1;
    }
    _svm_cur.voice = voice;
    _svm_voice[voice].seq_sep_no = 0x21;
    _svm_voice[voice].vabId = vabId;
    _svm_voice[voice].fake_program = _svm_cur.fake_program;
    _svm_voice[voice].prog = prog;
    _svm_voice[voice].vag_idx = _svm_cur.tone_vag_idx;
    _svm_voice[voice].tone = _svm_cur.tone;
    _svm_voice[voice].note = note;
    _svm_voice[voice].unk1b = 1;
    _svm_voice[voice].unk2 = 0;
    _SsVmDoAllocate();
    if (_svm_cur.tone_vag_idx == 0xFF) {
        vmNoiseOn(voice);
    } else {
        _SsVmKeyOnNow(1, note2pitch2(note, fine));
    }
    _snd_ev_flag = 0;
    return voice;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_keyv", SsUtKeyOffV);

short SsUtKeyOffV(short voice) {
    if (_snd_ev_flag == 1) {
        return -1;
    }
    _snd_ev_flag = 1;
    if (voice >= 0 && voice < NUM_VOICES) {
        _svm_cur.voice = voice;
        _SsVmKeyOffNow(0);
        _snd_ev_flag = 0;
        return 0;
    }
    _snd_ev_flag = 0;
    return -1;
}
