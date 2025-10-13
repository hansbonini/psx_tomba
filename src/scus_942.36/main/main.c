#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", main);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016940);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016A00);
void func_80016A00(short id, short arg1)
{
    typedef inline struct {
        byte data[0x1EA];
        short unk1EA;
        short unk1EC;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;

    scratch->unk1EA = id;
    scratch->unk1EC = arg1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016A18);
void func_80016A18(void)
{
    typedef inline struct {
        byte data[0x1C4];
        char unk1C4;
        char unk1C5;
        short unk1C6;
        char pad[4];
        char unk1CC;
        char unk1CD;
        char unk1CE;
        char unk1CF;
        char unk1D0;
        char unk1D1;
        char unk1D2;
        char unk1D3;
        byte pad1[0x12];
        short unk1E6;
        short unk1E8;
        short unk1EA;
        short unk1EC;
        short unk1EE;
        short unk1F0;
        short unk1F2;
        short unk1F4;
        short unk1F6;
        short unk1F8;
        byte pad3[0x1D2];
        u_char unk3CC;
        byte pad4[0x5];
        u_char unk3D2;
        u_char unk3D3;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    
    D_8009EB5A = 0xFFFF;
    D_8009EB7C = 0xFFFF;
    scratch->unk3D3 = 0xFF;
    scratch->unk3D2 = 0xFF;
    scratch->unk1F0 = 0;
    scratch->unk1F2 = 0;
    scratch->unk1EE = 0;
    scratch->unk1F6 = 0;
    scratch->unk1F8 = 0;
    scratch->unk1CC = 0;
    scratch->unk1D0 = 0;
    scratch->unk1D1 = 0;
    scratch->unk1CE = 0;
    scratch->unk1CF = 0;
    scratch->unk1D3 = 0;
    scratch->unk1C6 = 0;
    scratch->unk1C4 = 0;
    scratch->unk1C5= 0;
    scratch->unk3CC = 0;
    D_8009C9DA = 0;
    D_8009C9DE = 0;
    D_8009C940 = 0;
    D_8009EB52 = 0;
    D_8009C864 = 0;
    D_8009C866 = 8;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016AF4);
void func_80016AF4(void)
{
    RECT rect;
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    MATRIX* matrix = (MATRIX*)0x1F8000F8;

    SetGeomOffset(160, 112);
    SetGeomScreen(544);
    matrix->m[0][0] = 4096;
    matrix->m[0][1] = 0;
    matrix->m[0][2] = 0;
    matrix->m[1][0] = 0;
    matrix->m[1][1] = 4096;
    matrix->m[1][2] = 0;
    matrix->m[2][0] = 0;
    matrix->m[2][1] = 0;
    matrix->m[2][2] = 4096;
    matrix->t[2] = 0;
    matrix->t[1] = 0;
    matrix->t[0] = 0;
    func_80024AEC((MATRIX*)(&D_1F8000C0));
    camera->vrx= 0;
    camera->vry = 0;
    camera->vrz= -544;
    camera->vpx = 0;
    camera->vpy = 0;
    camera->vpz = 0;
    func_80024B3C((MATRIX*)(&D_1F800118));
    initDisplay(96U, 151U, 255U);
    setRECT(&rect, 0, 0, 1024, 512);
    ClearImage(&rect, 0U, 0U, 0U);
    ClearOTagR(&OT_FRAMEBUFFER, 0x328);
    ClearOTagR(&OT_FRAMEBUFFER + 0x344, 0x328);
    *(short* )&PSX_SCRATCH[0x1F4] = 0;
    *(u_int** )&PSX_SCRATCH[0x1E0] = &OT_FRAMEBUFFER;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay);
void initDisplay(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 256, 320, 224);
    SetDefDispEnv(dispenv1, 704, 256, 320, 224);
    SetDefDrawEnv(drawenv2, 704, 256, 320, 224);
    SetDefDispEnv(dispenv2, 384, 256, 320, 224);
    setWH(&dispenv1->screen, 256, 224);
    setWH(&dispenv2->screen, 256, 224);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = false;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    setXY(&dispenv1->screen, D_8009C864, D_8009C866);
    setXY(&dispenv2->screen, D_8009C864, D_8009C866);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initDisplay2x);
void initDisplay2x(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = (DRAWENV*)&D_8009D6C4;
    dispenv1 = (DISPENV*)((byte*)(&D_8009D6C4) - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)(&D_8009D6C4) + 0xD10);
    dispenv2 = (DISPENV*)((byte*)(&D_8009D6C4) + 0xD10 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 0, 640, 480);
    SetDefDispEnv(dispenv1, 384, 0, 640, 480);
    SetDefDrawEnv(drawenv2, 384, 0, 640, 480);
    SetDefDispEnv(dispenv2, 384, 0, 640, 480);
    setRECT(&dispenv1->screen, 0, 0, 256, 240);
    setRECT(&dispenv2->screen, 0, 0, 256, 240);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = true;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016F5C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80016FD8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017024);
