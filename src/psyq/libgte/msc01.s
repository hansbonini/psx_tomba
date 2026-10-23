.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel SquareRoot0
    mtc2       $a0, $30
    nop
    nop
    mfc2       $v0, $31
    addiu      $at, $zero, 0x20
    beq        $v0, $at, .LSquareRoot0_3
     nop
    andi       $t0, $v0, 0x1
    addiu      $t2, $zero, -0x2
    and        $t2, $v0, $t2
    addiu      $t1, $zero, 0x1F
    sub        $t1, $t1, $t2
    sra        $t1, $t1, 1
    addi       $t3, $t2, -0x18
    bltz       $t3, .LSquareRoot0_1
     nop
    sllv       $t4, $a0, $t3
    b          .LSquareRoot0_2
.LSquareRoot0_1:
     addiu      $t3, $zero, 0x18
    sub        $t3, $t3, $t2
    srav       $t4, $a0, $t3
.LSquareRoot0_2:
    addi       $t4, $t4, -0x40
    sll        $t4, $t4, 1
    lui        $t5, %hi(D_800915D0)
    addu       $t5, $t5, $t4
    lh         $t5, %lo(D_800915D0)($t5)
    nop
    sllv       $t5, $t5, $t1
    srl        $v0, $t5, 12
    jr         $ra
     nop
.LSquareRoot0_3:
    jr         $ra
     addiu      $v0, $zero, 0x0
endlabel SquareRoot0
    nop
    nop
    nop
