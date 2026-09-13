#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DC34);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DD14);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DFA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E244);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E3EC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E468);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E590);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E714);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E900);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004EB10);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004ED80);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004EFA8);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", addDrawModePrim);
void addDrawModePrim(short tpage, int p) {
    scratchpad* scratch = PSX_SCRATCH;
    DR_MODE* mode = scratch->nextprim;

    SetDrawMode(mode, 0, 0, tpage, 0);
    AddPrim(scratch->ot + (p * 4),mode);
    scratch->nextprim += sizeof(DR_MODE);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004F2CC);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004F3DC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", addTilePrim);
void addTilePrim(short* p, u_char r0, u_char g0, u_char b0)
{
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004F5A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004FB54);
