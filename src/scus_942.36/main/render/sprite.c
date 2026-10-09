#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DC34);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DD14);
extern s16 D_1F8001C6;
extern u8 D_800A539A;
extern void func_8004A300(GameObject *);
extern void func_8004DFA0(GameObject *);
extern void func_8004E244(GameObject *);
extern void func_800EA3A4(GameObject *);
extern void func_800EBA58(GameObject *);
extern void func_8011DA28(GameObject *);
extern void func_80116308(GameObject *);

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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004DFA0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E244);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E3EC);

void func_8004E3EC(void)
{
    u8* p = D_800B0770;

    if (D_8009C618 != 3) {
        if (D_8009BCA7 != 0) {
            D_800B0778 = 0x78;
        }
        if (D_800B0778 == 0 && (p[0] & 1)) {
            func_8004E468(p);
        }
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E468);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E590);
typedef struct { char p[0x24]; u16 **tbl; char q[0x30 - 0x28]; u16 *dot; } O_4E590;
extern u8 D_8009BCE8;
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E714);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004E900);
typedef struct {
    char pad[0x18];
    u8 *base;
    s16 **tbl;
} SPR_4E900;
extern u8 D_8009BCD9;
extern SPRT *D_1F800164__4E900;
extern void func_8004F3DC(SPR_4E900 *s, s32 x, s32 y, s32 v);

void func_8004E900(SPR_4E900 *s, s16 x, s16 y, u16 n)
{
    s32 i = 0;
    SPRT *p;
    u8 *e;
    s32 cy;

    for (; i < D_8009BCD9; i++) {
        {
            p = D_1F800164__4E900;
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
            if (i < (s16)n) {
                if ((s16)n < 3)
                    p->clut = GetClut(0x170, 0x1f7);
                else if ((s16)n < 5)
                    p->clut = GetClut(0x170, 0x1f6);
                else if ((s16)n < 7)
                    p->clut = GetClut(0x170, 0x1f5);
                else
                    p->clut = GetClut(0x170, 0x1f4);
            } else {
                p->clut = GetClut(0x170, 0x1f8);
            }
            AddPrim(D_1F8001E0 + 4, p);
            D_1F800164__4E900 = D_1F800164__4E900 + 1;
        }
    }
    func_8004F3DC(s, (s16)x, (s16)y, *((u16 **)&D_80012208)[(s16)n]);
    addDrawModePrim(0x15, 1);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004EB10);
typedef struct {
    u32 tag;
    u8 r0, g0, b0, code;
    s16 x0, y0;
    u8 u0, v0;
    u16 clut;
    u16 w, h;
} Sprt_4EB10;
typedef struct { u8 a, pa, b, pb, c, pc; } Col6_4EB10;

extern Sprt_4EB10 *D_1F800164__4EB10;
extern u8 D_8009C100[];
extern u8 D_8009C104[];
extern u8 D_8009C107;
extern u8 D_8009C40C[];
extern u8 D_8009BCF8;
extern s16 D_8007EC70[];
extern s16 D_8007EC78[];
extern Col6_4EB10 D_8007EC80[];

void func_8004EB10(GameObject *o, s32 idx, s16 x, s16 y, s16 flag)
{
    extern void addTilePrim(s16 *, s32, s32, s32);
    Sprt_4EB10 *p;
    u8 *s;
    s16 r[4];
    s32 c;

    if (flag)
        func_8004F2CC(o, (s16)(x + 8), y, *(u16 *)((void **)o->movetab)[D_8009C100[idx] + 1]);
    p = D_1F800164__4EB10;
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
    D_1F800164__4EB10++;
    addDrawModePrim(0x14, 1);
    r[0] = x + 0x13;
    r[1] = y + 2;
    if (!flag && D_8009C40C[D_8007EC70[idx]] && D_8009BCF8 == D_8007EC78[idx])
        r[2] = D_8009C107;
    else
        r[2] = D_8009C104[idx];
    r[3] = 4;
    addTilePrim(r, 0xff, 0xff, 0);
    r[0] = x + 0x13;
    r[1] = y + 2;
    r[2] = 0x3d;
    r[3] = 4;
    addTilePrim(r, D_8007EC80[idx].a, D_8007EC80[idx].b, D_8007EC80[idx].c);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004ED80);
