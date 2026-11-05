#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vs_vab", SsVabClose);

/**
 * @brief Close a VAB
 * 
 * Frees its SPU memory and releases the VAB ID.
 * 
 * @param vabid VAB ID
 */
void SsVabClose(s16 vabid) {
    if ((vabid >= 0 && vabid < 0x10) && (_svm_vab_used[vabid] == 1)) {
        SpuFree(_svm_vab_start[vabid]);
        _svm_vab_used[vabid] = 0;
        _svm_vab_count -= 1;
    }
}
