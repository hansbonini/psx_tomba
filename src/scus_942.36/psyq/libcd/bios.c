#include "common.h"

extern s32 D_80096294;

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", getintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_sync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_ready);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_cw);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_vol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_flush);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initvol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_init);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_datasync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_getsector);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_set_test_parmnum);
void CD_set_test_parmnum(int arg0)
{
    D_80096294 = arg0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", callback);
