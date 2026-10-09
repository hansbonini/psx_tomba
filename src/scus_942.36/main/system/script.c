#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", uploadSpriteFrame);
typedef struct { char p0[2]; u8 type; char p3[0x24 - 3]; u16 *anim; } O_3B0D4;
extern s32 WPP_DATA;
extern char *D_8009B698;
extern void unpackSpriteFrame(s32, s32, char *, s32);

void uploadSpriteFrame(O_3B0D4 *o)
{
    RECT r;
    switch (o->type) {
    case 0:
        unpackSpriteFrame(WPP_DATA, *o->anim, (char *)0x801fb000, 0);
        r.y = 2;
        r.w = 0x10;
        r.h = 0x50;
        r.x = (*(u16 *)&D_1F8001F4) << 4;
        ClearImage(&r, 0, 0, 0);
        break;
    case 1:
    case 2:
    case 3:
        unpackSpriteFrame(D_1F800350, *o->anim, (char *)0x801fb000, 0);
        r.y = 2;
        r.w = 0xe;
        r.h = 0x3a;
        r.x = (*(u16 *)&D_1F8001F4) << 4;
        ClearImage(&r, 0, 0, 0);
        break;
    }
    loadTIM((char *)0x801fb000, (*(u16 *)&D_1F8001F4) * 16 + 1, 4, 0x80, 0x1e0);
    *(u16 *)(D_8009B698 + D_1F8001F4 * 2 + 0x28) = *o->anim;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", projectOriginToScreen);
s32 projectOriginToScreen(s32 arg0, s16* arg1)
{
    SVECTOR v;
    long sxy;
    long p;
    long flag;
    long v2;
    long r;

    v.vx = 0;
    v.vy = 0;
    v.vz = 0;
    r = RotTransPers(&v, &sxy, &p, &flag);
    v2 = sxy;
    arg1[0] = v2;
    arg1[1] = v2 >> 16;
    return r;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", loadCompressedTIM);
void loadCompressedTIM(s32 arg0)
{
    u8* base = *(u8**)0x1F800354;

    lzDecompress(base + *(s32*)(base + (arg0 << 2)), (byte*)TIM_SCRATCH);
    loadTIM(TIM_SCRATCH, 0x20, 0, 0x80, 0x1EF);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003B2C8);
typedef struct H_3B2C8 { s16 m[2]; s16 x[2]; s16 d[64]; } H_3B2C8;
typedef struct D_3B2C8 { s16 d[64]; char *base; char *cur; u8 f; } D_3B2C8;

s32 func_8003B2C8(char *p, D_3B2C8 *o)
{
    H_3B2C8 h;
    s32 i;
    h = *(H_3B2C8 *)p;
    if (*(s32 *)&h != 0x530057) {
        printf("Not Script File");
        D_8009CA04 = 0;
        return -2;
    }
    for (i = 0; i < 64; i++)
        o->d[i] = h.d[i];
    o->base = p;
    o->cur = p + 0x88;
    o->f = 0;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptStart);
s32 scriptStart(u8* self, s32 idx)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptReset);
void scriptReset(u8* self)
{
    s32 i;

    for (i = 0x3F; i >= 0; i--) {
        SCRIPT_OBJECTS[i] = NULL;
    }
    *(u8*)(self + 0x88) = 0;
    *(s16*)(self + 0x8A) = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", readUnalignedU16);
u16 readUnalignedU16(u8* src)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", readUnalignedS32);
s32 readUnalignedS32(u8* src)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptReadOperand);
s32 scriptReadOperand(u8* src, u8 kind)
{
    ScriptContext* p = SCRIPT_CTX;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptSetCompareFlag);
void scriptSetCompareFlag(s32 arg0)
{
    ScriptContext* p = SCRIPT_CTX;

    if (arg0 == 0) {
        p->cmpFlag = 0;
    } else if (arg0 >= 0) {
        p->cmpFlag = 2;
    } else {
        p->cmpFlag = 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptTickWait);
void scriptTickWait(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u32 n = *(u32*)((u8*)p + 0x11D0) + 1;

    *(u32*)((u8*)p + 0x11D0) = n;
    if (n >= *(u32*)((u8*)p + 0x11D4)) {
        p->state = 1;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003B5D8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpSwapVars);
void scriptOpSwapVars(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8*  q = (u8*)(p->pc + (s32)SCRIPT_CODE);
    s32* a = (s32*)(q[1] * 4 + (s32)p + 0x1090);
    s32* b = (s32*)(q[2] * 4 + (s32)p + 0x1090);
    s32  x = *b;
    s32  y = *a;

    *a = x;
    *b = y;
    p->pc += 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpRandom);
void scriptOpRandom(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* script = SCRIPT_CODE;
    s32 idx = script[p->pc + 1];

    *(s32*)(idx * 4 + (s32)p + 0x1090) = nextRandom();
    p->pc += 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003B750);
static __inline__ s32 rd_3B750(u8 *g, u8 c, u8 *t)
{
    s32 tmp;
    s32 k;
    if (c == 0)
        return *(s32 *)(g + *t * 4 + 0x1090);
    for (k = 0; k < 4; k++)
        ((char *)&tmp)[k] = *t++;
    return tmp;
}

void func_8003B750(void)
{
    s32 buf[16];
    u8 *o;
    u8 *code;
    s32 *q;
    s32 pc;
    s32 i, n;
    u8 c;
    u8 *s;
    pc = 2;
    o = SCRIPT_CTX;
    code = SCRIPT_CODE;
    n = code[*(u16 *)(o + 0x8a) + 1];
    q = buf;
    for (i = 0; i < n; i++) {
        s = code + (*(u16 *)(o + 0x8a) + pc);
        c = *s++;
        buf[i] = rd_3B750(SCRIPT_CTX, c, s);
        if (c == 0)
            pc += 2;
        else
            pc += 5;
    }
    for (i = 0; i < n; i++)
        *(s32 *)(o + 0x1190 + i * 4) = q[i];
    *(u16 *)(o + 0x8a) += pc;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpBranch);
void scriptOpBranch(u8 op)
{
    u8* script = SCRIPT_CODE;
    ScriptContext* p = SCRIPT_CTX;
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
        cond = (p->cmpFlag == 0);
        break;
    case 10:
    case 12:
        cond = (p->cmpFlag != 0);
        break;
    case 14:
        cond = ((p->cmpFlag ^ 2) == 0);
        break;
    case 16:
        cond = ((p->cmpFlag ^ 1) != 0);
        break;
    case 13:
        cond = ((p->cmpFlag ^ 1) == 0);
        break;
    case 15:
        cond = ((p->cmpFlag ^ 2) != 0);
        break;
    }
    if (cond) {
        d = buf;
        s = (u8*)(p->pc + (s32)script + 1);
        do {
            *d = *s;
            d++;
            s++;
        } while ((s32)d < (s32)&buf[2]);
        p->pc = *(u16*)buf;
    } else {
        p->pc += 3;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003B968);
typedef struct {
    char pad[0x8a];
    u16 w8a;
    char pad2[0x1090 - 0x8c];
    s32 cnt[64];
} S8003A570_3B968;

void func_8003B968(void)
{
    S8003A570_3B968 *p = SCRIPT_CTX;
    u8 *code = SCRIPT_CODE;
    u16 tmp;
    s32 i;
    u8 *s;
    if (--p->cnt[code[p->w8a + 1]] > 0) {
        s = (u8 *)(p->w8a + (s32)code) + 2;
        for (i = 0; i < 2; i++) {
            ((u8 *)&tmp)[i] = *s++;
        }
        p->w8a = tmp;
    } else {
        p->w8a += 4;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpCall);
void scriptOpCall(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* script = SCRIPT_CODE;

    s32 v = p->pc + 2;

    *(s32*)((u8*)p + p->sp * 4 + 0x90) = v;
    p->sp = p->sp + 1;
    p->pc = *(u16*)((u8*)p + script[p->pc + 1] * 2) - 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpReturn);
void scriptOpReturn(void)
{
    ScriptContext* p = SCRIPT_CTX;

    p->sp = p->sp - 1;
    p->pc = *(u16*)((u8*)p + p->sp * 4 + 0x90);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpPushVars);
void scriptOpPushVars(void)
{
    ScriptContext* p = SCRIPT_CTX;
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
    p->pc++;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpPopVars);
void scriptOpPopVars(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* q = (u8*)p;
    s32 i;
    u16 n;

    for (i = 0x3F; i >= 0; i--) {
        n = *(u16*)(q + 0x8C) - 1;
        *(u16*)(q + 0x8C) = n;
        *(s32*)(q + i * 4 + 0x1090) = *(s32*)(q + n * 4 + 0x90);
    }
    p->pc++;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003BB48);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003BC34);
void func_8003BC34(u8 op)
{
    u8 *b = SCRIPT_CTX;
    u8 *code = SCRIPT_CODE;
    u8 idx = code[*(u16 *)(b + 0x8a) + 1];
    u8 *q;
    s32 v;

    switch (op) {
    case 0x18:
        *(s32 *)(idx * 4 + (s32)b + 0x1090) += 1;
        break;
    case 0x19:
        *(s32 *)(idx * 4 + (s32)b + 0x1090) -= 1;
        break;
    case 0x1a:
        *(s32 *)(idx * 4 + (s32)b + 0x1090) = ~*(s32 *)(idx * 4 + (s32)b + 0x1090);
        break;
    case 0x1b:
        *(s32 *)(idx * 4 + (s32)b + 0x1090) = -*(s32 *)(idx * 4 + (s32)b + 0x1090);
        break;
    }
    v = *(s32 *)(idx * 4 + (s32)b + 0x1090);
    q = SCRIPT_CTX;
    if (v == 0) {
        q[0x89] = 0;
    } else {
        q[0x89] = v < 0 ? 1 : 2;
    }
    *(s16 *)(b + 0x8a) = *(s16 *)(b + 0x8a) + 2;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003BD28);
typedef struct { char pad[0x1090]; s32 v[1]; } VS_3BD28;
void func_8003BD28(u8 op)
{
    s32 tmp;
    u8 *o = (*(u8 **)&SCRIPT_CTX);
    s32 code = SCRIPT_CODE;
    s32 idx;
    s32 a;
    s32 b;
    s32 k;
    s32 r;
    u8 f;
    u8 *p;
    u8 *g;
    u16 x;
    idx = *(u8 *)(*(u16 *)(o + 0x8a) + code + 1);
    a = *(s32 *)(o + idx * 4 + 0x1090);
    do { } while (0);
    switch (op) {
    case 0x1c: case 0x1e: case 0x20: case 0x22:
    case 0x24: case 0x26: case 0x28: case 0x2a:
        b = *(s32 *)((*(u8 **)&SCRIPT_CTX) + *(u8 *)(*(u16 *)(o + 0x8a) + code + 2) * 4 + 0x1090);
        f = 0;
        break;
    case 0x1d: case 0x1f: case 0x21: case 0x23:
    case 0x25: case 0x27: case 0x29: case 0x2b:
        p = (u8 *)(*(u16 *)(o + 0x8a) + code) + 2;
        for (k = 0; k < 4; k++)
            ((char *)&tmp)[k] = p[k];
        b = tmp;
        f = 1;
        break;
    }
    switch (op) {
    case 0x1c: case 0x1d:
        r = a + b;
        break;
    case 0x1e: case 0x1f:
        r = a - b;
        break;
    case 0x20: case 0x21:
        r = a * b;
        break;
    case 0x22: case 0x23:
        r = 0;
        if (b != 0)
            r = a / b;
        break;
    case 0x24: case 0x25:
        r = 0;
        if (b != 0)
            r = a % b;
        break;
    case 0x26: case 0x27:
        r = a & b;
        break;
    case 0x28: case 0x29:
        r = a | b;
        break;
    case 0x2a: case 0x2b:
        r = a ^ b;
        break;
    }
    ((VS_3BD28 *)o)->v[idx] = r;
    g = (*(u8 **)&SCRIPT_CTX);
    if (r == 0)
        g[0x89] = 0;
    else
        g[0x89] = (r < 0) ? 1 : 2;
    x = *(u16 *)(o + 0x8a);
    *(u16 *)(o + 0x8a) = f ? x + 6 : x + 3;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", scriptOpWait);
void scriptOpWait(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8 v = SCRIPT_CODE[p->pc + 1];

    *(s32*)((u8*)p + 0x11D0) = 0;
    *((u8*)p + 0x88) = 2;
    p->pc += 2;
    *(s32*)((u8*)p + 0x11D4) = v;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/script", func_8003BF58);
typedef struct { s16 m[4]; s16 w[64]; } F_3BF58;
typedef struct {
    s16 w[64];
    F_3BF58 *p80;
    F_3BF58 *p84;
    u8 b88;
    char b89;
    u16 w8a;
} G_3BF58;

void func_8003BF58(void)
{
    G_3BF58 *g = SCRIPT_CTX;
    u8 *t = SCRIPT_CODE;
    char buf[80];
    F_3BF58 s;
    F_3BF58 *src;
    F_3BF58 *ps;
    s32 i, n, j;

    n = t[g->w8a + 1];
    for (i = 0; i < n; i++) {
        buf[i] = t[i + g->w8a + 2];
    }
    buf[i] = 0;
    for (i = 63; i >= 0; i--) {
        SCRIPT_OBJECTS[i] = 0;
    }
    src = g->p80;
    g->b88 = 0;
    g->w8a = 0;
    ps = &s;
    s = *src;
    if (*(s32 *)s.m != 0x530057) {
        printf(D_80013798);
        D_8009CA04 = 0;
        return;
    }
    for (j = 0; j < 64; j++) {
        g->w[j] = ps->w[j];
    }
    g->p80 = src;
    g->p84 = src + 1;
    g->b88 = 0;
}
