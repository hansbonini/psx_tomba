/**
 * @file bios.s
 *
 * PSX BIOS / custom function stubs
 *
 * Contains:
 *   - Standard system call wrappers (DEFINE_SYS_FN).
 *   - A-, B-, and C-Function wrappers.
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

#ifdef FUNC_1
  DEFINE_SYS_FN EnterCriticalSection, 0x1
#endif

#ifdef FUNC_2
  DEFINE_SYS_FN ExitCriticalSection, 0x2
#endif

#ifdef FUNC_A44
  DEFINE_FN FlushCache, 0xA0, 0x44
#endif

#ifdef FUNC_A49
  DEFINE_FN GPU_cw, 0xA0, 0x49
#endif

#ifdef FUNC_A70
  DEFINE_FN _bu_init, 0xA0, 0x70
#endif

#ifdef FUNC_A94
  .set noat
    .set noreorder
    .global GetGp
    .type GetGp, @function
    GetGp:
      jr      $ra
      move    $v0, $gp
    .size GetGp, . - GetGp
      nop
#endif

#ifdef FUNC_AAB
  DEFINE_FN _card_info, 0xA0, 0xAB
#endif

#ifdef FUNC_AAC
  DEFINE_FN _card_load, 0xA0, 0xAC
#endif

#ifdef FUNC_B07
  DEFINE_FN DeliverEvent, 0xB0, 0x7
#endif

#ifdef FUNC_B08
  DEFINE_FN OpenEvent, 0xB0, 0x8
#endif

#ifdef FUNC_B09
  DEFINE_FN CloseEvent, 0xB0, 0x9
#endif

#ifdef FUNC_B0B
  DEFINE_FN TestEvent, 0xB0, 0xB
#endif

#ifdef FUNC_B0C
  DEFINE_FN EnableEvent, 0xB0, 0xC
#endif

#ifdef FUNC_B0E
  DEFINE_FN OpenTh, 0xB0, 0xE
#endif

#ifdef FUNC_B0F
  DEFINE_FN CloseTh, 0xB0, 0xF
#endif

#ifdef FUNC_B10
  DEFINE_FN ChangeTh, 0xB0, 0x10
#endif

#ifdef FUNC_B32
  DEFINE_FN open, 0xB0, 0x32
#endif

#ifdef FUNC_B33
  DEFINE_FN lseek, 0xB0, 0x33
#endif

#ifdef FUNC_B34
  DEFINE_FN read, 0xB0, 0x34
#endif

#ifdef FUNC_B35
  DEFINE_FN write, 0xB0, 0x35
#endif

#ifdef FUNC_B36
  DEFINE_FN close, 0xB0, 0x36
#endif

#ifdef FUNC_B41
  DEFINE_FN format, 0xB0, 0x42
#endif

#ifdef FUNC_B42
  DEFINE_FN firstfile, 0xB0, 0x42
#endif

#ifdef FUNC_B43
  DEFINE_FN nextfile, 0xB0, 0x43
#endif

#ifdef FUNC_B45
  DEFINE_FN erase, 0xB0, 0x45
#endif

#ifdef FUNC_B4A
  DEFINE_FN InitCARD2, 0xB0, 0x4A
#endif

#ifdef FUNC_B4B
  DEFINE_FN StartCARD2, 0xB0, 0x4B
#endif

#ifdef FUNC_B4C
  DEFINE_FN StopCARD2, 0xB0, 0x4C
#endif

#ifdef FUNC_B4E
  DEFINE_FN _card_write, 0xB0, 0x4E
#endif

#ifdef FUNC_B50
  DEFINE_FN _new_card, 0xB0, 0x50
#endif

#ifdef FUNC_B5B
  DEFINE_FN ChangeClearPAD, 0xB0, 0x5B
#endif

