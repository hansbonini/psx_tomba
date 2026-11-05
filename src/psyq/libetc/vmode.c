#include "common.h"

int D_80097504 = 0;


// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", SetVideoMode);

/**
 * @brief Declare the video mode used by the libraries
 * 
 * Sets the video standard that the graphics libraries assume.
 * 
 * @param mode MODE_NTSC (0) or MODE_PAL (1)
 * @return Previous video mode
 */
long SetVideoMode(long mode) {
    long prev = D_80097504;
    D_80097504 = mode;
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/vmode", GetVideoMode);

/**
 * @brief Get the video mode used by the libraries
 * 
 * Returns the value set by SetVideoMode().
 * 
 * @return MODE_NTSC (0) or MODE_PAL (1)
 */
int GetVideoMode(void) { return D_80097504; }
