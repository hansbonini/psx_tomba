#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 8, set the ADSR sustain rate (linear)
 * 
 * Sets the sustain rate and selects linear sustain.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr8(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    _SsUtResolveADSR(vagAtr.adsr1, vagAtr.adsr2, &adsr);
    adsr.unkC = 0;
    adsr.unk6 = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
