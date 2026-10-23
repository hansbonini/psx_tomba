#include "common.h"
#include "game.h"
#include "psyq/libspu.h"
#include "psyq/libsnd.h"

#define SOUND_QUEUE_SIZE 0x80
#define BGM_VOICE_MASK (SPU_00CH | SPU_01CH | SPU_02CH | SPU_03CH | SPU_04CH | SPU_05CH | SPU_06CH | SPU_07CH | SPU_08CH | SPU_09CH | SPU_10CH | SPU_11CH | SPU_12CH | SPU_13CH | SPU_14CH | SPU_15CH)
#define SFX_VOICE_MASK (SPU_16CH | SPU_17CH | SPU_18CH | SPU_19CH | SPU_20CH | SPU_21CH | SPU_22CH | SPU_23CH)

enum {
    SND_CMD_KEY_ON            = 0x0000,
    SND_CMD_KEY_OFF           = 0x1000,
    SND_CMD_OVERRIDE          = 0x8000,
    SND_CMD_BGM_FADE          = 0x9000,
    SND_CMD_PITCH_SLIDE       = 0xA000,
    SND_CMD_TYPE_MASK         = 0xF000,
    SND_CMD_PARAM_MASK        = 0x0F00,
    SND_CMD_VALUE_MASK        = 0x00FF,
    SND_SFX_ID_MASK           = 0x03FF,
    SND_KEYON_NOTE_OVERRIDE   = 0x0400,
    SND_KEYON_VOLUME_OVERRIDE = 0x0800,
    SND_OVERRIDE_NOTE         = 0x0000,
    SND_OVERRIDE_VOLUME       = 0x0100,
    SND_FADE_INTERVAL         = 0x0000,
    SND_FADE_STEP             = 0x0100,
    SND_FADE_TARGET           = 0x0200,
    SND_SLIDE_INTERVAL        = 0x0000,
    SND_SLIDE_STEP            = 0x0100,
    SND_SLIDE_DURATION        = 0x0200,
    SND_SLIDE_START           = 0x0300
};


SfxDef D_80077774[41] = {
    { 0, 2, 8, 40, 100, 0 },
    { 0, 0, 1, 1, 100, 0 },
    { 0, 0, 2, 2, 100, 0 },
    { 0, 0, 3, 3, 80, 0 },
    { 0, 0, 4, 4, 80, 0 },
    { 0, 0, 5, 5, 80, 0 },
    { 0, 0, 6, 6, 100, 0 },
    { 0, 0, 7, 7, 120, 0 },
    { 0, 0, 8, 8, 100, 0 },
    { 0, 0, 9, 9, 110, 0 },
    { 0, 0, 10, 10, 110, 0 },
    { 0, 0, 11, 11, 70, 0 },
    { 0, 0, 12, 12, 100, 0 },
    { 0, 0, 13, 13, 100, 0 },
    { 0, 0, 14, 14, 100, 0 },
    { 0, 0, 15, 15, 100, 0 },
    { 0, 1, 0, 16, 100, 0 },
    { 0, 1, 1, 17, 70, 0 },
    { 0, 1, 2, 18, 100, 0 },
    { 0, 1, 3, 19, 100, 0 },
    { 0, 1, 4, 20, 100, 0 },
    { 0, 1, 5, 21, 100, 0 },
    { 0, 1, 6, 22, 100, 0 },
    { 0, 1, 7, 23, 100, 0 },
    { 0, 1, 8, 24, 100, 0 },
    { 0, 1, 9, 25, 100, 0 },
    { 0, 1, 10, 26, 100, 0 },
    { 0, 1, 11, 27, 100, 0 },
    { 0, 1, 12, 28, 100, 0 },
    { 0, 1, 13, 29, 70, 0 },
    { 0, 1, 14, 30, 100, 0 },
    { 0, 1, 15, 31, 100, 0 },
    { 0, 2, 0, 32, 120, 0 },
    { 0, 2, 1, 33, 115, 0 },
    { 0, 2, 2, 34, 115, 0 },
    { 0, 2, 3, 35, 115, 0 },
    { 0, 2, 4, 36, 115, 0 },
    { 0, 2, 5, 37, 120, 0 },
    { 0, 2, 6, 38, 100, 0 },
    { 0, 1, 12, 27, 110, 0 },
    { 0, 2, 7, 39, 100, 0 }
};

SfxDef D_800778BC[1] = {
    { 4, 0, 0, 7, 120, 0 }
};

SfxDef D_800778C4[4] = {
    { 1, 0, 0, 0, 100, 0 },
    { 1, 0, 1, 1, 100, 0 },
    { 1, 0, 2, 2, 100, 0 },
    { 1, 0, 3, 3, 100, 0 }
};

