#include "common.h"

extern unsigned long SpuSetNoiseVoice(long on_off, unsigned long voice_bit);
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
extern char spuVmMaxVoice;

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
extern unsigned short pitch_table[];
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
extern VagAtr* _svm_tn;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_aloc1", _SsVmAlloc);

char _SsVmAlloc(short voice) {
    u8 alloc;
    u16 lowestKeyStat;
    char matches;
    u16 lowestAge;
    u8 lowest;
    u8 i;
    u16 lowestPrior;

    alloc = 99;
    lowestKeyStat = -1;
    matches = 0;
    lowestAge = 0;
    lowest = 99;
    lowestPrior = _svm_cur.tone_prior;
    for (i = 0; i < spuVmMaxVoice; i++) {
        if (_svm_voice[i].unk1b == 0 && _svm_voice[i].key_stat == 0) {
            alloc = i;
            break;
        }
        if (_svm_voice[i].priority < lowestPrior) {
            lowestPrior = _svm_voice[i].priority;
            lowest = i;
            lowestKeyStat = _svm_voice[i].key_stat;
            lowestAge = _svm_voice[i].unk2;
            matches = 1;
        } else if (_svm_voice[i].priority == lowestPrior) {
            matches++;
            if (_svm_voice[i].key_stat < lowestKeyStat) {
                lowestAge = _svm_voice[i].unk2;
                lowestKeyStat = _svm_voice[i].key_stat;
                lowest = i;
            } else if (_svm_voice[i].key_stat == lowestKeyStat) {
                if (lowestAge < _svm_voice[i].unk2) {
                    lowestAge = _svm_voice[i].unk2;
                    lowest = i;
                }
            }
        }
    }
    if (alloc == 99) {
        alloc = lowest;
        if (matches == 0) {
            alloc = spuVmMaxVoice;
        }
    }
    if (alloc < spuVmMaxVoice) {
        for (i = 0; i < spuVmMaxVoice; i++) {
            _svm_voice[i].unk2++;
        }
        _svm_voice[alloc].unk2 = 0;
        _svm_voice[alloc].priority = _svm_cur.tone_prior;
        if (_svm_voice[alloc].unk1b == 2) {
            SpuSetNoiseVoice(0, 0xFFFFFF);
        }
    }
    return alloc;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_aloc1", note2pitch);

unsigned short note2pitch(void) {
    int octave;
    int note;
    int shiftVal;
    int semitones;
    short semitone;
    unsigned int tableIndex;
    unsigned short step;
    short shift;
    unsigned short pitch;
    int noteIndex;

    note = _svm_cur.note + (60 - _svm_cur.tone_center);
    shiftVal = _svm_cur.tone_shift;
    step = shiftVal / 8;
    semitones = (short)note;
    octave = semitones / 12;
    semitone = semitones - (octave * 12);
    if (step >= 16) {
        step = 15;
    }
    noteIndex = semitone * 16;
    tableIndex = noteIndex + step;
    pitch = pitch_table[tableIndex];
    shift = octave - 5;
    if (shift > 0) {
        pitch <<= shift;
    } else if (shift < 0) {
        pitch >>= -shift;
    }
    return pitch;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_aloc1", note2pitch2);

unsigned short note2pitch2(unsigned short note, unsigned short fine) {
    VagAtr* tn;
    int octaveBase;
    int octave;
    short step;
    short shift;
    int semitones;
    int noteIndex;
    unsigned short pitch;
    int tone;

    tone = _svm_cur.tone + (_svm_cur.fake_program * 16);
    step = (fine + _svm_tn[tone].shift) / 8;
    octaveBase = 0;
    if (step >= 16) {
        octaveBase = 1;
        step -= 16;
    }
    semitones = (short)(octaveBase + (note + 60 - _svm_tn[tone].center));
    octave = semitones / 12;
    semitones = (short)(semitones - octave * 12);
    noteIndex = semitones * 16;
    pitch = pitch_table[noteIndex + step];
    shift = octave - 5;
    if (shift > 0) {
        pitch <<= shift;
    } else if (shift < 0) {
        pitch >>= -shift;
    }
    return pitch;
}
