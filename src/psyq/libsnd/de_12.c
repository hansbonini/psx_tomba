#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: NRPN data entry 12, set the ADSR sustain direction
 * 
 * Values 1-63 select a decreasing sustain and 64-127 an increasing one.
 * The ADSR fields are not decoded first, so the other envelope fields come
 * from uninitialized stack data.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr12(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    struct Unk adsr;

    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    if (data != 0 && data < 0x40) {
        adsr.unk10 = 0;
    } else if (data >= 0x40 && data < 0x80) {
        adsr.unk10 = 1;
    }
    _SsUtBuildADSR(&adsr, &vagAtr.adsr1, &vagAtr.adsr2);
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
}
