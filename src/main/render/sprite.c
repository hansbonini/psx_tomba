#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/render/sprite", drawModelList);
void drawModelList(void)
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

// INCLUDE_ASM("nonmatchings/main/render/sprite", drawFxList);

void drawFxList(void)
{
    GameObject *obj;
    GameObject **p;
    s32 n;

    if (D_1F8001C6 != 0) {
        n = (*(s16 *)&D_1F80025A);
        p = D_1F800270;
        while (n != 0) {
            obj = *p++;
            n--;
            switch (obj->drawType) {
            case 0:
                func_8004A300(obj);
                break;
            case 1:
                func_8004DFA0(obj);
                break;
            case 2:
                func_8004E244(obj);
                break;
            case 3:
                if (D_800A539A & 2)
                    func_800EBA58(obj);
                else
                    func_800EA3A4(obj);
                break;
            case 4:
                if (((u16 *)&GAME)[0] == 4)
                    func_8011DA28(obj);
                if (((u16 *)&GAME)[0] == 0xc)
                    func_80116308(obj);
                break;
            }
        }
    } else {
        (*(s16 *)&D_1F80025A) = D_1F800240;
        D_1F800270 = D_1F80022C;
        while (D_1F800240 != 0) {
            obj = *D_1F80022C++;
            D_1F800240--;
            switch (obj->drawType) {
            case 0:
                func_8004A300(obj);
                break;
            case 1:
                func_8004DFA0(obj);
                break;
            case 2:
                func_8004E244(obj);
                break;
            case 3:
                if (D_800A539A & 2)
                    func_800EBA58(obj);
                else
                    func_800EA3A4(obj);
                break;
            case 4:
                if (((u16 *)&GAME)[0] == 4)
                    func_8011DA28(obj);
                if (((u16 *)&GAME)[0] == 0xc)
                    func_80116308(obj);
                break;
            }
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004DFA0);

void func_8004DFA0(GameObject *obj)
{
    s16 pri;
    SPRT *sprt;
    s16 *e;
    SprFrag *f;
    s32 n;
    s32 tp;

    if (obj->otMode == OT_MODE_FIXED16) {
        pri = *(u16 *)&obj->unkE;
    } else {
        pri = (s8)obj->priority;
    }
    sprt = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)sprt, 0, 0, 0, 0);
    AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), sprt);
    D_1F800164 += sizeof(DR_MODE);
    e = (s16 *)(obj->spriteBank + *(u16 *)obj->anim * 4);
    n = e[0];
    f = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + e[1]);
    tp = f->tpage;
    do {
        sprt = (SPRT *)D_1F800164;
        setWH(sprt, f->w, f->h);
        setXY0(sprt, obj->x.p.whole + f->dx, obj->y.p.whole + f->dy);
        if (((u16)sprt->y0 < NTSC_PAL(0xF1, 0x101) || (u16)(sprt->y0 + sprt->h) < NTSC_PAL(0xF1, 0x101)) &&
            ((u16)sprt->x0 < 0x141 || (u16)(sprt->x0 + sprt->w) < 0x141)) {
            SetSprt(sprt);
            SetSemiTrans(sprt, obj->drawFlags >> 7);
            sprt->code |= 1;
            *(s32 *)&sprt->u0 = *(s32 *)f;
            if (obj->drawFlags & 1) {
                sprt->clut = obj->clut;
            }
            AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), sprt);
            D_1F800164 += sizeof(SPRT);
        }
        f++;
        n--;
    } while (n != 0);
    sprt = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)sprt, 0, 0, obj->tpage + (s16)tp, 0);
    AddPrim((u_long *)D_1F8001E0 + (pri + 0x324), sprt);
    D_1F800164 += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004E244);
typedef struct { s16 tpage; s16 x; s16 y; u8 u; u8 v; s16 w; s16 h; s16 cx; s16 cy; s16 semi; } SprPart;
extern SprPart *D_8007EBEC[];

