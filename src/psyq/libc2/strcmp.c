#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strcmp", strcmp);
/**
 * @brief Compare two strings
 * 
 * Compares the strings character by character. NULL pointers are accepted:
 * two NULLs compare equal and a NULL sorts before any string.
 * 
 * @param a First string
 * @param b Second string
 * @return Zero if equal, a negative value if a sorts before b, a positive value otherwise
 */
int strcmp(const char *a, const char *b)
{
    if ((a == NULL) || (b == NULL)) {
        if (a == b) {
            return 0;
        }
        return (a == NULL) ? -1 : 1;
    }
    while (*a == *b++) {
        if (*a++ == '\0') {
            return 0;
        }
    }
    b--;
    return *a - *b;
}
