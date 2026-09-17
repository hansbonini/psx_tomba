#include "common.h"
#include "game.h"


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", awardEventProgress);
u_char awardEventProgress(EVENT event_id, int ap_table, int state)
{
    if (ap_table == 0) {
        addPlayerAP(AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            spawnItemPickupObject(0);
        }
    } else {
        addPlayerAP(AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            func_80020DDC(2);
            muteBgm();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", setEventStarted);
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
        addPlayerAP(AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            spawnItemPickupObject(0);
        }        
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", setEventComplete);
u_char setEventComplete(EVENT event_id, int state)
{
    if (GAME.event[event_id] != 0xFF) {
        GAME.event[event_id] = 0xFF;
        addPlayerAP(AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            func_80020DDC(2);
            muteBgm();
        }
    }
    return GAME.event[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", getEventState);
u_char getEventState(EVENT event_id)
{
    return GAME.event[event_id];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", func_8001E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", func_8001EA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", printEventMessage);
