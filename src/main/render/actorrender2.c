#include "common.h"
#include "game.h"
#include "game/area_module.h"
#include "game/gte.h"

u32 D_8007EB7C_d[1] asm("D_8007EB7C") = {
    0x00100010,
};
u32 D_8007EB80_d[1] asm("D_8007EB80") = {
    0xFFF8FFF8,
};

asm(
    ".globl D_8007EB82\nD_8007EB82 = D_8007EB80 + 2\n"
);

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80045EFC);
void func_8004D448(GameObject *o);

void func_80045EFC(GameObject *obj)
{
    if (obj->visible == 0) return;
    if ((obj->drawType & 0x10) && obj->model == 0) return;
    if ((*(s32 *)&GAME) == 9 && D_8009BCCC != 0x20 && D_8009BCA2 == 1 &&
        obj->z.p.whole < 0xb6d && (obj->category & 0x7f) != 8) return;
    if ((*(u16 *)&GAME) == 10 && (D_8009BCCA == 0 || D_8009BCCA == 4) && D_8009BCCC != 0 &&
        (u16)(obj->z.p.whole + 9) < 0x13 && (obj->category & 0x7f) != 8) return;
    if ((*(s32 *)&GAME) == 6) {
        switch (obj->drawType) {
        case DRAW_SPRITE: func_8011C234(obj); break;
        case DRAW_SPRITE_SCALED: func_8011C500(obj); break;
        case DRAW_SPRITE_ROTATED: func_8011C824(obj); break;
        case DRAW_SPRITE_SCALED_ROTATED: func_8011CF38(obj); break;
        case DRAW_MODEL: goto c10;
        case DRAW_MODEL_ROTATED: goto c11;
        case DRAW_MODEL_EX_ROTATED: goto c12;
        case DRAW_MODEL_ROTATED_SCALED: goto c13;
        case DRAW_MODEL_SCREEN: goto c14;
        case DRAW_MODEL_MATRIX: goto c15;
        case DRAW_MODEL_EX_MATRIX: goto c16;
        }
        return;
    }
    switch (func_80045D0C(obj)) {
    case DRAW_SPRITE: func_800487A4(obj); break;
    case DRAW_SPRITE_SCALED: func_80048BF0(obj); break;
    case DRAW_SPRITE_ROTATED: func_80049134(obj); break;
    case DRAW_SPRITE_SCALED_ROTATED: func_80049994(obj); break;
    case DRAW_SPRITE_3D: func_8004AA70(obj); break;
    case DRAW_AREA:
        switch (D_800A539A) {
        case 1: func_800E9EB8(obj); break;
        case 2: func_800EB490(obj); break;
        case 3: func_800EAAC8(obj); break;
        }
        break;
    case DRAW_OVERLAY_6: func_80123314(obj); break;
    case DRAW_OVERLAY_7: func_8011DF10(obj); break;
    case DRAW_OVERLAY_8: func_8011E584(obj); break;
    case DRAW_OVERLAY_9: func_8011AB74(obj); break;
    case DRAW_OVERLAY_10: func_8011B350(obj); break;
    case DRAW_SPRT: func_8004A6A0(obj); break;
    case DRAW_MODEL: c10: func_8004D1A0(obj); break;
    case DRAW_MODEL_ROTATED: c11: func_8004D2A8(obj); break;
    case DRAW_MODEL_EX_ROTATED: c12: func_8004D448(obj); break;
    case DRAW_MODEL_ROTATED_SCALED: c13: func_8004D5F0(obj); break;
    case DRAW_MODEL_SCREEN: c14: func_8004D7E0(obj); break;
    case DRAW_MODEL_MATRIX: c15: func_8004D91C(obj); break;
    case DRAW_MODEL_EX_MATRIX: c16: func_8004DA28(obj); break;
    }
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80046264);
extern void func_8004FB54(s32);

void func_80046264(void)
{
    s32 u;
    SetLightMatrix(D_1F800118);
    func_8004637C();
    func_80046CDC();
    func_8004AD8C();
    func_8004AFAC();
    func_8004D0C0();
    func_8004CFE0();
    func_8004DB3C();
    func_8004DC34();
    func_8004DD14();
    if (D_1F8001C6 == 1)
        func_8004F5A4();
    switch (D_8009BCDD) {
    case 1:
    case 4:
        u = 0xff;
        break;
    case 2:
        u = 0xff;
        u -= D_8009BCDE;
        break;
    case 3:
    case 0x10:
        u = D_8009BCDE;
        break;
    default:
        goto end;
    }
    func_8004FB54(u);
end:
    if ((*(s32 *)&GAME) == 6)
        func_8011AF78();
    else
        func_8004E3EC();
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004637C);
void func_8004637C(void)
{
    u8 *p = &PLAYER.obj;
    if (D_800A5399_U8Arr[0] != 0) {
        switch (D_800A539A_U8Arr[0]) {
        case 0:
            func_80046428(p);
            break;
        case 1:
            func_800E9484(p);
            break;
        case 2:
            func_800EAA5C(p);
            break;
        case 3:
            func_800EA094(p);
            break;
        }
    }
}

typedef struct { char pad[7]; s8 b7; char pad8[0x18 - 8]; u16 w18, w1a; char pad1C[0xC]; u16 w28[2]; } PL_46EC0;
typedef struct { char pad[0x4c]; u16 w4c; } C4C_46EC0;
extern PL_46EC0 *D_8009B698;
extern s32 fixedMulCos(s32, s16);
extern s32 fixedMulSin2(s32, s16);
extern s32 fixedMulSin(s32, s16);
extern s32 angleBetweenPoints(Vec2s, Vec2s);


static __inline__ s32 proj_46EC0(void)
{
    gte_ldv0((s16 *)&D_1F800060);
    gte_rtps();
    gte_stflg(&D_1F80008C);
    if (D_1F80008C < 0) return 1;
    gte_stsxy(&LZ_FILE_CTRL_Long);
    gte_stszotz(&D_1F800074);
    return 0;
}

