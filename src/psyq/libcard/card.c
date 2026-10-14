#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libcard/card", _card_clear);
void _card_clear(s32 arg0)
{
    _new_card();
    _card_write(arg0, 0x3F, 0);
}
