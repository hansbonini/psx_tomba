#include "common.h"

typedef struct {
    u_char iq_y[64];
    u_char iq_c[64];
    short dct[64];
} DECDCTENV;
extern u32 mdec_iq[];
extern u32 mdec_coef[];
void MDEC_in(u_long* buf, int size);
int ResetCallback(void);
void MDEC_reset(int mode);
extern int DecDCTinCallback(void (*func)());
extern int DecDCToutCallback(void (*func)());
int DecDCToutCallback(void (*cb)());
int MDEC_in_sync(void);
u_long MDEC_status(void);
void MDEC_out(u_long* buf, int size);
int DecDCTinCallback(void (*cb)());
int MDEC_out_sync(void);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTReset);

void DecDCTReset(int mode) {
    if (mode == 0)
        ResetCallback();
    MDEC_reset(mode);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTGetEnv);

DECDCTENV* DecDCTGetEnv(DECDCTENV* env) {
    int i;
    u32 *dst, *src;
    dst = (u32*)env->iq_y;
    src = &mdec_iq[1];
    for (i = 15; i != -1; i--)
        *dst++ = *src++;
    dst = (u32*)env->iq_c;
    src = &mdec_iq[17];
    for (i = 15; i != -1; i--)
        *dst++ = *src++;
    dst = (u32*)env->dct;
    src = &mdec_coef[1];
    for (i = 31; i != -1; i--)
        *dst++ = *src++;
    return env;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTPutEnv);

DECDCTENV* DecDCTPutEnv(DECDCTENV* env) {
    int i;
    u32 *dst1, *src1, *dst2, *src2;
    dst1 = &mdec_iq[1];
    src1 = (u32*)env->iq_y;
    for (i = 15; i != -1; i--)
        *dst1++ = *src1++;
    dst2 = &mdec_iq[17];
    src2 = (u32*)env->iq_c;
    for (i = 15; i != -1; i--)
        *dst2++ = *src2++;
    MDEC_in((u_long*)mdec_iq, 32);
    MDEC_in((u_long*)mdec_coef, 32);
    return env;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTBufSize);

int DecDCTBufSize(u_long* bs) { return *(u_short*)bs; }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTin);

void DecDCTin(u_long* buf, int mode) {
    if (mode & 1)
        *(u32*)buf &= ~0x08000000;
    else
        *(u32*)buf |= 0x08000000;
    if (mode & 2)
        *(u32*)buf |= 0x02000000;
    else
        *(u32*)buf &= ~0x02000000;
    MDEC_in(buf, *(u_short*)buf);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTout);

void DecDCTout(u_long* buf, int size) { MDEC_out(buf, size); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTinSync);

int DecDCTinSync(int mode) {
    int result;
    if (mode == 0)
        result = MDEC_in_sync();
    else
        result = (MDEC_status() >> 29) & 1;
    return result;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCToutSync);

int DecDCToutSync(int mode) {
    int result;
    if (mode == 0)
        result = MDEC_out_sync();
    else
        result = (MDEC_status() >> 24) & 1;
    return result;
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCTinCallback);

int DecDCTinCallback(void (*cb)()) { return DMACallback(0, cb); }

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", DecDCToutCallback);

int DecDCToutCallback(void (*cb)()) { return DMACallback(1, cb); }

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_reset);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_in);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_out);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_in_sync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_out_sync);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", MDEC_status);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", timeout);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libpress/libpress", func_8005D748);
