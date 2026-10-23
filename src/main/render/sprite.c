#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004DC34);
void func_8004DC34(void)
{
    s32 n;
    s32 *p;
    s32 a;

    if (D_1F8001C6 != 0) {
        n = (*(s16 *)&D_1F800258);
        p = D_1F800274;
        if (n != 0) {
            do {
                a = *p++;
                n--;
                func_80045EFC(a);
            } while (n != 0);
        }
    } else {
        (*(s16 *)&D_1F800258) = D_1F800242;
        D_1F800274 = D_1F800230;
        if (D_1F800242 != 0) {
            do {
                a = *D_1F800230++;
                D_1F800242 = D_1F800242 - 1;
                func_80045EFC(a);
            } while ((*(s16 *)&D_1F800242) != 0);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004DD14);

void func_8004DD14(void)
{
    GameObject *o;
    GameObject **p;
    s32 n;

    if (D_1F8001C6 != 0) {
        n = (*(s16 *)&D_1F80025A);
        p = D_1F800270;
        while (n != 0) {
            o = *p++;
            n--;
            switch (o->unkA) {
            case 0:
                func_8004A300(o);
                break;
            case 1:
                func_8004DFA0(o);
                break;
            case 2:
                func_8004E244(o);
                break;
            case 3:
                if (D_800A539A & 2)
                    func_800EBA58(o);
                else
                    func_800EA3A4(o);
                break;
            case 4:
                if (((u16 *)&GAME)[0] == 4)
                    func_8011DA28(o);
                if (((u16 *)&GAME)[0] == 0xc)
                    func_80116308(o);
                break;
            }
        }
    } else {
        (*(s16 *)&D_1F80025A) = D_1F800240;
        D_1F800270 = D_1F80022C;
        while (D_1F800240 != 0) {
            o = *D_1F80022C++;
            D_1F800240--;
            switch (o->unkA) {
            case 0:
                func_8004A300(o);
                break;
            case 1:
                func_8004DFA0(o);
                break;
            case 2:
                func_8004E244(o);
                break;
            case 3:
                if (D_800A539A & 2)
                    func_800EBA58(o);
                else
                    func_800EA3A4(o);
                break;
            case 4:
                if (((u16 *)&GAME)[0] == 4)
                    func_8011DA28(o);
                if (((u16 *)&GAME)[0] == 0xc)
                    func_80116308(o);
                break;
            }
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004DFA0);

void func_8004DFA0(GameObject *o)
{
    s16 pri;
    SPRT *s;
    s16 *e;
    SprFrag *f;
    s32 n;
    s32 tp;

    if (o->unkB == 2) {
        pri = *(u16 *)&o->unkE;
    } else {
        pri = (s8)o->unkF;
    }
    s = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)s, 0, 0, 0, 0);
    AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), s);
    D_1F800164 += sizeof(DR_MODE);
    e = (s16 *)(o->spriteBank + *(u16 *)o->anim * 4);
    n = e[0];
    f = (SprFrag *)(*(volatile s32 *)&o->spriteBank + e[1]);
    tp = f->tpage;
    do {
        s = (SPRT *)D_1F800164;
        s->w = f->w;
        s->h = f->h;
        s->x0 = o->x.p.whole + f->dx;
        s->y0 = o->y.p.whole + f->dy;
        if (((u16)s->y0 < NTSC_PAL(0xF1, 0x101) || (u16)(s->y0 + s->h) < NTSC_PAL(0xF1, 0x101)) &&
            ((u16)s->x0 < 0x141 || (u16)(s->x0 + s->w) < 0x141)) {
            SetSprt(s);
            SetSemiTrans(s, o->unkD >> 7);
            s->code |= 1;
            *(s32 *)&s->u0 = *(s32 *)f;
            if (o->unkD & 1) {
                s->clut = o->clut;
            }
            AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), s);
            D_1F800164 += sizeof(SPRT);
        }
        f++;
        n--;
    } while (n != 0);
    s = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)s, 0, 0, o->tpage + (s16)tp, 0);
    AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), s);
    D_1F800164 += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E244);
typedef struct { s16 tpage; s16 x; s16 y; u8 u; u8 v; s16 w; s16 h; s16 cx; s16 cy; s16 semi; } SprPart;
extern SprPart *D_8007EBEC[];

