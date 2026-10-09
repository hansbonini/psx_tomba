#include "common.h"
#include "game.h"
#include "game/gte.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80045EFC);
s32 func_80045D0C(GameObject *o);
void func_8011C234(GameObject *o);
void func_8011C500(GameObject *o);
void func_8011C824(GameObject *o);
void func_8011CF38(GameObject *o);
void func_800487A4(GameObject *o);
void func_80048BF0(GameObject *o);
void func_80049994(GameObject *o);
void func_8004AA70(GameObject *o);
void func_800E9EB8(GameObject *o);
void func_800EB490(GameObject *o);
void func_800EAAC8(GameObject *o);
void func_80123314(GameObject *o);
void func_8011DF10(GameObject *o);
void func_8011E584(GameObject *o);
void func_8011AB74(GameObject *o);
void func_8011B350(GameObject *o);
void func_8004D1A0(GameObject *o);
void func_8004D448(GameObject *o);
void func_8004D5F0(GameObject *o);
void func_8004D7E0(GameObject *o);
void func_8004D91C(GameObject *o);
void func_8004DA28(GameObject *o);

void func_80045EFC(GameObject *o)
{
    extern void func_8004D2A8(GameObject *o);
    extern void func_8004A6A0(GameObject *o);
    extern void func_80049134(GameObject *o);
    extern u8 D_800A539A;
    if (o->visible == 0) return;
    if ((o->unkA & 0x10) && o->unkA0 == 0) return;
    if ((*(s32 *)&GAME) == 9 && D_8009BCCC != 0x20 && D_8009BCA2 == 1 &&
        o->z.p.whole < 0xb6d && (o->category & 0x7f) != 8) return;
    if ((*(u16 *)&GAME) == 10 && (D_8009BCCA == 0 || D_8009BCCA == 4) && D_8009BCCC != 0 &&
        (u16)(o->z.p.whole + 9) < 0x13 && (o->category & 0x7f) != 8) return;
    if ((*(s32 *)&GAME) == 6) {
        switch (o->unkA) {
        case 0: func_8011C234(o); break;
        case 1: func_8011C500(o); break;
        case 2: func_8011C824(o); break;
        case 3: func_8011CF38(o); break;
        case 0x10: goto c10;
        case 0x11: goto c11;
        case 0x12: goto c12;
        case 0x13: goto c13;
        case 0x14: goto c14;
        case 0x15: goto c15;
        case 0x16: goto c16;
        }
        return;
    }
    switch (func_80045D0C(o)) {
    case 0: func_800487A4(o); break;
    case 1: func_80048BF0(o); break;
    case 2: func_80049134(o); break;
    case 3: func_80049994(o); break;
    case 4: func_8004AA70(o); break;
    case 5:
        switch (D_800A539A) {
        case 1: func_800E9EB8(o); break;
        case 2: func_800EB490(o); break;
        case 3: func_800EAAC8(o); break;
        }
        break;
    case 6: func_80123314(o); break;
    case 7: func_8011DF10(o); break;
    case 8: func_8011E584(o); break;
    case 9: func_8011AB74(o); break;
    case 10: func_8011B350(o); break;
    case 13: func_8004A6A0(o); break;
    case 0x10: c10: func_8004D1A0(o); break;
    case 0x11: c11: func_8004D2A8(o); break;
    case 0x12: c12: func_8004D448(o); break;
    case 0x13: c13: func_8004D5F0(o); break;
    case 0x14: c14: func_8004D7E0(o); break;
    case 0x15: c15: func_8004D91C(o); break;
    case 0x16: c16: func_8004DA28(o); break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046264);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004637C);
