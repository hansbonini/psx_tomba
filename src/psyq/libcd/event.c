#include "common.h"
#include "psyq/libcd.h"
#include "psyq/kernel.h"

void def_cbsync(u_char intr, u_char* result);
void def_cbready(u_char intr, u_char* result);
void def_cbread(u_char intr, u_char* result);

// INCLUDE_ASM("nonmatchings/psyq/libcd/event", CdInit);
/**
 * @brief Initialize the CD-ROM subsystem
 * 
 * Resets the drive (retrying up to four times) and installs default
 * callbacks that deliver the HwCdRom events.
 * 
 * @return 1 on success, 0 on failure
 */
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
           printf("CdInit: Init failed\n");
          return 0;
        }
    }
    CdSyncCallback(def_cbsync);
    CdReadyCallback(def_cbready);
    CdReadCallback(def_cbread);
    return 1;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/event", def_cbsync);
/**
 * @brief Internal: default sync callback
 * 
 * Delivers the HwCdRom / EvSpCOMP event.
 * 
 * @param intr Interrupt type
 * @param result Result bytes
 */
void def_cbsync(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpCOMP);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/event", def_cbready);
/**
 * @brief Internal: default ready callback
 * 
 * Delivers the HwCdRom / EvSpDR event.
 * 
 * @param intr Interrupt type
 * @param result Result bytes
 */
void def_cbready(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/event", def_cbread);
/**
 * @brief Internal: default CdRead() completion callback
 * 
 * Delivers the HwCdRom / EvSpDR event.
 * 
 * @param intr Interrupt type
 * @param result Result bytes
 */
void def_cbread(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}
