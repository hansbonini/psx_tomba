#include "common.h"
#include "psyq/libcd.h"

extern volatile s8* D_80096340;
extern volatile s8* D_8009634C;
extern CdlLOC D_8009B2D0;
extern s32 D_8009B2D4;
extern void (*D_8009C85C)(void);
extern s32 D_8009CA08;
extern s32 D_8009BC7C;
extern s32 D_800A15CC;
extern s32 D_800A15D0;
extern StHEADER* D_800A326C;

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_003", data_ready_callback);
void data_ready_callback(void)
{
    StHEADER* ptr = &D_800A326C[D_800A15D0];
    do {
        ptr->id = 2;
    } while(0);
    D_8009B2D0 = ptr->loc;
    D_8009B2D4 = ptr->frameCount;
    D_800A15D0 = D_800A15CC;
    if (D_8009C85C != NULL) {
        D_8009C85C();
    }
    D_8009CA08 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_003", StGetBackloc);
s32 StGetBackloc(CdlLOC* loc)
{
    if (D_8009BC7C != 0) return -1;
    CdIntToPos(CdPosToInt(&D_8009B2D0) + 1, loc);
    return D_8009B2D4;
}