extern u8 D_800A5399[];
extern u8 D_800A539A[];
void func_8004637C(void)
{
    u8 *p = &PLAYER.obj;
    if (D_800A5399[0] != 0) {
        switch (D_800A539A[0]) {
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046428);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046CDC);
typedef struct { char p0[1]; u8 vis; char p1[8]; u8 k; } O_46CDC;
extern void func_80049134(O_46CDC *);
extern void func_8004A6A0(O_46CDC *);

void func_80046CDC(void)
{
    extern void func_8004D2A8(O_46CDC *);
    extern void func_80046EC0(O_46CDC *);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80046EC0);

typedef struct {
    s16 x, y;
    u16 w4, w6, w8, w10;
    s8 b12;
    u8 b13;
    s16 w14;
    u16 q1[8];
    u16 q2[8];
    s16 w48, w50;
} SH_46EC0;

typedef struct { s16 x, y; } P_46EC0;
typedef struct { char pad[7]; s8 b7; char pad8[0x18 - 8]; u16 w18, w1a; } PL_46EC0;
typedef struct { char pad[0x4c]; u16 w4c; } C4C_46EC0;
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");
extern char D_1F8000C0_CharArr[] asm("D_1F8000C0");
extern SH_46EC0 *D_8009B6A0;
extern PL_46EC0 *D_8009B698;
extern u8 D_800A5435;
extern u16 *D_800A53BC;
extern s32 D_800A5424;
extern void func_8004FE24(GameObject *, s32, s32);
extern s32 fixedMulCos(s32, s16);
extern s32 fixedMulSin2(s32, s16);
extern s32 fixedMulSin(s32, s16);
extern s32 angleBetweenPoints(P_46EC0, P_46EC0);


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

#define COS(i) D_8007DB88[i]
#define SIN(i) D_8007D988[i]

#define SHADOW(q) { \
    p = (POLY_FT4 *)D_1F800164; \
    func_8004FE24(o, D_8009B6A0->x, D_8009B6A0->y); \
    p->code = 0x2c; \
    SetSemiTrans(p, 1); \
    p->tpage = D_8009B6A0->w8; \
    p->clut = D_8009B6A0->w10; \
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
    if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->unkF - 5, 0x9000000) == 0) \
        D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1); \
}

static __inline__ void quadA_46EC0(POLY_FT4 *p, s16 x, s16 y, s16 a0, s16 a1)
{
s32 m, n2, m2, n;
    D_8007EB80 = -(D_8007EB80 + D_8007EB7C);
    m = -D_8007EB80;
    n = -D_8007EB82;
    p->x1 = x + ((m * COS(a1)) >> 12) + ((n * COS((a1 + 0xc0) & 0xff)) >> 12);
    p->y1 = y + ((m * SIN(a1)) >> 12) + ((n * SIN((a1 + 0xc0) & 0xff)) >> 12);
    m2 = D_8007EB80 + D_8007EB7C;
    p->x0 = x + ((m2 * COS(a0)) >> 12) + ((n * COS((a0 + 0x40) & 0xff)) >> 12);
    p->y0 = y + ((m2 * SIN(a0)) >> 12) + ((n * SIN((a0 + 0x40) & 0xff)) >> 12);
    n2 = D_8007EB82 + D_8007EB7E;
    p->x3 = x + ((m * COS(a1)) >> 12) + ((n2 * COS((a1 + 0x40) & 0xff)) >> 12);
    p->y3 = y + ((m * SIN(a1)) >> 12) + ((n2 * SIN((a1 + 0x40) & 0xff)) >> 12);
    p->x2 = x + ((m2 * COS(a0)) >> 12) + ((n2 * COS((a0 + 0xc0) & 0xff)) >> 12);
    p->y2 = y + ((m2 * SIN(a0)) >> 12) + ((n2 * SIN((a0 + 0xc0) & 0xff)) >> 12);
}

