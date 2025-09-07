#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", main);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016940);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016A00);
void func_80016A00(short id, short arg1)
{
    *(short* )&PSX_SCRATCH[0x1EA] = id;
    *(short* )&PSX_SCRATCH[0x1EC] = arg1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016A18);
void func_80016A18(void)
{
    D_8009EB5A = 0xFFFF;
    D_8009EB7C = 0xFFFF;
    *(u_char* )&PSX_SCRATCH[0x3D3] = 0xFF;
    *(u_char* )&PSX_SCRATCH[0x3D2] = 0xFF;
    *(short* )&PSX_SCRATCH[0x1F0] = 0;
    *(short* )&PSX_SCRATCH[0x1F2] = 0;
    *(short* )&PSX_SCRATCH[0x1EE] = 0;
    *(short* )&PSX_SCRATCH[0x1F6] = 0;
    *(short* )&PSX_SCRATCH[0x1F8] = 0;
    *(char* )&PSX_SCRATCH[0x1CC] = 0;
    *(char* )&PSX_SCRATCH[0x1D0] = 0;
    *(char* )&PSX_SCRATCH[0x1D1] = 0;
    *(char* )&PSX_SCRATCH[0x1CE] = 0;
    *(char* )&PSX_SCRATCH[0x1CF] = 0;
    *(char* )&PSX_SCRATCH[0x1D3] = 0;
    *(short* )&PSX_SCRATCH[0x1C6] = 0;
    *(char* )&PSX_SCRATCH[0x1C4] = 0;
    *(char* )&PSX_SCRATCH[0x1C5] = 0;
    *(char* )&PSX_SCRATCH[0x3CC] = 0;
    D_8009C9DA = 0;
    D_8009C9DE = 0;
    D_8009C940 = 0;
    D_8009EB52 = 0;
    D_8009C864 = 0;
    D_8009C866 = 8;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016AF4);
void func_80016AF4(void)
{
    RECT rect;

    SetGeomOffset(160, 112);
    SetGeomScreen(544);
    (*(MATRIX*)(&D_1F8000F8)).m[0][0] = 0x1000;
    (*(MATRIX*)(&D_1F8000F8)).m[0][1] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[0][2] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[1][0] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[1][1] = 0x1000;
    (*(MATRIX*)(&D_1F8000F8)).m[1][2] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[2][0] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[2][1] = 0;
    (*(MATRIX*)(&D_1F8000F8)).m[2][2] = 0x1000;
    (*(MATRIX*)(&D_1F8000F8)).t[2] = 0;
    (*(MATRIX*)(&D_1F8000F8)).t[1] = 0;
    (*(MATRIX*)(&D_1F8000F8)).t[0] = 0;
    func_80024AEC((MATRIX*)(&D_1F8000C0));
    *(short* )&PSX_SCRATCH[0xE2] = 0;
    *(short* )&PSX_SCRATCH[0xE6] = 0;
    *(short* )&PSX_SCRATCH[0xEA] = -0x220;
    *(short* )&PSX_SCRATCH[0xEE] = 0;
    *(short* )&PSX_SCRATCH[0xF2] = 0;
    *(short* )&PSX_SCRATCH[0xF6] = 0;
    func_80024B3C((MATRIX*)(&D_1F800118));
    func_80016C4C(96U, 151U, 255U);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage(&rect, 0U, 0U, 0U);
    ClearOTagR(&OT_FRAMEBUFFER, 0x328);
    ClearOTagR(&OT_FRAMEBUFFER + 0x344, 0x328);
    *(short* )&PSX_SCRATCH[0x1F4] = 0;
    *(u_int** )&PSX_SCRATCH[0x1E0] = &OT_FRAMEBUFFER;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016C4C);
