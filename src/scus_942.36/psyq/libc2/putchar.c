#include "common.h"

extern u8 D_8007FA71[];
extern u32 D_8009B140;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libc2/putchar", putchar);
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
