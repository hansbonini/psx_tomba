#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rev", SsUtSetReverbType);

/**
 * @brief Set the reverb type
 * 
 * Selects one of the reverb presets. A negative value selects the type
 * without clearing the work area. Type 0 also turns reverb off.
 * 
 * @param arg0 Reverb type (SS_REV_TYPE_OFF ... SS_REV_TYPE_PIPE, optionally negated)
 * @return Reverb type set, or -1 if invalid
 */
s16 SsUtSetReverbType(s16 arg0) {
    s16 var_v1;
    s32 var_a1;

    var_a1 = 0;
    var_v1 = arg0;
    if (arg0 < 0) {
        var_a1 = 1;
        var_v1 = -arg0;
    }

    if ((u16)var_v1 < 10) {
        _svm_rattr.mask = 1;
        if (var_a1 != 0) {
            _svm_rattr.mode = var_v1 | 0x100;
        } else {
            _svm_rattr.mode = var_v1;
        }
        if (var_v1 == 0) {
            SpuSetReverb(0);
        }
        SpuSetReverbModeParam(&_svm_rattr);
        return var_v1;
    }
    return -1;
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_rev", SsUtGetReverbType);

/**
 * @brief Get the reverb type
 * 
 * Returns the type last set with SsUtSetReverbType().
 * 
 * @return Reverb type
 */
s16 SsUtGetReverbType(void) { return _svm_rattr.mode; }
