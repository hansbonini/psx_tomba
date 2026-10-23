#include "common.h"
#include "psyq/libstamp.h"

#define JB_SP 1
extern int setjmp(jmp_buf);
long long startIntrDMA();
void* startIntrVSync();
void trapIntr();
static void memclr(s32* mem, int len);
void memclr(s32* mem, int len);

typedef int jmp_buf[12];
struct Intr {
    u16 unk0;
    u16 isCbContext;
    s16 D_800B5FFC[24];
    s32 D_800B602C;
    jmp_buf env;
    s32 stack[0x400];
};
extern struct Intr D_80096418;
extern int VSyncCallback(void (*f)());
struct intr {
    const char* ver;
    void (*cb)();
    void (*set)(int arg0, void (*cb)(void));
    int (*start)();
    int (*stop)();
    int (*unk14)(int, void (*f)());
    int (*restart)();
    short* unk1C;
};
extern struct intr* D_800974A0;
int VSyncCallback(void (*func)());
extern volatile u16* D_800974A8;
extern volatile s32* D_800974AC;
void HookEntryInt(jmp_buf env);
extern volatile u16* D_800974A4;

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", ResetCallback);

int ResetCallback(void) { return D_800974A0->start(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", InterruptCallback);

void InterruptCallback(int arg0, void (*cb)(void)) {
    D_800974A0->set(arg0, cb);
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", DMACallback);

void DMACallback(void) { D_800974A0->cb(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", VSyncCallback);

int VSyncCallback(void (*func)()) { return D_800974A0->unk14(4, func); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", VSyncCallbacks);

int VSyncCallbacks(int n, void (*func)()) { return D_800974A0->unk14(n, func); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", StopCallback);

int StopCallback(void) { return D_800974A0->stop(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", RestartCallback);

int RestartCallback(void) { return D_800974A0->restart(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", CheckCallback);

int CheckCallback() { return D_80096418.isCbContext; }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", GetIntrMask);

int GetIntrMask() { return *D_800974A8; }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", SetIntrMask);

int SetIntrMask(int mask) {
    int prev = *D_800974A8;
    *D_800974A8 = mask;
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", startIntr);

void* startIntr(void) {
    if (D_80096418.unk0) {
        return NULL;
    }
    *D_800974A4 = *D_800974A8 = 0;
    *D_800974AC = 0x33333333;
    memclr(&D_80096418, sizeof(D_80096418) / sizeof(s32));
    if (setjmp(D_80096418.env)) {
        trapIntr();
    }
    D_80096418.env[JB_SP] = &D_80096418.stack[0x3EC];
    HookEntryInt(D_80096418.env);
    D_80096418.unk0 = 1;
    D_800974A0->unk14 = startIntrVSync();
    D_800974A0->cb = startIntrDMA();
    _96_remove();
    ExitCriticalSection();
    return &D_80096418.unk0;
}

typedef struct IntrEnv {
    u16 initialized;
    u16 inInterrupt;
    void (*handlers[11])();
    u16 enabledMask;
} IntrEnv;
extern IntrEnv D_80096418_Env asm("D_80096418");
extern s32 D_800974B0;

INCLUDE_RODATA("nonmatchings/psyq/libetc/intr", D_800161F8);

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", trapIntr);
void trapIntr()
{
    int i;
    u16 mask;

    if (!D_80096418_Env.initialized) {
        printf("unexpected interrupt(%04x)\n", *D_800974A4);
        ReturnFromException();
    }
    D_80096418_Env.inInterrupt = 1;
    while ((mask = (D_80096418_Env.enabledMask & *D_800974A4) & *D_800974A8) != 0) {
        for (i = 0; mask && i < 11; ++i, mask >>= 1) {
            if (mask & 1) {
                *D_800974A4 = ~(1 << i);
                if (D_80096418_Env.handlers[i]) {
                    D_80096418_Env.handlers[i]();
                }
            }
        }
    }
    if (*D_800974A4 & *D_800974A8) {
        if (D_800974B0++ > 0x800) {
            printf("intr timeout(%04x:%04x)\n", *D_800974A4, *D_800974A8);
            D_800974B0 = 0;
            *D_800974A4 = 0;
        }
    } else {
        D_800974B0 = 0;
    }
    D_80096418_Env.inInterrupt = 0;
    ReturnFromException();
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", setIntr);

void (*setIntr(int index, void (*fn)()))()
{
    void (*old)();
    u16 mask;
    int newMask;

    old = D_80096418_Env.handlers[index];
    if (fn != old && D_80096418_Env.initialized) {
        mask = *D_800974A8;
        *D_800974A8 = 0;
        newMask = mask & 0xFFFF;
        if (fn != NULL) {
            D_80096418_Env.handlers[index] = fn;
            newMask |= 1 << index;
            D_80096418_Env.enabledMask |= 1 << index;
        } else {
            D_80096418_Env.handlers[index] = NULL;
            newMask &= ~(1 << index);
            D_80096418_Env.enabledMask &= ~(1 << index);
        }
        if (index == 0) {
            ChangeClearPAD(fn == NULL);
            ChangeClearRCnt(3, fn == NULL);
        }
        if (index == 4) {
            ChangeClearRCnt(0, fn == NULL);
        }
        if (index == 5) {
            ChangeClearRCnt(1, fn == NULL);
        }
        if (index == 6) {
            ChangeClearRCnt(2, fn == NULL);
        }
        *D_800974A8 = newMask;
    }
    return old;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", stopIntr);

u16* stopIntr(void) {
    if (D_80096418.unk0) {
        EnterCriticalSection();
        D_80096418.D_800B5FFC[0x17] = *D_800974A8;
        D_80096418.D_800B602C = *D_800974AC;
        *D_800974A4 = *D_800974A8 = 0;
        *D_800974AC &= 0x77777777;
        ResetEntryInt();
        if (D_800974AC && D_800974AC) {
        }
        D_80096418.unk0 = 0;
        return &D_80096418.unk0;
    }
    return NULL;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", restartIntr);

u16* restartIntr(void) {
    if (D_80096418.unk0) {
        return NULL;
    }
    HookEntryInt(D_80096418.env);
    D_80096418.unk0 = 1;
    *D_800974A8 = D_80096418.D_800B5FFC[0x17];
    *D_800974AC = D_80096418.D_800B602C;
    ExitCriticalSection();
    return &D_80096418.unk0;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", memclr);

void memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", func_80068534);
#if REGION == REGION_JP
const PsyqStamp libapi_stamp SECTION(".text") = PSYQ_SDK_STAMP(PSYQ_LIB_API, 18, 38, 52);
#elif REGION == REGION_EU && VERSION == 1 && LANGUAGE != LANGUAGE_NONE
const PsyqStamp libapi_stamp SECTION(".text") = PSYQ_STAMP(PSYQ_LIB_API, 4, 3, 0, 37, 10, 20, 54);
#else
const PsyqStamp libapi_stamp SECTION(".text") = PSYQ_STAMP(PSYQ_LIB_API, 4, 2, 0, 33, 6, 53, 26);
#endif

INCLUDE_RODATA("nonmatchings/psyq/libetc/intr", D_80016264);

INCLUDE_RODATA("nonmatchings/psyq/libetc/intr", D_80016280);

