#include "common.h"
#include "libsnd_i.h"

void _SsSndNextSep(s16, s16);
void _SsVmSeqKeyOff(s16);
s32 _SsReadDeltaValue(s16, s16);
void _SsSeqGetEof();

typedef struct {
    void (*noteon)();
    void (*programchange)();
    void (*pitchbend)();
    void (*metaevent)();
    void (*control[13])();
    void (*ccentry[20])();
} _SsFCALL;
extern _SsFCALL SsFCALL;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/midiread", _SsSeqPlay);

void _SsSeqPlay(s16 arg0, s16 arg1) {
    struct SeqStruct* score = &_ss_score[arg0][arg1];
    s32 var_s0;

    if (score->delta_value - score->unk70 > 0) {
        if (score->unk6E > 0) {
            score->unk6E--;
        } else if (score->unk6E == 0) {
            score->unk6E = score->unk70;
            score->delta_value--;
        } else {
            score->delta_value -= score->unk70;
        }
    } else if (score->delta_value <= score->unk70) {
        var_s0 = score->delta_value;
        do {
            do {
                _SsGetSeqData(arg0, arg1);
            } while (score->delta_value == 0);
            var_s0 += score->delta_value;
        } while (var_s0 < score->unk70);
        score->delta_value = var_s0 - score->unk70;
    }
}

void _SsSeqGetEof(access_num, seq_num)
short access_num;
short seq_num;
{
    struct SeqStruct* score = &_ss_score[access_num][seq_num];

    score->unk48++;
    if (score->unk46 == 0) {
        score->unk80 = 0;
        score->unk27 = 0;
        score->delta_value = 0;
        score->read_pos = score->next_sep_pos;
    } else if (score->unk48 < score->unk46) {
        score->unk80 = 0;
        score->unk27 = 0;
        score->delta_value = 0;
        score->read_pos = score->next_sep_pos;
        score->loop_pos = score->next_sep_pos;
    } else {
        _ss_score[access_num][seq_num].unk90 &= ~1;
        _ss_score[access_num][seq_num].unk90 &= ~8;
        _ss_score[access_num][seq_num].unk90 &= ~2;
        _ss_score[access_num][seq_num].unk90 |= 0x200;
        _ss_score[access_num][seq_num].unk90 |= 4;
        score->unk2b = 0;
        score->loop_pos = score->next_sep_pos;
        if (score->unk3C != 0xFF) {
            score->unk2b = 0;
            _SsSndNextSep(score->unk3C, score->unk0);
            _SsVmSeqKeyOff(access_num | (seq_num << 8));
        }
        _SsVmSeqKeyOff(access_num | (seq_num << 8));
        score->delta_value = score->unk70;
    }
}

void _SsGetSeqData(s16 access_num, s16 seq_num) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];
    u8 data;
    u8 channel;
    u8 note;
    u8 velocity;

    data = *score->read_pos++;
    channel = data & 0xF;
    if (data & 0x80) {
        score->channel = channel;
        switch (data & 0xF0) {
        case 0x90:
            score->unk11 = 0x90;
            note = *score->read_pos++;
            velocity = *score->read_pos++;
            score->delta_value = _SsReadDeltaValue(access_num, seq_num);
            SsFCALL.noteon(access_num, seq_num, note, velocity);
            break;
        case 0xB0:
            score->unk11 = 0xB0;
            data = *score->read_pos++;
            SsFCALL.control[0](access_num, seq_num, data);
            break;
        case 0xC0:
            score->unk11 = 0xC0;
            data = *score->read_pos++;
            SsFCALL.programchange(access_num, seq_num, data);
            break;
        case 0xE0:
            score->unk11 = 0xE0;
            score->read_pos++;
            SsFCALL.pitchbend(access_num, seq_num);
            break;
        case 0xF0:
            score->unk11 = 0xFF;
            score->channel = channel;
            data = *score->read_pos++;
            if (data == 0x2F) {
                _SsSeqGetEof(access_num, seq_num, data);
            } else {
                SsFCALL.metaevent(access_num, seq_num, data);
            }
            break;
        }
    } else {
        switch (score->unk11) {
        case 0x90:
            velocity = *score->read_pos++;
            score->delta_value = _SsReadDeltaValue(access_num, seq_num);
            SsFCALL.noteon(access_num, seq_num, data, velocity);
            break;
        case 0xB0:
            SsFCALL.control[0](access_num, seq_num, data);
            break;
        case 0xC0:
            SsFCALL.programchange(access_num, seq_num, data);
            break;
        case 0xE0:
            SsFCALL.pitchbend(access_num, seq_num);
            break;
        case 0xFF:
            if (data == 0x2F) {
                _SsSeqGetEof(access_num, seq_num, data);
            } else {
                SsFCALL.metaevent(access_num, seq_num, data);
            }
            break;
        }
    }
}
