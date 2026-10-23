.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel _patch_gte
    lui        $at, %hi(D_8009AFD0)
    sw         $ra, %lo(D_8009AFD0)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     addiu      $t1, $zero, 0x56
    lui        $t2, %hi(.LD_800645FC)
    lui        $t1, %hi(StSetRing)
    lw         $v0, 0x18($v0)
    addiu      $t2, $t2, %lo(.LD_800645FC)
    addiu      $t1, $t1, %lo(StSetRing)
.L_patch_gte_1:
    lw         $v1, 0x0($t2)
    addiu      $t2, $t2, 0x4
    addiu      $v0, $v0, 0x4
    bne        $t2, $t1, .L_patch_gte_1
     sw         $v1, -0x4($v0)
    jal        FlushCache
     nop
    jal        ExitCriticalSection
     nop
    lui        $ra, %hi(D_8009AFD0)
    lw         $ra, %lo(D_8009AFD0)($ra)
    nop
    jr         $ra
     nop
endlabel _patch_gte
.LD_800645FC:
    nop
    nop

glabel func_80064604
    addiu      $k0, $zero, 0x100
    lw         $k0, 0x8($k0)
    nop
    lw         $k0, 0x0($k0)
    nop
    addi       $k0, $k0, 0x8
    sw         $at, 0x4($k0)
    sw         $v0, 0x8($k0)
    sw         $v1, 0xC($k0)
    sw         $ra, 0x7C($k0)
    mfc0       $v0, $13
endlabel func_80064604
    nop
