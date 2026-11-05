#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 11, set the ADSR release rate (exponential)
 * 
 * Sets the release rate and selects exponential release. The ADSR fields
 * are not decoded first, so the other envelope fields come from
 * uninitialized stack data.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr11(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    adsr.unkE = 1;
    adsr.unk8 = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
