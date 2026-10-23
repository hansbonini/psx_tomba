.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel __SN_ENTRY_POINT
    lui        $v0, %hi(D_8009AFB0)
    addiu      $v0, $v0, %lo(D_8009AFB0)
    lui        $v1, %hi(LOAD_BUFFER)
    addiu      $v1, $v1, %lo(LOAD_BUFFER)
.L__SN_ENTRY_POINT_1:
    sw         $zero, 0x0($v0)
    addiu      $v0, $v0, 0x4
    sltu       $at, $v0, $v1
    bnez       $at, .L__SN_ENTRY_POINT_1
     nop
    lui        $v0, %hi(_ramsize)
    lw         $v0, %lo(_ramsize)($v0)
    nop
    addi       $v0, $v0, -0x8
    lui        $t0, 0x8000
    or         $sp, $v0, $t0
    lui        $a0, %hi(LOAD_BUFFER)
    addiu      $a0, $a0, %lo(LOAD_BUFFER)
    sll        $a0, $a0, 3
    srl        $a0, $a0, 3
    lui        $v1, %hi(_stacksize)
    lw         $v1, %lo(_stacksize)($v1)
    nop
    subu       $a1, $v0, $v1
    subu       $a1, $a1, $a0
    lui        $at, %hi(D_800975C0)
    sw         $a1, %lo(D_800975C0)($at)
    or         $a0, $a0, $t0
    lui        $at, %hi(D_800975BC)
    sw         $a0, %lo(D_800975BC)($at)
    lui        $at, %hi(D_8009AFE0)
    sw         $ra, %lo(D_8009AFE0)($at)
    lui        $gp, %hi(_gp)
    addiu      $gp, $gp, %lo(_gp)
    addu       $fp, $sp, $zero
    jal        InitHeap
     addi       $a0, $a0, 4
    lui        $ra, %hi(D_8009AFE0)
    lw         $ra, %lo(D_8009AFE0)($ra)
    nop
    jal        main
     nop
    break      0, 1
endlabel __SN_ENTRY_POINT

glabel __main
    lui        $t0, %hi(D_800975B8)
    lw         $t0, %lo(D_800975B8)($t0)
    addiu      $sp, $sp, -0x10
    sw         $s0, 0x4($sp)
    sw         $s1, 0x8($sp)
    sw         $ra, 0xC($sp)
    bnez       $t0, .L__main_2
     ori        $t0, $zero, 0x1
    lui        $at, %hi(D_800975B8)
    sw         $t0, %lo(D_800975B8)($at)
    lui        $s0, %hi(D_80010000)
    addiu      $s0, $s0, %lo(D_80010000)
    lui        $s1, 0
    addiu      $s1, $s1, 0x0
    beqz       $s1, .L__main_2
     nop
.L__main_1:
    lw         $t0, 0x0($s0)
    addiu      $s0, $s0, 0x4
    jalr       $t0
     addiu      $s1, $s1, -0x1
    bnez       $s1, .L__main_1
     nop
.L__main_2:
    lw         $ra, 0xC($sp)
    lw         $s1, 0x8($sp)
    lw         $s0, 0x4($sp)
    addiu      $sp, $sp, 0x10
    jr         $ra
     nop
endlabel __main

glabel __do_global_dtors
    lui        $t0, %hi(D_800975B8)
    lw         $t0, %lo(D_800975B8)($t0)
    addiu      $sp, $sp, -0x10
    sw         $s0, 0x4($sp)
    sw         $s1, 0x8($sp)
    sw         $ra, 0xC($sp)
    beqz       $t0, .L__do_global_dtors_2
     nop
    lui        $s0, %hi(D_80010000)
    addiu      $s0, $s0, %lo(D_80010000)
    lui        $s1, 0
    addiu      $s1, $s1, 0x0
    beqz       $s1, .L__do_global_dtors_2
     nop
.L__do_global_dtors_1:
    lw         $t0, 0x0($s0)
    addiu      $s0, $s0, 0x4
    jalr       $t0
     addiu      $s1, $s1, -0x1
    bnez       $s1, .L__do_global_dtors_1
     nop
.L__do_global_dtors_2:
    lw         $ra, 0xC($sp)
    lw         $s1, 0x8($sp)
    lw         $s0, 0x4($sp)
    addiu      $sp, $sp, 0x10
    jr         $ra
     nop
endlabel __do_global_dtors
