#include "common.h"
#include "game.h"
#include "psyq/libspu.h"

#define D_8009B034 ((DISPENV*)((byte*)&D_8009B010+0x24))
#define D_8009B01C ((u_long*)((byte*)&D_8009B010+0xC))

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001F6D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FAE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FCE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FD20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8001FD80);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8002059C);
void func_8002059C(s32 arg0)
{
    func_80020EEC((arg0 & 0xFF) | 0x1000, arg0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800205C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8002065C);
void func_8002065C(void)
{
    func_80020778(-1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_8002067C);
void func_8002067C(s16 arg0)
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800210A8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80021110);
void func_80021110(void)
{
    D_8009B074 = 1;
    SsSeqSetVol(D_800A2790, 0, 0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80021148);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_80021180);
void func_80021180(void)
{
    SpuSetKey(0, 0xFF0000);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/audio/sound", func_800211A4);
void func_800211A4(void)
{
    s32 i;

    if (D_80077FA8 != 0) {
        sndQuit();
    }
    SsInitHot();
    SsSetTableSize(&D_800A15D8, 4, 1);
    SsSetTickMode(SS_TICK60);
    SsSetAutoKeyOffMode(0);
    SpuSetKey(SPU_OFF, 0xFFFFFF);
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
        (&D_8009BC28)[i] = 0xF;
        (&D_800A3030)[i] = -1;
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
