#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/memcpy", memcpy);
/**
 * @brief Copy a block of memory
 * 
 * Copies arg2 bytes from arg1 to arg0, one byte at a time. The areas must
 * not overlap.
 * 
 * @param arg0 Destination buffer
 * @param arg1 Source buffer
 * @param arg2 Number of bytes to copy
 * @return The destination pointer, or NULL if the destination is NULL
 */
u8* memcpy(u8* arg0, u8* arg1, s32 arg2)
{
    s32 var_a2;
    u8 temp_v0;
    u8* temp_v1;
    u8* var_a0;
    u8* var_a1;
    u8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        temp_v1 = var_a0;
        if (var_a2 > 0) {
            do {
                temp_v0 = *var_a1;
                var_a1 += 1;
                var_a2 -= 1;
                *var_a0 = temp_v0;
                var_a0 += 1;
            } while (var_a2 > 0);
        }
        var_v0 = temp_v1;
    }
    return var_v0;
}
