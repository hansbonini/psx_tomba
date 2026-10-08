#include "common.h"
#include "game.h"

extern u32 D_80076E88[];
extern u32 D_80076E94[];
extern u32 D_80076EA0[];
extern u32 D_80076EAC[];
extern u32 D_80076EB8[];
extern u32 D_80076EE4[];
extern u32 D_80076EEC[];
extern u32 D_80076EF4[];
extern u32 D_80076F00[];
extern u32 D_80076F08[];
extern u32 D_80076F14[];
extern u32 D_80076F28[];
extern u32 D_80076F34[];
extern u32 D_80076F60[];
extern u32 D_80076F64[];
extern u32 D_80076F74[];
extern u32 D_80076F84[];
extern u32 D_80076F9C[];
extern u32 D_80076FA4[];
extern u32 D_80076FAC_data[] asm("D_80076FAC");
extern u32 D_80076FFC[];
extern u32 D_80077004[];
extern u32 D_8007700C[];
extern u32 D_80077014[];
extern u32 D_8007701C[];
extern u32 D_80077030[];
extern u32 D_80077034[];
extern u32 D_80077038[];
extern u32 D_8007703C[];
extern u32 D_80077044[];
extern u32 D_80077050[];
extern u32 D_8007705C[];
extern u32 D_80077060[];
extern u32 D_80077068[];
extern u32 D_80077070[];
extern u32 D_8007707C[];
extern u32 D_80077080[];
extern u32 D_80077084_data[] asm("D_80077084");
extern u32 D_800770D4[];
extern u32 D_800770DC[];
extern u32 D_800770E4[];
extern u32 D_800770EC[];
extern u32 D_800770F4[];
extern u32 D_80077108[];
extern u32 D_8007710C[];
extern u32 D_80077110[];
extern u32 D_80077118[];
extern u32 D_8007711C[];
extern u32 D_80077124[];
extern u32 D_80077130[];
extern u32 D_80077134[];
extern u32 D_80077148[];
extern u32 D_8007714C[];
extern u32 D_80077154[];
extern u32 D_8007715C[];
extern u32 D_80077164[];
extern u32 D_80077168[];
extern u32 D_8007716C_data[] asm("D_8007716C");
extern u32 D_800771FC_data[] asm("D_800771FC");
extern u32 D_8007722C_data[] asm("D_8007722C");
extern u32 D_80077274[];
extern u32 D_8007728C[];
extern u32 D_800772BC_data[] asm("D_800772BC");

u32 D_80076E88[3] = {
    0x000A000A, 0x000B000A, 0x000D000C
};

u32 D_80076E94[3] = {
    0x000E000E, 0x0010000F, 0x00110011
};

u32 D_80076EA0[3] = {
    0x00130012, 0x00150014, 0x00170016
};

u32 D_80076EAC[3] = {
    0x00190018, 0x001B001A, 0x00190018
};

u32 D_80076EB8[0xB] = {
    0x001C001C, 0x001C001C, 0x001E001D, 0x001D001F,
    0x00210020, 0x0022001D, 0x001D0023, 0x0024001D,
    0x0025001D, 0x001D0026, 0x001D001D
};

u32 D_80076EE4[2] = {
    0x00280027, 0x00280027
};

u32 D_80076EEC[2] = {
    0x00290029, 0x002A002A
};

u32 D_80076EF4[3] = {
    0x002B002B, 0x002D002C, 0x002E002E
};

u32 D_80076F00[2] = {
    0x0030002F, 0x0030002F
};

u32 D_80076F08[3] = {
    0x00320031, 0x00340033, 0x00360035
};

u32 D_80076F14[5] = {
    0x00380037, 0x003A0039, 0x00380037, 0x003B0039,
    0x003C003C
};

u32 D_80076F28[3] = {
    0x003E003D, 0x003E003F, 0x003F003F
};

u32 D_80076F34[0xB] = {
    0x00400040, 0x00400040, 0x00400040, 0x00400040,
    0x005C0041, 0x00400040, 0x00400040, 0x00420040,
    0x00400040, 0x00400040, 0x00400040
};

u32 D_80076F60[1] = {
    0x00430043
};

u32 D_80076F64[4] = {
    0x00450044, 0x00470046, 0x00490048, 0x004B004A
};

u32 D_80076F74[4] = {
    0x004D004C, 0x004F004E, 0x004E004D, 0x004F004F
};

u32 D_80076F84[6] = {
    0x00510050, 0x00530052, 0x00550054, 0x00520051,
    0x00540053, 0x00550055
};

u32 D_80076F9C[2] = {
    0x00570056, 0x00580058
};

u32 D_80076FA4[2] = {
    0x005A0059, 0x005B005B
};

u32 D_80076FAC_data[0x14] asm("D_80076FAC") = {
    (u32)D_80076E88, (u32)D_80076E94, (u32)D_80076EA0, (u32)D_80076EAC,
    (u32)D_80076EB8, (u32)D_80076EE4, (u32)D_80076EEC, (u32)D_80076EF4,
    (u32)D_80076F00, (u32)D_80076F08, (u32)D_80076F14, (u32)D_80076F28,
    (u32)D_80076F34, (u32)D_80076F60, (u32)D_80076F64, (u32)D_80076E88,
    (u32)D_80076F74, (u32)D_80076F84, (u32)D_80076F9C, (u32)D_80076FA4
};

u32 D_80076FFC[2] = {
    0x02010101, 0x01020101
};

u32 D_80077004[2] = {
    0x01010101, 0x01010101
};

u32 D_8007700C[2] = {
    0x06020204, 0x00000202
};

u32 D_80077014[2] = {
    0x01010101, 0x01010101
};

u32 D_8007701C[5] = {
    0x01010101, 0x01010101, 0x01010101, 0x01010101,
    0x01010101
};

u32 D_80077030[1] = {
    0x02050205
};

u32 D_80077034[1] = {
    0x01020201
};

u32 D_80077038[1] = {
    0x02050205
};

u32 D_8007703C[2] = {
    0x02020201, 0x01010101
};

u32 D_80077044[3] = {
    0x01010101, 0x01010101, 0x00000002
};

