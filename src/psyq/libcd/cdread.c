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
} ReadAttr_t;

CdlCB cdread_callback = 0;
volatile ReadAttr_t ReadAttr = {0};


// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", cb_read);
/**
 * @brief Internal: data ready callback used by CdRead()
 * 
 * Copies each sector into the destination buffer, checks the sector
 * position in 2048-byte mode, retries on errors and, when all sectors are
 * read (or on timeout/error), restores the previous callbacks, pauses the
 * drive and calls the CdReadCallback() function.
 * 
 * @param arg0 Interrupt type (CdlDataReady on success)
 * @param arg1 Result bytes of the interrupt
 */
void cb_read(u_char arg0, u_char* arg1)
{
    int pos[3];

    if (arg0 == 1) {
        if (ReadAttr.status > 0) {
            if (ReadAttr.secsize == 0x200) {
                CdGetSector(pos, 3);
                if (CdPosToInt(pos) != ReadAttr.pos) {
                    puts("CdRead: sector error\n");
                    ReadAttr.status = -1;
                }
            }
            CdGetSector(ReadAttr.buf_cur, ReadAttr.secsize);
            ReadAttr.buf_cur += ReadAttr.secsize;
            ReadAttr.status--;
            ReadAttr.pos++;
        }
    } else {
        ReadAttr.status = -1;
    }
    ReadAttr.vb_attempt_start = VSync(-1);
    if (ReadAttr.status < 0) {
        cd_read_retry(true);
    }
    if (VSync(-1) > (ReadAttr.vb_start + 1200)) {
        ReadAttr.status = -1;
    }
    if (ReadAttr.status && VSync(-1) <= ReadAttr.vb_start + 1200) {
        return;
    }
    CdSyncCallback(ReadAttr.cbsync);
    CdReadyCallback(ReadAttr.cbready);
    CdControl(CdlPause, 0, 0);
    if (cdread_callback != NULL) {
        cdread_callback(ReadAttr.status == 0 ? CdlComplete : CdlDiskError, arg1);
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", cd_read_retry);
/**
 * @brief Internal: (re)start the CdRead() transfer
 * 
 * Handles an open shell, optionally seeks back to the start position, sets
 * the read mode if needed, installs cb_read() and issues CdlReadN.
 * 
 * @param retry Non-zero when retrying after an error (pauses and re-seeks first)
 * @return Number of sectors remaining, or -1 on failure
 */
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
        ReadAttr.vb_start = VSync(-1);
        ReadAttr.status = -1;
        return ReadAttr.status;
    }
    if (retry) {
        puts("CdRead: retry...\n");
        CdControl(CdlPause, NULL, NULL);
        if (!CdControl(CdlSetloc, CdLastPos(), NULL)) {
            return ReadAttr.status = -1;
        }
    }
    CdFlush();
    mode2 = ReadAttr.mode;
    mode = mode2; // FAKE
    if ((char)mode2 != CdMode() || retry) {
        if (!CdControl(CdlSetmode, &mode, NULL)) {
            ReadAttr.status = -1;
            return ReadAttr.status;
        }
    }
    ReadAttr.pos = CdPosToInt(CdLastPos());
    CdReadyCallback(&cb_read);
    ReadAttr.buf_cur = ReadAttr.buf_start;
    CdControlF(CdlReadN, NULL);
    ReadAttr.status = ReadAttr.nsectors;
    ReadAttr.vb_attempt_start = VSync(-1);
    return ReadAttr.status;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", CdReadBreak);
/**
 * @brief Abort a read started with CdRead()
 * 
 * Restores the previous callbacks and pauses the drive.
 */
void CdReadBreak(void)
{
    ReadAttr.status = 0;
    CdSyncCallback(ReadAttr.cbsync);
    CdReadyCallback(ReadAttr.cbready);
    CdControl(CdlPause, NULL, NULL);
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", CdRead);
/**
 * @brief Read sectors from the CD-ROM in the background
 * 
 * Starts reading the given number of sectors from the position set by
 * CdlSetloc into buf. The read continues in the background; use
 * CdReadSync() or CdReadCallback() to know when it finishes.
 * 
 * @param sectors Number of sectors to read
 * @param buf Destination buffer
 * @param mode CD-ROM mode used for reading (CdlModeSpeed, CdlModeSize0/1, ...)
 * @return 1 if the read was started, 0 on failure
 */
int CdRead(int sectors, u_long* buf, int mode) {
    ReadAttr.mode = mode;
    switch (ReadAttr.mode & (CdlModeSize0 | CdlModeSize1)) {
    case 0:
        ReadAttr.secsize = 0x200;
        break;
    case CdlModeSize1:
        ReadAttr.secsize = 0x249;
        break;
    default:
        ReadAttr.secsize = 0x246;
        break;
    }
    ReadAttr.mode |= CdlModeSize1;
    ReadAttr.buf_start = buf;
    ReadAttr.nsectors = sectors;
    ReadAttr.cbsync = CdSyncCallback(NULL);
    ReadAttr.cbready = CdReadyCallback(NULL);
    ReadAttr.vb_start = VSync(-1);
    if (CdStatus() & (CdlStatPlay | CdlStatSeek | CdlStatRead)) {
        CdControlB(CdlPause, NULL, NULL);
    }
    return cd_read_retry(false) > 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", CdReadSync);
/**
 * @brief Wait for or check a read started with CdRead()
 * 
 * Monitors the background read, retrying on errors or stalls.
 * 
 * @param mode 0 = wait until the read finishes, 1 = return the current state immediately
 * @param result Buffer receiving the last status result (may be NULL)
 * @return Number of sectors still to read (0 when finished), or -1 on error
 */
int CdReadSync(int mode, u_char* result) {
    int var_s0;

    while (true) {
        var_s0 = -1;
        if (VSync(-1) <= ReadAttr.vb_start + 1200) {
            if (ReadAttr.status < 0 || VSync(-1) > ReadAttr.vb_attempt_start + 60) {
                cd_read_retry(true);
                var_s0 = ReadAttr.nsectors;
            } else {
                var_s0 = ReadAttr.status;
            }
        }
        if (mode != 0 || var_s0 <= 0) {
            CdReady(1, result);
            return var_s0;
        }
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/cdread", CdReadCallback);
/**
 * @brief Set the callback called when CdRead() finishes
 * 
 * The callback receives CdlComplete or CdlDiskError and the result bytes.
 * 
 * @param func New callback function (NULL to disable)
 * @return Previous callback function
 */
CdlCB CdReadCallback(CdlCB func) {
    CdlCB prevFunc = cdread_callback;
    cdread_callback = func;
    return prevFunc;
}
