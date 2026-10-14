#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_dcb", _SpuDataCallback);

void _SpuDataCallback(void (*arg0)()) { DMACallback(4, arg0); }
