#include "common.h"
#include "psyq/gtemac.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetTransMatrix);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex1);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertex2);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetVertexTri);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetRGBfifo);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetIR123);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetIR0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSZfifo3);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSZfifo4);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetSXSYfifo);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetRii);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetMAC123);
void SetMAC123(void)
{
    __asm__("mtc2 $a0, $25");
    __asm__("mtc2 $a1, $26");
    __asm__("mtc2 $a2, $27");
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetData32);
void SetData32(void) {
    __asm__("mtc2 $a0, $30");
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetDQA);
void SetDQA(int arg0) {
    __asm__("ctc2 %0, $27"::"r"(arg0));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_12", SetDQB);
void SetDQB(int arg0) {
    __asm__("ctc2 %0, $28"::"r"(arg0));
}
