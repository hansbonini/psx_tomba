#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_sr", SpuSetReverb);

s32 SpuSetReverb(s32 on_off) {
    u16 cnt;
    switch (on_off) {
    case 0:
        _spu_rev_flag = 0;
#ifdef VERSION_PC
        cnt = read_16(0x1F801DAA, __FILE__, __LINE__); // spucnt
        cnt &= ~0x80;
        write_16(0x1F801DAA, cnt, __FILE__, __LINE__); // spucnt
#else
        cnt = _spu_RXX->rxx.spucnt;
        cnt &= ~0x80;
        _spu_RXX->rxx.spucnt = cnt;
#endif
        break;

    case 1:
        if ((_spu_rev_reserve_wa != on_off) &&
            _SpuIsInAllocateArea_(_spu_rev_offsetaddr)) {
            _spu_rev_flag = 0;
#ifdef VERSION_PC
            cnt = read_16(0x1F801DAA, __FILE__, __LINE__);
            cnt &= ~0x80;
            write_16(0x1F801DAA, cnt, __FILE__, __LINE__);
#else
            cnt = _spu_RXX->rxx.spucnt;
            cnt &= ~0x80;
            _spu_RXX->rxx.spucnt = cnt;
#endif
        } else {
            _spu_rev_flag = on_off;
#ifdef VERSION_PC
            cnt = read_16(0x1F801DAA, __FILE__, __LINE__);
            cnt |= 0x80;
            write_16(0x1F801DAA, cnt, __FILE__, __LINE__);
#else
            cnt = _spu_RXX->rxx.spucnt;
            cnt |= 0x80;
            _spu_RXX->rxx.spucnt = cnt;
#endif
        }
        break;
    }

    return _spu_rev_flag;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_sr", _SpuIsInAllocateArea);

int _SpuIsInAllocateArea(unsigned arg0) {
    int i;

    if (_spu_memList == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (_spu_memList[i].addr & 0x80000000) {
            continue;
        }
        if (_spu_memList[i].addr & 0x40000000) {
            break;
        }
        if (arg0 <= (_spu_memList[i].addr & 0x0FFFFFFF)) {
            return 1;
        }
        if (arg0 < (_spu_memList[i].addr & 0x0FFFFFFF) + _spu_memList[i].size) {
            return 1;
        }
    }
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_sr", _SpuIsInAllocateArea_);

int _SpuIsInAllocateArea_(unsigned arg0) {
    int i;

    arg0 <<= _spu_mem_mode_plus;
    if (_spu_memList == NULL) {
        return 0;
    }
    for (i = 0;; i++) {
        if (_spu_memList[i].addr & 0x80000000) {
            continue;
        }
        if (_spu_memList[i].addr & 0x40000000) {
            break;
        }
        if (arg0 <= (_spu_memList[i].addr & 0x0FFFFFFF)) {
            return 1;
        }
        if (arg0 < (_spu_memList[i].addr & 0x0FFFFFFF) + _spu_memList[i].size) {
            return 1;
        }
    }
    return 0;
}