void func_8004E244(GameObject *o)
{
    SprPart *e = D_8007EBEC[o->subtype];
    SPRT *p;
    DR_MODE *dm;
#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
    short r[4];
#endif

    while (e->tpage != 0x7FFF) {
        p = (SPRT *)D_1F800164;
        SetSprt(p);
        SetSemiTrans(p, e->semi);
        p->r0 = 0x80;
        p->g0 = 0x80;
        p->b0 = 0x80;
        p->code |= 1;
        p->w = e->w;
        p->h = e->h;
        p->x0 = o->x.p.whole + e->x;
        p->y0 = o->y.p.whole + e->y + NTSC_PAL(0, 0x18);
        p->u0 = e->u;
        p->v0 = e->v;
        p->clut = GetClut(e->cx, e->cy);
        AddPrim((u_long *)D_1F8001E0 + ((s8)o->unkF + 0x324), p);
        D_1F800164 += sizeof(SPRT);
        dm = (DR_MODE *)D_1F800164;
        SetDrawMode(dm, 0, 0, e->tpage, 0);
        AddPrim((u_long *)D_1F8001E0 + ((s8)o->unkF + 0x324), dm);
        e++;
        D_1F800164 += sizeof(DR_MODE);
    }
#if defined(VERSION_SCES_01330) || defined(VERSION_SCES_01331)
    r[0] = 0;
    r[1] = 0;
    r[2] = 0x140;
    r[3] = 0x10;
    addTilePrim(r, 0, 0, 1);
    r[1] = 0xF0;
    addTilePrim(r, 0, 0, 1);
#endif
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E3EC);

