#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libspu/s_srv", SpuSetReverbVoice);

u_long SpuSetReverbVoice(long on_off, u_long voice_bit) {
    return _SpuSetAnyVoice(on_off, voice_bit, 0xCC, 0xCD);
}
