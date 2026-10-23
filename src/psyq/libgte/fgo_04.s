.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel RotMatrixX
    addu       $t7, $a0, $zero
    addu       $v0, $a1, $zero
    bgez       $t7, .LRotMatrixX_2
     andi       $t9, $t7, 0xFFF
    negu       $t7, $t7
    bgez       $t7, .LRotMatrixX_1
     andi       $t7, $t7, 0xFFF
.LRotMatrixX_1:
    sll        $t8, $t7, 2
    lui        $t9, %hi(D_80091750)
    addu       $t9, $t9, $t8
    lw         $t9, %lo(D_80091750)($t9)
    nop
    sll        $t6, $t9, 16
    sra        $t6, $t6, 16
    negu       $t1, $t6
    j          .LRotMatrixX_3
     sra        $t0, $t9, 16
.LRotMatrixX_2:
    sll        $t8, $t9, 2
    lui        $t9, %hi(D_80091750)
    addu       $t9, $t9, $t8
    lw         $t9, %lo(D_80091750)($t9)
    nop
    sll        $t8, $t9, 16
    sra        $t1, $t8, 16
    sra        $t0, $t9, 16
.LRotMatrixX_3:
    lh         $t2, 0x6($a1)
    lh         $t5, 0xC($a1)
    multu      $t0, $t2
    lh         $t3, 0x8($a1)
    lh         $t6, 0xE($a1)
    mflo       $t8
    lh         $t4, 0xA($a1)
    lh         $t7, 0x10($a1)
    multu      $t1, $t5
    nop
    nop
    mflo       $t9
    subu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    multu      $t0, $t3
    sh         $t8, 0x6($a1)
    nop
    mflo       $t8
    nop
    nop
    multu      $t1, $t6
    nop
    nop
    mflo       $t9
    subu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    multu      $t0, $t4
    sh         $t8, 0x8($a1)
    nop
    mflo       $t8
    nop
    nop
    multu      $t1, $t7
    nop
    nop
    mflo       $t9
    subu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    multu      $t1, $t2
    sh         $t8, 0xA($a1)
    nop
    mflo       $t8
    nop
    nop
    multu      $t0, $t5
    nop
    nop
    mflo       $t9
    addu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    multu      $t1, $t3
    sh         $t8, 0xC($a1)
    nop
    mflo       $t8
    nop
    nop
    multu      $t0, $t6
    nop
    nop
    mflo       $t9
    addu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    multu      $t1, $t4
    sh         $t8, 0xE($a1)
    nop
    mflo       $t8
    nop
    nop
    multu      $t0, $t7
    nop
    nop
    mflo       $t9
    addu       $t9, $t8, $t9
    sra        $t8, $t9, 12
    sh         $t8, 0x10($a1)
    jr         $ra
     nop
endlabel RotMatrixX
    nop
    nop
