#include "common.h"
#include "padlocal.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", PadEnableCom);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padSetVsyncParam);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", func_80068FF0);

int func_80068FF0(void)
{
    if (!(D_80097570->mask & 1) || !(D_80097570->stat & 1)) {
        return 0;
    }

    if (D_80097538 != NULL) {
        D_80097538();
    }

    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", func_80069058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padChkVsync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padStartCom);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padStopCom);

void _padStopCom(void)
{
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, D_8009B2E0);
    ExitCriticalSection();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padInitSioMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", func_800694FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padSioRW);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", func_8006979C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", _padClrIntSio0);

int _padClrIntSio0(void)
{
    D_80097570->stat = ~0x80;

    while (D_80097574->stat & 0x80) {
        if (chkRC2wait()) {
            return 0;
        }
    }

    D_80097574->ctrl |= 0x10;
    return 1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padmain", func_80069A60);