static __inline__ s32 otadd_46EC0(unsigned long *a, char *b, s32 c, s16 d, unsigned long e)
{
    s32 k = c * 4;
    k += d * 4;
    if (k < 0) k = 0;
    k += (s32)b;
    if ((u32)(k - (s32)D_1F8001E0) >= 0xca0) return 1;
    {
        unsigned long v = *(unsigned long *)k;
        *(unsigned long *)k = (unsigned long)a;
        *a = v | e;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80046428);
#define A0_46428 (ang & 0xff)
#define A1_46428 ((ang + 0x80) & 0xff)
#define SN_46428(i) COS_TABLE[i]
#define CS_46428(i) NEG_SIN_TABLE[i]
#define C_46428 fr->w
#define D_46428 fr->h

void func_80046428(obj)
GameObject *obj;
{
    extern void uploadSpriteFrame();
    POLY_FT4 *poly;
    s16 *e;
    s16 n;
    SprFrag *fr;
    s16 s;
    s32 xy;
    s16 x, y;
    s32 ang;
    s16 A, B;
    s16 u, w;
    u16 af;
    u8 c;

    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    s = *(s16 *)obj->anim;
    xy = LZ_FILE_CTRL_Long;
    e = (s16 *)obj->spriteBank;
    e += s * 2;
    fr = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + e[1]);
    n = ((u16 *)e)[0];
    x = xy;
    y = (u32)xy >> 16;
    if (D_8009B698->w28[SPAD->frameBufferIndex] != s) {
        if (GAME.selectedArea == 6) {
            switch (D_8009BCCA) {
            case 0:
            case 1:
                break;
            default:
                uploadSpriteFrame(obj);
            }
        }
        uploadSpriteFrame(obj);
    }
    ang = obj->rotZ;
    D_8009B698->w18 = x;
    D_8009B698->w1a = y;
    do {
        A = fr->dx;
        B = fr->dy;
        poly = (POLY_FT4 *)D_1F800164;
        poly->code = 0x2d;
        SetSemiTrans(poly, 0);
        poly->tpage = obj->tpage;
        if (n & 2)
            poly->clut = obj->clut;
        else
            poly->clut = *(u16 *)((u8 *)obj + 0xc4);
        setUV0(poly, fr->u + ((u8)SPAD->frameBufferIndex << 6) + 4, fr->v + 4);
        c = C_46428;
        poly->u2 = poly->u0;
        poly->u1 = poly->u0 + c;
        poly->v1 = poly->v0;
        poly->v2 = poly->v0 + D_46428;
        poly->u3 = poly->u0 + C_46428;
        poly->v3 = poly->v0 + D_46428;
        if (obj->unk9D)
            af = D_8009B698->b7;
        else
            af = obj->animFrame;
        if (af & 1) {
            u = -(A + C_46428);
            w = B;
            poly->x1 = x + ((-u * SN_46428(A1_46428)) >> 12) + ((-w * SN_46428((A1_46428 + 0xc0) & 0xff)) >> 12);
            poly->y1 = y + ((-u * CS_46428(A1_46428)) >> 12) + ((-w * CS_46428((A1_46428 + 0xc0) & 0xff)) >> 12);
            setXY0(poly, x + (((u + C_46428) * SN_46428(A0_46428)) >> 12) + ((-w * SN_46428((A0_46428 + 0x40) & 0xff)) >> 12), y + (((u + C_46428) * CS_46428(A0_46428)) >> 12) + ((-w * CS_46428((A0_46428 + 0x40) & 0xff)) >> 12));
            poly->x3 = x + ((-u * SN_46428(A1_46428)) >> 12) + (((w + D_46428) * SN_46428((A1_46428 + 0x40) & 0xff)) >> 12);
            poly->y3 = y + ((-u * CS_46428(A1_46428)) >> 12) + (((w + D_46428) * CS_46428((A1_46428 + 0x40) & 0xff)) >> 12);
            poly->x2 = x + (((u + C_46428) * SN_46428(A0_46428)) >> 12) + (((w + D_46428) * SN_46428((A0_46428 + 0xc0) & 0xff)) >> 12);
            poly->y2 = y + (((u + C_46428) * CS_46428(A0_46428)) >> 12) + (((w + D_46428) * CS_46428((A0_46428 + 0xc0) & 0xff)) >> 12);
        } else {
            u = A;
            w = B;
            setXY4(poly, x + ((-u * SN_46428(A1_46428)) >> 12) + ((-w * SN_46428((A1_46428 + 0xc0) & 0xff)) >> 12), y + ((-u * CS_46428(A1_46428)) >> 12) + ((-w * CS_46428((A1_46428 + 0xc0) & 0xff)) >> 12), x + (((u + C_46428) * SN_46428(A0_46428)) >> 12) + ((-w * SN_46428((A0_46428 + 0x40) & 0xff)) >> 12), y + (((u + C_46428) * CS_46428(A0_46428)) >> 12) + ((-w * CS_46428((A0_46428 + 0x40) & 0xff)) >> 12), x + ((-u * SN_46428(A1_46428)) >> 12) + (((w + D_46428) * SN_46428((A1_46428 + 0x40) & 0xff)) >> 12), y + ((-u * CS_46428(A1_46428)) >> 12) + (((w + D_46428) * CS_46428((A1_46428 + 0x40) & 0xff)) >> 12), x + (((u + C_46428) * SN_46428(A0_46428)) >> 12) + (((w + D_46428) * SN_46428((A0_46428 + 0xc0) & 0xff)) >> 12), y + (((u + C_46428) * CS_46428(A0_46428)) >> 12) + (((w + D_46428) * CS_46428((A0_46428 + 0xc0) & 0xff)) >> 12));
        }
        {
            s32 k = D_1F800074;
            unsigned long m;

            do {
            } while (0);
            m = 0x9000000;
            if (!otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, k, (s8)obj->priority, m))
                D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
        fr++;
    } while (--n);
}
#undef A0_46428
#undef A1_46428
#undef SN_46428
#undef CS_46428
#undef C_46428
#undef D_46428

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80046CDC);
typedef struct { char p0[1]; u8 vis; char p1[8]; u8 k; } O_46CDC;

void func_80046CDC(void)
{
    s32 n;
    O_46CDC **pp;
    O_46CDC *o;
    if (D_1F8001C6 != 0) {
        n = (*(s16 *)&D_1F80024E);
        pp = D_1F80025C;
        if (n != 0) {
            do {
                o = *pp++;
                n--;
                switch (o->k) {
                case 0: func_80046EC0(o); break;
                case 2: func_80049134(o); break;
                case 0xd: func_8004A6A0(o); break;
                case 0x11: func_8004D2A8(o); break;
                }
            } while (n != 0);
        }
    } else {
        (*(s16 *)&D_1F80024E) = D_1F800244;
        D_1F80025C = D_1F800218;
        if (D_1F800244 != 0) {
            do {
                o = *D_1F800218++;
                D_1F800244 = D_1F800244 - 1;
                if (o->vis != 0) {
                    switch (o->k) {
                    case 0: func_80046EC0(o); break;
                    case 2: func_80049134(o); break;
                    case 0xd: func_8004A6A0(o); break;
                    case 0x11: func_8004D2A8(o); break;
                    }
                }
            } while ((*(s16 *)&D_1F800244) != 0);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80046EC0);


#define COS(i) COS_TABLE[i]
#define SIN(i) NEG_SIN_TABLE[i]

#define SHADOW(q) { \
    p = (POLY_FT4 *)D_1F800164; \
    func_8004FE24(o, D_8009B6A0->x, D_8009B6A0->y); \
    p->code = 0x2c; \
    SetSemiTrans(p, 1); \
    p->tpage = D_8009B6A0->tpage2; \
    p->clut = D_8009B6A0->clut2; \
    p->u0 = 0xc0; \
    p->u2 = 0xc0; \
    p->v0 = 0; \
    p->u1 = 0xcf; \
    p->v1 = 0; \
    p->v2 = 0xf; \
    p->u3 = 0xcf; \
    p->v3 = 0xf; \
    p->x0 = q[0]; \
    p->x1 = q[2]; \
    p->x2 = q[4]; \
    p->x3 = q[6]; \
    p->y0 = q[1]; \
    p->y1 = q[3]; \
    p->y2 = q[5]; \
    p->y3 = q[7]; \
    p->r0 = 0x40; \
    p->g0 = 0x40; \
    p->b0 = 0x40; \
    if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->priority - 5, 0x9000000) == 0) \
        D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1); \
}

