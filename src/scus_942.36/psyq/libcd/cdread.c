#include "common.h"
#include "psyq/libcd.h"

typedef char Result_t[8];
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
void cb_read(u_char arg0, Result_t* arg1)
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", cd_read_retry);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadBreak);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdRead);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadSync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/cdread", CdReadCallback);
