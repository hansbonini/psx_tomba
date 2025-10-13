#include "common.h"
#include "psyq/libcd.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", StCdInterrupt);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", mem2mem);
void mem2mem(s32* dst, s32* src, u32 num) {
    u32 i;
    for (i = 0; i < num; i++) {
        *dst++ = *src++;
    }
}


INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_011", dma_execute);
