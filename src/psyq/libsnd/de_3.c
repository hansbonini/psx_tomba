#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 3, set the highest note of the key range
 * 
 * Sets the maximum note played by the tone.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr3(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.max = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
