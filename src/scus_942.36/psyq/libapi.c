#include "common.h"
#include "psyq/kernel.h"

BIOS_STUB(FlushCache, 0xA0, 0x44)

BIOS_STUB(_bu_init, 0xA0, 0x70)

BIOS_STUB(OpenEvent, 0xB0, 0x8)

BIOS_STUB(CloseEvent, 0xB0, 0x9)

BIOS_STUB(TestEvent, 0xB0, 0xB)

BIOS_STUB(EnableEvent, 0xB0, 0xC)

BIOS_STUB(OpenTh, 0xB0, 0xE)

BIOS_STUB(CloseTh, 0xB0, 0xF)

BIOS_STUB(ChangeTh, 0xB0, 0x10)

void EnterCriticalSection() { SYSCALL(1) }

void ExitCriticalSection() { SYSCALL(2) }

BIOS_STUB(open, 0xB0, 0x32)

BIOS_STUB(lseek, 0xB0, 0x33)

BIOS_STUB(read, 0xB0, 0x34)

BIOS_STUB(write, 0xB0, 0x35)

BIOS_STUB(close, 0xB0, 0x36)

BIOS_STUB(format, 0xB0, 0x41)

BIOS_STUB(nextfile, 0xB0, 0x43)

BIOS_STUB(erase, 0xB0, 0x45)

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", GetGp);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B4CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", func_8005B668);

BIOS_STUB(firstfile, 0xB0, 0x42)

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", _bcopy);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi", _bzero);
