#include "common.h"
#include "psyq/libcd.h"

extern s32 D_800A188C;
extern s32 D_800A302C;
extern StHEADER* D_800A326C;
extern volatile s32 D_800A3340;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/c_009", StGetNext);
u_long StGetNext(u_long** addr, u_long** header) {
    volatile StHEADER* ptr = &D_800A326C[D_800A188C];
    if (ptr->id == 1) {
        D_800A188C = 0;
        if (D_800A302C != 0) {
            ptr->id = 0;
        }
        ptr = &D_800A326C[D_800A188C];
    }
    if (ptr->id == 2) {
        ptr->id = 4;
        *addr = &D_800A326C[D_800A3340] + (D_800A188C * 0x3F);
        *header = ptr;
        return 0;
    } else {
        return 1;
    }
}
