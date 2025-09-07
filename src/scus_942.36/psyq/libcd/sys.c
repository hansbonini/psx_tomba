#include "common.h"
#include "psyq/libcd.h"

extern char* D_80015F2C;
extern char* D_80015F2C;
extern int D_80095F64[];
extern CdlCB CD_CBSYNC;
extern s32 CD_DEBUG;
extern CdlCB CD_CBREADY;
extern u8 CD_STATUS;
extern CdlLOC CD_POS;
extern const char* CD_COMSTR[];
extern const char* CD_INTSTR[];
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdSetDebug);
s32 CdSetDebug(s32 level) {
    s32 lastLevel;

    lastLevel = CD_DEBUG;
    CD_DEBUG = level;
    return lastLevel;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdComstr);
char* CdComstr(u_char com)
{
    if (com >= 0x1c) {
        return &D_80015F2C;
    }
    return CD_COMSTR[com];
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdIntstr);
char* CdIntstr(u_char intr) {
    if (intr >= 7) {
        return &D_80015F2C;
    }
    return CD_INTSTR[intr];
}

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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdControl);
int CdControl(u_char com, u_char* param, u_char* result) {
    static inline int loop(u_char com, u_char* param, u_char* result) {
        int i;
        CdlCB cbprev = CD_CBSYNC;
        for (i = 3; i != -1; --i) {
            CD_CBSYNC = 0;
    
            if (com != 1 && (CD_STATUS & CdlStatShellOpen) != 0) {
                CD_cw(CdlNop, 0, 0, 0);
            }
    
            if (param == 0 || D_80095F64[com] == 0 ||
                CD_cw(CdlSetloc, param, result, 0) == 0) {
                CD_CBSYNC = cbprev;
                if (CD_cw(com, param, result, 0) == 0) {
                    return 0;
                }
            }
        }
    
        CD_CBSYNC = cbprev;
        return -1;
    }
    return loop(com, param, result) == 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/sys", CdControlF);
int CdControlF(u_char com, u_char* param)
{
    static inline int loop(u8 com, u8* param, u8* result) {
        s32 i;
    
        CdlCB cbprev = CD_CBSYNC;
        
        for (i = 3; i != -1; i--) {
            CD_CBSYNC = NULL;
            if ((com != 1) && (CD_STATUS & 0x10)) {
                CD_cw(1, NULL, NULL, 0);
            }
            if ((param == NULL) || (D_80095F64[com] == 0) || (CD_cw(2, param, result, 0) == 0)) {
                CD_CBSYNC = cbprev;
                if (CD_cw(com, param, result, 1) == 0) {
                    return 0;
                }
            }
        }
    
        CD_CBSYNC = cbprev;
        return -1;
    }

    return loop(com, param, NULL) == 0;
}

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
