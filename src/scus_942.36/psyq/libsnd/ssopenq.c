#include "common.h"

#define DE_ADSR_SR_E 9
#define DE_ADSR_SR_L 8
#define CC_MAINVOL 3
#define CC_RPN1 8
#define CC_RPN2 9
#define CC_NUMBER 0
#define CC_BANKCHANGE 1
#define DE_LIMITH 3
#define DE_LIMITL 2
#define CC_EXTERNAL 10
#define DE_DELAY 19
#define DE_ECHO_FB 17
#define DE_ECHO_DELAY 18
#define DE_PORTA_DEPTH 14
#define CC_DAMPER 5
#define CC_NRPN1 6
#define CC_NRPN2 7
#define CC_DATAENTRY 2
#define DE_ADSR_DR 6
#define DE_PRIORITY 0
#define CC_RESETALL 11
#define DE_ADSR_AR_E 5
#define DE_ADSR_AR_L 4
#define DE_REV_DEPTH 16
#define DE_ADSR_SL 7
#define DE_MODE 1
#define DE_ADSR_RR_E 11
#define DE_ADSR_RR_L 10
#define DE_VIB_TIME 13
#define DE_ADSR_SR 12
#define DE_REV_TYPE 15
#define CC_PANPOT 4
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
typedef struct {
    void (*noteon)();
    void (*programchange)();
    void (*pitchbend)();
    void (*metaevent)();
    void (*control[13])();
    void (*ccentry[20])();
} _SsFCALL;
extern void _SsNoteOn(short, short, unsigned char, unsigned char);
extern void _SsSetProgramChange(short, short, unsigned char);
extern void _SsGetMetaEvent(short, short, unsigned char);
extern void _SsSetPitchBend(short, short);
extern void _SsSetControlChange(short, short, unsigned char);
extern void _SsContBankChange(short, short);
extern void _SsContDataEntry(short, short, unsigned char);
extern void _SsContMainVol(short, short, unsigned char);
extern void _SsContPanpot(short, short, unsigned char);
extern void _SsContExpression(short, short, unsigned char);
extern void _SsContDamper(short, short, unsigned char);
extern void _SsContExternal(short, short, unsigned char);
extern void _SsContNrpn1(short, short, unsigned char);
extern void _SsContNrpn2(short, short, unsigned char);
extern void _SsContRpn1(short, short, unsigned char);
extern void _SsContRpn2(short, short, unsigned char);
extern void _SsContResetAll(short, short);
extern void _SsSetNrpnVabAttr0(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr1(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr2(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr3(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr4(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr5(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr6(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr7(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr8(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr9(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr10(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr11(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr12(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr13(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr14(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr15(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr16(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr17(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr18(
    short, short, short, VagAtr, short, unsigned char);
extern void _SsSetNrpnVabAttr19(
    short, short, short, VagAtr, short, unsigned char);
extern _SsFCALL SsFCALL;
typedef void (*sCb)();
extern s32 _snd_openflag;
short _SsInitSoundSeq(short seq_no, short vab_id, u8* addr);
void _SsNoteOn(short a0, short a1, unsigned char a2, unsigned char a3);
void _SsSetProgramChange(short a0, short a1, unsigned char a2);
void _SsGetMetaEvent(short a0, short a1, unsigned char a2);
void _SsSetPitchBend(short a0, short a1);
void _SsSetControlChange(short a0, short a1, unsigned char a2);
void _SsContBankChange(short a0, short a1);
void _SsContDataEntry(short a0, short a1, unsigned char a2);
void _SsContMainVol(short a0, short a1, unsigned char a2);
void _SsContPanpot(short a0, short a1, unsigned char a2);
void _SsContExpression(short a0, short a1, unsigned char a2);
void _SsContDamper(short a0, short a1, unsigned char a2);
void _SsContExternal(short a0, short a1, unsigned char a2);
void _SsContNrpn1(short a0, short a1, unsigned char a2);
void _SsContNrpn2(short a0, short a1, unsigned char a2);
void _SsContRpn1(short a0, short a1, unsigned char a2);
void _SsContRpn2(short a0, short a1, unsigned char a2);
void _SsContResetAll(short a0, short a1);
void _SsSetNrpnVabAttr0(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr1(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr2(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr3(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr4(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr5(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr6(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr7(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr8(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr9(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr10(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr11(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr12(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr13(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr14(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr15(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr16(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr17(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr18(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);
void _SsSetNrpnVabAttr19(
    short a0, short a1, short a2, VagAtr a3, short a4, unsigned char a5);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssopenq", SsSeqOpen);

short SsSeqOpen(u_long* addr, short vab_id) {
    short bit;
    short flag;
    short ret;
    unsigned char exit_loop;
    u8* seq;

    flag = 0;
    seq = (u8*)addr;
    if (_snd_openflag == -1) {
        printf("Can't Open Sequence data any more\n\n");
        return -1;
    }
    bit = 0;
    exit_loop = 0;
    while (!exit_loop) {
        if ((_snd_openflag & (1 << bit)) == 0U) {
            flag = bit;
            exit_loop = 1;
        }
        bit++;
    }
    _snd_openflag |= 1 << flag;
    ret = _SsInitSoundSeq(flag, vab_id, seq);
    SsFCALL.noteon = (sCb)_SsNoteOn;
    SsFCALL.programchange = (sCb)_SsSetProgramChange;
    SsFCALL.metaevent = (sCb)_SsGetMetaEvent;
    SsFCALL.pitchbend = (sCb)_SsSetPitchBend;
    SsFCALL.control[CC_NUMBER] = (sCb)_SsSetControlChange;
    SsFCALL.control[CC_BANKCHANGE] = (sCb)_SsContBankChange;
    SsFCALL.control[CC_MAINVOL] = (sCb)_SsContMainVol;
    SsFCALL.control[CC_PANPOT] = (sCb)_SsContPanpot;
    SsFCALL.control[CC_DAMPER] = (sCb)_SsContDamper;
    SsFCALL.control[CC_NRPN1] = (sCb)_SsContNrpn1;
    SsFCALL.control[CC_NRPN2] = (sCb)_SsContNrpn2;
    SsFCALL.control[CC_RPN1] = (sCb)_SsContRpn1;
    SsFCALL.control[CC_RPN2] = (sCb)_SsContRpn2;
    SsFCALL.control[CC_EXTERNAL] = (sCb)_SsContExternal;
    SsFCALL.control[CC_RESETALL] = (sCb)_SsContResetAll;
    SsFCALL.control[CC_DATAENTRY] = (sCb)_SsContDataEntry;
    SsFCALL.ccentry[DE_PRIORITY] = (sCb)_SsSetNrpnVabAttr0;
    SsFCALL.ccentry[DE_MODE] = (sCb)_SsSetNrpnVabAttr1;
    SsFCALL.ccentry[DE_LIMITL] = (sCb)_SsSetNrpnVabAttr2;
    SsFCALL.ccentry[DE_LIMITH] = (sCb)_SsSetNrpnVabAttr3;
    SsFCALL.ccentry[DE_ADSR_AR_L] = (sCb)_SsSetNrpnVabAttr4;
    SsFCALL.ccentry[DE_ADSR_AR_E] = (sCb)_SsSetNrpnVabAttr5;
    SsFCALL.ccentry[DE_ADSR_DR] = (sCb)_SsSetNrpnVabAttr6;
    SsFCALL.ccentry[DE_ADSR_SL] = (sCb)_SsSetNrpnVabAttr7;
    SsFCALL.ccentry[DE_ADSR_SR_L] = (sCb)_SsSetNrpnVabAttr8;
    SsFCALL.ccentry[DE_ADSR_SR_E] = (sCb)_SsSetNrpnVabAttr9;
    SsFCALL.ccentry[DE_ADSR_RR_L] = (sCb)_SsSetNrpnVabAttr10;
    SsFCALL.ccentry[DE_ADSR_RR_E] = (sCb)_SsSetNrpnVabAttr11;
    SsFCALL.ccentry[DE_ADSR_SR] = (sCb)_SsSetNrpnVabAttr12;
    SsFCALL.ccentry[DE_VIB_TIME] = (sCb)_SsSetNrpnVabAttr13;
    SsFCALL.ccentry[DE_PORTA_DEPTH] = (sCb)_SsSetNrpnVabAttr14;
    SsFCALL.ccentry[DE_REV_TYPE] = (sCb)_SsSetNrpnVabAttr15;
    SsFCALL.ccentry[DE_REV_DEPTH] = (sCb)_SsSetNrpnVabAttr16;
    SsFCALL.ccentry[DE_ECHO_FB] = (sCb)_SsSetNrpnVabAttr17;
    SsFCALL.ccentry[DE_ECHO_DELAY] = (sCb)_SsSetNrpnVabAttr18;
    SsFCALL.ccentry[DE_DELAY] = (sCb)_SsSetNrpnVabAttr19;
    if (ret == -1) {
        return -1;
    }
    return flag;
}
