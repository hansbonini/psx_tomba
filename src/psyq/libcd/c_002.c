#include "common.h"
#include "psyq/libcd.h"

volatile s8* c002_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c002_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c002_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c002_cd_reg3 = (volatile s8*)0x1F801803;

extern s32 Stframe_no;
extern s16 Stsector_offset;
extern s32 StCdIntrFlag;
extern s32 StFinalSector;
extern s32 StRingIdx1;
extern s32 StRingIdx2;
extern s32 StRingIdx3;
extern s32 StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_002", StClearRing);
/**
 * @brief Clear the streaming ring buffer
 * 
 * Resets all ring indexes and the streaming state and marks every ring
 * entry as free.
 */
void StClearRing(void)
{
    StRingIdx3 = 0;
    StRingIdx2 = 0;
    StRingIdx1 = 0;
    StFinalSector = 0;
    init_ring_status(0, StRingSize);
    StCdIntrFlag = 0;
    Stsector_offset = 0;
    Stframe_no = 0;
}
