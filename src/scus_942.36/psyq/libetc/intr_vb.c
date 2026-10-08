#include "common.h"

extern void (*D_800974B4[8])(void);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", startIntrVSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", trapIntrVSync);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", setIntrVSync);

void setIntrVSync(int index, void (*callback)(void))
{
    if (callback != D_800974B4[index]) {
        D_800974B4[index] = callback;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", VSync_memclr);

void VSync_memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}
