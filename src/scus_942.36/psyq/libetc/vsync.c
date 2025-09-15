#include "common.h"
#include "psyq/libetc.h"

extern volatile s32* D_80096408;
extern volatile s32* D_8009640C;
extern volatile s32 D_80096410; // HSync counter
extern volatile s32 D_80096414; 
extern volatile s32 D_800974D4; // VSync counter

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/vsync", VSync);
int VSync(int mode) {
    int syncFlag;
    int elapsed;
    int timeout;
    int v;
    int n;

    syncFlag = *D_80096408;
    elapsed = (*D_8009640C - D_80096410) & 0xFFFF;
    if (mode < 0) {
        return D_800974D4;
    }
    if (mode == 1) {
        return elapsed;
    }
    n = 1;
    v = mode > 0 ? D_80096414 - n + mode : D_80096414;
    timeout = mode > 0 ? mode - n : 0;
    v_wait(v, timeout);
    syncFlag = *D_80096408;
    v_wait(D_800974D4 + 1, 1);
    if (syncFlag & 0x400000 && (syncFlag ^ *D_80096408) >= 0) {
        do {
        } while (!((syncFlag ^ *D_80096408) & 0x80000000));
    }
    D_80096414 = D_800974D4;
    D_80096410 = *D_8009640C;
    return elapsed;
}

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
