#include "common.h"
#include "psyq/libcd.h"

volatile u8* c011_cd_reg0 = (volatile u8*)0x1F801800;
volatile u8* c011_cd_reg1 = (volatile u8*)0x1F801801;
volatile u8* c011_cd_reg2 = (volatile u8*)0x1F801802;
volatile u8* c011_cd_reg3 = (volatile u8*)0x1F801803;
volatile s32* c011_cd_delay = (volatile s32*)0x1F801018;
volatile s32* c011_com_delay = (volatile s32*)0x1F801020;
volatile s32* c011_dpcr = (volatile s32*)0x1F8010F0;
volatile u8* c011_dicr = (volatile u8*)0x1F8010F4;
volatile s32* c011_d1_chcr = (volatile s32*)0x1F801098;
volatile s32* c011_d1_madr = (volatile s32*)0x1F801090;
volatile s32* c011_d2_chcr = (volatile s32*)0x1F8010A8;
volatile s32* c011_d2_madr = (volatile s32*)0x1F8010A0;
volatile s32* c011_d3_chcr = (volatile s32*)0x1F8010B8;
volatile s32* c011_d3_madr = (volatile s32*)0x1F8010B0;
volatile s32* c011_d5_chcr = (volatile s32*)0x1F8010D8;
volatile s32* c011_d5_madr = (volatile s32*)0x1F8010D0;
volatile s32* c011_istat = (volatile s32*)0x1F801070;
volatile s32* c011_imask = (volatile s32*)0x1F801074;
s32 debug_cause = 0;
s32 D_800963FC = 0;

typedef char Result_t[8];
typedef struct {
    s32 madr;
    s32 bcr;
    s32 chcr;
    s32 unk;
} DMA_CONTROL;
extern volatile u16* c011_header;
extern s32 Stframe_no;
extern s16 Stsector_offset;
extern s32 StRgb24;
extern s32 StMode;
extern void (*StFunc2)(void);
extern s32 StCHANNEL;
extern s32 StStartFrame;
extern s32 CChannel;
extern s32 StFinalSector;
extern s32 StEmu_Idx;
extern s32 StRingIdx1;
extern s32 StRingIdx2;
extern s32 StEmu_Addr;
extern u32 StEndFrame;
extern s32 StSTART_FLAG;
extern u16* StRingBase;
extern StHEADER* StRingAddr;
extern bool StCdIntrFlag;
extern s32 StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_011", StCdInterrupt);

