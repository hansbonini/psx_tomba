#include "common.h"
#include "libsnd_i.h"

void _SsSetNrpnVabAttr10(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    _SsUtResolveADSR(vagAtr.adsr1, vagAtr.adsr2, &adsr);
    adsr.unkE = 0;
    adsr.unk8 = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
