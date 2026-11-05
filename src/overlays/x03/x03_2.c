#include "common.h"
#include "game.h"
#include "x03.h"

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011B018);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011B1CC);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011B3A0);

static __inline__ void setAnim_1B3A0(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_8011B3A0(GameObject *o)
{
    GameObject *p = &PLAYER;

    switch (o->step) {
    case 0:
        if (o->param & 2) o->localY = (o->param & 1) * 64 + 0x20;
        else o->localY = (o->id & 1) << 7;
        if (o->localY <= 0x40) o->velH = 4;
        else o->velH = -4;
        o->step++;
        break;
    case 1:
        o->localZ = (o->localZ + o->velH) & 0xff;
        if (o->velH < 0) {
            if (o->localZ < 0x10) {
                o->localZ = 0x10;
                o->timer = 0x1e;
                o->velH = 8;
                o->step++;
            }
        } else {
            if (o->localZ > 0x70) {
                o->localZ = 0x70;
                o->timer = 0x1e;
                o->velH = -8;
                o->step++;
            }
        }
        break;
    case 2:
        if (--o->timer == -1) {
            if (o->localY > 0x40) o->step = 3;
            else o->step = 4;
        }
        break;
    case 3:
        o->localZ = (o->localZ + o->velH) & 0xff;
        if (o->localY < o->localZ) {
            o->localZ = o->localY;
            o->timer = 8;
            o->step = 5;
        }
        break;
    case 4:
        o->localZ += o->velH;
        if (o->localZ < o->localY) {
            o->localZ = o->localY;
            o->timer = 8;
            o->step = 5;
        }
        break;
    case 5:
        o->timer = 2;
        o->unkAC = 4;
        o->step++;
        setAnim_1B3A0(o, D_80138C28[0]);
        break;
    case 6:
        if (o->timer == 0) {
            playSFX(0x72);
            p->active = 1;
            p->timer = 0x12;
            p->unk9C = 1;
            p->state = 1;
            p->subState = 0x34;
            p->step = 1;
            p->h->p.whole = o->h->p.whole;
            p->y.p.whole = o->y.p.whole;
            if (o->param & 2) {
                p->animFrame = o->param & 1;
                p->velY = -0x200;
                p->y.p.whole -= 0x30;
                if (o->param & 1) {
                    p->h->p.whole -= 0x30;
                    p->velX = -0x400;
                } else {
                    p->h->p.whole += 0x30;
                    p->velX = 0x400;
                }
            } else {
                p->animFrame = o->id & 1;
                p->velY = 0;
                if (o->id & 1) {
                    p->h->p.whole -= 0x38;
                    p->velX = -0x400;
                } else {
                    p->h->p.whole += 0x38;
                    p->velX = 0x400;
                }
            }
            o->step++;
        } else {
            o->timer--;
        }
    case 7:
        if (tickAnimation(o)) {
            o->scaleX = 0;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011B728);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011B91C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BA78);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BB4C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BD20);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BDC0);

void func_8011BDC0(GameObject *o)
{
    switch (o->subState) {
    case 0:
        func_8011AA44(o);
        break;
    case 1:
        func_8011ABC0(o);
        break;
    case 2:
        func_8011AD84(o);
        break;
    case 3:
        func_8011B018(o);
        break;
    case 4:
        func_8011B3A0(o);
        break;
    case 5:
        switch (o->step) {
        case 0:
            o->timer = 15;
            o->localZ = 0x40;
            o->unkAC = 5;
            o->scaleX = 0;
            o->drawType = 0;
            o->y.p.whole += 0x30;
            o->step++;
            o->anim = D_80138C2C[0];
            readAnimFrameCount(o);
            break;
        case 1:
            if (o->timer != 0) {
                o->timer--;
            } else if (tickAnimation(o)) {
                o->step++;
                D_800A53AE_U16++;
            }
            break;
        case 2:
            o->step = 0;
            o->subState++;
            break;
        }
        break;
    case 6:
        func_8011B728(o);
        break;
    }
    if (o->scaleX & 2) {
        if (o->scaleX & 1)
            o->rotZ = (o->localZ + 0x80) & 0xff;
        else
            o->rotZ = o->localZ;
    } else if ((u32)((o->localZ - 0x40) & 0xff) < 0x80) {
        o->animFrame = 1;
        o->rotZ = (o->localZ + 0x80) & 0xff;
    } else {
        o->animFrame = 0;
        o->rotZ = o->localZ;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BFDC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011BFF8);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C174);




static __inline__ void setAnim_1C174(GameObject *o, void *a)
{
    o->anim = a;
    readAnimFrameCount(o);
}

