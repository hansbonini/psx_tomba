#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vs_vfb", SsVabFakeBody);

/**
 * @brief Mark a VAB body as loaded
 * 
 * Used when the waveform data was transferred to SPU RAM by other means:
 * completes the VAB opened with SsVabOpenHeadSticky()/SsVabFakeHead().
 * 
 * @param vabid VAB ID
 * @return VAB ID, or -1 on error
 */
s16 SsVabFakeBody(s16 vabid) {
    if (vabid >= 0 && vabid <= 0x10 && _svm_vab_used[vabid] == 2) {
        _spu_setInTransfer(0);
        _svm_vab_used[vabid] = 1;
        return vabid;
    }
    return -1;
}
