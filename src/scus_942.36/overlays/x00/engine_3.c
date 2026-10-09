#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8010E750);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8010F1C0);
typedef struct { s16 a[3]; char pad[0x24 - 6]; u16 g[10]; char pad2[0x74 - 0x38]; } T74_0F1C0;
extern u8 D_8009C61B;
extern u8 D_8009BCF8;
extern u8 D_8009C26E;
extern u8 D_8009C36E;
typedef struct { char pad[0x2e]; u16 animFrame; char p1[0xb2 - 0x30]; s16 wb2; char pad2[0xc1 - 0xb4]; u8 bc1; } P_0F1C0;

static __inline__ void decel_0F1C0(P_0F1C0 *o, s32 u)
{
    extern T74_0F1C0 D_80114860[];
    u16 w = o->wb2;
    s16 n;
    if ((u16)(w + 0x50) < 0xa1) {
        o->wb2 = 0;
        return;
    }
    n = w;
    if (n > D_80114860[u].a[2])
        o->wb2 = w - D_80114860[u].g[6];
    else if (D_80114860[u].a[1] < n)
        o->wb2 = w - D_80114860[u].g[7];
    else if (D_80114860[u].a[0] < n)
        o->wb2 = w - D_80114860[u].g[8];
    else if (n > 0)
        o->wb2 = w - D_80114860[u].g[9];
    else if (n < -D_80114860[u].a[2])
        o->wb2 = w + D_80114860[u].g[6];
    else if (n < -D_80114860[u].a[1])
        o->wb2 = w + D_80114860[u].g[7];
    else if (n < -D_80114860[u].a[0])
        o->wb2 = w + D_80114860[u].g[8];
    else if (n < 0)
        o->wb2 = w + D_80114860[u].g[9];
}

static __inline__ void step_0F1C0(P_0F1C0 *o, s32 u)
{
    extern T74_0F1C0 D_80114860[];
    s32 v, s;
    s16 k = u;
    switch (o->animFrame & 3) {
    case 0:
        v = o->wb2;
        s = v;
        if (v < -D_80114860[u].a[1])
            o->wb2 = o->wb2 + D_80114860[u].g[0];
        else if (v < -D_80114860[u].a[0])
            o->wb2 = o->wb2 + D_80114860[u].g[1];
        else if (v < 0)
            o->wb2 = o->wb2 + D_80114860[u].g[2];
        else if (v == 0)
            o->wb2 = D_80114860[u].g[3];
        else if (v < D_80114860[u].a[1])
            o->wb2 = o->wb2 + D_80114860[u].g[4];
        else if (v < D_80114860[u].a[2])
            o->wb2 = o->wb2 + D_80114860[u].g[5];
        else
            o->wb2 = D_80114860[u].a[2];
        break;
    case 1:
        v = o->wb2;
        s = v;
        if (D_80114860[u].a[1] < v)
            o->wb2 = o->wb2 - D_80114860[u].g[0];
        else if (D_80114860[u].a[0] < v)
            o->wb2 = o->wb2 - D_80114860[u].g[1];
        else if (v > 0)
            o->wb2 = o->wb2 - D_80114860[u].g[2];
        else if (v == 0)
            o->wb2 = -D_80114860[u].g[3];
        else if (-D_80114860[u].a[1] < v)
            o->wb2 = o->wb2 - D_80114860[u].g[4];
        else if (-D_80114860[u].a[2] < v)
            o->wb2 = o->wb2 - D_80114860[u].g[5];
        else
            o->wb2 = -D_80114860[u].a[2];
        break;
    case 2:
    case 3:
        decel_0F1C0(o, k);
        break;
    }
}

static __inline__ void body_0F1C0(P_0F1C0 *o)
{
    s32 b = o->bc1;
    s32 u = D_8009C61B + b * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)b << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    step_0F1C0(o, u);
}
void func_8010F1C0(P_0F1C0 *o)
{
    body_0F1C0(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8010F604);
typedef struct {
    s16 f0, f2, f4, f6;
    char r[0x38 - 8];
    u16 g38, g3a, g3c, g3e, g40, g42, g44, g46, g48, g4a, g4c;
    char r2[0x74 - 0x4e];
} T74_0F604;
extern T74_0F604 D_80114860_T74_0F604Arr[] asm("D_80114860");
#define TB D_80114860_T74_0F604Arr[u]

static __inline__ void l38_0F604(u8 *p, s32 u)
{
    if (*(s16 *)(p + 0xb2) > TB.f2)
        *(s16 *)(p + 0xb2) -= TB.g38;
    else if (TB.f0 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) -= TB.g3a;
    else if (*(s16 *)(p + 0xb2) > 0)
        *(s16 *)(p + 0xb2) -= TB.g3c;
    else if (*(s16 *)(p + 0xb2) == 0)
        *(s16 *)(p + 0xb2) = -TB.g3e;
    else if (-TB.f2 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) -= TB.g40;
    else if (*(s16 *)(p + 0xb2) < -TB.f2)
        *(s16 *)(p + 0xb2) = -TB.f2;
}

static __inline__ void r42_0F604(u8 *p, s32 u)
{
    if (*(s16 *)(p + 0xb2) < -TB.f2)
        *(s16 *)(p + 0xb2) += TB.g42;
    else if (*(s16 *)(p + 0xb2) < -TB.f0)
        *(s16 *)(p + 0xb2) += TB.g44;
    else if (*(s16 *)(p + 0xb2) < 0)
        *(s16 *)(p + 0xb2) += TB.g46;
    else if (*(s16 *)(p + 0xb2) == 0)
        *(s16 *)(p + 0xb2) = TB.g48;
    else if (*(s16 *)(p + 0xb2) < TB.f2)
        *(s16 *)(p + 0xb2) += TB.g4a;
    else {
        if (*(s16 *)(p + 0xb2) < TB.f6)
            *(s16 *)(p + 0xb2) += TB.g4c;
        else
            *(s16 *)(p + 0xb2) = TB.f6;
    }
}

static __inline__ void l42_0F604(u8 *p, s32 u)
{
    if (TB.f2 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) -= TB.g42;
    else if (TB.f0 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) -= TB.g44;
    else if (*(s16 *)(p + 0xb2) > 0)
        *(s16 *)(p + 0xb2) -= TB.g46;
    else if (*(s16 *)(p + 0xb2) == 0)
        *(s16 *)(p + 0xb2) = -TB.g48;
    else if (-TB.f2 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) -= TB.g4a;
    else {
        if (-TB.f6 < *(s16 *)(p + 0xb2))
            *(s16 *)(p + 0xb2) -= TB.g4c;
        else
            *(s16 *)(p + 0xb2) = -TB.f6;
    }
}

static __inline__ void r38_0F604(u8 *p, s32 u)
{
    if (*(s16 *)(p + 0xb2) < -TB.f2)
        *(s16 *)(p + 0xb2) += TB.g38;
    else if (*(s16 *)(p + 0xb2) < -TB.f0)
        *(s16 *)(p + 0xb2) += TB.g3a;
    else if (*(s16 *)(p + 0xb2) < 0)
        *(s16 *)(p + 0xb2) += TB.g3c;
    else if (*(s16 *)(p + 0xb2) == 0)
        *(s16 *)(p + 0xb2) = TB.g3e;
    else if (*(s16 *)(p + 0xb2) < TB.f2)
        *(s16 *)(p + 0xb2) += TB.g40;
    else if (TB.f2 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) = TB.f2;
}

static __inline__ void mid_0F604(u8 *p, s32 u)
{
    switch (p[0xbe] & 1) {
    case 0:
        if (*(u16 *)(p + 0x2e) & 1)
            l38_0F604(p, u);
        else
            r42_0F604(p, u);
        break;
    case 1:
        if (*(u16 *)(p + 0x2e) & 1)
            l42_0F604(p, u);
        else
            r38_0F604(p, u);
        break;
    }
}

void func_8010F604(u8 *p)
{
    s32 u;
    s32 c;
    c = p[0xc1];
    u = D_8009C61B + c * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)c << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    mid_0F604(p, u);
}
#undef TB

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8010FAB0);
extern u8 D_80114860[];
typedef struct { s16 f0, f2, f4, f6; char r[0x74 - 8]; } T74_0FAB0;
extern T74_0FAB0 D_80114860_T74_0FAB0Arr[] asm("D_80114860");

