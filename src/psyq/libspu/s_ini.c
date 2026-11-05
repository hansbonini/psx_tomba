#include "common.h"
#include "libspu_internal.h"

/** @brief Event descriptor signalled when an SPU DMA transfer completes */
s32 _spu_EVdma = 0;
/** @brief Bit mask of the voices currently keyed on */
s32 _spu_keystat = 0;
s32 _spu_trans_mode = 0;
s32 _spu_rev_flag = 0;
s32 _spu_rev_reserve_wa = 0;
s32 _spu_rev_offsetaddr = 0;
struct SpuRevAttr _spu_rev_attr = {0};
s32 _spu_RQvoice = 0;
s32 _spu_RQmask = 0;
/** @brief Center note / fine tune of each voice, used for note-based pitch setting */
u16 _spu_voice_centerNote[24] = {
    0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000,
    0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000,
    0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000, 0xC000,
};
s32 _spu_zerobuf[256] = {0};
s32 _spu_env = 0;
s32 _spu_isCalled = 0;


// INCLUDE_ASM("nonmatchings/psyq/libspu/s_ini", _SpuInit);

/**
 * @brief Internal: initialize the SPU library
 * 
 * Resets the interrupt callbacks and the SPU hardware, restores the
 * default voice center notes on a cold start, starts the DMA event
 * handling and resets the reverb, memory allocation and transfer state.
 * 
 * @param arg0 0 = cold start (full hardware reset), 1 = hot start (keep voice settings)
 */
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

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_ini", SpuStart);

/**
 * @brief Start the SPU DMA transfer handling
 * 
 * On the first call, installs the SPU DMA callback and opens and enables
 * the DMA completion event.
 */
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
