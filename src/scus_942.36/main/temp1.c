#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001A774);
void func_8001A774(void)
{
    short var_v0;
    int temp_v0;
    u_short temp_v1;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v0_3;
    unkstruct_1F8001D4* temp_v1_2;

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state1;
    switch (temp_v1) {
        case 0:
            SetDispMask(0);
            func_80028CE4();
            *(u_char* )0x1F8001CE = 0;
            func_800223A0(3);
            func_800222B8(5, 1);
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_2->state1++;;
            return;
        case 1:
            if (*(u_char* )0x1F8001CE != 0) {
                func_8001821C();
                D_800A3952 = 5;
                func_80020AF0(0);
                SetDispMask(1);
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state1++;;
                return;
            }
        default:
            return;
        case 2:
            *(int* )0x1F800164 = (int) ((*(short* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
            temp_v0 = func_800E9438();
            if (temp_v0 == 1) {
                (*(unkstruct_1F8001D4** )0x1F8001D4)->state1++;
            } else {
                if (temp_v0 == -1) (*(unkstruct_1F8001D4** )0x1F8001D4)->state1 = 4;
            }
            func_800E9EF8();
            func_8001F6D4();
            return;
        case 3:
            GAME.unk14 = 0;
            GAME.unk7 = 0;
            func_80020C00(0);
            temp_v0_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1U;
            temp_v0_2->state2 = 0;
            temp_v0_2->unk4E.value = 0;
            return;
        case 4:
            func_80020C00(0);
            temp_v0_3 = *(unkstruct_1F8001D4** )0x1F8001D4;
            *(char* )0x1F8001D0 = 0;
            temp_v0_3->state0 = 1;
            temp_v0_3->state1 = 0U;
            temp_v0_3->state2 = 0;
            temp_v0_3->unk4E.value = 0;
            setTask(&func_80019844);
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001A954);
void func_8001A954(void)
{
    u_short temp_v1;

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state1;
    switch (temp_v1) {
        case 0:
            func_8001A9F0();
            return;
        case 1:
            func_8001AC00();
            return;
        case 2:
            func_8001D2F0();
            return;
        case 3:
            func_8001D480();
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001A9F0);
void func_8001A9F0(void)
{
    u_short temp_v1;
    u_char* temp1;
    unkstruct_1F8001D4* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state2;
    switch (temp_v1) {
        case 0:
            func_800222B8(9, 1);
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_2->state2++;
            return;
        case 1:
            if (*(u_char* )0x1F8001CE != 0) {
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state2++;
                return;
            }
        default:
            return;
        case 2:
            if (*(u_char* )0x1F8001B4 == 0) {
                D_8009EB4C = 0;
                *(u_char* )0x1F8001CE = 0U;
                func_8001CE80(1);
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state2++;
                return;
            }
            (*(unkstruct_1F8001D4** )0x1F8001D4)->state2 = 7U;
            return;
        case 3:
            displayLoadingScreen();
            if (*(u_char* )0x1F8001CE != 0) {
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state2++;
                return;
            }
            break;
        case 4:
            *(u_char* )0x1F8001CC = 1;
            *(char* )0x1F8001CD = 1;
            func_80017154(1, &func_8001F1C0);
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_2->state2++;
            return;
        case 5:
            if (*(u_char* )0x1F8001CC != 0) {
                if (*(u_short* )(&SCRATCHPAD+0x1FC) & (JOY_CROSS | JOY_START)) {
                    *(char* )0x1F8001D3 = 1;
                    *(u_short* )0x1F8001FC = 0U;
                    (*(unkstruct_1F8001D4** )0x1F8001D4)->state2 = 6U;
                    return;
                }
            } else {
                (*(unkstruct_1F8001D4** )0x1F8001D4)->state2 = 7U;
                return;
            }
            break;
        case 6:
            if (*(u_char* )0x1F8001CC == 0) {
                (*(unkstruct_1F8001D4** )0x1F8001D4)->state2 = 7U;
                return;
            }
            break;
        case 7:
            temp1 = (u_char*)&GAME.unk14;
            *temp1 = 1;
            temp_v1_3 = *(unkstruct_1F8001D4** )0x1F8001D4;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001AC00);
void func_8001AC00(void)
{
    short temp_v0;
    u_short temp_v1;
    unkstruct_1F8001D4* temp_v0_2;

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state2;
    switch (temp_v1) {
        case 0:
            func_8001B0A4();
            break;
        case 1:
            func_8001B2B4();
            break;
        case 2:
            func_8001B780();
            break;
        case 3:
            func_8001BB1C();
            break;
        case 4:
            func_8001C104();
            break;
        case 5:
            func_8001C434();
            break;
        case 6:
            func_8001C75C();
            break;
        case 7:
            func_8001CFCC();
            break;
        case 8:
            func_8001D29C();
            break;
    }
    temp_v0 = *(short* )0x1F8001DC;
    if ((temp_v0 >= 0) && ((*(u_char* )0x1F8001CE) != 0)) {
        temp_v0_2 = (*(unkstruct_1F8001D4** )0x1F8001D4);
        *(short* )(&SCRATCHPAD+0x1DC) = -1;
        temp_v0_2->state2 = (u_short) temp_v0;
        temp_v0_2->unk4E = (u_short) *(u_short* )0x1F8001DE;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001AD1C);
void func_8001AD1C(void)
{
    unkstruct_1F8001D4* temp_v1;

    temp_v1 = *(unkstruct_1F8001D4** )0x1F8001D4;
    temp_v1->unk4E.value++;
    func_8001758C();
    *(char* )0x1F8001CF = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", displayDebugScreen);
void displayDebugScreen(void)
{
    typedef inline struct {
        char data[0x1B4];
        u_char debug_mode_enabled;
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
        u_short joypad_state;
    } scratchpad;

    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1 = *(unkstruct_1F8001D4**)&scratch->unk1D4;
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
        FontDebugPrintf(32, 96, 0U, &SPRINTF_BUFFER_MSG);
        sprintf(&SPRINTF_BUFFER_MSG, "SECTION SELECT = %02d", GAME.selectedSection);
        FontDebugPrintf(32, 104, 0U, &SPRINTF_BUFFER_MSG);
        // Print asterisk cursor on the selected row
        sprintf(&SPRINTF_BUFFER_MSG, "*");
        FontDebugPrintf(24, ((short) D_8009B6A8 + 0xC) * 8, (u_long) (*(u_short*)&PSX_SCRATCH[0x1F6] & 0xC) >> 2, &SPRINTF_BUFFER_MSG);
        // Set next area, section and spawn point to the selected ones
        GAME.nextArea = GAME.selectedArea;
        GAME.nextSection = GAME.selectedSection;
        GAME.nextSpawnPoint = GAME.selectedSpawnPoint;
        // If any action button (CIRCLE or START) is pressed
        if (scratch->joypad_state & 0x2008) {
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
            func_8001CF7C();
            return;
        }
    }
    func_8001CE80(var_a0);

    temp_v1_3 = (*(unkstruct_1F8001D4**)(&PSX_SCRATCH[0x1D4]))->unk4E.value;
    *(u_long*)&D_8009EB4C = 0;
    (*(unkstruct_1F8001D4**)(&PSX_SCRATCH[0x1D4]))->unk4E.value=temp_v1_3+1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001B0A4);
void func_8001B0A4(void)
{
    int var_a0;
    unkstruct_1F8001D4* p;
    u_char* temp1;
    u_char* temp2;

    switch ((*(unkstruct_1F8001D4**)0x1F8001D4)->unk4E.value) {
        case 0:
            func_800222B8(9, 1);
            (*(unkstruct_1F8001D4**)0x1F8001D4)->unk4E.value++;
            return;
        case 1:
            if (*(u_char* )0x1F8001CE != 0) {
                (*(unkstruct_1F8001D4**)0x1F8001D4)->unk4E.value++;
                return;
            }
        default:
            return;
        case 2:
            (*(unkstruct_1F8001D4**)0x1F8001D4)->unk4E.value++;
            func_8001758C();
            *(char* )0x1F8001CF = 0;
            return;
        case 3:
            displayDebugScreen();
            return;
        case 5:
            func_80020FAC();
            (*(unkstruct_1F8001D4**)(&SCRATCHPAD+0x1D4))->unk4E.value++;
            func_8001758C();
            *(u_char*)&(*(u_long**)0x1F8001CF) = 0;
            (*(unkstruct_1F8001D4**)0x1F8001D4)->unk5E = 0x78U;
            (*(unkstruct_1F8001D4**)0x1F8001D4)->unk64 = 0U;
            return;
        case 6:
            p = *(unkstruct_1F8001D4**)(&SCRATCHPAD+0x1D4);
            *(u_short*)&p->unk64=((p->unk64+12)&0xFF);
            func_80023E44(p->unk64);
            (*(unkstruct_1F8001D4**)0x1F8001D4)->unk5E--;
            if (((*(unkstruct_1F8001D4**)0x1F8001D4)->unk5E << 0x10) == 0) {
                var_a0 = 1;
                temp1 = (u_char*)&GAME.unk14;
                if (*temp1 == 0) {
                   *temp1 = 1;
                    func_8001CE80(var_a0);
                } else {
                    if (GAME.selectedArea == GAME.currentArea) {
                        var_a0 = 0;
                        if (GAME.selectedSection == GAME.currentSection) {
                            func_8001CF7C(0);
                            return;
                        }
                    }
                    func_8001CE80(var_a0);
                }
                D_8009EB4C = 0;
                (*(unkstruct_1F8001D4**)0x1F8001D4)->unk4E.value++;
            }
            break;
        case 4:
        case 7:
            displayLoadingScreen();
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001B2B4);
void func_8001B2B4(void)
{
    u_short temp_v1;
    u_char temp_v0;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_a0_2;
    unkstruct_1F8001D4* temp_v1_2;

    temp_a0 = *(unkstruct_1F8001D4** )0x1F8001D4;
    temp_v1 = temp_a0->unk4E.value;
    switch (temp_v1) {                              // irregular
        case 0:
            func_8001758C(temp_a0);
            func_80017AE0();
            temp_a0_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            *(char* )0x1F8001CF = 1;
            temp_a0_2->unk4E.value++;
            func_800243E8();
            func_800246B0();
            if (*(u_long*)&GAME.selectedArea == 6) {
                func_8011AF40();
            } else {
                func_80028EF4();
            }
            func_80059F7C();
            if (GAME.unk7 != 1) {
                func_8002065C();
            }
            GAME.unk21 = 1;
            *(&D_8009C9D8) = D_8009C9DC = 0;
            *(short*)(&SCRATCHPAD+0x1FC)=0;
            return;
        case 1:
            GAME.totalTimePlayed++;
            func_8001B5A8(temp_a0);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001B5A8);
void func_8001B5A8(void)
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
            func_8003438C();
            func_8005A074();
            func_80055BA0();
        }
    }
    if (*(s16* )0x1F8001C6 != 1) {
        func_80029C48();
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        func_8002DA2C();
        func_8002DB3C();
    }
    // Hack to match (using this instead SCRATCHPAD to access 1F8001C6)
    if (*(s16* )((byte*)&D_1F8001A0+0x26) != 2) {
        func_80046264();
    } else {
        func_80017614();
    }
    func_8001F6D4();
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001B780);
void func_8001B780(void)
{
    typedef inline struct {
        char data[0x1C2];
        u_char unk1C2;
        char pad[12];
        u_char unk1CF;
        char pad2[4];
        unkstruct_1F8001D4 *unk1D4;
    } scratchpad;

    char pad[4];
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_a0 = scratch->unk1D4;
    
    switch(scratch->unk1D4->unk4E.value) {
        case 0:
            func_8001758C();
            func_80017AE0();
            scratch->unk1CF = 1;
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770 = 2;
            if ((GAME.unk7 != 1) || (*(u_long *)&GAME == ((AREA03_PHOENIXMOUNTAIN << 16) | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS))) {
                func_8002065C();
            }
            *(short* )0x1F8001FC = 0;
            scratch->unk1D4->unk4E.volatile_value+=1;
            *(volatile u_short*)&D_8009C9D8 = D_8009C9DC = 0;
            break;
        case 1:
            GAME.totalTimePlayed++;
            func_8001B944();
            if (scratch->unk1C2 != 0) {
                volatile u_short *temp_v1 = (volatile int* )&D_8009C9D8;
                if (((*temp_v1 & 0x8) != 0) && ((temp_v1[0] & 0x800) != 0)) {
                    scratch->unk1D4->unk4E.value = 2;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001B944);
void func_8001B944(void)
{
    char* var_a0;
    u_short var_a1;
    unkstruct_1F8001D4* temp_v1;

    *(int* )0x1F800164 = (int) ((*(short* )(0x1F8001F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    if ((*(short* )(&SCRATCHPAD+0x1C6) == 2) && (*(u_char* )0x1F8001CC == 0)) {
        *(short* )0x1F8001C6 = 0;
    }
    func_8001D6C0();
    if (GAME.inventoryScreen == 0xFF) {
        GAME.inventoryScreen = 0;
        temp_v1 = *(unkstruct_1F8001D4** )0x1F8001D4;
        var_a0 = *(u_short*)&temp_v1->state2;
        var_a1 = *(u_short*)&(*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value;
        D_800A3952 = 6;
        D_800A3954 = 0;
        D_800A3956 = 0;
        D_800A3940 = 0;
        temp_v1->state2 = 3U;
        (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value = 0U;
        *(short* )0x1F8003B8 = (short)var_a0;
        *(u_short* )0x1F8003BA = var_a1;
    }
    if (*(short* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u_short* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        func_80029008();
        if (*(short* )0x1F8001C6 == 0) {
            func_8003C9D4();
            func_8003438C();
            func_8001DFD4();
            func_8005A074();
            func_80055BA0();
        }
    }
    if (*(short* )(&D_1F8000C0[0]+0x106) != 1) {
        func_80029C48();
    }
    if (*(short* )(&SCRATCHPAD+0x1C6) == 0) {
        func_8002DA2C();
        func_8002DB3C();
    }
    if (*(short* )0x1F8001C6 != 2) {
        func_80046264();
    } else {
        func_80017614();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001BB1C);
void func_8001BB1C(void)
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

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value;
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
            temp_a0 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_a0->unk4E.value++;
            return;
        case 1:                                     // switch 1
            *(u8* )0x1F8001CE = 0;
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
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_2->unk4E.value++;
            return;
        case 2:                                     // switch 1
            if (*(u8* )0x1F8001CE != 0) {
                EnterCriticalSection();
                FlushCache();
                ExitCriticalSection();
                temp_s1 = *(volatile u16*)&D_800A3952;
                func_8001821C();
                *(s16*)&(*(volatile u16**)&D_800A3952) = temp_s1;
                SetDispMask(1);
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->unk4E.value++;
                return;
            }
        default:                                    // switch 1
            return;
        case 3:                                     // switch 1
            func_8001BF90();
            if ((*(u8* )0x1F8001C2 != 0) && (*&D_8009C9D8 & 8) && (*&D_8009C9D8 & 0x800)) {
                (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value = 6U;
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
            var_a0 = ((&D_80076FAC)[(u32)GAME.selectedArea + (u16)D_8009EBA0]);
            func_800222B8(((s16*)var_a0)[GAME.selectedSection], 1);
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_2->unk4E.value++;
            return;
        case 5:                                     // switch 1
            if ((*(u8* )0x1F8001CE) != 0) {
                EnterCriticalSection();
                FlushCache();
                ExitCriticalSection();
                SetDispMask(1);
                temp_v0 = *(unkstruct_1F8001D4** )0x1F8001D4;
                *(s16* )0x1F8001C6 = 0;
                temp_v0->state2 = (u16) *(u16* )0x1F8003B8;
                temp_v0->unk4E.value = (u16) *(u16* )0x1F8003BA;
                return;
            }
            break;
        case 6:                                     // switch 1
            temp_v1_3 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_3->state2 = 8U;
            temp_v1_3->unk4E.value = 0U;
            return;
        case 7:                                     // switch 1
            GAME.unk14 = 0;
            GAME.unk7 = 0;
            func_80020C00(0);
            setRGB0((DRAWENV*)(&D_8009D6C4), 0, 0, 0);
            setRGB0((DRAWENV*)(D_8009E3D4), 0, 0, 0);
            (*(unkstruct_1F8001D4** )0x1F8001D4)->loadGameSelected = 1;
            temp_v0_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v0_2->state0 = 1;
            temp_v0_2->state1 = 1;
            temp_v0_2->state2 = 0U;
            temp_v0_2->unk4E.value = 0U;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001BF90);
void func_8001BF90(void)
{
    s32 var_s0;

    *(u16* )(&SCRATCHPAD+0x1F8)=*(u16* )(0x1F8001F8)+1;
    *(s32* )0x1F800164 = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
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
            (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value = 7U;
        } else {
            if (var_s0 != 0) {
                (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value++; 
            }
        }
    } else {
        if (var_s0 == 2) {
            SetDispMask(0);
            (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value = 1;
        }else if (var_s0 != 0) {
            (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value++;
        }
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C104);
void func_8001C104(void)
{
    typedef inline struct {
        u_char unk0;
        u_char unk1;
        u_char unk2;
        u_char unk3;
        u_char unk4;
        u_char unk5;
        u_char unk6;
        u_char unk7;
        u_char unk8;
        u_char unk9;
        u_char unkA;
        u_char unkB;
        u_char unkC;
        u_char unkD;
        u_char unkE;
        u_char unkF;
        u_char unk10;
        u_char unk11;
        u_short unk12;
        u_short unk14;
        u_short unk16;
        u_short unk18;
        u_short unk1A;
    } unkstruct_1F800214;
    
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value;

    switch (temp_v1) {
        case 0:
            func_8001758C();
            func_80017AE0();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770 = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                func_8002065C();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)func_80018614();
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
            func_8001C2E8();
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C2E8);
void func_8001C2E8(void)
{
    *(s32* )0x1F800164 = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16*)(&SCRATCHPAD+0x1C6) == 0) {
            func_8003C9D4();
            func_8001DFD4();
            func_8005A074();
            func_800EB804();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        func_80029C48();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        func_8002DB3C();
        if (*(s16* )0x1F8001C6 == 0) {
            func_800EAED4();
            func_8003438C();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        func_80017614();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C434);
void func_8001C434(void)
{
    typedef inline struct {
        u_char unk0;
        u_char unk1;
        u_char unk2;
        u_char unk3;
        u_char unk4;
        u_char unk5;
        u_char unk6;
        u_char unk7;
        u_char unk8;
        u_char unk9;
        u_char unkA;
        u_char unkB;
        u_char unkC;
        u_char unkD;
        u_char unkE;
        u_char unkF;
        u_char unk10;
        u_char unk11;
        u_short unk12;
        u_short unk14;
        u_short unk16;
        u_short unk18;
        u_short unk1A;
    } unkstruct_1F800214;
    
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value;
    switch (temp_v1) {
        case 0:
            func_8001758C();
            func_80017AE0();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770 = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                func_8002065C();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)func_80018614();
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
            func_8001C618();
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C618);
void func_8001C618(void)
{
    *(s32* )0x1F800164 = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(u16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8001DFD4();
            func_8005A074();
            func_800ECEEC();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        func_80029C48();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        func_8002DB3C();
        if (*(s16* )0x1F8001C6 == 0) {
            func_800EC588();
            func_8003438C();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        func_80017614();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C75C);
void func_8001C75C(void)
{
    typedef inline struct {
        u_char unk0;
        u_char unk1;
        u_char unk2;
        u_char unk3;
        u_char unk4;
        u_char unk5;
        u_char unk6;
        u_char unk7;
        u_char unk8;
        u_char unk9;
        u_char unkA;
        u_char unkB;
        u_char unkC;
        u_char unkD;
        u_char unkE;
        u_char unkF;
        u_char unk10;
        u_char unk11;
        u_short unk12;
        u_short unk14;
        u_short unk16;
        u_short unk18;
        u_short unk1A;
    } unkstruct_1F800214;
    
    u16 temp_v1;
    unkstruct_1F800214* temp_v0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    char pad[2]; // ?? fixes the stack, but there's probably a better way
    
    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->unk4E.value;
    switch (temp_v1) {
        case 0:
            func_8001758C();
            func_80017AE0();
            func_800243E8();
            func_800246B0();
            func_80059F7C();
            func_80028EF4();
            D_800B0770 = 0;
            *(s8* )0x1F8001CF = 1;
            if (GAME.unk7 != 1) {
                func_8002065C();
            }
            temp_v1_2 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_2->unk4E.value++;
            temp_v0 = (unkstruct_1F800214*)func_80018614();
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
            func_8001C940();
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001C940);
void func_8001C940(void)
{
    *(s32* )0x1F800164 = (s32) ((*(s16* )(&SCRATCHPAD+0x1F4) * 0xC000) + &D_800B3188) & 0xFFFFFF;
    func_8001D6C0();
    if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
        (*(s16* )(&SCRATCHPAD+0x1F8))++;
        func_80034524();
        if (*(s16* )(&SCRATCHPAD+0x1C6) == 0) {
            func_8001DFD4();
            func_8005A074();
            func_800EB5B8();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 1) {
        func_80029C48();
    }
    if (*(s16* )(&D_1F8000C0[0]+0x106) == 0) {
        func_8002DA2C();
        func_8002DB3C();
        if (*(s16* )0x1F8001C6 == 0) {
            func_8003438C();
        }
    }
    if (*(s16* )(&SCRATCHPAD+0x1C6) != 2) {
        func_80046264();
    } else {
        func_80017614();
    }
    func_8001F6D4();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", displayLoadingScreen);
void displayLoadingScreen(void)
{
    u_short temp_a1;
    u_short temp_v0;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v1;

    switch (D_8009EB4C) {                           // irregular
        case 0:
            temp_v1 = *(unkstruct_1F8001D4** )0x1F8001D4;
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
            temp_v0_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            *(u_short*)&temp_v0_2->unk64 = ((temp_v0_2->unk64 + 12) & 0xFF);
            drawLoadingSprites(temp_v0_2->unk62, temp_v0_2->unk64);
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001CB54);
s32 func_8001CB54(void)
{
    s32 var_a1;
    s32 var_v0;
    u16 var_v0_2;

    var_a1 = 0;
    switch (GAME.selectedArea) {
        case 7:
            if ((u16)D_8009EBA0 != 6) {
                var_a1 = 1;
            }
            GAME.purifiedAreas |= GAME.selectedArea = 1;
            D_8009EBA0 = 6;
            break;
        case 1:
            if (GAME.purifiedAreas & 1) {
                if (*(u16*)&D_8009EBA0 != 6) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 6;
            } else {
            case 0:
            case 6:
            case 8:
            case 9:
            case 11:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
                if (*(u16*)&D_8009EBA0 != 0) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 0;
            }
            break;
        case 19:
            if (GAME.selectedSection != 2) {
                if (*(u16*)&D_8009EBA0 != 0x11) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 17;
                GAME.selectedArea = 2;
            } else {
                if (*(u16*)&D_8009EBA0 != 0) {
                    var_a1 = 1;
                }
                D_8009EBA0 = 0;
            }
            break;
        case 2:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & 1) && ((u16) GAME.selectedSection < 2U)) {
                D_8009EBA0 = 17;
                GAME.selectedArea = 2;
            }
            break;
        case 3:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if (GAME.purifiedAreas & 2) {
                var_v0 = (u16) GAME.selectedSection < 2U;
                if (var_v0 != 0) {
                    var_v0_2 = GAME.selectedSection + 4;
                    GAME.selectedSection = var_v0_2;
                }
            }
            break;
        case 12:
            if (*(u16*)&D_8009EBA0 != 8) {
                var_a1 = 1;
            }
            GAME.purifiedAreas |= 8, GAME.selectedArea = 4;
            D_8009EBA0 = 8;
            break;
        case 4:
            if (GAME.purifiedAreas & 8) {
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
        case 5:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & 0x10) && ((u16) GAME.selectedSection < 2U)) {
                var_v0_2 = GAME.selectedSection + 2;
                GAME.selectedSection = var_v0_2;
            }
            break;
        case 10:
            if (*(u16*)&D_8009EBA0 != 0) {
                var_a1 = 1;
            }
            D_8009EBA0 = 0;
            if ((GAME.purifiedAreas & 0x40) && (GAME.selectedSection == 3)) {
                GAME.selectedSection = 7;
            }
            if (GAME.purifiedAreas & 0x20) {
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001CE80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001CF7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001CFCC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D29C);
void func_8001D29C(void)
{
    typedef inline struct {
        char data[0x1CF];
        char unk1CF;
        char pad[4];
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1;

    temp_v1 = scratch->unk1D4;
    scratch->unk1CF = 1;
    setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
    setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
    temp_v1->state1 = 3;
    temp_v1->state2 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D2F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D668);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001DE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001DFD4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", setEventState);
u_char setEventState(EVENT event_id, int ap_table, int state)
{
    if (ap_table == 0) {
        setPlayerAP((&AP_TABLE)[(&EVENT_STARTED_AP_TABLE)[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            func_8002E3B0(0);
        }
    } else {
        setPlayerAP((&AP_TABLE)[(&EVENT_COMPLETE_AP_TABLE)[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            func_80020DDC(2);
            func_80021110();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", setEventStarted);
u_char setEventStarted(EVENT event_id, int arg1, int state)
{
    if (GAME.event[event_id] == 0) {
        if (event_id == EVENT_THE100YEAROLDWISEMAN) {
            if (*(u_long*)&GAME.selectedArea == (AREA00_VILLAGEOFALLBEGINNINGS << 16 | AREA00_SECTION00_VILLAGEOFALLBEGINNINGS)) {
                GAME.event[event_id] += 1;
            }
        } else {
            GAME.event[event_id] += 1;
        }
        setPlayerAP((&AP_TABLE)[(&EVENT_STARTED_AP_TABLE)[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            func_8002E3B0(0);
        }        
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", setEventComplete);
u_char setEventComplete(EVENT event_id, int state)
{
    if (GAME.event[event_id] != 0xFF) {
        GAME.event[event_id] = 0xFF;
        setPlayerAP((&AP_TABLE)[(&EVENT_COMPLETE_AP_TABLE)[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            func_80020DDC(2);
            func_80021110();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", getEventState);
u_char getEventState(EVENT event_id)
{
    return GAME.event[event_id];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001EA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", printEventMessage);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001EFE8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F158);
void func_8001F158(short file_id)
{
    if (CdControl(2, (*(&D_80078F80 + (*(&D_8007775C[file_id]) * 1)) * 2) + &D_800791A0, 0) != 0) {
        CdControlF(0x15, 0);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F1C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F4D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F5D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F634);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001F6D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FAE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FCE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FD20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FD80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FDC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FE60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8001FF28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", playSFX);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800200EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", playSFXandSetNote);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002059C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800205C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002065C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002067C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800206A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020778);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020CB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80020FAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800210A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021148);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021180);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800211A4);
void func_800211A4(void)
{
    s32 i;

    if (D_80077FA8 != 0) {
        func_80021310();
    }
    SsInitHot();
    SsSetTableSize(&D_800A15D8, 4, 1);
    SsSetTickMode(SS_TICK60);
    SsSetAutoKeyOffMode(0);
    SpuSetKey(SPU_OFF, 0xFFFFFF);
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
    
    D_8009E638 = 0;
    D_800A32F8 = 0;
    D_8009C9F0 = 0;
    D_8009B078 = 0;
    D_8009B07C = 0;
    D_8009B094 = 0;
    for (i = 0; i < 0x18; ++i) {
        (&D_8009BC28)[i] = 0xF;
        (&D_800A3030)[i] = -1;
    }
    for (i = 0; i < 0x8; ++i) {
        (&D_1F8003B6-7)[i] = -1;
    }
    D_800A2790 = -1;
    D_8009E430 = -1;
    D_80077FA8 = 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021310);
void func_80021310(void)
{
    D_80077FA8 = 0;
    SsEnd();
    SsQuit();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021340);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021B7C);
int func_80021B7C(void)
{
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021B84);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021BC4);
void func_80021BC4(int arg1, int arg2)
{
    func_80021D70((D_8007912C)[arg2]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021BF4);
void func_80021BF4(void)
{
    *(byte* )0x1F8001CE = 0;
    func_80017154(2, &func_80021340);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021C24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80021D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800222B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800223A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800223E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800224B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800224CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800224FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800225B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800225F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022644);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022684);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800226B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800226D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002273C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800227A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002280C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800228A4);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800228C0);
void func_800228C0(u_short* id)
{
    ((u_int*)(id))[0x5] = (int)(((u_int*)(id))[0x5] + (((short*)(id))[0x41] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800228D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022908);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022924);
void func_80022924(short* id)
{
    ((u_int*)(id))[0x5] = (int) (((u_int*)(id))[0x5] + (((short*)(id))[0x3F] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002293C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002296C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_8002299C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800229CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_800229FC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022A18);
void func_80022A18(u_short* id)
{
    ((u_short*)(id))[0x16] = ((u_short*)(id))[0x10];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022A24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp1", func_80022B34);
