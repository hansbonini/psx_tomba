#include "common.h"
#include "libsnd_i.h"

short SsUtSetReverbType(short);

/**
 * @brief Internal: NRPN data entry 15, set the reverb type
 * 
 * Sets the reverb type with SsUtSetReverbType().
 * 
 * @param vabId VAB ID
 * @param prog Program number
 * @param tone Tone number
 * @param vagAtr Scratch tone attribute buffer (passed by value)
 * @param fn NRPN function number
 * @param data Data entry value
 */
void _SsSetNrpnVabAttr15(short vabId, short prog, short tone, VagAtr vagAtr, short fn, u8 data) {
    SsUtSetReverbType(data);
}
