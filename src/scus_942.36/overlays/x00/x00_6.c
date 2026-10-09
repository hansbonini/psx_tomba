#include "common.h"
#include "game.h"

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E0A4);
typedef struct {
    s16 p0, x, p4, y, p8, z;
} Pos8012ED60_2E0A4;

extern u8 D_8009C3E3;
extern u16 D_8013854C[];
extern u8 D_800A53A7;
extern s32 D_8009BCEC;
extern void func_80122EA8(Pos8012ED60_2E0A4 *);
extern void func_8012E4F8(GameObject *);
extern void func_8012EE80(GameObject *);
extern void func_8012F1DC(GameObject *);
extern void func_8012F5E4(GameObject *);
extern void freeObjectLayer2(GameObject *);

static __inline__ s32 nearObj_2E0A4(GameObject *o, GameObject *p)
{
    if (p == 0) return 0;
    if ((u16)(o->d->p.whole - p->d->p.whole + 45) >= 91) return 0;
    if ((u16)(o->y.p.whole - p->y.p.whole + 126) >= 253) return 0;
    return (u16)(o->h->p.whole - p->h->p.whole + 16) < 33;
}

static __inline__ s32 nearCam_2E0A4(GameObject *o)
{
    s16 dv;
    if ((u16)(o->d->p.whole - *(u16 *)0x1F800172 + 45) >= 91) return 0;
    dv = *(u16 *)0x1F80016E - o->y.p.whole;
    if (dv >= -31 || (u16)(dv + 172) >= 173) return 0;
    return (u16)(o->h->p.whole - *(u16 *)0x1F80016A + 16) < 33;
}

void func_8012E0A4(GameObject *o)
{
    extern void func_8012E6C4(GameObject *);
    extern void *D_8013A56C[];
    extern GameObject *D_8009BCB0;
    Pos8012ED60_2E0A4 s;
    u16 *b;
    s32 r;

    switch (o->state) {
    case 0:
        o->tpage = 12;
        if (o->unkC == 1) {
            if (D_8009C3E3 == 2) {
                o->state = 3;
                break;
            }
            if (D_8009C3E3 == 1) {
                if (o->subtype != 0) {
                    o->state = 3;
                    break;
                }
                s.x = o->h->p.whole;
                s.y = o->y.p.whole - 16;
                s.z = o->d->p.whole;
                func_80122EA8(&s);
                o->state = 3;
                break;
            }
        }
        o->animFrame = 1;
        o->unkD = 0;
        o->unkA = 2;
        o->anim = D_8013A56C[o->subtype];
        b = &D_8013854C[o->subtype * 4];
        o->spriteBank = ((struct { char pad[0x2d4]; s32 v; } *)0x1F800000)->v;
        o->hitOffsetX = *b++;
        o->hitWidth = *b++;
        o->hitOffsetY = b[0];
        o->hitHeight = b[1];
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->objectIndex = 0;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->unk68 = 0;
        o->subState = 0;
        o->step = 0;
        o->unk34 = o->y.p.whole;
        o->state++;
        switch (o->subtype) {
        case 0:
            o->unk7A = 2;
            break;
        case 1:
            o->unk7A = -2;
            break;
        case 2:
            o->unk7A = -1;
            o->active = 2;
            break;
        }
        break;
    case 1:
        o->unkF = D_800A53A7 + *(u8 *)&o->unk7A;
        if (func_80022E44(o)) {
            if (o->subState == 0) {
                if (o->unkC == 1 && nearObj_2E0A4(o, D_8009BCB0)) {
                    o->subState = 1;
                    o->step = 0;
                    goto sw;
                }
                r = nearCam_2E0A4(o);
                if (r) {
                    if (!(D_8009BCEC & 2) && (*(u8 *)&PLAYER) == 1) {
                        o->subState = 1;
                        o->step = 0;
                    }
                } else if (o->unk68) {
                    o->subState = 2;
                    o->step = 0;
                }
            }
sw:
            switch (o->subState) {
            case 0:
                func_8012E4F8(o);
                break;
            case 1:
                func_8012E6C4(o);
                break;
            case 2:
                func_8012EE80(o);
                break;
            case 3:
                func_8012F1DC(o);
                break;
            case 4:
                func_8012F5E4(o);
                break;
            }
            o->unk68 = 0;
            o->touchFlag = 0;
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

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E4F8);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E56C);
typedef struct O_2E56C {
    char p0[6]; u8 state; char p1[0x19]; s16 timer; char p2[0x5a];
    s16 velX; u16 velY; s16 velH; char p3[0xa]; s32 d8c;
} O_2E56C;
static __inline__ void body_2E56C(O_2E56C *o)
{
    s16 s;
    u8 t;
    switch (o->state) {
    case 0:
        o->velH = 0x80;
        o->velX = 4;
        o->d8c = 0;
        o->velY = 0;
        o->timer = 1 - *((u8 *)o + 0x6b);
        o->state++;
        break;
    case 1:
        s = o->velH - o->velX;
        o->velH = s;
        if (o->timer != 0)
            s = o->velY - s;
        else
            s = o->velY + s;
        o->velY = s;
        o->d8c = *(volatile u16 *)&o->velY >> 8;
        if (o->velH < 1) {
            o->velH = 0;
            o->state = o->state + 1;
        }
        break;
    case 2:
        s = o->velH + o->velX;
        o->velH = s;
        if (o->timer != 0)
            s = o->velY + s;
        else
            s = o->velY - s;
        o->velY = s;
        o->d8c = *(volatile u16 *)&o->velY >> 8;
        if (o->velH >= 0x80) {
            o->velH = 0x80;
            o->state = o->state - 1;
            o->timer = 1 - (u16)o->timer;
        }
        break;
    }
}
void func_8012E56C(O_2E56C *o) { body_2E56C(o); }

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E6B0);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E6C4);
extern void func_8012E738(char *);
extern void func_8012EBA8(char *);
extern void func_8012ED24(char *);

