#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_r", SpuRead);

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
