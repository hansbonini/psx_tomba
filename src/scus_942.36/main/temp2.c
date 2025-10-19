#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80022C08);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80022D3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80022E44);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80022F6C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80022FD8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023020);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800230BC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023168);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002331C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002337C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800233B8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023608);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002367C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800236F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023840);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800238B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023928);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023A3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", FontDebugPrintf);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", drawLoadingSprites);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023E44);
void func_80023E44(short arg0)
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

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80023ED0);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", drawNowLoadingSprite);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024254);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800242AC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800243E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024624);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002467C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800246B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024AA8);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024AEC);
void func_80024AEC(MATRIX* dst)
{
    *dst=*(MATRIX*)(&D_1F8000F8);
    return;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024B3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024BD4);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024CE4);
void func_80024CE4(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024CEC);
void func_80024CEC(void) {
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024CF4);
void func_80024CF4(void) {
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024CFC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80024EEC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800251C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800253C8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002564C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80025810);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80025A38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80025C14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80025E74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002601C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80026228);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800263F0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80026694);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80026E48);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80027600);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800279E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80027A30);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028638);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", joypadInit);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028794);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800287F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_800288C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028A74);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028B34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028CE4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028D70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80028EF4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_80029008);

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/main/temp2", D_80010368);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp2", func_8002907C);
