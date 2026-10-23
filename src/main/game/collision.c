#include "common.h"
#include "game.h"

INCLUDE_ASM("nonmatchings/main/game/collision", func_8004339C);

// INCLUDE_ASM("nonmatchings/main/game/collision", probeCollisionAtDepthA);
s16 probeCollisionAtDepthA(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_8004339C(self, arg1, arg2);
}

INCLUDE_ASM("nonmatchings/main/game/collision", func_80043740);

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80043AB0);
typedef struct {
    char pad[0x44];
    s16 *p44;
} O8004065C_43AB0;
extern s16 func_80043740(O8004065C_43AB0 *, s32, s32, s16);

s16 func_80043AB0(O8004065C_43AB0 *o, s16 a, s16 b, s32 c)
{
    SPAD->unk278 = getCollisionPlaneAt(a, o->p44[1]);
    return func_80043740(o, a, b, (c & 1) | 0xff00);
}

INCLUDE_ASM("nonmatchings/main/game/collision", func_80043B3C);

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80043D2C);
s16 func_80043D2C(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80043B3C(self, arg1, arg2);
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80043DA0);
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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80043F14);
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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80044050);
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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80044184);
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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_800442FC);
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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_800443CC);

static __inline__ s32 inr_443CC(s16 m, s16 lo, s16 hi)
{
    if (m < lo || lo + hi < m) return 0;
    return 1;
}
s32 func_800443CC(void *o, s32 x, s32 y)
{
    s16 n, m;
    register s32 r asm("$4");
    u16 w, a, c;
    s32 lo, hi;
    u16 s;
    n = *(s16 *)D_1F800278++;
    if (n == 0)
        return 0;
    do {
        w = *D_1F800278++;
        n--;
        if ((w & 0x1f) == 0) {
            D_1F800278 += 3;
            continue;
        }
        r = 0;
        if (w & 0x10) {
            D_1F800284 = (w & 0xe00) >> 9;
            a = *D_1F800278++;
            r = *D_1F800278++;
            c = *D_1F800278++;
            lo = c & 0xf;
            hi = (c >> 4) & 0xf;
            s = a + r;
            if ((s16)a >= (s16)y && (s16)y >= (s16)s)
                r = inr_443CC((s16)x % 8, lo, hi);
            else
                r = 0;
        } else {
            D_1F800284 = (w & 0xe00) >> 9;
            switch (w & 0xf) {
            case 1: r = func_80043DA0((s16)x, (s16)y); break;
            case 2: r = func_80044184((s16)x, (s16)y); break;
            case 4: r = func_80043F14((s16)x, (s16)y); break;
            case 8: r = func_80044050((s16)x, (s16)y); break;
            }
        }
        if (r) {
            D_1F800282 = w;
            return 1;
        }
    } while (n);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/collision", probeCollisionAtDepthB);
s16 probeCollisionAtDepthB(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_800443CC(self, arg1, arg2);
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80044694);

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

// INCLUDE_ASM("nonmatchings/main/game/collision", func_800448D4);
s32 func_800448D4(GameObject *o, s16 x, s16 y)
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

    p = getCollisionPlaneAt((s16)x, o->d->p.whole);
    D_1F800278 = (u16 *)(p + 1);
    n = *p;
    if (n == 0) return 0;
    cnt = 0;
    ys = (s16)y;
    xm = x & 7;
    while (n != 0) {
        a = *D_1F800278++;
        n--;
        if ((a & 0xc) == 0 || (a & 0x10)) {
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

INCLUDE_ASM("nonmatchings/main/game/collision", func_80044B0C);

// INCLUDE_ASM("nonmatchings/main/game/collision", func_800450FC);
s16 func_800450FC(u8* self, s16 arg1, s16 arg2)
{
    D_1F800278 = getCollisionPlaneAt(arg1, *(s16*)(*(u8**)(self + 0x44) + 2));
    return func_80044B0C(self, arg1, arg2, -1);
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80045174);
extern s32 angleFromDelta(s32, s32);

s32 func_80045174(GameObject *o, s16 a, s32 b)
{
    char pad[8];
    s16 *p;
    u16 *q;
    u16 f;
    s32 n, cnt, x, w, d, e;
    u32 k;
    s16 s;
    s16 ws;
    u16 t3;
    p = getCollisionPlaneAt(a, o->d->p.whole);
    D_1F800278 = (u16 *)(p + 1);
    n = cnt = *p;
    goto test;
top:
    q = D_1F800278;
    D_1F800278 = q + 1;
    f = *q;
    cnt--;
    if (f & 0x4000) {
        if (!(f & 0x10)) goto hit;
    }
    D_1F800278 = q + 4;
    goto next;
hit:
    x = *D_1F800278++;
    w = *D_1F800278++;
    D_1F800278++;
    ws = w;
    t3 = *(u16 *)((char *)q + 6);
    if (ws == 0) goto next;
    k = (t3 >> 4) & 0xf;
    d = b - x - w;
    if (((d - 1) & 0xffff) > -ws) {
        if (d << 16 > 0) return 0;
        goto next;
    }
    s = angleFromDelta(k, ws);
    D_1F80027C = s;
    if (s < 0x40) {
        D_1F80027C = s + 0xc0;
    } else if (s > 0xc0) {
        D_1F80027C = s - 0xc0;
    }
    e = x + 8;
    if (((b - e - w - 1) & 0xffff) > -(s16)w) return 2;
    return 1;
next:
    n = cnt << 16;
test:
    if (n != 0) goto top;
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80045310);
typedef struct O_45310 { char p[0x44]; s16 *q; } O_45310;
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
            D_1F800282_S16 = flags;
            D_1F800284 = (flags & 0xe00) >> 9;
            return 1;
        }
    } while (n != 0);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80045570);
