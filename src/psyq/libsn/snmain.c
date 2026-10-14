#include "common.h"
#include "../libpad/padlocal.h"

INCLUDE_ASM("nonmatchings/psyq/libsn/snmain", __SN_ENTRY_POINT);

INCLUDE_ASM("nonmatchings/psyq/libsn/snmain", __main);

INCLUDE_ASM("nonmatchings/psyq/libsn/snmain", __do_global_dtors);
