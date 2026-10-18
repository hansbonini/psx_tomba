#include "common.h"
#include "game.h"

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_801381B4);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_801384AC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_801387A4);



extern void *D_8013EE08[];
extern void *D_8013EE30[];
extern void *D_8013EE34[];
extern void readAnimFrameCount(GameObject *);
extern s32 tickAnimation(GameObject *);
extern void setEventComplete(s32, s32);

void func_801387A4(GameObject *o)
{
    switch (o->subState) {
    case 0:
        if (D_8009C068.unk721 == 1) {
            o->timer = 0;
            o->subState++;
        }
        break;
    case 1:
        if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 3) == 0) {
            s16 w = o->unkAC + 4;
            o->unkAC = w;
            o->anim = D_8013EE08[w];
            o->subState++;
        }
        break;
    case 2:
        if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 3) == 0) {
            if (++o->timer >= 0x10) {
                o->subState++;
                switch (o->unkAC) {
                case 4:
                    o->unkAC = 10;
                    o->anim = D_8013EE30[0];
                    readAnimFrameCount(o);
                    break;
                case 5:
                    o->unkAC = 11;
                    o->anim = D_8013EE34[0];
                    readAnimFrameCount(o);
                    break;
                case 6:
                    break;
                }
            } else {
                s16 w = o->unkAC - 4;
                o->unkAC = w;
                o->anim = D_8013EE08[w];
                o->subState--;
            }
        }
        break;
    case 3:
        setEventComplete(0x1b, 0);
        o->timer = 0xb4;
        o->subState++;
        break;
    case 4:
        tickAnimation(o);
        if (--o->timer == -1) {
            o->subState++;
            D_8009C068.unk721 = 2;
        }
        break;
    case 5:
        tickAnimation(o);
        if (D_8009C068.unk721 >= 5) o->subState++;
        break;
    case 6:
        switch (o->unkC) {
        case 0:
            o->step = 0;
            o->subState++;
            break;
        case 1:
            func_801381B4(o);
            break;
        case 2:
            func_801384AC(o);
            break;
        }
        break;
    case 7:
        if (o->unkC == 2) {
            D_8009C068.unk721 = 6;
            D_8009BC98.unk10 = 0;
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk12 = 0;
            D_8009BC98.unk0E = 0;
        }
        o->subState++;
        break;
    case 8:
        if (o->unkC) o->state = 3;
        else o->objectIndex = 1;
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80138AA8);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80138C4C);


static __inline__ void setbox_38C4C(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a;
    o->hitWidth = b;
    o->hitOffsetY = c;
    o->hitHeight = d;
}

