#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_800459E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045AF8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045BA4);
s32 func_80045BA4(s32* arg0, u8* arg1, s32 arg2, s16 arg3, s32 arg4)
{
    s32 off = (arg2 << 2) + ((s32)arg3 * 4);
    s32  prev;

    if (off < 0) {
        off = 0;
    }
    off += (s32)arg1;
    if ((u32)(off - D_1F8001E0) >= 0xCA0) {
        return 1;
    }
    prev = *(s32*)off;
    *(s32*)off = (s32)arg0;
    *arg0 = prev | arg4;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045C00);
s32 func_80045C00(s32* arg0, u8* arg1, s32 arg2, s16 arg3, s32 arg4)
{
    s32 off = arg3 * 4;
    s32  prev;

    if (off < 0) {
        off = 0;
    }
    off += (s32)arg1;
    if ((u32)(off - D_1F8001E0) >= 0xCA0) {
        return 1;
    }
    prev = *(s32*)off;
    *(s32*)off = (s32)arg0;
    *arg0 = prev | arg4;
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045C54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender1", func_80045D0C);
