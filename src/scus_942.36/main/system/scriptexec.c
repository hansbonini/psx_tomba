#include "common.h"
#include "game.h"

static inline s32 readOperand(u8* src, u8 kind)
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

static inline void opSet(u8 kind)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* script = SCRIPT_CODE;
    s32 dst = script[p->pc + 1];
    u8* q = script + p->pc;

    *(s32*)(dst * 4 + (s32)p + 0x1090) = readOperand(q + 2, kind);
    if (kind == 0) {
        p->pc += 3;
    } else {
        p->pc += 6;
    }
}

static inline u16 readU16(u8* src)
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

static inline void opLoop(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* script = SCRIPT_CODE;
    s32* v = (s32*)(script[p->pc + 1] * 4 + (s32)p + 0x1090);
    s32 n = *v - 1;

    *v = n;
    if (n > 0) {
        p->pc = readU16((u8*)(p->pc + (s32)script) + 2);
    } else {
        p->pc += 4;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptexec", execCoreOpcode);
int execCoreOpcode(u8 op)
{
    ScriptContext* self = SCRIPT_CTX;
    int ret;

    switch (op) {
    case 1: {
        s32 i;

        for (i = 0x3F; i >= 0; i--) {
            SCRIPT_OBJECTS[i] = NULL;
        }
        ret = 0;
        self->state = 0;
        self->pc = 0;
        break;
    }
    case 2:
        opSet(0);
        ret = 1;
        break;
    case 3:
        opSet(1);
        ret = 1;
        break;
    case 4: {
        ScriptContext* p = SCRIPT_CTX;
        u8*  q = (u8*)(p->pc + (s32)SCRIPT_CODE);
        s32* a = (s32*)(q[1] * 4 + (s32)p + 0x1090);
        s32* b = (s32*)(q[2] * 4 + (s32)p + 0x1090);
        s32  x = *b;
        s32  y = *a;

        *a = x;
        *b = y;
        p->pc += 3;
        ret = 1;
        break;
    }
    case 6: {
        ScriptContext* p = SCRIPT_CTX;
        u8* script = SCRIPT_CODE;
        s32 idx = script[p->pc + 1];

        *(s32*)(idx * 4 + (s32)p + 0x1090) = nextRandom();
        p->pc += 2;
        ret = 1;
        break;
    }
    case 5:
        func_8003B750();
        ret = 1;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        scriptOpBranch(op);
        ret = 1;
        break;
    case 17:
        opLoop();
        ret = 1;
        break;
    case 18: {
        ScriptContext* p = SCRIPT_CTX;
        u8* script = SCRIPT_CODE;
        s32 v = p->pc + 2;

        *(s32*)((u8*)p + p->sp * 4 + 0x90) = v;
        p->sp = p->sp + 1;
        p->pc = *(u16*)((u8*)p + script[p->pc + 1] * 2) - 1;
        ret = 1;
        break;
    }
    case 19: {
        ScriptContext* p = SCRIPT_CTX;

        p->sp = p->sp - 1;
        p->pc = *(u16*)((u8*)p + p->sp * 4 + 0x90);
        ret = 1;
        break;
    }
    case 20: {
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
        ret = 1;
        break;
    }
    case 21: {
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
        ret = 1;
        break;
    }
    case 22:
        func_8003BB48(0);
        ret = 1;
        break;
    case 23:
        func_8003BB48(1);
        ret = 1;
        break;
    case 24:
    case 25:
    case 26:
    case 27:
        func_8003BC34(op);
        ret = 1;
        break;
    case 28:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
        func_8003BD28(op);
        ret = 1;
        break;
    case 44: {
        ScriptContext* p = SCRIPT_CTX;
        u8 v = SCRIPT_CODE[p->pc + 1];

        ret = 0;
        *(s32*)((u8*)p + 0x11D0) = 0;
        *((u8*)p + 0x88) = 2;
        p->pc += 2;
        *(s32*)((u8*)p + 0x11D4) = v;
        break;
    }
    default: {
        s32 i;

        for (i = 0x3F; i >= 0; i--) {
            SCRIPT_OBJECTS[i] = NULL;
        }
        ret = 0;
        self->state = 0;
        self->pc = 0;
        break;
    }
    }
    return ret;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptexec", scriptRunOpcode);
void scriptRunOpcode(void)
{
    ScriptContext* p = SCRIPT_CTX;
    u8* script = SCRIPT_CODE;
    u8  op = script[p->pc];

    if (op < 0x80) {
        execCoreOpcode(op);
    } else {
        execGameOpcode(op);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptexec", runScript);
u_char runScript(void)
{
    ScriptContext* p;
    int ret;

    p = SCRIPT_CTX;
    if (p->state == 2) {
        *(u_int*)((u8*)p + 0x11D0) += 1;
        if (*(u_int*)((u8*)p + 0x11D0) >= *(u_int*)((u8*)p + 0x11D4)) {
            p->state = 1;
        }
    }
    if (p->state != 1) {
        return p->state;
    }
    do {
        ScriptContext* q = SCRIPT_CTX;
        u8* script = SCRIPT_CODE;
        u8 op = script[q->pc];

        if (op < 0x80) {
            ret = execCoreOpcode(op);
        } else {
            ret = execGameOpcode(op);
        }
    } while (ret != 0);
    return p->state;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptexec", runScriptContext);
u_char runScriptContext(ScriptContext* ctx)
{
    ScriptContext* p;
    u8* base;
    int ret;

    base = *(u8**)((u8*)ctx + 0x84);
    SCRIPT_CTX = ctx;
    SCRIPT_CODE = base;
    p = SCRIPT_CTX;
    if (p->state == 2) {
        *(u_int*)((u8*)p + 0x11D0) += 1;
        if (*(u_int*)((u8*)p + 0x11D0) >= *(u_int*)((u8*)p + 0x11D4)) {
            p->state = 1;
        }
    }
    if (p->state != 1) {
        return p->state;
    }
    do {
        ScriptContext* q = SCRIPT_CTX;
        u8* script = SCRIPT_CODE;
        u8 op = script[q->pc];

        if (op < 0x80) {
            ret = execCoreOpcode(op);
        } else {
            ret = execGameOpcode(op);
        }
    } while (ret != 0);
    return p->state;
}

extern u8 D_8009C119;
extern u8 D_8009C120;
extern u8 D_8009C121;
extern u8 D_8009C245;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/scriptexec", loadAreaSoundBank);
void loadAreaSoundBank(void)
{
    D_8009CA04 = 0;
    switch (GAME.selectedArea + (u16)D_8009EBA0) {
    case 0:
        switch (D_8009BCCA) {
        case 0:
        case 1:
        case 2:
            loadSoundBank(0xF, 6);
            D_8009CA04 = 1;
            break;
        }
        break;
    case 1:
    case 7:
        switch (D_8009BCCA) {
        case 0:
        case 1:
            if (D_8009C119 != 0xFF) {
                loadSoundBank(0xF, 0);
                D_8009CA04 = 1;
            }
            if (D_8009C120 == 0xFF) {
                if (D_8009C121 == 0) {
                    loadSoundBank(0xF, 0);
                    D_8009CA04 = 1;
                } else if (D_8009C245 == 2) {
                    loadSoundBank(0xF, 0);
                    D_8009CA04 = 1;
                }
            }
            break;
        case 2:
            loadSoundBank(0xF, 5);
            D_8009CA04 = 1;
            break;
        case 3:
            loadSoundBank(0xF, 4);
            D_8009CA04 = 1;
            break;
        case 4:
            loadSoundBank(0xF, 3);
            D_8009CA04 = 1;
            break;
        }
        break;
    case 2:
        switch (D_8009BCCA) {
        case 0:
            if (D_8009C120 == 1) {
                loadSoundBank(0xF, 8);
            } else {
                loadSoundBank(0xF, 1);
            }
            D_8009CA04 = 2;
            break;
        case 1:
            loadSoundBank(0xF, 2);
            D_8009CA04 = 1;
            break;
        case 2:
            loadSoundBank(0xF, 7);
            D_8009CA04 = 1;
            break;
        }
        break;
    case 0x13:
        switch (D_8009BCCA) {
        case 0:
            if (D_8009C120 == 1) {
                loadSoundBank(0xF, 8);
            } else {
                loadSoundBank(0xF, 1);
            }
            D_8009CA04 = 2;
            break;
        case 1:
            loadSoundBank(0xF, 2);
            D_8009CA04 = 1;
            break;
        }
        break;
    }
}
