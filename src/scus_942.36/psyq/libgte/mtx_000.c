#include "common.h"
#include "psyq/libgte.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_000", MulMatrix0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_000", ApplyMatrixLV);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_000", ApplyRotMatrix);

VECTOR *ApplyMatrix(MATRIX *matrix, SVECTOR *v, VECTOR *out) {
	register VECTOR *result asm("$2");

	__asm__ volatile("lw $8, 0($4)\n\tlw $9, 4($4)\n\t"
					 "lw $10, 8($4)\n\tlw $11, 12($4)\n\tlw $12, 16($4)\n\t"
					 "ctc2 $8, $0\n\tctc2 $9, $1\n\tctc2 $10, $2\n\t"
					 "ctc2 $11, $3\n\tctc2 $12, $4\n\t"
					 "lwc2 $0, 0($5)\n\tlwc2 $1, 4($5)\n\tnop\n\t"
					 ".word 0x4A486012\n\t"
					 "swc2 $25, 0($6)\n\tswc2 $26, 4($6)\n\tswc2 $27, 8($6)\n\t"
					 "addu $2, $6, $zero"
					 : "=r"(result) : : "$8", "$9", "$10", "$11", "$12", "memory");
	return result;
}

SVECTOR *ApplyMatrixSV(MATRIX *matrix, SVECTOR *v, SVECTOR *out) {
	register SVECTOR *result asm("$2");

	__asm__ volatile("lw $8, 0($4)\n\tlw $9, 4($4)\n\t"
					 "lw $10, 8($4)\n\tlw $11, 12($4)\n\tlw $12, 16($4)\n\t"
					 "ctc2 $8, $0\n\tctc2 $9, $1\n\tctc2 $10, $2\n\t"
					 "ctc2 $11, $3\n\tctc2 $12, $4\n\t"
					 "lwc2 $0, 0($5)\n\tlwc2 $1, 4($5)\n\tnop\n\t"
					 ".word 0x4A486012\n\t"
					 "mfc2 $8, $9\n\tmfc2 $9, $10\n\tmfc2 $10, $11\n\t"
					 "sh $8, 0($6)\n\tsh $9, 2($6)\n\tsh $10, 4($6)\n\t"
					 "addu $2, $6, $zero"
					 : "=r"(result) : : "$8", "$9", "$10", "$11", "$12", "memory");
	return result;
}

__asm__("nop");

INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/mtx_000", ScaleMatrix);
