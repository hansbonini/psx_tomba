#include "common.h"
#include "psyq/libcd.h"

extern s32 StMode;

void StCdInterrupt2(u_char intr, u_char* result);
void data_ready_callback();

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread2", CdRead2);
/**
 * @brief Start a streaming read
 * 
 * Sets the CD-ROM mode and, when streaming mode is requested, installs the
 * streaming DMA and data ready callbacks before issuing CdlReadS.
 * 
 * @param mode CD-ROM mode (CdlModeStream, CdlModeSize1, ...)
 * @return 1 on success, 0 on failure
 */
int CdRead2(long mode) {
    u8 param = mode;
    CdControl(CdlSetmode, &param, NULL);
    if (mode & CdlModeStream) {
        if (mode & CdlModeSize1) {
            StMode = 0;
        } else {
            StMode = 1;
        }
        CdDataCallback(data_ready_callback);
        CdReadyCallback(StCdInterrupt2);
    }
    return CdControl(CdlReadS, NULL, NULL);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread2", StCdInterrupt2);
/**
 * @brief Internal: data ready callback used by CdRead2()
 * 
 * Forwards the event to StCdInterrupt().
 * 
 * @param intr Interrupt type
 * @param result Result bytes
 */
void StCdInterrupt2(u_char intr, u_char* result) {
    StCdInterrupt();
}
