#include "common.h"
#include "psyq/libcd.h"

volatile s8* c003_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c003_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c003_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c003_cd_reg3 = (volatile s8*)0x1F801803;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_003", StUnSetRing);
/**
 * @brief Stop using the streaming ring buffer
 * 
 * Removes the streaming data/ready callbacks and resets the CD-ROM
 * interrupt enable register.
 */
void StUnSetRing(void)
{
    EnterCriticalSection();
    CdDataCallback(0);
    CdReadyCallback(0);
    *c003_cd_reg0 = 0;
    *c003_cd_reg3 = 0;
    ExitCriticalSection();
}
