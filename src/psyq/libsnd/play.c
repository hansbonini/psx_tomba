#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/play", _SsSndPlay);

void _SsSndPlay(s16 arg0, s16 arg1) { _SsSeqPlay(arg0, arg1); }
