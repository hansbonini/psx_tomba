#include "common.h"
#include "libsnd_i.h"

extern s16 _svm_sreg_buf[NUM_SPU_CHANNELS * 8];
extern char _svm_sreg_dirty[NUM_SPU_CHANNELS];
extern struct SpuVoice _svm_voice[NUM_SPU_CHANNELS];
extern u16* _svm_sreg;
extern s16 _svm_orev1;
extern s16 _svm_orev2;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_no1", vmNoiseOn);

void vmNoiseOn(u8 arg0) {
    struct SeqStruct* score =
        &_ss_score[_svm_cur.field_16_vag_idx & 0xFF]
                  [(_svm_cur.field_16_vag_idx & 0xFF00) >> 8];
    s16 voice;
    u16 bitsUpper;
    u16 bitsLower;
    u32 voll_t, volr_t;
    u32 voll, volr;
    u16 cnd;
    u32 temp;

    cnd = _svm_sreg[0x1AA / 2];

    voll_t = score->unk74 * 0x81;
    volr_t = score->unk76 * 0x81;

    voll_t = (voll_t * _svm_cur.field_A_mvol) / 0x7F;
    volr_t = (volr_t * _svm_cur.field_A_mvol) / 0x7F;

    voll_t = (voll_t * _svm_cur.field_D_vol) / 0x7F;
    volr_t = (volr_t * _svm_cur.field_D_vol) / 0x7F;

    temp = _svm_cur.field_E_pan;
    if (temp < 0x40) {
        voll = voll_t;
        volr = (volr_t * temp) / 0x3F;
    } else {
        voll = (voll_t * (0x7F - temp)) / 0x3F;
        volr = volr_t;
    }
    temp = _svm_cur.field_B_mpan;
    if (temp < 0x40) {
        volr = (volr * temp) / 0x3F;
    } else {
        voll = (voll * (0x7F - temp)) / 0x3F;
    }
    temp = _svm_cur.field_0x5;
    if (temp < 0x40) {
        volr = (temp * volr) / 0x3F;
    } else {
        voll = (voll * (0x7F - temp)) / 0x3F;
    }

    if (_svm_stereo_mono == 1) {
        if (voll < volr) {
            voll = volr;
        } else {
            volr = voll;
        }
    }

    cnd &= ~0x3F00;
    cnd |= ((_svm_cur.field_2_note - _svm_cur.field_10_centre) & 0x3F) << 8;
    _svm_sreg[0x1AA / 2] = cnd;

    _svm_sreg_buf[arg0 * 8 + 0] = voll;
    _svm_sreg_buf[arg0 * 8 + 1] = volr;
    _svm_sreg_dirty[arg0] |= 3;
    if (arg0 < 0x10) {
        bitsLower = 1 << arg0;
        bitsUpper = 0;
    } else {
        bitsLower = 0;
        bitsUpper = 1 << (arg0 - 0x10);
    }
    _svm_voice[arg0].unk04 = 0xA;
    for (voice = 0; voice < spuVmMaxVoice; voice++) {
        _svm_voice[voice].unk1b &= 1;
    }
    _svm_voice[arg0].unk1b = 2;

    _svm_okon1 |= bitsLower;
    _svm_okon2 |= bitsUpper;

    _svm_okof1 &= ~_svm_okon1;
    _svm_okof2 &= ~_svm_okon2;

    if (_svm_cur.field_14_seq_sep_no & 4) {
        _svm_orev1 |= bitsLower;
        _svm_orev2 |= bitsUpper;
    } else {
        _svm_orev1 &= ~bitsLower;
        _svm_orev2 &= ~bitsUpper;
    }

    _svm_sreg[0x194 / 2] = bitsLower;
    _svm_sreg[0x196 / 2] = bitsUpper;
}
