#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003D0E4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpKillObject);
void scriptOpKillObject(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8** slot = SCRIPT_OBJECTS + *(s32*)((u8*)p + 0x1190);
    u8*  obj = *slot;
    u8*  other;

    if (obj != NULL) {
        other = *(u8**)(obj + 0x94);
        obj[4] = 3;
        if (other != NULL) {
            other[4] = 3;
        }
        *slot = NULL;
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerPosition);
void scriptOpSetPlayerPosition(void)
{
    D_800A53D8[1] = *(s32*)((u8*)SCRIPT_CTX + 0x1190);
    D_800A53AE = *(s32*)((u8*)SCRIPT_CTX + 0x1194);
    D_800A53DC[1] = *(s32*)((u8*)SCRIPT_CTX + 0x1198);
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerPosition);
void scriptOpGetPlayerPosition(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_800A53D8[1];
    *(s32*)((u8*)SCRIPT_CTX + 0x1194) = D_800A53AE;
    *(s32*)((u8*)SCRIPT_CTX + 0x1198) = D_800A53DC[1];
    SCRIPT_CTX->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessageBox);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjField6A);
void scriptOpGetObjField6A(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x6A);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjPosition);
void scriptOpGetObjPosition(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(s16*)(*(u8**)(obj + 0x40) + 2);
        *(s32*)((u8*)p + 0x1194) = *(s16*)(obj + 0x16);
        *(s32*)((u8*)p + 0x1198) = *(s16*)(*(u8**)(obj + 0x44) + 2);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjectPosition);
void scriptOpSetObjectPosition(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(*(u8**)(obj + 0x40) + 2) = *(s32*)((u8*)p + 0x1194);
        *(s16*)(obj + 0x16) = *(s32*)((u8*)p + 0x1198);
        *(s16*)(*(u8**)(obj + 0x44) + 2) = *(s32*)((u8*)p + 0x119C);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjFrame);
void scriptOpSetObjFrame(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(obj + 0x2E) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjFrame);
void scriptOpGetObjFrame(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u16*)(obj + 0x2E);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpIsObjInState2);
void scriptOpIsObjInState2(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = ((obj[4] ^ 2) == 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjEnabled);
void scriptOpSetObjEnabled(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x0) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjVisible);
void scriptOpGetObjVisible(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        func_80022E44(obj);
        *(s32*)((u8*)p + 0x1190) = obj[1];
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpWriteFlag);
void scriptOpWriteFlag(void)
{
    ScriptContext* q = SCRIPT_CTX;

    SCRIPT_FLAGS[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpReadFlag);
void scriptOpReadFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = SCRIPT_FLAGS[*(s32*)((u8*)SCRIPT_CTX + 0x1190)];
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjSubtype);
void scriptOpGetObjSubtype(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];
    u8  k;

    if (obj != NULL) {
        k = obj[2] & 0x7F;
        switch (k) {
        case 0x18:
            *(s32*)((u8*)p + 0x1190) = obj[0x68];
            break;
        case 0x19:
            *(s32*)((u8*)p + 0x1190) = obj[0x68];
            break;
        }
    } else {
        *(s32*)((u8*)p + 0x1190) = 0;
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpReadGlobal);
void scriptOpReadGlobal(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = SCRIPT_GLOBALS[*(s32*)((u8*)SCRIPT_CTX + 0x1190)];
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpWriteGlobal);
void scriptOpWriteGlobal(void)
{
    ScriptContext* q = SCRIPT_CTX;

    SCRIPT_GLOBALS[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpLoadBackground);
void scriptOpLoadBackground(void)
{
    ScriptContext* p = SCRIPT_CTX;

    if (D_8009C618 != 3) {
        func_800EBD5C(PLAYER, *(s16*)((u8*)D_800A53D8 + 2), D_800A53AE);
    }
    *(s32*)((u8*)p + 0x1190) = D_800A5400;
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerField6B);
void scriptOpSetPlayerField6B(void)
{
    ScriptContext* p = SCRIPT_CTX;

    if (D_8009C618 != 3) {
        switch (*(s32*)((u8*)p + 0x1190)) {
        case 0:
            D_800A5403 = 0;
            break;
        case 1:
            D_800A5403 = 1;
            break;
        default:
            D_800A5403 = 2;
            break;
        }
    }
    p->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003DB04);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjAnim);
