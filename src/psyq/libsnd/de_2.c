#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 2, set the lowest note of the key range
 * 
 * Sets the minimum note played by the tone.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr2(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.min = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
