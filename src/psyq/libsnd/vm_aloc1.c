#include "common.h"

u32 pitch_table_d[99] asm("pitch_table") = {
    0x100E1000, 0x102C101D, 0x104A103B, 0x10681059,
    0x10871078, 0x10A51096, 0x10C410B5, 0x10E310D4,
    0x110310F3, 0x11221113, 0x11421132, 0x11621152,
    0x11821172, 0x11A31193, 0x11C411B3, 0x11E511D4,
    0x120611F5, 0x12271216, 0x12491238, 0x126B125A,
    0x128D127C, 0x12AF129E, 0x12D212C1, 0x12F512E3,
    0x13181306, 0x133C132A, 0x135F134D, 0x13831371,
    0x13A71395, 0x13CC13BA, 0x13F113DE, 0x14161403,
    0x143B1428, 0x1460144E, 0x14861473, 0x14AC1499,
    0x14D314BF, 0x14F914E6, 0x1520150D, 0x15471534,
    0x156F155B, 0x15971583, 0x15BF15AB, 0x15E715D3,
    0x161015FB, 0x16381624, 0x1662164D, 0x168B1676,
    0x16B516A0, 0x16DF16CA, 0x170A16F4, 0x1734171F,
    0x175F174A, 0x178B1775, 0x17B617A1, 0x17E217CC,
    0x180F17F9, 0x183B1825, 0x18681852, 0x1896187F,
    0x18C318AC, 0x18F118DA, 0x191F1908, 0x194E1937,
    0x197D1965, 0x19AC1995, 0x19DC19C4, 0x1A0C19F4,
    0x1A3C1A24, 0x1A6D1A55, 0x1A9E1A85, 0x1ACF1AB7,
    0x1B011AE8, 0x1B331B1A, 0x1B661B4C, 0x1B981B7F,
    0x1BCC1BB2, 0x1BFF1BE5, 0x1C331C19, 0x1C671C4D,
    0x1C9C1C82, 0x1CD11CB7, 0x1D071CEC, 0x1D3D1D22,
    0x1D731D58, 0x1DA91D8E, 0x1DE01DC5, 0x1E181DFC,
    0x1E501E34, 0x1E881E6C, 0x1EC11EA4, 0x1EFA1EDD,
    0x1F331F16, 0x1F6D1F50, 0x1FA71F8A, 0x1FE21FC5,
    0x00002000, 0x0C117350, 0x0037C5DA,
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

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_aloc1", _SsVmAlloc);

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
