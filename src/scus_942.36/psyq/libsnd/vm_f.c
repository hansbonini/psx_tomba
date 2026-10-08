#include "common.h"
#include "libsnd_i.h"

extern u16* _svm_sreg;
extern s16 _svm_sreg_buf[NUM_SPU_CHANNELS * 8];
extern char _svm_sreg_dirty[NUM_SPU_CHANNELS];
extern struct SpuVoice _svm_voice[NUM_SPU_CHANNELS];
extern s32 _svm_envx_hist[16];
extern u32 _svm_envx_ptr;
extern u8 _svm_auto_kof_mode;
extern void (*_autovol)();
extern void (*_autopan)();
extern u16 _svm_orev1;
extern u16 _svm_orev2;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vm_f", _SsVmFlush);

void _SsVmFlush(void) {
    s32 i;
    u32 env_mask;
    u16 okof1;
    u16 okof2;
    u16 okon1;
    u16 okon2;
    u16 rev1;
    u16 rev2;
    u16* sreg;

    _svm_envx_ptr = (_svm_envx_ptr + 1) & 0xF;
    _svm_envx_hist[_svm_envx_ptr] = 0;
    for (i = 0; i < spuVmMaxVoice; i++) {
        _svm_voice[i].unk6 = _svm_sreg[i * 8 + 6];
        if (!_svm_voice[i].unk6) {
            _svm_envx_hist[_svm_envx_ptr] |= 1 << i;
        }
    }
    if (_svm_auto_kof_mode == 0) {
        env_mask = -1;
        for (i = 0; i < 15; i++) {
            env_mask &= _svm_envx_hist[i];
        }
        for (i = 0; i < spuVmMaxVoice; i++) {
            if (env_mask & (1 << i)) {
                if (_svm_voice[i].unk1b == 2) {
                    SpuSetNoiseVoice(0, 0xFFFFFF);
                }
                _svm_voice[i].unk1b = 0;
            }
        }
    }
    _svm_okon1 &= ~_svm_okof1;
    _svm_okon2 &= ~_svm_okof2;
    for (i = 0; i < NUM_SPU_CHANNELS; i++) {
        if (_svm_voice[i].auto_vol) {
            _autovol(i);
        }
        if (_svm_voice[i].auto_pan) {
            _autopan(i);
        }
    }
    {
        char* dirty = _svm_sreg_dirty;
        u16* base = (u16*)_svm_sreg_buf;
        u16* adsr2 = base + 5;
        u16* adsr1 = base + 4;
        int offset = 0;
        u16* right = base + 1;
        u16* left = base;
        char* dirtyEnd = _svm_sreg_dirty + NUM_SPU_CHANNELS;

        do {
            if (*dirty & 1) {
                u16* spuVoice = (u16*)(offset + (u32)_svm_sreg);
                spuVoice[0] = *left;
                spuVoice[1] = *right;
            }
            if (*dirty & 4) {
                u16* spuVoice = (u16*)(offset + (u32)_svm_sreg);
                spuVoice[2] = *(u16*)((u8*)_svm_sreg_buf + offset + 4);
            }
            if (*dirty & 8) {
                u16* spuVoice = (u16*)(offset + (u32)_svm_sreg);
                spuVoice[3] = *(u16*)((u8*)_svm_sreg_buf + offset + 6);
            }
            if (*dirty & 0x10) {
                u16* spuVoice = (u16*)(offset + (u32)_svm_sreg);
                spuVoice[4] = *adsr1;
                spuVoice[5] = *adsr2;
            }
            *dirty++ = 0;
            adsr2 += 8;
            adsr1 += 8;
            offset += 16;
            right += 8;
            left += 8;
        } while ((s32)dirty < (s32)dirtyEnd);
    }
    sreg = _svm_sreg;
    okof1 = _svm_okof1;
    okof2 = _svm_okof2;
    okon1 = _svm_okon1;
    okon2 = _svm_okon2;
    rev1 = _svm_orev1;
    rev2 = _svm_orev2;
    _svm_okof1 = 0;
    _svm_okof2 = 0;
    _svm_okon1 = 0;
    _svm_okon2 = 0;
    sreg[0x18C / 2] = okof1;
    sreg[0x18E / 2] = okof2;
    sreg[0x188 / 2] = okon1;
    sreg[0x18A / 2] = okon2;
    sreg[0x198 / 2] = rev1;
    sreg[0x19A / 2] = rev2;
}
