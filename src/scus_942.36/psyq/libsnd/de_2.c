#include "common.h"
#include "libsnd_i.h"

void _SsSetNrpnVabAttr2(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.min = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
