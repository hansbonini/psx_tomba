#include "common.h"
#include "libspu_internal.h"

extern int _spu_AllocLastNum;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_m_m", SpuMalloc);
long SpuMalloc(long size) {
    s32 var_s2;
    s32 var_s3;
    s32 i;

    i = 0; // why tho?
    var_s2 = -1;

    if (_spu_rev_reserve_wa == 0) {
        var_s3 = 0;
    } else {
        var_s3 = (0x10000 - _spu_rev_offsetaddr) << _spu_mem_mode_plus;
    }

    size += (size & ~_spu_mem_mode_unitM) ? _spu_mem_mode_unitM : 0;
    size >>= _spu_mem_mode_plus;
    size <<= _spu_mem_mode_plus;

    if (_spu_memList[0].addr & 0x40000000) {
        var_s2 = 0;
    } else {
        _spu_gcSPU();

        for (; i < D_80097CA4; i++) {
            if (_spu_memList[i].addr & 0x40000000 ||
                (_spu_memList[i].addr & 0x80000000 &&
                 _spu_memList[i].size >= size)) {
                var_s2 = i;
                break;
            }
        }
    }

    if (var_s2 == -1)
        return -1;

    if (_spu_memList[var_s2].addr & 0x40000000) {
        if (var_s2 < D_80097CA4 && _spu_memList[var_s2].size - var_s3 >= size) {
            s32 next = var_s2 + 1;

            // Why the volatile?
            _spu_memList[next].addr =
                (*(volatile int*)&_spu_memList[var_s2].addr & 0x0FFFFFFF) +
                    size |
                0x40000000;
            _spu_memList[next].size = _spu_memList[var_s2].size - size;

            _spu_memList[var_s2].addr &= 0x0FFFFFFF;
            _spu_memList[var_s2].size = size;

            _spu_AllocLastNum = next;
            _spu_gcSPU();

            return _spu_memList[var_s2].addr;
        }
    } else {
        if (size < _spu_memList[var_s2].size && _spu_AllocLastNum < D_80097CA4) {
            u32 _addr = _spu_memList[var_s2].addr + size;
            u32 _size = _spu_memList[var_s2].size - size;

            u32 swapAddr = _spu_memList[_spu_AllocLastNum].addr;
            u32 swapSize = _spu_memList[_spu_AllocLastNum].size;

            _spu_memList[_spu_AllocLastNum].addr = _addr | 0x80000000;
            _spu_memList[_spu_AllocLastNum].size = _size;

            _spu_memList[_spu_AllocLastNum + 1].addr = swapAddr;
            _spu_memList[_spu_AllocLastNum + 1].size = swapSize;

            _spu_AllocLastNum++;
        }

        _spu_memList[var_s2].size = size;
        _spu_memList[var_s2].addr &= 0x0FFFFFFF;
        _spu_gcSPU();

        return _spu_memList[var_s2].addr;
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_m_m", _spu_gcSPU);

void _spu_gcSPU(void) {
    int i, j;

    for (i = 0; i <= _spu_AllocLastNum;) {
        if (_spu_memList[i].addr & 0x80000000) {
            for (j = i + 1;; j++) {
                if (i) {
                }
                if (_spu_memList[j].addr != 0x2FFFFFFF) {
                    break;
                }
            }
            if ((_spu_memList[j].addr & 0x80000000) &&
                ((_spu_memList[j].addr & 0x0FFFFFFF) ==
                 (_spu_memList[i].addr & 0x0FFFFFFF) + _spu_memList[i].size)) {
                _spu_memList[j].addr = 0x2FFFFFFF;
                _spu_memList[i].size += _spu_memList[j].size;
                continue;
            }
        }
        i++;
    }
    for (i = 0; i <= _spu_AllocLastNum; i++) {
        if (_spu_memList[i].size == 0) {
            _spu_memList[i].addr = 0x2FFFFFFF;
        }
    }
    for (i = 0; i <= _spu_AllocLastNum; i++) {
        if (_spu_memList[i].addr & 0x40000000) {
            break;
        }
        for (j = i + 1; j <= _spu_AllocLastNum; j++) {
            if (_spu_memList[j].addr & 0x40000000) {
                break;
            }
            if ((_spu_memList[j].addr & 0x0FFFFFFF) <
                (_spu_memList[i].addr & 0x0FFFFFFF)) {
                u32 swapAddr = _spu_memList[i].addr;
                u32 swapSize = _spu_memList[i].size;
                _spu_memList[i].addr = _spu_memList[j].addr;
                _spu_memList[i].size = _spu_memList[j].size;
                _spu_memList[j].addr = swapAddr;
                _spu_memList[j].size = swapSize;
            }
        }
    }
    for (i = 0; i <= _spu_AllocLastNum; i++) {
        if (_spu_memList[i].addr & 0x40000000) {
            break;
        }
        if (_spu_memList[i].addr == 0x2FFFFFFF) {
            _spu_memList[i].addr = _spu_memList[_spu_AllocLastNum].addr;
            _spu_memList[i].size = _spu_memList[_spu_AllocLastNum].size;
            _spu_AllocLastNum = i;
            break;
        }
    }
    for (i = _spu_AllocLastNum - 1; i >= 0; i--) {
        if (!(_spu_memList[i].addr & 0x80000000)) {
            break;
        }
        _spu_memList[i].addr &= 0x0FFFFFFF;
        _spu_memList[i].addr |= 0x40000000;
        _spu_memList[i].size += _spu_memList[_spu_AllocLastNum].size;
        _spu_AllocLastNum = i;
    }
}
