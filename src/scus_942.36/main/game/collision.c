#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_8004339C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", probeCollisionAtDepthA);
s16 probeCollisionAtDepthA(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_8004339C(self, arg1, arg2);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043740);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043AB0);
typedef struct {
    char pad[0x44];
    s16 *p44;
} O8004065C_43AB0;
extern s16 func_80043740(O8004065C_43AB0 *, s32, s32, s16);

s16 func_80043AB0(O8004065C_43AB0 *o, s16 a, s16 b, s32 c)
{
    *(s32 *)0x1F800278 = getCollisionPlaneAt(a, o->p44[1]);
    return func_80043740(o, a, b, (c & 1) | 0xff00);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043B3C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043D2C);
s16 func_80043D2C(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80043B3C(self, arg1, arg2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043DA0);

s32 func_80043DA0(s32 x, s32 y)
{
    s32 base;
    s16 amp;
    u16 v;
    s32 r; s16 n, lo;

    base = *D_1F800278++;
    if ((u16)(y - base + 16) > 32) {
        D_1F800278 += 2;
        return 0;
    }
    amp = *D_1F800278++;
    if (amp == 0) {
        D_1F800278++;
        x = base;
    } else {
        v = *D_1F800278++;
        lo = v & 0xf;
        n = (v >> 4) & 0xf;
        if (n == 0) return 0;
        x = (s16)x;
        r = (s16)(x % 8);
        if (r < lo) return 0;
        if (lo + n < r) return 0;
        x = base + amp * ((x - lo) % n) / n;
    }
    return (s16)x - (s16)y < 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80043F14);

u32 func_80043F14(s32 u, s32 a)
{
    u16 x;
    u16 w;
    u16 m;
    s32 lo;
    s32 hi;
    s16 sw;
    u16 t;
    u16 v;
    u8 cu;
    s16 cl;
    u8 ch;
    x = *D_1F800278++;
    w = *D_1F800278++;
    m = *D_1F800278++;
    lo = m & 0xf;
    hi = (m >> 4) & 0xf;
    sw = w;
    if (sw == 0) return 0;
    if ((s16)a > (s16)x + 0x10) return 0;
    if ((s32)(u16)(a - x - w - 1) > -sw) return 0;
    u &= 7;
    v = u;
    cu = u;
    cl = lo;
    t = 0;
    if (cu < cl) return 0;
    ch = hi;
    if (cl + ch < cu) {
        t = u - (lo + hi);
        v = lo + hi;
    }
    return (s16)(t + (v - lo - ch * ((s16)a - (s16)x) / sw)) >= 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044050);

s32 func_80044050(s32 u, s32 a)
{
    u16 x, w, m;
    s16 sw;
    s32 sx, sa;
    s16 lo, hi; s16 s;
    s16 k; s16 t2; s16 u2, lo2, hi2;
    x = *D_1F800278++;
    w = *D_1F800278++;
    m = *D_1F800278++;
    lo = m & 0xf;
    hi = (m >> 4) & 0xf;
    sw = w;
    s = lo;
    if (sw == 0) goto ret0;
    sa = (s16)a;
    sx = (s16)x;
    if (sx + 0x10 < sa) return 0;
    if ((u16)(a - x - w - 1) > -sw) return 0;
    u &= 7;
    k = u;
    u2 = u;
    lo2 = lo;
    hi2 = hi;
    t2 = 0;
    if (u2 > lo2 + hi2) {
ret0:
        return 0;
    }
    if (u2 < lo2) {
        t2 = lo - u;
        k = s;
    }
    return (s16)(k - lo - hi2 * (sa - sx) / sw - t2) <= 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044184);

s32 func_80044184(s32 x, s32 y)
{
    s32 h;
    u16 w;
    s16 k, m;
    s16 lo, n;
    h = *D_1F800278++;
    if ((u16)(y - h + 0x10) > 0x20) {
        D_1F800278 += 2;
        return 0;
    }
    k = *(s16 *)D_1F800278++;
    if (k == 0) {
        D_1F800278++;
        x = h;
    } else {
        w = *D_1F800278++;
        lo = w & 0xf;
        n = (w >> 4) & 0xf;
        if (n == 0) return 0;
        x = (s16)x;
        m = x % 8;
        if (m < lo) return 0;
        if (lo + n < m) return 0;
        x = h + k * ((x - lo) % n) / n;
    }
    return (s16)x - (s16)y >= 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800442FC);
static __inline__ s16 inrange_442FC(s16 m, char lo, s32 w)
{
    if (m < lo) return 0;
    if (lo + w < m) return 0;
    return 1;
}
s32 func_800442FC(s32 x, s16 y)
{
    u16 a, b, c;
    s32 lo, w, e;
    a = *D_1F800278++;
    b = *D_1F800278++;
    c = *D_1F800278++;
    lo = c & 0xf;
    w = (c >> 4) & 0xf;
    e = b + a;
    if ((s16)a >= y && y >= (s16)e) {
        return inrange_442FC((s16)x % 8, lo, w);
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800443CC);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", probeCollisionAtDepthB);
s16 probeCollisionAtDepthB(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_800443CC(self, arg1, arg2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044694);
extern u16 D_1F800284;

typedef struct O_44694 { char pad[0x44]; s16 *h; } O_44694;

s32 func_80044694(O_44694 *o, s16 x, s16 y)
{
    s16 *p;
    s16 n;
    s32 cnt;
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    s32 lo;
    s32 hi;
    s32 cs;
    s16 k;
    s16 r;
    s16 cc;
    char xm;
    s32 ys;

    p = getCollisionPlaneAt((s16)x, o->h[1]);
    D_1F800278 = (u16 *)(p + 1);
    n = *p;
    if (n == 0) return 0;
    cnt = 0;
    ys = (s16)y;
    xm = x & 7;
    while (n != 0) {
        a = *D_1F800278++;
        n--;
        if ((a & 0xc) == 0) {
            D_1F800278 += 3;
            cnt++;
            continue;
        }
        b = *D_1F800278++;
        c = *(volatile u16 *)D_1F800278++;
        cs = (s16)c;
        d = *D_1F800278++;
        if (cs == 0) continue;
        lo = d & 0xf;
        hi = (d >> 4) & 0xf;
        if (cnt != 0 && (s16)b + 0x10 < ys) break;
        cnt++;
        k = y - b;
        cc = cs;
        if (cc < 0) {
            if (k < cc) continue;
            if (k > 0) return 0;
        } else {
            if (cs < k) break;
            if (k < 0) continue;
        }
        D_1F800284 = (a & 0xe00) >> 9;
        if (a & 0x10) {
            if (a & 4) return 1;
            return (a >> 2) & 2;
        }
        r = xm - lo - hi * (ys - (s16)b) / (s16)c;
        if (a & 4) return r >= 0;
        if (a & 8) return (r < 1) << 1;
    }
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800448D4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80044B0C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800450FC);
s16 func_800450FC(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80044B0C(self, arg1, arg2, -1);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045174);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045310);
typedef struct O_45310 { char p[0x44]; s16 *q; } O_45310;
extern s16 D_1F800280;
extern s16 D_1F800282;
s32 func_80045310(O_45310 *o, s16 a, s16 b)
{
    s16 n;
    s32 cnt;
    u16 flags, w;
    s32 h;
    s16 k, lo, nn, m;
    s32 x;
    char pad[8];
    D_1F800278 = getCollisionPlaneAt(a, o->q[1]);
    n = *(s16 *)D_1F800278++;
    if (n == 0) return 0;
    cnt = 0;
    do {
        flags = *D_1F800278++;
        n--;
        if (flags & 0x10) {
            D_1F800278 += 3;
            continue;
        }
        if (!(flags & 1)) {
            D_1F800278 += 3;
            cnt++;
            continue;
        }
        h = *D_1F800278++;
        if (cnt != 0 && (s16)h + 0x10 < (s16)b) return 0;
        k = *(s16 *)D_1F800278++;
        cnt++;
        if (k == 0) {
            x = h;
            D_1F800278++;
        } else {
            w = *D_1F800278++;
            lo = w & 0xf;
            nn = (w >> 4) & 0xf;
            if (nn == 0) continue;
            m = a % 8;
            if (m < lo) continue;
            if (lo + nn < m) continue;
            x = h + k * ((a - lo) % nn) / nn;
        }
        if ((s16)(x - b) <= 0) {
            D_1F80027E = k;
            D_1F800280 = h;
            D_1F800282 = flags;
            D_1F800284 = (flags & 0xe00) >> 9;
            return 1;
        }
    } while (n != 0);
    return 0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045570);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_80045780);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/collision", func_800458B0);
