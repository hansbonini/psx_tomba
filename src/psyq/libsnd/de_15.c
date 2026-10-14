#include "common.h"
#include "libsnd_i.h"

short SsUtSetReverbType(short);

void _SsSetNrpnVabAttr15(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbType(data);
}
