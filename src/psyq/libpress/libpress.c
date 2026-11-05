#include "common.h"

u32 mdec_iq[33] = {
    0x40000001, 0x13101002, 0x16161310, 0x16161616,
    0x1B1A181A, 0x1A1A1B1B, 0x1B1B1A1A, 0x1D1D1D1B,
    0x1D222222, 0x1B1B1D1D, 0x20201D1D, 0x26252222,
    0x22232325, 0x28262623, 0x30302828, 0x38382E2E,
    0x5345453A, 0x13101002, 0x16161310, 0x16161616,
    0x1B1A181A, 0x1A1A1B1B, 0x1B1B1A1A, 0x1D1D1D1B,
    0x1D222222, 0x1B1B1D1D, 0x20201D1D, 0x26252222,
    0x22232325, 0x28262623, 0x30302828, 0x38382E2E,
    0x5345453A,
};
u32 mdec_coef[33] = {
    0x60000000, 0x5A825A82, 0x5A825A82, 0x5A825A82,
    0x5A825A82, 0x6A6D7D8A, 0x18F8471C, 0xB8E3E707,
    0x82759592, 0x30FB7641, 0x89BECF04, 0xCF0489BE,
    0x764130FB, 0xE7076A6D, 0xB8E38275, 0x7D8A471C,
    0x959218F8, 0xA57D5A82, 0x5A82A57D, 0xA57D5A82,
    0x5A82A57D, 0x8275471C, 0x6A6D18F8, 0xE7079592,
    0xB8E37D8A, 0x89BE30FB, 0xCF047641, 0x7641CF04,
    0x30FB89BE, 0xB8E318F8, 0x82756A6D, 0x95927D8A,
    0xE707471C,
};
u32 d0_madr_d[1] asm("d0_madr") = {
    0x1F801080,
};
u32 d0_bcr_d[1] asm("d0_bcr") = {
    0x1F801084,
};
u32 d0_chcr_d[1] asm("d0_chcr") = {
    0x1F801088,
};
u32 d1_madr_d[1] asm("d1_madr") = {
    0x1F801090,
};
u32 d1_bcr_d[1] asm("d1_bcr") = {
    0x1F801094,
};
u32 d1_chcr_d[1] asm("d1_chcr") = {
    0x1F801098,
};
u32 d2_madr_d[1] asm("d2_madr") = {
    0x1F8010A0,
};
u32 d2_bcr_d[1] asm("d2_bcr") = {
    0x1F8010A4,
};
u32 d2_chcr_d[1] asm("d2_chcr") = {
    0x1F8010A8,
};
u32 d3_madr_d[1] asm("d3_madr") = {
    0x1F8010B0,
};
u32 d3_bcr_d[1] asm("d3_bcr") = {
    0x1F8010B4,
};
u32 d3_chcr_d[1] asm("d3_chcr") = {
    0x1F8010B8,
};
u32 mdec0_d[1] asm("mdec0") = {
    0x1F801820,
};
u32 mdec1_d[1] asm("mdec1") = {
    0x1F801824,
};
u32 d_pcr_d[1] asm("d_pcr") = {
    0x1F8010F0,
};

extern u_int volatile* d1_madr;
extern u_int volatile* d1_bcr;

extern u_int volatile* d0_madr;
extern u_int volatile* d0_bcr;
extern u_int volatile* d0_chcr;
extern u_int volatile* mdec0;
extern u_int volatile* d_pcr;

extern u_int volatile* d1_chcr;
static int timeout(char* arg0);

extern volatile u_long* mdec1;

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

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTReset);

void DecDCTReset(int mode) {
    if (mode == 0)
        ResetCallback();
    MDEC_reset(mode);
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTGetEnv);

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

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTPutEnv);

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

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTBufSize);

int DecDCTBufSize(u_long* bs) { return *(u_short*)bs; }

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTin);

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

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTout);

void DecDCTout(u_long* buf, int size) { MDEC_out(buf, size); }

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTinSync);

int DecDCTinSync(int mode) {
    int result;
    if (mode == 0)
        result = MDEC_in_sync();
    else
        result = (MDEC_status() >> 29) & 1;
    return result;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCToutSync);

int DecDCToutSync(int mode) {
    int result;
    if (mode == 0)
        result = MDEC_out_sync();
    else
        result = (MDEC_status() >> 24) & 1;
    return result;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCTinCallback);

int DecDCTinCallback(void (*cb)()) { return DMACallback(0, cb); }

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", DecDCToutCallback);

int DecDCToutCallback(void (*cb)()) { return DMACallback(1, cb); }

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_reset);

void MDEC_reset(int mode) {
    switch (mode) {
    case 0:
        *mdec1 = 0x80000000;
        *d0_chcr = 0;
        *d1_chcr = 0;
        *mdec1 = 0x60000000;
        MDEC_in((u_long*)mdec_iq, 32);
        MDEC_in((u_long*)mdec_coef, 32);
        return;
    case 1:
        *mdec1 = 0x80000000;
        *d0_chcr = 0;
        *d1_chcr = 0;
        *d1_chcr;
        *mdec1 = 0x60000000;
        return;
    default:
        printf("MDEC_rest:bad option(%d)\n", mode);
        return;
    }
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_in);

void MDEC_in(u_long* buf, int size) {
    MDEC_in_sync();
    *d_pcr |= 0x88;
    *d0_madr = (u_int)(buf + 1);
    *d0_bcr = (((u_int)size >> 5) << 0x10) | 0x20;
    *mdec0 = *buf;
    *d0_chcr = 0x01000201;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_out);

void MDEC_out(u_long* buf, int size) {
    MDEC_out_sync();
    *d_pcr |= 0x88;
    *d1_chcr = 0;
    *d1_madr = (u_int)buf;
    *d1_bcr = (((u_int)size >> 5) << 0x10) | 0x20;
    *d1_chcr = 0x01000200;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_in_sync);

int MDEC_in_sync(void) {
    volatile int retries = 0x100000;

    while (*mdec1 & 0x20000000) {
        if (--retries == -1) {
            timeout("MDEC_in_sync");
            return -1;
        }
    }

    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_out_sync);

int MDEC_out_sync(void)
{
    volatile int retries = 0x100000;

    while (*d1_chcr & 0x01000000) {
        if (--retries == -1) {
            timeout("MDEC_out_sync");
            return -1;
        }
    }

    return 0;
}

// INCLUDE_ASM("nonmatchings/psyq/libpress/libpress", MDEC_status);

u_long MDEC_status(void) { return *mdec1; }

static inline void print_status(void) {
    u_long stat;

    stat = *mdec1;
    printf("	 DMA=(%d,%d), ADDR=(0x%08x->0x%08x)
", (*d0_chcr >> 24) & 1,
           (*d1_chcr >> 24) & 1, *d0_madr, *d1_madr);
    printf("	 FIFO=(%d,%d),BUSY=%d,DREQ=(%d,%d),RGB24=%d,STP=%d
",
           ~stat >> 31, (stat >> 30) & 1, (stat >> 29) & 1, (stat >> 28) & 1,
           (stat >> 27) & 1, (stat >> 25) & 1, (stat >> 23) & 1);
}

static int timeout(char* arg0) {
    printf("%s timeout:
", arg0);
    print_status();
    *mdec1 = 0x80000000;
    *d0_chcr = 0;
    *d1_chcr = 0;
    *d1_chcr;
    *mdec1 = 0x60000000;
    return 0;
}
