#include "common.h"
#include "game.h"

#define D_8009B034 ((DISPENV*)((byte*)&D_8009B010+0x24))
#define D_8009B01C ((u_long*)((byte*)&D_8009B010+0xC))

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", func_8001EFE8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", cdSeekStream);
void cdSeekStream(short file_id)
{
    if (CdControl(2, (*(&D_80078F80 + (*(&D_8007775C[file_id]) * 1)) * 2) + &D_800791A0, 0) != 0) {
        CdControlF(0x15, 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", moviePlayerTask);
void moviePlayerTask(void)
{   
    u_short state;
    unkstruct_1F8001D4* gameControl;
    unkstruct_1F8001D4* gameControlTemp;

    gameControl = CURRENT_TASK;
    MOVIE_PLAY_STATE = 1;
    gameControl->state0 = 0;
    gameControl->unk4E.value = 0;
    gameControl->loadGameSelected = 0;
    do {
        if (*(u_char* )0x1F8001D3 == 1) {
            (CURRENT_TASK)->state0 = 3;
            CdMix(&D_80077758);
        }
        gameControlTemp = CURRENT_TASK;
        state = gameControlTemp->state0;
        switch (state) {
            case 0:
                func_8001F5D0(&D_8009B010, 384, 256, 704, 256);
                startMovieStream((int) (((&D_80078F80)[D_8007775C[*(u_char* )0x1F8001CD]] * 2) + &D_800791A0));
                gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                gameControl->state0+=1;
                do {
                } while (func_8001EFE8(&D_8009B010) == 0);
                break;
            case 1:
                MOVIE_PLAY_STATE = 2;
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
                MOVIE_PLAY_STATE = 3;
                *(short* )0x1F8001E8 = 0;
                break;
            case 3:
                DecDCToutCallback(NULL);
                StUnSetRing();
                StClearRing();
                CdControlB(9, 0, 0);
                MOVIE_PLAY_STATE = 0;
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/video/movie", func_8001F5D0);

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

    } while (CdControl(2, arg0, 0) == 0);
    mode = 0x1C0;
    do {
        
    } while (CdRead2(mode) == 0);
    return;
}
