#include "common.h"
#include "game.h"

typedef struct {
    u16 unk0;
    u16 unk2;
} unk_80077720;

u8 D_80077428[0xC8] = {
    0x02, 0x03, 0x04, 0x06, 0x08, 0x09, 0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x48, 0x0E, 0x0F, 0x13, 0x14,
    0x15, 0x16, 0xFF, 0x1C, 0x1E, 0x1F, 0x20, 0x22, 0x27, 0x28, 0x1A, 0x2F, 0x30, 0x31, 0x32, 0x33,
    0x34, 0x35, 0x37, 0x38, 0x39, 0x3D, 0x3E, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0xFF, 0x46, 0x47,
    0xFF, 0x49, 0x4A, 0x4B, 0xFF, 0x4C, 0x4F, 0x50, 0x51, 0x52, 0x53, 0xFF, 0xFF, 0xFF, 0x59, 0x56,
    0x58, 0x5B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5C, 0xFF, 0xFF, 0xFF, 0x5F, 0x57, 0x62,
    0x19, 0x71, 0x81, 0xFF, 0xFF, 0x55, 0x23, 0x24, 0x26, 0xFF, 0x6C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5D, 0x64, 0x63, 0x5E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4D,
    0x69, 0x25, 0x73, 0x2C, 0x68, 0xFF, 0x60, 0x6B, 0x72, 0x75, 0xFF, 0x65, 0x66, 0x79, 0x67, 0x6E,
    0x7B, 0x80, 0xFF, 0xFF, 0x74, 0x76, 0x77, 0x78, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x7C, 0x7A, 0x7D, 0xFF, 0xFF, 0xFF, 0x61, 0x82, 0xFF, 0x6A, 0xFF, 0xFF, 0x6D, 0x84, 0xFF, 0x83,
    0x85, 0x7F, 0xFF, 0xFF, 0x86, 0xFF, 0x05, 0x07, 0x18, 0x1B, 0x3A, 0x3F, 0x36, 0x3B, 0x4E, 0x2D,
    0x2E, 0x10, 0x11, 0x12, 0x17, 0x21, 0x1D, 0x54, 0xFF, 0x3C, 0xFF, 0x29, 0x2A, 0x2B, 0x6F, 0x70,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

s16 D_800774F0[4] = { 0, 0xB4, 0, 0 };

u16 D_800774F8[8] = { 0, 1, 2, 3, 4, 5, 6, 0 };

unk_80077720 D_80077508[6] = {
    { 0xFFD8, 0 },
    { 0xFFEC, 0 },
    { 0, 0 },
    { 20, 0 },
    { 40, 0 },
    { 60, 0 }
};

int AP_TABLE[8] = { 0, 500, 1000, 2000, 5000, 10000, 20000, 50000 };

u_char EVENT_STARTED_AP_TABLE[0xC8] = {
    0, 0, 1, 2, 0, 2, 0, 2, 1, 1, 0, 1, 0, 0, 1, 4, 2, 1, 0, 2,
    3, 3, 2, 3, 3, 2, 0, 2, 2, 0, 0, 2, 2, 2, 0, 1, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 0, 1, 2, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 0,
    0, 0, 2, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1,
    0, 2, 3, 2, 0, 0, 2, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 2, 1, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 1, 2,
    2, 2, 0, 0, 0, 1, 1, 2, 1, 2, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 2, 2, 0, 1, 0, 0, 0, 1, 0, 0,
    0, 2, 0, 0, 2, 0, 2, 3, 0, 5, 2, 2, 0, 2, 0, 1, 1, 3, 2, 2,
    1, 2, 2, 1, 0, 1, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0
};

u_char EVENT_COMPLETE_AP_TABLE[0xC8] = {
    0, 2, 2, 3, 1, 4, 0, 5, 2, 2, 1, 2, 3, 3, 3, 3, 2, 4, 0, 3,
    4, 3, 2, 4, 4, 3, 2, 4, 1, 2, 6, 3, 3, 3, 2, 4, 3, 3, 3, 4,
    4, 2, 2, 3, 2, 0, 2, 5, 0, 2, 2, 3, 0, 2, 6, 3, 3, 3, 5, 0,
    0, 0, 2, 5, 3, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 2, 1, 2, 3,
    6, 4, 3, 3, 0, 6, 2, 2, 2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 0, 6, 3, 4, 3, 2, 3, 0, 2, 3,
    3, 3, 0, 2, 6, 2, 3, 5, 3, 5, 0, 0, 3, 2, 3, 4, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 2, 2, 0, 0, 0, 0, 4, 3, 3, 0, 0, 2, 5, 0, 1,
    7, 3, 0, 0, 5, 0, 3, 2, 1, 3, 2, 3, 3, 0, 2, 2, 2, 5, 5, 2,
    4, 3, 2, 2, 0, 2, 0, 2, 2, 3, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0
};

u8* D_800776D0[20] = {
    D_80077428, D_80077428, D_80077428, D_80077428, D_80077428,
    D_80077428, D_80077428, D_80077428, D_80077428, D_80077428,
    D_80077428, D_80077428, D_80077428, D_80077428, D_80077428,
    D_80077428, D_80077428, D_80077428, D_80077428, D_80077428
};

unk_80077720 D_80077720[2] = {
    { 0x5A, 0xB4 },
    { 0x96, 0x5A }
};

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", awardEventProgress);
u_char awardEventProgress(EVENT event_id, int ap_table, int state)
{
    if (ap_table == 0) {
        addPlayerAP(AP_TABLE[EVENT_STARTED_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 0, 0x3C, state);
            printEventMessage(event_id, 0);
            playSFX(42);
            spawnItemPickupObject(0);
        }
    } else {
        addPlayerAP(AP_TABLE[EVENT_COMPLETE_AP_TABLE[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            spawnEventTitle(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            playJingle(2);
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
            spawnEventTitle(event_id, 0, 0x3C, state);
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
            spawnEventTitle(event_id, 1, 1, state);
            printEventMessage(event_id, 1);
            playJingle(2);
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

extern u16 D_800A53AA;
extern u16 D_800A38C2;
extern u8 D_8009BC9B;
extern u8 D_8009BCA6;
extern u8 D_8009BCA8;
extern s8** D_80139330;
extern s8** D_8013CC1C;
extern s8** D_800F077C;
extern s8** D_80137998;
extern s8** D_80132CAC;
extern s8** D_80119334;
extern s8** D_80121BE0;
extern s8** D_80118018;
extern s8** D_801177F8;
extern s8** D_8012CB9C;
extern s8** D_80130DD8;
extern s8** D_8011B4C8;
extern s8** D_80118C38;
extern s8** D_80119B44;
extern s8** D_80128018;
extern s8** D_8011A5CC;
extern s8** D_8011B2A8;
extern s8** D_8011BDC0;
extern s8** D_800F00BC;
extern s8** D_8011E3A0;
extern s8** D_80102000;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", spawnEventTitle);
int spawnEventTitle(int event_id, int completed, int duration, int state)
{
    s16 x;
    s16 y;
    u8* src;
    u8 idx;
    s8** tbl;
    s8* p;
    u8* obj;
    int i;
    int done;
    int once;
    int n;
    u16* q;
    int temp;
    int* hdr;

    if (event_id == 1) {
        duration = 1;
        x = D_800A53AA - D_800A38C2;
        y = (u16)D_800A53AE - *(u16*)0x1F8000F2;
    }
    src = *(u8**)0x1F80039C;
    src += *(u16*)(src + 8);
    idx = D_800776D0[GAME.selectedArea][event_id];
    if (idx == 0xFF) {
        q = (u16*)(src + 2);
    } else {
        q = (u16*)(src + idx * 2);
    }
    src += *q;
    i = 0;
    switch (GAME.selectedArea) {
    case 0:
        tbl = D_80139330;
        break;
    case 1:
        tbl = D_8013CC1C;
        break;
    case 2:
        switch (D_8009BCCA) {
        case 0:
            tbl = D_800F00BC;
            break;
        case 1:
        case 2:
        case 4:
        case 5:
            tbl = D_8011E3A0;
            break;
        case 3:
            tbl = D_800F077C;
            break;
        }
        break;
    case 3:
        tbl = D_80137998;
        break;
    case 4:
        tbl = D_80132CAC;
        break;
    case 5:
        switch (D_8009BCCA) {
        case 0:
        case 2:
            tbl = D_80102000;
            break;
        case 1:
        case 3:
            tbl = D_80119334;
            break;
        }
        break;
    case 6:
        tbl = D_80121BE0;
        break;
    case 7:
        tbl = D_80118018;
        break;
    case 8:
        switch (D_8009BCCA) {
        case 0:
        case 2:
            tbl = D_80102000;
            break;
        case 1:
        case 3:
            tbl = D_801177F8;
            break;
        }
        break;
    case 9:
        tbl = D_8012CB9C;
        break;
    case 10:
        tbl = D_80130DD8;
        break;
    case 11:
        tbl = D_8011B4C8;
        break;
    case 12:
        tbl = D_80118C38;
        break;
    case 13:
        tbl = D_80119B44;
        break;
    case 14:
        tbl = D_80128018;
        break;
    case 16:
        tbl = D_8011A5CC;
        break;
    case 17:
        tbl = D_8011B2A8;
        break;
    case 18:
        tbl = D_8011BDC0;
        break;
    case 19:
        switch (D_8009BCCA) {
        case 0:
            tbl = D_800F00BC;
            break;
        case 1:
            tbl = D_8011E3A0;
            break;
        case 2:
            tbl = D_80102000;
            break;
        }
        break;
    }
    done = 0;
    p = tbl[event_id];
    D_8009BC9B = 1;
    once = 0;
    for (; p[0] != -1; p += 4) {
        obj = (u8*)allocObjectLayer8();
        if (obj != NULL) {
            obj[0] = 1;
            obj[2] = 1;
            obj[0xD] = 1;
            *(s16*)(obj + 8) = 0x7D16;
            obj[3] = completed;
            *(s16*)(obj + 0x1E) = 0;
            *(s8*)(obj + 0xF) = -0x5A;
            *(s16*)(obj + 0x2E) = 1;
            temp = obj[0x1C] | 0x80;
            obj[0x1C] = temp;
            *(s16*)(obj + 0x20) = duration;
            temp = (int)(&SCRATCHPAD + 0x33C);
            hdr = *(int* volatile*)temp;
            temp = (int)*(int* volatile*)temp;
            temp += hdr[1];
            *(int*)(obj + 0xA0) = temp;
            if (event_id == 1) {
                *(int*)(obj + 0x10) = (x - 0xA0) << 16;
                *(int*)(obj + 0x14) = y << 16;
                *(int*)(obj + 0x18) = (((s16*)PLAYER)[0xD] + 10) << 16;
                *(int*)(obj + 0x30) = (x - 0xA0) << 16;
                *(int*)(obj + 0x34) = y << 16;
                *(int*)(obj + 0x38) = (((s16*)PLAYER)[0xD] + 10) << 16;
            } else {
                *(int*)(obj + 0x10) = D_800774F0[1] << 16;
                *(int*)(obj + 0x14) = D_800774F0[2] << 16;
                *(int*)(obj + 0x18) = 0;
                *(int*)(obj + 0x30) = D_800774F0[1] << 16;
                *(int*)(obj + 0x34) = D_800774F0[2] << 16;
                *(int*)(obj + 0x38) = 0;
            }
            obj[0xC] = i;
            n = p[3] & 0xF;
            *(u16*)(obj + 0xBC) = *(u16*)src & 0xFFF;
            *(u16*)(obj + 0xC0) = D_800774F8[n];
            *(s16*)(obj + 0xC4) = p[1] * 10;
            *(s16*)(obj + 0xC6) = p[2] * 14;
            *(u16*)(obj + 0xC8) = D_80077508[n].unk0;
            *(u16*)(obj + 0xCA) = D_80077508[n].unk2;
            *(u16*)(obj + 0xCC) = (u8)p[3];
            *(u16*)(obj + 0xCE) = 0;
            i++;
            src += 2;
            if (D_8009C618 != 3 && done == 0) {
                if (state != 0) {
                    *(u16*)(obj + 0xD0) = D_8009BC98[0xF];
                    D_8009BC98[0xF] = 1;
                    D_8009BCAA = 1;
                    if (state != 4 && (PLAYER[0x9E] == 0 || PLAYER[0xAC] < 2)) {
                        PLAYER[4] = 5;
                        PLAYER[5] = 0;
                        PLAYER[6] = 0;
                        PLAYER[7] = 0;
                    } else if (D_8009BCA8 == 0) {
                        D_8009BCA6 = 1;
                    }
                    *(u16*)(obj + 0xCE) = state;
                }
                *(u16*)(obj + 0xCE) |= 0x8000;
                done = 1;
            }
            if (event_id == 0xF && completed == 1 && once == 0) {
                once = 1;
                *(u16*)(obj + 0xD2) = 0x27;
                *(u16*)(obj + 0xCE) = 0x8002;
            } else {
                *(u16*)(obj + 0xD2) = 0;
            }
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/event", acquireSpriteSlot);
short acquireSpriteSlot(int id)
{
    RECT rect;
    int i;
    int freeSlot;
    int j;
    int k;
    short slot;
    u16* src;
    u16* dst;
    u16 w;
    u16 h;
    u16 a;
    u16 b;
    DR_LOAD* load;

    freeSlot = -1;
    for (i = 0; i < 0x30; i++) {
        if (SPRITE_SLOTS[i].id == id) {
            SPRITE_SLOTS[i].refCount++;
            return i;
        }
        if (SPRITE_SLOTS[i].id == -1) {
            freeSlot = i;
        }
    }

    slot = freeSlot;
    if (slot == -1) {
        return -1;
    }

    SPRITE_SLOTS[slot].refCount = 1;
    src = ((scratchpad*)PSX_SCRATCH)->unk39C;
    dst = (u16*)(id * 2 + (int)src);
    src = (u16*)((u8*)src + dst[0x48]);
    w = *src++;
    h = *src++;
    a = *src++;
    b = *src++;
    SPRITE_SLOTS[slot].id = id;
    SPRITE_SLOTS[slot].val[4] = 0;
    SPRITE_SLOTS[slot].val[2] = a;
    SPRITE_SLOTS[slot].val[3] = h;
    SPRITE_SLOTS[slot].val[5] = b;
    for (k = 0; k < 4; k++) {
        load = (DR_LOAD*)D_1F800164;
        setRECT(&rect, SPRITE_SLOTS[slot].val[0], SPRITE_SLOTS[slot].val[1] + k * (h >> 2), w, h >> 2);
        SetDrawLoad(load, &rect);
        dst = (u16*)load->p;
        for (j = 0; j < w * (u16)(h >> 2); j++) {
            *dst++ = *src++;
        }
        addPrim(D_1F8001E0 + 4, load);
        D_1F800164 += sizeof(DR_LOAD);
    }
    return freeSlot;
}

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
