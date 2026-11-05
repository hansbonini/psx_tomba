#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_m_f", SpuFree);

/**
 * @brief Release an area allocated with SpuMalloc()
 * 
 * Marks the block starting at the given SPU address as free and merges
 * free blocks.
 * 
 * @param arg0 Start address returned by SpuMalloc()
 */
void SpuFree(unsigned long arg0) {
    s32 i;

    for (i = 0; i < D_80097CA4; i++) {
        if (_spu_memList[i].addr & 0x40000000) {
            break;
        }
        if (_spu_memList[i].addr == arg0) {
            _spu_memList[i].addr |= 0x80000000;
            break;
        }
    }
    _spu_gcSPU();
}
