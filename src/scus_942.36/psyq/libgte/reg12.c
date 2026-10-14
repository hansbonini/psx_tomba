#include "common.h"
#include "psyq/libgte.h"
#include "gte_local.h"

void SetGeomOffset(long ofx, long ofy) {
    ofx <<= 16;
    ofy <<= 16;
    gte_ldofxy(ofx, ofy);
}

__asm__("nop");
__asm__("nop");
