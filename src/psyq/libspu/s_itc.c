#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_itc", SpuIsTransferCompleted);

/**
 * @brief Check or wait for the end of a data transfer to SPU RAM
 * 
 * In I/O transfer mode transfers are always complete. Otherwise tests (or
 * waits on) the SPU DMA completion event.
 * 
 * @param arg0 SPU_TRANSFER_PEEK (0) = check only, SPU_TRANSFER_WAIT (1) = wait for completion
 * @return 1 if the transfer has completed, 0 if it is still running
 */
s32 SpuIsTransferCompleted(s32 arg0) {
    s32 in_transfer;

    if ((_spu_trans_mode == 1) || (_spu_inTransfer == 1)) {
        return 1;
    }
    in_transfer = TestEvent(_spu_EVdma);
    if (arg0 == 1) {
        if (in_transfer == 0) {
            do {
            } while (TestEvent(_spu_EVdma) == 0);
        }
        in_transfer = 1;
        _spu_inTransfer = in_transfer;
        return in_transfer;
    }
    if (in_transfer == 1) {
        _spu_inTransfer = in_transfer;
    }
    return in_transfer;
}
