#include "common.h"
#include "libsnd_i.h"

void SsUtSetReverbFeedback(short);
void SsUtSetReverbDelay(short);

/**
 * @brief Internal: NRPN data entry 16, set the reverb depth
 * 
 * Sets the left and right reverb depth to the value.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr16(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDepth(data, data);
}

/**
 * @brief Internal: NRPN data entry 17, set the echo feedback
 * 
 * Sets the reverb feedback.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr17(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbFeedback(data);
}

/**
 * @brief Internal: NRPN data entry 18, set the echo delay
 * 
 * Sets the reverb delay time.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr18(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDelay(data);
}

/**
 * @brief Internal: NRPN data entry 19, set the delay time
 * 
 * Sets the reverb delay time.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr19(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbDelay(data);
}
