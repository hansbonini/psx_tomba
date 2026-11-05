#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 0, set the tone priority
 * 
 * Sets the priority of the tone.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr0(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.prior = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
