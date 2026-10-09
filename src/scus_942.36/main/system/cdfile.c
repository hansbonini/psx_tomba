#include "common.h"
#include "game.h"
//#include "psyq/libcd.h"

s32 fixedMulSin(s16 arg0, s16 arg1);
s32 fixedMulCos(s16 arg0, s16 arg1);
s32 fixedMulSin2(s16 arg0, s16 arg1);


LoadRecord D_80077FAC[2] = {
    { FILE_SYS_LDSYS_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x1E18, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80077FD4[2] = {
    { FILE_SYS_LDAR00_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x890, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80077FFC[2] = {
    { FILE_SYS_LDAR01_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x79C, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078024[2] = {
    { FILE_SYS_LDAR02_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x87C, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007804C[2] = {
    { FILE_SYS_LDAR03_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x944, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078074[2] = {
    { FILE_SYS_LDAR04_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0xE90, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007809C[2] = {
    { FILE_SYS_LDAR05_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x680, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800780C4[2] = {
    { FILE_SYS_LDAR06_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x49C, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800780EC[2] = {
    { FILE_SYS_LDAR07_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x724, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078114[2] = {
    { FILE_SYS_LDAR08_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x590, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007813C[2] = {
    { FILE_SYS_LDAR09_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x7CC, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078164[2] = {
    { FILE_SYS_LDAR10_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0xB44, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007818C[2] = {
    { FILE_SYS_LDAR11_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x418, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800781B4[2] = {
    { FILE_SYS_LDAR12_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0xE40, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800781DC[2] = {
    { FILE_SYS_LDAR13_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x358, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078204[2] = {
    { FILE_SYS_LDAR14_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x834, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007822C[2] = {
    { FILE_SYS_LDAR14_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x834, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078254[2] = {
    { FILE_SYS_LDAR16_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x5C4, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007827C[2] = {
    { FILE_SYS_LDAR17_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x69C, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800782A4[2] = {
    { FILE_SYS_LDAR18_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x370, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800782CC[2] = {
    { FILE_SYS_LDAR19_BIN, 0xFF, LOAD_KIND_LDSYS, 0x00000000, 0x564, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

s32 LDSYS_LOAD_LIST = (s32)D_80077FAC;

s32 LDAR_LOAD_LISTS[20] = {
    (s32)D_80077FD4, (s32)D_80077FFC, (s32)D_80078024, (s32)D_8007804C, (s32)D_80078074,
    (s32)D_8007809C, (s32)D_800780C4, (s32)D_800780EC, (s32)D_80078114, (s32)D_8007813C,
    (s32)D_80078164, (s32)D_8007818C, (s32)D_800781B4, (s32)D_800781DC, (s32)D_80078204,
    (s32)D_8007822C, (s32)D_80078254, (s32)D_8007827C, (s32)D_800782A4, (s32)D_800782CC
};

LoadRecord D_80078348[2] = {
    { FILE_SOUND_SND_INI_WVD, 0xFF, LOAD_KIND_WVD | 15, 0x801B0900, 0x4A6CC, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078370[2] = {
    { FILE_SOUND_SND_LOGO_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D1A00, 0x2582C, 0, 9, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078398[3] = {
    { FILE_SOUND_SND_TTL_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801EBA00, 0xB7BC, 0, 11, LOAD_TYPE_RAW },
    { FILE_SOUND_S_TITLE_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x5A1, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800783D4[3] = {
    { FILE_SOUND_SND_SYS_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E6E00, 0xFBCC, 0, 9, LOAD_TYPE_RAW },
    { FILE_SOUND_S_SYS00_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xE10, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078410[3] = {
    { FILE_SOUND_SND0000_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C5D00, 0x2F564, 0, 1, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR000_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x2470, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007844C[3] = {
    { FILE_SOUND_SND0003_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D8600, 0x1E394, 0, 2, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR003_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xD19, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078488[3] = {
    { FILE_SOUND_SND001__WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D6B00, 0x1F77C, 0, 3, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR010_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1036, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800784C4[3] = {
    { FILE_SOUND_SND0020_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E0000, 0x16994, 0, 8, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR020_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xF96, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078500[3] = {
    { FILE_SOUND_SND0023_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E0C00, 0x15E04, 0, 10, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR023_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xCC7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007853C[3] = {
    { FILE_SOUND_SND0030_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C3800, 0x319A4, 0, 12, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR030_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x22D0, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078578[3] = {
    { FILE_SOUND_SND0030X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D3500, 0x22CF4, 2, 62, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR030X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x11CD, 2, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800785B4[3] = {
    { FILE_SOUND_SND0032_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D2800, 0x24A04, 3, 13, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR032_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x7FF, 3, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800785F0[3] = {
    { FILE_SOUND_SND0032X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D8300, 0x1E6A4, 4, 63, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR032X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xBA6, 4, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007862C[3] = {
    { FILE_SOUND_SND0040_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C8300, 0x2DEC4, 0, 16, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR040_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1630, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078668[3] = {
    { FILE_SOUND_SND0044_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C7500, 0x2F504, 0, 17, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR044_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xF04, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800786A4[3] = {
    { FILE_SOUND_SND0050_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801DD800, 0x1918C, 0, 64, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR050_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xB03, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800786E0[3] = {
    { FILE_SOUND_SND0060_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C9E00, 0x2ABA4, 0, 24, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR060_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x2801, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007871C[3] = {
    { FILE_SOUND_SND0062_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801DEF00, 0x17A8C, 0, 25, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR062_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xA94, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078758[3] = {
    { FILE_SOUND_SND001_X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E0B00, 0x14EDC, 0, 3, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR010X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1945, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078794[3] = {
    { FILE_SOUND_SND0080_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D1200, 0x26064, 0, 32, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR080_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x72F, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800787D0[3] = {
    { FILE_SOUND_SND0090_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C7100, 0x2E8E4, 0, 36, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR090_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x19EB, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_8007880C[3] = {
    { FILE_SOUND_SND0091_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801DEB00, 0x176BC, 0, 37, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR091_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x125E, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078848[3] = {
    { FILE_SOUND_SND0096_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E1D00, 0x14D0C, 0, 39, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR096_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x84B, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078884[3] = {
    { FILE_SOUND_SND010__WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D9800, 0x1C25C, 0, 40, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR100_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1F61, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800788C0[3] = {
    { FILE_SOUND_SND0103_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801CC000, 0x2A9F4, 0, 42, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR103_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x89F, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800788FC[3] = {
    { FILE_SOUND_SND010_X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801DFA00, 0x1583C, 0, 40, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR100X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x264E, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078938[3] = {
    { FILE_SOUND_SND0103X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801BF000, 0x37304, 0, 43, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR103X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xD95, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078974[3] = {
    { FILE_SOUND_SND0110_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E3B00, 0x1174C, 0, 44, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR110_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x2128, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800789B0[3] = {
    { FILE_SOUND_SND004_X_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801DDA00, 0x1805C, 0, 18, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR040X_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1AFB, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800789EC[3] = {
    { FILE_SOUND_SND0130_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801D6300, 0x1FF34, 0, 57, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR130_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x13A6, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078A28[3] = {
    { FILE_SOUND_SND_END_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E3E00, 0x1242C, 0, 15, LOAD_TYPE_RAW },
    { FILE_SOUND_S_END_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x17DB, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078A64[3] = {
    { FILE_SOUND_SND0140_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C4F00, 0x30B14, 0, 48, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078AA0[3] = {
    { FILE_SOUND_SND0141_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C9000, 0x2C9F4, 0, 49, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078ADC[3] = {
    { FILE_SOUND_SND0142_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C5A00, 0x30014, 0, 50, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078B18[3] = {
    { FILE_SOUND_SND0143_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C9A00, 0x2BFD4, 0, 51, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078B54[3] = {
    { FILE_SOUND_SND0144_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801CC300, 0x296D4, 0, 52, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078B90[3] = {
    { FILE_SOUND_SND0145_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801CB200, 0x2A7D4, 0, 53, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078BCC[3] = {
    { FILE_SOUND_SND0146_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C0900, 0x350E4, 0, 54, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR140_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x1BD7, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078C08[3] = {
    { FILE_SOUND_SND0147_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801BDF00, 0x36344, 0, 55, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR147_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x349F, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078C44[3] = {
    { FILE_SOUND_SND0160_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C8900, 0x2D8C4, 0, 70, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR160_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x107F, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078C80[3] = {
    { FILE_SOUND_SND0170_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C0D00, 0x34D34, 0, 72, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR170_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x193E, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078CBC[3] = {
    { FILE_SOUND_SND0181_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C2400, 0x32D84, 0, 73, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR181_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x22AF, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078CF8[3] = {
    { FILE_SOUND_SND0182_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801C7900, 0x2F0C4, 0, 74, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR1802_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0xAE0, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078D34[3] = {
    { FILE_SOUND_SND0192_WVD, 0xFF, LOAD_KIND_WVD | 3, 0x801E5100, 0x12094, 0, 59, LOAD_TYPE_RAW },
    { FILE_SOUND_S_AR192_SEQ, 0xFF, LOAD_KIND_SEQ, 0x00000000, 0x493, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078D70[2] = {
    { FILE_SOUND_SND0010_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801E7700, 0xC77C, 0, 4, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078D98[2] = {
    { FILE_SOUND_SND0012_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801DEF00, 0x14DCC, 0, 5, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078DC0[2] = {
    { FILE_SOUND_SND0013_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801E5700, 0xE30C, 0, 6, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078DE8[2] = {
    { FILE_SOUND_SND0014_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801F0700, 0x33EC, 0, 7, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078E10[2] = {
    { FILE_SOUND_SND0100_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801D8A00, 0x1AF2C, 0, 28, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078E38[2] = {
    { FILE_SOUND_SND0101_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801D9200, 0x1A2DC, 0, 28, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078E60[2] = {
    { FILE_SOUND_SND0040X_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801D9A00, 0x19F5C, 0, 19, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078E88[2] = {
    { FILE_SOUND_SND0044X_WVD, 0xFF, LOAD_KIND_WVD | 4, 0x801D5A00, 0x1DF0C, 0, 19, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

s32 SOUND_SET_LOAD_LISTS[52] = {
    (s32)D_80078348, (s32)D_80078370, (s32)D_80078398, (s32)D_800783D4, (s32)D_80078410,
    (s32)D_8007844C, (s32)D_80078488, (s32)D_800784C4, (s32)D_80078500, (s32)D_8007853C,
    (s32)D_80078578, (s32)D_800785B4, (s32)D_800785F0, (s32)D_8007862C, (s32)D_80078668,
    (s32)D_800786A4, (s32)D_800786E0, (s32)D_8007871C, (s32)D_80078758, (s32)D_80078794,
    (s32)D_800787D0, (s32)D_8007880C, (s32)D_80078848, (s32)D_80078884, (s32)D_800788C0,
    (s32)D_800788FC, (s32)D_80078938, (s32)D_80078974, (s32)D_800789B0, (s32)D_800789EC,
    (s32)D_80078A28, (s32)D_80078A64, (s32)D_80078AA0, (s32)D_80078ADC, (s32)D_80078B18,
    (s32)D_80078B54, (s32)D_80078B90, (s32)D_80078BCC, (s32)D_80078C08, (s32)D_80078C44,
    (s32)D_80078C80, (s32)D_80078CBC, (s32)D_80078CF8, (s32)D_80078D34, (s32)D_80078D70,
    (s32)D_80078D98, (s32)D_80078DC0, (s32)D_80078DE8, (s32)D_80078E10, (s32)D_80078E38,
    (s32)D_80078E60, (s32)D_80078E88
};

short MOVIE_FILE_IDS[22] = {
    FILE_MOVIE_MIST_STR,
    FILE_MOVIE_100US_STR,
    FILE_MOVIE_OP_INST_STR,
    FILE_MOVIE_BOY_STR,
    FILE_MOVIE_MCC_STR,
    FILE_MOVIE_NOZOITE1_STR,
    FILE_MOVIE_SORA1_STR,
    FILE_MOVIE_SORA2_STR,
    FILE_MOVIE_NOZOITE2_STR,
    FILE_MOVIE_MILLION_STR,
    FILE_MOVIE_HONOO2_STR,
    FILE_MOVIE_BUNMEI_STR,
    FILE_MOVIE_BUNMEI2_STR,
    FILE_MOVIE_HANA_STR,
    FILE_MOVIE_ARASHI_STR,
    FILE_MOVIE_MANTION_STR,
    FILE_MOVIE_BAKKASU_STR,
    FILE_MOVIE_JUNGLE_STR,
    FILE_MOVIE_KARAKURI_STR,
    FILE_MOVIE_MABUTA_STR,
    FILE_MOVIE_END_US_STR,
    FILE_MOVIE_LOGO_STR
};

LoadRecord D_80078FAC[1] = {
    LOAD_LIST_END
};

LoadRecord D_80078FC0[2] = {
    { FILE_AREA15_SCR0100_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0xF63, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80078FE8[2] = {
    { FILE_AREA15_0200_WSS, 0xFF, LOAD_KIND_WSS | 1, 0x801EF800, 0x4F35, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80079010[2] = {
    { FILE_AREA15_0210_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0x1C50, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80079038[2] = {
    { FILE_AREA15_0140_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0x1BE0, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80079060[2] = {
    { FILE_AREA15_0130_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0x238, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80079088[2] = {
    { FILE_AREA15_0120_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0x3AC, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800790B0[2] = {
    { FILE_AREA15_0000_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0xA31, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_800790D8[2] = {
    { FILE_AREA15_0220_WSS, 0x83, LOAD_KIND_WSS, 0x00000000, 0xACF, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

LoadRecord D_80079100[2] = {
    { FILE_AREA15_0201_WSS, 0xFF, LOAD_KIND_WSS | 1, 0x801F2000, 0x24CC, 0, 0, LOAD_TYPE_RAW },
    LOAD_LIST_END
};

s32 D_80079128 = (s32)D_80078FAC;

int WSS_LOAD_LISTS[9] = {
    (s32)D_80078FC0, (s32)D_80078FE8, (s32)D_80079010, (s32)D_80079038, (s32)D_80079060,
    (s32)D_80079088, (s32)D_800790B0, (s32)D_800790D8, (s32)D_80079100
};

s32 AREA_LOAD_LISTS[20] = {
    0x8009881C, 0x8009872C, 0x80098808, 0x800988D0, 0x80098DE4,
    0x80098614, 0x80098434, 0x800986B4, 0x80098524, 0x80098754,
    0x80098AC4, 0x800983A8, 0x80098D94, 0x800982F4, 0x800987B8,
    (s32)&D_80079128, 0x8009854C, 0x80098614, 0x80098308, 0x800984FC
};

fileLink FILE_LINKS[1054] = {
    [FILE_SYS_LDSYS_BIN] = { { itob(21), itob(23), itob(10), 0 }, 0x1E18 },
    [FILE_SYS_LDAR00_BIN] = { { itob(21), itob(22), itob(59), 0 }, 0x890 },
    [FILE_SYS_LDAR01_BIN] = { { itob(21), itob(22), itob(61), 0 }, 0x79C },
    [FILE_SYS_LDAR02_BIN] = { { itob(21), itob(22), itob(62), 0 }, 0x87C },
    [FILE_SYS_LDAR03_BIN] = { { itob(21), itob(22), itob(64), 0 }, 0x944 },
    [FILE_SYS_LDAR04_BIN] = { { itob(21), itob(22), itob(66), 0 }, 0xE90 },
    [FILE_SYS_LDAR05_BIN] = { { itob(21), itob(22), itob(68), 0 }, 0x680 },
    [FILE_SYS_LDAR06_BIN] = { { itob(21), itob(22), itob(69), 0 }, 0x49C },
    [FILE_SYS_LDAR07_BIN] = { { itob(21), itob(22), itob(70), 0 }, 0x724 },
    [FILE_SYS_LDAR08_BIN] = { { itob(21), itob(22), itob(71), 0 }, 0x590 },
    [FILE_SYS_LDAR09_BIN] = { { itob(21), itob(22), itob(72), 0 }, 0x7CC },
    [FILE_SYS_LDAR10_BIN] = { { itob(21), itob(22), itob(73), 0 }, 0xB44 },
    [FILE_SYS_LDAR11_BIN] = { { itob(21), itob(23), itob(0), 0 }, 0x418 },
    [FILE_SYS_LDAR12_BIN] = { { itob(21), itob(23), itob(1), 0 }, 0xE40 },
    [FILE_SYS_LDAR13_BIN] = { { itob(21), itob(23), itob(3), 0 }, 0x358 },
    [FILE_SYS_LDAR14_BIN] = { { itob(21), itob(23), itob(4), 0 }, 0x834 },
    [FILE_SYS_LDAR16_BIN] = { { itob(21), itob(23), itob(6), 0 }, 0x5C4 },
    [FILE_SYS_LDAR17_BIN] = { { itob(21), itob(23), itob(7), 0 }, 0x69C },
    [FILE_SYS_LDAR18_BIN] = { { itob(21), itob(23), itob(8), 0 }, 0x370 },
    [FILE_SYS_LDAR19_BIN] = { { itob(21), itob(23), itob(9), 0 }, 0x564 },
    [FILE_SYSTEM_A00000_GAM] = { { itob(21), itob(23), itob(20), 0 }, 0x3436 },
    [FILE_SYSTEM_A00001_000] = { { itob(21), itob(23), itob(27), 0 }, 0x200 },
    [FILE_SYSTEM_A00002_000] = { { itob(21), itob(23), itob(28), 0 }, 0x80 },
    [FILE_SYSTEM_A00003_GAM] = { { itob(21), itob(23), itob(29), 0 }, 0x3CBE },
    [FILE_SYSTEM_A00004_000] = { { itob(21), itob(23), itob(37), 0 }, 0x200 },
    [FILE_SYSTEM_A00005_000] = { { itob(21), itob(23), itob(38), 0 }, 0x120 },
    [FILE_SYSTEM_A00006_GAM] = { { itob(21), itob(23), itob(39), 0 }, 0x6C84 },
    [FILE_SYSTEM_A00007_000] = { { itob(21), itob(23), itob(53), 0 }, 0x200 },
    [FILE_SYSTEM_OPTSUB00_BIN] = { { itob(22), itob(59), itob(36), 0 }, 0x300C },
    [FILE_SYSTEM_A00008_GAM] = { { itob(21), itob(23), itob(54), 0 }, 0x6C84 },
    [FILE_SYSTEM_A00009_000] = { { itob(21), itob(23), itob(68), 0 }, 0x200 },
    [FILE_SYSTEM_A00010_GAM] = { { itob(21), itob(23), itob(69), 0 }, 0x10B9B },
    [FILE_SYSTEM_A00011_000] = { { itob(21), itob(24), itob(28), 0 }, 0x200 },
    [FILE_SYSTEM_A00012_000] = { { itob(21), itob(24), itob(29), 0 }, 0x10000 },
    [FILE_SYSTEM_A00013_000] = { { itob(21), itob(24), itob(61), 0 }, 0x200 },
    [FILE_SYSTEM_A000131_000] = { { itob(21), itob(24), itob(62), 0 }, 0x8000 },
    [FILE_SYSTEM_A000132_000] = { { itob(21), itob(25), itob(3), 0 }, 0x60 },
    [FILE_SYSTEM_A000133_000] = { { itob(21), itob(25), itob(4), 0 }, 0x100 },
    [FILE_SYSTEM_A00014_000] = { { itob(21), itob(25), itob(5), 0 }, 0x20000 },
    [FILE_SYSTEM_DSPSUB_BIN] = { { itob(22), itob(55), itob(35), 0 }, 0x28F9C },
    [FILE_SYSTEM_A00017_000] = { { itob(21), itob(25), itob(69), 0 }, 0x20000 },
    [FILE_SYSTEM_DSPCLUT_TIM] = { { itob(22), itob(55), itob(33), 0 }, 0xC00 },
    [FILE_SYSTEM_A00018_000] = { { itob(21), itob(26), itob(58), 0 }, 0x200 },
    [FILE_SYSTEM_DSPSUB2_BIN] = { { itob(22), itob(56), itob(42), 0 }, 0xEF58 },
    [FILE_SYSTEM_A00019_000] = { { itob(21), itob(26), itob(59), 0 }, 0x20000 },
    [FILE_SYSTEM_A00020_000] = { { itob(21), itob(27), itob(48), 0 }, 0x200 },
    [FILE_SYSTEM_A00021_000] = { { itob(21), itob(27), itob(49), 0 }, 0x18000 },
    [FILE_SYSTEM_DSPSUB3_BIN] = { { itob(22), itob(56), itob(72), 0 }, 0x18AF8 },
    [FILE_SYSTEM_A00023_000] = { { itob(21), itob(28), itob(22), 0 }, 0x10000 },
    [FILE_SYSTEM_A00024_000] = { { itob(21), itob(28), itob(54), 0 }, 0x20000 },
    [FILE_SYSTEM_A00025_000] = { { itob(21), itob(29), itob(43), 0 }, 0x200 },
    [FILE_SYSTEM_SUBMAP_WMD] = { { itob(22), itob(59), itob(43), 0 }, 0xA838 },
    [FILE_SYSTEM_A00026A_GAM] = { { itob(21), itob(29), itob(44), 0 }, 0xB90 },
    [FILE_SYSTEM_A00026B_GAM] = { { itob(21), itob(29), itob(46), 0 }, 0xB96C },
    [FILE_SYSTEM_A00027_000] = { { itob(21), itob(29), itob(70), 0 }, 0x200 },
    [FILE_SYSTEM_A00028_000] = { { itob(21), itob(29), itob(71), 0 }, 0x60 },
    [FILE_SYSTEM_A00029A_000] = { { itob(21), itob(29), itob(72), 0 }, 0x8000 },
    [FILE_SYSTEM_A00029B_000] = { { itob(21), itob(30), itob(13), 0 }, 0x200 },
    [FILE_SYSTEM_A00030_000] = { { itob(21), itob(30), itob(14), 0 }, 0x2400 },
    [FILE_SYSTEM_A00031_000] = { { itob(21), itob(30), itob(19), 0 }, 0x30000 },
    [FILE_SYSTEM_X00_BIN] = { { itob(22), itob(59), itob(65), 0 }, 0x53F38 },
    [FILE_SYSTEM_A00033_000] = { { itob(21), itob(31), itob(40), 0 }, 0x40000 },
    [FILE_SYSTEM_A00056_000] = { { itob(21), itob(39), itob(16), 0 }, 0x10000 },
    [FILE_SYSTEM_A00037_000] = { { itob(21), itob(33), itob(18), 0 }, 0x10000 },
    [FILE_SYSTEM_A00038_000] = { { itob(21), itob(33), itob(50), 0 }, 0x8000 },
    [FILE_SYSTEM_A00039_000] = { { itob(21), itob(33), itob(66), 0 }, 0x8000 },
    [FILE_SYSTEM_A00041_000] = { { itob(21), itob(34), itob(7), 0 }, 0x30000 },
    [FILE_SYSTEM_X01_BIN] = { { itob(23), itob(2), itob(8), 0 }, 0x57F94 },
    [FILE_SYSTEM_A00045_000] = { { itob(21), itob(35), itob(28), 0 }, 0x30000 },
    [FILE_SYSTEM_A00049_000] = { { itob(21), itob(36), itob(49), 0 }, 0x30000 },
    [FILE_SYSTEM_A00054_000] = { { itob(21), itob(37), itob(70), 0 }, 0x30000 },
    [FILE_SYSTEM_A00061_000] = { { itob(21), itob(39), itob(48), 0 }, 0x18000 },
    [FILE_SYSTEM_A00062_000] = { { itob(21), itob(40), itob(21), 0 }, 0x20000 },
    [FILE_SYSTEM_INFO_BIN] = { { itob(22), itob(57), itob(72), 0 }, 0xD3D4 },
    [FILE_SYSTEM_A00067_000] = { { itob(21), itob(41), itob(10), 0 }, 0x30000 },
    [FILE_SYSTEM_X02_BIN] = { { itob(23), itob(4), itob(34), 0 }, 0x37D0C },
    [FILE_SYSTEM_A000710_000] = { { itob(21), itob(42), itob(31), 0 }, 0x10000 },
    [FILE_SYSTEM_A000711_000] = { { itob(21), itob(42), itob(63), 0 }, 0x10000 },
    [FILE_SYSTEM_A00187_000] = { { itob(22), itob(40), itob(33), 0 }, 0x18000 },
    [FILE_SYSTEM_INFO3_BIN] = { { itob(22), itob(59), itob(16), 0 }, 0x9898 },
    [FILE_SYSTEM_A001890_000] = { { itob(22), itob(41), itob(6), 0 }, 0x10000 },
    [FILE_SYSTEM_A001891_000] = { { itob(22), itob(41), itob(38), 0 }, 0x10000 },
    [FILE_SYSTEM_A001892_000] = { { itob(22), itob(41), itob(70), 0 }, 0x8000 },
    [FILE_SYSTEM_A00210_000] = { { itob(22), itob(52), itob(34), 0 }, 0x10000 },
    [FILE_SYSTEM_A00211_000] = { { itob(22), itob(52), itob(66), 0 }, 0x10000 },
    [FILE_SYSTEM_A00212_000] = { { itob(22), itob(53), itob(23), 0 }, 0x8000 },
    [FILE_SYSTEM_A00074_000] = { { itob(21), itob(43), itob(20), 0 }, 0x18000 },
    [FILE_SYSTEM_A00075_000] = { { itob(21), itob(43), itob(68), 0 }, 0x18000 },
    [FILE_SYSTEM_X03_BIN] = { { itob(23), itob(5), itob(71), 0 }, 0x52A9C },
    [FILE_SYSTEM_A002014_000] = { { itob(22), itob(49), itob(3), 0 }, 0x10000 },
    [FILE_SYSTEM_A002015_000] = { { itob(22), itob(49), itob(35), 0 }, 0x10000 },
    [FILE_SYSTEM_A00077_000] = { { itob(21), itob(44), itob(41), 0 }, 0x18000 },
    [FILE_SYSTEM_A00077A_000] = { { itob(21), itob(45), itob(14), 0 }, 0x18000 },
    [FILE_SYSTEM_A00079_000] = { { itob(21), itob(45), itob(62), 0 }, 0x10000 },
    [FILE_SYSTEM_A00079A_000] = { { itob(21), itob(46), itob(19), 0 }, 0x8000 },
    [FILE_SYSTEM_A00081_000] = { { itob(21), itob(46), itob(35), 0 }, 0x18000 },
    [FILE_SYSTEM_A00081A_000] = { { itob(21), itob(47), itob(8), 0 }, 0x18000 },
    [FILE_SYSTEM_X04_BIN] = { { itob(23), itob(8), itob(12), 0 }, 0x4DA90 },
    [FILE_SYSTEM_A00082A_000] = { { itob(21), itob(47), itob(56), 0 }, 0x30000 },
    [FILE_SYSTEM_A000830_000] = { { itob(21), itob(50), itob(39), 0 }, 0x30000 },
    [FILE_SYSTEM_A00202_000] = { { itob(22), itob(49), itob(67), 0 }, 0x18000 },
    [FILE_SYSTEM_A00204_000] = { { itob(22), itob(50), itob(40), 0 }, 0x8000 },
    [FILE_SYSTEM_A00192_000] = { { itob(22), itob(42), itob(16), 0 }, 0x30000 },
    [FILE_SYSTEM_A00194_000] = { { itob(22), itob(43), itob(37), 0 }, 0x30000 },
    [FILE_SYSTEM_A002012_000] = { { itob(22), itob(48), itob(46), 0 }, 0x10000 },
    [FILE_SYSTEM_A00196_000] = { { itob(22), itob(44), itob(58), 0 }, 0x30000 },
    [FILE_SYSTEM_A00198_000] = { { itob(22), itob(46), itob(4), 0 }, 0x30000 },
    [FILE_SYSTEM_A00083_000] = { { itob(21), itob(49), itob(2), 0 }, 0x38000 },
    [FILE_SYSTEM_INFO2_BIN] = { { itob(22), itob(58), itob(24), 0 }, 0x215E0 },
    [FILE_SYSTEM_A00087_000] = { { itob(21), itob(51), itob(60), 0 }, 0x30000 },
    [FILE_SYSTEM_X05_BIN] = { { itob(23), itob(10), itob(18), 0 }, 0x3276C },
    [FILE_SYSTEM_A00090_000] = { { itob(21), itob(53), itob(6), 0 }, 0x18000 },
    [FILE_SYSTEM_X06_BIN] = { { itob(23), itob(11), itob(44), 0 }, 0x3B15C },
    [FILE_SYSTEM_A002000_000] = { { itob(22), itob(47), itob(25), 0 }, 0x10000 },
    [FILE_SYSTEM_A002001_000] = { { itob(22), itob(47), itob(57), 0 }, 0x10000 },
    [FILE_SYSTEM_A002002_000] = { { itob(22), itob(48), itob(14), 0 }, 0x10000 },
    [FILE_SYSTEM_A00091_000] = { { itob(21), itob(53), itob(54), 0 }, 0x18000 },
    [FILE_SYSTEM_A00092_000] = { { itob(21), itob(54), itob(27), 0 }, 0x18000 },
    [FILE_SYSTEM_A00095_000] = { { itob(21), itob(55), itob(0), 0 }, 0x18000 },
    [FILE_SYSTEM_A00096_000] = { { itob(21), itob(55), itob(48), 0 }, 0x18000 },
    [FILE_SYSTEM_A00099_000] = { { itob(21), itob(56), itob(21), 0 }, 0x20000 },
    [FILE_SYSTEM_A00100_000] = { { itob(21), itob(57), itob(10), 0 }, 0x8000 },
    [FILE_SYSTEM_A00103_000] = { { itob(21), itob(57), itob(26), 0 }, 0x18000 },
    [FILE_SYSTEM_A00105_000] = { { itob(21), itob(57), itob(74), 0 }, 0x18000 },
    [FILE_SYSTEM_A00109_000] = { { itob(21), itob(58), itob(47), 0 }, 0x18000 },
    [FILE_SYSTEM_A001130_000] = { { itob(21), itob(59), itob(20), 0 }, 0x10000 },
    [FILE_SYSTEM_A001131_000] = { { itob(21), itob(59), itob(52), 0 }, 0x10000 },
    [FILE_SYSTEM_A001150_000] = { { itob(22), itob(0), itob(9), 0 }, 0x8000 },
    [FILE_SYSTEM_X08_BIN] = { { itob(23), itob(13), itob(13), 0 }, 0x305E0 },
    [FILE_SYSTEM_A00119_000] = { { itob(22), itob(0), itob(25), 0 }, 0x30000 },
    [FILE_SYSTEM_X09_BIN] = { { itob(23), itob(14), itob(35), 0 }, 0x49238 },
    [FILE_SYSTEM_A00123_000] = { { itob(22), itob(1), itob(46), 0 }, 0x38000 },
    [FILE_SYSTEM_A001270_000] = { { itob(22), itob(3), itob(8), 0 }, 0x10000 },
    [FILE_SYSTEM_A001271_000] = { { itob(22), itob(3), itob(40), 0 }, 0x10000 },
    [FILE_SYSTEM_A001272_000] = { { itob(22), itob(3), itob(72), 0 }, 0x10000 },
    [FILE_SYSTEM_A00129_000] = { { itob(22), itob(4), itob(29), 0 }, 0x8000 },
    [FILE_SYSTEM_A001330_000] = { { itob(22), itob(4), itob(45), 0 }, 0x10000 },
    [FILE_SYSTEM_A001331_000] = { { itob(22), itob(5), itob(2), 0 }, 0x10000 },
    [FILE_SYSTEM_A001400_000] = { { itob(22), itob(7), itob(12), 0 }, 0x10000 },
    [FILE_SYSTEM_A001401_000] = { { itob(22), itob(7), itob(44), 0 }, 0x10000 },
    [FILE_SYSTEM_A001440_000] = { { itob(22), itob(8), itob(1), 0 }, 0x10000 },
    [FILE_SYSTEM_A001441_000] = { { itob(22), itob(8), itob(33), 0 }, 0x10000 },
    [FILE_SYSTEM_A00136_000] = { { itob(22), itob(5), itob(34), 0 }, 0x10000 },
    [FILE_SYSTEM_A00137_000] = { { itob(22), itob(5), itob(66), 0 }, 0x8000 },
    [FILE_SYSTEM_A00138_000] = { { itob(22), itob(6), itob(7), 0 }, 0x8000 },
    [FILE_SYSTEM_X10_BIN] = { { itob(23), itob(16), itob(32), 0 }, 0x4AE78 },
    [FILE_SYSTEM_A00139_000] = { { itob(22), itob(6), itob(23), 0 }, 0x20000 },
    [FILE_SYSTEM_A001462_000] = { { itob(22), itob(8), itob(65), 0 }, 0x18000 },
    [FILE_SYSTEM_A00206_000] = { { itob(22), itob(50), itob(56), 0 }, 0x18000 },
    [FILE_SYSTEM_A00207_000] = { { itob(22), itob(51), itob(29), 0 }, 0x28000 },
    [FILE_SYSTEM_A00147_000] = { { itob(22), itob(9), itob(38), 0 }, 0x38000 },
    [FILE_SYSTEM_A001490_000] = { { itob(22), itob(11), itob(0), 0 }, 0x10000 },
    [FILE_SYSTEM_A001491_000] = { { itob(22), itob(11), itob(32), 0 }, 0x10000 },
    [FILE_SYSTEM_X11_BIN] = { { itob(23), itob(18), itob(32), 0 }, 0x346D4 },
    [FILE_SYSTEM_A001510_000] = { { itob(22), itob(11), itob(64), 0 }, 0x10000 },
    [FILE_SYSTEM_A001511_000] = { { itob(22), itob(12), itob(21), 0 }, 0x10000 },
    [FILE_SYSTEM_A00218_000] = { { itob(22), itob(53), itob(39), 0 }, 0x20000 },
    [FILE_SYSTEM_A00220_000] = { { itob(22), itob(54), itob(28), 0 }, 0x18000 },
    [FILE_SYSTEM_A00222_000] = { { itob(22), itob(55), itob(1), 0 }, 0x10000 },
    [FILE_SYSTEM_X13_BIN] = { { itob(23), itob(19), itob(62), 0 }, 0x32D9C },
    [FILE_SYSTEM_A001742_000] = { { itob(22), itob(23), itob(60), 0 }, 0x18000 },
    [FILE_SYSTEM_A001743_000] = { { itob(22), itob(24), itob(33), 0 }, 0x18000 },
    [FILE_SYSTEM_X14_BIN] = { { itob(23), itob(21), itob(14), 0 }, 0x427C8 },
    [FILE_SYSTEM_A001746_000] = { { itob(22), itob(25), itob(6), 0 }, 0x18000 },
    [FILE_SYSTEM_A001747_000] = { { itob(22), itob(25), itob(54), 0 }, 0x10000 },
    [FILE_SYSTEM_A001750_000] = { { itob(22), itob(27), itob(16), 0 }, 0x18000 },
    [FILE_SYSTEM_A001751_000] = { { itob(22), itob(27), itob(64), 0 }, 0x18000 },
    [FILE_SYSTEM_A001754_000] = { { itob(22), itob(28), itob(37), 0 }, 0x18000 },
    [FILE_SYSTEM_A001755_000] = { { itob(22), itob(29), itob(10), 0 }, 0x18000 },
    [FILE_SYSTEM_A001758_000] = { { itob(22), itob(29), itob(58), 0 }, 0x18000 },
    [FILE_SYSTEM_A001759_000] = { { itob(22), itob(30), itob(31), 0 }, 0x18000 },
    [FILE_SYSTEM_A001762_000] = { { itob(22), itob(31), itob(36), 0 }, 0x18000 },
    [FILE_SYSTEM_A001763_000] = { { itob(22), itob(32), itob(9), 0 }, 0x18000 },
    [FILE_SYSTEM_A001766_000] = { { itob(22), itob(32), itob(57), 0 }, 0x18000 },
    [FILE_SYSTEM_A001767_000] = { { itob(22), itob(33), itob(30), 0 }, 0x18000 },
    [FILE_SYSTEM_A001770_000] = { { itob(22), itob(34), itob(3), 0 }, 0x18000 },
    [FILE_SYSTEM_A001771_000] = { { itob(22), itob(34), itob(51), 0 }, 0x18000 },
    [FILE_SYSTEM_A00153_000] = { { itob(22), itob(12), itob(53), 0 }, 0x28000 },
    [FILE_SYSTEM_A00154_000] = { { itob(22), itob(13), itob(58), 0 }, 0x10000 },
    [FILE_SYSTEM_A001560_000] = { { itob(22), itob(14), itob(15), 0 }, 0x10000 },
    [FILE_SYSTEM_A001561_000] = { { itob(22), itob(14), itob(47), 0 }, 0x10000 },
    [FILE_SYSTEM_A00157_000] = { { itob(22), itob(15), itob(4), 0 }, 0x10000 },
    [FILE_SYSTEM_X16_BIN] = { { itob(23), itob(22), itob(72), 0 }, 0x33758 },
    [FILE_SYSTEM_A001590_000] = { { itob(22), itob(15), itob(36), 0 }, 0x10000 },
    [FILE_SYSTEM_A001591_000] = { { itob(22), itob(15), itob(68), 0 }, 0x10000 },
    [FILE_SYSTEM_A001610_000] = { { itob(22), itob(16), itob(25), 0 }, 0x10000 },
    [FILE_SYSTEM_A001611_000] = { { itob(22), itob(16), itob(57), 0 }, 0x10000 },
    [FILE_SYSTEM_A00163_000] = { { itob(22), itob(17), itob(14), 0 }, 0x38000 },
    [FILE_SYSTEM_A001650_000] = { { itob(22), itob(18), itob(51), 0 }, 0x10000 },
    [FILE_SYSTEM_A001651_000] = { { itob(22), itob(19), itob(8), 0 }, 0x10000 },
    [FILE_SYSTEM_X17_BIN] = { { itob(23), itob(24), itob(25), 0 }, 0x346CC },
    [FILE_SYSTEM_A001670_000] = { { itob(22), itob(19), itob(40), 0 }, 0x10000 },
    [FILE_SYSTEM_A001671_000] = { { itob(22), itob(19), itob(72), 0 }, 0x10000 },
    [FILE_SYSTEM_A001672_000] = { { itob(22), itob(20), itob(29), 0 }, 0x10000 },
    [FILE_SYSTEM_A001690_000] = { { itob(22), itob(20), itob(61), 0 }, 0x10000 },
    [FILE_SYSTEM_A001691_000] = { { itob(22), itob(21), itob(18), 0 }, 0x10000 },
    [FILE_SYSTEM_A001710_000] = { { itob(22), itob(21), itob(50), 0 }, 0x10000 },
    [FILE_SYSTEM_A001711_000] = { { itob(22), itob(22), itob(7), 0 }, 0x10000 },
    [FILE_SYSTEM_A001730_000] = { { itob(22), itob(22), itob(39), 0 }, 0x10000 },
    [FILE_SYSTEM_A001731_000] = { { itob(22), itob(22), itob(71), 0 }, 0x10000 },
    [FILE_SYSTEM_A001732_000] = { { itob(22), itob(23), itob(28), 0 }, 0x10000 },
    [FILE_SYSTEM_A00175_000] = { { itob(22), itob(26), itob(11), 0 }, 0x28000 },
    [FILE_SYSTEM_A00176_000] = { { itob(22), itob(31), itob(4), 0 }, 0x10000 },
    [FILE_SYSTEM_X18_BIN] = { { itob(23), itob(25), itob(55), 0 }, 0x34D80 },
    [FILE_SYSTEM_A001790_000] = { { itob(22), itob(35), itob(24), 0 }, 0x10000 },
    [FILE_SYSTEM_A001791_000] = { { itob(22), itob(35), itob(56), 0 }, 0x10000 },
    [FILE_SYSTEM_A001792_000] = { { itob(22), itob(36), itob(13), 0 }, 0x8000 },
    [FILE_SYSTEM_A001810_000] = { { itob(22), itob(36), itob(29), 0 }, 0x30000 },
    [FILE_SYSTEM_A001820_000] = { { itob(22), itob(37), itob(50), 0 }, 0x20000 },
    [FILE_SYSTEM_A001830_000] = { { itob(22), itob(38), itob(39), 0 }, 0x8000 },
    [FILE_SYSTEM_A001831_000] = { { itob(22), itob(38), itob(55), 0 }, 0x8000 },
    [FILE_SYSTEM_A001850_000] = { { itob(22), itob(38), itob(71), 0 }, 0x10000 },
    [FILE_SYSTEM_A001851_000] = { { itob(22), itob(39), itob(28), 0 }, 0x10000 },
    [FILE_SYSTEM_A001852_000] = { { itob(22), itob(39), itob(60), 0 }, 0x10000 },
    [FILE_SYSTEM_A001860_000] = { { itob(22), itob(40), itob(17), 0 }, 0x8000 },
    [FILE_SYSTEM_GOVER_BIN] = { { itob(22), itob(57), itob(70), 0 }, 0xCAC },
    [FILE_SYSTEM_G000000_000] = { { itob(22), itob(57), itob(47), 0 }, 0xB19C },
    [FILE_SYSTEM_A001900_GAM] = { { itob(22), itob(42), itob(11), 0 }, 0x1E21 },
    [FILE_SYSTEM_A001901_000] = { { itob(22), itob(42), itob(15), 0 }, 0x200 },
    [FILE_SOUND_SND_INI_WVD] = { { itob(21), itob(17), itob(42), 0 }, 0x4A6CC },
    [FILE_SOUND_SND_LOGO_WVD] = { { itob(21), itob(19), itob(41), 0 }, 0x2582C },
    [FILE_SOUND_SND_TTL_WVD] = { { itob(21), itob(20), itob(74), 0 }, 0xB7BC },
    [FILE_SOUND_S_TITLE_SEQ] = { { itob(21), itob(22), itob(57), 0 }, 0x5A1 },
    [FILE_SOUND_SND_SYS_WVD] = { { itob(21), itob(20), itob(42), 0 }, 0xFBCC },
    [FILE_SOUND_S_SYS00_SEQ] = { { itob(21), itob(22), itob(55), 0 }, 0xE10 },
    [FILE_SOUND_SND0000_WVD] = { { itob(20), itob(33), itob(60), 0 }, 0x2F564 },
    [FILE_SOUND_S_AR000_SEQ] = { { itob(21), itob(21), itob(22), 0 }, 0x2470 },
    [FILE_SOUND_SND0003_WVD] = { { itob(20), itob(35), itob(5), 0 }, 0x1E394 },
    [FILE_SOUND_S_AR003_SEQ] = { { itob(21), itob(21), itob(27), 0 }, 0xD19 },
    [FILE_SOUND_SND001__WVD] = { { itob(20), itob(37), itob(19), 0 }, 0x1F77C },
    [FILE_SOUND_S_AR010_SEQ] = { { itob(21), itob(21), itob(29), 0 }, 0x1036 },
    [FILE_SOUND_SND0020_WVD] = { { itob(20), itob(38), itob(49), 0 }, 0x16994 },
    [FILE_SOUND_S_AR020_SEQ] = { { itob(21), itob(21), itob(36), 0 }, 0xF96 },
    [FILE_SOUND_SND0023_WVD] = { { itob(20), itob(39), itob(20), 0 }, 0x15E04 },
    [FILE_SOUND_S_AR023_SEQ] = { { itob(21), itob(21), itob(38), 0 }, 0xCC7 },
    [FILE_SOUND_SND0030_WVD] = { { itob(20), itob(39), itob(64), 0 }, 0x319A4 },
    [FILE_SOUND_S_AR030_SEQ] = { { itob(21), itob(21), itob(40), 0 }, 0x22D0 },
    [FILE_SOUND_SND0030X_WVD] = { { itob(20), itob(41), itob(14), 0 }, 0x22CF4 },
    [FILE_SOUND_S_AR030X_SEQ] = { { itob(21), itob(21), itob(45), 0 }, 0x11CD },
    [FILE_SOUND_SND0032_WVD] = { { itob(20), itob(42), itob(9), 0 }, 0x24A04 },
    [FILE_SOUND_S_AR032_SEQ] = { { itob(21), itob(21), itob(48), 0 }, 0x7FF },
    [FILE_SOUND_SND0032X_WVD] = { { itob(20), itob(43), itob(8), 0 }, 0x1E6A4 },
    [FILE_SOUND_S_AR032X_SEQ] = { { itob(21), itob(21), itob(49), 0 }, 0xBA6 },
    [FILE_SOUND_SND0040_WVD] = { { itob(20), itob(43), itob(69), 0 }, 0x2DEC4 },
    [FILE_SOUND_S_AR040_SEQ] = { { itob(21), itob(21), itob(51), 0 }, 0x1630 },
    [FILE_SOUND_SND0044_WVD] = { { itob(20), itob(45), itob(63), 0 }, 0x2F504 },
    [FILE_SOUND_S_AR044_SEQ] = { { itob(21), itob(21), itob(58), 0 }, 0xF04 },
    [FILE_SOUND_SND0050_WVD] = { { itob(20), itob(48), itob(42), 0 }, 0x1918C },
    [FILE_SOUND_S_AR050_SEQ] = { { itob(21), itob(21), itob(60), 0 }, 0xB03 },
    [FILE_SOUND_SND0060_WVD] = { { itob(20), itob(49), itob(18), 0 }, 0x2ABA4 },
    [FILE_SOUND_S_AR060_SEQ] = { { itob(21), itob(21), itob(62), 0 }, 0x2801 },
    [FILE_SOUND_SND0062_WVD] = { { itob(20), itob(50), itob(29), 0 }, 0x17A8C },
    [FILE_SOUND_S_AR062_SEQ] = { { itob(21), itob(21), itob(68), 0 }, 0xA94 },
    [FILE_SOUND_SND001_X_WVD] = { { itob(20), itob(38), itob(7), 0 }, 0x14EDC },
    [FILE_SOUND_S_AR010X_SEQ] = { { itob(21), itob(21), itob(32), 0 }, 0x1945 },
    [FILE_SOUND_SND0080_WVD] = { { itob(20), itob(51), itob(2), 0 }, 0x26064 },
    [FILE_SOUND_S_AR080_SEQ] = { { itob(21), itob(21), itob(70), 0 }, 0x72F },
    [FILE_SOUND_SND0090_WVD] = { { itob(20), itob(52), itob(4), 0 }, 0x2E8E4 },
    [FILE_SOUND_S_AR090_SEQ] = { { itob(21), itob(21), itob(71), 0 }, 0x19EB },
    [FILE_SOUND_SND0091_WVD] = { { itob(20), itob(53), itob(23), 0 }, 0x176BC },
    [FILE_SOUND_S_AR091_SEQ] = { { itob(21), itob(22), itob(0), 0 }, 0x125E },
    [FILE_SOUND_SND0096_WVD] = { { itob(20), itob(53), itob(70), 0 }, 0x14D0C },
    [FILE_SOUND_S_AR096_SEQ] = { { itob(21), itob(22), itob(3), 0 }, 0x84B },
    [FILE_SOUND_SND010__WVD] = { { itob(20), itob(58), itob(41), 0 }, 0x1C25C },
    [FILE_SOUND_S_AR100_SEQ] = { { itob(21), itob(22), itob(5), 0 }, 0x1F61 },
    [FILE_SOUND_SND0103_WVD] = { { itob(20), itob(55), itob(69), 0 }, 0x2A9F4 },
    [FILE_SOUND_S_AR103_SEQ] = { { itob(21), itob(22), itob(14), 0 }, 0x89F },
    [FILE_SOUND_SND010_X_WVD] = { { itob(20), itob(59), itob(23), 0 }, 0x1583C },
    [FILE_SOUND_S_AR100X_SEQ] = { { itob(21), itob(22), itob(9), 0 }, 0x264E },
    [FILE_SOUND_SND0103X_WVD] = { { itob(20), itob(57), itob(5), 0 }, 0x37304 },
    [FILE_SOUND_S_AR103X_SEQ] = { { itob(21), itob(22), itob(16), 0 }, 0xD95 },
    [FILE_SOUND_SND0110_WVD] = { { itob(20), itob(59), itob(67), 0 }, 0x1174C },
    [FILE_SOUND_S_AR110_SEQ] = { { itob(21), itob(22), itob(18), 0 }, 0x2128 },
    [FILE_SOUND_SND004_X_WVD] = { { itob(20), itob(47), itob(68), 0 }, 0x1805C },
    [FILE_SOUND_S_AR040X_SEQ] = { { itob(21), itob(21), itob(54), 0 }, 0x1AFB },
    [FILE_SOUND_SND0130_WVD] = { { itob(21), itob(0), itob(27), 0 }, 0x1FF34 },
    [FILE_SOUND_S_AR130_SEQ] = { { itob(21), itob(22), itob(23), 0 }, 0x13A6 },
    [FILE_SOUND_SND_END_WVD] = { { itob(21), itob(17), itob(5), 0 }, 0x1242C },
    [FILE_SOUND_S_END_SEQ] = { { itob(21), itob(22), itob(52), 0 }, 0x17DB },
    [FILE_SOUND_SND0140_WVD] = { { itob(21), itob(1), itob(16), 0 }, 0x30B14 },
    [FILE_SOUND_S_AR140_SEQ] = { { itob(21), itob(22), itob(26), 0 }, 0x1BD7 },
    [FILE_SOUND_SND0141_WVD] = { { itob(21), itob(2), itob(39), 0 }, 0x2C9F4 },
    [FILE_SOUND_SND0142_WVD] = { { itob(21), itob(3), itob(54), 0 }, 0x30014 },
    [FILE_SOUND_SND0143_WVD] = { { itob(21), itob(5), itob(1), 0 }, 0x2BFD4 },
    [FILE_SOUND_SND0144_WVD] = { { itob(21), itob(6), itob(14), 0 }, 0x296D4 },
    [FILE_SOUND_SND0145_WVD] = { { itob(21), itob(7), itob(22), 0 }, 0x2A7D4 },
    [FILE_SOUND_SND0146_WVD] = { { itob(21), itob(8), itob(32), 0 }, 0x350E4 },
    [FILE_SOUND_SND0147_WVD] = { { itob(21), itob(9), itob(64), 0 }, 0x36344 },
    [FILE_SOUND_S_AR147_SEQ] = { { itob(21), itob(22), itob(30), 0 }, 0x349F },
    [FILE_SOUND_SND0160_WVD] = { { itob(21), itob(11), itob(23), 0 }, 0x2D8C4 },
    [FILE_SOUND_S_AR160_SEQ] = { { itob(21), itob(22), itob(37), 0 }, 0x107F },
    [FILE_SOUND_SND0170_WVD] = { { itob(21), itob(12), itob(40), 0 }, 0x34D34 },
    [FILE_SOUND_S_AR170_SEQ] = { { itob(21), itob(22), itob(40), 0 }, 0x193E },
    [FILE_SOUND_SND0181_WVD] = { { itob(21), itob(13), itob(71), 0 }, 0x32D84 },
    [FILE_SOUND_S_AR181_SEQ] = { { itob(21), itob(22), itob(46), 0 }, 0x22AF },
    [FILE_SOUND_SND0182_WVD] = { { itob(21), itob(15), itob(23), 0 }, 0x2F0C4 },
    [FILE_SOUND_S_AR1802_SEQ] = { { itob(21), itob(22), itob(44), 0 }, 0xAE0 },
    [FILE_SOUND_SND0192_WVD] = { { itob(21), itob(16), itob(43), 0 }, 0x12094 },
    [FILE_SOUND_S_AR192_SEQ] = { { itob(21), itob(22), itob(51), 0 }, 0x493 },
    [FILE_SOUND_SND0010_WVD] = { { itob(20), itob(35), itob(66), 0 }, 0xC77C },
    [FILE_SOUND_SND0012_WVD] = { { itob(20), itob(36), itob(16), 0 }, 0x14DCC },
    [FILE_SOUND_SND0013_WVD] = { { itob(20), itob(36), itob(58), 0 }, 0xE30C },
    [FILE_SOUND_SND0014_WVD] = { { itob(20), itob(37), itob(12), 0 }, 0x33EC },
    [FILE_SOUND_SND0100_WVD] = { { itob(20), itob(54), itob(37), 0 }, 0x1AF2C },
    [FILE_SOUND_SND0101_WVD] = { { itob(20), itob(55), itob(16), 0 }, 0x1A2DC },
    [FILE_SOUND_SND0040X_WVD] = { { itob(20), itob(45), itob(11), 0 }, 0x19F5C },
    [FILE_SOUND_SND0044X_WVD] = { { itob(20), itob(47), itob(8), 0 }, 0x1DF0C },
    [FILE_MOVIE_MIST_STR] = { { itob(15), itob(6), itob(46), 0 }, 0x70EC00 },
    [FILE_MOVIE_100US_STR] = { { itob(4), itob(57), itob(21), 0 }, 0xA6D100 },
    [FILE_MOVIE_OP_INST_STR] = { { itob(16), itob(34), itob(22), 0 }, 0x1FD4A00 },
    [FILE_MOVIE_BOY_STR] = { { itob(7), itob(1), itob(57), 0 }, 0x82E300 },
    [FILE_MOVIE_MCC_STR] = { { itob(14), itob(21), itob(45), 0 }, 0x275A00 },
    [FILE_MOVIE_NOZOITE1_STR] = { { itob(15), itob(48), itob(64), 0 }, 0x379B00 },
    [FILE_MOVIE_SORA1_STR] = { { itob(19), itob(44), itob(60), 0 }, 0x41DF00 },
    [FILE_MOVIE_SORA2_STR] = { { itob(20), itob(9), itob(33), 0 }, 0x410400 },
    [FILE_MOVIE_NOZOITE2_STR] = { { itob(16), itob(9), itob(49), 0 }, 0x41DF00 },
    [FILE_MOVIE_MILLION_STR] = { { itob(14), itob(36), itob(24), 0 }, 0x50FC00 },
    [FILE_MOVIE_HONOO2_STR] = { { itob(11), itob(20), itob(12), 0 }, 0x526900 },
    [FILE_MOVIE_BUNMEI_STR] = { { itob(7), itob(50), itob(54), 0 }, 0x50FC00 },
    [FILE_MOVIE_BUNMEI2_STR] = { { itob(8), itob(21), itob(1), 0 }, 0x39E300 },
    [FILE_MOVIE_HANA_STR] = { { itob(10), itob(49), itob(25), 0 }, 0x526900 },
    [FILE_MOVIE_ARASHI_STR] = { { itob(5), itob(59), itob(51), 0 }, 0x52FB00 },
    [FILE_MOVIE_MANTION_STR] = { { itob(13), itob(50), itob(42), 0 }, 0x52FB00 },
    [FILE_MOVIE_BAKKASU_STR] = { { itob(6), itob(30), itob(54), 0 }, 0x52FB00 },
    [FILE_MOVIE_JUNGLE_STR] = { { itob(11), itob(50), itob(74), 0 }, 0x52FB00 },
    [FILE_MOVIE_KARAKURI_STR] = { { itob(12), itob(22), itob(2), 0 }, 0x52FB00 },
    [FILE_MOVIE_MABUTA_STR] = { { itob(13), itob(8), itob(24), 0 }, 0x70EC00 },
    [FILE_MOVIE_END_US_STR] = { { itob(8), itob(42), itob(50), 0 }, 0x1529F80 },
    [FILE_MOVIE_LOGO_STR] = { { itob(12), itob(53), itob(5), 0 }, 0x28C700 },
    [FILE_AREA00_A000_GAM] = { { itob(0), itob(5), itob(73), 0 }, 0xB2 },
    [FILE_AREA00_A001_GAM] = { { itob(0), itob(5), itob(74), 0 }, 0x367C },
    [FILE_AREA00_A002_GAM] = { { itob(0), itob(6), itob(6), 0 }, 0x22E7B },
    [FILE_AREA00_A003_GAM] = { { itob(0), itob(7), itob(1), 0 }, 0x12E1A },
    [FILE_AREA00_X00_BIN] = { { itob(0), itob(20), itob(40), 0 }, 0x53F38 },
    [FILE_AREA00_A005_000] = { { itob(0), itob(7), itob(39), 0 }, 0x42CE4 },
    [FILE_AREA00_A006_GAM] = { { itob(0), itob(9), itob(23), 0 }, 0x137B9 },
    [FILE_AREA00_B000_GAM] = { { itob(0), itob(9), itob(62), 0 }, 0x24DF4 },
    [FILE_AREA00_CLUT01_GAM] = { { itob(0), itob(14), itob(60), 0 }, 0x2993 },
    [FILE_AREA00_D003_GAM] = { { itob(0), itob(15), itob(21), 0 }, 0x3200C },
    [FILE_AREA00_B100_GAM] = { { itob(0), itob(10), itob(61), 0 }, 0x24DF4 },
    [FILE_AREA00_CLUT02_GAM] = { { itob(0), itob(14), itob(66), 0 }, 0x2993 },
    [FILE_AREA00_D103_GAM] = { { itob(0), itob(16), itob(47), 0 }, 0x3200C },
    [FILE_AREA00_B200_GAM] = { { itob(0), itob(11), itob(60), 0 }, 0x24DF4 },
    [FILE_AREA00_CLUT03_GAM] = { { itob(0), itob(14), itob(72), 0 }, 0x2993 },
    [FILE_AREA00_D203_GAM] = { { itob(0), itob(17), itob(73), 0 }, 0x3200C },
    [FILE_AREA00_B300_GAM] = { { itob(0), itob(12), itob(59), 0 }, 0x63AE },
    [FILE_AREA00_B301_000] = { { itob(0), itob(12), itob(72), 0 }, 0x30000 },
    [FILE_AREA00_CLUT04_GAM] = { { itob(0), itob(15), itob(3), 0 }, 0x29E2 },
    [FILE_AREA00_D303_GAM] = { { itob(0), itob(19), itob(24), 0 }, 0x2C72 },
    [FILE_AREA00_B400_GAM] = { { itob(0), itob(14), itob(18), 0 }, 0x5DDC },
    [FILE_AREA00_B401_GAM] = { { itob(0), itob(14), itob(30), 0 }, 0x362 },
    [FILE_AREA00_CLUT05_GAM] = { { itob(0), itob(15), itob(9), 0 }, 0x2949 },
    [FILE_AREA00_D403_GAM] = { { itob(0), itob(19), itob(30), 0 }, 0x18D5A },
    [FILE_AREA00_B500_GAM] = { { itob(0), itob(14), itob(31), 0 }, 0x6270 },
    [FILE_AREA00_B501_GAM] = { { itob(0), itob(14), itob(44), 0 }, 0xD24 },
    [FILE_AREA00_B502_GAM] = { { itob(0), itob(14), itob(46), 0 }, 0x390 },
    [FILE_AREA00_B503_GAM] = { { itob(0), itob(14), itob(47), 0 }, 0x671A },
    [FILE_AREA00_CLUT06_GAM] = { { itob(0), itob(15), itob(15), 0 }, 0x2EA5 },
    [FILE_AREA00_D505_GAM] = { { itob(0), itob(20), itob(5), 0 }, 0x115A3 },
    [FILE_AREA01_A000_GAM] = { { itob(0), itob(22), itob(60), 0 }, 0xB2 },
    [FILE_AREA01_A001_GAM] = { { itob(0), itob(22), itob(61), 0 }, 0x367C },
    [FILE_AREA01_A002_GAM] = { { itob(0), itob(22), itob(68), 0 }, 0x14A51 },
    [FILE_AREA01_A003_GAM] = { { itob(0), itob(23), itob(35), 0 }, 0xEFBA },
    [FILE_AREA01_A004_GAM] = { { itob(0), itob(23), itob(65), 0 }, 0xB39A },
    [FILE_AREA01_A007_000] = { { itob(0), itob(24), itob(13), 0 }, 0x2E008 },
    [FILE_AREA01_A008_GAM] = { { itob(0), itob(25), itob(31), 0 }, 0x14D2E },
    [FILE_AREA01_X01_BIN] = { { itob(0), itob(35), itob(20), 0 }, 0x57F94 },
    [FILE_AREA01_B000_GAM] = { { itob(0), itob(25), itob(73), 0 }, 0x17AB7 },
    [FILE_AREA01_B001_GAM] = { { itob(0), itob(26), itob(46), 0 }, 0x2C37 },
    [FILE_AREA01_B002_GAM] = { { itob(0), itob(26), itob(52), 0 }, 0xC1B8 },
    [FILE_AREA01_B003_GAM] = { { itob(0), itob(27), itob(2), 0 }, 0x2D50 },
    [FILE_AREA01_CLUT01_GAM] = { { itob(0), itob(30), itob(72), 0 }, 0x2A0D },
    [FILE_AREA01_D005_GAM] = { { itob(0), itob(31), itob(27), 0 }, 0x1DE75 },
    [FILE_AREA01_B100_GAM] = { { itob(0), itob(27), itob(8), 0 }, 0x17AB7 },
    [FILE_AREA01_B101_GAM] = { { itob(0), itob(27), itob(56), 0 }, 0x2C37 },
    [FILE_AREA01_B102_GAM] = { { itob(0), itob(27), itob(62), 0 }, 0xC1B8 },
    [FILE_AREA01_B103_GAM] = { { itob(0), itob(28), itob(12), 0 }, 0x2D50 },
    [FILE_AREA01_CLUT02_GAM] = { { itob(0), itob(31), itob(3), 0 }, 0x2A0D },
    [FILE_AREA01_D105_GAM] = { { itob(0), itob(32), itob(12), 0 }, 0x1DE75 },
    [FILE_AREA01_B200_GAM] = { { itob(0), itob(28), itob(18), 0 }, 0x166D4 },
    [FILE_AREA01_B201_GAM] = { { itob(0), itob(28), itob(63), 0 }, 0x1EDC },
    [FILE_AREA01_B202_GAM] = { { itob(0), itob(28), itob(67), 0 }, 0xAC3F },
    [FILE_AREA01_CLUT03_GAM] = { { itob(0), itob(31), itob(9), 0 }, 0x2A82 },
    [FILE_AREA01_D204_GAM] = { { itob(0), itob(32), itob(72), 0 }, 0x1AB74 },
    [FILE_AREA01_B300_GAM] = { { itob(0), itob(29), itob(14), 0 }, 0x116C3 },
    [FILE_AREA01_B301_GAM] = { { itob(0), itob(29), itob(49), 0 }, 0x2C37 },
    [FILE_AREA01_B302_GAM] = { { itob(0), itob(29), itob(55), 0 }, 0x34B2 },
    [FILE_AREA01_B303_GAM] = { { itob(0), itob(29), itob(62), 0 }, 0x4F83 },
    [FILE_AREA01_B304_GAM] = { { itob(0), itob(29), itob(72), 0 }, 0x2D50 },
    [FILE_AREA01_CLUT04_GAM] = { { itob(0), itob(31), itob(15), 0 }, 0x296F },
    [FILE_AREA01_D306_GAM] = { { itob(0), itob(33), itob(51), 0 }, 0x22FB2 },
    [FILE_AREA01_B400_GAM] = { { itob(0), itob(30), itob(3), 0 }, 0x16157 },
    [FILE_AREA01_B401_GAM] = { { itob(0), itob(30), itob(48), 0 }, 0xAC3F },
    [FILE_AREA01_B402_GAM] = { { itob(0), itob(30), itob(70), 0 }, 0x9F1 },
    [FILE_AREA01_CLUT05_GAM] = { { itob(0), itob(31), itob(21), 0 }, 0x2A4E },
    [FILE_AREA01_D404_GAM] = { { itob(0), itob(34), itob(46), 0 }, 0x1877D },
    [FILE_AREA02_A000_GAM] = { { itob(0), itob(37), itob(48), 0 }, 0xB2 },
    [FILE_AREA02_A003_GAM] = { { itob(0), itob(37), itob(49), 0 }, 0x13AEF },
    [FILE_AREA02_B000_GAM] = { { itob(0), itob(38), itob(14), 0 }, 0x1252F },
    [FILE_AREA02_B001_000] = { { itob(0), itob(38), itob(51), 0 }, 0x30000 },
    [FILE_AREA02_B002_000] = { { itob(0), itob(39), itob(72), 0 }, 0x20000 },
    [FILE_AREA02_B003_000] = { { itob(0), itob(40), itob(61), 0 }, 0x8000 },
    [FILE_AREA02_CLUT01_GAM] = { { itob(0), itob(48), itob(0), 0 }, 0x156E },
    [FILE_AREA02_D005_000] = { { itob(0), itob(48), itob(20), 0 }, 0x4FC64 },
    [FILE_AREA02_D006_GAM] = { { itob(0), itob(50), itob(30), 0 }, 0x3291 },
    [FILE_AREA02_INFO_BIN] = { { itob(0), itob(57), itob(12), 0 }, 0xD3D4 },
    [FILE_AREA02_B100_GAM] = { { itob(0), itob(41), itob(2), 0 }, 0x113D3 },
    [FILE_AREA02_B101_GAM] = { { itob(0), itob(41), itob(37), 0 }, 0x1984D },
    [FILE_AREA02_B102_GAM] = { { itob(0), itob(42), itob(14), 0 }, 0x5073 },
    [FILE_AREA02_B103_000] = { { itob(0), itob(42), itob(25), 0 }, 0x8000 },
    [FILE_AREA02_B104_GAM] = { { itob(0), itob(42), itob(41), 0 }, 0x6210 },
    [FILE_AREA02_B105_GAM] = { { itob(0), itob(42), itob(54), 0 }, 0x6F32 },
    [FILE_AREA02_CLUT02_GAM] = { { itob(0), itob(48), itob(3), 0 }, 0x19BA },
    [FILE_AREA02_D107_000] = { { itob(0), itob(50), itob(37), 0 }, 0x2E008 },
    [FILE_AREA02_D108_GAM] = { { itob(0), itob(51), itob(55), 0 }, 0x2889 },
    [FILE_AREA02_D109_GAM] = { { itob(0), itob(51), itob(61), 0 }, 0x15DA },
    [FILE_AREA02_X02_BIN] = { { itob(0), itob(57), itob(59), 0 }, 0x37D0C },
    [FILE_AREA02_B200_GAM] = { { itob(0), itob(42), itob(68), 0 }, 0x16765 },
    [FILE_AREA02_B201_GAM] = { { itob(0), itob(43), itob(38), 0 }, 0x6210 },
    [FILE_AREA02_B202_GAM] = { { itob(0), itob(43), itob(51), 0 }, 0xAAD6 },
    [FILE_AREA02_CLUT03_GAM] = { { itob(0), itob(48), itob(7), 0 }, 0x15B1 },
    [FILE_AREA02_D204_000] = { { itob(0), itob(51), itob(64), 0 }, 0x2E008 },
    [FILE_AREA02_D205_GAM] = { { itob(0), itob(53), itob(7), 0 }, 0x2889 },
    [FILE_AREA02_D206_GAM] = { { itob(0), itob(53), itob(13), 0 }, 0x5EE },
    [FILE_AREA02_B300_GAM] = { { itob(0), itob(43), itob(73), 0 }, 0x9604 },
    [FILE_AREA02_B301_000] = { { itob(0), itob(44), itob(17), 0 }, 0x20000 },
    [FILE_AREA02_B302_GAM] = { { itob(0), itob(45), itob(6), 0 }, 0x34B0 },
    [FILE_AREA02_CLUT04_GAM] = { { itob(0), itob(48), itob(10), 0 }, 0x16F8 },
    [FILE_AREA02_D304_000] = { { itob(0), itob(53), itob(14), 0 }, 0x9D84 },
    [FILE_AREA02_D305_000] = { { itob(0), itob(53), itob(34), 0 }, 0xCA3C },
    [FILE_AREA02_D306_GAM] = { { itob(0), itob(53), itob(60), 0 }, 0xF6F },
    [FILE_AREA02_D307_GAM] = { { itob(0), itob(53), itob(62), 0 }, 0x175DE },
    [FILE_AREA02_INFO3_BIN] = { { itob(0), itob(57), itob(39), 0 }, 0x9898 },
    [FILE_AREA02_B400_GAM] = { { itob(0), itob(45), itob(13), 0 }, 0x16724 },
    [FILE_AREA02_B401_GAM] = { { itob(0), itob(45), itob(58), 0 }, 0x4C9A },
    [FILE_AREA02_B402_000] = { { itob(0), itob(45), itob(68), 0 }, 0x8000 },
    [FILE_AREA02_B403_GAM] = { { itob(0), itob(46), itob(9), 0 }, 0x831C },
    [FILE_AREA02_CLUT05_GAM] = { { itob(0), itob(48), itob(13), 0 }, 0x166B },
    [FILE_AREA02_D405_000] = { { itob(0), itob(54), itob(34), 0 }, 0x2E008 },
    [FILE_AREA02_D406_GAM] = { { itob(0), itob(55), itob(52), 0 }, 0x1E06 },
    [FILE_AREA02_D407_GAM] = { { itob(0), itob(55), itob(56), 0 }, 0x1330 },
    [FILE_AREA02_B500_GAM] = { { itob(0), itob(46), itob(26), 0 }, 0x1D04A },
    [FILE_AREA02_B501_GAM] = { { itob(0), itob(47), itob(10), 0 }, 0x9F41 },
    [FILE_AREA02_B502_GAM] = { { itob(0), itob(47), itob(30), 0 }, 0x221B },
    [FILE_AREA02_B503_000] = { { itob(0), itob(47), itob(35), 0 }, 0x8000 },
    [FILE_AREA02_B504_GAM] = { { itob(0), itob(47), itob(51), 0 }, 0xBEE7 },
    [FILE_AREA02_CLUT06_GAM] = { { itob(0), itob(48), itob(16), 0 }, 0x1DF5 },
    [FILE_AREA02_D506_000] = { { itob(0), itob(55), itob(59), 0 }, 0x2E008 },
    [FILE_AREA02_D507_GAM] = { { itob(0), itob(57), itob(2), 0 }, 0x49E8 },
    [FILE_AREA03_A000_GAM] = { { itob(0), itob(59), itob(23), 0 }, 0xB2 },
    [FILE_AREA03_A001_GAM] = { { itob(0), itob(59), itob(24), 0 }, 0x367C },
    [FILE_AREA03_A002_GAM] = { { itob(0), itob(59), itob(31), 0 }, 0xC566 },
    [FILE_AREA03_A003_GAM] = { { itob(0), itob(59), itob(56), 0 }, 0x2193 },
    [FILE_AREA03_A004_000] = { { itob(0), itob(59), itob(61), 0 }, 0x2E008 },
    [FILE_AREA03_A005_GAM] = { { itob(1), itob(1), itob(4), 0 }, 0x12B75 },
    [FILE_AREA03_X03_BIN] = { { itob(1), itob(15), itob(41), 0 }, 0x52A9C },
    [FILE_AREA03_B000_GAM] = { { itob(1), itob(1), itob(42), 0 }, 0x1D8CD },
    [FILE_AREA03_B001_GAM] = { { itob(1), itob(2), itob(27), 0 }, 0xE11D },
    [FILE_AREA03_B002_GAM] = { { itob(1), itob(2), itob(56), 0 }, 0x8522 },
    [FILE_AREA03_B003_GAM] = { { itob(1), itob(2), itob(73), 0 }, 0x4411 },
    [FILE_AREA03_CLUT01_GAM] = { { itob(1), itob(9), itob(9), 0 }, 0x1F25 },
    [FILE_AREA03_D006_GAM] = { { itob(1), itob(9), itob(33), 0 }, 0x32B64 },
    [FILE_AREA03_B100_GAM] = { { itob(1), itob(3), itob(7), 0 }, 0x6DE2 },
    [FILE_AREA03_B101_GAM] = { { itob(1), itob(3), itob(21), 0 }, 0x53E0 },
    [FILE_AREA03_B102_GAM] = { { itob(1), itob(3), itob(32), 0 }, 0xB7D8 },
    [FILE_AREA03_B103_GAM] = { { itob(1), itob(3), itob(55), 0 }, 0x13016 },
    [FILE_AREA03_B104_GAM] = { { itob(1), itob(4), itob(19), 0 }, 0x4411 },
    [FILE_AREA03_CLUT02_GAM] = { { itob(1), itob(9), itob(13), 0 }, 0x1E6F },
    [FILE_AREA03_D106_GAM] = { { itob(1), itob(10), itob(60), 0 }, 0x26C7C },
    [FILE_AREA03_B200_GAM] = { { itob(1), itob(4), itob(28), 0 }, 0xFCC8 },
    [FILE_AREA03_B201_GAM] = { { itob(1), itob(4), itob(60), 0 }, 0x6925 },
    [FILE_AREA03_B202_GAM] = { { itob(1), itob(4), itob(74), 0 }, 0xBF57 },
    [FILE_AREA03_B203_GAM] = { { itob(1), itob(5), itob(23), 0 }, 0x9F1 },
    [FILE_AREA03_B204_GAM] = { { itob(1), itob(5), itob(25), 0 }, 0x9C8E },
    [FILE_AREA03_B205_GAM] = { { itob(1), itob(5), itob(45), 0 }, 0x4053 },
    [FILE_AREA03_CLUT03_GAM] = { { itob(1), itob(9), itob(17), 0 }, 0x1E31 },
    [FILE_AREA03_D210_GAM] = { { itob(1), itob(11), itob(63), 0 }, 0x219B5 },
    [FILE_AREA03_B300_GAM] = { { itob(1), itob(5), itob(54), 0 }, 0x6392 },
    [FILE_AREA03_B301_GAM] = { { itob(1), itob(5), itob(67), 0 }, 0x34B0 },
    [FILE_AREA03_B302_GAM] = { { itob(1), itob(5), itob(74), 0 }, 0xC602 },
    [FILE_AREA03_B303_GAM] = { { itob(1), itob(6), itob(24), 0 }, 0x4411 },
    [FILE_AREA03_CLUT04_GAM] = { { itob(1), itob(9), itob(21), 0 }, 0x1DE7 },
    [FILE_AREA03_D308_GAM] = { { itob(1), itob(12), itob(56), 0 }, 0xE9AF },
    [FILE_AREA03_B400_GAM] = { { itob(1), itob(6), itob(33), 0 }, 0x18E04 },
    [FILE_AREA03_B4001_GAM] = { { itob(1), itob(7), itob(8), 0 }, 0xE11D },
    [FILE_AREA03_B402_GAM] = { { itob(1), itob(7), itob(37), 0 }, 0x8522 },
    [FILE_AREA03_B403_GAM] = { { itob(1), itob(7), itob(54), 0 }, 0x40E6 },
    [FILE_AREA03_CLUT05_GAM] = { { itob(1), itob(9), itob(25), 0 }, 0x1DEC },
    [FILE_AREA03_D406_GAM] = { { itob(1), itob(13), itob(11), 0 }, 0x329C0 },
    [FILE_AREA03_B500_GAM] = { { itob(1), itob(7), itob(63), 0 }, 0x6DE2 },
    [FILE_AREA03_B501_GAM] = { { itob(1), itob(8), itob(2), 0 }, 0x53E0 },
    [FILE_AREA03_B502_GAM] = { { itob(1), itob(8), itob(13), 0 }, 0xB7D8 },
    [FILE_AREA03_B503_GAM] = { { itob(1), itob(8), itob(36), 0 }, 0x13016 },
    [FILE_AREA03_B504_GAM] = { { itob(1), itob(9), itob(0), 0 }, 0x40E6 },
    [FILE_AREA03_CLUT06_GAM] = { { itob(1), itob(9), itob(29), 0 }, 0x1E7A },
    [FILE_AREA03_D506_GAM] = { { itob(1), itob(14), itob(38), 0 }, 0x26C49 },
    [FILE_AREA04_A000_GAM] = { { itob(1), itob(17), itob(60), 0 }, 0xB2 },
    [FILE_AREA04_A001_GAM] = { { itob(1), itob(17), itob(61), 0 }, 0x367C },
    [FILE_AREA04_A002_GAM] = { { itob(1), itob(17), itob(68), 0 }, 0x1112D },
    [FILE_AREA04_A004_GAM] = { { itob(1), itob(18), itob(28), 0 }, 0x1017D },
    [FILE_AREA04_A005_GAM] = { { itob(1), itob(18), itob(61), 0 }, 0x34B0 },
    [FILE_AREA04_A006_000] = { { itob(1), itob(18), itob(68), 0 }, 0x2E008 },
    [FILE_AREA04_A007_GAM] = { { itob(1), itob(20), itob(11), 0 }, 0x11FBC },
    [FILE_AREA04_X04_BIN] = { { itob(1), itob(37), itob(0), 0 }, 0x4DA90 },
    [FILE_AREA04_B000_GAM] = { { itob(1), itob(20), itob(47), 0 }, 0x12DA4 },
    [FILE_AREA04_CLUT01_GAM] = { { itob(1), itob(30), itob(6), 0 }, 0x1C1E },
    [FILE_AREA04_D003_GAM] = { { itob(1), itob(31), itob(11), 0 }, 0x1E4F0 },
    [FILE_AREA04_D004_GAM] = { { itob(1), itob(31), itob(72), 0 }, 0x9D4C },
    [FILE_AREA04_B100_GAM] = { { itob(1), itob(21), itob(10), 0 }, 0x12DA4 },
    [FILE_AREA04_CLUT02_GAM] = { { itob(1), itob(30), itob(10), 0 }, 0x1C1E },
    [FILE_AREA04_D103_GAM] = { { itob(1), itob(32), itob(17), 0 }, 0x1E4F0 },
    [FILE_AREA04_D104_GAM] = { { itob(1), itob(33), itob(3), 0 }, 0xA797 },
    [FILE_AREA04_B200_GAM] = { { itob(1), itob(21), itob(48), 0 }, 0x12DA4 },
    [FILE_AREA04_CLUT03_GAM] = { { itob(1), itob(30), itob(14), 0 }, 0x1C1E },
    [FILE_AREA04_D203_GAM] = { { itob(1), itob(33), itob(24), 0 }, 0x1CE70 },
    [FILE_AREA04_D204_GAM] = { { itob(1), itob(34), itob(7), 0 }, 0xAE87 },
    [FILE_AREA04_B300_GAM] = { { itob(1), itob(22), itob(11), 0 }, 0x12DA4 },
    [FILE_AREA04_CLUT04_GAM] = { { itob(1), itob(30), itob(18), 0 }, 0x1C1E },
    [FILE_AREA04_D303_GAM] = { { itob(1), itob(34), itob(29), 0 }, 0x1CE70 },
    [FILE_AREA04_D304_GAM] = { { itob(1), itob(35), itob(12), 0 }, 0xA43C },
    [FILE_AREA04_B400_GAM] = { { itob(1), itob(22), itob(49), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT05_GAM] = { { itob(1), itob(30), itob(22), 0 }, 0x1C24 },
    [FILE_AREA04_D403_GAM] = { { itob(1), itob(35), itob(33), 0 }, 0x3C7A },
    [FILE_AREA04_B500_GAM] = { { itob(1), itob(23), itob(30), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT06_GAM] = { { itob(1), itob(30), itob(26), 0 }, 0x1D17 },
    [FILE_AREA04_D502_GAM] = { { itob(1), itob(35), itob(41), 0 }, 0x2D6C },
    [FILE_AREA04_B600_GAM] = { { itob(1), itob(24), itob(11), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT07_GAM] = { { itob(1), itob(30), itob(30), 0 }, 0x1C24 },
    [FILE_AREA04_D603_GAM] = { { itob(1), itob(35), itob(47), 0 }, 0x5240 },
    [FILE_AREA04_B700_GAM] = { { itob(1), itob(24), itob(67), 0 }, 0x11C69 },
    [FILE_AREA04_CLUT08_GAM] = { { itob(1), itob(30), itob(34), 0 }, 0x1C51 },
    [FILE_AREA04_D702_GAM] = { { itob(1), itob(35), itob(58), 0 }, 0x5127 },
    [FILE_AREA04_B800_000] = { { itob(1), itob(25), itob(28), 0 }, 0x18000 },
    [FILE_AREA04_CLUT09_GAM] = { { itob(1), itob(30), itob(38), 0 }, 0x1BB4 },
    [FILE_AREA04_D802_GAM] = { { itob(1), itob(35), itob(69), 0 }, 0x391B },
    [FILE_AREA04_B900_GAM] = { { itob(1), itob(26), itob(1), 0 }, 0x2349 },
    [FILE_AREA04_CLUT10_GAM] = { { itob(1), itob(30), itob(42), 0 }, 0x1C78 },
    [FILE_AREA04_D901_GAM] = { { itob(1), itob(36), itob(2), 0 }, 0x3DCA },
    [FILE_AREA04_CLUT11_GAM] = { { itob(1), itob(30), itob(46), 0 }, 0x1B92 },
    [FILE_AREA04_DA01_GAM] = { { itob(1), itob(36), itob(10), 0 }, 0x2603 },
    [FILE_AREA04_BB00_GAM] = { { itob(1), itob(26), itob(6), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT12_GAM] = { { itob(1), itob(30), itob(50), 0 }, 0x1C24 },
    [FILE_AREA04_DB02_GAM] = { { itob(1), itob(36), itob(15), 0 }, 0x4A4D },
    [FILE_AREA04_BC00_GAM] = { { itob(1), itob(26), itob(62), 0 }, 0x1BD9C },
    [FILE_AREA04_BC01_GAM] = { { itob(1), itob(27), itob(43), 0 }, 0x22A6 },
    [FILE_AREA04_BC02_GAM] = { { itob(1), itob(27), itob(48), 0 }, 0x1F7B },
    [FILE_AREA04_CLUT13_GAM] = { { itob(1), itob(30), itob(54), 0 }, 0x1C3D },
    [FILE_AREA04_DC03_GAM] = { { itob(1), itob(36), itob(25), 0 }, 0x4CB7 },
    [FILE_AREA04_CLUT14_GAM] = { { itob(1), itob(30), itob(58), 0 }, 0x1B92 },
    [FILE_AREA04_DD01_GAM] = { { itob(1), itob(36), itob(35), 0 }, 0x3232 },
    [FILE_AREA04_CLUT15_GAM] = { { itob(1), itob(30), itob(62), 0 }, 0x1B92 },
    [FILE_AREA04_DE01_GAM] = { { itob(1), itob(36), itob(42), 0 }, 0x1DD0 },
    [FILE_AREA04_BF00_GAM] = { { itob(1), itob(27), itob(52), 0 }, 0x52A9 },
    [FILE_AREA04_CLUT16_GAM] = { { itob(1), itob(30), itob(66), 0 }, 0x1C13 },
    [FILE_AREA04_DF03_GAM] = { { itob(1), itob(36), itob(46), 0 }, 0x1949 },
    [FILE_AREA04_BG00_GAM] = { { itob(1), itob(27), itob(63), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT17_GAM] = { { itob(1), itob(30), itob(70), 0 }, 0x1C24 },
    [FILE_AREA04_DG03_GAM] = { { itob(1), itob(36), itob(50), 0 }, 0x3C13 },
    [FILE_AREA04_BH00_GAM] = { { itob(1), itob(28), itob(44), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT18_GAM] = { { itob(1), itob(30), itob(74), 0 }, 0x1C24 },
    [FILE_AREA04_DH02_GAM] = { { itob(1), itob(36), itob(58), 0 }, 0x2D29 },
    [FILE_AREA04_BI00_GAM] = { { itob(1), itob(29), itob(25), 0 }, 0x1BD9C },
    [FILE_AREA04_CLUT19_GAM] = { { itob(1), itob(31), itob(3), 0 }, 0x1C24 },
    [FILE_AREA04_DI02_GAM] = { { itob(1), itob(36), itob(64), 0 }, 0x2D3D },
    [FILE_AREA04_CLUT20_GAM] = { { itob(1), itob(31), itob(7), 0 }, 0x1B92 },
    [FILE_AREA04_DJ01_GAM] = { { itob(1), itob(36), itob(70), 0 }, 0x21AC },
    [FILE_AREA05_A000_GAM] = { { itob(1), itob(39), itob(8), 0 }, 0xB2 },
    [FILE_AREA05_A001_GAM] = { { itob(1), itob(39), itob(9), 0 }, 0x367C },
    [FILE_AREA05_A003_GAM] = { { itob(1), itob(39), itob(16), 0 }, 0xFB19 },
    [FILE_AREA05_B000_GAM] = { { itob(1), itob(39), itob(48), 0 }, 0x3611B },
    [FILE_AREA05_B001_GAM] = { { itob(1), itob(41), itob(7), 0 }, 0x4A44 },
    [FILE_AREA05_B002_000] = { { itob(1), itob(41), itob(17), 0 }, 0x8000 },
    [FILE_AREA05_CLUT01_GAM] = { { itob(1), itob(45), itob(46), 0 }, 0x18C0 },
    [FILE_AREA05_D002_000] = { { itob(1), itob(45), itob(62), 0 }, 0x4008 },
    [FILE_AREA05_D003_000] = { { itob(1), itob(45), itob(71), 0 }, 0x80620 },
    [FILE_AREA05_D004_000] = { { itob(1), itob(49), itob(28), 0 }, 0xCA3C },
    [FILE_AREA05_D005_GAM] = { { itob(1), itob(49), itob(54), 0 }, 0x1D12 },
    [FILE_AREA05_INFO2_BIN] = { { itob(1), itob(56), itob(33), 0 }, 0x215E0 },
    [FILE_AREA05_B100_GAM] = { { itob(1), itob(41), itob(33), 0 }, 0x5FB2 },
    [FILE_AREA05_B101_GAM] = { { itob(1), itob(41), itob(45), 0 }, 0x62D9 },
    [FILE_AREA05_B102_GAM] = { { itob(1), itob(41), itob(58), 0 }, 0x1C294 },
    [FILE_AREA05_B103_GAM] = { { itob(1), itob(42), itob(40), 0 }, 0x33A8 },
    [FILE_AREA05_CLUT02_GAM] = { { itob(1), itob(45), itob(50), 0 }, 0x1852 },
    [FILE_AREA05_D103_000] = { { itob(1), itob(49), itob(58), 0 }, 0x2E008 },
    [FILE_AREA05_D104_GAM] = { { itob(1), itob(51), itob(1), 0 }, 0x46B8 },
    [FILE_AREA05_X05_BIN] = { { itob(1), itob(57), itob(25), 0 }, 0x3276C },
    [FILE_AREA05_B200_GAM] = { { itob(1), itob(42), itob(47), 0 }, 0x3611B },
    [FILE_AREA05_B201_GAM] = { { itob(1), itob(44), itob(6), 0 }, 0x4A44 },
    [FILE_AREA05_B202_000] = { { itob(1), itob(44), itob(16), 0 }, 0x8000 },
    [FILE_AREA05_CLUT03_GAM] = { { itob(1), itob(45), itob(54), 0 }, 0x18C0 },
    [FILE_AREA05_D202_000] = { { itob(1), itob(51), itob(10), 0 }, 0x4008 },
    [FILE_AREA05_D203_000] = { { itob(1), itob(51), itob(19), 0 }, 0x80620 },
    [FILE_AREA05_D204_000] = { { itob(1), itob(54), itob(51), 0 }, 0xCA3C },
    [FILE_AREA05_D205_GAM] = { { itob(1), itob(55), itob(2), 0 }, 0x1D12 },
    [FILE_AREA05_B300_GAM] = { { itob(1), itob(44), itob(32), 0 }, 0x5FB2 },
    [FILE_AREA05_B301_GAM] = { { itob(1), itob(44), itob(44), 0 }, 0x62D9 },
    [FILE_AREA05_B302_GAM] = { { itob(1), itob(44), itob(57), 0 }, 0x1C294 },
    [FILE_AREA05_B303_GAM] = { { itob(1), itob(45), itob(39), 0 }, 0x33A8 },
    [FILE_AREA05_CLUT04_GAM] = { { itob(1), itob(45), itob(58), 0 }, 0x1852 },
    [FILE_AREA05_D303_000] = { { itob(1), itob(55), itob(6), 0 }, 0x2E008 },
    [FILE_AREA05_D304_GAM] = { { itob(1), itob(56), itob(24), 0 }, 0x46B8 },
    [FILE_AREA06_A000_GAM] = { { itob(1), itob(58), itob(52), 0 }, 0xB2 },
    [FILE_AREA06_A001_GAM] = { { itob(1), itob(58), itob(53), 0 }, 0x5631 },
    [FILE_AREA06_A002_GAM] = { { itob(1), itob(58), itob(64), 0 }, 0x17E48 },
    [FILE_AREA06_X06_BIN] = { { itob(2), itob(11), itob(74), 0 }, 0x3B15C },
    [FILE_AREA06_B000_GAM] = { { itob(1), itob(59), itob(37), 0 }, 0xAF28 },
    [FILE_AREA06_B001_GAM] = { { itob(1), itob(59), itob(59), 0 }, 0x1957 },
    [FILE_AREA06_B002_GAM] = { { itob(1), itob(59), itob(63), 0 }, 0x9985 },
    [FILE_AREA06_B003_GAM] = { { itob(2), itob(0), itob(8), 0 }, 0x9395 },
    [FILE_AREA06_CLUT01_GAM] = { { itob(2), itob(9), itob(32), 0 }, 0x196F },
    [FILE_AREA06_D006_000] = { { itob(2), itob(9), itob(42), 0 }, 0x4FDDC },
    [FILE_AREA06_D007_GAM] = { { itob(2), itob(11), itob(52), 0 }, 0xFCB },
    [FILE_AREA06_B101_000] = { { itob(2), itob(0), itob(27), 0 }, 0x38000 },
    [FILE_AREA06_B102_000] = { { itob(2), itob(1), itob(64), 0 }, 0x30000 },
    [FILE_AREA06_B103_GAM] = { { itob(2), itob(3), itob(10), 0 }, 0x34B0 },
    [FILE_AREA06_B104_000] = { { itob(2), itob(3), itob(17), 0 }, 0x10000 },
    [FILE_AREA06_CLUT02_GAM] = { { itob(2), itob(9), itob(36), 0 }, 0x1706 },
    [FILE_AREA06_B105_000] = { { itob(2), itob(3), itob(49), 0 }, 0x2E008 },
    [FILE_AREA06_D106_GAM] = { { itob(2), itob(11), itob(54), 0 }, 0x4AC5 },
    [FILE_AREA06_B201_000] = { { itob(2), itob(4), itob(67), 0 }, 0x38000 },
    [FILE_AREA06_B202_000] = { { itob(2), itob(6), itob(29), 0 }, 0x30000 },
    [FILE_AREA06_B203_GAM] = { { itob(2), itob(7), itob(50), 0 }, 0x34B0 },
    [FILE_AREA06_B204_000] = { { itob(2), itob(7), itob(57), 0 }, 0x10000 },
    [FILE_AREA06_CLUT03_GAM] = { { itob(2), itob(9), itob(39), 0 }, 0x1706 },
    [FILE_AREA06_B205_000] = { { itob(2), itob(8), itob(14), 0 }, 0x2E008 },
    [FILE_AREA06_D206_GAM] = { { itob(2), itob(11), itob(64), 0 }, 0x4AA4 },
    [FILE_AREA07_A000_GAM] = { { itob(2), itob(13), itob(45), 0 }, 0xB2 },
    [FILE_AREA07_A001_GAM] = { { itob(2), itob(13), itob(46), 0 }, 0x367C },
    [FILE_AREA07_A002_GAM] = { { itob(2), itob(13), itob(53), 0 }, 0x1512D },
    [FILE_AREA07_A003_GAM] = { { itob(2), itob(14), itob(21), 0 }, 0xEA73 },
    [FILE_AREA07_A004_GAM] = { { itob(2), itob(14), itob(51), 0 }, 0xB396 },
    [FILE_AREA07_A007_000] = { { itob(2), itob(14), itob(74), 0 }, 0x2E008 },
    [FILE_AREA07_A008_GAM] = { { itob(2), itob(16), itob(17), 0 }, 0x14D28 },
    [FILE_AREA07_X01_BIN] = { { itob(2), itob(26), itob(9), 0 }, 0x57F94 },
    [FILE_AREA07_B000_GAM] = { { itob(2), itob(16), itob(59), 0 }, 0x17AB7 },
    [FILE_AREA07_B001_GAM] = { { itob(2), itob(17), itob(32), 0 }, 0x2C37 },
    [FILE_AREA07_B002_GAM] = { { itob(2), itob(17), itob(38), 0 }, 0xC18E },
    [FILE_AREA07_B003_GAM] = { { itob(2), itob(17), itob(63), 0 }, 0x2D50 },
    [FILE_AREA07_CLUT01_GAM] = { { itob(2), itob(21), itob(58), 0 }, 0x2986 },
    [FILE_AREA07_D005_GAM] = { { itob(2), itob(22), itob(13), 0 }, 0x1E196 },
    [FILE_AREA07_B100_GAM] = { { itob(2), itob(17), itob(69), 0 }, 0x17AB7 },
    [FILE_AREA07_B101_GAM] = { { itob(2), itob(18), itob(42), 0 }, 0x2C37 },
    [FILE_AREA07_B102_GAM] = { { itob(2), itob(18), itob(48), 0 }, 0xC18E },
    [FILE_AREA07_B103_GAM] = { { itob(2), itob(18), itob(73), 0 }, 0x2D50 },
    [FILE_AREA07_CLUT02_GAM] = { { itob(2), itob(21), itob(64), 0 }, 0x2986 },
    [FILE_AREA07_D105_GAM] = { { itob(2), itob(22), itob(74), 0 }, 0x1E196 },
    [FILE_AREA07_B200_GAM] = { { itob(2), itob(19), itob(4), 0 }, 0x166D4 },
    [FILE_AREA07_B201_GAM] = { { itob(2), itob(19), itob(49), 0 }, 0x1EDC },
    [FILE_AREA07_B202_GAM] = { { itob(2), itob(19), itob(53), 0 }, 0xACA6 },
    [FILE_AREA07_CLUT03_GAM] = { { itob(2), itob(21), itob(70), 0 }, 0x29FF },
    [FILE_AREA07_D204_GAM] = { { itob(2), itob(23), itob(60), 0 }, 0x1AB83 },
    [FILE_AREA07_B300_GAM] = { { itob(2), itob(20), itob(0), 0 }, 0x116C3 },
    [FILE_AREA07_B301_GAM] = { { itob(2), itob(20), itob(35), 0 }, 0x2C37 },
    [FILE_AREA07_B302_GAM] = { { itob(2), itob(20), itob(41), 0 }, 0x328F },
    [FILE_AREA07_B303_GAM] = { { itob(2), itob(20), itob(48), 0 }, 0x4F83 },
    [FILE_AREA07_B304_GAM] = { { itob(2), itob(20), itob(58), 0 }, 0x2D50 },
    [FILE_AREA07_CLUT04_GAM] = { { itob(2), itob(22), itob(1), 0 }, 0x28E3 },
    [FILE_AREA07_D306_GAM] = { { itob(2), itob(24), itob(39), 0 }, 0x23083 },
    [FILE_AREA07_B400_GAM] = { { itob(2), itob(20), itob(64), 0 }, 0x16157 },
    [FILE_AREA07_B401_GAM] = { { itob(2), itob(21), itob(34), 0 }, 0xACA6 },
    [FILE_AREA07_B402_GAM] = { { itob(2), itob(21), itob(56), 0 }, 0x9F1 },
    [FILE_AREA07_CLUT05_GAM] = { { itob(2), itob(22), itob(7), 0 }, 0x29CA },
    [FILE_AREA07_D404_GAM] = { { itob(2), itob(25), itob(35), 0 }, 0x18756 },
    [FILE_AREA08_A000_GAM] = { { itob(2), itob(28), itob(36), 0 }, 0xB2 },
    [FILE_AREA08_A001_GAM] = { { itob(2), itob(28), itob(37), 0 }, 0x367C },
    [FILE_AREA08_A003_GAM] = { { itob(2), itob(28), itob(44), 0 }, 0xC08C },
    [FILE_AREA08_B000_GAM] = { { itob(2), itob(28), itob(69), 0 }, 0x9A08 },
    [FILE_AREA08_B001_GAM] = { { itob(2), itob(29), itob(14), 0 }, 0x23C6 },
    [FILE_AREA08_CLUT01_GAM] = { { itob(2), itob(31), itob(26), 0 }, 0x161B },
    [FILE_AREA08_D002_000] = { { itob(2), itob(31), itob(38), 0 }, 0x4C464 },
    [FILE_AREA08_D003_GAM] = { { itob(2), itob(33), itob(41), 0 }, 0x3EE4 },
    [FILE_AREA08_INFO2_BIN] = { { itob(2), itob(38), itob(33), 0 }, 0x215E0 },
    [FILE_AREA08_B100_GAM] = { { itob(2), itob(29), itob(19), 0 }, 0x163D0 },
    [FILE_AREA08_B101_GAM] = { { itob(2), itob(29), itob(64), 0 }, 0x36EA },
    [FILE_AREA08_B102_GAM] = { { itob(2), itob(29), itob(71), 0 }, 0x6925 },
    [FILE_AREA08_CLUT02_GAM] = { { itob(2), itob(31), itob(29), 0 }, 0x15ED },
    [FILE_AREA08_D103_000] = { { itob(2), itob(33), itob(49), 0 }, 0x2E008 },
    [FILE_AREA08_D104_GAM] = { { itob(2), itob(34), itob(67), 0 }, 0x2D0C },
    [FILE_AREA08_X08_BIN] = { { itob(2), itob(39), itob(25), 0 }, 0x305E0 },
    [FILE_AREA08_B200_GAM] = { { itob(2), itob(30), itob(10), 0 }, 0x9A08 },
    [FILE_AREA08_B201_GAM] = { { itob(2), itob(30), itob(30), 0 }, 0x23C6 },
    [FILE_AREA08_CLUT03_GAM] = { { itob(2), itob(31), itob(32), 0 }, 0x161B },
    [FILE_AREA08_D202_000] = { { itob(2), itob(34), itob(73), 0 }, 0x4C464 },
    [FILE_AREA08_D203_GAM] = { { itob(2), itob(37), itob(1), 0 }, 0x3EE4 },
    [FILE_AREA08_B300_GAM] = { { itob(2), itob(30), itob(35), 0 }, 0x163D0 },
    [FILE_AREA08_B301_GAM] = { { itob(2), itob(31), itob(5), 0 }, 0x36EA },
    [FILE_AREA08_B302_GAM] = { { itob(2), itob(31), itob(12), 0 }, 0x6925 },
    [FILE_AREA08_CLUT04_GAM] = { { itob(2), itob(31), itob(35), 0 }, 0x15ED },
    [FILE_AREA08_D303_000] = { { itob(2), itob(37), itob(9), 0 }, 0x2E008 },
    [FILE_AREA08_D304_GAM] = { { itob(2), itob(38), itob(27), 0 }, 0x2D0C },
    [FILE_AREA09_A000_GAM] = { { itob(2), itob(40), itob(49), 0 }, 0xB2 },
    [FILE_AREA09_A001_GAM] = { { itob(2), itob(40), itob(50), 0 }, 0x367C },
    [FILE_AREA09_A002_000] = { { itob(2), itob(40), itob(57), 0 }, 0x2E008 },
    [FILE_AREA09_A003_GAM] = { { itob(2), itob(42), itob(0), 0 }, 0xF179 },
    [FILE_AREA09_X09_BIN] = { { itob(2), itob(53), itob(39), 0 }, 0x49238 },
    [FILE_AREA09_B000_GAM] = { { itob(2), itob(42), itob(31), 0 }, 0x1A823 },
    [FILE_AREA09_B001_GAM] = { { itob(2), itob(43), itob(10), 0 }, 0x17096 },
    [FILE_AREA09_B004_GAM] = { { itob(2), itob(43), itob(57), 0 }, 0x1568B },
    [FILE_AREA09_B005_GAM] = { { itob(2), itob(44), itob(25), 0 }, 0x13D4B },
    [FILE_AREA09_CLUT01_GAM] = { { itob(2), itob(51), itob(16), 0 }, 0x29E9 },
    [FILE_AREA09_D006_GAM] = { { itob(2), itob(51), itob(41), 0 }, 0x3471B },
    [FILE_AREA09_B100_GAM] = { { itob(2), itob(44), itob(65), 0 }, 0x2D6B0 },
    [FILE_AREA09_B101_GAM] = { { itob(2), itob(46), itob(6), 0 }, 0x12A1A },
    [FILE_AREA09_B102_GAM] = { { itob(2), itob(46), itob(44), 0 }, 0x14234 },
    [FILE_AREA09_B103_GAM] = { { itob(2), itob(47), itob(10), 0 }, 0x154C },
    [FILE_AREA09_B104_GAM] = { { itob(2), itob(47), itob(13), 0 }, 0xB314 },
    [FILE_AREA09_B105_GAM] = { { itob(2), itob(47), itob(36), 0 }, 0x34B0 },
    [FILE_AREA09_CLUT02_GAM] = { { itob(2), itob(51), itob(22), 0 }, 0x1877 },
    [FILE_AREA09_D106_GAM] = { { itob(2), itob(52), itob(71), 0 }, 0xEA7 },
    [FILE_AREA09_B200_GAM] = { { itob(2), itob(47), itob(43), 0 }, 0x25501 },
    [FILE_AREA09_B201_GAM] = { { itob(2), itob(48), itob(43), 0 }, 0x2290 },
    [FILE_AREA09_B202_GAM] = { { itob(2), itob(48), itob(48), 0 }, 0x42E6 },
    [FILE_AREA09_CLUT03_GAM] = { { itob(2), itob(51), itob(26), 0 }, 0x1525 },
    [FILE_AREA09_D203_GAM] = { { itob(2), itob(52), itob(73), 0 }, 0xF2C },
    [FILE_AREA09_B300_GAM] = { { itob(2), itob(48), itob(57), 0 }, 0x16386 },
    [FILE_AREA09_B301_GAM] = { { itob(2), itob(49), itob(27), 0 }, 0x5FB2 },
    [FILE_AREA09_CLUT04_GAM] = { { itob(2), itob(51), itob(29), 0 }, 0x15B7 },
    [FILE_AREA09_D302_GAM] = { { itob(2), itob(53), itob(0), 0 }, 0x19E4 },
    [FILE_AREA09_B400_GAM] = { { itob(2), itob(49), itob(39), 0 }, 0x1634D },
    [FILE_AREA09_B401_GAM] = { { itob(2), itob(50), itob(9), 0 }, 0x34B0 },
    [FILE_AREA09_CLUT05_GAM] = { { itob(2), itob(51), itob(32), 0 }, 0x14C1 },
    [FILE_AREA09_D401_GAM] = { { itob(2), itob(53), itob(4), 0 }, 0x995 },
    [FILE_AREA09_B500_GAM] = { { itob(2), itob(50), itob(16), 0 }, 0x164DA },
    [FILE_AREA09_B501_GAM] = { { itob(2), itob(50), itob(61), 0 }, 0x34B0 },
    [FILE_AREA09_CLUT06_GAM] = { { itob(2), itob(51), itob(35), 0 }, 0x14C1 },
    [FILE_AREA09_D501_GAM] = { { itob(2), itob(53), itob(6), 0 }, 0x1027 },
    [FILE_AREA09_B600_GAM] = { { itob(2), itob(50), itob(68), 0 }, 0x5DDC },
    [FILE_AREA09_B601_GAM] = { { itob(2), itob(51), itob(5), 0 }, 0x35B5 },
    [FILE_AREA09_B602_GAM] = { { itob(2), itob(51), itob(12), 0 }, 0x1BBF },
    [FILE_AREA09_CLUT07_GAM] = { { itob(2), itob(51), itob(38), 0 }, 0x12CA },
    [FILE_AREA09_D603_GAM] = { { itob(2), itob(53), itob(9), 0 }, 0xED41 },
    [FILE_AREA10_A000_GAM] = { { itob(2), itob(55), itob(38), 0 }, 0xB2 },
    [FILE_AREA10_A001_GAM] = { { itob(2), itob(55), itob(39), 0 }, 0x367C },
    [FILE_AREA10_A002_000] = { { itob(2), itob(55), itob(46), 0 }, 0x2E008 },
    [FILE_AREA10_A003_GAM] = { { itob(2), itob(56), itob(64), 0 }, 0x14779 },
    [FILE_AREA10_X10_BIN] = { { itob(3), itob(14), itob(36), 0 }, 0x4AE78 },
    [FILE_AREA10_B000_GAM] = { { itob(2), itob(57), itob(30), 0 }, 0x7E21 },
    [FILE_AREA10_B001_GAM] = { { itob(2), itob(57), itob(46), 0 }, 0xE13 },
    [FILE_AREA10_B002_GAM] = { { itob(2), itob(57), itob(48), 0 }, 0x12CC1 },
    [FILE_AREA10_B003_GAM] = { { itob(2), itob(58), itob(11), 0 }, 0x1632F },
    [FILE_AREA10_B004_GAM] = { { itob(2), itob(58), itob(56), 0 }, 0x10481 },
    [FILE_AREA10_CLUT01_GAM] = { { itob(3), itob(9), itob(38), 0 }, 0x234E },
    [FILE_AREA10_D005_GAM] = { { itob(3), itob(10), itob(4), 0 }, 0x1988B },
    [FILE_AREA10_B100_GAM] = { { itob(2), itob(59), itob(14), 0 }, 0x34B0 },
    [FILE_AREA10_B101_GAM] = { { itob(2), itob(59), itob(21), 0 }, 0xE13 },
    [FILE_AREA10_B102_GAM] = { { itob(2), itob(59), itob(23), 0 }, 0xD927 },
    [FILE_AREA10_B103_GAM] = { { itob(2), itob(59), itob(51), 0 }, 0x5957 },
    [FILE_AREA10_B104_GAM] = { { itob(2), itob(59), itob(63), 0 }, 0x10481 },
    [FILE_AREA10_CLUT02_GAM] = { { itob(3), itob(9), itob(43), 0 }, 0x1D68 },
    [FILE_AREA10_D105_GAM] = { { itob(3), itob(10), itob(56), 0 }, 0x6D7A },
    [FILE_AREA10_B200_GAM] = { { itob(3), itob(0), itob(21), 0 }, 0xD97F },
    [FILE_AREA10_B201_GAM] = { { itob(3), itob(0), itob(49), 0 }, 0x7B16 },
    [FILE_AREA10_B203_GAM] = { { itob(3), itob(0), itob(65), 0 }, 0x15601 },
    [FILE_AREA10_B204_GAM] = { { itob(3), itob(1), itob(33), 0 }, 0x10481 },
    [FILE_AREA10_CLUT03_GAM] = { { itob(3), itob(9), itob(47), 0 }, 0x212C },
    [FILE_AREA10_D205_GAM] = { { itob(3), itob(10), itob(70), 0 }, 0xFA06 },
    [FILE_AREA10_B300_GAM] = { { itob(3), itob(1), itob(66), 0 }, 0xF3EA },
    [FILE_AREA10_B302_GAM] = { { itob(3), itob(2), itob(22), 0 }, 0xD08C },
    [FILE_AREA10_B304_GAM] = { { itob(3), itob(2), itob(49), 0 }, 0x10481 },
    [FILE_AREA10_CLUT04_GAM] = { { itob(3), itob(9), itob(52), 0 }, 0x2262 },
    [FILE_AREA10_D305_GAM] = { { itob(3), itob(11), itob(27), 0 }, 0x234DF },
    [FILE_AREA10_B400_GAM] = { { itob(3), itob(3), itob(7), 0 }, 0x7E21 },
    [FILE_AREA10_B401_GAM] = { { itob(3), itob(3), itob(23), 0 }, 0xE13 },
    [FILE_AREA10_B402_GAM] = { { itob(3), itob(3), itob(25), 0 }, 0xAEBD },
    [FILE_AREA10_B403_GAM] = { { itob(3), itob(3), itob(47), 0 }, 0x1E07A },
    [FILE_AREA10_B405_GAM] = { { itob(3), itob(4), itob(33), 0 }, 0x10495 },
    [FILE_AREA10_CLUT05_GAM] = { { itob(3), itob(9), itob(57), 0 }, 0x22AF },
    [FILE_AREA10_D406_GAM] = { { itob(3), itob(12), itob(23), 0 }, 0x1900B },
    [FILE_AREA10_B500_GAM] = { { itob(3), itob(4), itob(66), 0 }, 0x34B0 },
    [FILE_AREA10_B501_GAM] = { { itob(3), itob(4), itob(73), 0 }, 0xE13 },
    [FILE_AREA10_B502_GAM] = { { itob(3), itob(5), itob(0), 0 }, 0xD929 },
    [FILE_AREA10_B503_GAM] = { { itob(3), itob(5), itob(28), 0 }, 0x5A0A },
    [FILE_AREA10_B504_GAM] = { { itob(3), itob(5), itob(40), 0 }, 0x10495 },
    [FILE_AREA10_CLUT06_GAM] = { { itob(3), itob(9), itob(62), 0 }, 0x1D58 },
    [FILE_AREA10_D505_GAM] = { { itob(3), itob(12), itob(74), 0 }, 0x6CB6 },
    [FILE_AREA10_B600_GAM] = { { itob(3), itob(5), itob(73), 0 }, 0xD97F },
    [FILE_AREA10_B601_GAM] = { { itob(3), itob(6), itob(26), 0 }, 0x7B16 },
    [FILE_AREA10_B603_GAM] = { { itob(3), itob(6), itob(42), 0 }, 0x1563F },
    [FILE_AREA10_B604_GAM] = { { itob(3), itob(7), itob(10), 0 }, 0x10495 },
    [FILE_AREA10_CLUT07_GAM] = { { itob(3), itob(9), itob(66), 0 }, 0x2121 },
    [FILE_AREA10_D605_GAM] = { { itob(3), itob(13), itob(13), 0 }, 0xFA06 },
    [FILE_AREA10_B700_GAM] = { { itob(3), itob(7), itob(43), 0 }, 0xF3EA },
    [FILE_AREA10_B702_GAM] = { { itob(3), itob(7), itob(74), 0 }, 0xD08C },
    [FILE_AREA10_B704_GAM] = { { itob(3), itob(8), itob(26), 0 }, 0x10495 },
    [FILE_AREA10_CLUT08_GAM] = { { itob(3), itob(9), itob(71), 0 }, 0x226F },
    [FILE_AREA10_D705_GAM] = { { itob(3), itob(13), itob(45), 0 }, 0x1FF3B },
    [FILE_AREA10_B800_GAM] = { { itob(3), itob(8), itob(59), 0 }, 0x3723 },
    [FILE_AREA10_B801_GAM] = { { itob(3), itob(8), itob(66), 0 }, 0x13B54 },
    [FILE_AREA10_B802_GAM] = { { itob(3), itob(9), itob(31), 0 }, 0x34B0 },
    [FILE_AREA10_CLUT09_GAM] = { { itob(3), itob(10), itob(1), 0 }, 0x15E7 },
    [FILE_AREA10_D803_GAM] = { { itob(3), itob(14), itob(34), 0 }, 0xC9B },
    [FILE_AREA11_A000_GAM] = { { itob(3), itob(16), itob(37), 0 }, 0xB2 },
    [FILE_AREA11_A001_GAM] = { { itob(3), itob(16), itob(38), 0 }, 0x367C },
    [FILE_AREA11_A002_GAM] = { { itob(3), itob(16), itob(45), 0 }, 0xE3FD },
    [FILE_AREA11_B100_GAM] = { { itob(3), itob(16), itob(74), 0 }, 0xC019 },
    [FILE_AREA11_B101_GAM] = { { itob(3), itob(17), itob(24), 0 }, 0x9C62 },
    [FILE_AREA11_B102_000] = { { itob(3), itob(17), itob(44), 0 }, 0x20000 },
    [FILE_AREA11_CLUT02_GAM] = { { itob(3), itob(19), itob(13), 0 }, 0x1CD0 },
    [FILE_AREA11_D103_000] = { { itob(3), itob(19), itob(26), 0 }, 0x2E008 },
    [FILE_AREA11_D104_GAM] = { { itob(3), itob(20), itob(44), 0 }, 0xD622 },
    [FILE_AREA11_X11_BIN] = { { itob(3), itob(23), itob(12), 0 }, 0x346D4 },
    [FILE_AREA11_B200_GAM] = { { itob(3), itob(18), itob(33), 0 }, 0x161FA },
    [FILE_AREA11_B201_GAM] = { { itob(3), itob(19), itob(3), 0 }, 0x34B0 },
    [FILE_AREA11_CLUT03_GAM] = { { itob(3), itob(19), itob(17), 0 }, 0x158F },
    [FILE_AREA11_D202_000] = { { itob(3), itob(20), itob(71), 0 }, 0x2E008 },
    [FILE_AREA11_D203_GAM] = { { itob(3), itob(22), itob(14), 0 }, 0x1E06 },
    [FILE_AREA11_D204_GAM] = { { itob(3), itob(22), itob(18), 0 }, 0xF0B },
    [FILE_AREA12_A000_GAM] = { { itob(3), itob(24), itob(45), 0 }, 0xB2 },
    [FILE_AREA12_A001_GAM] = { { itob(3), itob(24), itob(46), 0 }, 0x367C },
    [FILE_AREA12_A003_GAM] = { { itob(3), itob(24), itob(53), 0 }, 0x10A88 },
    [FILE_AREA12_A004_GAM] = { { itob(3), itob(25), itob(12), 0 }, 0xFFE7 },
    [FILE_AREA12_A005_GAM] = { { itob(3), itob(25), itob(44), 0 }, 0x34B0 },
    [FILE_AREA12_A006_000] = { { itob(3), itob(25), itob(51), 0 }, 0x2E008 },
    [FILE_AREA12_A007_GAM] = { { itob(3), itob(26), itob(69), 0 }, 0x11FDD },
    [FILE_AREA12_X04_BIN] = { { itob(3), itob(40), itob(59), 0 }, 0x4DA90 },
    [FILE_AREA12_B000_GAM] = { { itob(3), itob(27), itob(30), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT01_GAM] = { { itob(3), itob(34), itob(10), 0 }, 0x1C31 },
    [FILE_AREA12_D003_GAM] = { { itob(3), itob(35), itob(15), 0 }, 0x1DF8B },
    [FILE_AREA12_D004_GAM] = { { itob(3), itob(36), itob(0), 0 }, 0x955A },
    [FILE_AREA12_B100_GAM] = { { itob(3), itob(27), itob(66), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT02_GAM] = { { itob(3), itob(34), itob(14), 0 }, 0x1C31 },
    [FILE_AREA12_D103_GAM] = { { itob(3), itob(36), itob(19), 0 }, 0x1DF8B },
    [FILE_AREA12_D104_GAM] = { { itob(3), itob(37), itob(4), 0 }, 0x955A },
    [FILE_AREA12_B200_GAM] = { { itob(3), itob(28), itob(27), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT03_GAM] = { { itob(3), itob(34), itob(18), 0 }, 0x1C31 },
    [FILE_AREA12_D203_GAM] = { { itob(3), itob(37), itob(23), 0 }, 0x1C8A8 },
    [FILE_AREA12_D204_GAM] = { { itob(3), itob(38), itob(6), 0 }, 0x9C04 },
    [FILE_AREA12_B300_GAM] = { { itob(3), itob(28), itob(63), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT04_GAM] = { { itob(3), itob(34), itob(22), 0 }, 0x1C31 },
    [FILE_AREA12_D303_GAM] = { { itob(3), itob(38), itob(26), 0 }, 0x1C8A8 },
    [FILE_AREA12_D304_GAM] = { { itob(3), itob(39), itob(9), 0 }, 0x9C04 },
    [FILE_AREA12_B400_GAM] = { { itob(3), itob(29), itob(24), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT05_GAM] = { { itob(3), itob(34), itob(26), 0 }, 0x1C31 },
    [FILE_AREA12_D403_GAM] = { { itob(3), itob(39), itob(29), 0 }, 0x315F },
    [FILE_AREA12_B500_GAM] = { { itob(3), itob(29), itob(60), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT06_GAM] = { { itob(3), itob(34), itob(30), 0 }, 0x1C31 },
    [FILE_AREA12_D502_GAM] = { { itob(3), itob(39), itob(36), 0 }, 0x221C },
    [FILE_AREA12_B600_GAM] = { { itob(3), itob(30), itob(21), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT07_GAM] = { { itob(3), itob(34), itob(34), 0 }, 0x1C31 },
    [FILE_AREA12_D603_GAM] = { { itob(3), itob(39), itob(41), 0 }, 0x471F },
    [FILE_AREA12_B700_GAM] = { { itob(3), itob(30), itob(57), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT08_GAM] = { { itob(3), itob(34), itob(38), 0 }, 0x1C31 },
    [FILE_AREA12_D701_GAM] = { { itob(3), itob(39), itob(50), 0 }, 0x513F },
    [FILE_AREA12_B800_000] = { { itob(3), itob(31), itob(18), 0 }, 0x18000 },
    [FILE_AREA12_CLUT09_GAM] = { { itob(3), itob(34), itob(42), 0 }, 0x1B94 },
    [FILE_AREA12_D802_GAM] = { { itob(3), itob(39), itob(61), 0 }, 0x391B },
    [FILE_AREA12_B900_GAM] = { { itob(3), itob(31), itob(66), 0 }, 0x2349 },
    [FILE_AREA12_CLUT10_GAM] = { { itob(3), itob(34), itob(46), 0 }, 0x1C58 },
    [FILE_AREA12_D901_GAM] = { { itob(3), itob(39), itob(69), 0 }, 0x3DCA },
    [FILE_AREA12_CLUT11_GAM] = { { itob(3), itob(34), itob(50), 0 }, 0x1B72 },
    [FILE_AREA12_DA01_GAM] = { { itob(3), itob(40), itob(2), 0 }, 0x2603 },
    [FILE_AREA12_BB00_GAM] = { { itob(3), itob(31), itob(71), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT12_GAM] = { { itob(3), itob(34), itob(54), 0 }, 0x1C31 },
    [FILE_AREA12_DB02_GAM] = { { itob(3), itob(40), itob(7), 0 }, 0x3F2C },
    [FILE_AREA12_BC00_GAM] = { { itob(3), itob(32), itob(32), 0 }, 0x11C69 },
    [FILE_AREA12_BC01_GAM] = { { itob(3), itob(32), itob(68), 0 }, 0x22A6 },
    [FILE_AREA12_BC02_GAM] = { { itob(3), itob(32), itob(73), 0 }, 0x1F7B },
    [FILE_AREA12_CLUT13_GAM] = { { itob(3), itob(34), itob(58), 0 }, 0x1C49 },
    [FILE_AREA12_DC03_GAM] = { { itob(3), itob(40), itob(15), 0 }, 0x419B },
    [FILE_AREA12_CLUT14_GAM] = { { itob(3), itob(34), itob(62), 0 }, 0x1B72 },
    [FILE_AREA12_DD01_GAM] = { { itob(3), itob(40), itob(24), 0 }, 0x3232 },
    [FILE_AREA12_CLUT15_GAM] = { { itob(3), itob(34), itob(66), 0 }, 0x1B72 },
    [FILE_AREA12_DE01_GAM] = { { itob(3), itob(40), itob(31), 0 }, 0x1DD0 },
    [FILE_AREA12_BF00_GAM] = { { itob(3), itob(33), itob(2), 0 }, 0x52A9 },
    [FILE_AREA12_CLUT16_GAM] = { { itob(3), itob(34), itob(70), 0 }, 0x1BF3 },
    [FILE_AREA12_DF03_GAM] = { { itob(3), itob(40), itob(35), 0 }, 0x1949 },
    [FILE_AREA12_CLUT17_GAM] = { { itob(3), itob(34), itob(74), 0 }, 0x1B72 },
    [FILE_AREA12_DG03_GAM] = { { itob(3), itob(40), itob(39), 0 }, 0x2777 },
    [FILE_AREA12_BH00_GAM] = { { itob(3), itob(33), itob(13), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT18_GAM] = { { itob(3), itob(35), itob(3), 0 }, 0x1C31 },
    [FILE_AREA12_DH02_GAM] = { { itob(3), itob(40), itob(44), 0 }, 0x220A },
    [FILE_AREA12_BI00_GAM] = { { itob(3), itob(33), itob(49), 0 }, 0x11C69 },
    [FILE_AREA12_CLUT19_GAM] = { { itob(3), itob(35), itob(7), 0 }, 0x1C31 },
    [FILE_AREA12_DI02_GAM] = { { itob(3), itob(40), itob(49), 0 }, 0x222E },
    [FILE_AREA12_CLUT20_GAM] = { { itob(3), itob(35), itob(11), 0 }, 0x1B72 },
    [FILE_AREA12_DJ01_GAM] = { { itob(3), itob(40), itob(54), 0 }, 0x21AC },
    [FILE_AREA13_A000_GAM] = { { itob(3), itob(42), itob(66), 0 }, 0xB2 },
    [FILE_AREA13_A001_GAM] = { { itob(3), itob(42), itob(67), 0 }, 0x34B0 },
    [FILE_AREA13_A002_GAM] = { { itob(3), itob(42), itob(74), 0 }, 0x367C },
    [FILE_AREA13_A003_000] = { { itob(3), itob(43), itob(6), 0 }, 0x2E008 },
    [FILE_AREA13_A004_GAM] = { { itob(3), itob(44), itob(24), 0 }, 0x1009F },
    [FILE_AREA13_X13_BIN] = { { itob(3), itob(47), itob(61), 0 }, 0x32D9C },
    [FILE_AREA13_B100_GAM] = { { itob(3), itob(44), itob(57), 0 }, 0x318C },
    [FILE_AREA13_B101_GAM] = { { itob(3), itob(44), itob(64), 0 }, 0x61A9 },
    [FILE_AREA13_CLUT01_GAM] = { { itob(3), itob(47), itob(33), 0 }, 0x1578 },
    [FILE_AREA13_D103_GAM] = { { itob(3), itob(47), itob(39), 0 }, 0x4731 },
    [FILE_AREA13_B300_GAM] = { { itob(3), itob(45), itob(2), 0 }, 0x63AE },
    [FILE_AREA13_B301_000] = { { itob(3), itob(45), itob(15), 0 }, 0x20000 },
    [FILE_AREA13_B302_000] = { { itob(3), itob(46), itob(4), 0 }, 0x30000 },
    [FILE_AREA13_B303_GAM] = { { itob(3), itob(47), itob(25), 0 }, 0x3F58 },
    [FILE_AREA13_CLUT02_GAM] = { { itob(3), itob(47), itob(36), 0 }, 0x17AE },
    [FILE_AREA13_D303_GAM] = { { itob(3), itob(47), itob(48), 0 }, 0x65E3 },
    [FILE_AREA14_A000_GAM] = { { itob(3), itob(49), itob(15), 0 }, 0xB2 },
    [FILE_AREA14_A001_GAM] = { { itob(3), itob(49), itob(16), 0 }, 0x367C },
    [FILE_AREA14_A002_GAM] = { { itob(3), itob(49), itob(23), 0 }, 0xC980 },
    [FILE_AREA14_A003_GAM] = { { itob(3), itob(49), itob(49), 0 }, 0x7D42 },
    [FILE_AREA14_A004_000] = { { itob(3), itob(49), itob(65), 0 }, 0x2E008 },
    [FILE_AREA14_A005_GAM] = { { itob(3), itob(51), itob(8), 0 }, 0x12474 },
    [FILE_AREA14_X14_BIN] = { { itob(3), itob(59), itob(16), 0 }, 0x427C8 },
    [FILE_AREA14_B000_GAM] = { { itob(3), itob(51), itob(56), 0 }, 0x92B2 },
    [FILE_AREA14_B001_GAM] = { { itob(3), itob(52), itob(0), 0 }, 0x3FB7 },
    [FILE_AREA14_B002_GAM] = { { itob(3), itob(52), itob(8), 0 }, 0x209B },
    [FILE_AREA14_CLUT01_GAM] = { { itob(3), itob(57), itob(4), 0 }, 0x1943 },
    [FILE_AREA14_D003_GAM] = { { itob(3), itob(57), itob(36), 0 }, 0xC305 },
    [FILE_AREA14_B100_GAM] = { { itob(3), itob(52), itob(13), 0 }, 0x7180 },
    [FILE_AREA14_B102_GAM] = { { itob(3), itob(52), itob(28), 0 }, 0xC7CC },
    [FILE_AREA14_B103_GAM] = { { itob(3), itob(52), itob(53), 0 }, 0x17B0 },
    [FILE_AREA14_CLUT02_GAM] = { { itob(3), itob(57), itob(8), 0 }, 0x1999 },
    [FILE_AREA14_D104_GAM] = { { itob(3), itob(57), itob(61), 0 }, 0x4F0E },
    [FILE_AREA14_B200_GAM] = { { itob(3), itob(52), itob(56), 0 }, 0xC743 },
    [FILE_AREA14_B201_GAM] = { { itob(3), itob(53), itob(6), 0 }, 0x6E3A },
    [FILE_AREA14_B202_GAM] = { { itob(3), itob(53), itob(20), 0 }, 0x1F4D },
    [FILE_AREA14_CLUT03_GAM] = { { itob(3), itob(57), itob(12), 0 }, 0x19D6 },
    [FILE_AREA14_D203_GAM] = { { itob(3), itob(57), itob(71), 0 }, 0x542E },
    [FILE_AREA14_B300_GAM] = { { itob(3), itob(53), itob(24), 0 }, 0x10163 },
    [FILE_AREA14_B301_GAM] = { { itob(3), itob(53), itob(57), 0 }, 0x148FA },
    [FILE_AREA14_B302_GAM] = { { itob(3), itob(54), itob(24), 0 }, 0x2D76 },
    [FILE_AREA14_CLUT04_GAM] = { { itob(3), itob(57), itob(16), 0 }, 0x1ABA },
    [FILE_AREA14_D303_GAM] = { { itob(3), itob(58), itob(7), 0 }, 0x66F7 },
    [FILE_AREA14_B400_GAM] = { { itob(3), itob(54), itob(30), 0 }, 0xB2DD },
    [FILE_AREA14_B401_GAM] = { { itob(3), itob(54), itob(53), 0 }, 0xC0F6 },
    [FILE_AREA14_CLUT05_GAM] = { { itob(3), itob(57), itob(20), 0 }, 0x1BB8 },
    [FILE_AREA14_D403_GAM] = { { itob(3), itob(58), itob(20), 0 }, 0x61D6 },
    [FILE_AREA14_B500_GAM] = { { itob(3), itob(55), itob(3), 0 }, 0xA217 },
    [FILE_AREA14_B501_GAM] = { { itob(3), itob(55), itob(24), 0 }, 0x111C1 },
    [FILE_AREA14_CLUT06_GAM] = { { itob(3), itob(57), itob(24), 0 }, 0x1DC2 },
    [FILE_AREA14_D502_GAM] = { { itob(3), itob(58), itob(33), 0 }, 0x6226 },
    [FILE_AREA14_B600_GAM] = { { itob(3), itob(55), itob(59), 0 }, 0xCEA2 },
    [FILE_AREA14_B601_GAM] = { { itob(3), itob(56), itob(10), 0 }, 0xABFC },
    [FILE_AREA14_CLUT07_GAM] = { { itob(3), itob(57), itob(28), 0 }, 0x1981 },
    [FILE_AREA14_D602_GAM] = { { itob(3), itob(58), itob(46), 0 }, 0xA80E },
    [FILE_AREA14_B700_GAM] = { { itob(3), itob(56), itob(32), 0 }, 0xCDFB },
    [FILE_AREA14_B701_GAM] = { { itob(3), itob(56), itob(58), 0 }, 0xA7D4 },
    [FILE_AREA14_B_GAM] = { { itob(3), itob(51), itob(45), 0 }, 0x55EC },
    [FILE_AREA14_CLUT08_GAM] = { { itob(3), itob(57), itob(32), 0 }, 0x1C8D },
    [FILE_AREA14_D702_GAM] = { { itob(3), itob(58), itob(68), 0 }, 0xB56D },
    [FILE_AREA15_SCR0100_WSS] = { { itob(4), itob(1), itob(38), 0 }, 0xF63 },
    [FILE_AREA15_0200_WSS] = { { itob(4), itob(1), itob(8), 0 }, 0x4F35 },
    [FILE_AREA15_0210_WSS] = { { itob(4), itob(1), itob(23), 0 }, 0x1C50 },
    [FILE_AREA15_0140_WSS] = { { itob(4), itob(1), itob(4), 0 }, 0x1BE0 },
    [FILE_AREA15_0130_WSS] = { { itob(4), itob(1), itob(3), 0 }, 0x238 },
    [FILE_AREA15_0120_WSS] = { { itob(4), itob(1), itob(2), 0 }, 0x3AC },
    [FILE_AREA15_0000_WSS] = { { itob(4), itob(1), itob(0), 0 }, 0xA31 },
    [FILE_AREA15_0220_WSS] = { { itob(4), itob(1), itob(27), 0 }, 0xACF },
    [FILE_AREA15_0201_WSS] = { { itob(4), itob(1), itob(18), 0 }, 0x24CC },
    [FILE_AREA16_A000_GAM] = { { itob(4), itob(1), itob(42), 0 }, 0xB2 },
    [FILE_AREA16_A001_GAM] = { { itob(4), itob(1), itob(43), 0 }, 0x367C },
    [FILE_AREA16_A003_GAM] = { { itob(4), itob(1), itob(50), 0 }, 0xD25B },
    [FILE_AREA16_B300_000] = { { itob(4), itob(2), itob(2), 0 }, 0x20000 },
    [FILE_AREA16_B301_GAM] = { { itob(4), itob(2), itob(66), 0 }, 0x34B0 },
    [FILE_AREA16_CLUT04_GAM] = { { itob(4), itob(8), itob(53), 0 }, 0x138B },
    [FILE_AREA16_D303_000] = { { itob(4), itob(8), itob(65), 0 }, 0x2E008 },
    [FILE_AREA16_D304_GAM] = { { itob(4), itob(10), itob(8), 0 }, 0x1E06 },
    [FILE_AREA16_D305_GAM] = { { itob(4), itob(10), itob(12), 0 }, 0x1355 },
    [FILE_AREA16_X16_BIN] = { { itob(4), itob(15), itob(6), 0 }, 0x33758 },
    [FILE_AREA16_B400_000] = { { itob(4), itob(2), itob(73), 0 }, 0x20000 },
    [FILE_AREA16_B401_000] = { { itob(4), itob(3), itob(62), 0 }, 0x20000 },
    [FILE_AREA16_B402_000] = { { itob(4), itob(4), itob(51), 0 }, 0x20000 },
    [FILE_AREA16_B404_GAM] = { { itob(4), itob(5), itob(40), 0 }, 0x34B0 },
    [FILE_AREA16_CLUT05_GAM] = { { itob(4), itob(8), itob(56), 0 }, 0x158F },
    [FILE_AREA16_D401_000] = { { itob(4), itob(10), itob(15), 0 }, 0x2E008 },
    [FILE_AREA16_D402_GAM] = { { itob(4), itob(11), itob(33), 0 }, 0x29AB },
    [FILE_AREA16_B500_000] = { { itob(4), itob(5), itob(47), 0 }, 0x20000 },
    [FILE_AREA16_B501_000] = { { itob(4), itob(6), itob(36), 0 }, 0x18000 },
    [FILE_AREA16_B502_GAM] = { { itob(4), itob(7), itob(9), 0 }, 0x44B8 },
    [FILE_AREA16_B503_GAM] = { { itob(4), itob(7), itob(18), 0 }, 0x9F1 },
    [FILE_AREA16_CLUT06_GAM] = { { itob(4), itob(8), itob(59), 0 }, 0x1539 },
    [FILE_AREA16_D504_000] = { { itob(4), itob(11), itob(39), 0 }, 0x2E008 },
    [FILE_AREA16_D505_GAM] = { { itob(4), itob(12), itob(57), 0 }, 0x3672 },
    [FILE_AREA16_B600_000] = { { itob(4), itob(7), itob(20), 0 }, 0x20000 },
    [FILE_AREA16_B601_GAM] = { { itob(4), itob(8), itob(9), 0 }, 0xCCBF },
    [FILE_AREA16_B602_GAM] = { { itob(4), itob(8), itob(35), 0 }, 0x44B8 },
    [FILE_AREA16_CLUT07_GAM] = { { itob(4), itob(8), itob(62), 0 }, 0x14F5 },
    [FILE_AREA16_D603_000] = { { itob(4), itob(12), itob(64), 0 }, 0x2E008 },
    [FILE_AREA16_D604_GAM] = { { itob(4), itob(14), itob(7), 0 }, 0x316C },
    [FILE_AREA17_A000_GAM] = { { itob(4), itob(16), itob(36), 0 }, 0xB2 },
    [FILE_AREA17_A001_GAM] = { { itob(4), itob(16), itob(37), 0 }, 0x34B0 },
    [FILE_AREA17_A002_GAM] = { { itob(4), itob(16), itob(44), 0 }, 0x367C },
    [FILE_AREA17_A003_GAM] = { { itob(4), itob(16), itob(51), 0 }, 0xD058 },
    [FILE_AREA17_B100_GAM] = { { itob(4), itob(17), itob(3), 0 }, 0x1ADE2 },
    [FILE_AREA17_CLUT02_GAM] = { { itob(4), itob(22), itob(4), 0 }, 0x138B },
    [FILE_AREA17_D101_000] = { { itob(4), itob(22), itob(34), 0 }, 0x2E008 },
    [FILE_AREA17_D102_GAM] = { { itob(4), itob(23), itob(52), 0 }, 0x2889 },
    [FILE_AREA17_D103_GAM] = { { itob(4), itob(23), itob(58), 0 }, 0x154 },
    [FILE_AREA17_X17_BIN] = { { itob(4), itob(30), itob(5), 0 }, 0x346CC },
    [FILE_AREA17_B200_GAM] = { { itob(4), itob(17), itob(57), 0 }, 0x2F03F },
    [FILE_AREA17_B201_GAM] = { { itob(4), itob(19), itob(2), 0 }, 0xCC94 },
    [FILE_AREA17_B202_GAM] = { { itob(4), itob(19), itob(28), 0 }, 0x44B8 },
    [FILE_AREA17_CLUT03_GAM] = { { itob(4), itob(22), itob(7), 0 }, 0x15D6 },
    [FILE_AREA17_D203_000] = { { itob(4), itob(23), itob(59), 0 }, 0x2E008 },
    [FILE_AREA17_D204_GAM] = { { itob(4), itob(25), itob(2), 0 }, 0x2889 },
    [FILE_AREA17_D205_GAM] = { { itob(4), itob(25), itob(8), 0 }, 0xE70 },
    [FILE_AREA17_B300_GAM] = { { itob(4), itob(19), itob(37), 0 }, 0x13E42 },
    [FILE_AREA17_CLUT04_GAM] = { { itob(4), itob(22), itob(10), 0 }, 0x138B },
    [FILE_AREA17_D301_000] = { { itob(4), itob(25), itob(10), 0 }, 0x2E008 },
    [FILE_AREA17_D302_GAM] = { { itob(4), itob(26), itob(28), 0 }, 0x2889 },
    [FILE_AREA17_D303_GAM] = { { itob(4), itob(26), itob(34), 0 }, 0xDFC },
    [FILE_AREA17_B400_GAM] = { { itob(4), itob(20), itob(2), 0 }, 0x13E42 },
    [FILE_AREA17_CLUT05_GAM] = { { itob(4), itob(22), itob(13), 0 }, 0x138B },
    [FILE_AREA17_D401_000] = { { itob(4), itob(26), itob(36), 0 }, 0x2E008 },
    [FILE_AREA17_D402_GAM] = { { itob(4), itob(27), itob(54), 0 }, 0x2889 },
    [FILE_AREA17_D403_GAM] = { { itob(4), itob(27), itob(60), 0 }, 0xDFC },
    [FILE_AREA17_B500_GAM] = { { itob(4), itob(20), itob(42), 0 }, 0x2491A },
    [FILE_AREA17_B501_GAM] = { { itob(4), itob(21), itob(41), 0 }, 0xCC94 },
    [FILE_AREA17_B502_GAM] = { { itob(4), itob(21), itob(67), 0 }, 0x44B8 },
    [FILE_AREA17_CLUT06_GAM] = { { itob(4), itob(22), itob(16), 0 }, 0x15D6 },
    [FILE_AREA17_D503_000] = { { itob(4), itob(27), itob(62), 0 }, 0x2E008 },
    [FILE_AREA17_D504_GAM] = { { itob(4), itob(29), itob(5), 0 }, 0x2889 },
    [FILE_AREA17_D505_GAM] = { { itob(4), itob(29), itob(11), 0 }, 0xE40 },
    [FILE_AREA18_A000_GAM] = { { itob(4), itob(31), itob(36), 0 }, 0xB2 },
    [FILE_AREA18_A001_GAM] = { { itob(4), itob(31), itob(37), 0 }, 0x367C },
    [FILE_AREA18_A003_GAM] = { { itob(4), itob(31), itob(44), 0 }, 0xD0CA },
    [FILE_AREA18_B101_GAM] = { { itob(4), itob(31), itob(71), 0 }, 0x7304 },
    [FILE_AREA18_B102_GAM] = { { itob(4), itob(32), itob(11), 0 }, 0x1150D },
    [FILE_AREA18_B103_GAM] = { { itob(4), itob(32), itob(46), 0 }, 0x44B8 },
    [FILE_AREA18_CLUT02_GAM] = { { itob(4), itob(33), itob(53), 0 }, 0x15A1 },
    [FILE_AREA18_D103_000] = { { itob(4), itob(33), itob(59), 0 }, 0x2E008 },
    [FILE_AREA18_D104_GAM] = { { itob(4), itob(35), itob(2), 0 }, 0x63F5 },
    [FILE_AREA18_X18_BIN] = { { itob(4), itob(37), itob(31), 0 }, 0x34D80 },
    [FILE_AREA18_B200_GAM] = { { itob(4), itob(32), itob(55), 0 }, 0x1C136 },
    [FILE_AREA18_B201_GAM] = { { itob(4), itob(33), itob(37), 0 }, 0x60CB },
    [FILE_AREA18_CLUT03_GAM] = { { itob(4), itob(33), itob(56), 0 }, 0x1692 },
    [FILE_AREA18_D202_000] = { { itob(4), itob(35), itob(15), 0 }, 0x2E008 },
    [FILE_AREA18_D203_GAM] = { { itob(4), itob(36), itob(33), 0 }, 0x2F13 },
    [FILE_AREA19_A000_GAM] = { { itob(4), itob(38), itob(63), 0 }, 0xB2 },
    [FILE_AREA19_A003_GAM] = { { itob(4), itob(38), itob(64), 0 }, 0x6E8C },
    [FILE_AREA19_A004_GAM] = { { itob(4), itob(39), itob(3), 0 }, 0x877 },
    [FILE_AREA19_B000_GAM] = { { itob(4), itob(39), itob(5), 0 }, 0x1252F },
    [FILE_AREA19_B001_000] = { { itob(4), itob(39), itob(42), 0 }, 0x30000 },
    [FILE_AREA19_B002_000] = { { itob(4), itob(40), itob(63), 0 }, 0x20000 },
    [FILE_AREA19_B003_GAM] = { { itob(4), itob(41), itob(52), 0 }, 0x6210 },
    [FILE_AREA19_CLUT01_GAM] = { { itob(4), itob(46), itob(65), 0 }, 0x156E },
    [FILE_AREA19_D005_000] = { { itob(4), itob(47), itob(0), 0 }, 0x4FC64 },
    [FILE_AREA19_D008_GAM] = { { itob(4), itob(49), itob(10), 0 }, 0xF684 },
    [FILE_AREA19_INFO_BIN] = { { itob(4), itob(53), itob(21), 0 }, 0xD3D4 },
    [FILE_AREA19_B100_GAM] = { { itob(4), itob(41), itob(65), 0 }, 0x113D3 },
    [FILE_AREA19_B101_000] = { { itob(4), itob(42), itob(25), 0 }, 0x20000 },
    [FILE_AREA19_B102_GAM] = { { itob(4), itob(43), itob(14), 0 }, 0x45B8 },
    [FILE_AREA19_B103_000] = { { itob(4), itob(43), itob(23), 0 }, 0x8000 },
    [FILE_AREA19_B104_GAM] = { { itob(4), itob(43), itob(39), 0 }, 0x6210 },
    [FILE_AREA19_B105_GAM] = { { itob(4), itob(43), itob(52), 0 }, 0x6F32 },
    [FILE_AREA19_CLUT02_GAM] = { { itob(4), itob(46), itob(68), 0 }, 0x19BA },
    [FILE_AREA19_D107_000] = { { itob(4), itob(49), itob(41), 0 }, 0x2E008 },
    [FILE_AREA19_D108_GAM] = { { itob(4), itob(50), itob(59), 0 }, 0x2889 },
    [FILE_AREA19_D109_GAM] = { { itob(4), itob(50), itob(65), 0 }, 0xD9CE },
    [FILE_AREA19_X02_BIN] = { { itob(4), itob(54), itob(40), 0 }, 0x37D0C },
    [FILE_AREA19_B201_000] = { { itob(4), itob(43), itob(66), 0 }, 0x30000 },
    [FILE_AREA19_B202_000] = { { itob(4), itob(45), itob(12), 0 }, 0x20000 },
    [FILE_AREA19_B203_000] = { { itob(4), itob(46), itob(1), 0 }, 0x18000 },
    [FILE_AREA19_B204_000] = { { itob(4), itob(46), itob(49), 0 }, 0x8000 },
    [FILE_AREA19_CLUT03_GAM] = { { itob(4), itob(46), itob(72), 0 }, 0x16C6 },
    [FILE_AREA19_D206_000] = { { itob(4), itob(51), itob(18), 0 }, 0x3F464 },
    [FILE_AREA19_D208_GAM] = { { itob(4), itob(52), itob(70), 0 }, 0xCE6B },
    [FILE_AREA19_INFO2_BIN] = { { itob(4), itob(53), itob(48), 0 }, 0x215E0 },
};
asm(".globl FILE_LINK_SIZES
FILE_LINK_SIZES = FILE_LINKS + 4");

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", cdLoadTask);
#define CD_REQ   (*(u8**)0x1F800288)
#define CD_HDR   (*(s16**)0x1F80028C)
#define CD_DST   (*(u8**)0x1F800290)
#define CD_NSEC  (*(s32*)0x1F800294)
#define CD_HEAD  (*(s32*)0x1F80029C)
#define CD_TAIL  (*(s32*)0x1F8002A0)
#define CD_FLAGS (*(s32*)((u8*)CD_HDR + 0x10))

void cdLoadTask(void)
{
    RECT    rect;
    u_char  param[40];
    s32     i;
    s32     r;
    s32     base;
    s32     nhead;
    s32     nbody;
    s32     tail;
    s32     head;
    s32     id;
    s32     flags;
    u32     spuAddr;
    u32     len;
    u8*     headTop;
    u8*     bodyTop;
    u8*     headCur;
    u8*     bodyCur;
    u8*     data;
    u8*     entry;
    s16*    hdr;
    s16     vabId;

    LOAD_COMPLETE = 0;
    D_8009C8B0 = 0;
    param[0] = CdlModeSpeed;
    CURRENT_TASK->state0 = 0;
    CURRENT_TASK->state1 = 0;
    while (CdControl(CdlSetmode, param, 0) == 0) {
    }

    for (;;) {
        switch ((u16)CURRENT_TASK->state0) {
        case 0:
            if (CD_HEAD == CD_TAIL) {
                break;
            }
            CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
            break;

        case 1:
            entry = (u8*)(CD_QUEUE + CD_TAIL * 2);
            hdr = *(s16**)entry;
            id = ((LoadRecord*)hdr)->fileId;
            CD_REQ = entry;
            CD_HDR = hdr;
            CdControlF(CdlSetloc, (u8*)&FILE_LINKS + (id * 8));
            CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
            break;

        case 2:
            r = CdSync(1, 0);
            if (r == 2) {
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
            } else if (r == 5) {
                CURRENT_TASK->state0 = 1;
                D_8009C8B0++;
            }
            break;

        case 3:
            flags = CD_FLAGS;
            CD_NSEC = (u32)(FILE_LINK_SIZES[*CD_HDR * 2] + 0x7FF) >> 11;
            switch (flags & 0xF) {
            case LOAD_TYPE_STAGING:
            case LOAD_TYPE_LZ_TO_RAM:
                if (CD_FLAGS & LOAD_TYPE_ALT_BUFFER) {
                    CD_DST = (u8*)&LOAD_BUFFER_ALT;
                } else {
                    CD_DST = LOAD_BUFFER;
                }
                break;
            case LOAD_TYPE_LZ_TO_VRAM:
            case LOAD_TYPE_RAW:
            case LOAD_TYPE_RAW_4:
                CD_DST = *(u8**)(CD_REQ + 4);
                break;
            }
            if (CdRead(CD_NSEC, (u_long*)CD_DST, CdlModeSpeed) == 0) {
                D_8009C8B0++;
            } else {
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
            }
            break;

        case 4:
            r = CdReadSync(1, 0);
            if (r == 0) {
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
            } else if (r == -1) {
                CURRENT_TASK->state0 = 1;
                D_8009C8B0++;
            }
            break;

        case 5:
            switch ((u16)CURRENT_TASK->state1) {
            case 0:
                switch (CD_FLAGS & 0xF) {
                case LOAD_TYPE_STAGING:
                    switch (*((u8*)CD_HDR + 3) & 0xF0) {
                    case LOAD_KIND_GRPX:
                        CURRENT_TASK->state1 = 2;
                        break;
                    case LOAD_KIND_WVD:
                        CURRENT_TASK->state1 = 5;
                        break;
                    }
                    break;
                case LOAD_TYPE_LZ_TO_VRAM:
                    CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;
                    break;
                case LOAD_TYPE_RAW:
                case LOAD_TYPE_RAW_4:
                    if ((*((u8*)CD_HDR + 3) & 0xF0) == LOAD_KIND_WVD) {
                        CURRENT_TASK->state1 = 5;
                        break;
                    }
                    CURRENT_TASK->state1 = 0;
                    CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
                    break;
                case LOAD_TYPE_LZ_TO_RAM:
                    CURRENT_TASK->state1 = 4;
                    break;
                }
                break;

            case 1:
                if (CD_FLAGS & LOAD_TYPE_ALT_BUFFER) {
                    lzDecompress(*(u8**)(CD_REQ + 4), (u8*)&LOAD_BUFFER_ALT);
                } else {
                    lzDecompress(*(u8**)(CD_REQ + 4), LOAD_BUFFER);
                }
                CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;

            case 2:
                rect.x = CD_HDR[4];
                rect.y = CD_HDR[5];
                rect.w = CD_HDR[6];
                rect.h = CD_HDR[7];
                if (CD_FLAGS & LOAD_TYPE_ALT_BUFFER) {
                    LoadImage(&rect, (u_long*)&LOAD_BUFFER_ALT);
                } else {
                    LoadImage(&rect, (u_long*)LOAD_BUFFER);
                }
                CURRENT_TASK->state1 = (u16)CURRENT_TASK->state1 + 1;
                break;

            case 3:
                DrawSync(0);
                CURRENT_TASK->state1 = 0;
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
                break;

            case 4:
                if (CD_FLAGS & LOAD_TYPE_ALT_BUFFER) {
                    lzDecompress((u8*)&LOAD_BUFFER_ALT, *(u8**)(CD_REQ + 4));
                } else {
                    lzDecompress(LOAD_BUFFER, *(u8**)(CD_REQ + 4));
                }
                CURRENT_TASK->state1 = 0;
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
                break;

            case 5:
                base = *((u8*)CD_HDR + 3) & 0xF;
                if (base == 0xF) {
                    base = 0;
                }
                data = *(u8**)(CD_REQ + 4);
                headTop = data + *(s32*)(data + 4);
                i = 0;
                headCur = headTop;
                bodyTop = data + *(s32*)data;
                bodyCur = bodyTop;
                head = *(s32*)headCur;
                tail = *(s32*)bodyTop;
                head = (u32)head >> 2;
                nhead = head - 1;
                nbody = ((u32)tail >> 2) - 1;

                if (nhead > 0) {
                    do {
                        vabId = VAB_IDS[base + i];
                        if (vabId != -1) {
                            SsVabClose(vabId);
                        }
                        i++;
                    } while (i < nhead);
                }

                i = 0;
                if (nhead > 0) {
                    do {
                        WVD_HEADERS[base + i] = (s32)(headTop + *(s32*)headCur);
                        headCur += 4;
                        i++;
                    } while (i < nhead);
                }

                i = 0;
                if (nbody > 0) {
                    do {
                        WVD_BODIES[base + i] = (s32)(bodyTop + *(s32*)bodyCur);
                        bodyCur += 4;
                        i++;
                    } while (i < nbody);
                }

                spuAddr = SPU_BANK_ADDRS[CD_HDR[7] * 2];
                i = 0;
                if (nhead > 0) {
                    do {
                        if (i == (nhead - 1)) {
                            len = (s32)(bodyTop + *(s32*)bodyCur) - WVD_BODIES[base + i];
                        } else {
                            len = WVD_BODIES[base + i + 1] - WVD_BODIES[base + i];
                        }
                        SpuSetTransferStartAddr(spuAddr);
                        SpuRead((u_char*)WVD_BODIES[base + i], len);
                        SpuIsTransferCompleted(1);
                        VAB_IDS[base + i] = SsVabFakeHead((u_char*)WVD_HEADERS[base + i], -1, spuAddr);
                        spuAddr += len;
                        SsVabFakeBody(VAB_IDS[base + i]);
                        i++;
                    } while (i < nhead);
                }
                CURRENT_TASK->state1 = 0;
                CURRENT_TASK->state0 = (u16)CURRENT_TASK->state0 + 1;
                break;
            }
            break;

        case 6:
            tail = CD_TAIL;
            head = CD_HEAD;
            base = (s32)&CD_TAIL;
            tail = (tail + 1) & 0x7F;
            *(s32*)base = tail;
            if (head == tail) {
                LOAD_COMPLETE = 1;
                exitTask();
            } else {
                CURRENT_TASK->state0 = 1;
                CURRENT_TASK->state1 = 0;
            }
            break;
        }
        sleepTask(1);
    }
}


//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", stubCdFunction);
int stubCdFunction(void)
{
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", enqueueCdRead);
void enqueueCdRead(u8* dst, s16* hdr)
{
    s32 head = D_1F80029C;

    CD_QUEUE[head * 2] = (s32)hdr;
    CD_QUEUE_DST[head * 2] = (s32)dst;
    D_1F80029C = (head + 1) & 0x7F;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", loadWssFile);
void loadWssFile(int arg1, int arg2)
{
    queueLoadList((WSS_LOAD_LISTS)[arg2]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", startSoundTask);
void startSoundTask(void)
{
    *(byte* )0x1F8001CE = 0;
    openTask(2, &cdLoadTask);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", loadAreaListFile);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", queueAreaSectionLists);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", queueLoadList);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", queueSystemLoadList);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", loadSoundSet);
void loadSoundSet(s32 arg0)
{
    queueLoadList(SOUND_SET_LOAD_LISTS[arg0]);
    D_1F8002AC = LOAD_NEXT_ADDR;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800223E0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", updateObjectSideFlag);
void updateObjectSideFlag(u8* self)
{
    u8* q = self;
    s16 a = *(s16*)(*(u8**)(self + 0x40) + 2);

    if (a > *(s16*)0x1F80016A) {
        *(s16*)(self + 0x2E) = 1;
    } else {
        *(s16*)(q + 0x2E) = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", isObjectPastReferenceX);
s32 isObjectPastReferenceX(u8* self)
{
    s16 a = *(s16*)(*(u8**)(self + 0x40) + 2);

    return a > *(s16*)0x1F80016A;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", playObjectSfx);
void playObjectSfx(u8* self, s32 arg1)
{
    if (self[1] != 0) {
        playSFX(arg1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224FC);
void func_800224FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8* p = allocObjectLayer3();

    if (p != NULL) {
        p[0] = 1;
        p[2] = 0xF;
        p[3] = arg0;
        *(s16*)(p + 0x12) = arg1;
        *(s16*)(p + 0x16) = arg2;
        *(s16*)(p + 0x1A) = arg3;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", nextRandom);
u16 nextRandom(void)
{
    s32 seed = D_1F800200 * 0x41C64E6D + 0x3039;

    D_1F800200 = seed;
    return seed / 0x10000;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyAnimVelocityXY);
void applyAnimVelocityXY(u8* self, u16 arg1)
{
    s16* row = (s16*)(*(u8**)(self + 0x28) + arg1 * 4);
    s32* p = *(s32**)(self + 0x40);
    s32 t;

    t = row[0] << 8;
    *p += t;
    t = row[1] << 8;
    *(s32*)(self + 0x14) += t;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyAnimVelocityY);
void applyAnimVelocityY(u8* self, u16 arg1)
{
    u8* row = *(u8**)(self + 0x28) + arg1 * 4;

    *(s32*)(self + 0x14) += *(s16*)(row + 2) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyAnimVelocityX);
void applyAnimVelocityX(u8* self, u16 arg1)
{
    u8*  row = *(u8**)(self + 0x28) + arg1 * 4;
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)row << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyFrameVelocityXY);
void applyFrameVelocityXY(u8* self)
{
    s16* row = (s16*)(*(u8**)(self + 0x28) + *(u16*)(self + 0x2E) * 4);
    s32* p = *(s32**)(self + 0x40);
    s32 t;

    t = row[0] << 8;
    *p += t;
    t = row[1] << 8;
    *(s32*)(self + 0x14) += t;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyFrameVelocityX);
void applyFrameVelocityX(u8* self)
{
    u8*  row = *(u8**)(self + 0x28) + *(u16*)(self + 0x2E) * 4;
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)row << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyFrameVelocityY);
void applyFrameVelocityY(u8* self)
{
    u8* row = *(u8**)(self + 0x28) + *(u16*)(self + 0x2E) * 4;

    *(s32*)(self + 0x14) += *(s16*)(row + 2) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyTableVelocityXY);
void applyTableVelocityXY(u8* self, s16* row)
{
    s32* p = *(s32**)(self + 0x40);
    s32  t;

    row = (s16*)((u8*)row + *(u16*)(self + 0x2E) * 4);

    t = row[0] << 8;
    *p += t;
    t = row[1] << 8;
    *(s32*)(self + 0x14) += t;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyTableVelocityX);
void applyTableVelocityX(u8* self, s16* tab)
{
    s32* p = *(s32**)(self + 0x40);

    tab = (s16*)((u8*)tab + *(u16*)(self + 0x2E) * 4);

    *p += *tab << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", setObjectSpeedPolar);
void setObjectSpeedPolar(u8* self, s16 arg1, s16 arg2)
{
    s16 a = fixedMulCos2(arg1, arg2);
    s16 b = fixedMulSin2(arg1, arg2);

    *(s16*)(self + 0x80) = a;
    *(s16*)(self + 0x82) = b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", setObjectSpeedPolar2);
void setObjectSpeedPolar2(u8* self, s16 arg1, s16 arg2)
{
    s16 a = fixedMulCos(arg1, arg2);
    s16 b = fixedMulSin(arg1, arg2);

    *(s16*)(self + 0x80) = a;
    *(s16*)(self + 0x82) = b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", setObjectAltSpeedPolar);
void setObjectAltSpeedPolar(u8* self, s16 arg1, s16 arg2)
{
    s16 a = fixedMulCos(arg1, arg2);
    s16 b = fixedMulSin(arg1, arg2);

    *(s16*)(self + 0x7C) = a;
    *(s16*)(self + 0x7E) = b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectSpeedXY);
void applyObjectSpeedXY(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x80) << 8;
    *(s32*)(self + 0x14) += *(s16*)(self + 0x82) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectSpeedX);
void applyObjectSpeedX(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x80) << 8;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectSpeedVertical);
void applyObjectSpeedVertical(u_short* id)
{
    ((u_int*)(id))[0x5] = (int)(((u_int*)(id))[0x5] + (((short*)(id))[0x41] << 8));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectAltSpeedXY);
void applyObjectAltSpeedXY(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x7C) << 8;
    *(s32*)(self + 0x14) += *(s16*)(self + 0x7E) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectAltSpeedX);
void applyObjectAltSpeedX(u8* self)
{
    s32* p = *(s32**)(self + 0x40);

    *p += *(s16*)(self + 0x7C) << 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", applyObjectAltSpeedVertical);
void applyObjectAltSpeedVertical(short* id)
{
    ((u_int*)(id))[0x5] = (int) (((u_int*)(id))[0x5] + (((short*)(id))[0x3F] << 8));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", fixedMulSin);
s32 fixedMulSin(s16 arg0, s16 arg1)
{
    return ((D_8007D788[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", fixedMulCos);
s32 fixedMulCos(s16 arg0, s16 arg1)
{
    return ((D_8007DB88[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", fixedMulSin2);
s32 fixedMulSin2(s16 arg0, s16 arg1)
{
    return ((D_8007D988[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", fixedMulCos2);
s32 fixedMulCos2(s16 arg0, s16 arg1)
{
    return ((D_8007DB88[arg0] * arg1) << 4) >> 16;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", readAnimFrameCount);
void readAnimFrameCount(u8* self)
{
    *(s16*)(self + 0x2C) =
        *(u16*)(*(u8**)(self + 0x24) + 6) & 0x3FFF;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", resetAnimTimer);
void resetAnimTimer(u_short* id)
{
    ((u_short*)(id))[0x16] = ((u_short*)(id))[0x10];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", advanceAnimFrame);
void advanceAnimFrame(u8* self, s16 arg1)
{
    s32 off = arg1 * 8;

    *(s16*)(self + 0x2C) =
        *(u16*)(arg1 * 8 + *(u8**)(self + 0x24) + 6) & 0x3FFF;
    *(u8**)(self + 0x24) = *(u8**)(self + 0x24) + off;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022B34);
