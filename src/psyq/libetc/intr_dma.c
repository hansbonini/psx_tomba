#include "common.h"

typedef void (*Callback)();

volatile unsigned long* dma_dicr = (volatile unsigned long*)0x1F8010F4;
Callback dma_callbacks[8] = {0};
unsigned long* dma_madr = (unsigned long*)0x1F801080;

Callback setIntrDMA(int index, Callback callback);
void trapIntrDMA(void);
void DMA_memclr(int* ptr, int size);

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_dma", startIntrDMA);
void* startIntrDMA(void)
{
    DMA_memclr(&dma_callbacks, 8);
    *dma_dicr = 0;
    InterruptCallback(3, &trapIntrDMA);
    return &setIntrDMA;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_dma", trapIntrDMA);
void trapIntrDMA(void) {
    u32 mask;
    int i;

    while((mask = ((u32) *dma_dicr >> 24) & 0x7f) != 0) {
        for (i = 0; mask != 0 && i < 7; i++, mask >>= 1) {
            if (mask & 1) {
                *dma_dicr &= (0xffffff | (1 << (i + 24)));
                if (dma_callbacks[i] != 0) {
                     dma_callbacks[i]();
                }
            }
        }
    }
    if (((*dma_dicr & 0xFF000000) == 0x80000000) || (*dma_dicr & 0x8000)) {
        printf("DMA bus error: code=%08x\n", *dma_dicr);
        for (i = 0; i < 7; i++) {
            printf("MADR[%d]=%08x\n", i, dma_madr[4 * i]);
        }
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_dma", setIntrDMA);
Callback setIntrDMA(int index, Callback callback) {
    Callback prev = dma_callbacks[index];
    if (callback != prev) {
        if (callback != 0) {
            dma_callbacks[index] = callback;
            *dma_dicr = (*dma_dicr & 0xFFFFFF) | 0x800000 | ((1 << (index + 0x10)));
        } else {
            dma_callbacks[index] = 0;
            *dma_dicr = ((*dma_dicr & 0xFFFFFF) | 0x800000) & ~(1 << (index + 0x10));
        }
    }
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_dma", DMA_memclr);
void DMA_memclr(int* ptr, int size) {
    while (size--) {
        *ptr++ = 0;
    }
}