static __inline__ void dec_0FAB0(u8 *p, s16 u, s32 g)
{
    u16 s;
    s32 i, n;
    s = *(s16 *)(p + 0xb2);
    if ((u16)(s + 0x50) < 0xa1) {
        *(s16 *)(p + 0xb2) = 0;
        return;
    }
    i = u * 0x74;
    n = (s16)s;
    if (*(s16 *)(D_80114860 + i + 4) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + g);
    else if (*(s16 *)(D_80114860 + i + 2) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 2));
    else if (*(s16 *)(D_80114860 + i + 0) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 4));
    else if (n > 0)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 6));
    else if (n < -*(s16 *)(D_80114860 + i + 4))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + g);
    else if (n < -*(s16 *)(D_80114860 + i + 2))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 2));
    else if (n < -*(s16 *)(D_80114860 + i + 0))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 4));
    else if (n < 0)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 6));
}

static __inline__ void acc_0FAB0(u8 *p, s16 u)
{
    s16 s;
    s32 i;
    i = u * 0x74;
    s = *(s16 *)(p + 0xb2);
    if (*(s16 *)(D_80114860 + i + 4) < s)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x5e);
    else if (*(s16 *)(D_80114860 + i + 2) < s)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x60);
    else if (*(s16 *)(D_80114860 + i + 0) < s)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x62);
    else if (s > 0)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x64);
    else if (s < -*(s16 *)(D_80114860 + i + 4))
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x5e);
    else if (s < -*(s16 *)(D_80114860 + i + 2))
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x60);
    else if (s < -*(s16 *)(D_80114860 + i + 0))
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x62);
    else if (s < 0)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x64);
}

static __inline__ void clamp_0FAB0(u8 *p, s16 u)
{
    if (*(s16 *)(p + 0xb2) < -D_80114860_T74_0FAB0Arr[u].f6)
        *(s16 *)(p + 0xb2) = -D_80114860_T74_0FAB0Arr[u].f6;
    if (D_80114860_T74_0FAB0Arr[u].f6 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) = D_80114860_T74_0FAB0Arr[u].f6;
}

static __inline__ void mid_0FAB0(u8 *p, s16 u)
{
    s32 m;
    m = 0;
    if (p[0xbe] != 0) {
        m = 1;
        if ((*(u16 *)(p + 0x2e) & 1) == (p[0xbe] & 1))
            m = 2;
    }
    switch (m) {
    case 0:
        dec_0FAB0(p, u, 0x4e);
        break;
    case 1:
        dec_0FAB0(p, u, 0x56);
        break;
    case 2:
        acc_0FAB0(p, u);
        break;
    }
    clamp_0FAB0(p, u);
}

void func_8010FAB0(u8 *p)
{
    s32 u;
    s32 c;
    c = p[0xc1];
    u = D_8009C61B + c * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)c << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    mid_0FAB0(p, u);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8010FFFC);
typedef struct { s16 f0, f2, f4, f6; char r[0x74 - 8]; } T74_0FFFC;
extern T74_0FFFC D_80114860_T74_0FFFCArr[] asm("D_80114860");

static __inline__ void dec_0FFFC(u8 *p, s32 u, s32 g)
{
    u16 s;
    s32 i, n;
    s = *(s16 *)(p + 0xb2);
    if ((u16)(s + 0x50) < 0xa1) {
        *(s16 *)(p + 0xb2) = 0;
        return;
    }
    i = u * 0x74;
    n = (s16)s;
    if (*(s16 *)(D_80114860 + i + 4) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + g);
    else if (*(s16 *)(D_80114860 + i + 2) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 2));
    else if (*(s16 *)(D_80114860 + i + 0) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 4));
    else if (n > 0)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + (g + 6));
    else if (n < -*(s16 *)(D_80114860 + i + 4))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + g);
    else if (n < -*(s16 *)(D_80114860 + i + 2))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 2));
    else if (n < -*(s16 *)(D_80114860 + i + 0))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 4));
    else if (n < 0)
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + (g + 6));
}

static __inline__ void clamp_0FFFC(u8 *p, s16 u)
{
    if (*(s16 *)(p + 0xb2) < -D_80114860_T74_0FFFCArr[u].f6)
        *(s16 *)(p + 0xb2) = -D_80114860_T74_0FFFCArr[u].f6;
    if (D_80114860_T74_0FFFCArr[u].f6 < *(s16 *)(p + 0xb2))
        *(s16 *)(p + 0xb2) = D_80114860_T74_0FFFCArr[u].f6;
}

static __inline__ void mid_0FFFC(u8 *p, s16 u)
{
    dec_0FFFC(p, u, 0x56);
    clamp_0FFFC(p, u);
}

void func_8010FFFC(u8 *p)
{
    s32 u;
    s32 c;
    c = p[0xc1];
    u = D_8009C61B + c * 4;
    if ((D_8009BCF8 & 3) != 0)
        u = (u8)c << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    mid_0FFFC(p, u);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8011023C);
static __inline__ void inc_1023C(GameObject *o, s16 w)
{
    if (w < -0x144) o->unkB2 = w + 0x20;
    else if (w < -0x84) o->unkB2 = w + 0x22;
    else if (w < 0) o->unkB2 = w + 0x26;
    else if (w == 0) o->unkB2 = 0x88;
    else if (w < 0x144) o->unkB2 = w + 0x10;
    else if (w < 0x500) o->unkB2 = w + 0x20;
    else o->unkB2 = 0x500;
}

static __inline__ void dec_1023C(GameObject *o, s16 w)
{
    if (w >= 0x145) o->unkB2 = w - 0x20;
    else if (w >= 0x85) o->unkB2 = w - 0x22;
    else if (w > 0) o->unkB2 = w - 0x26;
    else if (w == 0) o->unkB2 = -0x88;
    else if (w >= -0x143) o->unkB2 = w - 0x10;
    else if (w >= -0x4ff) o->unkB2 = w - 0x20;
    else o->unkB2 = -0x500;
}

