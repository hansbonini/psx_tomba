#include "common.h"
#include "psyq/libstamp.h"
#include "psyq/libetc.h"

PsyqStamp libetc_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_ETC, 19, 30, 52);
volatile s32* vsync_gpustat = (volatile s32*)0x1F801814;
volatile s32* vsync_rcnt1 = (volatile s32*)0x1F801110;
/** @brief Horizontal blank counter value captured at the previous VSync() call */
volatile s32 Hcount = 0;
volatile s32 D_80096414 = 0;

extern volatile s32 Vcount; // VSync counter

// INCLUDE_ASM("nonmatchings/psyq/libetc/vsync", VSync);
/**
 * @brief Wait for vertical blank
 * 
 * With mode 0 waits for the next vertical blank; with a positive value n
 * waits until n vertical blanks have passed since the previous call. Also
 * synchronizes with the interlace field when interlaced output is used.
 * 
 * @param mode 0 = wait one VBlank, n > 1 = wait n VBlanks since the last call, 1 = do not wait and return the elapsed time, negative = return the VSync counter
 * @return Horizontal blank count elapsed since the previous call, or the VBlank counter when mode is negative
 */
int VSync(int mode) {
    int syncFlag;
    int elapsed;
    int timeout;
    int v;
    int n;

    syncFlag = *vsync_gpustat;
    elapsed = (*vsync_rcnt1 - Hcount) & 0xFFFF;
    if (mode < 0) {
        return Vcount;
    }
    if (mode == 1) {
        return elapsed;
    }
    n = 1;
    v = mode > 0 ? D_80096414 - n + mode : D_80096414;
    timeout = mode > 0 ? mode - n : 0;
    v_wait(v, timeout);
    syncFlag = *vsync_gpustat;
    v_wait(Vcount + 1, 1);
    if (syncFlag & 0x400000 && (syncFlag ^ *vsync_gpustat) >= 0) {
        do {
        } while (!((syncFlag ^ *vsync_gpustat) & 0x80000000));
    }
    D_80096414 = Vcount;
    Hcount = *vsync_rcnt1;
    return elapsed;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/vsync", v_wait);
/**
 * @brief Internal: wait until the VSync counter reaches a value
 * 
 * Busy-waits on the VBlank counter. On timeout it prints a message and
 * makes the BIOS acknowledge the VBlank interrupts again.
 * 
 * @param v Target VBlank count
 * @param timeout Timeout in units of about 32768 loop iterations
 */
void v_wait(int v, int timeout) {
    volatile int t = timeout << 15;
    while (Vcount < v) {
        if (!t--) {
            puts("VSync: timeout\n");
            ChangeClearPAD(0);
            ChangeClearRCnt(3, 0);
            return;
        }
    }
}
