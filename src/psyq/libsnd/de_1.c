#include "common.h"
#include "libsnd_i.h"

void SsUtReverbOn(void);
void SsUtReverbOff(void);

/**
 * @brief Internal: NRPN data entry 1, set the tone mode
 * 
 * Sets the mode of the tone; mode 0 also turns reverb off and mode 4 turns
 * it on.
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr1(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtGetVagAtr(vabId, prog, tone, &vagAtr);
    vagAtr.mode = data;
    SsUtSetVagAtr(vabId, prog, tone, &vagAtr);
    if (data == 0) {
        SsUtReverbOff();
    } else if (data == 4) {
        SsUtReverbOn();
    }
}