void func_8012E6C4(char *o)
{
    char *p;
    if (o[3] == 0) {
        func_8012E738(o);
        p = *(char **)(o + 0x94);
        func_8012EBA8(p);
        p[6] = o[6];
        p = *(char **)(p + 0x94);
        func_8012ED24(p);
        p[6] = o[6];
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012E738);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012EBA8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012ED24);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012EE80);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012EEF4);
void func_8012EEF4(GameObject *o)
{
    s16 a, b;
    s32 t;

    switch (o->step) {
    case 0:
        o->unk8C = 0;
        o->timer = 2;
        t = o->unk68 & 1;
        o->objectIndex = t;
        if (t) {
            o->velH = 0xa0;
            o->velX = -0x20;
            o->step = 1;
        } else {
            o->velH = -0xa0;
            o->velX = 0x20;
            o->step = 2;
        }
        o->unk68 = 0;
        break;
    case 1:
        if (o->unk68) o->step = 0;
        if (o->timer < 8) {
            o->unk8C = (o->unk8C + (o->velH >> 4)) & 0xff;
            o->velH += o->velX;
            if (o->velH < 0) {
                if (o->objectIndex) o->timer++;
                a = -0xa0 / (o->timer >> 1);
                b = 0x20 / (*(volatile s16 *)&o->timer >> 1);
                o->unk8C = 0;
                o->step = 2;
                o->velH = a;
                o->velX = b;
            }
        }
        if (o->timer >= 8) o->step = 3;
        break;
    case 2:
        if (o->unk68) o->step = 0;
        if (o->timer < 8) {
            o->unk8C = (o->unk8C + (o->velH >> 4)) & 0xff;
            o->velH += o->velX;
            if (o->velH > 0) {
                if (!o->objectIndex) o->timer++;
                a = 0xa0 / (o->timer >> 1);
                b = -0x20 / (*(volatile s16 *)&o->timer >> 1);
                o->unk8C = 0;
                o->step = 1;
                o->velH = a;
                o->velX = b;
            }
        }
        if (o->timer >= 8) o->step = 3;
        break;
    case 3:
        o->subState = 0;
        o->step = 0;
        break;
    }
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F1C8);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F1DC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F250);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F400);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F5E4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012F658);
typedef struct { char pad[4]; u8 b4; } E_2F658;
extern u8 D_8009C3E3;
extern E_2F658 *D_8009BCB0[];
extern void *D_8013A56C;

