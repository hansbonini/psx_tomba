#include "common.h"
#include "libsnd_i.h"

void SsUtReverbOn(void);
void SsUtReverbOff(void);

void _SsSetNrpnVabAttr1(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.mode = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
    if (data == 0) {
        SsUtReverbOff();
    } else if (data == 4) {
        SsUtReverbOn();
    }
}
