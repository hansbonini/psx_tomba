#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"
#include "gte_local.h"

void SetGeomScreen(long h) {
    gte_SetGeomScreen(h);
}

__asm__("nop");

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", LightColor);

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", DpqColorLight);

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", DpqColor3);

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", Intpl);

VECTOR* Square12(VECTOR* v0, VECTOR* v1) {
    /* Without the pin GCC copies v1 to $v0 up front and stores through it. */
    register VECTOR* out asm("$5") = v1;

    gte_ldlvl(v0);
    gte_sqr12_b();
    gte_stlvnl(out);
    return out;
}

VECTOR* Square0(VECTOR* v0, VECTOR* v1) {
    /* Without the pin GCC copies v1 to $v0 up front and stores through it. */
    register VECTOR* out asm("$5") = v1;

    gte_ldlvl(v0);
    gte_sqr0_b();
    gte_stlvnl(out);
    return out;
}

long AverageZ3(long sz0, long sz1, long sz2) {
    long otz;

    gte_ldsz3(sz0, sz1, sz2);
    gte_avsz3_b();
    gte_read_otz(otz);
    return otz;
}

long AverageZ4(long sz0, long sz1, long sz2, long sz3) {
    long otz;

    gte_ldsz4(sz0, sz1, sz2, sz3);
    gte_avsz4_b();
    gte_read_otz(otz);
    return otz;
}

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", OuterProduct12);

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", OuterProduct0);

long Lzc(long data) {
    long count;

    gte_ldlzc(data);
    __asm__ volatile("nop; nop");
    gte_read_lzcr(count);
    return count;
}

__asm__("nop");

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", RotTransPers);

INCLUDE_ASM("nonmatchings/psyq/libgte/reg13", RotMatrix);