static __inline__ void quadB_46EC0(POLY_FT4 *p, s16 x, s16 y, s16 a0, s16 a1)
{
s32 m, n2, m2, n;
    m = -D_8007EB80;
    n = -D_8007EB82;
    p->x0 = x + ((m * COS(a1)) >> 12) + ((n * COS((a1 + 0xc0) & 0xff)) >> 12);
    p->y0 = y + ((m * SIN(a1)) >> 12) + ((n * SIN((a1 + 0xc0) & 0xff)) >> 12);
    m2 = D_8007EB80 + D_8007EB7C;
    p->x1 = x + ((m2 * COS(a0)) >> 12) + ((n * COS((a0 + 0x40) & 0xff)) >> 12);
    p->y1 = y + ((m2 * SIN(a0)) >> 12) + ((n * SIN((a0 + 0x40) & 0xff)) >> 12);
    n2 = D_8007EB82 + D_8007EB7E;
    p->x2 = x + ((m * COS(a1)) >> 12) + ((n2 * COS((a1 + 0x40) & 0xff)) >> 12);
    p->y2 = y + ((m * SIN(a1)) >> 12) + ((n2 * SIN((a1 + 0x40) & 0xff)) >> 12);
    p->x3 = x + ((m2 * COS(a0)) >> 12) + ((n2 * COS((a0 + 0xc0) & 0xff)) >> 12);
    p->y3 = y + ((m2 * SIN(a0)) >> 12) + ((n2 * SIN((a0 + 0xc0) & 0xff)) >> 12);
}

