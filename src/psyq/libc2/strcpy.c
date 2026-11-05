#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strcpy", strcpy);
/**
 * @brief Copy a string
 * 
 * Copies src, including its terminating NUL, into dest.
 * 
 * @param dest Destination buffer
 * @param src Source string
 * @return The destination buffer (NULL if either pointer is NULL)
 */
char* strcpy(char* dest, const char* src)
{
    char* dst;

    if (dest == NULL || src == NULL) {
        return NULL;
    }

    dst = dest;
    while ((*dest++ = *src++) != '\0') {}

    return dst;
}
