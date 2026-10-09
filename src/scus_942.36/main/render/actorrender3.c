#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004B450);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004BAF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBox);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBoxFrame);

void drawMessageBoxFrame(u8* self)
{
    u8 pad[0x60];
    BalloonFrame v;

    drawMessageGlyphs(*(u16*)(self + 0xCA));
    v.tail = -1;
    v.rect.x = *(u16*)(self + 0xBE);
    v.rect.y = *(u16*)(self + 0xC0);
    v.rect.w = *(u16*)(self + 0xC2);
    v.rect.h = *(u16*)(self + 0xC4);
    drawBalloonFrame(&v, 0, *(s16*)(self + 0x1E));
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawBalloonFrame);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004CC84);
