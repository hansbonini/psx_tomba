#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/objsetup", updateGrabSnout);
extern s16 fixedMulSin2(s16 a, s16 b);

void updateGrabSnout(GameObject *obj)
{
    s16 v;
    switch (obj->state) {
    case 0:
        obj->state++;
        if (GetGraphType() == 1 || GetGraphType() == 2) v = 0xa5;
        else v = 0x35;
        obj->tpage = v;
        *(s8 *)&obj->priority = -9;
        obj->drawType = DRAW_NONE_14;
        obj->drawFlags = 0x81;
        obj->clut = GetClut(0x160, obj->param + 0x1f1);
        obj->animFrame = 0;
        obj->anim = D_80012680;
        obj->spriteBank = D_1F8002D8[0];
        obj->localX = D_1F80016A[0] << 16;
        obj->y.p.whole = D_1F80016E_U16Arr[0];
        obj->d->p.whole = D_1F800172[0];
        obj->velV = -0xc00;
        obj->timer = 1;
        obj->unkB4 = 0x80;
        obj->unkB6 = 0;
        obj->unkB8 = 100;
        readAnimFrameCount(obj);
        break;
    case 1:
        obj->visible = 1;
        pushDrawListCapped(obj);
        if (--obj->timer == 0) {
            obj->timer = 1;
            if (--*(u16 *)&obj->unkB4 == 0) obj->state++;
        }
        obj->unkB6 = (obj->unkB6 + 8) & 0xff;
        obj->unkB8 += 2;
        obj->h->raw = obj->localX + (fixedMulSin2(obj->unkB6, 0x10) << 16);
        obj->y.raw += obj->velV << 4;
        break;
    case 2:
        obj->state++;
        break;
    case 3:
        freeObjectLayer3(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", updateEventCube);

void updateEventCube(GameObject *obj)
{
    switch (obj->state) {
    case 0:
        obj->drawType = DRAW_OVERLAY_7;
        *(s8 *)&obj->priority = -20;
        obj->tpage = 0x14;
        obj->drawFlags = 0;
        obj->spriteBank = ((struct { char pad[0x2d8]; s32 v; } *)0x1F800000)->v;
        obj->anim = ((void **)&D_800122B0)[obj->param];
        readAnimFrameCount(obj);
        obj->subState = 0;
        obj->timer = obj->unkB4;
        obj->state++;
        break;
    case 1:
        switch (obj->subState) {
        case 0:
            if (--obj->timer == 0) {
                obj->timer = obj->unkB6;
                obj->subState++;
            }
            break;
        case 1:
            if (--obj->timer == 0) {
                obj->state++;
            }
            obj->visible = 1;
            pushDrawListCapped(obj);
            break;
        }
        break;
    case 2:
        obj->state++;
        break;
    case 3:
        freeObjectLayer3(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80031C90);
static inline void setupPoolType31(GameObject *obj)
{
    obj->state = 1;
    obj->type = 0x31;
    obj->animFrame = 1;
    obj->active = 1;
    obj->drawType = DRAW_SPRITE;
    obj->otMode = OT_MODE_DEPTH;
    obj->priority = 0;
    obj->tpage = 0x14;
    obj->drawFlags = 1;
    obj->clut = ((obj->param + 0x1FC) << 6) | 0x17;
    obj->spriteBank = D_1F8002D8[0];
    obj->anim = *(void **)D_80012364;
    readAnimFrameCount(obj);
}

void func_80031C90(GameObject *o)
{
    GameObject *p;
    u16 r;
    s32 s;

    switch (o->state) {
    case 0:
        switch (o->id) {
        case 0:
            if ((((scratchpad *)((void *)0x1F800000))->unk1F8 + D_1F800198) & 1) {
                if (--o->timer == -1) {
                    o->state = 3;
                    break;
                }
                p = allocObjectLayer3();
                if (p != NULL) {
                    r = nextRandom();
                    s = ((r & 1) << 11) + 0x800;
                    p->h->raw = o->h->raw;
                    p->y.raw = o->y.raw;
                    p->d->raw = o->d->raw;
                    p->h->raw += (COS_TABLE[r & 0xF0] * s) >> 4;
                    p->y.raw += (NEG_SIN_TABLE[r & 0xF0] * s) >> 4;
                    setupPoolType31(p);
                }
            }
            break;
        case 1:
            setupPoolType31(o);
            break;
        }
        break;
    case 1:
        cullAndQueueDraw(o);
        if (tickAnimation(o) != 0) {
            o->state = 3;
        }
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80031F00);

void func_80031F00(s32 a, s32 b, s32 c)
{
    GameObject *obj = allocObjectLayer3();
    if (obj != 0) {
        obj->active = 1;
        obj->type = 0x31;
        obj->id = 0;
        obj->param = 0;
        obj->h->raw = a << 16;
        obj->y.raw = b << 16;
        obj->d->raw = c << 16;
        obj->timer = 0x20;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80031F88);

void func_80031F88(GameObject *o)
{
    GameObject *n;
    s16 r;
    s16 s;
    s16 b;
    s16 i;

    switch (o->state) {
    case 0:
        switch (o->id) {
        case 0:
            if ((SPAD->unk1F8 + SPAD->unk198) & 1) {
                if (--o->timer == -1) {
                    o->state = 3;
                    break;
                }
                n = allocObjectLayer3();
                if (n == 0) break;
                r = ((s32 (*)(void))nextRandom)();
                b = r & 1;
                s = b;
                switch (o->param) {
                case 0:
                    s = (b << 11) + 0x800;
                    n->unkAC = 0;
                    n->drawType = DRAW_SPRITE;
                    break;
                case 1:
                    s = (b * 3 << 10) + 0xc00;
                    n->unkAC = ((s32 (*)(void))nextRandom)() & 1;
                    if (n->unkAC) goto one;
                    n->drawType = DRAW_SPRITE;
                    break;
                case 2:
                    s = (b << 12) + 0x1000;
                    n->unkAC = 1;
                one:
                    n->drawType = DRAW_SPRITE_SCALED;
                    n->buffSize = 0x1800;
                    break;
                }
                n->h->raw = o->h->raw;
                n->y.raw = o->y.raw;
                n->d->raw = o->d->raw;
                i = r & 0xf0;
                n->h->raw += (COS_TABLE[i] * s) >> 4;
                n->y.raw += (NEG_SIN_TABLE[i] * s) >> 4;
                n->state = 1;
                func_80032230(n);
            }
            break;
        case 1:
            o->state = 1;
            func_80032230(o);
            break;
        }
        break;
    case 1:
        cullAndQueueDraw(o);
        if (o->unkAC == 1) o->buffSize += 0x200;
        if (tickAnimation(o)) o->state = 3;
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80032230);
void func_80032230(u8* self)
{
    self[0] = 1;
    self[2] = 0x32;
    *(s16*)(self + 0x2E) = 1;
    *(s8*)(self + 0xF) = -0x1E;
    *(s16*)(self + 0x1E) = 0x14;
    self[0xD] = 0x80;
    self[0xB] = 0;
    *(void**)(self + 0x3C) = (void *)D_1F8002D8[0];
    *(s32*)(self + 0x24) = D_80012368[*(s16*)(self + 0xAC)];
    readAnimFrameCount(self);
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_800322A4);
typedef struct O_322A4 {
    char act;
    char pad0;
    char type;
    char sub;
    char pad1[0xc - 4];
    u8 b0c;
    char pad2[0x14 - 0xd];
    s32 y;
    char pad3[0x20 - 0x18];
    s16 w20;
    char pad4[0x40 - 0x22];
    s32 *h;
    s32 *d;
} O_322A4;

void func_800322A4(char a, s32 x, s32 y, s32 z)
{
    O_322A4 *p = allocObjectLayer3();
    s16 s;
    if (p == 0) return;
    p->act = 1;
    p->type = 0x32;
    p->sub = 0;
    p->b0c = a;
    *p->h = x << 16;
    p->y = y << 16;
    *p->d = z << 16;
    switch (p->b0c) {
    case 0: s = 0x10; break;
    case 1: s = 0x18; break;
    case 2: s = 0x20; break;
    default: return;
    }
    p->w20 = s;
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80032374);

void func_80032374(u8 *o)
{
    if (o[3] != 9) {
        *(u16 *)(o + 0x1e) = D_8007D2E8[o[3]].tpage;
        *(s32 *)(o + 0x3c) = SPR_DATA[D_8007D2E8[o[3]].sprite];
        *(s32 *)(o + 0x24) = D_8007D2E8[o[3]].anims[o[0xc]];
    } else {
        *(u16 *)(o + 0x1e) = D_8007D2E8[0].tpage;
        *(s32 *)(o + 0x3c) = SPR_DATA[D_8007D2E8[0].sprite];
        *(s32 *)(o + 0x24) = *D_8007D2E8[0].anims;
    }
    readAnimFrameCount(o);
    o[0xa] = 0xd;
    o[0xd] = 0x80;
    *(s8 *)(o + 0xf) = -7;
    *(s32 *)(o + 0x8c) = 0;
    o[0x6b] = 0;
    o[0x1c] |= 0x80;
    o[4]++;
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_800324B4);
typedef struct { void **a; s32 p[2]; } A12_324B4;
extern A12_324B4 D_8007D2F0[];

void func_800324B4(GameObject *obj)
{
    switch (obj->step) {
    case 0:
        obj->anim = D_8007D2F0[obj->id].a[obj->param];
        readAnimFrameCount(obj);
        obj->visible = D_800A5399;
        obj->priority = D_800A53A7_U8 - 1;
        obj->objectIndex = 0x7f;
        if (D_8009BCF8 == 3) {
            obj->objectIndex = 0x40;
        }
        obj->step++;
        break;
    case 1:
        if (tickAnimation(obj)) {
            setObjState(obj, 2, 0, 0);
        }
        if (obj->visible == 0) {
            setObjState(obj, 2, 0, 0);
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_800325C0);

void func_800325C0(GameObject *obj)
{
    u8 b;
    s32 s;
    Fix16 *f;
    s16 t;
    u8 v;
    switch (obj->step) {
    case 0:
        obj->anim = *(void **)(((char **)&D_8007D2F0)[obj->id * 3] + obj->param * 4);
        readAnimFrameCount(obj);
        obj->timer = 0xb4;
        obj->step = obj->step + 1;
    case 1:
        break;
    default:
        return;
    }
    if (obj->param == 0 && (D_1F8001F8 & 3) == 0)
        func_80028A74(0, 0, 0xff, 2);
    tickAnimation(obj);
    obj->timer = obj->timer - 1;
    obj->visible = D_800A5399;
    if (obj->timer >= 0x3d) {
        if (obj->objectIndex < 0x7f)
            b = obj->objectIndex + 8;
        else
            b = obj->objectIndex;
    } else {
        if (obj->timer < 0) {
            if (D_800A5478 > 0)
                PLAYER.obj.active = 3;
            else
                PLAYER.obj.active = 1;
            D_800A5464_Char = 3;
            obj->objectIndex = 0;
            obj->state = 2;
            goto L;
        }
        if (obj->objectIndex != 0)
            b = obj->objectIndex - 2;
        else
            b = 0;
    }
    obj->objectIndex = b;
L:
    s = PLAYER.obj.h->p.whole;
    f = obj->h;
    if (PLAYER.obj.animFrame & 1)
        f->p.whole = s + 4;
    else
        f->p.whole = s - 4;
    obj->y.p.whole = PLAYER.obj.y.p.whole - 8;
    obj->d->p.whole = PLAYER.obj.d->p.whole;
    switch (obj->param) {
    case 0:
        b = D_800A53A7_U8 + 1;
        break;
    case 1:
        b = D_800A53A7_U8 - 1;
        break;
    default:
        return;
    }
    obj->priority = b;
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_800327D8);

void func_800327D8(GameObject *obj)
{
    u8 t;
    switch (obj->step) {
    case 0:
        obj->anim = *(*(void ***)&D_8007D2F0);
        readAnimFrameCount(obj);
        obj->timer = 0x3c;
        obj->step++;
    case 1:
        break;
    default:
        return;
    }
    tickAnimation(obj);
    obj->timer = obj->timer - 1;
    obj->visible = D_800A5399;
    if (obj->timer > 0x20) {
        if (obj->objectIndex > 0x7e) t = obj->objectIndex;
        else t = obj->objectIndex + 8;
        obj->objectIndex = t;
    } else if (obj->timer < 0) {
        obj->objectIndex = 0;
        obj->state = 2;
    } else {
        if (obj->objectIndex == 0) t = 0;
        else t = obj->objectIndex - 8;
        obj->objectIndex = t;
    }
    {
        s32 x = PLAYER.obj.h->p.whole;
        obj->h->p.whole = (PLAYER.obj.animFrame & 1) ? x + 4 : x - 4;
    }
    obj->y.p.whole = (u16)PLAYER.obj.y.p.whole - 8;
    obj->d->p.whole = ((s16 **)&D_800A53DC)[0][1];
    obj->priority = PLAYER.obj.priority - 1;
}

// INCLUDE_ASM("nonmatchings/main/game/objsetup", func_80032934);
typedef struct { void **tab; s32 a; s32 b; } AT_32934;
extern s16 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);

void func_80032934(GameObject *obj)
{
    u8 v;
    s32 t;
    switch (obj->step) {
    case 0:
        switch (obj->param) {
        case 5:
            obj->unk84 = 0;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[5];
            break;
        case 6:
            obj->unk84 = 0x56;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[6];
            break;
        case 7:
            obj->unk84 = 0xab;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[7];
            break;
        case 8:
            obj->unk84 = 0x2c;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[5];
            break;
        case 9:
            obj->unk84 = 0x7f;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[6];
            break;
        case 10:
            obj->unk84 = 0xd4;
            obj->anim = ((AT_32934 *)&D_8007D2F0)[obj->id].tab[7];
            break;
        }
        readAnimFrameCount(obj);
        obj->unk88 = 0;
        obj->timer = 0xb4;
        obj->step++;
    case 1:
        if (obj->param == 0 && (D_1F8001F8 & 3) == 0)
            func_80028A74(0, 0, 0xff, 2);
        obj->timer--;
        obj->visible = PLAYER.obj.visible;
        if (obj->timer >= 0x3d) {
            if (obj->objectIndex < 0x7f)
                v = obj->objectIndex + 8;
            else
                v = obj->objectIndex;
        } else if (obj->timer < 0) {
            if (D_800A5478 > 0) PLAYER.obj.active = 3; else PLAYER.obj.active = 1;
            D_800A5464_Char = 3;
            obj->objectIndex = 0;
            obj->state = 2;
            goto anim;
        } else {
            if (obj->objectIndex)
                v = obj->objectIndex - 2;
            else
                v = 0;
        }
        obj->objectIndex = v;
    anim:
        tickAnimation(obj);
        switch (obj->param) {
        case 0:
            obj->h->p.whole = PLAYER.obj.h->p.whole;
            obj->y.p.whole = PLAYER.obj.y.p.whole - 8;
            obj->d->p.whole = PLAYER.obj.d->p.whole;
            break;
        case 5:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 8);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 28) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        case 6:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 16);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 16) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        case 7:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 24);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 8) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        case 8:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 4);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 24) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        case 9:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 20);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 20) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        case 10:
            obj->h->p.whole = PLAYER.obj.h->p.whole + fixedMulCos(*(s16 *)&obj->unk84, 28);
            obj->y.p.whole = PLAYER.obj.y.p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 12) - 8);
            obj->d->p.whole = PLAYER.obj.d->p.whole + (s16)(fixedMulSin(*(s16 *)&obj->unk84, 4) - 4);
            break;
        }
        obj->unk84 = (obj->unk84 + 0x10) & 0xff;
        break;
    }
}
