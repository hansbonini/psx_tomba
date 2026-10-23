.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"

glabel GetGp
    jr         $ra
     addu       $v0, $gp, $zero
endlabel GetGp
    nop
    nop
