#include "common.h"
#include "libsnd_i.h"

extern struct SndSeqTickEnv _snd_seq_tick_env;
void _SsTrapIntrVSync(void);
void _SsSeqCalledTbyT_1per2(void);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libsnd/ssstart", _SsStart);

void _SsStart(s32 arg0) {
    u16 rcnt_target;
    u32 rcnt_spec;

    s32 wait = 1000;
    while (--wait >= 0) {
    }

    rcnt_spec = 0xF2000002;
    _snd_seq_tick_env.unk16 = 0;
    _snd_seq_tick_env.unk18 = 6;
    _snd_seq_tick_env.unk17 = 0;
    _snd_seq_tick_env.unk12 = 0;
    rcnt_target = 0x44E8;
    switch (_snd_seq_tick_env.unk0) {
    case 0:
        _snd_seq_tick_env.unk18 = 0x7F;
        return;

    case 5:
        _snd_seq_tick_env.unk18 = 0;
        if (arg0 == 0) {
            _snd_seq_tick_env.unk16 = 1;
        } else {
            rcnt_spec = 0xF2000003;
            rcnt_target = 1;
        }
        break;

    case 3:
        rcnt_target = 0x89D0;
        break;

    case 2:
        break;

    default:
        if (_snd_seq_tick_env.unk4 == 0) {
            if (_snd_seq_tick_env.unk0 < 0x46) {
                rcnt_target = 0x204CC0 / _snd_seq_tick_env.unk0;
                _snd_seq_tick_env.unk17++;
            } else {
                rcnt_target = 0x409980 / _snd_seq_tick_env.unk0;
            }
        } else {
            return;
        }
        break;
    }

    if (_snd_seq_tick_env.unk16 != 0) {
        EnterCriticalSection();
        VSyncCallback(_snd_seq_tick_env.unk8);
    } else {
        EnterCriticalSection();
        ResetRCnt(rcnt_spec);
        SetRCnt(rcnt_spec, rcnt_target, 0x1000);
        if (_snd_seq_tick_env.unk18 == 0) {
            _snd_seq_tick_env.unk12 =
                InterruptCallback(_snd_seq_tick_env.unk18, NULL);
            InterruptCallback(_snd_seq_tick_env.unk18, _SsTrapIntrVSync);
        } else if (_snd_seq_tick_env.unk17 == 0) {
            InterruptCallback(_snd_seq_tick_env.unk18, _snd_seq_tick_env.unk8);
        } else {
            InterruptCallback(_snd_seq_tick_env.unk18, _SsSeqCalledTbyT_1per2);
        }
    }
    ExitCriticalSection();
}
