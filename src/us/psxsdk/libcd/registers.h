#include "types.h"

static volatile u8* CDROM_REG0 = (u8*)0x1F801800;
static volatile u8* CDROM_REG1 = (u8*)0x1F801801;
static volatile u8* CDROM_REG2 = (u8*)0x1F801802;
static volatile u8* CDROM_REG3 = (u8*)0x1F801803;