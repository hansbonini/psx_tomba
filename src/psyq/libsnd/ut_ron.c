#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_ron", SsStart);

/**
 * @brief Start the sound system
 * 
 * Starts the sequencer tick according to the mode set with
 * SsSetTickMode().
 */
void SsStart(void) { _SsStart(1); }
