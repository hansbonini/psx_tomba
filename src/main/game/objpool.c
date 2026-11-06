#include "common.h"
#include "game.h"
#include "game/area_module.h"

// INCLUDE_ASM("nonmatchings/main/game/objpool", setAnimation);
void setAnimation(u8* self, s16 arg1)
{
    *(s16*)(self + 0xAC) = arg1;
    *(s32*)(self + 0x24) =
        *(s32*)(*(u8**)(self + 0xA8) + arg1 * 4);
    readAnimFrameCount(self);
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80057C74);
typedef struct { char p[0x4c]; s16 w4c; s16 w4e; } G4_57C74;
extern void func_800EDDDC(GameObject *, s32, s32);

void func_80057C74(GameObject *obj)
{
    GameObject *player = &PLAYER.obj;
    switch (obj->step) {
    case 0:
        if ((*(s32 *)&player->state & 0xffffff) == 0x23001) {
            player->active = 5;
            player->visible = 1;
            setObjState(player, 5, 0x41, 0);
            obj->timer = 50;
            obj->step++;
        }
        break;
    case 1:
        tickAnimation(obj);
        if (obj->timer == 0) {
            obj->timer = 16;
            obj->step++;
            player->visible = 1;
            setObjState(player, 5, 0x41, 0);
            player->rotZ = 0;
            player->animFrame = 0;
            func_800EDDDC(player, 0, 0);
        } else {
            obj->timer--;
        }
        break;
    case 2:
        obj->h->p.whole++;
        if ((*(s16 *)&SCRATCHPAD.cameraPos.x.p.whole) + 0x134 < obj->h->p.whole)
            obj->h->p.whole = (*(s16 *)&SCRATCHPAD.cameraPos.x.p.whole) + 0x134;
        tickAnimation(obj);
        if (--obj->timer == -1) {
            obj->timer = 40;
            obj->step++;
            obj->unkAC = 0;
            obj->anim = (*(void ***)&obj->unkA8)[0];
            readAnimFrameCount(obj);
            obj->priority = player->priority - 2;
        }
        break;
    case 3:
        if (--obj->timer == -1)
            obj->step++;
        break;
    case 4:
        player->animFrame = 0;
        func_800EDDDC(player, 1, 0);
        obj->step++;
        break;
    case 5:
        tickAnimation(player);
        player->h->p.whole++;
        if (player->h->p.whole >= obj->h->p.whole) {
            player->h->p.whole = obj->h->p.whole;
            obj->timer = 30;
            obj->step++;
            func_800EDDDC(player, 0x2c, 0);
        }
        break;
    case 6:
        if (--obj->timer == -1)
            obj->step++;
        player->y.raw -= 0x8000;
        break;
    case 7:
        obj->unkAC = 1;
        obj->anim = (*(void ***)&obj->unkA8)[1];
        readAnimFrameCount(obj);
        obj->timer = 70;
        obj->velV = 0;
        obj->step++;
        break;
    case 8:
        if (--obj->timer == -1) {
            obj->step++;
            D_8009BCA4 = 0;
            D_8009BCDD = 3;
        }
        obj->velV += 0x20;
        if (obj->velV > 0x600)
            obj->velV = 0x600;
        obj->y.raw -= obj->velV << 8;
        player->y.raw -= obj->velV << 8;
        break;
    case 9:
        obj->velV += 0x20;
        if (obj->velV > 0x600)
            obj->velV = 0x600;
        obj->y.raw -= obj->velV << 8;
        player->y.raw -= obj->velV << 8;
        if (D_8009BCDD == 1) {
            D_8009C361 = 1;
            if ((*(s32 *)&GAME) == 0x7000E && D_8009C62B == 0xff) {
                obj->step++;
            } else {
                (*(G4_57C74 **)&SCRATCHPAD.currentTask)->w4c = 7;
                (*(G4_57C74 **)&SCRATCHPAD.currentTask)->w4e = 0;
            }
        }
        break;
    case 10:
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_800580BC);
extern void func_800EDDDC(GameObject *, s32, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

void func_800580BC(GameObject *obj)
{
    GameObject *player = &PLAYER.obj;

    switch (obj->step) {
    case 0:
        if ((*(s32 *)((u8 *)player + 4) & 0xffffff) != 0x30405)
            break;
        obj->h->p.whole = player->h->p.whole;
        player->h->p.whole = obj->h->p.whole;
        player->y.p.whole = obj->y.p.whole - 0x14;
        obj->priority = player->priority - 2;
        player->active = 5;
        player->visible = 1;
        setObjState(player, 5, 0x41, 0);
        func_800EDDDC(player, 0x2c, 0);
        obj->unkAC = 1;
        obj->anim = ((void **)*(s32 *)((u8 *)obj + 0xa8))[1];
        readAnimFrameCount(obj);
        obj->velV = 0x500;
        obj->step++;
        break;
    case 1:
        obj->velV -= 8;
        if (obj->velV < 0x100)
            obj->velV = 0x100;
        obj->y.raw += obj->velV << 8;
        player->y.raw += obj->velV << 8;
        if (obj->y.p.whole < *(s16 *)((u8 *)player + 0xf2) - 0x1e)
            break;
        if (probeCollisionAtDepthA(obj, obj->h->p.whole, obj->y.p.whole + 0x10)) {
            obj->timer = 0x1e;
            obj->unkAC = 0;
            obj->step++;
            obj->anim = ((void **)*(s32 *)((u8 *)obj + 0xa8))[0];
            readAnimFrameCount(obj);
        }
        break;
    case 2:
        if (--obj->timer == -1)
            obj->step++;
        break;
    case 3:
        player->y.raw += 0x8000;
        if (probeCollisionAtDepthA(player, player->h->p.whole, player->y.p.whole + 0x14)) {
            obj->unkAC = 0;
            obj->step++;
            obj->anim = ((void **)*(s32 *)((u8 *)obj + 0xa8))[0];
            readAnimFrameCount(obj);
        }
        break;
    case 4:
        obj->timer = 0x10;
        player->animFrame = 0;
        func_800EDDDC(player, 1, 0);
        obj->step++;
        break;
    case 5:
        tickAnimation(player);
        player->h->p.whole++;
        if (--obj->timer == -1) {
            obj->timer = 0x1e;
            obj->step++;
            player->animFrame = 0;
            func_800EDDDC(player, 0, 0);
        }
        break;
    case 6:
        if (--obj->timer == -1) {
            obj->step++;
            obj->priority = player->priority + 1;
            obj->unkAC = 3;
            obj->animFrame = 0;
            obj->anim = ((void **)*(s32 *)((u8 *)obj + 0xa8))[3];
            readAnimFrameCount(obj);
        }
        break;
    case 7:
        tickAnimation(obj);
        obj->h->p.whole++;
        if (obj->h->p.whole >= player->h->p.whole) {
            setObjState(player, 5, 4, 2);
            D_8009C361 = 0;
            obj->active = 2;
            obj->state = 3;
        }
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80058464);

#define SETANIM(o, a, b) \
    switch ((o)->unk6A - 1) { \
    case 0: func_800E7DF8(&PLAYER.obj, a, b); break; \
    case 1: func_800E8A30(&PLAYER.obj, a, b); break; \
    case 2: func_800E8758(&PLAYER.obj, a, b); break; \
    }

static __inline__ void SetAnim_58464(GameObject *obj, s16 n)
{
    obj->unkAC = n;
    obj->anim = (*(void ***)&obj->unkA8)[n];
    readAnimFrameCount(obj);
}

void func_80058464(GameObject *obj)
{
    GameObject *player = &PLAYER.obj;

    switch (obj->step) {
    case 0:
        if ((*(s32 *)&player->state & 0xffffff) == 0x23001) {
            player->active = 5;
            player->visible = 1;
            setObjState(player, 4, 0, 0);
            obj->timer = 0x32;
            obj->step++;
        }
        break;
    case 1:
        tickAnimation(obj);
        if (--obj->timer == -1) {
            obj->timer = 0x10;
            obj->step++;
            player->subState = 6;
            SETANIM(obj, 0, 6);
        }
        break;
    case 2:
        obj->h->p.whole++;
        if (obj->h->p.whole > (*(s16 *)&SCRATCHPAD.cameraPos.x.p.whole) + 0x136)
            obj->h->p.whole = (*(s16 *)&SCRATCHPAD.cameraPos.x.p.whole) + 0x136;
        tickAnimation(obj);
        if (--obj->timer == -1) {
            obj->timer = 0x28;
            obj->step++;
            SetAnim_58464(obj, 0);
            obj->priority = player->priority - 2;
        }
        break;
    case 3:
        if (--obj->timer == -1)
            goto next;
        break;
    case 4:
        player->animFrame = 0;
        SETANIM(obj, 1, 0);
    next:
        obj->step++;
        break;
    case 5:
        tickAnimation(player);
        player->h->p.whole++;
        if (player->h->p.whole >= obj->h->p.whole) {
            player->h->p.whole = obj->h->p.whole;
            obj->timer = 0x1e;
            obj->step++;
            SETANIM(obj, 0, 6);
        }
        break;
    case 6:
        if (--obj->timer == -1)
            obj->step++;
        player->y.raw -= 0x8000;
        break;
    case 7:
        SetAnim_58464(obj, 1);
        obj->timer = 0x46;
        obj->velV = 0;
        obj->step++;
        break;
    case 8:
        if (--obj->timer == -1) {
            obj->step++;
            D_8009BCA4 = 0;
            D_8009BCDD = 3;
        }
        if ((obj->velV += 0x20) > 0x600)
            obj->velV = 0x600;
        obj->y.raw -= obj->velV << 8;
        player->y.raw -= obj->velV << 8;
        break;
    case 9:
        if ((obj->velV += 0x20) > 0x600)
            obj->velV = 0x600;
        obj->y.raw -= obj->velV << 8;
        player->y.raw -= obj->velV << 8;
        if (D_8009BCDD == 1) {
            D_8009C361 = 1;
            (*(GameObject **)&SCRATCHPAD.currentTask)->unk4C = 7;
            (*(GameObject **)&SCRATCHPAD.currentTask)->unk4E = 0;
        }
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80058960);
typedef struct { GameObject o; char pad[0x32]; s16 wf2; } BigObj_58960;

#define SETANIM(o, a, b) \
    switch ((o)->unk6A - 1) { \
    case 0: func_800E7DF8(&PLAYER.obj, a, b); break; \
    case 1: func_800E8A30(&PLAYER.obj, a, b); break; \
    case 2: func_800E8758(&PLAYER.obj, a, b); break; \
    }

static __inline__ void SetAnim_58960(GameObject *obj, s16 n)
{
    obj->unkAC = n;
    obj->anim = (*(void ***)&obj->unkA8)[n];
    readAnimFrameCount(obj);
}

void func_80058960(GameObject *obj)
{
    GameObject *player = &(*(BigObj_58960 *)&PLAYER).o;
    s32 d;

    switch (obj->step) {
    case 0:
        if ((*(s32 *)&player->state & 0xffffff) == 0x30504) {
            obj->h->p.whole = player->h->p.whole;
            obj->localY = ((BigObj_58960 *)player)->wf2;
            obj->y.p.whole = player->y.p.whole + 0x14;
            setObjState(player, 4, 6, 0);
            SETANIM(obj, 0, 6);
            SetAnim_58960(obj, 1);
            obj->velV = 0x100;
            obj->step++;
            obj->priority = player->priority - 1;
        }
        break;
    case 1:
        obj->y.raw += (s16)(obj->velV += 8) << 8;
        player->y.raw += obj->velV << 8;
        if (obj->y.p.whole > (d = obj->localY)) {
            obj->timer = 0x1e;
            obj->y.p.whole = d;
            obj->step++;
            SetAnim_58960(obj, 0);
        }
        break;
    case 2:
        if (--obj->timer == -1)
            goto next;
        break;
    case 3:
        player->y.raw += 0x8000;
        if (obj->localY < player->y.p.whole) {
            obj->step++;
            SetAnim_58960(obj, 0);
        }
        break;
    case 4:
        obj->timer = 0x10;
        player->animFrame = 0;
        SETANIM(obj, 1, 4);
    next:
        obj->step++;
        break;
    case 5:
        tickAnimation(player);
        player->h->p.whole++;
        if (--obj->timer == -1) {
            obj->timer = 0x1e;
            obj->step++;
            player->animFrame = 0;
            SETANIM(obj, 0, 6);
        }
        break;
    case 6:
        if (--obj->timer == -1) {
            obj->animFrame = 0;
            obj->step++;
            SetAnim_58960(obj, 3);
        }
        break;
    case 7:
        tickAnimation(obj);
        obj->h->p.whole++;
        if (obj->h->p.whole >= player->h->p.whole) {
            setObjState(player, 4, 5, 2);
            D_8009C361 = 0;
            obj->active = 2;
            obj->state = 3;
        }
        break;
    }
}
#undef SETANIM

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80058E14);
extern void *D_80015578[];
extern void *D_80015590[];
extern void *D_800155A4[];
extern void *D_800155BC[];

void func_80058E14(GameObject *obj)
{
    Player *pl = &PLAYER;
    s32 f;

    switch (obj->state) {
    case 0:
        if (obj->id == 0) {
            obj->state = 3;
            break;
        }
        obj->unk6A = 0;
        switch (GAME.selectedArea) {
        case 0:
            obj->tpage = 0xE;
            *(void ***)&obj->unkA8 = D_80015590;
            break;
        case 1:
            switch ((s32)D_8009BCCA) {
            case 0:
            case 1:
                obj->tpage = 0xB;
                break;
            case 2:
            case 3:
            case 4:
                obj->tpage = 6;
                break;
            }
            *(void ***)&obj->unkA8 = D_80015590;
            break;
        case 2:
            switch ((s32)D_8009BCCA) {
            case 0:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_800155BC;
                obj->unk6A = 1;
                break;
            case 3:
                obj->tpage = 0x10;
                *(void ***)&obj->unkA8 = D_800155A4;
                obj->unk6A = 3;
                break;
            case 4:
            case 5:
                obj->tpage = 0x11;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 1:
            case 2:
                obj->tpage = 0xE;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            }
            break;
        case 3:
            switch ((s32)D_8009BCCA) {
            case 0:
            case 4:
                obj->tpage = 0xD;
                break;
            case 1:
            case 2:
            case 3:
            case 5:
            case 6:
                obj->tpage = 5;
                break;
            }
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 4:
            obj->tpage = 0x10;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 5:
            switch ((s32)D_8009BCCA) {
            case 0:
            case 2:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_800155BC;
                obj->unk6A = 2;
                break;
            case 1:
            case 3:
                obj->tpage = 0xB;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            }
            break;
        case 6:
            obj->tpage = 0xF;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 8:
            switch ((s32)D_8009BCCA) {
            case 0:
            case 2:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_800155BC;
                obj->unk6A = 2;
                break;
            case 1:
            case 3:
                obj->tpage = 0xE;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            }
            break;
        case 9:
            switch ((s32)D_8009BCCA) {
            case 0:
                obj->tpage = 0xC;
                *(void ***)&obj->unkA8 = D_80015590;
                break;
            case 1:
                obj->tpage = 0x12;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 2:
                obj->tpage = 0x11;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 3:
                obj->tpage = 0xB;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 4:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 5:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            }
            break;
        case 10:
            switch ((s32)D_8009BCCA) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
                obj->tpage = 7;
                break;
            case 8:
                obj->tpage = 0xC;
                break;
            }
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 11:
            obj->tpage = 0xD;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 13:
            obj->tpage = 0xD;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 14:
            obj->tpage = 0xA;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 16:
            switch ((s32)D_8009BCCA) {
            case 4: case 5: case 6:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            }
            break;
        case 17:
            obj->tpage = 0xB;
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 18:
            switch ((s32)D_8009BCCA) {
            case 1:
                obj->tpage = 0xA;
                break;
            case 2:
                obj->tpage = 9;
                break;
            }
            *(void ***)&obj->unkA8 = D_80015578;
            break;
        case 19:
            switch ((s32)D_8009BCCA) {
            case 0:
                obj->tpage = 0xF;
                *(void ***)&obj->unkA8 = D_800155BC;
                obj->unk6A = 1;
                break;
            case 1:
                obj->tpage = 0xE;
                *(void ***)&obj->unkA8 = D_80015578;
                break;
            case 2:
                obj->tpage = 0x12;
                *(void ***)&obj->unkA8 = D_800155A4;
                obj->unk6A = 2;
                break;
            }
            break;
        }
        obj->category |= 0x80;
        obj->state++;
        f = pl->obj.priority;
        obj->drawType = DRAW_SPRITE_ROTATED;
        obj->animFrame = 0;
        obj->rotX = 0;
        obj->rotY = 0;
        obj->rotZ = 0;
        setHitbox(obj, 0x10, 0x10, 0x20, 0x20);
        obj->drawFlags = 0x81;
        obj->priority = f + 1;
        obj->clut = GetClut(0x80, 0x1F9);
        obj->spriteBank = SPR_DATA[15];
        obj->unkAC = 3;
        obj->anim = (*(void ***)&obj->unkA8)[3];
        readAnimFrameCount(obj);
        if (obj->id == 1) {
            obj->x.p.whole = pl->obj.x.p.whole;
            obj->y.p.whole = pl->obj.y.p.whole;
            obj->z.p.whole = pl->obj.z.p.whole;
        }
        if (*(s32 *)&GAME == 0x1000D) {
            obj->state = 4;
        }
        break;
    case 1:
        cullAndQueueDraw(obj);
        if (obj->id == 0) {
            tickAnimation(obj);
            break;
        }
        switch (obj->unk6A) {
        case 0:
            switch (D_8009C361) {
            case 0:
                func_80057C74(obj);
                break;
            case 1:
                func_800580BC(obj);
                break;
            }
            break;
        case 1:
        case 2:
        case 3:
            switch (D_8009C361) {
            case 0:
                func_80058464(obj);
                break;
            case 1:
                func_80058960(obj);
                break;
            }
            break;
        }
        break;
    case 2:
    case 3:
        freeActorObject(obj);
        break;
    case 4:
        func_801156E8(obj);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_800593EC);
typedef struct { GameObject t; char c0[0x28]; s16 we8; s16 wea; } PO_593EC;
typedef struct E_593EC { u16 a, b; } E_593EC;
extern E_593EC D_8007EDA4[];

void func_800593EC(PO_593EC *o, GameObject *obj)
{
    s16 d, ad, t;
    u16 ox, oy;
    char pad[8];
    if ((u16)(o->t.d->p.whole - obj->d->p.whole + 45) > 90)
        return;
    d = o->we8 - o->t.h->p.whole;
    ox = D_8007EDA4[obj->param].a;
    oy = D_8007EDA4[obj->param].b;
    ad = d;
    if (d < 0) ad = -d;
    d = o->we8 - (obj->h->p.whole + ox);
    if (o->t.animFrame & 1) t = obj->hitboxX + ad + d;
    else t = obj->hitboxX + d;
    if ((u16)t > obj->hitboxW + ad)
        return;
    ad = obj->hitboxY + (o->wea - (obj->y.p.whole + oy));
    if ((u16)ad > obj->hitboxH)
        return;
    o->t.unk9E = 3;
    o->t.velY = 0;
    o->t.unkB8 = ox;
    o->t.unkBA = 0;
    obj->touchFlag = 2;
    SCRATCHPAD.listCounter = 0;
    SCRATCHPAD.touchedObject = obj;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80059514);
s32 func_80059514(PO_593EC *o, GameObject *obj)
{
    s16 d, ad, w;
    u16 t;

    if ((u16)(o->t.d->p.whole - obj->d->p.whole + 45) > 90)
        return 0;
    d = o->we8 - o->t.h->p.whole;
    ad = d;
    if (d < 0) ad = -d;
    d = o->we8 - obj->h->p.whole;
    if (o->t.animFrame & 1) t = obj->hitboxX + ad + d;
    else t = obj->hitboxX + d;
    w = obj->hitboxW;
    if ((u16)t > w + ad)
        return 0;
    ad = obj->hitboxY + (o->wea - obj->y.p.whole);
    if ((u16)ad > obj->hitboxH)
        return 0;
    if (!(o->t.animFrame & 1)) D_1F8003BC = -obj->hitboxX;
    else D_1F8003BC = w - obj->hitboxX;
    return 1;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80059638);
s32 func_80059638(PO_593EC *o, GameObject *obj)
{
    s16 d, ad, w;
    u16 t;

    if ((u16)(o->t.d->p.whole - obj->d->p.whole + 45) > 90)
        return 0;
    d = o->we8 - o->t.h->p.whole;
    ad = d;
    if (d < 0) ad = -d;
    d = o->we8 - obj->h->p.whole;
    if (o->t.animFrame & 1) t = obj->hitboxX + ad + d;
    else t = obj->hitboxX + d;
    w = obj->hitboxW;
    if ((u16)t > w + ad)
        return 0;
    ad = obj->hitboxY + (o->wea - obj->y.p.whole);
    if ((u16)ad > obj->hitboxH)
        return 0;
    if (!(o->t.animFrame & 1)) D_1F8003BC = -obj->hitboxX;
    else D_1F8003BC = w - obj->hitboxX;
    return 1;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005975C);
typedef struct { GameObject t; char c0[0x28]; s16 we8; s16 wea; } PO_5975C;

s32 func_8005975C(PO_5975C *o, GameObject *obj)
{
    s16 d, ad, dy, t;
    if ((u16)(o->t.d->p.whole - obj->d->p.whole + 45) > 90)
        return 0;
    d = o->we8 - o->t.h->p.whole;
    ad = d;
    if (d < 0) ad = -d;
    d = o->we8 - obj->h->p.whole;
    if (o->t.animFrame & 1) t = obj->hitboxX + ad + d;
    else t = obj->hitboxX + d;
    if ((u16)t > obj->hitboxW + ad)
        return 0;
    dy = o->wea - obj->y.p.whole;
    ad = obj->hitboxY + dy;
    if (obj->hitboxH < (u16)ad)
        return 0;
    switch (obj->type) {
    case 0x19:
    case 0x37:
    case 0x3d:
        if (obj->id == 0 && ad < 8) {
            o->t.unk9E = 0xb;
            if (obj->type == 0x3d && (obj->animFrame & 2)) o->t.animFrame = 0;
            else o->t.animFrame = 1;
        } else {
            o->t.unk9E = 0xa;
        }
        if (o->t.animFrame & 1) {
            o->t.unkB8 = 8;
            o->t.h->p.whole = obj->h->p.whole + 8;
        } else {
            o->t.unkB8 = -5;
            o->t.h->p.whole = obj->h->p.whole - 5;
        }
        break;
    case 0x11:
        if (ad < 8) o->t.unk9E = 0xb;
        else o->t.unk9E = 0xa;
        o->t.animFrame = 0;
        o->t.unkB8 = -8;
        o->t.h->p.whole = obj->h->p.whole - 8;
        break;
    case 0x10:
    case 0x3e:
        if (obj->id == 0 && ad < 8) o->t.unk9E = 0xc;
        else o->t.unk9E = 0xa;
        if (o->t.animFrame & 1) {
            o->t.unkB8 = 8;
            o->t.h->p.whole = obj->h->p.whole + 8;
        } else {
            o->t.unkB8 = -8;
            o->t.h->p.whole = obj->h->p.whole - 8;
        }
        break;
    case 0x35:
        if (obj->id != 0) return 0;
        if (o->t.animFrame & 1) {
            o->t.unkB8 = 8;
            o->t.h->p.whole = obj->h->p.whole + 8;
        } else {
            o->t.unkB8 = -8;
            o->t.h->p.whole = obj->h->p.whole - 8;
        }
        o->t.unk9E = 0xa;
        obj->touchFlag = 1;
        break;
    }
    o->t.unkBA = dy;
    o->t.velY = 0;
    SCRATCHPAD.listCounter = 0;
    SCRATCHPAD.touchedObject = obj;
    return 1;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80059A40);

s32 func_8005975C();

s32 func_80059A40(void *o)
{
    u8 **q = SCRATCHPAD.areaHeldList;
    u8 *p;
    SCRATCHPAD.touchedObject = 0;
    D_1F80019E = SCRATCHPAD.areaHeldCount;
    while (D_1F80019E != 0) {
        p = *q;
        D_1F80019E = D_1F80019E - 1;
        q++;
        if (p[0] & 1) {
            switch (p[2]) {
            case 0x10: case 0x11: case 0x19: case 0x35: case 0x37: case 0x3d: case 0x3e:
                func_8005975C(o, p);
            }
        }
    }
    return SCRATCHPAD.touchedObject;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", dispatchAreaCtrlHandler);
void dispatchAreaCtrlHandler(void)
{
    if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
        func_80125C84();
    } else {
        func_8011F188();
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80059B58);
typedef struct { char p0[2]; u16 s2; } H_59B58;
typedef struct { char p0[4]; u16 s4; } A_59B58;
typedef struct {
    char p0[0x16]; u16 s16;
    char p1[0x24 - 0x18]; A_59B58 *anim;
    char p2[0x2e - 0x28]; u16 s2e;
    char p3[0x40 - 0x30]; H_59B58 *h40;
    char p4[0x9e - 0x44]; u8 b9e;
    char p5[0xa9 - 0x9f]; u8 ba9;
    char p6[0xe8 - 0xaa]; u16 se8; s16 sea;
} TO_59B58;
extern void func_80125DA8(TO_59B58 *, u8 *);
extern void func_80126064(TO_59B58 *, u8 *);
extern void func_801261C4(TO_59B58 *, u8 *);
extern void func_80120608(TO_59B58 *, u8 *);
extern void func_801205F4(TO_59B58 *, u8 *);
extern void func_8011C73C(TO_59B58 *, u8 *);
extern void func_80120598(TO_59B58 *, u8 *);

s32 func_80059B58(TO_59B58 *o, u8 f)
{
    s16 r;
    s32 d;
    s16 n;
    u8 **q;
    u8 *e;

    if (o->b9e != 0) return 0;
    D_1F8003C0_S32 = 0;
    if (f) o->sea = o->s16 - 2;
    else o->sea = o->s16 - 8;
    d = 0x10;
    if (o->s2e & 1) d = -0x10;
    r = func_800450FC(o, o->h40->s2 + d, o->sea);
    if (r != 0) {
        o->b9e = (r == 2) ? 5 : 6;
        if (o->s2e & 1) o->h40->s2 -= 0xc;
        else o->h40->s2 += 0xc;
        D_1F8003C0_S32++;
        return D_1F8003C0_S32;
    }
    switch (o->anim->s4) {
    case 0: n = 9; break;
    case 1: n = 10; break;
    case 2: n = 0xc; break;
    default: n = 0x18; break;
    }
    if (o->ba9) n = 0xc;
    d = -n;
    if (!(o->s2e & 1)) d = n;
    q = SCRATCHPAD.areaHeldList;
    D_1F80019E = SCRATCHPAD.areaHeldCount;
    o->se8 = o->h40->s2 + d;
    while (D_1F80019E != 0) {
        e = *q;
        D_1F80019E--;
        q++;
        if (*e & 1) {
            switch (e[2]) {
            case 1:
                func_80125D14(o, e);
                break;
            case 3:
                func_800593EC(o, e);
                break;
            case 4:
                if (GAME.selectedArea == AREA00_VILLAGEOFALLBEGINNINGS) {
            case 2:
                    func_80125C84(o, e);
                } else {
                    func_8011F188(o, e);
                }
                break;
            case 5:
                func_8012631C(o, e);
                break;
            case 6:
                func_80125DA8(o, e);
                break;
            case 0x15:
                func_80126064(o, e);
                break;
            case 0xe:
                func_801261C4(o, e);
                break;
            case 0x1c:
                func_80120608(o, e);
                break;
            case 0x1d:
                func_8011D2AC(o, e);
                break;
            case 0x14:
                func_801269B4(o, e);
                break;
            case 0x34:
                func_8011E2B8(o, e);
                break;
            case 0x10: case 0x11: case 0x19: case 0x35: case 0x37: case 0x3d: case 0x3e:
                func_8005975C(o, e);
                break;
            case 0x1f:
                func_8011E888(o, e);
                break;
            case 0x22:
                func_8011E7C4(o, e);
                break;
            case 0x31:
                func_801205F4(o, e);
                break;
            case 0x42:
                func_8011C73C(o, e);
                break;
            case 0x24:
                func_8011E6DC(o, e);
                break;
            }
        }
    }
    if (D_1F8003C0_S32 == 0) {
        q = SCRATCHPAD.actorHeldList;
        D_1F80019E = SCRATCHPAD.actorHeldCount;
        while (D_1F80019E != 0) {
            e = *q;
            D_1F80019E--;
            q++;
            if (*e & 1) {
                switch (e[2]) {
                case 0xb:
                    func_8012629C(o, e);
                    break;
                case 0x21:
                    func_80120598(o, e);
                    break;
                }
            }
        }
    }
    return D_1F8003C0_S32;
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_80059F7C);
extern void (*D_8007F6F4[])(u8 *);

void func_80059F7C(void)
{
    u8 *e;
    u8 *p;

    p = D_8007F6A4[GAME.selectedArea][D_8009BCCA];
    while (*p != 0xff) {
        e = allocAreaCtrlObject();
        if (e) {
            *e = 1;
            e[2] = p[0];
            e[3] = p[1];
            if (p[3]) D_8007F6F4[e[2]](e);
        }
        p += 4;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", updateAreaCtrlObjects);
void updateAreaCtrlObjects(void)
{
    u8* p = &D_800A55C8;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007F6F4[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0x3C;
    } while (D_1F800198 < 0xA);
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", spawnAreaCtrlObjectAndInit);
void spawnAreaCtrlObjectAndInit(u8 arg0)
{
    u8* p = allocAreaCtrlObject();

    if (p != NULL) {
        p[0] = 1;
        p[2] = arg0;
        func_8005A184(p);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", spawnAreaCtrlObject);
void spawnAreaCtrlObject(u8 arg0)
{
    u8* p = allocAreaCtrlObject();

    if (p != NULL) {
        p[0] = 1;
        p[2] = arg0;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005A184);
typedef struct {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    s16 w08;
    s16 w0a;
    u16 w0c;
    u8 b0e;
    s8 b0f;
} S_5A184;
extern s32 APD_DATA[];
extern void func_8005A508(S_5A184 *);

void func_8005A184(S_5A184 *o)
{
    u8 t = o->b4;

    switch (t) {
    case 0:
        o->w0c = ((u16 *)&GAME)[0];
        o->b0e = GAME.selectedSection;
        o->b4++;
        o->b5 = 0;
        if (((u16 *)&GAME)[0] == 1 && !(D_8009C62B & 1) && D_8009C11D == 0 && D_8009BCCA < 2) {
            APD_DATA[0] = D_1F800370;
            D_1F80035C = D_1F800374;
            APD_DATA[D_8007B296] = D_1F800378;
        }
        func_8005A508(o);
        func_8005A660(o);
        break;
    case 1:
        switch (o->b5) {
        case 0:
            o->b0f = o->b0e - *(u8 *)D_8009BCCA_U16Arr;
            if (o->b0f == 0) break;
            if (o->b0f < 0) o->b0f = 0;
            o->b0e = D_8009BCCA_U16Arr[0];
            o->w08 = 2;
            o->b5++;
            func_8005A3B0(o);
            break;
        case 1:
            if (--o->w08 == 0) {
                o->b5--;
                if (o->b0f == 0) {
                    func_8005A508(o);
                } else {
                    func_8005A7E0(o);
                }
            }
            break;
        }
        break;
    case 2:
        o->b4 = t - 1;
        break;
    case 3:
        freeAreaCtrlObject(o);
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005A3B0);
typedef struct E_5A3B0 { char a; char pad[3]; char b; char pad2[0x1c-5]; char f; s8 g; char pad3[0xd4-0x1e]; } E_5A3B0;
typedef struct E3_5A3B0 { char a; char pad[3]; char b; char pad2[0x1c-5]; char f; s8 g; char pad3[0x6c-0x1e]; } E3_5A3B0;

void func_8005A3B0(s8 *o)
{
    E_5A3B0 *e;
    E3_5A3B0 *e3;
    s32 i;
    e = ((E_5A3B0 *)&D_800A5970);
    i = 0;
    do {
        if (e->a != 0 && (e->f & 0x80) == 0 && o[0xe] + o[0xf] + e->g != 0) {
            e->a = 2;
            e->b = 3;
        }
        i++;
        e++;
    } while (i < 200);
    i = 0;
    do {
        e = &((E_5A3B0 *)&D_800B0B88)[i];
        if (e->a != 0 && (e->f & 0x80) == 0 && o[0xe] + o[0xf] + e->g != 0) {
            e->a = 2;
            e->b = 3;
        }
        i++;
    } while (i < 0x2d);
    i = 0;
    do {
        e3 = &((E3_5A3B0 *)&D_800A3D08)[i];
        if (e3->a != 0 && (e3->f & 0x80) == 0 && o[0xe] + o[0xf] + e3->g != 0) {
            e3->a = 2;
            e3->b = 3;
        }
        i++;
    } while (i < 10);
}

typedef struct { s8 f0; char p1; u8 f2; char p3[0xc]; u8 ff; } R_5A660;
extern R_5A660 ***D_8007F0C8[];


// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005A508);
void func_8005A508(S_5A184 *o)
{
    extern void func_8005AA98(R_5A660 *, s32);
    R_5A660 ***tbl;
    R_5A660 *r;
    s16 i;
    s32 s;
    tbl = D_8007F0C8[GAME.selectedArea];
    for (r = *tbl[D_8009BCCA & 7]; r->f2 < 0xff; r++)
        func_8005AA98(r, -1);
    i = ((s16 *)&D_8007B294)[GAME.selectedArea];
    if (((s16 *)&D_8007B294)[GAME.selectedArea] >= 16) i = 15;
    for (r = *tbl[i]; r->f2 < 0xff; r++) {
        s = r->ff >> 2;
        if (!func_80023608(s) && (r->f0 == D_8009BCCA || r->f0 == ~D_8009BCCA)) func_8005AA98(r, s);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005A660);

void func_8005A660(s8 *o)
{
    extern void func_8005AA98(R_5A660 *, s32);
    R_5A660 ***tbl;
    R_5A660 *r;
    s16 i;
    s32 s;
    if (D_8009BCE9 == 1 && o[0xe] > 0) {
        tbl = D_8007F0C8[GAME.selectedArea];
        for (r = *tbl[(D_8009BCCA - 1) & 7]; r->f2 < 0xff; r++)
            if (r->f0 < 0) func_8005AA98(r, -1);
        i = ((s16 *)&D_8007B294)[GAME.selectedArea];
        if (((s16 *)&D_8007B294)[GAME.selectedArea] >= 16) i = 15;
        for (r = *tbl[i]; r->f2 < 0xff; r++) {
            s = r->ff >> 2;
            if (!func_80023608(s) && r->f0 == -D_8009BCCA) func_8005AA98(r, s);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005A7E0);
typedef struct { s8 f0; char p1; u8 f2; char p3[0xc]; u8 ff; } R_5A7E0;

void func_8005A7E0(s8 *o)
{
    R_5A7E0 ***tbl;
    R_5A7E0 *r;
    s16 i;
    s32 s;
    tbl = D_8007F0C8[GAME.selectedArea];
    for (r = *tbl[D_8009BCCA & 7]; r->f2 < 0xff; r++)
        if (r->f0 >= 0) func_8005AA98(r, -1);
    i = ((s16 *)&D_8007B294)[GAME.selectedArea];
    if (((s16 *)&D_8007B294)[GAME.selectedArea] >= 16) i = 15;
    for (r = *tbl[i]; r->f2 < 0xff; r++) {
        s = r->ff >> 2;
        if (!func_80023608(s) && r->f0 == D_8009BCCA) func_8005AA98(r, s);
    }
    if (o[0xe] > 0) {
        R_5A7E0 ***tbl;
        R_5A7E0 *r;
        s16 i;
        s32 s;
        tbl = D_8007F0C8[GAME.selectedArea];
        for (r = *tbl[(D_8009BCCA - 1) & 7]; r->f2 < 0xff; r++)
            if (r->f0 < 0) func_8005AA98(r, -1);
        i = ((s16 *)&D_8007B294)[GAME.selectedArea];
        if (((s16 *)&D_8007B294)[GAME.selectedArea] >= 16) i = 15;
        for (r = *tbl[i]; r->f2 < 0xff; r++) {
            s = r->ff >> 2;
            if (!func_80023608(s) && r->f0 == -D_8009BCCA) func_8005AA98(r, s);
        }
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005AA98);
typedef struct {
    u8 b0, b1, b2, b3, b4, b5;
    s16 s6, s8, sa;
    u8 bc, bd, be, bf;
} Ent_5AA98;

void func_8005AA98(Ent_5AA98 *e, s32 z)
{
    u8 kind;
    GameObject *obj;
    GameObject *parent;
    u8 ty;
    volatile s32 *q;
    s32 idx;
    s32 tt;
    s16 s;

    kind = e->b1 & 0x7f;
    switch (kind) {
    case OBJ_CAT_ACTOR:
        obj = allocActorObject();
        D_8009B100 = obj;
        if (obj == 0)
            return;
        if (e->bc & 0x10) {
            q = &D_1F800334;
            goto link;
        }
        break;
    case OBJ_CAT_EFFECT:
        if ((D_8009B100 = allocEffectObject()) == 0)
            return;
        break;
    case OBJ_CAT_AREA:
        obj = allocAreaObject();
        D_8009B100 = obj;
        if (obj == 0)
            return;
        idx = e->be;
        if (idx == 0xff) {
            obj->model = 0;
            break;
        }
        if (e->bc & 0x10) {
            q = &D_1F800334;
            s = idx << 2;
            tt = *q;
            q = (volatile s32 *)*q;
            tt = *(s32 *)(tt + s + 4);
            q = (volatile s32 *)((s32)q + tt);
            obj->modelLit = 1;
            obj->model = (s32)q;
        }
        break;
    case OBJ_CAT_ITEM:
        if ((D_8009B100 = allocItemObject()) == 0)
            return;
        break;
    case OBJ_CAT_MODEL:
        obj = allocModelObject();
        D_8009B100 = obj;
        if (obj == 0)
            return;
        q = &D_1F800338;
    link:
        s = *(volatile u8 *)&e->be << 2;
        tt = *q;
        q = (volatile s32 *)*q;
        tt = *(s32 *)(tt + s + 4);
        q = (volatile s32 *)((s32)q + tt);
        obj->modelLit = 1;
        obj->model = (s32)q;
        break;
    case OBJ_CAT_FX:
        if ((D_8009B100 = allocFxObject()) == 0)
            return;
        break;
    }
    if (z >= 0)
        D_8009B100->objectIndex = z;
    else
        D_8009B100->objectIndex = (e->bf >> 2) - 1;
    D_8009B100->category |= e->b1 & 0x80;
    D_8009B100->active = 1;
    D_8009B100->unk1D = e->b0;
    D_8009B100->type = e->b2;
    D_8009B100->id = e->b4;
    D_8009B100->param = e->b3;
    D_8009B100->drawType = e->bc;
    D_8009B100->animFrame = e->b5;
    D_8009B100->priority = e->bd;
    D_8009B100->x.raw = e->s6 << 16;
    D_8009B100->y.raw = e->s8 << 16;
    D_8009B100->z.raw = e->sa << 16;
    if (kind == 3) {
        ty = e->b2;
        if (ty == 0x18 || ty == 0x19 || ty == 0x24 || ty == 0x33)
            D_8009B100->hitboxX = e->be;
    }
    if (kind == 6 || kind == 7)
        return;
    switch (e->bf & 3) {
    case 0:
        D_8009B100->x.raw = e->s6 << 16;
        D_8009B100->y.raw = e->s8 << 16;
        D_8009B100->z.raw = e->sa << 16;
        D_8009B100->parent = 0;
        D_8009B100->child = 0;
        break;
    case 1:
        D_8009B100->x.raw = e->s6 << 16;
        D_8009B100->y.raw = e->s8 << 16;
        D_8009B100->z.raw = e->sa << 16;
        D_8009B104 = D_8009B100;
        D_8009B100->parent = 0;
        break;
    case 2:
        D_8009B100->x.raw = D_8009B104->x.raw + (e->s6 << 16);
        D_8009B100->y.raw = D_8009B104->y.raw + (e->s8 << 16);
        D_8009B100->z.raw = D_8009B104->z.raw + (e->sa << 16);
        D_8009B100->localX = e->s6 << 16;
        D_8009B100->localY = e->s8 << 16;
        D_8009B100->localZ = e->sa << 16;
        parent = D_8009B104;
        D_8009B104 = D_8009B100;
        D_8009B100->parent = (s32)parent;
        parent->child = (s32)D_8009B100;
        break;
    case 3:
        D_8009B100->x.raw = D_8009B104->x.raw + (e->s6 << 16);
        D_8009B100->y.raw = D_8009B104->y.raw + (e->s8 << 16);
        D_8009B100->z.raw = D_8009B104->z.raw + (e->sa << 16);
        D_8009B100->localX = e->s6 << 16;
        D_8009B100->localY = e->s8 << 16;
        D_8009B100->localZ = e->sa << 16;
        D_8009B100->parent = (s32)D_8009B104;
        D_8009B104->child = (s32)D_8009B100;
        D_8009B100->child = 0;
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005AF70);
void func_8005AF70(GameObject *obj)
{
    u8 *p;
    s32 r, g, b;
    switch (obj->state) {
    case 0:
        GAME.fadeScreenControl = 1;
        GAME.fadeScreenAmount = 0;
        p = D_8007F938[GAME.selectedArea];
        if (GAME.selectedArea == AREA04_HAUNTEDMANSION && (GAME.purifiedAreas & 8)) p = D_8007F968;
        p += GAME.selectedSection * 4;
        r = *p++;
        g = *p;
        b = p[1];
        if (GAME.selectedArea == AREA03_PHOENIXMOUNTAIN && (GAME.purifiedAreas & 2) && GAME.selectedSection == GAME.selectedArea) {
            r = 0x60;
            g = 0x97;
            b = 0xff;
        }
        D_8009D6DD = r;
        D_8009D6DE = g;
        D_8009D6DF = b;
        D_8009E3ED = r;
        D_8009E3EE = g;
        D_8009E3EF = b;
        obj->state++;
        break;
    case 1:
        GAME.fadeScreenControl = 2;
        GAME.fadeScreenAmount += 8;
        if ((u8)GAME.fadeScreenAmount != 0) break;
        if (D_1F8003D1 == 1) D_1F8003D1 = 0;
        GAME.fadeScreenControl = 0;
        obj->state++;
        break;
    case 2:
        if (GAME.fadeScreenControl == 3) obj->state++;
        break;
    case 3:
        GAME.fadeScreenControl = 2;
        GAME.fadeScreenAmount -= 8;
        if ((u8)GAME.fadeScreenAmount != 0) break;
        GAME.fadeScreenControl = 1;
        obj->state++;
        D_8009D6DD = 0;
        D_8009D6DE = 0;
        D_8009D6DF = 0;
        D_8009E3ED = 0;
        D_8009E3EE = 0;
        D_8009E3EF = 0;
        break;
    case 4:
        if (GAME.fadeScreenControl == 4) obj->state = 0;
        break;
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005B1A4);
void func_8005B1A4(u8* self)
{
    if (self[4] == 0) {
        *(s16*)(self + 0xC) = GAME.selectedArea;
        self[0xE] = D_8009BCCA;
        self[4] = self[4] + 1;
        func_8005B1F8(self);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", func_8005B1F8);
void func_8005B1F8(u8 *o)
{
    R_5A660 ***tbl;
    R_5A660 *r;
    s16 i;
    s32 s;
    tbl = D_8007F0C8[GAME.selectedArea];
    for (r = *tbl[D_8009BCCA & 7]; r->f2 < 0xff; r++)
        func_8005AA98((Ent_5AA98 *)r, -1);
    i = ((s16 *)&D_8007B294)[GAME.selectedArea];
    if (((s16 *)&D_8007B294)[GAME.selectedArea] >= 16) i = 15;
    for (r = *tbl[i]; r->f2 < 0xff; r++) {
        s = r->ff >> 2;
        if (!func_80023608(s) && (r->f0 == D_8009BCCA || r->f0 == ~D_8009BCCA)) func_8005AA98((Ent_5AA98 *)r, s);
    }
}

// INCLUDE_ASM("nonmatchings/main/game/objpool", dispatchAreaCtrlByVariant);
void dispatchAreaCtrlByVariant(u8* self)
{
    D_8007F988[self[3]]();
}

extern const u32 D_800151E0_ro[] asm("D_800151E0");
extern const u32 D_80015578_ro[] asm("D_80015578");
extern const u32 D_80015590_ro[] asm("D_80015590");
extern const u32 D_800155A4_ro[] asm("D_800155A4");
extern const u32 D_800155BC_ro[] asm("D_800155BC");
extern const u32 D_800155D4_ro[] asm("D_800155D4");
extern const u32 D_800155DC_ro[] asm("D_800155DC");
extern const u32 D_80015600_ro[] asm("D_80015600");
extern const u32 D_80015624_ro[] asm("D_80015624");
extern const u32 D_8001562C_ro[] asm("D_8001562C");
extern const u32 D_80015634_ro[] asm("D_80015634");
extern const u32 D_80015654_ro[] asm("D_80015654");
extern const u32 D_8001565C_ro[] asm("D_8001565C");
extern const u32 D_80015664_ro[] asm("D_80015664");
extern const u32 D_8001566C_ro[] asm("D_8001566C");
extern const u32 D_80015674_ro[] asm("D_80015674");
extern const u32 D_8001567C_ro[] asm("D_8001567C");
extern const u32 D_800156A0_ro[] asm("D_800156A0");
extern const u32 D_800156A8_ro[] asm("D_800156A8");
extern const u32 D_800156CC_ro[] asm("D_800156CC");
extern const u32 D_800156F0_ro[] asm("D_800156F0");
extern const u32 D_800156F8_ro[] asm("D_800156F8");
extern const u32 D_80015700_ro[] asm("D_80015700");
extern const u32 D_80015708_ro[] asm("D_80015708");
extern const u32 D_80015710_ro[] asm("D_80015710");
extern const u32 D_80015718_ro[] asm("D_80015718");
extern const u32 D_80015720_ro[] asm("D_80015720");
extern const u32 D_80015728_ro[] asm("D_80015728");

const u32 D_800151E0_ro[230] asm("D_800151E0") = {
    0x000000A9, 0x000E0000, 0x000000AA, 0x800E0000,
    0x00000094, 0x803C0000, 0x00000095, 0x803C0000,
    0x00000096, 0x803C0000, 0x00000097, 0x00080000,
    0x00000098, 0x00080000, 0x00000099, 0x00080000,
    0x0000009A, 0x00080000, 0x0000009B, 0x00080000,
    0x0000009C, 0x80080000, 0x0000009D, 0x00080000,
    0x0000009E, 0x00080000, 0x0000009F, 0x00080000,
    0x000000A0, 0x00080000, 0x000000A1, 0x00080000,
    0x000000A2, 0x80080000, 0x000000A3, 0x00080000,
    0x000000A4, 0x00080000, 0x000000A5, 0x00080000,
    0x000000A6, 0x00080000, 0x000000A7, 0x00080000,
    0x000000A8, 0x80080000, 0x000000AB, 0x000E0000,
    0x000000AC, 0x800E0000, 0x000000AD, 0x000E0000,
    0x000000AE, 0x800E0000, 0x000000AF, 0x00120000,
    0x000000B0, 0x00120000, 0x000000AF, 0x00080000,
    0x000000B0, 0x00080000, 0x000000AF, 0x00080000,
    0x000000B0, 0x00080000, 0x000000AF, 0x00120000,
    0x000000B0, 0x80120000, 0x000000B1, 0x00120000,
    0x000000B2, 0x00120000, 0x000000B3, 0x00080000,
    0x000000B2, 0x00080000, 0x000000B3, 0x00080000,
    0x000000B2, 0x00080000, 0x000000B3, 0x00120000,
    0x000000B2, 0x80120000, 0x000000B4, 0x00120000,
    0x000000B5, 0x00120000, 0x000000B6, 0x00080000,
    0x000000B5, 0x00080000, 0x000000B6, 0x00080000,
    0x000000B5, 0x00080000, 0x000000B6, 0x00120000,
    0x000000B5, 0x80120000, 0x000000B7, 0x00120000,
    0x000000B8, 0x00060000, 0x000000B7, 0x00060000,
    0x000000B8, 0x00060000, 0x000000B7, 0x00060000,
    0x000000B8, 0x00060000, 0x000000B7, 0x00060000,
    0x000000B8, 0x00060000, 0x000000B7, 0x00060000,
    0x000000B8, 0x00080000, 0x000000B7, 0x00080000,
    0x000000B8, 0x800A0000, 0x000000B9, 0x00120000,
    0x000000BA, 0x00060000, 0x000000B9, 0x00060000,
    0x000000BA, 0x00060000, 0x000000B9, 0x00060000,
    0x000000BA, 0x00060000, 0x000000B9, 0x00060000,
    0x000000BA, 0x00060000, 0x000000B9, 0x00060000,
    0x000000BA, 0x00080000, 0x000000B9, 0x00080000,
    0x000000BA, 0x800A0000, 0x000000BB, 0x00120000,
    0x000000BC, 0x00060000, 0x000000BB, 0x00060000,
    0x000000BC, 0x00060000, 0x000000BB, 0x00060000,
    0x000000BC, 0x00060000, 0x000000BB, 0x00060000,
    0x000000BC, 0x00060000, 0x000000BB, 0x00060000,
    0x000000BC, 0x00080000, 0x000000BB, 0x00080000,
    0x000000BC, 0x800A0000, 0x000000BD, 0x803C0000,
    0x000000BE, 0x803C0000, 0x000000BF, 0x803C0000,
    0x000000C0, 0x00070000, 0x000000C1, 0x00100000,
    0x000000C0, 0x00050000, 0x00000094, 0x80280000,
    0x000000C2, 0x00070000, 0x000000C3, 0x00100000,
    0x000000C2, 0x00050000, 0x000000C4, 0x80280000,
    0x000000C5, 0x00070000, 0x000000C6, 0x00100000,
    0x000000C5, 0x00050000, 0x000000C7, 0x80280000,
    0x00000095, 0x00090000, 0x000000C2, 0x00090000,
    0x000000C0, 0x00090000, 0x000000CA, 0x000B0000,
    0x000000C9, 0x80060000, 0x000000C8, 0x000B0000,
    0x000000C9, 0x00060000, 0x000000CA, 0x000B0000,
    0x000000C9, 0x80060000, 0x000000AA, 0x00070000,
    0x000000C0, 0x00090000, 0x000000C3, 0x00090000,
    0x00000095, 0x80090000,
};
const u32 D_80015578_ro[6] asm("D_80015578") = {
    (u32)D_80015624_ro, (u32)D_8001562C_ro,
    (u32)D_800155D4_ro, (u32)D_800155DC_ro,
    (u32)D_80015600_ro, (u32)D_80015634_ro,
};
const u32 D_80015590_ro[5] asm("D_80015590") = {
    (u32)D_800156F0_ro, (u32)D_800156F8_ro,
    (u32)D_800156A0_ro, (u32)D_800156A8_ro,
    (u32)D_800156CC_ro,
};
const u32 D_800155A4_ro[6] asm("D_800155A4") = {
    (u32)D_80015664_ro, (u32)D_8001566C_ro,
    (u32)D_8001565C_ro, (u32)D_8001567C_ro,
    (u32)D_80015654_ro, (u32)D_80015674_ro,
};
const u32 D_800155BC_ro[6] asm("D_800155BC") = {
    (u32)D_80015710_ro, (u32)D_80015718_ro,
    (u32)D_80015708_ro, (u32)D_80015728_ro,
    (u32)D_80015700_ro, (u32)D_80015720_ro,
};
const u32 D_800155D4_ro[2] asm("D_800155D4") = {
    0x00000000, 0x803C0000,
};
const u32 D_800155DC_ro[9] asm("D_800155DC") = {
    0x00000001, 0x00030000,
    0x00000002, 0x00030000,
    0x00000003, 0x00030000,
    0x00000004, 0x40030000,
    (u32)D_800155DC_ro,
};
const u32 D_80015600_ro[9] asm("D_80015600") = {
    0x00000005, 0x00080000,
    0x00000006, 0x00080000,
    0x00000007, 0x00080000,
    0x00000008, 0x80080000,
    (u32)D_80015600_ro,
};
const u32 D_80015624_ro[2] asm("D_80015624") = {
    0x00000009, 0x803C0000,
};
const u32 D_8001562C_ro[2] asm("D_8001562C") = {
    0x0000000A, 0x803C0000,
};
const u32 D_80015634_ro[8] asm("D_80015634") = {
    0x00000014, 0x00100000, 0x00000015, 0x00050000,
    0x00000016, 0x00040000, 0x00000015, 0x80030000,
};
const u32 D_80015654_ro[2] asm("D_80015654") = {
    0x0000000B, 0x803C0000,
};
const u32 D_8001565C_ro[2] asm("D_8001565C") = {
    0x0000000C, 0x803C0000,
};
const u32 D_80015664_ro[2] asm("D_80015664") = {
    0x0000000D, 0x803C0000,
};
const u32 D_8001566C_ro[2] asm("D_8001566C") = {
    0x0000000E, 0x803C0000,
};
const u32 D_80015674_ro[2] asm("D_80015674") = {
    0x0000000F, 0x803C0000,
};
const u32 D_8001567C_ro[9] asm("D_8001567C") = {
    0x00000010, 0x00030000,
    0x00000011, 0x00030000,
    0x00000012, 0x00030000,
    0x00000013, 0x40030000,
    (u32)D_8001567C_ro,
};
const u32 D_800156A0_ro[2] asm("D_800156A0") = {
    0x00000017, 0x803C0000,
};
const u32 D_800156A8_ro[9] asm("D_800156A8") = {
    0x00000018, 0x00080000,
    0x00000019, 0x00080000,
    0x0000001A, 0x00080000,
    0x0000001B, 0x40080000,
    (u32)D_800156A8_ro,
};
const u32 D_800156CC_ro[9] asm("D_800156CC") = {
    0x0000001C, 0x00080000,
    0x0000001D, 0x00080000,
    0x0000001E, 0x00080000,
    0x0000001F, 0x40080000,
    (u32)D_800156CC_ro,
};
const u32 D_800156F0_ro[2] asm("D_800156F0") = {
    0x00000020, 0x803C0000,
};
const u32 D_800156F8_ro[2] asm("D_800156F8") = {
    0x00000021, 0x803C0000,
};
const u32 D_80015700_ro[2] asm("D_80015700") = {
    0x00000022, 0x803C0000,
};
const u32 D_80015708_ro[2] asm("D_80015708") = {
    0x00000023, 0x803C0000,
};
const u32 D_80015710_ro[2] asm("D_80015710") = {
    0x00000024, 0x803C0000,
};
const u32 D_80015718_ro[2] asm("D_80015718") = {
    0x00000025, 0x803C0000,
};
const u32 D_80015720_ro[2] asm("D_80015720") = {
    0x00000026, 0x803C0000,
};
const u32 D_80015728_ro[5] asm("D_80015728") = {
    0x00000023, 0x00030000,
    0x00000027, 0x40040000,
    (u32)D_80015728_ro,
};
