#include "common.h"

/** @brief VSync callback slots called by trapIntrVSync */
void (*vb_callbacks[8])(void) = {0};
/** @brief Number of vertical blanks since the VSync dispatcher was started */
volatile int Vcount = 0;
int* vb_rcnt1_mode = (int*)0x1F801114;

extern void InterruptCallback(int, void (*)());
void trapIntrVSync(void);
extern void setIntrVSync(int, void (*)(void));
void VSync_memclr(s32*, int);
void setIntrVSync(int index, void (*callback)(void));

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", startIntrVSync);

/**
 * @brief Internal: start the VSync interrupt dispatcher
 * 
 * Sets root counter 1 to count horizontal blanks, resets the VSync
 * counter, clears the callbacks and registers trapIntrVSync() as the
 * VBlank handler.
 * 
 * @return Address of setIntrVSync(), used by VSyncCallback()
 */
void* startIntrVSync(void)
{
    *vb_rcnt1_mode = 0x107;
    Vcount = 0;
    VSync_memclr(vb_callbacks, 8);
    InterruptCallback(0, trapIntrVSync);
    return setIntrVSync;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", trapIntrVSync);

/**
 * @brief Internal: VBlank interrupt handler
 * 
 * Increments the VSync counter and calls every registered VSync callback.
 */
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

/**
 * @brief Internal: set a VSync callback slot
 * 
 * Stores the callback in the given slot.
 * 
 * @param index Slot number (0-7)
 * @param callback Callback function (NULL to remove it)
 */
void setIntrVSync(int index, void (*callback)(void))
{
    if (callback != vb_callbacks[index]) {
        vb_callbacks[index] = callback;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr_vb", VSync_memclr);

/**
 * @brief Internal: clear an array of 32-bit words
 * 
 * Writes zero to len consecutive words.
 * 
 * @param mem Start address
 * @param len Number of words
 */
void VSync_memclr(s32* mem, int len) {
    int i;
    for (i = len - 1; i != -1; i--) {
        *mem++ = 0;
    }
}
