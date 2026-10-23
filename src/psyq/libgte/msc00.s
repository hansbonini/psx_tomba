.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel InitGeom
    lui        $at, %hi(D_800915C0)
    sw         $ra, %lo(D_800915C0)($at)
    jal        _patch_gte
     nop
    lui        $ra, %hi(D_800915C0)
    lw         $ra, %lo(D_800915C0)($ra)
    nop
    mfc0       $v0, $12
    lui        $v1, (0x40000000 >> 16)
    or         $v0, $v0, $v1
    mtc0       $v0, $12
    nop
    addiu      $t0, $zero, 0x155
    ctc2       $t0, $29
    nop
    addiu      $t0, $zero, 0x100
    ctc2       $t0, $30
    nop
    addiu      $t0, $zero, 0x3E8
    ctc2       $t0, $26
    nop
    addiu      $t0, $zero, -0x1062
    ctc2       $t0, $27
    nop
    lui        $t0, (0x1400000 >> 16)
    ctc2       $t0, $28
    nop
    ctc2       $zero, $24
    ctc2       $zero, $25
    nop
    jr         $ra
     nop
endlabel InitGeom
    nop
    nop