extern u8 D_80077774_x[] asm("D_80077774");
extern u8 D_800778BC_x[] asm("D_800778BC");
extern u8 D_800778C4_x[] asm("D_800778C4");
extern u8 D_80077B90_x[] asm("D_80077B90");
extern u8 D_80077B98_x[] asm("D_80077B98");
extern u8 D_80077BA0_x[] asm("D_80077BA0");
extern u8 D_80077BA8_x[] asm("D_80077BA8");
extern u8 D_80077BB0_x[] asm("D_80077BB0");
extern u8 D_80077BC8_x[] asm("D_80077BC8");
extern u8 D_80077BCC_x[] asm("D_80077BCC");
extern u8 D_80077BD0_x[] asm("D_80077BD0");
extern u8 D_80077BD8_x[] asm("D_80077BD8");
extern u8 D_80077BE0_x[] asm("D_80077BE0");
extern u8 D_80077BE8_x[] asm("D_80077BE8");
extern u8 D_80077BF0_x[] asm("D_80077BF0");
extern u8 D_80077BF8_x[] asm("D_80077BF8");
extern u8 D_80077C10_x[] asm("D_80077C10");
extern u8 D_80077C18_x[] asm("D_80077C18");
extern u8 D_80077C20_x[] asm("D_80077C20");
extern u8 D_80077C28_x[] asm("D_80077C28");
extern u8 D_80077C30_x[] asm("D_80077C30");
extern u8 D_80077C38_x[] asm("D_80077C38");
extern u8 D_80077C40_x[] asm("D_80077C40");
extern u8 D_801152DC_x[] asm("D_801152DC");
extern u8 D_80119BE8_x[] asm("D_80119BE8");
extern u8 D_80121C84_x[] asm("D_80121C84");
extern u8 D_801280BC_x[] asm("D_801280BC");
extern u8 D_801280E4_x[] asm("D_801280E4");
extern u8 D_8012810C_x[] asm("D_8012810C");
extern u8 D_8012813C_x[] asm("D_8012813C");
extern u8 D_80128164_x[] asm("D_80128164");
extern u8 D_8012818C_x[] asm("D_8012818C");
extern u8 D_801281B4_x[] asm("D_801281B4");
extern u8 D_801281E4_x[] asm("D_801281E4");
extern u8 D_8012CC40_x[] asm("D_8012CC40");
extern u8 D_80130E7C_x[] asm("D_80130E7C");
extern u8 D_80130F04_x[] asm("D_80130F04");
extern u8 D_80130F1C_x[] asm("D_80130F1C");
extern u8 D_80130F54_x[] asm("D_80130F54");
extern u8 D_80132D50_x[] asm("D_80132D50");
extern u8 D_80132D90_x[] asm("D_80132D90");
extern u8 D_80137A3C_x[] asm("D_80137A3C");
extern u8 D_80137A94_x[] asm("D_80137A94");
extern u8 D_801393D4_x[] asm("D_801393D4");
extern u8 D_8013CCC0_x[] asm("D_8013CCC0");
extern u8 D_8013CD10_x[] asm("D_8013CD10");
extern u8 D_8013CD90_x[] asm("D_8013CD90");
extern u8 D_8013CDF0_x[] asm("D_8013CDF0");

