#include "common.h"
#include "psyq/libstamp.h"
#include "psyq/libcd.h"

typedef struct {
    unsigned char sync;
    unsigned char ready;
    unsigned char c;
} CdlIntr;

typedef struct Result_t {
    int unk0;
    int unk4;
} Result_t;

extern char cd_result_sync[];
extern char cd_result_ready[];
extern char cd_result_end[];
extern int cd_alarm;
extern int cd_alarm_count;
extern char* cd_alarm_func[];
extern const char cd_id[];

PsyqStamp libcd_stamp = PSYQ_SDK_STAMP(PSYQ_LIB_CD, 19, 14, 52);
CdlCB (*CD_cbsync)(u_char, u_char*) = NULL;
CdlCB (*CD_cbready)(u_char, u_char*) = NULL;
int CD_cbread = 0;
int CD_debug = 0;
int CD_status = 0;
int CD_status1 = 0;
int CD_nopen = 0;
CdlLOC CD_pos = {2, 0, 0, 0};
u_char CD_mode = 0;
u_char CD_com = 0;
const char* CD_comstr[] = {
    "CdlSync",    "CdlNop",
    "CdlSetloc",  "CdlPlay",
    "CdlForward", "CdlBackword",
    "CdlReadN",   "CdlStandby",
    "CdlStop",    "CdlPause",
    "CdlReset",   "CdlMute",
    "CdlDemute",  "CdlSetfilter",
    "CdlSetmode", "?",
    "CdlGetlocL", "CdlGetlocP",
    "?",          "CdlGetTN",
    "CdlGetTD",   "CdlSeekL",
    "CdlSeekP",   "?",
    "?",          "?",
    "?",          "CdlReadS",
    "?",          "?",
    "?",          "?",
};
const char* CD_intstr[] = {
    "NoIntr",  "DataReady", "Complete", "Acknowledge",
    "DataEnd", "DiskError", "?",        "?",
};
int cd_com_ack[32] = {
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
};
int cd_com_ready[32] = {
    0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
};
int cd_com_stat[32] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int cd_com_nparam[32] = {
    0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0,
    0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};
volatile u_char* cd_reg0 = (volatile u_char*)0x1F801800;
volatile u_char* cd_reg1 = (volatile u_char*)0x1F801801;
volatile u_char* cd_reg2 = (volatile u_char*)0x1F801802;
volatile u_char* cd_reg3 = (volatile u_char*)0x1F801803;
volatile int* cd_com_delay = (volatile int*)0x1F801020;
void* cd_spu = (void*)0x1F801C00;
volatile CdlIntr cd_intr = {0, 0, 0};
void* cd_info[] = {
    (void*)&cd_intr, cd_result_sync, &CD_com, &CD_status, &CD_pos, (void*)cd_id,
};
s32* cd_delay = (s32*)0x1F801018;
s32* cd_dpcr = (s32*)0x1F8010F0;
s32* cd_d3_madr = (s32*)0x1F8010B0;
s32* cd_d3_bcr = (s32*)0x1F8010B4;
volatile s32* cd_d3_chcr = (volatile s32*)0x1F8010B8;

void CD_flush(void);
void callback(void);

static inline void rescpy(void* _dst, void* _src) {
    char *pDst = (char*)_dst;
    char *pSrc = (char*)_src;
    u32 _size = sizeof(Result_t);

    if (pDst == 0) return;
    
    while (_size--) {
        *pDst++ = *pSrc++;
    }
}

