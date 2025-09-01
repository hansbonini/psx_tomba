#include "common.h"
#include "psyq/libcd.h"
#include "psyq/kernel.h"

void def_cbsync(u_char intr, u_char* result);
void def_cbready(u_char intr, u_char* result);
void def_cbread(u_char intr, u_char* result);
extern char* D_80015F14;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/event", CdInit);
int CdInit(void) {
    int status;
    int i;
    i = 4;
    while(1) {
        status = CdReset(1);
        i+=-1;
        if (status == 1) break;
        status = -1;
        if (i == status) {
           printf(&D_80015F14);
          return 0;
        }
    }
    CdSyncCallback(def_cbsync);
    CdReadyCallback(def_cbready);
    CdReadCallback(def_cbread);
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/event", def_cbsync);
void def_cbsync(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpCOMP);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/event", def_cbready);
void def_cbready(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/event", def_cbread);
void def_cbread(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}
