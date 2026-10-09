#include "common.h"
#include "padlocal.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", PadInitDirect);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006AB4C);

void func_8006AB4C(padPort* port)
{
    int i;
    u_char* slot;

    if (port->unk49) {
        slot = port->unk5D;
        port->unk49 = 0;
        port->unk46 = 0;
        port->unkE6 = 0;
        port->unk14 = 0;
        port->unk18 = 0;
        port->unkE3 = 0;
        port->unkE4 = 0;
        port->unkE6 = 0;
        port->unkE9 = 0;
        port->unkEA = 0;
        port->unk0 = 0;
        port->unk4 = NULL;
        port->unk8 = 0;

        for (i = 0; i < 6; ++i) {
            *slot++ = 0xFF;
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006ABB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006ACA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006ACB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006AD74);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006AFF0);

int func_8006AFF0(padPort* port)
{
    int i;

    for (i = 0; i < 2; ++i) {
        if (port == &D_8009B3A0[i]) {
            return (i + 1) * 16;
        }
    }

    return 0xFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padportd", func_8006B028);

padPort* func_8006B028(int port) { return port & 0xF0 ? &D_8009B3A0[1] : D_8009B3A0; }

__asm__("nop");
