#include "common.h"
#include "game.h"


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", titleScreenHandler);
void titleScreenHandler(void)
{
    short var_v0;
    int temp_v0;
    u_short temp_v1;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v0_3;
    unkstruct_1F8001D4* temp_v1_2;

    temp_v1 = (CURRENT_TASK)->state1;
    switch (temp_v1) {
        case 0:
            SetDispMask(0);
            func_80028CE4();
            LOAD_COMPLETE = 0;
            loadAreaResources(3);
            func_800222B8(5, 1);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->state1++;;
            return;
        case 1:
            if (LOAD_COMPLETE != 0) {
                clearMenuParams();
                D_800A3952 = 5;
                func_80020AF0(0);
                SetDispMask(1);
                temp_v1_2 = CURRENT_TASK;
                temp_v1_2->state1++;;
                return;
            }
        default:
            return;
        case 2:
            NEXT_PRIM = (int) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
            temp_v0 = func_800E9438();
            if (temp_v0 == 1) {
                (CURRENT_TASK)->state1++;
            } else {
                if (temp_v0 == -1) (CURRENT_TASK)->state1 = 4;
            }
            func_800E9EF8();
            func_8001F6D4();
            return;
        case 3:
            GAME.unk14 = 0;
            GAME.unk7 = 0;
            func_80020C00(0);
            temp_v0_2 = CURRENT_TASK;
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1U;
            temp_v0_2->state2 = 0;
            temp_v0_2->unk4E.value = 0;
            return;
        case 4:
            func_80020C00(0);
            temp_v0_3 = CURRENT_TASK;
            *(char* )0x1F8001D0 = 0;
            temp_v0_3->state0 = 1;
            temp_v0_3->state1 = 0U;
            temp_v0_3->state2 = 0;
            temp_v0_3->unk4E.value = 0;
            setTask(&titleSequenceTask);
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", gameStateDispatcher);
void gameStateDispatcher(void)
{
    u_short temp_v1;

    temp_v1 = (CURRENT_TASK)->state1;
    switch (temp_v1) {
        case 0:
            introSequenceHandler();
            return;
        case 1:
            gameplayStateDispatcher();
            return;
        case 2:
            func_8001D2F0();
            return;
        case 3:
            func_8001D480();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", introSequenceHandler);
void introSequenceHandler(void)
{
    u_short temp_v1;
    u_char* temp1;
    unkstruct_1F8001D4* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;

    temp_v1 = (CURRENT_TASK)->state2;
    switch (temp_v1) {
        case 0:
            func_800222B8(9, 1);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->state2++;
            return;
        case 1:
            if (LOAD_COMPLETE != 0) {
                temp_v1_2 = CURRENT_TASK;
                temp_v1_2->state2++;
                return;
            }
        default:
            return;
        case 2:
            if (*(u_char* )0x1F8001B4 == 0) {
                D_8009EB4C = 0;
                LOAD_COMPLETE = 0U;
                func_8001CE80(1);
                temp_v1_2 = CURRENT_TASK;
                temp_v1_2->state2++;
                return;
            }
            (CURRENT_TASK)->state2 = 7U;
            return;
        case 3:
            displayLoadingScreen();
            if (LOAD_COMPLETE != 0) {
                temp_v1_2 = CURRENT_TASK;
                temp_v1_2->state2++;
                return;
            }
            break;
        case 4:
            MOVIE_PLAY_STATE = MOVIE_STARTING;
            MOVIE_ID = 1;
            openTask(1, &moviePlayerTask);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->state2++;
            return;
        case 5:
            if (MOVIE_PLAY_STATE != MOVIE_IDLE) {
                if (*(u_short* )(&SCRATCHPAD+0x1FC) & (JOY_CROSS | JOY_START)) {
                    MOVIE_SKIP_REQUEST = 1;
                    JOYPAD_STATE = 0U;
                    (CURRENT_TASK)->state2 = 6U;
                    return;
                }
            } else {
                (CURRENT_TASK)->state2 = 7U;
                return;
            }
            break;
        case 6:
            if (MOVIE_PLAY_STATE == MOVIE_IDLE) {
                (CURRENT_TASK)->state2 = 7U;
                return;
            }
            break;
        case 7:
            temp1 = (u_char*)&GAME.unk14;
            *temp1 = 1;
            temp_v1_3 = CURRENT_TASK;
            *(u_short*)&temp_v1_3->state2 = 1;
            if (*(u_char* )0x1F8001B4 != 0) {
                temp_v1_3->state2 = 0U;
                *temp1 = 0;
            }
            temp_v0 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v0->state1 = 1;
            temp_v0->unk4E.value = 0;
            GAME.currentArea = GAME.selectedArea;
            GAME.currentSection = GAME.selectedSection;
            GAME.currentSpawnPoint = GAME.selectedSpawnPoint;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", gameplayStateDispatcher);
void gameplayStateDispatcher(void)
{
    short temp_v0;
    u_short temp_v1;
    unkstruct_1F8001D4* temp_v0_2;

    temp_v1 = (CURRENT_TASK)->state2;
    switch (temp_v1) {
        case 0:
            debugSelectHandler();
            break;
        case 1:
            gameplayMainHandler();
            break;
        case 2:
            phoenixMountainHandler();
            break;
        case 3:
            inventoryScreenHandler();
            break;
        case 4:
            cutsceneAreaHandler();
            break;
        case 5:
            specialAreaHandler();
            break;
        case 6:
            eventAreaHandler();
            break;
        case 7:
            func_8001CFCC();
            break;
        case 8:
            transitionToGameOver();
            break;
    }
    temp_v0 = *(short* )0x1F8001DC;
    if ((temp_v0 >= 0) && ((LOAD_COMPLETE) != 0)) {
        temp_v0_2 = (CURRENT_TASK);
        *(short* )(&SCRATCHPAD+0x1DC) = -1;
        temp_v0_2->state2 = (u_short) temp_v0;
        temp_v0_2->unk4E = (u_short) *(u_short* )0x1F8001DE;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", advanceAndResetPools);
void advanceAndResetPools(void)
{
    unkstruct_1F8001D4* temp_v1;

    temp_v1 = CURRENT_TASK;
    temp_v1->unk4E.value++;
    initObjectPools();
    *(char* )0x1F8001CF = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", displayDebugScreen);
void displayDebugScreen(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1 = *(unkstruct_1F8001D4**)&scratch->currentTask;
    u_short var_a0;
    int* var_v1;
    u_short temp_a0;
    u_long temp_v1_2;
    u_char* temp_v1_3;
    u_char *temp2;

    /* If start a game and debug mode is enabled */
    if ((temp_v1->loadGameSelected == 0) && (scratch->debug_mode_enabled != 0)) {
        // If button UP is pressed decrease selected row
        if (scratch->joypad_state & JOY_UP) {
            D_8009B6A8 = (D_8009B6A8 - 1) & 1;
        }
        // If button DOWN is pressed increase selected row
        if (scratch->joypad_state & JOY_DOWN) {
            D_8009B6A8 = (D_8009B6A8 + 1) & 1;
        }
        // If selected row is the second one "SELECTED SECTION"
        if (D_8009B6A8 != 0) {
            // If button LEFT is pressed decrease selected section
            if (scratch->joypad_state & JOY_LEFT) {
                var_v1 = &GAME.selectedSection;
                *(u_short*)var_v1 -= 1;
                /* If selected section is less than the min section allowed for the current area,
                   clamp it to the min section */
                if ((*(u_short*)var_v1 << 0x10) <= 0) {
                    *(u_short*)var_v1 = 0U;
                }
            // If button RIGHT is pressed increase selected section
            } else if (scratch->joypad_state & JOY_RIGHT) {
                temp_v1_2 = GAME.selectedSection += 1;
                /* If selected section is greater than the max section allowed for the current area,
                   clamp it to the max section */
                temp_a0 = *(u_short*)((u_short*)&D_8007B294 + GAME.selectedArea);
                if ((temp_a0 - 1) < (int)temp_v1_2) {
                    GAME.selectedSection = (u_short) (temp_a0 - 1);
                }
            }
        // If selected row is the first one "SELECTED AREA"
        } else {
            // If button LEFT is pressed decrease selected area option
            if (scratch->joypad_state & JOY_LEFT) {
                var_v1 = &GAME.selectedArea;
                *(u_short*)var_v1 -= 1;
                /* If selected area is less than the min area allowed,
                   clamp it to the min area */
                if ((*(u_short*)var_v1 << 0x10) <= 0) {
                    *(u_short*)var_v1 = 0U;
                }
            // If button RIGHT is pressed increase selected area option
            } else if (scratch->joypad_state & JOY_RIGHT) {
                GAME.selectedArea++;
                temp_v1_2 = (u_short*)D_8007B290;
                /* If selected area is greater than the max area allowed,
                   clamp it to the max area */
                if (temp_v1_2 < GAME.selectedArea) {
                    GAME.selectedArea = temp_v1_2;
                }
            }
        }
        // Print rows with current selected options
        sprintf(&SPRINTF_BUFFER_MSG, "AREA SELECT = %02d", GAME.selectedArea);
        fontDebugPrintf(32, 96, 0U, &SPRINTF_BUFFER_MSG);
        sprintf(&SPRINTF_BUFFER_MSG, "SECTION SELECT = %02d", GAME.selectedSection);
        fontDebugPrintf(32, 104, 0U, &SPRINTF_BUFFER_MSG);
        // Print asterisk cursor on the selected row
        sprintf(&SPRINTF_BUFFER_MSG, "*");
        fontDebugPrintf(24, ((short) D_8009B6A8 + 0xC) * 8, (u_long) (*(u_short*)&PSX_SCRATCH[0x1F6] & 0xC) >> 2, &SPRINTF_BUFFER_MSG);
        // Set next area, section and spawn point to the selected ones
        GAME.nextArea = GAME.selectedArea;
        GAME.nextSection = GAME.selectedSection;
        GAME.nextSpawnPoint = GAME.selectedSpawnPoint;
        // If any action button (CIRCLE or START) is pressed
        if (scratch->joypad_state & (JOY_CIRCLE | JOY_START)) {
            // Handle area and section exceptions cases
            /* If selected area is not VILLAGE OF ALL BEGINNINGS or DWARF FOREST
               and selected section is not VILLAGE OF ALL BEGINNINGS or FOREST OF 100 FLOWERS */
            if (
                (
                    GAME.selectedArea < AREA02_DWARFVILLAGE) &&
                    (GAME.selectedSection != (
                        AREA00_SECTION00_VILLAGEOFALLBEGINNINGS |
                        AREA01_SECTION00_FORESTOF100FLOWERS
                    )
                )
            ) {
                GAME.unk21 = 1; // Set unk21 to 1 (unknown purpose)
            }
            /* If selected area is not the VILLAGE OF ALL BEGINNINGS 
               and selected section is not VILLAGE OF ALL BEGINNINGS */
            if (*(u_long*)&GAME.selectedArea != (AREA00_VILLAGEOFALLBEGINNINGS << 16 | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS)) {
                GAME.event[EVENT_CLEARTHEFOG] = 0xFF; // Set event CLEARTHEFOG to CLEARED
                GAME.playerState = 1; // Set player state to NORMAL
            }
        } else return;
    }

    temp2 = (u_char*)(&GAME.unk14);
    var_a0 = 1;
    if (*temp2 == 0) {
        *temp2 = 1;
    } else if (GAME.selectedArea != GAME.currentArea) {
        var_a0 = 1;
    } else {
        var_a0 = 0;
        if (GAME.selectedSection == GAME.currentSection) {
            setAreaSubState();
            return;
        }
    }
    func_8001CE80(var_a0);

    temp_v1_3 = (*(unkstruct_1F8001D4**)(&PSX_SCRATCH[0x1D4]))->unk4E.value;
    *(u_long*)&D_8009EB4C = 0;
    (*(unkstruct_1F8001D4**)(&PSX_SCRATCH[0x1D4]))->unk4E.value=temp_v1_3+1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", debugSelectHandler);
void debugSelectHandler(void)
{
    int var_a0;
    unkstruct_1F8001D4* p;
    u_char* temp1;
    u_char* temp2;

    switch ((CURRENT_TASK)->unk4E.value) {
        case 0:
            func_800222B8(9, 1);
            (CURRENT_TASK)->unk4E.value++;
            return;
        case 1:
            if (LOAD_COMPLETE != 0) {
                (CURRENT_TASK)->unk4E.value++;
                return;
            }
        default:
            return;
        case 2:
            (CURRENT_TASK)->unk4E.value++;
            initObjectPools();
            *(char* )0x1F8001CF = 0;
            return;
        case 3:
            displayDebugScreen();
            return;
        case 5:
            func_80020FAC();
            (*(unkstruct_1F8001D4**)(&SCRATCHPAD+0x1D4))->unk4E.value++;
            initObjectPools();
            *(u_char*)&(*(u_long**)0x1F8001CF) = 0;
            (CURRENT_TASK)->unk5E = 0x78U;
            (CURRENT_TASK)->unk64 = 0U;
            return;
        case 6:
            p = *(unkstruct_1F8001D4**)(&SCRATCHPAD+0x1D4);
            *(u_short*)&p->unk64=((p->unk64+12)&0xFF);
            drawNowLoading(p->unk64);
            (CURRENT_TASK)->unk5E--;
            if (((CURRENT_TASK)->unk5E << 0x10) == 0) {
                var_a0 = 1;
                temp1 = (u_char*)&GAME.unk14;
                if (*temp1 == 0) {
                   *temp1 = 1;
                    func_8001CE80(var_a0);
                } else {
                    if (GAME.selectedArea == GAME.currentArea) {
                        var_a0 = 0;
                        if (GAME.selectedSection == GAME.currentSection) {
                            setAreaSubState(0);
                            return;
                        }
                    }
                    func_8001CE80(var_a0);
                }
                D_8009EB4C = 0;
                (CURRENT_TASK)->unk4E.value++;
            }
            break;
        case 4:
        case 7:
            displayLoadingScreen();
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", gameplayMainHandler);
void gameplayMainHandler(void)
{
    u_short temp_v1;
    u_char temp_v0;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_a0_2;
    unkstruct_1F8001D4* temp_v1_2;

    temp_a0 = CURRENT_TASK;
    temp_v1 = temp_a0->unk4E.value;
    switch (temp_v1) {                              // irregular
        case 0:
            initObjectPools(temp_a0);
            initHud();
            temp_a0_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            *(char* )0x1F8001CF = 1;
            temp_a0_2->unk4E.value++;
            func_800243E8();
            func_800246B0();
            if (*(u_long*)&GAME.selectedArea == AREA06_DIRTMOTOCROSS) {
                func_8011AF40();
            } else {
                func_80028EF4();
            }
            func_80059F7C();
            if (GAME.unk7 != 1) {
                startAreaBgm();
            }
            GAME.unk21 = 1;
            *(&D_8009C9D8) = D_8009C9DC = 0;
            *(short*)(&SCRATCHPAD+0x1FC)=0;
            return;
        case 1:
            GAME.totalTimePlayed++;
            gameplayTick(temp_a0);
            if (D_8009BCA0 == 2) {
                temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                temp_v1_2->unk4E.value++;
                func_80020C00(1);
            }
            if ((*(u_char* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->unk4E.value = 3U;
                return;
            }
            return;
        case 2:
            if ((*(u_char* )0x1F8001BB == 0) && (temp_v0 = GAME.playerLives - 1, GAME.playerLives = temp_v0, ((temp_v0 & 0xFF) == 0))) {
                temp_a0->unk4E.value = 3U;
            } else {
                temp_a0->state2 = 0;
                temp_a0->unk4E.value = 5U;
                GAME.selectedSpawnPoint = 0;
                GAME.nextSpawnPoint = 0;
                GAME.playerHealth = GAME.playerHealthDisplayed;
            }
            GAME.displayExpBar = 0;
            D_800B07CD = 0;
            GAME.unk7 = 0;
            D_8009D6DD = 0;
            D_8009D6DE = 0;
            D_8009D6DF = 0;
            D_8009E3ED = 0;
            D_8009E3EE = 0;
            D_8009E3EF = 0;
            GAME.currentArea = GAME.selectedArea;
            GAME.currentSection = GAME.selectedSection;
            GAME.currentSpawnPoint = GAME.selectedSpawnPoint;
            return;
        case 3:
            D_8009D6DD = 0;
            D_8009D6DE = 0;
            D_8009D6DF = 0;
            D_8009E3ED = 0;
            D_8009E3EE = 0;
            D_8009E3EF = 0;
            temp_a0->state2 = 8;
            temp_a0->unk4E.value = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", gameplayTick);
void gameplayTick(void)
{
    *(s32* )(&SCRATCHPAD+0x164) = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 2) {
        if (*(u8* )(&SCRATCHPAD+0x1CC) == 0) {
            *(s16* )0x1F8001C6 = 0;
        } else if (
            (*(u8* )(&SCRATCHPAD+0x3D0) == 1) &&
            ( 
                (
                    ((*(u8* )(&SCRATCHPAD+0x1CD)) == 5) || 
                    (((u8) ((*(u8* )(&SCRATCHPAD+0x1CD)) - 7) < 2))
                ) && ((*(u16* )(&SCRATCHPAD+0x1FC) & (JOY_CROSS | JOY_START)) != 0)
            )
        ) {
            *(s8* )(&SCRATCHPAD+0x1D3) = 1;
            *(u8* )(&SCRATCHPAD+0x3D0) = 0U;
        }
    }
    func_8001D6C0();
    if (*(s16* )0x1F8001C6 == 0) {
        (*(s16* )(&SCRATCHPAD+0x1F8))=(*(s16* )0x1F8001F8)+1;
        func_80034524();
        func_80029008();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8003C9D4();
            func_8001DFD4();
            updateObjectsLayer7();
            updateObjectsUnlayered();
            func_80055BA0();
        }
    }
    if (*(s16* )0x1F8001C6 != 1) {
        updateInventoryOverlay();
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        func_8002DA2C();
        updateObjectsLayer8();
    }
    // Hack to match (using this instead SCRATCHPAD to access 1F8001C6)
    if (*(s16* )((byte*)D_1F8001A0+0x26) != 2) {
        func_80046264();
    } else {
        resetDrawLists();
    }
    func_8001F6D4();
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", phoenixMountainHandler);
void phoenixMountainHandler(void)
{
    char pad[4];
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_a0 = scratch->currentTask;
    
    switch(scratch->currentTask->unk4E.value) {
        case 0:
            initObjectPools();
            initHud();
            scratch->unk1CF = 1;
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 2;
            if ((GAME.unk7 != 1) || (*(u_long *)&GAME == ((AREA03_PHOENIXMOUNTAIN << 16) | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS))) {
                startAreaBgm();
            }
            *(short* )0x1F8001FC = 0;
            scratch->currentTask->unk4E.volatile_value+=1;
            *(volatile u_short*)&D_8009C9D8 = D_8009C9DC = 0;
            break;
        case 1:
            GAME.totalTimePlayed++;
            phoenixMountainTick();
            if (scratch->unk1C2 != 0) {
                volatile u_short *temp_v1 = (volatile int* )&D_8009C9D8;
                if (((*temp_v1 & 0x8) != 0) && ((temp_v1[0] & 0x800) != 0)) {
                    scratch->currentTask->unk4E.value = 2;
                }
            }
            break;
        case 2:
            setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
            setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
            temp_a0->state2 = 8;
            temp_a0->unk4E.value = 0;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", phoenixMountainTick);
void phoenixMountainTick(void)
{
    char* var_a0;
    u_short var_a1;
    unkstruct_1F8001D4* temp_v1;

    NEXT_PRIM = (int) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
    if ((*(short* )(&SCRATCHPAD+0x1C6) == 2) && (MOVIE_PLAY_STATE == MOVIE_IDLE)) {
        *(short* )0x1F8001C6 = 0;
    }
    func_8001D6C0();
    if (GAME.inventoryScreen == 0xFF) {
        GAME.inventoryScreen = 0;
        temp_v1 = CURRENT_TASK;
        var_a0 = *(u_short*)&temp_v1->state2;
        var_a1 = *(u_short*)&(CURRENT_TASK)->unk4E.value;
        D_800A3952 = 6;
        D_800A3954 = 0;
        D_800A3956 = 0;
        D_800A3940[0] = 0;
        temp_v1->state2 = 3U;
        (CURRENT_TASK)->unk4E.value = 0U;
        *(short* )0x1F8003B8 = (short)var_a0;
        *(u_short* )0x1F8003BA = var_a1;
    }
    if (*(short* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u_short* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        func_80029008();
        if (*(short* )0x1F8001C6 == 0) {
            func_8003C9D4();
            updateObjectsLayer7();
            func_8001DFD4();
            updateObjectsUnlayered();
            func_80055BA0();
        }
    }
    if (*(short* )(&D_1F8000C0[0]+0x106) != 1) {
        updateInventoryOverlay();
    }
    if (*(short* )(&SCRATCHPAD+0x1C6) == 0) {
        func_8002DA2C();
        updateObjectsLayer8();
    }
    if (*(short* )0x1F8001C6 != 2) {
        func_80046264();
    } else {
        resetDrawLists();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", inventoryScreenHandler);
void inventoryScreenHandler(void)
{
    DRAWENV drawenv;
    RECT rect;
    s32 var_a0;
    s16* temp_s0;
    u16 temp_s1;
    u16 temp_v1;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_v0;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;

    temp_v1 = (CURRENT_TASK)->unk4E.value;
    switch (temp_v1) {                              // switch 1
        case 0:                                     // switch 1
            *(s8* )0x1F8001CF = 1;
            (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->unk6A = 0;
            SetDispMask(0);
            setRECT(&rect, 288, 480, 48, 31);
            StoreImage((RECT* ) &rect, (u32* )0x801FB000);
            setRECT(&rect, 128, 511, 256, 1);
            StoreImage((RECT* ) &rect, (u32* )0x801FBBA0);
            GetDrawEnv(&drawenv);
            setRGB0((DRAWENV*)(&D_8009D6C4), 248, 200, 192);
            setRGB0((DRAWENV*)(D_8009E3D4), 248, 200, 192);
            D_8009B000 = drawenv.r0;
            D_8009B004 = drawenv.g0;
            D_8009B008 = drawenv.b0;
            temp_a0 = CURRENT_TASK;
            temp_a0->unk4E.value++;
            return;
        case 1:                                     // switch 1
            LOAD_COMPLETE = 0;
            switch (D_800A3952) {                   // switch 2
                case 0:                             // switch 2
                case 1:                             // switch 2
                case 2:                             // switch 2
                case 6:                             // switch 2
                    func_800222B8(3, 1);
                    break;
                case 4:                             // switch 2
                    func_800222B8(4, 1);
                    break;
                case 5:                             // switch 2
                    func_800222B8(5, 1);
                    break;
                case 7:                             // switch 2
                    func_800222B8(6, 1);
                    break;
                case 3:                             // switch 2
                    func_800222B8(7, 1);
                    break;
            }
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->unk4E.value++;
            return;
        case 2:                                     // switch 1
            if (LOAD_COMPLETE != 0) {
                EnterCriticalSection();
                FlushCache();
                ExitCriticalSection();
                temp_s1 = *(volatile u16*)&D_800A3952;
                clearMenuParams();
                *(s16*)&(*(volatile u16**)&D_800A3952) = temp_s1;
                SetDispMask(1);
                temp_v1_2 = CURRENT_TASK;
                temp_v1_2->unk4E.value++;
                return;
            }
        default:                                    // switch 1
            return;
        case 3:                                     // switch 1
            inventoryScreenTick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (CURRENT_TASK)->unk4E.value = 6U;
                return;
            }
            break;
        case 4:                                     // switch 1
            SetDispMask(0);
            setRECT(&rect, 288, 480, 48, 31);
            LoadImage((RECT* ) &rect, (u32* )0x801FB000);
            setRECT(&rect, 128, 511, 256, 1);
            LoadImage((RECT* ) &rect, (u32* )0x801FBBA0);
            *(s8* )0x1F8001CE = 0U;
            setRGB0((DRAWENV*)(&D_8009D6C4), (s8) D_8009B000, (s8) D_8009B004, (s8) D_8009B008);
            setRGB0((DRAWENV*)(D_8009E3D4), (s8) D_8009B000, (s8) D_8009B004, (s8) D_8009B008);
            var_a0 = (D_80076FAC[(u32)GAME.selectedArea + (u16)D_8009EBA0]);
            func_800222B8(((s16*)var_a0)[GAME.selectedSection], 1);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->unk4E.value++;
            return;
        case 5:                                     // switch 1
            if ((LOAD_COMPLETE) != 0) {
                EnterCriticalSection();
                FlushCache();
                ExitCriticalSection();
                SetDispMask(1);
                temp_v0 = CURRENT_TASK;
                *(s16* )0x1F8001C6 = 0;
                temp_v0->state2 = (u16) *(u16* )0x1F8003B8;
                temp_v0->unk4E.value = (u16) *(u16* )0x1F8003BA;
                return;
            }
            break;
        case 6:                                     // switch 1
            temp_v1_3 = CURRENT_TASK;
            temp_v1_3->state2 = 8U;
            temp_v1_3->unk4E.value = 0U;
            return;
        case 7:                                     // switch 1
            GAME.unk14 = 0;
            GAME.unk7 = 0;
            func_80020C00(0);
            setRGB0((DRAWENV*)(&D_8009D6C4), 0, 0, 0);
            setRGB0((DRAWENV*)(D_8009E3D4), 0, 0, 0);
            (CURRENT_TASK)->loadGameSelected = 1;
            temp_v0_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1;
            temp_v0_2->state2 = 0U;
            temp_v0_2->unk4E.value = 0U;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", inventoryScreenTick);
void inventoryScreenTick(void)
{
    s32 var_s0;

    *(u16* )(&SCRATCHPAD+0x1F8)=*(u16* )(0x1F8001F8)+1;
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    switch (D_800A3952) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 6:
            var_s0 = func_800EEBBC();
            if (var_s0 == 0) {
                func_800EEE84();
            }
            break;
        case 4:
        case 5:
            var_s0 = func_800E9438();
            if (var_s0 == 0) {
                func_800E9EF8();
            }
            break;
        case 7:
            var_s0 = func_800ECED8();
            if (var_s0 == 0) {
                func_800ED0B8();
            }
            break;
    }
    if (D_800A3952 == 5) {
        if (var_s0 == 1) {
            (CURRENT_TASK)->unk4E.value = 7U;
        } else {
            if (var_s0 != 0) {
                (CURRENT_TASK)->unk4E.value++; 
            }
        }
    } else {
        if (var_s0 == 2) {
            SetDispMask(0);
            (CURRENT_TASK)->unk4E.value = 1;
        }else if (var_s0 != 0) {
            (CURRENT_TASK)->unk4E.value++;
        }
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", cutsceneAreaHandler);
void cutsceneAreaHandler(void)
{
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way

    temp_v1 = (CURRENT_TASK)->unk4E.value;

    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)allocObjectLayer7();
            if (temp_v0 != NULL) {
                temp_v0->unk0 = 1;
                temp_v0->unk2 = 5;
                temp_v0->unk3 = 0;
                temp_v0->unk12 = 0;
                temp_v0->unk16 = 0;
                temp_v0->unk1A = 0;
            }
            *&D_8009C9D8 = D_8009C9DC = 0;
            *(s16* )0x1F8001FC = 0;
        break;   

        case 1:
            GAME.totalTimePlayed += 1;
            cutsceneAreaTick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->unk4E.value = 3U;
                return;
            }
        break;

        case 2:
        case 3:
            temp_v1_3 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&D_8009D6C4), 0, 0, 0);
            setRGB0((DRAWENV*)(D_8009E3D4), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->unk4E.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", cutsceneAreaTick);
void cutsceneAreaTick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16*)(&SCRATCHPAD+0x1C6) == 0) {
            func_8003C9D4();
            func_8001DFD4();
            updateObjectsUnlayered();
            func_800EB804();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        updateInventoryOverlay();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        updateObjectsLayer8();
        if (*(s16* )0x1F8001C6 == 0) {
            func_800EAED4();
            updateObjectsLayer7();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        resetDrawLists();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", specialAreaHandler);
void specialAreaHandler(void)
{
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (CURRENT_TASK)->unk4E.value;
    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)allocObjectLayer7();
            if (temp_v0 != NULL) {
                temp_v0->unk0 = 1;
                temp_v0->unk2 = 10;
                temp_v0->unk3 = 0;
                temp_v0->unk12 = 0;
                temp_v0->unk16 = 0;
                temp_v0->unk1A = 0;
            }
            *&D_8009C9D8 = D_8009C9DC = 0;
            *(s16* )0x1F8001FC = 0;
        break;   
    
        case 1:
            GAME.totalTimePlayed += 1;
            specialAreaTick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->unk4E.value = 3U;
                return;
            }
        break;
    
        case 2:
        case 3:
            temp_v1_3 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&D_8009D6C4), 0, 0, 0);
            setRGB0((DRAWENV*)(D_8009E3D4), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->unk4E.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", specialAreaTick);
void specialAreaTick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8001DFD4();
            updateObjectsUnlayered();
            func_800ECEEC();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        updateInventoryOverlay();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        updateObjectsLayer8();
        if (*(s16* )0x1F8001C6 == 0) {
            func_800EC588();
            updateObjectsLayer7();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        resetDrawLists();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", eventAreaHandler);
void eventAreaHandler(void)
{
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (CURRENT_TASK)->unk4E.value;
    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)allocObjectLayer7();
            if (temp_v0 != NULL) {
                temp_v0->unk0 = 1;
                temp_v0->unk2 = 13;
                temp_v0->unk3 = 0;
                temp_v0->unk12 = 0;
                temp_v0->unk16 = 0;
                temp_v0->unk1A = 0;
            }
            *&D_8009C9D8 = D_8009C9DC = 0;
            *(s16* )0x1F8001FC = 0;
        break;   
    
        case 1:
            GAME.totalTimePlayed += 1;
            eventAreaTick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->unk4E.value = 3U;
                return;
            }
        break;
    
        case 2:
        case 3:
            temp_v1_3 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&D_8009D6C4), 0, 0, 0);
            setRGB0((DRAWENV*)(D_8009E3D4), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->unk4E.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", eventAreaTick);
void eventAreaTick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(s16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8001DFD4();
            updateObjectsUnlayered();
            func_800EB5B8();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        updateInventoryOverlay();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        func_8002DA2C();
        updateObjectsLayer8();
        if (*(s16* )0x1F8001C6 == 0) {
            updateObjectsLayer7();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        resetDrawLists();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", displayLoadingScreen);
void displayLoadingScreen(void)
{
    u_short temp_a1;
    u_short temp_v0;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v1;

    switch (D_8009EB4C) {                           // irregular
        case 0:
            temp_v1 = CURRENT_TASK;
            temp_v1->unk62 = 0;
            temp_v1->unk60 = 0xFU;
            temp_v1->unk64 = 0U;
            drawLoadingSprites(temp_v1->unk62, 0U);
            D_8009EB4C += 1;
            // fallthrough
        case 1:
            temp_a0 = *(unkstruct_1F8001D4**)(&SCRATCHPAD+0x1D4);
            temp_v0 = temp_a0->unk60 - 1;
            temp_a0->unk60 = temp_v0;
            if ((temp_v0 << 0x10) == 0) {
                temp_a0->unk60 = 0xFU; // sprite refresh rate?
                temp_a0->unk62 = (short) ((u_short) temp_a0->unk62 ^ 1); // is even frame?
            }
            temp_v0_2 = CURRENT_TASK;
            *(u_short*)&temp_v0_2->unk64 = ((temp_v0_2->unk64 + 12) & 0xFF);
            drawLoadingSprites(temp_v0_2->unk62, temp_v0_2->unk64);
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", resolveAreaVariant);
s32 resolveAreaVariant(void)
{
    s32 var_a1;
    s32 var_v0;
    u16 var_v0_2;

    var_a1 = 0;
    switch (GAME.selectedArea) {
        case AREA07_DWARFFORESTPURIFIED:
            if ((u16)D_8009EBA0 != 6) {
                var_a1 = 1;
            }
            GAME.purifiedAreas |= GAME.selectedArea = AREA01_DWARFFOREST;
            D_8009EBA0 = 6;
            break;
        case AREA01_DWARFFOREST:
            if (GAME.purifiedAreas & PURIFIED_DWARFFOREST) {
                if (*(u16*)&D_8009EBA0 != 6) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 6;
            } else {
            case AREA00_VILLAGEOFALLBEGINNINGS:
            case AREA06_DIRTMOTOCROSS:
            case AREA08_BACCUSLAKE:
            case AREA09_MUSHROOMVILLAGE:
            case AREA11_VILLAGEOFCIVILIZATION:
            case AREA13_PIGISLAND:
            case AREA14_EVILPIGS:
            case AREA15_UNKNOWN:
            case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            case AREA18_VILLAGEOFCIVILIZATIONYCROSSING:
                if (*(u16*)&D_8009EBA0 != 0) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 0;
            }
            break;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            if (GAME.selectedSection != AREA19_SECTION02_HIDDENVILLAGE) {
                if (*(u16*)&D_8009EBA0 != 0x11) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 17;
                GAME.selectedArea = AREA02_DWARFVILLAGE;
            } else {
                if (*(u16*)&D_8009EBA0 != 0) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 0;
            }
            break;
        case AREA02_DWARFVILLAGE:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & PURIFIED_DWARFFOREST) && ((u16) GAME.selectedSection < 2U)) {
                D_8009EBA0 = 17;
                GAME.selectedArea = AREA02_DWARFVILLAGE;
            }
            break;
        case AREA03_PHOENIXMOUNTAIN:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if (GAME.purifiedAreas & PURIFIED_PHOENIXMOUNTAIN) {
                var_v0 = (u16) GAME.selectedSection < 2U;
                if (var_v0 != 0) {
                    var_v0_2 = GAME.selectedSection + 4;
                    GAME.selectedSection = var_v0_2;
                }
            }
            break;
        case AREA12_HAUNTEDMANSIONPURIFIED:
            if (*(u16*)&D_8009EBA0 != 8) {
                var_a1 = 1;
            }
            GAME.purifiedAreas |= PURIFIED_HAUNTEDMANSION, GAME.selectedArea = AREA04_HAUNTEDMANSION;
            D_8009EBA0 = 8;
            break;
        case AREA04_HAUNTEDMANSION:
            if (GAME.purifiedAreas & PURIFIED_HAUNTEDMANSION) {
                if (*(u16*)&D_8009EBA0 != 8) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 8;
            } else {
                if (*(u16*)&D_8009EBA0 != 0) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 0;
            }
            break;
        case AREA05_BACCUSVILLAGE:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & PURIFIED_BACCUSVILLAGE) && ((u16) GAME.selectedSection < 2U)) {
                var_v0_2 = GAME.selectedSection + 2;
                GAME.selectedSection = var_v0_2;
            }
            break;
        case AREA10_DEEPJUNGLE:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & PURIFIED_TRICKVILLAGE) && (GAME.selectedSection == AREA10_SECTION03_TRICKVILLAGE)) {
                GAME.selectedSection = AREA10_SECTION07_TRICKVILLAGEPURIFIED;
            }
            if (GAME.purifiedAreas & PURIFIED_DEEPJUNGLE) {
                var_v0 = (u16) GAME.selectedSection < 3U;
                if (var_v0 != 0) {
                    var_v0_2 = GAME.selectedSection + 4;
                    GAME.selectedSection = var_v0_2;
                }
            }
            break;
    }
    return var_a1;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001CE80);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", setAreaSubState);
void setAreaSubState(void)
{
    u8* row = D_80077084[GAME.selectedArea + (u16)D_8009EBA0];
    u8  v = row[D_8009BCCA];
    unkstruct_1F8001D4* p = CURRENT_TASK;

    p->unk4E.value = 0;
    p->state2 = v;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001CFCC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", transitionToGameOver);
void transitionToGameOver(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1;

    temp_v1 = scratch->currentTask;
    scratch->unk1CF = 1;
    setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
    setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
    temp_v1->state1 = 3;
    temp_v1->state2 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001D2F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001D480);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", openMenuScreen);
void openMenuScreen(s16 arg0)
{
    u8* p = D_1F8001D4;
    u16 a = *(u16*)(p + 0x4C);
    u16 b = *(u16*)(p + 0x4E);

    D_800A3940[0] = 0;
    D_800A3941 = 0;
    D_800A3952 = arg0;
    D_800A3956 = 0;
    *(u16*)(p + 0x4C) = 3;
    *(u16*)(p + 0x4E) = 0;
    D_1F8003B8 = a;
    D_1F8003BA = b;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", openMenuScreenEx);
void openMenuScreenEx(s16 arg0, s16 arg1, s16 arg2)
{
    unkstruct_1F8001D4* p = CURRENT_TASK;

    D_800A3952 = arg0;
    D_800A3954 = arg1;
    D_800A3956 = arg2;
    D_800A3940[0] = 0;
    p->state2 = 3;
    p->unk4E.value = 0;
    func_80020058(10, 10);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001DE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001DFD4);
