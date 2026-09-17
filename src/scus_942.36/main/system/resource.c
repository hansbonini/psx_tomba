#include "common.h"
#include "game.h"

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/system/resource", D_80013798);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B0D4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B214);
s32 func_8003B214(s32 arg0, s16* arg1)
{
    SVECTOR v;
    s32 sxy;
    s32 p;
    s32 flag;
    s32 v2;
    s32 r;

    v.vx = 0;
    v.vy = 0;
    v.vz = 0;
    r = RotTransPers(&v, &sxy, &p, &flag);
    v2 = sxy;
    arg1[0] = v2;
    arg1[1] = v2 >> 16;
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B26C);
void func_8003B26C(s32 arg0)
{
    u8* base = *(u8**)0x1F800354;

    lzDecompress(base + *(s32*)(base + (arg0 << 2)), (byte*)0x801FBE00);
    loadTIM((u_long*)0x801FBE00, 0x20, 0, 0x80, 0x1EF);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B2C8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B410);
s32 func_8003B410(u8* self, s32 idx)
{
    s32 i;
    u16 e;

    if (self[0x88] != 0) {
        return 1;
    }
    if (*(u16*)(self + idx * 2) == 0) {
        return 2;
    }
    self[0x88] = 1;
    e = *(u16*)(self + idx * 2);
    *(u16*)(self + 0x8C) = 0;
    *(u16*)(self + 0x8A) = e - 1;
    for (i = 0x4F; i >= 0; i--) {
        *(s32*)(self + i * 4 + 0x1090) = 0;
    }
    return 0;
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B510);
s32 func_8003B510(u8* src, u8 kind)
{
    unkstruct_8009E458* p = D_8009E458;
    u8  buf[4];
    u8* d;

    if (kind == 0) {
        return *(s32*)((u8*)p + src[0] * 4 + 0x1090);
    }
    d = buf;
    do {
        *d = *src;
        d++;
        src++;
    } while ((s32)d < (s32)&buf[4]);
    return *(s32*)buf;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B574);
void func_8003B574(s32 arg0)
{
    unkstruct_8009E458* p = D_8009E458;

    if (arg0 == 0) {
        *((u8*)p + 0x89) = 0;
    } else if (arg0 >= 0) {
        *((u8*)p + 0x89) = 2;
    } else {
        *((u8*)p + 0x89) = 1;
    }
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B68C);
void func_8003B68C(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8*  q = (u8*)(p->unk8A + (s32)D_8009C974);
    s32* a = (s32*)(q[1] * 4 + (s32)p + 0x1090);
    s32* b = (s32*)(q[2] * 4 + (s32)p + 0x1090);
    s32  x = *b;
    s32  y = *a;

    *a = x;
    *b = y;
    p->unk8A += 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B6E4);
void func_8003B6E4(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* script = D_8009C974;
    s32 idx = script[p->unk8A + 1];

    *(s32*)(idx * 4 + (s32)p + 0x1090) = func_80022570();
    p->unk8A += 2;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B750);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B860);
void func_8003B860(u8 op)
{
    u8* script = D_8009C974;
    unkstruct_8009E458* p = D_8009E458;
    u8  cond;
    u8  buf[2];
    u8* d;
    u8* s;

    switch (op) {
    case 8:
        cond = 1;
        break;
    case 9:
    case 11:
        cond = (*((u8*)p + 0x89) == 0);
        break;
    case 10:
    case 12:
        cond = (*((u8*)p + 0x89) != 0);
        break;
    case 14:
        cond = ((*((u8*)p + 0x89) ^ 2) == 0);
        break;
    case 16:
        cond = ((*((u8*)p + 0x89) ^ 1) != 0);
        break;
    case 13:
        cond = ((*((u8*)p + 0x89) ^ 1) == 0);
        break;
    case 15:
        cond = ((*((u8*)p + 0x89) ^ 2) != 0);
        break;
    }
    if (cond) {
        d = buf;
        s = (u8*)(p->unk8A + (s32)script + 1);
        do {
            *d = *s;
            d++;
            s++;
        } while ((s32)d < (s32)&buf[2]);
        p->unk8A = *(u16*)buf;
    } else {
        p->unk8A += 3;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003B968);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA00);
void func_8003BA00(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* script = D_8009C974;

    s32 v = p->unk8A + 2;

    *(s32*)((u8*)p + *(u16*)((u8*)p + 0x8C) * 4 + 0x90) = v;
    *(u16*)((u8*)p + 0x8C) = *(u16*)((u8*)p + 0x8C) + 1;
    p->unk8A = *(u16*)((u8*)p + script[p->unk8A + 1] * 2) - 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA60);
void func_8003BA60(void)
{
    unkstruct_8009E458* p = D_8009E458;

    *(u16*)((u8*)p + 0x8C) = *(u16*)((u8*)p + 0x8C) - 1;
    p->unk8A = *(u16*)((u8*)p + *(u16*)((u8*)p + 0x8C) * 4 + 0x90);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BA94);
void func_8003BA94(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* q = (u8*)p;
    u8* s = (u8*)p;
    s32 i;
    s32 v;

    for (i = 0; i < 0x40; i++) {
        v = *(s32*)(s + 0x1090);
        *(s32*)(q + *(u16*)(q + 0x8C) * 4 + 0x90) = v;
        *(u16*)(q + 0x8C) = *(u16*)(q + 0x8C) + 1;
        s += 4;
    }
    p->unk8A++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BAF0);
void func_8003BAF0(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* q = (u8*)p;
    s32 i;
    u16 n;

    for (i = 0x3F; i >= 0; i--) {
        n = *(u16*)(q + 0x8C) - 1;
        *(u16*)(q + 0x8C) = n;
        *(s32*)(q + i * 4 + 0x1090) = *(s32*)(q + n * 4 + 0x90);
    }
    p->unk8A++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BB48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BD28);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BF18);
void func_8003BF18(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8 v = D_8009C974[p->unk8A + 1];

    *(s32*)((u8*)p + 0x11D0) = 0;
    *((u8*)p + 0x88) = 2;
    p->unk8A += 2;
    *(s32*)((u8*)p + 0x11D4) = v;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/resource", func_8003BF58);
