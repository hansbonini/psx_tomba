#include "common.h"
#include "libspu_internal.h"

s32 D_80097CA4 = 0;
s32 _spu_AllocLastNum = 0;
SPU_MALLOC* _spu_memList = 0;

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_m_init", SpuInitMalloc);

/**
 * @brief Initialize SPU RAM memory management
 * 
 * Sets up the allocation table in the user-supplied buffer with a single
 * free block covering the usable SPU RAM.
 * 
 * @param num Maximum number of blocks that can be allocated
 * @param top Buffer for the allocation table (SPU_MALLOC_RECSIZ * (num + 1) bytes)
 * @return num on success, 0 if num is not positive
 */
s32 SpuInitMalloc(s32 num, s8* top) {
    if (num > 0) {
        _spu_memList = top;
        _spu_memList[0].addr = 1073745936;
        _spu_memList[0].size = (0x10000 << _spu_mem_mode_plus) - 0x1010;
        _spu_AllocLastNum = 0;
        D_80097CA4 = num;
        return num;
    }
    return 0;
}