static __inline__ s32 check_45570(GameObject *o, s16 a, s16 b)
{
    s16 *q;
    s32 nn;
    s32 n;
    u32 v;
    s32 t;
    s16 h;
    s16 m;
    s32 y0;
    s16 lo;
    s32 ys;

    q = getCollisionPlaneAt(a, o->d->p.whole);
    D_1F800278 = (u16 *)(q + 1);
    nn = *q;
    n = nn;
    if (nn == 0) return 0;
    do {
        t = *D_1F800278++;
        n--;
        if (t & 2) {
            if (!(t & 0x10)) goto take;
        }
        D_1F800278 += 3;
        continue;
take:
        ys = (s16)*D_1F800278++;
        y0 = ys;
        ys -= 16;
        if (b < ys) return 0;
        h = *D_1F800278++;
        if (h == 0) {
            D_1F800278++;
            t = y0;
        } else {
            v = *D_1F800278++;
            lo = v & 0xf;
            v >>= 4;
            t = v & 0xf;
            if (t == 0) continue;
            m = a % 8;
            if (m < lo) continue;
            if (lo + t < m) continue;
            t = y0 + h * ((a - lo) % t) / t;
        }
        if ((s16)(t - b) >= 0) return 1;
    } while ((s16)n != 0);
    lo = ys; t = nn;
    return 0;
}

s32 func_80045570(GameObject *o, s16 a, s32 b)
{
    char pad[0x18];
    return check_45570(o, a, b);
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_80045780);
s32 func_80045780(s16 a, s32 b, s16 c)
{
    s16 *q;
    s32 nn;
    s32 empty;
    s32 n;
    u16 f, y, h;
    s32 d;
    char pad[8];

    q = getCollisionPlaneAt(a, c);
    D_1F800278 = (u16 *)(q + 1);
    nn = *q;
    empty = nn == 0;
    n = nn;
    if (empty) return 0;
    do {
        f = *D_1F800278++;
        n--;
        if (f & 0x4000) {
            if (f & 0x10) goto take;
        }
        D_1F800278 += 3;
        continue;
take:
        y = *D_1F800278++;
        h = *D_1F800278++;
        D_1F800278++;
        d = b - y - h;
        if ((u16)(d - 1) > -(s16)h) {
            if ((s16)d > 0) return 0;
            continue;
        }
        y += 8;
        if ((u16)(b - y - h - 1) > -(s16)h) return 2;
        return 1;
    } while ((s16)n != 0);
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/collision", func_800458B0);
s32 func_800458B0(s16 a, s32 b, s16 c)
{
    s16 *q;
    s32 nn;
    s32 empty;
    s32 n;
    u16 f, y, h;
    s32 d;
    char pad[8];

    q = getCollisionPlaneAt(a, c);
    D_1F800278 = (u16 *)(q + 1);
    nn = *q;
    empty = nn == 0;
    n = nn;
    if (empty) return 0;
    do {
        f = *D_1F800278++;
        n--;
        if (f & 0x4000) {
            if (f & 0x10) goto take;
        }
        D_1F800278 += 3;
        continue;
take:
        y = *D_1F800278++;
        h = *D_1F800278++;
        D_1F800278++;
        d = b - y - h;
        if ((u16)(d - 1) > -(s16)h) {
            if ((s16)d > 0) return 0;
            continue;
        }
        y += 8;
        if ((u16)(b - y - h - 1) > -(s16)h) return 2;
        return 1;
    } while ((s16)n != 0);
    return 0;
}
