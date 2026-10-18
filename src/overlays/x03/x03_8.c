#include "common.h"
#include "game.h"
#include "x03.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012B35C);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012B9DC);


extern ObjSetupHitbox D_80135138[];
extern void advanceAnimFrame(GameObject *, s32);

void func_8012B9DC(GameObject *o)
{
    o->hitOffsetX = D_80135138[o->subtype].b0;
    o->hitWidth = D_80135138[o->subtype].b1;
    o->hitOffsetY = D_80135138[o->subtype].b2;
    o->hitHeight = D_80135138[o->subtype].b3;
    o->tpage = D_80135138[o->subtype].w4;
    o->spriteBank = SPR_DATA[D_80135138[o->subtype].w6];
    if (D_8009C068.event_21 != 0xff) {
        o->anim = D_80135138[o->subtype].anim[5];
        advanceAnimFrame(o, 0);
    } else {
        o->anim = D_80135138[o->subtype].anim[4];
        advanceAnimFrame(o, 0);
        o->h->p.whole = 0xc4d;
    }
    o->animFrame = 1;
    o->unkA = 2;
    o->unk8C = 0;
    o->unkD = 0;
    o->unk68 = 0;
    o->category |= 0x80;
    o->unkF = PLAYER.obj.unkF + 1;
    o->state++;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012BBA8);

void func_8012BBA8(GameObject *o)
{
    switch (o->state) {
    case 0:
        func_8012B9DC(o);
        break;
    case 1:
        func_80022E44(o);
        if (o->unkC == 0x29) {
            switch (o->subState) {
            case 0:
                if (o->unk68) {
                    o->subState++;
                }
                break;
            case 1:
                func_8012B35C(o);
                break;
            }
        }
        if (o->anim && o->active) {
            tickAnimation(o);
        }
        break;
    case 2:
        o->state++;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012BCCC);

extern s16 probeCollisionAtDepthA(GameObject *o, s16 x, s16 y);

static __inline__ s32 hit_2BCCC(GameObject *o)
{
    if (probeCollisionAtDepthA(o, o->h->p.whole + 8, o->y.p.whole + 0x10)) return 1;
    return probeCollisionAtDepthA(o, o->h->p.whole - 8, o->y.p.whole + 0x10) != 0;
}

void func_8012BCCC(GameObject *o)
{
    s32 k;
    switch (o->step) {
    case 0:
        if (D_8009C608.purifiedAreas & 2) {
            o->subState = 4;
            o->x.p.whole = 0x842;
            o->y.p.whole = -0x38e;
            break;
        }
        o->unk6A = 0;
        o->active = 1;
        o->step++;
    case 1:
        tickAnimation(o);
        if (o->unk6A) {
            D_8009C068.unk5a3 = k = 1;
            o->timer = 1;
            o->touchFlag = 0;
            o->velV = 0;
            o->unkAC = 0xc;
            o->step++;
            o->anim = D_80138D8C[0];
            readAnimFrameCount(o);
            D_800A539C = 5;
            D_800A539D = 0;
            D_800A539E = 0;
            D_8009BC98.unk0F = k;
            D_8009BC98.unk12 = k;
        }
        break;
    case 2:
        tickAnimation(o);
        o->x.raw += 0x14000;
        PLAYER_GameObject.x.raw += 0x14000;
        o->velV += 0x20;
        if (o->velV > 0x500) o->velV = 0x500;
        o->y.raw += o->velV << 8;
        if (hit_2BCCC(o)) {
            o->timer = 10;
            o->touchFlag = 0;
            o->unkAC = 0xb;
            o->step++;
            o->anim = D_80138D88[0];
            readAnimFrameCount(o);
        }
        break;
    case 3:
        tickAnimation(o);
        if (--o->timer == 0) {
            o->step = 0;
            o->subState++;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012BF60);

typedef struct { char c[12]; } B12_2BF60;

extern GameObject *showMessageBoxDirect(s32, s32, B12_2BF60 *);

void func_8012BF60(GameObject *o)
{
    B12_2BF60 v;
    GameObject *p;

    v = *(B12_2BF60 *)&o->x;
    switch (o->step) {
    case 0:
        o->animFrame = 1;
        o->unk68 = 0;
        o->unkAC = 9;
        o->step++;
        o->anim = D_80138D80[0];
        readAnimFrameCount(o);
        break;
    case 1:
        tickAnimation(o);
        if (o->unk68 == 0)
            break;
        ((u8*)&PLAYER.obj.state)[0] = 5;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        ((u8*)&PLAYER.obj.subState)[0] = 0;
        ((u8*)&PLAYER.obj.step)[0] = 0;
        o->unkAC = 5;
        o->step++;
        o->animFrame = o->unk68 & 1;
        o->anim = D_80138D70[0];
        readAnimFrameCount(o);
        D_8009C068.unk5a3 = 2;
        o->unk90 = (s32)showMessageBoxDirect(6, 5, &v);
        break;
    case 2:
        tickAnimation(o);
        p = (GameObject *)o->unk90;
        if (p->state != 2)
            break;
        p->state = 3;
        o->subState = 2;
        o->step = 1;
        o->unk68 = 1;
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_8", func_8012C110);

typedef struct { s16 v[6]; } V6_2C110;
extern void setEventStarted(s32, s32, s32);

static __inline__ void setAnim_2C110(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_8012C110(GameObject *o)
{
    V6_2C110 v;
    GameObject *p;

    v = *(V6_2C110 *)&o->x;
    switch (o->step) {
    case 0:
        o->unk68 = 0;
        o->unkAC = 9;
        o->step++;
        setAnim_2C110(o, D_80138D80[0]);
        break;
    case 1:
        tickAnimation(o);
        if (D_8009C068.unk5a3 == 3) {
            o->subState++;
            o->step = 0;
            PLAYER.obj.state = PLAYER_SCRIPTED;
            PLAYER.obj.subState = PLAYER_IDLE;
            PLAYER.obj.step = 0;
            D_8009BC98.unk0F = 1;
            D_8009BC98.unk12 = 1;
            break;
        }
        if (o->unk68 == 0) break;
        PLAYER.obj.state = PLAYER_SCRIPTED;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 1;
        D_8009BC98.unk12 = 1;
        o->unk90 = showMessageBoxDirect(6, 6, &v);
        o->unkAC = 5;
        o->step++;
        o->animFrame = o->unk68 & 1;
        setAnim_2C110(o, D_80138D70[0]);
        break;
    case 2:
        tickAnimation(o);
        p = (GameObject *)o->unk90;
        if (p->state != 2) break;
        p->state = 3;
        o->unk68 = 0;
        o->step = 0;
        PLAYER.obj.state = PLAYER_ACTIVE;
        PLAYER.obj.subState = PLAYER_IDLE;
        PLAYER.obj.step = 0;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        setEventStarted(EVENT_CHARLESPANTS, 0, 1);
        break;
    }
}

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_8", func_80115C70);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_8", func_80115D0C);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_8", jtbl_80115FC8);
