#include "common.h"
#include "game.h"


UiSpriteDef D_8007B2F4_data[2] asm("D_8007B2F4") = {
    { 0x70, 0, 0x30, 0x30, 0x30, 0x47 },
    { 0xA0, 0, 0x30, 0x30, 0x30, 0x47 }
};

asm(".globl D_8007B2F6\nD_8007B2F6 = D_8007B2F4 + 2");
asm(".globl D_8007B2F8\nD_8007B2F8 = D_8007B2F4 + 4");
asm(".globl D_8007B2FA\nD_8007B2FA = D_8007B2F4 + 6");
asm(".globl D_8007B2FC\nD_8007B2FC = D_8007B2F4 + 8");
asm(".globl D_8007B2FE\nD_8007B2FE = D_8007B2F4 + 10");

UiSpriteDef D_8007B30C[3] = {
    { 0, 0, 0x70, 0x47, 0x10, 0x47 },
    { 0xB8, 0xC0, 0x28, 0x10, 0x160, 0x1FD },
    { 0xB8, 0xD0, 0x38, 0x10, 0x160, 0x1FD }
};


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", fontDebugPrintf);
void fontDebugPrintf(short x, short y, short color, char* fmt)
{
    SPRT_8 buf;
    SPRT_8* sprt;
    SPRT_8* dst;
    DR_MODE* mode;

    sprt = &buf;
    while (*fmt != 0) {
        if ((u_int)D_8009C8A8 >= (u_int)(D_800A1FF8 + D_1F8001F4 * 0x780)) {
            break;
        }
        setlen(sprt, 3);
        setcode(sprt, 0x75);
        setRGB0(sprt, 128, 128, 128);
        setXY0(sprt, x, y);
        setSemiTrans(sprt, 0);
        setUV0(sprt, (*fmt & 0xF) << 3, (*fmt >> 4) << 3);
        setClut(sprt, 0x170, color + 0x1F0);
        dst = D_8009C8A8;
        *dst = *sprt;
        addPrim(D_1F8001E0, dst);
        D_8009C8A8 += sizeof(SPRT_8);
        fmt++;
        x += 8;
    }

    mode = D_8009C8A8;
    if ((u_int)mode < (u_int)(D_800A2008 + D_1F8001F4 * 0x780)) {
        SetDrawMode(mode, 0, 0, 0x15, NULL);
        addPrim(CURRENT_OT, mode);
        D_8009C8A8 += sizeof(DR_MODE);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawLoadingSprites);
void drawLoadingSprites(int arg0, int arg1)
{
    int i;
    int j;
    DR_MODE* mode;

    if (GetGraphType() != 1) {
        GetGraphType();
    }
    drawNowLoadingSprite(192, 128, 0, 0, arg1);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if ((j + i) & 1) {
                drawUiSprite(j * 48, i * 48, 1 - arg0);
            } else {
                drawUiSprite(j * 48, i * 48, arg0);
            }
        }
    }

    mode = D_8009C8A8;
    SetDrawMode(mode, 0, 0, 0, NULL);
    addPrim(CURRENT_OT, mode);
    D_8009C8A8 += sizeof(DR_MODE);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawNowLoading);
void drawNowLoading(short arg0)
{
    int graphType = GetGraphType();
    int tpage = 36;
    if (graphType != 1) {
        graphType = GetGraphType();
        asm("");
        if (graphType == 2) {
            tpage = 36;
        } else {
            tpage = 20;
        }
    }
    drawNowLoadingSprite(104, 96, 1, tpage, arg0);
    drawNowLoadingSprite(160, 96, 2, tpage, arg0);
    return;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawUiSprite);
void drawUiSprite(short x, short y, short sprt_id)
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
    setSemiTrans(sprt, 0);
    setUV0(sprt, *(u_short*)&D_8007B2F4[sprt_ofs], *(u_short*)(&D_8007B2F6[sprt_ofs]));
    setWH(sprt, *(u_short*)(&D_8007B2F8[sprt_ofs]), *(u_short*)(&D_8007B2FA[sprt_ofs]));
    setClut(sprt, (short) *(&D_8007B2FC[sprt_ofs]), (short) *(&D_8007B2FE[sprt_ofs]));
    addPrim(CURRENT_OT, sprt);
    D_8009C8A8 += sizeof(SPRT);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawNowLoadingSprite);
void drawNowLoadingSprite(int x, int y, short sprt_id, short tpage, short arg4)
{
    int pad;
    int w;
    int h;
    POLY_FT4* poly;

    if (sprt_id == 0) {
        int scale = D_8007D988[arg4];
        pad = (u_int)scale >> 11;
    } else {
        int scale = D_8007D988[arg4];
        pad = ((scale << 6) >> 16) + 4;
    }

    poly = D_8009C8A8;
    setPolyFT4(poly);
    setRGB0(poly, 128, 128, 128);
    setSemiTrans(poly, 0);
    poly->x0 = x - pad;
    poly->y0 = y - pad;
    w = D_8007B30C[sprt_id].w;
    poly->x1 = pad + (x + w);
    poly->y1 = y - pad;
    poly->x2 = x - pad;
    h = D_8007B30C[sprt_id].h;
    poly->y2 = pad + (y + h);
    w = D_8007B30C[sprt_id].w;
    poly->x3 = pad + (x + w);
    h = D_8007B30C[sprt_id].h;
    poly->y3 = pad + (y + h);
    poly->u0 = D_8007B30C[sprt_id].u;
    poly->v0 = D_8007B30C[sprt_id].v;
    poly->u1 = poly->u0 + D_8007B30C[sprt_id].w - 1;
    poly->v1 = poly->v0;
    poly->u2 = poly->u0;
    poly->v2 = poly->v0 + D_8007B30C[sprt_id].h - 1;
    poly->u3 = poly->u1;
    poly->v3 = poly->v2;
    setClut(poly, D_8007B30C[sprt_id].clutX, D_8007B30C[sprt_id].clutY);
    poly->tpage = tpage;
    addPrim(CURRENT_OT, poly);
    D_8009C8A8 += sizeof(POLY_FT4);
}
