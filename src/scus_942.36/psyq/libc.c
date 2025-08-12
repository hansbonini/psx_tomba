#include "common.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", _memcpy);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", _memset);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", rand);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc", srand);

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
