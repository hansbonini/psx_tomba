#include "common.h"
#include "libsnd_i.h"

typedef struct { u8 pad[0x44]; void (*ccentry[20])(); } SsFCallEntry;
extern SsFCallEntry SsFCALL;


void _SsContDataEntry(short seq_no, short sep_no, unsigned char data)
{
    struct SeqStruct* score;
    ProgAtr progAtr;
    VagAtr vagAtr;
    u8 channel;
    u8 r;
    s32 i;
    s16 tune;

    score = &_ss_score[seq_no][sep_no];
    channel = score->channel;
    SsUtGetProgAtr(score->unk4c, score->programs[channel], &progAtr);
    if (score->unk27 == 1 && score->unk10 == 0) {
        score->unk28 = data;
        score->unk27 = 0;
        score->unk10 = 1;
        score->delta_value = _SsReadDeltaValue(seq_no, sep_no);
    } else if (score->unk29 == 2) {
        if (score->unk14 == 0) {
            for (i = 0; i < progAtr.tones; i++) {
                SsUtGetVagAtr(score->unk4c, score->programs[channel], i, &vagAtr);
                switch (score->unk13) {
                case 0:
                    r = data & 0x7F;
                    vagAtr.pbmax = r;
                    vagAtr.pbmin = r;
                    break;
                case 1:
                    if (data < 0x40) {
                        tune = (data * 100 / 8192) * 8192;
                    }
                    r = data - 0x41;
                    if (r < 0x3F) {
                        tune = (data * 100 / 8192) * 8192;
                    } else {
                        tune = 0;
                    }
                    vagAtr.shift += tune;
                    break;
                case 2:
                    if (data < 0x40) {
                        tune = data * 6400;
                    }
                    if (data >= 0x40 && data < 0x80) {
                        tune = data * 6400;
                    } else {
                        tune = 0;
                    }
                    vagAtr.center += tune;
                    break;
                }
                SsUtSetVagAtr(score->unk4c, score->programs[channel], i, &vagAtr);
            }
        }
        score->delta_value = _SsReadDeltaValue(seq_no, sep_no);
        score->unk29 = 0;
    } else if (score->unk2a == 2) {
        if (score->unk16 == 16) {
            for (i = 0; i < progAtr.tones; i++) {
                SsFCALL.ccentry[score->unk15](score->unk4c, score->programs[channel], i, vagAtr, score->unk15, data);
            }
        } else {
            SsFCALL.ccentry[score->unk15](score->unk4c, score->programs[channel], score->unk16, vagAtr, score->unk15, data);
        }
        score->delta_value = _SsReadDeltaValue(seq_no, sep_no);
        score->unk2a = 0;
    } else {
        score->delta_value = _SsReadDeltaValue(seq_no, sep_no);
    }
}
