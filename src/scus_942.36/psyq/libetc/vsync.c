#include "common.h"
#include "psyq/libetc.h"

extern volatile s32 D_800974D4;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vsync", VSync);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vsync", v_wait);
void v_wait(int v, int timeout) {
    volatile int t = timeout << 15;
    while (D_800974D4 < v) {
        if (!t--) {
            puts("VSync: timeout\n");
            ChangeClearPAD(0);
            ChangeClearRCnt(3, 0);
            return;
        }
    }
}