u32 D_80077050[3] = {
    0x02020205, 0x02020202, 0x01010101
};

u32 D_8007705C[1] = {
    0x01010201
};

u32 D_80077060[2] = {
    0x01010101, 0x01010101
};

u32 D_80077068[2] = {
    0x02020205, 0x02020202
};

u32 D_80077070[3] = {
    0x02020205, 0x02020202, 0x02020202
};

u32 D_8007707C[1] = {
    0x02020205
};

u32 D_80077080[1] = {
    0x02050204
};

u32 D_80077084_data[0x14] asm("D_80077084") = {
    (u32)D_80076FFC, (u32)D_80077004, (u32)D_8007700C, (u32)D_80077014,
    (u32)D_8007701C, (u32)D_80077030, (u32)D_80077034, (u32)D_80077004,
    (u32)D_80077038, (u32)D_8007703C, (u32)D_80077044, (u32)D_80077050,
    (u32)D_8007701C, (u32)D_8007705C, (u32)D_80077060, (u32)D_80077068,
    (u32)D_80077068, (u32)D_80077070, (u32)D_8007707C, (u32)D_80077080
};

u32 D_800770D4[2] = {
    0x05040404, 0x00000404
};

u32 D_800770DC[2] = {
    0x06060606, 0x00000606
};

u32 D_800770E4[2] = {
    0x08070707, 0x00000805
};

u32 D_800770EC[2] = {
    0x090B0909, 0x00000A0A
};

u32 D_800770F4[5] = {
    0x0D0D0D0D, 0x0E0E0E0E, 0x0E0E0E0E, 0x050E0E0E,
    0x0E0E0E0E
};

u32 D_80077108[1] = {
    0x0F0F0F0F
};

u32 D_8007710C[1] = {
    0x11111110
};

u32 D_80077110[2] = {
    0x12121212, 0x00001212
};

u32 D_80077118[1] = {
    0x13131313
};

u32 D_8007711C[2] = {
    0x15151514, 0x15161515
};

u32 D_80077124[3] = {
    0x18171717, 0x1A191919, 0x00000505
};

u32 D_80077130[1] = {
    0x1B1B1B1B
};

u32 D_80077134[5] = {
    0x1C1C1C1C, 0x1C1C1C1C, 0x1C1C1C1C, 0x051C1C1C,
    0x1C1C1C1C
};

u32 D_80077148[1] = {
    0x00001E1D
};

u32 D_8007714C[2] = {
    0x2221201F, 0x26252423
};

u32 D_80077154[2] = {
    0x27272727, 0x27272727
};

u32 D_8007715C[2] = {
    0x28282828, 0x28282828
};

u32 D_80077164[1] = {
    0x2A2A2929
};

u32 D_80077168[1] = {
    0x2B072B2B
};

u32 D_8007716C_data[0x14] asm("D_8007716C") = {
    (u32)D_800770D4, (u32)D_800770DC, (u32)D_800770E4, (u32)D_800770EC,
    (u32)D_800770F4, (u32)D_80077108, (u32)D_8007710C, (u32)D_80077110,
    (u32)D_80077118, (u32)D_8007711C, (u32)D_80077124, (u32)D_80077130,
    (u32)D_80077134, (u32)D_80077148, (u32)D_8007714C, (u32)D_800770D4,
    (u32)D_80077154, (u32)D_8007715C, (u32)D_80077164, (u32)D_80077168
};

u8 D_800771BC[8] = {
    0x2C, 0x2C, 0x2D, 0x2E, 0x2F, 0x2F, 0, 0
};

u8 D_800771C4[0xC] = {
    0x30, 0x31, 0x30, 0x30, 0x30, 0x31, 0x30, 0x30, 0x30, 0x30, 0, 0
};

u8 D_800771D0[0x2C] = {
    0x32, 0x32, 0x32, 0x32, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x33, 0x33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x20, 0, 0, 3, 0xE0, 0xFF, 0, 3, 0, 0, 0, 0
};

u32 D_800771FC_data[0xC] asm("D_800771FC") = {
    0x03000080, 0x0300FF80, 0x00000000, 0x030000C0,
    0x0300FF40, 0x00000000, 0x03000100, 0x0300FF00,
    0x00000000, 0x03000130, 0x0300FED0, 0x00000000
};

u32 D_8007722C_data[0x12] asm("D_8007722C") = {
    0x04000180, 0x0400FE80, 0x00000000, 0x040001C0,
    0x0400FE40, 0x00000000, 0x05000200, 0x0500FE00,
    0x00000000, 0x05000280, 0x0500FD80, 0x00000000,
    0x06000300, 0x0600FD00, 0x00000000, 0x06000380,
    0x0600FC80, 0x00000000
};

u32 D_80077274[6] = {
    0x06000400, 0x0600FC00, 0x00000000, 0x07000480,
    0x0700FB80, 0x00000000
};

u32 D_8007728C[0xC] = {
    0x07000500, 0x0700FB00, 0x00000000, 0x07000550,
    0x0700FAB0, 0x00000000, 0x00500000, 0xFFB00000,
    0x00000000, 0x01000000, 0xFF000000, 0x00000000
};

