#ifndef LIBGTE_GTE_LOCAL_H
#define LIBGTE_GTE_LOCAL_H

/*
 * GTE helpers for the LIBGTE sources.
 *
 * psyq/inline_c.h emits DMPSX placeholders for GTE commands and uses
 * $12-$14 as scratch registers. LIBGTE itself was written with real opcodes,
 * one load-delay nop before each command and $8-$12 as scratch, so the
 * commands below go through the assembler macros of include/gte_macros.inc.
 */

/* Commands. */
#define gte_sqr0_b() __asm__ volatile("nop; sqr 0")
#define gte_sqr12_b() __asm__ volatile("nop; sqr 1")
#define gte_avsz3_b() __asm__ volatile("nop; avsz3")
#define gte_avsz4_b() __asm__ volatile("nop; avsz4")
#define gte_lcir_b() __asm__ volatile("nop; mvmva 1, 2, 3, 1, 1")
#define gte_dpcl_b() __asm__ volatile("nop; dpcl")
#define gte_dpct_b() __asm__ volatile("nop; dpct")
#define gte_intpl_b() __asm__ volatile("nop; intpl")
#define gte_rtps_b() __asm__ volatile("nop; rtps")

/* Data register reads into a C value. */
#define gte_read_otz(r0) __asm__ volatile("mfc2 %0, $7" : "=r"(r0))
#define gte_read_lzcr(r0) __asm__ volatile("mfc2 %0, $31" : "=r"(r0))
#define gte_read_flag(r0) __asm__ volatile("cfc2 %0, $31" : "=r"(r0))
#define gte_read_sz3(r0) __asm__ volatile("mfc2 %0, $19" : "=r"(r0))

/* RGB color and depth cue together: maspsx takes the GTE $6 of lwc2 for
   $a2 and would put a nop before a following mtc2 of $a2. */
#define gte_ldrgb_dp(r0, r1) __asm__ volatile("lwc2 $6, 0(%0); mtc2 %1, $8" : : "r"(r0), "r"(r1))

/* Control register writes. */
#define gte_ldofxy(r0, r1)                                                     \
    __asm__ volatile("ctc2 %0, $24; ctc2 %1, $25" : : "r"(r0), "r"(r1))

/* Loads a 3x3 matrix (five packed words) into control registers base..base+4
   through $8-$12. */
#define gte_ldmatrix_t(r0, c0, c1, c2, c3, c4)                                 \
    __asm__ volatile("lw $8, 0(%0); lw $9, 4(%0); lw $10, 8(%0);"              \
                     "lw $11, 12(%0); lw $12, 16(%0);"                         \
                     "ctc2 $8, $" #c0 "; ctc2 $9, $" #c1 "; ctc2 $10, $" #c2 ";" \
                     "ctc2 $11, $" #c3 "; ctc2 $12, $" #c4                     \
                     :                                                         \
                     : "r"(r0)                                                 \
                     : "$8", "$9", "$10", "$11", "$12")

/* Outer product of r0 and r1 into r2 through the rotation matrix diagonal,
   which is kept in $13-$15 and given back. */
#define gte_OuterProduct_t(r0, r1, r2, sf)                                     \
    __asm__ volatile("cfc2 $13, $0; cfc2 $14, $2; cfc2 $15, $4;"               \
                     "lw $8, 0(%0); lw $9, 4(%0); lw $10, 8(%0);"              \
                     "ctc2 $8, $0; ctc2 $9, $2; ctc2 $10, $4;"                 \
                     "lwc2 $11, 8(%1); lwc2 $9, 0(%1); lwc2 $10, 4(%1);"       \
                     "nop; op " #sf ";"                                        \
                     "swc2 $25, 0(%2); swc2 $26, 4(%2); swc2 $27, 8(%2);"      \
                     "ctc2 $13, $0; ctc2 $14, $2; ctc2 $15, $4"                \
                     :                                                         \
                     : "r"(r0), "r"(r1), "r"(r2)                               \
                     : "$8", "$9", "$10", "$13", "$14", "$15", "memory")

/* RotMatrix: the matrix of r0 into r1 (returned in out), with the
   multiplications scheduled by hand around rcossin_tbl. */
