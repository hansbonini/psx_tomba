#include "common.h"

extern void InterruptCallback(int, void (*)());
void trapIntrVSync(void);
extern void setIntrVSync(int, void (*)(void));
void VSync_memclr(s32*, int);
extern volatile int Vcount;
extern int* D_800974D8;
void setIntrVSync(int index, void (*callback)(void));

extern void (*D_800974B4[8])(void);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", startIntrVSync);

void* startIntrVSync(void)
{
    *D_800974D8 = 0x107;
    Vcount = 0;
    VSync_memclr(D_800974B4, 8);
    InterruptCallback(0, trapIntrVSync);
    return setIntrVSync;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", trapIntrVSync);

void trapIntrVSync(void) {
    void (**cb)();
    s32 i;

    i = 0;
    cb = D_800974B4;
    Vcount += 1;
    (void)Vcount;
    do {
        if (cb[i] != 0) {
            cb[i]();
        }
        i += 1;
    } while (i < 8);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", setIntrVSync);

void setIntrVSync(int index, void (*callback)(void))
{
    if (callback != D_800974B4[index]) {
        D_800974B4[index] = callback;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libetc/intr_vb", VSync_memclr);

void VSync_memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}
