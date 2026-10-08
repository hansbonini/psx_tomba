#include "common.h"
#include "psyq/libcd.h"

typedef char Result_t[8];
extern volatile s32* D_800963C0;
extern volatile s32* D_800963C4;
extern volatile s32* D_800963D0;
extern volatile s32* D_800963E0;
extern s32 D_800963F8;
extern volatile u16* D_8009B2D8;
extern s32 D_8009B69C;
extern s16 D_8009BC74;
extern s32 D_8009BC78;
extern s32 D_8009BC7C;
extern void (*D_8009C860)(void);
extern s32 D_8009C95C;
extern s32 D_8009C960;
extern s32 D_8009C9FC;
extern s32 D_8009CA08;
extern s32 D_8009EB48;
extern s32 D_800A15CC;
extern s32 D_800A15D0;
extern s32 D_800A3028;
extern u32 D_800A302C;
extern s32 D_800A3060;
extern u16* D_800A3268;
extern StHEADER* D_800A326C;
extern volatile u8* D_800963B0;
extern volatile u8* D_800963B8;
extern volatile u8* D_800963BC;
extern bool D_8009C8AC;
extern s32 D_800A3340;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", StCdInterrupt);

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

    if (D_8009CA08 == 1) {
        return;
    }
    if ((D_8009BC78 != 0) && (*D_800963D0 & 0x01000000)) {
        D_8009C8AC = true;
        if (D_800A3028 != 0) {
            D_8009EB48++;
        }
        D_800963F8 = 1;
        return;
    }
    if (CdReady(1, &result) == CdlDiskError) {
        return;
    }
    subroutine_arg8[1] = result[0];
    subroutine_arg8[2] = result[1];
    if (subroutine_arg8[1] & 4) {
        D_800963F8 = 3;
        return;
    }
    D_8009B2D8 = (u16*)&D_800A326C[D_800A15CC];
    if (D_8009B2D8[0] != 0) {
        if (D_800A3028 != 0) {
            D_8009EB48++;
        }
        D_800963F8 = 4;
        return;
    }
    *D_800963B0 = 0;
    *D_800963BC = 0;
    *D_800963B0 = 0;
    *D_800963BC = 0x80;
    *D_800963C0 = 0x20943;
    *D_800963C4 = 0x1323;
    if (D_8009BC7C == 0) {
        var_v1 = (u8*)&subroutine_arg8[4];
        do {
            *var_v1++ = *D_800963B8;
        } while (var_v1 < &subroutine_arg8[6]);
        for (var_v1_2 = 0; var_v1_2 < 8; var_v1_2++) {
            *D_800963B8;
        }
    }
    var_t0 = 0x11000000;
    if (D_800A3028 != 0) {
        mem2mem(D_8009B2D8, D_800A3028 + (D_8009EB48 << 0xB), 8, 0);
    } else {
        dma_execute(3, D_8009B2D8, 0, 8, var_t0, 0, 0);
    }
    while (*D_800963E0 & 0x01000000) {
    }
    ((StHEADER*)D_8009B2D8)->loc = loc;
    *D_800963C0 = 0x20843;
    *D_800963C4 = 0x1325;
    if ((D_800A3060 == 1) && (D_8009C960 != 0)) {
        if (D_8009C960 != D_8009B2D8[4]) {
            D_8009B2D8[0] = 0;
            if (D_800A3028 != 0) {
                D_8009EB48++;
            }
            return;
        }
        D_800A3060 = 0;
    }
    if ((D_8009B2D8[0] != 0x160) || (((D_8009B2D8[1] >> 0xA) & 0x1F) != D_8009C9FC)) {
        if (D_800A3028 != 0) {
            D_8009EB48 = 0;
        } else {
            D_8009B2D8[0];
        }
        D_800963F8 = 5;
        D_8009B2D8[0] = 0;
        return;
    }
    if ((D_8009BC74 != D_8009B2D8[2]) || ((D_8009B69C != 0) && (D_8009B69C != D_8009B2D8[4]))) {
        D_8009B69C = 0;
        D_8009BC74 = 0;
        init_ring_status(D_800A15D0, D_800A15CC - D_800A15D0);
        D_800A15CC = D_800A15D0;
        D_8009B2D8[0] = 0;
        if (D_800A3028 != 0) {
            D_8009EB48++;
        }
        D_800963F8 = 6;
        return;
    }
    if (D_8009B2D8[2] == 0) {
        D_8009BC74 = 0;
        D_8009B69C = D_8009B2D8[4];
        if ((D_800A302C != 0) && (D_8009B69C >= D_800A302C)) {
            D_8009B69C = 0;
            D_8009BC74 = 0;
            init_ring_status(D_800A15D0, D_800A15CC - D_800A15D0);
            D_800A15CC = D_800A15D0;
            D_8009B2D8[0] = 0;
            D_800A3060 = 1;
            if (D_8009C860 != NULL) {
                D_8009C860();
            }
            if (D_800A3028 != 0) {
                D_8009EB48++;
            }
            D_800963F8 = 7;
            return;
        }
        if ((u32) (D_800A3340 - D_800A15CC - 1) < D_8009B2D8[3]) {
            if (D_800A302C == 0) {
                D_8009B2D8[0] = 1;
                D_800A3060 = 1;
                if (D_8009C860 != NULL) {
                    D_8009C860();
                }
                if (D_800A3028 != 0) {
                    D_8009EB48++;
                }
                D_800963F8 = 8;
                return;
            }
            if ((short)D_800A326C->id != 0) {
                D_8009B2D8[0] = 0;
                if (D_800A3028 != 0) {
                    D_8009EB48++;
                }
                D_800963F8 = 9;
                return;
            }
            D_8009B2D8[0] = 1;
            var_a1 = D_800A326C;
            var_a0 = D_8009B2D8;
            D_800A15CC = 0;
            for (var_v1_3 = 0; var_v1_3 < 8; var_v1_3++) {
                *var_a1++ = *var_a0++;
            }
            D_8009B2D8 = D_800A326C;
        }
        D_800A15D0 = D_800A15CC;
    }
    D_800963F8 = 10;
    D_8009BC74++;
    D_800A3268 = &D_800A326C[D_800A3340] + (D_800A15CC * 0x3F);
    
    if (D_8009BC78 != 0) {
        var_t0 = 0x11000000;
        *D_800963C0 = 0x20943;
        *D_800963C4 = 0x1323;
    } else {
        *D_800963C0 = 0x21020843;
        var_t0 = 0x11400100;
    }
    if ((D_8009B2D8[3] - 1) == D_8009B2D8[2]) {
        D_8009CA08 = 1;
        if (D_800A3028 != 0) {
            mem2mem(D_800A3268, D_800A3028 + (D_8009EB48 << 0xB) + 0x20, 0x1F8, 1);
            D_8009EB48++;
        } else {
            dma_execute(3, D_800A3268, 0, 0x1F8, var_t0, 1, 0);
        }
        D_8009BC74 = 0;
        D_8009B69C = 0;
        D_8009C9FC = D_8009C95C;
    } else {
        if (D_800A3028 != 0) {
            mem2mem(D_800A3268, D_800A3028 + (D_8009EB48 << 0xB) + 0x20, 0x1F8, 0);
            D_8009EB48++;
        } else {
            dma_execute(3, D_800A3268, 0, 0x1F8, var_t0, 0, 0);
        }
    }
    *D_800963C4 = 0x1325;
    D_8009B2D8[0] = 3;
    D_800A15CC += 1;
    if ((D_800A3028 != 0) && (D_8009CA08 != 0)) {
        data_ready_callback();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", mem2mem);
void mem2mem(s32* dst, s32* src, u32 num) {
    u32 i;
    for (i = 0; i < num; i++) {
        *dst++ = *src++;
    }
}


INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", dma_execute);
