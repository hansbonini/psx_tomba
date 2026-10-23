#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"
#include "gte_local.h"

void SetGeomScreen(long h) {
    gte_SetGeomScreen(h);
}

__asm__("nop");

void LightColor(VECTOR* v0, VECTOR* v1) {
    gte_ldlvl(v0);
    gte_lcir_b();
    gte_stlvl(v1);
}

void DpqColorLight(VECTOR* v0, CVECTOR* v1, long p, CVECTOR* v2) {
    gte_ldlvl(v0);
    gte_ldrgb_dp(v1, p);
    gte_dpcl_b();
    gte_strgb(v2);
}

void DpqColor3(CVECTOR* v0, CVECTOR* v1, CVECTOR* v2, long p, CVECTOR* volatile v3, CVECTOR* volatile v4,
               CVECTOR* volatile v5) {
    gte_ldrgb3(v0, v1, v2);
    gte_lddp(p);
    gte_dpct_b();
    {
        register CVECTOR* r0 asm("$8") = v3;
        register CVECTOR* r1 asm("$9") = v4;
        register CVECTOR* r2 asm("$10") = v5;

        gte_strgb3(r0, r1, r2);
    }
}

void Intpl(VECTOR* v0, long p, CVECTOR* v1) {
    gte_ldlvl(v0);
    gte_lddp(p);
    gte_intpl_b();
    gte_strgb(v1);
}

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

void OuterProduct12(VECTOR* v0, VECTOR* v1, VECTOR* v2) {
    gte_OuterProduct_t(v0, v1, v2, 1);
}

void OuterProduct0(VECTOR* v0, VECTOR* v1, VECTOR* v2) {
    gte_OuterProduct_t(v0, v1, v2, 0);
}

long Lzc(long data) {
    long count;

    gte_ldlzc(data);
    __asm__ volatile("nop; nop");
    gte_read_lzcr(count);
    return count;
}

__asm__("nop");

long RotTransPers(SVECTOR* v0, long* sxy, long* p, long* flag) {
    long f;
    long sz;

    gte_ldv0(v0);
    gte_rtps_b();
    gte_stsxy(sxy);
    gte_stdp(p);
    gte_read_flag(f);
    gte_read_sz3(sz);
    *flag = f;
    return sz >> 2;
}

__asm__("nop");

MATRIX* RotMatrix(SVECTOR* r, MATRIX* m) {
    register MATRIX* ret asm("$2");

    gte_RotMatrix_t(r, m, ret);
    return ret;
}

__asm__("nop");
