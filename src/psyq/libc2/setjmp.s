.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel setjmp
    sw         $ra, 0x0($a0)
    sw         $gp, 0x2C($a0)
    sw         $sp, 0x4($a0)
    sw         $fp, 0x8($a0)
    sw         $s0, 0xC($a0)
    sw         $s1, 0x10($a0)
    sw         $s2, 0x14($a0)
    sw         $s3, 0x18($a0)
    sw         $s4, 0x1C($a0)
    sw         $s5, 0x20($a0)
    sw         $s6, 0x24($a0)
    sw         $s7, 0x28($a0)
    addu       $v0, $zero, $zero
    jr         $ra
     nop
endlabel setjmp

glabel longjmp
    lw         $ra, 0x0($a0)
    lw         $gp, 0x2C($a0)
    lw         $sp, 0x4($a0)
    lw         $fp, 0x8($a0)
    lw         $s0, 0xC($a0)
    lw         $s1, 0x10($a0)
    lw         $s2, 0x14($a0)
    lw         $s3, 0x18($a0)
    lw         $s4, 0x1C($a0)
    lw         $s5, 0x20($a0)
    lw         $s6, 0x24($a0)
    lw         $s7, 0x28($a0)
    addu       $v0, $a1, $zero
    jr         $ra
     nop
endlabel longjmp
    nop
    nop
