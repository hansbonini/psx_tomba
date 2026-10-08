#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_m_init", SpuInitMalloc);

s32 SpuInitMalloc(s32 num, s8* top) {
    if (num > 0) {
        _spu_memList = top;
        _spu_memList[0].addr = 0x40001010;
        _spu_memList[0].size = (0x10000 << _spu_mem_mode_plus) - 0x1010;
        _spu_AllocLastNum = 0;
        D_80097CA4 = num;
        return num;
    }
    return 0;
}
