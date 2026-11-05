#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 10, set the ADSR release rate (linear)
 * 
 * Sets the release rate and selects linear release.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr10(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    _SsUtResolveADSR(vagAtr.adsr1, vagAtr.adsr2, &adsr);
    adsr.unkE = 0;
    adsr.unk8 = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
