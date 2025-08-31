#include "common.h"
#include "psyq/libcd.h"
#include "psyq/kernel.h"

extern CdlCB CD_CBSYNC;
extern CdlCB CD_CBREADY;
extern CdlLOC CD_POS;
extern u8 CD_COM;
extern s32 D_80096294;
extern s32 D_8009BC7C;
extern StHEADER* D_800A326C;
extern u32 D_800A3340;

void StCdInterrupt2(u_char intr, u_char* result);
void data_ready_callback();

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetRing);
void StSetRing(u_long* ring_addr, u_long ring_size)
{
    D_800A326C = (StHEADER*)ring_addr;
    D_800A3340 = ring_size;
    StClearRing();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdInit);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbsync);
void def_cbsync(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpCOMP);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbready);
void def_cbready(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", def_cbread);
void def_cbread(u_char intr, u_char* result) {
    DeliverEvent(HwCdRom, EvSpDR);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", DeliverEvent);
// BIOS_STUB(DeliverEvent, 0xB0, 0x7);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdStatus);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdMode);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdLastCom);
int CdLastCom(void)
{
    return CD_COM;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdLastPos);
CdlLOC* CdLastPos(void)
{
    return &CD_POS;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReset);
int CdReset(int mode) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdFlush);
void CdFlush(void) { CD_flush(); }

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSetDebug);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdComstr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdIntstr);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSync);
int CdSync(int mode, u_char* result) { return CD_sync(mode, result); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReady);
int CdReady(int mode, u_char* result) { return CD_ready(mode, result); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdSyncCallback);
CdlCB CdSyncCallback(CdlCB func) {
    CdlCB old = CD_CBSYNC;
    CD_CBSYNC = func;
    return old;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadyCallback);
CdlCB CdReadyCallback(CdlCB func) {
    CdlCB old = CD_CBREADY;
    CD_CBREADY = func;
    return old;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControl);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControlF);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdControlB);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdMix);
int CdMix(CdlATV* vol) {
    CD_vol(vol);
    return 1;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdGetSector);
int CdGetSector(void* madr, int size) { return CD_getsector(madr, size) == 0; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdDataCallback);
void(*CdDataCallback(void (*func)())) { return DMACallback(3, func); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdDataSync);
int CdDataSync(int mode) { CD_datasync(mode); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdIntToPos);
CdlLOC* CdIntToPos(int i, CdlLOC* p) {
    inline int ENCODE_BCD(n) { return ((n / 10) << 4) + (n % 10); }

    i += 150;
    p->sector = ENCODE_BCD(i % 75);
    p->second = ENCODE_BCD(i / 75 % 60);
    p->minute = ENCODE_BCD(i / 75 / 60);
    return p;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdPosToInt);
int CdPosToInt(CdlLOC* p) {
    #define DECODE_BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))

    u8 sector = p->sector;
    u8 second = p->second;
    u8 minute = p->minute;

    return (DECODE_BCD(minute) * 60 + DECODE_BCD(second)) * 75 +
           DECODE_BCD(sector) - 150;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", getintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_sync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_ready);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_cw);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_vol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_flush);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_initvol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_initintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_init);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_datasync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_getsector);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CD_set_test_parmnum);
void CD_set_test_parmnum(int arg0)
{
    D_80096294 = arg0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", callback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", puts);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", cb_read);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", cd_read_retry);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadBreak);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdRead);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdReadCallback);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", CdRead2);
int CdRead2(long mode) {
    u8 param = mode;
    CdControl(CdlSetmode, &param, NULL);
    if (mode & CdlModeStream) {
        if (mode & CdlModeSize1) {
            D_8009BC7C = 0;
        } else {
            D_8009BC7C = 1;
        }
        CdDataCallback(data_ready_callback);
        CdReadyCallback(StCdInterrupt2);
    }
    return CdControl(CdlReadS, NULL, NULL);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StCdInterrupt2);
void StCdInterrupt2(u_char intr, u_char* result) {
    StCdInterrupt();
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StClearRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StUnSetRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", data_ready_callback);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StGetBackloc);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetStream);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StFreeRing);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", init_ring_status);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StGetNext);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StSetMask);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", StCdInterrupt);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", mem2mem);
void mem2mem(s32* dst, s32* src, u32 num) {
    u32 i;
    for (i = 0; i < num; i++) {
        *dst++ = *src++;
    }
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", dma_execute);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", VSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd", v_wait);
