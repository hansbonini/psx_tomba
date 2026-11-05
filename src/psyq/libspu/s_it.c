#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_it", _spu_setInTransfer);

/**
 * @brief Internal: set the transfer-in-progress flag
 * 
 * Updates the internal flag tested by SpuIsTransferCompleted().
 * 
 * @param arg0 1 = no transfer pending, any other value = transfer in progress
 */
void _spu_setInTransfer(s32 arg0) {
    if (arg0 == 1) {
        _spu_inTransfer = 0;
    } else {
        _spu_inTransfer = 1;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_it", _spu_getInTransfer);

/**
 * @brief Internal: get the transfer-in-progress flag
 * 
 * Reports whether a transfer is currently marked as in progress.
 * 
 * @return 1 if a transfer is in progress, 0 otherwise
 */
int _spu_getInTransfer(void) { return _spu_inTransfer != 1; }
