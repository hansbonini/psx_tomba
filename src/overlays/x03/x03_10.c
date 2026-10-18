#include "common.h"
#include "game.h"
#include "x03.h"

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012D124);

#define WOBBLE() \
    o->unkA7 += 2; \
    o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);

static __inline__ s16 chk2_2D124(GameObject *o)
{
    s16 r;
    if (o->animFrame & 1) r = o->x.p.whole < o->unkB6;
    else if (o->y.p.whole < -0x46a) r = o->unkB8 - 0x14 < o->x.p.whole;
    else r = o->x.p.whole > o->unkB8;
    if (r) return 1;
    return 0;
}

#define chk(o) (func_8012C9BC(o) || chk2_2D124(o))

void func_8012D124(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->velX = o->animFrame << 2;
        o->step++;
        o->timer = D_801351B8[nextRandom() & 7];
        o->unkAC = 1;
        o->anim = D_80139A50[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->animFrame) o->x.p.whole--;
        else o->x.p.whole++;
        WOBBLE();
        tickAnimation(o);
        if (--o->timer == -1) {
            o->timer = 0x3c;
            o->unkAC = 4;
            o->step++;
            o->anim = D_80139A5C[0];
            readAnimFrameCount(o);
        } else if (chk(o)) {
            o->unkB0 = 1;
            o->unkA5 = o->step;
            o->step = 4;
            o->unk7 = 0;
        }
        break;
    case 2:
        if (o->animFrame) o->x.raw += -0x8000;
        else o->x.raw += 0x8000;
        WOBBLE();
        if (chk(o)) goto hit;
        if (o->timer) o->timer--;
        if (tickAnimation(o) && o->timer == 0) {
            o->timer = 0x3c;
            o->step++;
            o->unkA6 = (o->unkA6 + 1) & 1;
        }
        break;
    case 3:
        if (o->animFrame) o->x.raw += -0x8000;
        else o->x.raw += 0x8000;
        WOBBLE();
        if (tickAnimation(o)) {
            if (*(s8 *)&o->unkA6) {
                if ((nextRandom() & 3) == 1) {
                    o->subState++;
                    o->step = 0;
                    break;
                }
            } else if (D_801351B0[nextRandom() & 7] == 1) {
                o->subState = 3;
                o->step = 0;
                o->velH = 0x80;
                break;
            }
            if (o->timer == 0) {
                o->step = 0;
                break;
            }
        }
        if (chk(o)) {
        hit:
            o->unkB0 = 4;
            o->unkA5 = o->step;
            o->step = 4;
            o->unk7 = 0;
            break;
        }
        if (o->timer) o->timer--;
        break;
    case 4:
        switch (o->unk7) {
        case 0:
            o->unk7++;
            o->unkAC = 6;
            o->anim = D_80139A64[0];
            readAnimFrameCount(o);
            break;
        case 1:
            if (tickAnimation(o)) {
                u16 w;
                s32 f;
                u8 st;
                f = 1 - o->animFrame;
                st = o->unkA5;
                w = o->unkB0;
                o->animFrame = f;
                o->velX = f << 2;
                o->unkAC = w;
                o->step = st;
                o->anim = D_80139A4C[(s16)w];
                readAnimFrameCount(o);
            }
            break;
        }
        WOBBLE();
        break;
    }
}
#undef WOBBLE
#undef chk

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012D6C8);
extern s16 isObjectPastReferenceX(GameObject *o);

static __inline__ s32 side_2D6C8(GameObject *o)
{
    u16 d = (*(u16*)((char*)&SCRATCHPAD.unk168[1].raw + 2));
    if ((u16)(d - o->y.p.whole + 0x60) < 0xc0) return 0;
    return (s16)d > o->y.p.whole ? 6 : 2;
}