void func_80016C4C(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = &D_8009D6C4;
    SetDefDrawEnv(drawenv1, 384, 256, 320, 224);
    dispenv1 = &D_8009D6C4 - 0x5;
    SetDefDispEnv(dispenv1, 704, 256, 320, 224);
    drawenv2 = (&D_8009D6C4 + 0x344);
    SetDefDrawEnv(drawenv2, 704, 256, 320, 224);
    dispenv2 = (&D_8009D6C4 + 0x344)-0x5;
    SetDefDispEnv(dispenv2, 384, 256, 320, 224);
    dispenv1->screen.w = 256;
    dispenv1->screen.h = 224;
    dispenv2->screen.h = 224;
    dispenv2->screen.w = 256;
    drawenv2->isbg = true;
    drawenv1->isbg = true;
    drawenv2->dtd = true;
    drawenv1->dtd = true;
    drawenv2->dfe = false;
    drawenv1->dfe = false;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    dispenv1->screen.x = D_8009C864;
    dispenv1->screen.y = D_8009C866;
    dispenv2->screen.x = D_8009C864;
    dispenv2->screen.y = D_8009C866;
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016DDC);
void func_80016DDC(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = &D_8009D6C4;
    SetDefDrawEnv(drawenv1, 384, 0, 640, 480);
    dispenv1 = &D_8009D6C4 - 0x5;
    SetDefDispEnv(dispenv1, 384, 0, 640, 480);
    drawenv2 = (&D_8009D6C4 + 0x344);
    SetDefDrawEnv(drawenv2, 384, 0, 640, 480);
    dispenv2 = (&D_8009D6C4 + 0x344)-0x5;
    SetDefDispEnv(dispenv2, 384, 0, 640, 480);
    dispenv1->screen.x = 0;
    dispenv1->screen.y = 0;
    dispenv1->screen.w = 256;
    dispenv1->screen.h = 240;
    dispenv2->screen.h = 240;
    dispenv2->screen.x = 0;
    dispenv2->screen.y = 0;
    dispenv2->screen.w = 256;
    drawenv2->isbg = true;
    drawenv1->isbg = true;
    drawenv2->dtd = true;
    drawenv1->dtd = true;
    drawenv2->dfe = true;
    drawenv1->dfe = true;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016F5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017024);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800170F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017154);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800171D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017208);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017258);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800172C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001731C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017348);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800173B0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017418);
void func_80017418(unkstruct_01* arg0, int arg1)
{
    DrawSync(0);
    arg0->unk0 = arg1;
    arg0->saved_reg_gp = GetGp();
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001745C);
void func_8001745C(u_long* p, short x, short y, short w, short h)
{
    RECT rect;
    setRECT(&rect, x, y, w, h);
    LoadImage(&rect, p);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017498);
void func_80017498(u_long* address, short x, short y, short x2, short y2)
{
    TIM_IMAGE tim;
    TIM_IMAGE *pTim;

    pTim= &tim;
    
    if (OpenTIM(address)) {
        return;
    }
    
    if (ReadTIM(pTim) == NULL) {
        return;
    }
    
    pTim->prect->x = x;
    pTim->prect->y = y;
    pTim->crect->x = x2;
    pTim->crect->y = y2;

    if (((pTim->mode & 8) != 0) && ((x2 << 0x10) >= 0)) {
        LoadImage(pTim->crect, pTim->caddr);
    }

    if ((x << 0x10) >= 0) {
        LoadImage(pTim->prect, pTim->paddr);
    }
    
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001758C);
void func_8001758C(void)
{
    func_80017CA0();
    func_80017D70();
    func_80017E44();
    func_80017EEC();
    func_80017F1C();
    func_80017F88();
    func_80017FB8();
    func_80018094();
    func_800180F0();
    func_8001811C();
    func_800180C4();
    func_80017CCC();
    func_800181F0();
    func_8001821C();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800177D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017AE0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017CA0);
void func_80017CA0(void)
{
    memset(&D_800A5398, 0, 0x178);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017CCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017E44);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017EEC);
void func_80017EEC(void)
{
    *(int* )0x1F80021C = &D_800A5970;
    *(int* )0x1F800260 = &D_800A5970;
    *(short* )0x1F800250 = 0;
    *(short* )0x1F800246 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017F1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017F88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017FB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018094);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180F0);
void func_800180F0(void)
{
    memset(&D_800B00F8, 0, 0x16C);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001811C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800181F0);
void func_800181F0(void)
{
    memset(&D_800B0770, 0, 0x68);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001821C);
void func_8001821C(void)
{
    memset(&D_800A3940, 0, 0x70);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800182C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018354);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800183E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018504);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018594);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800186E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001872C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800187D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018828);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001887C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800188D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001891C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018BC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018E58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018F04);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019020);
