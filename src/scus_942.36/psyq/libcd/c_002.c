#include "common.h"

extern s32 D_8009B69C;
extern s16 D_8009BC74;
extern s32 D_8009C8AC;
extern s32 D_8009CA08;
extern s32 D_800A15CC;
extern s32 D_800A15D0;
extern s32 D_800A188C;
extern s32 D_800A3340;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_002", StClearRing);
void StClearRing(void)
{
    D_800A188C = 0;
    D_800A15D0 = 0;
    D_800A15CC = 0;
    D_8009CA08 = 0;
    init_ring_status(0, D_800A3340);
    D_8009C8AC = 0;
    D_8009BC74 = 0;
    D_8009B69C = 0;
}
