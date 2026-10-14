#include "common.h"

typedef struct {
    short m[3][3];
    long t[3];
} Reg13Matrix;

typedef struct {
    short vx, vy, vz, pad;
} Reg13ShortVector;

extern u32 D_80091750[];

#define GTE_SINE_WORD_AT_OFFSET(byte_offset) ({ \
    register s32 table_word asm("$25"); \
    asm volatile("lui $25, %%hi(D_80091750)\n\t" \
                 "addu $25, $25, %1\n\t" \
                 "lw $25, %%lo(D_80091750)($25)" \
                 : "=r"(table_word) : "r"(byte_offset)); \
    table_word; \
})
#define GTE_MULTU(a, b) ((unsigned long long)(u32)(a) * (u32)(b))
#define GTE_NOP_MEMORY_DEP(constraint, value) \
    asm volatile("nop" : : constraint(value) : "memory")

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

Reg13Matrix *RotMatrix(Reg13ShortVector *angles, Reg13Matrix *matrix) {
    register Reg13Matrix *result;
    unsigned long long product;
    unsigned low;
    register s32 cx asm("$8");
    register s32 cy asm("$9");
    register s32 cz asm("$10");
    register s32 sx asm("$11");
    register s32 negative_sy asm("$12");
    register s32 sz asm("$13");
    register s32 value asm("$14");
    register s32 angle asm("$15");
    register s32 temp asm("$24");
    register s32 word asm("$25");

    angle = angles->vx;
    result = matrix;
    word = angle & 0xFFF;
    if (angle < 0) {
        angle = 0U - angle;
        if (angle < 0)
            asm volatile("" : : : "15");
        else
            angle &= 0xfff;
        asm volatile("" : : : "24");

        temp = angle << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        temp = word << 16;
        temp = temp >> 16;
        sx = 0U - temp;
        cx = word >> 16;
    } else {
        temp = word << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        temp = word << 16;
        sx = temp >> 16;
        cx = word >> 16;
        asm volatile("" : "=r"(cx) : "0"(cx));
    }
x_ready:
    angle = angles->vy;
    word = angle & 0xFFF;
    if (angle < 0) {
        angle = 0U - angle;
        if (angle < 0)
            asm volatile("" : : : "15");
        else
            angle &= 0xfff;
        asm volatile("" : : : "24");

        temp = angle << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        negative_sy = word << 16;
        negative_sy = negative_sy >> 16;
        value = 0U - negative_sy;
        cy = word >> 16;
    } else {
        temp = word << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        value = word << 16;
        value = value >> 16;
        negative_sy = 0U - value;
        cy = word >> 16;
        asm volatile("" : "=r"(cy) : "0"(cy));
    }
y_ready:
    product = GTE_MULTU(cy, sx);
    angle = angles->vz;
    matrix->m[0][2] = value;
    asm volatile("" : "=l"(low) : "x"(product));
    temp = low;
    asm volatile("" : "=r"(temp) : "0"(temp));
    word = 0U - temp;
    value = word >> 12;
    product = GTE_MULTU(cy, cx);
    asm volatile("" : : "x"(product) : "memory");
    matrix->m[1][2] = value;
    word = angle & 0xFFF;
    if (angle < 0) {
        asm volatile("" : "=l"(low) : "x"(product));
        temp = low;
        asm volatile("" : "=r"(temp) : "0"(temp));
        value = temp >> 12;
        matrix->m[2][2] = value;
        angle = 0U - angle;
        asm volatile("" : "=r"(angle) : "0"(angle));
        if (angle < 0)
            asm volatile("" : : : "15");
        else
            angle &= 0xfff;
        asm volatile("" : : : "24");

        temp = angle << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        temp = word << 16;
        temp = temp >> 16;
        sz = 0U - temp;
        cz = word >> 16;
    } else {
        asm volatile("" : "=l"(low) : "x"(product));
        angle = low;
        asm volatile("" : "=r"(angle) : "0"(angle));
        value = angle >> 12;
        matrix->m[2][2] = value;
        asm volatile("" : : "m"(matrix->m[2][2]) : "memory");
        temp = word << 2;
        word = GTE_SINE_WORD_AT_OFFSET(temp);
        GTE_NOP_MEMORY_DEP("r", word);
        temp = word << 16;
        sz = temp >> 16;
        cz = word >> 16;
        asm volatile("" : "=r"(cz) : "0"(cz));
    }
z_ready:
    product = GTE_MULTU(cz, cy);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    value = angle >> 12;
    matrix->m[0][0] = value;
    asm volatile("" : : "m"(matrix->m[0][0]) : "memory");
    product = GTE_MULTU(sz, cy);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    value = 0U - angle;
    angle = value >> 12;
    asm volatile("" : "=r"(angle) : "0"(angle));
    product = GTE_MULTU(cz, negative_sy);
    matrix->m[0][1] = angle;
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    temp = angle >> 12;
    product = GTE_MULTU(temp, sx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    value = angle >> 12;
    GTE_NOP_MEMORY_DEP("r", value);
    product = GTE_MULTU(sz, cx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    word = angle >> 12;
    angle = word - value;
    asm volatile("" : "=r"(angle) : "0"(angle));
    product = GTE_MULTU(temp, cx);
    matrix->m[1][0] = angle;
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    value = low;
    asm volatile("" : "=r"(value) : "0"(value));
    angle = value >> 12;
    GTE_NOP_MEMORY_DEP("r", angle);
    product = GTE_MULTU(sz, sx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    value = low;
    asm volatile("" : "=r"(value) : "0"(value));
    word = value >> 12;
    value = word + angle;
    asm volatile("" : "=r"(value) : "0"(value));
    product = GTE_MULTU(sz, negative_sy);
    matrix->m[2][0] = value;
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    temp = angle >> 12;
    product = GTE_MULTU(temp, sx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    value = angle >> 12;
    GTE_NOP_MEMORY_DEP("r", value);
    product = GTE_MULTU(cz, cx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    angle = low;
    asm volatile("" : "=r"(angle) : "0"(angle));
    word = angle >> 12;
    angle = word + value;
    asm volatile("" : "=r"(angle) : "0"(angle));
    product = GTE_MULTU(temp, cx);
    matrix->m[1][1] = angle;
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    value = low;
    asm volatile("" : "=r"(value) : "0"(value));
    angle = value >> 12;
    GTE_NOP_MEMORY_DEP("r", angle);
    product = GTE_MULTU(cz, sx);
    GTE_NOP_MEMORY_DEP("x", product);
    GTE_NOP_MEMORY_DEP("x", product);
    asm volatile("" : "=l"(low) : "x"(product));
    value = low;
    asm volatile("" : "=r"(value) : "0"(value));
    word = value >> 12;
    value = word - angle;
    matrix->m[2][1] = value;
    asm volatile("" ::: "memory");
    return result;
}

__asm__("nop");

#undef GTE_NOP_MEMORY_DEP
#undef GTE_MULTU
#undef GTE_SINE_WORD_AT_OFFSET
