#include "common.h"
#include "libsnd_i.h"

int _SsVmKeyOn(unsigned short seq_sep_no, short vabId, short prog, unsigned short note,
                unsigned short voll, unsigned short pan);
int _SsVmKeyOff(short seq_sep_no, short vabId, short prog, unsigned short note);
void _SsVmKeyOffNow(int mode);
void vmNoiseOff(u8 voice);
extern struct SpuVoice _svm_voice[24];

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_key", _SsVmKeyOn);
extern u8 _SsVmSelectToneAndVag(u8* tones, u8* vags);
extern u8 _SsVmAlloc(int mode);
extern void _SsVmDoAllocate(void);
extern void vmNoiseOn(u8 voice);
extern u16 note2pitch(void);
extern void _SsVmKeyOnNow(u8 count, u16 pitch);

/**
 * @brief Internal: key on a note
 * 
 * Selects the tones of the program that cover the note, allocates a voice
 * for each and starts them (or the noise generator).
 * 
 * @param seq_sep_no Sequence handle (access number | seq number << 8, or 0x21 for sound effects)
 * @param vabId VAB ID
 * @param prog Program number
 * @param note Note number
 * @param voll Velocity / volume
 * @param pan Pan
 * @return Bit mask of the voices started, or -1 on error
 */
int _SsVmKeyOn(unsigned short seq_sep_no, short vabId, short prog, unsigned short note,
                unsigned short voll, unsigned short pan)
{
    struct SeqStruct* score;
    u8 vags[128];
    u8 tones[128];
    int ret;
    u8 count;
    u8 i;
    u8 t;
    short sep;

    ret = 0;
    sep = seq_sep_no;
    score = &_ss_score[seq_sep_no & 0xFF][(sep & 0xFF00) >> 8];
    if (_SsVmVSetUp(vabId, prog) != 0) {
        return -1;
    }
    _svm_cur.field_16_vag_idx = seq_sep_no;
    _svm_cur.field_2_note = note;
    _svm_cur.field_0x3 = 0;
    if (sep == 0x21) {
        _svm_cur.field_4_voll = voll;
    } else {
        _svm_cur.field_4_voll = score->vol[score->channel] * voll / 127;
    }
    _svm_cur.field_0x5 = pan;
    _svm_cur.field_A_mvol = _svm_pg[prog].mvol;
    _svm_cur.field_B_mpan = _svm_pg[prog].mpan;
    _svm_cur.field_0_sep_sep_no_tonecount = _svm_pg[prog].tones;
    if ((u8)_svm_cur.field_7_fake_program >= _svm_vh->ps) {
        return -1;
    }
    if (voll == 0) {
        ret = _SsVmKeyOff(seq_sep_no, vabId, prog, note);
    } else {
    count = _SsVmSelectToneAndVag(tones, vags);
    for (i = 0; i < count; i++) {
        _svm_cur.field_18_voice_idx = vags[i];
        t = tones[i];
        _svm_cur.field_C_vag_idx = t;
        _svm_cur.field_F_prior = _svm_tn[t + _svm_cur.field_7_fake_program * 16].prior;
        _svm_cur.field_D_vol = _svm_tn[t + _svm_cur.field_7_fake_program * 16].vol;
        _svm_cur.field_E_pan = _svm_tn[t + _svm_cur.field_7_fake_program * 16].pan;
        _svm_cur.field_10_centre = _svm_tn[t + _svm_cur.field_7_fake_program * 16].center;
        _svm_cur.field_11_shift = _svm_tn[t + _svm_cur.field_7_fake_program * 16].shift;
        _svm_cur.field_14_seq_sep_no = _svm_tn[t + _svm_cur.field_7_fake_program * 16].mode;
        _svm_cur.field_12_mode = _svm_tn[t + _svm_cur.field_7_fake_program * 16].min;
        _svm_cur.field_0x13 = _svm_tn[t + _svm_cur.field_7_fake_program * 16].max;
        _svm_cur.field_0x1a = _SsVmAlloc(0);
        if (_svm_cur.field_0x1a < spuVmMaxVoice) {
            _svm_voice[_svm_cur.field_0x1a].unk1b = 1;
            _svm_voice[_svm_cur.field_0x1a].unk2 = 0;
            _svm_voice[_svm_cur.field_0x1a].unke = seq_sep_no;
            _svm_voice[_svm_cur.field_0x1a].vabId = _svm_cur.field_1_vabId;
            _svm_voice[_svm_cur.field_0x1a].unk10 = _svm_cur.field_7_fake_program;
            _svm_voice[_svm_cur.field_0x1a].prog = prog;
            if ((short)seq_sep_no != 0x21) {
                _svm_voice[_svm_cur.field_0x1a].unk8 = voll;
            }
            _svm_voice[_svm_cur.field_0x1a].unka = pan;
            _svm_voice[_svm_cur.field_0x1a].tone = _svm_cur.field_C_vag_idx;
            _svm_voice[_svm_cur.field_0x1a].note = note;
            _svm_voice[_svm_cur.field_0x1a].unk18 = _svm_cur.field_F_prior;
            _svm_voice[_svm_cur.field_0x1a].unk0 = _svm_cur.field_18_voice_idx;
            _SsVmDoAllocate();
            if (_svm_cur.field_18_voice_idx == 0xFF) {
                vmNoiseOn(_svm_cur.field_0x1a);
            } else {
                _SsVmKeyOnNow(count, note2pitch());
            }
            ret |= 1 << _svm_cur.field_0x1a;
        } else {
            ret = -1;
        }
    }
    }
    return ret;
}

/**
 * @brief Internal: key off a note
 * 
 * Releases every voice playing the given note of the program for this
 * sequence.
 * 
 * @param seq_sep_no Sequence handle
 * @param vabId VAB ID
 * @param prog Program number
 * @param note Note number
 * @return Number of voices released
 */
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

/**
 * @brief Internal: key on a sound effect note
 * 
 * Converts the left/right volume to volume and pan and keys on the note as
 * a sound effect.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param note Note number
 * @param pitch Pitch (unused)
 * @param voll Left volume
 * @param volr Right volume
 */
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

/**
 * @brief Internal: key off a sound effect note
 * 
 * Releases the voices playing the note as a sound effect.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param note Note number
 */
void _SsVmSeKeyOff(short vabId, short prog, unsigned short note) {
    _SsVmKeyOff(0x21, vabId, prog, note);
}

/**
 * @brief Internal: empty placeholder
 * 
 * Does nothing.
 */
void KeyOnCheck(void) {
}
