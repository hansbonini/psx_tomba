#include "common.h"
#include "padlocal.h"

/* PSY-Q LIBPAD WAITRC2: setRC2wait, chkRC2wait. */

void setRC2wait(int limit) {
    int start = *(volatile u16 *)0x1F801120;
    D_8009FD80 = limit;
    D_8009B6A4 = start;
}

int chkRC2wait(void) {
    register u32 current asm("$4");
    register u32 raw asm("$3");
    u32 base;
    u32 limit;

    raw = *(volatile u16 *)0x1F801120;
    base = D_8009B6A4;
    asm volatile("" : "=r"(raw) : "0"(raw));
    current = raw & 0xFFFF;
    if (current < base) {
        if (*(volatile u16 *)0x1F801128 != 0) {
            current += *(volatile u16 *)0x1F801128;
        } else {
            current += 0x10000;
        }
    }

    if ((*(volatile u16 *)0x1F801124 & 0x200) != 0) {
        limit = D_8009FD80;
        return !((current - D_8009B6A4) < limit);
    } else {
        limit = D_8009FD80;
        return !(((current - D_8009B6A4) >> 3) < limit);
    }
}
