#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libc2/printf", printf);
/**
 * @brief Print formatted text to the standard output (TTY)
 * 
 * Forwards the format string and the variable arguments (taken from the
 * stack starting at a1) to prnt().
 * 
 * @param fmt printf-style format string
 * @param a1 First variable argument
 * @param a2 Second variable argument
 * @param a3 Third variable argument
 * @return Number of characters written
 */
int printf(char* fmt, int a1, int a2, int a3)
{
    &fmt;
    &a2;
    &a3;
    return prnt(1, fmt, &a1);
}
