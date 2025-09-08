#include "common.h"
#include "psyq/libcd.h"
// #include "psyq/libetc.h"

typedef struct {                          
    unsigned char sync;  // sync state    
    unsigned char ready; // ready state   
    unsigned char c;                      
} CdlIntr;  

typedef struct Result_t {
    int unk0;
    int unk4;
} Result_t;

extern CdlCB (*CD_CBREADY)(u_char, u_char*); 
extern CdlCB (*CD_CBSYNC)(u_char, u_char*);  

INCLUDE_RODATA("asm/scus_942.36/nonmatchings/psyq/libcd/bios", D_80015F34);

extern int CD_DEBUG; // CD_DEBUG
extern u_char CD_COM;
extern u_char CD_MODE;
extern int CD_STATUS;
extern int CD_STATUS1;
extern int D_80096004;
extern CdlLOC CD_POS;
extern const char* CD_COMSTR[]; // CD_COMSTR
extern const char* CD_INTSTR[];
extern const char* D_800960B0[];
extern int D_80096130[]; 
extern const char* D_800961B0[];
extern int D_80096230[]; // CD_COMATTR
extern int D_80096294;
extern volatile u_char* D_800962B4;
extern volatile u_char* D_800962B8;
extern volatile int* D_800962C0;
extern void* D_800962C4;
extern volatile CdlIntr D_800962C8; // CD_INTR
extern void* D_800962CC[];
extern volatile unsigned char* D_800962B0;
extern s32* D_800962E4;
extern s32* D_800962E8;
extern s32* D_800962EC;
extern s32* D_800962F0;
extern volatile s32* D_800962F4;
extern char D_8009B2A8[];
extern char D_8009B2B0[];
extern volatile u_char* D_800962BC;
extern char D_8009B2B8[];
extern int D_8009B2C0;
extern int D_8009B2C4; // timeout
extern char* D_8009B2C8[];

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
    if ((D_8009B2C0 < VSync(-1)) || D_8009B2C4++ > 0x3C0000) {
        puts("CD timeout: ");
        
        printf("%s:(%s) Sync=%s, Ready=%s\n",
            D_8009B2C8[0],
            CD_COMSTR[CD_COM],
            CD_INTSTR[D_800962C8.sync],
            CD_INTSTR[D_800962C8.ready]);
        CD_flush();
        return -1;
    } 
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", getintr);
int getintr(void) {
    volatile char nReg;
    volatile char buf[8];
    int i, j;
    int bHasError;

    *D_800962B0 = 1;

    nReg = *D_800962BC & 0x7;

    if (nReg == 0) {
        return 0;
    }

    bHasError = 0;

    while (nReg != (*D_800962BC & 7)) {
        nReg = *D_800962BC & 0x7;
    }

    for (i = 0; i < 8; i++) {
        if ((*D_800962B0 & 0x20) == 0) {
            break;
        }
        buf[i] = *D_800962B4;
    }
    for (j = i; j < 8; j++) {
        buf[j] = 0;
    }

    *D_800962B0 = 1;
    *D_800962BC = 7;
    *D_800962B8 = 7;
    if (nReg != 3 || D_800961B0[CD_COM]) {
        if (!(CD_STATUS & CdlStatShellOpen) && (buf[0] & CdlStatShellOpen)) {
            D_80096004++;
        }
        CD_STATUS = buf[0];
        CD_STATUS1 = buf[1];
        bHasError = CD_STATUS;
        bHasError &= (CdlStatError | CdlStatSeekError | CdlStop | CdlStatShellOpen);
    }
    if ((nReg == 5) && (0 < CD_DEBUG)) {
        printf("DiskError: ");
        if (CD_DEBUG > 0)
            printf("com=%s,code=(%02x:%02x)\n", CD_COMSTR[CD_COM], CD_STATUS, CD_STATUS1);
    }
    switch (nReg) {
    case 3:
        if (bHasError) {
            D_800962C8.sync = CdlDiskError;
            rescpy(&D_8009B2A8, &buf);
            return 2;
        }
        if (D_800960B0[CD_COM]) {
            D_800962C8.sync = CdlAcknowledge;
            rescpy(&D_8009B2A8, &buf);
            return 1;
        }
        D_800962C8.sync = CdlComplete;
        rescpy(&D_8009B2A8, &buf);
        return 2;
    case 2:
        D_800962C8.sync = bHasError ? CdlDiskError : CdlComplete;
        rescpy(&D_8009B2A8, &buf);
        return 2;
    case 1:
        if (bHasError && i == 1) {
            bHasError = 0;
        }
        D_800962C8.ready = bHasError ? CdlDiskError : CdlDataReady;
        rescpy(&D_8009B2B0, &buf);
        *D_800962B0 = 0;
        *D_800962BC = 0;
        return 4;
    case 4:
        D_800962C8.ready = D_800962C8.c = CdlDataEnd;
        rescpy(&D_8009B2B8, &buf);
        rescpy(&D_8009B2B0, &buf);
        return 4;
    case 5:
        D_800962C8.sync = D_800962C8.ready = CdlDiskError;
        rescpy(&D_8009B2A8, &buf);
        rescpy(&D_8009B2B0, &buf);
        return 6;
    default:
        puts("CDROM: unknown intr");
        printf("(%d)\n", nReg);
        return 0;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_sync);
int CD_sync(int mode, unsigned char* result) {
    int i;
    int intr;
    int sync;
    
    int temp_s1;
    u_char* src;
    u_char* dst;
    char com, s, r;
    char** name;

    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = "CD_sync";  

    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }

        if (CheckCallback()) {
            temp_s1 = D_800962B0[0] & 3;

            while (intr = getintr()) {
                if (intr & 4 && CD_CBREADY != NULL) {
                    CD_CBREADY(D_800962C8.ready, D_8009B2B0);
                }
                if (intr & 2 && CD_CBSYNC != NULL) {
                    CD_CBSYNC(D_800962C8.sync, D_8009B2A8);
                }
            }
            D_800962B0[0] = temp_s1;
        }

        sync = D_800962C8.sync;
        if (sync == 2 || sync == 5) {
            D_800962C8.sync = 2;
            dst = result;
            src = D_8009B2A8;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_ready);
int CD_ready(int arg0, u_char* arg1) {
    int i;
    int c;
    int ready;
    int intr;
    int temp_s1;
    u_char* src;
    u_char* dst;
    
    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = "CD_ready";
    
    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }
        
        if (CheckCallback()) {
            temp_s1 = D_800962B0[0] & 3;

            while (intr = getintr()) {
                if (intr & 4 && CD_CBREADY != NULL) {
                    CD_CBREADY(D_800962C8.ready, D_8009B2B0);
                }
                if (intr & 2 && CD_CBSYNC != NULL) {
                    CD_CBSYNC(D_800962C8.sync, D_8009B2A8);
                }
            }
            D_800962B0[0] = temp_s1;
        }
        
        c = D_800962C8.c;
        if (c != 0) {
            D_800962C8.c = 0;
            src = &D_8009B2B8;
            if (arg1 != NULL) {
                dst = arg1;
                for (i = 7; i != -1; i--) {
                    *dst++ = *src++;
                }
            }
            return c;
        }
        ready = D_800962C8.ready;
        if (ready != 0) {
            D_800962C8.ready = 0;
            dst = arg1;
            src = &D_8009B2B0;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_cw);
int CD_cw(u_char arg0, u_char* arg1, u_char* arg2, int arg3)
{
    s32 i;
    s32 intr;
    s32 sync;
    s32 temp_s1;
    u8* src;
    u8* dst;
    
    if (CD_DEBUG > 1) {
        printf("%s...\n", CD_COMSTR[arg0]);
    }
    
    if ((D_80096230[arg0] != 0) && (arg1 == 0)) {
        if (CD_DEBUG > 0) {
            printf("%s: no param\n", CD_COMSTR[arg0]);
        }
        
        return -2;
    }
    
    CD_sync(0, 0);
    if (arg0 == 0x2) {
        for (i = 0; i < 4; i++) {
            ((u8*)&CD_POS)[i] = ((u8*)arg1)[i];
        }
    }
    if (arg0 == 0xE) {
        CD_MODE = *arg1;
    }
    
    D_800962C8.sync = 0;
    if (D_80096130[arg0] != 0) {
        D_800962C8.ready = 0;
    }
    
    *D_800962B0 = 0;
    for (i = 0; i < D_80096130[0x40 + arg0]; i++) {
        *D_800962B8 = arg1[i];
    }
    
    CD_COM = arg0;
    *D_800962B4 = arg0;   
    if (arg3 != 0) return 0;
    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = "CD_cw";
    
    while ( D_800962C8.sync == 0) {
        if (get_alarm() != 0) {
            return -1;
        }
        
        if (CheckCallback()) {
            temp_s1 = D_800962B0[0] & 3;
            while (intr = getintr()) {
                if (intr & 4 && CD_CBREADY != NULL) {
                    CD_CBREADY(D_800962C8.ready, D_8009B2B0);
                }
                if (intr & 2 && CD_CBSYNC != NULL) {
                    CD_CBSYNC(D_800962C8.sync, D_8009B2A8);
                }
            }
            D_800962B0[0] = temp_s1;
        }
    }

    rescpy(arg2, D_8009B2A8);

    return D_800962C8.sync == 5 ? -1 : 0;
}


// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_vol);
int CD_vol(CdlATV* vol)
{
    *D_800962B0 = 2;
    *D_800962B8 = vol->val0;
    *D_800962BC = vol->val1;
    *D_800962B0 = 3;
    *D_800962B4 = vol->val2;
    *D_800962B8 = vol->val3;
    *D_800962BC = 0x20;
    return 0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_flush);
void CD_flush(void)
{
    *D_800962B0 = 1;
    if (*D_800962BC & 7) {
        do {
            *D_800962B0 = 1;
            *D_800962BC = 7;
            *D_800962B8 = 7;
        } while (*D_800962BC & 7);
    }
    D_800962C8.ready = D_800962C8.c = 0;
    D_800962C8.sync = 2;
    *D_800962B0 = 0;
    *D_800962BC = 0;
    *D_800962C0 = 0x1325;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initvol);
int CD_initvol(void) {
    CdlATV vol;
    // 0x800962C4 + 0x1b8 = 0x8009647C (current main vol left).
    if (*((volatile u16*)((u32)D_800962C4 + 0x1b8)) == 0 &&
    *((volatile u16*)((u32)D_800962C4 + 0x1ba)) == 0) {
        // 0x800962C4 + 0x180 = 0x80096444 (main vol left/right).
        *((volatile u16*)((u32)D_800962C4 + 0x180)) = 0x3fff;
        *((volatile u16*)((u32)D_800962C4 + 0x182)) = 0x3fff;
    }
    // 0x800962C4 + 0x1b0 = 0x80096474 (CD volume left/right).
    *((volatile u16*)((u32)D_800962C4 + 0x1b0)) = 0x3fff;
    *((volatile u16*)((u32)D_800962C4 + 0x1b2)) = 0x3fff;
    // Enable spu, unmute spu and enable cd audio.
    *((volatile u16*)((u32)D_800962C4 + 0x1aa)) =
    (1 << 15) | (1 << 14) | (1 << 0);
    vol.val0 = vol.val2 = 0x80;
    vol.val1 = vol.val3 = 0;
    *D_800962B0 = 2;
    *D_800962B8 = vol.val0;
    *D_800962BC = vol.val1;
    *D_800962B0 = 3;
    *D_800962B4 = vol.val2;
    *D_800962B8 = vol.val3;
    *D_800962BC = 0x20;
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initintr);
void CD_initintr(void) {
    CD_CBREADY = 0;
    CD_CBSYNC = 0;
    CD_STATUS1 = 0;
    CD_STATUS = 0;
    ResetCallback();
    InterruptCallback(2, callback);
}

const char D_8001612C[] = "$Id: bios.c,v 1.81 1996/12/16 06:24:14 makoto Exp $";

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_init);
int CD_init(void) {
    puts("CD_init:");
    printf("addr=%08x\n", &D_800962CC);
    CD_COM = 0;
    CD_MODE = 0;
    CD_CBREADY = 0;
    CD_CBSYNC = 0;
    CD_STATUS1 = 0;
    CD_STATUS = 0;
    ResetCallback();
    InterruptCallback(2, &callback);
    
    *D_800962B0 = 1;
    while (*D_800962BC & 7) {
        *D_800962B0 = 1;
        *D_800962BC = 7;
        *D_800962B8 = 7;
    }
    
    D_800962C8.ready = D_800962C8.c = 0;
    D_800962C8.sync = 2;
    
    *D_800962B0 = 0;
    *D_800962BC = 0;
    *D_800962C0 = 0x1325; // COM_DELAY
    
    CD_cw(1, 0, 0, 0);
    if (CD_STATUS & 0x10) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_datasync);
