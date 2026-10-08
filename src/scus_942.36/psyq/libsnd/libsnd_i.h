// SPDX-License-Identifier: MIT
#include "common.h"
#ifndef KERNEL_H
#define KERNEL_H

#define DescMask 0xff000000
#define DescTH DescMask
#define DescHW 0xf0000000
#define DescEV 0xf1000000
#define DescRC 0xf2000000
#define DescUEV 0xf3000000 /* User event */
#define DescSW 0xf4000000  /* BIOS */

#define HwVBLANK (DescHW | 0x01) /* VBLANK */
#define HwGPU (DescHW | 0x02)    /* GPU */
#define HwCdRom (DescHW | 0x03)  /* CDROM Decorder */
#define HwDMAC (DescHW | 0x04)   /* DMA controller */
#define HwRTC0 (DescHW | 0x05)   /* RTC0 */
#define HwRTC1 (DescHW | 0x06)   /* RTC1 */
#define HwRTC2 (DescHW | 0x07)   /* RTC2 */
#define HwCNTL (DescHW | 0x08)   /* Controller */
#define HwSPU (DescHW | 0x09)    /* SPU */
#define HwPIO (DescHW | 0x0a)    /* PIO */
#define HwSIO (DescHW | 0x0b)    /* SIO */

#define HwCPU (DescHW | 0x10)    /* Exception */
#define HwCARD (DescHW | 0x11)   /* memory card */
#define HwCARD_0 (DescHW | 0x12) /* memory card */
#define HwCARD_1 (DescHW | 0x13) /* memory card */
#define SwCARD (DescSW | 0x01)   /* memory card */
#define SwMATH (DescSW | 0x02)   /* libmath */

#define RCntCNT0 (DescRC | 0x00) /* �\���s�N�Z�� */
#define RCntCNT1 (DescRC | 0x01) /* �������� */
#define RCntCNT2 (DescRC | 0x02) /* �V�X�e���N���b�N�W���� */
#define RCntCNT3 (DescRC | 0x03) /* �������� �^�[�Q�b�g�l�͂P�ɌŒ� */

#define RCntMdINTR 0x1000
#define RCntMdNOINTR 0x2000
#define RCntMdSC 0x0001
#define RCntMdSP 0x0000
#define RCntMdFR 0x0000
#define RCntMdGATE 0x0010

#define EvSpCZ 0x0001      /* counter becomes zero */
#define EvSpINT 0x0002     /* interrupted */
#define EvSpIOE 0x0004     /* end of i/o */
#define EvSpCLOSE 0x0008   /* file was closed */
#define EvSpACK 0x0010     /* command acknowledged */
#define EvSpCOMP 0x0020    /* command completed */
#define EvSpDR 0x0040      /* data ready */
#define EvSpDE 0x0080      /* data end */
#define EvSpTIMOUT 0x0100  /* time out */
#define EvSpUNKNOWN 0x0200 /* unknown command */
#define EvSpIOER 0x0400    /* end of read buffer */
#define EvSpIOEW 0x0800    /* end of write buffer */
#define EvSpTRAP 0x1000    /* general interrupt */
#define EvSpNEW 0x2000     /* new device */
#define EvSpSYSCALL 0x4000 /* system call instruction */
#define EvSpERROR 0x8000   /* error happned */
#define EvSpPERROR 0x8001  /* previous write error happned */
#define EvSpEDOM 0x0301    /* domain error in libmath */
#define EvSpERANGE 0x0302  /* range error in libmath */

#define EvMdINTR 0x1000
#define EvMdNOINTR 0x2000

#define EvStUNUSED 0x0000
#define EvStWAIT 0x1000
#define EvStACTIVE 0x2000
#define EvStALREADY 0x4000

#define TcbMdRT 0x1000  /* reserved by system */
#define TcbMdPRI 0x2000 /* reserved by system */

#define TcbStUNUSED 0x1000
#define TcbStACTIVE 0x4000

struct DIRENTRY {
    /* 0x00 */ char name[20];
    /* 0x14 */ long attr;
    /* 0x18 */ long size;
    /* 0x1C */ struct DIRENTRY* next;
    /* 0x20 */ long head;
    /* 0x24 */ char system[4];
}; // size = 0x28

