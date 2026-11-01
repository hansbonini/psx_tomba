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
