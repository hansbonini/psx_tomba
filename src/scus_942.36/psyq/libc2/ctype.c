#include "common.h"
#include "psyq/ctype.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/ctype", toupper);
char toupper(char c)
{
    if (islower(c)) {
        c = _toupper(c);
    }
    return c;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/ctype", tolower);
char tolower(char c)
{
    if (isupper(c)) {
        c = _tolower(c);
    }
    return c;
}
