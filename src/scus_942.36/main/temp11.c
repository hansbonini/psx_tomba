#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003C9D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003CE18);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D0E4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D1B0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D20C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D25C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D2A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D5F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D648);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D6C0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D72C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D77C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D7CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D824);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D874);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D8EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D920);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D950);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D9C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003D9F4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DA28);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DA9C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DB04);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DB70);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DC38);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DCF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DE90);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DEBC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DF10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DF3C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DF88);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DFCC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003DFF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E014);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E0A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E0E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E12C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E1A8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E1F8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E248);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E298);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E2E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E30C);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E330);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E3C4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E3E8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003E408);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", LZDecompress);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003F0DC);
void func_8003F0DC(char* src, char* dst, char* len)
{
    bzero(dst, len);
    LZDecompress(src, dst);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003F124);
void func_8003F124(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF5B0();
            return;
        case AREA08_BACCUSLAKE:
            func_800F08C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F1CA8();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800F2D84();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F428C();
            return;
        case AREA18_VILLAGEOFCIVILIZATIONYCROSSING:
            func_800F448C();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F5B4C();
            // fallthrough
        default:
            return;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/temp11", func_8003F1D4);
