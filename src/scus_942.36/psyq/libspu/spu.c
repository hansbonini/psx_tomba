#include "common.h"
#include "psyq/stdarg.h"
#include "libspu_internal.h"

#define SPU_CTRL_MASK_TRANSFER_DMA_READ (3 << 4)
#define SPU_CTRL_MASK_TRANSFER_DMA_WRITE (2 << 4)
extern volatile unsigned* dma_spu_madr;
extern volatile unsigned* dma_spu_bcr;
extern volatile unsigned* dma_spu_chcr;
extern int D_80097C98;
extern int spu_madr;
extern int spu_bcr;
void _spu_FsetDelayW(void);
void _spu_FsetDelayR(void);

#define SPU_CTRL_MASK_SPU_ENABLE (1 << 15)
#define DMA_PRIORITY_HIGH 3
#define LEN(x) ((s32)(sizeof(x) / sizeof(*(x))))
#define DMA_DPCR_DMA4_PRIORITY_SHIFT 16
#define DMA_TIMEOUT (0xF00U)
#define NUM_VOICES 24
#define DMA_DPCR_SPU_PRIORITY_HIGH (DMA_PRIORITY_HIGH << DMA_DPCR_DMA4_PRIORITY_SHIFT)
#define DMA_DPCR_MASK_DMA4_ENABLE (1 << 19)
#define SPU_CTRL_MASK_MUTE_SPU (1 << 14)
extern volatile u16 _spu_RQ[10];
void _spu_writeByIO(unsigned char* addr, u_long size);
extern volatile unsigned* dma_dpcr;
extern int _spu_addrMode;
extern int _spu_mem_mode;
extern int _spu_mem_mode_unit;
extern s8 _spu_dummy[16];
#define SPU_CTRL_MASK_SRAM_TRANSFER_MODE ((1 << 4) | (1 << 5))
#define SPUR(field) (_spu_RXX->rxx.field)
#define SPUW(field,val) _spu_RXX->rxx.field = (val)
#define SPU_CTRL_MASK_TRANSFER_MANUAL_WRITE (1 << 4)
void _spu_FwaitFs(void);
extern s32 _spu_mem_mode;
extern s32 _spu_mem_mode_unit;
extern volatile s32* D_80097C5C;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_init);

int _spu_init(int bHot) {
    unsigned dmaTimer;
    int i;

    *dma_dpcr |= DMA_DPCR_SPU_PRIORITY_HIGH | DMA_DPCR_MASK_DMA4_ENABLE;
    SPUW(main_vol.left, 0);
    SPUW(main_vol.right, 0);
    SPUW(spucnt, 0);
    _spu_transMode = 0;
    _spu_addrMode = 0;
    _spu_tsa = 0;
    _spu_FwaitFs();
    SPUW(main_vol.left, 0);
    SPUW(main_vol.right, 0);

    dmaTimer = 0;
    while (SPUR(spustat) & 0x7FF) {
        if (++dmaTimer > DMA_TIMEOUT) {
            printf("SPU:T/O [%s]\n", "wait (reset)");
            break;
        }
    }

    _spu_mem_mode = 2;
    _spu_mem_mode_plus = 3;
    _spu_mem_mode_unit = 8;
    _spu_mem_mode_unitM = 7;
    SPUW(data_trans, 4);
    SPUW(rev_vol.left, 0);
    SPUW(rev_vol.right, 0);
    SPUW(key_off[0], 0xFFFF);
    SPUW(key_off[1], 0xFFFF);
    SPUW(rev_mode[0], 0);
    SPUW(rev_mode[1], 0);
    for (i = 0; i < 10; i++) {
        _spu_RQ[i] = 0;
    }
    if (!bHot) {
        SPUW(chan_fm[0], 0);
        SPUW(chan_fm[1], 0);
        SPUW(noise_mode[0], 0);
        SPUW(noise_mode[1], 0);
        SPUW(cd_vol.left, 0);
        SPUW(cd_vol.right, 0);
        SPUW(ex_vol.left, 0);
        SPUW(ex_vol.right, 0);
        _spu_tsa = 0x200;
        _spu_writeByIO((unsigned char*)&_spu_dummy, LEN(_spu_dummy));
        for (i = 0; i < NUM_VOICES; i++) {
            SPUW(voice[i].volume.left, 0);
            SPUW(voice[i].volume.right, 0);
            SPUW(voice[i].pitch, 0x3fff);
            SPUW(voice[i].addr, 0x200);
            SPUW(voice[i].adsr[0], 0);
            SPUW(voice[i].adsr[1], 0);
        }
        SPUW(key_on[0], 0xFFFF);
        SPUW(key_on[1], 0xFF);
        _spu_FwaitFs();
        _spu_FwaitFs();
        _spu_FwaitFs();
        _spu_FwaitFs();
        SPUW(key_off[0], 0xFFFF);
        SPUW(key_off[1], 0xFF);
        _spu_FwaitFs();
        _spu_FwaitFs();
        _spu_FwaitFs();
        _spu_FwaitFs();
    }
    SPUW(spucnt, SPU_CTRL_MASK_MUTE_SPU | SPU_CTRL_MASK_SPU_ENABLE);
    _spu_inTransfer = 1;
    _spu_transferCallback = NULL;
    _spu_IRQCallback = NULL;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_writeByIO);

