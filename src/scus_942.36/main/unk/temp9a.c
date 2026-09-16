#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_8003473C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_8003481C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800348FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800349DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80034AB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80034C14);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036440);
void func_80036440(u8* self)
{
    switch (self[5]) {
    case 0:
        func_80034C14(self);
        break;
    case 1:
        func_80034C14(self);
        break;
    case 2:
        func_80034C14(self);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036494);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800365DC);
void func_800365DC(u8* self)
{
    if (self[6] == 0) {
        *(s16*)(self + 0x22) = 0;
        func_800384F0(self, D_8009C61A - 5);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800369BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036A28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036A8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036C88);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036DB0);
s16 func_80036DB0(void)
{
    s16 r = 0;

    switch (D_800A539D) {
    case 5:
    case 6:
    case 7:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 21:
    case 22:
    case 23:
    case 27:
    case 29:
    case 30:
    case 32:
    case 33:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 46:
    case 47:
    case 48:
    case 51:
    case 52:
    case 53:
    case 54:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 69:
        r++;
    }
    return r;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036DF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80036F98);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_80038358);
void func_80038358(u8* self)
{
    switch (self[5]) {
    case 0:
        func_80036F98(self);
        break;
    case 1:
        func_80036F98(self);
        break;
    case 2:
        func_80036F98(self);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800383AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp9a", func_800384F0);