static __inline__ void quadA_46EC0(POLY_FT4 *poly, s16 x, s16 y, s16 a0, s16 a1)
{
s32 m, n2, m2, n;
    D_8007EB80 = -(D_8007EB80 + D_8007EB7C);
    m = -D_8007EB80;
    n = -D_8007EB82;
    poly->x1 = x + ((m * COS(a1)) >> 12) + ((n * COS((a1 + 0xc0) & 0xff)) >> 12);
    poly->y1 = y + ((m * SIN(a1)) >> 12) + ((n * SIN((a1 + 0xc0) & 0xff)) >> 12);
    m2 = D_8007EB80 + D_8007EB7C;
    setXY0(poly, x + ((m2 * COS(a0)) >> 12) + ((n * COS((a0 + 0x40) & 0xff)) >> 12), y + ((m2 * SIN(a0)) >> 12) + ((n * SIN((a0 + 0x40) & 0xff)) >> 12));
    n2 = D_8007EB82 + D_8007EB7E;
    poly->x3 = x + ((m * COS(a1)) >> 12) + ((n2 * COS((a1 + 0x40) & 0xff)) >> 12);
    poly->y3 = y + ((m * SIN(a1)) >> 12) + ((n2 * SIN((a1 + 0x40) & 0xff)) >> 12);
    poly->x2 = x + ((m2 * COS(a0)) >> 12) + ((n2 * COS((a0 + 0xc0) & 0xff)) >> 12);
    poly->y2 = y + ((m2 * SIN(a0)) >> 12) + ((n2 * SIN((a0 + 0xc0) & 0xff)) >> 12);
}

static __inline__ void quadB_46EC0(POLY_FT4 *poly, s16 x, s16 y, s16 a0, s16 a1)
{
s32 m, n2, m2, n;
    m = -D_8007EB80;
    n = -D_8007EB82;
    setXY0(poly, x + ((m * COS(a1)) >> 12) + ((n * COS((a1 + 0xc0) & 0xff)) >> 12), y + ((m * SIN(a1)) >> 12) + ((n * SIN((a1 + 0xc0) & 0xff)) >> 12));
    m2 = D_8007EB80 + D_8007EB7C;
    poly->x1 = x + ((m2 * COS(a0)) >> 12) + ((n * COS((a0 + 0x40) & 0xff)) >> 12);
    poly->y1 = y + ((m2 * SIN(a0)) >> 12) + ((n * SIN((a0 + 0x40) & 0xff)) >> 12);
    n2 = D_8007EB82 + D_8007EB7E;
    poly->x2 = x + ((m * COS(a1)) >> 12) + ((n2 * COS((a1 + 0x40) & 0xff)) >> 12);
    poly->y2 = y + ((m * SIN(a1)) >> 12) + ((n2 * SIN((a1 + 0x40) & 0xff)) >> 12);
    poly->x3 = x + ((m2 * COS(a0)) >> 12) + ((n2 * COS((a0 + 0xc0) & 0xff)) >> 12);
    poly->y3 = y + ((m2 * SIN(a0)) >> 12) + ((n2 * SIN((a0 + 0xc0) & 0xff)) >> 12);
}