void func_80046EC0(GameObject *o)
{
    P_46EC0 s;
    P_46EC0 t;
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
    a0 = o->unk8C & 0xff;
    a1 = (o->unk8C + 0x80) & 0xff;
    if (D_800A5435)
        k = D_8009B698->b7;
    else
        k = PLAYER.obj.animFrame;
    switch (k) {
    case 0: case 1: case 2: case 3:
        switch (*D_800A53BC) {
        case 0x8b: break;
        case 0x94: idx += 2; break;
        case 0x97: idx += 4; break;
        case 0x9a: case 0x9b: case 0x9c: idx += 0x12; break;
        case 0xa3: idx += 0x14; break;
        case 0xa6: idx += 0x16; break;
        }
        break;
    case 4: case 5:
        switch (*D_800A53BC) {
        case 0x8e: case 0x8f: case 0x90: idx += 6; break;
        case 0x95: idx += 8; break;
        case 0x98: idx += 10; break;
        case 0x9d: case 0x9e: case 0x9f: idx += 0x18; break;
        case 0xa4: idx += 0x1a; break;
        case 0xa7: idx += 0x1c; break;
        }
        break;
    case 6: case 7:
        switch (*D_800A53BC) {
        case 0x91: case 0x92: case 0x93: idx += 0xc; break;
        case 0x96: idx += 0xe; break;
        case 0x99: idx += 0x10; break;
        case 0xa0: case 0xa1: case 0xa2: idx += 0x1e; break;
        case 0xa5: idx += 0x20; break;
        case 0xa8: idx += 0x22; break;
        }
        break;
    }
    if (D_8009B6A0->b12) {
        if (D_8009B6A0->w48 > 0)
            SHADOW(D_8009B6A0->q1);
        if (D_8009B6A0->w50 > 0)
            SHADOW(D_8009B6A0->q2);
        p = (POLY_FT4 *)D_1F800164;
        p->code = 0x2d;
        SetSemiTrans(p, 0);
        p->tpage = D_8009B6A0->w4;
        p->clut = D_8009B6A0->w10;
        p->u0 = D_8009B6A0->b13 * 32 - 0x80;
        p->v0 = 0x10;
        p->u1 = D_8009B6A0->b13 * 32 - 0x61;
        p->v1 = 0x10;
        p->u2 = D_8009B6A0->b13 * 32 - 0x80;
        p->v2 = 0x1f;
        p->u3 = D_8009B6A0->b13 * 32 - 0x61;
        p->v3 = 0x1f;
        s.x = D_8009B6A0->x;
        s.y = D_8009B6A0->y;
        if (D_800A5460 && *D_800A53BC >= 0xa9) {
            c = fixedMulCos2((D_800A5424 + 0x40) & 0xff, 0x18);
            sn = fixedMulSin2((D_800A5424 + 0x40) & 0xff, 0x18);
        } else {
            s16 t0;
            s16 kk;
            s16 an;
            t0 = (s8)tbl[idx];
            k = (s8)tbl[idx + 1];
            if (o->animFrame & 1) {
                if (D_800A5448 <= 0) {
                    kk = k;
                    an = D_800A5424 + 0x180;
                    an -= t0;
                    c = fixedMulCos2(an & 0xff, kk);
                    sn = fixedMulSin2(an & 0xff, kk);
                } else {
                    kk = k;
                    an = D_800A5424 + 0x180;
                    an -= t0;
                    c = fixedMulCos2(an & 0xff, kk);
                    sn = fixedMulSin2(an & 0xff, kk);
                }
            } else {
                kk = k;
                an = t0 + D_800A5424;
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
            p->x0 = t.x + fixedMulCos(b1, 8);
            p->y0 = t.y + fixedMulSin(b1, 8);
            b2 = (r + 0xc0) & 0xff;
            p->x2 = t.x + fixedMulCos(b2, 8);
            p->y2 = t.y + fixedMulSin(b2, 8);
            p->x1 = s.x + fixedMulCos(b1, 8);
            p->y1 = s.y + fixedMulSin(b1, 8);
            p->x3 = s.x + fixedMulCos(b2, 8);
            p->y3 = s.y + fixedMulSin(b2, 8);
        }
        if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->unkF - 3, 0x9000000) == 0)
            D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
    }
    p = (POLY_FT4 *)D_1F800164;
    p->code = 0x2d;
    SetSemiTrans(p, o->unkD >> 7);
    {
    u16 cl;
    p->tpage = D_8009B6A0->w4;
    cl = D_8009B6A0->w6;
    k = (D_1F8001F8 & 3) * D_8007EB7C;
    p->u0 = k - 0x80;
    p->v0 = 0;
    p->u1 = p->u0 + (u8)D_8007EB7C - 1;
    p->v1 = p->v0;
    p->u2 = p->u0;
    p->v2 = p->v0 + (u8)D_8007EB7E - 1;
    p->u3 = p->u1;
    p->v3 = p->v2;
    *(u16 *)((char *)p + 14) = cl;
    }
    if (D_800A5460 && *D_800A53BC >= 0xa9) {
        s32 t, g = D_800A5424;
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
    if (otadd_46EC0((unsigned long *)p, D_1F8001E0 + 0x10, D_1F800074, (s8)o->unkF - 4, 0x9000000) == 0)
        D_1F800164 = (u8 *)((POLY_FT4 *)D_1F800164 + 1);
}
#undef COS
#undef SIN
#undef SHADOW

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80047FC8);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_800487A4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80048BF0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80049134);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_80049994);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004A300);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004A6A0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AA70);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AD8C);
extern s16 D_1F800250;
extern GameObject **D_1F800260;