u32 D_800772BC_data[0x5B] asm("D_800772BC") = {
    0x8012A60C, 0x80126330, 0x800577F4, 0x8012D220,
    0x8012D504, 0x8012D808, 0x8012DC08, 0x80110E30,
    0x801314B8, 0x80131BF8, 0x80123168, 0x8012E780,
    0x8012ECC0, 0x80130630, 0x801127D4, 0x80130914,
    0x80130C3C, 0x80130FDC, 0x801327B8, 0x80133F38,
    0x80133748, 0x80133F64, 0x801357D4, 0x80136554,
    0x801139DC, 0x800ED068, 0x80123A14, 0x801244F8,
    0x80123C18, 0x8012434C, 0x80126104, 0x80113BE0,
    0x80124514, 0x801276EC, 0x80138084, 0x80138C4C,
    0x8012487C, 0x800ED6DC, 0x800ED9B8, 0x80124360,
    0x8012754C, 0x801267AC, 0x801162F8, 0x8012C5D8,
    0x80127C00, 0x800ED748, 0x800EDAC8, 0x801154F8,
    0x8003F124, 0x80127174, 0x8005788C, 0x8012A4C0,
    0x801341A0, 0x8012A6E8, 0x8012B208, 0x8012C5D0,
    0x8012E874, 0x8012ECF0, 0x80129F68, 0x8011E824,
    0x8011E824, 0x8011E824, 0x8011E824, 0x8011E824,
    0x8011E824, 0x8011E824, 0x8011E824, 0x8011FA04,
    0x800EBD20, 0x800ED1C4, 0x801208F4, 0x8012175C,
    0x8012212C, 0x801222E4, 0x801179D4, 0x801234A0,
    0x800ED48C, 0x8012787C, 0x8012BBC0, 0x80123814,
    0x801244F8, 0x8011D890, 0x80118680, 0x8011E068,
    0x80058E14, 0x80113D58, 0x80116330, 0x801353D4,
    0x8012C1A0, 0x801288A4, 0x8012FB00
};


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", titleScreenHandler);
void titleScreenHandler(void)
{
    short var_v0;
    int temp_v0;
    u_short temp_v1;
    Task* temp_v0_2;
    Task* temp_v0_3;
    Task* temp_v1_2;

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
                startBgmTrack(0);
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
            updateSound();
            return;
        case 3:
            GAME.areaTransition = 0;
            GAME.keepBgm = 0;
            stopBgm(0);
            temp_v0_2 = CURRENT_TASK;
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1U;
            temp_v0_2->state2 = 0;
            temp_v0_2->step.value = 0;
            return;
        case 4:
            stopBgm(0);
            temp_v0_3 = CURRENT_TASK;
            *(char* )0x1F8001D0 = 0;
            temp_v0_3->state0 = 1;
            temp_v0_3->state1 = 0U;
            temp_v0_3->state2 = 0;
            temp_v0_3->step.value = 0;
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
    Task* temp_v0;
    Task* temp_v1_2;
    Task* temp_v1_3;

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
                loadCurrentArea(1);
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
            MOVIE_PLAY_STATE = MOVIE_STATE_STARTING;
            MOVIE_ID = 1;
            openTask(1, &moviePlayerTask);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->state2++;
            return;
        case 5:
            if (MOVIE_PLAY_STATE != MOVIE_STATE_IDLE) {
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
            if (MOVIE_PLAY_STATE == MOVIE_STATE_IDLE) {
                (CURRENT_TASK)->state2 = 7U;
                return;
            }
            break;
        case 7:
            temp1 = (u_char*)&GAME.areaTransition;
            *temp1 = 1;
            temp_v1_3 = CURRENT_TASK;
            *(u_short*)&temp_v1_3->state2 = 1;
            if (*(u_char* )0x1F8001B4 != 0) {
                temp_v1_3->state2 = 0U;
                *temp1 = 0;
            }
            temp_v0 = *(Task** )(&SCRATCHPAD+0x1D4);
            temp_v0->state1 = 1;
            temp_v0->step.value = 0;
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
    Task* temp_v0_2;

    temp_v1 = (CURRENT_TASK)->state2;
    switch (temp_v1) {
        case 0:
            debugSelectHandler();
            break;
        case 1:
            gameplayMainHandler();
            break;
        case 2:
            areaMode2Handler();
            break;
        case 3:
            inventoryScreenHandler();
            break;
        case 4:
            areaMode4Handler();
            break;
        case 5:
            areaMode5Handler();
            break;
        case 6:
            areaMode6Handler();
            break;
        case 7:
            areaTransitionHandler();
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
        temp_v0_2->step = (u_short) *(u_short* )0x1F8001DE;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", advanceAndResetPools);
void advanceAndResetPools(void)
{
    Task* temp_v1;

    temp_v1 = CURRENT_TASK;
    temp_v1->step.value++;
    initObjectPools();
    *(char* )0x1F8001CF = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", displayDebugScreen);
void displayDebugScreen(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    Task* temp_v1 = *(Task**)&scratch->currentTask;
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

    temp2 = (u_char*)(&GAME.areaTransition);
    var_a0 = 1;
    if (*temp2 == 0) {
        *temp2 = 1;
    } else if (GAME.selectedArea != GAME.currentArea) {
        var_a0 = 1;
    } else {
        var_a0 = 0;
        if (GAME.selectedSection == GAME.currentSection) {
            setAreaModeFromSection();
            return;
        }
    }
    loadCurrentArea(var_a0);

    temp_v1_3 = (*(Task**)(&PSX_SCRATCH[0x1D4]))->step.value;
    *(u_long*)&D_8009EB4C = 0;
    (*(Task**)(&PSX_SCRATCH[0x1D4]))->step.value=temp_v1_3+1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", debugSelectHandler);
void debugSelectHandler(void)
{
    int var_a0;
    Task* p;
    u_char* temp1;
    u_char* temp2;

    switch ((CURRENT_TASK)->step.value) {
        case 0:
            func_800222B8(9, 1);
            (CURRENT_TASK)->step.value++;
            return;
        case 1:
            if (LOAD_COMPLETE != 0) {
                (CURRENT_TASK)->step.value++;
                return;
            }
        default:
            return;
        case 2:
            (CURRENT_TASK)->step.value++;
            initObjectPools();
            *(char* )0x1F8001CF = 0;
            return;
        case 3:
            displayDebugScreen();
            return;
        case 5:
            stopAllSound();
            (*(Task**)(&SCRATCHPAD+0x1D4))->step.value++;
            initObjectPools();
            *(u_char*)&(*(u_long**)0x1F8001CF) = 0;
            (CURRENT_TASK)->unk5E = 0x78U;
            (CURRENT_TASK)->unk64 = 0U;
            return;
        case 6:
            p = *(Task**)(&SCRATCHPAD+0x1D4);
            *(u_short*)&p->unk64=((p->unk64+12)&0xFF);
            drawNowLoading(p->unk64);
            (CURRENT_TASK)->unk5E--;
            if (((CURRENT_TASK)->unk5E << 0x10) == 0) {
                var_a0 = 1;
                temp1 = (u_char*)&GAME.areaTransition;
                if (*temp1 == 0) {
                   *temp1 = 1;
                    loadCurrentArea(var_a0);
                } else {
                    if (GAME.selectedArea == GAME.currentArea) {
                        var_a0 = 0;
                        if (GAME.selectedSection == GAME.currentSection) {
                            setAreaModeFromSection(0);
                            return;
                        }
                    }
                    loadCurrentArea(var_a0);
                }
                D_8009EB4C = 0;
                (CURRENT_TASK)->step.value++;
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
    Task* temp_a0;
    Task* temp_a0_2;
    Task* temp_v1_2;

    temp_a0 = CURRENT_TASK;
    temp_v1 = temp_a0->step.value;
    switch (temp_v1) {                              // irregular
        case 0:
            initObjectPools(temp_a0);
            initHud();
            temp_a0_2 = *(Task** )(&SCRATCHPAD+0x1D4);
            *(char* )0x1F8001CF = 1;
            temp_a0_2->step.value++;
            initPlayerAtSpawn();
            func_800246B0();
            if (*(u_long*)&GAME.selectedArea == AREA06_DIRTMOTOCROSS) {
                func_8011AF40();
            } else {
                func_80028EF4();
            }
            func_80059F7C();
            if (GAME.keepBgm != 1) {
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
                temp_v1_2 = *(Task** )(&SCRATCHPAD+0x1D4);
                temp_v1_2->step.value++;
                stopBgm(1);
            }
            if ((*(u_char* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(Task** )(&SCRATCHPAD+0x1D4))->step.value = 3U;
                return;
            }
            return;
        case 2:
            if ((*(u_char* )0x1F8001BB == 0) && (temp_v0 = GAME.playerLives - 1, GAME.playerLives = temp_v0, ((temp_v0 & 0xFF) == 0))) {
                temp_a0->step.value = 3U;
            } else {
                temp_a0->state2 = 0;
                temp_a0->step.value = 5U;
                GAME.selectedSpawnPoint = 0;
                GAME.nextSpawnPoint = 0;
                GAME.playerHealth = GAME.playerHealthDisplayed;
            }
            GAME.displayExpBar = 0;
            D_800B07CD = 0;
            GAME.keepBgm = 0;
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
            temp_a0->step.value = 0U;
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
    updatePauseMenu();
    if (*(s16* )0x1F8001C6 == 0) {
        (*(s16* )(&SCRATCHPAD+0x1F8))=(*(s16* )0x1F8001F8)+1;
        updateAreaScreenEffect();
        func_80029008();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8003C9D4();
            updateMainObjects();
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
    updateSound();
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode2Handler);
void areaMode2Handler(void)
{
    char pad[4];
    scratchpad* scratch = PSX_SCRATCH;
    Task* temp_a0 = scratch->currentTask;
    
    switch(scratch->currentTask->step.value) {
        case 0:
            initObjectPools();
            initHud();
            scratch->unk1CF = 1;
            initPlayerAtSpawn();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 2;
            if ((GAME.keepBgm != 1) || (*(u_long *)&GAME == ((AREA03_PHOENIXMOUNTAIN << 16) | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS))) {
                startAreaBgm();
            }
            *(short* )0x1F8001FC = 0;
            scratch->currentTask->step.volatile_value+=1;
            *(volatile u_short*)&D_8009C9D8 = D_8009C9DC = 0;
            break;
        case 1:
            GAME.totalTimePlayed++;
            areaMode2Tick();
            if (scratch->unk1C2 != 0) {
                volatile u_short *temp_v1 = (volatile int* )&D_8009C9D8;
                if (((*temp_v1 & 0x8) != 0) && ((temp_v1[0] & 0x800) != 0)) {
                    scratch->currentTask->step.value = 2;
                }
            }
            break;
        case 2:
            setRGB0((DRAWENV*)&DRAW_ENV_1, 0, 0, 0);
            setRGB0((DRAWENV*)DRAW_ENV_2, 0, 0, 0);
            temp_a0->state2 = 8;
            temp_a0->step.value = 0;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode2Tick);
void areaMode2Tick(void)
{
    char* var_a0;
    u_short var_a1;
    Task* temp_v1;

    NEXT_PRIM = (int) ((FRAME_BUFFER_INDEX * 0xC000) + &D_800B3188) & 0xFFFFFF;
    if ((*(short* )(&SCRATCHPAD+0x1C6) == 2) && (MOVIE_PLAY_STATE == MOVIE_STATE_IDLE)) {
        *(short* )0x1F8001C6 = 0;
    }
    updatePauseMenu();
    if (GAME.inventoryScreen == 0xFF) {
        GAME.inventoryScreen = 0;
        temp_v1 = CURRENT_TASK;
        var_a0 = *(u_short*)&temp_v1->state2;
        var_a1 = *(u_short*)&(CURRENT_TASK)->step.value;
        D_800A3952 = 6;
        D_800A3954 = 0;
        D_800A3956 = 0;
        D_800A3940[0] = 0;
        temp_v1->state2 = 3U;
        (CURRENT_TASK)->step.value = 0U;
        *(short* )0x1F8003B8 = (short)var_a0;
        *(u_short* )0x1F8003BA = var_a1;
    }
    if (*(short* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u_short* )(&SCRATCHPAD+0x1F8))++;
        updateAreaScreenEffect();
        func_80029008();
        if (*(short* )0x1F8001C6 == 0) {
            func_8003C9D4();
            updateObjectsLayer7();
            updateMainObjects();
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
    updateSound();
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
    Task* temp_a0;
    Task* temp_v0;
    Task* temp_v0_2;
    Task* temp_v1_2;
    Task* temp_v1_3;

    temp_v1 = (CURRENT_TASK)->step.value;
    switch (temp_v1) {                              // switch 1
        case 0:                                     // switch 1
            *(s8* )0x1F8001CF = 1;
            (*(Task** )(&SCRATCHPAD+0x1D4))->unk6A = 0;
            SetDispMask(0);
            setRECT(&rect, 288, 480, 48, 31);
            StoreImage((RECT* ) &rect, (u32* )0x801FB000);
            setRECT(&rect, 128, 511, 256, 1);
            StoreImage((RECT* ) &rect, (u32* )0x801FBBA0);
            GetDrawEnv(&drawenv);
            setRGB0((DRAWENV*)(&DRAW_ENV_1), 248, 200, 192);
            setRGB0((DRAWENV*)(DRAW_ENV_2), 248, 200, 192);
            D_8009B000 = drawenv.r0;
            D_8009B004 = drawenv.g0;
            D_8009B008 = drawenv.b0;
            temp_a0 = CURRENT_TASK;
            temp_a0->step.value++;
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
            temp_v1_2->step.value++;
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
                temp_v1_2->step.value++;
                return;
            }
        default:                                    // switch 1
            return;
        case 3:                                     // switch 1
            inventoryScreenTick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (CURRENT_TASK)->step.value = 6U;
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
            setRGB0((DRAWENV*)(&DRAW_ENV_1), (s8) D_8009B000, (s8) D_8009B004, (s8) D_8009B008);
            setRGB0((DRAWENV*)(DRAW_ENV_2), (s8) D_8009B000, (s8) D_8009B004, (s8) D_8009B008);
            var_a0 = (D_80076FAC[(u32)GAME.selectedArea + (u16)D_8009EBA0]);
            func_800222B8(((s16*)var_a0)[GAME.selectedSection], 1);
            temp_v1_2 = CURRENT_TASK;
            temp_v1_2->step.value++;
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
                temp_v0->step.value = (u16) *(u16* )0x1F8003BA;
                return;
            }
            break;
        case 6:                                     // switch 1
            temp_v1_3 = CURRENT_TASK;
            temp_v1_3->state2 = 8U;
            temp_v1_3->step.value = 0U;
            return;
        case 7:                                     // switch 1
            GAME.areaTransition = 0;
            GAME.keepBgm = 0;
            stopBgm(0);
            setRGB0((DRAWENV*)(&DRAW_ENV_1), 0, 0, 0);
            setRGB0((DRAWENV*)(DRAW_ENV_2), 0, 0, 0);
            (CURRENT_TASK)->loadGameSelected = 1;
            temp_v0_2 = *(Task** )(&SCRATCHPAD+0x1D4);
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1;
            temp_v0_2->state2 = 0U;
            temp_v0_2->step.value = 0U;
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
            (CURRENT_TASK)->step.value = 7U;
        } else {
            if (var_s0 != 0) {
                (CURRENT_TASK)->step.value++; 
            }
        }
    } else {
        if (var_s0 == 2) {
            SetDispMask(0);
            (CURRENT_TASK)->step.value = 1;
        }else if (var_s0 != 0) {
            (CURRENT_TASK)->step.value++;
        }
    }
    updateSound();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode4Handler);
void areaMode4Handler(void)
{
    u16 temp_v1;
    ObjectRawView* temp_v0;
    Task* temp_v1_2;
    Task* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way

    temp_v1 = (CURRENT_TASK)->step.value;

    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            initPlayerAtSpawn();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.keepBgm != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(Task** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->step.value++;
            temp_v0 = (ObjectRawView*)allocObjectLayer7();
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
            areaMode4Tick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(Task** )(&SCRATCHPAD+0x1D4))->step.value = 3U;
                return;
            }
        break;

        case 2:
        case 3:
            temp_v1_3 = *(Task** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&DRAW_ENV_1), 0, 0, 0);
            setRGB0((DRAWENV*)(DRAW_ENV_2), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->step.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode4Tick);
void areaMode4Tick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    updatePauseMenu();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        updateAreaScreenEffect();
        if (*(s16*)(&SCRATCHPAD+0x1C6) == 0) {
            func_8003C9D4();
            updateMainObjects();
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
    updateSound();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode5Handler);
void areaMode5Handler(void)
{
    u16 temp_v1;
    ObjectRawView* temp_v0;
    Task* temp_v1_2;
    Task* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (CURRENT_TASK)->step.value;
    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            initPlayerAtSpawn();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.keepBgm != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(Task** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->step.value++;
            temp_v0 = (ObjectRawView*)allocObjectLayer7();
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
            areaMode5Tick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(Task** )(&SCRATCHPAD+0x1D4))->step.value = 3U;
                return;
            }
        break;
    
        case 2:
        case 3:
            temp_v1_3 = *(Task** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&DRAW_ENV_1), 0, 0, 0);
            setRGB0((DRAWENV*)(DRAW_ENV_2), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->step.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode5Tick);
void areaMode5Tick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    updatePauseMenu();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        updateAreaScreenEffect();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            updateMainObjects();
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
    updateSound();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode6Handler);
void areaMode6Handler(void)
{
    u16 temp_v1;
    ObjectRawView* temp_v0;
    Task* temp_v1_2;
    Task* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (CURRENT_TASK)->step.value;
    switch (temp_v1) {
        case 0:
            initObjectPools();
            initHud();
            initPlayerAtSpawn();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770[0] = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.keepBgm != 1) {
                startAreaBgm();
            }
            temp_v1_2 = *(Task** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->step.value++;
            temp_v0 = (ObjectRawView*)allocObjectLayer7();
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
            areaMode6Tick();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(Task** )(&SCRATCHPAD+0x1D4))->step.value = 3U;
                return;
            }
        break;
    
        case 2:
        case 3:
            temp_v1_3 = *(Task** )(&SCRATCHPAD+0x1D4);
            setRGB0((DRAWENV*)(&DRAW_ENV_1), 0, 0, 0);
            setRGB0((DRAWENV*)(DRAW_ENV_2), 0, 0, 0);
            temp_v1_3->state2 = 8;
            temp_v1_3->step.value = 0U;
        break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaMode6Tick);
void areaMode6Tick(void)
{
    NEXT_PRIM = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    updatePauseMenu();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(s16* )(&SCRATCHPAD+0x1F8))++;
        updateAreaScreenEffect();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            updateMainObjects();
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
    updateSound();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", displayLoadingScreen);
void displayLoadingScreen(void)
{
    u_short temp_a1;
    u_short temp_v0;
    Task* temp_a0;
    Task* temp_v0_2;
    Task* temp_v1;

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
            temp_a0 = *(Task**)(&SCRATCHPAD+0x1D4);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", loadCurrentArea);
void loadCurrentArea(s16 arg0)
{
    s32 variant;
    s32 val;

    variant = resolveAreaVariant() & 0xFF;

    val = D_80077084[GAME.selectedArea + (u16)D_8009EBA0][GAME.selectedSection];
    *(short*)0x1F8001DE = 0;
    D_8009C610 = GAME.selectedArea;
    D_8009C612 = GAME.selectedSection;
    D_8009C614 = D_8009BCEA;
    *(short*)0x1F8001DC = val;

    func_80021C24(GAME.selectedArea + (u16)D_8009EBA0);

    if (loadAreaSectionResources((s16)arg0) != -1) {
        D_8009BCCF = 2;
    }

    func_80021CC8(GAME.selectedArea + (u16)D_8009EBA0, GAME.selectedSection, (s16)(arg0 | variant));
    loadAreaSoundBank();
    startSoundTask();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", setAreaModeFromSection);
void setAreaModeFromSection(void)
{
    u8* row = D_80077084[GAME.selectedArea + (u16)D_8009EBA0];
    u8  v = row[D_8009BCCA];
    Task* p = CURRENT_TASK;

    p->step.value = 0;
    p->state2 = v;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", areaTransitionHandler);
void areaTransitionHandler(void)
{
    switch (CURRENT_TASK->step.value) {
    case 0:
        func_800222B8(9, 1);
        goto advance;
    case 1:
        if (LOAD_COMPLETE == 0) break;
    advance:
        CURRENT_TASK->step.value++;
        break;
    case 2:
        CURRENT_TASK->step.value++;
        asm("");
        D_8009BCCF = 1;
        D_8009BCE9 = 1;
        break;
    case 3:
    {
        gameConfig* gp;
        s32 areaChanged;
        s32 variant;
        s32 val;

        gp = &GAME;
        areaChanged = gp->selectedArea != D_8009C0FC;
        {
            Task* task;
            task = CURRENT_TASK;
            task->step.value = 4;

            if (areaChanged) {
                D_8009BCCF = 2;
                stopAllSound();
                (*(Task**)(&SCRATCHPAD + 0x1D4))->step.value = 5;
                asm("");
                if (D_8009C0FC == 0) {
                    if ((u32)(D_8009C0FE - 1) < 2) {
                        D_8009BCE9 = 1;
                    }
                } else if (D_8009C0FC == 1) {
                    if (D_8009C0FE == 1) {
                        D_8009BCE9 = 1;
                    }
                } else {
                    D_8009BCE9 = 0;
                }
            } else {
                if (gp->selectedArea == 2) {
                    if (D_8009BCCA + D_8009C0FE == 1) {
                        task->step.value = 5;
                    }
                }
            }
        }

        gp->selectedArea = gp->nextArea;
        gp->selectedSection = gp->nextSection;
        gp->selectedSpawnPoint = gp->nextSpawnPoint;

        variant = resolveAreaVariant() & 0xFF;

        val = D_80077084[GAME_A + (u16)D_8009EBA0][D_8009BCCA];
        *(short*)0x1F8001DE = 0;
        D_8009C610 = GAME_A;
        D_8009C612 = D_8009BCCA;
        D_8009C614 = D_8009BCEA;
        *(short*)0x1F8001DC = val;

        func_80021C24(GAME_A + (u16)D_8009EBA0);

        if (loadAreaSectionResources(areaChanged) != -1) {
            D_8009BCCF = 2;
        }

        func_80021CC8(GAME_B + (u16)D_8009EBA0, D_8009BCCA, variant | areaChanged);
        loadAreaSoundBank();
        startSoundTask();
        D_8009EB4C = 0;
        break;
    }
    case 5:
        displayLoadingScreen();
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", transitionToGameOver);
void transitionToGameOver(void)
{
    scratchpad* scratch = PSX_SCRATCH;
    Task* temp_v1;

    temp_v1 = scratch->currentTask;
    scratch->unk1CF = 1;
    setRGB0((DRAWENV*)&DRAW_ENV_1, 0, 0, 0);
    setRGB0((DRAWENV*)DRAW_ENV_2, 0, 0, 0);
    temp_v1->state1 = 3;
    temp_v1->state2 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001D2F0);
void func_8001D2F0(void)
{
    Task* task = (Task*)D_1F8001D4;

    switch ((u_short)task->state2) {
    case 0:
        task->countdown = 0xF0;
        task->step.value = 0;
        LOAD_COMPLETE = 0;
        task->state2++;
        func_800222B8(0x5D, 1);
        break;
    case 1:
        if (LOAD_COMPLETE == 0) break;
        task->state2++;
        break;
    case 2:
    {
        Task* t2;
        s16 val;
        func_800E7E68();
        t2 = (*(Task**)(&SCRATCHPAD + 0x1D4));
        val = --t2->countdown;
        if (val == -1) {
            t2->state2++;
        } else {
            if (val >= 0x3D) {
                if (JOYPAD_STATE & (JOY_START | JOY_CIRCLE | JOY_CROSS)) {
                    t2->countdown = 0x3C;
                }
            }
            if ((s16)CURRENT_TASK->countdown == 0x3C) {
                stopBgm(1);
            }
        }
        updateSound();
        break;
    }
    case 3:
    {
        Task* t;
        stopAllSound();
        t = TASK_C;
        *(char*)0x1F8001D0 = 0;
        t->state0 = 1;
        t->state1 = 0;
        t->state2 = 0;
        t->step.value = 0;
        setTask(&titleSequenceTask);
        break;
    }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", func_8001D480);
void func_8001D480(void)
{
    Task* task = (Task*)D_1F8001D4;

    switch ((u_short)task->state2) {
    case 0:
    {
        Task* t0;
        func_80028CE4();
        stopBgm(0);
        t0 = (*(Task**)(&SCRATCHPAD + 0x1D4));
        t0->countdown = 0xF0;
        t0->step.value = 0;
        t0->state2++;
        stopAllSound();
        LOAD_COMPLETE = 0;
        func_800222B8(0x5D, 1);
        break;
    }
    case 1:
    {
        Task* t1;
        if (LOAD_COMPLETE == 0) break;
        SetDispMask(1);
        t1 = CURRENT_TASK;
        t1->state2++;
        break;
    }
    case 2:
    {
        Task* t2;
        s16 val;
        func_800E7CDC();
        t2 = TASK_C;
        val = --t2->countdown;
        if (val == -1) {
            t2->state2++;
        } else if (val < 0xC8) {
            if (JOYPAD_STATE & (JOY_START | JOY_CIRCLE | JOY_CROSS)) {
                t2->countdown = 0;
            }
        }
        break;
    }
    case 3:
        task->state0 = 1;
        task->state1 = 0;
        task->state2 = 0;
        task->step.value = 0;
        *(char*)0x1F8001D0 = 0;
        setTask(&titleSequenceTask);
        break;
    }
}

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
    Task* p = CURRENT_TASK;

    D_800A3952 = arg0;
    D_800A3954 = arg1;
    D_800A3956 = arg2;
    D_800A3940[0] = 0;
    p->state2 = 3;
    p->step.value = 0;
    playSFXWithNote(10, 10);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", updatePauseMenu);
typedef struct {
    u8 unk0;
    u8 unk1;
    u8 pad2[0x10];
    s16 unk12;
    s16 unk14;
    s16 unk16;
} unk_800A3940;
#define MENU_STATE ((unk_800A3940*)D_800A3940)

void updatePauseMenu(void) {
    if (*(u8*)0x1F8003CE | MOVIE_PLAY_STATE) {
        return;
    }

    switch (*(s16*)0x1F8001C6) {
    case 0: {
        u16 pad;

        if (D_8009BCDD != 0 && D_8009BCDD != 0x10) {
            return;
        }

        pad = JOYPAD_STATE;
        if ((pad & JOY_START) || D_8009EB58 != 0) {
            *(s16*)(&SCRATCHPAD + 0x1C6) = 1;
            D_8009C10B = 0;
            *(&SCRATCHPAD + 0x3CD) = 1;
            keyOffSfxAll(0);
            playSFX(0x29);
            return;
        }

        if (D_8009C10A != 0) {
            return;
        }
        if (D_8009BCA2 == 0) {
            return;
        }
        if (D_8009C618 != 1) {
            return;
        }
        if (D_8009BCA7 != 0) {
            return;
        }

        if (D_800A5462 != D_8009C618) {
            if (D_800A539C != D_8009C618) {
                return;
            }
            if (D_800A539D >= 0x20) {
                return;
            }
        }

        if (pad & JOY_SELECT) {
            *(s16*)(&SCRATCHPAD + 0x1C6) = 1;
            D_8009C10B = 0;
            *(&SCRATCHPAD + 0x3CD) = 0;
            keyOffSfxAll(0);
            playSFX(0x29);
            return;
        }

        if (*(u8*)0x1F8001B8 != 0) {
            return;
        }
        if ((pad & *(u16*)0x1F8003CA) == 0) {
            return;
        }

        *(s16*)(&SCRATCHPAD + 0x1C6) = 1;
        D_8009C10B = 4;
        *(&SCRATCHPAD + 0x3CD) = 0;
        keyOffSfxAll(0);

        {
            Task* p;
            u16 savedS2;
            u16 savedUn;
            p = CURRENT_TASK;
            savedS2 = p->state2;
            savedUn = p->step.value;

            MENU_STATE->unk12 = 7;
            MENU_STATE->unk16 = 4;
            MENU_STATE->unk14 = 0;
            MENU_STATE->unk0 = 0;
            p->state2 = 3;
            p->step.value = 0;
            *(u16*)0x1F8003B8 = savedS2;
            *(u16*)0x1F8003BA = savedUn;
            playSFXWithNote(10, 10);
        }
        break;
    }

    case 1: {
        u8 cd;
        short buttons;

        cd = *(u8*)0x1F8003CD;
        switch (cd) {
        case 0:
            buttons = JOY_CIRCLE | JOY_SELECT;
            break;
        case 1:
            buttons = JOY_CIRCLE;
            break;
        }

        if (*(u8*)0x1F8003CD < 2) {
            if (JOYPAD_STATE & buttons) {
                *(u16*)(&SCRATCHPAD + 0x1FC) = 0;
                *(s16*)(&SCRATCHPAD + 0x1C6) = 0;
                D_8009C10B = 0;
                return;
            }
        }

        switch (*(u8*)0x1F8003CD) {
        case 0: {
            u16 pad = JOYPAD_STATE;

            if (pad & JOY_START) {
                *(s16*)(&SCRATCHPAD + 0x1C6) = 1;
                D_8009C10B = 0;
                *(&SCRATCHPAD + 0x3CD) = 1;
                playSFX(0x29);
                return;
            }

            if (pad & JOY_CROSS) {
                Task* task = CURRENT_TASK;
                u16 s2 = task->state2;
                u16 un = task->step.value;
                int c10b;

                *(u16*)0x1F8003B8 = s2;
                *(u16*)0x1F8003BA = un;

                c10b = D_8009C10B;
                switch (c10b) {
                case 0:
                    MENU_STATE->unk16 = 4;
                    MENU_STATE->unk12 = c10b + 1;
                    MENU_STATE->unk14 = 0;
                    MENU_STATE->unk0 = 0;
                    task->state2 = 3;
                    task->step.value = 0;
                    playSFXWithNote(10, 10);
                    return;
                case 1:
                    MENU_STATE->unk12 = 2;
                    MENU_STATE->unk16 = 5;
                    MENU_STATE->unk14 = 0;
                    MENU_STATE->unk0 = 0;
                    task->state2 = 3;
                    task->step.value = 0;
                    playSFXWithNote(10, 10);
                    return;
                case 2:
                    MENU_STATE->unk16 = 6;
                    MENU_STATE->unk12 = 0;
                    MENU_STATE->unk14 = 0;
                    MENU_STATE->unk0 = 0;
                    task->state2 = 3;
                    task->step.value = 0;
                    playSFXWithNote(10, 10);
                    return;
                case 3:
                    MENU_STATE->unk16 = 7;
                    MENU_STATE->unk12 = c10b;
                    MENU_STATE->unk14 = 0;
                    MENU_STATE->unk0 = 0;
                    task->state2 = 3;
                    task->step.value = 0;
                    playSFXWithNote(10, 10);
                    return;
                }
                return;
            }

            if (pad & JOY_UP) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val != 0) {
                    *p = val - 1;
                    playSFX(8);
                    return;
                }
            }

            if (JOYPAD_STATE & JOY_DOWN) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val < 3) {
                    *p = val + 1;
                    playSFX(8);
                    return;
                }
            }
            break;
        }

        case 1: {
            u16 pad = JOYPAD_STATE;

            if (pad & (JOY_START | JOY_CROSS)) {
                u8* s0 = &D_8009C10B;
                u8 c10b = *s0;

                switch (c10b) {
                case 0:
                    *(u16*)(&SCRATCHPAD + 0x1FC) = 0;
                    *(s16*)(&SCRATCHPAD + 0x1C6) = 0;
                    *s0 = 0;
                    return;
                case 1:
                    playSFXWithNote(10, 10);
                    *(&SCRATCHPAD + 0x3CD) = 2;
                    *s0 = 1;
                    return;
                case 2:
                    playSFXWithNote(10, 10);
                    *(&SCRATCHPAD + 0x3CD) = 3;
                    *s0 = 1;
                    return;
                default:
                    return;
                }
            }

            if (pad & JOY_UP) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val != 0) {
                    *p = val - 1;
                    playSFX(8);
                    return;
                }
            }

            if (JOYPAD_STATE & JOY_DOWN) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val < 2) {
                    *p = val + 1;
                    playSFX(8);
                    return;
                }
            }
            break;
        }

        case 2:
        case 3:
            if (JOYPAD_STATE & (JOY_START | JOY_CROSS)) {
                u8 c10b = D_8009C10B;

                if (c10b == 0) {
                    if (*(u8*)0x1F8003CD == 2) {
                        SetDispMask(0);
                        stopAllSound();
                        {
                            Task* task = CURRENT_TASK;
                            task->state0 = 1;
                            task->state1 = 3;
                            task->state2 = 3;
                        }
                    } else {
                        Task* task;
                        u16 s2, un;

                        playSFXWithNote(10, 10);
                        task = CURRENT_TASK;
                        s2 = task->state2;
                        un = task->step.value;

                        MENU_STATE->unk12 = 5;
                        MENU_STATE->unk0 = 0;
                        MENU_STATE->unk1 = 0;
                        MENU_STATE->unk16 = 0;
                        task->state2 = 3;
                        task->step.value = 0;
                        *(u16*)0x1F8003B8 = s2;
                        *(u16*)0x1F8003BA = un;
                    }
                    return;
                }
                if (c10b == 1) goto cd_check;
            }

            if (JOYPAD_STATE & JOY_CIRCLE) {
            cd_check:
                if (*(u8*)0x1F8003CD == 2) {
                    D_8009C10B = 1;
                } else {
                    D_8009C10B = 2;
                }
                *(&SCRATCHPAD + 0x3CD) = 1;
                return;
            }

            if (JOYPAD_STATE & JOY_RIGHT) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val == 0) {
                    *p = val + 1;
                    playSFX(8);
                    return;
                }
            }

            if (JOYPAD_STATE & JOY_LEFT) {
                u8 *p = &D_8009C10B;
                u8 val = *p;
                if (val == 1) {
                    *p = val - 1;
                    playSFX(8);
                    return;
                }
            }
            break;
        }
        break;
    }
    case 2:
        return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", loadAreaSectionResources);
s32 loadAreaSectionResources(s32 arg)
{
    gameConfig* gp = &GAME;
    u32 s2 = gp->selectedArea + (u16)D_8009EBA0;
    u32 _t;
    u8 s1 = (_t = D_8007716C[s2], *(u8*)(_t + D_8009BCCA));
    s32 s4 = -1;
    u8 s0;

    if (s1 == 9) {
        if (D_8009C62B & 2) {
            s1 = 0xA;
        }
    }
    if (s1 == 0xB) {
        if (D_8009C62B & 4) {
            s1 = 0xC;
        }
    }

    s0 = s1;

    if (*(u8*)0x1F8003D3 != s0 || arg != 0) {
        loadAreaResources(s0);
        s4 = s0;
        stopAllSound();
        *(&SCRATCHPAD + 0x3D3) = s1;
    }

    if (s2 == 1 || s2 == 7) {
        keyOffActiveSfxVoices();
        loadAreaResources(D_800771BC[gp->selectedSection]);
    } else if (s2 == 0xA && gp->selectedSection != 3 && gp->selectedSection != 7) {
        keyOffActiveSfxVoices();
        loadAreaResources(D_800771C4[gp->selectedSection]);
    } else if (s2 == 0xC) {
        keyOffActiveSfxVoices();
        loadAreaResources(D_800771D0[gp->selectedSection]);
    }

    return s4;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/gamestate", updateMainObjects);
void updateMainObjects(void)
{
    u8* s0 = (u8*)&D_800A5970;
    u8* s1 = s0 + 2;

    *(s32*)&D_1F800198 = 0;

    do {
        if (*s0 != 0) {
            switch (s1[0x1A] & 0x7F) {
            case 2:
                ((void (*)(u8*))D_800772BC[*s1])(s0);
                break;
            case 3:
                ((void (*)(u8*))D_8007C6B0[*s1])(s0);
                break;
            case 4:
                ((void (*)(u8*))D_8007D30C[*s1])(s0);
                break;
            case 5:
                ((void (*)(u8*))D_8007E8A8[*s1])(s0);
                break;
            }
        }
        s1 += 0xD4;
        s0 += 0xD4;
    } while (++(*(s32*)&D_1F800198) < 0xC8);
}
