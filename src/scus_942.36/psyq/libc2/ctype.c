#include "common.h"

extern u8 D_8007FA71[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/ctype", toupper);
s32 toupper(char ch)
{
    if (D_8007FA71[ch] & 2) {
        ch = ch - 0x20;
    }
    return ch;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/ctype", tolower);
s32 tolower(char ch)
{
    if (D_8007FA71[ch] & 1) {
        ch = ch + 0x20;
    }
    return ch;
}
