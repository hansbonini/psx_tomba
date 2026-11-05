#include "common.h"

void (*vb_callbacks[8])(void) = {0};
volatile int Vcount = 0;
int* vb_rcnt1_mode = (int*)0x1F801114;

extern void InterruptCallback(int, void (*)());
void trapIntrVSync(void);
extern void setIntrVSync(int, void (*)(void));
void VSync_memclr(s32*, int);
void setIntrVSync(int index, void (*callback)(void));

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", startIntrVSync);

void* startIntrVSync(void)
{
    *vb_rcnt1_mode = 0x107;
    Vcount = 0;
    VSync_memclr(vb_callbacks, 8);
    InterruptCallback(0, trapIntrVSync);
    return setIntrVSync;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", trapIntrVSync);

void trapIntrVSync(void) {
    void (**cb)();
    s32 i;

    i = 0;
    cb = vb_callbacks;
    Vcount += 1;
    (void)Vcount;
    do {
        if (cb[i] != 0) {
            cb[i]();
        }
        i += 1;
    } while (i < 8);
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", setIntrVSync);

void setIntrVSync(int index, void (*callback)(void))
{
    if (callback != vb_callbacks[index]) {
        vb_callbacks[index] = callback;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", VSync_memclr);

void VSync_memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}
