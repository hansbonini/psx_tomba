#include "common.h"

extern void* D_800915C0;
void func_80064594();

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/psyq/libgte/msc00", InitGeom);

void InitGeom() {
    int status;

    __asm__("sw $ra,%0; jal %1; nop; lw $ra,%0; nop;" : : "m"(D_800915C0), "i"(func_80064594));
    __asm__("mfc0 %0,$12" : "=r"(status));
    status |= 0x40000000;
    __asm__("mtc0 %0,$12; nop" : : "r"(status));
    __asm__("li $t0, %0
 ctc2 $t0, $29
 nop
" : : "i"(0x155) : "t0");
    __asm__("li $t0, %0
 ctc2 $t0, $30
 nop
" : : "i"(0x100) : "t0");
    __asm__("li $t0, %0
 ctc2 $t0, $26
 nop
" : : "i"(0x3E8) : "t0");
    __asm__("li $t0, %0
 ctc2 $t0, $27
 nop
" : : "i"(-0x1062) : "t0");
    __asm__("li $t0, %0
 ctc2 $t0, $28
 nop
" : : "i"(0x1400000) : "t0");
    __asm__("ctc2 $0,$24
");
    __asm__("ctc2 $0,$25
");
    __asm__("nop");
}

__asm__("nop");
__asm__("nop");