void func_80019020(void)
{
    EnterCriticalSection();
    D_8009E474 = OpenEvent(0xF4000001, 4, 0x2000, 0);
    D_8009E478 = OpenEvent(0xF4000001, 0x8000, 0x2000, 0);
    D_8009E47C = OpenEvent(0xF4000001, 0x100, 0x2000, 0);
    D_8009E480 = OpenEvent(0xF4000001, 0x2000, 0x2000, 0);
    D_8009E45C = OpenEvent(0xF0000011, 4, 0x2000, 0);
    D_8009E460 = OpenEvent(0xF0000011, 0x8000, 0x2000, 0);
    D_8009E464 = OpenEvent(0xF0000011, 0x100, 0x2000, 0);
    D_8009E468 = OpenEvent(0xF0000011, 0x2000, 0x2000, 0);
    InitCARD(0);
    ExitCriticalSection();
    StartCARD();
    _bu_init();
    EnableEvent(D_8009E474);
    EnableEvent(D_8009E478);
    EnableEvent(D_8009E47C);
    EnableEvent(D_8009E480);
    EnableEvent(D_8009E45C);
    EnableEvent(D_8009E460);
    EnableEvent(D_8009E464);
    EnableEvent(D_8009E468);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800191E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001964C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019844);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800199B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019CA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019D78);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019E68);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A328);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A51C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A670);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A774);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A9F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001AC00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001AD1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001AD58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001B0A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001B2B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001B5A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001B780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001B944);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001BB1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001BF90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C104);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C2E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C75C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001C940);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001CA84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001CB54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001CE80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001CF7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001CFCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D29C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D2F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D668);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001DE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001DFD4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E118);
u_char func_8001E118(EVENT event_id, int arg1, int arg2)
{
    if (arg1 == 0) {
        func_80029548(*(&D_80077520 + (*(&D_80077540 + event_id) * 1)));
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, arg2);
            func_8001ECD8(event_id, 0);
            func_8001FFE8(0x2A);
            func_8002E3B0(0);
        }
    } else {
        func_80029548(*(&D_80077520 + (*(&D_80077608 + event_id) * 1)));
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, arg2);
            func_8001ECD8(event_id, 1);
            func_80020DDC(2);
            func_80021110();
        }
    }
    return EVENT_LIST[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E220);
u_char func_8001E220(EVENT event_id, int arg1, int arg2)
{
    if (EVENT_LIST[event_id] == 0) {
        if (event_id == 1) {
            if (SELECTED_AREA == 0) {
                EVENT_LIST[event_id] += 1;
            }
        } else {
            EVENT_LIST[event_id] += 1;
        }
        func_80029548((&D_80077520)[(&D_80077540)[event_id]]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 0, 0x3C, arg2);
            func_8001ECD8(event_id, 0);
            func_8001FFE8(0x2A);
            func_8002E3B0(0);
        }        
    }
    return EVENT_LIST[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E31C);
u_char func_8001E31C(EVENT event_id, int arg1)
{
    int index;
    if (EVENT_LIST[event_id] != 0xFF) {
        index = (&D_80077608)[event_id];
        asm("");
        EVENT_LIST[event_id] = 0xFF;
        asm("");
        func_80029548((&D_80077520)[index]);
        if (event_id != EVENT_TALEOFTHEEVILPIGS) {
            func_8001E3EC(event_id, 1, 1, arg1);
            func_8001ECD8(event_id, 1);
            func_80020DDC(2);
            func_80021110();
        }
    }
    return EVENT_LIST[event_id];
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E3D8);
u_char func_8001E3D8(EVENT event_id)
{
    return EVENT_LIST[event_id];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001EA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001ECD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001EFE8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F158);
