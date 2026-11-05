#include "common.h"
#include "psyq/libgte.h"
#include "gte_local.h"

/**
 * @brief Set the GTE rotation matrix
 * 
 * Loads the 3x3 part of m into the GTE rotation matrix registers.
 * 
 * @param m Matrix to load
 */
void SetRotMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 0, 1, 2, 3, 4);
}

/**
 * @brief Set the GTE light source matrix
 * 
 * Loads the 3x3 part of m into the GTE light matrix registers.
 * 
 * @param m Matrix holding the light direction vectors
 */
void SetLightMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 8, 9, 10, 11, 12);
}

/**
 * @brief Set the GTE light color matrix
 * 
 * Loads the 3x3 part of m into the GTE light color matrix registers.
 * 
 * @param m Matrix holding the light colors
 */
void SetColorMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 16, 17, 18, 19, 20);
}