u32 D_800778E4_d[130] asm("D_800778E4") = {
    0x01000000, 0x03000200, 0x05000400, 0x07000600,
    0x09000800, 0x0B000A00, 0x0D000C00, 0x0F000E00,
    0x11001000, 0x13001200, 0x15001400, 0x17001600,
    0x19001800, 0x1B001A00, 0x1D001C00, 0x1F001E00,
    0x21002000, 0x23002200, 0x25002400, 0x27002600,
    0x00012800, 0x02010101, 0x01020002, 0x03020202,
    0x05020402, 0x07020602, 0x09020802, 0x0B020A02,
    0x0D020C02, 0x00030E02, 0x02030103, 0x04030303,
    0x06030503, 0x08030703, 0x00040903, 0x02040104,
    0x04040304, 0x06040504, 0x08040704, 0x0A040904,
    0x0C040B04, 0x0E040D04, 0x00050F04, 0x02050105,
    0x04050305, 0x06050505, 0x08050705, 0x0A050905,
    0x001B0B05, 0x02060106, 0x04060306, 0x06060506,
    0x08060706, 0x0A060906, 0x0C060B06, 0x00070D06,
    0x02070107, 0x04070307, 0x06070507, 0x08070707,
    0x0A070907, 0x01080008, 0x00090208, 0x02090109,
    0x04090309, 0x000A0509, 0x020A010A, 0x040A030A,
    0x060A050A, 0x080A070A, 0x010B000B, 0x030B020B,
    0x010C000C, 0x030C020C, 0x050C040C, 0x070C060C,
    0x090C080C, 0x0B0C0A0C, 0x0D0C0C0C, 0x010D000D,
    0x030D020D, 0x050D040D, 0x070D060D, 0x090D080D,
    0x0B0D0A0D, 0x0D0D0C0D, 0x0F0D0E0D, 0x000E100D,
    0x020E010E, 0x010F000F, 0x030F020F, 0x050F040F,
    0x0010060F, 0x02100110, 0x04100310, 0x06100510,
    0x01110011, 0x03110211, 0x05110411, 0x01120012,
    0x03120212, 0x00130412, 0x02130113, 0x04130313,
    0x01140014, 0x03140214, 0x05140414, 0x01150015,
    0x03150215, 0x00160415, 0x02160116, 0x04160316,
    0x01170017, 0x03170217, 0x00180417, 0x02180118,
    0x04180318, 0x00190518, 0x02190119, 0x04190319,
    0x06190519, 0x08190719, 0x0A190919, 0x06090B19,
    0x090A0709, 0x001A0A0A, 0x021A011A, 0x041A031A,
    0x061A051A, 0x081A071A,
};
u32 SFX_BANKS_d[28] asm("SFX_BANKS") = {
    (u32)D_80077774_x, (u32)D_800778C4_x, (u32)D_801393D4_x, (u32)D_8013CCC0_x,
    (u32)D_8013CD10_x, (u32)D_8013CD90_x, (u32)D_8013CDF0_x, (u32)D_80137A3C_x,
    (u32)D_80137A94_x, (u32)D_80132D50_x, (u32)D_80132D90_x, (u32)D_801152DC_x,
    (u32)D_8012CC40_x, (u32)D_80130E7C_x, (u32)D_80130F04_x, (u32)D_80130F1C_x,
    (u32)D_80130F54_x, (u32)D_80119BE8_x, (u32)D_801280BC_x, (u32)D_801280E4_x,
    (u32)D_8012810C_x, (u32)D_8012813C_x, (u32)D_80128164_x, (u32)D_8012818C_x,
    (u32)D_801281B4_x, (u32)D_801281E4_x, (u32)D_80121C84_x, (u32)D_800778BC_x,
};
u32 AREA_BGM_VOLUME_d[12] asm("AREA_BGM_VOLUME") = {
    0x005A004A, 0x005F0050, 0x005A005F, 0x00400054,
    0x005F005F, 0x005A005A, 0x005A005A, 0x005A005A,
    0x005A005A, 0x005A005A, 0x005A005A, 0x005A005A,
};
u32 BGM_TRACK_VOLUME_d[1] asm("BGM_TRACK_VOLUME") = {
    0x00640064,
};
u32 D_80077B90_d[2] asm("D_80077B90") = {
    0x18181818, 0x00001818,
};
u32 D_80077B98_d[2] asm("D_80077B98") = {
    0x18181818, 0x00001818,
};
u32 D_80077BA0_d[2] asm("D_80077BA0") = {
    0x18181818, 0x00001818,
};
u32 D_80077BA8_d[2] asm("D_80077BA8") = {
    0x18181818, 0x00001818,
};
u32 D_80077BB0_d[6] asm("D_80077BB0") = {
    0x28282828, 0x18181818, 0x18181818, 0x18181818,
    0x18181818, 0x00001818,
};
u32 D_80077BC8_d[1] asm("D_80077BC8") = {
    0x18181818,
};
u32 D_80077BCC_d[1] asm("D_80077BCC") = {
    0x18381818,
};
u32 D_80077BD0_d[2] asm("D_80077BD0") = {
    0x18181818, 0x00001818,
};
u32 D_80077BD8_d[2] asm("D_80077BD8") = {
    0x18181818, 0x00001818,
};
u32 D_80077BE0_d[2] asm("D_80077BE0") = {
    0x28282818, 0x00002828,
};
u32 D_80077BE8_d[2] asm("D_80077BE8") = {
    0x18181818, 0x00001818,
};
u32 D_80077BF0_d[2] asm("D_80077BF0") = {
    0x18181818, 0x00001818,
};
u32 D_80077BF8_d[6] asm("D_80077BF8") = {
    0x28282828, 0x18181818, 0x18181818, 0x18181818,
    0x18181818, 0x00001818,
};
u32 D_80077C10_d[2] asm("D_80077C10") = {
    0x18181818, 0x00001818,
};
u32 D_80077C18_d[2] asm("D_80077C18") = {
    0x18181818, 0x00001818,
};
u32 D_80077C20_d[2] asm("D_80077C20") = {
    0x18181818, 0x00001818,
};
u32 D_80077C28_d[2] asm("D_80077C28") = {
    0x18181818, 0x00001818,
};
u32 D_80077C30_d[2] asm("D_80077C30") = {
    0x18181818, 0x00001818,
};
u32 D_80077C38_d[2] asm("D_80077C38") = {
    0x18181818, 0x00001818,
};
u32 D_80077C40_d[2] asm("D_80077C40") = {
    0x18181818, 0x00001818,
};
u32 AREA_REVERB_DEPTH_d[20] asm("AREA_REVERB_DEPTH") = {
    (u32)D_80077B90_x, (u32)D_80077B98_x, (u32)D_80077BA0_x, (u32)D_80077BA8_x,
    (u32)D_80077BB0_x, (u32)D_80077BC8_x, (u32)D_80077BCC_x, (u32)D_80077BD0_x,
    (u32)D_80077BD8_x, (u32)D_80077BE0_x, (u32)D_80077BE8_x, (u32)D_80077BF0_x,
    (u32)D_80077BF8_x, (u32)D_80077C10_x, (u32)D_80077C18_x, (u32)D_80077C20_x,
    (u32)D_80077C28_x, (u32)D_80077C30_x, (u32)D_80077C38_x, (u32)D_80077C40_x,
};
u32 AREA_REVERB_MODE_d[20] asm("AREA_REVERB_MODE") = {
    0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000002, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001,
    0x00000001, 0x00000001, 0x00000001, 0x00000001,
};
u32 AREA_BGM_DEFS_d[22] asm("AREA_BGM_DEFS") = {
    0x00000300, 0x00000400, 0x00000501, 0x00000300,
    0x00000300, 0x00000300, 0x00000300, 0x00000300,
    0x00000300, 0x00000300, 0x00000300, 0x00000300,
    0x00000300, 0x00000300, 0x00000300, 0x00000300,
    0x00000300, 0x00000300, 0x00000300, 0x00000300,
    0x00000300, 0x00000300,
};
u32 BGM_TRACK_DEFS_d[4] asm("BGM_TRACK_DEFS") = {
    0x00000300, 0x00000300, 0x00000300, 0x00000300,
};
u32 SPU_BANK_ADDRS_d[150] asm("SPU_BANK_ADDRS") = {
    0x00001010, 0x00004000, 0x00048250, 0x00002100,
    0x00048250, 0x00002000, 0x00048250, 0x00001900,
    0x00066190, 0x00000D00, 0x00066190, 0x00000D00,
    0x00066190, 0x00000D00, 0x00066190, 0x00000D00,
    0x00048250, 0x00001F00, 0x00048250, 0x00001500,
    0x00048250, 0x00002300, 0x00048250, 0x00001100,
    0x00048250, 0x00002700, 0x00048250, 0x00002300,
    0x00048250, 0x00001700, 0x00048250, 0x00001900,
    0x00048250, 0x00002900, 0x00048250, 0x00002500,
    0x00048250, 0x00001900, 0x0005EA70, 0x00003900,
    0x00048250, 0x00001100, 0x00001010, 0x00003900,
    0x00001010, 0x00003900, 0x00001010, 0x00003900,
    0x00048250, 0x00002300, 0x00048250, 0x00001500,
    0x00001010, 0x00003900, 0x00001010, 0x00003900,
    0x00062870, 0x00003900, 0x00001010, 0x00003900,
    0x00001010, 0x00003900, 0x00001010, 0x00003900,
    0x00048250, 0x00002500, 0x00001010, 0x00003900,
    0x00001010, 0x00003900, 0x00001010, 0x00003900,
    0x00048250, 0x00002300, 0x00048250, 0x00001500,
    0x00001010, 0x00003900, 0x00048250, 0x00001700,
    0x00048250, 0x00002B00, 0x00001010, 0x00003900,
    0x00048250, 0x00002300, 0x00048250, 0x00002700,
    0x00048250, 0x00001B00, 0x00048250, 0x00001500,
    0x00048250, 0x00001900, 0x00048250, 0x00001900,
    0x00048250, 0x00002900, 0x00048250, 0x00002900,
    0x00048250, 0x00002900, 0x00048250, 0x00002900,
    0x00048250, 0x00002900, 0x00048250, 0x00002900,
    0x00048250, 0x00002900, 0x00048250, 0x00002900,
    0x00048250, 0x00001D00, 0x00048250, 0x00002500,
    0x00001010, 0x00003900, 0x00048250, 0x00001B00,
    0x00048250, 0x00001B00, 0x00048250, 0x00001700,
    0x00048250, 0x00002700, 0x00048250, 0x00001F00,
    0x00048250, 0x00001700, 0x00001010, 0x00003900,
    0x00001010, 0x00003900, 0x00048250, 0x00002500,
    0x00048250, 0x00001900, 0x00048250, 0x00001D00,
    0x00048250, 0x00002100, 0x00048250, 0x00002500,
    0x00048250, 0x00002500, 0x00048250, 0x00002900,
    0x00048250, 0x00002300,
};
u32 SOUND_INITIALIZED_d[1] asm("SOUND_INITIALIZED") = {
    0x00000000,
};

