#include "common.h"
#include "game.h"

extern u8 D_8007E924_x[] asm("D_8007E924");
extern u8 D_8007E974_x[] asm("D_8007E974");
extern u8 D_8007E994_x[] asm("D_8007E994");
extern u8 D_8007E9AC_x[] asm("D_8007E9AC");
extern u8 D_8007E9C4_x[] asm("D_8007E9C4");
extern u8 D_8007EA48_x[] asm("D_8007EA48");
extern u8 D_8007EA50_x[] asm("D_8007EA50");
extern u8 D_8007EA58_x[] asm("D_8007EA58");
extern u8 D_8007EA60_x[] asm("D_8007EA60");
extern u8 D_8007EA68_x[] asm("D_8007EA68");
extern u8 D_8007EA80_x[] asm("D_8007EA80");
extern u8 D_8007EA84_x[] asm("D_8007EA84");
extern u8 D_8007EA88_x[] asm("D_8007EA88");
extern u8 D_8007EA90_x[] asm("D_8007EA90");
extern u8 D_8007EA94_x[] asm("D_8007EA94");
extern u8 D_8007EA9C_x[] asm("D_8007EA9C");
extern u8 D_8007EAA8_x[] asm("D_8007EAA8");
extern u8 D_8007EAB0_x[] asm("D_8007EAB0");
extern u8 D_8007EAC8_x[] asm("D_8007EAC8");
extern u8 D_8007EACC_x[] asm("D_8007EACC");
extern u8 D_8007EAD4_x[] asm("D_8007EAD4");
extern u8 D_8007EAD8_x[] asm("D_8007EAD8");
extern u8 D_8007EAE0_x[] asm("D_8007EAE0");
extern u8 D_8007EAEC_x[] asm("D_8007EAEC");
extern u8 D_8007EAF0_x[] asm("D_8007EAF0");
extern u8 D_80115EA8_x[] asm("D_80115EA8");
extern u8 D_80116064_x[] asm("D_80116064");
extern u8 D_8011AD80_x[] asm("D_8011AD80");
extern u8 D_8011E46C_x[] asm("D_8011E46C");
extern u8 D_80122A34_x[] asm("D_80122A34");
extern u8 D_80122D60_x[] asm("D_80122D60");
extern u8 D_80122E68_x[] asm("D_80122E68");
extern u8 D_8012325C_x[] asm("D_8012325C");
extern u8 D_8012E538_x[] asm("D_8012E538");
extern u8 D_8012E774_x[] asm("D_8012E774");
extern u8 D_8012E938_x[] asm("D_8012E938");
extern u8 D_8012ECBC_x[] asm("D_8012ECBC");
extern u8 D_8012EE78_x[] asm("D_8012EE78");
extern u8 D_8012F034_x[] asm("D_8012F034");
extern u8 D_8012F220_x[] asm("D_8012F220");
extern u8 D_8012F4FC_x[] asm("D_8012F4FC");
extern u8 D_8012F860_x[] asm("D_8012F860");
extern u8 D_8012FC6C_x[] asm("D_8012FC6C");
extern u8 D_8012FED8_x[] asm("D_8012FED8");
extern u8 D_8013016C_x[] asm("D_8013016C");
extern u8 dispatchAreaItemDraw_x[] asm("dispatchAreaItemDraw");
extern u8 dispatchAreaItemInit_x[] asm("dispatchAreaItemInit");
extern u8 func_8004117C_x[] asm("func_8004117C");
extern u8 func_80041DB4_x[] asm("func_80041DB4");
extern u8 func_80042204_x[] asm("func_80042204");

