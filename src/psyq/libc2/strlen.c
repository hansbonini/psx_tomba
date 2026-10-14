#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strlen", strlen);
int strlen(char* pString) {
    int nLen;
    char chCur;

    nLen = 0;
    if (pString == NULL)
        return 0;

    while (chCur = *pString, pString++, chCur != '\0')
        nLen++;
    return nLen;
}
