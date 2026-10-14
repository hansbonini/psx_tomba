#include "common.h"
#include "libsnd_i.h"

void _SsSetNrpnVabAttr3(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.max = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
