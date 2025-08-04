#include "common.h"
#include "psxsdk/libcd.h"
#include "registers.h"

void StUnSetRing() {
    EnterCriticalSection();
    CdDataCallback(0);
    CdReadyCallback(0);
    *CDROM_REG0 = 0;
    *CDROM_REG3 = 0;
    ExitCriticalSection();
}