void func_8012F658(GameObject *o)
{
    Fix16 v[3];
    s16 d;
    switch (o->step) {
    case 0:
        switch (o->subtype) {
        case 0:
            o->unk88 = 0;
            D_8009C3E3 = 1;
            break;
        case 1:
            o->unk88 = 0;
            D_8009BCB0[0]->b4 = 3;
            break;
        case 2:
            o->unk88 = 0;
            break;
        }
        o->velH = 0x400;
        o->objectIndex = 0;
        o->unk6A = 0;
        o->touchFlag = 0;
        o->timer = 1 - *((u8 *)o + 0x6b);
        o->cooldownTimer = 0;
        o->step++;
        o->velY = 0;
        o->velX = 0x40;
        break;
    case 1:
        o->velH = d = o->velH - o->velX;
        if (o->timer) {
            o->velY -= d;
        } else {
            o->velY += d;
        }
        o->unk8C = ((o->velY >> 8) + o->unk88) & 0xff;
        if (o->velH <= 0) {
            o->velH = 0;
            o->step++;
            if (o->timer != 0) o->cooldownTimer++;
        }
        if (o->cooldownTimer >= 3) o->step = 3;
        break;
    case 2:
        o->velH = d = o->velH + o->velX;
        if (o->timer) {
            o->velY += d;
        } else {
            o->velY -= d;
        }
        o->unk8C = ((o->velY >> 8) + o->unk88) & 0xff;
        if (o->velH >= 0x400) {
            o->velH = 0x400;
            o->step--;
            o->timer = 1 - o->timer;
            if (o->timer == 0) o->cooldownTimer++;
        }
        if (o->cooldownTimer >= 3) o->step = 3;
        break;
    case 3:
        switch (o->subtype) {
        case 0:
            o->anim = D_8013A56C;
            o->unk8C = 0;
            o->unkA = 2;
            break;
        case 1:
            o->unk8C = 0;
            o->unk6A = 0;
            o->hitOffsetY = 0x20;
            o->hitHeight = 0x20;
            break;
        case 2:
            o->unk8C = 0;
            break;
        }
        o->step++;
        break;
    case 4:
        o->y.p.whole += 2;
        if (o->y.p.whole < o->unk34 - 8) break;
        o->y.raw = (o->unk34 - 8) << 16;
        o->timer = 0x14;
        o->step++;
        if (o->subtype == 1) {
            v[0].p.whole = o->h->p.whole;
            v[1].p.whole = o->y.p.whole - 0x10;
            v[2].p.whole = o->d->p.whole;
            func_80122EA8(v);
        }
        break;
    case 5:
        switch (o->subtype) {
        case 0:
            if (--o->timer == -1) o->state = 3;
            break;
        case 1:
            o->unk8C = (o->unk8C + 4) & 0xff;
            if (--o->timer == -1) o->state = 3;
            break;
        case 2:
            o->unk8C = (o->unk8C - 4) & 0xff;
            if (--o->timer == -1) o->state = 3;
            break;
        }
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012FA34);
extern void unpackSpriteFrame(s32, s32, char *, s32);
void func_8012FA34(s32 a, s32 b)
{
    s16 r[4];
    r[0] = b * 0x20 + 0x1c0;
    r[1] = 0xa0;
    r[2] = 0x20;
    r[3] = 0x60;
    ClearImage(r, 0, 0, 0);
    unpackSpriteFrame(D_1F800350, (s16)a, ((char *)&D_800D7188), 0xa001c0);
    loadTIM(((char *)&D_800D7188), (s16)(b * 0x20 + 0x1c1), 0xa0, 0xe0, 0x1f0);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012FAE4);
extern void readAnimFrameCount(GameObject *o);
extern void tickAnimation(GameObject *o);
extern void *D_8013A078[];
extern u16 D_80138584[];

void func_8012FAE4(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->timer = 0x70;
        o->unkB4 = 0;
        o->unkAC = 0;
        o->anim = D_8013A078[0];
        readAnimFrameCount(o);
        o->unk7++;
    case 1:
        if (--o->timer == 0) {
            o->step = D_80138584[nextRandom() & 0xf];
            o->unk7 = 0;
            if (o->d->p.whole == (*(Fix16 **)&D_800A53DC)->p.whole) {
                s32 dy = (*(u16 *)&D_800A53AE) - (u16)o->y.p.whole + 0x30;
                s32 dx = (u16)(*(Fix16 **)&D_800A53D8)->p.whole - (u16)o->h->p.whole + 0x80;
                if ((u16)dx < 0x100 && (u16)dy < 0xf8) {
                    o->step = 4;
                    o->unk7 = 0;
                }
            }
        }
    }
    tickAnimation(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012FC1C);
extern void *D_8013A090[];

void func_8012FC1C(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->timer = 0x8a;
        o->cooldownTimer = 1;
        o->unkB4 = 0;
        o->unk7++;
    case 1:
        if (--o->cooldownTimer == 0) {
            o->unkAC = 6;
            o->anim = D_8013A090[0];
            readAnimFrameCount(o);
            o->cooldownTimer = 0x2e;
        }
        if (--o->timer == 0) {
            o->step = D_80138584[nextRandom() & 0xf];
            o->unk7 = 0;
            if (o->d->p.whole == (*(Fix16 **)&D_800A53DC)->p.whole) {
                s32 dy = (*(u16 *)&D_800A53AE) - (u16)o->y.p.whole + 0x30;
                s32 dx = (u16)(*(Fix16 **)&D_800A53D8)->p.whole - (u16)o->h->p.whole + 0x80;
                if ((u16)dx < 0x100 && (u16)dy < 0xf8) {
                    o->step = 4;
                    o->unk7 = 0;
                }
            }
        }
    }
    tickAnimation(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012FD7C);
extern s32 D_8013A094;
typedef struct G_2FD7C { char p0[0x16]; u16 y; char p2[0x40 - 0x18]; char *h; char *d; } G_2FD7C;
extern void playSFX(s32);

void func_8012FD7C(u8 *o)
{
    u16 a;
    switch (o[7]) {
    case 0:
        *(s16 *)(o + 0x20) = 0x8a;
        *(s16 *)(o + 0x22) = 1;
        *(s16 *)(o + 0xb4) = 0;
        o[7] = o[7] + 1;
    case 1:
        *(s16 *)(o + 0x22) = *(s16 *)(o + 0x22) - 1;
        if (*(s16 *)(o + 0x22) == 0) {
            *(s16 *)(o + 0xac) = 7;
            *(s32 *)(o + 0x24) = D_8013A094;
            readAnimFrameCount(o);
            if (*(u16 *)(o + 0xca) != 0)
                playSFX(0x13);
            *(s16 *)(o + 0x22) = 0x2e;
        }
        *(s16 *)(o + 0x20) = *(s16 *)(o + 0x20) - 1;
        if (*(s16 *)(o + 0x20) == 0) {
            o[6] = D_80138584[nextRandom() & 0xf];
            o[7] = 0;
            if (*(s16 *)(*(char **)(o + 0x44) + 2) == *(s16 *)((*(G_2FD7C *)&PLAYER).d + 2)) {
                a = (*(G_2FD7C *)&PLAYER).y - *(u16 *)(o + 0x16) + 0x30;
                if ((u16)(*(u16 *)((*(G_2FD7C *)&PLAYER).h + 2) - *(u16 *)(*(char **)(o + 0x40) + 2) + 0x80) < 0x100 && a < 0xf8) {
                    o[6] = 4;
                    o[7] = 0;
                }
            }
        }
        break;
    }
    tickAnimation(o);
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_8012FEF4);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_80130B28);
extern void *D_8013A0AC[];

