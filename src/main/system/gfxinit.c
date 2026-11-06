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
    initWeaponPool();
    initActorPool();
    initActorDrawList();
    initEffectDrawList();
    initAreaDrawList();
    initModelPool();
    initItemDrawList();
    clearOtBuffer();
    initFxPool();
    clearLayer1Buffer();
    initAreaCtrlPool();
    clearMenuState();
    clearMenuParams();
}

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", resetDrawLists);
void resetDrawLists(void)
{
    (*(int* *)&SPAD->weaponDrawList) = &D_800B0528;
    (*(int* *)&SPAD->weaponHeldList) = &D_800B0528;
    (*(int* *)&SPAD->actorDrawList) = &D_800A5970;
    (*(int* *)&SPAD->actorHeldList) = &D_800A5970;
    (*(int* *)&SPAD->effectDrawList) = &D_800B0680;
    (*(int* *)&SPAD->effectHeldList) = &D_800B0680;
    (*(int* *)&SPAD->areaDrawList) = &D_800B0470;
    (*(int* *)&SPAD->areaHeldList) = &D_800B0470;
    (*(int* *)&SPAD->modelDrawList) = &D_800B3184;
    (*(int* *)&SPAD->modelHeldList) = &D_800B3184;
    (*(int* *)&SPAD->itemDrawList) = &D_800B04F0;
    *(int** )0x1F80026C = &D_800B04F0;
    SPAD->weaponHeldCount = 0;
    SPAD->weaponDrawCount = 0;
    (*(short *)&SPAD->actorHeldCount) = 0;
    SPAD->actorDrawCount = 0;
    SPAD->effectHeldCount = 0;
    SPAD->effectDrawCount = 0;
    SPAD->areaHeldCount = 0;
    (*(short *)&SPAD->areaDrawCount) = 0;
    SPAD->modelHeldCount = 0;
    SPAD->modelDrawCount = 0;
    SPAD->itemHeldCount = 0;
    SPAD->itemDrawCount = 0;
    (*(int* *)&SPAD->fxDrawList) = &D_800A5858;
    (*(int* *)&SPAD->fxHeldList) = &D_800A5858;
    SPAD->fxHeldCount = 0;
    SPAD->fxDrawCount = 0;
}

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", resetCamera);
void resetCamera(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    getBaseMatrix(SCRATCH_VIEW_MATRIX);
    camera->vrz = -544; 
    camera->vpx = 160;
    camera->vpy = -NTSC_PAL(120, 128);
    SPAD->randomSeed = 69;
    camera->vrx = 0;
    camera->vry = 0;
    camera->vpz = 0;
    SPAD->pauseMenuLock = 0;
    (*(short *)&SPAD->axisSwap) = 0;
    SPAD->warpFadeActive = 0;
    LOADED_LIST_FILE = 0xFF;
    LOADED_SOUND_SET = 0xFF;
    D_8009EBA0 = 0;
}
