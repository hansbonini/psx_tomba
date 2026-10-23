.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel func_8005CDC8
    lui        $v0, %hi(.LD_8005CDDC)
    addiu      $v0, $v0, %lo(.LD_8005CDDC)
    jr         $v0
     nop
    nop
.LD_8005CDDC:
    lw         $v0, 0x1074($v1)
    nop
    andi       $v0, $v0, 0x80
    beqz       $v0, .Lfunc_8005CDC8_2
     nop
.Lfunc_8005CDC8_1:
    lw         $v0, 0x1044($v1)
    nop
    andi       $v0, $v0, 0x80
    bnez       $v0, .Lfunc_8005CDC8_1
     nop
    lui        $v0, %hi(jtbl_8009AFB4_main)
    lw         $v0, %lo(jtbl_8009AFB4_main)($v0)
    nop
    jr         $v0
     nop
.Lfunc_8005CDC8_2:
    jr         $ra
     nop
endlabel func_8005CDC8

glabel _patch_card
    lui        $at, %hi(D_8009AFB0)
    sw         $ra, %lo(D_8009AFB0)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     addiu      $t1, $zero, 0x56
    lw         $v0, 0x18($v0)
    nop
    lw         $v1, 0x70($v0)
    nop
    andi       $t1, $v1, 0xFFFF
    lw         $v1, 0x74($v0)
    sll        $t1, $t1, 16
    andi       $t2, $v1, 0xFFFF
    addu       $v1, $t1, $t2
    lui        $t2, %hi(func_8005CDC8)
    lui        $t1, %hi(.LD_8005CDDC)
    addiu      $v0, $v1, 0x28
    addiu      $t2, $t2, %lo(func_8005CDC8)
    addiu      $t1, $t1, %lo(.LD_8005CDDC)
.L_patch_card_1:
    lw         $v1, 0x0($t2)
    addiu      $t2, $t2, 0x4
    addiu      $v0, $v0, 0x4
    bne        $t2, $t1, .L_patch_card_1
     sw         $v1, -0x4($v0)
    lui        $at, %hi(jtbl_8009AFB4_main)
    jal        FlushCache
     sw         $v0, %lo(jtbl_8009AFB4_main)($at)
    lui        $ra, %hi(D_8009AFB0)
    lw         $ra, %lo(D_8009AFB0)($ra)
    nop
    jr         $ra
     nop
endlabel _patch_card

glabel func_8005CEA8
    lui        $t0, %hi(func_8005CEA8)
    addiu      $t0, $t0, %lo(func_8005CEA8)
    jalr       $t0
     nop
    nop
    nop
    addiu      $t0, $zero, 0xC8
.Lfunc_8005CEA8_1:
    addiu      $t0, $t0, -0x1
    bnez       $t0, .Lfunc_8005CEA8_1
     nop
    jr         $ra
     nop
endlabel func_8005CEA8

glabel _patch_card2
    lui        $at, %hi(D_8009AFB0)
    sw         $ra, %lo(D_8009AFB0)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     addiu      $t1, $zero, 0x57
    lw         $v0, 0x16C($v0)
    lui        $t2, %hi(func_8005CEA8)
    lui        $t1, %hi(func_8005CEA8 + 0x14)
    lw         $v1, 0x9C8($v0)
    addiu      $t2, $t2, %lo(func_8005CEA8)
    addiu      $t1, $t1, %lo(func_8005CEA8 + 0x14)
.L_patch_card2_1:
    lw         $v1, 0x9C8($v0)
    lw         $t0, 0x0($t2)
    addiu      $t2, $t2, 0x4
    sw         $v1, -0x4($t2)
    addiu      $v0, $v0, 0x4
    bne        $t2, $t1, .L_patch_card2_1
     sw         $t0, 0x9C4($v0)
    jal        FlushCache
     nop
    lui        $ra, %hi(D_8009AFB0)
    lw         $ra, %lo(D_8009AFB0)($ra)
    nop
    jr         $ra
     nop
endlabel _patch_card2

glabel func_8005CF44
    lui        $t6, %hi(0x31FFFF)
    addiu      $t6, $t6, %lo(0x31FFFF)
.Lfunc_8005CF44_1:
    bnez       $t6, .Lfunc_8005CF44_1
     addiu      $t6, $t6, -0x1
    jr         $ra
     nop
endlabel func_8005CF44
    nop
    nop
    nop

glabel func_8005CF68
    lui        $at, %hi(D_8009AFC0)
    sw         $ra, %lo(D_8009AFC0)($at)
    jal        EnterCriticalSection
     nop
    addiu      $t2, $zero, 0xB0
    jalr       $t2
     addiu      $t1, $zero, 0x56
    lui        $t2, %hi(.LD_8005CFD0)
    lui        $t1, %hi(.LD_8005CFDC)
    lw         $v0, 0x18($v0)
    addiu      $t2, $t2, %lo(.LD_8005CFD0)
    addiu      $t1, $t1, %lo(.LD_8005CFDC)
.Lfunc_8005CF68_1:
    lw         $v1, 0x0($t2)
    addiu      $t2, $t2, 0x4
    addiu      $v0, $v0, 0x4
    bne        $t2, $t1, .Lfunc_8005CF68_1
     sw         $v1, 0x6C($v0)
    jal        FlushCache
     nop
    jal        ExitCriticalSection
     nop
    lui        $ra, %hi(D_8009AFC0)
    lw         $ra, %lo(D_8009AFC0)($ra)
    nop
    jr         $ra
     nop
endlabel func_8005CF68
.LD_8005CFD0:
    nop
    nop
    nop
.LD_8005CFDC:
    nop
    nop
    nop
