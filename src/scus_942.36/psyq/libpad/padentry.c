#include "common.h"
#include "padlocal.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadChkVsync);

int PadChkVsync(void) { return _padChkVsync(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadStartCom);

int PadStartCom(void) { return _padStartCom(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadStopCom);

void PadStopCom(void) { _padStopCom(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadChkMtap);

int PadChkMtap(int port)
{
    int ret;

    if (D_8009755C == 0) {
        ret = 0;
    } else {
        ret = D_80097544[port >> 4].unkE8 == 8;
    }

    return ret;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadGetState);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadInfoMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadInfoAct);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadInfoComb);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadSetActAlign);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadSetMainMode);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpad/padentry", PadSetAct);
