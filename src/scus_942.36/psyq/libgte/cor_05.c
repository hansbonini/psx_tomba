#include "common.h"

long Lzc(long a);

long csqrt_1(long a)
{
    long x[8];
    long y[8];
    long yt;
    long xt;
    long x1;
    long x2;
    int i;

    x[1] = a + 0x5D50AD;
    y[1] = a - 0x5D50AD;
    for (i = 1; i < 7; i++) {
        if (i != 4) {
            if (y[i] >= 0) {
                x[i + 1] = x[i] - (y[i] >> i);
                y[i + 1] = y[i] - (x[i] >> i);
            } else {
                x[i + 1] = x[i] + (y[i] >> i);
                y[i + 1] = y[i] + (x[i] >> i);
            }
        } else if ((yt = y[4]) >= 0) {
            xt = x[4];
            x1 = xt - (yt >> 4);
            xt = yt - (xt >> 4);
            x[4] = x1;
            y[4] = xt;
            if (xt >= 0) {
                x[5] = x1 - (xt >> 4);
                y[5] = xt - (x1 >> 4);
            } else {
                x[5] = x1 + (xt >> 4);
                y[5] = xt + (x1 >> 4);
            }
        } else {
            xt = x[4];
            x2 = xt + (yt >> 4);
            xt = yt + (xt >> 4);
            x[4] = x2;
            y[4] = xt;
            if (xt >= 0) {
                x[5] = x2 - (xt >> 4);
                y[5] = xt - (x2 >> 4);
            } else {
                x[5] = x2 + (xt >> 4);
                y[5] = xt + (x2 >> 4);
            }
        }
    }
    return x[7];
}

long csqrt(long a)
{
    int e;
    int n;
    long x;

    if (a == 0) {
        return 0;
    }
    n = 8 - Lzc(a);
    if (n >= 0) {
        e = n >> 1;
        x = a >> (e * 2);
    } else {
        e = (n >> 1) + 1;
        x = a << -(e * 2);
    }
    e -= 6;
    if (e >= 0) {
        return csqrt_1(x) << e;
    } else {
        return csqrt_1(x) >> -e;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/cor_05", func_80063294);
