#include "common.h"
#include "game.h"
#include "x14.h"
#include "game/gte.h"

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

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_8011812C);


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

// INCLUDE_ASM("overlays/x14/nonmatchings/x14/x14_1", func_80118420);

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
        (*(GameObject **)&D_8009BC98.unk24) = o;
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
