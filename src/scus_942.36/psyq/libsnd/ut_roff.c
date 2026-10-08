#include "common.h"
#include "libsnd_i.h"

typedef struct {
    u_short currentVal;
    short : 16;
    u_short mode;
    short : 16;
    u_short targetVal;
    short : 16;
    int : 32;
} RootCounter;
extern int (*_interruptReg)[2];
extern volatile RootCounter (*_rootCounter0)[3];
extern long _interruptMasks[4];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", SsStart2);

void SsStart2(void) { _SsStart(0); }

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", _SsTrapIntrVSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", _SsSeqCalledTbyT_1per2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", SetRCnt);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", func_8006E58C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", StartRCnt);

long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] |= _interruptMasks[i];
    return i < 3;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", func_8006E5F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", ResetRCnt);
