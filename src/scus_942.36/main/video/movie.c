#include "common.h"
#include "game.h"
#include "psyq/libcd.h"

short D_80077728[0x16] = {
    1414, 366, 316, 467, 110, 152, 181, 181,
    182, 227, 230, 227, 157, 231, 232, 232,
    232, 232, 232, 316, 943, 94
};

CdlATV D_80077754 = { 0x7F, 0, 0x7F, 0 };

CdlATV D_80077758 = { 0, 0, 0, 0 };

u_char D_8007775C[0x18] = {
    2, 3, 0, 1, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x15, 0x15
};


extern short D_80077728[];

typedef struct {
    u_long* vlcbuf[2];
    int vlcid;
    u_short* imgbuf[2];
    int imgid;
    RECT rect[2];
    int rectid;
    RECT slice;
    int isdone;
} DecEnv;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", movieDecodeNextFrame);
int movieDecodeNextFrame(DecEnv* dec)
{
    u_long* addr;
    StHEADER* header;
    register u_long* next asm("$16");

    do {
        if (StGetNext(&addr, (u_long**)&header) != 0) {
            next = NULL;
            break;
        }
        if (header->frameCount >= D_80077728[MOVIE_ID] - 3) {
            (CURRENT_TASK)->state0 = 3;
            CdMix(&D_80077758);
        }
        if (*(&SCRATCHPAD + 0x1CD) == 0x15 && (*(Task**)(&SCRATCHPAD + 0x1D4))->loadGameSelected == 0 && header->frameCount >= 0xF) {
            startBgmTrack(0);
            (CURRENT_TASK)->loadGameSelected = 1;
        }
        next = addr;
        dec->rect[0].w = dec->rect[1].w = header->width;
        dec->rect[0].h = dec->rect[1].h = header->height;
        dec->slice.h = header->height;
    } while (0);

    if (next == NULL) {
        asm("" : : : "$16");
        return 0;
    }
    dec->vlcid = 1 - dec->vlcid;
    DecDCTvlc(next, dec->vlcbuf[dec->vlcid]);
    StFreeRing(next);
    (CURRENT_TASK)->step.value = 1;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", cdSeekStream);
void cdSeekStream(short file_id)
{
    if (CdControl(CdlSetloc, (u_char*)&FILE_LINKS[MOVIE_FILE_IDS[D_8007775C[file_id]]], 0) != 0) {
        CdControlF(CdlSeekL, 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", moviePlayerTask);
void moviePlayerTask(void)
{   
    u_short state;
    Task* gameControl;
    Task* gameControlTemp;

    gameControl = CURRENT_TASK;
    MOVIE_PLAY_STATE = MOVIE_STATE_STARTING;
    gameControl->state0 = 0;
    gameControl->step.value = 0;
    gameControl->loadGameSelected = 0;
    do {
        if (MOVIE_SKIP_REQUEST == 1) {
            (CURRENT_TASK)->state0 = 3;
            CdMix(&D_80077758);
        }
        gameControlTemp = CURRENT_TASK;
        state = gameControlTemp->state0;
        switch (state) {
            case 0:
                movieInitDecodeEnv((DecEnv*)&MOVIE_DEC_ENV, 384, 256, 704, 256);
                startMovieStream((int)&FILE_LINKS[MOVIE_FILE_IDS[D_8007775C[MOVIE_ID]]]);
                gameControl = *(Task** )(&SCRATCHPAD+0x1D4);
                gameControl->state0+=1;
                do {
                } while (movieDecodeNextFrame((DecEnv*)&MOVIE_DEC_ENV) == 0);
                break;
            case 1:
                MOVIE_PLAY_STATE = MOVIE_STATE_PLAYING;
                gameControlTemp->state0 = 2;
            case 2:
                while ((CURRENT_TASK)->step.value == 0) {
                    movieDecodeNextFrame((DecEnv*)&MOVIE_DEC_ENV);
                }
                DecDCTin(*(MOVIE_DEC_VLCID + &MOVIE_DEC_ENV), 2);
                *(int*)&MOVIE_DEC_DISPENV->disp.w = FRAME_BUFFER_INDEX;
                MOVIE_DEC_DISPENV->screen.x = ((short*)&MOVIE_DEC_RECT_X)[(FRAME_BUFFER_INDEX) * 4];
                MOVIE_DEC_DISPENV->screen.y = ((short*)&MOVIE_DEC_RECT_Y)[(FRAME_BUFFER_INDEX) * 4];
                DecDCTout(
                    *(u_long**)&MOVIE_DEC_IMGBUF[MOVIE_DEC_IMGID],
                    (MOVIE_DEC_DISPENV->screen.w * MOVIE_DEC_DISPENV->screen.h) / 2
                );
                (CURRENT_TASK)->step.value = 0;
                while (movieDecodeNextFrame((DecEnv*)&MOVIE_DEC_ENV) == 0) {
                    if (*(int*)&MOVIE_DEC_DISPENV->isinter == 1) {
                        break;
                    }
                }
                if (*(int*)&MOVIE_DEC_DISPENV->isinter == 0) {
                    do {
                    } while (*(int*)&MOVIE_DEC_DISPENV->isinter == 0);
                }
                SetDispMask(1);
                *(int*)&MOVIE_DEC_DISPENV->isinter = 0;
                MOVIE_PLAY_STATE = MOVIE_STATE_ENDING;
                *(short* )0x1F8001E8 = 0;
                break;
            case 3:
                DecDCToutCallback(NULL);
                StUnSetRing();
                StClearRing();
                CdControlB(CdlPause, 0, 0);
                MOVIE_PLAY_STATE = MOVIE_STATE_IDLE;
                *(char* )(&SCRATCHPAD+0x1D3) = 0;
                exitTask();
                break;
        }
        sleepTask(1);
    } while(true);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", mdecSliceCallback);
void mdecSliceCallback(void)
{
    u_long* sliceRect = &MOVIE_DEC_DISPENV->screen;
    u_long* mdecImage = sliceRect - 0x8;
    int sliceSize;
    short screenX;
    int temp_v1;
    
    LoadImage(sliceRect, *(u_long**)&mdecImage[MOVIE_DEC_IMGID]);
    MOVIE_DEC_IMGID = 1 - MOVIE_DEC_IMGID;
    screenX = MOVIE_DEC_DISPENV->screen.x;
    MOVIE_DEC_DISPENV->screen.x += 0x10;

    asm("");
    temp_v1 = *(int*)&MOVIE_DEC_DISPENV->disp.w * 4;
    asm("");

    if (
            MOVIE_DEC_DISPENV->screen.x <
            (
                (((short*)&MOVIE_DEC_RECT_X)[temp_v1]) +
                (((short*)&MOVIE_DEC_RECT_W)[temp_v1])
            )
    ) {
        sliceSize = (MOVIE_DEC_DISPENV->screen.w * MOVIE_DEC_DISPENV->screen.h) / 2;
        DecDCTout(
            *(u_long**)&mdecImage[MOVIE_DEC_IMGID],
            sliceSize
        );
        return;
    }
    *(int*)&MOVIE_DEC_DISPENV->isinter = 1;
    MOVIE_DEC_DISPENV->screen.x = screenX;
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", movieInitDecodeEnv);
void movieInitDecodeEnv(DecEnv* dec, s32 x0, s32 y0, s32 x1)
{
    register s32 y1 asm("$3");

    dec->vlcbuf[0] = (u_long*)&LOAD_BUFFER_ALT;
    dec->vlcbuf[1] = (u_long*)&D_800C3188;
    dec->imgbuf[0] = (u_short*)&D_800D3188;
    dec->imgbuf[1] = (u_short*)&D_800D5188;
    dec->vlcid = 0;
    dec->imgid = 0;
    dec->rect[0].x = x0;
    dec->rect[0].y = y0;
    dec->rect[1].x = x1;
    dec->isdone = 0;
    dec->slice.w = 0x10;
    asm("");
    asm("lw $3, 16($sp)" : "=r"(y1));
    asm("");
    dec->slice.h = 0xE0;
    dec->rect[1].y = y1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", startMovieStream);
void startMovieStream(s32 arg0)
{
    int mode;
    
    DecDCTReset(0);
    DecDCToutCallback(&mdecSliceCallback);
    CdMix(&D_80077754);
    StSetRing(&D_800D7188, 0x20);
    StSetStream(0, 1, -1, 0, 0);
    do {

    } while (CdControl(CdlSetloc, arg0, 0) == 0);
    mode = CdlModeStream | CdlModeSpeed | CdlModeRT;
    do {
        
    } while (CdRead2(mode) == 0);
    return;
}
