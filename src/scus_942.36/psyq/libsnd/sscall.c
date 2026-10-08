#include "common.h"
#include "libsnd_i.h"

void _SsSndStop(s16, s16);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/sscall", SsSeqCalledTbyT);

void SsSeqCalledTbyT(void) {
    int i;
    int j;
    s32 bit;
    if (_snd_ev_flag != 1) {
        _snd_ev_flag = 1;

        _SsVmFlush();

        
        for (i = 0; i < _snd_seq_s_max; i++) {
            
            if (_snd_openflag & (u32)(1 << i)) {
                
                for (j = 0; j < _snd_seq_t_max; j++) {
                    if (_ss_score[i][j].unk90 & 1) {
                        _SsSndPlay(i, j);

                        if (_ss_score[i][j].unk90 & 0x10) {
                            _SsSndCrescendo(i, j);
                        }

                        if (_ss_score[i][j].unk90 & 0x20) {
                            _SsSndDecrescendo(i, j);
                        }

                        if (_ss_score[i][j].unk90 & 0x40) {
                            _SsSndTempo(i, j);
                        }

                        if (_ss_score[i][j].unk90 & 0x80) {
                            _SsSndTempo(i, j);
                        }
                    }

                    if (_ss_score[i][j].unk90 & 2) {
                        _SsSndPause(i, j);
                    }

                    if (_ss_score[i][j].unk90 & 8) {
                        _SsSndReplay(i, j);
                    }

                    if (_ss_score[i][j].unk90 & 4) {
                        _SsSndStop(i, j);
                        _ss_score[i][j].unk90 = 0;
                    }
                }
            }
        }
        _snd_ev_flag = 0;
    }
}