u32 D_8007E8A8_d[19] asm("D_8007E8A8") = {
    (u32)func_8004117C_x, (u32)func_8004117C_x, (u32)func_8004117C_x, (u32)func_8004117C_x,
    (u32)func_8004117C_x, (u32)func_8004117C_x, (u32)D_80122E68_x, (u32)dispatchAreaItemInit_x,
    (u32)func_8004117C_x, (u32)func_80041DB4_x, (u32)func_80042204_x, (u32)D_80122A34_x,
    (u32)D_80122D60_x, (u32)D_8012325C_x, (u32)D_8011E46C_x, (u32)D_80115EA8_x,
    (u32)D_8011AD80_x, (u32)D_80116064_x, (u32)dispatchAreaItemDraw_x,
};
u32 D_8007E8F4_d[3] asm("D_8007E8F4") = {
    0xFF000080, 0xFF00FF80, 0xFF000000,
};
u32 D_8007E900_d[3] asm("D_8007E900") = {
    0x04010401, 0x04040401, 0x00000004,
};
u32 D_8007E90C_d[3] asm("D_8007E90C") = {
    0xFF000080, 0xFF00FF80, 0xFF000000,
};
u32 D_8007E918_d[3] asm("D_8007E918") = {
    0xFF000080, 0xFF00FF80, 0xFF000000,
};
u32 D_8007E924_d[20] asm("D_8007E924") = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
u32 D_8007E974_d[8] asm("D_8007E974") = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x04B00000, 0x0A460000, 0x00000000, 0x00000000,
};
u32 D_8007E994_d[6] asm("D_8007E994") = {
    0x00000000, 0x00000000, 0x00820000, 0x01700000,
    0x08800000, 0x0B400000,
};
u32 D_8007E9AC_d[6] asm("D_8007E9AC") = {
    0x0B400000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000,
};
u32 D_8007E9C4_d[8] asm("D_8007E9C4") = {
    0x0000FFC0, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
u32 D_8007E9E4_d[1] asm("D_8007E9E4") = {
    0x00001498,
};
u32 D_8007E9E8_d[4] asm("D_8007E9E8") = {
    0x01680000, 0x05460000, 0x01680000, 0x05A00000,
};
u32 D_8007E9F8_d[3] asm("D_8007E9F8") = {
    (u32)D_8007E974_x, (u32)D_8007E994_x, (u32)D_8007E924_x,
};
u32 D_8007EA04_d[17] asm("D_8007EA04") = {
    (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E924_x,
    (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E9AC_x, (u32)D_8007E924_x,
    (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E9C4_x,
    (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E924_x, (u32)D_8007E924_x,
    (u32)D_8007E924_x,
};
u32 D_8007EA48_d[2] asm("D_8007EA48") = {
    0x00050505, 0x00000000,
};
u32 D_8007EA50_d[2] asm("D_8007EA50") = {
    0x00000000, 0x00000000,
};
u32 D_8007EA58_d[2] asm("D_8007EA58") = {
    0x00000100, 0x00000000,
};
u32 D_8007EA60_d[2] asm("D_8007EA60") = {
    0x00010101, 0x00000101,
};
u32 D_8007EA68_d[6] asm("D_8007EA68") = {
    0x05030607, 0x00000000, 0x00010000, 0x00000000,
    0x01000000, 0x00000000,
};
u32 D_8007EA80_d[1] asm("D_8007EA80") = {
    0x01000100,
};
u32 D_8007EA84_d[1] asm("D_8007EA84") = {
    0x00000000,
};
u32 D_8007EA88_d[2] asm("D_8007EA88") = {
    0x00000000, 0x00000000,
};
u32 D_8007EA90_d[1] asm("D_8007EA90") = {
    0x00000000,
};
u32 D_8007EA94_d[2] asm("D_8007EA94") = {
    0x00000001, 0x00000000,
};
u32 D_8007EA9C_d[3] asm("D_8007EA9C") = {
    0x00020001, 0x00020001, 0x00000000,
};
u32 D_8007EAA8_d[2] asm("D_8007EAA8") = {
    0x01000100, 0x00000000,
};
u32 D_8007EAB0_d[6] asm("D_8007EAB0") = {
    0x05030607, 0x00000000, 0x00010000, 0x00000000,
    0x01000000, 0x00000000,
};
u32 D_8007EAC8_d[1] asm("D_8007EAC8") = {
    0x00000001,
};
u32 D_8007EACC_d[2] asm("D_8007EACC") = {
    0x00000000, 0x00000001,
};
u32 D_8007EAD4_d[1] asm("D_8007EAD4") = {
    0x00000000,
};
u32 D_8007EAD8_d[2] asm("D_8007EAD8") = {
    0x00000000, 0x00000000,
};
u32 D_8007EAE0_d[3] asm("D_8007EAE0") = {
    0x00000000, 0x00000000, 0x00000000,
};
u32 D_8007EAEC_d[1] asm("D_8007EAEC") = {
    0x00000000,
};
u32 D_8007EAF0_d[1] asm("D_8007EAF0") = {
    0x00000100,
};
u32 D_8007EAF4_d[20] asm("D_8007EAF4") = {
    (u32)D_8007EA48_x, (u32)D_8007EA50_x, (u32)D_8007EA58_x, (u32)D_8007EA60_x,
    (u32)D_8007EA68_x, (u32)D_8007EA80_x, (u32)D_8007EA84_x, (u32)D_8007EA88_x,
    (u32)D_8007EA90_x, (u32)D_8007EA94_x, (u32)D_8007EA9C_x, (u32)D_8007EAA8_x,
    (u32)D_8007EAB0_x, (u32)D_8007EAC8_x, (u32)D_8007EACC_x, (u32)D_8007EAD4_x,
    (u32)D_8007EAD8_x, (u32)D_8007EAE0_x, (u32)D_8007EAEC_x, (u32)D_8007EAF0_x,
};
u32 D_8007EB44_d[12] asm("D_8007EB44") = {
    (u32)D_8012E538_x, (u32)D_8012E774_x, (u32)D_8012E938_x, (u32)D_8012ECBC_x,
    (u32)D_8012EE78_x, (u32)D_8012F034_x, (u32)D_8012F220_x, (u32)D_8012F4FC_x,
    (u32)D_8012F860_x, (u32)D_8012FC6C_x, (u32)D_8012FED8_x, (u32)D_8013016C_x,
};
u32 D_8007EB74_d[2] asm("D_8007EB74") = {
    0x00000000, 0x00000000,
};

asm(
    ".globl D_8007E8F6\nD_8007E8F6 = D_8007E8F4 + 2\n"
    ".globl D_8007E90E\nD_8007E90E = D_8007E90C + 2\n"
    ".globl D_8007E91A\nD_8007E91A = D_8007E918 + 2\n"
);

s16 probeCollisionAtDepthB(u8*, s16, s16);
s32 probeCollisionAtDepthA(u8*, s16, s16);

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", func_8004117C);
typedef struct { s16 h; s16 v; } VT_4117C;
extern VT_4117C D_8007E8F4[];
extern void (*D_8007DE28[])(GameObject *);
extern u8 D_8009C132, D_8009C163, D_8009C3EF, D_8009C175, D_8009C371;
s16 func_80043AB0(GameObject *o, s16 x, s16 y, s32 dir);

void func_8004117C(GameObject *o)
{
    s32 k;

    switch (o->state) {
    case 0:
        o->cooldownTimer = 0;
        if (o->subtype == 0x3F && D_8009C132 != 0xFF) {
            o->state = 3;
            break;
        }
        if (o->subtype == 0x9E && D_8009C163 != 0xFF) {
            o->state = 3;
            break;
        }
        if (o->subtype == 0x90 && D_8009C3EF < 4) break;
        if (o->subtype == 0x3C && (D_8009C175 == 0 || D_8009C175 == 0xFF)) {
            o->state = 3;
            break;
        }
        if (o->subtype == 3 && o->unkC == 1 && (D_8009C114 != 0xFF || D_8009C371 != 0)) {
            o->state = 3;
            break;
        }
        initItemObject(o);
        switch (o->type) {
        case 1:
            o->timer = 0x3C;
            break;
        case 2:
            o->unkB4 = 1;
            break;
        case 3:
            o->active = 4;
            o->unkB4 = 1;
            o->timer = 0x1E;
            break;
        case 4:
            o->unkB4 = 0;
            break;
        case 5:
        case 8:
            o->velY = -0x500;
            o->timer = 0x3C;
            o->unk34 = o->y.p.whole << 16;
            break;
        case 10:
            if (o->velV != 0) {
                o->unkB4 = 1;
            } else {
                o->unkB4 = 0;
            }
            o->timer = 0x1E;
            break;
        }
        o->state++;
        break;
    case 1:
        k = 8;
        if (o->subtype == 2 && o->unkC >= 4)
            k = 0x1C;
        switch (o->type) {
        case 1:
        case 3:
        case 10:
            if (o->timer != 0 && --o->timer == 0)
                o->active = 1;
        }
        switch (o->type) {
        case 2:
        case 3:
        case 4:
        case 10:
            if (o->unk68 & 1) {
                o->unk68 = 0;
                o->unkB4 = 1;
                o->velH = D_8007E8F4[o->animFrame].h;
                o->velV = D_8007E8F4[o->animFrame].v;
            } else if (o->touchFlag & 1) {
                o->touchFlag = 0;
                if (o->velV <= 0x100) {
                    if (o->type == 4) {
                        o->velH = 0;
                        o->velV = 0;
                    }
                    o->unkB4 = 0;
                    o->active = 2;
                } else {
                    o->velV = -o->velV / 4;
                }
            } else if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + k)) {
                if (o->velV <= 0x100) {
                    if (o->type == 4) {
                        o->velH = 0;
                        o->velV = 0;
                    }
                    o->unkB4 = 0;
                    o->active = 2;
                } else {
                    o->velV = -o->velV / 4;
                }
            } else if (func_80043AB0(o, o->h->p.whole + 8, o->y.p.whole, 0) ||
                       func_80043AB0(o, o->h->p.whole - 8, o->y.p.whole, 1)) {
                o->velH = -o->velH;
            }
            if ((u16)o->unkB4 != 0) {
                if (o->type == 10) {
                    applyObjectSpeedXY((u8 *)o);
                    if (o->velV < 0x800)
                        o->velV += 0x20;
                    if (o->y.p.whole - ((Fix16 *)&o->unk34)->p.whole >= -7) {
                        o->unkB4 = 0;
                        o->velV = 0;
                    }
                } else {
                    applyObjectSpeedXY((u8 *)o);
                    o->velV += 0x20;
                }
            }
            break;
        case 5:
        case 8:
            o->unk30 += o->velH << 8;
            o->unk34 += o->velV << 8;
            o->unk34 += o->velY << 8;
            o->h->raw = o->unk30;
            o->y.raw = o->unk34;
            *o->d = *(Fix16 *)&o->unk38;
            if (o->velY < 0x800)
                o->velY += 0x28;
            if (o->velY > 0)
                o->active = 1;
            if (--o->timer == 0)
                o->state++;
            break;
        }
        if (o->cooldownTimer != 0)
            o->cooldownTimer--;
        if (func_80022E44(o))
            tickAnimation(o);
        break;
    case 2:
        D_8007DE28[D_8007DD88[o->subtype]](o);
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItem);
void spawnItem(short id, short arg1, int arg2)
{
    func_80041940(0, id, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemDrop);
void spawnItemDrop(short arg0, short arg1, int arg2)
{
    func_80041940(1, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemAtPos);
void spawnItemAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(2, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemDropAtPos);
void spawnItemDropAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(3, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemBounce);
void spawnItemBounce(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(4, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemFixed);
void spawnItemFixed(short arg0, short arg1, int arg2)
{
    func_80041940(5, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemChest);
void spawnItemChest(short arg0, short arg1, int arg2)
{
    func_80041940(8, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", func_80041940);

void func_80041940(s32 type, s16 sub, s16 flag, Fix16 *pos, s16 vx, s16 vy)
{
    GameObject *o = allocObjectLayer5();
    u8 c;
    s32 d;

    if (o == 0)
        return;
    c = D_8007E900[type];
    o->type = type;
    o->subtype = sub;
    o->active = c;
    o->unkC = flag | 0x80;
    { u8 c2 = ((u8 **)&D_8007E6E4)[D_8007E61C[sub]][3];
    o->animFrame = 0;
    o->unkF = c2; }
    o->h->raw = pos[0].p.whole << 16;
    o->y.raw = pos[1].p.whole << 16;
    o->d->raw = pos[2].p.whole << 16;
    o->velH = vx;
    o->velV = vy;
    switch (type) {
    case 5:
        if (!(D_1F8001C8 & 1)) {
            d = (PLAYER.obj.h->p.whole - pos[0].p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (D_800A53AC[0].p.whole - pos[1].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk30 = pos[0].p.whole << 16;
            o->unk34 = pos[1].p.whole << 16;
            o->unk38 = pos[2].p.whole << 16;
        } else {
            d = (PLAYER.obj.h->p.whole - pos[2].p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (D_800A53AC[0].p.whole - pos[1].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk38 = pos[0].p.whole << 16;
            o->unk34 = pos[1].p.whole << 16;
            o->unk30 = pos[2].p.whole << 16;
        }
        break;
    case 8:
        if (!(D_1F8001C8 & 1)) {
            d = (pos[0].p.whole - PLAYER.obj.h->p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (pos[1].p.whole - D_800A53AC[0].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk30 = PLAYER.obj.h->raw;
            o->unk34 = D_800A53AC[0].raw;
            o->unk38 = PLAYER.obj.d->raw;
        } else {
            d = (pos[2].p.whole - PLAYER.obj.h->p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (pos[1].p.whole - D_800A53AC[0].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk38 = PLAYER.obj.h->raw;
            o->unk34 = D_800A53AC[0].raw;
            o->unk30 = PLAYER.obj.d->raw;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", dispatchAreaItemInit);
void dispatchAreaItemInit(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80122688();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D498();
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", dispatchAreaItemUpdate);
void dispatchAreaItemUpdate(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_8012298C();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D79C();
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", func_80041DB4);
typedef struct { s16 h; s16 v; } VT_41DB4;
extern VT_41DB4 D_8007E90C[];
extern void (*D_8007DE28[])(GameObject *);

void func_80041DB4(GameObject *o)
{
    s32 k;
    switch (o->state) {
    case 0:
        initItemObject(o);
        o->timer = 30;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        k = 8;
        if (o->subtype == 2 && o->unkC >= 4)
            k = 0x1c;
        if (func_80022E44(o) == 0)
            break;
        switch (o->subState) {
        case 0:
            applyObjectSpeedXY(o);
            if (o->velV <= 0x800)
                o->velV += 0x20;
            if (o->unk68 & 1) {
                o->unk68 = 0;
                o->velH = D_8007E90C[o->animFrame].h;
                o->velV = D_8007E90C[o->animFrame].v;
            } else if (o->touchFlag & 1) {
                o->touchFlag = 0;
                if (o->velV <= 0x100) {
                    o->active = 2;
                    o->subState++;
                } else {
                    o->velV = -o->velV / 4;
                }
            } else if (o->velV >= 0) {
                if (((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + k)) {
                    if (o->velV <= 0x100) {
                        o->active = 2;
                        o->subState++;
                    } else {
                        o->velV = -o->velV / 4;
                    }
                }
            }
            if (o->subtype == 0x94 && D_8009BCCA == 3 && o->y.p.whole >= -0x3bf) {
                o->y.p.whole = -0x3c0;
                o->active = 2;
                o->subState++;
            }
            break;
        case 1:
            if (o->unk68 & 1) {
                o->unk68 = 0;
                o->velH = D_8007E90C[o->animFrame].h;
                o->velV = D_8007E90C[o->animFrame].v;
                o->subState = 0;
            }
            break;
        }
        tickAnimation(o);
        if (o->timer && --o->timer == 0)
            o->active = 1;
        break;
    case 2:
        if (o->unkC & 0x80) {
            func_80023794(o->objectIndex);
            o->unkC &= 0x7f;
        }
        D_8007DE28[D_8007DD88[o->subtype]](o);
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemFromEntry);
void spawnItemFromEntry(u8* arg0, s16* arg1, s32 arg2, s32 arg3, u8* arg4) {
    u8* obj;

    obj = allocObjectLayer5();
    if (obj != NULL) {
        obj[0] = 4;
        obj[2] = 9;
        obj[3] = arg0[1];
        obj[0xC] = arg0[2];
        obj[0xF] = ((itemDef*)D_8007E6E4[D_8007E61C[arg0[1]]])->unk3;
        *(s16*)(obj + 0x2E) = 0;
        **(s32**)(obj + 0x40) = arg1[1] << 16;
        *(s32*)(obj + 0x14) = arg1[3] << 16;
        **(s32**)(obj + 0x44) = arg1[5] << 16;
        *(s16*)(obj + 0x80) = arg2;
        *(s16*)(obj + 0x82) = arg3;
        obj[0x6B] = arg4[0x6B];
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", func_80042204);
typedef struct { u16 a, b; } VP_42204;
extern VP_42204 D_8007E918[];
extern void (*D_8007DE28[])(GameObject *);

void func_80042204(GameObject *o)
{
    char pad;
    switch (o->state) {
    case 0:
        initItemObject(o);
        o->active = 4;
        if (o->velV != 0) {
            o->unkB4 = 1;
        } else {
            o->unkB4 = 0;
        }
        o->timer = 30;
        o->state++;
        break;
    case 1:
        if (!func_80022E44(o)) break;
        if (o->timer != 0 && --o->timer == 0) {
            o->active = 1;
        }
        if (o->unk68 & 1) {
            o->unk68 = 0;
            o->unkB4 = 1;
            o->velH = D_8007E918[o->animFrame].a;
            o->velV = D_8007E918[o->animFrame].b;
        } else if (o->touchFlag & 1) {
            o->touchFlag = 0;
            if (o->velV <= 0x100) {
                o->unkB4 = 0;
                o->active = 2;
            } else {
                o->velV = -o->velV / 4;
            }
        } else if (((s16 (*)(GameObject *, s32, s32))probeCollisionAtDepthA)(o, o->h->p.whole, (s16)(o->y.p.whole + 8))) {
            o->active = 2;
            if (o->velV <= 0x100) {
                o->unkB4 = 0;
                o->active = 2;
            } else {
                o->velV = -o->velV / 4;
            }
        }
        if (*(u16 *)&o->unkB4) {
            applyObjectSpeedXY(o);
            if (o->velV < 0x800) {
                o->velV += 0x20;
            }
            if (o->y.p.whole - ((s16 *)&o->unk34)[1] >= -7) {
                o->unkB4 = 0;
                o->velV = 0;
            }
        }
        tickAnimation(o);
        break;
    case 2:
        D_8007DE28[D_8007DD88[o->subtype]](o);
        break;
    case 3:
        freeObjectLayer5(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", spawnItemLinked);
void spawnItemLinked(u8* arg0, s16 arg1, s16 arg2, s16* arg3, u16 arg4, u16 arg5) {
    u8* obj;

    obj = allocObjectLayer5();
    if (obj != NULL) {
        obj[0] = 4;
        obj[2] = 3;
        obj[3] = arg1;
        obj[0xC] = arg2 | 0x80;
        obj[0xF] = ((itemDef*)D_8007E6E4[D_8007E61C[arg1]])->unk3;
        *(s16*)(obj + 0x2E) = 0;
        **(s32**)(obj + 0x40) = arg3[1] << 16;
        *(s32*)(obj + 0x14) = arg3[3] << 16;
        **(s32**)(obj + 0x44) = arg3[5] << 16;
        *(Vec3L*)(obj + 0x30) = *(Vec3L*)(obj + 0x10);
        *(s16*)(obj + 0x80) = arg4;
        *(s16*)(obj + 0x82) = arg5;
        *(u8**)(arg0 + 0x94) = obj;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", dispatchAreaItemDraw);
void dispatchAreaItemDraw(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80122F64();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D844();
    } else if (GAME.selectedArea == AREA10_DEEPJUNGLE) {
        func_8011CD70();
    } else if (GAME.selectedArea == AREA13_PIGISLAND) {
        func_8011602C();
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", getCollisionColumnPtr);

u8* getCollisionColumnPtr(s16 arg0, u8 arg1) {
    u8* base;
    s32 off;

    base = (&D_8007EB44)[arg1];
    off = *(u16*)(base + 8);
    base += off;
    off = *(u16*)(base + ((arg0 / 8) << 1));
    return base + off;
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", getCollisionPlaneAt);
typedef struct { s16 x, y; } PlaneOrigin;
extern PlaneOrigin D_8007E9E4[];
extern PlaneOrigin D_8007E9E8[];
extern PlaneOrigin *D_8007E9F8[];
extern PlaneOrigin *D_8007EA04;
extern u8 *D_8007EAF4[];
extern char D_8007EB74[];

char *getCollisionPlaneAt(x, y)
s16 x;
s16 y;
{
    PlaneOrigin *t;
    char *b;
    s16 r, c;
    u8 lim;

    if (x < D_800A38E4 - 0xaa || D_800A38E6 + 0xaa < x || ((*(s32 *)&GAME) != 0xe && x < 0))
        return D_8007EB74;
    if (GAME.selectedArea == 0 && D_8009BCCA != 3) {
        if (y >= 0x10f) {
            b = (char *)WHM_DATA_S32Arr[0];
            y -= 0x10e;
        } else {
            b = (char *)WHM_DATA_S32Arr[1];
        }
        t = D_8007E9F8[GAME.selectedArea];
        t += D_8009BCCA;
    } else if ((GAME.selectedArea == 4 || GAME.selectedArea == 12) && D_8009BCCA < 4) {
        t = &D_8007E9E8[D_8009BCCA];
        b = (char *)WHM_DATA_S32Arr[SPAD->unk1C8 & 1];
    } else if (GAME.selectedArea == 3 && (D_8009BCCA == 1 || D_8009BCCA == 5)) {
        if (PLAYER.obj.d->p.whole < 0) {
            b = (char *)WHM_DATA_S32Arr[1];
            t = D_8007E9E4;
            y += 0x5a;
        } else {
            t = D_8007EA04;
            b = (char *)WHM_DATA_S32Arr[0];
            t += D_8009BCCA;
        }
    } else {
        t = D_8007E9F8[GAME.selectedArea];
        b = (char *)WHM_DATA_S32Arr[0];
        t += D_8009BCCA;
    }
    if (SPAD->unk1C8 & 1)
        r = (t->y - y) / 90;
    else
        r = (y - t->y) / 90;
    { u8 *q = D_8007EAF4[GAME.selectedArea]; lim = q[D_8009BCCA]; }
    if (lim < r) r = lim;
    if (r < 0) r = 0;
    b += *(u16 *)(b + 8 + r * 2);
    c = (x - t->x) / 8;
    if (c < 0) c = 0;
    return b + *(u16 *)(b + (c << 1));
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", readCollisionTileShape);
inline s32 readCollisionTileShape(u8* arg0) {
    u16 pad;
    s32 dir;

    pad = SPAD->unk282;
    dir = (pad >> 5) & 0xF;
    if (!(pad & 0x3000)) {
        switch (dir) {
        case 13:
            arg0[0xA1] = 3;
            break;
        case 14:
            arg0[0xA1] = 2;
            break;
        case 15:
            arg0[0xA1] = 1;
            break;
        }
        return arg0[0xA1];
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", probeTileShapeThreePoints);
s32 probeTileShapeThreePoints(arg0, arg1)
u8* arg0;
s16 arg1;
{
    u8* obj = arg0;

    obj[0xA1] = 0;
    if (probeCollisionAtDepthB(obj, (*(u16**)(obj + 0x40))[1] + 8, arg1 + (*(u16*)(obj + 0x16) + *(u16*)(obj + 0x70))) != 0 && readCollisionTileShape(obj) != 0) {
        return 1;
    }
    if (probeCollisionAtDepthB(obj, (*(u16**)(obj + 0x40))[1] - 8, arg1 + (*(u16*)(obj + 0x16) + *(u16*)(obj + 0x70))) != 0 && readCollisionTileShape(obj) != 0) {
        return 1;
    }
    if (probeCollisionAtDepthB(obj, (*(s16**)(obj + 0x40))[1], *(s16*)(obj + 0x16)) != 0) {
        if (readCollisionTileShape(obj) != 0) {
            return 1;
        }
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", func_80042C20);
s16 func_80043AB0(GameObject *o, s16 x, s16 y, s32 dir);

#define HIT(DIR) \
    if (DIR == (o->animFrame & 1)) { \
        if (!DIR) o->unkA6 = 2; else o->unkA6 = 3; \
    }

s16 func_80042C20(GameObject *o)
{
    s16 d;
    s16 dx;
    s16 dx2;
    s16 lo;
    s16 hi;
    s16 r;
    s32 h;
    s16 b;
    s16 dir;
    s16 dir2;
    s32 t;

    if (*(u8 *)&o->unkAA != 0) return 0;
    if (o->active == 5) return 0;
    d = o->h->p.whole - (*(u16 *)&SPAD->unk168[0].p.whole);
    if (d == 0) {
        if (!(o->animFrame & 1)) {
            dx = 8; dx2 = -8; t = 0; dir2 = 1;
        } else {
            dx = -8; dx2 = 8; t = 1; dir2 = 0;
        }
    } else if (d >= 0) {
        dx = 8; dx2 = -8; t = 0; dir2 = 1;
    } else {
        dx = -8; dx2 = 8; t = 1; dir2 = 0;
    }
    h = o->hitOffsetY;
    b = o->hitOffsetY;
    lo = b;
    if (h >= 8) lo = 8;
    hi = b;
    if (h >= 14) hi = 14;
    dir = t;
    r = func_80043AB0(o, o->h->p.whole + dx, o->y.p.whole - lo, dir);
    if (r) {
        HIT(dir)
    } else {
        r = func_80043AB0(o, o->h->p.whole + dx, o->y.p.whole + hi, dir);
        if (r) {
            HIT(dir)
        } else {
            r = func_80043AB0(o, o->h->p.whole + dx, o->y.p.whole + lo, dir);
            if (r) {
                HIT(dir)
            }
        }
    }
    dir = dir2;
    if (func_80043AB0(o, o->h->p.whole + dx2, o->y.p.whole + hi, dir)) {
        HIT(dir)
    } else if (func_80043AB0(o, o->h->p.whole + dx2, o->y.p.whole + lo, dir)) {
        HIT(dir)
    }
    return r;
}
#undef HIT

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", clampToCeilingAndProbeSides);
s32 clampToCeilingAndProbeSides(u8* arg0) {
    u8* obj;
    s16 ret;

    obj = arg0;
    if (*(s16*)(arg0 + 0x16) < D_800A38E8 - NTSC_PAL(0x88, 0x90)) {
        *(s16*)(obj + 0x16) = D_800A38E8 - NTSC_PAL(0x88, 0x90);
        return 1;
    }
    ret = func_80043D2C(arg0, (*(u16**)(obj + 0x40))[1] + 4, *(s16*)(arg0 + 0x16) - 0x15);
    if (ret != 0) {
        return ret;
    }
    ret = func_80043D2C(obj, (*(u16**)(obj + 0x40))[1] - 4, *(u16*)(obj + 0x16) - 0x15);
    if (ret != 0) {
        return ret;
    }
    return 0;
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", applyCollisionTileResponse);
void applyCollisionTileResponse(u8* arg0) {
    s32 unused[2];
    s16 speed;
    u32 pad;
    u16 tmp;
    s32 dir;
    u8 dir2;
    u8 hi;

    speed = D_1F80027E;
    if (speed < 0) {
        speed = -speed;
    }
    if (speed > 8) {
        speed = 8;
    }
    if (D_1F80027E < 0) {
        speed = -speed;
    }
    arg0[0x69] = 1;
    tmp = (*(u16 *)&SPAD->unk284);
    SPAD->unk1D2 = 1;
    arg0[0xA0] = 0;
    arg0[0xBE] = 0;
    pad = SPAD->unk282;
    *(s16*)(arg0 + 0xB0) = speed;
    *(u16*)(arg0 + 0xAE) = tmp;
    hi = pad >> 15;
    dir = (pad >> 5) & 0xF;
    dir2 = dir;
    if (!(pad & 0x3000)) {
        switch (dir) {
        case 0:
            arg0[0xBE] = 0;
            break;
        case 1:
            arg0[0xBE] = 2;
            break;
        case 2:
            arg0[0xBE] = 0x10;
            break;
        case 3:
            arg0[0xBE] = 0x20;
            break;
        }
        arg0[0xBE] = hi | arg0[0xBE];
    } else {
        if (pad & 0x2000) {
            switch ((int)((unsigned)dir >> 2)) {
            case 0:
                arg0[0xA0] = 2;
                break;
            case 1:
                arg0[0xA0] = 1;
                break;
            case 2:
                arg0[0xA0] = 3;
                break;
            }
        }
        if (SPAD->unk282 & 0x1000) {
            switch (dir2 & 3) {
            case 0:
                arg0[0xA0] |= 0x10;
                break;
            case 1:
                arg0[0xA0] |= 0x20;
                break;
            case 2:
                arg0[0xA0] |= 0x30;
                break;
            case 3:
                arg0[0xA0] |= 0x40;
                break;
            }
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/itemspawn", probeSidesAndApplyTileResponse);
s32 probeSidesAndApplyTileResponse(arg0, arg1, arg2)
u8* arg0;
s16 arg1;
s32 arg2;
{
    u8* obj = arg0;
    s16* src;

    s32 first;
    s32 second;
    s32 ret;

    src = &D_80114670[(*(s16**)(obj + 0x24))[1] * 4];
    *(s16*)(obj + 0x6C) = *src++;
    *(s16*)(obj + 0x6E) = *src++;
    *(s16*)(obj + 0x70) = *src;
    *(s16*)(obj + 0x72) = src[1];
    obj[0x69] = 0;
    *(s16*)(obj + 0xB0) = 0;
    obj[0xA0] = 0;
    obj[0xBE] = 0;
    if (obj[0x9C] != 0) {
        if (*(s16*)(obj + 0x7C) >= 0) {
            first = 8;
            second = -8;
        } else {
            first = -8;
            second = 8;
        }
    } else {
        if (*(s16*)(obj + 0x80) >= 0) {
            first = 8;
            second = -8;
        } else {
            first = -8;
            second = 8;
        }
    }
    ret = probeCollisionAtDepthA(obj, (*(s16**)(obj + 0x40))[1], arg1 + (*(u16*)(obj + 0x16) + *(u16*)(obj + 0x70)));
    if ((s16)ret == 0) {
        ret = probeCollisionAtDepthA(obj, (*(u16**)(obj + 0x40))[1] + first, arg1 + (*(u16*)(obj + 0x16) + *(u16*)(obj + 0x70)));
        if ((s16)ret == 0) {
            ret = probeCollisionAtDepthA(obj, (*(u16**)(obj + 0x40))[1] + second, arg1 + (*(u16*)(obj + 0x16) + *(u16*)(obj + 0x70)));
            if ((s16)ret == 0) {
                return 0;
            }
        }
    }
    if (!arg2) {
        *(u16*)(obj + 0x16) += arg1;
    }
    applyCollisionTileResponse(obj);
    return (s16)ret;
}
