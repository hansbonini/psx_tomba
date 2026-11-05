#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/memset", memset);
/**
 * @brief Fill a block of memory with a byte value
 * 
 * Writes val into the first len bytes of pMem.
 * 
 * @param pMem Memory block to fill
 * @param val Byte value to store
 * @param len Number of bytes to fill
 * @return The memory block pointer, or NULL if it is NULL or len is not positive
 */
void* memset(unsigned char* pMem, unsigned char val, int len) {
    unsigned char* pRet = 0;
    int remaining = len;
    if(pMem != 0){
        pRet = pMem;
        if (len <= 0){
            pRet = 0;
        }else{
            while(remaining > 0){
                *pMem = val;
                pMem++;
                remaining--;
            }
        }
    }
    return pRet;
}
