#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_q", SpuQuit);

/**
 * @brief Shut down the SPU library
 * 
 * Removes the transfer and IRQ callbacks, the DMA callback and closes the
 * DMA completion event.
 */
void SpuQuit(void) {
    if (_spu_isCalled == 1) {
        _spu_isCalled = 0;
        EnterCriticalSection();
        _spu_transferCallback = NULL;
        _spu_IRQCallback = NULL;
        _SpuDataCallback(0);
        CloseEvent(_spu_EVdma);
        DisableEvent(_spu_EVdma);
        ExitCriticalSection();
    }
}
