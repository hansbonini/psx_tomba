#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_8004339C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", probeCollisionAtDepthA);
s16 probeCollisionAtDepthA(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_8004339C(self, arg1, arg2);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043740);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043AB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043B3C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043D2C);
s16 func_80043D2C(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80043B3C(self, arg1, arg2);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043F14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044050);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800442FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800443CC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", probeCollisionAtDepthB);
s16 probeCollisionAtDepthB(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_800443CC(self, arg1, arg2);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800448D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044B0C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800450FC);
s16 func_800450FC(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80044B0C(self, arg1, arg2, -1);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045174);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800458B0);
