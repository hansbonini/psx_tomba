#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B214);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B26C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B2C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B410);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B478);
void func_8003B478(u8* self)
{
    s32  i;
    s32* p;

    i = 0x3F;
    p = &D_8009E73C;
    for (; i >= 0; i--) {
        *p = 0;
        p--;
    }
    *(u8*)(self + 0x88) = 0;
    *(s16*)(self + 0x8A) = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B4A0);
u16 func_8003B4A0(u8* src)
{
    u8  buf[2];
    u8* d = buf;

    do {
        *d = *src;
        d++;
        src++;
    } while ((s32)d < (s32)&buf[2]);
    return *(u16*)buf;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B4D8);
s32 func_8003B4D8(u8* src)
{
    u8  buf[4];
    u8* d = buf;

    do {
        *d = *src;
        d++;
        src++;
    } while ((s32)d < (s32)&buf[4]);
    return *(s32*)buf;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B510);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B574);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B5A4);
void func_8003B5A4(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u32 n = *(u32*)((u8*)p + 0x11D0) + 1;

    *(u32*)((u8*)p + 0x11D0) = n;
    if (n >= *(u32*)((u8*)p + 0x11D4)) {
        *((u8*)p + 0x88) = 1;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B5D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B68C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B6E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B750);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B860);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B968);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA00);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA60);
void func_8003BA60(void)
{
    unkstruct_8009E458* p = D_8009E458;

    *(u16*)((u8*)p + 0x8C) = *(u16*)((u8*)p + 0x8C) - 1;
    p->unk8A = *(u16*)((u8*)p + *(u16*)((u8*)p + 0x8C) * 4 + 0x90);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BB48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BF18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BF58);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/system/resource", D_80013798);
