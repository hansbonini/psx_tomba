#include "common.h"
#include "psyq/ctype.h"

extern u32 D_8009B140;

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/putchar", putchar);
void putchar(char c) {
    if (c != '\t') {
        if (c == '\n') {
            putchar('\r');
            D_8009B140 = 0;
            write(1, &c, 1);
            return;
        }
    } else {
        do {
            putchar(' ');
        } while (D_8009B140 & 0x7);
        return;
    }
    if (isprint(c)) {
        D_8009B140++;
    }
    write(1, &c, 1);
}
