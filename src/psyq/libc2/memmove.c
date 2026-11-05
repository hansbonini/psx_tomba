#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/memmove", memmove);
/**
 * @brief Copy a block of memory, allowing overlapping areas
 * 
 * Copies size bytes from pSrc to pDst, choosing the copy direction so that
 * overlapping regions are handled correctly.
 * 
 * @param pDst Destination buffer
 * @param pSrc Source buffer
 * @param size Number of bytes to copy
 * @return pDst; note that after a forward copy it has been advanced past the copied bytes
 */
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
