#include "common.h"
#include "libsnd_i.h"

extern s16 _svm_sreg_buf[24 * 8];
extern char _svm_sreg_dirty[24];
extern struct SpuVoice _svm_voice[24];
s16 note2pitch2(u16 note, u16 fine);
short _SsVmPBVoice(short voice, short seq_sep_no, short vabId, short prog,
                   int pitch);

/**
 * @brief Internal: apply pitch bend to one voice
 * 
 * If the voice belongs to the sequence and program, recomputes its pitch
 * from the bend value and the pitch bend range of its tone.
 * 
 * @param voice Voice number
 * @param seq_sep_no Sequence handle
 * @param vabId VAB ID
 * @param prog Program number
 * @param pitch Pitch bend value (64 = center)
 * @return 1 if the voice was updated, 0 otherwise
 */
short _SsVmPBVoice(short voice, short seq_sep_no, short vabId, short prog,
                   int pitch) {
    short bend;
    unsigned short note;
    int fine;
    unsigned short tone;
    int fake;

    bend = pitch - 64;
    if (_svm_voice[voice].unke == seq_sep_no &&
        _svm_voice[voice].vabId == vabId && _svm_voice[voice].prog == prog) {
        fake = _svm_cur.field_7_fake_program;
        tone = _svm_voice[voice].tone;
        note = _svm_voice[voice].note;
        fake <<= 4;
        tone += fake;
        if (bend > 0) {
            note += bend * _svm_tn[tone].pbmax / 63;
            fine = (bend * _svm_tn[tone].pbmax % 63) * 2;
        } else if (bend < 0) {
            note = note + bend * _svm_tn[tone].pbmin / 64 - 1;
            fine = (bend * _svm_tn[tone].pbmin % 64) * 2 + 127;
        } else {
            fine = 0;
        }
        _svm_cur.field_C_vag_idx = _svm_voice[voice].tone;
        _svm_cur.field_0x1a = voice;
        _svm_sreg_buf[voice * 8 + 2] = note2pitch2(note, fine);
        _svm_sreg_dirty[voice] |= 4;
        return 1;
    }
    return 0;
}

/**
 * @brief Internal: apply pitch bend to all voices of a program
 * 
 * Calls _SsVmPBVoice() for every voice.
 * 
 * @param seq_sep_no Sequence handle
 * @param vabId VAB ID
 * @param prog Program number
 * @param pitch Pitch bend value (64 = center)
 * @return Number of voices updated
 */
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