extern SPRT *D_1F800164__4ED80;

void func_8004ED80(s32 o, s16 x, s16 y)
{
    SPRT *p;
    u8 *q;
    s32 m;
    void *ot;
    u8 c;
    switch (D_8009C61A) {
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
        p = D_1F800164__4ED80;
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
        D_1F800164__4ED80++;
        addDrawModePrim(0x14, 1);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", drawMessageGlyphs);
typedef struct { s16 x, y; s16 pad[8]; } DRAWENV__4EFA8;
typedef struct { s16 n, pad, x, y; } GA_4EFA8;
typedef struct { u16 f; s16 pad, x, y; } GE_4EFA8;
typedef struct { u8 u, v, w, h, b4, b5, pad[4]; } GT_4EFA8;
extern GA_4EFA8 MESSAGE_SLOTS__4EFA8[];
extern GE_4EFA8 MESSAGE_GLYPHS[][128];
extern GT_4EFA8 D_800A5144[];
extern SPRT *D_1F800164__4EFA8;

#define SETUV0(p, u, v) do { (p)->u0 = (u); (p)->v0 = (v); } while (0)
typedef struct { s16 clip[4]; s16 ofs[2]; s16 tw[4]; u16 tpage; char rest[0x68 - 0x16]; } DRAWENV_4EFA8;
extern void GetDrawEnv__4EFA8(DRAWENV_4EFA8 *env);

void drawMessageGlyphs(s32 a)
{
    DRAWENV_4EFA8 env;
    SPRT *p;
    s32 i;
    s16 f;

    GetDrawEnv__4EFA8(&env);
    addDrawModePrim((s16)env.tpage, 1);
    for (i = 0; i < MESSAGE_SLOTS__4EFA8[a].n; i++) {
        f = MESSAGE_GLYPHS[a][i].f;
        if (*(s16 *)&MESSAGE_GLYPHS[a][i].f & 0x8000) {
            MESSAGE_GLYPHS[a][i].f = f & 0x7fff;
            continue;
        }
        p = D_1F800164__4EFA8;
        SetSprt(p);
        p->code |= 1;
        f &= 0xfff;
        if (D_800A5144[f].b5 == 0) {
            p->x0 = MESSAGE_SLOTS__4EFA8[a].x + MESSAGE_GLYPHS[a][i].x;
            if (D_800A5144[f].w >= 0xb)
            { p->y0 = MESSAGE_SLOTS__4EFA8[a].y + MESSAGE_GLYPHS[a][i].y - 2; }
            else
            {    p->y0 = MESSAGE_SLOTS__4EFA8[a].y + MESSAGE_GLYPHS[a][i].y; }
        } else {
            p->x0 = MESSAGE_SLOTS__4EFA8[a].x + MESSAGE_GLYPHS[a][i].x - 0xb;
            p->y0 = MESSAGE_SLOTS__4EFA8[a].y + MESSAGE_GLYPHS[a][i].y - 10;
        }
        SETUV0(p, D_800A5144[f].u << 2, D_800A5144[f].v);
        p->w = D_800A5144[f].w;
        p->h = D_800A5144[f].h;
        p->clut = GetClut(0x160, 0x1e3);
        AddPrim(D_1F8001E0 + 4, p);
        D_1F800164__4EFA8++;
    }
    addDrawModePrim(0, 1);
}
#undef SETUV0

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", addDrawModePrim);
void addDrawModePrim(short tpage, int p) {
    scratchpad* scratch = PSX_SCRATCH;
    DR_MODE* mode = scratch->nextprim;

    SetDrawMode(mode, 0, 0, tpage, 0);
    AddPrim(scratch->ot + (p * 4),mode);
    scratch->nextprim += sizeof(DR_MODE);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/sprite", func_8004F2CC);
extern SPRT *D_1F800164__4F2CC;

void func_8004F2CC(s32 obj, s16 x, s16 y, u16 idx)
{
    SPRT *p;
    u8 *s;
    s32 t;
    s32 tb;
    s32 i;
    i = idx * 4;
    p = D_1F800164__4F2CC;
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
    D_1F800164__4F2CC = D_1F800164__4F2CC + 1;
}

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
