#include "common.h"
#include "libspu_internal.h"

u32 D_80097CA4_d[1] asm("D_80097CA4") = {
    0x00000000,
};
u32 _spu_AllocLastNum_d[1] asm("_spu_AllocLastNum") = {
    0x00000000,
};
u32 _spu_memList_d[1] asm("_spu_memList") = {
    0x00000000,
};

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_m_init", SpuInitMalloc);

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