void func_80017024(void)
{
    int tid;
    unkstruct_1F8001D4* temp_v0;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v1;

    *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = (u32*)0x801FD800;
    for (temp_v0 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4); temp_v0 <= 0x801FD94FU; temp_v0 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4) = *(u32* )(&D_1F8000C0[0]+0x114) + sizeof(unkstruct_1F8001D4)) {
        tid = 2;
        switch ((u16)(*(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34))->unk0) {
            case 3:
                EnterCriticalSection();
                temp_v0_2 = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                (*(unkstruct_1F8001D4** )0x01F8001D4)->task_id = OpenTh(temp_v0_2->task_func, temp_v0_2->task_sp, temp_v0_2->task_gp);
                ExitCriticalSection();
            case 2:
                temp_v1 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                temp_v1->unk0 = tid*2;
                ChangeTh(temp_v1->task_id);
                break;
        }
    }
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800170F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017154);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800171D4);
void func_800171D4(s16 arg0)
{
    unkstruct_1F8001D4* temp_v1;

    temp_v1 = *(unkstruct_1F8001D4** )0x1F8001D4;
    temp_v1->unk2 = arg0;
    temp_v1->unk0 = 1;
    ChangeTh(DescTH);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017208);
void func_80017208(void)
{
    (*(unkstruct_1F8001D4** )0x1F8001D4)->unk0 = 0;
    EnterCriticalSection();
    CloseTh((*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->task_id);
    ExitCriticalSection();
    ChangeTh(DescTH);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017258);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800172C4);
void func_800172C4(s32 arg0)
{
    unkstruct_1F8001D4* temp_v0;

    temp_v0 = *(unkstruct_1F8001D4** )0x1F8001D4;
    temp_v0->unk0 = 3;
    temp_v0->task_func = arg0;
    EnterCriticalSection();
    CloseTh((*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->task_id);
    ExitCriticalSection();
    ChangeTh(DescTH);
}

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
    if (((pTim->mode & 8) != 0) && ((x2 << 16) >= 0)) {
        LoadImage(pTim->crect, pTim->caddr);
    }
    if ((x << 16) >= 0) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017614);
void func_80017614(void)
{
    *(int** )0x1F800218 = &D_800B0528;
    *(int** )0x1F80025C = &D_800B0528;
    *(int** )0x1F80021C = &D_800A5970;
    *(int** )0x1F800260 = &D_800A5970;
    *(int** )0x1F800220 = &D_800B0680;
    *(int** )0x1F800264 = &D_800B0680;
    *(int** )0x1F800224 = &D_800B0470;
    *(int** )0x1F800268 = &D_800B0470;
    *(int** )0x1F800230 = &D_800B3184;
    *(int** )0x1F800274 = &D_800B3184;
    *(int** )0x1F800228 = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    *(short* )0x1F80024E = 0;
    *(short* )0x1F800244 = 0;
    *(short* )0x1F800250 = 0;
    *(short* )0x1F800246 = 0;
    *(short* )0x1F800252 = 0;
    *(short* )0x1F80024A = 0;
    *(short* )0x1F800254 = 0;
    *(short* )0x1F80024C = 0;
    *(short* )0x1F800258 = 0;
    *(short* )0x1F800242 = 0;
    *(short* )0x1F800256 = 0;
    *(short* )0x1F800248 = 0;
    *(int** )0x1F80022C = &D_800A5858;
    *(int** )0x1F800270 = &D_800A5858;
    *(short* )0x1F80025A = 0;
    *(short* )0x1F800240 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017734);
