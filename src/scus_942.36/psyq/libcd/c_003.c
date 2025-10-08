#include "common.h"
#include "psyq/libcd.h"
extern volatile s8* D_80096340;
extern volatile s8* D_8009634C;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_003", StUnSetRing);
void StUnSetRing(void)
{
    EnterCriticalSection();
    CdDataCallback(0);
    CdReadyCallback(0);
    *D_80096340 = 0;
    *D_8009634C = 0;
    ExitCriticalSection();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_003", data_ready_callback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_003", StGetBackloc);
