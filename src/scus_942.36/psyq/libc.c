#include "common.h"

extern u32 D_8009B138;
extern u32 D_8009B140;
extern u8 D_8007FA71[];

u8* _memcpy(u8* arg0, u8* arg1, s32 arg2)
{
    s32 var_a2;
    u8 temp_v0;
    u8* temp_v1;
    u8* var_a0;
    u8* var_a1;
    u8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        temp_v1 = var_a0;
        if (var_a2 > 0) {
            do {
                temp_v0 = *var_a1;
                var_a1 += 1;
                var_a2 -= 1;
                *var_a0 = temp_v0;
                var_a0 += 1;
            } while (var_a2 > 0);
        }
        var_v0 = temp_v1;
    }
    return var_v0;
}

s8* _memset(s8* arg0, s8 arg1, s32 arg2)
{
    s32 var_a2;
    s8* var_a0;
    s8* var_v0;

    var_a0 = arg0;
    var_a2 = arg2;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        var_v0 = var_a0;
        if (var_a2 <= 0) {
            return NULL;
        }
        do {
            *var_a0 = arg1;
            var_a2 -= 1;
            var_a0 += 1;
        } while (var_a2 > 0);
    }
    return var_v0;
}

int rand(void) {
    u_long nNext;

    nNext = (D_8009B138 * 0x41C64E6D) + 0x3039;
    D_8009B138 = nNext;
    return (nNext >> 0x10) & 0x7FFF;
}

void srand(u_long seed) {
    D_8009B138 = seed;
}

char* strcat(char* arg0, char* arg1)
{
    char* temp_v1;
    char temp_v0;

    if (arg0 == NULL) {
        return NULL;
    }
    if (arg1 == NULL) {
        return NULL;
    }
    if (&arg0[strlen(arg0)] != &arg1[strlen(arg1)]) {
        temp_v1 = arg0;
        while (*arg0++ != '\0') {}
        arg0--;
        do {
            *arg0++ = temp_v0 = *arg1++;
        } while (temp_v0 != '\0');
        return temp_v1;
    }

    return NULL;
}

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

void putchar(char ch) {
    if (ch != 0x9) {
        if (ch == 0xa) {
            putchar(0xd);
            D_8009B140 = 0;
            write(1, &ch, 1);
            return;
        }
    } else {
        do {
            putchar(0x20);
        } while (D_8009B140 & 0x7);
        return;
    }

    if (D_8007FA71[ch] & 0x97) {
        D_8009B140++;
    }

    write(1, &ch, 1);
}

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
