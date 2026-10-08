#include "common.h"

#define SPUW(field,val) _spu_RXX->rxx.field = (val)
#define SPU_REV_DEPTHL (0x01 << 1)
#define SPU_REV_DEPTHR (0x01 << 2)
typedef struct {
    short left;
    short right;
} SpuVolume;
typedef struct {
    unsigned long mask;
    long mode;
    SpuVolume depth;
    long delay;
    long feedback;
} SpuReverbAttr;
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
extern union SpuUnion* _spu_RXX;
extern SpuReverbAttr _spu_rev_attr;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_rrwa", SpuReserveReverbWorkArea);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_rrwa", SpuSetReverbDepth);

long SpuSetReverbDepth(SpuReverbAttr* attr) {
    u32 mask = attr->mask;
    s32 bSetAll = attr->mask == 0;

    if (bSetAll || (mask & SPU_REV_DEPTHL)) {
        SPUW(rev_vol.left, attr->depth.left);
        _spu_rev_attr.depth.left = attr->depth.left;
    }
    if (bSetAll || (mask & SPU_REV_DEPTHR)) {
        SPUW(rev_vol.right, attr->depth.right);
        _spu_rev_attr.depth.right = attr->depth.right;
    }
    return 0;
}
