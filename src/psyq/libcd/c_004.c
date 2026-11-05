#include "common.h"
#include "psyq/libcd.h"

volatile s8* c004_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c004_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c004_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c004_cd_reg3 = (volatile s8*)0x1F801803;

extern CdlLOC previous_frame_location;
extern int next_frameid;
extern void (*StFunc1)(void);
extern int StFinalSector;
extern int StMode;
extern int StRingIdx1;
extern int StRingIdx2;
extern StHEADER* StRingAddr;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_004", data_ready_callback);
void data_ready_callback(void)
{
    StHEADER* ptr = &StRingAddr[StRingIdx2];
    do {
        ptr->id = 2;
    } while(0);
    previous_frame_location = ptr->loc;
    next_frameid = ptr->frameCount;
    StRingIdx2 = StRingIdx1;
    if (StFunc1 != NULL) {
        StFunc1();
    }
    StFinalSector = 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_004", StGetBackloc);
int StGetBackloc(CdlLOC* loc)
{
    if (StMode != 0) return -1;
    CdIntToPos(CdPosToInt(&previous_frame_location) + 1, loc);
    return next_frameid;
}
