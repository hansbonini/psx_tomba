#include "common.h"

typedef void (*Callback)();

Callback setIntrDMA(int index, Callback callback);
void trapIntrDMA(void);
void DMA_memclr(void* ptr, int size);

extern char* D_80016264[];
extern char* D_80016280[];
extern volatile unsigned long* D_800974DC;
extern Callback D_800974E0[8];
extern unsigned long* D_80097500;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", startIntrDMA);
void* startIntrDMA(void)
{
    DMA_memclr(&D_800974E0, 8);
    *D_800974DC = 0;
    InterruptCallback(3, &trapIntrDMA);
    return &setIntrDMA;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", trapIntrDMA);
void trapIntrDMA(void) {
    u32 mask;
    int i;

    while((mask = ((u32) *D_800974DC >> 24) & 0x7f) != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *D_800974DC &= (0xffffff | (1 << (i + 24)));
                if (D_800974E0[i] != 0) {
                     D_800974E0[i]();
                }
            }
        }
    }
    if (((*D_800974DC & 0xFF000000) == 0x80000000) || (*D_800974DC & 0x8000)) {
        printf(D_80016264, *D_800974DC);
        for (i = 0; i < 7; i++) {
            printf(D_80016280, i, D_80097500[4 * i]);
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", setIntrDMA);
Callback setIntrDMA(int index, Callback callback) {
    Callback prev = D_800974E0[index];
    if (callback != prev) {
        if (callback != 0) {
            D_800974E0[index] = callback;
            *D_800974DC = (*D_800974DC & 0xFFFFFF) | 0x800000 | ((1 << (index + 0x10)));
        } else {
            D_800974E0[index] = 0;
            *D_800974DC = ((*D_800974DC & 0xFFFFFF) | 0x800000) & ~(1 << (index + 0x10));
        }
    }
    return prev;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", DMA_memclr);
