#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_80019020);
void memCardInit(void)
{
    EnterCriticalSection();
    MEMCARD_SW_END_IO = OpenEvent(SwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_END_ERROR = OpenEvent(SwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_TIMEOUT = OpenEvent(SwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_NEW_DEVICE = OpenEvent(SwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_IO = OpenEvent(HwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_ERROR = OpenEvent(HwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_TIMEOUT = OpenEvent(HwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_NEW_DEVICE = OpenEvent(HwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    InitCARD(0);
    ExitCriticalSection();
    StartCARD();
    _bu_init();
    EnableEvent(MEMCARD_SW_END_IO);
    EnableEvent(MEMCARD_SW_END_ERROR);
    EnableEvent(MEMCARD_SW_TIMEOUT);
    EnableEvent(MEMCARD_SW_NEW_DEVICE);
    EnableEvent(MEMCARD_HW_END_IO);
    EnableEvent(MEMCARD_HW_END_ERROR);
    EnableEvent(MEMCARD_HW_TIMEOUT);
    EnableEvent(MEMCARD_HW_NEW_DEVICE);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", bootSequenceTask);
void bootSequenceTask(void)
{
    u16 state;
    unkstruct_1F8001D4* task5;
    unkstruct_1F8001D4* task6;
    unkstruct_1F8001D4* task7;
    unkstruct_1F8001D4* task8;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;
    unkstruct_1F8001D4* task4;
    unkstruct_1F8001D4* task9;

    D_8009D6DD = 0;
    D_8009D6DE = 0;
    D_8009D6DF = 0;
    D_8009E3ED = 0;
    D_8009E3EE = 0;
    D_8009E3EF = 0;
    *(s8* )0x1F8001D1 = 0;
    *(s8* )0x1F8001D0 = 0;
    D_8009E744 = 0;
    D_8009C9E4 = 1;
    D_8009E450 = 0;
    func_80023A3C();
    task = CURRENT_TASK;
    task->state0 = 9U;
    task->state1 = 0U;
    task->state2 = 0;
    SetDispMask(0);
    do {
        state = (CURRENT_TASK)->state0;
        switch (state) {
            case 0:
                LOAD_COMPLETE = 0;
                func_800223A0(0);
                func_800223A0(1);
                func_800222B8(0, 1);
                *(s8* )0x1F8001C4 = 0;
                *(s8* )0x1F8001C5 = 0;
                memset(D_1F8001A0, 0, sizeof(D_1F8001A0));
                task9 = CURRENT_TASK;
                task9->state0++;
                break;
            case 1:
                if (LOAD_COMPLETE != 0) {
                    cdSeekStream(0x15);
                    (CURRENT_TASK)->state0 = 4U;
                }
                break;
            case 2:
                SetDispMask(1);
                task5 = CURRENT_TASK;
                task5->timer = 120;
                task5->state0++;
                break;
            case 3:
                task7 = CURRENT_TASK;
                NEXT_PRIM = (s32) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
                task7->timer--;
                if ((s16) task7->timer == -1) {
                    task7->state0++;
                }
                fontDebugPrintf(0x50, 0x60, 0, &D_80010000);
                fontDebugPrintf(0x50, 0x70, 0, &D_80010008);
                break;
            case 4:
                task2 = CURRENT_TASK;
                task2->state0 = 0U;
                task2->state1 = 1U;
                task2->state2 = 0;
                setTask((s32*)titleSequenceTask);
                break;
            case 9:
                SetDispMask(0);
                *(byte* )0x1F8001CE = 0U;
                func_800222B8(0x5E, 1);
                (CURRENT_TASK)->state0 = 0xAU;
                break;
            case 10:
                if (LOAD_COMPLETE != 0) {
                    SetDispMask(0);
                    initDisplay2x(0U, 0U, 0U);
                    SetDispMask(1);
                    task3 = CURRENT_TASK;
                    task3->timer = 240;
                    task3->state0 = 0xBU;
                    task3->state1 = 0U;
                }
                break;
            case 11:
                task8 = CURRENT_TASK;
                NEXT_PRIM = (s32) ((s32) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF);
                switch (task8->state1) {                    // switch 1; irregular
                    case 0:                             // switch 1
                        task8->unk5A = 1U;
                        task8->state1++;
                        break;
                    case 1:                             // switch 1
                        task8->unk5A++;
                        if ((s16) task8->unk5A >= 0x80) {
                            task8->timer = 0xB4U;
                            task8->state1++;
                            break;
                        }
                        break;
                    case 2:                             // switch 1
                        task8->timer--;
                        if ((s16) task8->timer == -1) {
                            task8->state1++;
                        }
                        break;
                    case 3:                             // switch 1
                        task8->unk5A--;
                        if ((s16)task8->unk5A == 0) {
                            SetDispMask(0);
                            initDisplay(0U, 0U, 0U);
                            task4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            *(byte* )0x1F8001D1 = 0;
                            *(s16* )0x1F8001F6 = 0;
                            task4->state0 = 0U;
                            task4->state1 = 0U;
                        }
                        break;
                }
                task6 = CURRENT_TASK;
                if (*(u16*)&task6->state0 == 0xB) {
                    func_8001964C((u8) task6->unk5A, 1);
                }
                break;
        }
        sleepTask(1);
    } while(true);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_8001964C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", titleSequenceTask);
void titleSequenceTask(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(unkstruct_1F8001D4**)scratch->currentTask;

    u32 sp10[2];
    u16 state;

    *(s8* )&scratch->unk1D1 = 1;
    *(s8* )&scratch->unk1D0 = 0;
    sp10[0] = 0;
    scratch->currentTask->titleScreenSelectedOption = 0;
    while(true) {
        *(u16* )0x1F8001F8 = *(u16* )(D_1F8000F8+0x100) + 1;
        asm("");
        func_800223E0();
        task = CURRENT_TASK;
        state = task->state0;
        if ((state >= 3U) && (JOYPAD_STATE & (JOY_CROSS | JOY_START)) && (state != 4)) {
            task->state0 = 4U;
            task->state1 = 0;
            task->state2 = 0;
            sp10[0] = 1;
            func_80020C00(0);
            if (MOVIE_PLAY_STATE != 0) {
                MOVIE_SKIP_REQUEST = 1;
            }
        }
        switch ((u16)(CURRENT_TASK)->state0) {
            case 0:
                func_800199B8(sp10);
                break;
            case 1:
                func_80019CA4();
                break;
            case 2:
                func_8001A328();
                break;
            case 3:
                func_80019D78();
                break;
            case 4:
                loopTitleScreen(sp10);
                break;
        }
        sleepTask(1);
    };
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_800199B8);
void func_800199B8(void)
{
    u16 state2;
    u16 timer;
    u16 state1;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;
    unkstruct_1F8001D4* task4;
    unkstruct_1F8001D4* task5;
    unkstruct_1F8001D4* task6;
    unkstruct_1F8001D4* task7;
    unkstruct_1F8001D4* task8;

    state1 = (CURRENT_TASK)->state1;
    switch (state1) {
        case 0:
            task3 = CURRENT_TASK;
            state2 = task3->state2;
            switch (state2) {                      // switch 1; irregular
                case 0:                             // switch 1
                    SetDispMask(0);
                    LOAD_COMPLETE = 0U;
                    func_800223A0(1);
                    func_800222B8(1, 1);
                    task4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                    task4->state2++;
                    return;
                case 1:                             // switch 1
                    if (LOAD_COMPLETE != 0) {
                        task3->state1 = 2U;
                        task3->state2 = 0U;
                        func_800E7D5C();
                        return;
                    }
                default:
                    return;
            }
            break;
        case 1:
            SetDispMask(0);
            func_800E7D5C();
            task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            task5->state1++;
            return;
        case 2:
            task2 = CURRENT_TASK;
            MOVIE_PLAY_STATE = 1;
            MOVIE_ID = 0x15;
            task2->state1++;
            openTask(1, moviePlayerTask);
            return;
        case 3:
            if (MOVIE_PLAY_STATE != 0) {
                return;
            }
            task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            task5->state1++;
            return;
        case 4:
            SetDispMask(0);
            initDisplay2x(240U, 240U, 240U);
            SetDispMask(1);
            NEXT_PRIM = (s32) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
            func_800E7D74();
            task = CURRENT_TASK;
            task->timer = 120;
            task->state1++;
            return;
        case 5:
            NEXT_PRIM = (s32) ((s32) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF);
            func_800E7D74();
            task6 = CURRENT_TASK;
            timer = task6->timer - 1;
            task6->timer = timer;
            if ((timer << 0x10) <= 0) {
                func_80020C00(0);
                SetDispMask(0);
                initDisplay(0U, 0U, 0U);
                LOAD_COMPLETE = 0U;
                func_800223A0(2);
                func_800222B8(2, 1);
                task5 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                task5->state1++;
                return;
            }
            break;
        case 6:
            if (LOAD_COMPLETE != 0) {
                task7 = CURRENT_TASK;
                task7->state1++;
                cdSeekStream(0);
                return;
            }
            break;
        case 7:
            task8 = CURRENT_TASK;
            task8->state0 = 3;
            task8->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_80019CA4);
void func_80019CA4(void)
{
    unkstruct_1F8001D4* task2;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = scratch->currentTask;

    switch (task->state1) {                              // irregular
        case 0:
            SetDispMask(0);
             *(u8* )&scratch->loadComplete = 0;
            func_800223A0(2);
            func_800222B8(2, 1);
            scratch->currentTask->state1++;
            return;
        case 1:
            if (*(u8* )&scratch->loadComplete != 0) {
                task->state1++;
                cdSeekStream(0);
                return;
            }
            return;
        case 2:
            task2 = *(u_long**)&scratch->currentTask;
            task2->state0 = 4;
            task2->state1 = 0;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_80019D78);
void func_80019D78(void)
{
    u8 temp_v0;
    unkstruct_1F8001D4* task2;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = scratch->currentTask;
    
    switch (task->state1) {
        case 0:
            SetDispMask(0);
            initDisplay(0U, 0U, 0U);
            *(u8* )&scratch->moviePlayState = 1;
            *(s8* )&scratch->movieId = 0;
            scratch->currentTask->state1 ++;
            openTask(1, &moviePlayerTask);
            break;
        case 1:
            temp_v0 = *(u_long**)&scratch->moviePlayState;
            if (temp_v0 == 0) {
                task->state1++;
                return;
            }
            break;
        case 2:
            func_80020C00(0);
            task2 = *(u_long**)&scratch->currentTask;
            task2->state0 = 4;
            task2->state1 = 0;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", loopTitleScreen);
void loopTitleScreen(int* arg0)
{
    int amount;
    unkstruct_1F8001D4* gameControl;
    unkstruct_1F8001D4* gameControlTemp;
    unkstruct_1F8001D4* gameControlTemp2;
    unkstruct_1F8001D4* gameControlTemp3;
    unkstruct_1F8001D4* gameControlTemp4;
    unkstruct_1F8001D4* gameControlTemp5;
    unkstruct_1F8001D4* gameControlTemp6;
    unkstruct_1F8001D4* gameControlTemp7;

    switch ((CURRENT_TASK)->state1) {
        case 0:
            SetDispMask(0);
            gameControl = CURRENT_TASK;
            gameControl->state2 = 0U;
            gameControl->state1++;
        case 1:
            if (MOVIE_PLAY_STATE == 0) {
                initDisplay(0U, 0U, 0U);
                gameControl = CURRENT_TASK;
                gameControl->state1++;
                return;
            }
        default:
            return;
        case 2:
            func_800E7DA4();
            SetDispMask(1);
            func_80020AF0(0);
            printTitleScreenMessage(48, 192, TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT);
            (CURRENT_TASK)->titleScreenSelectedOption = TITLESCREEN_NEWGAME;
            gameControl = (*(unkstruct_1F8001D4** )((byte*)D_1F8001A0+0x34));
            gameControl->unk6A = (u_char) D_80076E80[gameControl->titleScreenSelectedOption];
            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
            gameControl->unk6B = (u_char) D_80076E80[gameControl->titleScreenSelectedOption];
            gameControlTemp = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            gameControlTemp->timer = 972;
            gameControlTemp->state1++;
            return;
        case 3:
            gameControlTemp5 = *(unkstruct_1F8001D4** )((byte*)D_1F8001A0+0x34);
            NEXT_PRIM = (int) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
            gameControlTemp5->timer--;
            if ((short)gameControlTemp5->timer <= 0) {
                gameControlTemp5->state1++;
            }
            func_800E7DDC(arg0);
            if (*&D_8009C9D8 != 0) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->timer = 972;
            }
            gameControlTemp2 = CURRENT_TASK;
            switch ((u_short)gameControlTemp2->state2) {                    // switch 1; irregular
                case 0:                             // switch 1
                    if (JOYPAD_STATE & JOY_LEFT) {
                        if (gameControlTemp2->titleScreenSelectedOption != 0) {
                            gameControlTemp2->titleScreenSelectedOption--;
                            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControl->unk6B = (u_char) D_80076E80[gameControl->titleScreenSelectedOption];
                            gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControl->state2++;
                            playSFX(8);
                        }
                    }
                    if (JOYPAD_STATE & JOY_RIGHT) {
                        gameControlTemp3 = CURRENT_TASK;;
                        if (gameControlTemp3->titleScreenSelectedOption < 2U) {
                            gameControlTemp3->titleScreenSelectedOption++;
                            gameControl = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControl->unk6B = (u_char) D_80076E80[gameControl->titleScreenSelectedOption];
                            gameControl = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControl->state2++;
                            playSFX(8);
                        }
                    }
                    if (JOYPAD_STATE & (JOY_CROSS | JOY_START)) {
                        func_80020C00(0);
                        gameControlTemp6 = CURRENT_TASK;
                        switch (gameControlTemp6->titleScreenSelectedOption) {       // switch 2; irregular
                            case TITLESCREEN_NEWGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 0;
                                playSFXAndSetNote(10, 10);
                                setTask(func_8001A51C);
                                break;
                            case TITLESCREEN_LOADGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 1;
                                playSFXAndSetNote(10, 10);
                                setTask(func_8001A51C);
                                break;
                            case TITLESCREEN_OPTIONS:                 // switch 2
                                gameControlTemp6->state0 = 2;
                                gameControlTemp6->state1 = 0U;
                                playSFXAndSetNote(10, 10);
                                break;
                        }
                    }
                    break;
                case 1:                             // switch 1
                    if (gameControlTemp2->unk6A != gameControlTemp2->unk6B) {
                        amount = -4;
                        if (gameControlTemp2->unk6A < gameControlTemp2->unk6B) {
                            amount = 4;
                        }
                        gameControlTemp2->unk6A += amount;
                        gameControlTemp4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                        if (gameControlTemp4->unk6B == gameControlTemp4->unk6A) {
                            gameControlTemp4->state2--;
                        }
                    }
                    break;
            }
            printTitleScreenMessage(48, 192, TITLESCREEN_MESSAGE_WHOOPCAMPCOPYRIGHT);
            if (*(u_short* )0x1F8001F8 & 0x20) {
                printTitleScreenMessage(56, 144, TITLESCREEN_MESSAGE_PRESSSTART);
            }
            gameControlTemp7 = CURRENT_TASK;
            func_800E8E78(gameControlTemp7->unk6A, gameControlTemp7->titleScreenSelectedOption);
            func_8001F6D4();
            return;
        case 4:
            func_80020C00(0);
            *arg0 = 0;
            gameControl = CURRENT_TASK;
            gameControl->state0 = 3;
            gameControl->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_8001A328);
void func_8001A328(void)
{
    u_short state2;
    unkstruct_1F8001D4* task;
    unkstruct_1F8001D4* task2;
    unkstruct_1F8001D4* task3;

    NEXT_PRIM = (int) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
    switch ((CURRENT_TASK)->state1) {
        case 0:
            func_80020C00(0);
            SetDispMask(0);
            LOAD_COMPLETE = 0;
            func_800223A0(3);
            func_800222B8(8, 1);
            (CURRENT_TASK)->state1++;
            return;
        case 1:
            if (LOAD_COMPLETE != 0) {
                SetDispMask(1);
                func_800E75C4();
                func_80020AF0(0);
                task2 = CURRENT_TASK;
                task2->state2 = 0U;
                (CURRENT_TASK)->state1++;
                return;
            }
        default:
            return;
        case 2:
            task = CURRENT_TASK;
            state2 = task->state2;
            switch (state2) {                    // switch 1; irregular
                case 0:                             // switch 1
                    task->unk4E.value = 0;
                    task->state2++;
                    // fallthrough
                case 1:                             // switch 1
                    if (func_800E75CC(task) != 0) {
                    (CURRENT_TASK)->state1++;
                    return;
                    }
                    break;
                case 2:                             // switch 1
                    func_800E7960(task);
                    return;
                case 3:                             // switch 1
                    func_800E7A48(task);
                    return;
            }
            break;
        case 3:
            func_80020C00(0);
            SetDispMask(0);
            LOAD_COMPLETE = 0U;
            func_800223A0(2);
            func_800222B8(2, 1);
            (CURRENT_TASK)->state1++;
            return;
        case 4:
            if (LOAD_COMPLETE != 0) {
                task3 = CURRENT_TASK;
                task3->state0 = 4;
                task3->state1 = 0U;
            }
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_8001A51C);
void func_8001A51C(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(unkstruct_1F8001D4**)&scratch->currentTask;
    int state;

    scratch->unk1D1 = 0;
    scratch->unk1D0 = 1;
    task->state0 = 0;
    task->state1 = 0;
    task->state2 = 0;
    task->unk4E.value = 0;
    task->unk6A = 0;
    setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
    setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
    scratch->unk1DC = -1;
    scratch->unk1DE = 0;
    D_8009EB4C = 0;
    scratch->loadComplete = 0;
    D_8009EBA0 = 0;
    func_80024B3C(D_1F800118);
    scratch->joypad_state  = 0;
    while (true){
        func_800223E0();
        state = (CURRENT_TASK)->state0;
        switch ((u_short)state) {
            case 0:
                func_8001A670(); // New Game
                break;
            case 1:
                func_8001A954(); // Debug
                break;
            case 2:
                func_8001A774(); // Load Game
                break;
        }
        sleepTask(1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/boot", func_8001A670);
void func_8001A670(void)
{

    RECT rect;
    u16 timer;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* task = *(u_long**)&scratch->currentTask;

    switch (task->state1) {                              // irregular
        case 0:
            task->unk5A = 1U;
            task->state1 += 1;
            setRECT(&rect, 0, 0, 64, 256);
            ClearImage((RECT* ) &rect, 0U, 0U, 0U);
            initGameConfig();
            scratch->unk1CF = 0;
            return;
        case 1:
            timer = task->unk5A - 1;
            task->unk5A = timer;
            if ((short)timer <= 0) {
                task->state1 += 1;
                return;
            }
            return;
        case 2:
            task->state2 = 0;
            task->unk4E.value = 0;
            if (task->loadGameSelected != 0) {
                task->state0 = 2;
            } else {
                task->state0 = 1;
            }
            task->state1 = 0U;
            break;
    }
}
