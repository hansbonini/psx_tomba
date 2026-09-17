#include "common.h"
#include "game.h"
#include "psyq/libcd.h"


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", main);
void main(void)
{
    u8 cdMode;
    u16 toggled;
    u16 flags;
    u16 targetFrame;
    u16 joypad_state;
    u16 newFlags;
    u16 curFlags;
    s32 dbgMode;
    u_short* joypad_state_ptr;

    SetDispMask(0);
    SetVideoMode(MODE_NTSC);
    ResetCallback();
    initGlobalState();
    ResetGraph(0);
    SetGraphDebug(0);
    InitGeom();
    CdInit();
    cdMode = CdlModeSpeed;
    while (CdControl(CdlSetmode, &cdMode, 0) == 0);
    DecDCTReset(0);
    CD_QUEUE_TAIL = 0;
    CD_QUEUE_HEAD = 0;
    initGraphics();
    GsSetOrigin(1, 1);
    func_800211A4();
    SetDefDispEnv(&D_8009AFE8, 0, 0, 512, 240);
    memCardInit();
    joypadInit();
    initTasks();
    startTask(0, bootSequenceTask);
    EnterCriticalSection();
    *(s32*)0x1F8001D8 = OpenEvent(RCntCNT3, EvSpINT, RCntMdINTR, &vblankHandler);
    ExitCriticalSection();
    joypad_state_ptr = &D_8009EB5A;
    EnableEvent(*(u32*)(&D_1F8000C0[0]+0x118));
    SetDispMask(1);
    while (true) {
        *(u16*)((byte*)&D_1F8001A0+0x48) = 0;
        if (*(u16*)(&SCRATCHPAD+0x1F0) < 0x4001U) {
            D_8009C8A8 = (FRAME_BUFFER_INDEX * 0x780) + &D_800A1890;
            dispatchTasks();
        }
        if (*(u16*)0x1F8001EC != 0) {
            DrawSync(0);
        }
        targetFrame = *(u16*)(&D_1F8000C0[0]+0x12A);
        while (((unkstruct_1F8001D4*)0x1F8001D4)->unk14 < targetFrame) {
        }
        if (*(u16*)(&SCRATCHPAD+0x1EC) == 0) {
            ResetGraph(1);
        }
        if ((*(u8*)0x1F8001BD != 0) && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0)) {
            while (~*joypad_state_ptr & JOY_R2) {
                if (~*joypad_state_ptr & JOY_LEFT) {
                    D_8009AFE8.disp.x -= 4;
                }
                if (~*joypad_state_ptr & JOY_RIGHT) {
                    D_8009AFE8.disp.x += 4;
                }
                if (~*joypad_state_ptr & JOY_UP) {
                    D_8009AFE8.disp.y -= 4;
                }
                if (~*joypad_state_ptr & JOY_DOWN) {
                    D_8009AFE8.disp.y += 4;
                }
                VSync(0);
                PutDispEnv(&D_8009AFE8);
                do {} while (0);
            }
        }

        switch (MOVIE_PLAY_STATE) {
            case 2:
                break;
            case 0:
            case 1:
                if (PAUSE_FLAGS <= 0x4000) {
                    flipFrameBuffer();
                    tickTaskTimers();
                }
                break;
            case 3:
                *(u8*)(&SCRATCHPAD+0x1CC) = 2;
                if (PAUSE_FLAGS <= 0x4000) {
                    flipFrameBuffer();
                    tickTaskTimers();
                }
                break;
        }

        if (*(u8*)0x1F8001BF != 0) {
            if ((MOVIE_PLAY_STATE == 0) && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0) && (LOAD_COMPLETE == 1) && (JOYPAD_STATE & JOY_L1)) {
                *(u16*)(&SCRATCHPAD+0x1F0) = (u16)(0x8000 - PAUSE_FLAGS);
            }
        } else if (*(u8*)0x1F8001BE != 0 && MOVIE_PLAY_STATE == 0 && ((*(u8*)0x1F8001D1 | *(u8*)0x1F8001D0) != 0)) {
            dbgMode = LOAD_COMPLETE;
            if (dbgMode == 1) {
                joypad_state = JOYPAD_STATE;
                if (joypad_state & JOY_L1) {
                    toggled = 1 - PAUSE_TOGGLE;
                    *(u16*)(&SCRATCHPAD+0x1EE) = toggled;
                    PAUSE_FLAGS = (u16)(toggled << 0xF);
                }
                if (PAUSE_TOGGLE != 0) {
                    PAUSE_FLAGS = 0x8000U;
                    if (joypad_state & JOY_L2) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = 0U;
                    }
                } else if (joypad_state & JOY_L2) {
                    flags = PAUSE_FLAGS;
                    newFlags = (~flags & 0x4000) | (flags & 0xBFFF);
                    *(u16*)(&D_1F800118[0]+0xD8) = newFlags;
                    if (!(newFlags & 0x4000)) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = (u16)(newFlags & 0xFFF0);
                    }
                } else {
                    curFlags = PAUSE_FLAGS;
                    if (curFlags & 0x4000) {
                        *(u16*)(&SCRATCHPAD+0x1F0) = (u16)((curFlags + 1) & 0xFFF3);
                    }
                }
            }
        }   
    };
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", flipFrameBuffer);
void flipFrameBuffer(void)
{
    short bufIndex;
    u_long* ot;
    u_long* prevOt;

    bufIndex = 1 - *(u_short* )(0x1F8001F4);
    ot = (bufIndex * 0xD10) + (byte*)&OT_FRAMEBUFFER;
    prevOt = *(u_long** )((byte*)&D_1F8000C0[0]+0x120);
    *(u_short* )(&SCRATCHPAD+0x1f4) = (u_short) bufIndex;
    *(u_long* )(&SCRATCHPAD+0x1E0) = ot;
    *(u_long** )(&SCRATCHPAD+0x1E4) = prevOt;
    PutDispEnv(ot + 0x328);
    PutDrawEnv(CURRENT_OT + 0xCB4);
    compactOrderingTable(*(u_long* )(&SCRATCHPAD+0x1E4) + 0xC9C);
    DrawOTag(*(u_long* )(&SCRATCHPAD+0x1E4) + 0xC9C);
    ClearOTagR(*(u_long* )(&SCRATCHPAD+0x1E0), 0x328);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", GsSetOrigin);
void GsSetOrigin(short id, short arg1)
{
    scratchpad* scratch = PSX_SCRATCH;

    scratch->unk1EA = id;
    scratch->useDrawSync = arg1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGlobalState);
void initGlobalState(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    
    D_8009EB5A = 0xFFFF;
    D_8009EB7C = 0xFFFF;
    scratch->unk3D3 = 0xFF;
    scratch->unk3D2 = 0xFF;
    scratch->pauseFlags = 0;
    scratch->unk1F2 = 0;
    scratch->pauseToggle = 0;
    scratch->frameCount = 0;
    scratch->unk1F8 = 0;
    scratch->moviePlayState = 0;
    scratch->unk1D0 = 0;
    scratch->unk1D1 = 0;
    scratch->loadComplete = 0;
    scratch->unk1CF = 0;
    scratch->movieSkipRequest = 0;
    scratch->unk1C6 = 0;
    scratch->unk1C4 = 0;
    scratch->unk1C5= 0;
    scratch->unk3CC = 0;
    D_8009C9DA = 0;
    D_8009C9DE = 0;
    D_8009C940 = 0;
    D_8009EB52 = 0;
    D_8009C864 = 0;
    D_8009C866 = 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGraphics);
void initGraphics(void)
{
    RECT rect;
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    MATRIX* matrix = (MATRIX*)0x1F8000F8;

    SetGeomOffset(160, 112);
    SetGeomScreen(544);
    matrix->m[0][0] = 4096;
    matrix->m[0][1] = 0;
    matrix->m[0][2] = 0;
    matrix->m[1][0] = 0;
    matrix->m[1][1] = 4096;
    matrix->m[1][2] = 0;
    matrix->m[2][0] = 0;
    matrix->m[2][1] = 0;
    matrix->m[2][2] = 4096;
    matrix->t[2] = 0;
    matrix->t[1] = 0;
    matrix->t[0] = 0;
    getBaseMatrix((MATRIX*)(&D_1F8000C0));
    camera->vrx= 0;
    camera->vry = 0;
    camera->vrz= -544;
    camera->vpx = 0;
    camera->vpy = 0;
    camera->vpz = 0;
    func_80024B3C((MATRIX*)(&D_1F800118));
    initDisplay(96U, 151U, 255U);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage(&rect, 0U, 0U, 0U);
    ClearOTagR(&OT_FRAMEBUFFER, 0x328);
    ClearOTagR(&OT_FRAMEBUFFER + 0x344, 0x328);
    *(short* )&PSX_SCRATCH[0x1F4] = 0;
    *(u_int** )&PSX_SCRATCH[0x1E0] = &OT_FRAMEBUFFER;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay);
void initDisplay(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 256, 320, 224);
    SetDefDispEnv(dispenv1, 704, 256, 320, 224);
    SetDefDrawEnv(drawenv2, 704, 256, 320, 224);
    SetDefDispEnv(dispenv2, 384, 256, 320, 224);
    setWH(&dispenv1->screen, 256, 224);
    setWH(&dispenv2->screen, 256, 224);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = false;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    setXY(&dispenv1->screen, D_8009C864, D_8009C866);
    setXY(&dispenv2->screen, D_8009C864, D_8009C866);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay2x);
void initDisplay2x(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 0, 640, 480);
    SetDefDispEnv(dispenv1, 384, 0, 640, 480);
    SetDefDrawEnv(drawenv2, 384, 0, 640, 480);
    SetDefDispEnv(dispenv2, 384, 0, 640, 480);
    setRECT(&dispenv1->screen, 0, 0, 256, 240);
    setRECT(&dispenv2->screen, 0, 0, 256, 240);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = true;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}
