#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strncpy", strncpy);
/**
 * @brief Copy at most count characters of a string
 * 
 * Copies up to count characters from src to dest, padding with NUL
 * characters if src is shorter.
 * 
 * @param dest Destination buffer
 * @param src Source string
 * @param count Number of characters to write
 * @return The destination buffer (NULL if either pointer is NULL)
 */
u_char* strncpy(u_char* dest, u_char* src, int count) {
    int i;
    u_char* tmp;

    if ((dest == NULL) || (src == NULL)) {
        return NULL;
    }
    tmp = dest;
    for (i = 0; i < count; i++) {
        if ((*dest++ = *src++) == '\x00') {
            for (i=i+1; i < count; i++) {
                *dest++ = '\x00';
            }
            return tmp;
        }
    }
    return tmp;
}
