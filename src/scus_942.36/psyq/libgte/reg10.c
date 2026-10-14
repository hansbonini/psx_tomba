#include "common.h"
#include "psyq/libgte.h"
#include "psyq/inline_c.h"

void SetBackColor(long rbk, long gbk, long bbk) {
    rbk <<= 4;
    gbk <<= 4;
    bbk <<= 4;
    gte_ldbkdir(rbk, gbk, bbk);
}
