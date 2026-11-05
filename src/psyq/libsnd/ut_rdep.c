#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rdep", SsUtSetReverbDepth);

/**
 * @brief Set the reverb depth
 * 
 * Converts the 0-127 values to the SPU range and sets the left and right
 * reverb depth.
 * 
 * @param ldepth Left depth (0-127)
 * @param rdepth Right depth (0-127)
 */
void SsUtSetReverbDepth(short ldepth, short rdepth) {
    _svm_rattr.mask = 6;
    _svm_rattr.depth.left = (ldepth * 0x7FFF) / 127;
    _svm_rattr.depth.right = (rdepth * 0x7FFF) / 127;
    SpuSetReverbModeParam(&_svm_rattr);
}