void EnterCriticalSection(void);
void ExitCriticalSection(void);

long _card_info(long chan);
long _card_clear(long chan);
long _card_load(long chan);
void InitCARD(long val);
long StartCARD(void);

#endif

#ifndef LIBSPU_H
#define LIBSPU_H

#define SPU_VOICE_VOLL (0x01 << 0)        // volume (left)
#define SPU_VOICE_VOLR (0x01 << 1)        // volume (right)
#define SPU_VOICE_VOLMODEL (0x01 << 2)    // volume mode (left)
#define SPU_VOICE_VOLMODER (0x01 << 3)    // volume mode (right)
#define SPU_VOICE_PITCH (0x01 << 4)       // tone (pitch setting)
#define SPU_VOICE_NOTE (0x01 << 5)        // tone (note setting)
#define SPU_VOICE_SAMPLE_NOTE (0x01 << 6) // waveform data sample note
#define SPU_VOICE_WDSA (0x01 << 7)        // waveform data start address
#define SPU_VOICE_ADSR_AMODE (0x01 << 8)  // ADSR Attack rate mode
#define SPU_VOICE_ADSR_SMODE (0x01 << 9)  // ADSR Sustain rate mode
#define SPU_VOICE_ADSR_RMODE (0x01 << 10) // ADSR Release rate mode
#define SPU_VOICE_ADSR_AR (0x01 << 11)    // ADSR Attack rate
#define SPU_VOICE_ADSR_DR (0x01 << 12)    // ADSR Decay rate
#define SPU_VOICE_ADSR_SR (0x01 << 13)    // ADSR Sustain rate
#define SPU_VOICE_ADSR_RR (0x01 << 14)    // ADSR Release rate
#define SPU_VOICE_ADSR_SL (0x01 << 15)    // ADSR Sustain level
#define SPU_VOICE_LSAX (0x01 << 16)       // start address for loop
#define SPU_VOICE_ADSR_ADSR1 (0x01 << 17) // ADSR adsr1 for `VagAtr'
#define SPU_VOICE_ADSR_ADSR2 (0x01 << 18) // ADSR adsr2 for `VagAtr'

#define SPU_COMMON_MVOLL (0x01 << 0)     // master volume (left)
#define SPU_COMMON_MVOLR (0x01 << 1)     // master volume (right)
#define SPU_COMMON_MVOLMODEL (0x01 << 2) // master volume mode (left)
#define SPU_COMMON_MVOLMODER (0x01 << 3) // master volume mode (right)
#define SPU_COMMON_RVOLL (0x01 << 4)     // reverb volume (left)
#define SPU_COMMON_RVOLR (0x01 << 5)     // reverb volume (right)
#define SPU_COMMON_CDVOLL (0x01 << 6)    // CD input volume (left)
#define SPU_COMMON_CDVOLR (0x01 << 7)    // CD input volume (right)
#define SPU_COMMON_CDREV (0x01 << 8)     // CD input reverb on/off
#define SPU_COMMON_CDMIX (0x01 << 9)     // CD input on/off
#define SPU_COMMON_EXTVOLL (0x01 << 10)  // external digital input volume (left)
#define SPU_COMMON_EXTVOLR (0x01 << 11) // external digital input volume (right)
#define SPU_COMMON_EXTREV (0x01 << 12)  // external digital input reverb on/off
#define SPU_COMMON_EXTMIX (0x01 << 13)  // external digital input on/off

#define SPU_REV_MODE (0x01 << 0)      // mode setting
#define SPU_REV_DEPTHL (0x01 << 1)    // reverb depth (left)
#define SPU_REV_DEPTHR (0x01 << 2)    // reverb depth (right)
#define SPU_REV_DELAYTIME (0x01 << 3) // Delay Time  (ECHO, DELAY only)
#define SPU_REV_FEEDBACK (0x01 << 4)  // Feedback    (ECHO only)

#define SPU_REV_MODE_CHECK (-1)
#define SPU_REV_MODE_OFF 0
#define SPU_REV_MODE_ROOM 1
#define SPU_REV_MODE_STUDIO_A 2
#define SPU_REV_MODE_STUDIO_B 3
#define SPU_REV_MODE_STUDIO_C 4
#define SPU_REV_MODE_HALL 5
#define SPU_REV_MODE_SPACE 6
#define SPU_REV_MODE_ECHO 7
#define SPU_REV_MODE_DELAY 8
#define SPU_REV_MODE_PIPE 9
#define SPU_REV_MODE_MAX 10

