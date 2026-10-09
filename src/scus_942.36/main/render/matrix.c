#include "common.h"
#include "game.h"

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004CFE0);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D0C0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D1A0);
extern void getBaseMatrix(void *);
extern void func_80026694(s32, s32, void *, s32);
void func_8004D1A0(char *o)
{
    getBaseMatrix(&(*(MATRIX *)&SCRATCHPAD));
    ((s16 *)&D_1F800060)[0] = *(u16 *)((u8 *)o + 0x12);
    ((s16 *)&D_1F800060)[1] = *(u16 *)((u8 *)o + 0x16);
    ((s16 *)&D_1F800060)[2] = *(u16 *)((u8 *)o + 0x1a);
    SetRotMatrix(SCRATCH_VIEW_MATRIX);
    ApplyRotMatrix(((s16 *)&D_1F800060), &(*(MATRIX *)&SCRATCHPAD).t[0]);
    (*(MATRIX *)&SCRATCHPAD).t[0] += SCRATCH_VIEW_MATRIX->t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += SCRATCH_VIEW_MATRIX->t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += SCRATCH_VIEW_MATRIX->t[2];
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    func_80026694(*(s32 *)((u8 *)o + 0xa0), (s32)((*(char **)&D_1F8001E0) + ((*(s8 *)((u8 *)o + 0xf) << 2) + 0x10)), o, *(u8 *)((u8 *)o + 0xa4));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D2A8);
extern MATRIX D_1F800020;
extern SVECTOR D_1F800068;