void func_80017734(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    func_80024AEC((MATRIX* ) D_1F8000C0);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -120;
    *(int* )0x1F800200 = 69;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    *(char* )0x1F8003CE = 0;
    *(short* )0x1F8001C8 = 0;
    *(char* )0x1F8003D1 = 0;
    *(u_char* )0x1F8003D2 = 0xFF;
    *(u_char* )0x1F8003D3 = 0xFF;
    D_8009EBA0 = 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", initGameConfig);
void initGameConfig(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    memset((u_char *)&GAME, 0, sizeof(gameConfig));
    memset(&D_8009BC98, 0, 0x2C);
    func_80024AEC((MATRIX* ) D_1F8000C0);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -120;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    *(int* )0x1F800200 = 69; // ?
    *(u_char* )0x1F8003D2 = 0xFF;
    *(u_char* )0x1F8003D3 = 0xFF;
    GAME.playerAP = 0;
    *&GAME.selectedArea = AREA00_VILLAGEOFALLBEGINNINGS;
    GAME.playerLives = 3;
    GAME.saveSlot = 0xFF;
    GAME.unk730 = 0xFF;
    *(char* )0x1F8003CE = 0; // INVENTORY ENABLED
    *(short* )0x1F8001C8 = 0; // SPRITE ZOOM
    *(char* )0x1F8003D1 = 0; 
    D_8009EBA0 = 0;
    GAME.selectedSection = AREA00_SECTION00_VILLAGEOFALLBEGINNINGS;
    GAME.inventoryScreen = INVENTORY_SCREEN_ITEM;
    GAME.unk13 = 1;
    GAME.unk54f = 1;
    GAME.event[EVENT_GRANDPASBRACELET] = 1;
    GAME.unk12 = 9;
    GAME.playerHealthDisplayed = 4;
    GAME.playerHealth = 4;
    GAME.unk670 = 0x5DA;
    GAME.unk672 = 0x639;
    GAME.unk674 = 0x691;
    GAME.unk5bc = D_8009E744;
    if (*(u8* )0x1F8001B3 == 0) {
        // 0 = NORMAL MODE | 1 = EASY MODE
        if (*(u8* )0x1F8001AB != 0) {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_GRAPPLE;
            GAME.inventory.slots[2] = ITEM_GRAPPLEJACK;
            GAME.inventory.slots[3] = ITEM_WOODBOOMERANG;
            GAME.inventory.slots[4] = ITEM_STONEBOOMERANG;
            GAME.inventory.slots[5] = ITEM_IRONBOOMERANG;
            GAME.inventory.slots[6] = ITEM_NORMALPANTS;
            GAME.inventory.slots[7] = ITEM_JUMPINGPANTS;
            GAME.inventory.slots[8] = ITEM_DASHINGPANTS;
            GAME.inventory.slots[9] = ITEM_FLASHPANTS;
            GAME.inventory.slots[10] = ITEM_100YEAROLDBELL;
            GAME.inventory.slots[11] = ITEM_100YEAROLDKEY;
            GAME.inventory.slots[12] = ITEM_1000YEAROLDKEY;
            GAME.inventory.slots[13] = ITEM_FUNKYPARASOL;
            GAME.inventory.counter = 14;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_GRAPPLE] = 1;
            GAME.item[ITEM_GRAPPLEJACK] = 1;
            GAME.item[ITEM_WOODBOOMERANG] = 1;
            GAME.item[ITEM_STONEBOOMERANG] = 1;
            GAME.item[ITEM_IRONBOOMERANG] = 1;
            GAME.item[ITEM_DASHINGPANTS] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.item[ITEM_JUMPINGPANTS] = 1;
            GAME.item[ITEM_FLASHPANTS] = 1;
            GAME.item[ITEM_100YEAROLDBELL] = 1;
            GAME.item[ITEM_100YEAROLDKEY] = 1;
            GAME.item[ITEM_1000YEAROLDKEY] = 1;
            GAME.item[ITEM_FUNKYPARASOL] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        } else {
            GAME.inventory.slots[0] = ITEM_BLACKJACK;
            GAME.inventory.slots[1] = ITEM_NORMALPANTS;
            GAME.inventory.counter = 2;
            GAME.item[ITEM_BLACKJACK] = 1;
            GAME.item[ITEM_NORMALPANTS] = 1;
            GAME.inventory.sortMode = SORT_MODE_DEFAULT;
        }
    }
    return;
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017F88);
void func_80017F88(void)
{
    *(int** )0x1F800224 = &D_800B0470;
    *(int** )0x1F800268 = &D_800B0470;
    *(short* )0x1F800254 = 0;
    *(short* )0x1F80024C = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80017FB8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018094);
void func_80018094(void)
{
    *(int** )0x1F800228 = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    *(short* )0x1F800256 = 0;
    *(short* )0x1F800248 = 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180C4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800180F0);