asm(
    ".globl D_800778E5\nD_800778E5 = D_800778E4 + 1\n"
    ".globl D_80077CE9\nD_80077CE9 = AREA_BGM_DEFS + 1\n"
    ".globl D_80077CEA\nD_80077CEA = AREA_BGM_DEFS + 2\n"
    ".globl D_80077D41\nD_80077D41 = BGM_TRACK_DEFS + 1\n"
    ".globl D_80077FA9\nD_80077FA9 = SOUND_INITIALIZED + 1\n"
);


extern u_long* SEQ_DATA[];


// INCLUDE_ASM("nonmatchings/main/audio/sound", updateSound);
void updateSound(void)
{
    int i;
    u16 cmd;

    SpuGetAllKeysStatus(VOICE_KEY_STATUS);
    for (i = 0; i < 24; i++) {
        if (VOICE_KEY_STATUS[i] == 0) {
            VOICE_PRIORITY[i] = 0xF;
        }
    }
    while (SOUND_QUEUE_COUNT != 0) {
        cmd = SOUND_QUEUE[SOUND_QUEUE_HEAD].id;
        switch (cmd & SND_CMD_TYPE_MASK) {
        case SND_CMD_KEY_ON:
            keyOnQueuedSfx(cmd);
            break;
        case SND_CMD_KEY_OFF:
            keyOffSfxVoice(cmd & SND_CMD_VALUE_MASK);
            break;
        case SND_CMD_OVERRIDE:
            setSfxOverride(cmd);
            break;
        case SND_CMD_BGM_FADE:
            setBgmFadeParam(cmd);
            break;
        case SND_CMD_PITCH_SLIDE:
            setPitchSlideParam(cmd);
            break;
        }
        SOUND_QUEUE_HEAD = (SOUND_QUEUE_HEAD + 1) & (SOUND_QUEUE_SIZE - 1);
        SOUND_QUEUE_COUNT--;
    }
    if (BGM_MUTED == 0 && BGM_FADE_ACTIVE != 0) {
        if (--BGM_FADE_TIMER == 0) {
            BGM_FADE_TIMER = BGM_FADE_INTERVAL;
            if (BGM_FADE_STEP < 0) {
                BGM_FADE_VOLUME += BGM_FADE_STEP;
                if (BGM_FADE_VOLUME <= 0) {
                    if (BGM_SEQ_ID != -1) {
                        SsSeqStop(BGM_SEQ_ID);
                        SsSeqClose(BGM_SEQ_ID);
                        BGM_SEQ_ID = -1;
                    }
                    BGM_FADE_ACTIVE = 0;
                }
            } else if (BGM_FADE_VOLUME >= BGM_FADE_TARGET) {
                BGM_FADE_ACTIVE = 0;
            }
            BGM_VOLUME = BGM_FADE_VOLUME;
        }
        SsSeqSetVol(BGM_SEQ_ID, BGM_FADE_VOLUME, BGM_FADE_VOLUME);
    }
    if (PITCH_SLIDE_ACTIVE != 0) {
        if (--PITCH_SLIDE_TIMER == 0) {
            PITCH_SLIDE_TIMER = PITCH_SLIDE_INTERVAL;
            PITCH_SLIDE_NEW_FINE += PITCH_SLIDE_STEP;
            if (PITCH_SLIDE_NEW_FINE < 0) {
                PITCH_SLIDE_NEW_FINE += 0x80;
                PITCH_SLIDE_NEW_NOTE--;
            } else if (PITCH_SLIDE_NEW_FINE >= 0x80) {
                PITCH_SLIDE_NEW_FINE -= 0x80;
                PITCH_SLIDE_NEW_NOTE++;
            }
            SsUtChangePitch(PITCH_SLIDE_VOICE, PITCH_SLIDE_VAB, PITCH_SLIDE_PROG, PITCH_SLIDE_OLD_NOTE, PITCH_SLIDE_OLD_FINE, PITCH_SLIDE_NEW_NOTE, PITCH_SLIDE_NEW_FINE);
        }
        if (--PITCH_SLIDE_DURATION == 0) {
            keyOffSfxVoice((u16)PITCH_SLIDE_VOICE);
            PITCH_SLIDE_ACTIVE = 0;
        }
    }
    if (BGM_MUTED != 0) {
        muteBgm();
        if (JINGLE_SEQ_ID != -1 && SsIsEos(JINGLE_SEQ_ID, 0) == 0) {
            unmuteBgm();
        }
    }
}


