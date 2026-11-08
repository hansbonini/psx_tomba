#include "common.h"
#include "game.h"

// INCLUDE_ASM("nonmatchings/main/game/inventory2", func_8002DA2C);
extern s32 WMD_DATA;
extern void (*D_8007C640[])(char *, s32);

void func_8002DA2C(void)
{
    u16 v, x;
    D_800B00FB = 0;
    switch (GAME.selectedArea) {
    case 0:
        break;
    case 0xd:
        if (D_8009BCCA != 0) return;
        break;
    case 2:
        x = D_8009BCCA;
        v = 3;
        goto cmp;
    case 6:
        if (D_8009BCCA > 1) return;
        break;
    case 9:
        x = D_8009BCCA;
        if (x == 0) break;
        v = 6;
        goto cmp;
    case 0x12:
        x = D_8009BCCA;
        v = 1;
    cmp:
        if (x != v) return;
        break;
    case 5: case 8: case 0xb: case 0x10: case 0x11: case 0x13:
        return;
    }
    D_8007C640[GAME.selectedArea](D_800B00F8, WMD_DATA);
    D_800B00F9 = D_8009C10A;
}

// INCLUDE_ASM("nonmatchings/main/game/inventory2", stubInventory1);
void stubInventory1(void) {
}

// INCLUDE_ASM("nonmatchings/main/game/inventory2", updateModelObjects);
void updateModelObjects(void)
{
    u8* p = &D_800B0B88;

    D_1F800198 = 0;
    do {
        if (p[0] != 0) {
            D_8007C68C[p[2]](p);
        }
        D_1F800198 = D_1F800198 + 1;
        p += 0xD4;
    } while (D_1F800198 < 0x2D);
}

// INCLUDE_ASM("nonmatchings/main/game/inventory2", stubInventory2);
void stubInventory2(void) {
}

// INCLUDE_ASM("nonmatchings/main/game/inventory2", func_8002DBD8);
typedef struct {
    /* 0x00 */ u8 active;
    /* 0x01 */ u8 visible;
    /* 0x02 */ u8 type;
    /* 0x03 */ u8 subtype;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 subState;
    /* 0x06 */ u8 pad06[4];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 pad0B[5];
    /* 0x10 */ Fix16 x;
    /* 0x14 */ Fix16 y;
    /* 0x18 */ Fix16 z;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ s16 timer;
    /* 0x22 */ u8 pad22[0xE];
    /* 0x30 */ Fix16 posX;
    /* 0x34 */ Fix16 posY;
    /* 0x38 */ Fix16 posZ;
    /* 0x3C */ u8 pad3C[0x30];
    /* 0x6C */ u16 uv[4];
    /* 0x74 */ u8 pad74[0xA];
    /* 0x7E */ s16 velY;
    /* 0x80 */ s16 velX;
    /* 0x82 */ s16 velZ;
    /* 0x84 */ s32 rotX;
    /* 0x88 */ s32 rotY;
    /* 0x8C */ s32 rotZ;
    /* 0x90 */ u8 pad90[0x14];
    /* 0xA4 */ u8 unkA4;
    /* 0xA5 */ u8 padA5[0xF];
    /* 0xB4 */ s16 phaseA;
    /* 0xB6 */ s16 stepA;
    /* 0xB8 */ s16 phaseB;
    /* 0xBA */ s16 stepB;
    /* 0xBC */ u16 spriteId;
    /* 0xBE */ u16 slot;
    /* 0xC0 */ u16 spriteId2;
    /* 0xC2 */ s16 slot2;
    /* 0xC4 */ s16 destX;
    /* 0xC6 */ s16 destY;
    /* 0xC8 */ s16 homeX;
    /* 0xCA */ s16 homeY;
    /* 0xCC */ u16 unkCC;
    /* 0xCE */ u16 cmd;
    /* 0xD0 */ u16 flagD0;
    /* 0xD2 */ u16 eventId;
} PopupIcon;

