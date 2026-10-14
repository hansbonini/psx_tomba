#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libgte/fog_01", SetFogNear);
void SetFogNear(long a, long h) {
    SetDQA(-(a * 0x140) / h);
    SetDQB(0x01400000);
}