// INCLUDE_ASM("nonmatchings/main/audio/sound", keyOnQueuedSfx);
s32 keyOnQueuedSfx(s32 cmd)
{
    u8* e = (u8*)getSfxVabOffset(cmd & SND_SFX_ID_MASK);
    s16 voice = SOUND_QUEUE[SOUND_QUEUE_HEAD].arg;
    s16* prio;

    VOICE_KEY_STATUS[voice] = 1;
    VOICE_SFX_ID[voice] = -1;
    prio = &VOICE_PRIORITY[voice];
    if (*prio < e[5]) {
        return -1;
    }
    *prio = e[5];
    switch (cmd & (SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE)) {
    case 0:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, e[4], e[4]);
        break;
    case SND_KEYON_NOTE_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], SFX_NOTE_OVERRIDE, 0, e[4], e[4]);
        break;
    case SND_KEYON_VOLUME_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, SFX_VOLUME_OVERRIDE, SFX_VOLUME_OVERRIDE);
        break;
    case SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE:
        LAST_KEYON_VOICE = SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], SFX_NOTE_OVERRIDE, 0, SFX_VOLUME_OVERRIDE, SFX_VOLUME_OVERRIDE);
        break;
    }
    return LAST_KEYON_VOICE;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", getSfxVabOffset);
