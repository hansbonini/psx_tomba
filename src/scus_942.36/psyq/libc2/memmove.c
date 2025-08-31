#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/memmove", memmove);
void* memmove(u_char* pDst, u_char* pSrc, int size) {
    if (pDst >= pSrc) {
        while (size-- > 0) {
            pDst[size] = pSrc[size];
        }
    } else {
        while (size-- > 0) {
            *pDst++ = *pSrc++;
        }
    }

    return pDst;
}
