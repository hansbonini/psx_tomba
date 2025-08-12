#include "common.h"

extern u32 D_8009B138;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", _memcpy);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", _memset);

int rand(void) {
    u_long nNext;

    nNext = (D_8009B138 * 0x41C64E6D) + 0x3039;
    D_8009B138 = nNext;
    return (nNext >> 0x10) & 0x7FFF;
}

void srand(u_long seed) {
    D_8009B138 = seed;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strcat);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strcmp);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strcpy);

int strlen(char* pString) {
    int nLen;
    char chCur;

    nLen = 0;
    if (pString == NULL)
        return 0;

    while (chCur = *pString, pString++, chCur != NULL)
        nLen++;
    return nLen;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strncat);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strncpy);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", strstr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", printf);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", prnt);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", toupper);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", tolower);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", _memchr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", putchar);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", sprintf);

void* _memmove(u_char* pDst, u_char* pSrc, int size) {
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
