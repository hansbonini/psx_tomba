#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004B450);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", func_8004BAF0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender3", drawMessageBox);
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
    u16 w, h;
} Sprt_4BDE4;
typedef struct { s16 n, pad, x, y; } Hdr_4BDE4;
typedef struct { u16 f, clut, x, y; } Ent_4BDE4;
typedef struct { u8 u, v, w, h, p4, flag, p6, p7, p8, p9; } Img_4BDE4;
typedef struct O_4BDE4 { char p0[0x1e]; s16 v1e; char p20[2]; s16 v22; char p24[0x92]; u16 m; char pb8[6];
    u16 a, b, c, d; char pc6[4]; u16 idx; } O_4BDE4;
typedef struct L_4BDE4 { s16 x0, x1, x2, x3; s16 a, b, c, d; s16 m; s16 pad[7]; } L_4BDE4;
extern Hdr_4BDE4 MESSAGE_SLOTS__4BDE4[];
extern Ent_4BDE4 MESSAGE_GLYPHS[][128];
extern Img_4BDE4 D_800A5144[];
extern void GetDrawEnv__4BDE4(char *);
extern s32 GetGraphType(void);

void drawMessageBox(O_4BDE4 *o)
{
    char env[0x60];
    L_4BDE4 l;
    void *r;
    s32 i;
    u16 f;
    s32 j;
    Sprt_4BDE4 *s;

    GetDrawEnv__4BDE4(env);
    r = D_1F800164;
    SetDrawMode(r, 0, 0, *(u16 *)(env + 0x14), 0);
    AddPrim(D_1F8001E0 + 8, r);
    D_1F800164 = (char *)D_1F800164 + 0xc;
    s = (Sprt_4BDE4 *)0x1f800000;
    for (i = 0, j = 0; i < MESSAGE_SLOTS__4BDE4[o->idx].n; j++, i++) {
        f = MESSAGE_GLYPHS[o->idx][j].f;
        if (*(s16 *)&MESSAGE_GLYPHS[o->idx][j].f & 0x8000) {
            MESSAGE_GLYPHS[o->idx][j].f = f - (f & 0x8000);
        } else if (!(f & 0x4000) || o->v22 < 0x1f) {
            SetSprt(s);
            s->r0 = 0x80;
            s->g0 = 0x80;
            s->b0 = 0x80;
            if (D_800A5144[f &= 0xfff].flag == 0) {
                s->x0 = MESSAGE_SLOTS__4BDE4[o->idx].x + MESSAGE_GLYPHS[o->idx][j].x;
                s->y0 = MESSAGE_SLOTS__4BDE4[o->idx].y + MESSAGE_GLYPHS[o->idx][j].y;
            } else {
                s->x0 = MESSAGE_SLOTS__4BDE4[o->idx].x + MESSAGE_GLYPHS[o->idx][j].x - 7;
                s->y0 = MESSAGE_SLOTS__4BDE4[o->idx].y + MESSAGE_GLYPHS[o->idx][j].y - 9;
            }
            s->u0 = D_800A5144[(s16)f].u << 2;
            s->v0 = D_800A5144[(s16)f].v;
            s->w = D_800A5144[(s16)f].w;
            s->h = D_800A5144[(s16)f].h;
            s->clut = MESSAGE_GLYPHS[o->idx][j].clut;
            {
                Sprt_4BDE4 *q = D_1F800164;
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
