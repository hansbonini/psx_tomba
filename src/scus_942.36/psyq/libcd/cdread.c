#include "common.h"
#include "psyq/libcd.h"

typedef struct {
/*0x00*/    int nsectors;
/*0x04*/    u_long* buf_start;
/*0x08*/    u_long* buf_cur;
/*0x0C*/    int mode;
/*0x10*/    int secsize;
/*0x14*/    int status;
/*0x18*/    int vb_attempt_start;
/*0x1C*/    int vb_start;
/*0x20*/    int pos;
/*0x24*/    CdlCB cbsync;
/*0x28*/    CdlCB cbready;
/*0x2C*/    CdlCB cbdata;
/*0x30*/    int block_mode; 
/*0x34*/    u_char* unk34;
/*0x38*/    int unk38;
} ReadAttr_t;

extern CdlCB D_80096300;
extern volatile ReadAttr_t D_80096304;

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", cb_read);
void cb_read(u_char arg0, u_char* arg1)
{
    int pos[3];

    if (arg0 == 1) {
        if (D_80096304.status > 0) {
            if (D_80096304.secsize == 0x200) {
                CdGetSector(pos, 3);
                if (CdPosToInt(pos) != D_80096304.pos) {
                    puts("CdRead: sector error\n");
                    D_80096304.status = -1;
                }
            }
            CdGetSector(D_80096304.buf_cur, D_80096304.secsize);
            D_80096304.buf_cur += D_80096304.secsize;
            D_80096304.status--;
            D_80096304.pos++;
        }
    } else {
        D_80096304.status = -1;
    }
    D_80096304.vb_attempt_start = VSync(-1);
    if (D_80096304.status < 0) {
        cd_read_retry(true);
    }
    if (VSync(-1) > (D_80096304.vb_start + 1200)) {
        D_80096304.status = -1;
    }
    if (D_80096304.status && VSync(-1) <= D_80096304.vb_start + 1200) {
        return;
    }
    CdSyncCallback(D_80096304.cbsync);
    CdReadyCallback(D_80096304.cbready);
    CdControl(CdlPause, 0, 0);
    if (D_80096300 != NULL) {
        D_80096300(D_80096304.status == 0 ? CdlComplete : CdlDiskError, arg1);
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", cd_read_retry);
int cd_read_retry(int retry) {
    char mode;
    int mode2;
    CdSyncCallback(NULL);
    CdReadyCallback(NULL);
    if (CdStatus() & CdlStatShellOpen) {
        if ((VSync(-1) % 0x40) == 0) {
            puts("CdRead: Shell open...\n");
        }
        CdControlF(CdlNop, NULL);
        D_80096304.vb_start = VSync(-1);
        D_80096304.status = -1;
        return D_80096304.status;
    }
    if (retry) {
        puts("CdRead: retry...\n");
        CdControl(CdlPause, NULL, NULL);
        if (!CdControl(CdlSetloc, CdLastPos(), NULL)) {
            return D_80096304.status = -1;
        }
    }
    CdFlush();
    mode2 = D_80096304.mode;
    mode = mode2; // FAKE
    if ((char)mode2 != CdMode() || retry) {
        if (!CdControl(CdlSetmode, &mode, NULL)) {
            D_80096304.status = -1;
            return D_80096304.status;
        }
    }
    D_80096304.pos = CdPosToInt(CdLastPos());
    CdReadyCallback(&cb_read);
    D_80096304.buf_cur = D_80096304.buf_start;
    CdControlF(CdlReadN, NULL);
    D_80096304.status = D_80096304.nsectors;
    D_80096304.vb_attempt_start = VSync(-1);
    return D_80096304.status;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadBreak);
void CdReadBreak(void)
{
    D_80096304.status = 0;
    CdSyncCallback(D_80096304.cbsync);
    CdReadyCallback(D_80096304.cbready);
    CdControl(CdlPause, NULL, NULL);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdRead);
int CdRead(int sectors, u_long* buf, int mode) {
    D_80096304.mode = mode;
    switch (D_80096304.mode & (CdlModeSize0 | CdlModeSize1)) {
    case 0:
        D_80096304.secsize = 0x200;
        break;
    case CdlModeSize1:
        D_80096304.secsize = 0x249;
        break;
    default:
        D_80096304.secsize = 0x246;
        break;
    }
    D_80096304.mode |= CdlModeSize1;
    D_80096304.buf_start = buf;
    D_80096304.nsectors = sectors;
    D_80096304.cbsync = CdSyncCallback(NULL);
    D_80096304.cbready = CdReadyCallback(NULL);
    D_80096304.vb_start = VSync(-1);
    if (CdStatus() & (CdlStatPlay | CdlStatSeek | CdlStatRead)) {
        CdControlB(CdlPause, NULL, NULL);
    }
    return cd_read_retry(false) > 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadSync);
int CdReadSync(int mode, u_char* result) {
    int var_s0;

    while (true) {
        var_s0 = -1;
        if (VSync(-1) <= D_80096304.vb_start + 1200) {
            if (D_80096304.status < 0 || VSync(-1) > D_80096304.vb_attempt_start + 60) {
                cd_read_retry(true);
                var_s0 = D_80096304.nsectors;
            } else {
                var_s0 = D_80096304.status;
            }
        }
        if (mode != 0 || var_s0 <= 0) {
            CdReady(1, result);
            return var_s0;
        }
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadCallback);
CdlCB CdReadCallback(CdlCB func) {
    CdlCB prevFunc = D_80096300;
    D_80096300 = func;
    return prevFunc;
}
