#include "common.h"
#include "libsnd_i.h"

extern u16* _svm_sreg;
extern s16 _svm_sreg_buf[24 * 8];
extern char _svm_sreg_dirty[24];
extern struct SpuVoice _svm_voice[24];
extern unsigned short _svm_orev1;
extern unsigned short _svm_orev2;
extern char _svm_auto_kof_mode;
extern char D_8009B588[];

long SpuInitMalloc(long num, char* top);
void _SsVmKeyOffNow(int mode);
void _SsVmFlush(void);

// INCLUDE_ASM("nonmatchings/psyq/libsnd/vm_init", _SsVmInit);
void _SsVmInit(u8 numVoices) {
    u16 i;
    u16 reg;
    u32 n;

    _spu_setInTransfer(0);
    _svm_damper = 0;
    SpuInitMalloc(32, D_8009B588);
    for (i = 0; i < 24 * 8; i++) {
        _svm_sreg_buf[i] = 0;
    }
    for (i = 0; i < 24; i++) {
        _svm_sreg_dirty[i] = 0;
    }
    _svm_vab_count = 0;
    for (i = 0; i < 16; i++) {
        _svm_vab_used[i] = 0;
    }

    n = numVoices;
    if (n >= 24) {
        spuVmMaxVoice = 24;
    } else {
        spuVmMaxVoice = n;
    }

    for (i = 0; i < spuVmMaxVoice; i++) {
        reg = i * 8;
        _svm_voice[i].unk2 = 0x18;
        _svm_voice[i].unke = -1;
        _svm_voice[i].unk0 = 0xFF;
        _svm_voice[i].unk1b = 0;
        _svm_voice[i].unk04 = 0;
        _svm_voice[i].unk6 = 0;
        _svm_voice[i].unk10 = 0;
        _svm_voice[i].prog = 0;
        _svm_voice[i].tone = 0xFF;
        _svm_voice[i].unk8 = 0;
        _svm_voice[i].unka = 0x40;
        _svm_voice[i].auto_vol = 0;
        _svm_voice[i].unk1e = 0;
        _svm_voice[i].unk20 = 0;
        _svm_voice[i].unk22 = 0;
        _svm_voice[i].auto_pan = 0;
        _svm_voice[i].unk2a = 0;
        _svm_voice[i].unk2c = 0;
        _svm_voice[i].unk2e = 0;
        _svm_voice[i].start_pan = 0;
        _svm_voice[i].start_vol = 0;
        _svm_sreg[reg + 3] = 0x200;
        _svm_sreg[reg + 2] = 0x1000;
        _svm_sreg[reg + 4] = 0x80FF;
        _svm_sreg[reg + 0] = 0;
        _svm_sreg[reg + 1] = 0;
        _svm_sreg[reg + 5] = 0x4000;
        _svm_cur.field_0x1a = i;
        _SsVmKeyOffNow(1);
    }
    _svm_rattr.depth.left = 0x3FFF;
    _svm_rattr.depth.right = 0x3FFF;
    _svm_okon1 = 0;
    _svm_okon2 = 0;
    _svm_okof1 = 0;
    _svm_orev1 = 0;
    _svm_orev2 = 0;
    _svm_rattr.mask = 0;
    _svm_rattr.mode = 0;
    _svm_auto_kof_mode = 0;
    _svm_stereo_mono = 0;
    kMaxPrograms = 128;
    _SsVmFlush();
}
