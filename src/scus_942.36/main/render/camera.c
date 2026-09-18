#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", setSpawnAreaFlag);
void setSpawnAreaFlag(void)
{
    u8*  row = D_8007C110[GAME.selectedArea] + D_8009BCCA * 2;
    u16* dst = (u16*)((u8*)&GAME + 0x964 + row[0] * 2);

    *dst |= 1 << row[1];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800242AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800243E8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", loadSectionBounds);
void loadSectionBounds(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x2C) = *row++;
    *(u16*)(self + 0x2E) = *row++;
    *(u16*)(self + 0x30) = *row;
    *(u16*)(self + 0x32) = row[1];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", loadSectionHeight);
void loadSectionHeight(u8* self)
{
    u16* row = (u16*)(D_8007B680[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x32) = row[3];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800246B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", copyMatrix32);
void copyMatrix32(s32* src, s32* dst)
{
    s32 a, b, c, d;

    a = src[0];
    b = src[1];
    c = src[2];
    d = src[3];
    dst[0] = a;
    dst[1] = b;
    dst[2] = c;
    dst[3] = d;
    a = src[4];
    b = src[5];
    c = src[6];
    d = src[7];
    dst[4] = a;
    dst[5] = b;
    dst[6] = c;
    dst[7] = d;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", getBaseMatrix);
void getBaseMatrix(MATRIX* dst)
{
    *dst=*(MATRIX*)(&D_1F8000F8);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024BD4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera1);
void stubCamera1(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera2);
void stubCamera2(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", stubCamera3);
void stubCamera3(void) {
}
