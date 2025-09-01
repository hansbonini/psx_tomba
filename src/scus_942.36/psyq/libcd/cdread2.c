#include "common.h"
#include "psyq/libcd.h"

extern s32 D_8009BC7C;

void StCdInterrupt2(u_char intr, u_char* result);
void data_ready_callback();

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread2", CdRead2);
int CdRead2(long mode) {
    u8 param = mode;
    CdControl(CdlSetmode, &param, NULL);
    if (mode & CdlModeStream) {
        if (mode & CdlModeSize1) {
            D_8009BC7C = 0;
        } else {
            D_8009BC7C = 1;
        }
        CdDataCallback(data_ready_callback);
        CdReadyCallback(StCdInterrupt2);
    }
    return CdControl(CdlReadS, NULL, NULL);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread2", StCdInterrupt2);
void StCdInterrupt2(u_char intr, u_char* result) {
    StCdInterrupt();
}
