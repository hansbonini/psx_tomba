#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/gfxinit", loadImageRect);
void loadImageRect(u_long* p, short x, short y, short w, short h)
{
    RECT rect;
    setRECT(&rect, x, y, w, h);
    LoadImage(&rect, p);
    return;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/gfxinit", loadTIM);
void loadTIM(u_long* address, short x, short y, short x2, short y2)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/gfxinit", initDrawLists);
void initDrawLists(void)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/gfxinit", resetDrawLists);
void resetDrawLists(void)
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/system/gfxinit", resetCamera);
void resetCamera(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    getBaseMatrix((MATRIX* ) D_1F8000C0);
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
