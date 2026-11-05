#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_r", SpuRead);

/**
 * @brief Transfer data between main memory and SPU RAM
 * 
 * Clamps the size to the SPU RAM limit and starts the transfer from the
 * current transfer start address. Note: the body calls _spu_write() and
 * therefore behaves like PsyQ SpuWrite() (main memory to SPU RAM), so the
 * symbol name may be wrong.
 * 
 * @param addr Main memory buffer
 * @param size Transfer size in bytes
 * @return Number of bytes transferred
 */
unsigned long SpuRead(unsigned char* addr, unsigned long size) {
    if (size > 0x7EFF0) {
        size = 0x7EFF0;
    }
    _spu_write(addr, size);
    if (_spu_transferCallback == NULL) {
        _spu_inTransfer = 0;
    }
    return size;
}
