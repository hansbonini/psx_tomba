#include "common.h"
#include "libsnd_i.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssvol", _SsSndSetVol);

void _SsSndSetVol(s32 arg0, s32 arg1, u16 arg2, u16 arg3) {
    _SsVmSetSeqVol(arg0 | (arg1 << 8), arg2, arg3, 1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssvol", SsSeqSetVol);

void SsSeqSetVol(short arg0, short arg1, short arg2) {
    _SsVmSetSeqVol(arg0, arg1, arg2, 1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssvol", SsSepSetVol);

void SsSepSetVol(s16 sep_access_num, s16 seq_num, s16 voll, s16 volr) {
    _SsVmSetSeqVol(
        sep_access_num | (seq_num << 8), voll & 0xFFFF, volr & 0xFFFF, 1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssvol", SsSeqGetVol);

void SsSeqGetVol(s16 access_num, s16 seq_num, s16* voll, s16* volr) {
    _SsVmGetSeqVol(access_num | (seq_num << 8), voll, volr);
}
