#include "common.h"
#include "game.h"

s16 probeCollisionAtDepthB(u8*, s16, s16);
s32 probeCollisionAtDepthA(u8*, s16, s16);
s16 func_80043D2C(u8*, s16, s16);

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_8004117C);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItem);
void spawnItem(short id, short arg1, int arg2)
{
    func_80041940(0, id, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemDrop);
void spawnItemDrop(short arg0, short arg1, int arg2)
{
    func_80041940(1, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemAtPos);
void spawnItemAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(2, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemDropAtPos);
void spawnItemDropAtPos(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(3, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemBounce);
void spawnItemBounce(short arg0, short arg1, int arg2, short arg3, short arg4)
{
    func_80041940(4, arg0, arg1, arg2, arg3, arg4);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemFixed);
void spawnItemFixed(short arg0, short arg1, int arg2)
{
    func_80041940(5, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemChest);
void spawnItemChest(short arg0, short arg1, int arg2)
{
    func_80041940(8, arg0, arg1, arg2, 0, 0);
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80041940);
extern GameObject *allocObjectLayer5(void);
extern u8 D_8007E900[];
extern Fix16 *D_800A53D8__41940[];
extern Fix16 D_800A53AC[];
extern Fix16 *D_800A53DC__41940[];

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
            d = (D_800A53D8__41940[0]->p.whole - pos[0].p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (D_800A53AC[0].p.whole - pos[1].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk30 = pos[0].p.whole << 16;
            o->unk34 = pos[1].p.whole << 16;
            o->unk38 = pos[2].p.whole << 16;
        } else {
            d = (D_800A53D8__41940[0]->p.whole - pos[2].p.whole) << 8;
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
            d = (pos[0].p.whole - D_800A53D8__41940[0]->p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (pos[1].p.whole - D_800A53AC[0].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk30 = D_800A53D8__41940[0]->raw;
            o->unk34 = D_800A53AC[0].raw;
            o->unk38 = D_800A53DC__41940[0]->raw;
        } else {
            d = (pos[2].p.whole - D_800A53D8__41940[0]->p.whole) << 8;
            d /= 60;
            o->velH = d;
            d = (pos[1].p.whole - D_800A53AC[0].p.whole) << 8;
            d /= 60;
            o->velV = d;
            o->unk38 = D_800A53D8__41940[0]->raw;
            o->unk34 = D_800A53AC[0].raw;
            o->unk30 = D_800A53DC__41940[0]->raw;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemInit);
void dispatchAreaItemInit(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80122688();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D498();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemUpdate);
void dispatchAreaItemUpdate(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_8012298C();
    } else if (GAME.selectedArea == AREA04_HAUNTEDMANSION) {
        func_8011D79C();
    }
}

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80041DB4);
typedef struct { s16 h; s16 v; } VT_41DB4;
extern VT_41DB4 D_8007E90C[];
extern u8 D_8007DD88[];
extern void (*D_8007DE28[])(GameObject *);
extern void initItemObject(GameObject *);
extern void applyObjectSpeedXY(GameObject *);
extern s16 probeCollisionAtDepthA__41DB4(GameObject *, s16, s16);
extern void func_80023794(s32);
extern void freeObjectLayer5(GameObject *);

void func_80041DB4(GameObject *o)
{
    extern void tickAnimation(GameObject *);
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
                if (probeCollisionAtDepthA__41DB4(o, o->h->p.whole, o->y.p.whole + k)) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemFromEntry);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042204);
typedef struct { u16 a, b; } VP_42204;
extern VP_42204 D_8007E918[];
extern u8 D_8007DD88[];
extern void (*D_8007DE28[])(GameObject *);
extern void initItemObject(GameObject *);
extern s16 probeCollisionAtDepthA__42204(GameObject *, s32, s32);
extern void applyObjectSpeedXY(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void freeObjectLayer5(GameObject *);

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
        } else if (probeCollisionAtDepthA__42204(o, o->h->p.whole, (s16)(o->y.p.whole + 8))) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", spawnItemLinked);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", dispatchAreaItemDraw);
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", getCollisionColumnPtr);

u8* getCollisionColumnPtr(s16 arg0, u8 arg1) {
    u8* base;
    s32 off;

    base = (&D_8007EB44)[arg1];
    off = *(u16*)(base + 8);
    base += off;
    off = *(u16*)(base + ((arg0 / 8) << 1));
    return base + off;
}

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", getCollisionPlaneAt);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", readCollisionTileShape);
inline s32 readCollisionTileShape(u8* arg0) {
    u16 pad;
    s32 dir;

    pad = *(u16*)0x1F800282;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", probeTileShapeThreePoints);
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

INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", func_80042C20);

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", clampToCeilingAndProbeSides);
s32 clampToCeilingAndProbeSides(u8* arg0) {
    u8* obj;
    s16 ret;

    obj = arg0;
    if (*(s16*)(arg0 + 0x16) < D_800A38E8 - 0x88) {
        *(s16*)(obj + 0x16) = D_800A38E8 - 0x88;
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", applyCollisionTileResponse);
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
    tmp = *(u16*)0x1F800284;
    *(u8*)0x1F8001D2 = 1;
    arg0[0xA0] = 0;
    arg0[0xBE] = 0;
    pad = *(u16*)0x1F800282;
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
        if (*(u16*)0x1F800282 & 0x1000) {
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

// INCLUDE_ASM("asm/scus_942.36/nonmatchings/main/game/itemspawn", probeSidesAndApplyTileResponse);
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
