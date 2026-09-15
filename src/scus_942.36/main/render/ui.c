#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024CFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80024EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800251C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800253C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002564C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025810);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025A38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80025E74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002601C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026228);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800263F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80026E48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80027600);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800279E8);
void func_800279E8(u8* arg0, s32 arg1, s32 arg2)
{
    u8* r;

    arg0 += 4;
    r = func_80024EEC(arg2, arg0, arg0 + 4, arg1);
    func_80025C14(r + 0x14, r + 0x18, arg1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80027A30);
void func_80027A30(u8* dst, u8* src, s32 scale)
{
    s32 n;

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x20;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xA) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x28;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x26) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x30) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x34;
            src += 0x40;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x28;
            src += 0x20;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x4) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x6) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x8) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x30;
            src += 0x28;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0xC) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0xE) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x16) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x1E) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            dst += 0x40;
            src += 0x30;
        } while (--n != 0);
    }

    n = *(s32*)src;
    src += 4;
    if (n != 0) {
        do {
            *(s16*)(dst + 0x10) -=
                (*(s16*)(src + 0x0) * scale) >> 12;
            *(s16*)(dst + 0x12) -=
                (*(s16*)(src + 0x2) * scale) >> 12;
            *(s16*)(dst + 0x14) -=
                (*(s16*)(src + 0x4) * scale) >> 12;
            *(s16*)(dst + 0x18) -=
                (*(s16*)(src + 0x8) * scale) >> 12;
            *(s16*)(dst + 0x1A) -=
                (*(s16*)(src + 0xA) * scale) >> 12;
            *(s16*)(dst + 0x1C) -=
                (*(s16*)(src + 0xC) * scale) >> 12;
            *(s16*)(dst + 0x20) -=
                (*(s16*)(src + 0x10) * scale) >> 12;
            *(s16*)(dst + 0x22) -=
                (*(s16*)(src + 0x12) * scale) >> 12;
            *(s16*)(dst + 0x24) -=
                (*(s16*)(src + 0x14) * scale) >> 12;
            *(s16*)(dst + 0x28) -=
                (*(s16*)(src + 0x18) * scale) >> 12;
            *(s16*)(dst + 0x2A) -=
                (*(s16*)(src + 0x1A) * scale) >> 12;
            *(s16*)(dst + 0x2C) -=
                (*(s16*)(src + 0x1C) * scale) >> 12;
            dst += 0x54;
            src += 0x40;
        } while (--n != 0);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", joypadInit);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800287F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_800288C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028A74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028CE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80028EF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_80029008);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/render/ui", D_80010368);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/ui", func_8002907C);
