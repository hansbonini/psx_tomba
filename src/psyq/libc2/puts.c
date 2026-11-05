#include "common.h"
#include "psyq/libstamp.h"

PsyqStamp libc2_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_C2, 19, 6, 52);

void putchar(char c);

/**
 * @brief Write a string to the TTY
 * 
 * Outputs every character of the string through putchar(). A NULL pointer
 * prints "<NULL>". Unlike the ANSI version no newline is appended.
 * 
 * @param s NUL-terminated string to write
 */
void puts(char* s) {
    char c;

    if (s == NULL) {
        s = "<NULL>";
    }
    while ((c = *s++) != 0) {
        putchar(c);
    }
}
