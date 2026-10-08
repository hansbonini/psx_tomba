#include "common.h"

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", ResetCallback);

int ResetCallback(void) { return D_800974A0->start(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", InterruptCallback);

void InterruptCallback(int arg0, void (*cb)(void)) {
    D_800974A0->set(arg0, cb);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", DMACallback);

void DMACallback(void) { D_800974A0->cb(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", VSyncCallback);

int VSyncCallback(void (*func)()) { return D_800974A0->unk14(4, func); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", VSyncCallbacks);

int VSyncCallbacks(int n, void (*func)()) { return D_800974A0->unk14(n, func); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", StopCallback);

int StopCallback(void) { return D_800974A0->stop(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", RestartCallback);

int RestartCallback(void) { return D_800974A0->restart(); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", CheckCallback);

int CheckCallback() { return D_80096418.isCbContext; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", GetIntrMask);

int GetIntrMask() { return *D_800974A8; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", SetIntrMask);

int SetIntrMask(int mask) {
    int prev = *D_800974A8;
    *D_800974A8 = mask;
    return prev;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", startIntr);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/psyq/libetc/intr", D_800161F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", trapIntr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", setIntr);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", stopIntr);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", restartIntr);

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", memclr);

void memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", func_80068534);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr", func_8006853C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/psyq/libetc/intr", D_80016264);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/psyq/libetc/intr", D_80016280);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/psyq/libetc/intr", jtbl_80016290);
