#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp10", func_8003C124);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp10", func_8003C5A4);
void func_8003C5A4(void)
{
    unkstruct_8009E458* p = D_8009E458;
    u8* script = D_8009C974;
    u8  op = script[p->pc];

    if (op < 0x80) {
        func_8003C124(op);
    } else {
        func_8003E408(op);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp10", func_8003C604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp10", func_8003C6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp10", func_8003C78C);
