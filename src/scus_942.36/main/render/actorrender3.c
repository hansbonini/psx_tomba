#include "common.h"
#include "game.h"
#include "game/gte.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004B450);
typedef struct { s16 n, p2, x0, y0, x1, y1; char pad[8]; } ENT_4B450;
typedef struct { ENT_4B450 e[7]; } ROW_4B450;
typedef struct { char pad[0x4c]; u16 w4c; } C4C_4B450;
extern unsigned long LZ_FILE_CTRL_UnsignedLong asm("LZ_FILE_CTRL");
extern char D_1F8000C0_CharArr[] asm("D_1F8000C0");
extern ROW_4B450 LOAD_BUFFER_ROW_4B450Arr[] asm("LOAD_BUFFER");


#define WC6(o) (*(u16 *)((char *)(o) + 0xc6))

static __inline__ s32 proj_4B450(void)
{
    gte_ldv0((s16 *)&D_1F800060);
    gte_rtps();
    gte_stflg(&D_1F80008C);
    if (D_1F80008C < 0) return 1;
    gte_stsxy(&LZ_FILE_CTRL_UnsignedLong);
    gte_stszotz(&D_1F800074);
    return 0;
}

static __inline__ s32 otadd_4B450(unsigned long *a, char *b, s32 c, s32 d, unsigned long e)
{
    d = ((s8)d + c) << 2;
    if (d < 0) d = 0;
    d += (s32)b;
    if ((u32)(d - (s32)D_1F8001E0) >= 0xca0) return 1;
    {
        unsigned long v = *(unsigned long *)d;
        *(unsigned long *)d = (unsigned long)a;
        *a = v | e;
    }
    return 0;
}

void func_8004B450(GameObject *o)
{
    POLY_FT4 *p;
    u8 *q;
    s32 i;
    s16 *e;
    s32 d;
    ROW_4B450 *tbl;
    s16 x;
    s32 y;
    unsigned long xy;
    s32 u;
    s32 v;
    u8 w;
    s32 h;

    D_1F800060.vx = o->x.p.whole;
    D_1F800062 = o->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_4B450 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = o->z.p.whole >> 2;
    else
        D_1F800064 = o->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_4B450()) return;
    xy = LZ_FILE_CTRL_UnsignedLong;
    x = xy;
    y = xy >> 16;
    tbl = (ROW_4B450 *)LOAD_BUFFER;
    for (i = 0; i < 6; i++) {
        if ((&tbl[WC6(o)].e[i])->n > 0) {
            d = o->spriteBank;
            d += *(*(s16 ***)&D_800A37D0)[((u16 *)&o->unkB4)[i]] * 4;
            p = D_1F800164;
            q = (u8 *)(o->spriteBank + ((s16 *)d)[1]);
            p->code = 0x2d;
            SetSemiTrans(p, 0);
            u = q[0];
            v = q[1];
            w = q[10];
            h = q[11];
            p->u0 = u;
            __asm__ volatile("");
            p->u2 = u;
            p->v0 = v;
            p->u1 = u + w;
            p->v1 = v;
            p->v2 = v + h;
            p->u3 = u + w;
            p->v3 = v + h;
            p->x0 = x + (&tbl[WC6(o)].e[i])->x0 / 100;
            p->y0 = y + (&tbl[WC6(o)].e[i])->y0 / 100;
            p->x1 = x + (&tbl[WC6(o)].e[i])->x1 / 100;
            p->y1 = p->y0;
            p->x2 = p->x0;
            p->y2 = y + (&tbl[WC6(o)].e[i])->y1 / 100;
            p->x3 = p->x1;
            p->y3 = p->y2;
            p->tpage = o->tpage;
            p->clut = *(u16 *)(q + 2);
            if (!otadd_4B450((unsigned long *)p, D_1F8001E0, 0, o->unkF, 0x9000000))
                D_1F800164 = (POLY_FT4 *)((char *)D_1F800164 + 0x28);
        }
    }
    d = o->spriteBank;
    d += *D_800AFF10 * 4;
    p = D_1F800164;
    q = (u8 *)(o->spriteBank + ((s16 *)d)[1]);
    p->code = 0x2d;
    SetSemiTrans(p, 0);
    u = q[0];
    v = q[1];
    w = q[10];
    h = q[11];
    p->u0 = u;
    __asm__ volatile("");
    p->u2 = u;
    p->v0 = v;
    p->u1 = u + w;
    p->v1 = v;
    p->v2 = v + h;
    p->u3 = u + w;
    p->v3 = v + h;
    p->x0 = x + ((ROW_4B450 *)LOAD_BUFFER)[WC6(o)].e[6].x0 / 100;
    p->y0 = y + LOAD_BUFFER_ROW_4B450Arr[WC6(o)].e[6].y0 / 100;
    p->x1 = x + LOAD_BUFFER_ROW_4B450Arr[WC6(o)].e[6].x1 / 100;
    p->y1 = p->y0;
    p->x2 = p->x0;
    p->y2 = y + LOAD_BUFFER_ROW_4B450Arr[WC6(o)].e[6].y1 / 100;
    p->x3 = p->x1;
    p->y3 = p->y2;
    p->tpage = o->tpage;
    p->clut = *(u16 *)(q + 2);
    if (!otadd_4B450((unsigned long *)p, D_1F8001E0, 0, o->unkF, 0x9000000))
        D_1F800164 = (POLY_FT4 *)((char *)D_1F800164 + 0x28);
}
#undef WC6

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004BAF0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBox);
typedef struct O_4BDE4 { char p0[0x1e]; s16 v1e; char p20[2]; s16 v22; char p24[0x92]; u16 m; char pb8[6];
    u16 a, b, c, d; char pc6[4]; u16 idx; } O_4BDE4;
