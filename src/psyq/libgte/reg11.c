#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"

/**
 * @brief Set the GTE far (fog) color
 * 
 * Loads the color that depth cueing interpolates towards.
 * 
 * @param rfc Red component (0-255)
 * @param gfc Green component (0-255)
 * @param bfc Blue component (0-255)
 */
void SetFarColor(long rfc, long gfc, long bfc) {
    rfc <<= 4;
    gfc <<= 4;
    bfc <<= 4;
    gte_ldfcdir(rfc, gfc, bfc);
}
