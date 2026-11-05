#include "common.h"
#include "psyq/libgte.h"
#include "psyq/gtemac.h"
#include "psyq/inline_c.h"

#define gte_SetTransMatrix(r0)                                                 \
    __asm__ volatile(                                                          \
        "lw	$8, 20( %0 );"                                                     \
        "lw	$9, 24( %0 );"                                                     \
        "lw	$10, 28( %0 );"                                                    \
        "ctc2	$8, $5;"                                                       \
        "ctc2	$9, $6;"                                                       \
        "ctc2	$10, $7"                                                       \
        :                                                                      \
        : "r"(r0)                                                              \
        : "$8", "$9", "$10")
#define gte_ldrgb1(r0) __asm__ volatile("lwc2	$20, 0( %0 )" : : "r"(r0))
#define gte_ldrgb2(r0) __asm__ volatile("lwc2	$21, 0( %0 )" : : "r"(r0))
#define gte_ldrgb3(r0) __asm__ volatile("lwc2	$22, 0( %0 )" : : "r"(r0))
#define gte_ldsv_(r0, r1, r2)                                                  \
    __asm__ volatile("mtc2	%0, $9;"                                           \
                     "mtc2	%1, $10;"                                          \
                     "mtc2	%2, $11"                                           \
                     :                                                         \
                     : "r"(r0), "r"(r1), "r"(r2))
#define gte_SetRii(r0, r1, r2)                                                \
    __asm__ volatile("ctc2	%0, $0;"                                           \
                     "ctc2	%1, $2;"                                           \
                     "ctc2	%2, $4"                                            \
                     :                                                         \
                     : "r"(r0), "r"(r1), "r"(r2))
#define gte_ldMAC1(r0) __asm__ volatile("mtc2	%0, $25" : : "r"(r0))
#define gte_ldMAC2(r0) __asm__ volatile("mtc2	%0, $26" : : "r"(r0))
#define gte_ldMAC3(r0) __asm__ volatile("mtc2	%0, $27" : : "r"(r0))
#define gte_ldDQA(r0) __asm__ volatile("ctc2	%0, $27" : : "r"(r0))
#define gte_ldDQB(r0) __asm__ volatile("ctc2	%0, $28" : : "r"(r0))

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetTransMatrix);
/**
 * @brief Set the GTE translation vector
 * 
 * Loads the translation part of m into the GTE translation registers.
 * 
 * @param m Matrix whose translation vector is loaded
 */
void SetTransMatrix(MATRIX* m)
{
    gte_SetTransMatrix(m);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetVertex0);
/**
 * @brief Load GTE vertex register V0
 * 
 * Writes a short vector to the GTE V0 input register.
 * 
 * @param r0 Vertex to load
 */