void func_8004E3EC(void)
{
    u8* p = D_800B0770;

    if (D_8009C618[0] != 3) {
        if (D_8009BCA7 != 0) {
            D_800B0778 = 0x78;
        }
#if defined(VERSION_SLPS_01144)
        if (D_800B0778 == 0 && p[0]) {
#else
        if (D_800B0778 == 0 && (p[0] & 1)) {
#endif
            func_8004E468(p);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E468);
typedef struct { s16 x, y; } Pt_4E468;
extern Pt_4E468 D_8007EC5C[];

void func_8004E468(char *o)
{
    extern void func_8004E900();
    extern void func_8004E590(char *, s32, s32);
    extern void addDrawModePrim(s32, s32);
    char env[0x60];
    s32 i;
    GetDrawEnv(env);
    addDrawModePrim(*(s16 *)(env + 0x14), 1);
    func_8004E590(o, 0x18, NTSC_PAL(0xD0, 0xF0));
    func_8004E714(o, 0x12c, 0x10);
#if defined(VERSION_SLPS_01144)
    func_8004E900(o, 0x24, 0x1c);
#else
    func_8004E900(o, 0x24, 0x1c, *(s16 *)(o + 0x52));
#endif
    func_8004ED80(o, 0x48, 0x10);
    for (i = 0; i < 3; i++) {
        if (D_8009BCF8 == D_8007EC68[i]) {
            func_8004EB10(o, i, D_8007EC5C[i].x, D_8007EC5C[i].y, 0);
        } else if (D_800B07C8[i] != 0) {
            func_8004EB10(o, i, D_8007EC5C[i].x, D_8007EC5C[i].y, 1);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E590);
typedef struct { char p[0x24]; u16 **tbl; char q[0x30 - 0x28]; u16 *dot; } O_4E590;
void func_8004E590(O_4E590 *o, s16 x, s16 y)
{
    extern void func_8004F2CC(O_4E590 *o, s16 x, s16 y, s32 k);
    extern void addDrawModePrim(s32, s32);
    u8 *g = &D_8009BCE8;
    u16 *t;
    if (*g - 1 >= 10) {
        t = o->tbl[(*g - 1) / 10];
        func_8004F2CC(o, x - 5, y, *t);
        func_8004F2CC(o, x + 5, y, *o->tbl[(*g - 1) % 10]);
    } else {
        t = o->tbl[*g - 1];
        func_8004F2CC(o, x, y, *t);
    }
    func_8004F2CC(o, x, y - 4, *o->dot);
    addDrawModePrim(0x15, 1);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E714);
typedef struct {
    char pad0[0x18];
    u8 *volatile base;
    char pad1C[4];
    u16 **tbl;
    u16 **digits;
    char pad28[0x14];
    u8 ap[8];
} O_4E714;

void func_8004E714(o, x0, y0)
O_4E714 *o;
s32 x0;
s32 y0;
{
    extern void func_8004F2CC(O_4E714 *o, s16 x, s16 y, s32 k);
    extern void addDrawModePrim(s32, s32);
    s16 x = x0, y = y0;
    SPRT *p;
    u8 *q;
    s16 *e;
    SprFrag *f;
    s32 i, n, dx, cnt;

    n = 0;
    q = o->ap;
    i = 0;
    dx = -0x44;
    do {
        if (i == 7 || *q != 0 || n != 0) {
            func_8004F2CC(o, (s16)(x + dx), (s16)y, *o->digits[*q]);
            n++;
        }
        q++;
        i++;
        dx += 8;
    } while (i < 8);
    n -= 4;
    if (n < 0) n = 0;
    e = (s16 *)(o->base + *o->tbl[n] * 4);
    cnt = e[0];
    f = (SprFrag *)(o->base + e[1]);
    do {
        p = (SPRT *)D_1F800164;
        SetSprt(p);
        p->code |= 1;
        SetSemiTrans(p, 1);
        p->x0 = x + f->dx;
        p->y0 = y + f->dy;
        p->u0 = f->u;
        cnt--;
        p->v0 = f->v;
        p->w = f->w;
        p->h = f->h;
        p->clut = f->clut;
        f++;
        AddPrim(D_1F8001E0 + 4, p);
        D_1F800164 = (u8 *)((SPRT *)D_1F800164 + 1);
    } while (cnt != 0);
    addDrawModePrim(0x15, 1);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E900);
typedef struct {
    char pad[0x18];
    u8 *base;
    s16 **tbl;
    char pad20[0x52 - 0x20];
    s16 n;
} SPR_4E900;
extern void func_8004F3DC(SPR_4E900 *s, s16 x, s16 y, u16 v);

void func_8004E900(SPR_4E900 *s, s16 x, s16 y, u16 n)
{
#if defined(VERSION_SLPS_01144)
#define N_4E900 s->n
#else
#define N_4E900 ((s16)n)
#endif
    s32 i = 0;
    SPRT *p;
    u8 *e;
    s32 cy;

    for (; i < D_8009BCD9; i++) {
        {
            p = (SPRT *)D_1F800164;
            e = s->base + *(s16 *)(*(u8 *volatile *)&s->base + (*s->tbl[i] << 2) + 2);
            SetSprt(p);
            p->code |= 1;
            SetSemiTrans(p, 0);
            p->x0 = x + (s8)e[0xe];
            p->y0 = y + (s8)e[0xf];
            p->u0 = e[0];
            p->v0 = e[1];
            p->w = e[10];
            p->h = e[11];
            if (i < N_4E900) {
                if (N_4E900 < 3)
                    p->clut = GetClut(0x170, 0x1f7);
                else if (N_4E900 < 5)
                    p->clut = GetClut(0x170, 0x1f6);
                else if (N_4E900 < 7)
                    p->clut = GetClut(0x170, 0x1f5);
                else
                    p->clut = GetClut(0x170, 0x1f4);
            } else {
                p->clut = GetClut(0x170, 0x1f8);
            }
            AddPrim(D_1F8001E0 + 4, p);
            D_1F800164 = (u8 *)((SPRT *)D_1F800164 + 1);
        }
    }
    func_8004F3DC(s, (s16)x, (s16)y, *((u16 **)&D_80012208)[N_4E900]);
    addDrawModePrim(0x15, 1);
#undef N_4E900
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004EB10);
typedef struct { u8 a, pa, b, pb, c, pc; } Col6_4EB10;
extern Col6_4EB10 D_8007EC80[];

void func_8004EB10(GameObject *o, s32 idx, s16 x, s16 y, s16 flag)
{
    SPRT *p;
    u8 *s;
    s16 r[4];
    s32 c;

    if (flag)
        func_8004F2CC(o, (s16)(x + 8), y, *(u16 *)((void **)o->movetab)[D_8009C100[idx] + 1]);
    p = (SPRT *)D_1F800164;
    s = (u8 *)o->z.raw + *(s16 *)(*(volatile s32 *)&o->z.raw + (*(u16 *)o->unk34 << 2) + 2);
    SetSprt(p);
    p->code |= 1;
    p->x0 = x;
    p->y0 = y;
    p->u0 = s[0];
    p->v0 = s[1];
    p->w = s[10];
    p->h = s[11];
    c = *((u8 *)o + idx + 0x64) + 0x1e4;
    p->clut = GetClut(0x150, idx * 4 + c);
    AddPrim(D_1F8001E0 + 4, p);
    ((SPRT *)D_1F800164)++;
    addDrawModePrim(0x14, 1);
    r[0] = x + 0x13;
    r[1] = y + 2;
#if defined(VERSION_SLPS_01144)
    r[2] = D_8009C104[idx];
#else
    if (!flag && D_8009C40C[D_8007EC70[idx]] && D_8009BCF8 == D_8007EC78[idx])
        r[2] = D_8009C107;
    else
        r[2] = D_8009C104[idx];
#endif
    r[3] = 4;
    addTilePrim(r, 0xff, 0xff, 0);
    r[0] = x + 0x13;
    r[1] = y + 2;
    r[2] = 0x3d;
    r[3] = 4;
    addTilePrim(r, D_8007EC80[idx].a, D_8007EC80[idx].b, D_8007EC80[idx].c);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004ED80);

void func_8004ED80(s32 o, s16 x, s16 y)
{
    SPRT *p;
    u8 *q;
    s32 m;
    void *ot;
    u8 c;
    switch (D_8009C61A[0]) {
    case 0:
        func_8004F3DC(o, x, y, *(*(u16 **)&D_80012318));
        addDrawModePrim(0x14, 1);
        break;
    case 5:
        func_8004F3DC(o, x, y, *(*(u16 **)&D_8001232C));
        addDrawModePrim(0x15, 1);
        break;
    case 6:
        func_8004F3DC(o, x, y, *(*(u16 **)&D_80012330));
        addDrawModePrim(0x15, 1);
        break;
    case 7:
        func_8004F3DC(o, x, y, *(*(u16 **)&D_80012334));
        addDrawModePrim(0x15, 1);
        break;
    case 8:
        func_8004F3DC(o, x, y, *(*(u16 **)&D_80012310));
        addDrawModePrim(0x14, 1);
        break;
    case 9:
        p = (SPRT *)D_1F800164;
        q = (u8 *)(*(volatile s32 *)(o + 0x18) + *(s16 *)(*(volatile s32 *)(o + 0x18) + (*(*(u16 **)&D_80012314) << 2) + 2));
        SetSprt(p);
        p->code |= 1;
        SetSemiTrans(p, 0);
        p->x0 = x + (s8)q[0xe];
        p->y0 = y + (s8)q[0xf];
        p->u0 = q[0];
        p->v0 = q[1];
        ot = (void *)(D_1F8001E0 + 4);
        p->w = q[0xa];
        c = q[0xb];
        p->clut = 0x7e14;
        p->h = c;
        AddPrim(ot, p);
        ((SPRT *)D_1F800164)++;
        addDrawModePrim(0x14, 1);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", drawMessageGlyphs);

#define SETUV0(p, u, v) do { (p)->u0 = (u); (p)->v0 = (v); } while (0)
typedef struct { s16 clip[4]; s16 ofs[2]; s16 tw[4]; u16 tpage; char rest[0x68 - 0x16]; } DRAWENV_4EFA8;

void drawMessageGlyphs(s32 a)
{
    DRAWENV_4EFA8 env;
    SPRT *p;
    s32 i;
    s16 f;

    GetDrawEnv((DRAWENV *)&env);
    addDrawModePrim((s16)env.tpage, 1);
    for (i = 0; i < MESSAGE_SLOTS[a].count; i++) {
        f = MESSAGE_GLYPHS[a][i].id;
        if (*(s16 *)&MESSAGE_GLYPHS[a][i].id & 0x8000) {
            MESSAGE_GLYPHS[a][i].id = f & 0x7fff;
            continue;
        }
        p = (SPRT *)D_1F800164;
        SetSprt(p);
        p->code |= 1;
        f &= 0xfff;
        if (GLYPH_CACHE[f].flag == 0) {
            p->x0 = MESSAGE_SLOTS[a].x + MESSAGE_GLYPHS[a][i].x;
            if (GLYPH_CACHE[f].w >= 0xb)
            { p->y0 = MESSAGE_SLOTS[a].y + MESSAGE_GLYPHS[a][i].y - 2; }
            else
            {    p->y0 = MESSAGE_SLOTS[a].y + MESSAGE_GLYPHS[a][i].y; }
        } else {
            p->x0 = MESSAGE_SLOTS[a].x + MESSAGE_GLYPHS[a][i].x - 0xb;
            p->y0 = MESSAGE_SLOTS[a].y + MESSAGE_GLYPHS[a][i].y - 10;
        }
        SETUV0(p, GLYPH_CACHE[f].u << 2, GLYPH_CACHE[f].v);
        p->w = GLYPH_CACHE[f].w;
        p->h = GLYPH_CACHE[f].h;
        p->clut = GetClut(0x160, 0x1e3);
        AddPrim(D_1F8001E0 + 4, p);
        ((SPRT *)D_1F800164)++;
    }
    addDrawModePrim(0, 1);
}
#undef SETUV0

// INCLUDE_ASM("nonmatchings/main/render/sprite", addDrawModePrim);
void addDrawModePrim(short tpage, int p) {
    scratchpad* scratch = PSX_SCRATCH;
    DR_MODE* mode = scratch->nextprim;

    SetDrawMode(mode, 0, 0, tpage, 0);
    AddPrim(scratch->ot + (p * 4),mode);
    scratch->nextprim += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F2CC);

void func_8004F2CC(s32 obj, s16 x, s16 y, u16 idx)
{
    SPRT *p;
    u8 *s;
    s32 t;
    s32 tb;
    s32 i;
    i = idx * 4;
    p = (SPRT *)D_1F800164;
    s = (u8 *)(*(volatile s32 *)(obj + 0x18) + *(s16 *)(*(volatile s32 *)(obj + 0x18) + i + 2));
    SetSprt(p);
    p->code = p->code | 1;
    SetSemiTrans(p, 0);
    p->x0 = x + (s8)s[0xe];
    p->y0 = y + (s8)s[0xf];
    p->u0 = s[0];
    p->v0 = s[1];
    t = D_1F8001E0;
    p->w = s[10];
    p->h = s[0xb];
    p->clut = *(u16 *)(s + 2);
    AddPrim((void *)(t + 4), p);
    D_1F800164 = (u8 *)((SPRT *)D_1F800164 + 1);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F3DC);
void func_8004F3DC(SPR_4E900 *a, s16 x, s16 y, u16 idx)
{
    s16 *e;
    s32 n;
    SprFrag *f;
    SPRT *p;

    e = (s16 *)(a->base + idx * 4);
    f = (SprFrag *)(*(u8 *volatile *)&a->base + e[1]);
    n = *e;
    do {
        p = (SPRT *)D_1F800164;
        SetSprt(p);
        p->code |= 1;
        SetSemiTrans(p, 0);
        p->x0 = x + f->dx;
        p->y0 = y + f->dy;
        p->u0 = f->u;
        n--;
        p->v0 = f->v;
        p->w = f->w;
        p->h = f->h;
        p->clut = f->clut;
        f++;
        AddPrim(D_1F8001E0 + 4, p);
        D_1F800164 = (u8 *)((SPRT *)D_1F800164 + 1);
    } while (n != 0);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", addTilePrim);
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

INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F5A4);

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004FB54);
typedef struct { char p0[0xc]; u8 b0c, b0d, b0e, b0f, b10, b11, b12, b13; s16 s14, s16, s18, s1a; } P_4FB54;

void func_8004FB54(u8 a)
{
    P_4FB54 *p;
    void *r;
    s32 t, m;
#if defined(VERSION_SCES_01330) || defined(VERSION_SLPS_01144)
    p = D_1F800164;
    SetDrawMode(p, 0, 0, 0, 0);
    AddPrim(D_1F8001E0 + 0x10, p);
#else
    r = D_1F800164;
    SetDrawMode(r, 0, 0, 0, 0);
    AddPrim(D_1F8001E0 + 0x10, r);
#endif
    p = D_1F800164;
    r = D_1F800164 = (P_4FB54 *)((char *)p + 0xc);
    p->s18 = 0x140;
    p->s1a = NTSC_PAL(0xF0, 0x100);
    p->b0f = 3;
    p->s14 = 0;
    p->s16 = 0;
    p->b13 = 0x60;
    SetSemiTrans(r, 1);
    if (D_8009BCA4 == 2) {
        p->b10 = 0;
        p->b11 = 0;
    } else {
        p->b10 = a;
        p->b11 = a;
    }
    p->b12 = a;
    AddPrim(D_1F8001E0 + 0x10, r);
#if defined(VERSION_SCES_01330) || defined(VERSION_SLPS_01144)
    p = D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0x10);
#else
    r = D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0x10);
#endif
#if defined(VERSION_SCES_01330)
    if (D_1F8003D1 == 1 || (u32)(D_8009BCA4 - 1) < 2) {
        m = 0x20;
    } else {
        m = 0x40;
    }
#else
#if defined(VERSION_SLPS_01144)
    if ((u32)(D_8009BCA4 - 1) < 2) {
#else
    if (D_1F8003D1 == 1 || (u32)(D_8009BCA4 - 1) < 2) {
#endif
        if (GetGraphType() == 1) m = 0x80;
        else if (GetGraphType() == 2) m = 0x80;
        else m = 0x20;
    } else {
        if (GetGraphType() == 1) m = 0x100;
        else if (GetGraphType() == 2) m = 0x100;
        else m = 0x40;
    }
#endif
#if defined(VERSION_SCES_01330) || defined(VERSION_SLPS_01144)
    SetDrawMode(p, 0, 0, m, 0);
    AddPrim(D_1F8001E0 + 0x10, p);
#else
    SetDrawMode(r, 0, 0, m, 0);
    AddPrim(D_1F8001E0 + 0x10, r);
#endif
    D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0xc);
}
