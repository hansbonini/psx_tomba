#include "common.h"
#include "psyq/libcd.h"

extern u_long D_8009C960;
extern u_long D_800A302C;
extern u_long D_800A3060;

// INCLUDE_ASM("nonmatchings/psyq/libcd/c_010", StSetMask);
void StSetMask(u_long mask, u_long start, u_long end)
{
    D_800A3060 = mask;
    D_8009C960 = start;
    D_800A302C = end;
}
