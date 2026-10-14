#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strcpy", strcpy);
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
