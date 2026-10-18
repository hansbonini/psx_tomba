#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116330);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116814);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116C78);

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116D04);
typedef struct { s16 a, b, c; } R6_16D04;
extern R6_16D04 D_80117560[];
extern R6_16D04 D_80117574[];
extern R6_16D04 D_801175AC[];
extern R6_16D04 D_801175F4[];
void func_80116F60(s32 a, s32 b, s32 c);
void func_80117164(s32 a, s32 b, s32 c, s32 d);
void addDrawModePrim(s32 a, s32 b);

void func_80116D04(s32 a, s32 b, s32 c, s32 d)
{
    extern void func_80116E9C(R6_16D04 *p);
    R6_16D04 *p;

    for (p = D_80117560; p->a != -1;) {
        func_80116E9C(p++);
    }
    for (p = D_80117574; p->a != -1;) {
        func_80116E9C(p++);
    }
    for (p = D_801175AC; p->a != -1;) {
        func_80116E9C(p++);
    }
    for (p = D_801175F4; p->a != -1;) {
        func_80116E9C(p++);
    }
    func_80116F60((*(s32*)&GAME.playerAP), 0xc0, 0x3c);
    func_80117164(a, b, 0xc0, 0x5c);
    func_80116F60(c, 0xc0, 0x7c);
    func_80116F60(d, 0xc0, 0x9c);
    if (GetGraphType() == 1) {
        addDrawModePrim(0xe, 5);
    } else {
        GetGraphType();
        addDrawModePrim(0xe, 5);
    }
}

// INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116E9C);

#define setlen(p, _len) (((P_TAG *)(p))->len = (u8)(_len))
#define setcode(p, _code) (((P_TAG *)(p))->code = (u8)(_code))
typedef struct { s16 x, y; u8 u, v; } SP_16E9C;

void func_80116E9C(SP_16E9C *s)
{
    SPRT *p;

    p = D_1F800164;
    setlen(p, 4);
    setcode(p, 0x65);
    p->r0 = 0x80;
    p->g0 = 0x80;
    p->b0 = 0x80;
    p->code &= ~2;
    p->x0 = s->x;
    p->y0 = s->y;
    p->u0 = s->u;
    p->v0 = s->v;
    p->w = 8;
    p->h = 0x10;
    p->clut = 0x7812;
    addPrim((*(u_long*)&SCRATCHPAD.ot) + 0x14, p);
    D_1F800164 = (SPRT *)((char *)D_1F800164 + 0x14);
}
#undef setlen
#undef setcode

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80116F60);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", updatePointsBalloon);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_8011700C);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80117164);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_801172E8);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80117378);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_80117390);

INCLUDE_ASM("overlays/x13/nonmatchings/x13/x13_1", func_801173FC);