void func_800180F0(void)
{
    memset(&D_800B00F8, 0, 0x16C);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001811C);

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

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/main", D_80010000);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/main", D_80010008);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018954);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018BC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C40);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018C8C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018CC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D40);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018D7C);
void func_80018D7C(void)
{
    int var_v1_2;
    int var_a0;
    int var_a2;

    int i;
    
    var_a0 = 0;
    var_a2 = 0x6A;
    
    for (i = 0; i < 60; i++) {
        D_800A5140[i].val[0] = var_a0;
        D_800A5140[i].unk0 = -1;
        D_800A5140[i].unk2 = 0;
        D_800A5140[i].val[1] = var_a2;
        D_800A5140[i].val[2] = 4;
        D_800A5140[i].val[3] = 16;
        D_800A5140[i].val[4] = 0;
        D_800A5140[i].val[5] = 0;

        var_a0 += 4;
        
        if (var_a0 >= 61) {
            var_a0 = 0;
            var_a2 += 16;
        }
    }
    for (i=0; i < 8; i+=2) {
        D_800A39B0[i].unk0 = -1;
        D_800A39B0[i].unk2 = -1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018E58);
void func_80018E58(void)
{
    int var_a0;
    int var_a2;

    int i;
    
    var_a0 = 0;
    var_a2 = 0x9E;
    
    for (i = 0; i < 48; i++) {
        D_800AFF18[i].val[0] = var_a0;
        D_800AFF18[i].unk0 = -1;
        D_800AFF18[i].unk2 = 0;
        D_800AFF18[i].val[1] = var_a2;
        D_800AFF18[i].val[2] = 4;
        D_800AFF18[i].val[3] = 24;
        D_800AFF18[i].val[4] = 0;
        D_800AFF18[i].val[5] = 0;

        var_a0 += 4;
        
        if (var_a0 >= 60) {
            var_a0 = 0;
            var_a2 += 24;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80018F04);
void func_80018F04(void) {
    int var_a0;
    int var_v0;

    if (D_8009CA04 == 0) return;
    var_v0 = &D_8009EBA8;
    func_8003B478(var_v0);
            
    switch(GAME.selectedArea&0xFFFF) {
        case AREA00_VILLAGEOFALLBEGINNINGS:
            switch (GAME.selectedSection) {
                case AREA00_SECTION00_VILLAGEOFALLBEGINNINGS:
                case AREA00_SECTION01_FORESTOFALLBEGINNINGS:
                case AREA00_SECTION02_FORESTOFALLBEGINNINGSHUTENTRANCE:
                    var_a0 = *(int* )0x1F8002B8;
                    func_8003B2C8(var_a0, var_v0);
                    func_8003B410(var_v0, 0);
                    break;
            }
            break;
        case AREA01_DWARFFOREST:
            switch (GAME.selectedSection) {
                 case AREA01_SECTION00_FORESTOF100FLOWERS:
                 case AREA01_SECTION01_FORESTOF100FLOWERSRIGHTENTRANCE:
                 case AREA01_SECTION02_WOBBLYWHARF:
                 case AREA01_SECTION03_WATCHTOWER:
                 case AREA01_SECTION04_CHARITYSQUARE:
                    var_a0 = *(int* )0x1F8002B8;
                    func_8003B2C8(var_a0, var_v0);
                    func_8003B410(var_v0, 0);
                    break;
            }
            break;
        case AREA02_DWARFVILLAGE:
            switch(GAME.selectedSection) {
                case AREA02_SECTION00_DWARFVILLAGE:
                    var_a0 = *(int* )0x1F8002BC;
                    func_8003B2C8(var_a0, var_v0);
                    func_8003B410(var_v0, 0);
                    break;
                 case AREA02_SECTION01_DWARFELDERSHUT:
                 case AREA02_SECTION02_UNDERGROUNDPRISON:
                    var_a0 = *(int* )0x1F8002B8;
                    func_8003B2C8(var_a0, var_v0);
                    func_8003B410(var_v0, 0);
                    break;
            }
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019020);
void memCardInit(void)
{
    EnterCriticalSection();
    MEMCARD_SW_END_IO = OpenEvent(SwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_END_ERROR = OpenEvent(SwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_TIMEOUT = OpenEvent(SwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_SW_NEW_DEVICE = OpenEvent(SwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_IO = OpenEvent(HwCARD, EvSpIOE, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_END_ERROR = OpenEvent(HwCARD, EvSpERROR, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_TIMEOUT = OpenEvent(HwCARD, EvSpTIMOUT, EvMdNOINTR, EvStUNUSED);
    MEMCARD_HW_NEW_DEVICE = OpenEvent(HwCARD, EvSpNEW, EvMdNOINTR, EvStUNUSED);
    InitCARD(0);
    ExitCriticalSection();
    StartCARD();
    _bu_init();
    EnableEvent(MEMCARD_SW_END_IO);
    EnableEvent(MEMCARD_SW_END_ERROR);
    EnableEvent(MEMCARD_SW_TIMEOUT);
    EnableEvent(MEMCARD_SW_NEW_DEVICE);
    EnableEvent(MEMCARD_HW_END_IO);
    EnableEvent(MEMCARD_HW_END_ERROR);
    EnableEvent(MEMCARD_HW_TIMEOUT);
    EnableEvent(MEMCARD_HW_NEW_DEVICE);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800191E0);
void func_800191E0(void)
{
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;
    u16 temp_v1;
    u16 temp_v1_3;
    u16 temp_v1_4;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_a0_2;
    unkstruct_1F8001D4* temp_a1;
    unkstruct_1F8001D4* temp_a1_2;
    unkstruct_1F8001D4* temp_v0;
    unkstruct_1F8001D4* temp_v0_2;
    unkstruct_1F8001D4* temp_v0_3;
    unkstruct_1F8001D4* temp_v0_7;
    unkstruct_1F8001D4* temp_v1_2;

    D_8009D6DD = 0;
    D_8009D6DE = 0;
    D_8009D6DF = 0;
    D_8009E3ED = 0;
    D_8009E3EE = 0;
    D_8009E3EF = 0;
    *(s8* )0x1F8001D1 = 0;
    *(s8* )0x1F8001D0 = 0;
    D_8009E744 = 0;
    D_8009C9E4 = 1;
    D_8009E450 = 0;
    func_80023A3C();
    temp_v0 = *(unkstruct_1F8001D4** )0x1F8001D4;
    temp_v0->state0 = 9U;
    temp_v0->state1 = 0U;
    temp_v0->state2 = 0;
    SetDispMask(0);
    do {
        temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state0;
        switch (temp_v1) {
            case 0:
                *(u8* )0x1F8001CE = 0;
                func_800223A0(0);
                func_800223A0(1);
                func_800222B8(0, 1);
                *(s8* )0x1F8001C4 = 0;
                *(s8* )0x1F8001C5 = 0;
                memset(&D_1F8001A0, 0, 0x24);
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state0++;
                break;
            case 1:
                if (*(u8* )0x1F8001CE != 0) {
                    func_8001F158(0x15);
                    (*(unkstruct_1F8001D4** )0x1F8001D4)->state0 = 4U;
                }
                break;
            case 2:
                SetDispMask(1);
                temp_a0 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_a0->timer = 120;
                temp_a0->state0++;
                break;
            case 3:
                temp_a1 = *(unkstruct_1F8001D4** )0x1F8001D4;
                *(s32* )0x1F800164 = (s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
                temp_a1->timer--;
                if ((s16) temp_a1->timer == -1) {
                    temp_a1->state0++;
                }
                FontDebugPrintf(0x50, 0x60, 0, &D_80010000);
                FontDebugPrintf(0x50, 0x70, 0, &D_80010008);
                break;
            case 4:
                temp_v0_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v0_2->state0 = 0U;
                temp_v0_2->state1 = 1U;
                temp_v0_2->state2 = 0;
                func_800172C4((s32*)func_80019844);
                break;
            case 9:
                SetDispMask(0);
                *(byte* )0x1F8001CE = 0U;
                func_800222B8(0x5E, 1);
                (*(unkstruct_1F8001D4** )0x1F8001D4)->state0 = 0xAU;
                break;
            case 10:
                if (*(u8* )0x1F8001CE != 0) {
                    SetDispMask(0);
                    initDisplay2x(0U, 0U, 0U);
                    SetDispMask(1);
                    temp_v0_3 = *(unkstruct_1F8001D4** )0x1F8001D4;
                    temp_v0_3->timer = 240;
                    temp_v0_3->state0 = 0xBU;
                    temp_v0_3->state1 = 0U;
                }
                break;
            case 11:
                temp_a1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                *(int* )0x1F800164 = (s32) ((s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF);
                switch (temp_a1_2->state1) {                    // switch 1; irregular
                    case 0:                             // switch 1
                        temp_a1_2->unk5A = 1U;
                        temp_a1_2->state1++;
                        break;
                    case 1:                             // switch 1
                        temp_a1_2->unk5A++;
                        if ((s16) temp_a1_2->unk5A >= 0x80) {
                            temp_a1_2->timer = 0xB4U;
                            temp_a1_2->state1++;
                            break;
                        }
                        break;
                    case 2:                             // switch 1
                        temp_a1_2->timer--;
                        if ((s16) temp_a1_2->timer == -1) {
                            temp_a1_2->state1++;
                        }
                        break;
                    case 3:                             // switch 1
                        temp_a1_2->unk5A--;
                        if ((s16)temp_a1_2->unk5A == 0) {
                            SetDispMask(0);
                            initDisplay(0U, 0U, 0U);
                            temp_v0_7 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            *(byte* )0x1F8001D1 = 0;
                            *(s16* )0x1F8001F6 = 0;
                            temp_v0_7->state0 = 0U;
                            temp_v0_7->state1 = 0U;
                        }
                        break;
                }
                temp_a0_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                if (*(u16*)&temp_a0_2->state0 == 0xB) {
                    func_8001964C((u8) temp_a0_2->unk5A, 1);
                }
                break;
        }
        func_800171D4(1);
    } while(true);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001964C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019844);
void func_80019844(void)
{
        typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte unk1D0;
        byte unk1D1;
        byte unk1D2;
        byte unk1D3;
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v1 = *(unkstruct_1F8001D4**)scratch->unk1D4;

    u32 sp10[2];
    u16 temp_a0;

    *(s8* )&scratch->unk1D1 = 1;
    *(s8* )&scratch->unk1D0 = 0;
    sp10[0] = 0;
    scratch->unk1D4->titleScreenSelectedOption = 0;
    while(true) {
        *(u16* )0x1F8001F8 = *(u16* )(D_1F8000F8+0x100) + 1;
        asm("");
        func_800223E0();
        temp_v1 = *(unkstruct_1F8001D4**)0x1F8001D4;
        temp_a0 = temp_v1->state0;
        if ((temp_a0 >= 3U) && (*(u16* )0x1F8001FC & (JOY_CROSS | JOY_START)) && (temp_a0 != 4)) {
            temp_v1->state0 = 4U;
            temp_v1->state1 = 0;
            temp_v1->state2 = 0;
            sp10[0] = 1;
            func_80020C00(0);
            if (*(u8* )0x1F8001CC != 0) {
                *(s8* )0x1F8001D3 = 1;
            }
        }
        switch ((u16)(*(unkstruct_1F8001D4**)0x1F8001D4)->state0) {
            case 0:
                func_800199B8(sp10);
                break;
            case 1:
                func_80019CA4();
                break;
            case 2:
                func_8001A328();
                break;
            case 3:
                func_80019D78();
                break;
            case 4:
                loopTitleScreen(sp10);
                break;
        }
        func_800171D4(1);
    };
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_800199B8);
void func_800199B8(void)
{
    u16 temp_a0;
    u16 temp_v0;
    u16 temp_v1;
    unkstruct_1F8001D4* temp_a0_2;
    unkstruct_1F8001D4* temp_a2;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_3;
    unkstruct_1F8001D4* temp_v1_4;
    unkstruct_1F8001D4* temp_v1_5;
    unkstruct_1F8001D4* temp_v1_6;
    unkstruct_1F8001D4* temp_v1_7;

    temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state1;
    switch (temp_v1) {
        case 0:
            temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_a0 = temp_v1_2->state2;
            switch (temp_a0) {                      // switch 1; irregular
                case 0:                             // switch 1
                    SetDispMask(0);
                    *(u8* )0x1F8001CE = 0U;
                    func_800223A0(1);
                    func_800222B8(1, 1);
                    temp_v1_3 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                    temp_v1_3->state2++;
                    return;
                case 1:                             // switch 1
                    if (*(u8* )0x1F8001CE != 0) {
                        temp_v1_2->state1 = 2U;
                        temp_v1_2->state2 = 0U;
                        func_800E7D5C();
                        return;
                    }
                default:
                    return;
            }
            break;
        case 1:
            SetDispMask(0);
            func_800E7D5C();
            temp_v1_4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_4->state1++;
            return;
        case 2:
            temp_a2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            *(u8* )0x1F8001CC = 1;
            *(s8* )0x1F8001CD = 0x15;
            temp_a2->state1++;
            func_80017154(1, func_8001F1C0);
            return;
        case 3:
            if (*(u8* )0x1F8001CC != 0) {
                return;
            }
            temp_v1_4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            temp_v1_4->state1++;
            return;
        case 4:
            SetDispMask(0);
            initDisplay2x(240U, 240U, 240U);
            SetDispMask(1);
            *(s32* )0x1F800164 = (s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
            func_800E7D74();
            temp_a0_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_a0_2->timer = 120;
            temp_a0_2->state1++;
            return;
        case 5:
            *(s32* )0x1F800164 = (s32) ((s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF);
            func_800E7D74();
            temp_v1_5 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v0 = temp_v1_5->timer - 1;
            temp_v1_5->timer = temp_v0;
            if ((temp_v0 << 0x10) <= 0) {
                func_80020C00(0);
                SetDispMask(0);
                initDisplay(0U, 0U, 0U);
                *(u8* )0x1F8001CE = 0U;
                func_800223A0(2);
                func_800222B8(2, 1);
                temp_v1_4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                temp_v1_4->state1++;
                return;
            }
            break;
        case 6:
            if (*(u8* )0x1F8001CE != 0) {
                temp_v1_6 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_6->state1++;
                func_8001F158(0);
                return;
            }
            break;
        case 7:
            temp_v1_7 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_7->state0 = 3;
            temp_v1_7->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019CA4);
void func_80019CA4(void)
{
    typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte pad[0x4];
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    u8 temp_v0;
    unkstruct_1F8001D4* temp_v1;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_a1 = scratch->unk1D4;

    switch (temp_a1->state1) {                              // irregular
        case 0:
            SetDispMask(0);
             *(u8* )&scratch->unk1CE = 0;
            func_800223A0(2);
            func_800222B8(2, 1);
            scratch->unk1D4->state1++;
            return;
        case 1:
            if (*(u8* )&scratch->unk1CE != 0) {
                temp_a1->state1++;
                func_8001F158(0);
                return;
            }
            return;
        case 2:
            temp_v1 = *(u_long**)&scratch->unk1D4;
            temp_v1->state0 = 4;
            temp_v1->state1 = 0;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_80019D78);
void func_80019D78(void)
{
    typedef inline struct {
        byte data[0x1CC];
        byte unk1CC;
        byte unk1CD;
        byte unk1CE;
        byte unk1CF;
        byte pad[0x4];
        unkstruct_1F8001D4* unk1D4;
    } scratchpad;
    
    u8 temp_v0;
    unkstruct_1F8001D4* temp_v1;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_a1 = scratch->unk1D4;
    
    switch (temp_a1->state1) {
        case 0:
            SetDispMask(0);
            initDisplay(0U, 0U, 0U);
            *(u8* )&scratch->unk1CC = 1;
            *(s8* )&scratch->unk1CD = 0;
            scratch->unk1D4->state1 ++;
            func_80017154(1, &func_8001F1C0);
            break;
        case 1:
            temp_v0 = *(u_long**)&scratch->unk1CC;
            if (temp_v0 == 0) {
                temp_a1->state1++;
                return;
            }
            break;
        case 2:
            func_80020C00(0);
            temp_v1 = *(u_long**)&scratch->unk1D4;
            temp_v1->state0 = 4;
            temp_v1->state1 = 0;
            break;
    }
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", loopTitleScreen);
void loopTitleScreen(s32* arg0)
{
    s32 direction;
    u16 nextTimer;
    u16 currentState1;
    u16 currentState2;
    unkstruct_1F8001D4* gameControl;
    unkstruct_1F8001D4* gameControlTemp1;
    unkstruct_1F8001D4* gameControlTemp2;
    unkstruct_1F8001D4* gameControlTemp3;
    unkstruct_1F8001D4* gameControlTemp4;
    unkstruct_1F8001D4* gameControlTemp5;
    unkstruct_1F8001D4* gameControlTemp6;
    unkstruct_1F8001D4* gameControlTemp7;
    unkstruct_1F8001D4* gameControlTemp8;
    unkstruct_1F8001D4* gameControlTemp9;
    unkstruct_1F8001D4* gameControlTemp10;

    currentState1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state1;
    switch (currentState1) {
        case 0:
            SetDispMask(0);
            gameControl = *(unkstruct_1F8001D4** )0x1F8001D4;
            gameControl->state2 = 0U;
            gameControl->state1++;
        case 1:
            if (*(u8* )0x1F8001CC == 0) {
                initDisplay(0U, 0U, 0U);
                gameControl = *(unkstruct_1F8001D4** )0x1F8001D4;
                gameControl->state1++;
                return;
            }
        default:
            return;
        case 2:
            func_800E7DA4();
            SetDispMask(1);
            func_80020AF0(0);
            func_800E889C(48, 192, 1);
            (*(unkstruct_1F8001D4** )0x1F8001D4)->titleScreenSelectedOption = TITLESCREEN_NEWGAME;
            gameControlTemp9 = (*(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34));
            gameControlTemp9->unk6A = (u8) (&D_80076E80)[gameControlTemp9->titleScreenSelectedOption];
            gameControlTemp9 = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
            gameControlTemp9->unk6B = (u8) (&D_80076E80)[gameControlTemp9->titleScreenSelectedOption];
            gameControlTemp1 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
            gameControlTemp1->timer = 972;
            gameControlTemp1->state1++;
            return;
        case 3:
            gameControlTemp5 = *(unkstruct_1F8001D4** )((byte*)&D_1F8001A0+0x34);
            *(s32* )0x1F800164 = (s32) ((*(s16* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
            nextTimer = gameControlTemp5->timer - 1;
            gameControlTemp5->timer = nextTimer;
            if ((nextTimer << 0x10) <= 0) {
                gameControlTemp5->state1++;
            }
            func_800E7DDC(arg0, gameControlTemp5);
            if (*&D_8009C9D8 != 0) {
                (*(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4))->timer = 972;
            }
            gameControlTemp2 = *(unkstruct_1F8001D4** )0x1F8001D4;
            currentState2 = gameControlTemp2->state2;
            switch (currentState2) {                    // switch 1; irregular
                case 0:                             // switch 1
                    if (*(u16* )0x1F8001FC & JOY_LEFT) {
                        if (gameControlTemp2->titleScreenSelectedOption != 0) {
                            gameControlTemp2->titleScreenSelectedOption--;
                            gameControlTemp9 = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControlTemp9->unk6B = (u8) (&D_80076E80)[gameControlTemp9->titleScreenSelectedOption];
                            gameControlTemp9 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControlTemp9->state2++;
                            playSFX(8);
                        }
                    }
                    if (*(u16* )0x1F8001FC & JOY_RIGHT) {
                        gameControlTemp3 = *(unkstruct_1F8001D4** )0x1F8001D4;;
                        if (gameControlTemp3->titleScreenSelectedOption < 2U) {
                            gameControlTemp3->titleScreenSelectedOption++;
                            gameControlTemp8 = *(unkstruct_1F8001D4** )(&D_1F8000C0[0]+0x114);
                            gameControlTemp8->unk6B = (u8) (&D_80076E80)[gameControlTemp8->titleScreenSelectedOption];
                            gameControlTemp8 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                            gameControlTemp8->state2++;
                            playSFX(8);
                        }
                    }
                    if (*(u16* )0x1F8001FC & (JOY_CROSS | JOY_START)) {
                        func_80020C00(0);
                        gameControlTemp6 = *(unkstruct_1F8001D4** )0x1F8001D4;
                        switch (gameControlTemp6->titleScreenSelectedOption) {       // switch 2; irregular
                            case TITLESCREEN_NEWGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 0;
                                func_800204E0(10, 10, gameControlTemp6);
                                func_800172C4(func_8001A51C);
                                break;
                            case TITLESCREEN_LOADGAME:                 // switch 2
                                gameControlTemp6->loadGameSelected = 1;
                                func_800204E0(10, 10, gameControlTemp6);
                                func_800172C4(func_8001A51C);
                                break;
                            case TITLESCREEN_OPTIONS:                 // switch 2
                                gameControlTemp6->state0 = 2;
                                gameControlTemp6->state1 = 0U;
                                func_800204E0(10, 10, gameControlTemp6);
                                break;
                        }
                    }
                    break;
                case 1:                             // switch 1
                    if (gameControlTemp2->unk6A != gameControlTemp2->unk6B) {
                        direction = -4;
                        if (gameControlTemp2->unk6A < gameControlTemp2->unk6B) {
                            direction = 4;
                        }
                        gameControlTemp2->unk6A = gameControlTemp2->unk6A + direction;
                        gameControlTemp4 = *(unkstruct_1F8001D4** )(&SCRATCHPAD+0x1D4);
                        if (gameControlTemp4->unk6B == gameControlTemp4->unk6A) {
                            gameControlTemp4->state2--;
                        }
                    }
                    break;
            }
            func_800E889C(48, 192, 1);
            if (*(u16* )0x1F8001F8 & 0x20) {
                func_800E889C(56, 144, 0);
            }
            gameControlTemp7 = *(unkstruct_1F8001D4** )0x1F8001D4;
            func_800E8E78(gameControlTemp7->unk6A, gameControlTemp7->titleScreenSelectedOption);
            func_8001F6D4();
            return;
        case 4:
            func_80020C00(0);
            *arg0 = 0;
            gameControl = *(unkstruct_1F8001D4** )0x1F8001D4;
            gameControl->state0 = 3;
            gameControl->state1 = 0U;
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A328);
void func_8001A328(void)
{
    u_short temp_v1_3;
    unkstruct_1F8001D4* temp_a0;
    unkstruct_1F8001D4* temp_v1_2;
    unkstruct_1F8001D4* temp_v1_4;

    *(int* )0x1F800164 = (int) ((*(short* )0x1F8001F4 * 0xC000) + &D_800B3188) & 0xFFFFFF;
    switch ((*(unkstruct_1F8001D4** )0x1F8001D4)->state1) {
        case 0:
            func_80020C00(0);
            SetDispMask(0);
            *(u_char* )0x1F8001CE = 0;
            func_800223A0(3);
            func_800222B8(8, 1);
            (*(unkstruct_1F8001D4** )0x1F8001D4)->state1++;
            return;
        case 1:
            if (*(u_char* )0x1F8001CE != 0) {
                SetDispMask(1);
                func_800E75C4();
                func_80020AF0(0);
                temp_v1_2 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_2->state2 = 0U;
                (*(unkstruct_1F8001D4** )0x1F8001D4)->state1++;
                return;
            }
        default:
            return;
        case 2:
            temp_a0 = *(unkstruct_1F8001D4** )0x1F8001D4;
            temp_v1_3 = temp_a0->state2;
            switch (temp_v1_3) {                    // switch 1; irregular
                case 0:                             // switch 1
                    temp_a0->unk4E.value = 0;
                    temp_a0->state2++;
                    // fallthrough
                case 1:                             // switch 1
                    if (func_800E75CC(temp_a0) != 0) {
                    (*(unkstruct_1F8001D4** )0x1F8001D4)->state1++;
                    return;
                    }
                    break;
                case 2:                             // switch 1
                    func_800E7960(temp_a0);
                    return;
                case 3:                             // switch 1
                    func_800E7A48(temp_a0);
                    return;
            }
            break;
        case 3:
            func_80020C00(0);
            SetDispMask(0);
            *(u_char* )0x1F8001CE = 0U;
            func_800223A0(2);
            func_800222B8(2, 1);
            (*(unkstruct_1F8001D4** )0x1F8001D4)->state1++;
            return;
        case 4:
            if (*(u_char* )0x1F8001CE != 0) {
                temp_v1_4 = *(unkstruct_1F8001D4** )0x1F8001D4;
                temp_v1_4->state0 = 4;
                temp_v1_4->state1 = 0U;
            }
            break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A51C);
void func_8001A51C(void)
{
    typedef inline struct {
        byte data[0x1CE];
        char unk1CE;
        char unk1CF;
        char unk1D0;
        char unk1D1;
        char unk1D2;
        char unk1D3;
        char unk1D4;
        char pad[6];
        short unk1DC;
        short unk1DE;
        char pad2[28];
        short unk1FC;
    } scratchpad;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_v0 = *(unkstruct_1F8001D4**)&scratch->unk1D4;
    int temp_v1;

    scratch->unk1D1 = 0;
    scratch->unk1D0 = 1;
    temp_v0->state0 = 0;
    temp_v0->state1 = 0;
    temp_v0->state2 = 0;
    temp_v0->unk4E.value = 0;
    temp_v0->unk6A = 0;
    setRGB0((DRAWENV*)&D_8009D6C4, 0, 0, 0);
    setRGB0((DRAWENV*)D_8009E3D4, 0, 0, 0);
    scratch->unk1DC = -1;
    scratch->unk1DE = 0;
    D_8009EB4C = 0;
    scratch->unk1CE = 0;
    D_8009EBA0 = 0;
    func_80024B3C(D_1F800118);
    scratch->unk1FC  = 0;
    while (true){
        func_800223E0();
        temp_v1 = (*(unkstruct_1F8001D4** )0x1F8001D4)->state0;
        switch ((u_short)temp_v1) {
            case 0:
                func_8001A670(); // New Game
                break;
            case 1:
                func_8001A954(); // Debug
                break;
            case 2:
                func_8001A774(); // Load Game
                break;
        }
        func_800171D4(1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/main", func_8001A670);
void func_8001A670(void)
{

    typedef inline struct {
        byte data[0x1CF];
        byte unk1CF;
        byte pad[0x4];
        byte unk1D4;
    } scratchpad;
    
    RECT rect;
    s16 var_v0;
    u16 temp_v0;
    u16 temp_v1;
    scratchpad* scratch = PSX_SCRATCH;
    unkstruct_1F8001D4* temp_a0 = *(u_long**)&scratch->unk1D4;

    switch (temp_a0->state1) {                              // irregular
        case 0:
            temp_a0->unk5A = 1U;
            temp_a0->state1 += 1;
            rect.w = 64;
            rect.x = 0;
            rect.y = 0;
            rect.h = 256;
            ClearImage((RECT* ) &rect, 0U, 0U, 0U);
            initGameConfig();
            scratch->unk1CF = 0;
            return;
        case 1:
            temp_v0 = temp_a0->unk5A - 1;
            temp_a0->unk5A = temp_v0;
            if ((temp_v0 << 0x10) <= 0) {
                temp_a0->state1 += 1;
                return;
            }
            return;
        case 2:
            temp_a0->state2 = 0;
            temp_a0->unk4E.value = 0;
            if (temp_a0->loadGameSelected != 0) {
                var_v0 = 2;
            } else {
                var_v0 = 1;
                asm("");
            }
            temp_a0->state0 = var_v0;
            temp_a0->state1 = 0U;
            break;
    }
}