int CD_datasync(int arg0) {
    int sync;

    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = "CD_datasync";    
    while (true) {
        if (get_alarm() != 0) {
            return -1;
        }
        if (!(*D_800962F4 & 0x01000000)) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_getsector);
int CD_getsector(int arg0, int arg1) {
    *D_800962B0 = 0;
    *D_800962BC = 0x80;
    *D_800962E4 = 0x20943;
    *D_800962C0 = 0x1323;
    *D_800962E8 |= 0x8000;
    *D_800962EC = arg0;
    *D_800962F0 = arg1 | 0x10000;
    while (!(*D_800962B0 & 0x40)){};
    *D_800962F4 = 0x11000000;
    while (*D_800962F4 & 0x01000000){};
    *D_800962C0 = 0x1325;
    return 0;
}

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_set_test_parmnum);
void CD_set_test_parmnum(int arg0)
{
    D_80096294 = arg0;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", callback);
void callback(void) {
    int intr;
    int temp_s1;
    
    temp_s1 = D_800962B0[0] & 3;

    while (intr = getintr()) {
        if (intr & 4 && CD_CBREADY != NULL) {
            CD_CBREADY(D_800962C8.ready, D_8009B2B0);
        }
        if (intr & 2 && CD_CBSYNC != NULL) {
            CD_CBSYNC(D_800962C8.sync, D_8009B2A8);
        }
    }
    D_800962B0[0] = temp_s1;
}
