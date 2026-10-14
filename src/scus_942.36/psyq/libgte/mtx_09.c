#include "common.h"
#include "psyq/libgte.h"
#include "gte_local.h"

void SetRotMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 0, 1, 2, 3, 4);
}

void SetLightMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 8, 9, 10, 11, 12);
}

void SetColorMatrix(MATRIX* m) {
    gte_ldmatrix_t(m, 16, 17, 18, 19, 20);
}
