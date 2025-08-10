#include "common.h"
#include "game.h"
#include "psyq/libgte.h"
#include "psyq/libgpu.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800164FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016940);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016A00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016A18);

void func_80016AF4(void)
{
    extern s32 D_1F8000C0;
    extern s32 D_1F800118;
    RECT rect;

    SetGeomOffset(160, 112);
    SetGeomScreen(544);
    *(s16* )(PSX_SCRATCH + 0xF8) = 4096;
    *(s16* )(PSX_SCRATCH + 0xFA) = 0;
    *(s16* )(PSX_SCRATCH + 0xFC) = 0;
    *(s16* )(PSX_SCRATCH + 0xFE) = 0;
    *(s16* )(PSX_SCRATCH + 0x100) = 4096;
    *(s16* )(PSX_SCRATCH + 0x102) = 0;
    *(s16* )(PSX_SCRATCH + 0x104) = 0;
    *(s16* )(PSX_SCRATCH + 0x106) = 0;
    *(s16* )(PSX_SCRATCH + 0x108) = 4096;
    *(s32* )(PSX_SCRATCH + 0x114) = 0;
    *(s32* )(PSX_SCRATCH + 0x110) = 0;
    *(s32* )(PSX_SCRATCH + 0x10C) = 0;
    func_80024AEC(&D_1F8000C0);
    *(s16* )(PSX_SCRATCH + 0xE2) = 0;
    *(s16* )(PSX_SCRATCH + 0xE6) = 0;
    *(s16* )(PSX_SCRATCH + 0xEA) = -544;
    *(s16* )(PSX_SCRATCH + 0xEE) = 0;
    *(s16* )(PSX_SCRATCH + 0xF2) = 0;
    *(s16* )(PSX_SCRATCH + 0xF6) = 0;
    func_80024B3C(&D_1F800118);
    func_80016C4C(96, 151, 255);
    // Clear entire screen
    rect.w = 1024;
    rect.x = 0;
    rect.y = 0;
    rect.h = 512;
    ClearImage(&rect, 0, 0, 0);
    ClearOTagR(FRAMEBUFFER_OT, 808);
    ClearOTagR((u32)FRAMEBUFFER_OT + 0xD10, 808);
    
    *(s16*)(PSX_SCRATCH + 0x1F4) = 0;
    *(s32*)(PSX_SCRATCH + 0x1E0) = FRAMEBUFFER_OT;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016C4C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016F5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80016FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017024);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800170F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017154);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800171D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017208);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017258);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800172C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001731C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017348);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800173B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017418);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001745C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017498);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001758C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800177D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017AE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017CA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017CCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017F1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017F88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80017FB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018094);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800180C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800180F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001811C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800181F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001821C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800182C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018354);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800183E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018504);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018594);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800186E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001872C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800187D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018828);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001887C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800188D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001891C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018BC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018C04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018C40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018C8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018D04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018D40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018D7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018E58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80018F04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80019020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800191E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001964C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80019844);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800199B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80019CA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80019D78);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80019E68);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A328);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A51C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A670);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A774);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001A9F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001AC00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001AD1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001AD58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001B0A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001B2B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001B5A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001B780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001B944);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001BB1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001BF90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C104);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C2E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C75C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001C940);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001CA84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001CB54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001CE80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001CF7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001CFCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D29C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D2F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D668);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001DE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001DFD4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001E118);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001E220);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001E31C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001E3D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001EA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001ECD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001EFE8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F158);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F1C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F4D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F5D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F634);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001F6D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FAE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FCE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FD20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FD80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FDC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FE60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FF28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8001FFE8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800200EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800204E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002059C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800205C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002065C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002067C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800206A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020778);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020CB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80020FAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800210A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021148);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800211A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021340);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021B7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021B84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021BC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021BF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021C24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80021D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800222B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800223A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800223E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800224B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800224CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800224FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800225B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800225F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022644);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022684);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800226B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800226D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002273C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800227A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002280C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800228A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800228C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800228D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022908);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022924);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002293C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002296C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002299C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800229CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800229FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022A18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022A24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022C08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022D3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022F6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80022FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800230BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023168);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002331C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002337C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800233B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002367C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800236F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023840);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800238B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023928);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023A3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023AA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023CE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80023ED0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024254);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800242AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800243E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002467C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800246B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024AA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024AEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024BD4);

void func_80024CE4(void) {
}

void func_80024CEC(void) {
}

void func_80024CF4(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024CFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80024EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800251C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800253C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002564C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80025810);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80025A38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80025C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80025E74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002601C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80026228);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800263F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80026694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80026E48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80027600);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800279E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80027A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028728);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800287F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800288C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028A74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028CE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80028EF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002907C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029548);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029788);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029944);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029A84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029B20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029BD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029C48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80029CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A0A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A240);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A31C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A334);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A798);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002A9FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002ABC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002AD74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002AF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002AF8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002AFFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B06C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B278);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B664);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B6A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002B704);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002BAB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002BB9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002C7D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CB58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CC20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CD7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CEF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002CFF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D4C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D534);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D5AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D660);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D69C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D6D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D784);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002D9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002DA2C);

