#include "common.h"
#include "libspu_internal.h"

extern s32 _spu_trans_mode, _spu_transMode, _spu_keystat, _spu_RQmask, _spu_RQvoice, _spu_env;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_ini", _SpuInit);

void _SpuInit(s32 arg0) {
    s32 i;
    ResetCallback();
    _spu_init(arg0);
    if (arg0 == 0) {
        for (i = 0; i < NUM_SPU_CHANNELS; i++) {
            _spu_voice_centerNote[i] = 0xC000;
        }
    }
    SpuStart();
    _spu_rev_flag = 0;
    _spu_rev_reserve_wa = 0;
    _spu_rev_attr.unk18 = 0;
    _spu_rev_attr.unk1c = 0;
    _spu_rev_attr.unk1e = 0;
    _spu_rev_attr.unk20 = 0;
    _spu_rev_attr.unk24 = 0;
    _spu_rev_offsetaddr = _spu_rev_startaddr[0];
    _spu_FsetRXX(0xD1, _spu_rev_startaddr[0], 0);
    D_80097CA4 = 0;
    _spu_AllocLastNum = 0;
    _spu_memList = 0;
    _spu_trans_mode = 0;
    _spu_transMode = 0;
    _spu_keystat = 0;
    _spu_RQmask = 0;
    _spu_RQvoice = 0;
    _spu_env = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_ini", SpuStart);

void SpuStart(void) {
    if (_spu_isCalled == 0) {
        _spu_isCalled = 1;
        EnterCriticalSection();
        _SpuDataCallback(_spu_FiDMA);
        _spu_EVdma = OpenEvent(HwSPU, EvSpCOMP, EvMdNOINTR, NULL);
        EnableEvent(_spu_EVdma);
        ExitCriticalSection();
    }
}
