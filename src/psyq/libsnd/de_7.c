#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 7, set the ADSR sustain level
 * 
 * Sets the sustain level of the envelope.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr7(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    _SsUtResolveADSR(vagAtr.adsr1, vagAtr.adsr2, &adsr);
    adsr.unk4 = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
