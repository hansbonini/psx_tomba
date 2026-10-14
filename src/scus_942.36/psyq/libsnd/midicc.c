#include "common.h"
#include "libsnd_i.h"

#define CC_DATAENTRY 2
#define CC_MAINVOL 3
#define CC_PANPOT 4
#define CC_DAMPER 5
#define CC_NRPN1 6
#define CC_NRPN2 7
#define CC_RPN1 8
#define CC_RPN2 9
#define CC_EXTERNAL 10
#define CC_RESETALL 11

typedef struct {
    void (*noteon)();
    void (*programchange)();
    void (*pitchbend)();
    void (*metaevent)();
    void (*control[13])();
    void (*ccentry[20])();
} _SsFCALL;
extern _SsFCALL SsFCALL;

s32 _SsReadDeltaValue(s16, s16);

void _SsSetControlChange(s16 access_num, s16 seq_num, u8 control) {
    struct SeqStruct* score = &_ss_score[access_num][seq_num];
    u8 data;

    data = *score->read_pos++;
    switch (control) {
    case 0:
        score->unk4c = data;
        score->delta_value = _SsReadDeltaValue(access_num, seq_num);
        break;
    case 6:
        SsFCALL.control[CC_DATAENTRY](access_num, seq_num, data);
        break;
    case 7:
        SsFCALL.control[CC_MAINVOL](access_num, seq_num, data);
        break;
    case 10:
        SsFCALL.control[CC_PANPOT](access_num, seq_num, data);
        break;
    case 11:
        SsFCALL.control[CC_DAMPER](access_num, seq_num, data);
        break;
    case 64:
        SsFCALL.control[CC_DAMPER](access_num, seq_num, data);
        break;
    case 91:
        SsFCALL.control[CC_EXTERNAL](access_num, seq_num, data);
        break;
    case 98:
        SsFCALL.control[CC_NRPN1](access_num, seq_num, data);
        break;
    case 99:
        SsFCALL.control[CC_NRPN2](access_num, seq_num, data);
        break;
    case 100:
        SsFCALL.control[CC_RPN1](access_num, seq_num, data);
        break;
    case 101:
        SsFCALL.control[CC_RPN2](access_num, seq_num, data);
        break;
    case 121:
        SsFCALL.control[CC_RESETALL](access_num, seq_num);
        break;
    default:
        score->delta_value = _SsReadDeltaValue(access_num, seq_num);
        break;
    }
}
