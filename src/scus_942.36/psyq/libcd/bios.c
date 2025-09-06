#include "common.h"
#include "psyq/libcd.h"

typedef struct {                          
    unsigned char sync;  // sync state    
    unsigned char ready; // ready state   
    unsigned char c;                      
} CD_flush_struct;                        

extern int (*CD_CBREADY)(u8, char*); 
extern int (*CD_CBSYNC)(u8, char*);  

extern u8 CD_COM;
extern char* D_80016070;
extern char* D_80016080;
extern char* D_800160F8;
extern char* D_80016100;

extern const char* D_80096010[];
extern char* D_80096090[];

extern s32 D_80096294;
extern volatile CD_flush_struct D_800962C8;
extern volatile unsigned char* D_800962B0;

extern char D_8009B2A8[];
extern char D_8009B2B0[];
extern char D_8009B2B8[];
extern s32 D_8009B2C0;
extern s32 D_8009B2C4; // timeout
extern char* D_8009B2C8[];

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", getintr);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_sync);
int CD_sync(int mode, unsigned char* result) {
    s32 i;
    s32 intr;
    s32 sync;
    s32 flushed;
    s32 temp_s1;
    u8* src;
    u8* dst;
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
    s32 i;
    s32 c;
    s32 ready;
    s32 intr;
    s32 flushed;
    s32 temp_s1;
    u8* src;
    u8* dst;
    
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_cw);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_vol);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libcd/bios", CD_flush);

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