void func_8011023C(GameObject *o)
{
    switch (o->unkBE & 1) {
    case 0:
        inc_1023C(o, o->unkB2);
        break;
    case 1:
        dec_1023C(o, o->unkB2);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8011032C);
extern u8 D_8009C61B;
extern u8 D_8009C26E;
extern u8 D_8009C36E;
extern u8 D_8009BCF8;
extern u8 D_80114860[];

void func_8011032C(u8 *p)
{
    u32 u;
    u16 s;
    s32 i, n, c;
    u8 *q = p;
    c = p[0xc1];
    u = D_8009C61B + c * 4; if ((D_8009BCF8 & 3) != 0) u = (u8)c << 2 | 3;
    if (D_8009C26E != 0)
        u = 8;
    if (D_8009C36E != 0)
        u = 8;
    s = *(u16 *)(p + 0xb2);
    if ((u16)(s + 0x50) < 0xa1) {
        *(s16 *)(p + 0xb2) = 0;
        return;
    }
    i = u * 0x74;
    n = (s16)s;
    if (*(s16 *)(D_80114860 + i + 2) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x66);
    else if (*(s16 *)(D_80114860 + i + 0) < n)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x68);
    else if (n > 0)
        *(s16 *)(p + 0xb2) = s - *(s16 *)(D_80114860 + i + 0x6a);
    else if (n < -*(s16 *)(D_80114860 + i + 2))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x66);
    else if (n < -*(s16 *)(D_80114860 + i + 0))
        *(s16 *)(p + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x68);
    else if (n < 0)
        *(s16 *)(q + 0xb2) = s + *(s16 *)(D_80114860 + i + 0x6a);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801104BC);
typedef struct { s16 a[3]; char pad[0x6c - 6]; u16 b[4]; } T74_104BC;
extern T74_104BC D_80114860_T74_104BCArr[] asm("D_80114860");
typedef struct { char pad[0xb2]; u16 wb2; char pad2[0xc1 - 0xb4]; u8 bc1; } P_104BC;

static __inline__ void body_104BC(P_104BC *o)
{
    s16 i;
    u16 w;
    s16 s;
    i = D_8009C61B + o->bc1 * 4;
    if (D_8009BCF8 & 3)
        i = (o->bc1 << 2) | 3;
    if (D_8009C26E)
        i = 8;
    if (D_8009C36E)
        i = 8;
    w = o->wb2;
    if ((u16)(w + 0x50) <= 0xa0) {
        o->wb2 = 0;
        return;
    }
    s = w;
    if (s > D_80114860_T74_104BCArr[i].a[2])
        o->wb2 = w - D_80114860_T74_104BCArr[i].b[0];
    else if (s > D_80114860_T74_104BCArr[i].a[1])
        o->wb2 = w - D_80114860_T74_104BCArr[i].b[1];
    else if (s > D_80114860_T74_104BCArr[i].a[0])
        o->wb2 = w - D_80114860_T74_104BCArr[i].b[2];
    else if (s > 0)
        o->wb2 = w - D_80114860_T74_104BCArr[i].b[3];
    else if (s < -D_80114860_T74_104BCArr[i].a[2])
        o->wb2 = w + D_80114860_T74_104BCArr[i].b[0];
    else if (s < -D_80114860_T74_104BCArr[i].a[1])
        o->wb2 = w + D_80114860_T74_104BCArr[i].b[1];
    else if (s < -D_80114860_T74_104BCArr[i].a[0])
        o->wb2 = w + D_80114860_T74_104BCArr[i].b[2];
    else if (s < 0)
        o->wb2 = w + D_80114860_T74_104BCArr[i].b[3];
}