static __inline__ s32 check_30B28(GameObject *o)
{
    s16 r;
    u16 d;
    s32 x;
    if (o->d->p.whole != (*(Fix16 **)&D_800A53DC)->p.whole) {
        x = 0;
    } else {
        r = 0;
        if ((u16)((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole + 0x40) < 0x80 && (((s32 (*)(void))nextRandom)() & 0xf) < 12) {
            r = 1;
        } else if ((u16)((*(Fix16 **)&D_800A53D8)->p.whole - o->h->p.whole + 0x80) < 0x100 && (((s32 (*)(void))nextRandom)() & 0xf) < 6) {
            r = 1;
        }
        x = 0;
        d = (*(u16 *)&D_800A53AE) - o->y.p.whole + 0x30;
        if (r == 1)
            x = d < 0xf8;
        else
            x = 0;
    }
    return x;
}

void func_80130B28(GameObject *o)
{
    switch (o->unk7) {
    case 0:
        o->timer = 0xa8;
        o->cooldownTimer = 1;
        o->unkB4 = 0;
        o->unk7++;
    case 1:
        if (--o->cooldownTimer == 0) {
            o->unkAC = 13;
            o->anim = D_8013A0AC[0];
            readAnimFrameCount(o);
            o->cooldownTimer = 0x54;
        }
        if (--o->timer == 0) {
            if (check_30B28(o)) {
                o->subState = 1;
                o->step = 0;
                o->unk7 = 0;
            } else {
                o->step = D_80138584[((s32 (*)(void))nextRandom)() & 0xf];
                o->unk7 = 0;
            }
        }
        break;
    }
    tickAnimation(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_80130D14);
typedef struct { s16 x, y; } P;
extern s32 angleBetweenPoints(P a, P b);
extern void applyObjectAltSpeedXY(GameObject *);
extern void decreaseObjectTimer(void *, s32);
extern s32 fixedMulCos(s32, s32);
extern s32 fixedMulSin(s32, s32);
extern s16 probeCollisionAtDepthB(GameObject *, s16, s16);
extern u8 D_800A539C_U8Arr[] asm("D_800A539C");
extern u8 D_800A539D_U8Arr[] asm("D_800A539D");
extern u8 D_800A539E_U8Arr[] asm("D_800A539E");
extern u8 D_800A539F;
extern void *D_8013A0B8[];
extern void *D_8013A080[];
extern void *D_8013A0C0[];
extern void *D_8013A0C4[];
extern s16 D_801385C4[];
extern s16 *D_80138578[];

static __inline__ s16 hit_30D14(GameObject *o)
{
    if (probeCollisionAtDepthB(o, o->h->p.whole + 0x20, o->y.p.whole + 0x18)) return 1;
    if (probeCollisionAtDepthB(o, o->h->p.whole - 0x20, o->y.p.whole + 0x18)) return 1;
    return 0;
}

void func_80130D14(GameObject *o)
{
    P a, b;
    s16 *t;
    s16 d;
    u16 v;
    Fix16 *p;
    u8 *q;

    switch (o->unk7) {
    case 0:
        if (o->h->p.whole >= (*(Fix16 **)&D_800A53D8)->p.whole)
            o->animFrame = 1;
        else
            o->animFrame = 0;
        o->cooldownTimer = 0x38;
        o->unkAC = 0x10;
        *(u16 *)((u8 *)o + 0xc8) = o->animFrame;
        o->anim = D_8013A0B8[0];
        readAnimFrameCount(o);
        if (*(u16 *)((u8 *)o + 0xca))
            playSFX(0x13);
        o->unk7++;
        break;
    case 1:
        if (--o->cooldownTimer == 0) {
            o->velV = -0x400;
            o->cooldownTimer = 0x38;
            o->velH = 0;
            o->unkAC = 2;
            o->anim = D_8013A080[0];
            readAnimFrameCount(o);
            o->unk7++;
        }
        break;
    case 2:
        if (o->velV >= 0) {
            o->cooldownTimer = 0x1e;
            o->unk7++;
        }
        o->velV += 0x20;
        o->y.raw += o->velV << 8;
        break;
    case 3:
        if (--o->cooldownTimer == 0) {
            a.x = o->h->p.whole;
            a.y = o->y.p.whole;
            b.x = (*(Fix16 **)&D_800A53D8)->p.whole;
            b.y = (*(u16 *)&D_800A53AE);
            *(u16 *)((u8 *)o + 0xcc) = angleBetweenPoints(a, b) + 0x100;
            o->cooldownTimer = 0x78;
            o->unkB6 = 0;
            o->unk6A = 1;
            o->unk7++;
        }
        break;
    case 4:
        a.x = o->h->p.whole;
        a.y = o->y.p.whole;
        b.x = (*(Fix16 **)&D_800A53D8)->p.whole;
        b.y = (*(u16 *)&D_800A53AE);
        d = angleBetweenPoints(a, b) + 0x100;
        *(u16 *)((u8 *)o + 0xcc) = d;
        o->h->raw += (s16)fixedMulCos(d & 0xf8, o->unkB6) << 8;
        o->y.raw += (s16)fixedMulSin(*(u16 *)((u8 *)o + 0xcc) & 0xf8, o->unkB6) << 8;
        if ((u16)o->unkB6 < 0x400)
            o->unkB6 += 0x20;
        if (o->unk6A == 2) {
            o->unkAC = 0x12;
            o->anim = D_8013A0C0[0];
            readAnimFrameCount(o);
            o->y.p.whole -= 8;
            o->cooldownTimer = D_801385C4[nextRandom() & 0xf];
            playSFX(0x14);
            o->unk7++;
        } else if (--o->cooldownTimer == 0) {
            o->unk6A = 0;
            o->unkAC = 2;
            o->anim = D_8013A080[0];
            readAnimFrameCount(o);
            o->velV = -0x400;
            o->timer = 0x1e;
            o->unk7 = 0xb;
        } else if (hit_30D14(o)) {
            o->unk6A = 0;
            o->unkAC = 2;
            o->anim = D_8013A080[0];
            readAnimFrameCount(o);
            o->velV = -0x400;
            o->timer = 0x1e;
            o->unk7 = 0xb;
        } else {
            t = D_80138578[o->subtype];
            if (o->h->p.whole < t[0] || t[1] < o->h->p.whole) {
                o->unk6A = 0;
                o->unkAC = 2;
                o->anim = D_8013A080[0];
                readAnimFrameCount(o);
                o->velV = -0x400;
                o->timer = 0x1e;
                o->unk7 = 9;
            }
        }
        break;
    case 5:
        if (--o->cooldownTimer == 0) {
            o->velY = -0x100;
            o->cooldownTimer = 0x60;
            o->velX = 0;
            o->unk7 = 6;
        } else {
            p = (*(Fix16 **)&D_800A53D8);
            d = o->h->p.whole - p->p.whole;
            v = p->p.whole;
            if (d != 0) {
                if (d < 0)
                    p->p.whole = v - 1;
                else
                    p->p.whole = v + 1;
            }
        }
        break;
    case 6:
        applyObjectAltSpeedXY(o);
        q = ((u8 *)&PLAYER);
        (*(Fix16 **)&D_800A53D8)->p.whole = o->h->p.whole;
        (*(u16 *)&D_800A53AE) = o->y.p.whole + 0x28;
        if (D_800A539F == 1) {
            o->unk6A = 0;
            *q = 1;
            D_800A539C_U8Arr[0] = 1;
            D_800A539D_U8Arr[0] = 0;
            D_800A539E_U8Arr[0] = 0;
            o->unkAC = 0x13;
            o->anim = D_8013A0C4[0];
            readAnimFrameCount(o);
            o->unk7 = 8;
        } else if (--o->cooldownTimer == 0) {
            o->unk6A = 0;
            *q = 2;
            D_800A53C6 = 2;
            D_800A5416 = 0;
            D_800A539C_U8Arr[0] = 2;
            D_800A539D_U8Arr[0] = 0;
            D_800A539E_U8Arr[0] = 1;
            decreaseObjectTimer(q, 1);
            o->unkAC = 0x13;
            o->anim = D_8013A0C4[0];
            readAnimFrameCount(o);
            o->unk7 = 8;
        }
        break;
    case 8:
        o->velV = -0x400;
        o->timer = 0x1e;
        o->unk7++;
    case 9:
        o->y.raw += o->velV << 8;
        if (--o->timer == 0) {
            o->active = 1;
            o->timer = 0x1e;
            o->unk7++;
        }
        break;
    case 10:
        if (--o->timer == 0) {
            o->step = 3;
            o->subState = 0;
            o->unk7 = 0;
            o->unkB4 = 1;
        }
        break;
    case 11:
        o->y.raw += o->velV << 8;
        if (--o->timer == 0) {
            o->timer = 0x1e;
            o->unk7 = 10;
        }
        break;
    }
    tickAnimation(o);
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_801313EC);
extern void spawnItemNotification(s32, s32);
extern void readAnimFrameCount(GameObject *);
extern void *D_8013A088[];
extern void *D_8013A08C[];

static __inline__ void set_box_313EC(GameObject *o, s16 a, s16 b, s16 c, s16 d)
{
    o->hitOffsetX = a;
    o->hitWidth = b;
    o->hitOffsetY = c;
    o->hitHeight = d;
}

void func_801313EC(GameObject *o)
{
    switch (o->step) {
    case 0: {
        set_box_313EC(o, 0x14, 0x28, 0, 0x14);
        *(s8 *)&o->unkF = -7;
        o->unk68 = 0;
        o->unk8C = 0;
        spawnItemNotification(0, 6);
        o->step++;
        break; }
    case 3:
        o->unkAC = 4;
        o->anim = D_8013A088[0];
        readAnimFrameCount(o);
        break;
    case 2:
    case 4:
    case 7:
        o->unkAC = 5;
        o->anim = D_8013A08C[0];
        readAnimFrameCount(o);
        break;
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_801314B8);
typedef struct { GameObject o; u16 c0, c2, c4, c6, c8, ca, cc, ce, d0; s16 d2; } E_314B8;
extern s32 D_1F8002DC;
extern char D_800772B0[];
extern void *D_8013A084[];
extern void applyAnimVelocityXY(GameObject *, u16);
extern void applyAnimVelocityX(GameObject *, u16);

static __inline__ void draw_314B8(s32 a, s32 b)
{
    s16 r[4];
    r[0] = b * 0x20 + 0x1c0;
    r[1] = 0xa0;
    r[2] = 0x20;
    r[3] = 0x60;
    ClearImage(r, 0, 0, 0);
    unpackSpriteFrame(D_1F800350, (s16)a, ((char *)&D_800D7188), 0xa001c0);
    loadTIM(((char *)&D_800D7188), (s16)(b * 0x20 + 0x1c1), 0xa0, 0xe0, 0x1f0);
}

void func_801314B8(GameObject *o)
{
    s32 d;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x14;
        o->hitWidth = 0x28;
        o->hitOffsetY = 10;
        o->hitHeight = 0x1e;
        o->active = 1;
        o->tpage = 7;
        o->unkD = 1;
        o->clut = GetClut(0xe0, 0x1f0);
        o->unkA = 6;
        o->unk84 = 0;
        o->unk88 = 0;
        o->unk8C = 0;
        o->unkAC = 2;
        o->anim = D_8013A080[0];
        readAnimFrameCount(o);
        o->spriteBank = D_1F8002DC;
        o->movetab = ((char *)&D_800771FC);
        o->timer = 1;
        *(s8 *)&o->unkF = -9;
        ((E_314B8 *)o)->c4 = 0xffff;
        o->state++;
        o->unk6A = 0;
        o->subState = 0;
        o->step = 0;
        o->unk7 = 0;
        o->unkB4 = 0;
        ((E_314B8 *)o)->c6 = 0;
        ((E_314B8 *)o)->ca = 0;
        *(s16 *)&o->unkBE = o->h->p.whole;
        ((E_314B8 *)o)->c0 = o->y.p.whole;
        ((E_314B8 *)o)->c2 = o->d->p.whole;
        o->buffSize = 0x1000;
        break;
    case 1:
        if (D_8009BCAA != 0) {
            func_80022E44(o);
            break;
        }
        if (o->unk9E == 0) {
            switch (o->subState) {
            case 0:
                switch (o->step) {
                case 0:
                    func_8012FAE4(o);
                    break;
                case 1:
                    func_8012FC1C(o);
                    break;
                case 2:
                    func_8012FD7C(o);
                    break;
                case 3:
                    func_8012FEF4(o);
                    break;
                case 4:
                    func_80130B28(o);
                    break;
                }
                break;
            case 1:
                func_80130D14(o);
                break;
            }
        } else if (o->unk9F == 0) {
            s16 t = o->h->p.whole;
            o->unk9F = 0xf;
            ((E_314B8 *)o)->d2 = t;
        } else {
            { s32 r = nextRandom(); o->h->p.whole = (s16)(((E_314B8 *)o)->d2 - 2) + (r & 3); }
            if (--o->unk9F == 0) {
                o->unk9E = 0;
                o->h->p.whole = ((E_314B8 *)o)->d2;
            }
        }
        if (func_80022E44(o))
            ((E_314B8 *)o)->ca = 1;
        else
            ((E_314B8 *)o)->ca = 0;
        if ((*(Fix16 **)&D_800A53DC)->p.whole >= o->d->p.whole)
            o->clut = GetClut(0xe0, 0x1f0);
        else
            o->clut = GetClut(0xe0, 0x1f1);
        break;
    case 2:
        if (D_8009BCAA != 0) {
            func_80022E44(o);
            break;
        }
        switch (o->subState) {
        case 0:
            switch (o->step) {
            case 0:
                o->timer = 0x78;
                o->cooldownTimer = 1;
                o->unkAC = 3;
                o->anim = D_8013A084[0];
                readAnimFrameCount(o);
                o->movetab = D_800772B0;
                o->step++;
                break;
            case 1:
                if (--o->timer == 0) {
                    o->unkAC = 2;
                    o->anim = D_8013A080[0];
                    readAnimFrameCount(o);
                    o->step++;
                }
                d = 8;
                if (o->animFrame)
                    d = -8;
                if (probeCollisionAtDepthB(o, o->h->p.whole + d, o->y.p.whole + 0x18) == 0) {
                    applyAnimVelocityXY(o, 0);
                    o->cooldownTimer++;
                }
                break;
            case 2:
                if (*(u16 *)&o->unkB4 != 0) {
                    if (--o->cooldownTimer == 0) {
                        o->active = 1;
                        o->state = 1;
                        o->subState = 0;
                        o->step = 3;
                        o->unk7 = 0;
                    }
                    applyAnimVelocityXY(o, 1);
                } else {
                    if (--o->cooldownTimer == 0) {
                        o->active = 1;
                        o->state = 1;
                        o->subState = 0;
                        o->step = 0;
                        o->unk7 = 0;
                    }
                }
                break;
            }
            if (func_80022E44(o)) {
                tickAnimation(o);
                ((E_314B8 *)o)->ca = 1;
            } else
                ((E_314B8 *)o)->ca = 0;
            break;
        case 1:
            func_801313EC(o);
            if (func_80022E44(o)) {
                tickAnimation(o);
                ((E_314B8 *)o)->ca = 1;
            } else
                ((E_314B8 *)o)->ca = 0;
            break;
        case 2:
            switch (o->step) {
            case 0:
                o->unkB = 1;
                o->unkF = 4;
                o->velV = -0x400;
                o->movetab = ((char *)&D_800771FC);
                o->unkAC = 5;
                o->step++;
                o->anim = D_8013A08C[0];
                readAnimFrameCount(o);
                break;
            case 1:
                applyAnimVelocityX(o, 1 - o->animFrame);
                if ((o->velV += 0x40) > 0x400)
                    o->velV = 0x400;
                o->y.raw += o->velV << 8;
                break;
            }
            if (o->animFrame & 1)
                o->unk8C = (o->unk8C + 0x14) & 0xff;
            else
                o->unk8C = (o->unk8C - 0x14) & 0xff;
            if (func_80022E44(o) == 0)
                o->state = 3;
            tickAnimation(o);
            break;
        }
        break;
    case 3:
        freeObjectLayer2(o);
        break;
    }
    if (((E_314B8 *)o)->ca == 1 && ((E_314B8 *)o)->c4 != *(u16 *)o->anim) {
        ((E_314B8 *)o)->c4 = *(u16 *)o->anim;
        ((E_314B8 *)o)->c6 ^= 1;
        draw_314B8(((E_314B8 *)o)->c4, ((E_314B8 *)o)->c6);
    }
}

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_80131BF8);
typedef struct { u8 b[8]; } V801328B4_31BF8;

extern V801328B4_31BF8 D_80138630[][4];
extern void *D_8013A594[];
extern void (*D_80138624[])(GameObject *);
extern s32 D_1F8002D4[];
extern u16 GetClut(s32, s32);

#define COPY() \
    ((V801328B4_31BF8 *)&o->unkB4)[0] = D_80138630[o->unkC][0]; \
    ((V801328B4_31BF8 *)&o->unkB4)[1] = D_80138630[o->unkC][1]; \
    ((V801328B4_31BF8 *)&o->unkB4)[2] = D_80138630[o->unkC][2]; \
    ((V801328B4_31BF8 *)&o->unkB4)[3] = D_80138630[o->unkC][3];

void func_80131BF8(GameObject *o)
{
    V801328B4_31BF8 *t;

    switch (o->state) {
    case 0:
        o->hitOffsetX = 0x20;
        o->hitWidth = 0x40;
        o->hitOffsetY = 8;
        o->hitHeight = 0x10;
        o->active = 1;
        if (o->unkC == 0)
            o->active = 2;
        o->tpage = 0xf;
        o->unkD = 1;
        o->clut = GetClut(0x90, 0x1e6);
        o->anim = D_8013A594[o->unkC];
        o->spriteBank = D_1F8002D4[0];
        t = D_80138630[o->unkC];
        o->state++;
        o->touchFlag = 0;
        o->objectIndex = 0;
        o->subState = 0;
        ((V801328B4_31BF8 *)&o->unkB4)[0] = t[0];
        ((V801328B4_31BF8 *)&o->unkB4)[1] = D_80138630[o->unkC][1];
        ((V801328B4_31BF8 *)&o->unkB4)[2] = D_80138630[o->unkC][2];
        ((V801328B4_31BF8 *)&o->unkB4)[3] = D_80138630[o->unkC][3];
        readAnimFrameCount(o);
        break;
    case 1:
        if (func_80022E44(o)) {
            D_80138624[o->subtype](o);
        } else if (o->subState) {
            COPY();
            o->subState = 0;
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
#undef COPY

void func_80131EF4(void) {
}

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_80131EFC);

INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_80132114);

// INCLUDE_ASM("asm/scus_942.36/overlays/x00/nonmatchings/x00_6", func_801322C4);
extern void *D_8013A4D4;
extern void *D_8013A4C8;
extern void *D_8013A4C4;
extern char D_80077214[];
extern void advanceAnimFrame(GameObject *, s32);
extern s16 func_80043AB0(GameObject *, s16, s16, s32);
extern void applyFrameVelocityX(GameObject *);
extern s16 probeCollisionAtDepthA(GameObject *, s16, s16);
void func_801322C4(GameObject *o)
{
    u16 px, hx;
    s16 near;
    Fix16 *pp = D_800A53D8;
    s32 x, t;
    s32 s2;
    px = pp->p.whole;
    hx = o->h->p.whole;
    near = (u16)(px - hx + 0x40) < 0x80;
    switch (o->step) {
    case 0:
        o->animFrame = (s16)hx < (s16)px;
        if (nextRandom() & 1) {
            o->anim = D_8013A4D4;
            advanceAnimFrame(o, 1);
            o->movetab = D_80077214;
            o->velY = -0x200;
            o->step = 2;
        } else {
            o->anim = D_8013A4C8;
            readAnimFrameCount(o);
            o->timer = 0x40 >> (near * 5);
            o->step = 1;
        }
        break;
    case 1:
        tickAnimation(o);
        t = near;
        if (--o->timer == 0) {
            o->step = 0;
        } else if (t) {
            o->step = 0;
        }
        break;
    case 2:
        tickAnimation(o);
        t = o->h->p.whole;
        s2 = (o->animFrame & 1) ? t - 8 : t + 8;
        if (func_80043AB0(o, s2, o->y.p.whole, 0) == 0) {
            applyFrameVelocityX(o);
        }
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (o->velY > 0) {
            o->anim = D_8013A4D4;
            advanceAnimFrame(o, 4);
            o->step = 3;
        }
        goto common;
    case 3:
        t = (s16)hx;
        if (o->animFrame & 1) x = t - 8;
        else x = t + 8;
        if (func_80043AB0(o, x, o->y.p.whole, 0) == 0) {
            applyFrameVelocityX(o);
        }
        o->y.raw += o->velY << 8;
        o->velY += 0x20;
        if (probeCollisionAtDepthA(o, o->h->p.whole, o->y.p.whole + 8) != 0) {
            o->anim = D_8013A4C4;
            readAnimFrameCount(o);
            o->step = 0;
        }
    common:
        if (o->unk68 == 0 && o->h->p.whole >= 0x49f) {
            o->state = 3;
            o->subState = 0;
            o->step = 0;
        }
        break;
    }
}
