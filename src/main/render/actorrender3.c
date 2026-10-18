#include "common.h"
#include "game.h"
#include "game/gte.h"

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", func_8004B450);
typedef struct { s16 n, p2, x0, y0, x1, y1; char pad[8]; } ENT_4B450;
typedef struct { ENT_4B450 e[7]; } ROW_4B450;
typedef struct { char pad[0x4c]; u16 w4c; } C4C_4B450;
extern unsigned long LZ_FILE_CTRL_UnsignedLong asm("LZ_FILE_CTRL");
extern char D_1F8000C0_CharArr[] asm("D_1F8000C0");
extern ROW_4B450 LOAD_BUFFER_ROW_4B450Arr[] asm("LOAD_BUFFER");



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
        if ((&tbl[*(u16 *)((u8 *)o + 0xc6)].e[i])->n > 0) {
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
            p->x0 = x + (&tbl[*(u16 *)((u8 *)o + 0xc6)].e[i])->x0 / 100;
            p->y0 = y + (&tbl[*(u16 *)((u8 *)o + 0xc6)].e[i])->y0 / 100;
            p->x1 = x + (&tbl[*(u16 *)((u8 *)o + 0xc6)].e[i])->x1 / 100;
            p->y1 = p->y0;
            p->x2 = p->x0;
            p->y2 = y + (&tbl[*(u16 *)((u8 *)o + 0xc6)].e[i])->y1 / 100;
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
    p->x0 = x + ((ROW_4B450 *)LOAD_BUFFER)[*(u16 *)((u8 *)o + 0xc6)].e[6].x0 / 100;
    p->y0 = y + LOAD_BUFFER_ROW_4B450Arr[*(u16 *)((u8 *)o + 0xc6)].e[6].y0 / 100;
    p->x1 = x + LOAD_BUFFER_ROW_4B450Arr[*(u16 *)((u8 *)o + 0xc6)].e[6].x1 / 100;
    p->y1 = p->y0;
    p->x2 = p->x0;
    p->y2 = y + LOAD_BUFFER_ROW_4B450Arr[*(u16 *)((u8 *)o + 0xc6)].e[6].y1 / 100;
    p->x3 = p->x1;
    p->y3 = p->y2;
    p->tpage = o->tpage;
    p->clut = *(u16 *)(q + 2);
    if (!otadd_4B450((unsigned long *)p, D_1F8001E0, 0, o->unkF, 0x9000000))
        D_1F800164 = (POLY_FT4 *)((char *)D_1F800164 + 0x28);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", func_8004BAF0);
typedef struct {
    unsigned long tag;
    u8 r0, g0, b0, code;
    u16 x0, y0;
    u16 uv0, clut;
    u16 x1, y1;
    u16 uv1, tpage;
    u16 x2, y2;
    u16 uv2, pad2;
    u16 x3, y3;
    u16 uv3, pad3;
} PolyFT4_4BAF0;

typedef struct {
    unsigned long w0;
    unsigned long w4;
    u16 h8;
    u8 w, h;
    u16 hc;
    s8 dx, dy;
} Ent_4BAF0;

typedef struct {
    char p0[8];
    u16 w08;
    char p0a[3];
    u8 b0d;
    char p0e;
    s8 b0f;
    char p10[2];
    u16 x;
    char p14[2];
    u16 y;
    char p18[2];
    s16 z;
    char p1c[2];
    u16 w1e;
    char p20[4];
    u16 *anim;
    char p28[0x2e - 0x28];
    u16 animFrame;
    char p30[0x3c - 0x30];
    char *tab;
} O_4BAF0;
extern PolyFT4_4BAF0 *D_1F800164_PolyFT4_4BAF0Ptr asm("D_1F800164");

static __inline__ s32 onscreen_4BAF0(PolyFT4_4BAF0 *p)
{
    if ((*(volatile u16 *)&p->y0 < SCREEN_HEIGHT || p->y1 < SCREEN_HEIGHT || p->y2 < SCREEN_HEIGHT || p->y3 < SCREEN_HEIGHT) &&
        (p->x0 < 0x140 || p->x1 < 0x140 || p->x2 < 0x140 || p->x3 < 0x140))
        return 1;
    return 0;
}

static __inline__ s32 addprim_4BAF0(u32 e, u32 *a, char *b, s32 c, s32 d)
{
    d = ((s8)d + c) << 2;
    if (d < 0) d = 0;
    d += (s32)b;
    if ((u32)(d - (s32)D_1F8001E0) >= 0xca0) return 1;
    {
        u32 v = *(u32 *)d;
        *(u32 *)d = (u32)a;
        *a = v | e;
    }
    return 0;
}

void func_8004BAF0(O_4BAF0 *o)
{
    PolyFT4_4BAF0 *p;
    Ent_4BAF0 *e;
    s16 *h;
    s32 n;
    s32 z;

    h = (s16 *)(o->tab + *o->anim * 4);
    n = h[0];
    e = (Ent_4BAF0 *)(*(char * volatile *)&o->tab + h[1]);
    do {
        p = D_1F800164_PolyFT4_4BAF0Ptr;
        if (o->animFrame & 1) {
            p->x0 = o->x + e->dx;
            p->y0 = o->y + e->dy;
            p->x1 = p->x0 + e->w;
            p->x2 = p->x0;
            p->y1 = p->y0;
        } else {
            p->x0 = o->x - e->dx;
            p->y0 = o->y + e->dy;
            p->x1 = p->x0 - e->w;
            p->x2 = p->x0;
            p->y1 = p->y0;
        }
        p->y2 = p->y0 + e->h;
        *(volatile u16 *)&p->x3 = p->x1;
        *(volatile u16 *)&p->y3 = p->y2;
        if (onscreen_4BAF0(p)) {
            p->code = 0x2d;
            SetSemiTrans(p, o->b0d >> 7);
            *(unsigned long *)&p->uv0 = e->w0;
            *(unsigned long *)&p->uv1 = e->w4;
            p->uv2 = e->h8;
            p->uv3 = e->hc;
            p->tpage += o->w1e;
            if (o->b0d & 1) {
                p->clut = o->w08;
            }
            z = o->z;
            do {} while (0);
            if (addprim_4BAF0(0x9000000, (u32 *)p, D_1F8001E0 + 0x10, z, o->b0f) == 0) {
                D_1F800164_PolyFT4_4BAF0Ptr = D_1F800164_PolyFT4_4BAF0Ptr + 1;
            }
        }
        e++;
    } while (--n != 0);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", drawMessageBox);
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
#if !defined(VERSION_SCES_01330)
    if (GetGraphType() != 1)
        GetGraphType();
#endif
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

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", drawMessageBoxFrame);

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

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", drawBalloonFrame);
typedef struct { char pad[8]; s16 x, y, w, h, f; } R_4C258;
typedef struct { s16 u, v; u8 w, pw; s16 h; } UVT_4C258;
typedef struct { u8 u, v; } UV2_4C258;
typedef struct { u8 u0, v0, u1, v1, u2, v2, u3, v3; } UV8_4C258;
extern UVT_4C258 BALLOON_TAIL_SPRITES[];
extern UV2_4C258 D_8007EB84[];
extern UV8_4C258 D_8007EB8C[];

void drawBalloonFrame(R_4C258 *o_, s16 c, s16 tp)
{
    register R_4C258 *o asm("$17") = o_;
    SPRT *sp;
    POLY_FT4 *ft;
    TILE *ti;
    char pad[96];
    s16 pos[4][8];
    s32 k;
    s16 x;
    s16 y;
    register s16 w asm("$6");
    s16 h;
    s32 i;
    void *p;
    register s32 f asm("$4");
    { register s32 r asm("$5"); r = (u16)o->f; f = r << 16; }
    sp = (SPRT *)0x1f800000; ft = (POLY_FT4 *)0x1f800014; ti = (TILE *)0x1f80003c;
    if ((f>>16) != -1 && (u32)(k = f >> 28) < 8) {
        ((u8 *)ft)[3] = 9;
        ft->code = 0x2c;
        ft->r0 = 0x80;
        ft->g0 = 0x80;
        ft->b0 = 0x80;
        switch (k) {
        case 0:
            w = 8; h = 16;
            x = o->x + o->w / 2 - 4;
            y = o->y + o->h - 6;
            break;
        case 1:
            w = 16; h = 16;
            x = o->x + 8;
            y = o->y + o->h - 8;
            break;
        case 2:
            w = 16; h = 8;
            x = o->x - 9;
            y = o->y + o->h / 2 - 6;
            break;
        case 3:
            w = 16; h = 16;
            x = o->x + 8;
            y = o->y - 9;
            break;
        case 4:
            w = 8; h = 16;
            x = o->x + o->w / 2 - 4;
            y = o->y - 10;
            break;
        case 5:
            w = 16; h = 16;
            x = o->x + o->w - 24;
            y = o->y - 9;
            break;
        case 6:
            w = 16; h = 8;
            x = o->x + o->w - 4;
            y = o->y + o->h / 2 - 6;
            break;
        case 7:
            w = 16; h = 16;
            x = o->x + o->w - 24;
            y = o->y + o->h - 8;
            break;
        default:
            goto skip;
        }
        { register s16 t asm("$2") = x + w; ft->x3 = ft->x1 = t; } asm("");
        ft->y1 = ft->y0 = y;
        ft->x2 = ft->x0 = x;
        ft->y3 = ft->y2 = y + h;
        ft->u0 = BALLOON_TAIL_SPRITES[k].u;
        ft->v0 = BALLOON_TAIL_SPRITES[k].v;
        { s32 w2;
        h = BALLOON_TAIL_SPRITES[k].h;
        w2 = BALLOON_TAIL_SPRITES[k].w;
        ft->u2 = ft->u0;
        ft->u1 = ft->u0 + w2;
        ft->v1 = ft->v0;
        ft->v2 = h + ft->v0;
        ft->v3 = ft->v2;
        ft->u3 = ft->u1; }
        ft->clut = GetClut(0x160, c + 0x1e3);
        ft->tpage = tp;
        { void *p = D_1F800164;
        *(POLY_FT4 *)p = *ft;
        AddPrim((void *)(D_1F8001E0 + 8), p); }
        D_1F800164 += 0x28;
    }
skip:
    pos[0][0] = o->x;
    pos[0][1] = o->y;
    pos[1][0] = o->x + o->w - 8;
    pos[1][1] = o->y;
    pos[2][0] = o->x;
    pos[2][1] = o->y + o->h - 8;
    pos[3][0] = o->x + o->w - 8;
    pos[3][1] = o->y + o->h - 8;
    for (i = 0; i < 4; i++) {
        SetSprt(sp);
        sp->r0 = 0x80;
        sp->g0 = 0x80;
        sp->b0 = 0x80;
        sp->x0 = pos[i][0];
        sp->y0 = pos[i][1];
        sp->u0 = D_8007EB84[i].u;
        sp->v0 = D_8007EB84[i].v;
        sp->w = 8;
        sp->h = 8;
        sp->clut = GetClut(0x160, c + 0x1e3);
        { void *p = D_1F800164;
        *(SPRT *)p = *sp;
        AddPrim((void *)(D_1F8001E0 + 8), p); }
        D_1F800164 += 0x14;
    }
    pos[0][0] = o->x + 8;
    pos[0][1] = o->y;
    pos[0][2] = o->x + o->w - 8;
    pos[0][3] = o->y;
    pos[0][4] = o->x + 8;
    pos[0][5] = o->y + 8;
    pos[0][6] = o->x + o->w - 8;
    pos[0][7] = o->y + 8;
    pos[1][0] = o->x + 8;
    pos[1][1] = o->y + o->h - 8;
    pos[1][2] = o->x + o->w - 8;
    pos[1][3] = o->y + o->h - 8;
    pos[1][4] = o->x + 8;
    pos[1][5] = o->y + o->h;
    pos[1][6] = o->x + o->w - 8;
    pos[1][7] = o->y + o->h;
    pos[2][0] = o->x;
    pos[2][1] = o->y + 8;
    pos[2][2] = o->x + 8;
    pos[2][3] = o->y + 8;
    pos[2][4] = o->x;
    pos[2][5] = o->y + o->h - 8;
    pos[2][6] = o->x + 8;
    pos[2][7] = o->y + o->h - 8;
    pos[3][0] = o->x + o->w - 8;
    pos[3][1] = o->y + 8;
    pos[3][2] = o->x + o->w;
    pos[3][3] = o->y + 8;
    pos[3][4] = o->x + o->w - 8;
    pos[3][5] = o->y + o->h - 8;
    pos[3][6] = o->x + o->w;
    pos[3][7] = o->y + o->h - 8;
    for (i = 0; i < 4; i++) {
        ((u8 *)ft)[3] = 9;
        ft->code = 0x2c;
        ft->r0 = 0x80;
        ft->g0 = 0x80;
        ft->b0 = 0x80;
        ft->x0 = pos[i][0];
        ft->y0 = pos[i][1];
        ft->x1 = pos[i][2];
        ft->y1 = pos[i][3];
        ft->x2 = pos[i][4];
        ft->y2 = pos[i][5];
        ft->x3 = pos[i][6];
        ft->y3 = pos[i][7];
        ft->u0 = D_8007EB8C[i].u0;
        ft->v0 = D_8007EB8C[i].v0;
        ft->u1 = D_8007EB8C[i].u1;
        ft->v1 = D_8007EB8C[i].v1;
        ft->u2 = D_8007EB8C[i].u2;
        ft->v2 = D_8007EB8C[i].v2;
        ft->u3 = D_8007EB8C[i].u3;
        ft->v3 = D_8007EB8C[i].v3;
        ft->clut = GetClut(0x160, c + 0x1e3);
        ft->tpage = tp;
        { void *p = D_1F800164;
        *(POLY_FT4 *)p = *ft;
        AddPrim((void *)(D_1F8001E0 + 8), p); }
        D_1F800164 += 0x28;
    }
    ((u8 *)ti)[3] = 3;
    ti->code = 0x60;
    if (c) {
        ti->r0 = 0;
        ti->g0 = 0x50;
        ti->b0 = 0;
    } else {
        ti->r0 = 0xf8;
        ti->g0 = 0xe8;
        ti->b0 = 0xd8;
    }
    ti->x0 = o->x + 8;
    ti->y0 = o->y + 8;
    ti->w = o->w - 16;
    ti->h = o->h - 16;
    { void *p = D_1F800164;
    *(TILE *)p = *ti;
    AddPrim((void *)(D_1F8001E0 + 8), p); }
    p = D_1F800164 = D_1F800164 + 0x10;
    SetDrawMode(p, 0, 0, tp, 0);
    AddPrim((void *)(D_1F8001E0 + 8), p);
    D_1F800164 += 0xc;
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender3", func_8004CC84);


typedef struct {
    unsigned long tag;
    u8 r0, g0, b0, code;
    u16 x0, y0;
    u8 u0, v0; u16 clut;
    u16 x1, y1;
    u8 u1, v1; u16 tpage;
    u16 x2, y2;
    u8 u2, v2; u16 pad2;
    u16 x3, y3;
    u8 u3, v3; u16 pad3;
} PolyFT4_4CC84;
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");
static __inline__ s32 project_4CC84(void)
{
    gte_ldv0(&D_1F800060);
    gte_rtps();
    gte_stflg(&SCRATCHPAD.unk08C);
    if (SCRATCHPAD.unk08C < 0) return 1;
    gte_stsxy(&LZ_FILE_CTRL_Long);
    gte_stszotz(&SCRATCHPAD.lz.offset);
    return 0;
}
static __inline__ s32 addprim_4CC84(u32 *a, char *b, s32 c, s32 d, u32 e)
{
    d = ((s8)d + c) << 2;
    if (d < 0) d = 0;
    d += (s32)b;
    if ((u32)(d - D_1F8001E0) >= 0xca0) return 1;
    {
        u32 v = *(u32 *)d;
        *(u32 *)d = (u32)a;
        *a = v | e;
    }
    return 0;
}
void func_8004CC84(GameObject *o)
{
    PolyFT4_4CC84 *p;
    u8 *s;
    s32 xy;
    s32 t;
    s32 z;
    u16 *a;
    s16 *hh;
    u8 w, h;
    s16 u;
    u8 v;

    D_1F800060.vx = o->x.p.whole;
    D_1F800060.vy = o->y.p.whole;
    if ((*(s32*)&GAME.selectedArea) == 0x10005 && *(u16 *)&(*(GameTask **)&D_1F8001D4)->mode != 3)
        D_1F800060.vz = o->z.p.whole >> 2;
    else
        D_1F800060.vz = o->z.p.whole;
    SetRotMatrix(&SCRATCHPAD.viewMatrix);
    SetTransMatrix(D_1F8000C0);
    if (project_4CC84()) return;
    a = (u16 *)o->anim;
    hh = (s16 *)(o->spriteBank + *a * 4);
    xy = LZ_FILE_CTRL_Long;
    s = (u8 *)(*(volatile s32 *)&o->spriteBank + hh[1]);
    p = D_1F800164;
    p->code = 0x2c;
    p->r0 = o->unkB4;
    p->g0 = o->unkB4;
    p->b0 = o->unkB4;
    SetSemiTrans(p, 1);
    p->tpage = o->tpage;
    u = s[0]; v = s[1]; w = s[0xa]; h = s[0xb];
    p->u0 = u; p->v0 = v; p->v1 = v; p->u1 = w + u;
    p->u2 = u; p->v2 = v + h; p->u3 = w + u; p->v3 = v + h;
    p->x0 = xy + ((s8)s[0xe] * (u16)o->unkB8) / 200;
    p->y0 = (xy >> 16) + ((s8)s[0xf] * (u16)o->unkB8) / 200;
    t = (w * (u16)o->unkB8) / 100;
    p->y1 = *(volatile u16 *)&p->y0;
    p->x2 = p->x0;
    p->x1 = p->x0 + t - 1;
    p->y2 = p->y0 + (h * (u16)o->unkB8) / 100 - 1;
    p->x3 = p->x1;
    p->y3 = p->y2;
    z = SCRATCHPAD.lz.offset;
    p->clut = o->clut;
    if (addprim_4CC84((u32 *)p, (char *)(D_1F8001E0 + 0x10), z, o->unkF, 0x9000000) == 0)
        D_1F800164 = (PolyFT4_4CC84 *)((char *)D_1F800164 + 0x28);
}
