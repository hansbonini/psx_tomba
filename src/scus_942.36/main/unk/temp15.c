#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80057C3C);
void func_80057C3C(u8* self, s16 arg1)
{
    *(s16*)(self + 0xAC) = arg1;
    *(s32*)(self + 0x24) =
        *(s32*)(*(u8**)(self + 0xA8) + arg1 * 4);
    func_800229FC(self);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80057C74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_800580BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80058464);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80058960);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80058E14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_800593EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059514);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005975C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059A40);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059B1C);
void func_80059B1C(void)
{
    if (GAME.selectedArea == 0) {
        func_80125C84();
    } else {
        func_8011F188();
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059B58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_80059F7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A074);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A108);
void func_8005A108(u8 arg0)
{
    u8* p = func_80018694();

    if (p != NULL) {
        p[0] = 1;
        p[2] = arg0;
        func_8005A184(p);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A148);
void func_8005A148(u8 arg0)
{
    u8* p = func_80018694();

    if (p != NULL) {
        p[0] = 1;
        p[2] = arg0;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A508);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A660);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005A7E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005AA98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005AF70);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005B1A4);
void func_8005B1A4(u8* self)
{
    if (self[4] == 0) {
        *(s16*)(self + 0xC) = GAME.selectedArea;
        self[0xE] = D_8009BCCA;
        self[4] = self[4] + 1;
        func_8005B1F8(self);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005B1F8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/unk/temp15", func_8005B350);
void func_8005B350(u8* self)
{
    (&D_8007F988)[self[3]]();
}

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800151E0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015578);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015590);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800155A4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800155BC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800155D4);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800155DC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015600);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015624);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_8001562C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015634);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015654);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_8001565C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015664);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_8001566C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015674);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_8001567C);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800156A0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800156A8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800156CC);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800156F0);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_800156F8);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015700);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015708);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015710);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015718);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015720);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/unk/temp15", D_80015728);