inline s32 getSfxVabOffset(u16 arg0)
{
    u8 a = D_800778E4[arg0 * 2];
    u8 b = D_800778E5[arg0 * 2];

    return SFX_BANKS[a] + b * sizeof(SfxDef);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", keyOffSfxVoice);
inline s16 keyOffSfxVoice(s16 voice)
{
    u16 i = voice;

    if (VOICE_KEY_STATUS[i] != 0) {
        VOICE_PRIORITY[i] = 0xF;
        return SsUtKeyOffV(voice);
    }
    return -1;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", setSfxOverride);
s32 setSfxOverride(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_OVERRIDE_NOTE:
        SFX_NOTE_OVERRIDE = cmd & SND_CMD_VALUE_MASK;
        break;
    case SND_OVERRIDE_VOLUME:
        SFX_VOLUME_OVERRIDE = cmd & SND_CMD_VALUE_MASK;
        break;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", setBgmFadeParam);
s32 setBgmFadeParam(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_FADE_INTERVAL:
        BGM_FADE_INTERVAL = cmd & SND_CMD_VALUE_MASK;
        BGM_FADE_TIMER = 1;
        break;
    case SND_FADE_STEP:
        BGM_FADE_STEP = cmd & SND_CMD_VALUE_MASK;
        if ((cmd & SND_CMD_VALUE_MASK) >= 0x80) {
            BGM_FADE_STEP = (cmd & SND_CMD_VALUE_MASK) | 0xFF00;
        }
        break;
    case SND_FADE_TARGET:
        BGM_FADE_TARGET = cmd & SND_CMD_VALUE_MASK;
        break;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", setPitchSlideParam);
s32 setPitchSlideParam(s32 cmd)
{
    switch (cmd & SND_CMD_PARAM_MASK) {
    case SND_SLIDE_INTERVAL:
        PITCH_SLIDE_INTERVAL = cmd & SND_CMD_VALUE_MASK;
        PITCH_SLIDE_TIMER = 1;
        break;
    case SND_SLIDE_STEP:
        PITCH_SLIDE_STEP = cmd & SND_CMD_VALUE_MASK;
        if ((cmd & SND_CMD_VALUE_MASK) >= 0x80) {
            PITCH_SLIDE_STEP = (cmd & SND_CMD_VALUE_MASK) | 0xFF00;
        }
        break;
    case SND_SLIDE_DURATION:
        PITCH_SLIDE_DURATION = cmd & SND_CMD_VALUE_MASK;
        break;
    case SND_SLIDE_START:
        PITCH_SLIDE_ACTIVE = 1;
        PITCH_SLIDE_VOICE = LAST_KEYON_VOICE;
        break;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", allocSfxVoice);
s32 allocSfxVoice(id)
    u16 id;
{
    s32 i;
    u8 a;
    u8 b;
    u8 prio;

    for (i = 0x17; i >= 0x10; i--) {
        if (VOICE_KEY_STATUS[i] == 0 && VOICE_SFX_ID[i] == -1) {
            return i;
        }
    }
    {
        u8* e = (u8*)SFX_BANKS[D_800778E4[id * 2]] + D_800778E5[id * 2] * sizeof(SfxDef);
        prio = e[5];
    }
    for (i = 0x17; i >= 0x10; i--) {
        if (VOICE_PRIORITY[i] >= prio) {
            return i;
        }
    }
    return -1;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFX);
s32 playSFX(s32 arg)
{
    register s32 id asm("$16") = arg;
    s32 slot = allocSfxVoice(id);

    if (slot == -1) {
        return -1;
    }
    if (queueSoundCommand(id & SND_SFX_ID_MASK, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFXWithNote);
s32 playSFXWithNote(s32 id, s32 note)
{
    s32 slot = allocSfxVoice(id);

    if (slot == -1 || queueSoundCommand((note & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_NOTE), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | SND_KEYON_NOTE_OVERRIDE, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFXWithVolume);
s32 playSFXWithVolume(s32 id, s32 volume)
{
    s32 slot = allocSfxVoice(id);

    if (slot == -1 || queueSoundCommand((volume & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_VOLUME), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | SND_KEYON_VOLUME_OVERRIDE, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFXWithNoteAndVolume);
s32 playSFXWithNoteAndVolume(s32 id, s32 note, s32 volume)
{
    s32 slot;

    if ((GAME.selectedArea == AREA02_DWARFVILLAGE || GAME.selectedArea == AREA19_VILLAGEOFCIVILIZATIONPURIFIED) && id == 0x32) {
        id = 0x61;
    }
    slot = allocSfxVoice(id);
    if (slot == -1 || queueSoundCommand((note & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_NOTE), slot) == -1 || queueSoundCommand((volume & SND_CMD_VALUE_MASK) | (SND_CMD_OVERRIDE | SND_OVERRIDE_VOLUME), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand((id & SND_SFX_ID_MASK) | (SND_KEYON_NOTE_OVERRIDE | SND_KEYON_VOLUME_OVERRIDE), slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}


// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFXWithPitchSlide);
s32 playSFXWithPitchSlide(s32 id, s32 interval, s32 step, s32 duration)
{
    u8* e;
    s32 slot;
    s32 note;

    if (PITCH_SLIDE_ACTIVE != 0) {
        keyOffSfxVoice(PITCH_SLIDE_VOICE);
        PITCH_SLIDE_ACTIVE = 0;
    }
    e = (u8*)getSfxVabOffset(id);
    PITCH_SLIDE_VAB = VAB_IDS[e[0]];
    PITCH_SLIDE_PROG = e[1];
    note = e[3];
    PITCH_SLIDE_NEW_FINE = 0;
    PITCH_SLIDE_OLD_FINE = 0;
    PITCH_SLIDE_NEW_NOTE = note;
    PITCH_SLIDE_OLD_NOTE = note;
    slot = allocSfxVoice(id);
    if (slot == -1 || queueSoundCommand(id & SND_SFX_ID_MASK, slot) == -1 || queueSoundCommand((interval & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_INTERVAL), slot) == -1 || queueSoundCommand((step & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_STEP), slot) == -1 || queueSoundCommand((duration & SND_CMD_VALUE_MASK) | (SND_CMD_PITCH_SLIDE | SND_SLIDE_DURATION), slot) == -1) {
        return -1;
    }
    if (queueSoundCommand(SND_CMD_PITCH_SLIDE | SND_SLIDE_START, slot) != -1) {
        VOICE_SFX_ID[slot] = id;
    }
    return slot;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", keyOnSFX);
s16 keyOnSFX(s32 id)
{
    s32 voice = allocSfxVoice(id);
    u8* e = (u8*)(SFX_BANKS[D_800778E4[(id & SND_SFX_ID_MASK) * 2]] + D_800778E5[(id & SND_SFX_ID_MASK) * 2] * sizeof(SfxDef));

    return SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], e[3], 0, e[4], e[4]);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playSFXAndSetNote);
s16 playSFXAndSetNote(s32 id, s16 note)
{
    s32 voice = allocSfxVoice(id);
    u8* e = (u8*)(SFX_BANKS[D_800778E4[(id & SND_SFX_ID_MASK) * 2]] + D_800778E5[(id & SND_SFX_ID_MASK) * 2] * sizeof(SfxDef));

    return SsUtKeyOnV(voice, VAB_IDS[e[0]], e[1], e[2], note, 0, e[4], e[4]);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", queueSfxKeyOff);
void queueSfxKeyOff(s32 voice)
{
    queueSoundCommand((voice & SND_CMD_VALUE_MASK) | SND_CMD_KEY_OFF, voice);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", keyOffActiveSfxVoices);
void keyOffActiveSfxVoices(void)
{
    s32 i;

    for (i = 0x10; i < 0x18; i++) {
        if (VOICE_KEY_STATUS[i] != 0) {
            VOICE_PRIORITY[i] = 0xF;
            VOICE_SFX_ID[i] = -1;
            SsUtKeyOffV(i);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", startAreaBgm);
void startAreaBgm(void)
{
    openAreaBgm(-1);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", startAreaBgmWithReverb);
void startAreaBgmWithReverb(s16 reverbDepth)
{
    openAreaBgm(reverbDepth);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", adjustAreaBgmVolume);
inline s32 adjustAreaBgmVolume(s32 id)
{
    switch (GAME.selectedArea) {
    case 0:
    case 2:
        id += 5;
        break;
    case 6:
        switch (D_8009BCCA) {
        case 0:
            id -= 5;
            break;
        case 1:
            id += 0xC;
            break;
        case 2:
            id += 0xC;
            break;
        }
        break;
    case 9:
        switch (D_8009BCCA) {
        case 0:
            id -= 0xB;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            id += 0xA;
            break;
        }
        break;
    }
    return id;
}


// INCLUDE_ASM("nonmatchings/main/audio/sound", openAreaBgm);
s32 openAreaBgm(s32 reverbDepth)
{
    u16 vab;
    int t;
    int area;
    s32 depth;
    s32 mode;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    BGM_MUTED = 0;
    vab = VAB_IDS[AREA_BGM_DEFS[0].vab];
    BGM_VAB_ID = vab;
    BGM_SEQ_ID = SsSeqOpen(SEQ_DATA[AREA_BGM_DEFS[0].seq], vab);
    SsSetMVol(100, 100);
    do {
        t = (int)&GAME;
    } while (0);
    area = *(u16*)t;
    if (AREA_BGM_DEFS[area].fadeIn != 0) {
        SsSeqSetVol(BGM_SEQ_ID, 0, 0);
        area = (s16)AREA_BGM_VOLUME[*(u16*)t];
        BGM_FADE_VOLUME = 0;
        switch (GAME_A) {
        case 0:
        case 2:
            area += 5;
            break;
        case 6:
            switch (D_8009BCCA) {
            case 0:
                area -= 5;
                break;
            case 1:
                area += 0xC;
                break;
            case 2:
                area += 0xC;
                break;
            }
            break;
        case 9:
            switch (D_8009BCCA) {
            case 0:
                area -= 0xB;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                area += 0xA;
                break;
            }
            break;
        }
        BGM_FADE_TARGET = area;
        BGM_FADE_ACTIVE = 1;
    } else {
        t = adjustAreaBgmVolume((s16)AREA_BGM_VOLUME[area]);
        SsSeqSetVol(BGM_SEQ_ID, t, t);
        BGM_VOLUME = t;
        BGM_FADE_ACTIVE = 0;
    }
    depth = (s16)reverbDepth;
    mode = 1;
    if (depth < 0) {
        mode = GAME.selectedArea;
        depth = AREA_REVERB_DEPTH[mode][D_8009BCCA];
        mode = AREA_REVERB_MODE[mode];
        depth <<= 24;
        depth >>= 16;
    }
    setReverbMode(mode, depth);
    SsSeqPlay(BGM_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", startBgmTrack);
s32 startBgmTrack(s32 id)
{
    s16* vol;
    u16 vab;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    vab = VAB_IDS[BGM_TRACK_DEFS[id].vab];
    BGM_VAB_ID = vab;
    BGM_SEQ_ID = SsSeqOpen(SEQ_DATA[BGM_TRACK_DEFS[id].seq], vab);
    SsSetMVol(100, 100);
    SsSeqSetVol(BGM_SEQ_ID, BGM_TRACK_VOLUME[id], BGM_TRACK_VOLUME[id]);
#if REGION == REGION_EU
    BGM_MUTED = 0;
#endif
    BGM_FADE_ACTIVE = 0;
    BGM_VOLUME = BGM_TRACK_VOLUME[id];
    SsSeqPlay(BGM_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", stopBgm);
void stopBgm(s32 fadeOut)
{
    if (fadeOut != 0) {
        BGM_FADE_VOLUME = AREA_BGM_VOLUME[GAME.selectedArea] - 1;
        BGM_FADE_INTERVAL = 1;
        BGM_FADE_TIMER = 1;
        BGM_FADE_STEP = -1;
        BGM_FADE_ACTIVE = 1;
    } else {
        if (BGM_SEQ_ID != -1) {
            SsSeqStop(BGM_SEQ_ID);
            SsSeqClose(BGM_SEQ_ID);
            BGM_SEQ_ID = -1;
        }
        BGM_FADE_ACTIVE = 0;
    }
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", restoreAreaBgmVolume);
void restoreAreaBgmVolume(void)
{
    s16 vol;

    if (BGM_SEQ_ID != -1) {
        vol = adjustAreaBgmVolume((s16)AREA_BGM_VOLUME[GAME.selectedArea]);
        SsSeqSetVol(BGM_SEQ_ID, vol, vol);
        BGM_MUTED = 0;
    }
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", playJingle);
s32 playJingle(s32 seqIndex)
{
    u16 vab;

    if (JINGLE_SEQ_ID != -1) {
        SsSeqStop(JINGLE_SEQ_ID);
        SsSeqClose(JINGLE_SEQ_ID);
        JINGLE_SEQ_ID = -1;
    }
    if (seqIndex == 1) {
        if (BGM_SEQ_ID != -1) {
            SsSeqStop(BGM_SEQ_ID);
            SsSeqClose(BGM_SEQ_ID);
            BGM_SEQ_ID = -1;
        }
    }
    vab = (*(u16 *)&SPAD->vabIds[2]);
    JINGLE_VAB_ID = vab;
    JINGLE_SEQ_ID = SsSeqOpen(SEQ_DATA[seqIndex], vab);
    SsSetMVol(100, 100);
    SsSeqSetVol(JINGLE_SEQ_ID, 0x50, 0x50);
    SsSeqPlay(JINGLE_SEQ_ID, SSPLAY_PLAY, 1);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", queueSoundCommand);
s32 queueSoundCommand(cmd, param)
    u16 cmd;
    s32 param;
{
    s32 i;
    u16 idx = SOUND_QUEUE_HEAD;

    for (i = 0; i < SOUND_QUEUE_COUNT; i++) {
        if (SOUND_QUEUE[(s16)idx].id == cmd) {
            return -1;
        }
        idx = (idx + 1) & (SOUND_QUEUE_SIZE - 1);
    }
    SOUND_QUEUE[SOUND_QUEUE_TAIL].id = cmd;
    SOUND_QUEUE[SOUND_QUEUE_TAIL].arg = param;
    SOUND_QUEUE_TAIL = (SOUND_QUEUE_TAIL + 1) & (SOUND_QUEUE_SIZE - 1);
    SOUND_QUEUE_COUNT++;
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", stopAllSound);
void stopAllSound(void)
{
    s32 i;

    if (BGM_SEQ_ID != -1) {
        SsSeqStop(BGM_SEQ_ID);
        SsSeqClose(BGM_SEQ_ID);
        BGM_SEQ_ID = -1;
    }
    if (JINGLE_SEQ_ID != -1) {
        SsSeqStop(JINGLE_SEQ_ID);
        SsSeqClose(JINGLE_SEQ_ID);
        JINGLE_SEQ_ID = -1;
    }
    BGM_FADE_ACTIVE = 0;
    PITCH_SLIDE_ACTIVE = 0;
    for (i = 0; i < 0x18; i++) {
        VOICE_PRIORITY[i] = 0xF;
        VOICE_SFX_ID[i] = -1;
    }
    SOUND_QUEUE_TAIL = 0;
    SOUND_QUEUE_HEAD = 0;
    SOUND_QUEUE_COUNT = 0;
    SpuSetKey(SPU_OFF, SPU_ALLCH);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", setReverbMode);
void setReverbMode(s32 reverbMode, s16 reverbDepth)
{
    SpuReverbAttr attr;

    attr.mask = SPU_REV_MODE | SPU_REV_DEPTHL | SPU_REV_DEPTHR;
    attr.mode = reverbMode | SPU_REV_MODE_CLEAR_WA;
    attr.depth.left = reverbDepth;
    attr.depth.right = reverbDepth;
    SpuReserveReverbWorkArea(SPU_ON);
    SpuSetReverbModeParam(&attr);
    SpuSetReverb(SPU_ON);
    SpuSetReverbDepth(&attr);
    SpuSetReverbVoice(SPU_ON, BGM_VOICE_MASK);
    SpuSetReverbVoice(SPU_OFF, SFX_VOICE_MASK);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", muteBgm);
void muteBgm(void)
{
    BGM_MUTED = 1;
    SsSeqSetVol(BGM_SEQ_ID, 0, 0);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", unmuteBgm);
void unmuteBgm(void)
{
    BGM_MUTED = 0;
    SsSeqSetVol(BGM_SEQ_ID, BGM_VOLUME, BGM_VOLUME);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", keyOffSfxAll);
void keyOffSfxAll(void)
{
    SpuSetKey(SPU_OFF, SFX_VOICE_MASK);
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", shutdownSound);
void shutdownSound(void)
{
    s32 i;

    if (SOUND_INITIALIZED != 0) {
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
    
    SOUND_QUEUE_TAIL = 0;
    SOUND_QUEUE_HEAD = 0;
    SOUND_QUEUE_COUNT = 0;
    BGM_VOLUME = 0;
    BGM_FADE_ACTIVE = 0;
    PITCH_SLIDE_ACTIVE = 0;
    for (i = 0; i < 0x18; ++i) {
        VOICE_PRIORITY[i] = 0xF;
        VOICE_SFX_ID[i] = -1;
    }
    for (i = 0; i < 0x8; ++i) {
        (&D_1F8003B6-7)[i] = -1;
    }
    BGM_SEQ_ID = -1;
    JINGLE_SEQ_ID = -1;
    SOUND_INITIALIZED = 1;
}

// INCLUDE_ASM("nonmatchings/main/audio/sound", sndQuit);
void sndQuit(void)
{
    SOUND_INITIALIZED = 0;
    SsEnd();
    SsQuit();
}