void scriptOpSetObjAnim(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];
    u8  k;
    s32 v;

    if (obj != NULL) {
        k = obj[2] & 0x7F;
        switch (k) {
        case 0x18:
            obj[0xF] = *(s32*)((u8*)p + 0x1194);
            break;
        case 0x19:
        case 0x2E:
            v = *(s32*)((u8*)p + 0x1194);
            obj[0xE] = v;
            switch ((u8)v) {
            case 1:
                *(s8*)(obj + 0xF) = -0xB;
                break;
            case 2:
                *(s8*)(obj + 0xF) = 0x10;
                break;
            }
            break;
        }
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerState);
void scriptOpSetPlayerState(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b;

    D_800A539C = a;
    b = *(s32*)((u8*)p + 0x1194);
    D_800A539E = 0;
    D_800A539D = b;
    switch ((u8)a) {
    case 1:
        D_8009BCA7 = 0;
        PLAYER[0] = 1;
        D_800A5436 = 0;
        break;
    case 4:
        switch ((u8)b) {
        case 2:
            D_800A544A = *(s32*)((u8*)p + 0x11A0);
        case 1:
            D_800A53C6 = *(s32*)((u8*)p + 0x1198);
            D_800A53B8 = *(s32*)((u8*)p + 0x119C);
            break;
        }
        D_8009BCA7 = 1;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003DCF0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetPlayerFacing);
void scriptOpSetPlayerFacing(void)
{
    ScriptContext* q = SCRIPT_CTX;

    D_800A53C6 = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpAwardEvent);
void scriptOpAwardEvent(void)
{
    ScriptContext* p = SCRIPT_CTX;

    EVENT id = *(s32*)((u8*)p + 0x1190);

    if (*(s32*)((u8*)p + 0x1194) != 0) {
        awardEventProgress(id, 1, 0);
    } else {
        awardEventProgress(id, 0, 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetDialogId);
void scriptOpSetDialogId(void)
{
    ScriptContext* q = SCRIPT_CTX;

    D_8009BCAA = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpPlaySound);
void scriptOpPlaySound(void)
{
    ScriptContext* p = SCRIPT_CTX;

    playSFXWithNoteAndVolume(*(s32*)((u8*)p + 0x1190),
                  *(s32*)((u8*)p + 0x1194),
                  *(s32*)((u8*)p + 0x1198));
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessage);
void scriptOpShowMessage(void)
{
    ScriptContext* p = SCRIPT_CTX;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), MSG_TYPE_INFO);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerTouchFlag);
void scriptOpGetPlayerTouchFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_800A5401;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerHitFlag);
void scriptOpGetPlayerHitFlag(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_800A5436;
    SCRIPT_CTX->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E014);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpShowMessage2);
void scriptOpShowMessage2(void)
{
    ScriptContext* p = SCRIPT_CTX;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), MSG_TYPE_INFO);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetFadeEffect);
void scriptOpSetFadeEffect(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);

    D_8009BCDD = 0x10;
    D_8009BCA4 = a;
    D_8009BCDE = b;
    asm("");
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGiveItem);
void scriptOpGiveItem(void)
{
    ScriptContext* p = SCRIPT_CTX;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);
    s32 c = *(s32*)((u8*)p + 0x1198);

    if (a < 0) {
        if (c != 0) {
            printInfoMessage(0x15, 3);
            playSFX(10);
        }
        increaseMaxHealth();
    } else {
        addItemToInventory(a, b, c);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetObjTouchFlag);
void scriptOpGetObjTouchFlag(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x69);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjTouchFlag);
void scriptOpSetObjTouchFlag(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x69) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpSetObjParam);
void scriptOpSetObjParam(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* obj = SCRIPT_OBJECTS[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x9C) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpMoveCamera);
void scriptOpMoveCamera(void)
{
    ScriptContext* temp_s0;

    temp_s0 = SCRIPT_CTX;
    func_800EDE44(PLAYER, *(s16*)&*(s32*)((u8*)temp_s0 + 0x1190), *(s16*)&*(s32*)((u8*)temp_s0 + 0x1194));
    temp_s0->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetAreaId);
void scriptOpGetAreaId(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_8009C619;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", scriptOpGetPlayerFieldE2);
void scriptOpGetPlayerFieldE2(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_800A547A;
    SCRIPT_CTX->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E330);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003E3C4);
void func_8003E3C4(void)
{
    *(s32*)((u8*)SCRIPT_CTX + 0x1190) = D_8009BCD4;
    SCRIPT_CTX->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", opNop);
void opNop(void)
{
    SCRIPT_CTX->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", execGameOpcode);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", lzDecompress);
void lzDecompress(byte *src, byte *dest)
{
    uint length;
    byte offset;
    int next_bitmask;
    src += 4;

    READ32(LZ_FILE_CTRL->size, src);
    READ16(LZ_BITMASK, src);
    LZ_CURRENT_BIT = 0;
    LZ_FILE_CTRL->offset = 0;
     
    do {
        if (((LZ_BITMASK >> LZ_CURRENT_BIT) & 1)) {
            u_char off, len;
            off = *src++;
            len = *src++;
            bcopy(dest - off, dest, len);
            dest += len;
            LZ_FILE_CTRL->offset += len;
        }
        else {
            *dest++ = *src++;
            LZ_FILE_CTRL->offset += 1;
        }
        LZ_CURRENT_BIT++;

        if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else next_bitmask = 0;
        
        if (next_bitmask) {
            READ16(LZ_BITMASK, src);
            LZ_CURRENT_BIT = 0;
        }
    } while (LZ_FILE_CTRL->size > LZ_FILE_CTRL->offset);
    
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", lzDecompressToBuffer);
void lzDecompressToBuffer(char* src, char* dst, char* len)
{
    bzero(dst, len);
    lzDecompress(src, dst);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", func_8003F124);
void func_8003F124(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF5B0();
            return;
        case AREA08_BACCUSLAKE:
            func_800F08C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F1CA8();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800F2D84();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F428C();
            return;
        case AREA18_VILLAGEOFCIVILIZATIONYCROSSING:
            func_800F448C();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F5B4C();
            // fallthrough
        default:
            return;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptop", updateObjectsLayer1);
void updateObjectsLayer1(void)
{
    u8* p = &D_800B07D8;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007D6A4[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xEC;
    } while (D_1F800198 < 0x4);
}
