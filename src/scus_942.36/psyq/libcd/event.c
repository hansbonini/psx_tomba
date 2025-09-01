#include "common.h"
#include "psyq/kernel.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/event", CdInit);

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