void func_80138C4C(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->state++;
        o->active = 2;
        *(s8 *)&o->unkF = -6;
        setbox_38C4C(o, 8, 0x10, 8, 0x10);
        o->tpage = 5;
        o->unk98 = o->animFrame;
        o->unkD = 0;
        o->spriteBank = SCRATCHPAD.sprData[10];
        o->anim = D_8013EE08[o->unkAC = o->unkC];
        o->objectIndex = 0;
        if (D_8009C068.event_1B != 0xff) break;
        if (o->unkC) {
            o->state = 3;
            break;
        }
        o->unkAC = 10;
        o->anim = D_8013EE08[10];
        readAnimFrameCount(o);
        o->objectIndex = 1;
        break;
    case 1:
        func_80022E44(o);
        if (o->objectIndex == 0)
            func_801387A4(o);
        else
            func_80138AA8(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80138DB8);
extern GameObject *allocObjectLayer2(void);

void func_80138DB8(GameObject *o)
{
    GameObject *n;

    if (D_8009C068.event_0E < 2) {
        if (GAME.area00_eventControl & 0x100) {
            o->state = 3;
        } else {
            n = allocObjectLayer2();
            if (n) {
                n->active = 1;
                n->type = 0x16;
                n->unkA = 2;
                n->x.p.whole = 0x105b;
                n->y.p.whole = -0x506;
                n->animFrame = 0;
                n->subtype = 0;
                n->unkC = 0;
                n->z.p.whole = 0x47a;
                *(GameObject **)&o->category = n;
            }
            o->state = 1;
        }
    } else {
        o->state = 3;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80138E64);

extern u8 D_800A5458;

s32 func_80138E64(GameObject *o)
{
    GameObject *p = *(GameObject **)&o->category;
    s32 r = 0;

    if (D_8009C068.event_0E >= 2) return 0;
    if (!(GAME.area00_eventControl & 0x100) && PLAYER.obj.state == PLAYER_ACTIVE && PLAYER.obj.touchFlag &&
        (u16)((*(u16*)&PLAYER.obj.y.p.whole) + 0x50a) < 0x10 &&
        (u16)((*(Fix16 **)&PLAYER.obj.h)->p.whole - p->h->p.whole + 0x30) < 0x60) {
        if (*(u16 *)&o->anim) {
            r = 1;
        } else if ((*(s8 *)&D_8009C618) == PLAYER.obj.state && (D_1F8001FC & (*(u16 *)&D_1F8003C4))) {
            r = 1;
            *(u16 *)&o->anim = 1;
            D_8009BC98.unk12 = 1;
            D_800A5458 = 1;
        }
    }
    return r;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80138F88);

extern GameObject PLAYER_GameObject asm("PLAYER");
#define P PLAYER_GameObject
extern GameObject *D_800A5428;
extern GameObject *D_8009B698;

typedef struct { char pad[0x24]; u16 a; } AnimH_38F88;
extern char D_800108A8[];
extern GameObject *showMessageBox(s32, s32, s32, s32);
extern void printInfoMessage(s32, s32);

void func_80138F88(GameObject *o)
{
    GameObject *e = *(GameObject **)&o->category;
    GameObject *p;
    u8 *f;
    s32 n;

    switch (o->subState) {
    case 0:
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk0E = 1;
        D_8009BC98.unk12 = 1;
        P.anim = D_800108A8;
        readAnimFrameCount(&P);
        e->subState = 1;
        e->step = 0;
        switch (D_8009C068.unk55c) {
        case 0:
            D_800A5428 = showMessageBox(2, 10, 0x80, 0x6c);
            o->subState++;
            break;
        case 1:
            D_800A5428 = showMessageBox(2, 11, 0x80, 0x6c);
            o->subState++;
            break;
        }
        break;
    case 1:
        p = D_800A5428;
        if (p->state != 2) break;
        f = &D_8009C068.unk55c;
        switch (*f) {
        case 0:
            p->state = 3;
            *f = 1;
            o->subState = 0;
            o->step = 0;
            D_800A539C = 1;
            D_800A539D = 0;
            D_800A539E = 0;
            e->subState = 0;
            e->step = 1;
            e->animFrame = e->objectIndex;
            ((AnimH_38F88 *)o)->a = 0;
            *(u16 *)((char *)D_8009B698 + 0x2e) = 0xffff;
            D_8009BC98.unk0E = 0;
            D_8009BC98.unk12 = 0;
            D_800A5458 = 0;
            D_8009BC98.unk0F = 0;
            break;
        case 1:
            p->state = 3;
            D_800A53C6 = 0;
            D_800A539C = 1;
            D_800A539D = 0;
            D_800A539E = 0;
            o->subState = 2;
            o->step = 0;
            D_8009B698->animFrame = 0xffff;
            *f = 2;
            *(u16 *)&o->anim = 1;
            D_800A5458 = 0;
            break;
        }
        break;
    case 2:
        switch (o->step) {
        case 0:
            o->clut = 0x20;
            e->unk8C = 0;
            e->touchFlag = 0;
            e->velY = -0x300;
            e->velV = 0;
            e->velH = (P.h->p.whole - e->h->p.whole) * 8;
            e->velV = (P.y.p.whole - e->y.p.whole) * 8;
            o->step = 1;
            break;
        case 1:
            applyObjectSpeedXY(e);
            e->y.raw += e->velY << 8;
            e->velY += 0x30;
            if (e->velY > 0) o->step = 2;
            if (--o->clut == 0) {
                D_800A539C = 1;
                D_8009B698->animFrame = 0xffff;
                D_800A539D = 0;
                D_800A539E = 0;
                e->touchFlag = 0;
                e->velH = 0;
                e->velV = 0;
                e->velX = 0;
                e->velY = 0;
                e->state = 2;
                e->subState = 3;
                e->step = 0;
                o->state = 3;
                o->subState = 0;
                o->step = 0;
                D_8009C068.event_0E = 2;
                { s32 *q = &GAME.area00_eventControl; *q |= 0x100; }
                printInfoMessage(0x13, MSG_TYPE_INFO);
                D_8009BC98.unk0E = 0;
                D_8009BC98.unk12 = 0;
                D_800A5458 = 0;
                D_8009BC98.unk0F = 0;
            }
            break;
        case 2:
            applyObjectSpeedXY(e);
            e->y.raw += e->velY << 8;
            e->velY += 0x30;
            if (--o->clut == 0) {
                D_800A539C = 1;
                D_8009B698->animFrame = 0xffff;
                D_800A539D = 0;
                D_800A539E = 0;
                e->touchFlag = 0;
                e->velH = 0;
                e->velV = 0;
                e->velX = 0;
                e->velY = 0;
                e->state = 2;
                e->subState = 3;
                e->step = 0;
                o->state = 3;
                o->subState = 0;
                o->step = 0;
                D_8009C068.event_0E = 2;
                D_8009BC98.unk12 = 0;
                D_800A5458 = 0;
                D_8009BC98.unk0F = 0;
                D_8009BC98.unk0E = 0;
                { s32 *q = &GAME.area00_eventControl; *q |= 0x100; }
            }
            break;
        }
        break;
    }
}
#undef P

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80139404);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80139410);
void func_80139410(GameObject *o)
{
    GameObject *n, *m;
    u8 k;

    if (D_8009C068.unk69a == 0 && D_8009C068.item_0E == 0 && (k = D_8009C068.baronState) != 0 && k != 0xff) {
        if (k < 3) {
            n = allocObjectLayer2();
            if (n) {
                n->active = 1;
                n->type = 0x16;
                n->unkA = 2;
                n->x.p.whole = 0xacd;
                n->animFrame = 0;
                n->subtype = 0;
                n->unkC = 0;
                n->y.p.whole = -0x10a;
                n->z.p.whole = 0;
                *(GameObject **)&o->category = n;
            }
            m = allocObjectLayer2();
            if (m) {
                m->active = 1;
                m->type = 0x17;
                m->unkA = 2;
                m->x.p.whole = 0x9a8;
                m->animFrame = 0;
                m->subtype = 0;
                m->unkC = 0;
                m->y.p.whole = -0x200;
                m->z.p.whole = 0;
                *(GameObject **)&o->timer = m;
                m->unk90 = (s32)n;
            }
            o->state = 1;
        } else {
            o->state = 3;
        }
    } else {
        o->state = 3;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_8013952C);

s32 func_8013952C(GameObject *o)
{
    s32 r = 0;

    if (D_8009C068.baronState != 0 && D_8009C068.baronState < 4 && PLAYER.obj.touchFlag != 0
        && (u16)((*(Fix16 **)&PLAYER.obj.h)->p.whole - 0xaad) < 0x40 && PLAYER.obj.y.p.whole >= -0x10f) {
        if (o->animTimer != 0) {
            r = 1;
        } else if ((*(s8 *)&D_8009C618) == 1 && (D_1F8001FC & (*(u16 *)&D_1F8003C4))) {
            r = 1;
            D_8009BC98.unk12 = 1;
            D_800A5458 = 1;
            o->animTimer = 1;
        }
    }
    return r;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80139610);

void func_80139610(GameObject *o)
{
    GameObject *p = *(GameObject **)&o->category;
    s32 v;
    s32 t;

    switch (o->subState) {
    case 0:
        PLAYER_GameObject.anim = D_800108A8;
        readAnimFrameCount(&PLAYER_GameObject);
        switch (D_8009C068.baronState) {
        case 1:
            D_800A5428 = showMessageBox(2, 0x1f, 0x80, 0x6c);
            break;
        case 2:
            D_800A5428 = showMessageBox(2, 0x20, 0x80, 0x6c);
            break;
        case 3:
            D_800A5428 = showMessageBox(2, 0x21, 0x80, 0x6c);
            break;
        default:
            return;
        }
        t = *(s16 *)((char *)D_800A53D8 + 2) > *(s16 *)((char *)p->h + 2);
        D_800A539C = 1;
        D_800A539D = 0;
        D_800A539E = 0;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        D_8009BC98.unk0E = 1;
        D_800A53C6 = t;
        o->subState++;
        break;
    case 1:
        if (D_800A5428->state == 2) {
            v = D_8009C068.baronState;
            if (v == 1 || (v != 0 && v < 4)) {
                D_800A5428->state = 3;
                o->subState = 0;
                o->step = 0;
                t = *(s16 *)((char *)D_800A53D8 + 2) > *(s16 *)((char *)p->h + 2);
        D_800A539C = 1;
                D_800A539D = 0;
                D_800A539E = 0;
                o->animTimer = 0;
                D_8009BC98.unk0F = 0;
                D_8009BC98.unk0E = 0;
                D_8009BC98.unk12 = 0;
                D_800A5458 = 0;
            }
        }
        break;
    }
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_801397DC);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_801397E8);
void func_801397E8(GameObject *o)
{
    GameObject *e;
    GameObject **p;
    u8 *q;

    o->state = 3;
    p = (GameObject **)&o->category;
    switch (D_8009C068.event_B5) {
    case 1:
    case 3:
        q = &D_8009C068.unk57e;
        if (*q == 1) {
            e = allocObjectLayer2();
            if (e) {
                e->active = 1;
                e->active = 1;
            e->type = 0xd;
                e->animFrame = 1;
                e->unkA = 2;
                e->x.p.whole = 0x105b;
                e->y.p.whole = -0x178;
                e->z.p.whole = 0x26a;
                e->subtype = 0;
                e->unkC = 0;
                *p = e;
                D_8009C068.event_B5 = 3;
                *q = 0;
                D_8009C068.unk57f = 0;
                o->state = 1;
            }
        } else {
            e = allocObjectLayer2();
            if (e) {
                e->active = 1;
                e->active = 1;
            e->type = 0xd;
                e->animFrame = 1;
                e->unkA = 2;
                e->x.p.whole = 0x105b;
                e->y.p.whole = -0x178;
                e->subtype = 0;
                e->unkC = 0;
                e->z.p.whole = 0x26a;
                *p = e;
                o->state = 1;
            }
        }
        break;
    case 2:
        e = allocObjectLayer2();
        if (e) {
            e->active = 1;
            e->type = 0xd;
            e->animFrame = 1;
            e->unkA = 2;
            e->x.p.whole = 0x105b;
            e->y.p.whole = -0x6d4;
            e->subtype = 0;
            e->unkC = 0;
            e->z.p.whole = 0x53c;
            *(GameObject **)&o->category = e;
            o->state = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_8013999C);

#define W24(o) (((u16 *)(o))[0x12])

s32 func_8013999C(GameObject *o)
{
    GameObject *q = *(GameObject **)&o->category;
    s32 r = 0;

    switch (D_8009C068.event_B5) {
    case 1:
        switch (D_8009C068.unk57e) {
        case 0:
            if ((*(GameObject *)&PLAYER).h->p.whole >= 0x19b)
                r = 1;
            break;
        case 1:
            r = 1;
            break;
        case 2:
            r = 1;
            break;
        }
        break;
    case 2:
        if ((*(GameObject *)&PLAYER).touchFlag == 0)
            break;
        if ((u16)((*(GameObject *)&PLAYER).h->p.whole - q->h->p.whole + 0x20) >= 0x40)
            break;
        if ((u16)((*(GameObject *)&PLAYER).y.p.whole + 0x6d4) >= 4)
            break;
        if (W24(o) != 0) {
            r = 1;
            break;
        }
        if ((*(s8 *)&D_8009C618) == 1 && (D_1F8001FC & (*(u16 *)&D_1F8003C4))) {
            D_8009BC98.unk12 = 1;
            D_800A5458 = 1;
            r = 1;
            W24(o) = 1;
        }
        break;
    case 3:
        if ((*(GameObject *)&PLAYER).state != 1)
            break;
        if ((*(GameObject *)&PLAYER).touchFlag == 0)
            break;
        if ((u16)((*(GameObject *)&PLAYER).h->p.whole - q->h->p.whole + 0x20) >= 0x40)
            break;
        if ((*(GameObject *)&PLAYER).y.p.whole < -0x17c)
            break;
        if (W24(o) != 0) {
            r = 1;
            break;
        }
        if ((*(s8 *)&D_8009C618) == 1 && (D_1F8001FC & (*(u16 *)&D_1F8003C4))) {
            r = 1;
            D_8009BC98.unk12 = 1;
            D_800A5458 = 1;
            D_8009BC98.unk0F = 1;
            W24(o) = 1;
        }
        break;
    case 0xff:
        r = 1;
        break;
    }
    return r;
}
#undef W24

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_9", func_80139C04);
extern void func_800EDE44(GameObject *, s32, s32);
extern void probeSidesAndApplyTileResponse(GameObject *, s32, s32);

void func_80139C04(GameObject *o)
{
    GameObject *e = *(GameObject **)&o->category;
    GameObject *p;

    switch (o->subState) {
    case 0:
        D_8009BC98.unk12 = 1;
        D_8009BC98.unk0F = 1;
        PLAYER_GameObject.animFrame = 0;
        PLAYER_GameObject.state = 5;
        PLAYER_GameObject.subState = 100;
        PLAYER_GameObject.step = 0;
        func_800EDE44(&PLAYER_GameObject, 2, 0);
        o->subState++;
    case 1:
        PLAYER_GameObject.h->raw += 0x10000;
        PLAYER_GameObject.y.raw += 0x50000;
        probeSidesAndApplyTileResponse(&PLAYER_GameObject, 0, 0);
        if (PLAYER_GameObject.h->p.whole >= 0x279) {
            e->animFrame = 0;
            D_800A5428 = showMessageBox(2, 0x19, 0x80, 0x6c);
            func_800EDE44(&PLAYER_GameObject, 0, 0);
            o->subState++;
        }
        break;
    case 2:
        p = D_800A5428;
        if (p->state == 2) {
            p->state = 3;
            D_8009BC98.unk0A = 1;
            D_8009BC98.unk0F = 0;
            D_8009BC98.unk0E = 0;
            D_8009BC98.unk12 = 0;
            D_8009C068.unk57e = 1;
            D_800A5458 = 0;
            D_800A539C = 1;
            D_800A539D = 0;
            D_800A539E = 0;
            e->subtype = 1;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}
