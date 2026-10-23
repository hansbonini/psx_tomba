.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

.Lvlc_size:
    .word 0x00FFFFFF

glabel DecDCTvlcSize
    lui        $t0, %hi(.Lvlc_size)
    addiu      $t0, $t0, %lo(.Lvlc_size)
    addi       $at, $a0, -0x1
    blez       $at, .LDecDCTvlcSize_1
     lw         $v0, 0x0($t0)
    sll        $at, $a0, 1
    jr         $ra
     sw         $at, 0x0($t0)
.LDecDCTvlcSize_1:
    lui        $at, (0xFFFFFF >> 16)
    ori        $at, $at, (0xFFFFFF & 0xFFFF)
    jr         $ra
     sw         $at, 0x0($t0)
endlabel DecDCTvlcSize

glabel DecDCTvlc
    lui        $t0, %hi(.Lvlc_size)
    addiu      $t0, $t0, %lo(.Lvlc_size)
    lui        $a2, %hi(D_8008044C)
    addiu      $a2, $a2, %lo(D_8008044C)
    lui        $a3, %hi(D_8009044C)
    addiu      $a3, $a3, %lo(D_8009044C)
    bnez       $a0, .LDecDCTvlc_1
     lw         $t1, 0x0($t0)
    lui        $t0, %hi(.LD_8005DABC)
    addiu      $t0, $t0, %lo(.LD_8005DABC)
    lw         $a0, 0x0($t0)
    lw         $a1, 0x4($t0)
    lw         $v0, 0x8($t0)
    lw         $v1, 0xC($t0)
    lw         $t4, 0x10($t0)
    lw         $t5, 0x14($t0)
    lw         $t7, 0x18($t0)
    lw         $t8, 0x1C($t0)
    lw         $t9, 0x20($t0)
    add        $t1, $t1, $t1
    bgez       $zero, .LDecDCTvlc_14
     add        $t6, $a1, $t1
.LDecDCTvlc_1:
    add        $t5, $zero, $zero
    add        $t7, $zero, $zero
    add        $t8, $zero, $zero
    add        $t9, $zero, $zero
    add        $t1, $t1, $t1
    add        $t6, $a1, $t1
    lhu        $t0, 0x0($a0)
    lhu        $t1, 0x2($a0)
    lhu        $t4, 0x4($a0)
    lhu        $t2, 0x6($a0)
    lhu        $v0, 0x8($a0)
    lhu        $v1, 0xA($a0)
    addi       $t2, $t2, -0x3
    bltz       $t2, .LDecDCTvlc_2
     sll        $t4, $t4, 10
    addi       $t5, $zero, 0x1
.LDecDCTvlc_2:
    addi       $a0, $a0, 0xC
    sll        $v0, $v0, 16
    or         $v0, $v0, $v1
    or         $v1, $zero, $zero
    sh         $t0, 0x0($a1)
    sh         $t1, 0x2($a1)
    addi       $a1, $a1, 0x2
.LDecDCTvlc_3:
    beqz       $t5, .LDecDCTvlc_11
     srl        $t0, $v0, 22
    xori       $at, $t0, 0x3FF
    beqz       $at, .LDecDCTvlc_20
     addi       $a1, $a1, 0x2
    addi       $at, $t5, -0x3
    bltz       $at, .LDecDCTvlc_4
     addi       $at, $a2, -0x400
    addi       $at, $at, -0x400
.LDecDCTvlc_4:
    srl        $t0, $v0, 24
    sll        $t0, $t0, 2
    add        $t0, $t0, $at
    lhu        $t1, 0x0($t0)
    lhu        $t2, 0x2($t0)
    and        $t0, $zero, $zero
    beqz       $t2, .LDecDCTvlc_6
     sllv       $v0, $v0, $t1
    addi       $at, $zero, 0x20
    sub        $at, $at, $t2
    srlv       $t0, $v0, $at
    bltz       $v0, .LDecDCTvlc_5
     sllv       $v0, $v0, $t2
    addi       $t3, $zero, -0x1
    srlv       $t3, $t3, $at
    sub        $t0, $t0, $t3
.LDecDCTvlc_5:
    add        $v1, $v1, $t2
.LDecDCTvlc_6:
    add        $v1, $v1, $t1
    andi       $at, $v1, 0x10
    beqz       $at, .LDecDCTvlc_7
     andi       $v1, $v1, 0xF
    lhu        $t1, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t1, $t1, $v1
    or         $v0, $v0, $t1
.LDecDCTvlc_7:
    addi       $at, $t5, -0x2
    bgtz       $at, .LDecDCTvlc_9
     add        $t1, $t9, $t0
    beqz       $at, .LDecDCTvlc_8
     add        $t1, $t8, $t0
    add        $t1, $t7, $t0
    bgez       $zero, .LDecDCTvlc_10
     add        $t7, $t7, $t0
.LDecDCTvlc_8:
    bgez       $zero, .LDecDCTvlc_10
     add        $t8, $t8, $t0
.LDecDCTvlc_9:
    add        $t9, $t9, $t0
