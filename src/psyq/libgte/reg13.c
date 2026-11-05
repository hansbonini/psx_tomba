#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"
#include "gte_local.h"

/**
 * @brief Set the projection plane distance
 * 
 * Sets the distance between the viewpoint and the screen (GTE register H),
 * which controls the field of view.
 * 
 * @param h Projection distance
 */
void SetGeomScreen(long h) {
    gte_SetGeomScreen(h);
}

__asm__("nop");

/**
 * @brief Apply the light color matrix to a vector
 * 
 * Multiplies v0 by the GTE light color matrix and adds the back color.
 * 
 * @param v0 Input light intensity vector
 * @param v1 Receives the resulting color vector
 */
void LightColor(VECTOR* v0, VECTOR* v1) {
    gte_ldlvl(v0);
    gte_lcir_b();
    gte_stlvl(v1);
}

/**
 * @brief Combine a light vector with a color and apply depth cueing
 * 
 * Multiplies the color v1 by the light vector v0 and interpolates the
 * result towards the far color by p.
 * 
 * @param v0 Light intensity vector
 * @param v1 Base color
 * @param p Interpolation factor (0-4096)
 * @param v2 Receives the resulting color
 */
void DpqColorLight(VECTOR* v0, CVECTOR* v1, long p, CVECTOR* v2) {
    gte_ldlvl(v0);
    gte_ldrgb_dp(v1, p);
    gte_dpcl_b();
    gte_strgb(v2);
}

/**
 * @brief Apply depth cueing to three colors
 * 
 * Interpolates each of the three colors towards the far color by p.
 * 
 * @param v0 First input color
 * @param v1 Second input color
 * @param v2 Third input color
 * @param p Interpolation factor (0-4096)
 * @param v3 Receives the first result
 * @param v4 Receives the second result
 * @param v5 Receives the third result
 */
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

/**
 * @brief Interpolate a vector towards the far color
 * 
 * Interpolates v0 towards the far color by p and stores the color result.
 * 
 * @param v0 Input vector
 * @param p Interpolation factor (0-4096)
 * @param v1 Receives the resulting color
 */
void Intpl(VECTOR* v0, long p, CVECTOR* v1) {
    gte_ldlvl(v0);
    gte_lddp(p);
    gte_intpl_b();
    gte_strgb(v1);
}

/**
 * @brief Square each component of a vector (fixed point)
 * 
 * Squares the components of v0 and shifts the results right by 12 bits.
 * 
 * @param v0 Input vector
 * @param v1 Receives the result
 * @return v1
 */
VECTOR* Square12(VECTOR* v0, VECTOR* v1) {
    /* Without the pin GCC copies v1 to $v0 up front and stores through it. */
    register VECTOR* out asm("$5") = v1;

    gte_ldlvl(v0);
    gte_sqr12_b();
    gte_stlvnl(out);
    return out;
}

/**
 * @brief Square each component of a vector (integer)
 * 
 * Squares the components of v0 without shifting.
 * 
 * @param v0 Input vector
 * @param v1 Receives the result
 * @return v1
 */
VECTOR* Square0(VECTOR* v0, VECTOR* v1) {
    /* Without the pin GCC copies v1 to $v0 up front and stores through it. */
    register VECTOR* out asm("$5") = v1;

    gte_ldlvl(v0);
    gte_sqr0_b();
    gte_stlvnl(out);
    return out;
}

/**
 * @brief Average three Z values
 * 
 * Uses the GTE to compute the scaled average of three screen Z values, as
 * used for ordering table indexes.
 * 
 * @param sz0 First Z value
 * @param sz1 Second Z value
 * @param sz2 Third Z value
 * @return Scaled average Z (OTZ)
 */
long AverageZ3(long sz0, long sz1, long sz2) {
    long otz;

    gte_ldsz3(sz0, sz1, sz2);
    gte_avsz3_b();
    gte_read_otz(otz);
    return otz;
}

/**
 * @brief Average four Z values
 * 
 * Uses the GTE to compute the scaled average of four screen Z values, as
 * used for ordering table indexes.
 * 
 * @param sz0 First Z value
 * @param sz1 Second Z value
 * @param sz2 Third Z value
 * @param sz3 Fourth Z value
 * @return Scaled average Z (OTZ)
 */
long AverageZ4(long sz0, long sz1, long sz2, long sz3) {
    long otz;

    gte_ldsz4(sz0, sz1, sz2, sz3);
    gte_avsz4_b();
    gte_read_otz(otz);
    return otz;
}

/**
 * @brief Cross product of two vectors (fixed point)
 * 
 * Computes v0 x v1 with the GTE and shifts the result right by 12 bits.
 * 
 * @param v0 First vector
 * @param v1 Second vector
 * @param v2 Receives the result
 */
void OuterProduct12(VECTOR* v0, VECTOR* v1, VECTOR* v2) {
    gte_OuterProduct_t(v0, v1, v2, 1);
}

/**
 * @brief Cross product of two vectors (integer)
 * 
 * Computes v0 x v1 with the GTE without shifting.
 * 
 * @param v0 First vector
 * @param v1 Second vector
 * @param v2 Receives the result
 */
void OuterProduct0(VECTOR* v0, VECTOR* v1, VECTOR* v2) {
    gte_OuterProduct_t(v0, v1, v2, 0);
}

/**
 * @brief Count leading zero (or one) bits
 * 
 * Uses the GTE to count the leading bits equal to the sign bit.
 * 
 * @param data Value to analyze
 * @return Number of leading bits
 */
long Lzc(long data) {
    long count;

    gte_ldlzc(data);
    __asm__ volatile("nop; nop");
    gte_read_lzcr(count);
    return count;
}

__asm__("nop");

/**
 * @brief Rotate, translate and perspective-project a vertex
 * 
 * Transforms v0 with the current rotation matrix and translation vector
 * and projects it to screen coordinates.
 * 
 * @param v0 Vertex to transform
 * @param sxy Receives the packed screen coordinates
 * @param p Receives the depth cue interpolation factor
 * @param flag Receives the GTE error flags
 * @return Screen Z divided by 4 (for use as an ordering table index)
 */
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

/**
 * @brief Build a rotation matrix from Euler angles
 * 
 * Computes the rotation matrix for the angles in r (applied in X, Y, Z
 * order) and stores it in m.
 * 
 * @param r Rotation angles (4096 = 360 degrees)
 * @param m Receives the rotation matrix
 * @return m
 */
MATRIX* RotMatrix(SVECTOR* r, MATRIX* m) {
    register MATRIX* ret asm("$2");

    gte_RotMatrix_t(r, m, ret);
    return ret;
}

__asm__("nop");
