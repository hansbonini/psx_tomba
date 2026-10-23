#include "common.h"
#include "psyq/ctype.h"

u32 _ctype__d[33] asm("_ctype_") = {
    0x20202000, 0x20202020, 0x08082020, 0x20080808,
    0x20202020, 0x20202020, 0x20202020, 0x20202020,
    0x10101820, 0x10101010, 0x10101010, 0x10101010,
    0x04040410, 0x04040404, 0x10040404, 0x10101010,
    0x41411010, 0x41414141, 0x01010101, 0x01010101,
    0x01010101, 0x01010101, 0x01010101, 0x10101010,
    0x42421010, 0x42424242, 0x02020202, 0x02020202,
    0x02020202, 0x02020202, 0x02020202, 0x10101010,
    0x00000020,
};

asm(
    ".globl D_8007FA73\nD_8007FA73 = _ctype_ + 3\n"
);

// INCLUDE_ASM("nonmatchings/psyq/libc2/ctype", toupper);
char toupper(char c)
{
    if (islower(c)) {
        c = _toupper(c);
    }
    return c;
}

// INCLUDE_ASM("nonmatchings/psyq/libc2/ctype", tolower);
char tolower(char c)
{
    if (isupper(c)) {
        c = _tolower(c);
    }
    return c;
}
