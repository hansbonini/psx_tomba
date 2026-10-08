#include "common.h"
#include "libsnd_i.h"

typedef void (*SndSsMarkCallbackProc)(short seq_no, short sep_no, short data);
extern SndSsMarkCallbackProc _SsMarkCallback[32][16];
extern short D_800975E4[];
extern short D_800975F4[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssinit", _SsInit);

void _SsInit(void) {
    u16* var_a2;
    int i, j;

    var_a2 = (u16*)0x1F801C00;
    for (i = 0; i < 24; i++) {
        for (j = 0; j < 8; j++) {
#ifdef VERSION_PC
            write_16(0x1F801C00 + (i * 8 + j) * 2, D_800975E4[j], __FILE__,
                     __LINE__);
#else
            *var_a2++ = D_800975E4[j];
#endif
        }
    }

    var_a2 = (u16*)0x1F801D80;
    for (i = 0; i < 16; i++) {
#ifdef VERSION_PC
        write_16(0x1F801D80 + i * 2, D_800975F4[i], __FILE__, __LINE__);
#else
        *var_a2++ = D_800975F4[i];
#endif
    }

    _SsVmInit(24);

    for (j = 0; j < 32; j++) {
        for (i = 0; i < 16; i++) {
            _SsMarkCallback[j][i] = 0;
        }
    }

    VBLANK_MINUS = 60;
    _snd_openflag = 0;
    _snd_ev_flag = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssinit", SsInitHot);

void SsInitHot(void) {
    ResetCallback();
    SpuInit();
    _SsInit();
}
