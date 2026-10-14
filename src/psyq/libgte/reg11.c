#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"

void SetFarColor(long rfc, long gfc, long bfc) {
    rfc <<= 4;
    gfc <<= 4;
    bfc <<= 4;
    gte_ldfcdir(rfc, gfc, bfc);
}
