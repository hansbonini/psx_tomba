#include "common.h"

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libapi/bzero", bzero);
s8* bzero(s8* arg0, s32 arg1)
{
    s32 var_a1;
    s8* var_a0;
    s8* var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = NULL;
    if (var_a0 != NULL) {
        var_v0 = var_a0;
        if (var_a1 <= 0) {
            return NULL;
        }
        do {
            *var_a0 = 0;
            var_a1 -= 1;
            var_a0 += 1;
        } while (var_a1 > 0);
    }
    return var_v0;
}
