#include "common.h"
#include "psyq/libcd.h"

volatile s8* c008_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c008_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c008_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c008_cd_reg3 = (volatile s8*)0x1F801803;

extern StHEADER* StRingAddr;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_008", init_ring_status);
/**
 * @brief Internal: mark a range of ring buffer sectors as free
 * 
 * Clears the header status of arg1 consecutive ring entries starting at
 * index arg0.
 * 
 * @param arg0 Index of the first ring entry
 * @param arg1 Number of entries to clear
 */
void init_ring_status(int arg0, u_long arg1)
{
    u_long i;
    StHEADER* temp_v0;

    for (i=0; i < arg1; i++){
        temp_v0 = &StRingAddr[i+arg0];
        *(int*)temp_v0 = 0;
    }
}