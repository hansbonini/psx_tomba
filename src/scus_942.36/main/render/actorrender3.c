#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004B450);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBox);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBoxFrame);

void drawMessageBoxFrame(u8* self)
{
    u8 pad[0x60];
    unk_8004C1E4 v;

    drawMessageGlyphs(*(u16*)(self + 0xCA));
    v.unk10 = -1;
    v.unk8[0] = *(u16*)(self + 0xBE);
    v.unk8[1] = *(u16*)(self + 0xC0);
    v.unk8[2] = *(u16*)(self + 0xC2);
    v.unk8[3] = *(u16*)(self + 0xC4);
    drawBalloonFrame(&v, 0, *(s16*)(self + 0x1E));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawBalloonFrame);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004CC84);
