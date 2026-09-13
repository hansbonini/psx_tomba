#include "common.h"
#include "game.h"

#define D_8009B034 ((DISPENV*)((byte*)&D_8009B010+0x24))
#define D_8009B01C ((u_long*)((byte*)&D_8009B010+0xC))

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021340);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021B7C);
int func_80021B7C(void)
{
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021B84);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021BC4);
void func_80021BC4(int arg1, int arg2)
{
    func_80021D70((D_8007912C)[arg2]);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", startSoundTask);
void startSoundTask(void)
{
    *(byte* )0x1F8001CE = 0;
    openTask(2, &func_80021340);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021C24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80021D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800222B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800223A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800223E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800224FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800225B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800225F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022644);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022684);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800226B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800226D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002273C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800227A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002280C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228A4);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228C0);
void func_800228C0(u_short* id)
{
    ((u_int*)(id))[0x5] = (int)(((u_int*)(id))[0x5] + (((short*)(id))[0x41] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800228D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022908);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022924);
void func_80022924(short* id)
{
    ((u_int*)(id))[0x5] = (int) (((u_int*)(id))[0x5] + (((short*)(id))[0x3F] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002293C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002296C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_8002299C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800229CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_800229FC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A18);
void func_80022A18(u_short* id)
{
    ((u_short*)(id))[0x16] = ((u_short*)(id))[0x10];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/cdfile", func_80022B34);
