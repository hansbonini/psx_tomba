#include "common.h"
#include "libspu_internal.h"

// INCLUDE_ASM("nonmatchings/psyq/libspu/s_srv", SpuSetReverbVoice);

/**
 * @brief Select the voices sent to the reverb unit
 * 
 * Sets or clears voices in the reverb enable register.
 * 
 * @param on_off SPU_ON (1) = enable reverb, SPU_OFF (0) = disable
 * @param voice_bit Bit mask of the voices
 * @return Resulting bit mask of reverb-enabled voices
 */
u_long SpuSetReverbVoice(long on_off, u_long voice_bit) {
    return _SpuSetAnyVoice(on_off, voice_bit, 0xCC, 0xCD);
}
