#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/sssmv", SsSetMVol);

/**
 * @brief Set the master volume
 * 
 * Converts the 0-127 values to the SPU range and sets the left and right
 * master volume.
 * 
 * @param voll Left volume (0-127)
 * @param volr Right volume (0-127)
 */
void SsSetMVol(short voll, short volr) {
    SpuCommonAttr attr;
    attr.mask = SPU_COMMON_MVOLL | SPU_COMMON_MVOLR;
    attr.mvol.left = 0x81 * voll;
    attr.mvol.right = 0x81 * volr;
    SpuSetCommonAttr(&attr);
}
