#include "common.h"
#include "psyq/libcd.h"

extern StHEADER* D_800A326C;
extern u32 D_800A3340;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdrom", StSetRing);
void StSetRing(u_long* ring_addr, u_long ring_size)
{
    D_800A326C = (StHEADER*)ring_addr;
    D_800A3340 = ring_size;
    StClearRing();
}
