#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libgte/fog_01", SetFogNear);
/**
 * @brief Set the depth cueing start distance
 * 
 * Programs the GTE depth cue coefficients (DQA/DQB) so that fog starts at
 * distance a for a projection plane distance h.
 * 
 * @param a Distance at which fog begins
 * @param h Distance between the viewpoint and the screen (as given to SetGeomScreen)
 */
void SetFogNear(long a, long h) {
    SetDQA(-(a * 0x140) / h);
    SetDQB(0x01400000);
}