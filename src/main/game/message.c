#include "common.h"
#include "game.h"

s16 loadMessageGlyph(s32 p, s32 id, s32 bank);

// INCLUDE_ASM("nonmatchings/main/game/message", updateInfoMessage);
typedef struct S_30EF8 {
    char p0; u8 b01; char p1[2]; u8 b04; char p2[0x20 - 5];
    s16 timer; char p3[0xb4 - 0x22];
    u16 wb4, wb6; char p4[0xbe - 0xb8];
    u16 wbe, wc0; char p5[0xca - 0xc2];
    u16 wca;
} S_30EF8;
typedef struct M2_30EF8 { u16 mask; s16 pad[4]; } M2_30EF8;
extern M2_30EF8 D_800A5142[];
void updateInfoMessage(S_30EF8 *o)
{
    s32 i;
    switch (o->b04) {
    case 0:
        o->b04++;
        if (o->wb6 == 2 && o->wb4 == 0)
            o->timer = 0x28;
        else
            o->timer = 0x78;
        break;
    case 1:
        MESSAGE_SLOTS[o->wca].x = o->wbe;
        MESSAGE_SLOTS[o->wca].y = o->wc0;
        o->b01 = 1;
        pushEffectDrawList(o);
        if (--o->timer == 0 || MESSAGE_SLOTS[o->wca].unk2 == -1) {
            MESSAGE_SLOTS[o->wca].unk2 = -1;
            o->b04++;
        }
        break;
    case 2:
        for (i = 0; i < MESSAGE_SLOTS[o->wca].count; i++) {
            s32 v = (s16)MESSAGE_GLYPHS[o->wca][i].id * 10;
            if ((*(u16 *)((char *)D_800A5142 + v) &= ~(1 << o->wca)) == 0)
                *(s16 *)((char *)GLYPH_CACHE + v) = -1;
        }
        MESSAGE_SLOTS[o->wca].count = -1;
        o->b04++;
        break;
    case 3:
        freeEffectObject(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/message", printInfoMessage);
static inline void placeInfoMessage(InfoMessage *o, s16 x, s16 y)
{
    o->lineY = 0;
    o->lineX = -((u16)o->width >> 1);
    S16(o, 0xC0) = y + o->lineY;
    S16(o, 0xBE) = x + o->lineX;
}

#if REGION != REGION_JP
static inline void drawInfoMessageTitle(InfoMessage *o, s32 id)
{
    s32 i = 0;
    s8 c;

    do {
        c = D_8007D2D8[i];
        if (c == -1) {
            drawInfoMessageText(o, 0);
            return;
        }
        i++;
    } while (c != id);
    drawInfoMessageText(o, 1);
}
#endif

void *printInfoMessage(s32 id, s32 kind)
{
    s32 i;
    u8 *pair;
    u8 *index;
    s16 skip;
    InfoMessage *o;
    u16 *str;
    u16 tok;
    u16 *q;
    char *base;
    u16 half;

    D_8009BCAB = 0xFF;
    for (i = 2; i >= 0; i--) {
        if (MESSAGE_SLOTS[i].count == -1) {
            D_8009BCAB = i;
            MESSAGE_SLOTS[i].unk2 = i;
            break;
        }
    }
    if (D_8009BCAB == 0xFF) {
        return NULL;
    }
    if (kind == 1) {
        playSFX(0xC);
    }
    if ((u32)(kind - 2) < 2) {
        pair = D_8007CF6C[id];
        pair += GAME.selectedArea * 2;
        if (*pair == 0xFF) {
            pair = D_8007CF44;
            pair += GAME.selectedArea * 2;
        }
    } else {
        index = D_8007D288[GAME.selectedArea];
        index += id;
    }
    skip = 0;
    o = allocEffectObject();
    if (o != NULL) {
        o->active = 1;
        o->type = 0x1C;
        o->unkA = 0xC;
        o->tpage = 0x14;
        S16(o, 0x2C) = 0;
        o->unkF = 0;
        S32(o, 0x10) = 0xA00000;
        o->z = 0;
        o->id = id;
        o->kind = kind;
#if REGION == REGION_JP
        o->y.raw = (0xB4 - (2 - D_8009BCAB) * 20) << 16;
#else
        o->y.raw = (0xB4 - (3 - D_8009BCAB) * 20) << 16;
#endif
#if REGION == REGION_JP
        if ((u32)(kind - 2) < 2) {
            o->width = D_8007D1AC[id] + 0x10;
        } else if (kind == 0) {
            o->width = D_8007D05C[id] + 0x40;
        } else {
            o->width = D_8007D05C[id] + 0x4C;
        }
#else
        switch (kind) {
        case 0:
            o->width = D_8007D05C[id] + 0x60;
            break;
        case 1:
            o->width = D_8007D05C[id] + 0x78;
            break;
        case 2:
        case 3:
            o->width = D_8007D1AC[id] + 0x10;
            break;
        }
#endif
        S16(o, 0xC4) = 0x14;
        U16(o, 0xC6) = 0xFFFF;
        placeInfoMessage(o, o->x.p.whole, o->y.p.whole);
        i = 1;
        o->slot = D_8009BCAB;
        S16(o, 0x20) = i;
        S16(o, 0xCE) = 8;
#if REGION == REGION_JP
        S16(o, 0xD0) = 7;
#else
        S16(o, 0xD0) = 6;
#endif
        S16(o, 0x22) = 0;
        o->unkCC = i;
        MESSAGE_SLOTS[o->slot].count = 0;
        base = (char *)SPAD->wfm3Data;
        if ((u32)(kind - 2) < 2) {
            q = (u16 *)(pair[0] * 2 + (s32)base);
            o->text = q[8] + pair[1];
        } else {
            s16 c = *index;

            q = (u16 *)(base + (D_8007D274[GAME.selectedArea] * 2 + 0x10));
            if ((u8)c == 0xFF) {
                pair = D_8007CF44 + GAME.selectedArea * 2;
                q = (u16 *)(pair[0] * 2 + (s32)base);
                o->text = q[8] + pair[1];
            } else {
                o->text = c + *q;
            }
        }
#if REGION != REGION_JP
        if (kind == 1) {
            drawInfoMessageTitle(o, id);
        }
#endif
        base = (char *)SPAD->wfm3Data;
        base += *(s16 *)(base + 8);
        q = (u16 *)(base + (u16)o->text * 2);
        str = (u16 *)(base + *(s16 *)q);
        while (1) {
            tok = *str++;
            if ((u16)(tok + 2) < 2) {
#if REGION != REGION_JP
                if (kind == 0 || kind == 3) {
                    drawInfoMessageText(o, 2);
                }
#endif
                return o;
            }
            if (skip == 0 || (s16)tok == -12) {
                switch ((s16)tok) {
#if REGION == REGION_JP
                case (s16)MSG_NEWLINE:
                    o->cursorX = o->left + 8;
                    o->cursorY += 0xD;
                    break;
#endif
                case (s16)MSG_CLEAR:
                    o->cursorX = o->left + 8;
                    o->cursorY = o->top + 8;
                    break;
#if REGION == REGION_JP
                case (s16)MSG_BOX:
                    {
                        u16 h = o->lineHeight;
                        u16 dx;
                        half = (u16)o->width >> 1;
                        o->width = *str++;
                        o->lineHeight = *str++;
                        dx = *str++;
                        o->lineY = 0;
                        o->lineX = -((u16)o->width >> 1);
                        o->cursorX = 8;
                        o->cursorY = 8;
                        {
                            s16 t = o->left + half;
                            o->left = dx + (t + o->lineX);
                        }
                        {
                            s16 t = o->top + h;
                            o->top = t + o->lineY;
                        }
                    }
                    break;
#else
                case (s16)MSG_BOX:
                    half = (u16)o->width >> 1;
                    str += 2;
                    o->lineY = 0;
                    o->lineX = -half;
                    {
                        s16 t = o->top + o->lineHeight;
                        o->top = t + o->lineY;
                    }
                    {
                        s16 t = o->left + half;
                        o->left = t + o->lineX;
                    }
                    break;
#endif
                case (s16)MSG_VOICE:
                    o->color = *str++;
                    break;
                case -12:
                    if (kind != 1) {
                        skip ^= 1;
                    }
                    break;
                default:
#if REGION == REGION_JP
                    {
                        u16 r;
                        id = MESSAGE_SLOTS[o->slot].count++;
                        r = ((s32 (*)(s32, s32, s32))loadMessageGlyph)(o->slot, tok & 0xFFF, 0);
                        if ((tok & 0x7000) == 0x4000) {
                            MESSAGE_GLYPHS[o->slot][id].id = r | 0x4000;
                            MESSAGE_GLYPHS[o->slot][id].x = (u16)o->width - 0x10;
                            MESSAGE_GLYPHS[o->slot][id].y = (u16)o->lineHeight - 0x10;
                        } else {
                            MESSAGE_GLYPHS[o->slot][id].id = r;
                            MESSAGE_GLYPHS[o->slot][id].x = (u16)o->cursorX;
                            MESSAGE_GLYPHS[o->slot][id].y = (u16)o->cursorY;
                        }
                        if ((tok & 0x7000) == 0x5000 || (tok & 0x7000) != 0x6000) {
                            o->cursorX += GLYPH_CACHE[(s16)r].w;
                        }
                    }
#else
                    drawMessageGlyph(o, (s16)tok);
#endif
                    break;
                case (s16)MSG_DELAY:
                case (s16)MSG_WAIT:
#if REGION != REGION_JP
                case (s16)MSG_NEWLINE:
#endif
                case (s16)MSG_CLOSE:
                case (s16)MSG_END:
                    break;
                }
            }
        }
    }
    return o;
}


#if REGION != REGION_JP
void drawInfoMessageText(void* obj, s32 stringIndex)
{
    u8*      base;
    s16*     tbl;
    s16*     ent;
    u_short* str;
    s32      token;

    base = *(u8**)(PSX_SCRATCH + 0x398);
    tbl  = (s16*)(base + *(s16*)(base + 8));
    ent  = tbl + stringIndex;
    str  = (u_short*)((u8*)tbl + *ent);

    for (;;) {
        token = *str++;

        if ((u_short)(token + 2) < 2) {
            return;
        }
        if ((s16)token == -3) continue;
        if ((s16)token == -7) continue;
        if ((s16)token == -6) {
            str += 2;
            continue;
        }
        drawMessageGlyph(obj, (s16)token);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/message", drawMessageGlyph);

typedef struct { char p[0xc2]; u16 w2, w4; char q[4]; u16 idx; char r[2]; u16 wce, wd0; } O_316EC;

void drawMessageGlyph(O_316EC *o, u16 k)
{
    s32 n;
    s32 r;
    n = MESSAGE_SLOTS[o->idx].count++;
    r = ((s32 (*)(s32, s32, s32))loadMessageGlyph)(o->idx, k & 0xfff, 0);
    if ((k & 0x7000) == 0x4000) {
        MESSAGE_GLYPHS[o->idx][n].id = r | 0x4000;
        MESSAGE_GLYPHS[o->idx][n].x = o->w2 - 0x10;
        MESSAGE_GLYPHS[o->idx][n].y = o->w4 - 0x10;
    } else {
        MESSAGE_GLYPHS[o->idx][n].id = r;
        MESSAGE_GLYPHS[o->idx][n].x = o->wce;
        MESSAGE_GLYPHS[o->idx][n].y = o->wd0;
    }
    if ((k & 0x7000) == 0x5000 || (k & 0x7000) != 0x6000)
        o->wce += GLYPH_CACHE[r].w;
}

#endif

// INCLUDE_ASM("nonmatchings/main/game/message", dispatchAreaDialogInit);
void dispatchAreaDialogInit(void)
{
    switch (GAME.selectedArea) {
        case AREA05_BACCUSVILLAGE:
            func_800EF7C0();
            return;
        case AREA11_VILLAGEOFCIVILIZATION:
            func_800F5D5C();
            return;
        case AREA16_VILLAGEOFCIVILIZATIONCLOCKTOWER:
            func_800EFC0C();
            return;
        case AREA17_VILLAGEOFCIVILIZATIONIRONTOWER:
            func_800F026C();
            return;
        case AREA08_BACCUSLAKE:
            func_800F0A60();
            return;
        case AREA19_VILLAGEOFCIVILIZATIONPURIFIED:
            func_800F0590();
        default:
            return;
    }
}
