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

typedef struct {
    u16 unk0;
    u16 unk2;
} unk_80077720;

extern unk_80077720 D_80077720[];

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", printEventMessage);
void printEventMessage(int event_id, int completed)
{
    int digits[8];
    int ap;
    int n;
    int count;
    int i;
    u8* obj;

    if (completed == 0) {
        ap = AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]];
    } else {
        ap = AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]];
    }
    if (ap == 0) {
        return;
    }

    n = ap;
    digits[0] = n % 10;
    n /= 10;
    digits[1] = n % 10;
    n /= 10;
    digits[2] = n % 10;
    n /= 10;
    digits[3] = n % 10;
    n /= 10;
    digits[4] = n % 10;
    n /= 10;
    digits[5] = n % 10;
    n /= 10;
    digits[6] = n % 10;
    n /= 10;
    digits[7] = n % 10;

    if (ap < 10) {
        count = 1;
    } else if (ap < 100) {
        count = 2;
    } else if (ap < 1000) {
        count = 3;
    } else if (ap < 10000) {
        count = 4;
    } else if (ap < 100000) {
        count = 5;
    } else if (ap < 1000000) {
        count = 6;
    } else if (ap < 10000000) {
        count = 7;
    } else {
        count = 8;
    }

    for (i = 0; i < count; i++) {
        obj = allocObjectLayer3();
        if (obj != NULL) {
            int active = 1;

            obj[2] = 0x22;
            obj[0] = active;
            obj[3] = completed;
            obj[0xC] = digits[i];
            *(s16*)(obj + 8) = 0x7D16;
            *(int*)(obj + 0x10) = (count * 8 + 160 - i * 16) << 16;
            obj[0xD] = 1;
            *(s16*)(obj + 0x2E) = 1;
            obj[0xF] = 0;
            *(int*)(obj + 0x14) = 0x900000;
            *(int*)(obj + 0x18) = 0;
            obj[0x1C] |= 0x80;
            *(u16*)(obj + 0xB4) = D_80077720[completed].unk0;
            *(u16*)(obj + 0xB6) = D_80077720[completed].unk2;
        }
    }
}