void func_80046EC0(GameObject *o)
{
    Vec2s s;
    Vec2s t;
    u8 tbl[36] = {
        0x00, 0x00, 0x06, 0x16, 0x54, 0x18, 0x00, 0x00, 0x1f, 0x18, 0x60, 0x18,
        0x00, 0x00, 0x40, 0x1d, 0x6f, 0x17, 0x00, 0x00, 0x08, 0x16, 0x58, 0x18,
        0x00, 0x00, 0x24, 0x1a, 0x68, 0x1a, 0x00, 0x00, 0x3c, 0x1a, 0x70, 0x16 };
    s16 idx;
    s16 x, y;
    u32 a0, a1;
    POLY_FT4 *p;
    s32 ang, c, sn, r;
    s16 k;
    s16 t1;

    D_1F800060.vx = o->x.p.whole;
    D_1F800062 = o->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = o->z.p.whole >> 2;
    else
        D_1F800064 = o->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    idx = 0;
    x = LZ_FILE_CTRL_Long;
    y = (unsigned long)LZ_FILE_CTRL_Long >> 16;
    D_8009B6A0->x = x;
    D_8009B6A0->y = y;
    a0 = o->rotZ & 0xff;
    a1 = (o->rotZ + 0x80) & 0xff;
    if (D_800A5435)
        k = D_8009B698->b7;
    else
        k = PLAYER.obj.animFrame;
    switch (k) {
    case 0: case 1: case 2: case 3:
        switch (*D_800A53BC_U16Ptr) {
        case 0x8b: break;
        case 0x94: idx += 2; break;
        case 0x97: idx += 4; break;
        case 0x9a: case 0x9b: case 0x9c: idx += 0x12; break;
        case 0xa3: idx += 0x14; break;
        case 0xa6: idx += 0x16; break;
        }
        break;
    case 4: case 5:
        switch (*D_800A53BC_U16Ptr) {
        case 0x8e: case 0x8f: case 0x90: idx += 6; break;
        case 0x95: idx += 8; break;
        case 0x98: idx += 10; break;
        case 0x9d: case 0x9e: case 0x9f: idx += 0x18; break;
        case 0xa4: idx += 0x1a; break;
        case 0xa7: idx += 0x1c; break;
        }
        break;
    case 6: case 7:
        switch (*D_800A53BC_U16Ptr) {
        case 0x91: case 0x92: case 0x93: idx += 0xc; break;
        case 0x96: idx += 0xe; break;
        case 0x99: idx += 0x10; break;
        case 0xa0: case 0xa1: case 0xa2: idx += 0x1e; break;
        case 0xa5: idx += 0x20; break;
        case 0xa8: idx += 0x22; break;
        }
        break;
    }
    if (D_8009B6A0->mode) {
        if (D_8009B6A0->shadowLen > 0)
            SHADOW(D_8009B6A0->shadow);
        if (D_8009B6A0->shadowLen2 > 0)
            SHADOW(D_8009B6A0->shadow2);
        p = (POLY_FT4 *)D_1F800164;
        p->code = 0x2d;
        SetSemiTrans(p, 0);
        p->tpage = D_8009B6A0->tpage;
        p->clut = D_8009B6A0->clut2;
        setUV4(p, D_8009B6A0->frame * 32 - 0x80, 0x10, D_8009B6A0->frame * 32 - 0x61, 0x10, D_8009B6A0->frame * 32 - 0x80, 0x1f, D_8009B6A0->frame * 32 - 0x61, 0x1f);
        s.x = D_8009B6A0->x;
        s.y = D_8009B6A0->y;
        if (D_800A5460 && *D_800A53BC_U16Ptr >= 0xa9) {
            c = fixedMulCos2((D_800A5424_S32 + 0x40) & 0xff, 0x18);
            sn = fixedMulSin2((D_800A5424_S32 + 0x40) & 0xff, 0x18);
        } else {
            s16 t0;
            s16 kk;
            s16 an;
            t0 = (s8)tbl[idx];
            k = (s8)tbl[idx + 1];
            if (o->animFrame & 1) {
                if (D_800A5448 <= 0) {
                    kk = k;
                    an = D_800A5424_S32 + 0x180;
                    an -= t0;
                    c = fixedMulCos2(an & 0xff, kk);
                    sn = fixedMulSin2(an & 0xff, kk);
                } else {
                    kk = k;
                    an = D_800A5424_S32 + 0x180;
                    an -= t0;
                    c = fixedMulCos2(an & 0xff, kk);
                    sn = fixedMulSin2(an & 0xff, kk);
                }
            } else {
                kk = k;
                an = t0 + D_800A5424_S32;
                c = fixedMulCos2(an & 0xff, kk);
                sn = fixedMulSin2(an & 0xff, kk);
            }
        }
        t.x = D_8009B698->w18 + c;
        t.y = D_8009B698->w1a + sn;
        r = angleBetweenPoints(t, s);
        {
            s32 b1 = (r + 0x140) & 0xff;
            s32 b2;
            setXY0(p, t.x + fixedMulCos(b1, 8), t.y + fixedMulSin(b1, 8));
            b2 = (r + 0xc0) & 0xff;
            p->x2 = t.x + fixedMulCos(b2, 8);
            p->y2 = t.y + fixedMulSin(b2, 8);
            p->x1 = s.x + fixedMulCos(b1, 8);
            p->y1 = s.y + fixedMulSin(b1, 8);
            p->x3 = s.x + fixedMulCos(b2, 8);
            p->y3 = s.y + fixedMulSin(b2, 8);
        }
        if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->priority - 3, 0x9000000) == 0)
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
    }
    p = (POLY_FT4 *)D_1F800164;
    p->code = 0x2d;
    SetSemiTrans(p, o->drawFlags >> 7);
    {
    u16 cl;
    p->tpage = D_8009B6A0->tpage;
    cl = D_8009B6A0->clut;
    k = (D_1F8001F8 & 3) * D_8007EB7C;
    setUV4(p, k - 0x80, 0, p->u0 + (u8)D_8007EB7C - 1, p->v0, p->u0, p->v0 + (u8)D_8007EB7E - 1, p->u1, p->v2);
    *(u16 *)((char *)p + 14) = cl;
    }
    if (D_800A5460 && *D_800A53BC_U16Ptr >= 0xa9) {
        s32 t, g = D_800A5424_S32;
        if (o->animFrame & 1)
            t = g + 0xc0;
        else
            t = g + 0x40;
        a0 = t & 0xff;
        a1 = (a0 + 0x80) & 0xff;
    }
    if (o->animFrame & 1)
        quadA_46EC0(p, x, y, a0, a1);
    else
        quadB_46EC0(p, x, y, a0, a1);
    if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->priority - 4, 0x9000000) == 0)
        D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
}
#undef COS
#undef SIN
#undef SHADOW

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80047FC8);
#define A0_47FC8 (ang & 0xff)
#define A1_47FC8 ((ang + 0x80) & 0xff)
#define SN_47FC8(i) COS_TABLE[i]
#define CS_47FC8(i) NEG_SIN_TABLE[i]

