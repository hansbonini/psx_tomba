#include "common.h"
#include "libsnd_i.h"

/**
 * @brief Internal: press the damper pedal
 * 
 * Sets the sustain adjustment applied to new notes.
 */
void _SsVmDamperOn(void) {
    _svm_damper = 2;
}
