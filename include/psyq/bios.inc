/*
 * PSX BIOS function stubs, as libapi and libcard have them: each one jumps
 * to the A0, B0 or C0 table of the kernel with the function number in $t1,
 * or makes a system call with the number in $a0.
 *
 * @see https://psx-spx.consoledev.net/kernelbios/#bios-function-summary
 */

.macro DEFINE_FN fn_name, call_code, fn_num
    .set noat
    .set noreorder
    .global \fn_name
    .type \fn_name, @function
    \fn_name:
      addiu   $t2, $zero, \call_code
      jr      $t2
      addiu   $t1, $zero, \fn_num
    .size \fn_name, . - \fn_name
      nop
.endm

.macro DEFINE_SYS_FN fn_name, fn_num
    .set noreorder
    .set noat
    .global \fn_name
    .type \fn_name, @function
    \fn_name:
      addiu   $a0, $zero, \fn_num
      syscall 0
      jr      $ra
      nop
    .size \fn_name, . - \fn_name
.endm