void func_80047FC8(GameObject *obj)
{
    POLY_FT4 *poly;
    s16 *e;
    s32 n;
    SprFrag *f;
    s32 xy;
    s16 x, y;
    s32 ang;
    s16 A, B, C, D;
    s16 u, w;

    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    xy = LZ_FILE_CTRL_Long;
    e = (s16 *)obj->spriteBank;
    e += *(u16 *)obj->anim * 2;
    f = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + e[1]);
    n = e[0];
    x = xy;
    y = (u32)xy >> 16;
    ang = obj->rotZ;
    do {
        A = f->dx;
        B = f->dy;
        poly = (POLY_FT4 *)D_1F800164;
        C = f->w;
        D = f->h;
        if ((obj->animFrame & 1) == 0) {
            u = A;
            w = B;
            setXY4(poly, x + ((-u * SN_47FC8(A1_47FC8)) >> 12) + ((-w * SN_47FC8((A1_47FC8 + 0xc0) & 0xff)) >> 12), y + ((-u * CS_47FC8(A1_47FC8)) >> 12) + ((-w * CS_47FC8((A1_47FC8 + 0xc0) & 0xff)) >> 12), x + (((u + C) * SN_47FC8(A0_47FC8)) >> 12) + ((-w * SN_47FC8((A0_47FC8 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_47FC8(A0_47FC8)) >> 12) + ((-w * CS_47FC8((A0_47FC8 + 0x40) & 0xff)) >> 12), x + ((-u * SN_47FC8(A1_47FC8)) >> 12) + (((w + D) * SN_47FC8((A1_47FC8 + 0x40) & 0xff)) >> 12), y + ((-u * CS_47FC8(A1_47FC8)) >> 12) + (((w + D) * CS_47FC8((A1_47FC8 + 0x40) & 0xff)) >> 12), x + (((u + C) * SN_47FC8(A0_47FC8)) >> 12) + (((w + D) * SN_47FC8((A0_47FC8 + 0xc0) & 0xff)) >> 12), y + (((u + C) * CS_47FC8(A0_47FC8)) >> 12) + (((w + D) * CS_47FC8((A0_47FC8 + 0xc0) & 0xff)) >> 12));
        } else {
            u = -(A + C);
            w = B;
            poly->x1 = x + ((-u * SN_47FC8(A1_47FC8)) >> 12) + ((-w * SN_47FC8((A1_47FC8 + 0xc0) & 0xff)) >> 12);
            poly->y1 = y + ((-u * CS_47FC8(A1_47FC8)) >> 12) + ((-w * CS_47FC8((A1_47FC8 + 0xc0) & 0xff)) >> 12);
            setXY0(poly, x + (((u + C) * SN_47FC8(A0_47FC8)) >> 12) + ((-w * SN_47FC8((A0_47FC8 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_47FC8(A0_47FC8)) >> 12) + ((-w * CS_47FC8((A0_47FC8 + 0x40) & 0xff)) >> 12));
            poly->x3 = x + ((-u * SN_47FC8(A1_47FC8)) >> 12) + (((w + D) * SN_47FC8((A1_47FC8 + 0x40) & 0xff)) >> 12);
            poly->y3 = y + ((-u * CS_47FC8(A1_47FC8)) >> 12) + (((w + D) * CS_47FC8((A1_47FC8 + 0x40) & 0xff)) >> 12);
            poly->x2 = x + (((u + C) * SN_47FC8(A0_47FC8)) >> 12) + (((w + D) * SN_47FC8((A0_47FC8 + 0xc0) & 0xff)) >> 12);
            poly->y2 = y + (((u + C) * CS_47FC8(A0_47FC8)) >> 12) + (((w + D) * CS_47FC8((A0_47FC8 + 0xc0) & 0xff)) >> 12);
        }
        poly->code = 0x2c;
        if (obj->id == 0)
            SetSemiTrans(poly, 1);
        else
            SetSemiTrans(poly, 0);
        poly->tpage = obj->tpage;
        poly->clut = obj->clut;
        if (obj->id == 0) {
            if (obj->drawFlags & 0x40) {
                setRGB0(poly, 0x20, 0x20, 0x20);
            } else {
                setRGB0(poly, 0x40, 0x40, 0x40);
            }
        } else {
            setRGB0(poly, 0x80, 0x80, 0x80);
        }
        *(u16 *)&poly->u0 = *(u16 *)f + 0x80;
        *(u16 *)&poly->u1 = f->uv1 + 0x80;
        *(u16 *)&poly->u2 = f->uv2 + 0x80;
        *(u16 *)&poly->u3 = f->uv3 + 0x80;
        if (!otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, D_1F800074, (s8)obj->priority, 0x9000000))
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        f++;
    } while (--n);
}
#undef A0_47FC8
#undef A1_47FC8
#undef SN_47FC8
#undef CS_47FC8

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_800487A4);
static __inline__ s32 quadOnScreen(POLY_FT4 *poly)
{
    if ((u16)poly->y0 < NTSC_PAL(0xE0, 0x100) || (u16)poly->y1 < NTSC_PAL(0xE0, 0x100) || (u16)poly->y2 < NTSC_PAL(0xE0, 0x100) || (u16)poly->y3 < NTSC_PAL(0xE0, 0x100)) {
        if ((u16)poly->x0 < 0x140 || (u16)poly->x1 < 0x140 || (u16)poly->x2 < 0x140 || (u16)poly->x3 < 0x140)
            return 1;
    }
    return 0;
}

void func_800487A4(GameObject *obj)
{
    POLY_FT4 *poly;
    s16 *e;
    SprFrag *f;
    s32 n;

    if (obj->anim == NULL) return;
    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    e = (s16 *)(obj->spriteBank + *(s16 *)obj->anim * 4);
    n = e[0];
    f = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + e[1]);
    do {
        poly = (POLY_FT4 *)D_1F800164;
        if (obj->animFrame & 1) {
            setXY0(poly, f->dx + LZ_FILE_CTRL_Long, f->dy + (LZ_FILE_CTRL_Long >> 16));
            poly->x1 = poly->x0 + f->w;
            poly->x2 = poly->x0;
            poly->y1 = poly->y0;
            poly->y2 = poly->y0 + f->h;
            poly->x3 = poly->x1;
            poly->y3 = poly->y2;
        } else {
            setXY0(poly, LZ_FILE_CTRL_Long - f->dx, f->dy + (LZ_FILE_CTRL_Long >> 16));
            poly->x1 = poly->x0 - f->w;
            poly->x2 = poly->x0;
            poly->y1 = poly->y0;
            poly->y2 = poly->y0 + f->h;
            poly->x3 = poly->x1;
            poly->y3 = poly->y2;
        }
        if (quadOnScreen(poly)) {
            poly->code = 0x2d;
            SetSemiTrans(poly, obj->drawFlags >> 7);
            *(u32 *)&poly->u0 = *(u32 *)f;
            *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
            *(u16 *)&poly->u2 = f->uv2;
            *(u16 *)&poly->u3 = f->uv3;
            poly->tpage += obj->tpage;
            if (obj->drawFlags & 1)
                poly->clut = obj->clut;
            if (obj->otMode != OT_MODE_DEPTH) {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, 0, (s8)obj->priority, 0x9000000)) goto next;
            } else {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, D_1F800074, (s8)obj->priority, 0x9000000)) goto next;
            }
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
    next:
        f++;
        n--;
    } while (n != 0);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80048BF0);
void func_80048BF0(GameObject *obj)
{
    POLY_FT4 *poly;
    s16 *e;
    SprFrag *f;
    s32 n;
    u32 k;
    s32 d;

    if (obj->anim == NULL) return;
    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    e = (s16 *)(obj->spriteBank + *(s16 *)obj->anim * 4);
    n = e[0];
    f = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + e[1]);
    if (obj->drawType == DRAW_SPRITE_SCALED) {
        switch (SPAD->unk1C8 & 1) {
        case 0:
            d = VIEW_CAMERA.pos[2].p.whole - obj->z.p.whole;
            k = obj->scale * (d * 7 + 0x1000) >> 12;
            break;
        case 1:
            d = obj->x.p.whole - VIEW_CAMERA.pos[0].p.whole;
            k = obj->scale * (d * 7 + 0x1000) >> 12;
            break;
        }
    } else {
        k = SPAD->loadSlots[4];
    }
    do {
        poly = (POLY_FT4 *)D_1F800164;
        if (obj->animFrame & 1) {
            setXY4(poly, LZ_FILE_CTRL_Long + ((f->dx * k - 0x1000) >> 12), (LZ_FILE_CTRL_Long >> 16) + ((f->dy * k - 0x1000) >> 12), poly->x0 + ((f->w * k + 0x1000) >> 12), poly->y0, poly->x0, poly->y0 + ((f->h * k + 0x1000) >> 12), poly->x1, poly->y2);
        } else {
            setXY4(poly, LZ_FILE_CTRL_Long - ((f->dx * k - 0x1000) >> 12), (LZ_FILE_CTRL_Long >> 16) + ((f->dy * k - 0x1000) >> 12), poly->x0 - ((f->w * k + 0x1000) >> 12), poly->y0, poly->x0, poly->y0 + ((f->h * k + 0x1000) >> 12), poly->x1, poly->y2);
        }
        if (quadOnScreen(poly)) {
            poly->code = 0x2d;
            SetSemiTrans(poly, obj->drawFlags >> 7);
            *(u32 *)&poly->u0 = *(u32 *)f;
            *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
            *(u16 *)&poly->u2 = f->uv2;
            *(u16 *)&poly->u3 = f->uv3;
            poly->tpage += obj->tpage;
            if (obj->drawFlags & 1)
                poly->clut = obj->clut;
            if (obj->otMode != OT_MODE_DEPTH) {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, 0, (s8)obj->priority, 0x9000000)) goto next;
            } else {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, D_1F800074, (s8)obj->priority, 0x9000000)) goto next;
            }
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
    next:
        f++;
        n--;
    } while (n != 0);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80049134);
#define A0_49134 (ang & 0xff)
#define SN_49134(i) COS_TABLE[i]
#define CS_49134(i) NEG_SIN_TABLE[i]
#define A1_49134 ((ang + 0x80) & 0xff)

