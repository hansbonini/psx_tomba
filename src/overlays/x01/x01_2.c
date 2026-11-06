#include "common.h"
#include "game.h"
#include "x01.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EA14);


typedef struct { Fix16 a, y, b; } FV_1EA14;
extern void addItemToInventory(s32, s32, s32);

static __inline__ s32 vdiv_1EA14(s32 a, s32 b)
{
    return a / b;
}

static __inline__ void start_1EA14(GameObject *o)
{
    s32 vy, vx;

    o->visible = (*(GameObject *)&PLAYER).visible;
    o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
    o->anim = D_8013DA7C[0];
    o->h->p.whole = (*(GameObject *)&PLAYER).h->p.whole;
    o->y.p.whole = (*(GameObject *)&PLAYER).y.p.whole;
    o->d->p.whole = (*(GameObject *)&PLAYER).d->p.whole;
    *(volatile s16 *)&o->timer = 20;
    vy = vdiv_1EA14(-0x6c00 - (o->y.p.whole << 8), o->timer);
    o->rotZ = 0;
    o->localX = 0x20;
    o->localY = -0x140;
    vx = vdiv_1EA14(0x79b00 - (o->h->p.whole << 8), 20);
    o->category |= 0x80;
    o->velY = vy;
    o->velX = vx;
    o->priority = (*(GameObject *)&PLAYER).priority - 1;
    o->step++;
}

