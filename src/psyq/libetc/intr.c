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
    u16 initialized;
    u16 inInterrupt;
    void (*handlers[11])();
    u16 enabledMask;
    s16 savedMask;
    s32 savedDpcr;
    jmp_buf env;
    s32 stack[0x400];
};
extern int VSyncCallback(void (*f)());
struct intr {
    const char* ver;
    void (*dma)();
    void (*set)(int arg0, void (*cb)(void));
    int (*start)();
    int (*stop)();
    int (*vsync)(int, void (*f)());
    int (*restart)();
    short* env;
};
int VSyncCallback(void (*func)());
void HookEntryInt(jmp_buf env);

extern const char intr_id[];
void* startIntr(void);
void (*setIntr(int index, void (*fn)()))();
u16* stopIntr(void);
u16* restartIntr(void);

struct Intr intr_env = {0};
struct intr intr_table = {
    intr_id, NULL, (void*)setIntr, (void*)startIntr,
    (void*)stopIntr, NULL, (void*)restartIntr, (short*)&intr_env,
};
struct intr* intr_table_ptr = &intr_table;
volatile u16* intr_istat = (volatile u16*)0x1F801070;
volatile u16* intr_imask = (volatile u16*)0x1F801074;
volatile s32* intr_dpcr = (volatile s32*)0x1F8010F0;
s32 intr_timeout = 0;

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", ResetCallback);

/**
 * @brief Initialize the interrupt callback system
 * 
 * Installs the library interrupt handler, clears all callbacks and sets up
 * the VSync and DMA dispatchers. Must be called before any other callback
 * function.
 * 
 * @return Pointer to the internal interrupt state on first initialization, 0 if already initialized
 */
