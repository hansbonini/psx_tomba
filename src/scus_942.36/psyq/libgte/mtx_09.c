#include "common.h"

void SetRotMatrix(void *matrix) {
	__asm__ volatile("lw $8, 0($4)\n\tlw $9, 4($4)\n\t"
					 "lw $10, 8($4)\n\tlw $11, 12($4)\n\tlw $12, 16($4)\n\t"
					 "ctc2 $8, $0\n\tctc2 $9, $1\n\tctc2 $10, $2\n\t"
					 "ctc2 $11, $3\n\tctc2 $12, $4");
}

void SetLightMatrix(void *matrix) {
	__asm__ volatile("lw $8, 0($4)\n\tlw $9, 4($4)\n\t"
					 "lw $10, 8($4)\n\tlw $11, 12($4)\n\tlw $12, 16($4)\n\t"
					 "ctc2 $8, $8\n\tctc2 $9, $9\n\tctc2 $10, $10\n\t"
					 "ctc2 $11, $11\n\tctc2 $12, $12");
}

void SetColorMatrix(void *matrix) {
	__asm__ volatile("lw $8, 0($4)\n\tlw $9, 4($4)\n\t"
					 "lw $10, 8($4)\n\tlw $11, 12($4)\n\tlw $12, 16($4)\n\t"
					 "ctc2 $8, $16\n\tctc2 $9, $17\n\tctc2 $10, $18\n\t"
					 "ctc2 $11, $19\n\tctc2 $12, $20");
}