void func_8011EA14(GameObject *o)
{
    GameObject *n;
    FV_1EA14 v;
    s32 t;

    switch (o->step) {
    case 0:
        start_1EA14(o);
        break;
    case 1:
        if (--o->timer > 0)
            break;
        o->timer = 0xf;
        o->step++;
        break;
    case 2:
        o->h->raw += o->velX << 8;
        o->y.raw += o->velY << 8;
        o->y.raw += o->localY << 8;
        o->localY += o->localX;
        if (--o->timer > 0)
            break;
        o->h->p.whole = 0x79b;
        o->y.p.whole = -0x6c;
        o->timer = 20;
        o->step++;
        break;
    case 3:
        if (--o->timer > 0)
            break;
        o->rotZ = 0x100;
        o->timer = 0x40;
        o->step++;
        break;
    case 4:
        t = o->rotZ;
        if (o->animFrame & 1)
            t += 2;
        else
            t -= 2;
        o->rotZ = t & 0xff;
        if (--o->timer > 0)
            break;
        o->anim = D_8013DA84;
        readAnimFrameCount(o);
        o->timer = 0x50;
        n = allocActorObject();
        if (n != 0) {
            n->active = 1;
            n->id = 1;
            n->type = 0x22;
            n->x.p.whole = o->x.p.whole;
            n->y.p.whole = o->y.p.whole + 0x20;
            n->z.p.whole = o->z.p.whole;
            D_8009C1BD[0] = 2;
        }
        o->step++;
        break;
    case 5:
        if (--o->timer > 0)
            break;
        v.a.p.whole = o->x.p.whole;
        v.y.p.whole = o->y.p.whole + 0x30;
        v.b.p.whole = o->z.p.whole;
        applyItemEffect(D_8013BA60, &v, 0, 0, 1);
        printInfoMessage(MSG_EFFECT_NOTICE, MSG_TYPE_INFO);
        removeItemFromInventory(ITEM_BUCKETOFWATER, 1);
        addItemToInventory(ITEM_BUCKET, 1, 0);
        D_8009C068.unk54d = 1;
        D_8009BC98.unk0F = 0;
        D_8009BC98.unk12 = 0;
        D_8009BC98.unk0E = 0;
        o->state = 3;
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EDF8);

void func_8011EDF8(GameObject *o)
{
    if (o->visible == 0) return;
    switch (o->subState) {
    case 0:
        break;
    case 1:
        func_8011E600(o);
        break;
    case 2:
        func_8011EA14(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011EE60);
typedef struct {
    u16 b0, b1, b2, b3, w1e;
    s16 idx;
    void **tab;
} Ent_1EE60;
extern Ent_1EE60 D_8013BA68[];

void func_8011EE60(GameObject *o)
{
    switch (o->state) {
    case 0:
        o->hitboxX = D_8013BA68[o->id].b0;
        o->hitboxW = D_8013BA68[o->id].b1;
        o->hitboxY = D_8013BA68[o->id].b2;
        o->hitboxH = D_8013BA68[o->id].b3;
        o->tpage = D_8013BA68[o->id].w1e;
        o->spriteBank = SPR_DATA[D_8013BA68[o->id].idx];
        o->anim = *D_8013BA68[o->id].tab;
        o->rotZ = 0;
        o->drawFlags = 0;
        o->category |= 0x80;
        o->drawType = 2;
        readAnimFrameCount(o);
        o->state = 1;
        break;
    case 1:
        cullAndQueueDraw(o);
        if (o->visible) {
            switch (o->subState) {
            case 0:
                break;
            case 1:
                func_8011E600(o);
                break;
            case 2:
                func_8011EA14(o);
                break;
            }
        }
        break;
    case 2:
        cullAndQueueDraw(o);
        switch (o->subState) {
        case 0:
            o->subState = 1;
            break;
        case 1:
            tickAnimation(o);
            break;
        case 2:
            o->subState = 5;
            o->step = 0;
            break;
        case 3:
            o->state = 3;
            break;
        }
        break;
    case 3:
        D_8009C068.unk597 = 0;
        freeAreaObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F0CC);


void func_8011F0CC(GameObject *o)
{
    Vec3Fix v;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xb;
        o->drawFlags = 0;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013D944[o->id];
        o->hitboxX = 0x10;
        o->hitboxW = 0x1c;
        o->hitboxY = 0xe;
        o->hitboxH = 0x1c;
        break;
    case 1:
        cullAndQueueDraw(o);
        break;
    case 2:
        switch (o->subState) {
        case 0:
            o->subState++;
            cullAndQueueDraw(o);
            func_80117CE8(o->h->p.whole, o->y.p.whole, o->d->p.whole);
            func_800322A4(2, o->h->p.whole, o->y.p.whole, o->d->p.whole);
            v.x.p.whole = o->h->p.whole;
            v.y.p.whole = o->y.p.whole;
            v.z.p.whole = o->d->p.whole;
            applyItemEffect(D_8013BA98, &v, 0, 0, 0);
            o->timer = 0x20;
            D_8009C068.unk54e = 4;
            break;
        case 1:
            if (--o->timer == -1) {
                o->subState++;
            } else if ((SCRATCHPAD.activeFrameCount + SCRATCHPAD.updateIndex) & 1) {
                cullAndQueueDraw(o);
            }
            break;
        case 2:
            o->state = 3;
            ((GameObject *)o->child)->state = 3;
            func_8002367C(o->objectIndex);
            func_8002367C(((GameObject *)o->child)->objectIndex);
            break;
        }
        break;
    case 3:
        freeAreaObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F30C);


void func_8011F30C(GameObject *o)
{
    switch (o->state) {
    case 0:
        if (!(D_8009C608.purifiedAreas & 1)) {
            o->state = 3;
            break;
        }
        o->state++;
        o->active = 2;
        if (D_8009C068.event_A4) {
            o->subState = 1;
        } else {
            o->subState = 0;
        }
        break;
    case 1:
        switch (o->subState) {
        case 0:
            switch (o->step) {
            case 0: {
                u8 *c = &D_8009C068.unk721;
                if (*c >= 4) {
                    *c = 5;
                    o->step++;
                }
                break;
            }
            case 1:
                func_80022D3C(o, 0x90);
                break;
            }
            break;
        case 1:
            func_80022D3C(o, 0x90);
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeAreaObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F43C);

extern void setEventStarted(s32, s32, s32);

void func_8011F43C(GameObject *o)
{
    u8 s;
    GameObject *e;

    switch (o->state) {
    case 0:
        switch (o->id) {
        case 0:
            o->state++;
            o->hitboxX = 0x24;
            o->hitboxW = 0x48;
            o->hitboxY = 0x2b;
            o->hitboxH = 0x57;
            o->active = 1;
            o->unk68 = 0;
            if (D_8009C3EC[0] || D_8009C068.event_4D == 0xff) {
                o->model = (s32)((char **)&D_1F800334)[0] + *(s32 *)((*(char **)&SCRATCHPAD.wmdData[1]) + 0x34);
            }
            break;
        case 1:
        case 2:
            o->state++;
            o->active = 2;
            o->priority = 8;
            if (D_8009C068.event_4D == 0xff) o->y.p.whole += 0x10;
            else o->y.p.whole += 0x76;
            break;
        case 3:
            o->state++;
            o->drawType = 0x11;
            o->rotY = 0x40;
            o->active = 2;
            o->priority = 8;
            o->y.p.whole += 0x10;
            break;
        }
        break;
    case 1:
        cullAndQueueDraw(o);
        switch (o->id) {
        case 0:
            s = o->subState;
            if (s != 0) break;
            if (D_8009C3EC_U8 || D_8009C068.event_4D == 0xff) {
                o->subState = s + 1;
                break;
            }
            if (o->unk68 == 0) break;
            setEventStarted(EVENT_WHATISTHIS, 0, 1);
            D_8009C3EC_U8 = 1;
            o->model = (s32)((char **)&D_1F800334)[0] + *(s32 *)((*(char **)&SCRATCHPAD.wmdData[1]) + 0x34);
            e = allocEffectObject();
            if (e != 0) {
                e->type = 0x3d;
                e->active = 1;
                e->id = 0;
                e->timer = 0x18;
                e->h->raw = o->h->raw;
                e->y.raw = o->y.raw;
                e->d->raw = o->d->raw;
            }
            o->unk68 = 0;
            o->subState++;
            break;
        case 1:
        case 2:
            s = o->subState;
            switch (s) {
            case 0:
                if (D_800A38BD[0] == 4) {
                    o->priority = 0;
                    o->subState++;
                }
                break;
            case 1:
                if (D_800A38BD[0] == 7) o->subState = s + 1;
                break;
            case 2:
                o->y.raw += 0x18000;
                break;
            }
            break;
        case 3:
            s = o->subState;
            switch (s) {
            case 0:
                if (D_800A38BD[0] == 4) o->subState = s + 1;
                break;
            case 1:
                o->d->p.whole -= 2;
                if (o->d->p.whole < 0x1037) o->subState++;
                break;
            case 2:
                break;
            }
            break;
        }
        break;
    case 2:
        break;
    case 3:
        freeAreaObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F82C);

s32 func_8011F82C(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) goto ret0;
    if (D_8009BC98.unk0F | D_8009BC98.unk10) return 0;
    if ((*(GameObject *)&PLAYER).active == 2) return 0;
    if ((u16)((*(GameObject *)&PLAYER).d->p.whole - o->d->p.whole + 0x2d) >= 0x5b) return 0;
    if ((u16)((*(GameObject *)&PLAYER).h->p.whole - o->h->p.whole + (o->hitboxX + (*(GameObject *)&PLAYER).hitboxX)) > o->hitboxW + (*(GameObject *)&PLAYER).hitboxW) {
    ret0:
        return 0;
    }
    return (u16)((*(GameObject *)&PLAYER).y.p.whole - o->y.p.whole + ((*(GameObject *)&PLAYER).hitboxY + o->hitboxY)) <= (*(GameObject *)&PLAYER).hitboxH + o->hitboxH;
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011F940);



void func_8011F940(GameObject *o)
{
    switch (o->step) {
    case 0:
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        SCRATCHPAD.prevTargetX = o->h->raw;
        o->timer = 60;
        o->step++;
        break;
    case 1:
        if (--o->timer == -1) {
            o->step++;
        }
        break;
    case 2:
        o->scaleX += 0x80;
        if (o->scaleX > 0x1000) {
            GameObject *p = (GameObject *)o->child;
            o->scaleX = 0x1000;
            o->timer = 30;
            o->active = 1;
            o->step++;
            p->unk6A = 1;
            p = (GameObject *)p->child;
            p->unk6A = 1;
        }
        o->scaleY = o->scaleX;
        o->scaleZ = o->scaleX;
        break;
    case 3:
        if (--o->timer == -1) {
            o->step = 0;
            o->subState++;
            D_800A38BB[0] = 6;
            D_8009C068.unk5ab = 1;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011FAD0);




void func_8011FAD0(GameObject *o)
{
    s16 t;

    switch (o->step) {
    case 0:
        if (o->visible == 0) break;
        if (func_8011F82C(o) == 0) break;
        o->step++;
        (*(GameObject *)&PLAYER).active = 2;
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        D_1F80018C = o->h->raw;
        o->timer = 10;
        break;
    case 1:
        if (--o->timer == -1) {
            (*(GameObject *)&PLAYER).active = 5;
            ((u8 *)&D_800A539C)[0] = 5;
            ((u8*)&D_8009BC98.unk0E)[0] = 0;
            (*(GameObject *)&PLAYER).visible = 0;
            ((u8 *)&D_800A539D)[0] = 0x40;
            o->timer = 0x14;
            o->step++;
            ((s16 *)&GAME.nextArea)[0] = 0xe;
            ((s16 *)&GAME.nextSection)[0] = 0;
            ((s16 *)&GAME.nextSpawnPoint)[0] = 0;
        }
        break;
    case 2:
        t = o->timer;
        if (t == 0) {
            GAME.fadeScreenControl = 3;
            ((u8*)&D_8009BC98.unk0C)[0] = 1;
            ((u8*)&SCRATCHPAD.warpFadeActive)[0] = 1;
            o->step++;
        } else {
            o->timer = t - 1;
        }
        o->scaleX += 0x80;
        if (o->scaleX > 0x4000) {
            o->scaleX = 0x4000;
            o->step++;
        }
        o->scaleY = o->scaleX;
        o->scaleZ = o->scaleX;
        break;
    case 3:
        o->scaleX += 0x80;
        if (o->scaleX > 0x4000) {
            o->scaleX = 0x4000;
        }
        o->scaleY = o->scaleX;
        o->scaleZ = o->scaleX;
        if (GAME.fadeScreenControl == 1) {
            SCRATCHPAD.currentTask->state2 = 7;
            SCRATCHPAD.currentTask->step.value = 0;
            D_8009D6DD_U8Arr[0] = 0xff;
            D_8009D6DE_U8Arr[0] = 0xff;
            D_8009D6DF_U8Arr[0] = 0xff;
            D_8009E3ED_U8Arr[0] = 0xff;
            D_8009E3EE_U8Arr[0] = 0xff;
            D_8009E3EF_U8Arr[0] = 0xff;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8011FD7C);



static __inline__ s32 onscreen_1FD7C(GameObject *o)
{
    if (D_8009BC98.unk0A == 0) return 0;
    if ((u16)(o->h->p.whole - (*(u16*)((char*)&SCRATCHPAD.cameraPos.x.raw + 2))) >= 0x12d) return 0;
    return (u16)((*(u16 *)&SCRATCHPAD.screenOrigin.y.p.whole) - (o->y.p.whole + 0x10)) < 0xc9;
}

void func_8011FD7C(GameObject *o)
{
    s16 buf[4];
    GameObject *p;
    s32 dx, dy;

    switch (o->state) {
    case 0:
        if (D_8009C068.item_25 == 0 || (D_8009C608.purifiedAreas & 2)) {
            o->state = 3;
            break;
        }
        o->state++;
        o->drawType = 0x13;
        o->unk6A = 0;
        o->active = 2;
        if (o->param == 0) {
            buf[0] = 0x80;
            buf[1] = 0x1fe;
            buf[2] = 0x10;
            buf[3] = 2;
            LoadImage(buf, D_8013BAA0);
            o->hitboxX = 0x18;
            o->hitboxW = 0x30;
            o->hitboxY = 0x18;
            o->hitboxH = 0x32;
        } else {
            o->hitboxX = 0xa;
            o->hitboxW = 0x14;
            o->hitboxY = 0xe;
            o->hitboxH = 0x36;
        }
        o->rotX = 0;
        o->rotY = D_8013BAE0[o->param];
        o->rotZ = 0;
        if (D_8009C068.unk5ab == 0) {
            o->subState = 0;
            o->scaleX = 0x800;
            o->scaleY = 0x800;
            o->scaleZ = 0x800;
        } else {
            if (o->param == 0) {
                o->subState = 2;
                o->active = 1;
            } else {
                o->subState = 1;
                o->active = 2;
            }
            o->scaleX = 0x1000;
            o->scaleY = 0x1000;
            o->scaleZ = 0x1000;
        }
        break;
    case 1:
        if (o->param != 0) {
            p = (GameObject *)o->parent;
            if (p->visible == 0) break;
            o->scaleX = p->scaleX;
            o->scaleY = p->scaleY;
            o->scaleZ = p->scaleZ;
            dx = (s16)(o->localX >> 16) * o->scaleX;
            dy = (s16)(o->localY >> 16) * o->scaleX;
            o->h->raw = p->h->raw + (dx << 4);
            o->y.raw = p->y.raw + (dy << 4);
            o->visible = 1;
            pushAreaDrawList(o);
            switch (o->subState) {
            case 0:
                if (o->unk6A) o->subState++;
                break;
            case 1:
                if (o->param == 2) {
                    o->rotY -= 0x20;
                    if (o->rotY < -0x638) {
                        o->rotY = -0x638;
                        o->subState++;
                    }
                } else {
                    o->rotY += 0x20;
                    if (o->rotY > 0x638) {
                        o->rotY = 0x638;
                        o->subState++;
                    }
                }
                break;
            case 2:
                o->active = 1;
                break;
            }
        } else {
            cullAndQueueDraw(o);
            switch (o->subState) {
            case 0:
                if (onscreen_1FD7C(o)) o->subState++;
                break;
            case 1:
                func_8011F940(o);
                break;
            case 2:
                func_8011FAD0(o);
                break;
            }
        }
        break;
    case 2:
        break;
    case 3:
        freeAreaObject(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_80120174);


void func_80120174(GameObject *o)
{
    switch (o->param) {
    case 0:
        o->drawFlags = 0x80;
        if (o->localX < -0x3c0000) o->localX = 0x17c0000;
        o->localX -= o->animFrame << 4;
        o->x.raw = o->localX;
        break;
    case 1:
        if (o->localX < -0x280000) o->localX = 0x1680000;
        o->localX -= o->animFrame << 4;
        o->x.raw = o->localX;
        break;
    case 2:
        o->x.p.whole = (u32)o->localX >> 4;
        break;
    case 3:
        o->x.p.whole = (u32)o->localX >> 3;
        break;
    case 4:
        o->drawFlags = 0x80;
        *(s8 *)&o->priority = -1;
        if (o->localX < -0x3c0000) {
            o->localX = 0x17c0000;
        } else if (o->localX < 0xa0) {
            o->animFrame = 0x800;
        }
        o->localX -= o->animFrame << 4;
        o->x.raw = o->localX;
        break;
    }
    {
        s32 y = o->localY;
        o->y.p.whole = ((u32)(y - (*(u16 *)&SCRATCHPAD.screenOrigin.y.p.whole)) & 0xfff) >> 4;
    }
    o->visible = 1;
    pushFxDrawList(o);
}

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8012029C);

INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_8012042C);

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_2", func_801205D8);

void func_801205D8(GameObject *o)
{
    D_8009E454 = 0;
    if (GAME.baronState == 3)
        func_801367F8(0, o->x.p.whole, o->y.p.whole, o->z.p.whole);
    if (D_8009C068.event_0E != 0xff) {
        if (!(GAME.area00_eventControl & 0x100))
            goto clr;
        if (GAME.selectedSection == 3 || GAME.selectedSection == 1)
            func_80135C0C(o->x.p.whole, o->y.p.whole, o->z.p.whole);
    } else {
        if (!(GAME.area00_eventControl & 0x100))
            goto clr;
        GAME.area00_eventControl &= ~0x100;
    }
    if (!(GAME.area00_eventControl & 0x100)) {
    clr:
        D_8009C068.unk597 = 0;
    }
    if (D_8009C068.event_14 == 0xff && D_8009C068.item_1A != 0)
        removeItemFromInventory(ITEM_BROKENVASE, 1);
}
