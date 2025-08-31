#include "common.h"
#include "psyq/kernel.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", FlushCache);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(FlushCache, 0xA0, 0x44);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", _bu_init);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(_bu_init, 0xA0, 0x70);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", OpenEvent);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(OpenEvent, 0xB0, 0x8);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", CloseEvent);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(CloseEvent, 0xB0, 0x9);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", TestEvent);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(TestEvent, 0xB0, 0xB);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", EnableEvent);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(EnableEvent, 0xB0, 0xC);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", OpenTh);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(OpenTh, 0xB0, 0xE);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", CloseTh);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(CloseTh, 0xB0, 0xF);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", ChangeTh);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(ChangeTh, 0xB0, 0x10);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", EnterCriticalSection);
// #if !(SKIP_ASM || M2CTX)
//     void EnterCriticalSection() { SYSCALL(1); }
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", ExitCriticalSection);
// #if !(SKIP_ASM || M2CTX)
//     void ExitCriticalSection() { SYSCALL(2); }
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", open);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(open, 0xB0, 0x32);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", lseek);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(lseek, 0xB0, 0x33);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", read);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(read, 0xB0, 0x34);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", write);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(write, 0xB0, 0x35);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", close);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(close, 0xB0, 0x36);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", format);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(format, 0xB0, 0x41);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", nextfile);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(nextfile, 0xB0, 0x43);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", erase);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(erase, 0xB0, 0x45);
// #endif

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", GetGp);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B4CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B668);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", firstfile);
// #if !(SKIP_ASM || M2CTX)
//     BIOS_STUB(firstfile, 0xB0, 0x42);
// #endif

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
