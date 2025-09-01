#include "common.h"
#include "psyq/libcd.h"

extern CdlCB CD_CBSYNC;
extern CdlCB CD_CBREADY;
extern u8 CD_STATUS;
extern CdlLOC CD_POS;
extern u8 CD_COM;
extern u8 CD_MODE;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdStatus);
int CdStatus(void)
{
    return CD_STATUS;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdMode);
int CdMode(void)
{
    return CD_MODE;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdLastCom);
int CdLastCom(void)
{
    return CD_COM;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdLastPos);
CdlLOC* CdLastPos(void)
{
    return &CD_POS;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdReset);
int CdReset(int mode)
{
    if (mode == CdlModeAP) {
        CD_initintr();
        return 1;
    }
    if (CD_init()) {
        return 0;
    }
    if (mode == CdlModeDA && CD_initvol()) {
        return 0;
    }
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdFlush);
void CdFlush(void)
{
    CD_flush();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdSetDebug);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdComstr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdIntstr);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdSync);
int CdSync(int mode, u_char* result)
{
    return CD_sync(mode, result);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdReady);
int CdReady(int mode, u_char* result) {
    return CD_ready(mode, result);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdSyncCallback);
CdlCB CdSyncCallback(CdlCB func) {
    CdlCB old = CD_CBSYNC;
    CD_CBSYNC = func;
    return old;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdReadyCallback);
CdlCB CdReadyCallback(CdlCB func) {
    CdlCB old = CD_CBREADY;
    CD_CBREADY = func;
    return old;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdControl);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdControlF);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdControlB);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdMix);
int CdMix(CdlATV* vol) {
    CD_vol(vol);
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdGetSector);
int CdGetSector(void* madr, int size)
{
    return CD_getsector(madr, size) == 0;

}
// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdDataCallback);
void(*CdDataCallback(void (*func)()))
{
    return DMACallback(3, func); 
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdDataSync);
int CdDataSync(int mode) {
    CD_datasync(mode);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdIntToPos);
CdlLOC* CdIntToPos(int i, CdlLOC* p) {
    inline int ENCODE_BCD(n) { return (((n / 10) << 4) + (n % 10)); };

    i += 150;
    p->sector = ENCODE_BCD(i % 75);
    p->second = ENCODE_BCD(i / 75 % 60);
    p->minute = ENCODE_BCD(i / 75 / 60);
    return p;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdPosToInt);
int CdPosToInt(CdlLOC* p) {
    #define DECODE_BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))

    u8 sector = p->sector;
    u8 second = p->second;
    u8 minute = p->minute;

    return (DECODE_BCD(minute) * 60 + DECODE_BCD(second)) * 75 +
           DECODE_BCD(sector) - 150;
}