void func_8002DB34(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002DB3C);

void func_8002DBD0(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002DBD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002DEC4);

void func_8002E3A8(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002E3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002E404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002E494);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002E964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002EB3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002EB80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002EBC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002ED1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002EF20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F05C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F138);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F220);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F56C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F7C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002F948);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8002FA24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80030734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003076C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800307AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800307D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80030800);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80030A54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80030E30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80030EF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031628);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800316EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031868);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031908);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031B18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031C90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031F00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80031F88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80032230);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800322A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80032374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800324B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800325C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800327D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80032934);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80032DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003301C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800330EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800332CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033488);

void func_80033858(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033860);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800338A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033F50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033FB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80033FF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800340FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800341AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003438C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80034420);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80034524);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800346A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003473C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003481C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800348FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800349DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80034AB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80034C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036440);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036494);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800365DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800369BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036A28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036A8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036C88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036DB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036DF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80036F98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80038358);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800383AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800384F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80038570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800385EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80038748);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003887C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80038AC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A10C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A384);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A4F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003A8A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B214);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B26C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B2C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B410);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B478);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B4A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B4D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B510);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B574);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B5D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B68C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B6E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B750);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B860);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003B968);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BA00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BA60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BA94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BB48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BF18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003BF58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D0E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D1B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D20C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D25C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D5F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D648);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D72C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D77C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D7CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D824);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D8EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D920);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D950);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D9C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003D9F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DA28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DA9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DB04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DB70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DC38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DCF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DE90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DEBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DF10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DF3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DF88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DFCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003DFF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E014);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E0A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E0E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E12C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E1A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E1F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E298);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E2E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E30C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E330);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E3C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003E408);

void LZDecompress(byte *src, byte *dest)
{
    uint length;
    byte offset;
    int next_bitmask;
    src += 4;

    READ32(LZ_FILE_CTRL->size, src);
    READ16(LZ_BITMASK, src);
    LZ_CURRENT_BIT = 0;
    LZ_FILE_CTRL->offset = 0;

    do {
        if (((LZ_BITMASK >> LZ_CURRENT_BIT) & 1)) {
            u8 off, len;
            off = *src++;
            len = *src++;
            _bcopy(dest - off, dest, len);
            dest += len;
            LZ_FILE_CTRL->offset += len;
        }
        else {
            *dest++ = *src++;
            LZ_FILE_CTRL->offset += 1;
        }
        LZ_CURRENT_BIT++;

        if ( LZ_CURRENT_BIT > 15) next_bitmask=1;
        else if ( LZ_CURRENT_BIT > 15) next_bitmask=1;
        else LZ_CURRENT_BIT= 0;
        
        if (next_bitmask) {
            READ16(LZ_BITMASK, src);
            LZ_CURRENT_BIT = 0;
        }
    } while (LZ_FILE_CTRL->size > LZ_FILE_CTRL->offset);

    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F0DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F1D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F268);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F3D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003F9A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003FC18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8003FDD4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004008C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800400E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040268);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004035C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800403E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800404E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040564);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800405C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004062C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040690);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040718);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004080C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004095C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800409CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040B28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040B98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040C0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040E24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80040FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041048);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800410D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004117C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041754);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041790);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800417CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041820);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800418C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041904);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041940);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041D24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041D6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80041DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042104);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042204);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042478);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042598);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042654);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042978);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800429EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042C20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80042FE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800431CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004339C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800436CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043740);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043AB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043D2C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80043F14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80044050);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80044184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800442FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800443CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80044620);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80044694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800448D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80044B0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800450FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045174);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800458B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800459E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045AF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045BA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045C54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045D0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80045EFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80046264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004637C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80046428);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80046CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80046EC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80047FC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800487A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80048BF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80049134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80049994);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004A300);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004A6A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004AA70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004AD8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004AFAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004B450);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004BDE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004C1E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004C258);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004CC84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004CFE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D0C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D1A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D448);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D5F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D7E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004D91C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004DA28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004DB3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004DC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004DD14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004DFA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E244);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E590);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004E900);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004EB10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004ED80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004EFA8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004F24C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004F2CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004F3DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004F510);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004F5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004FB54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004FD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8004FE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800505B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800505E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800508E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800509F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050AD0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050BBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050C94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050D80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050EA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80050FE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051090);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051488);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051A18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051C98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051DA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80051EE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052100);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800521E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800522B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800522D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052350);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005242C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052558);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800526E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800527C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800529A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052B88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052D5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80052F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800530F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800532B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005334C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053588);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005368C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053808);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800539E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053A1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053A58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053B30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053B94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053BB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053D14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80053F08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80054618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80054D60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005548C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80055A44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80055BA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80055E0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80055ED4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005606C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056498);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800566E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056970);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056BBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056C84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056CD4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056D24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056E00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80056F94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80057044);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80057188);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800574BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800577F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005788C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80057C3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80057C74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800580BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80058464);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80058960);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80058E14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_800593EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059514);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005975C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059A40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059B1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059B58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_80059F7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A074);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A108);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A148);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A508);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A660);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005A7E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005AA98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005AF70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005B1A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005B1F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main_loop", func_8005B350);
