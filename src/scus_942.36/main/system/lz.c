#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D0E4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpKillObject);
void scriptOpKillObject(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8** slot = D_8009E640 + *(s32*)((u8*)p + 0x1190);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpWritePosition);
void scriptOpWritePosition(void)
{
    D_800A53D8[1] = *(s32*)((u8*)D_8009E458 + 0x1190);
    D_800A53AE = *(s32*)((u8*)D_8009E458 + 0x1194);
    D_800A53DC[1] = *(s32*)((u8*)D_8009E458 + 0x1198);
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpReadPosition);
void scriptOpReadPosition(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A53D8[1];
    *(s32*)((u8*)D_8009E458 + 0x1194) = D_800A53AE;
    *(s32*)((u8*)D_8009E458 + 0x1198) = D_800A53DC[1];
    D_8009E458->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D2A8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetObjLayer);
void scriptOpGetObjLayer(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x6A);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetObjPosition);
void scriptOpGetObjPosition(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(s16*)(*(u8**)(obj + 0x40) + 2);
        *(s32*)((u8*)p + 0x1194) = *(s16*)(obj + 0x16);
        *(s32*)((u8*)p + 0x1198) = *(s16*)(*(u8**)(obj + 0x44) + 2);
    }
    p->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D6C0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetObjFrame);
void scriptOpSetObjFrame(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(obj + 0x2E) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetObjFrame);
void scriptOpGetObjFrame(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u16*)(obj + 0x2E);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpCheckObjActive);
void scriptOpCheckObjActive(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = ((obj[4] ^ 2) == 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetObjEnabled);
void scriptOpSetObjEnabled(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x0) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpCallObjHandler);
void scriptOpCallObjHandler(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        func_80022E44(obj);
        *(s32*)((u8*)p + 0x1190) = obj[1];
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpWriteFlag);
void scriptOpWriteFlag(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_8009C10C[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpReadFlag);
void scriptOpReadFlag(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009C10C[*(s32*)((u8*)D_8009E458 + 0x1190)];
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetObjSubtype);
void scriptOpGetObjSubtype(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpReadGlobal);
void scriptOpReadGlobal(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009C20C[*(s32*)((u8*)D_8009E458 + 0x1190)];
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpWriteGlobal);
void scriptOpWriteGlobal(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_8009C20C[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpLoadBackground);
void scriptOpLoadBackground(void)
{
    unkstruct_8009E458* p = D_8009E458;

    if (D_8009C618 != 3) {
        func_800EBD5C(D_800A5398, *(s16*)((u8*)D_800A53D8 + 2), D_800A53AE);
    }
    *(s32*)((u8*)p + 0x1190) = D_800A5400;
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetProgressFlag);
void scriptOpSetProgressFlag(void)
{
    unkstruct_8009E458* p = D_8009E458;

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DB04);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetObjAnim);
void scriptOpSetObjAnim(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetAreaConfig);
void scriptOpSetAreaConfig(void)
{
    unkstruct_8009E458* p = D_8009E458;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b;

    D_800A539C = a;
    b = *(s32*)((u8*)p + 0x1194);
    D_800A539E = 0;
    D_800A539D = b;
    switch ((u8)a) {
    case 1:
        D_8009BCA7 = 0;
        D_800A5398[0] = 1;
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DCF0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetCameraTarget);
void scriptOpSetCameraTarget(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_800A53C6 = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpAwardEvent);
void scriptOpAwardEvent(void)
{
    unkstruct_8009E458* p = D_8009E458;

    EVENT id = *(s32*)((u8*)p + 0x1190);

    if (*(s32*)((u8*)p + 0x1194) != 0) {
        awardEventProgress(id, 1, 0);
    } else {
        awardEventProgress(id, 0, 0);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetDialogId);
void scriptOpSetDialogId(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_8009BCAA = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpPlaySound);
void scriptOpPlaySound(void)
{
    unkstruct_8009E458* p = D_8009E458;

    func_80020180(*(s32*)((u8*)p + 0x1190),
                  *(s32*)((u8*)p + 0x1194),
                  *(s32*)((u8*)p + 0x1198));
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpShowMessage);
void scriptOpShowMessage(void)
{
    unkstruct_8009E458* p = D_8009E458;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), 2);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetAreaStatus);
void scriptOpGetAreaStatus(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A5401;
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetAreaFlag);
void scriptOpGetAreaFlag(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A5436;
    D_8009E458->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E014);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpShowMessage2);
void scriptOpShowMessage2(void)
{
    unkstruct_8009E458* p = D_8009E458;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), 2);
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetFadeEffect);
void scriptOpSetFadeEffect(void)
{
    unkstruct_8009E458* p = D_8009E458;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);

    D_8009BCDD = 0x10;
    D_8009BCA4 = a;
    D_8009BCDE = b;
    asm("");
    p->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E12C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetObjState);
void scriptOpGetObjState(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x69);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetObjState);
void scriptOpSetObjState(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x69) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpSetObjParam);
void scriptOpSetObjParam(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = D_8009E640[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x9C) = *(s32*)((u8*)p + 0x1194);
    }
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpMoveCamera);
void scriptOpMoveCamera(void)
{
    unkstruct_8009E458* temp_s0;

    temp_s0 = D_8009E458;
    func_800EDE44(D_800A5398, *(s16*)&*(s32*)((u8*)temp_s0 + 0x1190), *(s16*)&*(s32*)((u8*)temp_s0 + 0x1194));
    temp_s0->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetAreaId);
void scriptOpGetAreaId(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009C619;
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", scriptOpGetWeather);
void scriptOpGetWeather(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A547A;
    D_8009E458->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E330);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E3C4);
void func_8003E3C4(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009BCD4;
    D_8009E458->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E3E8);
void func_8003E3E8(void)
{
    D_8009E458->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E408);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", lzDecompress);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", lzDecompressToBuffer);
void lzDecompressToBuffer(char* src, char* dst, char* len)
{
    bzero(dst, len);
    lzDecompress(src, dst);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003F124);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", updateObjectsLayer1);
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