void func_8001F158(short file_id)
{
    if (CdControl(2, (*(&D_80078F80 + (*(&D_8007775C[file_id]) * 1)) * 2) + &D_800791A0, 0) != 0) {
        CdControlF(0x15, 0);
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F1C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F4D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F5D0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F634);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001F6D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FAE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FCE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FD20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FD80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FDC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FE60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FF28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001FFE8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020058);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800200EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020434);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800204E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002059C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800205C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002065C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002067C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800206A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020778);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020CB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020DDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80020FAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800210A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021148);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021180);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800211A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021340);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021B7C);
int func_80021B7C(void)
{
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021B84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021BC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021BF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021C24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80021D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800222B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800223A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800223E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022474);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800224B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800224CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800224FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800225B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800225F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022644);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022684);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800226B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800226D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002273C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800227A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002280C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800228A4);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800228C0);
void func_800228C0(u_short* id)
{
    ((u_int*)(id))[0x5] = (int)(((u_int*)(id))[0x5] + (((short*)(id))[0x41] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800228D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022908);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022924);
void func_80022924(short* id)
{
    ((u_int*)(id))[0x5] = (int) (((u_int*)(id))[0x5] + (((short*)(id))[0x3F] << 8));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002293C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002296C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002299C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800229CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800229FC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001E3D8);
void func_80022A18(u_short* id)
{
    ((u_short*)(id))[0x16] = ((u_short*)(id))[0x10];
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022A24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022A50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022C08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022D3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022F6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80022FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800230BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023168);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002331C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002337C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800233B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002367C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800236F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023840);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800238B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023928);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023A3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", FontDebugPrintf);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023CE0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023E44);
void func_80023E44(short arg0)
{
    int graphType = GetGraphType();
    int val = 0x24;
    if (graphType != 1) {
        graphType = GetGraphType();
        asm("");
        if (graphType == 2) {
            val = 0x24;
        } else {
            val = 0x14;   
        }
    }
    func_80024008(0x68, 0x60, 1, val, arg0);
    func_80024008(0xA0, 0x60, 2, val, arg0);
    return;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80023ED0);
void func_80023ED0(short x, short y, short sprt_id)
{   
    u_int sprt_ofs;
    int* ot;
    SPRT* sprt;

    sprt = D_8009C8A8;
    setlen(sprt, 4),
    setcode(sprt, 0x65); // which type is? SPRT = 0x64
    setRGB0(sprt, 128, 128, 128);
    sprt_ofs = sprt_id * 0x3;
    setXY0(sprt, x, y);
    sprt->code = (u_char) (sprt->code & 0xFD);
    setUV0(sprt, *(u_short*)&D_8007B2F4[sprt_ofs], *(u_short*)(&D_8007B2F6[sprt_ofs]));
    setWH(sprt, *(u_short*)(&D_8007B2F8[sprt_ofs]), *(u_short*)(&D_8007B2FA[sprt_ofs]));
    setClut(sprt, (short) *(&D_8007B2FC[sprt_ofs]), (short) *(&D_8007B2FE[sprt_ofs]));
    addPrim(*(u_long*)(0x1F8001E0), sprt);
    D_8009C8A8 += sizeof(SPRT);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024254);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800242AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800243E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002467C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800246B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024AA8);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024AEC);
void func_80024AEC(MATRIX* dst)
{
    *dst=*(MATRIX*)(&D_1F8000F8);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024BD4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024CE4);
void func_80024CE4(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024CEC);
void func_80024CEC(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024CF4);
void func_80024CF4(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024CFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80024EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800251C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800253C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002564C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80025810);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80025A38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80025C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80025E74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002601C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80026228);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800263F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80026694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80026E48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80027600);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800279E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80027A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028728);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800287F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800288C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028A74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028CE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80028EF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002907C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029548);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029788);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029944);
int func_80029944(ITEM id, int qty)
{
    int i;
    for (i = 0; i < *INVENTORY_SLOT_COUNTER; i++) {
        if (INVENTORY_SLOT[i] == id) {
            if (qty == -1) {
                ITEM_LIST[id] = 0;
                while (i < *INVENTORY_SLOT_COUNTER - 1) {
                    INVENTORY_SLOT[i] = INVENTORY_SLOT[i+1];
                    i++;
                }
                *INVENTORY_SLOT_COUNTER -= 1;
                return 0;
            }
            ITEM_LIST[id] = ITEM_LIST[id] - qty;
            if (ITEM_LIST[id] == 0) {
                ITEM_LIST[id] = 0;
                while (i < *INVENTORY_SLOT_COUNTER - 1) {
                    INVENTORY_SLOT[i] = INVENTORY_SLOT[i+1];
                    i++;
                }
                *INVENTORY_SLOT_COUNTER -= 1;
                return 0;
            }
            return ITEM_LIST[id];
        }
    }
    return -1;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029A84);
