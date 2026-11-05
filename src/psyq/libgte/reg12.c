#include "common.h"
#include "psyq/libgte.h"
#include "gte_local.h"

/**
 * @brief Set the GTE screen offset
 * 
 * Sets the offset added to the projected screen coordinates (normally the
 * screen center).
 * 
 * @param ofx X offset
 * @param ofy Y offset
 */
void SetGeomOffset(long ofx, long ofy) {
    ofx <<= 16;
    ofy <<= 16;
    gte_ldofxy(ofx, ofy);
}

__asm__("nop");
__asm__("nop");
