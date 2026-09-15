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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023840);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_800238B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023928);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/entity", func_80023A3C);
