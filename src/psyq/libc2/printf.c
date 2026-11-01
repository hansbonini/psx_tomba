#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/printf", printf);
int printf(char* fmt, int a1, int a2, int a3)
{
    &fmt;
    &a2;
    &a3;
    return prnt(1, fmt, &a1);
}
