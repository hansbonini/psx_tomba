#include "common.h"

unsigned short pitch_table[198] = {
    0x1000, 0x100E, 0x101D, 0x102C, 0x103B, 0x104A, 0x1059, 0x1068,
    0x1078, 0x1087, 0x1096, 0x10A5, 0x10B5, 0x10C4, 0x10D4, 0x10E3,
    0x10F3, 0x1103, 0x1113, 0x1122, 0x1132, 0x1142, 0x1152, 0x1162,
    0x1172, 0x1182, 0x1193, 0x11A3, 0x11B3, 0x11C4, 0x11D4, 0x11E5,
    0x11F5, 0x1206, 0x1216, 0x1227, 0x1238, 0x1249, 0x125A, 0x126B,
    0x127C, 0x128D, 0x129E, 0x12AF, 0x12C1, 0x12D2, 0x12E3, 0x12F5,
    0x1306, 0x1318, 0x132A, 0x133C, 0x134D, 0x135F, 0x1371, 0x1383,
    0x1395, 0x13A7, 0x13BA, 0x13CC, 0x13DE, 0x13F1, 0x1403, 0x1416,
    0x1428, 0x143B, 0x144E, 0x1460, 0x1473, 0x1486, 0x1499, 0x14AC,
    0x14BF, 0x14D3, 0x14E6, 0x14F9, 0x150D, 0x1520, 0x1534, 0x1547,
    0x155B, 0x156F, 0x1583, 0x1597, 0x15AB, 0x15BF, 0x15D3, 0x15E7,
    0x15FB, 0x1610, 0x1624, 0x1638, 0x164D, 0x1662, 0x1676, 0x168B,
    0x16A0, 0x16B5, 0x16CA, 0x16DF, 0x16F4, 0x170A, 0x171F, 0x1734,
    0x174A, 0x175F, 0x1775, 0x178B, 0x17A1, 0x17B6, 0x17CC, 0x17E2,
    0x17F9, 0x180F, 0x1825, 0x183B, 0x1852, 0x1868, 0x187F, 0x1896,
    0x18AC, 0x18C3, 0x18DA, 0x18F1, 0x1908, 0x191F, 0x1937, 0x194E,
    0x1965, 0x197D, 0x1995, 0x19AC, 0x19C4, 0x19DC, 0x19F4, 0x1A0C,
    0x1A24, 0x1A3C, 0x1A55, 0x1A6D, 0x1A85, 0x1A9E, 0x1AB7, 0x1ACF,
    0x1AE8, 0x1B01, 0x1B1A, 0x1B33, 0x1B4C, 0x1B66, 0x1B7F, 0x1B98,
    0x1BB2, 0x1BCC, 0x1BE5, 0x1BFF, 0x1C19, 0x1C33, 0x1C4D, 0x1C67,
    0x1C82, 0x1C9C, 0x1CB7, 0x1CD1, 0x1CEC, 0x1D07, 0x1D22, 0x1D3D,
    0x1D58, 0x1D73, 0x1D8E, 0x1DA9, 0x1DC5, 0x1DE0, 0x1DFC, 0x1E18,
    0x1E34, 0x1E50, 0x1E6C, 0x1E88, 0x1EA4, 0x1EC1, 0x1EDD, 0x1EFA,
    0x1F16, 0x1F33, 0x1F50, 0x1F6D, 0x1F8A, 0x1FA7, 0x1FC5, 0x1FE2,
    0x2000, 0x0000, 0x7350, 0x0C11, 0xC5DA, 0x0037,
};

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

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_aloc1", _SsVmAlloc);

/**
 * @brief Internal: allocate a voice for a new note
 * 
 * Returns a free voice, or steals the voice with the lowest priority
 * (preferring released and older voices).
 * 
 * @param voice Unused
 * @return Voice number, or spuVmMaxVoice if none is available
 */
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

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_aloc1", note2pitch);

/**
 * @brief Internal: convert the current note to an SPU pitch
 * 
 * Uses the note, center note and fine shift of the current tone and the
 * pitch table.
 * 
 * @return SPU pitch value
 */
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

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_aloc1", note2pitch2);

/**
 * @brief Internal: convert a note and fine tune to an SPU pitch
 * 
 * Like note2pitch() but with an explicit note and additional fine tune,
 * relative to the current tone.
 * 
 * @param note Note number
 * @param fine Fine tune (0-127)
 * @return SPU pitch value
 */
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
