#include "common.h"
#include "psyq/libgte.h"
#include "psyq/gtemac.h"
#include "psyq/inline_c.h"

#define gte_SetTransMatrix(r0)                                                 \
    __asm__ volatile(                                                          \
        "lw	$8, 20( %0 );"                                                     \
        "lw	$9, 24( %0 );"                                                     \
        "lw	$10, 28( %0 );"                                                    \
        "ctc2	$8, $5;"                                                       \
        "ctc2	$9, $6;"                                                       \
        "ctc2	$10, $7"                                                       \
        :                                                                      \
        : "r"(r0)                                                              \
        : "$8", "$9", "$10")
#define gte_ldrgb1(r0) __asm__ volatile("lwc2	$20, 0( %0 )" : : "r"(r0))
#define gte_ldrgb2(r0) __asm__ volatile("lwc2	$21, 0( %0 )" : : "r"(r0))
#define gte_ldrgb3(r0) __asm__ volatile("lwc2	$22, 0( %0 )" : : "r"(r0))
#define gte_ldsv_(r0, r1, r2)                                                  \
    __asm__ volatile("mtc2	%0, $9;"                                           \
                     "mtc2	%1, $10;"                                          \
                     "mtc2	%2, $11"                                           \
                     :                                                         \
                     : "r"(r0), "r"(r1), "r"(r2))
#define gte_ldMAC1(r0) __asm__ volatile("mtc2	%0, $25" : : "r"(r0))
#define gte_ldMAC2(r0) __asm__ volatile("mtc2	%0, $26" : : "r"(r0))
#define gte_ldMAC3(r0) __asm__ volatile("mtc2	%0, $27" : : "r"(r0))
#define gte_ldDQA(r0) __asm__ volatile("ctc2	%0, $27" : : "r"(r0))
#define gte_ldDQB(r0) __asm__ volatile("ctc2	%0, $28" : : "r"(r0))

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetTransMatrix);
void SetTransMatrix(MATRIX* m) {
    gte_SetTransMatrix(m);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex0);
void SetVertex0(SVECTOR* r0) {
    gte_ldv0(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex1);
void SetVertex1(SVECTOR* r0) {
    gte_ldv1(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex2);
void SetVertex2(SVECTOR* r0) {
    gte_ldv2(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertexTri);
void SetVertexTri(SVECTOR* r0, SVECTOR* r1, SVECTOR* r2) {
    gte_ldv3(r0, r1, r2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetRGBfifo);
void SetRGBfifo(int r0, int r1, int r2) {
    gte_ldrgb1(r0);
    gte_ldrgb2(r1);
    gte_ldrgb3(r2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetIR123);
void SetIR123(int r0, int r1, int r2)
{
    gte_ldsv_(r0,r1,r2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetIR0);
void SetIR0(int r0) {
    gte_lddp(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSZfifo3);
void SetSZfifo3(int r0, int r1, int r2) {
    gte_ldsz3(r0,r1,r2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSZfifo4);
void SetSZfifo4(int r0, int r1, int r2, int r3) {
    gte_ldsz4(r0,r1,r2,r3);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSXSYfifo);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetRii);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetMAC123);
void SetMAC123(int r0, int r1, int r2)
{
    gte_ldMAC1(r0);
    gte_ldMAC2(r1);
    gte_ldMAC3(r2);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetData32);
void SetData32(int r0) {
    gte_ldlzc(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetDQA);
void SetDQA(int r0) {
    gte_ldDQA(r0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetDQB);
void SetDQB(int r0) {
    gte_ldDQB(r0);
}
