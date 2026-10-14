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

/* Data register reads into a C value. */
#define gte_read_otz(r0) __asm__ volatile("mfc2 %0, $7" : "=r"(r0))
#define gte_read_lzcr(r0) __asm__ volatile("mfc2 %0, $31" : "=r"(r0))

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

#endif