void func_80049134(GameObject *obj)
{
    POLY_FT4 *poly;
    s16 *e;
    SprFrag *f;
    s32 xy;
    s16 x, y;
    s32 d;
    s32 ang;
    s16 A, B, C, D;
    s16 u, w;

    if (obj->anim == NULL) return;
    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    xy = LZ_FILE_CTRL_Long;
    x = xy;
    y = (u32)xy >> 16;
    d = obj->spriteBank;
    d += *(u16 *)obj->anim * 4;
    e = (s16 *)d;
    D_1F800078 = e[0];
    f = (SprFrag *)(obj->spriteBank + e[1]);
    ang = obj->rotZ;
    do {
        A = f->dx;
        B = f->dy;
        poly = (POLY_FT4 *)D_1F800164;
        C = f->w;
        D = f->h;
        if (obj->animFrame & 1) {
            u = A;
            w = B;
            setXY4(poly, x + ((-u * SN_49134(A1_49134)) >> 12) + ((-w * SN_49134((A1_49134 + 0xc0) & 0xff)) >> 12), y + ((-u * CS_49134(A1_49134)) >> 12) + ((-w * CS_49134((A1_49134 + 0xc0) & 0xff)) >> 12), x + (((u + C) * SN_49134(A0_49134)) >> 12) + ((-w * SN_49134((A0_49134 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_49134(A0_49134)) >> 12) + ((-w * CS_49134((A0_49134 + 0x40) & 0xff)) >> 12), x + ((-u * SN_49134(A1_49134)) >> 12) + (((w + D) * SN_49134((A1_49134 + 0x40) & 0xff)) >> 12), y + ((-u * CS_49134(A1_49134)) >> 12) + (((w + D) * CS_49134((A1_49134 + 0x40) & 0xff)) >> 12), x + (((u + C) * SN_49134(A0_49134)) >> 12) + (((w + D) * SN_49134((A0_49134 + 0xc0) & 0xff)) >> 12), y + (((u + C) * CS_49134(A0_49134)) >> 12) + (((w + D) * CS_49134((A0_49134 + 0xc0) & 0xff)) >> 12));
        } else {
            u = -(A + C);
            w = B;
            poly->x1 = x + ((-u * SN_49134(A1_49134)) >> 12) + ((-w * SN_49134((A1_49134 + 0xc0) & 0xff)) >> 12);
            poly->y1 = y + ((-u * CS_49134(A1_49134)) >> 12) + ((-w * CS_49134((A1_49134 + 0xc0) & 0xff)) >> 12);
            setXY0(poly, x + (((u + C) * SN_49134(A0_49134)) >> 12) + ((-w * SN_49134((A0_49134 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_49134(A0_49134)) >> 12) + ((-w * CS_49134((A0_49134 + 0x40) & 0xff)) >> 12));
            poly->x3 = x + ((-u * SN_49134(A1_49134)) >> 12) + (((w + D) * SN_49134((A1_49134 + 0x40) & 0xff)) >> 12);
            poly->y3 = y + ((-u * CS_49134(A1_49134)) >> 12) + (((w + D) * CS_49134((A1_49134 + 0x40) & 0xff)) >> 12);
            poly->x2 = x + (((u + C) * SN_49134(A0_49134)) >> 12) + (((w + D) * SN_49134((A0_49134 + 0xc0) & 0xff)) >> 12);
            poly->y2 = y + (((u + C) * CS_49134(A0_49134)) >> 12) + (((w + D) * CS_49134((A0_49134 + 0xc0) & 0xff)) >> 12);
        }
        if (quadOnScreen(poly)) {
            poly->code = 0x2d;
            SetSemiTrans(poly, obj->drawFlags >> 7);
            *(u32 *)&poly->u0 = *(u32 *)f;
            *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
            *(u16 *)&poly->u2 = f->uv2;
            *(u16 *)&poly->u3 = f->uv3;
            poly->tpage += obj->tpage;
            if (obj->drawFlags & 1)
                poly->clut = obj->clut;
            if (obj->otMode != OT_MODE_DEPTH) {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, 0, (s8)obj->priority, 0x9000000)) goto next;
            } else {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, D_1F800074, (s8)obj->priority, 0x9000000)) goto next;
            }
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
    next:
        f++;
        D_1F800078--;
    } while (D_1F800078 != 0);
}
#undef A0_49134
#undef A1_49134
#undef SN_49134
#undef CS_49134

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_80049994);
#define A0_49994 (ang & 0xff)
#define SN_49994(i) COS_TABLE[i]
#define CS_49994(i) NEG_SIN_TABLE[i]
#define A1_49994 ((ang + 0x80) & 0xff)

