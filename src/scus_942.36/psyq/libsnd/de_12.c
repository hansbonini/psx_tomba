#include "common.h"
#include "libsnd_i.h"

void _SsSetNrpnVabAttr12(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    if (data != 0 && data < 0x40) {
        adsr.unk10 = 0;
    } else if (data >= 0x40 && data < 0x80) {
        adsr.unk10 = 1;
    }
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
