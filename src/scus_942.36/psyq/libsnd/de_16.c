#include "common.h"
#include "libsnd_i.h"

void SsUtSetReverbFeedback(short);
void SsUtSetReverbDelay(short);

void _SsSetNrpnVabAttr16(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDepth(data, data);
}

void _SsSetNrpnVabAttr17(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbFeedback(data);
}

void _SsSetNrpnVabAttr18(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDelay(data);
}

void _SsSetNrpnVabAttr19(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDelay(data);
}