void func_801104BC(P_104BC *o)
{
    body_104BC(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8011068C);
extern u8 D_8009C980;

void func_8011068C(char *o)
{
    s16 s;
    char *p;
    volatile u16 *k;
    p = o;
    s = 0x200;
    if ((*(u16 *)&D_8009C978) == 7)
        s >>= 3 - D_8009C980;
    k = &D_8009C9D8;
    if (*k & 0x80)
        *(s16 *)(o + 0x7c) = -s;
    else if (*k & 0x20)
        *(s16 *)(o + 0x7c) = s;
    else
        *(s16 *)(p + 0x7c) = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_8011070C);
extern u8 D_8009C981;

void func_8011070C(GameObject *o)
{
    s16 v;
    v = 0x20;
    if ((*(u16 *)&D_8009C978) == 7) { v = 0x20; v = v >> (3 - D_8009C981); }
    if (*(volatile u16 *)&D_8009C9D8 & 0x40) o->velY = o->velY + v;
    else o->velY = o->velY - v;
    if (o->velY > 0x300) o->velY = 0x300;
    if (o->velY < 0xc0) o->velY = 0xc0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801107AC);
typedef struct { u16 a; s16 p0; s16 b; s16 p1; s32 *c; } E8_107AC;
extern E8_107AC D_80114C74[];
extern s32 SPR_DATA[];
extern void readAnimFrameCount(GameObject *o);

void func_801107AC(GameObject *o)
{
    o->hitOffsetX = 0x20;
    o->hitWidth = 0x40;
    o->hitOffsetY = 0x1e;
    o->hitHeight = 0x3c;
    o->tpage = D_80114C74[o->subtype].a;
    o->spriteBank = SPR_DATA[D_80114C74[o->subtype].b];
    o->anim = (void *)D_80114C74[o->subtype].c[o->unkC];
    readAnimFrameCount(o);
    o->unkA = 13;
    o->unkD = 0x80;
    o->category |= 0x80;
    o->unk8C = 0;
    o->objectIndex = 0;
    *(s8 *)&o->unkF = -7;
    if (o->subtype == 2) {
        o->unkA5 = 0;
        o->active = 2;
    } else {
        o->unkA5 = 1;
        o->unk98 = 2;
    }
    o->state = o->state + 1;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801108E0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110A64);
extern void tickAnimation(GameObject *o);
typedef struct G_10A64 { char p0[0xf]; u8 b0f; char p1[0x16 - 0x10]; u16 y; char p2[0x40 - 0x18]; Fix16 *h; Fix16 *d; } G_10A64;

void func_80110A64(GameObject *o)
{
    s8 t;
    switch (o->step) {
    case 0:
        o->anim = (void *)D_80114C74[o->subtype].c[o->unkC];
        readAnimFrameCount(o);
        o->unkA5 = 1;
        o->unk88 = 0;
        o->timer = 0xb4;
        o->step++;
    case 1:
        tickAnimation(o);
        o->timer--;
        o->visible = 0;
        if (o->timer >= 0x3d) {
            t = o->objectIndex < 0x7f ? o->objectIndex + 8 : o->objectIndex;
        } else {
            if (o->timer < 0) {
                o->objectIndex = 0;
                o->state = 3;
                goto L;
            }
            t = o->objectIndex != 0 ? o->objectIndex - 2 : 0;
        }
        o->objectIndex = t;
    L:
        o->h->p.whole = (*(G_10A64 *)&PLAYER).h->p.whole;
        o->y.p.whole = (*(G_10A64 *)&PLAYER).y - 8;
        o->d->p.whole = (*(G_10A64 *)&PLAYER).d->p.whole;
        o->unkF = (*(G_10A64 *)&PLAYER).b0f - 1;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110BD0);
extern void func_801108E0(GameObject *);
extern void func_80110A64(GameObject *);

void func_80110BD0(GameObject *o)
{
    switch (o->subtype) {
    case 0:
        func_801108E0(o);
        break;
    case 1:
        func_80110A64(o);
        break;
    }
    if (o->cooldownTimer != 0) {
        o->cooldownTimer--;
        if (o->cooldownTimer <= 0)
            o->active = 1;
    }
    if (o->unk6A != 0) {
        o->unk6A = 0;
        o->cooldownTimer = 3;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110C6C);
extern void freeObjectLayer1(void *);

void func_80110C6C(u8 *o)
{
    switch (o[4]) {
    case 0:
        func_801107AC(o);
        break;
    case 1:
        if ((u32)((*(u8 *)&PLAYER) - 4) >= 2) {
            func_80022E44(o);
            switch (o[3]) {
            case 0:
                func_801108E0(o);
                break;
            case 1:
                func_80110A64(o);
                break;
            }
            if (*(s16 *)(o + 0x22) != 0) {
                *(s16 *)(o + 0x22) = *(s16 *)(o + 0x22) - 1;
                if (*(s16 *)(o + 0x22) < 1)
                    o[0] = 1;
            }
            if (o[0x6a] != 0) {
                o[0x6a] = 0;
                *(s16 *)(o + 0x22) = 3;
            }
        }
        break;
    case 2:
        o[4] = 3;
        break;
    case 3:
        freeObjectLayer1(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110DA0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110E30);
extern void func_8012E0A4(void);
extern void func_80122E44(void);
extern void func_80120ECC(void);
void func_80110E30(void)
{
    u16 m = (*(u16 *)&GAME);
    if (m == 0) {
        func_8012E0A4();
    } else if (m == 4) {
        func_80122E44();
    } else if (m == 10) {
        func_80120ECC();
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80110E90);
typedef struct { s16 lo, hi; } HL_10E90;
typedef union { s32 i; HL_10E90 s; } FX_10E90;
typedef struct { FX_10E90 x, y, z; } V3_10E90;
typedef struct { char p0[2]; s16 s2; } H_10E90;
typedef struct { s16 a, b; } AB_10E90;
typedef struct O_10E90 {
    char p0[0x16]; u16 w16; char p1[0x40 - 0x18]; H_10E90 *h, *h44; char p2[0x6a - 0x48]; u8 b6a;
} O_10E90;
extern u8 D_80114DA8[][6];
extern u8 *D_8011508C[];
extern AB_10E90 D_801150C0[];
extern u8 D_8009C1B2;
extern u8 D_8009C420;

void func_80110E90(O_10E90 *o)
{
    extern void spawnItemFromEntry(u8 *, V3_10E90 *, s32, s32, O_10E90 *);
    V3_10E90 v;
    u8 *e, *l;
    s32 i;
    v.x.s.hi = o->h->s2;
    v.y.s.hi = o->w16;
    v.z.s.hi = o->h44->s2;
    e = D_80114DA8[o->b6a];
    if (e[0] == 0xff) {
        l = D_8011508C[e[1]];
        for (i = 0; *l != 0xff; i++) {
            spawnItemFromEntry(l, &v, D_801150C0[i].a, D_801150C0[i].b, o);
            l += 6;
        }
    } else if (e[0] == 0xfe) {
        switch (e[1]) {
        case 0:
            if ((((s32 (*)(void))nextRandom)() & 7) < 4) {
                spawnItemFromEntry(D_8011508C[1], &v, 0, -0x400, o);
            } else {
                l = D_8011508C[0];
                for (i = 0; *l != 0xff; i++) {
                    spawnItemFromEntry(l, &v, D_801150C0[i].a, D_801150C0[i].b, o);
                    l += 6;
                }
            }
            break;
        case 1:
            if (D_8009C1B2 == 0xff) spawnItemFromEntry(D_8011508C[8], &v, 0, -0x400, o);
            else spawnItemFromEntry(D_8011508C[7], &v, 0, -0x400, o);
            break;
        case 2:
            if (D_8009C420 == 0) spawnItemFromEntry(D_8011508C[9], &v, 0, -0x400, o);
            else spawnItemFromEntry(D_8011508C[10], &v, 0, -0x400, o);
            break;
        }
    } else {
        spawnItemFromEntry(e, &v, 0, -0x400, o);
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111118);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801112A8);
extern s16 DAT_1f80016ab[];

void func_801112A8(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;
    u8 d;
    s32 w;
    s16 v;

    o->h->p.whole += p->h->p.whole - o->unkB4;
    o->y.p.whole += p->y.p.whole - o->unkB6;
    o->unkB4 = p->h->p.whole;
    o->unkB6 = p->y.p.whole;
    if (func_80022E44(o) == 0) return;
    switch (o->subState) {
    case 0:
        if (o->visible) o->subState++;
        break;
    case 1:
        o->h->p.whole = p->h->p.whole + 0x18;
        o->y.p.whole = p->y.p.whole - 0x10;
        if ((*(s16 *)&D_1F80016A) > o->h->p.whole) o->subState++;
        break;
    case 2:
        o->h->p.whole = p->h->p.whole + 0x18;
        o->y.p.whole = p->y.p.whole - 0x10;
        if ((*(s16 *)&D_1F80016A) < o->h->p.whole + 0x18 && p->unk8C > 0x150) break;
        o->velY = 0x100;
        o->touchFlag = 0;
        o->velX = 0x80;
        o->subState++;
        o->unk78 = ((o->unk38 + 0x800) & 0xfff) >> 4;
        if (o->unk78 > 0x80) o->unk78 = 0x80;
        w = (u16)o->unk78;
        d = o->unk8C - 0x80 - w;
        if (d != 0) {
            if (d < 0x80) o->unk8C--;
            else o->unk8C++;
            o->unk8C = *(u8 *)&o->unk8C;
        }
        v = -o->velX;
        o->velV = v * D_8007D788[o->unk78] >> 12;
        o->velH = v * D_8007DB88[o->unk78] >> 12;
    case 3:
        func_80111118(o);
        if (o->y.p.whole >= -0xae) {
            o->timer = 10;
            o->active = 2;
            o->state = 2;
            o->subState = 7;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111554);
extern char D_80114E4A[];
extern s32 GAME_S32Arr[] asm("GAME");
extern s32 *D_80114D58[];
extern s32 *D_80114C98[];
extern void func_80023020(GameObject *o);
extern void func_800EAC50(GameObject *o, s32 x, s32 y, s32 z);

void func_80111554(GameObject *o)
{
    GameObject *p = (GameObject *)o->unk90;
    s16 dx, dy;
    Fix16 v[3];
    dx = p->h->p.whole - o->unkB4;
    dy = p->y.p.whole - o->unkB6;
    o->h->p.whole += dx;
    o->y.p.whole += dy;
    o->unkB4 = p->h->p.whole;
    o->unkB6 = p->y.p.whole;
    func_80022E44(o);
    switch (o->subState) {
    case 0:
        D_800A53D8[1] += dx;
        D_800A53AE[0] += dy;
        break;
    case 1:
        func_80023794(o->objectIndex);
        v[0].p.whole = o->h->p.whole;
        v[1].p.whole = o->y.p.whole;
        v[2].p.whole = o->d->p.whole;
        spawnItemFromEntry(D_80114E4A, v, -0x40, -0x400, o);
        spawnItemFromEntry(D_80114E4A, v, 0x40, -0x400, o);
        o->subState = 3;
        o->timer = 10;
        o->unkAC = 1;
        if (GAME_S32Arr[0] == 0x30009)
            o->anim = (void *)D_80114D58[o->unkC & 0x7f][1];
        else
            o->anim = (void *)D_80114C98[(*(u16 *)&GAME) * 4 + (o->unkC & 0x7f)][1];
        readAnimFrameCount(o);
        o->touchFlag = 0;
        o->velX = 0x80;
        o->velY = 0x100;
        o->unk78 = ((o->unk38 + 0x800) & 0xfff) >> 4;
        if (o->unk78 > 0x80) o->unk78 = 0x80;
        o->unk8C = o->unk78 + 0x80;
        break;
    case 2:
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        break;
    case 3:
        if (--o->timer == -1) {
            o->active = 3;
            o->subState++;
        }
    case 4:
        if (o->visible == 0) {
            o->state = 3;
            break;
        }
        func_80023020(o);
        func_80111118(o);
        if (o->y.p.whole < -0xae) break;
        o->timer = 10;
        o->active = 2;
        o->subState = 7;
        break;
    case 5:
        func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        func_80023794(o->objectIndex);
        o->state++;
        break;
    case 7:
        func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        o->state++;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111870);
extern s16 probeCollisionAtDepthA(GameObject *o, s32 a, s32 b);

void func_80111870(GameObject *o)
{
    ((void (*)(void))func_80022E44)();
    switch (o->subState) {
    case 0:
        o->velV = o->velV + 0x20;
        if (o->velV > 0x400) {
            o->velV = 0x400;
        }
        o->y.raw += o->velV << 8;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10)) != 0) {
            o->active = 1;
            o->subState = o->subState + 1;
        }
        break;
    case 1:
        o->velV = 0x100;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111938);
extern char D_80115078[];
extern void spawnItemFromEntry(char *d, Fix16 *pos, s32 a, s32 b, GameObject *o);
extern void func_80023020(GameObject *o);

void func_80111938(GameObject *o)
{
    void **p;
    func_80022E44(o);
    switch (o->subState) {
    case 0:
        o->velV += 0x20;
        if (o->velV > 0x400)
            o->velV = 0x400;
        o->y.raw += o->velV << 8;
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        break;
    case 1:
        spawnItemFromEntry(D_80115078, &o->x, -0x40, -0x400, o);
        spawnItemFromEntry(D_80115078 + 6, &o->x, 0x40, -0x400, o);
        o->subState = 3;
        o->timer = 10;
        o->unkAC = 1;
        if (GAME_S32Arr[0] == 0x30009)
            o->anim = D_80114D58[o->unkC & 0x7f][1];
        else
            o->anim = D_80114C98[((u16 *)&GAME)[0] * 4 + (o->unkC & 0x7f)][1];
        readAnimFrameCount(o);
        break;
    case 2:
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        break;
    case 3:
        if (--o->timer == -1) {
            o->active = 3;
            o->velV = 0;
            o->subState++;
        }
        break;
    case 4:
        o->velV += 0x20;
        if (o->velV > 0x400)
            o->velV = 0x400;
        o->y.raw += o->velV << 8;
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10));
        func_80023020(o);
        break;
    case 7:
        func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        o->state++;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111BB4);
void func_80111BB4(GameObject *o)
{
    o->unkA = 0;
    *(s16 *)((char *)o + 0x82) = 0;
    *(s32 *)((char *)o + 0x84) = 0;
    *(s32 *)((char *)o + 0x88) = 0;
    *(s32 *)((char *)o + 0x8c) = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111BCC);
void func_80111BCC(GameObject *o)
{
    o->unkA = 2;
    o->velV = 0;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk8C = 0;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111BE8);
void func_80111BE8(GameObject *o)
{
    GameObject *p = *(GameObject **)&o->unk90;
    o->unkA = 2;
    o->movetab = ((char *)&D_800771FC);
    o->unk38 = 0xd20;
    o->unk84 = 0;
    o->unk88 = 0;
    o->unk8C = 0;
    o->velX = 0;
    o->velY = 0x200;
    o->unkB4 = p->h->p.whole;
    o->unkB6 = p->y.p.whole;
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111C40);
void func_80111C40(GameObject *o)
{
    o->unkA = 0;
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111C48);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111C68);
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_80111C68(GameObject *o)
{
    s16 yy;
    switch (o->subState) {
    case 0:
        yy = o->y.p.whole;
        o->y.p.whole = yy + 4;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(yy + 0x14))) {
            o->unk8C = (-D_1F80027E << 2) & 0xff;
            o->subState++;
        }
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
    case 1:
        func_80022E44(o);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111D20);
extern u16 GAME_U16Arr[] asm("GAME");
extern u8 D_8009C412;
extern u8 D_8009C430;
extern u8 D_8009BCA3;

#define SETANIM(o) \
    o->unkAC = 1; \
    if (GAME_S32Arr[0] == 0x30009) o->anim = D_80114D58[o->unkC & 0x7f][1]; \
    else o->anim = D_80114C98[(*(u16 *)&GAME) * 4 + (o->unkC & 0x7f)][1]; \
    readAnimFrameCount(o);

void func_80111D20(GameObject *o)
{
    switch (o->subState) {
    case 0:
        o->active = 4;
        o->y.p.whole += 4;
        if (GAME_U16Arr[0] == 0 && D_8009C412 != 0) {
            SETANIM(o)
        }
        if ((GAME_U16Arr[0] == 4 || GAME_U16Arr[0] == 0xc) && D_8009C430 != 0) {
            SETANIM(o)
        }
        if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10)) o->subState++;
    case 1:
        if (D_8009BCA3) {
            o->state = 2;
            o->subState = 0;
        }
        func_80022E44(o);
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111F30);
extern u8 D_8009BCCC;
extern u8 D_8009BCA2;
extern void func_80116814(void);

void func_80111F30(void)
{
    if (D_8009BCCC != 0x21 || D_8009BCA2 != 1) func_80116814();
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80111F74);
extern u8 D_8009C438;
extern u8 D_8009C439;
void printInfoMessage(s32 a, s32 b);
void setEventComplete(s32 a, s32 b);

static __inline__ s32 check_11F74(GameObject *o)
{
    u8 v;
    switch (o->unkC & 0x7f) {
    case 0: v = D_8009C412; break;
    case 1: v = D_8009C430; break;
    case 2: v = D_8009C438; break;
    case 3: v = D_8009C439; break;
    default: goto fail;
    }
    if (v) return 1;
fail:
    printInfoMessage(0, 2);
    return 0;
}

void func_80111F74(GameObject *o)
{
    func_80022E44(o);
    switch (o->subState) {
    case 0:
        break;
    case 1:
        if (check_11F74(o)) {
            func_80110E90(o);
            o->subState = 3;
            o->timer = 10;
            o->unkAC = 1;
            if (GAME_S32Arr[0] == 0x30009) {
                o->anim = (void *)D_80114D58[o->unkC & 0x7f][1];
            } else {
                o->anim = (void *)D_80114C98[((u16 *)&GAME)[0] * 4 + (o->unkC & 0x7f)][1];
            }
            readAnimFrameCount(o);
            playSFXWithNote(0x18, 8);
            if (o->subtype == 6) {
                setEventComplete(0x19, 0);
            }
            break;
        }
        goto fail;
    case 2:
        o->subState = 6;
        break;
    case 3:
        if (--o->timer == -1) {
            o->subState++;
        }
        break;
    case 4:
        o->velV += 0x20;
        if (o->velV > 0x400) {
            o->velV = 0x400;
        }
        o->y.raw += o->velV << 8;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) {
            func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            o->state = 3;
        } else {
            func_80023020(o);
        }
        break;
    case 5:
        if (--o->timer == -1) {
            o->subState++;
        }
        o->y.p.whole = o->unk34 + (D_1F8001F8 & 1);
        o->h->p.whole = (s16)(o->unk30 - 2) + (((s32 (*)(void))nextRandom)() & 3);
        break;
    case 6:
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        o->y.p.whole = o->unk34;
        o->h->p.whole = o->unk30;
        break;
    case 7:
        if (!check_11F74(o)) {
        fail:
            playSFXWithNote(0x18, 0x12);
            o->subState = 5;
            o->timer = 0x14;
            break;
        }
        func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
        o->state++;
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112384);
extern u8 D_8009C438;
extern u8 D_8009C439;
extern void printInfoMessage(s32, s32);

static __inline__ s16 chk_12384(GameObject *o)
{
    u8 f;
    switch (o->unkC & 0x7f) {
    case 0:
        f = D_8009C412;
        break;
    case 1:
        f = D_8009C430;
        break;
    case 2:
        f = D_8009C438;
        break;
    case 3:
        f = D_8009C439;
        break;
    default:
        printInfoMessage(0, 2);
        return 0;
    }
    if (f)
        return 1;
    printInfoMessage(0, 2);
    return 0;
}

void func_80112384(GameObject *o)
{
    func_80022E44(o);
    switch (o->subState) {
    case 0:
        break;
    case 1:
        if (chk_12384(o)) {
            func_80110E90(o);
            o->subState = 3;
            o->timer = 10;
            o->unkAC = 1;
            if (GAME_S32Arr[0] == 0x30009)
                o->anim = D_80114D58[o->unkC & 0x7f][1];
            else
                o->anim = D_80114C98[(*(u16 *)&GAME) * 4 + (o->unkC & 0x7f)][1];
            readAnimFrameCount(o);
            playSFXWithNote(0x18, 8);
        } else {
            playSFXWithNote(0x18, 0x12);
            o->subState = 5;
            o->timer = 10;
        }
        break;
    case 2:
        o->subState = 6;
        break;
    case 3:
        if (--o->timer == -1) {
            o->active = 3;
            o->subState++;
        }
        break;
    case 4:
        if (o->visible)
            func_80023020(o);
        else
            o->state = 3;
        break;
    case 5:
        if (--o->timer == -1)
            o->subState++;
        o->y.p.whole = o->unk34 + (D_1F8001F8 & 1);
        o->h->p.whole = (s16)(o->unk30 - 2) + (((s32 (*)(void))nextRandom)() & 3);
        break;
    case 6:
        o->active = 1;
        o->state = 1;
        o->subState = 0;
        o->y.p.whole = o->unk34;
        o->h->p.whole = o->unk30;
        break;
    case 7:
        if (!chk_12384(o)) {
            playSFXWithNote(0x18, 0x12);
            o->subState = 5;
            o->timer = 10;
        } else {
            func_800EAC50(o, o->x.p.whole, o->y.p.whole, o->z.p.whole);
            o->state++;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112708);
extern s32 *D_80114D58[];
extern s32 *D_80114C98[];

void func_80112708(GameObject *o)
{
    ((void (*)())func_80022E44)();
    if (o->subState == 0) {
        o->subState++;
        o->unkAC = 1;
        if (GAME_S32Arr[0] == 0x30009)
            o->anim = (void *)D_80114D58[o->unkC & 0x7f][1];
        else
            o->anim = (void *)D_80114C98[((u16 *)&GAME)[0] * 4 + (o->unkC & 0x7f)][1];
        readAnimFrameCount(o);
        playSFXWithNote(0x18, 8);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801127D4);
typedef void (*ObjFn_127D4)(GameObject *);
typedef union { s32 w; struct { u16 a, b; } h; } Stage_127D4;
extern Stage_127D4 GAME_Stage_127D4 asm("GAME");
extern u8 D_8009C305;
extern s32 D_1F8002E0[];
extern s32 D_1F8002D4[];
extern u8 D_80114DA4[];
extern u8 D_80114D68[];
extern ObjFn_127D4 D_801150E0[];
extern ObjFn_127D4 D_801150FC[];
extern ObjFn_127D4 D_80115118[];
extern void freeObjectLayer2(GameObject *);

void func_801127D4(GameObject *o)
{
    s32 ok;
    switch (o->state) {
    case 0:
        o->unk9A = 0;
        if (o->animFrame) {
            o->unk9A = o->animFrame;
            o->animFrame = 0;
            ok = o->unk9A == 1 && D_8009C305 == 2;
            if (!ok) {
                o->state = 3;
                break;
            }
        }
        if ((*(Stage_127D4 *)&GAME).w == 0x30009) {
            o->tpage = 10;
            o->spriteBank = D_1F8002E0[0];
        } else {
            if ((*(Stage_127D4 *)&GAME).h.a == 1 && (*(Stage_127D4 *)&GAME).h.b < 2)
                o->tpage = D_80114DA4[o->unkC & 0x7f];
            else
                {

                register s32 i asm("$3");
                i = o->unkC & 0x7f;
                o->tpage = D_80114D68[(*(Stage_127D4 *)&GAME).h.a * 4 + i];
            }
            o->spriteBank = D_1F8002D4[0];
        }
        o->state++;
        o->unkD = 0;
        o->unk6A = o->unkF;
        o->unk30 = o->h->p.whole;
        o->unk34 = o->y.p.whole;
        o->hitOffsetX = 0x10;
        o->hitWidth = 0x20;
        if (o->unkC == 1) {
            o->hitOffsetY = 0x11;
            o->hitHeight = 0x21;
        } else {
            o->hitOffsetY = 0xd;
            o->hitHeight = 0x1d;
        }
        *(s8 *)&o->unkF = -3;
        o->unkAC = 0;
        if ((*(Stage_127D4 *)&GAME).w == 0x30009)
            o->anim = *D_80114D58[o->unkC & 0x7f];
        else
            o->anim = *D_80114C98[GAME_Stage_127D4.h.a * 4 + (o->unkC & 0x7f)];
        readAnimFrameCount(o);
        D_801150E0[o->subtype](o);
        break;
    case 1:
        D_801150FC[o->subtype](o);
        break;
    case 2:
        D_80115118[o->subtype](o);
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112AA4);
typedef struct O_12AA4 { char p0[3]; u8 st; char p1[0x20]; s32 *anim; char p2[0x74-0x28]; s16 a; s16 b; } O_12AA4;
extern s32 *D_80115140[][4];
extern void advanceAnimFrame(O_12AA4*,s16); void func_80112AA4(O_12AA4 *o){ o->anim = (s32*)((s32**)D_80115140)[o->st * 4][o->a]; advanceAnimFrame(o, o->b); }

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112AEC);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112B0C);
void func_80112B0C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->velX = 0;
        o->velY = 0;
        o->velH = 0;
        o->velV = 0;
        o->step = o->step + 1;
    case 1:
        tickAnimation(o);
        o->y.raw += 0x40000;
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + o->hitHeight - o->hitOffsetY));
        if (--o->timer == 0) {
            o->unk6A = 0;
            o->subState = 0;
            o->step = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112BD8);
void func_80112BD8(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX * 0x100;
        *(volatile s32 *)&o->y.raw += 0x40000;
        if ((*(u16 *)&GAME) == 2) {
            if (o->h->p.whole < 0x2b)
                o->h->p.whole = 0x2b;
            if (o->h->p.whole > 0x130)
                o->h->p.whole = 0x130;
        }
        probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + o->hitHeight - o->hitOffsetY));
        if (--o->timer == 0) {
            o->unk6A = 0;
            o->subState = 0;
            o->step = 0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112D04);
typedef struct V_12D04 { char c[12]; } V_12D04;
typedef struct O_12D04 {
    char p0[5]; u8 f5; u8 state;
    char p1[0x10 - 7]; V_12D04 v;
    char p2[0x20 - 0x1c]; u16 timer;
    char p3[0x6a - 0x22]; char f6a;
    char p4[0x90 - 0x6b]; s32 d90;
} O_12D04;
extern s32 showMessageBoxDirectTimed(s32, s32, V_12D04 *, s32);

void func_80112D04(O_12D04 *o)
{
    V_12D04 v;
    switch (o->state) {
    case 0:
        v = o->v;
        *(u16 *)(v.c + 6) = *(u16 *)(v.c + 6) - 0x40;
        o->d90 = showMessageBoxDirectTimed(13, 2, &v, (s16)o->timer);
        o->state++;
        break;
    case 1:
        tickAnimation(o);
        o->timer--;
        if ((s16)o->timer == 0) {
            o->f6a = 0;
            o->f5 = 0;
            o->state = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112DDC);
typedef struct O_12DDC {
    char pad0[5];
    u8 step;
    u8 state;
    char pad1[0x68 - 7];
    u8 b68;
    char pad2;
    u8 b6a;
    char pad3[0x90 - 0x6b];
    char *d90;
} O_12DDC;
extern s32 D_800A53F4;

void func_80112DDC(O_12DDC *o)
{
    char pad[16];
    switch (o->state) {
    case 0:
        o->b68 = 0;
        o->state++;
    case 1:
        break;
    default:
        return;
    }
    tickAnimation(o);
    if (o->d90[4] == 2) {
        o->d90[4] = 3;
        D_800A539C = 1;
        D_1F8001C6 = 0;
        D_8009BCAA = 0;
        D_800A544A = 0;
        D_800A539D = 0;
        D_800A539E = 0;
        if (D_800A53F4 == 1) {
            D_8009BCA7 = 0;
            D_800A53F4 = 0;
        }
        o->b68 = 0;
        o->b6a = 0;
        o->step = 0;
        o->state = 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80112EBC);
extern void tickAnimation(GameObject *);
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_80112EBC(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->touchFlag = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw = o->h->raw + o->velX * 0x100;
        o->y.raw = o->y.raw + o->velY * 0x100;
        o->velY = o->velY + 0x20;
        if (o->velY > 0) o->step = 2;
        break;
    case 2:
        tickAnimation(o);
        o->h->raw = o->h->raw + o->velX * 0x100;
        o->y.raw = o->y.raw + o->velY * 0x100;
        o->velY = o->velY + 0x20;
        if (o->touchFlag == 0 &&
            probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + (u16)(o->hitHeight - o->hitOffsetY))) == 0)
            return;
        o->unk6A = 0;
        o->subState = 0;
        o->step = 0;
        o->touchFlag = 0;
        break;
    }
}

void func_80113010(void) {
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113018);
extern void tickAnimation(GameObject *);
extern s16 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_80113018(GameObject *o)
{
    switch (o->step) {
    case 0:
        if (o->unk78 > 0)
            o->unk7A = (o->d->p.whole + 90) / 90 * 90;
        else
            o->unk7A = (o->d->p.whole - 90) / 90 * 90;
        o->touchFlag = 0;
        o->step++;
    case 1:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->d->raw += o->unk78 << 8;
        if (o->unk78 > 0) {
            if (o->d->p.whole > o->unk7A)
                o->d->p.whole = o->unk7A;
        } else {
            if (o->d->p.whole < o->unk7A)
                o->d->p.whole = o->unk7A;
        }
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0)
            o->step = 2;
        break;
    case 2:
        tickAnimation(o);
        o->h->raw += o->velX << 8;
        o->d->raw += o->unk78 << 8;
        if (o->unk78 > 0) {
            if (o->d->p.whole > o->unk7A)
                o->d->p.whole = o->unk7A;
        } else {
            if (o->d->p.whole < o->unk7A)
                o->d->p.whole = o->unk7A;
        }
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + (o->hitHeight - o->hitOffsetY)))) {
            o->unk6A = 0;
            o->subState = 0;
            o->step = 0;
            o->touchFlag = 0;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113288);
