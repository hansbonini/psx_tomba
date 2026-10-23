.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel MulMatrix0
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lhu        $t0, 0x0($a1)
    lw         $t1, 0x4($a1)
    lw         $t2, 0xC($a1)
    lui        $at, (0xFFFF0000 >> 16)
    and        $t1, $t1, $at
    or         $t0, $t0, $t1
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    lhu        $t0, 0x2($a1)
    lw         $t1, 0x8($a1)
    lh         $t2, 0xE($a1)
    sll        $t1, $t1, 16
    or         $t0, $t0, $t1
    mfc2       $t3, $9
    mfc2       $t4, $10
    mfc2       $t5, $11
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    lhu        $t0, 0x4($a1)
    lw         $t1, 0x8($a1)
    lw         $t2, 0x10($a1)
    lui        $at, (0xFFFF0000 >> 16)
    and        $t1, $t1, $at
    or         $t0, $t0, $t1
    mfc2       $t6, $9
    mfc2       $t7, $10
    mfc2       $t8, $11
    mtc2       $t0, $0
    mtc2       $t2, $1
    nop
    mvmva      1, 0, 0, 3, 0
    andi       $t3, $t3, 0xFFFF
    sll        $t6, $t6, 16
    or         $t6, $t6, $t3
    sw         $t6, 0x0($a2)
    andi       $t5, $t5, 0xFFFF
    sll        $t8, $t8, 16
    or         $t8, $t8, $t5
    sw         $t8, 0xC($a2)
    mfc2       $t0, $9
    mfc2       $t1, $10
    andi       $t0, $t0, 0xFFFF
    sll        $t4, $t4, 16
    or         $t0, $t0, $t4
    sw         $t0, 0x4($a2)
    andi       $t7, $t7, 0xFFFF
    sll        $t1, $t1, 16
    or         $t1, $t1, $t7
    sw         $t1, 0x8($a2)
    swc2       $11, 0x10($a2)
    addu       $v0, $a2, $zero
    jr         $ra
     nop
endlabel MulMatrix0
    nop

glabel ApplyMatrixLV
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lw         $t0, 0x0($a1)
    lw         $t1, 0x4($a1)
    lw         $t2, 0x8($a1)
    bgez       $t0, .LApplyMatrixLV_1
     sra        $t3, $t0, 15
    negu       $t0, $t0
    sra        $t3, $t0, 15
    andi       $t0, $t0, 0x7FFF
    negu       $t3, $t3
    b          .LApplyMatrixLV_2
     negu       $t0, $t0
    sra        $t3, $t0, 15
.LApplyMatrixLV_1:
    andi       $t0, $t0, 0x7FFF
.LApplyMatrixLV_2:
    bgez       $t1, .LApplyMatrixLV_3
     sra        $t4, $t1, 15
    negu       $t1, $t1
    sra        $t4, $t1, 15
    andi       $t1, $t1, 0x7FFF
    negu       $t4, $t4
    b          .LApplyMatrixLV_4
     negu       $t1, $t1
    sra        $t4, $t1, 15
.LApplyMatrixLV_3:
    andi       $t1, $t1, 0x7FFF
.LApplyMatrixLV_4:
    bgez       $t2, .LApplyMatrixLV_5
     sra        $t5, $t2, 15
    negu       $t2, $t2
    sra        $t5, $t2, 15
    andi       $t2, $t2, 0x7FFF
    negu       $t5, $t5
    b          .LApplyMatrixLV_6
     negu       $t2, $t2
    sra        $t5, $t2, 15
.LApplyMatrixLV_5:
    andi       $t2, $t2, 0x7FFF
.LApplyMatrixLV_6:
    mtc2       $t3, $9
    mtc2       $t4, $10
    mtc2       $t5, $11
    nop
    mvmva      0, 0, 3, 3, 0
    mfc2       $t3, $25
    mfc2       $t4, $26
    mfc2       $t5, $27
    mtc2       $t0, $9
    mtc2       $t1, $10
    mtc2       $t2, $11
    nop
    mvmva      1, 0, 3, 3, 0
    bgez       $t3, .LApplyMatrixLV_7
     nop
    negu       $t3, $t3
    sll        $t3, $t3, 3
    b          .LApplyMatrixLV_8
     negu       $t3, $t3
.LApplyMatrixLV_7:
    sll        $t3, $t3, 3