void func_8004D2A8(GameObject *o)
{
    getBaseMatrix(&D_1F800020);
    switch (D_1F8001C8 & 1) {
    case 0:
        D_1F800060.vx = o->unk84;
        D_1F800060.vy = o->unk88;
        D_1F800060.vz = o->unk8C;
        break;
    case 1:
        D_1F800060.vx = o->unk8C;
        D_1F800060.vy = o->unk88;
        D_1F800060.vz = o->unk84;
        break;
    }
    RotMatrix(&D_1F800060, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(SCRATCH_VIEW_MATRIX, &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += SCRATCH_VIEW_MATRIX->t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += SCRATCH_VIEW_MATRIX->t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += SCRATCH_VIEW_MATRIX->t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    func_80026694(o->unkA0, (s32)&((struct { char pad[0x10]; s32 a[1]; } *)D_1F8001E0)->a[(s8)o->unkF], o, o->unkA4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D448);
typedef struct {
    char p0[0xf]; s8 f; char p1[2]; u16 x; char p2[2]; u16 y; char p3[2]; u16 z;
    char p4[0x84 - 0x1c]; s32 a84, a88, a8c; char p5[0xa0 - 0x90]; s32 aa0; u8 ba4; char p6[3]; s32 aa8;
} O_4D448;

void func_8004D448(O_4D448 *o)
{
    extern void func_80026E48(s32, s32 *, O_4D448 *, s32, s32);
    getBaseMatrix(&D_1F800020);
    switch (D_1F8001C8 & 1) {
    case 0:
        D_1F800060.vx = o->a84;
        D_1F800060.vy = o->a88;
        D_1F800060.vz = o->a8c;
        break;
    case 1:
        D_1F800060.vx = o->a8c;
        D_1F800060.vy = o->a88;
        D_1F800060.vz = o->a84;
        break;
    }
    RotMatrix(&D_1F800060, &D_1F800020);
    D_1F800068.vx = o->x;
    D_1F800068.vy = o->y;
    D_1F800068.vz = o->z;
    MulMatrix0(SCRATCH_VIEW_MATRIX, &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += SCRATCH_VIEW_MATRIX->t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += SCRATCH_VIEW_MATRIX->t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += SCRATCH_VIEW_MATRIX->t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    func_80026E48(o->aa0, &(*(s32 **)&D_1F8001E0)[o->f + 4], o, o->aa8, o->ba4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D5F0);
extern VECTOR D_1F800040;

void func_8004D5F0(GameObject *o)
{
    getBaseMatrix(&D_1F800020);
    switch (D_1F8001C8 & 1) {
    case 0:
        D_1F800060.vx = o->unk84;
        D_1F800060.vy = o->unk88;
        D_1F800060.vz = o->unk8C;
        break;
    case 1:
        D_1F800060.vx = o->unk8C;
        D_1F800060.vy = o->unk88;
        D_1F800060.vz = o->unk84;
        break;
    }
    D_1F800040.vx = o->unk74;
    D_1F800040.vy = o->unk76;
    D_1F800040.vz = o->unk78;
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(SCRATCH_VIEW_MATRIX, &D_1F800020, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800068, (*(MATRIX *)&SCRATCHPAD).t);
    (*(MATRIX *)&SCRATCHPAD).t[0] += SCRATCH_VIEW_MATRIX->t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += SCRATCH_VIEW_MATRIX->t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += SCRATCH_VIEW_MATRIX->t[2];
    ScaleMatrix(&(*(MATRIX *)&SCRATCHPAD), &D_1F800040);
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    func_80026694(o->unkA0, (*(char **)&D_1F8001E0) + ((s8)o->unkF * 4 + 0x10), o, o->unkA4);
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D7E0);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004D91C);
typedef struct { s16 vx, vy, vz, pad; } SVEC_4D91C;
typedef struct { s16 m[3][3]; s32 t[3]; } MATR_4D91C;

void func_8004D91C(GameObject *o)
{
    D_1F800060.vx = o->x.p.whole;
    D_1F800060.vy = o->y.p.whole;
    D_1F800060.vz = o->z.p.whole;
    MulMatrix0(&(*(MATR_4D91C *)&D_1F8000C0), (MATR_4D91C *)&o->unk48, &(*(MATR_4D91C *)&SCRATCHPAD));
    ApplyRotMatrix(&D_1F800060, (*(MATR_4D91C *)&SCRATCHPAD).t);
    (*(MATR_4D91C *)&SCRATCHPAD).t[0] += (*(MATR_4D91C *)&D_1F8000C0).t[0];
    (*(MATR_4D91C *)&SCRATCHPAD).t[1] += (*(MATR_4D91C *)&D_1F8000C0).t[1];
    (*(MATR_4D91C *)&SCRATCHPAD).t[2] += (*(MATR_4D91C *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*(MATR_4D91C *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATR_4D91C *)&SCRATCHPAD));
    func_80026694(o->unkA0, &(*(s32 **)&D_1F8001E0)[*(s8 *)&o->unkF + 4], o, o->unkA4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004DA28);
extern void func_80026E48(s32, s32, void *, s32, s32);
void func_8004DA28(char *o)
{
    ((s16 *)&D_1F800060)[0] = *(u16 *)((u8 *)o + 0x12);
    ((s16 *)&D_1F800060)[1] = *(u16 *)((u8 *)o + 0x16);
    ((s16 *)&D_1F800060)[2] = *(u16 *)((u8 *)o + 0x1a);
    MulMatrix0(SCRATCH_VIEW_MATRIX, o + 0x48, &(*(MATRIX *)&SCRATCHPAD));
    ApplyRotMatrix(((s16 *)&D_1F800060), &(*(MATRIX *)&SCRATCHPAD).t[0]);
    (*(MATRIX *)&SCRATCHPAD).t[0] += SCRATCH_VIEW_MATRIX->t[0];
    (*(MATRIX *)&SCRATCHPAD).t[1] += SCRATCH_VIEW_MATRIX->t[1];
    (*(MATRIX *)&SCRATCHPAD).t[2] += SCRATCH_VIEW_MATRIX->t[2];
    SetRotMatrix(&(*(MATRIX *)&SCRATCHPAD));
    SetTransMatrix(&(*(MATRIX *)&SCRATCHPAD));
    func_80026E48(*(s32 *)((u8 *)o + 0xa0), (s32)((*(char **)&D_1F8001E0) + ((*(s8 *)((u8 *)o + 0xf) << 2) + 0x10)), o, *(s32 *)((u8 *)o + 0xa8), *(u8 *)((u8 *)o + 0xa4));
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/render/matrix", func_8004DB3C);
extern void func_8011F5C4(s32, s32);
extern void func_80027600(s32, s32);

void func_8004DB3C(void)
{
    char pad;
    s32 i;
    s32 *p;
    u8 *base;
    SetRotMatrix(D_1F8000C0);
    SetTransMatrix(D_1F8000C0);
    base = D_800B00F8;
    if ((*(s32 *)&GAME) == 0x60009) {
        i = 0;
        if (i < D_800B00F8[3]) {
            p = (s32 *)base;
            do {
                func_8011F5C4(p[1], D_1F8001E0 + 0x10);
                p++;
                i++;
            } while (i < base[3]);
        }
    } else {
        i = 0;
        if (i < D_800B00F8[3]) {
            p = (s32 *)base;
            do {
                func_80027600(p[1], D_1F8001E0 + 0x10);
                p++;
                i++;
            } while (i < base[3]);
        }
    }
}
