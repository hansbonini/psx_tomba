#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", loadImageRect);
void loadImageRect(u_long* p, short x, short y, short w, short h)
{
    RECT rect;
    setRECT(&rect, x, y, w, h);
    LoadImage(&rect, p);
    return;
}

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", loadTIM);
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

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", initObjectPools);
void initObjectPools(void)
{
    clearPlayerObject();
    initObjectPoolLayer1();
    initObjectPool();
    initLayer1DrawList();
    initMainDrawList();
    initLayer4DrawList();
    initObjectPoolLayer8();
    initLayer5DrawList();
    clearOtBuffer();
    initObjectPoolLayer7();
    clearLayer1Buffer();
    initObjectPoolUnlayered();
    clearMenuState();
    clearMenuParams();
}

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", resetDrawLists);
void resetDrawLists(void)
{
    (*(int* *)&SPAD->unk218) = &D_800B0528;
    (*(int* *)&SPAD->unk25C) = &D_800B0528;
    (*(int* *)&SPAD->unk21C) = &D_800A5970;
    (*(int* *)&SPAD->unk260) = &D_800A5970;
    (*(int* *)&SPAD->unk220) = &D_800B0680;
    (*(int* *)&SPAD->unk264) = &D_800B0680;
    (*(int* *)&SPAD->unk224) = &D_800B0470;
    (*(int* *)&SPAD->unk268) = &D_800B0470;
    (*(int* *)&SPAD->unk230) = &D_800B3184;
    (*(int* *)&SPAD->unk274) = &D_800B3184;
    (*(int* *)&SPAD->unk228) = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    SPAD->unk24E = 0;
    SPAD->unk244 = 0;
    (*(short *)&SPAD->unk250) = 0;
    SPAD->unk246 = 0;
    SPAD->unk252 = 0;
    SPAD->unk24A = 0;
    SPAD->unk254 = 0;
    (*(short *)&SPAD->unk24C) = 0;
    SPAD->unk258 = 0;
    SPAD->unk242 = 0;
    SPAD->unk256 = 0;
    SPAD->unk248 = 0;
    (*(int* *)&SPAD->unk22C) = &D_800A5858;
    (*(int* *)&SPAD->unk270) = &D_800A5858;
    SPAD->unk25A = 0;
    SPAD->unk240 = 0;
}

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", resetCamera);
void resetCamera(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    getBaseMatrix(SCRATCH_VIEW_MATRIX);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -NTSC_PAL(120, 128);
    SPAD->unk200 = 69;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    SPAD->unk3CE = 0;
    (*(short *)&SPAD->unk1C8) = 0;
    SPAD->unk3D1 = 0;
    LOADED_LIST_FILE = 0xFF;
    LOADED_SOUND_SET = 0xFF;
    D_8009EBA0 = 0;
}