void func_80049994(GameObject *obj)
{
    POLY_FT4 *poly;
    s16 *e;
    SprFrag *f;
    s32 xy;
    u32 s;
    s16 x, y;
    s32 d;
    s32 ang;
    s16 A, B, C, D;
    s16 u, w;

    if (obj->anim == NULL) return;
    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    xy = LZ_FILE_CTRL_Long;
    x = xy;
    y = (u32)xy >> 16;
    d = obj->spriteBank;
    d += *(u16 *)obj->anim * 4;
    e = (s16 *)d;
    D_1F800078 = e[0];
    f = (SprFrag *)(obj->spriteBank + e[1]);
    if (obj->drawType & 1) {
        switch (SPAD->unk1C8 & 1) {
        case 0:
            d = VIEW_CAMERA.pos[2].p.whole - obj->z.p.whole;
            s = obj->scale * (d * 7 + 0x1000) >> 12;
            break;
        case 1:
            d = obj->x.p.whole - VIEW_CAMERA.pos[0].p.whole;
            s = obj->scale * (d * 7 + 0x1000) >> 12;
            break;
        }
    } else {
        s = SPAD->loadSlots[4];
    }
    ang = obj->rotZ;
    do {
        A = (f->dx * s - 0x1800) >> 12;
        B = (f->dy * s - 0x1800) >> 12;
        C = (f->w * s + 0x1800) >> 12;
        D = (f->h * s + 0x1800) >> 12;
        poly = (POLY_FT4 *)D_1F800164;
        if (obj->animFrame & 1) {
            u = A;
            w = B;
            setXY4(poly, x + ((-u * SN_49994(A1_49994)) >> 12) + ((-w * SN_49994((A1_49994 + 0xc0) & 0xff)) >> 12), y + ((-u * CS_49994(A1_49994)) >> 12) + ((-w * CS_49994((A1_49994 + 0xc0) & 0xff)) >> 12), x + (((u + C) * SN_49994(A0_49994)) >> 12) + ((-w * SN_49994((A0_49994 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_49994(A0_49994)) >> 12) + ((-w * CS_49994((A0_49994 + 0x40) & 0xff)) >> 12), x + ((-u * SN_49994(A1_49994)) >> 12) + (((w + D) * SN_49994((A1_49994 + 0x40) & 0xff)) >> 12), y + ((-u * CS_49994(A1_49994)) >> 12) + (((w + D) * CS_49994((A1_49994 + 0x40) & 0xff)) >> 12), x + (((u + C) * SN_49994(A0_49994)) >> 12) + (((w + D) * SN_49994((A0_49994 + 0xc0) & 0xff)) >> 12), y + (((u + C) * CS_49994(A0_49994)) >> 12) + (((w + D) * CS_49994((A0_49994 + 0xc0) & 0xff)) >> 12));
        } else {
            u = -(A + C);
            w = B;
            poly->x1 = x + ((-u * SN_49994(A1_49994)) >> 12) + ((-w * SN_49994((A1_49994 + 0xc0) & 0xff)) >> 12);
            poly->y1 = y + ((-u * CS_49994(A1_49994)) >> 12) + ((-w * CS_49994((A1_49994 + 0xc0) & 0xff)) >> 12);
            setXY0(poly, x + (((u + C) * SN_49994(A0_49994)) >> 12) + ((-w * SN_49994((A0_49994 + 0x40) & 0xff)) >> 12), y + (((u + C) * CS_49994(A0_49994)) >> 12) + ((-w * CS_49994((A0_49994 + 0x40) & 0xff)) >> 12));
            poly->x3 = x + ((-u * SN_49994(A1_49994)) >> 12) + (((w + D) * SN_49994((A1_49994 + 0x40) & 0xff)) >> 12);
            poly->y3 = y + ((-u * CS_49994(A1_49994)) >> 12) + (((w + D) * CS_49994((A1_49994 + 0x40) & 0xff)) >> 12);
            poly->x2 = x + (((u + C) * SN_49994(A0_49994)) >> 12) + (((w + D) * SN_49994((A0_49994 + 0xc0) & 0xff)) >> 12);
            poly->y2 = y + (((u + C) * CS_49994(A0_49994)) >> 12) + (((w + D) * CS_49994((A0_49994 + 0xc0) & 0xff)) >> 12);
        }
        if (quadOnScreen(poly)) {
            poly->code = 0x2d;
            SetSemiTrans(poly, obj->drawFlags >> 7);
            *(u32 *)&poly->u0 = *(u32 *)f;
            *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
            *(u16 *)&poly->u2 = f->uv2;
            *(u16 *)&poly->u3 = f->uv3;
            poly->tpage += obj->tpage;
            if (obj->drawFlags & 1)
                poly->clut = obj->clut;
            if (obj->otMode != OT_MODE_DEPTH) {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, 0, (s8)obj->priority, 0x9000000)) goto next;
            } else {
                if (otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, D_1F800074, (s8)obj->priority, 0x9000000)) goto next;
            }
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
    next:
        f++;
        D_1F800078--;
    } while (D_1F800078 != 0);
}
#undef A0_49994
#undef A1_49994
#undef SN_49994
#undef CS_49994

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004A300);
void func_8004A300(GameObject *obj)
{
    SPRT *sprt;
    s16 *e;
    SprFrag *f;
    s32 n;
    s32 tp;

    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    e = (s16 *)(*(volatile s32 *)&obj->spriteBank + *(u16 *)obj->anim * 4);
    sprt = (SPRT *)D_1F800164_Volatile;
    n = e[0];
    f = (SprFrag *)(obj->spriteBank + e[1]);
    tp = f->tpage;
    SetDrawMode((DR_MODE *)sprt, 0, 0, 0, 0);
    AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
    D_1F800164 += sizeof(DR_MODE);
    do {
        sprt = (SPRT *)D_1F800164;
        setWH(sprt, f->w, f->h);
        setXY0(sprt, f->dx + LZ_FILE_CTRL_Long, f->dy + (LZ_FILE_CTRL_Long >> 16));
        if (((u16)sprt->y0 < NTSC_PAL(0xF1, 0x101) || (u16)(sprt->y0 + sprt->h) < NTSC_PAL(0xF1, 0x101)) &&
            ((u16)sprt->x0 < 0x141 || (u16)(sprt->x0 + sprt->w) < 0x141)) {
            SetSprt(sprt);
            SetSemiTrans(sprt, obj->drawFlags >> 7);
            sprt->code |= 1;
            *(s32 *)&sprt->u0 = *(s32 *)f;
            if (obj->drawFlags & 1) {
                sprt->clut = obj->clut;
            }
            AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
            D_1F800164 += sizeof(SPRT);
        }
        f++;
        n--;
    } while (n != 0);
    sprt = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)sprt, 0, 0, obj->tpage + (s16)tp, 0);
    AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
    D_1F800164 += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004A6A0);
