#include "common.h"

typedef void (*Callback)();

void setIntrDMA(int arg0, Callback arg1);
void trapIntrDMA(void);
void DMA_memclr(void* ptr, int size);

extern volatile unsigned long* D_800974DC;
extern Callback D_800974E0;

void* startIntrDMA(void)
{
    DMA_memclr(&D_800974E0, 8);
    *D_800974DC = 0;
    InterruptCallback(3, &trapIntrDMA);
    return &setIntrDMA;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", trapIntrDMA);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", setIntrDMA);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_dma", DMA_memclr);
