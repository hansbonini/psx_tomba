#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", SsStart2);

/**
 * @brief Start the sound system (interrupt version)
 * 
 * Starts the sequencer tick, using VSyncCallback for the VSync based
 * modes.
 */
void SsStart2(void) { _SsStart(0); }

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", _SsTrapIntrVSync);

/**
 * @brief Internal: VBlank interrupt handler of the sequencer
 * 
 * Calls the previous VBlank handler (if any) and then the sequencer tick
 * function.
 */
void _SsTrapIntrVSync(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk12) {
        env->unk12();
    }
    env->unk8();
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ut_roff", _SsSeqCalledTbyT_1per2);

/**
 * @brief Internal: call the sequencer tick every other interrupt
 * 
 * Used for low tick rates: calls the tick function on every second
 * invocation.
 */
void _SsSeqCalledTbyT_1per2(void) {
    struct SndSeqTickEnv* env = &_snd_seq_tick_env;

    if (env->unk20 == 0) {
        env->unk20 = 1;
    } else {
        env->unk20 = 0;
        env->unk8();
    }
}