void func_8004A6A0(GameObject *obj)
{
    SPRT *sprt;
    s16 *e;
    SprFrag *f;
    s32 n;
    s32 tp;

    D_1F800060.vx = obj->x.p.whole;
    D_1F800062 = obj->y.p.whole;
    if ((*(s32 *)&GAME) == 0x10005 && (*(C4C_46EC0 **)&D_1F8001D4)->w4c != 3)
        D_1F800064 = obj->z.p.whole >> 2;
    else
        D_1F800064 = obj->z.p.whole;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0_CharArr);
    if (proj_46EC0()) return;
    e = (s16 *)obj->spriteBank;
    e += *(u16 *)obj->anim * 2;
    sprt = (SPRT *)D_1F800164;
    n = e[0];
    f = (SprFrag *)(obj->spriteBank + e[1]);
    tp = f->tpage;
    SetDrawMode((DR_MODE *)sprt, 0, 0, 0, 0);
    AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
    D_1F800164 += sizeof(DR_MODE);
    do {
        sprt = (SPRT *)D_1F800164;
        setWH(sprt, f->w, f->h);
        setXY0(sprt, f->dx + LZ_FILE_CTRL_Long, f->dy + (LZ_FILE_CTRL_Long >> 16));
        if (((u16)sprt->y0 < NTSC_PAL(0xF1, 0x101) || (u16)(sprt->y0 + sprt->h) < NTSC_PAL(0xF1, 0x101)) &&
            ((u16)sprt->x0 < 0x141 || (u16)(sprt->x0 + sprt->w) < 0x141)) {
            SetSprt(sprt);
            SetSemiTrans(sprt, obj->drawFlags >> 7);
            sprt->code |= 1;
            *(s32 *)&sprt->u0 = *(s32 *)f;
            if (obj->drawFlags & 1) {
                sprt->clut = obj->clut;
            }
            SetShadeTex(sprt, 0);
            setRGB0(sprt, obj->objectIndex, obj->objectIndex, obj->objectIndex);
            AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
            D_1F800164 += sizeof(SPRT);
        }
        f++;
        n--;
    } while (n != 0);
    sprt = (SPRT *)D_1F800164;
    SetDrawMode((DR_MODE *)sprt, 0, 0, obj->tpage + (s16)tp, 0);
    AddPrim((char *)D_1F8001E0 + D_1F800074 * 4 + ((s8)obj->priority * 4 + 0x10), sprt);
    D_1F800164 += sizeof(DR_MODE);
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004AA70);
void func_8004AA70(GameObject *obj)
{
    POLY_FT4 *poly;
    SprFrag *f;
    u8 *v0, *v1, *v2, *v3;

    getBaseMatrix(&SCRATCHPAD.workMatrix);
    ((s16 *)&D_1F800060)[0] = obj->x.p.whole;
    ((s16 *)&D_1F800060)[1] = obj->y.p.whole;
    ((s16 *)&D_1F800060)[2] = obj->z.p.whole;
    SetRotMatrix(SCRATCH_VIEW_MATRIX);
    ApplyRotMatrix(&D_1F800060, (VECTOR *)&SCRATCHPAD.workMatrix.t[0]);
    SCRATCHPAD.workMatrix.t[0] += SCRATCH_VIEW_MATRIX->t[0];
    SCRATCHPAD.workMatrix.t[1] += SCRATCH_VIEW_MATRIX->t[1];
    SCRATCHPAD.workMatrix.t[2] += SCRATCH_VIEW_MATRIX->t[2];
    SetTransMatrix(&SCRATCHPAD.workMatrix);
    v0 = (u8 *)obj + 0xb4;
    v1 = (u8 *)obj + 0xbc;
    v2 = (u8 *)obj + 0xc4;
    v3 = (u8 *)obj + 0xcc;
    poly = (POLY_FT4 *)D_1F800164;
    gte_ldv3(v0, v1, v2);
    gte_rtpt();
    gte_stsxy3_ft4(poly);
    gte_ldv0(v3);
    gte_rtps();
    gte_avsz4();
    gte_stotz(&LZ_FILE_CTRL_Long);
    gte_stsxy(&poly->x3);
    if (quadOnScreen(poly)) {
        f = (SprFrag *)(*(volatile s32 *)&obj->spriteBank + ((s16 *)(obj->spriteBank + (*(u16 *)obj->anim << 2)))[1]);
        poly->code = 0x2d;
        SetSemiTrans(poly, obj->drawFlags >> 7);
        *(u32 *)&poly->u0 = *(u32 *)f;
        *(u32 *)&poly->u1 = *(u32 *)&f->uv1;
        *(u16 *)&poly->u2 = f->uv2;
        *(u16 *)&poly->u3 = f->uv3;
        poly->tpage += obj->tpage;
        if (obj->drawFlags & 1)
            poly->clut = obj->clut;
        {
            s32 c = LZ_FILE_CTRL_Long;
            unsigned long e;

            do {
            } while (0);
            e = 0x9000000;
            if (!otadd_46EC0((unsigned long *)poly, D_1F8001E0 + 0x10, c, (s8)obj->priority, e))
                D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004AD8C);
extern GameObject **D_1F800260;

void func_8004AD8C(void)
{
    s32 n;
    GameObject **p;
    GameObject *obj;
    if (D_1F8001C6 != 0) {
        n = D_1F800250_S16;
        p = D_1F800260;
        while (n != 0) {
            obj = *p++;
            n--;
            if (obj->drawType == DRAW_SPRT) {
                switch ((*(u8 *)&D_800A539A_U8Arr)) {
                case 0: func_8004A6A0(obj); break;
                case 1: func_800E9EB8(obj); break;
                case 2: func_800EB490(obj); break;
                case 3: func_800EAAC8(obj); break;
                }
            } else {
                func_80045EFC(obj);
            }
        }
    } else {
        D_1F800250_S16 = D_1F800246;
        D_1F800260 = D_1F80021C;
        if (D_1F800246 == 0)
            return;
        do {
            obj = *D_1F80021C++;
            D_1F800246--;
            if (obj->visible) {
                if (obj->drawType == DRAW_SPRT) {
                    switch ((*(u8 *)&D_800A539A_U8Arr)) {
                    case 0: func_8004A6A0(obj); break;
                    case 1: func_800E9EB8(obj); break;
                    case 2: func_800EB490(obj); break;
                    case 3: func_800EAAC8(obj); break;
                    }
                } else {
                    func_80045EFC(obj);
                }
            }
        } while ((*(s16 *)&D_1F800246) != 0);
    }
}

// INCLUDE_ASM("nonmatchings/main/render/actorrender2", func_8004AFAC);

void func_8004BAF0(GameObject *o);
void func_800EC0E8(GameObject *o);

void func_8004AFAC(void)
{
    s32 n;
    GameObject **p;
    GameObject *obj;

    if (D_1F8001C6 != 0) {
        n = D_1F800252;
        p = D_1F800264;
        while (n != 0) {
            obj = *p++;
            n--;
            switch (func_80045D0C(obj)) {
            case 0: func_800487A4(obj); break;
            case 2: func_80049134(obj); break;
            case 4: func_8004B450(obj); break;
            case 5: func_80123148(obj); break;
            case 6: func_8004AA70(obj); break;
            case 7: func_8004BAF0(obj); break;
            case 8: func_80047FC8(obj); break;
            case 1: case 9: func_80048BF0(obj); break;
            case 10: drawMessageBox(obj); break;
            case 3: case 11: func_80049994(obj); break;
            case 12: drawMessageBoxFrame(obj); break;
            case 13:
                switch ((*(u8 *)&D_800A539A_U8Arr)) {
                case 0: func_8004A6A0(obj); break;
                case 1: func_800E9EB8(obj); break;
                case 2: func_800EB490(obj); break;
                case 3: func_800EAAC8(obj); break;
                }
            case 14: func_8004CC84(obj); break;
            case 16: func_8004A300(obj); break;
            case 17: func_80123AC4(obj); break;
            case 18: func_8011B350(obj); break;
            case 19: func_800EC0E8(obj); break;
            case 20: func_80117D3C(obj); break;
            case 21: func_8011812C(obj); break;
            case 22: func_8004D2A8(obj); break;
            }
        }
    } else {
        D_1F800252 = D_1F80024A;
        D_1F800264 = D_1F800220;
        while (D_1F80024A != 0) {
            obj = *D_1F800220++;
            D_1F80024A--;
            if (obj->visible) {
                switch (func_80045D0C(obj)) {
                case 0: func_800487A4(obj); break;
                case 2: func_80049134(obj); break;
                case 4: func_8004B450(obj); break;
                case 5: func_80123148(obj); break;
                case 6: func_8004AA70(obj); break;
                case 7: func_8004BAF0(obj); break;
                case 8: func_80047FC8(obj); break;
                case 1: case 9: func_80048BF0(obj); break;
                case 10: drawMessageBox(obj); break;
                case 3: case 11: func_80049994(obj); break;
                case 12: drawMessageBoxFrame(obj); break;
                case 13:
                    switch ((*(u8 *)&D_800A539A_U8Arr)) {
                    case 0: func_8004A6A0(obj); break;
                    case 1: func_800E9EB8(obj); break;
                    case 2: func_800EB490(obj); break;
                    case 3: func_800EAAC8(obj); break;
                    }
                    break;
                case 14: func_8004CC84(obj); break;
                case 16: func_8004A300(obj); break;
                case 17: func_80123AC4(obj); break;
                case 18: func_8011B350(obj); break;
                case 19: func_800EC0E8(obj); break;
                case 20: func_80117D3C(obj); break;
                case 21: func_8011812C(obj); break;
                case 22: func_8004D2A8(obj); break;
                }
            }
        }
    }
}

const s32 D_800146DC = 0;
