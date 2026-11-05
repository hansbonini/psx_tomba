#include "common.h"
#include "psyq/libcd.h"

volatile s8* c007_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c007_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c007_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c007_cd_reg3 = (volatile s8*)0x1F801803;

extern int StRingIdx3;
extern StHEADER* StRingAddr;
extern int StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_007", StFreeRing);
u_long StFreeRing(u_long *base)
{
    int temp_a1;
    int i;
    short nSectors;
    StHEADER* temp_v0;
    StHEADER* temp_v0_2;

    temp_a1 = (base - (u_long*)&StRingAddr[StRingSize]) / 504;
    temp_v0 = &StRingAddr[temp_a1];
    nSectors = StRingAddr[temp_a1].nSectors;
    if ((short)temp_v0->id != 4) {
        return 1;
    }
    for (i = 0; i < nSectors; i++) {
        temp_v0_2 = &StRingAddr[i+temp_a1];
        *(short*)temp_v0_2 = 0;
    }
    StRingIdx3 = i+temp_a1;
    return 0;
}