.LDecDCTvlc_10:
    sll        $t1, $t1, 2
    andi       $t1, $t1, 0x3FF
    or         $t1, $t4, $t1
    addi       $t5, $t5, 0x1
    addi       $at, $t5, -0x7
    bnez       $at, .LDecDCTvlc_13
     sh         $t1, 0x0($a1)
    bgez       $zero, .LDecDCTvlc_13
     addi       $t5, $t5, -0x6
.LDecDCTvlc_11:
    xori       $at, $t0, 0x1FF
    beqz       $at, .LDecDCTvlc_20
     addi       $a1, $a1, 0x2
    sll        $v0, $v0, 10
    addi       $v1, $v1, 0xA
    andi       $at, $v1, 0x10
    beqz       $at, .LDecDCTvlc_12
     andi       $v1, $v1, 0xF
    lhu        $t1, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t1, $t1, $v1
    or         $v0, $v0, $t1
.LDecDCTvlc_12:
    or         $t0, $t4, $t0
    sh         $t0, 0x0($a1)
.LDecDCTvlc_13:
    subu       $at, $a1, $t6
    bgez       $at, .LDecDCTvlc_22
     addi       $a1, $a1, 0x2
.LDecDCTvlc_14:
    srl        $t0, $v0, 19
    sll        $t0, $t0, 3
    add        $t0, $t0, $a2
    lw         $t1, 0x0($t0)
    nop
    bnez       $t1, .LDecDCTvlc_16
     andi       $at, $t1, 0xFF
    sll        $v0, $v0, 8
    addi       $v1, $v1, 0x8
    andi       $at, $v1, 0x10
    beqz       $at, .LDecDCTvlc_15
     andi       $v1, $v1, 0xF
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t0, $t0, $v1
    or         $v0, $v0, $t0
.LDecDCTvlc_15:
    srl        $t0, $v0, 23
    sll        $t0, $t0, 2
    add        $t0, $t0, $a3
    lw         $t1, 0x0($t0)
    add        $t3, $zero, $zero
    bgez       $zero, .LDecDCTvlc_17
     andi       $at, $t1, 0xFF
.LDecDCTvlc_16:
    lw         $t3, 0x4($t0)
.LDecDCTvlc_17:
    sllv       $v0, $v0, $at
    add        $v1, $v1, $at
    andi       $at, $v1, 0x10
    beqz       $at, .LDecDCTvlc_18
     andi       $v1, $v1, 0xF
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sllv       $t0, $t0, $v1
    or         $v0, $v0, $t0
.LDecDCTvlc_18:
    srl        $t1, $t1, 16
    xori       $at, $t1, 0x7C1F
    beqz       $at, .LDecDCTvlc_19
     xori       $at, $t1, 0xFE00
    beqz       $at, .LDecDCTvlc_3
     sh         $t1, 0x0($a1)
    beqz       $t3, .LDecDCTvlc_14
     addi       $a1, $a1, 0x2
    andi       $t2, $t3, 0xFFFF
    xori       $at, $t2, 0x7C1F
    beqz       $at, .LDecDCTvlc_19
     xori       $at, $t2, 0xFE00
    beqz       $at, .LDecDCTvlc_3
     sh         $t2, 0x0($a1)
    srl        $t2, $t3, 16
    beqz       $t2, .LDecDCTvlc_14
     addi       $a1, $a1, 0x2
    xori       $at, $t2, 0x7C1F
    beqz       $at, .LDecDCTvlc_19
     xori       $at, $t2, 0xFE00
    beqz       $at, .LDecDCTvlc_3
     sh         $t2, 0x0($a1)
    bgez       $zero, .LDecDCTvlc_14
     addi       $a1, $a1, 0x2
.LDecDCTvlc_19:
    srl        $t0, $v0, 16
    sh         $t0, 0x0($a1)
    addi       $a1, $a1, 0x2
    lhu        $t0, 0x0($a0)
    addi       $a0, $a0, 0x2
    sll        $v0, $v0, 16
    sllv       $t0, $t0, $v1
    bgez       $zero, .LDecDCTvlc_14
     or         $v0, $v0, $t0
.LDecDCTvlc_20:
    ori        $t0, $zero, 0xFE00
    addi       $v0, $zero, 0x40
.LDecDCTvlc_21:
    sh         $t0, 0x0($a1)
    addi       $a1, $a1, 0x2
    bnez       $v0, .LDecDCTvlc_21
     addi       $v0, $v0, -0x1
    mfc0       $t1, $12
    nop
    lui        $at, (0x20000 >> 16)
    or         $t1, $t1, $at
    mtc0       $t1, $12
    jr         $ra
     add        $v0, $zero, $zero
.LDecDCTvlc_22:
    lui        $t0, %hi(.LD_8005DABC)
    addiu      $t0, $t0, %lo(.LD_8005DABC)
    sw         $a0, 0x0($t0)
    sw         $a1, 0x4($t0)
    sw         $v0, 0x8($t0)
    sw         $v1, 0xC($t0)
    sw         $t4, 0x10($t0)
    sw         $t5, 0x14($t0)
    sw         $t7, 0x18($t0)
    sw         $t8, 0x1C($t0)
    sw         $t9, 0x20($t0)
    jr         $ra
     addi       $v0, $zero, 0x1
endlabel DecDCTvlc
.LD_8005DABC:
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