void func_8011C174(GameObject *o)
{
    GameObject *p;
    s32 hw;
    u8 t = o->state;

    switch (t) {
    case 0:
        o->hitboxX = 0x10;
        o->hitboxW = 0x20;
        o->hitboxH = 0x20;
        o->hitboxY = 0x10;
        o->unkB0 = 0;
        o->unkA6 = 0;
        o->unkA7 = 0;
        o->tpage = 0xe;
        o->spriteBank = SCRATCHPAD.sprData[6];
        *(s8 *)&o->priority = -12;
        o->drawFlags = 1;
        o->clut = 0x7c90;
        if (o->id & 1) o->localZ = 0x80;
        else o->localZ = 0;
        o->state++;
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
        o->touchFlag = 0;
        o->scaleX = 0;
        hw = o->h->p.whole;
        o->unkB4 = o->y.p.whole;
        o->localX = hw;
        p = allocObjectLayer3();
        if (p) {
            p->active = 2;
            p->type = 0x38;
            p->drawType = 2;
            p->rotX = 0;
            p->rotY = 0;
            p->rotZ = 0;
            p->x.p.whole = o->x.p.whole;
            p->y.p.whole = o->y.p.whole + 0x28;
            p->z.p.whole = o->z.p.whole;
            p->localX = o->h->p.whole << 16;
            p->localY = p->y.p.whole << 16;
            p->parent = (s32)o;
        }
        if (o->param & 8) {
            if (D_8009C608.unk962) {
                D_8009BC98.unk0F = 1;
                D_8009BC98.unk12 = 1;
                o->subState = 8;
                o->localZ = 0x40;
                o->step = 0;
                o->drawType = 0;
                o->unkAC = 6;
                o->y.p.whole += 0x30;
                setAnim_1C174(o, D_80138C30[0]);
            }
        }
        break;
    case 1:
        cullAndQueueDraw(o);
        { s32 k = o->id & 4;
        switch (k != 0) {
        case 0:
            func_8011BDC0(o);
            break;
        case 1:
            func_8011BFDC(o);
            break;
        }}
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer4(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C3CC);

void func_8011C3CC(GameObject *o)
{
    GameObject *p;
    s32 a, v, x;

    switch (o->state) {
    case 0:
        o->state++;
        o->tpage = 0xe;
        o->spriteBank = D_1F8002E0[0];
        *(s8 *)&o->priority = -9;
        o->drawFlags = 1;
        o->clut = 0x7c90;
        o->velH = 4;
        o->animFrame = 0;
        break;
    case 1:
        p = (GameObject *)o->parent;
        if (p->unkAC >= 5)
            break;
        if ((o->visible = p->visible) == 0)
            break;
        o->step = 0;
        o->unkAC = D_80134DD8[(p->localZ & 0xff) >> 3];
        o->anim = D_80138C34[o->unkAC];
        readAnimFrameCount(o);
        switch (o->subState) {
        case 0:
            o->velH = 0x40;
            o->subState++;
            break;
        case 1:
            o->velH += 4;
            if (o->velH == 0x80)
                o->subState++;
            break;
        case 2:
            o->velH -= 4;
            if (o->velH == 0)
                o->subState--;
            break;
        }
        a = (4 - (o->velH >> 4)) & 0xff;
        o->rotZ = a;
        if (p->unkAC != 2) {
            v = D_8007D788[(a + 0x40) & 0xff];
            o->velY = v << 2;
            x = COS_TABLE[(o->rotZ + 0x40) & 0xff];
            x <<= 2;
            o->velX = x;
            p->h->raw = o->localX + ((s16)x << 8);
            p->y.raw = o->localY + (o->velY << 8);
        }
        pushDrawListCapped(o);
        break;
    case 2:
        break;
    case 3:
        freeObjectLayer3(o);
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C648);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C678);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C730);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C75C);




void func_8011C75C(GameObject *o)
{
    switch (o->step) {
    case 0:
        ((u8*)&D_8009BC98.unk0F)[0] = 1;
        ((u8*)&D_8009BC98.unk0E)[0] = 1;
        ((u8*)&D_8009BC98.unk12)[0] = 1;
        D_800A38BB[0] = 3;
        D_800A38D0[0] = 0;
        D_1F800190 = o->y.raw;
        SCRATCHPAD.unk18C = o->h->raw;
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
            D_8009C068.unk5ae = 1;
        }
        break;
    }
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C8EC);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011C914);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CB24);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CB9C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CC08);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CCE8);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CE24);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CF50);

void func_8011CF94(void) {
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_2", func_8011CF9C);

void func_8011CF9C(GameObject *o)
{
    u8 *p;

    D_8009E454 = 0;
    if ((GAME.selectedSection == 1 || GAME.selectedSection == 5) && GAME.selectedSpawnPoint == 1) {
        o->state = 5;
        o->subState = 9;
    }
    if ((GAME.selectedSection == 0 || GAME.selectedSection == 4) && D_8009C068.event_1F != 0xff && GAME.selectedSpawnPoint == 4) {
        D_8009BC98.unk0A = 1;
        D_8009C608.playerEquips = 0;
        o->active = 1;
        o->state = 1;
        o->subState = 2;
        o->step = 3;
        o->unk7 = 0;
    }
    p = &D_8009C608.unk962;
    if (*p == 1) {
        o->active = 5;
        o->state = 5;
        o->subState = 0x40;
        o->visible = 0;
        D_8009BC98.unk0A = 1;
        *p = 2;
    }
}