#define SPU_REV_MODE_CLEAR_WA 0x100

#define SPU_OFF 0
#define SPU_ON 1

#ifndef __SPU_IRQCALLBACK_PROC
#define __SPU_IRQCALLBACK_PROC
typedef void (*SpuIRQCallbackProc)(void);
#endif

typedef struct {
    unsigned short left;  // left channel
    unsigned short right; // right channel
} SpuVolume;

typedef struct {
    /* 0x00 */ unsigned long voice; // each voice is a bit value
    /* 0x04 */ unsigned long mask;  // settings attribute bit (invalid with Get)
    /* 0x08 */ SpuVolume volume;    // volume
    /* 0x0C */ SpuVolume volmode;   // volume mode
    /* 0x10 */ SpuVolume volumex;   // current volume (invalid with Set)
    /* 0x14 */ unsigned short pitch;       // tone (pitch setting)
    /* 0x16 */ unsigned short note;        // tone (note setting)
    /* 0x18 */ unsigned short sample_note; // tone (note setting)
    /* 0x1A */ short envx;         // current envelope value (invalid with Set)
    /* 0x1C */ unsigned long addr; // waveform data start address
    /* 0x20 */ unsigned long loop_addr; // loop start address
    /* 0x24 */ long a_mode;             // Attack rate mode
    /* 0x28 */ long s_mode;             // Sustain rate mode
    /* 0x2C */ long r_mode;             // Release rate mode
    /* 0x30 */ unsigned short ar;       // Attack rate
    /* 0x32 */ unsigned short dr;       // Decay rate
    /* 0x34 */ unsigned short sr;       // Sustain rate
    /* 0x36 */ unsigned short rr;       // Release rate
    /* 0x38 */ unsigned short sl;       // Sustain level
    /* 0x3A */ unsigned short adsr1;    // adsr1 for `VagAtr'
    /* 0x3C */ unsigned short adsr2;    // adsr2 for `VagAtr'
} SpuVoiceAttr;                         // size=0x3E

typedef struct {
    unsigned long mask; // settings mask
    long mode;          // reverb mode
    SpuVolume depth;    // reverb depth
    long delay;         // Delay Time  (ECHO, DELAY only)
    long feedback;      // Feedback    (ECHO only)
} SpuReverbAttr;

typedef struct {
    SpuVolume volume; /* volume       */
    long reverb;      /* reverb on/off */
    long mix;         /* mixing on/off */
} SpuExtAttr;

typedef struct {
    unsigned long mask; /* settings mask */

    SpuVolume mvol;     /* master volume */
    SpuVolume mvolmode; /* master volume mode */
    SpuVolume mvolx;    /* current master volume */
    SpuExtAttr cd;      /* CD input attributes */
    SpuExtAttr ext;     /* external digital input attributes */
} SpuCommonAttr;

extern long SpuSetTransferMode(long mode);
extern unsigned long SpuWrite(unsigned char* addr, unsigned long size);

extern long SpuSetReverbModeParam(SpuReverbAttr* attr);

extern void SpuSetVoiceAttr(SpuVoiceAttr* arg);
extern void SpuSetKey(long on_off, unsigned long voice_bit);

extern long SpuMallocWithStartAddr(unsigned long addr, long size);

extern SpuIRQCallbackProc SpuSetIRQCallback(SpuIRQCallbackProc);

#endif

#ifndef LIBSND_INTERNAL_H
#define LIBSND_INTERNAL_H