.LApplyMatrixLV_8:
    bgez       $t4, .LApplyMatrixLV_9
     nop
    negu       $t4, $t4
    sll        $t4, $t4, 3
    b          .LApplyMatrixLV_10
     negu       $t4, $t4
.LApplyMatrixLV_9:
    sll        $t4, $t4, 3
.LApplyMatrixLV_10:
    bgez       $t5, .LApplyMatrixLV_11
     nop
    negu       $t5, $t5
    sll        $t5, $t5, 3
    b          .LApplyMatrixLV_12
     negu       $t5, $t5
.LApplyMatrixLV_11:
    sll        $t5, $t5, 3
.LApplyMatrixLV_12:
    mfc2       $t0, $25
    mfc2       $t1, $26
    mfc2       $t2, $27
    addu       $t0, $t0, $t3
    addu       $t1, $t1, $t4
    addu       $t2, $t2, $t5
    sw         $t0, 0x0($a2)
    sw         $t1, 0x4($a2)
    sw         $t2, 0x8($a2)
    jr         $ra
     addu       $v0, $a2, $zero
endlabel ApplyMatrixLV

glabel ApplyRotMatrix
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    mtc2       $t0, $0
    mtc2       $t1, $1
    nop
    mvmva      1, 0, 0, 3, 0
    swc2       $9, 0x0($a1)
    swc2       $10, 0x4($a1)
    swc2       $11, 0x8($a1)
    addu       $v0, $a2, $zero
    jr         $ra
     nop
endlabel ApplyRotMatrix

glabel ApplyMatrix
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lwc2       $0, 0x0($a1)
    lwc2       $1, 0x4($a1)
    nop
    mvmva      1, 0, 0, 3, 0
    swc2       $25, 0x0($a2)
    swc2       $26, 0x4($a2)
    swc2       $27, 0x8($a2)
    addu       $v0, $a2, $zero
    jr         $ra
     nop
endlabel ApplyMatrix

glabel ApplyMatrixSV
    lw         $t0, 0x0($a0)
    lw         $t1, 0x4($a0)
    lw         $t2, 0x8($a0)
    lw         $t3, 0xC($a0)
    lw         $t4, 0x10($a0)
    ctc2       $t0, $0
    ctc2       $t1, $1
    ctc2       $t2, $2
    ctc2       $t3, $3
    ctc2       $t4, $4
    lwc2       $0, 0x0($a1)
    lwc2       $1, 0x4($a1)
    nop
    mvmva      1, 0, 0, 3, 0
    mfc2       $t0, $9
    mfc2       $t1, $10
    mfc2       $t2, $11
    sh         $t0, 0x0($a2)
    sh         $t1, 0x2($a2)
    sh         $t2, 0x4($a2)
    addu       $v0, $a2, $zero
    jr         $ra
     nop
endlabel ApplyMatrixSV
    nop

glabel ScaleMatrix
    lw         $t0, 0x0($a0)
    lw         $t3, 0x0($a1)
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t3
    lw         $t4, 0x4($a1)
    sra        $t2, $t0, 16
    lw         $t5, 0x8($a1)
    lw         $t0, 0x4($a0)
    addu       $v0, $a0, $zero
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    multu      $t2, $t4
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x0($a0)
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t5
    sra        $t2, $t0, 16
    lw         $t0, 0x8($a0)
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    multu      $t2, $t3
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x4($a0)
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t4
    sra        $t2, $t0, 16
    lw         $t0, 0xC($a0)
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    multu      $t2, $t5
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0x8($a0)
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t3
    sra        $t2, $t0, 16
    lw         $t0, 0x10($a0)
    mflo       $t1
    sra        $t1, $t1, 12
    andi       $t1, $t1, 0xFFFF
    multu      $t2, $t4
    mflo       $t2
    sra        $t2, $t2, 12
    sll        $t2, $t2, 16
    or         $t1, $t1, $t2
    sw         $t1, 0xC($a0)
    andi       $t1, $t0, 0xFFFF
    sll        $t1, $t1, 16
    sra        $t1, $t1, 16
    multu      $t1, $t5
    mflo       $t1
    sra        $t1, $t1, 12
    jr         $ra
     sw         $t1, 0x10($a0)
endlabel ScaleMatrix
    nop
    nop
    nop