void SetVertex0(SVECTOR* r0)
{
    gte_ldv0(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetVertex1);
/**
 * @brief Load GTE vertex register V1
 * 
 * Writes a short vector to the GTE V1 input register.
 * 
 * @param r0 Vertex to load
 */
void SetVertex1(SVECTOR* r0)
{
    gte_ldv1(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetVertex2);
/**
 * @brief Load GTE vertex register V2
 * 
 * Writes a short vector to the GTE V2 input register.
 * 
 * @param r0 Vertex to load
 */
void SetVertex2(SVECTOR* r0)
{
    gte_ldv2(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetVertexTri);
/**
 * @brief Load GTE vertex registers V0, V1 and V2
 * 
 * Writes three short vectors to the GTE vertex input registers.
 * 
 * @param r0 Vertex for V0
 * @param r1 Vertex for V1
 * @param r2 Vertex for V2
 */
void SetVertexTri(SVECTOR* r0, SVECTOR* r1, SVECTOR* r2)
{
    gte_ldv3(r0, r1, r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetRGBfifo);
/**
 * @brief Load the GTE color FIFO
 * 
 * Loads the three entries of the GTE RGB FIFO (RGB0-RGB2) from memory.
 * 
 * @param r0 Address of the color for RGB0
 * @param r1 Address of the color for RGB1
 * @param r2 Address of the color for RGB2
 */
void SetRGBfifo(int r0, int r1, int r2)
{
    gte_ldrgb1(r0);
    gte_ldrgb2(r1);
    gte_ldrgb3(r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetIR123);
/**
 * @brief Load GTE registers IR1-IR3
 * 
 * Writes the three intermediate value registers of the GTE.
 * 
 * @param r0 Value for IR1
 * @param r1 Value for IR2
 * @param r2 Value for IR3
 */
void SetIR123(int r0, int r1, int r2)
{
    gte_ldsv_(r0,r1,r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetIR0);
/**
 * @brief Load GTE register IR0
 * 
 * Writes the IR0 register (interpolation / depth cue factor).
 * 
 * @param r0 Value for IR0
 */
void SetIR0(int r0)
{
    gte_lddp(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetSZfifo3);
/**
 * @brief Load the last three entries of the GTE Z FIFO
 * 
 * Writes SZ1-SZ3, as used by AverageZ3.
 * 
 * @param r0 Value for SZ1
 * @param r1 Value for SZ2
 * @param r2 Value for SZ3
 */
void SetSZfifo3(int r0, int r1, int r2)
{
    gte_ldsz3(r0,r1,r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetSZfifo4);
/**
 * @brief Load all four entries of the GTE Z FIFO
 * 
 * Writes SZ0-SZ3, as used by AverageZ4.
 * 
 * @param r0 Value for SZ0
 * @param r1 Value for SZ1
 * @param r2 Value for SZ2
 * @param r3 Value for SZ3
 */
void SetSZfifo4(int r0, int r1, int r2, int r3)
{
    gte_ldsz4(r0,r1,r2,r3);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetSXSYfifo);
/**
 * @brief Load the GTE screen XY FIFO
 * 
 * Writes SXY0-SXY2.
 * 
 * @param r0 Packed screen coordinates for SXY0
 * @param r1 Packed screen coordinates for SXY1
 * @param r2 Packed screen coordinates for SXY2
 */
void SetSXSYfifo(int r0, int r1, int r2)
{
    gte_ldsxy0(r0);
    gte_ldsxy1(r1);
    gte_ldsxy2(r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetRii);
/**
 * @brief Load the GTE rotation matrix control registers 0, 2 and 4
 * 
 * Writes the raw packed values of the rotation matrix registers that hold
 * the diagonal elements (R11/R12, R22/R23 and R33).
 * 
 * @param r0 Value for control register 0
 * @param r1 Value for control register 2
 * @param r2 Value for control register 4
 */
void SetRii(int r0, int r1, int r2)
{
    gte_SetRii(r0, r1, r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetMAC123);
/**
 * @brief Load GTE registers MAC1-MAC3
 * 
 * Writes the three accumulator registers of the GTE.
 * 
 * @param r0 Value for MAC1
 * @param r1 Value for MAC2
 * @param r2 Value for MAC3
 */
void SetMAC123(int r0, int r1, int r2)
{
    gte_ldMAC1(r0);
    gte_ldMAC2(r1);
    gte_ldMAC3(r2);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetData32);
/**
 * @brief Load the GTE leading zero count input register
 * 
 * Writes the LZCS register; the leading zero/one count can then be read
 * from LZCR.
 * 
 * @param r0 Value to analyze
 */
void SetData32(int r0)
{
    gte_ldlzc(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetDQA);
/**
 * @brief Set the GTE depth cue coefficient A
 * 
 * Writes the DQA control register.
 * 
 * @param r0 Depth cue coefficient
 */
void SetDQA(int r0)
{
    gte_ldDQA(r0);
}

// INCLUDE_ASM("nonmatchings/psyq/libgte/mtx_12", SetDQB);
/**
 * @brief Set the GTE depth cue offset B
 * 
 * Writes the DQB control register.
 * 
 * @param r0 Depth cue offset
 */
void SetDQB(int r0)
{
    gte_ldDQB(r0);
}
