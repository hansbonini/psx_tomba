#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031908);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031B18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031C90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031F00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80031F88);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032230);
void func_80032230(u8* self)
{
    self[0] = 1;
    self[2] = 0x32;
    *(s16*)(self + 0x2E) = 1;
    *(s8*)(self + 0xF) = -0x1E;
    *(s16*)(self + 0x1E) = 0x14;
    self[0xD] = 0x80;
    self[0xB] = 0;
    *(void**)(self + 0x3C) = D_1F8002D8;
    *(s32*)(self + 0x24) = D_80012368[*(s16*)(self + 0xAC)];
    readAnimFrameCount(self);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800322A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800324B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800325C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_800327D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/objsetup", func_80032934);
