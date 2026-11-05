#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strncat", strncat);
/**
 * @brief Append at most count characters of one string to another
 * 
 * Copies up to count characters of src to the end of dest and terminates
 * the result.
 * 
 * @param dest Destination string
 * @param src String to append
 * @param count Maximum number of characters to append
 * @return The destination string (NULL if either pointer is NULL)
 */
u_char* strncat(u_char* dest, u_char* src, int count) {
    u_char* temp;
    
    if (dest == NULL) {
        return NULL;
    }
    temp = dest;
    if (src == NULL) return NULL;
    while (*dest++) {
    }
    dest--;
    while ((*dest++ = *src++) != 0) {
        if (--count < 0) {
            dest[-1] = '\x00';
            break;
        }   
    }
    return temp;
}