void _spu_writeByIO(unsigned char* addr, u_long size) {
    unsigned short spustat;
    int num_to_trans;
    unsigned short* cur_pos;
    int spustat_cur;
    int i;
    unsigned short cnt;
    unsigned timeout;

    cur_pos = (unsigned short*)addr;
    spustat = SPUR(spustat) & 0x7FF;
    SPUW(trans_addr, _spu_tsa);
    _spu_FwaitFs();
    while (size > 0) {
        num_to_trans = (size > 0x40) ? 0x40 : size;
        for (i = 0; i < num_to_trans; i += 2) {
            SPUW(trans_fifo, *cur_pos++);
        }
        cnt = SPUR(spucnt);
        cnt &= ~SPU_CTRL_MASK_SRAM_TRANSFER_MODE;
        cnt |= SPU_CTRL_MASK_TRANSFER_MANUAL_WRITE;
        SPUW(spucnt, cnt);
        _spu_FwaitFs();
        timeout = 0;
        while (SPUR(spustat) & 0x400) {
            timeout++;
            if (timeout > 0xF00) {
                printf("SPU:T/O [%s]\n", "wait (wrdy H -> L)");
                break;
            }
        }
        _spu_FwaitFs();
        _spu_FwaitFs();
        size -= num_to_trans;
    }
    cnt = SPUR(spucnt);
    cnt &= ~SPU_CTRL_MASK_SRAM_TRANSFER_MODE;
    SPUW(spucnt, cnt);
    timeout = 0;
    spustat_cur = SPUR(spustat) & 0x7FF;
    while (spustat_cur != spustat) {
        timeout++;
        if (timeout > 0xF00) {
            printf("SPU:T/O [%s]\n", "wait (dmaf clear/W)");
            return;
        }
        spustat_cur = SPUR(spustat) & 0x7FF;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FiDMA);

void _spu_FiDMA(void) {
    u32 i;

    if (D_80097C98 == 0) {
        _spu_FwaitFs();
        _spu_FwaitFs();
        _spu_FwaitFs();
    }

    _spu_RXX->rxx.spucnt &= 0xFFCF;

    i = 0;
    while (_spu_RXX->rxx.spucnt & 0x30) {
        if (++i > 0xF00) {
            break;
        }
    }

    if (_spu_transferCallback) {
        _spu_transferCallback();
        return;
    }
    DeliverEvent(HwSPU, EvSpCOMP);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_r_);

void _spu_r_(s32 arg0, u16 arg1, s32 arg2) {
    _spu_RXX->rxx.trans_addr = arg1;
    _spu_FwaitFs();
    _spu_FwaitFs();
    _spu_RXX->rxx.spucnt |= 0x30;
    _spu_FwaitFs();
    _spu_FwaitFs();
    _spu_FsetDelayR();
    *dma_spu_madr = arg0;
    *dma_spu_bcr = (arg2 << 16) | 0x10;
    D_80097C98 = 1;
    *dma_spu_chcr = 0x01000200;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_t);

int _spu_t(int arg0, ...) {
    unsigned channelControl;
    unsigned i;
    unsigned addr;
    va_list args;
    unsigned arg;
    u16 mode;
    u16 cnt;

    va_start(args, arg0);
    switch (arg0) {
    case 2:
        arg = va_arg(args, unsigned);
        _spu_tsa = arg >> _spu_mem_mode_plus;
        _spu_RXX->rxx.trans_addr = _spu_tsa;
        break;
    case 1:
        D_80097C98 = 0;
        i = 0;
        while (_spu_RXX->rxx.trans_addr != _spu_tsa) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        cnt = _spu_RXX->rxx.spucnt;
        cnt &= ~SPU_CTRL_MASK_SRAM_TRANSFER_MODE;
        cnt |= SPU_CTRL_MASK_TRANSFER_DMA_WRITE;
        _spu_RXX->rxx.spucnt = cnt;
        break;
    case 0:
        D_80097C98 = 1;
        i = 0;
        while (_spu_RXX->rxx.trans_addr != _spu_tsa) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        cnt = _spu_RXX->rxx.spucnt;
        cnt &= ~SPU_CTRL_MASK_SRAM_TRANSFER_MODE;
        cnt |= SPU_CTRL_MASK_TRANSFER_DMA_READ;
        _spu_RXX->rxx.spucnt = cnt;
        break;
    case 3:
        if (D_80097C98 == 1) {
            mode = SPU_CTRL_MASK_TRANSFER_DMA_READ;
        } else {
            mode = SPU_CTRL_MASK_TRANSFER_DMA_WRITE;
        }
        i = 0;
        while (
            (_spu_RXX->rxx.spucnt & SPU_CTRL_MASK_SRAM_TRANSFER_MODE) != mode) {
            if (++i > 0xF00) {
                return -2;
            }
        }
        if (D_80097C98 == 1) {
            _spu_FsetDelayR();
        } else {
            _spu_FsetDelayW();
        }
        arg = va_arg(args, unsigned);
        spu_madr = arg;
        arg = va_arg(args, unsigned);
        spu_bcr = arg / 0x40;
        spu_bcr += (arg % 0x40) ? 1 : 0;
        *dma_spu_madr = spu_madr;
        *dma_spu_bcr = (spu_bcr << 0x10) | 0x10;
        if (D_80097C98 == 1) {
            channelControl = 0x01000200;
        } else {
            channelControl = 0x01000201;
        }
        *dma_spu_chcr = channelControl;
        break;
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_write);

s32 _spu_write(u8* arg0, u32 size) {

    if (_spu_transMode != 0) {
        _spu_writeByIO(arg0, size);
        return size;
    }
    _spu_t(2, _spu_tsa << _spu_mem_mode_plus);
    _spu_t(1);
    _spu_t(3, arg0, size);
    return size;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_read);

s32 _spu_read(s32 arg0, u32 size) {
    _spu_t(2, _spu_tsa << _spu_mem_mode_plus);
    _spu_t(0);
    _spu_t(3, arg0, size);
    return size;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FsetRXX);

void _spu_FsetRXX(s32 arg0, u32 arg1, s32 arg2) {
    if (arg2 == 0) {
#ifdef VERSION_PC
        write_16(0x1F801C00 + arg0 * 2, arg1, __FILE__, __LINE__);
#else
        _spu_RXX->raw[arg0] = arg1;
#endif
        return;
    }

    _spu_RXX->raw[arg0] = arg1 >> _spu_mem_mode_plus;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FsetRXXa);

u32 _spu_FsetRXXa(s32 arg0, u32 arg1) {
    u32 temp_a3;
    u32 var_a1;

    var_a1 = arg1;
    if ((_spu_mem_mode != 0) && ((var_a1 % _spu_mem_mode_unit) != 0)) {
        var_a1 += _spu_mem_mode_unit;
        var_a1 &= ~_spu_mem_mode_unitM;
    }
    temp_a3 = var_a1 >> _spu_mem_mode_plus;

    switch (arg0) {
    case -1:
        return temp_a3 & 0xFFFF;
    case -2:
        return var_a1;
    default:
        _spu_RXX->raw[arg0] = temp_a3;
        return var_a1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FgetRXXa);

u32 _spu_FgetRXXa(s32 arg0, s32 arg1) {
    u16 temp = _spu_RXX->raw[arg0];
    if (arg1 == -1) {
        return temp;
    } else {
        return temp << _spu_mem_mode_plus;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FsetPCR);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FsetDelayW);

void _spu_FsetDelayW(void) {
    *D_80097C5C = (*D_80097C5C & 0xF0FFFFFF) | 0x20000000;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FsetDelayR);

void _spu_FsetDelayR(void) {
    *D_80097C5C = (*D_80097C5C & 0xF0FFFFFF) | 0x22000000;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/spu", _spu_FwaitFs);

void _spu_FwaitFs(void) {
    volatile int i;
    volatile int sp4;

    sp4 = 13;
    for (i = 0; i < 0xF0; i++) {
        sp4 *= 3;
    }
}
