#include "common.h"

// INCLUDE_ASM("nonmatchings/psyq/libcard/card", _card_clear);
/**
 * @brief Internal: clear the "new card" state of a memory card port
 * 
 * Acknowledges a card change by calling _new_card() and then issuing a
 * dummy write to sector 0x3F of the given channel.
 * 
 * @param arg0 Memory card channel (0x00/0x10 per port, plus multitap slot)
 */
void _card_clear(s32 arg0)
{
    _new_card();
    _card_write(arg0, 0x3F, 0);
}
