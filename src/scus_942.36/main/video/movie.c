#include "common.h"
#include "game.h"
#include "psyq/libcd.h"


extern short D_80077728[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", func_8001EFE8);
int func_8001EFE8(int* dec)
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
        if (*(&SCRATCHPAD + 0x1CD) == 0x15 && (*(unkstruct_1F8001D4**)(&SCRATCHPAD + 0x1D4))->loadGameSelected == 0 && header->frameCount >= 0xF) {
            func_80020AF0(0);
            (CURRENT_TASK)->loadGameSelected = 1;
        }
        next = addr;
        *(s16*)((u8*)dec + 0x1C) = *(s16*)((u8*)dec + 0x24) = header->width;
        *(s16*)((u8*)dec + 0x1E) = *(s16*)((u8*)dec + 0x26) = header->height;
        *(s16*)((u8*)dec + 0x32) = header->height;
    } while (0);

    if (next == NULL) {
        asm("" : : : "$16");
        return 0;
    }
    dec[2] = 1 - dec[2];
    DecDCTvlc(next, (u_long*)dec[dec[2]]);
    StFreeRing(next);
    (CURRENT_TASK)->unk4E.value = 1;
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", cdSeekStream);
void cdSeekStream(short file_id)
{
    if (CdControl(CdlSetloc, (u_char*)&D_800791A0[D_80078F80[D_8007775C[file_id]]], 0) != 0) {
        CdControlF(CdlSeekL, 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", moviePlayerTask);
void moviePlayerTask(void)
{   
    u_short state;
    unkstruct_1F8001D4* gameControl;
    unkstruct_1F8001D4* gameControlTemp;

    gameControl = CURRENT_TASK;
    MOVIE_PLAY_STATE = MOVIE_STARTING;
    gameControl->state0 = 0;
    gameControl->unk4E.value = 0;
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
                func_8001F5D0(&D_8009B010, 384, 256, 704, 256);
                startMovieStream((int)&D_800791A0[D_80078F80[D_8007775C[MOVIE_ID]]]);
                gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                gameControl->state0+=1;
                do {
                } while (func_8001EFE8(&D_8009B010) == 0);
                break;
            case 1:
                MOVIE_PLAY_STATE = MOVIE_PLAYING;
                gameControlTemp->state0 = 2;
            case 2:
                while ((CURRENT_TASK)->unk4E.value == 0) {
                    func_8001EFE8(&D_8009B010);
                }
                DecDCTin(*(D_8009B018 + &D_8009B010), 2);
                *(int*)&D_8009B034->disp.w = FRAME_BUFFER_INDEX;
                D_8009B034->screen.x = ((short*)&D_8009B028)[(FRAME_BUFFER_INDEX) * 4];
                D_8009B034->screen.y = ((short*)&D_8009B02A)[(FRAME_BUFFER_INDEX) * 4];
                DecDCTout(
                    *(u_long**)&D_8009B01C[D_8009B024],
                    (D_8009B034->screen.w * D_8009B034->screen.h) / 2
                );
                (CURRENT_TASK)->unk4E.value = 0;
                while (func_8001EFE8(&D_8009B010) == 0) {
                    if (*(int*)&D_8009B034->isinter == 1) {
                        break;
                    }
                }
                if (*(int*)&D_8009B034->isinter == 0) {
                    do {
                    } while (*(int*)&D_8009B034->isinter == 0);
                }
                SetDispMask(1);
                *(int*)&D_8009B034->isinter = 0;
                MOVIE_PLAY_STATE = MOVIE_ENDING;
                *(short* )0x1F8001E8 = 0;
                break;
            case 3:
                DecDCToutCallback(NULL);
                StUnSetRing();
                StClearRing();
                CdControlB(CdlPause, 0, 0);
                MOVIE_PLAY_STATE = MOVIE_IDLE;
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
    u_long* sliceRect = &D_8009B034->screen;
    u_long* mdecImage = sliceRect - 0x8;
    int sliceSize;
    short screenX;
    int temp_v1;
    
    LoadImage(sliceRect, *(u_long**)&mdecImage[D_8009B024]);
    D_8009B024 = 1 - D_8009B024;
    screenX = D_8009B034->screen.x;
    D_8009B034->screen.x += 0x10;

    asm("");
    temp_v1 = *(int*)&D_8009B034->disp.w * 4;
    asm("");

    if (
            D_8009B034->screen.x <
            (
                (((short*)&D_8009B028)[temp_v1]) +
                (((short*)&D_8009B02C)[temp_v1])
            )
    ) {
        sliceSize = (D_8009B034->screen.w * D_8009B034->screen.h) / 2;
        DecDCTout(
            *(u_long**)&mdecImage[D_8009B024],
            sliceSize
        );
        return;
    }
    *(int*)&D_8009B034->isinter = 1;
    D_8009B034->screen.x = screenX;
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", func_8001F5D0);
void func_8001F5D0(u8* arg0, s32 arg1, s32 arg2, s32 arg3)
{
    register s32 arg4 asm("$3");

    *(int*)arg0 = (int)&D_800B3188;
    *(int*)(arg0 + 4) = (int)&D_800C3188;
    *(int*)(arg0 + 0xC) = (int)&D_800D3188;
    *(int*)(arg0 + 0x10) = (int)&D_800D5188;
    *(int*)(arg0 + 8) = 0;
    *(int*)(arg0 + 0x14) = 0;
    *(s16*)(arg0 + 0x18) = arg1;
    *(s16*)(arg0 + 0x1A) = arg2;
    *(s16*)(arg0 + 0x20) = arg3;
    *(int*)(arg0 + 0x34) = 0;
    *(s16*)(arg0 + 0x30) = 0x10;
    asm("");
    asm("lw $3, 16($sp)" : "=r"(arg4));
    asm("");
    *(s16*)(arg0 + 0x32) = 0xE0;
    *(s16*)(arg0 + 0x22) = arg4;
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