void StCdInterrupt(void) {
    volatile s16 subroutine_arg8[4];
    CdlLOC loc;
    Result_t result;
    u32* var_a1;
    s32 var_t0;
    u32* var_a0;
    u32 var_v1_2;
    u32 var_v1_3;
    u8* var_v1;

    if (StFinalSector == 1) {
        return;
    }
    if ((StRgb24 != 0) && (*c011_d1_chcr & 0x01000000)) {
        StCdIntrFlag = true;
        if (StEmu_Addr != 0) {
            StEmu_Idx++;
        }
        debug_cause = 1;
        return;
    }
    if (CdReady(1, &result) == CdlDiskError) {
        return;
    }
    subroutine_arg8[1] = result[0];
    subroutine_arg8[2] = result[1];
    if (subroutine_arg8[1] & 4) {
        debug_cause = 3;
        return;
    }
    c011_header = (u16*)&StRingAddr[StRingIdx1];
    if (c011_header[0] != 0) {
        if (StEmu_Addr != 0) {
            StEmu_Idx++;
        }
        debug_cause = 4;
        return;
    }
    *c011_cd_reg0 = 0;
    *c011_cd_reg3 = 0;
    *c011_cd_reg0 = 0;
    *c011_cd_reg3 = 0x80;
    *c011_cd_delay = 0x20943;
    *c011_com_delay = 0x1323;
    if (StMode == 0) {
        var_v1 = (u8*)&subroutine_arg8[4];
        do {
            *var_v1++ = *c011_cd_reg2;
        } while (var_v1 < &subroutine_arg8[6]);
        for (var_v1_2 = 0; var_v1_2 < 8; var_v1_2++) {
            *c011_cd_reg2;
        }
    }
    var_t0 = 0x11000000;
    if (StEmu_Addr != 0) {
        mem2mem(c011_header, StEmu_Addr + (StEmu_Idx << 0xB), 8, 0);
    } else {
        dma_execute(3, c011_header, 0, 8, var_t0, 0, 0);
    }
    while (*c011_d3_chcr & 0x01000000) {
    }
    ((StHEADER*)c011_header)->loc = loc;
    *c011_cd_delay = 0x20843;
    *c011_com_delay = 0x1325;
    if ((StSTART_FLAG == 1) && (StStartFrame != 0)) {
        if (StStartFrame != c011_header[4]) {
            c011_header[0] = 0;
            if (StEmu_Addr != 0) {
                StEmu_Idx++;
            }
            return;
        }
        StSTART_FLAG = 0;
    }
    if ((c011_header[0] != 0x160) || (((c011_header[1] >> 0xA) & 0x1F) != CChannel)) {
        if (StEmu_Addr != 0) {
            StEmu_Idx = 0;
        } else {
            c011_header[0];
        }
        debug_cause = 5;
        c011_header[0] = 0;
        return;
    }
    if ((Stsector_offset != c011_header[2]) || ((Stframe_no != 0) && (Stframe_no != c011_header[4]))) {
        Stframe_no = 0;
        Stsector_offset = 0;
        init_ring_status(StRingIdx2, StRingIdx1 - StRingIdx2);
        StRingIdx1 = StRingIdx2;
        c011_header[0] = 0;
        if (StEmu_Addr != 0) {
            StEmu_Idx++;
        }
        debug_cause = 6;
        return;
    }
    if (c011_header[2] == 0) {
        Stsector_offset = 0;
        Stframe_no = c011_header[4];
        if ((StEndFrame != 0) && (Stframe_no >= StEndFrame)) {
            Stframe_no = 0;
            Stsector_offset = 0;
            init_ring_status(StRingIdx2, StRingIdx1 - StRingIdx2);
            StRingIdx1 = StRingIdx2;
            c011_header[0] = 0;
            StSTART_FLAG = 1;
            if (StFunc2 != NULL) {
                StFunc2();
            }
            if (StEmu_Addr != 0) {
                StEmu_Idx++;
            }
            debug_cause = 7;
            return;
        }
        if ((u32) (StRingSize - StRingIdx1 - 1) < c011_header[3]) {
            if (StEndFrame == 0) {
                c011_header[0] = 1;
                StSTART_FLAG = 1;
                if (StFunc2 != NULL) {
                    StFunc2();
                }
                if (StEmu_Addr != 0) {
                    StEmu_Idx++;
                }
                debug_cause = 8;
                return;
            }
            if ((short)StRingAddr->id != 0) {
                c011_header[0] = 0;
                if (StEmu_Addr != 0) {
                    StEmu_Idx++;
                }
                debug_cause = 9;
                return;
            }
            c011_header[0] = 1;
            var_a1 = StRingAddr;
            var_a0 = c011_header;
            StRingIdx1 = 0;
            for (var_v1_3 = 0; var_v1_3 < 8; var_v1_3++) {
                *var_a1++ = *var_a0++;
            }
            c011_header = StRingAddr;
        }
        StRingIdx2 = StRingIdx1;
    }
    debug_cause = 10;
    Stsector_offset++;
    StRingBase = &StRingAddr[StRingSize] + (StRingIdx1 * 0x3F);
    
    if (StRgb24 != 0) {
        var_t0 = 0x11000000;
        *c011_cd_delay = 0x20943;
        *c011_com_delay = 0x1323;
    } else {
        *c011_cd_delay = 0x21020843;
        var_t0 = 0x11400100;
    }
    if ((c011_header[3] - 1) == c011_header[2]) {
        StFinalSector = 1;
        if (StEmu_Addr != 0) {
            mem2mem(StRingBase, StEmu_Addr + (StEmu_Idx << 0xB) + 0x20, 0x1F8, 1);
            StEmu_Idx++;
        } else {
            dma_execute(3, StRingBase, 0, 0x1F8, var_t0, 1, 0);
        }
        Stsector_offset = 0;
        Stframe_no = 0;
        CChannel = StCHANNEL;
    } else {
        if (StEmu_Addr != 0) {
            mem2mem(StRingBase, StEmu_Addr + (StEmu_Idx << 0xB) + 0x20, 0x1F8, 0);
            StEmu_Idx++;
        } else {
            dma_execute(3, StRingBase, 0, 0x1F8, var_t0, 0, 0);
        }
    }
    *c011_com_delay = 0x1325;
    c011_header[0] = 3;
    StRingIdx1 += 1;
    if ((StEmu_Addr != 0) && (StFinalSector != 0)) {
        data_ready_callback();
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_011", mem2mem);
void mem2mem(s32* dst, s32* src, u32 num) {
    u32 i;
    for (i = 0; i < num; i++) {
        *dst++ = *src++;
    }
}


// INCLUDE_ASM("nonmatchings/psyq/libcd/c_011", dma_execute);
void dma_execute(s32 id, void* addr, u32 blocks, u32 size, u32 control,
                 u_char arg5, u32 arg6) {
    s32 i;
    s32 temp;
    s32 temp2;
    u8 v;
    volatile s32 ret;
    volatile s32* ptr;

    for (i = 0; *(volatile u32*)(0x1F801088 + (id << 4)) & 0x01000000; i++) {
        if (i == 0x10000) {
            printf("DMA STATUS ERROR %x\n",
                   *(volatile u32*)(0x1F801088 + (id << 4)));
            break;
        }
    }
    if (arg5 == 1) {
        u8* q = (u8*)c011_dicr;
        v = q[2];
        v |= 1 << id;
        q[2] = v;
    } else {
        u8* q = (u8*)c011_dicr;
        v = q[2];
        v &= ~(1 << id);
        q[2] = v;
    }
    do {
        ret = *(volatile s32*)c011_dicr;
    } while (0);
    temp2 = id << 2;
    temp2 = temp2 + 3;
    temp = 1;
    temp = temp << temp2;
    ptr = &((volatile DMA_CONTROL*)0x1F801080)[id].madr;
    temp2 = *c011_dpcr;
    temp2 |= temp;
    *c011_dpcr = temp2;
    *ptr++ = (s32)addr;
    *ptr++ = (blocks << 16) | size;
    while (!(*c011_cd_reg0 & 0x40)) {
    }
    *ptr = control;
    do {
        ret = *ptr;
    } while (0);
}
