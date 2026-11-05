#include "common.h"
#include "psyq/libcd.h"

volatile s8* c010_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c010_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c010_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c010_cd_reg3 = (volatile s8*)0x1F801803;

extern u_long StStartFrame;
extern u_long StEndFrame;
extern u_long StSTART_FLAG;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_010", StSetMask);
/**
 * @brief Set the streaming start flag and frame range
 * 
 * Stores the start flag and the first/last frame numbers used by the
 * streaming interrupt handler.
 * 
 * @param mask Start flag (1 = waiting for the start frame)
 * @param start First frame number
 * @param end Last frame number
 */
void StSetMask(u_long mask, u_long start, u_long end)
{
    StSTART_FLAG = mask;
    StStartFrame = start;
    StEndFrame = end;
}