#define gte_RotMatrix_t(r0, r1, out) \
    __asm__ volatile( \
    "lh     $t7, 0(%1);" \
    "addu   %0, %2, $zero;" \
    "bgez   $t7, 2f;" \
    "andi   $t9, $t7, 0xFFF;" \
    "negu   $t7, $t7;" \
    "bgez   $t7, 1f;" \
    "andi   $t7, $t7, 0xFFF;" \
    "1:;" \
    "sll    $t8, $t7, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t8, $t9, 16;" \
    "sra    $t8, $t8, 16;" \
    "negu   $t3, $t8;" \
    "j      3f;" \
    "sra    $t0, $t9, 16;" \
    "2:;" \
    "sll    $t8, $t9, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t8, $t9, 16;" \
    "sra    $t3, $t8, 16;" \
    "sra    $t0, $t9, 16;" \
    "3:;" \
    "lh     $t7, 2(%1);" \
    "nop;" \
    "bgez   $t7, 5f;" \
    "andi   $t9, $t7, 0xFFF;" \
    "negu   $t7, $t7;" \
    "bgez   $t7, 4f;" \
    "andi   $t7, $t7, 0xFFF;" \
    "4:;" \
    "sll    $t8, $t7, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t4, $t9, 16;" \
    "sra    $t4, $t4, 16;" \
    "negu   $t6, $t4;" \
    "j      6f;" \
    "sra    $t1, $t9, 16;" \
    "5:;" \
    "sll    $t8, $t9, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t6, $t9, 16;" \
    "sra    $t6, $t6, 16;" \
    "negu   $t4, $t6;" \
    "sra    $t1, $t9, 16;" \
    "6:;" \
    "multu  $t1, $t3;" \
    "lh     $t7, 4(%1);" \
    "sh     $t6, 4(%2);" \
    "mflo   $t8;" \
    "negu   $t9, $t8;" \
    "sra    $t6, $t9, 12;" \
    "multu  $t1, $t0;" \
    "sh     $t6, 10(%2);" \
    "bgez   $t7, 8f;" \
    "andi   $t9, $t7, 0xFFF;" \
    "mflo   $t8;" \
    "sra    $t6, $t8, 12;" \
    "sh     $t6, 16(%2);" \
    "negu   $t7, $t7;" \
    "bgez   $t7, 7f;" \
    "andi   $t7, $t7, 0xFFF;" \
    "7:;" \
    "sll    $t8, $t7, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t8, $t9, 16;" \
    "sra    $t8, $t8, 16;" \
    "negu   $t5, $t8;" \
    "j      9f;" \
    "sra    $t2, $t9, 16;" \
    "8:;" \
    "mflo   $t7;" \
    "sra    $t6, $t7, 12;" \
    "sh     $t6, 16(%2);" \
    "sll    $t8, $t9, 2;" \
    "lui    $t9, %%hi(D_80091750);" \
    "addu   $t9, $t9, $t8;" \
    "lw     $t9, %%lo(D_80091750)($t9);" \
    "nop;" \
    "sll    $t8, $t9, 16;" \
    "sra    $t5, $t8, 16;" \
    "sra    $t2, $t9, 16;" \
    "9:;" \
    "multu  $t2, $t1;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t6, $t7, 12;" \
    "sh     $t6, 0(%2);" \
    "multu  $t5, $t1;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "negu   $t6, $t7;" \
    "sra    $t7, $t6, 12;" \
    "multu  $t2, $t4;" \
    "sh     $t7, 2(%2);" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t8, $t7, 12;" \
    "nop;" \
    "multu  $t8, $t3;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t6, $t7, 12;" \
    "nop;" \
    "multu  $t5, $t0;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t9, $t7, 12;" \
    "subu   $t7, $t9, $t6;" \
    "multu  $t8, $t0;" \
    "sh     $t7, 6(%2);" \
    "nop;" \
    "mflo   $t6;" \
    "sra    $t7, $t6, 12;" \
    "nop;" \
    "multu  $t5, $t3;" \
    "nop;" \
    "nop;" \
    "mflo   $t6;" \
    "sra    $t9, $t6, 12;" \
    "addu   $t6, $t9, $t7;" \
    "multu  $t5, $t4;" \
    "sh     $t6, 12(%2);" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t8, $t7, 12;" \
    "nop;" \
    "multu  $t8, $t3;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t6, $t7, 12;" \
    "nop;" \
    "multu  $t2, $t0;" \
    "nop;" \
    "nop;" \
    "mflo   $t7;" \
    "sra    $t9, $t7, 12;" \
    "addu   $t7, $t9, $t6;" \
    "multu  $t8, $t0;" \
    "sh     $t7, 8(%2);" \
    "nop;" \
    "mflo   $t6;" \
    "sra    $t7, $t6, 12;" \
    "nop;" \
    "multu  $t2, $t3;" \
    "nop;" \
    "nop;" \
    "mflo   $t6;" \
    "sra    $t9, $t6, 12;" \
    "subu   $t6, $t9, $t7;" \
    "sh     $t6, 14(%2);" \
        : "=r"(out) \
        : "r"(r0), "r"(r1) \
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$24", "$25", "memory")

#endif
