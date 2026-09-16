#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024254);
void func_80024254(void)
{
    u8*  row = (&D_8007C110)[GAME.selectedArea] + D_8009BCCA * 2;
    u16* dst = (u16*)((u8*)&GAME + 0x964 + row[0] * 2);

    *dst |= 1 << row[1];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800242AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800243E8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024624);
void func_80024624(u8* self)
{
    u16* row = (u16*)((&D_8007B680)[GAME.selectedArea] + D_8009BCCA * 8);

    *(u16*)(self + 0x2C) = *row++;
    *(u16*)(self + 0x2E) = *row++;
    *(u16*)(self + 0x30) = *row;
    *(u16*)(self + 0x32) = row[1];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_8002467C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_800246B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024AA8);
void func_80024AA8(s32* src, s32* dst)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024CE4);
void func_80024CE4(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024CEC);
void func_80024CEC(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/camera", func_80024CF4);
void func_80024CF4(void) {
}