#if REGION == REGION_EU
void func_8002DBD8(PopupIcon *o)
{
    s32 u0, v0, u1, v1;
    s16 s;

    switch (o->state) {
    case 0:
        o->unkA = 0x14;
        o->unkA4 = 1;
        o->slot2 = acquireSpriteSlot(o->spriteId2);
        if (o->active == 1) {
            o->slot = s = acquireSpriteSlot(o->spriteId);
            u0 = SPRITE_SLOTS[s].val[0] * 4;
            v0 = SPRITE_SLOTS[s].val[1] << 8;
            u1 = u0 + SPRITE_SLOTS[s].val[2];
            v1 = v0 + (SPRITE_SLOTS[s].val[3] << 8);
            o->uv[1] = u0 | v0;
            o->uv[3] = v0 | u1;
            o->uv[0] = u0 | v1;
            o->uv[2] = u1 | v1;
        }
        o->state++;
        break;
    case 1:
        if (D_8009C10A != 1) {
            func_8002DEC4(o);
        }
        if (o->active & 1) {
            o->visible = 1;
            pushModelDrawList(o);
        }
        break;
    case 2:
        if (o->active == 1) {
            if (--SPRITE_SLOTS[o->slot].refCount == 0) {
                SPRITE_SLOTS[o->slot].id = -1;
            }
        }
        if (D_8009C618[0] != 3) {
            if (o->cmd & 0x7FFF) {
                if (o->eventId != 0) {
                    setEventStarted(o->eventId, 0, 3);
                }
                if ((o->cmd & 0x7FFF) == 2) break;
                if (o->flagD0 == 0 || (o->cmd & 0x7FFF) == 3) {
                    D_8009BCA7_U8Arr[0] = 0;
                    D_8009BCAA_U8Arr[0] = 0;
                    if ((o->cmd & 0x7FFF) != 4 && (D_800A5436[0] == 0 || D_800A5444[0] < 2)) {
                        D_800A539C = 1;
                        D_800A539D = 0;
                        D_800A539E = 0;
                        D_800A539F = 0;
                    } else {
                        D_8009BCA6 = 0;
                    }
                }
            }
            if ((o->cmd & 0x8000) && (o->cmd & 0x7FFF) != 2) {
                D_8009BC9B = 0;
            }
        }
        o->state++;
        break;
    case 3:
        freeModelObject(o);
        break;
    }
}
#else
void func_8002DBD8(PopupIcon *o)
{
    s32 state = o->state;
    s32 u0, v0, u1, v1;
    s16 s;

    switch (state) {
    case 0:
        o->unkA = 0x14;
        o->unkA4 = 1;
        o->slot2 = acquireSpriteSlot(o->spriteId2);
        o->slot = s = acquireSpriteSlot(o->spriteId);
        u0 = SPRITE_SLOTS[s].val[0] * 4;
        v0 = SPRITE_SLOTS[s].val[1] << 8;
        u1 = u0 + SPRITE_SLOTS[s].val[2];
        v1 = v0 + (SPRITE_SLOTS[s].val[3] << 8);
        o->uv[1] = u0 | v0;
        o->uv[3] = v0 | u1;
        o->uv[0] = u0 | v1;
        o->uv[2] = u1 | v1;
        o->state++;
        break;
    case 1:
        if (D_8009C10A != state) {
            func_8002DEC4(o);
        }
        o->visible = 1;
        pushModelDrawList(o);
        break;
#if REGION == REGION_JP
    case 2:
        D_8009BC98.unk03 = 0;
        if (--SPRITE_SLOTS[o->slot].refCount == 0) {
            SPRITE_SLOTS[o->slot].id = -1;
        }
        if (o->cmd != 0) {
            if (o->eventId != 0) {
                setEventStarted(o->eventId, 0, 3);
            }
            if (o->cmd == state) break;
            if (o->flagD0 == 0 || o->cmd == 3) {
                D_8009BCA7_U8Arr[0] = 0;
                D_8009BCAA_U8Arr[0] = 0;
                if (D_800A5436[0] == 0 || D_800A5444[0] < 2) {
                    D_800A539C = 1;
                    D_800A539D = 0;
                    D_800A539E = 0;
                    D_800A539F = 0;
                } else {
                    D_8009BCA6 = 0;
                }
            }
        }
#else
    case 2:
        if (--SPRITE_SLOTS[o->slot].refCount == 0) {
            SPRITE_SLOTS[o->slot].id = -1;
        }
        if (D_8009C618[0] != 3) {
            if (o->cmd & 0x7FFF) {
                if (o->eventId != 0) {
                    setEventStarted(o->eventId, 0, 3);
                }
                if ((o->cmd & 0x7FFF) == state) break;
                if (o->flagD0 == 0 || (o->cmd & 0x7FFF) == 3) {
                    D_8009BCA7_U8Arr[0] = 0;
                    D_8009BCAA_U8Arr[0] = 0;
                    if ((o->cmd & 0x7FFF) != 4 && (D_800A5436[0] == 0 || D_800A5444[0] < 2)) {
                        D_800A539C = 1;
                        D_800A539D = 0;
                        D_800A539E = 0;
                        D_800A539F = 0;
                    } else {
                        D_8009BCA6 = 0;
                    }
                }
            }
            if ((o->cmd & 0x8000) && (o->cmd & 0x7FFF) != 2) {
                D_8009BC9B = 0;
            }
        }
#endif
        o->state++;
        break;
    case 3:
        freeModelObject(o);
        break;
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory2", func_8002DEC4);
void func_8002DEC4(PopupIcon *o)
{
    s32 done;
    s32 u0, v0;
    char first;
    s32 u1, v1;
    s32 dx;
    s32 yy;
    s32 px, py;
    s32 t;

    switch (o->subState) {
    case 0:
        o->rotX = 0;
        o->rotY = 0;
        o->rotZ = 0;
        o->subState++;
        break;
    case 1:
        done = --o->timer == 0;
        if (done) {
#if REGION == REGION_EU
            if (o->active == 1) {
                dx = o->x.p.whole - 0xA0;
                px = (o->destX - dx) << 8;
                o->velX = px / 30;
                yy = o->y.p.whole + 0x78;
                dx = yy;
                px = (o->destY - dx) << 8;
                o->velZ = px / 30;
            } else {
                o->velX = 0;
                o->velZ = 0;
            }
            o->velY = -0x800;
            o->subState++;
            o->timer = 30;
#else
            o->velY = -0x800;
            o->subState++;
            o->timer = 30;
            dx = o->x.p.whole - 0xA0;
            px = (o->destX - dx) << 8;
            o->velX = px / 30;
            yy = o->y.p.whole + 0x78;
            dx = yy;
            px = (o->destY - dx) << 8;
            o->velZ = px / 30;
#endif
        }
        break;
    case 2:
        o->posX.raw += o->velX << 8;
        o->posY.raw += o->velZ << 8;
        o->posY.raw += o->velY << 8;
        o->velY += 0x88;
        if (--o->timer == 0) {
            first = o->subtype == 0;
            o->timer = first ? 0xB4 : 0x5A;
            o->phaseA = 0;
            o->stepA = (nextRandom() & 3) + 3;
            o->phaseB = 0;
            o->stepB = (nextRandom() & 7) + 3;
            o->subState++;
        }
        break;
    case 3:
        if (o->subtype == 0) {
            o->posY.raw = ((u16)o->destY + (s16)fixedMulSin(o->phaseA, 4)) << 16;
        }
        o->rotZ = (s16)fixedMulSin(o->phaseB, 0x80);
        o->phaseA += o->stepA;
        o->phaseB += o->stepB;
        o->phaseA &= 0xFF;
        o->phaseB &= 0xFF;
        if (--o->timer == 0) {
            o->rotZ = 0;
            if (o->subtype == 0) {
                o->subState++;
            } else {
                o->timer = 1;
                o->subState = 5;
            }
        }
        break;
    case 4:
        o->posX.raw += 0x80000;
        if (o->posX.raw > 0x1400000) {
            o->state++;
        }
        break;
    case 5:
        if (--o->timer == 0) {
            o->timer = 30;
            o->rotX = 0;
            o->subState++;
        }
        break;
    case 6:
#if REGION != REGION_JP
        o->posX.raw += (((u16)o->homeX << 16) - o->posX.raw) >> NTSC_PAL(3, 2);
        o->posY.raw += (((u16)o->homeY << 16) - o->posY.raw) >> NTSC_PAL(3, 2);
#endif
        o->rotX += 0x40;
        if (o->rotX >= 0x400) {
            if (o->unkCC >= 0x80) {
                u0 = SPRITE_SLOTS[o->slot2].val[0] * 4;
                v0 = SPRITE_SLOTS[o->slot2].val[1] << 8;
                u1 = u0 + SPRITE_SLOTS[o->slot2].val[2];
                v1 = v0 + (SPRITE_SLOTS[o->slot2].val[3] << 8);
                o->rotX = 0xC00;
                o->subState++;
#if REGION == REGION_EU
                o->active = 1;
#endif
                o->uv[1] = u0 | v0;
                o->uv[3] = v0 | u1;
                o->uv[0] = u0 | v1;
                o->uv[2] = u1 | v1;
            } else {
                o->state++;
            }
        }
        break;
    case 7:
        o->rotX += 0x40;
        if (o->rotX == 0x1000) {
            o->timer = (nextRandom() & 0x1F) + 0x5A;
            o->subState++;
        }
    case 8:
        if (--o->timer == 0) {
            o->stepA = (nextRandom() & 0x7F) - 0x40;
            o->stepB = (nextRandom() & 0x7F) - 0x40;
            o->phaseB = (nextRandom() & 0x7F) - 0x40;
            o->velY = nextRandom() & 0x13;
            o->subState++;
        }
        break;
    case 9:
        o->rotX = (o->rotX + (u16)o->stepA) & 0xFFF;
        o->rotY = (o->rotY + (u16)o->stepB) & 0xFFF;
        o->rotZ = (o->rotZ + (u16)o->phaseB) & 0xFFF;
        o->velY += 2;
        o->posY.raw += o->velY << 12;
        if (o->posY.raw > 0x1100000) {
            o->state++;
        }
        break;
    }
    t = o->posX.p.whole + 0xA0;
    o->x.p.whole = t;
    py = o->posZ.p.whole;
    o->z.p.whole = py;
    t = o->posY.p.whole - 0x78;
    o->y.p.whole = t;
}

#if REGION != REGION_JP
// INCLUDE_ASM("nonmatchings/main/game/inventory2", stubInventory3);
void stubInventory3(void) {
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory2", spawnItemPickupObject);
void spawnItemPickupObject(u8 arg0)
{
    u8* p;

    if (D_8009BCBC == 0) {
        p = allocEffectObject();
        if (p != NULL) {
            p[0] = 1;
            p[2] = 0xD;
            p[0xC] = arg0;
        }
    }
}

#if REGION != REGION_JP
// INCLUDE_ASM("nonmatchings/main/game/inventory2", cloneItemPickupObject);
void cloneItemPickupObject(u8* src)
{
    u8* p = allocEffectObject();

    if (p != NULL) {
        p[0] = 1;
        p[2] = 0xD;
        p[3] = 1;
        p[0xC] = src[2];
        p[0xF] = src[0xF] - 1;
        *(u8**)(p + 0x90) = src;
        *(u16*)(p + 0x12) = *(u16*)(src + 0x12);
        *(u16*)(p + 0x16) = *(u16*)(src + 0x16);
        *(u16*)(p + 0x1A) = *(u16*)(src + 0x1A);
        *(u16*)(p + 0xAC) = *(u16*)(src + 0xAC);
    }
}
#endif

// INCLUDE_ASM("nonmatchings/main/game/inventory2", updateItemGetIcon);
static inline void initHeldItemIcon(GameObject *obj)
{
    obj->tpage = 0x14;
    obj->drawFlags = 1;
    obj->clut = 0x7ED7;
    obj->animFrame = 0;
    obj->anim = *(void **)D_800123CC;
    obj->spriteBank = D_1F8002D8[0];
    obj->state++;
    obj->timer = 0x78;
    readAnimFrameCount(obj);
}

extern s32 D_8009BCBC_Arr[] asm("D_8009BCBC");

void updateItemGetIcon(GameObject *o)
{
    GameObject *owner;
    s32 dx, dy;
    s32 st;
    u8 state = o->state;

    switch (state) {
    case 0:
#if REGION != REGION_JP
        if (o->id != 0) {
            {
                register GameObject *self = o;
                initHeldItemIcon(self);
            }
            break;
        }
#endif
        D_8009BCBC_Arr[0] = 1;
        o->tpage = 0x15;
        *(s8 *)&o->priority = -9;
        o->animFrame = 0;
        o->state++;
        o->animFrame = 1;
        o->drawFlags = 0;
        o->drawType = DRAW_SPRITE;
        o->anim = *D_8007C838[o->param];
        o->spriteBank = D_1F8002D8[0];
        o->x.p.whole = SCRATCHPAD.cameraTarget.x.p.whole;
        o->y.p.whole = D_1F80016E_U16Arr[0] - 0x1E;
        o->z.p.whole = D_1F800172[0];
        if (GAME.selectedArea == 2 && (D_8009BCCA == 0 || D_8009BCCA == 3)) {
            o->velV = -0x3E0;
#if REGION != REGION_JP
            *(s8 *)&o->priority = -0x12;
#endif
        } else {
            o->velV = -0x380;
#if REGION != REGION_JP
            *(s8 *)&o->priority = -9;
#endif
        }
        o->timer = 0x78;
        o->localY = 0;
        readAnimFrameCount(o);
        playSFX(0x1A);
        break;
    case 1:
#if REGION != REGION_JP
        if (o->id != 0) {
            owner = (GameObject *)o->parent;
            if (*(u16 *)&owner->state == 2) {
                switch (o->param) {
                case 0x0:
                    if (owner->unkAC != 0xF) o->state = 3;
                    dx = 0;
                    dy = -0x10;
                    break;
                case 0x2:
                    dx = 0;
                    dy = 0;
                    st = owner->step;
                    if (st != 4) {
                        if (st < 4) goto fail;
                        if (st >= 8) goto fail;
                        dy = -0x26;
                        break;
                    }
                    dx = (owner->animFrame & 1) ? -0xC : 0xC;
                    dy = -0x10;
                    break;
                case 0x8:
                    dx = 0;
                    dy = -0x20;
                    break;
                case 0x1E:
                    dx = (owner->animFrame & 1) ? -0xC : 0xC;
                    dy = -0x1C;
                    break;
                case 0x13:
                    dx = 0;
                    dy = -0x10;
                    break;
                case 0x38:
                    st = owner->step;
                    if (st < 3) goto fail;
                    if (st < 6) goto twenty;
                    if (st == 6) goto twelve;
                    goto fail;
                twenty:
                    dx = (owner->animFrame & 1) ? -0x14 : 0x14;
                    dy = -0x10;
                    break;
                twelve:
                    dx = (owner->animFrame & 1) ? -0xC : 0xC;
                    dy = -0x18;
                    break;
                fail:
                    o->state = 3;
                    break;
                }
                o->h->p.whole = owner->h->p.whole + dx;
                o->y.p.whole = owner->y.p.whole + dy;
                o->d->p.whole = owner->d->p.whole;
                if (D_8009BCAA_U8Arr[0] == 0) {
                    tickAnimation(o);
                }
                if (o->state == 1) {
                    cullAndQueueDraw(o);
                }
            } else {
                o->state = 3;
            }
            break;
        }
#endif
        o->visible = 1;
        pushEffectDrawList(o);
        switch (o->subState) {
        case 0:
            o->velV += 0x20;
            if (o->velV >= 0x101) {
                o->subState++;
            }
            o->localY += o->velV << 8;
            break;
        case 1:
            if (--o->timer == -1) {
                o->state++;
            }
            break;
        }
        o->x.p.whole = SCRATCHPAD.cameraTarget.x.p.whole;
        o->y.raw = D_1F80016C_S32Arr[0] + o->localY;
        o->z.p.whole = D_1F800172[0];
        break;
    case 2:
        D_8009BCBC = 0;
        o->state++;
        break;
    case 3:
        freeEffectObject(o);
        break;
    }
}
