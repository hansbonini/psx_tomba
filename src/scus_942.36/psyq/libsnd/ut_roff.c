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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", _SsTrapIntrVSync);

void _SsTrapIntrVSync(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk12) {
        env->unk12();
    }
    env->unk8();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", _SsSeqCalledTbyT_1per2);

void _SsSeqCalledTbyT_1per2(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk20 == 0) {
        env->unk20 = 1;
    } else {
        env->unk20 = 0;
        env->unk8();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", SetRCnt);

long SetRCnt(u_long counter, u_short targetVal, long mode) {
    int i;
    u_short newMode;

    i = counter & 0xFFFF;
    newMode = 0x48;

    if (i >= 3) {
        return 0;
    }

    (*_rootCounter0)[i].mode = 0;
    (*_rootCounter0)[i].targetVal = targetVal;

    if (i < 2u) {
        if (mode & 0x10) {
            newMode = 0x49;
        }
        if (!(mode & 1)) {
            newMode |= 0x100;
        }
    } else {
        if (i == 2) {
            if (!(mode & 1)) {
                newMode = 0x248;
            }
        }
    }
    if ((mode & 0x1000) != 0) {
        newMode |= 0x10;
    }
    (*_rootCounter0)[i].mode = newMode;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", GetRCnt);

long GetRCnt(u_long spec) {
    int i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    return (*_rootCounter0)[i].currentVal;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", StartRCnt);

long StartRCnt(u_long spec)
{
    int i;

    i = spec & 0xFFFF;
    (*_interruptReg)[1] |= _interruptMasks[i];
    return i < 3;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", func_8006E5F4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ut_roff", ResetRCnt);

long ResetRCnt(u_long spec) {
    int i;

    i = spec & 0xFFFF;
    if (i >= 3) {
        return 0;
    }
    (*((RootCounter(*)[3])_rootCounter0))[i].currentVal = 0;
    return 1;
}

__asm__("nop");
