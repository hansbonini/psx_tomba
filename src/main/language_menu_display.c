#include "common.h"
#include "game.h"

extern DRAWENV languageMenuDrawEnv;

void initLanguageMenuDisplay(u_char r0, u_char g0, u_char b0)
{
    DISPENV* dispenv1;
    DISPENV* dispenv2;
    DRAWENV* drawenv1;
    DRAWENV* drawenv2;

    drawenv1 = &languageMenuDrawEnv;
    dispenv1 = (DISPENV*)((byte*)drawenv1 - sizeof(DISPENV));
    drawenv2 = (DRAWENV*)((byte*)drawenv1 + 0x90);
    dispenv2 = (DISPENV*)((byte*)drawenv1 + 0x90 - sizeof(DISPENV));
    SetDefDrawEnv(drawenv1, 384, 256, 320, 256);
    SetDefDispEnv(dispenv1, 704, 256, 320, 256);
    SetDefDrawEnv(drawenv2, 704, 256, 320, 256);
    SetDefDispEnv(dispenv2, 384, 256, 320, 256);
    setRECT(&dispenv1->screen, 4, 16, 256, 256);
    setRECT(&dispenv2->screen, 4, 16, 256, 256);
    drawenv1->isbg = drawenv2->isbg = true;
    drawenv1->dtd = drawenv2->dtd = true;
    drawenv1->dfe = drawenv2->dfe = false;
    setRGB0(drawenv1, r0, g0, b0);
    setRGB0(drawenv2, r0, g0, b0);
    PutDispEnv(dispenv1);
    PutDrawEnv(drawenv1);
}
