#include "common.h"
#include "game.h"

// extern int sprintf(char* buffer, const char* fmt, ...);
// extern int FontDebugPrintf(short x, short y, short color, char* fmt);
extern void playSFX(u_long sfx_id);
extern void playBGM(u_long bgm_id);
extern void stopMusic(int volume);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", displayDebugScreen);
extern void displayDebugScreen(void)
{
    typedef inline struct {
        char data[0x1B4];
        u_char unk1B4;
        char pad1[23];
        char unk1CF;
        char pad2[7];
        char unk1D4;
        char pad3[33];
        char unk1F6;
        char unk1F7;
        char unk1F8;
        char unk1F9;
        char unk1FA;
        char unk1FB;
        u_short unk1FC;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1 = *(unkstruct_1F8001D4**)&scratch->unk1D4;
    
    u_short var_a0;
    int* var_v1;
    u_short temp_a0;
    u_long temp_v1_2;
    u_char* temp_v1_3;
    u_char *temp2;

        if (scratch->unk1FC & 0x10) {  // button up pressed
            D_8009B6A8 = (D_8009B6A8 - 1) & 1;
        }
        if ((scratch->unk1FC & 0x40) != 0) { // button down pressed
            D_8009B6A8 = (D_8009B6A8 + 1) & 1;
        }

    switch (D_8009B6A8) {
        case 0:
                var_v1 = &GAME.selectedArea;
            break;
        case 1:
                var_v1 = &GAME.selectedSection;
            break;
    }
    if ((scratch->unk1FC & 0x80) != 0) { // button left pressed
        *(u_short*)var_v1 -= 1;
        if ((*(u_short*)var_v1 << 0x10) <= 0) {
            *(u_short*)var_v1 = 0U;
        }
    } else if (scratch->unk1FC & 0x20) { // button right pressed
        *(u_short*)var_v1 += 1;
        // temp_v1_2 = (u_short*)D_8007B290; // max areas
        temp_v1_2 = 0xFF;
        if (temp_v1_2 < *(u_short*)var_v1) {
            *(u_short*)var_v1 = temp_v1_2;
        }
    }
    FontDebugPrintf(102, 46, 0U, "SOUND TEST MENU");
    FontDebugPrintf(52, 56, 0U, "TOMBA DECOMPILATION PROJECT");
    sprintf(&SPRINTF_BUFFER_MSG, "SFX TEST = %02d", GAME.selectedArea);
    FontDebugPrintf(32, 96, 0U, &SPRINTF_BUFFER_MSG);
    sprintf(&SPRINTF_BUFFER_MSG, "BGM TEST = %02d", GAME.selectedSection);
    FontDebugPrintf(32, 104, 0U, &SPRINTF_BUFFER_MSG);
    sprintf(&SPRINTF_BUFFER_MSG, "*");
    FontDebugPrintf(24, ((short) D_8009B6A8 + 0xC) * 8, (u_long) (*(u_short*)&PSX_SCRATCH[0x1F6] & 0xC) >> 2, &SPRINTF_BUFFER_MSG);
    if (scratch->unk1FC & 0x2008) { // button O pressed
        stopMusic(0);
        if (D_8009B6A8 == 0) {
            playSFX(GAME.selectedArea);
        } else {
            *(u_short*)0x1F8003AC = GAME.selectedSection;
            playBGM(0);
        }
    }
    else return;

}
