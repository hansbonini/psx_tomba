#include "common.h"
#include "psyq/kernel.h"

#if !(SKIP_ASM || M2CTX)

    BIOS_STUB(FlushCache, 0xA0, 0x44);

    BIOS_STUB(_bu_init, 0xA0, 0x70);

    BIOS_STUB(OpenEvent, 0xB0, 0x8);

    BIOS_STUB(CloseEvent, 0xB0, 0x9);

    BIOS_STUB(TestEvent, 0xB0, 0xB);

    BIOS_STUB(EnableEvent, 0xB0, 0xC);

    BIOS_STUB(OpenTh, 0xB0, 0xE);

    BIOS_STUB(CloseTh, 0xB0, 0xF);

    BIOS_STUB(ChangeTh, 0xB0, 0x10);

    void EnterCriticalSection() { SYSCALL(1); }

    void ExitCriticalSection() { SYSCALL(2); }

    BIOS_STUB(open, 0xB0, 0x32);

    BIOS_STUB(lseek, 0xB0, 0x33);

    BIOS_STUB(read, 0xB0, 0x34);

    BIOS_STUB(write, 0xB0, 0x35);

    BIOS_STUB(close, 0xB0, 0x36);

    BIOS_STUB(format, 0xB0, 0x41);

    BIOS_STUB(nextfile, 0xB0, 0x43);

    BIOS_STUB(erase, 0xB0, 0x45);

#endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", GetGp);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B4CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B668);

#if !(SKIP_ASM || M2CTX)
    BIOS_STUB(firstfile, 0xB0, 0x42);
#endif

u8* bcopy(u8* arg0, u8* arg1, s32 arg2)
{
    s32 var_a2;
    u8 temp_v0;
    u8* temp_v1;
    u8* var_a0;
    u8* var_a1;
    u8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_a2 = arg2;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        temp_v1 = var_a0;
        if (var_a2 > 0) {
            do {
                temp_v0 = *var_a0;
                var_a0 += 1;
                var_a2 -= 1;
                *var_a1 = temp_v0;
                var_a1 += 1;
            } while (var_a2 > 0);
        }
        var_v0 = temp_v1;
    }
    return var_v0;
}

s8* bzero(s8* arg0, s32 arg1)
{
    s32 var_a1;
    s8* var_a0;
    s8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        var_v0 = var_a0;
        if (var_a1 <= 0) {
            return NULL;
        }
        do {
            *var_a0 = 0;
            var_a1 -= 1;
            var_a0 += 1;
        } while (var_a1 > 0);
    }
    return var_v0;
}
