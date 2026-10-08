#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/vs_srv", SsSetReservedVoice);

char SsSetReservedVoice(char voices) {
    if ((voices >= 0x19) || (voices == 0)) {
        return -1;
    }
    spuVmMaxVoice = voices;
    return spuVmMaxVoice;
}
