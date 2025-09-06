#include "common.h"
#include "psyq/libcd.h"

typedef struct {                          
    unsigned char sync;  // sync state    
    unsigned char ready; // ready state   
    unsigned char c;                      
} CdlIntr;                        

extern CdlCB (*CD_CBREADY)(u_char, u_char*); 
extern CdlCB (*CD_CBSYNC)(u_char, u_char*);  

extern char* D_80016070;
extern char* D_80016080;
extern char* D_800160F8;
extern char* D_80016100;
extern char* D_8001610C;
extern char* D_80016114;
extern char* D_80016124;

extern int D_80095FF8; // CD_DEBUG
extern u_char CD_COM;
extern u_char CD_MODE;
extern CdlLOC CD_POS;
extern const char* D_80096010[]; // CD_COMSTR
extern char* D_80096090[];
extern int D_80096130[]; 
extern int D_80096294;
extern int D_80096230[]; // CD_COMATTR
extern volatile u_char* D_800962B4;
extern volatile u_char* D_800962B8;
extern volatile int* D_800962C0;
extern volatile CdlIntr D_800962C8; // CD_INTR
extern volatile unsigned char* D_800962B0;

extern char D_8009B2A8[];
extern char D_8009B2B0[];
extern u_char* D_800962BC;
extern char D_8009B2B8[];
extern int D_8009B2C0;
extern int D_8009B2C4; // timeout
extern char* D_8009B2C8[];

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", getintr);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_sync);
int CD_sync(int mode, unsigned char* result) {
    int i;
    int intr;
    int sync;
    int flushed;
    int temp_s1;
    u_char* src;
    u_char* dst;
    char com, s, r;
    char** name;

    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = &D_800160F8;  

    while (true) {
        if ((D_8009B2C0 < VSync(-1)) || D_8009B2C4++ > 0x3C0000) {
            puts(&D_80016070);
            
            printf(&D_80016080,
                D_8009B2C8[0],
                D_80096010[CD_COM],
                D_80096090[D_800962C8.sync],
                D_80096090[D_800962C8.ready]);
            CD_flush();
            flushed = -1;
        } else {
            flushed = 0;
        }

        if (flushed != 0) {
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
    int flushed;
    int temp_s1;
    u_char* src;
    u_char* dst;
    
    D_8009B2C0 = VSync(-1) + 0x3C0;
    D_8009B2C4 = 0;
    D_8009B2C8[0] = &D_80016100;
    
    while (true) {
        
        if ((D_8009B2C0 < VSync(-1)) || D_8009B2C4++ > 0x3C0000) {
            puts(&D_80016070);
            
            printf(&D_80016080,
                D_8009B2C8[0],
                D_80096010[CD_COM],
                D_80096090[D_800962C8.sync],
                D_80096090[D_800962C8.ready]);
            CD_flush();
            flushed = -1;
        } else {
            flushed = 0;
        }

        if (flushed != 0) {
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
    s32 flushed;
    s32 temp_s1;
    u8* src;
    u8* dst;

    typedef struct Result_t {
        int unk0;
        int unk4;
    } Result_t;

    static inline void rescpy(void* _dst, void* _src) {
        char *pDst = (char*)_dst;
        char *pSrc = (char*)_src;
        u32 _size = sizeof(Result_t);
    
        if (pDst == 0) return;
        
        while (_size--) {
            *pDst++ = *pSrc++;
        }
    }
    
    if (D_80095FF8 > 1) {
        printf(&D_8001610C, D_80096010[arg0]);
    }
    
    if ((D_80096230[arg0] != 0) && (arg1 == 0)) {
        if (D_80095FF8 > 0) {
            printf(&D_80016114, D_80096010[arg0]);
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
    D_8009B2C8[0] = &D_80016124;
    
    while ( D_800962C8.sync == 0) {
        if ((D_8009B2C0 < VSync(-1)) || D_8009B2C4++ > 0x3C0000) {
            puts(&D_80016070);
            printf(&D_80016080,
                D_8009B2C8[0],
                D_80096010[CD_COM],
                D_80096090[D_800962C8.sync],
                D_80096090[D_800962C8.ready]);
            CD_flush();
            flushed = -1;
        } else {
            flushed = 0;
        }
        if (flushed != 0) {
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initvol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_initintr);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_init);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_datasync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_getsector);

//INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_set_test_parmnum);
void CD_set_test_parmnum(int arg0)
{
    D_80096294 = arg0;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", callback);
