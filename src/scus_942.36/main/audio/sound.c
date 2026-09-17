#include "common.h"
#include "game.h"
#include "psyq/libspu.h"


INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001F6D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FAE4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", getSfxVabOffset);
s32 getSfxVabOffset(u16 arg0)
{
    u8 a = D_800778E4[arg0 * 2];
    u8 b = D_800778E5[arg0 * 2];

    return D_80077AEC[a] + b * 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOffSfxVoice);
s16 keyOffSfxVoice(s16 arg0)
{
    u16 i = arg0;

    if (D_8009E438[i] != 0) {
        D_8009BC28[i] = 0xF;
        return SsUtKeyOffV(arg0);
    }
    return -1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setSoundChannel);
s32 setSoundChannel(s32 arg0)
{
    switch (arg0 & 0xF00) {
    case 0x000:
        D_800A2818 = arg0 & 0xFF;
        break;
    case 0x100:
        D_8009C9F8 = arg0 & 0xFF;
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FDC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FE60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FF28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFX);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800200EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSFXAndSetNote);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", playSfxWrapped);
void playSfxWrapped(s32 arg0)
{
    func_80020EEC((arg0 & 0xFF) | 0x1000, arg0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800205C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", startAreaBgm);
void startAreaBgm(void)
{
    func_80020778(-1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", startBgmById);
void startBgmById(s16 arg0)
{
    func_80020778(arg0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800206A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020778);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020CB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80020FAC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", setReverbMode);
void setReverbMode(s32 arg0, s16 arg1)
{
    SpuReverbAttr attr;

    attr.mask = SPU_REV_MODE | SPU_REV_DEPTHL | SPU_REV_DEPTHR;
    attr.mode = arg0 | SPU_REV_MODE_CLEAR_WA;
    attr.depth.left = arg1;
    attr.depth.right = arg1;
    SpuReserveReverbWorkArea(SPU_ON);
    SpuSetReverbModeParam(&attr);
    SpuSetReverb(SPU_ON);
    func_80076364(&attr);
    SpuSetReverbVoice(SPU_ON, 0xFFFF);
    SpuSetReverbVoice(SPU_OFF, 0xFF0000);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", muteBgm);
void muteBgm(void)
{
    D_8009B074 = 1;
    SsSeqSetVol(D_800A2790, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", unmuteBgm);
void unmuteBgm(void)
{
    D_8009B074 = 0;
    SsSeqSetVol(D_800A2790, D_8009B078, D_8009B078);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", keyOffSfxAll);
void keyOffSfxAll(void)
{
    SpuSetKey(SPU_OFF, 0xFF0000);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", shutdownSound);
void shutdownSound(void)
{
    s32 i;

    if (D_80077FA8 != 0) {
        sndQuit();
    }
    SsInitHot();
    SsSetTableSize(&D_800A15D8, 4, 1);
    SsSetTickMode(SS_TICK60);
    SsSetAutoKeyOffMode(0);
    SpuSetKey(SPU_OFF, SPU_ALLCH);
    SsSetReservedVoice(0x10);
    D_8009B048.mask = (
        SPU_COMMON_CDMIX |
        SPU_COMMON_CDVOLR | 
        SPU_COMMON_CDVOLL | 
        SPU_COMMON_MVOLR | 
        SPU_COMMON_MVOLL
    );
    D_8009B048.mvol.left = 0x3FFF;
    D_8009B048.mvol.right = 0x3FFF;
    D_8009B048.cd.volume.left = 0x7FFF;
    D_8009B048.cd.volume.right = 0x7FFF;
    D_8009B048.cd.mix = SPU_ON;
    SpuSetCommonAttr(&D_8009B048);
    SsStart();
    
    D_8009E638 = 0;
    D_800A32F8 = 0;
    D_8009C9F0 = 0;
    D_8009B078 = 0;
    D_8009B07C = 0;
    D_8009B094 = 0;
    for (i = 0; i < 0x18; ++i) {
        D_8009BC28[i] = 0xF;
        D_800A3030[i] = -1;
    }
    for (i = 0; i < 0x8; ++i) {
        (&D_1F8003B6-7)[i] = -1;
    }
    D_800A2790 = -1;
    D_8009E430 = -1;
    D_80077FA8 = 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", sndQuit);
void sndQuit(void)
{
    D_80077FA8 = 0;
    SsEnd();
    SsQuit();
}
