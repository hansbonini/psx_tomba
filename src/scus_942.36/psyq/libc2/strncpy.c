#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/strncpy", strncpy);
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
