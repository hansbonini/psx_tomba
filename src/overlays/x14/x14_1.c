#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_801170E4);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_801172E8);

void func_80117390(void) {
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117398);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_801173FC);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117664);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_8011767C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_801176E0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117790);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_8011781C);

void func_8011781C(void)
{
    GameObject *n = allocObjectLayer3();

    if (n) {
        n->active = 1;
        n->type = 0x61;
        n->subtype = 5;
        n->h->p.whole = ((u16*)((char*)&SCRATCHPAD.unk168[3].raw + 2))[0];
        n->y.p.whole = SCRATCHPAD.unk168[4].p.whole - 0x104;
        n->d->p.whole = SCRATCHPAD.unk168[5].p.whole;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117894);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_801178B8);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117AB0);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117C4C);

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117C60);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80117D3C);
extern long LZ_FILE_CTRL_Long asm("LZ_FILE_CTRL");
extern void getBaseMatrix(MATRIX *);
extern s32 insertPrimWithBias(void *, s32, s32, s32, u32);
extern s32 insertPrim(void *, s32, s32, s32, u32);

#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 0( %1 );lwc2 $3, 4( %1 );lwc2 $4, 0( %2 );lwc2 $5, 4( %2 )" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")

#define gte_avsz3() __asm__ volatile ("nop;nop;.word 0x4b58002d")

void func_80117D3C(GameObject *o)
{
    s32 m;
    char *vb4;
    char *vbc;
    char *vc4;
    u8 *p;
    u8 *q;

    getBaseMatrix(&D_1F800020);
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(&(*(MATRIX *)&D_1F8000C0), &D_1F800020, &(*&SCRATCHPAD.workMatrix));
    ApplyRotMatrix(&D_1F800068, SCRATCHPAD.workMatrix.t);
    SCRATCHPAD.workMatrix.t[0] += (*(MATRIX *)&D_1F8000C0).t[0];
    SCRATCHPAD.workMatrix.t[1] += (*(MATRIX *)&D_1F8000C0).t[1];
    SCRATCHPAD.workMatrix.t[2] += (*(MATRIX *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*&SCRATCHPAD.workMatrix));
    SetTransMatrix(&(*&SCRATCHPAD.workMatrix));
    p = (u8 *)D_1F800164;
    p[7] = 0x33;
    if (o->subtype == 0) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[0xe] = 0;
        p[0xd] = 0;
        p[0xc] = 0;
        {
            u8 c = *(u8 *)&o->unk30;
            p[0x16] = c;
            p[0x14] = p[0x15] = c;
        }
    } else if (o->subtype == 4) {
        switch (o->unkAC) {
        case 0:
            {
                u16 c = o->unk74;
                p[6] = c;
                p[4] = p[5] = (u8)c / 3;
            }
            {
                u16 c = o->unk76;
                p[0xe] = c;
                p[0xc] = p[0xd] = (u8)c / 3;
            }
            {
                u16 c = o->unk78;
                p[0x16] = c;
                p[0x14] = p[0x15] = (u8)c / 3;
            }
            break;
        case 1:
            {
                u16 c = o->unk74;
                p[6] = c;
                p[4] = p[5] = c;
            }
            {
                u16 c = o->unk76;
                p[0xe] = c;
                p[0xc] = p[0xd] = c;
            }
            {
                u16 c = o->unk78;
                p[0x16] = c;
                p[0x14] = p[0x15] = c;
            }
            break;
        case 2:
            {
                u8 c = *(u8 *)&o->unk74;
                p[6] = 0;
                p[4] = p[5] = c;
            }
            {
                u8 c = *(u8 *)&o->unk76;
                p[0xe] = 0;
                p[0xc] = p[0xd] = c;
            }
            {
                u8 c = *(u8 *)&o->unk78;
                p[0x16] = 0;
                p[0x14] = p[0x15] = c;
            }
            break;
        }
    }
    vb4 = (char *)o + 0xb4;
    vbc = (char *)o + 0xbc;
    vc4 = (char *)o + 0xc4;
    gte_ldv3(vb4, vbc, vc4);
    gte_rtpt();
    gte_stsxy3_g4(p);
    gte_avsz3();
    gte_stotz(&LZ_FILE_CTRL_Long);
    if (o->unkB) insertPrim(p, SCRATCHPAD.ot + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x6000000);
    else insertPrimWithBias(p, SCRATCHPAD.ot + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x6000000);
    D_1F800164 += 0x1c;
    q = (u8 *)D_1F800164;
    if (GetGraphType() == 1) m = 0x80;
    else if (GetGraphType() == 2) m = 0x80;
    else m = 0x20;
    SetDrawMode(q, 0, 0, m, 0);
    if (o->unkB) AddPrim((s32 *)(SCRATCHPAD.ot + 0x10) + (s8)o->unkF, q);
    else AddPrim((s32 *)SCRATCHPAD.ot + (LZ_FILE_CTRL_Long + 4) + (s8)o->unkF, q);
    D_1F800164 += 0xc;
}
#undef gte_ldv3
#undef gte_rtpt
#undef gte_stsxy3_g4
#undef gte_ldv0
#undef gte_rtps
#undef gte_avsz4
#undef gte_stotz
#undef gte_stsxy
#undef gte_avsz3

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_8011812C);
extern void getBaseMatrix__1812C(MATRIX *);

