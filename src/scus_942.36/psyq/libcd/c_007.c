#include "common.h"
#include "psyq/libcd.h"

extern int D_800A188C;
extern StHEADER* D_800A326C;
extern int D_800A3340;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_007", StFreeRing);
u_long StFreeRing(u_long *base)
{
    int temp_a1;
    int i;
    short nSectors;
    StHEADER* temp_v0;
    StHEADER* temp_v0_2;

    temp_a1 = (base - (u_long*)&D_800A326C[D_800A3340]) / 504;
    temp_v0 = &D_800A326C[temp_a1];
    nSectors = D_800A326C[temp_a1].nSectors;
    if ((short)temp_v0->id != 4) {
        return 1;
    }
    for (i = 0; i < nSectors; i++) {
        temp_v0_2 = &D_800A326C[i+temp_a1];
        *(short*)temp_v0_2 = 0;
    }
    D_800A188C = i+temp_a1;
    return 0;
}
