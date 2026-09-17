#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D0E4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D1B0);
void func_8003D1B0(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8** slot = &D_8009E640 + *(s32*)((u8*)p + 0x1190);
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
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D20C);
void func_8003D20C(void)
{
    D_800A53D8[1] = *(s32*)((u8*)D_8009E458 + 0x1190);
    D_800A53AE = *(s32*)((u8*)D_8009E458 + 0x1194);
    D_800A53DC[1] = *(s32*)((u8*)D_8009E458 + 0x1198);
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D25C);
void func_8003D25C(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A53D8[1];
    *(s32*)((u8*)D_8009E458 + 0x1194) = D_800A53AE;
    *(s32*)((u8*)D_8009E458 + 0x1198) = D_800A53DC[1];
    D_8009E458->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D2A8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D5F8);
void func_8003D5F8(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x6A);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D648);
void func_8003D648(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(s16*)(*(u8**)(obj + 0x40) + 2);
        *(s32*)((u8*)p + 0x1194) = *(s16*)(obj + 0x16);
        *(s32*)((u8*)p + 0x1198) = *(s16*)(*(u8**)(obj + 0x44) + 2);
    }
    p->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D6C0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D72C);
void func_8003D72C(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s16*)(obj + 0x2E) = *(s32*)((u8*)p + 0x1194);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D77C);
void func_8003D77C(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u16*)(obj + 0x2E);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D7CC);
void func_8003D7CC(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = ((obj[4] ^ 2) == 0);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D824);
void func_8003D824(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x0) = *(s32*)((u8*)p + 0x1194);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D874);
void func_8003D874(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        func_80022E44(obj);
        *(s32*)((u8*)p + 0x1190) = obj[1];
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D8EC);
void func_8003D8EC(void)
{
    unkstruct_8009E458* q = D_8009E458;

    (&D_8009C10C)[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D920);
void func_8003D920(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = (&D_8009C10C)[*(s32*)((u8*)D_8009E458 + 0x1190)];
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D950);
void func_8003D950(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];
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
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D9C4);
void func_8003D9C4(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = (&D_8009C20C)[*(s32*)((u8*)D_8009E458 + 0x1190)];
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003D9F4);
void func_8003D9F4(void)
{
    unkstruct_8009E458* q = D_8009E458;

    (&D_8009C20C)[*(s32*)((u8*)q + 0x1190)] = *(s32*)((u8*)q + 0x1194);
    q->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DA28);
void func_8003DA28(void)
{
    unkstruct_8009E458* p = D_8009E458;

    if (D_8009C618 != 3) {
        func_800EBD5C(&D_800A5398, *(s16*)((u8*)D_800A53D8 + 2), D_800A53AE);
    }
    *(s32*)((u8*)p + 0x1190) = D_800A5400;
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DA9C);
void func_8003DA9C(void)
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
    p->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DB04);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DB70);
void func_8003DB70(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];
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
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DC38);
void func_8003DC38(void)
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
        D_800A5398 = 1;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DE90);
void func_8003DE90(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_800A53C6 = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DEBC);
void func_8003DEBC(void)
{
    unkstruct_8009E458* p = D_8009E458;

    s32 id = *(s32*)((u8*)p + 0x1190);

    if (*(s32*)((u8*)p + 0x1194) != 0) {
        awardEventProgress(id, 1, 0);
    } else {
        awardEventProgress(id, 0, 0);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DF10);
void func_8003DF10(void)
{
    unkstruct_8009E458* q = D_8009E458;

    D_8009BCAA = *(s32*)((u8*)q + 0x1190);
    asm("");
    q->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DF3C);
void func_8003DF3C(void)
{
    unkstruct_8009E458* p = D_8009E458;

    func_80020180(*(s32*)((u8*)p + 0x1190),
                  *(s32*)((u8*)p + 0x1194),
                  *(s32*)((u8*)p + 0x1198));
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DF88);
void func_8003DF88(void)
{
    unkstruct_8009E458* p = D_8009E458;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), 2);
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DFCC);
void func_8003DFCC(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A5401;
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003DFF0);
void func_8003DFF0(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A5436;
    D_8009E458->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E014);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E0A4);
void func_8003E0A4(void)
{
    unkstruct_8009E458* p = D_8009E458;

    printInfoMessage(*(s32*)((u8*)p + 0x1190), 2);
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E0E8);
void func_8003E0E8(void)
{
    unkstruct_8009E458* p = D_8009E458;
    s32 a = *(s32*)((u8*)p + 0x1190);
    s32 b = *(s32*)((u8*)p + 0x1194);

    D_8009BCDD = 0x10;
    D_8009BCA4 = a;
    D_8009BCDE = b;
    asm("");
    p->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E12C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E1A8);
void func_8003E1A8(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(s32*)((u8*)p + 0x1190) = *(u8*)(obj + 0x69);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E1F8);
void func_8003E1F8(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x69) = *(s32*)((u8*)p + 0x1194);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E248);
void func_8003E248(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* obj = (&D_8009E640)[*(s32*)((u8*)p + 0x1190)];

    if (obj != NULL) {
        *(u8*)(obj + 0x9C) = *(s32*)((u8*)p + 0x1194);
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E298);
void func_8003E298(void)
{
    unkstruct_8009E458* temp_s0;

    temp_s0 = D_8009E458;
    func_800EDE44(&D_800A5398, temp_s0->unk1190, temp_s0->unk1194);
    temp_s0->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E2E8);
void func_8003E2E8(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009C619;
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E30C);
void func_8003E30C(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_800A547A;
    D_8009E458->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E330);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E3C4);
void func_8003E3C4(void)
{
    *(s32*)((u8*)D_8009E458 + 0x1190) = D_8009BCD4;
    D_8009E458->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003E3E8);
void func_8003E3E8(void)
{
    D_8009E458->unk8A++;
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/lz", func_8003F1D4);
