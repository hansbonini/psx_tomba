#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_stsa", SpuSetTransferStartAddr);

/**
 * @brief Set the SPU RAM address for the next transfer
 * 
 * Rounds the address to the SPU memory unit and stores it as the start
 * address of the next transfer.
 * 
 * @param addr Start address in SPU RAM (0x1010 and above)
 * @return Address actually set, or 0 if out of range
 */
unsigned long SpuSetTransferStartAddr(unsigned long addr) {
    unsigned _addr;
    _addr = addr;
    if (_addr - 0x1010 > 0x7EFE8) {
        return 0;
    }
    _addr = _spu_FsetRXXa(-1, _addr);
    _spu_tsa = (u16)_addr;
    return (u16)_addr << _spu_mem_mode_plus;
}
