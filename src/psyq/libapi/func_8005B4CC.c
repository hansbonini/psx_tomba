#include "common.h"

typedef struct {
    char* name;
    s32 pad[12];
    s32 (*firstfile)();
    s32 pad2[6];
} DevEntry;

extern s32 firstfile();
extern s32 (*D_8009B108)();
extern char D_8009B110[];

#define DEV_TABLE (*(DevEntry**)0x150)
#define DEV_SIZE (*(u32*)0x154)

/**
 * @brief Internal: look up the saved device name in the BIOS device table
 * 
 * Walks the kernel device table (pointer/size at 0x150/0x154) looking for
 * the entry whose name matches the device name previously stored in
 * D_8009B110, and saves that entry's firstfile handler in D_8009B108.
 * 
 * @return 1 if the device was found, 0 otherwise
 */
static inline s32 hook_find(void)
{
    DevEntry* dev;
    DevEntry* end;
    DevEntry* tmp;

    dev = DEV_TABLE;
    tmp = dev + DEV_SIZE / sizeof(DevEntry);
    if (dev < tmp) {
        end = tmp;
        do {
            if (dev->name != NULL && strcmp(dev->name, D_8009B110) == 0) {
                D_8009B108 = dev->firstfile;
                return 1;
            }
            dev++;
        } while (dev < end);
    }
    return 0;
}

s32 func_8005B668();

/**
 * @brief Internal: firstfile() wrapper that temporarily hooks the device handler
 * 
 * Copies the device name prefix of the path (up to the first character
 * below ';', normally the ':') into D_8009B110, finds that device,
 * replaces its firstfile handler with func_8005B668 and then calls the
 * BIOS firstfile(). The replacement handler restores the original one on
 * its first call. The exact purpose of the hook (probably a BIOS bug
 * workaround) is uncertain.
 * 
 * @param name Path / file name pattern, e.g. "cdrom:\\FILE"
 * @param entry Directory entry buffer filled by firstfile()
 * @return Result of the BIOS firstfile() call, or 0 if the device is unknown
 */
s32 func_8005B4CC(signed char* name, void* entry)
{
    DevEntry* dev;
    DevEntry* end;
    DevEntry* tmp;
    signed char* s = name;
    char* d = D_8009B110;

    while (*s >= 0x3B) {
        *d++ = *s++;
    }
    *d = 0;
    if (hook_find() == 0) {
        return 0;
    }
    dev = DEV_TABLE;
    tmp = dev + DEV_SIZE / sizeof(DevEntry);
    if (dev < tmp) {
        end = tmp;
        do {
            if (dev->name != NULL && strcmp(dev->name, D_8009B110) == 0) {
                dev->firstfile = func_8005B668;
                break;
            }
            dev++;
        } while (dev < end);
    }
    return firstfile(name, entry);
}

/**
 * @brief Internal: replacement device firstfile handler installed by func_8005B4CC
 * 
 * Forces the first field of the file descriptor to 1 if it is zero,
 * restores the original firstfile handler of the hooked device and
 * forwards the call to it.
 * 
 * @param fd Device file control block passed by the kernel
 * @param a1 Second argument forwarded to the original handler
 * @param a2 Third argument forwarded to the original handler
 * @return Result of the original device handler
 */
s32 func_8005B668(s32* fd, void* a1, void* a2)
{
    DevEntry* dev;
    DevEntry* end;
    DevEntry* tmp;
    s32 (*saved)();

    if (*fd == 0) {
        *fd = 1;
    }
    saved = D_8009B108;
    dev = DEV_TABLE;
    tmp = dev + DEV_SIZE / sizeof(DevEntry);
    if (dev < tmp) {
        end = tmp;
        do {
            if (dev->name != NULL && strcmp(dev->name, D_8009B110) == 0) {
                dev->firstfile = saved;
                break;
            }
            dev++;
        } while (dev < end);
    }
    return D_8009B108(fd, a1, a2);
}
