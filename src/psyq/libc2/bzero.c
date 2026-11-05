#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/bzero", bzero);
/**
 * @brief Fill a block of memory with zeros
 * 
 * Clears arg1 bytes starting at arg0.
 * 
 * @param arg0 Buffer to clear
 * @param arg1 Number of bytes to clear
 * @return The buffer pointer, or NULL if the buffer is NULL or the size is not positive
 */
s8* bzero(s8* arg0, s32 arg1)
{
    s32 var_a1;
    s8* var_a0;
    s8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        var_v0 = var_a0;
        if (var_a1 <= 0) {
            return NULL;
        }
        do {
            *var_a0 = 0;
            var_a1 -= 1;
            var_a0 += 1;
        } while (var_a1 > 0);
    }
    return var_v0;
}