static inline int get_alarm(void) {
    if ((cd_alarm < VSync(-1)) || cd_alarm_count++ > 0x3C0000) {
        puts("CD timeout: ");
        
        printf("%s:(%s) Sync=%s, Ready=%s\n",
            cd_alarm_func[0],
            CD_comstr[CD_com],
            CD_intstr[cd_intr.sync],
            CD_intstr[cd_intr.ready]);
        CD_flush();
        return -1;
    } 
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", getintr);
int getintr(void) {
    volatile char nReg;
    volatile char buf[8];
    int i, j;
    int bHasError;

    *cd_reg0 = 1;

    nReg = *cd_reg3 & 0x7;

    if (nReg == 0) {
        return 0;
    }

    bHasError = 0;

    while (nReg != (*cd_reg3 & 7)) {
        nReg = *cd_reg3 & 0x7;
    }

    for (i = 0; i < 8; i++) {
        if ((*cd_reg0 & 0x20) == 0) {
            break;
        }
        buf[i] = *cd_reg1;
    }
    for (j = i; j < 8; j++) {
        buf[j] = 0;
    }

    *cd_reg0 = 1;
    *cd_reg3 = 7;
    *cd_reg2 = 7;
    if (nReg != 3 || cd_com_stat[CD_com]) {
        if (!(CD_status & CdlStatShellOpen) && (buf[0] & CdlStatShellOpen)) {
            CD_nopen++;
        }
        CD_status = buf[0];
        CD_status1 = buf[1];
        bHasError = CD_status;
        bHasError &= (CdlStatError | CdlStatSeekError | CdlStop | CdlStatShellOpen);
    }
    if ((nReg == 5) && (0 < CD_debug)) {
        printf("DiskError: ");
        if (CD_debug > 0)
            printf("com=%s,code=(%02x:%02x)\n", CD_comstr[CD_com], CD_status, CD_status1);
    }
    switch (nReg) {
    case 3:
        if (bHasError) {
            cd_intr.sync = CdlDiskError;
            rescpy(&cd_result_sync, &buf);
            return 2;
        }
        if (cd_com_ack[CD_com]) {
            cd_intr.sync = CdlAcknowledge;
            rescpy(&cd_result_sync, &buf);
            return 1;
        }
        cd_intr.sync = CdlComplete;
        rescpy(&cd_result_sync, &buf);
        return 2;
    case 2:
        cd_intr.sync = bHasError ? CdlDiskError : CdlComplete;
        rescpy(&cd_result_sync, &buf);
        return 2;
    case 1:
        if (bHasError && i == 1) {
            bHasError = 0;
        }
        cd_intr.ready = bHasError ? CdlDiskError : CdlDataReady;
        rescpy(&cd_result_ready, &buf);
        *cd_reg0 = 0;
        *cd_reg3 = 0;
        return 4;
    case 4:
        cd_intr.ready = cd_intr.c = CdlDataEnd;
        rescpy(&cd_result_end, &buf);
        rescpy(&cd_result_ready, &buf);
        return 4;
    case 5:
        cd_intr.sync = cd_intr.ready = CdlDiskError;
        rescpy(&cd_result_sync, &buf);
        rescpy(&cd_result_ready, &buf);
        return 6;
    default:
        puts("CDROM: unknown intr");
        printf("(%d)\n", nReg);
        return 0;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_sync);
int CD_sync(int mode, unsigned char* result) {
    int i;
    int intr;
    int sync;
    
    int temp_s1;
    u_char* src;
    u_char* dst;
    char com, s, r;
    char** name;

    cd_alarm = VSync(-1) + 0x3C0;
    cd_alarm_count = 0;
    cd_alarm_func[0] = "CD_sync";  

    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }

        if (CheckCallback()) {
            temp_s1 = cd_reg0[0] & 3;

            while (intr = getintr()) {
                if (intr & 4 && CD_cbready != NULL) {
                    CD_cbready(cd_intr.ready, cd_result_ready);
                }
                if (intr & 2 && CD_cbsync != NULL) {
                    CD_cbsync(cd_intr.sync, cd_result_sync);
                }
            }
            cd_reg0[0] = temp_s1;
        }

        sync = cd_intr.sync;
        if (sync == 2 || sync == 5) {
            cd_intr.sync = 2;
            dst = result;
            src = cd_result_sync;
            if (dst != NULL) {
                for (i = 7; i != -1; i--) {
                    *dst++ = *src++;
                }
            }
            return sync;
        }

        if (mode != 0) {
            break;
        }
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_ready);
int CD_ready(int arg0, u_char* arg1) {
    int i;
    int c;
    int ready;
    int intr;
    int temp_s1;
    u_char* src;
    u_char* dst;
    
    cd_alarm = VSync(-1) + 0x3C0;
    cd_alarm_count = 0;
    cd_alarm_func[0] = "CD_ready";
    
    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }
        
        if (CheckCallback()) {
            temp_s1 = cd_reg0[0] & 3;

            while (intr = getintr()) {
                if (intr & 4 && CD_cbready != NULL) {
                    CD_cbready(cd_intr.ready, cd_result_ready);
                }
                if (intr & 2 && CD_cbsync != NULL) {
                    CD_cbsync(cd_intr.sync, cd_result_sync);
                }
            }
            cd_reg0[0] = temp_s1;
        }
        
        c = cd_intr.c;
        if (c != 0) {
            cd_intr.c = 0;
            src = &cd_result_end;
            if (arg1 != NULL) {
                dst = arg1;
                for (i = 7; i != -1; i--) {
                    *dst++ = *src++;
                }
            }
            return c;
        }
        ready = cd_intr.ready;
        if (ready != 0) {
            cd_intr.ready = 0;
            dst = arg1;
            src = &cd_result_ready;
            if (dst != NULL) {
                for (i = 7; i != -1; i--) {
                    *dst++ = *src++;
                }
            }
            return ready;
        }
        if (arg0 != 0) {
            return 0;
        }
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_cw);
int CD_cw(u_char arg0, u_char* arg1, u_char* arg2, int arg3)
{
    s32 i;
    s32 intr;
    s32 sync;
    s32 temp_s1;
    u8* src;
    u8* dst;
    
    if (CD_debug > 1) {
        printf("%s...\n", CD_comstr[arg0]);
    }
    
    if ((cd_com_nparam[arg0] != 0) && (arg1 == 0)) {
        if (CD_debug > 0) {
            printf("%s: no param\n", CD_comstr[arg0]);
        }
        
        return -2;
    }
    
    CD_sync(0, 0);
    if (arg0 == 0x2) {
        for (i = 0; i < 4; i++) {
            ((u8*)&CD_pos)[i] = ((u8*)arg1)[i];
        }
    }
    if (arg0 == 0xE) {
        CD_mode = *arg1;
    }
    
    cd_intr.sync = 0;
    if (cd_com_ready[arg0] != 0) {
        cd_intr.ready = 0;
    }
    
    *cd_reg0 = 0;
    for (i = 0; i < cd_com_ready[0x40 + arg0]; i++) {
        *cd_reg2 = arg1[i];
    }
    
    CD_com = arg0;
    *cd_reg1 = arg0;   
    if (arg3 != 0) return 0;
    cd_alarm = VSync(-1) + 0x3C0;
    cd_alarm_count = 0;
    cd_alarm_func[0] = "CD_cw";
    
    while ( cd_intr.sync == 0) {
        if (get_alarm() != 0) {
            return -1;
        }
        
        if (CheckCallback()) {
            temp_s1 = cd_reg0[0] & 3;
            while (intr = getintr()) {
                if (intr & 4 && CD_cbready != NULL) {
                    CD_cbready(cd_intr.ready, cd_result_ready);
                }
                if (intr & 2 && CD_cbsync != NULL) {
                    CD_cbsync(cd_intr.sync, cd_result_sync);
                }
            }
            cd_reg0[0] = temp_s1;
        }
    }

    rescpy(arg2, cd_result_sync);

    return cd_intr.sync == 5 ? -1 : 0;
}


// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_vol);
int CD_vol(CdlATV* vol)
{
    *cd_reg0 = 2;
    *cd_reg2 = vol->val0;
    *cd_reg3 = vol->val1;
    *cd_reg0 = 3;
    *cd_reg1 = vol->val2;
    *cd_reg2 = vol->val3;
    *cd_reg3 = 0x20;
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_flush);
void CD_flush(void)
{
    *cd_reg0 = 1;
    if (*cd_reg3 & 7) {
        do {
            *cd_reg0 = 1;
            *cd_reg3 = 7;
            *cd_reg2 = 7;
        } while (*cd_reg3 & 7);
    }
    cd_intr.ready = cd_intr.c = 0;
    cd_intr.sync = 2;
    *cd_reg0 = 0;
    *cd_reg3 = 0;
    *cd_com_delay = 0x1325;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_initvol);
int CD_initvol(void) {
    CdlATV vol;
    // 0x800962C4 + 0x1b8 = 0x8009647C (current main vol left).
    if (*((volatile u16*)((u32)cd_spu + 0x1b8)) == 0 &&
    *((volatile u16*)((u32)cd_spu + 0x1ba)) == 0) {
        // 0x800962C4 + 0x180 = 0x80096444 (main vol left/right).
        *((volatile u16*)((u32)cd_spu + 0x180)) = 0x3fff;
        *((volatile u16*)((u32)cd_spu + 0x182)) = 0x3fff;
    }
    // 0x800962C4 + 0x1b0 = 0x80096474 (CD volume left/right).
    *((volatile u16*)((u32)cd_spu + 0x1b0)) = 0x3fff;
    *((volatile u16*)((u32)cd_spu + 0x1b2)) = 0x3fff;
    // Enable spu, unmute spu and enable cd audio.
    *((volatile u16*)((u32)cd_spu + 0x1aa)) =
    (1 << 15) | (1 << 14) | (1 << 0);
    vol.val0 = vol.val2 = 0x80;
    vol.val1 = vol.val3 = 0;
    *cd_reg0 = 2;
    *cd_reg2 = vol.val0;
    *cd_reg3 = vol.val1;
    *cd_reg0 = 3;
    *cd_reg1 = vol.val2;
    *cd_reg2 = vol.val3;
    *cd_reg3 = 0x20;
    return 0;
}

//INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_initintr);
void CD_initintr(void) {
    CD_cbready = 0;
    CD_cbsync = 0;
    CD_status1 = 0;
    CD_status = 0;
    ResetCallback();
    InterruptCallback(2, callback);
}


const char cd_id[] = "$Id: bios.c,v 1.81 1996/12/16 06:24:14 makoto Exp $";

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_init);
int CD_init(void) {
    puts("CD_init:");
    printf("addr=%08x\n", &cd_info);
    CD_com = 0;
    CD_mode = 0;
    CD_cbready = 0;
    CD_cbsync = 0;
    CD_status1 = 0;
    CD_status = 0;
    ResetCallback();
    InterruptCallback(2, &callback);
    
    *cd_reg0 = 1;
    while (*cd_reg3 & 7) {
        *cd_reg0 = 1;
        *cd_reg3 = 7;
        *cd_reg2 = 7;
    }
    
    cd_intr.ready = cd_intr.c = 0;
    cd_intr.sync = 2;
    
    *cd_reg0 = 0;
    *cd_reg3 = 0;
    *cd_com_delay = 0x1325; // COM_DELAY
    
    CD_cw(1, 0, 0, 0);
    if (CD_status & 0x10) {
        CD_cw(1, 0, 0, 0);
    }
    if (CD_cw(0xA, 0, 0, 0) != 0) {
        return -1;
    }

    if (CD_cw(0xC, 0, 0, 0) != 0) {
        return -1;
    }

    if (CD_sync(0, 0) != 2) {
        return -1;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_datasync);
int CD_datasync(int arg0) {
    int sync;

    cd_alarm = VSync(-1) + 0x3C0;
    cd_alarm_count = 0;
    cd_alarm_func[0] = "CD_datasync";    
    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }
        if (!(*cd_d3_chcr & 0x01000000)) {
            sync = 0;
            break;
        }
        if (arg0 != 0) {
            sync = 1;
            break;
        }
    }
    return sync;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_getsector);
int CD_getsector(int arg0, int arg1) {
    *cd_reg0 = 0;
    *cd_reg3 = 0x80;
    *cd_delay = 0x20943;
    *cd_com_delay = 0x1323;
    *cd_dpcr |= 0x8000;
    *cd_d3_madr = arg0;
    *cd_d3_bcr = arg1 | 0x10000;
    while (!(*cd_reg0 & 0x40)){};
    *cd_d3_chcr = 0x11000000;
    while (*cd_d3_chcr & 0x01000000){};
    *cd_com_delay = 0x1325;
    return 0;
}

//INCLUDE_ASM("nonmatchings/psyq/libcd/bios", CD_set_test_parmnum);
void CD_set_test_parmnum(int arg0)
{
    cd_com_nparam[25] = arg0;
}

// INCLUDE_ASM("nonmatchings/psyq/libcd/bios", callback);
void callback(void) {
    int intr;
    int temp_s1;
    
    temp_s1 = cd_reg0[0] & 3;

    while (intr = getintr()) {
        if (intr & 4 && CD_cbready != NULL) {
            CD_cbready(cd_intr.ready, cd_result_ready);
        }
        if (intr & 2 && CD_cbsync != NULL) {
            CD_cbsync(cd_intr.sync, cd_result_sync);
        }
    }
    cd_reg0[0] = temp_s1;
}