#ifdef __cplusplus
extern "C" {
#endif

struct Unk {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    s16 unk10;
};
void _SsUtResolveADSR(u16 arg0, u16 arg1, struct Unk* arg2);
void _SsSeqPlay(s16, s16);
void _SsClose(s16);

void EnterCriticalSection(void);
void VSyncCallback(void (*func)());
void ExitCriticalSection(void);
void* InterruptCallback(u8, void (*)());
void ResetCallback(void);
void SpuInit(void);
void _SsInit(void);
void SsSeqCalledTbyT(void);
void Snd_SetPlayMode(s16, s16, u8, s16);
void SpuQuit(void);

extern s32 D_8003C74C;
extern SpuReverbAttr _svm_rattr;

void SpuVmSeKeyOn(s16 arg0, s16 arg1, u16 arg2, s32 arg3, u16 arg4, u16 arg5);
s32 _SsVmSetSeqVol(s16 seq_sep_no, u16 voll, u16 volr, s16 arg3);
s32 _SsVmGetSeqVol(s16, s16*, s16*);
s16 SpuIsTransferCompleted(s16);

void _spu_setInTransfer(s32);
u32 SpuSetTransferStartAddr(u32);
extern s32 _svm_vab_total[];
extern s32 _svm_vab_start[];
extern u8 _svm_vab_used[];

void SpuFree(s32);
extern u16 _svm_vab_count;

typedef struct VabHdr {
    s32 form;
    s32 ver;
    s32 id;
    u32 fsize;
    u16 reserved0;
    u16 ps;
    u16 ts;
    u16 vs;
    u8 mvol;
    u8 pan;
    u8 attr1;
    u8 attr2;
    u32 reserved1;
} VabHdr;

s16 SsVabOpenHead(u8*, s16);
s16 SsVabTransBody(u8*, s16);
extern s32 _svm_brr_start_addr[];

extern u8 spuVmMaxVoice;

extern s16 _svm_stereo_mono;

void vmNoiseOn2(u8 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);

struct struct_svm {
    char field_0_sep_sep_no_tonecount;
    char field_1_vabId;
    char field_2_note;
    char field_0x3;
    char field_4_voll;
    char field_0x5;
    char field_6_program;
    char field_7_fake_program;
    char field_8_unknown;
    char field_0x9;
    char field_A_mvol;
    char field_B_mpan;
    char field_C_vag_idx;
    char field_D_vol;
    char field_E_pan;
    char field_F_prior;
    char field_10_centre;
    unsigned char field_11_shift;
    char field_12_mode;
    char field_0x13;
    u8 field_14_seq_sep_no;
    u8 pad;
    short field_16_vag_idx;
    short field_18_voice_idx;
    short field_0x1a;
    short field_0x1c;
    short field_0x1e;
};

extern struct struct_svm _svm_cur;

extern u8 spuVmMaxVoice;
void SeAutoVol(s16, s16, s16, s16);
void SeAutoPan(s16, s16, s16, s16);

// similar to
// https://github.com/AliveTeam/sound_rev/blob/7a9223139c3375bf10e96a4ac17d77b973979e20/psx_seq_player/lib_snd.hpp#L127C1-L184C7

struct SeqStruct {
    u8 unk0;
    u8 pad1[3];
    u8* read_pos;
    u8* next_sep_pos; /* 0x8 */
    u8* loop_pos;     /* 0xC */
    u8 unk10;
    u8 unk11;
    u8 channel;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 panpot[16];
    u8 unk27;
    u8 unk28;
    u8 unk29;
    u8 unk2a;
    u8 unk2b;
    u8 programs[16];
    u8 unk3C;
    u8 pad3D;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4a;
    s16 unk4c;
    s16 vol[16];
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    u16 unk74;
    u16 unk76;
    s16 unk78;
    s16 unk7A;
    s32 unk7c;
    u32 unk80;
    s32 unk84;
    s32 delta_value;
    s32 unk8c;
    s32 unk90;
    u32 unk94;
    u32 unk98;
    s32 unk9C;
    u32 unkA0;
    u32 unkA4;
    s16 padA6;
    s16 padaa;
};

#ifdef VERSION_PC
extern struct SeqStruct* _ss_score[34];
#else
extern struct SeqStruct* _ss_score[32];
#endif

extern void SpuSetCommonAttr(SpuCommonAttr* attr);

extern s16 _snd_seq_s_max;
extern s16 _snd_seq_t_max;

typedef struct ProgAtr { /* Program Headdings */

    unsigned char tones;      /* # of tones */
    unsigned char mvol;       /* program volume */
    unsigned char prior;      /* program priority */
    unsigned char mode;       /* program mode */
    unsigned char mpan;       /* program pan */
    char reserved0;           /* system reserved */
    short attr;               /* program attribute */
    u32 reserved1;            // "fake" program index (skips empties)
    unsigned short reserved2; // even vag spu ptr
    unsigned short reserved3; // odd vag spu ptr
} ProgAtr;                    /* 16 byte */

#define NUM_SPU_CHANNELS 24

extern u8 spuVmMaxVoice;

struct SpuVoice {
    s16 unk0;
    s16 unk2;
    s16 unk04;
    u16 unk6;
    s16 unk8;
    char unka;
    char unkb;
    s16 note; /* 0xC */
    s16 unke;
    s16 unk10;
    s16 prog;  /* 0x12 */
    s16 tone;  /* 0x14*/
    s16 vabId; /* 0x16 */
    s16 unk18;
    u8 pad4[1];
    u8 unk1b;
    s16 auto_vol; /* 0x1c */
    s16 unk1e;
    s16 unk20;
    s16 unk22;
    s16 start_vol; /* 0x24 */
    s16 end_vol;   /* 0x26 */
    s16 auto_pan;  /* 0x28 */
    s16 unk2a;
    s16 unk2c;
    s16 unk2e;
    s16 start_pan; /* 0x30 */
    s16 end_pan;   /* 0x32 */
};

u32 _SsVmVSetUp(s16, s16);

typedef struct VagAtr { /* VAG Tone Headdings */

    unsigned char prior;     /* tone priority */
    unsigned char mode;      /* play mode */
    unsigned char vol;       /* tone volume*/
    unsigned char pan;       /* tone panning */
    unsigned char center;    /* center note */
    unsigned char shift;     /* center note fine tune */
    unsigned char min;       /* minimam note limit */
    unsigned char max;       /* maximam note limit */
    unsigned char vibW;      /* vibrate depth */
    unsigned char vibT;      /* vibrate duration */
    unsigned char porW;      /* portamento depth */
    unsigned char porT;      /* portamento duration */
    unsigned char pbmin;     /* under pitch bend max */
    unsigned char pbmax;     /* upper pitch bend max */
    unsigned char reserved1; /* system reserved */
    unsigned char reserved2; /* system reserved */
    unsigned short adsr1;    /* adsr1 */
    unsigned short adsr2;    /* adsr2 */
    short prog;              /* parent program*/
    short vag;               /* vag reference */
    short reserved[4];       /* system reserved */

} VagAtr; /* 32 byte */

extern VagAtr* _svm_tn;

void SpuVmFlush();
void _SsSndCrescendo(s16, s16);
void _SsSndDecrescendo(s16, s16);
void _SsSndPause(s16, s16);
void _SsSndPlay(s16, s16);
void _SsSndReplay(s16, s16);
void _SsSndTempo(s16, s16);
extern s32 _snd_ev_flag;
extern s32 _snd_openflag;

short SsUtGetProgAtr(short vabId, short progNum, ProgAtr* progatrptr);
short SsUtGetVagAtr(
    short vabId, short progNum, short toneNum, VagAtr* vagatrptr);
short SsUtSetVagAtr(
    short vabId, short progNum, short toneNum, VagAtr* vagatrptr);

short SsVabTransBodyPartly(
    unsigned char* addr, unsigned long bufsize, short vabid);

u32 SpuWritePartly(u8*, u32);

struct SndSeqTickEnv {
    s32 unk0;
    s32 unk4;
    void (*unk8)();
    void (*unk12)();
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u32 unk20;
};

extern struct SndSeqTickEnv _snd_seq_tick_env;

extern u32 VBLANK_MINUS;

extern s16 _svm_damper;

extern VagAtr* _svm_vab_tn[16];
extern ProgAtr* _svm_vab_pg[16];
extern VabHdr* _svm_vab_vh[16];
extern ProgAtr* _svm_pg;
extern VabHdr* _svm_vh;
extern s16 kMaxPrograms;

extern unsigned short _svm_okon1;
extern unsigned short _svm_okon2;
extern unsigned short _svm_okof1;
extern unsigned short _svm_okof2;

void SsUtSetReverbDepth(short, short);

#ifdef __cplusplus
}
#endif

#endif
