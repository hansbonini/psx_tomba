#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/strncat", strncat);
u_char* strncat(u_char* dest, u_char* src, int count) {
    u_char* temp;
    
    if (dest == NULL) {
        return NULL;
    } else {
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
    }
    return temp;
}