void func_8012D6C8(GameObject *o)
{
    s32 r;
    s32 i;
    s16 sp;
    s32 c, s;
    s16 t;

    switch (o->step) {
    case 0:
        o->velX = o->animFrame << 2;
        t = isObjectPastReferenceX(o);
        if (o->animFrame == t) {
            o->step = 2;
            o->unkAC = 3;
        } else {
            o->unkAC = 6;
            o->step++;
        }
        o->anim = D_80139A4C[o->unkAC];
        readAnimFrameCount(o);
        break;
    case 1:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        if (tickAnimation(o)) {
            o->unkAC = 3;
            o->step++;
            o->animFrame = 1 - o->animFrame;
            o->velX = o->animFrame << 2;
            o->anim = D_80139A4C[3];
            readAnimFrameCount(o);
        }
        break;
    case 2:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        if (tickAnimation(o)) o->step++;
        break;
    case 3:
        r = side_2D6C8(o);
        if (r == 0) goto done;
        o->timer = 100;
        o->velH = 0;
        o->step++;
        if (r & 4) {
            o->unkAC = 2;
            if (o->animFrame) o->velX = 5;
            else o->velX = 7;
        } else {
            o->unkAC = 0;
            if (o->animFrame) o->velX = 3;
            else o->velX = 1;
        }
        o->anim = D_80139A4C[o->unkAC];
        readAnimFrameCount(o);
        break;
    case 4:
        tickAnimation(o);
        i = (o->velX << 5) & 0xe0;
        sp = o->velH;
        c = sp * D_8007DB88[i];
        s = sp * (s16)D_8007D988[i];
        o->x.raw += (s16)(c >> 12) << 8;
        o->y.raw += (s16)(s >> 12) << 8;
        if (func_8012C868(o)) o->timer = 0;
        o->velH += 0x20;
        if (o->velH > 0x180) o->velH = 0x180;
        if (--o->timer == -1) {
        done:
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012DA00);

static __inline__ void spawn_2DA00(GameObject *o, s32 sub)
{
    GameObject *n = allocObjectLayer2();
    if (n) {
        n->active = 2;
        n->type = 0x39;
        n->subtype = sub;
        n->unk8C = (o->velX << 5) & 0xf0;
        if (o->animFrame) n->x.p.whole = o->x.p.whole - 0xe;
        else n->x.p.whole = o->x.p.whole + 0xe;
        n->y.p.whole = o->y.p.whole;
        n->z.p.whole = o->z.p.whole;
        n->unk90 = (s32)o;
    }
}

void func_8012DA00(GameObject *o)
{
    GameObject *n;
    u32 d;
    u16 e;

    switch (o->step) {
    case 0:
        if (o->animFrame) o->velY = D_801351E0[nextRandom() & 0xf];
        else o->velY = D_801351D0[nextRandom() & 0xf];
        {
            s32 a = o->animFrame << 2;
            d = ((u16)o->velY - a) & 7;
            o->velX = a;
        }
        e = d;
        if (d != 0) {
            if (e < 4) o->velV = 1;
            else o->velV = -1;
        } else {
            o->velV = 0;
        }
        o->timer = 0x1e;
        o->cooldownTimer = 5;
        o->unkAC = 0xf;
        o->step++;
        o->anim = D_80139A88[0];
        readAnimFrameCount(o);
        break;
    case 1:
    case 4:
        if (--o->cooldownTimer == -1) {
            o->cooldownTimer = 5;
            spawn_2DA00(o, 0);
        }
        if (--o->timer == -1) {
            o->timer = 0x1e;
            if (o->velX == o->velY) {
                if (o->step == 4) {
                    o->timer = 10;
                    o->step = 5;
                } else {
                    o->cooldownTimer = 2;
                    o->timer = 0x78;
                    o->unkAC = D_801351C8[o->velX];
                    o->step++;
                }
            } else {
                o->velX = (o->velX + o->velV) & 7;
                o->unkAC = D_801351C8[o->velX];
            }
            o->anim = D_80139A4C[o->unkAC];
            readAnimFrameCount(o);
        }
        break;
    case 2:
        if (--o->cooldownTimer == -1) {
            o->cooldownTimer = 2;
            spawn_2DA00(o, 1);
        }
        if (--o->timer == -1) {
            o->timer = 0x1e;
            o->cooldownTimer = 5;
            o->step++;
        }
        break;
    case 3:
        o->step++;
        o->velY = o->animFrame << 2;
        if (o->velV) {
            if (o->velV < 0) o->velV = 1;
            else o->velV = -1;
        }
        break;
    case 5:
        if (--o->timer == -1) {
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
    tickAnimation(o);
    o->unkA7 += 2;
    o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
    o->velH -= 8;
    if (o->velH < 0x40) o->velH = 0x40;
    if (o->animFrame) o->x.raw -= o->velH << 8;
    else o->x.raw += o->velH << 8;
}

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012DE7C);

INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012E0A4);

INCLUDE_RODATA("overlays/x03/nonmatchings/x03/x03_10", func_801160A0);

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012E28C);
extern s32 probeCollisionAtDepthA(GameObject *, s32, s32);

void func_8012E28C(GameObject *o)
{
    switch (o->step) {
    case 0:
        o->unk9C = 0;
        spawnItemNotification(1, 6);
        *(s8 *)&o->unkF = -7;
        o->velV = 0x300;
        o->movetab = D_800771F0;
        o->unk68 = 0;
        o->unk8C = 0;
        o->unkAC = 0xa;
        o->step++;
        o->anim = D_80139A74[0];
        readAnimFrameCount(o);
        applyAnimVelocityX(o, *(u16 *)&o->unk7A);
        break;
    case 1:
        o->step++;
        o->velV -= 0x20;
        o->y.raw += o->velV << 8;
        if (o->touchFlag == 1 || (s16)probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) o->touchFlag = 0;
        applyAnimVelocityX(o, *(u16 *)&o->unk7A);
        break;
    case 2:
        o->step++;
        (*(GameObject *)&PLAYER).step = 2;
        *(u8 *)&(*(GameObject *)&PLAYER).unkAC = 3;
        (*(GameObject *)&PLAYER).unk9C = 0;
    case 3:
        o->velV -= 0x20;
        if (o->velV < 0) o->step++;
        o->y.raw += o->velV << 8;
        if (o->touchFlag == 1 || (s16)probeCollisionAtDepthA(o, o->h->p.whole, (s16)(o->y.p.whole + 0x10))) o->touchFlag = 0;
        tickAnimation(o);
        o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
        applyFrameVelocityX(o);
        func_8012C9BC(o);
        break;
    case 4:
        o->velV -= 0x20;
        if (o->velV < -0x300) {
            o->velV = -0x300;
            o->step++;
        }
        o->y.raw += o->velV << 8;
        func_80043D2C(o, o->h->p.whole, (s16)(o->y.p.whole - 0x20));
        tickAnimation(o);
        o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
        applyFrameVelocityX(o);
        func_8012C9BC(o);
        break;
    case 5:
        o->unkA7 += 2;
        o->y.raw += (s16)(D_8007D988[o->unkA7] << 2);
        tickAnimation(o);
        o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
        applyFrameVelocityX(o);
        func_8012C9BC(o);
        break;
    case 6:
        o->animFrame = (*(GameObject *)&PLAYER).animFrame & 1;
        o->unkAC = 0xb;
        o->step++;
        o->anim = D_80139A78[0];
        readAnimFrameCount(o);
        break;
    case 7:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012E584);

static __inline__ s16 land_2E584(GameObject *o)
{
    if (o->touchFlag == 1 || ((s16 (*)(GameObject *, s16, s16))probeCollisionAtDepthA)(o, o->h->p.whole, o->y.p.whole + 0x10)) {
        o->touchFlag = 0;
        return 1;
    }
    return 0;
}

void func_8012E584(GameObject *o)
{
    switch (o->step) {
    case 0:
        spawnItemNotification(1, 6);
        *(s8 *)&o->unkF = -7;
        o->unk68 = 0;
        o->unk8C = 0;
        o->velV = 0;
        o->unkAC = 0x1d;
        o->step++;
        o->anim = D_80139AC0[0];
        readAnimFrameCount(o);
        break;
    case 1:
        o->step++;
        o->velV += 0x20;
        if (o->velV > 0x300) o->velV = 0x300;
        o->y.raw += o->velV << 8;
        land_2E584(o);
        break;
    case 2:
        o->step++;
        PLAYER.obj.step = 2;
        (*(u8*)&PLAYER.obj.unkAC) = 3;
    case 3:
        o->velV += 0x20;
        if (o->velV > 0x300) o->velV = 0x300;
        o->y.raw += o->velV << 8;
        land_2E584(o);
        break;
    case 4:
        o->step++;
        break;
    case 5:
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012E700);
extern void applyAnimVelocityX(GameObject *, u16);

void func_8012E700(GameObject *o)
{
    s32 x;

    switch (o->step) {
    case 0:
        o->active = 2;
        o->unkB = 1;
        o->unkF = 4;
        o->unk8C = 0;
        o->animFrame = o->unk7A & 1;
        if (o->subState == 0) o->velV = 0;
        else o->velV = -0x400;
        o->movetab = ((char *)&D_8007722C);
        o->step++;
        if (o->subtype == 0) o->unkAC = 0x1c;
        else o->unkAC = 0xb;
        o->anim = D_80139A4C[o->unkAC];
        readAnimFrameCount(o);
        break;
    case 1:
        if (o->subState == 2) applyAnimVelocityX(o, 1 - o->animFrame);
        o->velV += 0x20;
        if (o->velV > 0x400) o->velV = 0x400;
        o->y.raw += o->velV << 8;
        break;
    }
    if (o->animFrame & 1) x = o->unk8C + 20;
    else x = o->unk8C - 20;
    o->unk8C = x & 0xff;
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012E874);


typedef struct { GameObject o; char pc0[0x12]; u16 wd2; } TX_2E874;
#define X(o) ((TX_2E874 *)(o))
typedef struct { s16 f0, f1, f2, f3, f4, f5; } XS_2E874;
extern void func_80023020(GameObject *);

void func_8012E874(GameObject *o)
{
    XS_2E874 *x = (XS_2E874 *)((char *)o + 0xb4);

    switch (o->state) {
    case 0:
        switch (o->subState) {
        case 0:
            o->active = 2;
            o->velH = 0;
            o->velV = 0;
            o->unkA6 = 0;
            o->velX = 0;
            o->unkA7 = 0;
            o->hitOffsetX = 8;
            o->hitWidth = 0x10;
            o->hitOffsetY = 8;
            o->hitHeight = 0x10;
            o->spriteBank = SCRATCHPAD.sprData[5];
            o->tpage = 1;
            o->unkD = 0;
            o->touchFlag = 0;
            o->unk68 = 0;
            *(s8 *)&o->unkF = -9;
            o->unk8C = 0;
            o->anim = 0;
            o->subState++;
            x->f0 = 0;
            x->f3 = o->x.p.whole;
            x->f4 = o->y.p.whole;
            x->f5 = o->z.p.whole;
            x->f1 = 0x5f3;
            x->f2 = 0x9f6;
            break;
        case 1:
            if (D_8009BC98.unk12 == 0) {
                func_8012CA90(o);
            }
            break;
        }
        break;
    case 1:
        if (D_8009BC98.unk12) {
            func_80022E44(o);
            break;
        }
        func_80022E44(o);
        if (o->unk9E == 0) {
            switch (o->subtype) {
            case 0:
                switch (o->subState) {
                case 0:
                    func_8012CC64(o);
                    break;
                case 1:
                    func_8012CDB8(o);
                    break;
                }
                break;
            case 1:
                switch (o->subState) {
                case 0:
                    func_8012CFFC(o);
                    break;
                case 1:
                    func_8012D124(o);
                    break;
                case 2:
                    func_8012D6C8(o);
                    break;
                case 3:
                    func_8012DA00(o);
                    break;
                }
                break;
            }
            if (((SCRATCHPAD.unk1F8 + SCRATCHPAD.unk198) & 0xf) == 0) {
                func_80023020(o);
            }
            o->unk9D = 0;
            break;
        } else if (o->unk9F == 0) {
            X(o)->wd2 = o->h->p.whole;
            o->unk9F = 0xf;
        } else {
            { s32 r = nextRandom() & 3; s32 w = X(o)->wd2 - 2; o->h->p.whole = w + r; }
            if (--o->unk9F == 0) {
                o->unk9E = 0;
                o->h->p.whole = X(o)->wd2;
            }
        }
        o->unk9D = 0;
        break;
    case 2:
        if (D_8009BC98.unk12) {
            func_80022E44(o);
            break;
        }
        switch (o->subtype) {
        case 0:
            switch (o->subState) {
            case 1:
                func_8012E584(o);
                func_80022E44(o);
                break;
            case 0:
            case 2:
                func_8012E700(o);
                if (!func_80022E44(o)) {
                    o->state = 3;
                }
                break;
            }
            break;
        case 1:
            switch (o->subState) {
            case 0:
                func_8012DE7C(o);
                func_80022E44(o);
                break;
            case 1:
                func_8012E28C(o);
                func_80022E44(o);
                break;
            case 2:
                func_8012E700(o);
                if (!func_80022E44(o)) {
                    o->state = 3;
                }
                break;
            }
            break;
        }
        break;
    case 3:
        o->timer = 600;
        o->unkB = 0;
        *(s8 *)&o->unkF = -9;
        o->unk8C = 0;
        o->state++;
        break;
    case 4:
        if (--o->timer == -1) {
            x->f0 = 0;
            o->velH = 0;
            o->velV = 0;
            o->velX = 0;
            o->unkA7 = 0;
            o->x.p.whole = x->f3;
            o->y.p.whole = x->f4;
            o->z.p.whole = x->f5;
            o->state = 0;
            o->subState = 1;
            o->step = 0;
            o->unk7 = 0;
        }
        break;
    }
}
#undef X

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012ECF0);

void func_8012ECF0(GameObject *o)
{
    GameObject *p;
    s8 *t;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 8;
        o->hitWidth = 0x10;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->animFrame = 1;
        o->tpage = 1;
        o->state++;
        o->spriteBank = SCRATCHPAD.sprData[5];
        *(s8 *)&o->unkF = -10;
        o->unkD = 0x80;
        o->unkA = 0;
        o->unk30 = 0;
        o->unk34 = 0;
        if (o->subtype == 0) {
            o->velH = 0x80;
            o->unkAC = 0x19;
        } else {
            o->active = 1;
            o->velH = 0x480;
            o->unkAC = 0x12;
        }
        o->anim = D_80139A4C[o->unkAC];
        readAnimFrameCount(o);
        break;
    case 1:
        p = (GameObject *)o->unk90;
        if (p->animFrame) t = D_80135200 + ((o->unk8C >> 4) & 0xe);
        else t = D_801351F0 + ((o->unk8C >> 4) & 0xe);
        {
            s32 i, x, y, tx, ty;
            i = o->unk8C & 0xf0;
            x = o->velH * D_8007DB88[i];
            y = o->velH * D_8007D988[i];
            tx = t[0] << 16;
            ty = t[1] << 16;
            o->unk30 += x >> 4;
            o->unk34 += y >> 4;
            o->x.raw = p->x.raw + o->unk30 + tx;
            o->y.raw = p->y.raw + o->unk34 + ty;
        }
        if (tickAnimation(o)) o->state++;
        func_80022E44(o);
        break;
    case 2:
    case 3:
        freeObjectLayer2(o);
        break;
    }
}

// INCLUDE_ASM("overlays/x03/nonmatchings/x03/x03_10", func_8012EF14);


void func_8012EF14(GameObject *o)
{
    u8 b = o->state;

    switch (b) {
    case 0:
        o->state = b + 1;
        o->tpage = 1;
        o->spriteBank = SCRATCHPAD.sprData[5];
        *(s8 *)&o->unkF = -0xb;
        o->unkD = 0x80;
        o->unkAC = 0x1b;
        o->anim = D_80139AB8[0];
        readAnimFrameCount(o);
        break;
    case 1:
        if (tickAnimation(o))
            o->state++;
        func_80022E44(o);
        break;
    case 2:
    case 3:
        freeObjectLayer3(o);
        break;
    }
}
