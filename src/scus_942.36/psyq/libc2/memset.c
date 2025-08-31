#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/memset", memset);
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
