#include "common.h"
#include "game.h"
#include "x01.h"

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80137888);
typedef struct { s16 z, y, x; } P3_37888;

extern P3_37888 D_8013BD24[];
extern s32 fixedMulSin(s32, s32);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);

void func_80137888(GameObject *o)
{
    s32 s1;
    s32 s2;
    s32 b;

    switch (o->state) {
    case 0:
        o->active = 2;
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->objectIndex = 1;
        o->x.raw = D_8013BD24[o->unkC].x << 16;
        o->y.raw = D_8013BD24[o->unkC].y << 16;
        o->z.raw = D_8013BD24[o->unkC].z << 16;
        o->tpage = 7;
        *(s8 *)&o->unkF = -9;
        o->unkD = 0x80;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->spriteBank = D_1F8002D4[0];
        o->anim = D_8013DA88;
        readAnimFrameCount(o);
        o->timer = (nextRandom() & 0xff) + 1;
        o->subState = 0;
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        switch (o->subState) {
        case 0:
            if (--o->timer == 0) {
                o->anim = D_8013DA88_VoidPtrArr[1];
                readAnimFrameCount(o);
                o->unk6A = 0;
                o->active = 1;
                o->subState++;
            }
            break;
        case 1:
            if (tickAnimation(o)) {
                o->anim = D_8013DA88_VoidPtrArr[5];
                o->y.p.whole += 0x18;
                readAnimFrameCount(o);
                o->velY = 0;
                o->unk8C = 0;
                o->subState++;
            }
            break;
        case 2:
            if (o->velY < 0x600) o->velY += 0x20;
            applyObjectAltSpeedVertical(o);
            if (o->unk6A && !PLAYER.obj.touchFlag && (*(u8*)&PLAYER.obj.unkAC) < 2 && PLAYER.obj.unk9C && (u8)(PLAYER.obj.unk9E - 5) >= 2)
                PLAYER.obj.y.raw += o->velY << 8;
            if (o->touchFlag) {
                o->anim = D_8013DA88_VoidPtrArr[2];
                readAnimFrameCount(o);
                o->touchFlag = 0;
                o->subState++;
            } else if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 8)) {
                o->unk8C = 0;
                o->active = 2;
                o->anim = D_8013DA88_VoidPtrArr[6];
                readAnimFrameCount(o);
                o->velY = 0;
                o->subState = 6;
            }
            break;
        case 3:
            if (o->touchFlag) {
                o->touchFlag = 0;
                if ((u32)((o->unk8C + 0x40) & 0xff) >= 0x81) {
                    o->anim = D_8013DA88_VoidPtrArr[4];
                    readAnimFrameCount(o);
                    o->cooldownTimer = 4;
                    o->subState++;
                }
                s1 = (o->unk8C + 4) & 0x7f;
                if ((u32)s1 < 8) {
                    if (o->unk6A) {
                        if (tickAnimation(o)) {
                            o->anim = D_8013DA88_VoidPtrArr[9];
                            readAnimFrameCount(o);
                        }
                    } else {
                        o->anim = D_8013DA88_VoidPtrArr[2];
                    }
                } else {
                    s1 = o->unk8C;
                    if (s1 < 0x80) {
                        s1 += 0x80;
                        o->animFrame = 1;
                    } else {
                        o->animFrame = 0;
                    }
                    s1 &= 0xff;
                    s2 = -(s16)fixedMulSin((o->unk8C << 1) & 0x7e, 0x300);
                    b = (s16)fixedMulSin(o->unk8C & 0x7f, 0x400);
                    o->h->raw += (D_8007DB88[s1] * s2) >> 4;
                    o->y.raw += (D_8007D788[s1] * -b) >> 4;
                    if (o->unk6A) {
                        if ((u8)(PLAYER.obj.unk9E - 5) >= 2) {
                            (*(Fix16 **)&PLAYER.obj.h)->raw += (D_8007DB88[s1] * s2) >> 4;
                            PLAYER.obj.y.raw += (D_8007D788[s1] * -b) >> 4;
                        }
                        if (tickAnimation(o)) {
                            o->anim = D_8013DA88_VoidPtrArr[10];
                            readAnimFrameCount(o);
                        }
                    } else {
                        o->anim = D_8013DA88_VoidPtrArr[3];
                    }
                    o->y.p.whole += 2;
                }
                readAnimFrameCount(o);
            } else {
                o->anim = D_8013DA88_VoidPtrArr[4];
                readAnimFrameCount(o);
                o->cooldownTimer = 4;
                o->subState++;
            }
            break;
        case 4:
            if (--o->cooldownTimer == 0) {
                o->anim = D_8013DA88_VoidPtrArr[5];
                readAnimFrameCount(o);
                o->unk6A = 0;
                o->velY = 0;
                o->unk8C = 0;
                o->subState = 2;
            }
            break;
        case 5:
            o->unk8C = 0;
            o->active = 2;
            o->anim = D_8013DA88_VoidPtrArr[6];
            readAnimFrameCount(o);
            o->velY = 0;
            o->subState++;
        case 6:
            if (tickAnimation(o)) {
                o->x.raw = D_8013BD24[o->unkC].x << 16;
                o->y.raw = D_8013BD24[o->unkC].y << 16;
                o->z.raw = D_8013BD24[o->unkC].z << 16;
                o->unk8C = 0;
                o->anim = D_8013DA88;
                readAnimFrameCount(o);
                o->timer = (nextRandom() & 0xff) + 1;
                o->subState = 0;
            }
            break;
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

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80137F84);


void func_80137F84(GameObject *o)
{
    u8 s = o->state;
    switch (s) {
    case 0:
        o->active = 2;
        o->tpage = 7;
        *(s8 *)&o->unkF = -9;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkD = 0x80;
        o->spriteBank = SCRATCHPAD.sprData[3];
        o->anim = D_8013DAA4[0];
        readAnimFrameCount(o);
        o->state++;
        break;
    case 1:
        func_80022E44(o);
        if (tickAnimation(o)) o->state++;
        break;
    case 2:
        o->state = s + 1;
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x01/nonmatchings/x01/x01_8", func_80138084);

void func_80138084(GameObject *o)
{
    switch (o->subtype) {
    case 0:
        func_80137888(o);
        break;
    case 1:
        switch (o->state) {
        case 0:
            o->active = 2;
            o->tpage = 7;
            *(s8 *)&o->unkF = -9;
            o->unk84 = 0;
            o->unk88 = 0;
            o->unk8C = 0;
            o->unkD = 0x80;
            o->spriteBank = SCRATCHPAD.sprData[3];
            o->anim = D_8013DAA4[0];
            readAnimFrameCount(o);
            o->state++;
            break;
        case 1:
            func_80022E44(o);
            if (tickAnimation(o) != 0) {
                o->state++;
            }
            break;
        case 2:
            o->state++;
            break;
        case 3:
            freeObjectLayer2(o);
            break;
        }
        break;
    }
}
