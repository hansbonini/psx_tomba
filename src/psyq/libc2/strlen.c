#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/strlen", strlen);
/**
 * @brief Get the length of a string
 * 
 * Counts the characters before the terminating NUL.
 * 
 * @param pString String to measure
 * @return Length of the string (0 for a NULL pointer)
 */
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