int ResetCallback(void) { return intr_table_ptr->start(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", InterruptCallback);

/**
 * @brief Set the callback of a hardware interrupt
 * 
 * Registers a handler for one of the interrupt sources of I_STAT (0 =
 * VBlank, 1 = GPU, 2 = CD-ROM, 3 = DMA, 4-6 = root counters, ...).
 * 
 * @param arg0 Interrupt number
 * @param cb Callback function (NULL to remove it)
 */
void InterruptCallback(int arg0, void (*cb)(void)) {
    intr_table_ptr->set(arg0, cb);
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", DMACallback);

/**
 * @brief Set the callback of a DMA channel
 * 
 * Forwards its register arguments (channel number and callback function)
 * to the DMA dispatcher installed by ResetCallback(). Declared without
 * parameters here, but called as DMACallback(channel, func) and returns
 * the previous callback.
 */
void DMACallback(void) { intr_table_ptr->dma(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", VSyncCallback);

/**
 * @brief Set the vertical blank callback
 * 
 * Registers a function called at the start of every vertical blank (uses
 * dispatcher slot 4).
 * 
 * @param func Callback function (NULL to remove it)
 * @return Result of the VSync dispatcher
 */
int VSyncCallback(void (*func)()) { return intr_table_ptr->vsync(4, func); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", VSyncCallbacks);

/**
 * @brief Set one of the vertical blank callback slots
 * 
 * Registers a function in a specific slot of the VSync dispatcher (8
 * slots).
 * 
 * @param n Slot number (0-7)
 * @param func Callback function (NULL to remove it)
 * @return Result of the VSync dispatcher
 */
int VSyncCallbacks(int n, void (*func)()) { return intr_table_ptr->vsync(n, func); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", StopCallback);

/**
 * @brief Disable the interrupt callback system
 * 
 * Masks all interrupts, saves the interrupt and DMA state and removes the
 * library interrupt handler.
 * 
 * @return Result of the internal stop function
 */
int StopCallback(void) { return intr_table_ptr->stop(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", RestartCallback);

/**
 * @brief Re-enable the interrupt callback system
 * 
 * Reinstalls the interrupt handler and restores the state saved by
 * StopCallback().
 * 
 * @return Result of the internal restart function
 */
int RestartCallback(void) { return intr_table_ptr->restart(); }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", CheckCallback);

/**
 * @brief Check whether the code runs inside an interrupt callback
 * 
 * Reads the "in interrupt" flag of the dispatcher.
 * 
 * @return 1 if called from an interrupt context, 0 otherwise
 */
int CheckCallback() { return intr_env.inInterrupt; }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", GetIntrMask);

/**
 * @brief Get the interrupt mask register
 * 
 * Returns the current value of I_MASK.
 * 
 * @return Interrupt mask
 */
int GetIntrMask() { return *intr_imask; }

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", SetIntrMask);

/**
 * @brief Set the interrupt mask register
 * 
 * Writes a new value to I_MASK.
 * 
 * @param mask New interrupt mask
 * @return Previous interrupt mask
 */
int SetIntrMask(int mask) {
    int prev = *intr_imask;
    *intr_imask = mask;
    return prev;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", startIntr);

/**
 * @brief Internal: start the interrupt dispatcher
 * 
 * Clears the interrupt registers and state, sets up a private stack and
 * hooks trapIntr() into the BIOS interrupt chain, then starts the VSync
 * and DMA dispatchers.
 * 
 * @return Pointer to the dispatcher state, or NULL if already started
 */
void* startIntr(void) {
    if (intr_env.initialized) {
        return NULL;
    }
    *intr_istat = *intr_imask = 0;
    *intr_dpcr = 0x33333333;
    memclr(&intr_env, sizeof(intr_env) / sizeof(s32));
    if (setjmp(intr_env.env)) {
        trapIntr();
    }
    intr_env.env[JB_SP] = &intr_env.stack[0x3EC];
    HookEntryInt(intr_env.env);
    intr_env.initialized = 1;
    intr_table_ptr->vsync = startIntrVSync();
    intr_table_ptr->dma = startIntrDMA();
    _96_remove();
    ExitCriticalSection();
    return &intr_env.initialized;
}


const char intr_id[] = "$Id: intr.c,v 1.74 1996/12/04 07:30:16 makoto Exp $";

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", trapIntr);
/**
 * @brief Internal: main interrupt handler
 * 
 * Acknowledges each pending and enabled interrupt source and calls its
 * handler, repeating until none remain. Reports a stuck interrupt after
 * too many retries.
 */
void trapIntr()
{
    int i;
    u16 mask;

    if (!intr_env.initialized) {
        printf("unexpected interrupt(%04x)\n", *intr_istat);
        ReturnFromException();
    }
    intr_env.inInterrupt = 1;
    while ((mask = (intr_env.enabledMask & *intr_istat) & *intr_imask) != 0) {
        for (i = 0; mask && i < 11; ++i, mask >>= 1) {
            if (mask & 1) {
                *intr_istat = ~(1 << i);
                if (intr_env.handlers[i]) {
                    intr_env.handlers[i]();
                }
            }
        }
    }
    if (*intr_istat & *intr_imask) {
        if (intr_timeout++ > 0x800) {
            printf("intr timeout(%04x:%04x)\n", *intr_istat, *intr_imask);
            intr_timeout = 0;
            *intr_istat = 0;
        }
    } else {
        intr_timeout = 0;
    }
    intr_env.inInterrupt = 0;
    ReturnFromException();
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", setIntr);

/**
 * @brief Internal: set the handler of an interrupt source
 * 
 * Stores the handler, updates the interrupt mask and tells the BIOS
 * whether it should still auto-acknowledge the pad/VBlank and root counter
 * interrupts.
 * 
 * @param index Interrupt number (0-10)
 * @param fn Handler function (NULL to remove it)
 * @return Previous handler
 */
void (*setIntr(int index, void (*fn)()))()
{
    void (*old)();
    u16 mask;
    int newMask;

    old = intr_env.handlers[index];
    if (fn != old && intr_env.initialized) {
        mask = *intr_imask;
        *intr_imask = 0;
        newMask = mask & 0xFFFF;
        if (fn != NULL) {
            intr_env.handlers[index] = fn;
            newMask |= 1 << index;
            intr_env.enabledMask |= 1 << index;
        } else {
            intr_env.handlers[index] = NULL;
            newMask &= ~(1 << index);
            intr_env.enabledMask &= ~(1 << index);
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
        *intr_imask = newMask;
    }
    return old;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", stopIntr);

/**
 * @brief Internal: stop the interrupt dispatcher
 * 
 * Saves and clears the interrupt mask and DMA enable bits and unhooks the
 * handler.
 * 
 * @return Pointer to the dispatcher state, or NULL if it was not running
 */
u16* stopIntr(void) {
    if (intr_env.initialized) {
        EnterCriticalSection();
        intr_env.savedMask = *intr_imask;
        intr_env.savedDpcr = *intr_dpcr;
        *intr_istat = *intr_imask = 0;
        *intr_dpcr &= 0x77777777;
        ResetEntryInt();
        if (intr_dpcr && intr_dpcr) {
        }
        intr_env.initialized = 0;
        return &intr_env.initialized;
    }
    return NULL;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", restartIntr);

/**
 * @brief Internal: restart the interrupt dispatcher
 * 
 * Rehooks the handler and restores the saved interrupt mask and DMA enable
 * bits.
 * 
 * @return Pointer to the dispatcher state, or NULL if it was already running
 */
u16* restartIntr(void) {
    if (intr_env.initialized) {
        return NULL;
    }
    HookEntryInt(intr_env.env);
    intr_env.initialized = 1;
    *intr_imask = intr_env.savedMask;
    *intr_dpcr = intr_env.savedDpcr;
    ExitCriticalSection();
    return &intr_env.initialized;
}

// INCLUDE_ASM("nonmatchings/psyq/libetc/intr", memclr);

/**
 * @brief Internal: clear an array of 32-bit words
 * 
 * Writes zero to len consecutive words.
 * 
 * @param mem Start address
 * @param len Number of words
 */
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

