#include "common.h"
#include "psyq/libcd.h"

extern int D_8009B69C;
extern short D_8009BC74;
extern int D_8009BC78;
extern int D_8009C85C;
extern int D_8009C860;
extern int D_8009C95C;
extern int D_8009C9FC;
extern int D_800A3028;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_005", StSetStream);
void StSetStream(u_long mode, u_long start_frame, u_long end_frame, void (*func1)(), void (*func2)())
{
    StSetMask(1, start_frame, end_frame);
    D_800A3028 = 0;
    D_8009C85C = func1;
    D_8009BC78 = mode & 1;
    D_8009C9FC = 0;
    D_8009C95C = 0;
    D_8009BC74 = 0;
    D_8009B69C = 0;
    D_8009C860 = func2;
}
