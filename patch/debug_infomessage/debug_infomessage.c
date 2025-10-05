#include "common.h"
#include "game.h"

// extern int sprintf(char* buffer, const char* fmt, ...);
// extern int FontDebugPrintf(short x, short y, short color, char* fmt);
extern u_char setEventComplete(EVENT event_id, int state);
extern void printInfoMessage(int message_id, int arg1);

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
                var_v1 = &GAME.unk21;
            break;
        case 1:
                var_v1 = &GAME.unk28;
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
    FontDebugPrintf(102, 26, 0U, "DEBUG TEST MENU");
    FontDebugPrintf(52, 36, 0U, "TOMBA DECOMPILATION PROJECT");
    sprintf(&SPRINTF_BUFFER_MSG, "INFO MESSAGE TEST = %02d", GAME.unk21);
    FontDebugPrintf(32, 198, 0U, &SPRINTF_BUFFER_MSG);
    sprintf(&SPRINTF_BUFFER_MSG, "TYPE MESSAGE TEST = %02d", GAME.unk28);
    FontDebugPrintf(32, 206, 0U, &SPRINTF_BUFFER_MSG);
    sprintf(&SPRINTF_BUFFER_MSG, "*");
    FontDebugPrintf(24, 102+((short) D_8009B6A8 + 0xC) * 8, (u_long) (*(u_short*)&PSX_SCRATCH[0x1F6] & 0xC) >> 2, &SPRINTF_BUFFER_MSG);
    /*
    0x0001 Button SELECT
    0x0002 Button L3
    0x0004 Button R3
    0x0008 Button START
    0x0010 Button UP
    0x0020 Button RIGHT
    0x0040 Button DOWN
    0x0080 Button LEFT
    0x0100 Button L2
    0x0200 Button R2
    0x0400 Button L1
    0x0800 Button R1
    0x1000 Button TRIANGLE
    0x2000 Button CIRCLE
    0x4000 Button CROSS
    0x8000 Button SQUARE
    */
    if (scratch->unk1FC & 0x8000) {
        printInfoMessage(GAME.unk21, GAME.unk28);
    }
    return;
}