typedef struct P_13288 { s16 x; s16 y; } P_13288;
typedef struct V_13288 { s16 x, xh, y, yh, z, zh; } V_13288;
typedef struct S_13288 {
    u8 b00, b01, b02, b03, b04, step, state, b07; char p0[0x10 - 8];
    V_13288 pos; char p1[0x20 - 0x1c]; s16 timer; char p2[0x2e - 0x22]; u16 frame; char p3[0x40 - 0x30];
    P_13288 *h; char p4[0x68 - 0x44]; u8 b68, b69, b6a; char p5[0x6c - 0x6b];
    s16 w6c, w6e, w70, w72; char p6[0x7c - 0x74]; s16 velX, velY, velH, velV; char p7[0x90 - 0x84];
    struct S_13288 *p90;
} S_13288;
void func_80113288(S_13288 *o)
{
    V_13288 v;
    s32 f;
    if ((o->b00 & 8) && D_8009BCA2 != 0 && (u16)(o->pos.yh - (*(u16 *)&D_800A53AE) + 0x80) < 0x100) {
        if (o->frame & 1) {
            if (o->h->y - o->w6c < (*(P_13288 **)&D_800A53D8)->y)
                (*(P_13288 **)&D_800A53D8)->y = o->h->y - o->w6c;
        } else {
            if ((*(P_13288 **)&D_800A53D8)->y < o->h->y + (o->w6e - o->w6c))
                (*(P_13288 **)&D_800A53D8)->y = o->h->y + (o->w6e - o->w6c);
        }
    }
    switch (o->step) {
    case 0:
        tickAnimation(o);
        break;
    case 1:
        switch (o->state) {
        case 0:
            o->velX = 0;
            o->velY = 0;
            o->velH = 0;
            o->velV = 0;
            o->state++;
        case 1:
            tickAnimation(o);
            *(s32 *)&o->pos.y += 0x40000;
            probeCollisionAtDepthA(o, o->h->y, (s16)(o->pos.yh + o->w72 - o->w70));
            if (--o->timer == 0) {
                o->b6a = 0;
                goto reset;
            }
            break;
        }
        break;
    case 2:
        func_80112BD8(o);
        break;
    case 3:
        if (o->b01 == 0)
            break;
        switch (o->state) {
        case 0:
            v = o->pos;
            v.yh -= 0x40;
            o->p90 = showMessageBoxDirectTimed(0xd, 2, &v, o->timer);
            o->state++;
            break;
        case 1:
            tickAnimation(o);
            if (--o->timer == 0) {
                o->b6a = 0;
                goto reset;
            }
            break;
        }
        break;
    case 4:
        switch (o->state) {
        case 0:
            o->b68 = 0;
            o->state++;
        case 1:
            tickAnimation(o);
            if (o->p90->b04 == 2) {
                o->p90->b04 = 3;
                f = D_800A53F4;
                D_800A539C = 1;
                *(s16 *)0x1F8001C6 = 0;
                D_8009BCAA = 0;
                D_800A544A = 0;
                D_800A539D = 0;
                D_800A539E = 0;
                if (f == 1) {
                    D_8009BCA7 = 0;
                    D_800A53F4 = 0;
                }
                o->b68 = 0;
                o->b6a = 0;
            reset:
                o->step = 0;
                o->state = 0;
            }
            break;
        }
        break;
    case 5:
        func_80112EBC(o);
        break;
    case 7:
        func_80113018(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113610);
typedef struct { s16 s[6]; } P6_13610;
extern u8 *D_8009B698;
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A5401;
extern s16 D_800A5414;

void func_80113610(GameObject *o)
{
    P6_13610 pos;
    u16 *p;
    switch (o->step) {
    case 0:
        o->timer = 60;
        o->step++;
    case 1:
        if (--o->timer > 0) break;
        o->timer = 0;
        pos = *(P6_13610 *)&o->x;
        p = &(*(u16 *)&GAME);
        if (*p == 2) pos.s[1] -= 0x50;
        pos.s[3] -= 0x20;
        o->unk68 = 0;
        o->unk6A = 1;
        if (*p == 2) {
            switch (D_8009C119) {
            case 1: o->unk90 = showMessageBoxDirectTimed(2, 0, &pos, 0x78); break;
            case 2: o->unk90 = showMessageBoxDirectTimed(2, 1, &pos, 0x78); break;
            case 3: o->unk90 = showMessageBoxDirectTimed(2, 1, &pos, 0x78); break;
            case 4: o->unk90 = showMessageBoxDirectTimed(2, 2, &pos, 0x78); break;
            }
        } else {
            switch (D_8009C119) {
            case 1: o->unk90 = showMessageBoxDirectTimed(2, 0, &pos, 0x78); break;
            case 2: o->unk90 = showMessageBoxDirectTimed(2, 1, &pos, 0x78); break;
            case 3: o->unk90 = showMessageBoxDirectTimed(2, 1, &pos, 0x78); break;
            case 4: o->unk90 = showMessageBoxDirectTimed(2, 2, &pos, 0x78); break;
            }
        }
        D_800A539C_U8Arr[0] = 6;
        D_800A539C_U8Arr[1] = 5;
        D_800A539C_U8Arr[2] = 0;
        D_8009B698[9] = 10;
        if ((*(s32 *)&GAME) == 0x10002) {
            D_800A53C6 = 1;
            D_800A5414 = 0xc0;
        } else {
            D_800A53C6 = 0;
            D_800A5414 = -0xc0;
        }
        D_800A5401 = 0;
        o->step++;
        break;
    case 2:
        if ((*(u16 *)&GAME) == 1) o->h->p.whole += 4;
        else if ((*(u16 *)&GAME) == 2) o->h->p.whole -= 4;
        o->y.raw += 0x80000;
        ((void (*)(GameObject *o, s16 x, s16 y))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + o->hitHeight - o->hitOffsetY);
        tickAnimation(o);
        if (D_800A5401) {
            if ((*(u16 *)&GAME) == 2) {
                if (D_8009C119 == 4) printInfoMessage(8, 3);
            } else if (D_8009C119 != 0xff) {
                printInfoMessage(D_8009C119 + 7, 2);
            }
            o->unk6A = 0;
            SCRIPT_OBJECTS[o->unkC] = 0;
            D_800A539C_U8Arr[0] = 1;
            D_800A539C_U8Arr[1] = 0;
            D_800A539C_U8Arr[2] = 0;
            o->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801139AC);
extern void func_80113610(GameObject *o);
void func_801139AC(GameObject *o)
{
    if (o->subState == 0) func_80113610(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_801139DC);
typedef struct {
    u16 b0, b1, b2, b3, w1e;
    s16 idx;
    void **tab;
} Ent5de4_139DC;
extern Ent5de4_139DC D_80115134[];
extern void freeObjectLayer2(GameObject *);

void func_801139DC(GameObject *o)
{
    char pad[16];

    switch (o->state) {
    case 0:
        o->hitOffsetX = D_80115134[o->subtype].b0;
        o->hitWidth = D_80115134[o->subtype].b1;
        o->hitOffsetY = D_80115134[o->subtype].b2;
        o->hitHeight = D_80115134[o->subtype].b3;
        o->tpage = D_80115134[o->subtype].w1e;
        o->spriteBank = SPR_DATA[D_80115134[o->subtype].idx];
        o->anim = D_80115134[o->subtype].tab[o->unk74];
        advanceAnimFrame(o, o->unk76);
        o->unkA = 2;
        o->unk8C = 0;
        o->unkD = 0;
        switch (o->subtype) {
        case 9:
            o->unkD = 1;
            o->clut = 0x7fc8;
            o->unkA = 0;
            break;
        case 10:
            o->unkD = 1;
            o->clut = 0x7809;
            break;
        }
        o->category |= 0x80;
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        func_80113288(o);
        break;
    case 2:
        func_80022E44(o);
        if (o->subState == 0)
            func_80113610(o);
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113BE0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113C20);
extern char *allocObjectLayer2(void);
typedef struct N_13C20 { char t, p1, k, b; char pad[0x10]; s32 y; char pad2[0x28]; s32 *x; s32 *z; char pad3[0x48]; s32 a; } N_13C20;
void func_80113C20(s32 a, char b, s32 c, s32 d, s16 e)
{
    N_13C20 *n = (N_13C20 *)allocObjectLayer2();
    if (n != 0) {
        n->t = 1; n->k = 0x1f; n->b = b; *n->x = c << 16; n->y = d << 16; *n->z = e << 16; n->a = a;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113CB8);
extern char *allocObjectLayer2(void);
extern u8 D_8009BCC1;

void func_80113CB8(s32 unused, char sub, s32 x, s32 y, s32 z)
{
    char *p = allocObjectLayer2();
    if (p != 0) {
        p[0] = 1;
        p[2] = 0x1f;
        p[3] = sub;
        **(s32 **)(p + 0x40) = x << 16;
        *(s32 *)(p + 0x14) = y << 16;
        **(s32 **)(p + 0x44) = z << 16;
        { u8 *c = &D_8009BCC1; *c = *c + 1; }
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/engine_3", func_80113D58);
