#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"

/**
 * @brief Set the GTE ambient (back) color
 * 
 * Loads the background color used by the lighting calculations.
 * 
 * @param rbk Red component (0-255)
 * @param gbk Green component (0-255)
 * @param bbk Blue component (0-255)
 */
void SetBackColor(long rbk, long gbk, long bbk) {
    rbk <<= 4;
    gbk <<= 4;
    bbk <<= 4;
    gte_ldbkdir(rbk, gbk, bbk);
}
