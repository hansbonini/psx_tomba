#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vs_vab", SsVabClose);

void SsVabClose(s16 vabid) {
    if ((vabid >= 0 && vabid < 0x10) && (_svm_vab_used[vabid] == 1)) {
        SpuFree(_svm_vab_start[vabid]);
        _svm_vab_used[vabid] = 0;
        _svm_vab_count -= 1;
    }
}
