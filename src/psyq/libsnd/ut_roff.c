#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", SsStart2);

void SsStart2(void) { _SsStart(0); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", _SsTrapIntrVSync);

void _SsTrapIntrVSync(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk12) {
        env->unk12();
    }
    env->unk8();
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", _SsSeqCalledTbyT_1per2);

void _SsSeqCalledTbyT_1per2(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk20 == 0) {
        env->unk20 = 1;
    } else {
        env->unk20 = 0;
        env->unk8();
    }
}