#define gte_ldv3(r0, r1, r2) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 );lwc2 $2, 0( %1 );lwc2 $3, 4( %1 );lwc2 $4, 0( %2 );lwc2 $5, 4( %2 )" : : "r"(r0), "r"(r1), "r"(r2))
#define gte_rtpt() __asm__ volatile ("nop;nop;.word 0x4a280030")
#define gte_stsxy3_g4(r0) __asm__ volatile ("swc2 $12, 8( %0 );swc2 $13, 16( %0 );swc2 $14, 24( %0 )" : : "r"(r0) : "memory")
#define gte_ldv0(r0) __asm__ volatile ("lwc2 $0, 0( %0 );lwc2 $1, 4( %0 )" : : "r"(r0))
#define gte_rtps() __asm__ volatile ("nop;nop;.word 0x4a180001")
#define gte_avsz4() __asm__ volatile ("nop;nop;.word 0x4b68002e")
#define gte_stotz(r0) __asm__ volatile ("swc2 $7, 0( %0 )" : : "r"(r0) : "memory")
#define gte_stsxy(r0) __asm__ volatile ("swc2 $14, 0( %0 )" : : "r"(r0) : "memory")

void func_8011812C(GameObject *o)
{
    s32 m;
    char *vb4;
    char *vbc;
    char *vc4;
    char *vcc;
    u8 *p;
    u8 *q;

    getBaseMatrix__1812C(&D_1F800020);
    RotMatrixZ(o->unk8C, &D_1F800020);
    RotMatrixX(o->unk84, &D_1F800020);
    RotMatrixY(o->unk88, &D_1F800020);
    D_1F800068.vx = o->x.p.whole;
    D_1F800068.vy = o->y.p.whole;
    D_1F800068.vz = o->z.p.whole;
    MulMatrix0(&(*(MATRIX *)&D_1F8000C0), &D_1F800020, &(*&SCRATCHPAD.workMatrix));
    ApplyRotMatrix(&D_1F800068, SCRATCHPAD.workMatrix.t);
    SCRATCHPAD.workMatrix.t[0] += (*(MATRIX *)&D_1F8000C0).t[0];
    SCRATCHPAD.workMatrix.t[1] += (*(MATRIX *)&D_1F8000C0).t[1];
    SCRATCHPAD.workMatrix.t[2] += (*(MATRIX *)&D_1F8000C0).t[2];
    SetRotMatrix(&(*&SCRATCHPAD.workMatrix));
    SetTransMatrix(&(*&SCRATCHPAD.workMatrix));
    p = (u8 *)D_1F800164;
    p[7] = 0x3b;
    {
        u16 c = o->unk74;
        p[6] = c;
        p[4] = p[5] = (u8)c / 3;
    }
    {
        u16 c = o->unk76;
        p[0xe] = c;
        p[0xc] = p[0xd] = (u8)c / 3;
    }
    {
        u16 c = o->unk78;
        p[0x16] = c;
        p[0x14] = p[0x15] = (u8)c / 3;
    }
    {
        u16 c = o->unk7A;
        p[0x1e] = c;
        p[0x1c] = p[0x1d] = (u8)c / 3;
    }
    vb4 = (char *)o + 0xb4;
    vbc = (char *)o + 0xbc;
    vcc = (char *)o + 0xcc;
    vc4 = (char *)o + 0xc4;
    gte_ldv3(vb4, vbc, vc4);
    gte_rtpt();
    gte_stsxy3_g4(p);
    gte_ldv0(vcc);
    gte_rtps();
    gte_avsz4();
    gte_stotz(&LZ_FILE_CTRL_Long);
    gte_stsxy(p + 0x20);
    insertPrimWithBias(p, SCRATCHPAD.ot + 0x10, LZ_FILE_CTRL_Long, (s8)o->unkF, 0x8000000);
    D_1F800164 += 0x24;
    q = (u8 *)D_1F800164;
    if (GetGraphType() == 1) m = 0x80;
    else if (GetGraphType() == 2) m = 0x80;
    else m = 0x20;
    SetDrawMode(q, 0, 0, m, 0);
    AddPrim((s32 *)SCRATCHPAD.ot + (LZ_FILE_CTRL_Long + 4) + (s8)o->unkF, q);
    D_1F800164 += 0xc;
}
#undef gte_ldv3
#undef gte_rtpt
#undef gte_stsxy3_g4
#undef gte_ldv0
#undef gte_rtps
#undef gte_avsz4
#undef gte_stotz
#undef gte_stsxy

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80118420);
typedef struct GVars_18420 {
    u8 b30;
    u8 _pad31[3];
    s32 i34;
    u8 b38;
    u8 b39;
    u8 b3a;
    u8 b3b;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    u8 b3f;
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    s16 s44;
    s16 s46;
    void *p48;
    void *p4c;
    void *p50;
    void *p54;
    u8 b58;
    u8 b59;
    u8 _pad5a[2];
    s32 i5c;
} GVars_18420;

