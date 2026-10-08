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

#ifndef LIBSPU_INTERNAL_H
#define LIBSPU_INTERNAL_H

#define NUM_SPU_CHANNELS 24

void* InterruptCallback(int, void (*)());
void _SpuInit(s32);
void _spu_FiDMA();

extern s32 D_80033098;
extern s32 _spu_EVdma;
extern s32 _spu_isCalled;
extern s32 _spu_inTransfer;
extern s32 _spu_keystat;
extern s32 _spu_transMode;
extern u16 _spu_tsa;
extern s32 _spu_rev_flag;
extern s32 _spu_rev_reserve_wa;
extern s32 _spu_rev_offsetaddr;
extern s32 _spu_rev_startaddr[];
extern s32 _spu_trans_mode;

extern s32 D_80097C98;
extern s32 D_80097CA4;
extern s32 _spu_AllocLastNum;
extern s8* D_80033564;
extern s32 _spu_mem_mode_plus;
extern s32 _spu_mem_mode_unitM;
extern u16 _spu_voice_centerNote[];

typedef struct tagSpuMalloc {
    u32 addr;
    u32 size;
} SPU_MALLOC;

extern void (* volatile _spu_transferCallback)();

void _SpuCallback(s32 arg0);
extern void (* volatile _spu_IRQCallback)();

s32 _SpuSetAnyVoice(s32 on_off, u32 bits, s32 addr1, s32 addr2);

s32 _spu_t(s32, ...);

u32 _spu_FsetRXXa(s32 arg0, u32 arg1);
s32 _spu_write(u8*, u32);

struct rev_param_entry {
    u32 flags;
    u16 dAPF1;
    u16 dAPF2;
    u16 vIIR;
    u16 vCOMB1;
    u16 vCOMB2;
    u16 vCOMB3;
    u16 vCOMB4;
    u16 vWALL;
    u16 vAPF1;
    u16 vAPF2;
    u16 mLSAME;
    u16 mRSAME;
    u16 mLCOMB1;
    u16 mRCOMB1;
    u16 mLCOMB2;
    u16 mRCOMB2;
    u16 dLSAME;
    u16 dRSAME;
    u16 mLDIFF;
    u16 mRDIFF;
    u16 mLCOMB3;
    u16 mRCOMB3;
    u16 mLCOMB4;
    u16 mRCOMB4;
    u16 dLDIFF;
    u16 dRDIFF;
    u16 mLAPF1;
    u16 mRAPF1;
    u16 mLAPF2;
    u16 mRAPF2;
    u16 vLIN;
    u16 vRIN;
};

struct SpuRevAttr {
    s32 unk0;
    s32 unk18;
    s16 unk1c;
    s16 unk1e;
    s32 unk20;
    s32 unk24;
};

extern struct SpuRevAttr _spu_rev_attr;

typedef struct tagSpuVoiceRegister {
    SpuVolume volume; // 0-2
    u16 pitch;        // 4
    u16 addr;         // 6
    u16 adsr[2];      // 8-A
    u16 volumex;      // C
    u16 loop_addr;    // E
} SPU_VOICE_REG;      // 16 bytes

typedef struct tagSpuControl {
    SPU_VOICE_REG voice[NUM_SPU_CHANNELS];
    SpuVolume main_vol; // 180
    SpuVolume rev_vol;  // 184
    // bit flags
    u16 key_on[2];       // 188
    u16 key_off[2];      // 18C
    u16 chan_fm[2];      // 190
    u16 noise_mode[2];   // 194
    u16 rev_mode[2];     // 198
    u32 chan_on;         // 19C
    u16 unk;             // 1A0
    u16 rev_work_addr;   // 1A2
    u16 irq_addr;        // 1A4
    u16 trans_addr;      // 1A6
    u16 trans_fifo;      // 1A8
    u16 spucnt;          // 1AA SPUCNT
    u16 data_trans;      // 1AC
    u16 spustat;         // 1AE SPUSTAT
    SpuVolume cd_vol;    // 1B0
    SpuVolume ex_vol;    // 1B4
    SpuVolume main_volx; // 1B8
    SpuVolume unk_vol;   // 1BC

    u16 dAPF1; // Starting at 0x1F801DC0
    u16 dAPF2;
    u16 vIIR;
    u16 vCOMB1;
    u16 vCOMB2;
    u16 vCOMB3;
    u16 vCOMB4;
    u16 vWALL;
    u16 vAPF1;
    u16 vAPF2;
    u16 mLSAME;
    u16 mRSAME;
    u16 mLCOMB1;
    u16 mRCOMB1;
    u16 mLCOMB2;
    u16 mRCOMB2;
    u16 dLSAME;
    u16 dRSAME;
    u16 mLDIFF;
    u16 mRDIFF;
    u16 mLCOMB3;
    u16 mRCOMB3;
    u16 mLCOMB4;
    u16 mRCOMB4;
    u16 dLDIFF;
    u16 dRDIFF;
    u16 mLAPF1;
    u16 mRAPF1;
    u16 mLAPF2;
    u16 mRAPF2;
    u16 vLIN;
    u16 vRIN;
} SPU_RXX;

union SpuUnion {
    volatile SPU_RXX rxx;
    volatile u16 raw[0x100];
};

extern union SpuUnion* _spu_RXX;

s32 _SpuIsInAllocateArea_(u32);

#define SPU_TRANSFER_BY_DMA 0
#define SPU_TRANSFER_BY_IO 1

extern SPU_MALLOC* _spu_memList;

#endif
