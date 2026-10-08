#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_it", _spu_setInTransfer);

void _spu_setInTransfer(s32 arg0) {
    if (arg0 == 1) {
        _spu_inTransfer = 0;
    } else {
        _spu_inTransfer = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_it", _spu_getInTransfer);

int _spu_getInTransfer(void) { return _spu_inTransfer != 1; }