void func_80118420(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->step++;
        o->timer = 600;
        o->velH = 0x1800;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->velX = -0x40;
        o->animFrame = 0;
        (*(GameObject **)&(*(GVars_18420 *)&D_8009BC98).p54) = o;
        break;
    case 1:
        o->unk8C = (o->unk8C - (o->velH >> 8)) & 0xfff;
        if (--o->timer == -1) {
            o->step++;
            o->animFrame = 1 - o->animFrame;
        }
        break;
    case 2:
        o->unk8C = (o->unk8C - (o->velH >> 8)) & 0xfff;
        o->velH += o->velX;
        if ((u16)(o->velH + 0x17ff) >= 0x2fff) {
            o->timer = 600;
            o->step--;
            o->velX *= -1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_8011855C);
extern s16 D_80124F74[];

void func_8011855C(GameObject *o)
{
    GameObject *p;

    switch (o->step) {
    case 0:
        o->step++;
        o->unk8C = D_80124F74[o->unkC];
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->velH != 0) break;
        if (o->animFrame = p->animFrame) {
            o->step = 2;
            o->velV = 0;
            o->velY = 0x40;
        } else {
            o->step = 3;
            o->velV = 0;
            o->velY = -0x40;
        }
        break;
    case 2:
        o->velV += o->velY;
        o->unk84 += o->velV >> 8;
        if (o->unk84 >= 0x800) {
            o->unk84 = 0x800;
            o->step = 1;
        }
        break;
    case 3:
        o->velV += o->velY;
        o->unk84 += o->velV >> 8;
        if (o->unk84 <= 0) {
            o->unk84 = 0;
            o->step = 1;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80118694);

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80118960);
extern void freeObjectLayer4(GameObject *);

void func_80118960(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->active = 2;
        break;
    case 1:
        func_80022E44(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}
