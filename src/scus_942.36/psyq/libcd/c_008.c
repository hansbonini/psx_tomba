#include "common.h"
#include "psyq/libcd.h"

extern StHEADER* D_800A326C;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_008", init_ring_status);
void init_ring_status(int arg0, u_long arg1)
{
    u_long i;
    StHEADER* temp_v0;

    for (i=0; i < arg1; i++){
        temp_v0 = &D_800A326C[i+arg0];
        *(int*)temp_v0 = 0;
    }
}