typedef struct L_4BDE4 { s16 x0, x1, x2, x3; s16 a, b, c, d; s16 m; s16 pad[7]; } L_4BDE4;

void drawMessageBox(O_4BDE4 *o)
{
    char env[0x60];
    L_4BDE4 l;
    void *r;
    s32 i;
    u16 f;
    s32 j;
    SPRT *s;

    GetDrawEnv((DRAWENV *)env);
    r = D_1F800164;
    SetDrawMode(r, 0, 0, *(u16 *)(env + 0x14), 0);
    AddPrim(D_1F8001E0 + 8, r);
    D_1F800164 = (char *)D_1F800164 + 0xc;
    s = (SPRT *)0x1f800000;
    for (i = 0, j = 0; i < MESSAGE_SLOTS[o->idx].count; j++, i++) {
        f = MESSAGE_GLYPHS[o->idx][j].id;
        if (*(s16 *)&MESSAGE_GLYPHS[o->idx][j].id & 0x8000) {
            MESSAGE_GLYPHS[o->idx][j].id = f - (f & 0x8000);
        } else if (!(f & 0x4000) || o->v22 < 0x1f) {
            SetSprt(s);
            s->r0 = 0x80;
            s->g0 = 0x80;
            s->b0 = 0x80;
            if (GLYPH_CACHE[f &= 0xfff].flag == 0) {
                s->x0 = MESSAGE_SLOTS[o->idx].x + MESSAGE_GLYPHS[o->idx][j].x;
                s->y0 = MESSAGE_SLOTS[o->idx].y + MESSAGE_GLYPHS[o->idx][j].y;
            } else {
                s->x0 = MESSAGE_SLOTS[o->idx].x + MESSAGE_GLYPHS[o->idx][j].x - 7;
                s->y0 = MESSAGE_SLOTS[o->idx].y + MESSAGE_GLYPHS[o->idx][j].y - 9;
            }
            s->u0 = GLYPH_CACHE[(s16)f].u << 2;
            s->v0 = GLYPH_CACHE[(s16)f].v;
            s->w = GLYPH_CACHE[(s16)f].w;
            s->h = GLYPH_CACHE[(s16)f].h;
            s->clut = MESSAGE_GLYPHS[o->idx][j].clut;
            {
                SPRT *q = D_1F800164;
                *q = *s;
                AddPrim(D_1F8001E0 + 8, q);
            }
            D_1F800164 = (char *)D_1F800164 + 0x14;
        }
    }
    if (GetGraphType() != 1)
        GetGraphType();
    r = D_1F800164;
    SetDrawMode(r, 0, 0, 0, 0);
    AddPrim(D_1F8001E0 + 8, r);
    l.m = o->m;
    l.a = o->a;
    l.b = o->b;
    l.c = o->c;
    l.d = o->d;
    D_1F800164 = (char *)D_1F800164 + 0xc;
    drawBalloonFrame(&l, 0, o->v1e);
}

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
