#include "common.h"
#include "psyq/libstamp.h"

PsyqStamp libc2_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_C2, 19, 6, 52);

void putchar(char c);

void puts(char* s) {
    char c;

    if (s == NULL) {
        s = "<NULL>";
    }
    while ((c = *s++) != 0) {
        putchar(c);
    }
}
