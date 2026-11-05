#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_dcb", _SpuDataCallback);

/**
 * @brief Internal: set the SPU DMA completion callback
 * 
 * Registers a callback for DMA channel 4 (SPU).
 * 
 * @param arg0 Callback function (NULL to remove it)
 */
void _SpuDataCallback(void (*arg0)()) { DMACallback(4, arg0); }
