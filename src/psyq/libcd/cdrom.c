#include "common.h"
#include "psyq/libcd.h"

extern StHEADER* StRingAddr;
extern u32 StRingSize;

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdrom", StSetRing);
/**
 * @brief Set the ring buffer used for CD-ROM streaming
 * 
 * Registers the ring buffer memory and its size (in frames) and clears it.
 * 
 * @param ring_addr Start address of the ring buffer
 * @param ring_size Ring buffer size in sectors
 */
void StSetRing(u_long* ring_addr, u_long ring_size)
{
    StRingAddr = (StHEADER*)ring_addr;
    StRingSize = ring_size;
    StClearRing();
}
