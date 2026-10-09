#include "common.h"
#include "padlocal.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padseqd", _padInitDirSeq);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padseqd", func_8006B080);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padseqd", func_8006B154);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padseqd", _dirFailAuto);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padseqd", func_8006B494);

int func_8006B494(padPort* port) {
    int ret;

    if ((port->unkE6 == 0) || (port->unk46 != 0xFF)) {
        ret = 1;
    } else {
        ret = 0;
    }

    return ret;
}

__asm__("nop");
__asm__("nop");
__asm__("nop");