void func_8004E244(GameObject *obj)
{
    SprPart *e = D_8007EBEC[obj->id];
    SPRT *sprt;
    DR_MODE *drMode;
#if REGION == REGION_EU
    short r[4];
#endif

    while (e->tpage != 0x7FFF) {
        sprt = (SPRT *)D_1F800164;
        SetSprt(sprt);
        SetSemiTrans(sprt, e->semi);
        setRGB0(sprt, 0x80, 0x80, 0x80);
        sprt->code |= 1;
        setWH(sprt, e->w, e->h);
        setXY0(sprt, obj->x.p.whole + e->x, obj->y.p.whole + e->y + NTSC_PAL(0, 0x18));
        setUV0(sprt, e->u, e->v);
        sprt->clut = GetClut(e->cx, e->cy);
        AddPrim((u_long *)D_1F8001E0 + ((s8)obj->priority + 0x324), sprt);
        D_1F800164 += sizeof(SPRT);
        drMode = (DR_MODE *)D_1F800164;
        SetDrawMode(drMode, 0, 0, e->tpage, 0);
        AddPrim((u_long *)D_1F8001E0 + ((s8)obj->priority + 0x324), drMode);
        e++;
        D_1F800164 += sizeof(DR_MODE);
    }
#if REGION == REGION_EU
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
#if REGION == REGION_JP
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
#if REGION == REGION_JP
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
    SPRT *sprt;
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
        sprt = (SPRT *)D_1F800164;
        SetSprt(sprt);
        sprt->code |= 1;
        SetSemiTrans(sprt, 1);
        setXY0(sprt, x + f->dx, y + f->dy);
        sprt->u0 = f->u;
        cnt--;
        sprt->v0 = f->v;
        setWH(sprt, f->w, f->h);
        sprt->clut = f->clut;
        f++;
        AddPrim(D_1F8001E0 + 4, sprt);
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
#if REGION == REGION_JP
#define N_4E900 s->n
#else
#define N_4E900 ((s16)n)
#endif
    s32 i = 0;
    SPRT *sprt;
    u8 *e;
    s32 cy;

    for (; i < D_8009BCD9; i++) {
        {
            sprt = (SPRT *)D_1F800164;
            e = s->base + *(s16 *)(*(u8 *volatile *)&s->base + (*s->tbl[i] << 2) + 2);
            SetSprt(sprt);
            sprt->code |= 1;
            SetSemiTrans(sprt, 0);
            setXY0(sprt, x + (s8)e[0xe], y + (s8)e[0xf]);
            setUV0(sprt, e[0], e[1]);
            setWH(sprt, e[10], e[11]);
            if (i < N_4E900) {
                if (N_4E900 < 3)
                    sprt->clut = GetClut(0x170, 0x1f7);
                else if (N_4E900 < 5)
                    sprt->clut = GetClut(0x170, 0x1f6);
                else if (N_4E900 < 7)
                    sprt->clut = GetClut(0x170, 0x1f5);
                else
                    sprt->clut = GetClut(0x170, 0x1f4);
            } else {
                sprt->clut = GetClut(0x170, 0x1f8);
            }
            AddPrim(D_1F8001E0 + 4, sprt);
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

void func_8004EB10(GameObject *obj, s32 idx, s16 x, s16 y, s16 flag)
{
    SPRT *sprt;
    u8 *s;
    s16 r[4];
    s32 c;

    if (flag)
        func_8004F2CC(obj, (s16)(x + 8), y, *(u16 *)((void **)obj->movetab)[D_8009C100[idx] + 1]);
    sprt = (SPRT *)D_1F800164;
    s = (u8 *)obj->z.raw + *(s16 *)(*(volatile s32 *)&obj->z.raw + (*(u16 *)obj->localY << 2) + 2);
    SetSprt(sprt);
    sprt->code |= 1;
    setXY0(sprt, x, y);
    setUV0(sprt, s[0], s[1]);
    setWH(sprt, s[10], s[11]);
    c = *((u8 *)obj + idx + 0x64) + 0x1e4;
    sprt->clut = GetClut(0x150, idx * 4 + c);
    AddPrim(D_1F8001E0 + 4, sprt);
    ((SPRT *)D_1F800164)++;
    addDrawModePrim(0x14, 1);
    r[0] = x + 0x13;
    r[1] = y + 2;
#if REGION == REGION_JP
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
    SPRT *sprt;
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
        sprt = (SPRT *)D_1F800164;
        q = (u8 *)(*(volatile s32 *)(o + 0x18) + *(s16 *)(*(volatile s32 *)(o + 0x18) + (*(*(u16 **)&D_80012314) << 2) + 2));
        SetSprt(sprt);
        sprt->code |= 1;
        SetSemiTrans(sprt, 0);
        setXY0(sprt, x + (s8)q[0xe], y + (s8)q[0xf]);
        setUV0(sprt, q[0], q[1]);
        ot = (void *)(D_1F8001E0 + 4);
        sprt->w = q[0xa];
        c = q[0xb];
        sprt->clut = 0x7e14;
        sprt->h = c;
        AddPrim(ot, sprt);
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
            setXY0(p, MESSAGE_SLOTS[a].x + MESSAGE_GLYPHS[a][i].x - 0xb, MESSAGE_SLOTS[a].y + MESSAGE_GLYPHS[a][i].y - 10);
        }
        SETUV0(p, GLYPH_CACHE[f].u << 2, GLYPH_CACHE[f].v);
        setWH(p, GLYPH_CACHE[f].w, GLYPH_CACHE[f].h);
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
    DR_MODE* drMode = scratch->nextprim;

    SetDrawMode(drMode, 0, 0, tpage, 0);
    AddPrim(scratch->ot + (p * 4),drMode);
    scratch->nextprim += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F2CC);

void func_8004F2CC(s32 obj, s16 x, s16 y, u16 idx)
{
    SPRT *sprt;
    u8 *s;
    s32 t;
    s32 tb;
    s32 i;
    i = idx * 4;
    sprt = (SPRT *)D_1F800164;
    s = (u8 *)(*(volatile s32 *)(obj + 0x18) + *(s16 *)(*(volatile s32 *)(obj + 0x18) + i + 2));
    SetSprt(sprt);
    sprt->code = sprt->code | 1;
    SetSemiTrans(sprt, 0);
    setXY0(sprt, x + (s8)s[0xe], y + (s8)s[0xf]);
    setUV0(sprt, s[0], s[1]);
    t = D_1F8001E0;
    setWH(sprt, s[10], s[0xb]);
    sprt->clut = *(u16 *)(s + 2);
    AddPrim((void *)(t + 4), sprt);
    D_1F800164 = (u8 *)((SPRT *)D_1F800164 + 1);
}

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F3DC);
void func_8004F3DC(SPR_4E900 *a, s16 x, s16 y, u16 idx)
{
    s16 *e;
    s32 n;
    SprFrag *f;
    SPRT *sprt;

    e = (s16 *)(a->base + idx * 4);
    f = (SprFrag *)(*(u8 *volatile *)&a->base + e[1]);
    n = *e;
    do {
        sprt = (SPRT *)D_1F800164;
        SetSprt(sprt);
        sprt->code |= 1;
        SetSemiTrans(sprt, 0);
        setXY0(sprt, x + f->dx, y + f->dy);
        sprt->u0 = f->u;
        n--;
        sprt->v0 = f->v;
        setWH(sprt, f->w, f->h);
        sprt->clut = f->clut;
        f++;
        AddPrim(D_1F8001E0 + 4, sprt);
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

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004F5A4);
typedef struct { s16 x; s16 y; u8 *text; } MenuLine;
typedef struct { s16 x; s16 y; } MenuPos;
extern MenuLine D_8007ED10[];
extern MenuLine D_8007ED30[];
extern MenuLine D_8007ED50[];
extern MenuLine D_8007ED70[];
extern u8 D_8007EC94[][2];
extern MenuPos D_8007ED98[];
extern u8 D_8009C10B_Arr[] asm("D_8009C10B");

#if REGION == REGION_JP
extern s16 D_800783F0_slps01144[];
extern s16 D_800783F8_slps01144[];
extern s16 D_80078404_slps01144[];
extern s16 **D_800783CC_slps01144[];
extern s16 **D_800783E8_slps01144[];
void func_8004F5A4(void)
{
    TILE *tile;
    void *r;
    s16 *e;
    SprFrag *f;
    POLY_FT4 *poly;
    s32 i;
    s16 n;
    s32 w;
    s16 **q;
    tile = (TILE *)D_1F800164;
    setWH(tile, 0x140, 0xF0);
    setXY0(tile, 0, 0);
    setlen(tile, 3);
    tile->code = 0x60;
    SetSemiTrans(tile, 1);
    setRGB0(tile, 0x20, 0x20, 0x20);
    AddPrim((u_long *)D_1F8001E0 + 4, tile);
    r = D_1F800164 = D_1F800164 + sizeof(TILE);
    SetDrawMode(r, 0, 0, 0, 0);
    AddPrim((u_long *)D_1F8001E0 + 4, r);
    tile = (TILE *)(D_1F800164 = D_1F800164 + sizeof(DR_MODE));
    if (D_8009C10B_Arr[0] < 4) {
        setWH(tile, 0x30, 0xC);
        setXY0(tile, 0x88, D_800783F0_slps01144[D_8009C10B_Arr[0]]);
        setlen(tile, 3);
        tile->code = 0x60;
        SetSemiTrans(tile, 1);
        setRGB0(tile, 0xFF, 0xFF, 0);
        AddPrim((u_long *)D_1F8001E0 + 1, tile);
        r = D_1F800164 = D_1F800164 + sizeof(TILE);
        SetDrawMode(r, 0, 0, 0, 0);
        AddPrim((u_long *)D_1F8001E0 + 1, r);
        D_1F800164 = D_1F800164 + sizeof(DR_MODE);
    }
    if (D_8009C10B_Arr[0] < 4)
        i = 5;
    else
        i = 1;
    for (; i >= 0; i--) {
        if (D_8009C10B_Arr[0] < 4)
            q = D_800783CC_slps01144[i];
        else
            q = D_800783E8_slps01144[i];
        e = (s16 *)(D_1F8002D8[0] + *q[0] * 4);
        n = e[0];
        f = (SprFrag *)(D_1F8002D8[0] + e[1]);
        do {
            poly = (POLY_FT4 *)D_1F800164;
            setlen(poly, 9);
            poly->code = 0x2D;
            if (i == 0)
                SetSemiTrans(poly, 1);
            else
                SetSemiTrans(poly, 0);
            *(u32 *)&poly->u0 = *(u32 *)f;
            *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
            *(u16 *)&poly->u2 = *(u32 *)&f->uv2;
            *(u16 *)&poly->u3 = *(u32 *)&f->uv3;
            if (i != 0) {
                poly->u1 = poly->u1 + 1;
                poly->u3 = poly->u3 + 1;
                poly->v2 = poly->v2 + 1;
                poly->v3 = poly->v3 + 1;
            }
            poly->tpage = 0x14;
            setXY0(poly, (s16)(f->dx + 0xA0) + D_80078404_slps01144[i], D_800783F8_slps01144[i] + f->dy);
            w = f->w;
            poly->x2 = poly->x0;
            poly->x1 = poly->x0 + w;
            poly->y1 = poly->y0;
            poly->y2 = poly->y0 + f->h;
            poly->x3 = poly->x1;
            poly->y3 = poly->y2;
            if (i == 0) {
                poly->clut = GetClut(0x160, 0x1E5);
                AddPrim((u_long *)D_1F8001E0 + 2, poly);
            } else {
                poly->clut = GetClut(0x160, 0x1E3);
                AddPrim((u_long *)D_1F8001E0, poly);
            }
            f++;
            n--;
            D_1F800164 = D_1F800164 + sizeof(POLY_FT4);
        } while (n != 0);
    }
}
#elif REGION == REGION_EU
#if LANGUAGE == LANGUAGE_GERMAN || LANGUAGE == LANGUAGE_ITALIAN || LANGUAGE == LANGUAGE_DUTCH || LANGUAGE == LANGUAGE_DANISH
#define MENU_KIND_0 3
#define MENU_KIND_2 4
#define MENU_KIND_3 4
#elif LANGUAGE == LANGUAGE_SPANISH
#define MENU_KIND_0 1
#define MENU_KIND_2 4
#define MENU_KIND_3 4
#elif LANGUAGE == LANGUAGE_PORTUGUESE
#define MENU_KIND_0 1
#define MENU_KIND_2 2
#define MENU_KIND_3 4
#else
#define MENU_KIND_0 1
#define MENU_KIND_2 2
#define MENU_KIND_3 2
#endif

void func_8004F5A4(void)
{
    MenuLine *l;
    s32 kind;
    u8 *c;
    u8 ch;
    u16 x;
    s16 y;
    TILE *tile;
    SPRT *sprt;
    void *r;
    s32 tp;
    s16 *e;
    SprFrag *f;
    POLY_FT4 *poly;
    s16 n;
    s32 k;
    s32 w;

    switch (SPAD->menuCloseMode) {
    case 0:
        l = D_8007ED70;
        kind = MENU_KIND_0;
        break;
    case 1:
        l = D_8007ED10;
        kind = 0;
        break;
    case 2:
        l = D_8007ED30;
        kind = MENU_KIND_2;
        break;
    case 3:
        kind = MENU_KIND_3;
        l = D_8007ED50;
        break;
    }
    tile = (TILE *)D_1F800164;
    setWH(tile, 0x140, 0x100);
    setlen(tile, 3);
    setXY0(tile, 0, 0);
    tile->code = 0x60;
    SetSemiTrans(tile, 1);
    setRGB0(tile, 0x20, 0x20, 0x20);
    AddPrim((u_long *)D_1F8001E0 + 4, tile);
    r = D_1F800164 = D_1F800164 + sizeof(TILE);
    SetDrawMode(r, 0, 0, 0, 0);
    AddPrim((u_long *)D_1F8001E0 + 4, r);
    D_1F800164 = D_1F800164 + sizeof(DR_MODE);
    for (; l->x != -1; l++) {
        x = l->x;
        y = l->y;
        c = l->text;
        while ((ch = *c) != 0xFF) {
            c++;
            if (ch) {
                sprt = (SPRT *)D_1F800164;
                setlen(sprt, 4);
                sprt->code = 0x65;
                SetSemiTrans(sprt, 0);
                setXY0(sprt, x, y);
                setUV0(sprt, D_8007EC94[ch][0], D_8007EC94[ch][1]);
                setWH(sprt, 8, 0x10);
                sprt->clut = GetClut(0x160, 0x1E3);
                AddPrim((u_long *)D_1F8001E0 + 1, sprt);
                D_1F800164 = D_1F800164 + sizeof(SPRT);
            }
            x += 8;
        }
    }
    r = D_1F800164;
#if VERSION == 0
    tp = 0x14;
#else
    if (GetGraphType() == 1)
        tp = 0x24;
    else if (GetGraphType() == 2)
        tp = 0x24;
    else
        tp = 0x14;
#endif
    SetDrawMode(r, 0, 0, tp, 0);
    AddPrim((u_long *)D_1F8001E0 + 1, r);
    tile = (TILE *)(D_1F800164 = D_1F800164 + sizeof(DR_MODE));
    switch (kind) {
    case 0:
        tile->x0 = 0x74;
        k = D_8009C10B_Arr[0];
        setWH(tile, 0x50, 0x10);
        k <<= 4;
        k += 0x58;
        tile->y0 = k;
        break;
    case 1:
        tile->x0 = 0x84;
        k = D_8009C10B_Arr[0];
        setWH(tile, 0x38, 0x10);
        k <<= 4;
        k += 0x58;
        tile->y0 = k;
        break;
    case 3:
        tile->x0 = 0x74;
        k = D_8009C10B_Arr[0];
        setWH(tile, 0x58, 0x10);
        k <<= 4;
        k += 0x58;
        tile->y0 = k;
        break;
    case 2:
    case 4:
        k = D_8009C10B_Arr[0];
        tile->y0 = 0x78;
        setWH(tile, 0x28, 0x10);
        tile->x0 = k * 0x30 + 0x74;
        break;
    }
    setlen(tile, 3);
    tile->code = 0x60;
    SetSemiTrans(tile, 1);
    setRGB0(tile, 0xFF, 0xFF, 0);
    AddPrim((u_long *)D_1F8001E0 + 1, tile);
    D_1F800164 = D_1F800164 + sizeof(TILE);
    e = (s16 *)(D_1F8002D8[0] + *((s16 **)D_800123E4)[kind] * 4);
    n = e[0];
    f = (SprFrag *)(D_1F8002D8[0] + e[1]);
    do {
        poly = (POLY_FT4 *)D_1F800164;
        setlen(poly, 9);
        poly->code = 0x2D;
        SetSemiTrans(poly, 1);
        *(u32 *)&poly->u0 = *(u32 *)f;
        *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
        *(u16 *)&poly->u2 = *(u16 *)&f->uv2;
        *(u16 *)&poly->u3 = *(u16 *)&f->uv3;
        poly->tpage = 0x14;
        setXY0(poly, D_8007ED98[kind].x + f->dx, D_8007ED98[kind].y + f->dy);
        w = f->w;
        poly->x2 = poly->x0;
        poly->x1 = poly->x0 + w;
        poly->y1 = poly->y0;
        poly->y2 = poly->y0 + f->h;
        poly->x3 = poly->x1;
        poly->y3 = poly->y2;
        poly->clut = GetClut(0x160, 0x1E5);
        AddPrim((u_long *)D_1F8001E0 + 1, poly);
        f++;
        n--;
        D_1F800164 = D_1F800164 + sizeof(POLY_FT4);
    } while (n != 0);
}
#else
void func_8004F5A4(void)
{
    MenuLine *l;
    s32 kind;
    u8 *c;
    u8 ch;
    u16 x;
    s16 y;
    TILE *tile;
    SPRT *sprt;
    void *r;
    s32 tp;
    s16 *e;
    SprFrag *f;
    POLY_FT4 *poly;
    s16 n;
    s32 k;
    s32 w;
    s32 tpage;

    tile = (TILE *)D_1F800164;
    setWH(tile, 0x140, 0xF0);
    setlen(tile, 3);
    setXY0(tile, 0, 0);
    tile->code = 0x60;
    SetSemiTrans(tile, 1);
    setRGB0(tile, 0x20, 0x20, 0x20);
    AddPrim((u_long *)D_1F8001E0 + 4, tile);
    r = D_1F800164 = D_1F800164 + sizeof(TILE);
    SetDrawMode(r, 0, 0, 0, 0);
    AddPrim((u_long *)D_1F8001E0 + 4, r);
    D_1F800164 = D_1F800164 + sizeof(DR_MODE);
    switch (SPAD->menuCloseMode) {
    case 0:
        l = D_8007ED70;
        kind = 1;
        break;
    case 1:
        l = D_8007ED10;
        kind = 0;
        break;
    case 2:
        l = D_8007ED30;
        kind = 2;
        break;
    case 3:
        kind = 2;
        l = D_8007ED50;
        break;
    }
    for (; l->x != -1; l++) {
        x = l->x;
        y = l->y;
        c = l->text;
        while ((ch = *c) != 0xFF) {
            c++;
            if (ch) {
                sprt = (SPRT *)D_1F800164;
                setlen(sprt, 4);
                sprt->code = 0x65;
                SetSemiTrans(sprt, 0);
                setXY0(sprt, x, y);
                setUV0(sprt, D_8007EC94[ch][0], D_8007EC94[ch][1]);
                setWH(sprt, 8, 0x10);
                sprt->clut = GetClut(0x160, 0x1E3);
                AddPrim((u_long *)D_1F8001E0 + 1, sprt);
                D_1F800164 = D_1F800164 + sizeof(SPRT);
            }
            x += 8;
        }
    }
    r = D_1F800164;
    if (GetGraphType() == 1)
        tp = 0x24;
    else if (GetGraphType() == 2)
        tp = 0x24;
    else
        tp = 0x14;
    SetDrawMode(r, 0, 0, tp, 0);
    AddPrim((u_long *)D_1F8001E0 + 1, r);
    tile = (TILE *)(D_1F800164 = D_1F800164 + sizeof(DR_MODE));
    switch (kind) {
    case 0:
        tile->x0 = 0x74;
        k = D_8009C10B_Arr[0];
        setWH(tile, 0x50, 0x10);
        k <<= 4;
        k += 0x48;
        tile->y0 = k;
        break;
    case 1:
        tile->x0 = 0x84;
        k = D_8009C10B_Arr[0];
        setWH(tile, 0x38, 0x10);
        k <<= 4;
        k += 0x48;
        tile->y0 = k;
        break;
    case 2:
        k = D_8009C10B_Arr[0];
        tile->y0 = 0x68;
        setWH(tile, 0x18, 0x10);
        tile->x0 = k * 0x34 + 0x78;
        break;
    }
    setlen(tile, 3);
    tile->code = 0x60;
    SetSemiTrans(tile, 1);
    setRGB0(tile, 0xFF, 0xFF, 0);
    AddPrim((u_long *)D_1F8001E0 + 1, tile);
    D_1F800164 = D_1F800164 + sizeof(TILE);
    e = (s16 *)(D_1F8002D8[0] + *((s16 **)D_800123E4)[kind] * 4);
    n = e[0];
    f = (SprFrag *)(D_1F8002D8[0] + e[1]);
    do {
        poly = (POLY_FT4 *)D_1F800164;
        setlen(poly, 9);
        poly->code = 0x2D;
        SetSemiTrans(poly, 1);
        *(u32 *)&poly->u0 = *(u32 *)f;
        *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
        *(u16 *)&poly->u2 = *(u32 *)&f->uv2;
        *(u16 *)&poly->u3 = *(u32 *)&f->uv3;
        poly->tpage = 0x14;
        setXY0(poly, D_8007ED98[kind].x + f->dx, D_8007ED98[kind].y + f->dy);
        w = f->w;
        poly->x2 = poly->x0;
        poly->x1 = poly->x0 + w;
        poly->y1 = poly->y0;
        poly->y2 = poly->y0 + f->h;
        poly->x3 = poly->x1;
        poly->y3 = poly->y2;
        poly->clut = GetClut(0x160, 0x1E5);
        if (GetGraphType() == 1 || GetGraphType() == 2)
            tpage = 0x24;
        else
            tpage = 0x14;
        poly->tpage = tpage;
        AddPrim((u_long *)D_1F8001E0 + 1, poly);
        f++;
        n--;
        D_1F800164 = D_1F800164 + sizeof(POLY_FT4);
    } while (n != 0);
}
#endif

// INCLUDE_ASM("nonmatchings/main/render/sprite", func_8004FB54);
typedef struct { char p0[0xc]; u8 b0c, b0d, b0e, b0f, b10, b11, b12, b13; s16 s14, s16, s18, s1a; } P_4FB54;

void func_8004FB54(u8 a)
{
    P_4FB54 *p;
    void *r;
    s32 t, m;
#if (REGION == REGION_EU && VERSION == 0) || REGION == REGION_JP
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
#if (REGION == REGION_EU && VERSION == 0) || REGION == REGION_JP
    p = D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0x10);
#else
    r = D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0x10);
#endif
#if REGION == REGION_EU && VERSION == 0
    if (D_1F8003D1 == 1 || (u32)(D_8009BCA4 - 1) < 2) {
        m = 0x20;
    } else {
        m = 0x40;
    }
#else
#if REGION == REGION_JP
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
#if (REGION == REGION_EU && VERSION == 0) || REGION == REGION_JP
    SetDrawMode(p, 0, 0, m, 0);
    AddPrim(D_1F8001E0 + 0x10, p);
#else
    SetDrawMode(r, 0, 0, m, 0);
    AddPrim(D_1F8001E0 + 0x10, r);
#endif
    D_1F800164 = (P_4FB54 *)((char *)D_1F800164 + 0xc);
}
