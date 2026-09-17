#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022C08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022D3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022F6C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80022FD8);
s32 func_80022FD8(s16 x, s16 y)
{
    if ((u16)(x - D_1F800176 + 0x40) < 0x1C1) {
        return (u16)(D_1F800186 - y + 0x40) < 0x171;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800230BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023168);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_8002331C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_8002337C);
void func_8002337C(u8* self)
{
    if ((*(u16*)0x1F8001C8 & 1) == 0) {
        *(u8**)(self + 0x40) = self + 0x10;
        *(u8**)(self + 0x44) = self + 0x18;
    } else {
        *(u8**)(self + 0x44) = self + 0x10;
        *(u8**)(self + 0x40) = self + 0x18;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800233B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_8002367C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800236F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023794);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023840);
void func_80023840(s32 n, u32* arr)
{
    s32 i;
    s32 j;
    u32 key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800238B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023928);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023A3C);
void func_80023A3C(void)
{
    s32 i = (s16)D_8009E744 * 4;

    D_1F8003C4 = D_8007B2C4[i];
    D_1F8003C6 = D_8007B2C6[i];
    D_1F8003C8 = D_8007B2C8[i];
    D_1F8003CA = D_8007B2CA[i];
}
