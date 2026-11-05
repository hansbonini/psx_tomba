#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/memchr", memchr);
/**
 * @brief Search a memory block for a byte value
 * 
 * Scans the first len bytes of pMem for the value ch.
 * 
 * @param pMem Memory block to search
 * @param ch Byte value to find
 * @param len Number of bytes to scan
 * @return Pointer to the first matching byte, or NULL if not found
 */
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
