#include "common.h"

#define SPUW_RAW(idx,val) _spu_RXX->raw[idx] = (val)
#define SPUR_RAW(idx) (_spu_RXX->raw[idx])
typedef struct {
    short left;
    short right;
} SpuVolume;
typedef struct tagSpuVoiceRegister {
               SpuVolume volume;
               u16 pitch;
               u16 addr;
               u16 adsr[2];
               u16 volumex;
               u16 loop_addr;
} SPU_VOICE_REG;
typedef struct tagSpuControl {
                           SPU_VOICE_REG voice[24];
                           SpuVolume main_vol;
                           SpuVolume rev_vol;
                           u16 key_on[2];
                           u16 key_off[2];
                           u16 chan_fm[2];
                           u16 noise_mode[2];
                           u16 rev_mode[2];
                           u32 chan_on;
                           u16 unk;
                           u16 rev_work_addr;
                           u16 irq_addr;
                           u16 trans_addr;
                           u16 trans_fifo;
                           u16 spucnt;
                           u16 data_trans;
                           u16 spustat;
                           SpuVolume cd_vol;
                           SpuVolume ex_vol;
                           SpuVolume main_volx;
                           SpuVolume unk_vol;
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
} SPU_RXX;
union SpuUnion {
    volatile SPU_RXX rxx;
    volatile u16 raw[0x100];
};
extern volatile s32 _spu_RQmask;
extern volatile u16 _spu_RQ[10];
extern union SpuUnion* _spu_RXX;
extern s32 _spu_env;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_sav", _SpuSetAnyVoice);

u_long _SpuSetAnyVoice(long on_off, u_long voice_bit, int lo_reg, int hi_reg) {
    u_long ret;

    if (_spu_env & 1) {
        ret = ((_spu_RQ[hi_reg - 0xC4] & 0xFF) << 16) | _spu_RQ[lo_reg - 0xC4];
    } else {
        ret = ((SPUR_RAW(hi_reg) & 0xFF) << 16) | SPUR_RAW(lo_reg);
    }

    switch (on_off) {
    case 1:
        if (_spu_env & 1) {
            _spu_RQ[lo_reg - 0xC4] |= voice_bit;
            _spu_RQ[hi_reg - 0xC4] |= (voice_bit >> 16) & 0xFF;
            _spu_RQmask |= on_off << ((lo_reg - 0xC6) >> 1);
        } else {
            SPUW_RAW(lo_reg, SPUR_RAW(lo_reg) | voice_bit);
            SPUW_RAW(hi_reg, SPUR_RAW(hi_reg) | ((voice_bit >> 16) & 0xFF));
        }
        ret |= voice_bit & 0xFFFFFF;
        break;
    case 0:
        if (_spu_env & 1) {
            _spu_RQ[lo_reg - 0xC4] &= ~voice_bit;
            _spu_RQ[hi_reg - 0xC4] &= ~((voice_bit >> 16) & 0xFF);
            _spu_RQmask |= 1 << ((lo_reg - 0xC6) >> 1);
        } else {
            SPUW_RAW(lo_reg, SPUR_RAW(lo_reg) & ~voice_bit);
            SPUW_RAW(hi_reg, SPUR_RAW(hi_reg) & ~((voice_bit >> 16) & 0xFF));
        }
        ret &= ~(voice_bit & 0xFFFFFF);
        break;
    }
    return ret & 0xFFFFFF;
}
