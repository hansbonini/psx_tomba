#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", fontDebugPrintf);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawLoadingSprites);

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
    sprt->code = (u_char) (sprt->code & 0xFD);
    setUV0(sprt, *(u_short*)&D_8007B2F4[sprt_ofs], *(u_short*)(&D_8007B2F6[sprt_ofs]));
    setWH(sprt, *(u_short*)(&D_8007B2F8[sprt_ofs]), *(u_short*)(&D_8007B2FA[sprt_ofs]));
    setClut(sprt, (short) *(&D_8007B2FC[sprt_ofs]), (short) *(&D_8007B2FE[sprt_ofs]));
    addPrim(CURRENT_OT, sprt);
    D_8009C8A8 += sizeof(SPRT);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/drawutil", drawNowLoadingSprite);
