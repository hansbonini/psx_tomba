#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/memchr", memchr);
void* memchr(unsigned char* pMem, unsigned char ch, int len) {
    if (pMem == NULL || len <= 0) {
        return NULL;
    }
    len--;
    while (len >= 0) {
        if (*pMem++ == ch) {
            return pMem - 1;
        }
        len--;
    }   
    return NULL;
}
