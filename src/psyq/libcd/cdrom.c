#include "common.h"
#include "psyq/libcd.h"

extern StHEADER* StRingAddr;
extern u32 StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdrom", StSetRing);
void StSetRing(u_long* ring_addr, u_long ring_size)
{
    StRingAddr = (StHEADER*)ring_addr;
    StRingSize = ring_size;
    StClearRing();
}