void func_8004AD8C(void)
{
    s32 n;
    GameObject **p;
    GameObject *o;
    if (D_1F8001C6 != 0) {
        n = D_1F800250;
        p = D_1F800260;
        while (n != 0) {
            o = *p++;
            n--;
            if (o->unkA == 0xd) {
                switch ((*(u8 *)&D_800A539A)) {
                case 0: func_8004A6A0(o); break;
                case 1: func_800E9EB8(o); break;
                case 2: func_800EB490(o); break;
                case 3: func_800EAAC8(o); break;
                }
            } else {
                func_80045EFC(o);
            }
        }
    } else {
        D_1F800250 = D_1F800246;
        D_1F800260 = D_1F80021C;
        if (D_1F800246 == 0)
            return;
        do {
            o = *D_1F80021C++;
            D_1F800246--;
            if (o->visible) {
                if (o->unkA == 0xd) {
                    switch ((*(u8 *)&D_800A539A)) {
                    case 0: func_8004A6A0(o); break;
                    case 1: func_800E9EB8(o); break;
                    case 2: func_800EB490(o); break;
                    case 3: func_800EAAC8(o); break;
                    }
                } else {
                    func_80045EFC(o);
                }
            }
        } while ((*(s16 *)&D_1F800246) != 0);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/actorrender2", func_8004AFAC);

s32 func_80045D0C(GameObject *o);
void func_8004B450(GameObject *o);
void func_80123148(GameObject *o);
void func_8004BAF0(GameObject *o);
void drawMessageBoxFrame(GameObject *o);
void func_800E9EB8(GameObject *o);
void func_800EB490(GameObject *o);
void func_800EAAC8(GameObject *o);
void func_8004CC84(GameObject *o);
void func_80123AC4(GameObject *o);
void func_8011B350(GameObject *o);
void func_800EC0E8(GameObject *o);
void func_80117D3C(GameObject *o);
void func_8011812C(GameObject *o);
void func_8004D2A8(GameObject *o);

void func_8004AFAC(void)
{
    s32 n;
    GameObject **p;
    GameObject *o;

    if (D_1F8001C6 != 0) {
        n = D_1F800252;
        p = D_1F800264;
        while (n != 0) {
            o = *p++;
            n--;
            switch (func_80045D0C(o)) {
            case 0: func_800487A4(o); break;
            case 2: func_80049134(o); break;
            case 4: func_8004B450(o); break;
            case 5: func_80123148(o); break;
            case 6: func_8004AA70(o); break;
            case 7: func_8004BAF0(o); break;
            case 8: func_80047FC8(o); break;
            case 1: case 9: func_80048BF0(o); break;
            case 10: drawMessageBox(o); break;
            case 3: case 11: func_80049994(o); break;
            case 12: drawMessageBoxFrame(o); break;
            case 13:
                switch ((*(u8 *)&D_800A539A)) {
                case 0: func_8004A6A0(o); break;
                case 1: func_800E9EB8(o); break;
                case 2: func_800EB490(o); break;
                case 3: func_800EAAC8(o); break;
                }
            case 14: func_8004CC84(o); break;
            case 16: func_8004A300(o); break;
            case 17: func_80123AC4(o); break;
            case 18: func_8011B350(o); break;
            case 19: func_800EC0E8(o); break;
            case 20: func_80117D3C(o); break;
            case 21: func_8011812C(o); break;
            case 22: func_8004D2A8(o); break;
            }
        }
    } else {
        D_1F800252 = D_1F80024A;
        D_1F800264 = D_1F800220;
        while (D_1F80024A != 0) {
            o = *D_1F800220++;
            D_1F80024A--;
            if (o->visible) {
                switch (func_80045D0C(o)) {
                case 0: func_800487A4(o); break;
                case 2: func_80049134(o); break;
                case 4: func_8004B450(o); break;
                case 5: func_80123148(o); break;
                case 6: func_8004AA70(o); break;
                case 7: func_8004BAF0(o); break;
                case 8: func_80047FC8(o); break;
                case 1: case 9: func_80048BF0(o); break;
                case 10: drawMessageBox(o); break;
                case 3: case 11: func_80049994(o); break;
                case 12: drawMessageBoxFrame(o); break;
                case 13:
                    switch ((*(u8 *)&D_800A539A)) {
                    case 0: func_8004A6A0(o); break;
                    case 1: func_800E9EB8(o); break;
                    case 2: func_800EB490(o); break;
                    case 3: func_800EAAC8(o); break;
                    }
                    break;
                case 14: func_8004CC84(o); break;
                case 16: func_8004A300(o); break;
                case 17: func_80123AC4(o); break;
                case 18: func_8011B350(o); break;
                case 19: func_800EC0E8(o); break;
                case 20: func_80117D3C(o); break;
                case 21: func_8011812C(o); break;
                case 22: func_8004D2A8(o); break;
                }
            }
        }
    }
}

const s32 D_800146DC = 0;
