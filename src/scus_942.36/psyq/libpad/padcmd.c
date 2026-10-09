#include "common.h"
#include "padlocal.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padSetAct);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padSetCmd);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padSendAtLoadInfo);

void _padSendAtLoadInfo(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8006A378(port);
        break;

    case 3:
        func_8006A38C(port, port->unkE4);
        break;

    case 4:
        func_8006A3CC(port, port->unk47);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padRecvAtLoadInfo);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padGetActSize);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padLoadActInfo);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_80069DA4);

void func_80069DA4(padPort* port)
{
    switch (port->unk46) {
    case 2:
        func_8006A38C(port, port->unk47);
        break;

    case 3:
        func_8006A3AC(port, port->unk47);
        break;

    case 4:
        if (port->unk48 == 0) {
            func_8006A3CC(port, port->unk47);
        } else {
            func_8006A3EC(port);
        }
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_80069E4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padSetActAlign);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A128);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A144);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padSetMainMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A2A4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A2F8);

int func_8006A2F8(padPort* port)
{
    if (port->unk53) {
        if (port->unk46 == 2) {
            return 1;
        }

        port->unk46 = 0xFE;
    } else {
        D_80097514(port);
    }

    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", _padCmdParaMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A378);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A38C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A3AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A3CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padcmd", func_8006A3EC);
