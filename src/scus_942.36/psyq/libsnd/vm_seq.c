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
extern struct SeqStruct* _ss_score[32];
extern VabHdr* _svm_vh;
extern ProgAtr* _svm_pg;
extern VagAtr* _svm_tn;
extern short _svm_stereo_mono;
extern SPU_VOICE_REG _svm_sreg_buf[24];
extern char _svm_sreg_dirty[24];

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_seq", _SsVmSetSeqVol);

short _SsVmSetSeqVol(short seq_sep_no, u16 voll, u16 volr, short arg3) {
    struct SeqStruct* score;
    int vol;
    int vol_scaled;
    int tone;
    unsigned voll_t, volr_t;
    u8 pan;
    short i;

    score = &_ss_score[seq_sep_no & 0xFF][(seq_sep_no & 0xFF00) >> 8];
    _svm_cur.seq_sep_no = seq_sep_no;
    if (voll == 0) {
        voll = 1;
    }
    if (volr == 0) {
        volr = 1;
    }
    score->unk74 = voll;
    score->unk76 = volr;
    if (score->unk74 > 127) {
        score->unk74 = 127;
    }
    if (score->unk76 > 127) {
        score->unk76 = 127;
    }
    if (arg3 == 1) {
        for (i = 0; i < spuVmMaxVoice; i++) {
            if ((u16)_svm_voice[i].seq_sep_no == (u16)seq_sep_no) {
                vol =
                    _svm_voice[i].voll1 * score->vol[score->channel] / 127;
                vol_scaled = vol * 0x3FFF;
                voll_t = _svm_vh->mvol * vol_scaled / 0x3F01;
                tone = _svm_voice[i].fake_program * 16 + _svm_voice[i].tone;
                volr_t = voll_t * _svm_pg[_svm_voice[i].prog].mvol *
                         _svm_tn[tone].vol / 0x3F01;
                voll_t = volr_t * score->unk74 / 127;
                volr_t = volr_t * score->unk76 / 127;
                pan = _svm_tn[tone].pan;
                if (pan < 64) {
                    voll = voll_t;
                    volr = (volr_t * pan) / 63;
                } else {
                    volr = volr_t;
                    voll = (voll_t * (127 - pan)) / 63;
                }
                pan = _svm_pg[_svm_voice[i].prog].mpan;
                if (pan < 64) {
                    volr = (volr * pan) / 63;
                } else {
                    voll = (voll * (127 - pan)) / 63;
                }
                pan = _svm_voice[i].pan;
                if (pan < 64) {
                    volr = (volr * pan) / 63;
                } else {
                    voll = (voll * (127 - pan)) / 63;
                }
                if (_svm_stereo_mono == 1) {
                    if (voll < volr) {
                        voll = volr;
                    } else {
                        volr = voll;
                    }
                }
                voll = (voll * voll) / 0x3FFF;
                volr = (volr * volr) / 0x3FFF;
                ((short*)_svm_sreg_buf)[i * 8 + 0] = voll;
                ((short*)_svm_sreg_buf)[i * 8 + 1] = volr;
                _svm_sreg_dirty[i] |= 3;
            }
        }
    }
    return _svm_cur.seq_sep_no;
}

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
