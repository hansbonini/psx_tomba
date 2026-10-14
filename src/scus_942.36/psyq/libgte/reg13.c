#include "common.h"

void SetGeomScreen(int h) {
    __asm__ volatile("ctc2 %0, $26" : : "r"(h));
}

__asm__("nop");

void LightColor(void *input, void *output) {
    register void *source asm("$4") = input;
    register void *destination asm("$5") = output;

    __asm__ volatile("lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)\n\t"
                     "nop\n\t.word 0x4A4DA412\n\t"
                     "swc2 $9, 0(%1)\n\tswc2 $10, 4(%1)\n\tswc2 $11, 8(%1)"
                     : : "r"(source), "r"(destination) : "memory");
}

void DpqColorLight(void *input, void *color, int depth, void *output) {
    register void *source asm("$4") = input;
    register void *rgb asm("$5") = color;
    register int interpolation asm("$6") = depth;
    register void *destination asm("$7") = output;

    __asm__ volatile("lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)\n\t"
                     "lwc2 $6, 0(%1)\n\t.word 0x48864000\n\tnop\n\t"
                     ".word 0x4A680029\n\tswc2 $22, 0(%3)"
                     : : "r"(source), "r"(rgb), "r"(interpolation), "r"(destination)
                     : "memory");
}

void DpqColor3(void *rgb0, void *rgb1, void *rgb2, int interpolation,
               void *volatile out0, void *volatile out1,
               void *volatile out2) {
    __asm__ volatile("lwc2 $20, 0($4)\n\tlwc2 $21, 0($5)\n\t"
                     "lwc2 $22, 0($6)\n\tlwc2 $6, 0($6)\n\t"
                     "mtc2 $7, $8\n\tnop\n\t.word 0x4AF8002A\n\t"
                     "lw $8, 16($sp)\n\tlw $9, 20($sp)\n\tlw $10, 24($sp)\n\t"
                     "swc2 $20, 0($8)\n\tswc2 $21, 0($9)\n\tswc2 $22, 0($10)"
                     : : : "$8", "$9", "$10", "memory");
}

void Intpl(void *input, int depth, void *output) {
    register void *source asm("$4") = input;
    register int interpolation asm("$5") = depth;
    register void *destination asm("$6") = output;

    __asm__ volatile("lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)\n\t"
                     "mtc2 %1, $8\n\tnop\n\t.word 0x4A980011\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(source), "r"(interpolation), "r"(destination)
                     : "memory");
}

void *Square12(void *input, void *output) {
    register void *result asm("$5") = output;

    __asm__ volatile("lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)"
                     : : "r"(input));
    __asm__ volatile("nop\n\t.word 0x4AA80428");
    __asm__ volatile("swc2 $25, 0(%0)\n\tswc2 $26, 4(%0)\n\tswc2 $27, 8(%0)"
                     : : "r"(result) : "memory");
    return result;
}

void *Square0(void *input, void *output) {
    register void *result asm("$5") = output;

    __asm__ volatile("lwc2 $9, 0(%0)\n\tlwc2 $10, 4(%0)\n\tlwc2 $11, 8(%0)"
                     : : "r"(input));
    __asm__ volatile("nop\n\t.word 0x4AA00428");
    __asm__ volatile("swc2 $25, 0(%0)\n\tswc2 $26, 4(%0)\n\tswc2 $27, 8(%0)"
                     : : "r"(result) : "memory");
    return result;
}

int AverageZ3(int z1, int z2, int z3) {
    int result;

    __asm__ volatile("mtc2 %0, $17\n\tmtc2 %1, $18\n\tmtc2 %2, $19"
                     : : "r"(z1), "r"(z2), "r"(z3));
    __asm__ volatile("nop\n\t.word 0x4B58002D");
    __asm__ volatile("mfc2 %0, $7" : "=r"(result));
    return result;
}

int AverageZ4(int z0, int z1, int z2, int z3) {
    int result;

    __asm__ volatile("mtc2 %0, $16\n\tmtc2 %1, $17\n\tmtc2 %2, $18\n\tmtc2 %3, $19"
                     : : "r"(z0), "r"(z1), "r"(z2), "r"(z3));
    __asm__ volatile("nop\n\t.word 0x4B68002E");
    __asm__ volatile("mfc2 %0, $7" : "=r"(result));
    return result;
}

void OuterProduct12(void *matrix_column, void *vector, void *output) {
    register void *matrix asm("$4") = matrix_column;
    register void *input asm("$5") = vector;
    register void *result asm("$6") = output;

    __asm__ volatile("cfc2 $13, $0\n\tcfc2 $14, $2\n\tcfc2 $15, $4\n\t"
                     "lw $8, 0(%0)\n\tlw $9, 4(%0)\n\tlw $10, 8(%0)\n\t"
                     "ctc2 $8, $0\n\tctc2 $9, $2\n\tctc2 $10, $4\n\t"
                     "lwc2 $11, 8(%1)\n\tlwc2 $9, 0(%1)\n\tlwc2 $10, 4(%1)\n\t"
                     "nop\n\t.word 0x4B78000C\n\t"
                     "swc2 $25, 0(%2)\n\tswc2 $26, 4(%2)\n\tswc2 $27, 8(%2)\n\t"
                     "ctc2 $13, $0\n\tctc2 $14, $2\n\tctc2 $15, $4"
                     : : "r"(matrix), "r"(input), "r"(result)
                     : "$8", "$9", "$10", "$11", "$13", "$14", "$15", "memory");
}

void OuterProduct0(void *matrix_column, void *vector, void *output) {
    register void *matrix asm("$4") = matrix_column;
    register void *input asm("$5") = vector;
    register void *result asm("$6") = output;

    __asm__ volatile("cfc2 $13, $0\n\tcfc2 $14, $2\n\tcfc2 $15, $4\n\t"
                     "lw $8, 0(%0)\n\tlw $9, 4(%0)\n\tlw $10, 8(%0)\n\t"
                     "ctc2 $8, $0\n\tctc2 $9, $2\n\tctc2 $10, $4\n\t"
                     "lwc2 $11, 8(%1)\n\tlwc2 $9, 0(%1)\n\tlwc2 $10, 4(%1)\n\t"
                     "nop\n\t.word 0x4B70000C\n\t"
                     "swc2 $25, 0(%2)\n\tswc2 $26, 4(%2)\n\tswc2 $27, 8(%2)\n\t"
                     "ctc2 $13, $0\n\tctc2 $14, $2\n\tctc2 $15, $4"
                     : : "r"(matrix), "r"(input), "r"(result)
                     : "$8", "$9", "$10", "$11", "$13", "$14", "$15", "memory");
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", Lzc);

long Lzc(long data) {
    long result;

    __asm__ volatile("mtc2 %0, $30" : : "r"(data));
    __asm__ volatile("nop");
    __asm__ volatile("nop");
    __asm__ volatile("mfc2 %0, $31" : "=r"(result));
    return result;
}

__asm__("nop");

int RotTransPers(const void *v, s32 *sxy, s32 *p, s32 *flag) {
    register int result asm("$2");

    __asm__ volatile("lwc2 $0, 0($4)\n\tlwc2 $1, 4($4)\n\tnop\n\t"
                     ".word 0x4A180001\n\tswc2 $14, 0($5)\n\t"
                     "swc2 $8, 0($6)\n\tcfc2 $3, $31\n\tmfc2 $2, $19\n\t"
                     "sw $3, 0($7)"
                     : "=r"(result) : : "$3", "memory");
    return result >> 2;
}

__asm__("nop");

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/reg13", RotMatrix);
