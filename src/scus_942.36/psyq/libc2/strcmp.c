#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/strcmp", strcmp);
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
