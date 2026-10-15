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

// INCLUDE_ASM("nonmatchings/main/system/gfxinit", resetCamera);
#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
typedef struct SPADBlock_17798 {
    unsigned char b0;
    unsigned char _pad1[0x5f];
    short s60;
    short s62;
    short s64;
    unsigned char _pad66[0xe];
    int i74;
    int i78;
    unsigned char _pad7c[0x10];
    int i8c;
    unsigned char _pad90[0x30];
    unsigned char bc0;
    unsigned char _padc1[0x13];
    int id4;
    int id8;
    int idc;
    int ie0;
    unsigned char _pade4[0x2];
    short se6;
    unsigned char _pade8[0x2];
    short sea;
    int iec;
    int if0;
    int if4;
    unsigned char _padf8[0x20];
    unsigned char b118;
    unsigned char _pad119[0x4b];
    void * p164;
    int i168;
    int i16c;
    int i170;
    int i174;
    unsigned char _pad178[0x2];
    unsigned short s17a;
    unsigned char _pad17c[0x2];
    unsigned short s17e;
    unsigned char _pad180[0x6];
    unsigned short s186;
    unsigned char _pad188[0x4];
    int i18c;
    int i190;
    unsigned char _pad194[0x4];
    int i198;
    short s19c;
    short s19e;
    unsigned char b1a0;
    unsigned char _pad1a1[0x3];
    unsigned char b1a4;
    unsigned char b1a5;
    unsigned char _pad1a6[0x1c];
    unsigned char b1c2;
    unsigned char _pad1c3[0x1];
    unsigned char b1c4;
    unsigned char b1c5;
    short s1c6;
    unsigned short s1c8;
    unsigned char _pad1ca[0x2];
    unsigned char b1cc;
    unsigned char b1cd;
    unsigned char _pad1ce[0x1];
    unsigned char b1cf;
    unsigned char b1d0;
    unsigned char b1d1;
    unsigned char b1d2;
    unsigned char b1d3;
    unsigned char _pad1d4[0xc];
    int i1e0;
    unsigned char _pad1e4[0x4];
    short s1e8;
    unsigned char _pad1ea[0xa];
    short s1f4;
    short s1f6;
    unsigned short s1f8;
    unsigned char _pad1fa[0x2];
    unsigned short s1fc;
    unsigned short s1fe;
    unsigned char _pad200[0x1c];
    void * p21c;
    unsigned char _pad220[0x4];
    void * p224;
    void * p228;
    unsigned char _pad22c[0xc];
    short s238;
    unsigned char _pad23a[0xc];
    short s246;
    unsigned short s248;
    unsigned char _pad24a[0x2];
    short s24c;
    unsigned char _pad24e[0x2];
    unsigned short s250;
    unsigned char _pad252[0x2];
    unsigned short s254;
    short s256;
    unsigned char _pad258[0x8];
    void * p260;
    unsigned char _pad264[0x4];
    void * p268;
    void * p26c;
    unsigned char _pad270[0x8];
    void * p278;
    unsigned char _pad27c[0x2];
    short s27e;
    short s280;
    unsigned short s282;
    short s284;
    short s286;
    unsigned char _pad288[0x2c];
    int i2b4;
    unsigned char _pad2b8[0x18];
    int i2d0;
    int i2d4;
    int i2d8;
    int i2dc;
    int i2e0;
    int i2e4;
    int i2e8;
    unsigned char _pad2ec[0x4];
    int i2f0;
    unsigned char _pad2f4[0x4];
    int i2f8;
    unsigned char _pad2fc[0x4];
    int i300;
    int i304;
    void * p308;
    void * p30c;
    int i310;
    int i314;
    int i318;
    void * p31c;
    unsigned char _pad320[0x14];
    int i334;
    void * p338;
    void * p33c;
    unsigned char _pad340[0x1c];
    int i35c;
    unsigned char _pad360[0x10];
    int i370;
    int i374;
    int i378;
    unsigned char _pad37c[0x3c];
    unsigned short s3b8;
    unsigned short s3ba;
    short s3bc;
    unsigned char _pad3be[0x2];
    void * p3c0;
    unsigned short s3c4;
    unsigned short s3c6;
    unsigned short s3c8;
    unsigned char _pad3ca[0x4];
    unsigned char b3ce;
    unsigned char _pad3cf[0x1];
    unsigned char b3d0;
    unsigned char b3d1;
    unsigned char _pad3d2[0x2e];
} SPADBlock_17798;
extern SPADBlock_17798 SCRATCHPAD__resetCamera;

extern short D_8009EBA0__resetCamera;
extern void getBaseMatrix__resetCamera();

void resetCamera(void)
{
    getBaseMatrix__resetCamera(((char*)&SCRATCHPAD__resetCamera.bc0));
    *(short *)0x1F8000EA = -0x220;
    *(short *)0x1F8000EE = 0xA0;
    *(short *)0x1F8000F2 = -0x80;
    *(int *)0x1F800200 = 0x45;
    *(short *)0x1F8000E2 = 0;
    *(short *)0x1F8000E6 = 0;
    *(short *)0x1F8000F6 = 0;
    *(char *)0x1F8003CE = 0;
    *(short *)0x1F8001C8 = 0;
    *(char *)0x1F8003D1 = 0;
    *(char *)0x1F8003D2 = 0xFF;
    *(char *)0x1F8003D3 = 0xFF;
    D_8009EBA0__resetCamera = 0;
}
#else
void resetCamera(void)
{
    CAMERA* camera = (CAMERA*)0x1F8000E2;
    getBaseMatrix(SCRATCH_VIEW_MATRIX);
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
    LOADED_LIST_FILE = 0xFF;
    LOADED_SOUND_SET = 0xFF;
    D_8009EBA0 = 0;
}
#endif