u_int func_80029A84(void)
{
    if (D_8009C3E7 == 0) {
        if (PLAYER_HEALTH_DISPLAYED < 8) {
            PLAYER_HEALTH_DISPLAYED++;
        } else {
            D_8009C3E8++;
        }
    } else {
        if (PLAYER_HEALTH_DISPLAYED < 16) {
            PLAYER_HEALTH_DISPLAYED++;
        }
    }

    PLAYER_HEALTH = D_800A5432 = D_800A5430 = PLAYER_HEALTH_DISPLAYED;
    return PLAYER_HEALTH_DISPLAYED;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029B20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029BD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029C48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029C80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80029CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A0A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A240);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A31C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A334);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A480);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A798);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002A9FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002ABC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002AD74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002AF44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002AF8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002AFFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B06C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B110);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B278);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B664);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B6A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002B704);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002BAB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002BB9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002C7D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CA40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CB58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CC20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CD7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CEF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002CFF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D4C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D534);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D5AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D660);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D69C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D6D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D784);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002D9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DA2C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DB34);
void func_8002DB34(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DB3C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DBD0);
void func_8002DBD0(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DBD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002DEC4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002E3A8);
void func_8002E3A8(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002E3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002E404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002E494);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002E964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002EB3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002EB80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002EBC4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002ED1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002EF20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F05C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F138);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F220);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F56C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F7C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002F948);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8002FA24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80030734);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003076C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800307AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800307D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80030800);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80030A54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80030E30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80030EF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031628);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800316EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031868);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031908);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031B18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031C90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031F00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80031F88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80032230);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800322A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80032374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800324B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800325C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800327D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80032934);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80032DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003301C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800330EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800332CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033374);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033404);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033488);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033858);
void func_80033858(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033860);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800338A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033964);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033F50);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033FB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80033FF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800340FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800341AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003438C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80034420);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80034524);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800346A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003473C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003481C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800348FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800349DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80034AB8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80034C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036440);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036494);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800365DC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800369BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036A28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036A8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036C88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036DB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036DF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80036F98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80038358);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800383AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800384F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80038570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800385EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80038748);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003887C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80038AC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A10C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A384);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A4F8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A604);
void func_8003A604(int id)
{
    D_8007D6A0 = id;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A614);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003A8A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B0D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B214);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B26C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B2C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B410);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B478);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B4A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B4D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B510);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B574);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B5D8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B68C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B6E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B750);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B860);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003B968);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BA00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BA60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BA94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BB48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BF18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003BF58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D0E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D1B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D20C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D25C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D5F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D648);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D72C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D77C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D7CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D824);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D8EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D920);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D950);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D9C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003D9F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DA28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DA9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DB04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DB70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DC38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DCF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DE90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DEBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DF10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DF3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DF88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DFCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003DFF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E014);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E0A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E0E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E12C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E1A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E1F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E298);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E2E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E30C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E330);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E3C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003E408);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", LZDecompress);
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
            u_char off, len;
            off = *src++;
            len = *src++;
            bcopy(dest - off, dest, len);
            dest += len;
            LZ_FILE_CTRL->offset += len;
        }
        else {
            *dest++ = *src++;
            LZ_FILE_CTRL->offset += 1;
        }
        LZ_CURRENT_BIT++;

        if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else if ( LZ_CURRENT_BIT > 15) next_bitmask = 1;
        else next_bitmask = 0;
        
        if (next_bitmask) {
            READ16(LZ_BITMASK, src);
            LZ_CURRENT_BIT = 0;
        }
    } while (LZ_FILE_CTRL->size > LZ_FILE_CTRL->offset);
    
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F0DC);
void func_8003F0DC(char* src, char* dst, char* len)
{
    bzero(dst, len);
    LZDecompress(src, dst);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F124);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F1D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F268);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F3D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F78C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003F9A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003FC18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8003FDD4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004008C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800400E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040268);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004035C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800403E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800404E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040564);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800405C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004062C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040690);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040718);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004080C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004095C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800409CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040B28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040B98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040C0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040E24);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80040FD8);
void func_80040FD8(void* arg0)
{
    func_8001E31C(EVENT_ASAFEMUSHROOM, 0);
    func_80029788(*(u_char*)(arg0+3), 1, 1);
    if (!(*(u_char*)(arg0+0xC) & 0x80)) {
        func_8002367C(*(u_char*)(arg0+0x6B));
    }
    *(u_char*)(arg0+4)= (u_char) (*(u_char*)(arg0+4) + 1);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041048);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800410D8);
