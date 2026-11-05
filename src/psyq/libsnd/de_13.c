#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 13, set the vibrato time
 * 
 * Sets the vibrato time of the tone (the ADSR is rebuilt from an
 * uninitialized structure).
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr13(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.vibT = data;
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
