#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsSeqPlay);

void SsSeqPlay(short seq_access_num, char play_mode, short l_count) {
    Snd_SetPlayMode(seq_access_num, 0, play_mode, l_count);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsSepPlay);

void SsSepPlay(
    short sep_access_num, short seq_num, char play_mode, short l_count) {
    Snd_SetPlayMode(sep_access_num, seq_num, play_mode, l_count);
}

// INCLUDE_ASM("nonmatchings/psyq/libsnd/ssplay", SsQuit);

void SsQuit(void) { SpuQuit(); }