void func_800410D8(unkstruct_00* arg0)
{   
    if (ITEM_LIST[ITEM_JUMPINGPANTS] == 0) {
        func_80029788(ITEM_JUMPINGPANTS, 1, 1);
    } else if ((ITEM_LIST[ITEM_DASHINGPANTS] == 0)) {
        func_80029788(ITEM_DASHINGPANTS, 1, 1);
    } else if (ITEM_LIST[ITEM_FLASHPANTS] == 0) {
        func_80029788(ITEM_FLASHPANTS, 1, 1);
    }
    func_8001FFE8(0xA);
    if (!(arg0->field_C & 0x80)) {
        func_8002367C(arg0->field_6B);
    }
    arg0->field_4++;
}


INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004117C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041754);
void func_80041754(short id, short arg1, int arg2)
{
    func_80041940(0, id, arg1, arg2, 0, 0);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041790);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800417CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041820);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800418C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041904);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041940);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041D24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041D6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80041DB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042104);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042204);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042478);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042598);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042610);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042654);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042978);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800429EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042C20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80042FE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800431CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004339C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800436CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043740);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043AB0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043D2C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80043F14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80044050);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80044184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800442FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800443CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80044620);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80044694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800448D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80044B0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800450FC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045174);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045310);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800458B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800459E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045AF8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045BA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045C00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045C54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045D0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80045EFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80046264);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004637C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80046428);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80046CDC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80046EC0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80047FC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800487A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80048BF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80049134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80049994);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004A300);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004A6A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004AA70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004AD8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004AFAC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004B450);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004BDE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004C1E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004C258);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004CC84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004CFE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D0C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D1A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D448);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D5F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D7E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004D91C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004DA28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004DB3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004DC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004DD14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004DFA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E244);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E590);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004E900);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004EB10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004ED80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004EFA8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004F24C);
void func_8004F24C(short tpage, int p) {
    typedef inline struct {
        u_char pad[0x164];
        int nextprim;
        u_char pad2[0x78];
        int ot;
    } scratchpad;
    
    scratchpad* scratch = PSX_SCRATCH;
    DR_MODE* mode = scratch->nextprim;

    SetDrawMode(mode, 0, 0, tpage, 0);
    AddPrim(scratch->ot + (p * 4),mode);
    scratch->nextprim += sizeof(DR_MODE);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004F2CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004F3DC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004F510);
void func_8004F510(short* p, u_char r0, u_char g0, u_char b0)
{
    typedef inline struct {
        u_char pad[0x164];
        int nextprim;
        u_char pad2[0x78];
        int ot;
    } scratchpad;
    
    scratchpad* scratch  = PSX_SCRATCH;
    TILE* tile = scratch->nextprim;
    u_long *ot;

    setTile(tile);
    setRGB0(tile, r0, g0, b0);
    setXY0(tile, p[0], p[1]);
    tile->w = (u_short)p[2];
    ot = scratch->ot+4;
    tile->h = (u_short)p[3];
    AddPrim(ot, tile);
    scratch->nextprim += sizeof(TILE);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004F5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004FB54);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004FD28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8004FE24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800505B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800505E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800508E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800509F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050AD0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050BBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050C94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050D80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050EA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80050FE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051090);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051488);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051604);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051A18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051C98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051DA4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80051EE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052100);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800521E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800522B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800522D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052350);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005242C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052558);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800526E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800527C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800529A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052B88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052D5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80052F20);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800530F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800532B4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005334C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053588);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005368C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053808);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800539E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053A1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053A58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053AF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053B30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053B94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053BB4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053D14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053DA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80053F08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80054618);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80054D60);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005548C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80055A44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80055BA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80055E0C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80055ED4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005606C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056284);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056498);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800566E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056804);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056970);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056BBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056C84);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056CD4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056D24);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056E00);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80056F94);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80057044);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80057188);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800574BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800577F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005788C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80057C3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80057C74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800580BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80058464);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80058960);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80058E14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800593EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059514);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005975C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059A40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059B1C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059B58);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80059F7C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A074);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A108);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A148);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A184);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A3B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A508);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A660);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005A7E0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005AA98);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005AF70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005B1A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005B1F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8005B350);
