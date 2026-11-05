#include "common.h"
#include "psyq/libcd.h"

volatile s8* c009_cd_reg0 = (volatile s8*)0x1F801800;
volatile s8* c009_cd_reg1 = (volatile s8*)0x1F801801;
volatile s8* c009_cd_reg2 = (volatile s8*)0x1F801802;
volatile s8* c009_cd_reg3 = (volatile s8*)0x1F801803;

extern s32 StRingIdx3;
extern s32 StEndFrame;
extern StHEADER* StRingAddr;
extern volatile s32 StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_009", StGetNext);
u_long StGetNext(u_long** addr, u_long** header) {
    volatile StHEADER* ptr = &StRingAddr[StRingIdx3];
    if (ptr->id == 1) {
        StRingIdx3 = 0;
        if (StEndFrame != 0) {
            ptr->id = 0;
        }
        ptr = &StRingAddr[StRingIdx3];
    }
    if (ptr->id == 2) {
        ptr->id = 4;
        *addr = &StRingAddr[StRingSize] + (StRingIdx3 * 0x3F);
        *header = ptr;
        return 0;
    } else {
        return 1;
    }
}
