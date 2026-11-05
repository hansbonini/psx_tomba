#include "common.h"
#include "libsnd_i.h"

extern s16 _svm_sreg_buf[24 * 8];
extern char _svm_sreg_dirty[24];
extern struct SpuVoice _svm_voice[24];

/**
 * @brief Internal: set the volume and pan of the voices of a channel
 * 
 * Recomputes the volume registers of every voice playing the given program
 * for the sequence.
 * 
 * @param seq_sep_no Sequence handle
 * @param vabId VAB ID
 * @param prog Program number
 * @param vol Channel volume (0-127)
 * @param pan Channel pan (0-127)
 * @return Number of voices updated
 */
int _SsVmSetVol(short seq_sep_no, short vabId, short prog, u16 vol, u16 pan) {
    struct SeqStruct* score;
    int count;
    short i;
    int v;
    int vol_scaled;
    int tone;
    unsigned voll_t, volr_t;
    unsigned voll, volr;
    u8 p;

    count = 0;
    score = &_ss_score[seq_sep_no & 0xFF][(seq_sep_no & 0xFF00) >> 8];
    _SsVmVSetUp(vabId, prog);
    _svm_cur.field_16_vag_idx = seq_sep_no;
    if (pan == 0) {
        pan = 1;
    }
    if (vol == 0) {
        vol = 1;
    }
    for (i = 0; i < spuVmMaxVoice; i++) {
        if (_svm_voice[i].unke == seq_sep_no && _svm_voice[i].prog == prog &&
            _svm_voice[i].vabId == vabId) {
            if (score->vol[score->channel] != vol &&
                score->vol[score->channel] == 0) {
                score->vol[score->channel] = 1;
            }
            v = _svm_voice[i].unk8 * vol / 127;
            vol_scaled = _svm_vh->mvol * 0x3FFF;
            voll_t = v * vol_scaled / 0x3F01;
            tone = _svm_voice[i].unk10 * 16 + _svm_voice[i].tone;
            volr_t = voll_t * _svm_pg[prog].mvol * _svm_tn[tone].vol / 0x3F01;
            voll_t = volr_t * score->unk74 / 127;
            volr_t = volr_t * score->unk76 / 127;
            p = _svm_tn[tone].pan;
            if (p < 64) {
                voll = voll_t;
                volr = (volr_t * p) / 63;
            } else {
                volr = volr_t;
                voll = (voll_t * (127 - p)) / 63;
            }
            do {
                do {
                    p = _svm_pg[_svm_voice[i].prog].mpan;
                } while (0);
            } while (0);
            if (p < 64) {
                volr = (volr * p) / 63;
            } else {
                voll = (voll * (127 - p)) / 63;
            }
            do {
                do {
                    p = pan;
                } while (0);
            } while (0);
            if (p < 64) {
                volr = (volr * p) / 63;
            } else {
                voll = (voll * (127 - p)) / 63;
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
            _svm_sreg_buf[i * 8 + 0] = voll;
            _svm_sreg_buf[i * 8 + 1] = volr;
            count++;
            _svm_sreg_dirty[i] |= 3;
        }
    }
    return count;
}
